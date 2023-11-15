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
* Filename: RecordTypes.h
* 
*
*/


 
#if !(defined __RECORDTYPES_H__)
#define __RECORDTYPES_H__

/**********************************************************************************
 *
 * System Includes
 *
 **********************************************************************************/
 
 #include<e32def.h>
 #include<e32std.h>

/**********************************************************************************
 *
 * User Includes
 *
 **********************************************************************************/
 
 #include "systemmonitor/systemmonitorerrors.h"

/**********************************************************************************
 *
 * Definition 
 *
 **********************************************************************************/

 #define SMT_HOUR_MASK			(0x0000001F)
 #define SMT_MINUTE_MASK		(0x0000003F)
 #define SMT_SECOND_MASK		(0x0000003F)
 #define SMT_MILLISECOND_MASK	(0x000003FF)
 #define COMMANDLINE_LENGTH		80
 
/**********************************************************************************
 *
 * Types
 *
 **********************************************************************************/

/**
TSystemMonitorTime: Bitfields used to store the time of record creation. 
@publishedAll
@test
*/

struct TSystemMonitorTime  //27 bits rounded to 4 bytes
	{
	int iHour 			:  5;
	int iMinute			:  6;
	int iSecond			:  6;
	int iMilliSecond  	:  10;
	};
	
/** Defines the types records that can exist.
@publishedAll
@test
*/
	
typedef enum {
	SM_REC_ID_DYNAMIC_SYSTEM_INFORMATION,
	SM_REC_ID_STATIC_SYSTEM_INFORMATION,
	SM_REC_ID_PROCESS_START_TIME,
	SM_REC_ID_PROCESS_END_TIME,
	SM_REC_ID_PROCESS_EXIT_INFORMATION,	
	SM_REC_ID_DYNAMIC_PROCESS_INFORMATION,
	SM_REC_ID_STATIC_PROCESS_INFORMATION,
	SM_REC_ID_THREAD_START_TIME,
	SM_REC_ID_THREAD_END_TIME,
	SM_REC_ID_THREAD_EXIT_INFORMATION,						
	SM_REC_ID_DYNAMIC_THREAD_INFORMATION,
	SM_REC_ID_STATIC_THREAD_INFORMATION,
	SM_REC_ID_EVENT_LOG_INFORMATION,
	SM_REC_ID_EVENT_LOG_OVERFLOW,
	SM_REC_ID_APIGATHERER_ERROR,
	SM_REC_ID_ZOMBIE_PROCESS_REMOVED,
	SM_REC_ID_ZOMBIE_THREAD_REMOVED
} TRecordTypeID;


/******************************************************************************
 *
 * TSystemMonitorRecordBase
 *
 ******************************************************************************/
 
struct TSystemMonitorTime;

/******************************************************************************
 *
 * TSystemMonitorRecordBase
 *
 ******************************************************************************/
 
/**
TSystemMonitorRecordBase: Base class of all record type classes. Implements GetType() 
to return the type of the sub classed record. 
@publishedAll
@test
*/


class TSystemMonitorRecordBase
 	{
 	
public:
	// Construction
	IMPORT_C TSystemMonitorRecordBase(TRecordTypeID aType);
	
	IMPORT_C ~TSystemMonitorRecordBase();
	// general functions
	IMPORT_C TRecordTypeID GetType();
	IMPORT_C void TypeAsString(TBuf<124>& aRecordType);
	IMPORT_C void TypeRetrievingAsString(TBuf<124>& aRecordType,TRecordTypeID aTypeRetrieving);
	
protected:
	TSystemMonitorTime iTime;
private:
	TRecordTypeID iType;
	};
	

/******************************************************************************
 *
 * TStaticSystemInformation
 *
 ******************************************************************************/
	
/**
TStaticSystemInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store static system information.
@publishedAll
@test
*/

