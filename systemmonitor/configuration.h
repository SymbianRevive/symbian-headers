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
* Filename: Configuration.h
* 
*
*/


 
#if !(defined __CONFIGURATION_H__)
#define __CONFIGURATION_H__

/*******************************************************************************
 *
 * System Includes
 *
 ******************************************************************************/
 
 #include<e32def.h>
 
 /*******************************************************************************
 *
 * User Includes
 *
 ******************************************************************************/
 
 #include "systemmonitor/systemmonitorerrors.h"
 #include "systemmonitor/recordtypes.h"
 
/********************************************************************************
 *
 * Types
 *
 ********************************************************************************/

/** Defines the types of all data gatherers.
@publishedAll
@test
*/

typedef enum {
	SM_API_GATHERER,
	SM_INSTRUMENTATION_GATHERER,
	SM_DDEBUG_GATHERER,
	SM_TEST_GATHERER
} TGathererTypeID;

/********************************************************************************
 *
 * Constants
 *
 ********************************************************************************/
 
const TInt MAXMASKS=16;

/*******************************************************************************
 *
 * Class Definitions
 *
 ******************************************************************************/
 

/**
CConfiguration: Allows data gatherers to be turned on or off. Also allow masks to be set to 
block particular items of information. 
@publishedAll
@test
*/

class CConfiguration : public CBase
 	{
 	
public:
	// Construction
	CConfiguration();
	IMPORT_C void Construct( TBool aCreatedChunk );
	~CConfiguration(); 
	// Getter and setter
	IMPORT_C TBool GetGathererOption(TGathererTypeID aOption,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C void  SetGathererOption(TGathererTypeID aOption,TBool aSetting,CSystemMonitorError& aSystemMonitorError);	
	IMPORT_C void  SetRecordTypeOption(TRecordTypeID aRecord,TBool aSetting,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C TBool GetRecordTypeOption(TRecordTypeID aRecord,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C TInt* GetMasks(TInt& aSize);
	IMPORT_C void  SetMasks(TInt aMasks[],TInt aSize,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C void  AddMasks(TInt aMasks[],TInt aSize,CSystemMonitorError& aSystemMonitorError);
	IMPORT_C void ClearMasks();
	IMPORT_C TBool EventTagConfigured(TInt aEventTag);
private:
	
private:
	//Gatherers
	TBool iAPIGatherer;
	TBool iInstrumentationGatherer;
	TBool iDDebugGatherer;
	TBool iTestGatherer;
	//Record typeid's
	TBool iDynamicSystemInformation;
	TBool iStaticSystemInformation;
	TBool iProcessStartTime;
	TBool iProcessEndTime;
	TBool iProcessExitInformation;
	TBool iDynamicProcessInformation;
	TBool iStaticProcessInformation;
	TBool iThreadStartTime;
	TBool iThreadEndTime;	
	TBool iThreadExitInformation;	
	TBool iDynamicThreadInformation;
	TBool iStaticThreadInformation;
	TBool iEventLogInformation;
	TBool iZombieProcessRemovedInformation;
	TBool iZombieThreadRemovedInformation;
	
	TInt iMasks[MAXMASKS];
	TInt iMaskCount;
	};
 		
 #endif
