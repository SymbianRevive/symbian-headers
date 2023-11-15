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
* Filename: SystemMonitorErrors.h
* 
*
*/


 
#if !(defined __SYSTEMMONITORERRORS_H__)
#define __SYSTEMMONITORERRORS_H__

/*******************************************************************************
 *
 * System Includes
 *
 ******************************************************************************/
 
 #include <e32base.h>

 /*******************************************************************************
 *
 * Definitions
 *
 ******************************************************************************/
 
 #define SM_ERROR_STACK_SIZE 8
  
/********************************************************************************
 *
 * Types
 *
 ********************************************************************************/

/** Defines the types errors that can occur.
@publishedAll
@test
*/

typedef enum {
	SM_CONFIG_UNKNOWN_GATHERER,					//from CConfiguration, unknow gatherer
	SM_CONFIG_UNKNOWN_RECORDTYPE,				//from CConfiguration, unknow record type
	SM_CONFIG_MASK_OVERFLOW,					//from CConfiguration, the maximum number was exceeded 
	SM_SYSTEM_MONITOR_CONFIG_CHUNK_ALLOCATION,  //from CSystemMonitor, unable to allocate rchunk
	SM_SYSTEM_MONITOR_CENTRAL_GATHERER,			//from CSystemMonitor, error returned from CCentralGatherer
	SM_SYSTEM_MONITOR_NOT_REGISTERED,			//from CSystemMonitor, user tried to start periodic updates before registering
	SM_CENTRAL_GATHERER_CONFIG,					//from CCentralGatherer, error reading the configuration
	SM_CENTRAL_GATHERER_API_GATHERER,			//from CCentralGatherer, error returned from CAPIGatherer
	SM_CENTRAL_GATHERER_DDEBUG_GATHERER,		//from CCentralGatherer, error returned from CDDebugGatherer
	SM_CENTRAL_GATHERER_TEST_GATHERER,			//from CCentralGatherer, error returned from CInstGatherer
	SM_INSTRUMENTATION_GATHERER_READ,			//from CInstrumentationGatherer, error reading from chunk
	SM_INSTRUMENTATION_GATHERER_CONFIG,			//from CInstrumentationGatherer, error using the config
	SM_TEST_GATHERER_CONFIG,					//from CTestGatherer, error using the config
	SM_EVENTLOGPLUGIN_ERROR_STARTING_THREAD,	//from CEventLogControler, error creating thread
	SM_EVENTLOGPLUGIN_THREAD_ALREADY_RUNNING,	//from CEventLogControler, thread already  running
	SM_EVENTLOGPLUGIN_ERROR_APPENDING_RECORD,	//from CEventLogControler, error appending record to local log
	SM_EVENTLOGPLUGIN_ERROR_STARTING_SYSTEMMONITOR, //from CEventLogControler, error staring the system monitor
	SM_UTILITIES_OPEN_CHUNK, 					//from utilites function, error opening rchunk
	SM_UTILITIES_CREATE_CHUNK, 					//from utilites function, error creating rchunk
	SM_SYSTEM_MONITOR_UTILITIES, 				//from CSystemMonitor error from utility function
	SM_INSTRUMENTATION_GATHERER_UTILITIES, 		//from CInstrumentationGatherer error from utility function
	SM_API_GATHERER_CONFIG,						//from CAPIGatherer, error using the config
	SM_API_GATHERER_STATIC_SYSTEM_DATA, 		//from CAPIGatherer error collecting static system data
	SM_API_GATHERER_DYNAMIC_SYSTEM_DATA, 		//from CAPIGatherer error collecting dynamic system data
	SM_API_GATHERER_STATIC_PROCESS_DATA, 		//from CAPIGatherer error collecting static process data
	SM_API_GATHERER_DYNAMIC_PROCESS_DATA, 		//from CAPIGatherer error collecting dynamic process data
	SM_API_GATHERER_PROCESS_START_TIME_DATA,	//from CAPIGatherer error collecting process start time data
	SM_API_GATHERER_PROCESS_END_TIME_DATA, 		//from CAPIGatherer error collecting process end time data
	SM_API_GATHERER_PROCESS_EXIT_DATA, 			//from CAPIGatherer error collecting process exit information
	SM_API_GATHERER_STATIC_THREAD_DATA, 		//from CAPIGatherer error collecting static thread data
	SM_API_GATHERER_DYNAMIC_THREAD_DATA, 		//from CAPIGatherer error collecting dynamic thread data
	SM_API_GATHERER_THREAD_START_TIME_DATA,		//from CAPIGatherer error collecting thread start time data
	SM_API_GATHERER_THREAD_END_TIME_DATA, 		//from CAPIGatherer error collecting thread end time data
	SM_API_GATHERER_THREAD_EXIT_DATA, 			//from CAPIGatherer error collecting thread exit information
	SM_API_GATHERER_TOTAL_SYSTEM_RAM,			//from CAPIGatherer error collecting total system RAM
	SM_API_GATHERER_TOTAL_SYSTEM_ROM,			//from CAPIGatherer error collecting total system ROM
	SM_API_GATHERER_FREE_SYSTEM_RAM,			//from CAPIGatherer error collecting free system RAM
	SM_API_GATHERER_OPENING_PROCESS,			//from CAPIGatherer error opening a handle to a process
	SM_API_GATHERER_OPENING_THREAD,				//from CAPIGatherer error opening a handle to a thread
	SM_API_GATHERER_THREAD_TO_PARENT_PROCESS,	//from CAPIGatherer error opening a handle to a threads parent process
	SM_API_GATHERER_THREAD_CPUTIME,				//from CAPIGatherer error retrieving a threads cpu time
	SM_API_GATHERER_READING_RAMSIZES,			//from CAPIGatherer error calling getramsizes
	SM_API_GATHERER_THREAD_STACK_INFO,			//from CAPIGatherer error retrieving a threads stack information
	SM_NO_ERROR									//Initial setting for all elements in the error stack	
} SM_ErrorID;


/*******************************************************************************
 *
 * Class Definitions
 *
 ******************************************************************************/
 
/**
CSystemMonitorError: Manages a stack system of CSystemMonitorError error messages. 
@publishedAll
@test
*/


class CSystemMonitorError : public CBase
  	{
public:
	// Construction / Destructor
	IMPORT_C CSystemMonitorError();
	IMPORT_C ~CSystemMonitorError();
	// general functions - exported
	IMPORT_C CSystemMonitorError& operator=(const CSystemMonitorError& aErrorObj);
	IMPORT_C TBool Push(SM_ErrorID aError);
	IMPORT_C TBool Error();
	IMPORT_C TBool Previous(SM_ErrorID& aErrorType);
	IMPORT_C TBool Last(SM_ErrorID& aErrorType);
	IMPORT_C void Clear();
	IMPORT_C void GetErrorMessage(SM_ErrorID aError,TBuf<124>& aErrorMsg);
private: 
	
private:
	SM_ErrorID iStack [SM_ERROR_STACK_SIZE];
	TInt iPreviousError;
	TInt iNextError;
	};
	
#endif

