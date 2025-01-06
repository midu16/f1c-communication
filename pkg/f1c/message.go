package f1c

import (
	"fmt"
)

// F1CMessage represents a basic F1-C message structure
type F1CMessage struct {
	MessageType string `json:"message_type"`
	Payload     string `json:"payload"`
}

// Validate checks if the message is valid
func (m *F1CMessage) Validate() error {
	if m.MessageType == "" || m.Payload == "" {
		return fmt.Errorf("invalid F1CMessage: both MessageType and Payload are required")
	}
	return nil
}
