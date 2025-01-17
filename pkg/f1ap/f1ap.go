package f1ap

import (
	"encoding/json"
	"fmt"
)

// F1SetupRequest represents a setup request in the F1AP protocol.
type F1SetupRequest struct {
	TransactionID int    // Unique identifier for the transaction
	GlobalCUId    string // Identifier for the Central Unit (CU)
	GNBID         string // Identifier for the gNodeB
	GNBName       string // Name of the gNodeB
}

// EncodeF1SetupRequest serializes the F1SetupRequest into JSON format.
func EncodeF1SetupRequest(req F1SetupRequest) ([]byte, error) {
	data, err := json.Marshal(req)
	if err != nil {
		return nil, fmt.Errorf("failed to encode F1SetupRequest: %v", err)
	}
	return data, nil
}

// DecodeF1SetupRequest deserializes the JSON data into an F1SetupRequest.
func DecodeF1SetupRequest(data []byte, req *F1SetupRequest) error {
	err := json.Unmarshal(data, req)
	if err != nil {
		return fmt.Errorf("failed to decode F1SetupRequest: %v", err)
	}
	return nil
}
