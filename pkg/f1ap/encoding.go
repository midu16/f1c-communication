package f1ap

import (
	"encoding/asn1"
	"fmt"
)

// EncodeASN1 encodes the given value into ASN.1 format
func EncodeASN1(value interface{}) ([]byte, error) {
	// Use asn1.Marshal to encode the value
	encodedData, err := asn1.Marshal(value)
	if err != nil {
		return nil, fmt.Errorf("failed to encode ASN.1: %v", err)
	}
	return encodedData, nil
}

// DecodeASN1 decodes the given ASN.1 data into the provided value
func DecodeASN1(data []byte, value interface{}) error {
	// Use asn1.Unmarshal to decode the data
	_, err := asn1.Unmarshal(data, value)
	if err != nil {
		return fmt.Errorf("failed to decode ASN.1: %v", err)
	}
	return nil
}
