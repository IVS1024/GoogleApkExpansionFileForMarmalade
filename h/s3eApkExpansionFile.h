/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_APKEXPANSIONFILE_H
#define S3E_EXT_APKEXPANSIONFILE_H

#include <s3eTypes.h>
#include "IwDebug.h"

enum s3eApkExpansionFileCallback
{
	S3E_APKEXPANSIONFILE_DOWNLOADING_COMPLETED,
	S3E_APKEXPANSIONFILE_DOWNLOADING_FAILED,
	S3E_APKEXPANSIONFILE_DOWNLOADING_UPDATE,	
	S3E_APKEXPANSIONFILE_CALLBACK_MAX
};

struct s3eApkExpansionFileDownloadingInfo
{
	long mOverallTotal;
	long mOverallProgress;
	long mTimeRemaining; // time remaining
	float mCurrentSpeed; // speed in KB/S
};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the ApkExpansionFile extension is available.
 */
s3eBool s3eApkExpansionFileAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eApkExpansionFileCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eApkExpansionFileUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eApkExpansionFileCallback enum.
 */
s3eResult s3eApkExpansionFileRegister(s3eApkExpansionFileCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3eApkExpansionFileCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3eApkExpansionFileRegister
 */
s3eResult s3eApkExpansionFileUnRegister(s3eApkExpansionFileCallback cbid, s3eCallback fn);

s3eResult s3eApkExpansionFileInitialize(const char* apiKey, const char* mainFileVersion, const char* patchFileVersion);

const char* s3eApkExpansionFileGetPathToMainObb();

const char* s3eApkExpansionFileGetPathToPatchObb();

bool s3eApkExpansionFileNeedDownloadMainObb();

bool s3eApkExpansionFileNeedDownloadPatchObb();

void s3eApkExpansionFileStartDownloading();

S3E_END_C_DECL

#endif /* !S3E_EXT_APKEXPANSIONFILE_H */