class TStaticSystemInformation : public TSystemMonitorRecordBase
	{
public:
	TStaticSystemInformation(TInt aTotalRAM,TInt aTotalROM);
	IMPORT_C TInt GetTotalRAM();
	IMPORT_C TInt GetTotalROM();
private:
	TInt iTotalRAM;
	TInt iTotalROM;
	};
	
/******************************************************************************
 *
 * TDynamicSystemInformation
 *
 ******************************************************************************/
	
/**
TDynamicSystemInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store dynamic system information.
@publishedAll
@test
*/

class TDynamicSystemInformation : public TSystemMonitorRecordBase
	{
public:
	TDynamicSystemInformation(TInt aFreeRAM);

	IMPORT_C TInt GetFreeRAM();
private:
	TInt iFreeRAM;
	};


/******************************************************************************
 *
 * TStaticProcessInformation
 *
 ******************************************************************************/
	
/**
TStaticProcessInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store static process information.
@publishedAll
@test
*/

class TStaticProcessInformation : public TSystemMonitorRecordBase
	{
public:
	
	TStaticProcessInformation(TProcessId aID,TProcessId aParentID,TFileName& aFileName,
 							  TBuf<COMMANDLINE_LENGTH>& aCommandLine,TInt aCodeSize,TInt aConstDataSize,
 							  TInt aInitialisedDataSize,TInt aUninitialisedDataSize);
								
	IMPORT_C TProcessId GetID();
	IMPORT_C TProcessId GetParentID();
	IMPORT_C TFileName GetFileName();
	IMPORT_C void GetCommandLine(TBuf<COMMANDLINE_LENGTH>& aCommandLine);
	IMPORT_C TInt GetCodeSize();
	IMPORT_C TInt GetConstDataSize();
	IMPORT_C TInt GetInitialisedDataSize();
	IMPORT_C TInt GetUnitialisedDataSize();
	
private:
	TProcessId  iID;
	TProcessId  iParentID;
	TFileName iFileName;
	TBuf <COMMANDLINE_LENGTH> iCommandLine;
	TInt iCodeSize; 
	TInt iConstDataSize; 
	TInt iInitialisedDataSize; 
	TInt iUninitialisedDataSize; 
	};

/******************************************************************************
 *
 * TDynamicProcessInformation
 *
 ******************************************************************************/
	
/**
TDynamicProcessInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store dynamic process information.
@publishedAll
@test
*/

class TDynamicProcessInformation : public TSystemMonitorRecordBase
	{
public:
	TDynamicProcessInformation(TProcessId aID,TBool aProtected,TProcessPriority aPriority);
								
	IMPORT_C TProcessId GetID();
	IMPORT_C TBool GetProtected();
	IMPORT_C TProcessPriority GetPriority();
private:
	TProcessId  iID;
	TBool iProtected;
	TProcessPriority iPriority;
	};
	
			
/******************************************************************************
 *
 * TInstrumentationEventInformation
 *
 ******************************************************************************/
 
 /**
TInstrumentationEventInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store instrumentation record information.
@publishedAll
@test
*/

class TInstrumentationEventInformation : public TSystemMonitorRecordBase
	{
public:

	IMPORT_C TInstrumentationEventInformation(TInt aEventTag,TProcessId aProcessId,TThreadId aThreadId);
	IMPORT_C TInt GetEventTag();
	IMPORT_C TProcessId GetProcessId();
	IMPORT_C TThreadId GetThreadId();
	IMPORT_C TSystemMonitorTime GetDateTime();
	
private:
	TInt iEventTag;
	TProcessId iProcessId;
	TThreadId iThreadId;
	};
		
/******************************************************************************
 *
 * TInstrumentationEventOverflow
 *
 ******************************************************************************/

 /**
TInstrumentationEventOverflow: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating a data overflow.
@publishedAll
@test
*/

class TInstrumentationEventOverflow : public TSystemMonitorRecordBase
	{
public:
	IMPORT_C TInstrumentationEventOverflow();
	};

