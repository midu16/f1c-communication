package transport

import (
	"bufio"
	"net"
)

// SendMessage sends a message over the connection
func SendMessage(conn net.Conn, message []byte) error {
	_, err := conn.Write(append(message, '\n'))
	return err
}

// ReadMessage reads a message from the connection
func ReadMessage(conn net.Conn) ([]byte, error) {
	reader := bufio.NewReader(conn)
	return reader.ReadBytes('\n')
}
