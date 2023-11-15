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
* Filename: Instrumentationhandler.h
* 
*
*/


 
#if !(defined __INSTRUMENTATION_HANDLER_H__)
#define __INSTRUMENTATION_HANDLER_H__

/*******************************************************************************
 *
 * System Includes
 *
 ******************************************************************************/
 
 #include<e32std.h>
 #include <e32base.h>
 
 /*******************************************************************************
 *
 * User Includes
 *
 ******************************************************************************/
 #include "systemmonitor/configuration.h"
 #include "systemmonitor/systemmonitor.h"
 #include "systemmonitor/eventlog.h"
 
/*******************************************************************************
 *
 * Macros
 *
 ******************************************************************************/
 
 #ifdef SM_INSTRUMENTATION_OFF
 #define RAISE_NOTIFICATION(a)
 #define RAISE_NOTIFICATION_AFTER(a)
 #else
 #define RAISE_NOTIFICATION(a)\
 	{\
 	CInstrumentationHandler* lInstrumentationHandler;\
 	lInstrumentationHandler = CInstrumentationHandler::NewL();\
 	lInstrumentationHandler->RaiseEventNotification(a);\
 	delete lInstrumentationHandler;\
 	}
 #define RAISE_NOTIFICATION_AFTER(a)\
 	{\
 	CInstrumentationHandler* lInstrumentationHandler;\
 	lInstrumentationHandler = CInstrumentationHandler::NewL();\
 	lInstrumentationHandler->RaiseEventNotificationAfter(a);\
 	delete lInstrumentationHandler;\
 	}
 #endif
 
 #ifdef SM_INSTRUMENTATION_NO_DELETE_OFF
 #define RAISE_NOTIFICATION_NO_DELETE(a)
 #define RAISE_NOTIFICATION_AFTER_NO_DELETE(a)
 #else
 #define RAISE_NOTIFICATION_NO_DELETE(a)\
 	{\
 	CInstrumentationHandler* lInstrumentationHandler;\
 	lInstrumentationHandler = CInstrumentationHandler::NewL();\
 	lInstrumentationHandler->RaiseEventNotification(a);\
 	}
 #define RAISE_NOTIFICATION_AFTER_NO_DELETE(a)\
 	{\
 	CInstrumentationHandler* lInstrumentationHandler;\
 	lInstrumentationHandler = CInstrumentationHandler::NewL();\
 	lInstrumentationHandler->RaiseEventNotificationAfter(a);\
 	}
 #endif
 

/*******************************************************************************
 *
 * Class Definitions
 *
 ******************************************************************************/

/**
CInstrumentationHandler: Implements RaiseEventNotification to enable code to be instrumented.
@publishedAll
@test
*/

class CInstrumentationHandler : public CBase
  	{
public:
	// Construction
	IMPORT_C static CInstrumentationHandler* NewLC();
	IMPORT_C static CInstrumentationHandler* NewL();
	// Destructor - virtual and class not intended
	// for derivation, so not exported
	~CInstrumentationHandler();
	// general functions - exported
	IMPORT_C void RaiseEventNotification(TInt aEventTag);
	IMPORT_C void RaiseEventNotificationAfter(TInt aEventTag);
	
	IMPORT_C TInt GetRecordCount(void);
	IMPORT_C void CopyRecord(TInstrumentationEventInformation* aRecord, TInt aIndex);
	IMPORT_C void ClearLog();
	IMPORT_C TInt SetLogBufferSizeL(TInt aLogBufferSize);
	IMPORT_C CConfiguration* Configuration();

private: 
	// C++ constructor - not exported;
	// implicitly called from NewLC()
	CInstrumentationHandler();
	// 2nd phase construction, called by NewLC()
	void ConstructL(); // second-phase constructor
	TBool ConfiguredForRecordAndEvent(TInt aEventTag);
	
	//This function creates the global chunk with specified size
	void CreateChunkL(TInt aChunkSize);
	
private:
	RChunk iChunk;  //global object
	TProcessId iProcessId;
	CConfiguration* iConfiguration;
	CEventLog* iEventLog;
	CSystemMonitorError iSystemMonitorError;
	};
	
#endif

