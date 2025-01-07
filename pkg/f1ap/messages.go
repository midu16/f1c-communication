package f1ap

type F1SetupRequest struct {
	TransactionID int32
	GNBID         string
	GNBName       string
}

func NewF1SetupRequest(transactionID int32, gnbID, gnbName string) F1SetupRequest {
	return F1SetupRequest{
		TransactionID: transactionID,
		GNBID:         gnbID,
		GNBName:       gnbName,
	}
}