/******************************************************************************
 *
 * TProcessStartTime
 *
 ******************************************************************************/

 /**
TProcessStartTime: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating process start times.
@publishedAll
@test
*/

class TProcessStartTime : public TSystemMonitorRecordBase
	{
public:
	TProcessStartTime(TProcessId aID,TBool aPredatesTool);
	IMPORT_C TProcessId GetID();
	IMPORT_C TSystemMonitorTime GetDateTime();
	IMPORT_C TBool GetPredatesTool();
private:
	TProcessId  iID;
	TBool iPredatesTool;
	};

/******************************************************************************
 *
 * TProcessEndTime
 *
 ******************************************************************************/

 /**
TProcessEndTime: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating process end times.
@publishedAll
@test
*/

class TProcessEndTime : public TSystemMonitorRecordBase
	{
public:
	TProcessEndTime(TProcessId aID);
	IMPORT_C TProcessId GetID();
	IMPORT_C TSystemMonitorTime GetDateTime();
private:
	TProcessId  iID;
	};

/******************************************************************************
 *
 * TProcessExitInformation
 *
 ******************************************************************************/

 /**
TProcessExitInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating process exit information.
@publishedAll
@test
*/

class TProcessExitInformation : public TSystemMonitorRecordBase
	{
public:
	TProcessExitInformation(TProcessId aID,TExitType aExitType,TInt iExitReason,TExitCategoryName aExitCategoryName);
	IMPORT_C TProcessId GetID();
	IMPORT_C TExitType GetExitType();
	IMPORT_C TInt GetExitReason();
	IMPORT_C TExitCategoryName GetExitCategory();
private:
	TProcessId  iID;
	TExitType iExitType; 
	TInt iExitReason;
	TExitCategoryName iExitCategoryName;
	};

/******************************************************************************
 *
 * TStaticThreadInformation
 *
 ******************************************************************************/
	
/**
TStaticThreadInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store static thread information.
@publishedAll
@test
*/

class TStaticThreadInformation : public TSystemMonitorRecordBase
	{
public:
	
	TStaticThreadInformation(TThreadId aID,TProcessId aParentID,TFullName& aName);
								
	IMPORT_C TThreadId GetID();
	IMPORT_C TProcessId GetParentProcessID();
	IMPORT_C TFullName GetName();

private:
	TThreadId  iID;
	TProcessId  iParentID;
	TFullName  iName;
	};
		
/******************************************************************************
 *
 * TThreadStartTime
 *
 ******************************************************************************/

 /**
TThreadStartTime: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating thread start times.
@publishedAll
@test
*/

class TThreadStartTime : public TSystemMonitorRecordBase
	{
public:
	TThreadStartTime(TThreadId aID,TBool aPredatesTool);
	IMPORT_C TThreadId GetID();
	IMPORT_C TSystemMonitorTime GetDateTime();
	IMPORT_C TBool GetPredatesTool();
private:
	TThreadId  iID;
	TBool iPredatesTool;
	};


/******************************************************************************
 *
 * TThreadEndTime
 *
 ******************************************************************************/

 /**
TThreadEndTime: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating thread end times.
@publishedAll
@test
*/

class TThreadEndTime : public TSystemMonitorRecordBase
	{
public:
	TThreadEndTime(TThreadId aID);
	IMPORT_C TThreadId GetID();
	IMPORT_C TSystemMonitorTime GetDateTime();
private:
	TThreadId  iID;
	};


/******************************************************************************
 *
 * TThreadExitInformation
 *
 ******************************************************************************/

 /**
TThreadExitInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store a record indicating thread exit information.
@publishedAll
@test
*/

