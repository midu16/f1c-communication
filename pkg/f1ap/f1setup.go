package f1ap

// F1SetupResponse represents a response to an F1 Setup Request
type F1SetupResponse struct {
	TransactionID int    `asn1:"tag:0"`
	Result        string `asn1:"tag:1"`
}

// NewF1SetupResponse creates a new F1SetupResponse
func NewF1SetupResponse(transactionID int, result string) *F1SetupResponse {
	return &F1SetupResponse{
		TransactionID: transactionID,
		Result:        result,
	}
}

// EncodeF1SetupResponse encodes the F1SetupResponse to ASN.1
func EncodeF1SetupResponse(response *F1SetupResponse) ([]byte, error) {
	// You can use the EncodeASN1 function to encode it to ASN.1 format
	return EncodeASN1(response)
}
