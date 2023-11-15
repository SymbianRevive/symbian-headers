// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#include <smcmmain.h>
#include <smut.h>

/** 
Constructor.

@param	aType	
The type of operation for which progress information is being given.
*/
inline TSmsProgress::TSmsProgress(TSmsProgressType aType)
:	iError(KErrNone),
	iType(aType),
	iState(0),
	iRcpDone(0),
	iRcpCount(0),
	iMsgDone(0),
	iMsgCount(0),
	iEnumerateFolder(0)
	{
	iServiceCenterAddress.Zero();
	}

/** 
Gets the validity period for messages sent by the SMS MTM.

If the service centre is unable to deliver the SMS message before this time 
expires, a failure report may be generated by the service centre, and no further 
attempts will be made to deliver the message to ther recipient.

Validity period is only used for SMS-SUBMIT, mobile originated messages.

@return
The validity period of the message.
*/
inline const TTimeIntervalMinutes& CSmsMessageSettings::ValidityPeriod() const
	{
	return iValidityPeriod;
	}

/** 
Sets the validity period for messages sent by the SMS MTM.

@param	aValidityPeriod	
The validity period.

@panic	SMCM	8	
The validity period is negative or greater than the maximum validity period
(debug only).
*/
inline void CSmsMessageSettings::SetValidityPeriod(TTimeIntervalMinutes aValidityPeriod)
	{
	__ASSERT_DEBUG(aValidityPeriod.Int()>=0 && aValidityPeriod.Int()<=ESmsVPMaximum,Panic(ESmscVPOutOfRange));
	iValidityPeriod=aValidityPeriod;
	}

/**
Gets the values of the UI concatenated-SMS-allowed flag.

If true, the UI should pass a long message in one piece to the MTM. If false, 
it should split the message manually into 140 byte parts. The value of this 
flag does not affect the behaviour of the SMS MTM.

@return	
The concatenated-SMS-allowed flag.
*/
inline TBool CSmsMessageSettings::CanConcatenate() const
	{
	return iMsgFlags&ESmsSettingsCanConcatenate;
	}

/** 
Sets the values of the UI concatenated-SMS-allowed flag.

If true, the UI should pass a long message in one piece to the MTM. If false, 
it should split the message manually into 140 byte parts. The value of this 
flag does not affect the behaviour of the SMS MTM.

@param	aCanConcatenate	
The value to set the concatenated-SMS-allowed flag to.
*/
inline void CSmsMessageSettings::SetCanConcatenate(TBool aCanConcatenate)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsCanConcatenate) | (aCanConcatenate?ESmsSettingsCanConcatenate : ESmsSettingsNoFlags);
	}

/**
Gets the value of the reject-duplicate setting.

If this is true, the service instructs the SC to reject an Sms-Submit for an 
SMS still held in the SC that has the same message reference number and same 
destination address as an previously submitted SMS from the same originating 
address.

@return	
The value of the reject-duplicate setting.
*/
inline TBool CSmsMessageSettings::RejectDuplicate() const
	{	
	return iMsgFlags&ESmsSettingsRejectDuplicate;
	}

/**
Sets the value of the reject-duplicate setting.

@param	aRejectDuplicate	
The value to set the reject-duplicate setting to.
*/
inline void CSmsMessageSettings::SetRejectDuplicate(TBool aRejectDuplicate)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsRejectDuplicate) | (aRejectDuplicate?ESmsSettingsRejectDuplicate : ESmsSettingsNoFlags);
	}

/**
Tests if a status report (TP-SRR in GSM spec 03.40) will be requested from 
the Service Centre.

A value of ETrue indicates that a status report will be requested.

@return	
The value of the Status report flag.
*/
inline TBool CSmsMessageSettings::DeliveryReport() const
	{
	return iMsgFlags&ESmsSettingsDeliveryReport;
	}

/** 
Sets if a status report (TP-SRR in GSM spec 03.40) will be requested from the
Service Centre.

A value of ETrue indicates that a status report will be requested.

@param	aDeliveryReport	
The value of the status report flag.
*/
inline void CSmsMessageSettings::SetDeliveryReport(TBool aDeliveryReport)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsDeliveryReport) | (aDeliveryReport?ESmsSettingsDeliveryReport : ESmsSettingsNoFlags);
	}

/**
Gets the boolean flag that indicates whether a the reply path (Service Centre
address) should be included in the SMS-SUBMIT message (TP-RP in GSM spec 03.40).

A value of ETrue indicates that the Service Centre address should be included.
This flag is only relavent for SMS-SUBMIT messages.

@return
The value of the reply path flag.
*/

