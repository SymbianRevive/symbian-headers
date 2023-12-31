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

#ifndef __VWSAPPST_H__
#define __VWSAPPST_H__

class MVwsAppStarter
/**
The MVwsAppStarter class specifies an interface through which the view server makes callbacks to start applications.

If a view has not been registered in the server when an activation request arrives, the server will try to start
the application associated with that view.

@internalTechnology
*/
	{
public:	// Internal to Symbian

	/**
	 * Starts the application identified by aAppUid.
	 */
	virtual void StartAppL(TUid aAppUid,TThreadId& aThreadId)=0;
	};

#endif
