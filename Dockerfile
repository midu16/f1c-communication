# Step 1: Use the official Golang image as a builder base image
FROM golang:1.19 as builder

# Step 2: Set the current working directory inside the container
WORKDIR /app

# Step 3: Copy go.mod and go.sum files to the container to download the dependencies
COPY go.mod go.sum ./

# Step 4: Download all the dependencies
RUN go mod tidy

# Step 5: Copy the source code into the container
COPY . .

# Step 6: Build the Go app with specific configurations (ensure CGO_ENABLED is set appropriately)
RUN CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -o f1c-communication .

# Step 7: Use a smaller base image for running the app
FROM alpine:latest

# Step 8: Install required dependencies (e.g., for SCTP support)
RUN apk --no-cache add libcap && apk --no-cache add --virtual .build-deps gcc musl-dev make

# Step 9: Copy the compiled binary from the builder image
COPY --from=builder /app/f1c-communication /usr/local/bin/f1c-communication

# Step 10: Expose the port the server runs on
EXPOSE 38473

# Step 11: Set environment variables for the server address and mode
ENV SERVER_IP="0.0.0.0"
ENV SERVER_PORT="38473"
ENV RUN_MODE="server"

# Step 12: Add entrypoint to conditionally start the server or client
ENTRYPOINT ["/bin/sh", "-c", "if [ \"$RUN_MODE\" = \"server\" ]; then /usr/local/bin/f1c-communication -server \"$SERVER_IP:$SERVER_PORT\"; else /usr/local/bin/f1c-communication -client \"$SERVER_IP:$SERVER_PORT\"; fi"]
