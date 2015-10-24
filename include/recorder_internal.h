/*
* Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef __TIZEN_MULTIMEDIA_RECORDER_INTERNAL_H__
#define __TIZEN_MULTIMEDIA_RECORDER_INTERNAL_H__
#include <recorder.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @internal
 * @file recorder_internal.h
 * @brief This file contains the Recorder Product-internal API, related structures and enumerations.
 */

/**
 * @internal
 * @addtogroup CAPI_MEDIA_RECORDER_ATTRIBUTES_MODULE_INTERNAL
 * @{
 */

/**
 * @brief Sets the audio device id
 * @details This function sets audio device id which will be used for audio , video recording
 * @remarks If you set audio device id after recording, it will not work.
 * @param[in]	recorder	The handle to the media recorder
 * @param[in]	device_id The recording audio device id
 * @return @c 0 on success, otherwise a negative error value
 * @retval #RECORDER_ERROR_NONE Successful
 * @retval #RECORDER_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #RECORDER_ERROR_INVALID_STATE Invalid state
 * @pre The recorder state must be only #RECORDER_STATE_CREATED by recorder_create() or recorder_unprepare().
 * @see	recorder_get_filename()
 */
int recorder_set_audio_device_id(recorder_h recorder, const char *device_id);


/**
 * @brief  Gets the audio device id
 * @remarks You must release @a device id using free().
 * @param[in]	recorder    The handle to the media recorder
 * @param[out]	device_id    The recording audio device id
 * @return @c 0 on success, otherwise a negative error value
 * @retval #RECORDER_ERROR_NONE Successful
 * @retval #RECORDER_ERROR_INVALID_PARAMETER Invalid parameter
 * @see	recorder_get_filename()
 */
int recorder_get_audio_device_id(recorder_h recorder, char **device_id);



/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_MULTIMEDIA_RECORDER_PRODUCT_H__ */
