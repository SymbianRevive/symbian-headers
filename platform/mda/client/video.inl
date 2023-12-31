// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Mda\Client\Video.inl
// 
//

inline TMdaFbsBitmapDevice::TMdaFbsBitmapDevice():
	TMdaStreamDevice(KUidMdaFbsBitmapDevice,sizeof(TMdaFbsBitmapDevice))
	{}

inline TMdaFbsBitmapHandle::TMdaFbsBitmapHandle():
	TMdaPackage(KUidMdaFbsBitmapDevice,KUidMdaFbsBitmapHandle,sizeof(TMdaFbsBitmapHandle)),
	iBitmapHandle(0)
	{}

inline TMdaFbsBitmapMaskHandle::TMdaFbsBitmapMaskHandle():
	TMdaPackage(KUidMdaFbsBitmapDevice,KUidMdaFbsBitmapMaskHandle,sizeof(TMdaFbsBitmapMaskHandle)),
	iBitmapHandle(0)
	{}

