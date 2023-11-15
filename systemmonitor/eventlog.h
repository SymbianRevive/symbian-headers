/**
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Filename: EventLog.h
* 
*
*/


 
#if !(defined __EVENTLOG_H__)
#define __EVENTLOG_H__

/*******************************************************************************
 *
 * System Includes
 *
 ******************************************************************************/
  
 #include<e32std.h>
 
 /*******************************************************************************
 *
 * User Includes
 *
 ******************************************************************************/
 
#include "systemmonitor/recordtypes.h"
#include "systemmonitor/locking.h"
 
/*******************************************************************************
 *
 * Definitions
 *
 ******************************************************************************/
 
 _LIT(KEVENT_LOG_SEMAPHORE,"EventLogSemaphore");
 
/*******************************************************************************
*
* Type definitions
*
******************************************************************************/

/**
CGlobalEventLogVars: Encapsulates the variables whose values must be shared between the instrumentation handler and the SystemMonitor.
@publishedAll
@test
*/

typedef struct 
	{
	TInt iFirstRecord;
	TInt iNextRecord;
	TInt iRecordCount;
	TInt iMaxRecords;
	TInt iLock;
	TInt iMagicValue1;
	TInt iMagicValue2;
	}CGlobalEventLogVars;
 
/*******************************************************************************
 *
 * Class Definitions
 *
 ******************************************************************************/
 
/**
CEventLog: Implements append, read and count, to manage EventLog records.
@publishedAll
@test
*/

class CEventLog
	{
public:

	IMPORT_C void Append(TInstrumentationEventInformation* iEventInformation,TBool aIsTSBeforeCriticalSection);
	IMPORT_C void Read(TInstrumentationEventInformation* aRecord);
	IMPORT_C TInt Count();
	IMPORT_C void CopyRecord(TInstrumentationEventInformation* aEventInformation, TInt aIndex);
	IMPORT_C void ClearLog();

	// Construction
	IMPORT_C CEventLog(TInstrumentationEventInformation* aRecordsStart,CGlobalEventLogVars* aGlobalEventLog,TInt aBufferSize,TBool aCreatedChunk);
	IMPORT_C ~CEventLog();
private:
	void PerformOperation(const TInstrumentationEventInformation* const aEventInformation);
private:
	CGlobalEventLogVars* iGlobalEventLogVars;
	TInstrumentationEventInformation* iBufferStart;
	CSystemMonitorLock iSystemMonitorLock;
	CConsoleBase* iConsole; // write all your messages to this
	};

#endif

