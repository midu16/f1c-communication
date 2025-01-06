# Use an official Go image as the base
FROM golang:1.20-alpine as builder

# Set up the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Install dependencies and build the Go application
RUN go mod tidy && go build -o f1c-communication .

# Use a minimal base image for the final container
FROM alpine:latest

# Set up necessary system dependencies
RUN apk --no-cache add ca-certificates

# Set the working directory
WORKDIR /app

# Copy the built Go binary from the builder stage
COPY --from=builder /app/f1c-communication /app/

# Set the default environment variable to specify the component
ENV COMPONENT=du

# Expose the port the DU server will listen on
EXPOSE 38473

# Command to run when the container starts
CMD if [ "$COMPONENT" = "du" ]; then \
        ./f1c-communication cmd/du/main.go; \
    elif [ "$COMPONENT" = "cu" ]; then \
        ./f1c-communication cmd/cu/main.go; \
    else \
        echo "Invalid COMPONENT value! Use 'du' or 'cu'"; \
        exit 1; \
    fi
