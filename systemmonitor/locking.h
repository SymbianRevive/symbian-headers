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
* Filename: Locking.h
* 
*
*/


 
#if !(defined __LOCKING_H__)
#define __LOCKING_H__

/*******************************************************************************
 *
 * System Includes
 *
 *******************************************************************************/
 
 #include<e32std.h>
  
/*******************************************************************************
 *
 * Class Definitions
 *
 *******************************************************************************/

 /**
CSystemMonitorLock: Implements locking mechanism to ensure synchronisation between 
the InstrumentationH andler ant the SystemMonitor when using the global memory. 
@publishedAll
@test
*/

class CSystemMonitorLock
  	{
public:
	// Construction/Destruction
	CSystemMonitorLock();
	~CSystemMonitorLock();
	void InitialiseLock(TInt& aLock);
	void EnterCriticalSection(TInt& aLock);
	void ExitCriticalSection(TInt& aLock);
	private: 
	
private:
	RSemaphore iSemaphore;	
	};

	
#endif