inline TBool CSmsMessageSettings::ReplyPath() const
	{
	return iMsgFlags&ESmsSettingsReplyPathRequested;
	}

/**
Sets the boolean flag that indicates whether a the reply path (Service Centre
address) should be included in the SMS-SUBMIT message (TP-RP in GSM spec 03.40).

A value of ETrue indicates that the Service Centre address should be included.
This flag is only relavent for SMS-SUBMIT messages.

@param   aReplyPathRequest
The value of the reply path flag.
*/
inline void CSmsMessageSettings::SetReplyPath(TBool aReplyPathRequest)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsReplyPathRequested) | (aReplyPathRequest?ESmsSettingsReplyPathRequested : ESmsSettingsNoFlags);
	}

/**
Gets the form in which the message should be delivered to the recipient by 
the service centre. 

Note that the form may or may not actually be supported by the service centre, 
and that the format of the recipient address(es) may need to be different 
to a normal telephone number if MessageConversion() is set to any other value 
than ESmsConvPIDNone, ESmsConvFax, ESmsConvPaging or ESmsConvErmes.

@return
The value of the message form specifier.
*/
inline TSmsPIDConversion CSmsMessageSettings::MessageConversion() const
	{
	return iMessageConversion;
	}

/**
Sets the form in which the message should be delivered to the recipient by the
Service Centre. 

Note that the form may or may not actually be supported by the service centre, 
and that the format of the recipient address(es) may need to be different 
to a normal telephone number if MessageConversion() is set to any other value 
than ESmsConvPIDNone, ESmsConvFax, ESmsConvPaging or ESmsConvErmes.


@param	aMessageConversion
The message form specifier.
*/
inline void CSmsMessageSettings::SetMessageConversion(TSmsPIDConversion aMessageConversion)
	{
	iMessageConversion=aMessageConversion;
	}

/** 
Gets the default character set used in the SMS message. 

Text is stored in Unicode on the Symbian OS phone and is converted into the 
appropriate character set when the message is sent.

@return
The default character set for the message.
*/
inline TSmsDataCodingScheme::TSmsAlphabet CSmsMessageSettings::CharacterSet() const
	{
	return iAlphabet;
	}

/**
Sets the default character set used in the SMS message.

Text is stored in Unicode on the Symbian OS phone and is converted into the 
appropriate character set when the message is sent.

@param	aAlphabet
The value of the default character set for the message.
*/
inline void CSmsMessageSettings::SetCharacterSet(TSmsDataCodingScheme::TSmsAlphabet aAlphabet)
	{
	iAlphabet=aAlphabet;
	}

/**
Sets the format in which the validity period should be sent in a SMS-DELIVER 
type message.

This is field TP-VPF from GSM spec 03.40.

@param	aValidityPeriodFormat
The validity period format.
*/
inline void CSmsMessageSettings::SetValidityPeriodFormat(TSmsFirstOctet::TSmsValidityPeriodFormat aValidityPeriodFormat)
	{
	iValidityPeriodFormat = aValidityPeriodFormat;
	}

/** 
Gets the format in which the validity period should be sent in a SMS-DELIVER
type message.

@return
The validity period format.
*/
inline const TSmsFirstOctet::TSmsValidityPeriodFormat CSmsMessageSettings::ValidityPeriodFormat() const
	{
	return iValidityPeriodFormat;
	}

/**
Sets the flag which indicates whether the service center timestamp should
be used for the date field in the TMsvEntry in message store. If the flag
is not set, then the timestamp from the associated CSmsMessage is used.

@param	aUseServiceCenterTimestamp
Flag to indicate whether to use the service center timestamp
*/
inline void CSmsMessageSettings::SetUseServiceCenterTimeStampForDate(TBool aUseServiceCenterTimestamp)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsUseServiceCenterTimeStamp) | (aUseServiceCenterTimestamp ? ESmsSettingsUseServiceCenterTimeStamp : ESmsSettingsNoFlags);
	}

/**
Gets the flag which indicates whether the service center timestamp should
be used for the date field in the TMsvEntry in message store. If the flag
is not set, then the timestamp from the associated CSmsMessage is used.

@return Flag which indcates if service center timestamp will be used.
*/
inline TBool CSmsMessageSettings::UseServiceCenterTimeStampForDate() const
	{
	return iMsgFlags & ESmsSettingsUseServiceCenterTimeStamp;
	}

