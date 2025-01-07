# Stage 1: Build the Go application
FROM golang:1.19-alpine AS builder

# Set the working directory inside the container
WORKDIR /app

# Copy the source code into the container
COPY ../go.mod ../go.sum ./

# Download dependencies
RUN go mod tidy

# Copy the entire project source into the container
COPY ../* .

# Build the Go binary
RUN go build -o f1c-communication .

# Stage 2: Create the final image
FROM alpine:latest

# Install required dependencies (e.g., certificates)
RUN apk --no-cache add ca-certificates

# Set the working directory for the application
WORKDIR /app

# Copy the binary from the builder stage
COPY --from=builder /app/f1c-communication /app/

# Set default environment variable for running either DU or CU
ENV COMPONENT=du

# Expose the necessary port for the DU server
EXPOSE 38473

# Command to run the application
CMD if [ "$COMPONENT" = "du" ]; then \
        ./f1c-communication cmd/du/main.go; \
    elif [ "$COMPONENT" = "cu" ]; then \
        ./f1c-communication cmd/cu/main.go; \
    else \
        echo "Invalid COMPONENT value! Use 'du' or 'cu'"; \
        exit 1; \
    fi
