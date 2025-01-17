package f1ap

// Example function to create an F1SetupRequest
func CreateF1SetupRequest(transactionID int, globalCUId, gnbID, gnbName string) F1SetupRequest {
	return F1SetupRequest{
		TransactionID: transactionID,
		GlobalCUId:    globalCUId,
		GNBID:         gnbID,
		GNBName:       gnbName,
	}
}