/**
Gets whether the editor should quote the received message at the beginning of 
the reply message.

@return	
A value of ETrue if the editor should quote the received message at the beginning
of the reply. EFalse if not.
*/
inline TBool CSmsSettings::ReplyQuoted() const
	{
	return iSetFlags&ESmsSettingsReplyQuoted;
	}

/**
Sets whether the editor should quote the received message at the beginning of
the reply message.

@param	aReplyQuited
The value to set the reply-quoted flag to.
*/
inline void CSmsSettings::SetReplyQuoted(TBool aReplyQuoted)
	{
	iSetFlags = (iSetFlags & ~ESmsSettingsReplyQuoted) | (aReplyQuoted?ESmsSettingsReplyQuoted : ESmsSettingsNoFlags);
	}

/** 
Gets the default schedule delivery type of a new message created using the SMS
client MTM.

@return	
The schedule delivery type.
*/
inline TSmsDelivery CSmsSettings::Delivery() const
	{
	return iDelivery;
	}

/** 
Sets the default schedule delivery type of a new message created using the SMS
client MTM.

@param	aDelivery
The schedule delivery type.
*/
inline void CSmsSettings::SetDelivery(TSmsDelivery aDelivery)
	{
	iDelivery=aDelivery;
	}


/**
Gets the way in which status reports that are received by the watcher are handled.

By default, this is EDoNotWatchForReport. This value is not supported and 
therefore the value must be changed from the default.

@return
How SMS status reports are handled.

@see	CSmsSettings::TSmsReportHandling
*/
inline CSmsSettings::TSmsReportHandling CSmsSettings::StatusReportHandling() const
	{
	return iStatusReportHandling;
	}

/**
Sets the way in which status reports that are received by the watcher are handled.

@param	aStatusReportHandling
The SMS status report handling data.

@see	CSmsSettings::TSmsReportHandling
*/
inline void CSmsSettings::SetStatusReportHandling(CSmsSettings::TSmsReportHandling aStatusReportHandling)
	{
	iStatusReportHandling = aStatusReportHandling;
	}

/**
Gets the way in which special messages that are received by the watcher are 
handled. 

By default, this is EDoNotWatchForReport. This value is not supported and 
therefore the value must be changed from the default.

@return
How special messages are handled.

@see	CSmsSettings::TSmsReportHandling
*/
inline CSmsSettings::TSmsReportHandling CSmsSettings::SpecialMessageHandling() const
	{
	return iSpecialMessageHandling;
	}

/**
Sets the way in which special messages that are received by the watcher are 
handled.

@param	aSpecialMessageHandling
The special messages handling data.

@see	CSmsSettings::TSmsReportHandling
*/
inline void CSmsSettings::SetSpecialMessageHandling(CSmsSettings::TSmsReportHandling aSpecialMessageHandling)
	{
	iSpecialMessageHandling = aSpecialMessageHandling;
	}

/**
Sets whether the Service settings should be used to update the communications 
database.

If set, this uses the service settings to update the comms db MODEM table's 
MODEM_MESSAGE_CENTRE_NUMBER, MODEM_MESSAGE_VALIDITY_PERIOD and 
MODEM_MESSAGE_DELIVERY_REPORT fields. The update is done when the Service 
settings are stored into the message store using CSmsSettings::StoreL().

The default setting is for the comms db not to be updated - TSmsSettingsCommDbAction::ENone.

@param	aCommDbAction
The communications database action.

@see	CSmsSettings::TSmsSettingsCommDbAction
@see	CSmsSettings::StoreL
*/
inline void CSmsSettings::SetCommDbAction(CSmsSettings::TSmsSettingsCommDbAction aCommDbAction)
	{
	iCommDbAction = aCommDbAction;
	}

/**
Gets the communications database action.

For details, see CSmsSettings::SetCommDbAction().

@return
The communications database action.

@see	CSmsSettings::TSmsSettingsCommDbAction
@see	CSmsSettings::SetCommDbAction
*/
inline CSmsSettings::TSmsSettingsCommDbAction CSmsSettings::CommDbAction() const
	{
	return iCommDbAction;
	}

/**
Sets whether the Service's SMS bearer setting should be used to update the 
communications database.

If set, this uses the service setting to update the comm db global table's 
SMS_BEARER field. The update is done when the Service settings are stored into 
the message store using CSmsSettings::StoreL().

The default setting is for the comms db not to be updated - TSmsSettingsCommDbAction::ENone.

@param	aSmsBearerAction
The SMS bearer action.

@see	CSmsSettings::TSmsSettingsCommDbAction
@see	CSmsSettings::StoreL
*/
inline void CSmsSettings::SetSmsBearerAction(CSmsSettings::TSmsSettingsCommDbAction aSmsBearerAction)
	{
	iSmsBearerAction = aSmsBearerAction;
	}

