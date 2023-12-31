// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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

/**
 @file
 @publishedPartner
 @released
*/

#if !defined(__MMFHWDEVICECMDS_H__)
#define __MMFHWDEVICECMDS_H__

enum TDeviceFunc
{
	EDevNullFunc,
	EDevEncode,
	EDevDecode
};

enum TDeviceFlow
{
	EDevNullFlow,
	EDevOutFlow,
	EDevInFlow,
	EDevInAndOutFlow,
	EDevNoFlow
};

#endif __MMFHWDEVICECMDS_H__