class TThreadExitInformation : public TSystemMonitorRecordBase
	{
public:
	TThreadExitInformation(TThreadId aID,TProcessId aParentID,TExitType aExitType,TInt aExitReason,TExitCategoryName aExitCategoryName);
	IMPORT_C TThreadId GetID();
	IMPORT_C TProcessId GetParentProcessID();
	IMPORT_C TExitType GetExitType();
	IMPORT_C TInt GetExitReason();
	IMPORT_C TExitCategoryName GetExitCategory();
private:
	TThreadId  iID;
	TProcessId  iParentID;
	TExitType iExitType; 
	TInt iExitReason;
	TExitCategoryName iExitCategoryName;
	};

/******************************************************************************
 *
 * TDynamicThreadInformation
 *
 ******************************************************************************/
	
/**
TDynamicThreadInformation: Inherits from TSystemMonitorRecordBase, modifies it 
to store dynamic thread information.
@publishedAll
@test
*/

class TDynamicThreadInformation : public TSystemMonitorRecordBase
	{
public:
	
	TDynamicThreadInformation(TThreadId aID,TThreadPriority aPriority,TBool aProtected,TTimeIntervalMicroSeconds aCPUTime,TInt aProcessHandleCount,
							  TInt aThreadHandleCount,TInt aRequestCount,TInt aHeapSize,TInt aStackSize);
			
	IMPORT_C TThreadId GetID();					
	IMPORT_C TThreadPriority GetPriority();
	IMPORT_C TBool GetProtected();
	IMPORT_C TTimeIntervalMicroSeconds GetCPUTime();
	IMPORT_C TInt GetProcessHandleCount();
	IMPORT_C TInt GetThreadHandleCount();
	IMPORT_C TInt GetRequestCount();
	IMPORT_C TInt GetHeapSize();
	IMPORT_C TInt GetStackSize();

private:
	TThreadId  iID;
	TThreadPriority iPriority;
	TBool iProtected;
	TTimeIntervalMicroSeconds iCPUTime;
	TInt iProcessHandleCount;
	TInt iThreadHandleCount;
	TInt iRequestCount;
	TInt iHeapSize;
	TInt iStackSize;

	};

/******************************************************************************
 *
 * TAPIGathereError
 *
 ******************************************************************************/

 /**
TAPIGathereError: Inherits from TSystemMonitorRecordBase, modifies it 
to store APIGatherer error data.
@publishedAll
@test
*/

class TAPIGathereError : public TSystemMonitorRecordBase
	{
public:
	TAPIGathereError(TRecordTypeID aRecordTypeID,SM_ErrorID aErrorID, TInt aErrorCode);
	IMPORT_C TRecordTypeID RetrievingRecordType();
	IMPORT_C SM_ErrorID ErrorID();
	IMPORT_C TInt ErrorCode();
private:
	TRecordTypeID iRetrievingRecordType;
	SM_ErrorID iErrorID;
	TInt iErrorCode;
	};
	
/******************************************************************************
 *
 * TZombieProcessRemoved
 *
 ******************************************************************************/

 /**
TZombieProcessRemoved: Inherits from TSystemMonitorRecordBase, modifies it 
to store Zombie Process Removed data.
@publishedAll
@test
*/

class TZombieProcessRemoved : public TSystemMonitorRecordBase
	{
public:
	TZombieProcessRemoved(TProcessId aID,TFullName aName);
	IMPORT_C TProcessId GetID();
	IMPORT_C TFullName GetName();
private:
	TProcessId iID;
	TFullName iName;
	};
	
/******************************************************************************
 *
 * TZombieThreadRemoved
 *
 ******************************************************************************/

 /**
TZombieThreadRemoved: Inherits from TSystemMonitorRecordBase, modifies it 
to store Zombie Thread Removed data.
@publishedAll
@test
*/

class TZombieThreadRemoved : public TSystemMonitorRecordBase
	{
public:
	TZombieThreadRemoved(TThreadId aID,TFullName aName);
	IMPORT_C TThreadId GetID();
	IMPORT_C TFullName GetName();
private:
	TThreadId iID;
	TFullName iName;
	};

 #endif