/**
Gets the SMS bearer action.

For details, see CSmsSettings::SetCommDbAction().

@return The SMS bearer action. 

@see	CSmsSettings::TSmsSettingsCommDbAction
@see	CSmsSettings::SetSmsBearerAction
*/
inline CSmsSettings::TSmsSettingsCommDbAction CSmsSettings::SmsBearerAction() const
	{
	return iSmsBearerAction;
	}

/**
Sets the SMS bearer.

@param	aSmsBearer
The SMS bearer.
*/
inline void CSmsSettings::SetSmsBearer(CSmsSettings::TMobileSmsBearer aSmsBearer)
	{
	iSmsBearer = aSmsBearer;
	}

/**
Gets the SMS bearer.

@return
The SMS bearer.
*/
inline CSmsSettings::TMobileSmsBearer CSmsSettings::SmsBearer() const
	{
	return iSmsBearer;
	}

/**
Sets the folder ID into which received class 2 SMS-DELIVER messages are stored.

@param	aId
The folder ID for received class 2 messages.
*/
inline void CSmsSettings::SetClass2Folder(TMsvId aId)
	{
	iClass2Folder = aId;
	}

/**
Gets the folder ID into which received class 2 SMS-DELIVER messages are stored.

@return
The class 2 folder ID.
*/
inline TMsvId CSmsSettings::Class2Folder() const
	{
	return iClass2Folder;
	}

/**
Sets the maximum length of the message entry description.

The default value is given by KSmsDescriptionLength.

@param	aDescriptionLength
The maximum length.

@see	KSmsDescriptionLength
*/
inline void CSmsSettings::SetDescriptionLength(TInt aDescriptionLength)
	{
	iDescriptionLength = aDescriptionLength;
	}

/**
Gets the maximum length of the message entry description.

@return
The maximum length of the message entry description.

@see	KSmsDescriptionLength
*/
inline TInt CSmsSettings::DescriptionLength() const
	{
	return iDescriptionLength;
	}

/**
Sets the boolean flag that indicates whether to discard unknown port message.

A value of ETrue indicates that discard unknown port message, 
it will be done without indicating the user.

@param   aDeleteMsg
The value of the discard message flag.
*/
inline void CSmsSettings::SetDiscardUnknownPortMessage(TBool aDeleteMessage) 
    {
    iSetFlags = (iSetFlags & ~ESmsSettingsDiscardUnknownPortMsgs) | (aDeleteMessage ? ESmsSettingsDiscardUnknownPortMsgs : ESmsSettingsNoFlags);
    }

/**
Gets the boolean flag that indicates whether to discard unknown port message.

A value of ETrue indicates to discard unknown port message.

@return
The value of the discard message flag.
*/
inline TBool CSmsSettings::DiscardUnknownPortMessage() const
    {
    return iSetFlags & ESmsSettingsDiscardUnknownPortMsgs;
    }
	
/**
Gets the ID by which to identify the SMS-DELIVER message PDU for this recipient.

@return	
The log ID for this recipient.
*/
inline TLogId CSmsNumber::LogId() const
	{
	return iLogId;
	}

/** 
Sets the ID by which to identify the SMS-DELIVER message PDU for this recipient.

@param	aLogId	
The log ID for this recipient.
*/
inline void CSmsNumber::SetLogId(TLogId aLogId)
	{
	iLogId = aLogId;
	}

/**
Tests if a status report (TP-SRR in GSM spec 03.40) for the last segment will be requested from 
the Service Centre.

A value of ETrue indicates that a status report will be requested for the last segment.

@return	
The value of the Status report flag only for the last segment.
*/

inline TBool CSmsMessageSettings::LastSegmentDeliveryReport() const
	{
	return iMsgFlags & ESmsSettingsLastSegmentDeliveryReport;
	}

/** 
Sets if a status report (TP-SRR in GSM spec 03.40) for the last segment will be requested from the
Service Centre.

A value of ETrue indicates that a status report will be requested for the last segment.

@param	aDeliveryReport	
The value of the status report flagfor the last segment.
*/

inline void CSmsMessageSettings::SetLastSegmentDeliveryReport(TBool aDeliveryReport)
	{
	iMsgFlags = (iMsgFlags & ~ESmsSettingsLastSegmentDeliveryReport) | (aDeliveryReport?ESmsSettingsLastSegmentDeliveryReport : ENoSmsSettingsLastSegmentDeliveryReport);
	}