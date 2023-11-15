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
* Filename: SystemMonitor.h
* 
*
*/


 
#if !(defined __SYSTEMMONITOR_H__)
#define __SYSTEMMONITOR_H__

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
 #include "systemmonitor/systemmonitorerrors.h"
 #include "systemmonitor/configuration.h"
 
 /*******************************************************************************
 *
 * Definitions
 *
 ******************************************************************************/
 
 #define RCHUNKSIZE 49152
 #define RCHUNKMAXSIZE 524288   // Maximum size of the global chunk
 #define SMSTARTDELAY 1 //1 microsend delay before starting cperiodic
 _LIT(KSYSTEMMONITORGLOBALCHUNK,"SYSTEM_MONITOR_GLOBAL_CHUNK");

/*******************************************************************************
 *
 * Forward Declarations
 *
 ******************************************************************************/
 
 class CCentralGatherer;

/*******************************************************************************
 *
 * Interface Definitions
 *
 ******************************************************************************/

/**
MSystemMonitorNotification: Interface call that all registering components must implement. 
@publishedAll
@test
*/


class MSystemMonitorNotification
	{
public:
 	virtual void HandleData(RPointerArray<TSystemMonitorRecordBase>& aRecordArray, CSystemMonitorError& aSystemMonitorError) = 0;
	};

/*******************************************************************************
 *
 * Class Definitions
 *
 ******************************************************************************/

/**
CSystemMonitor: Main interface to the tool, allows the user to collect information on a one off basis, 
and to register for periodic updates.
@publishedAll
@test
*/

class CSystemMonitor : public CBase
  	{
public:
	// Construction
	IMPORT_C static CSystemMonitor* NewLC(TInt aChunkSize=0);
	IMPORT_C static CSystemMonitor* NewL(TInt aChunkSize=0);
	~CSystemMonitor();
	// general functions - exported
	IMPORT_C void StartL(TInt aInterval,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C void Stop();
	IMPORT_C void Register(MSystemMonitorNotification* aCallBack);
	IMPORT_C void Unregister();
	IMPORT_C void GetLatest(RPointerArray<TSystemMonitorRecordBase>& aRecordArray, CSystemMonitorError& aSystemMonitorError);
	IMPORT_C CConfiguration* Configuration();
private: 
		// C++ constructor - not exported;
		// implicitly called from NewLC()
	CSystemMonitor();
		// 2nd phase construction, called by NewLC()
	void ConstructL(TInt iChunkSize); // second-phase constructor
	static TInt Run(TAny* aThis);
	void OpenGlobalChunkL();
	void CreateGlobalChunkL();
private:
    MSystemMonitorNotification* iCallBack;
	CPeriodic* iPeriodic;
	CSystemMonitorError iSystemMonitorError;
	RPointerArray<TSystemMonitorRecordBase>iRecordArray;
	CConfiguration* iConfiguration;
	CCentralGatherer* iCentralGatherer;
	TFindChunk iFindChunk;
	TBool iCreatedChunk;
	RChunk iChunk;  //global object
	TInt iChunkSize;
	};
	
#endif

