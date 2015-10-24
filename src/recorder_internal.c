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

#include <stdio.h>
#include <stdlib.h>
#include <mm.h>
#include <mm_types.h>
#include <recorder_private.h>
#include <recorder_internal.h>
#include <dlog.h>
#include <unistd.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "TIZEN_N_RECORDER"

int recorder_set_audio_device_id(recorder_h recorder,  const char *device_id)
{
	if (recorder == NULL) {
		return __convert_recorder_error_code(__func__, RECORDER_ERROR_INVALID_PARAMETER);
	}

	if (device_id == NULL) {
		LOGE("device id is NULL");
		return RECORDER_ERROR_INVALID_PARAMETER;
	}

	int ret = MM_ERROR_NONE;
	recorder_s *handle = (recorder_s *)recorder;

	ret = mm_camcorder_set_attributes(handle->mm_handle, NULL,
					MMCAM_USB_AUDIO_UDEV_ID, device_id, strlen(device_id),
					NULL);

	return __convert_recorder_error_code(__func__, ret);
}

int recorder_get_audio_device_id(recorder_h recorder,  char **device_id)
{
	if (recorder == NULL) {
		return __convert_recorder_error_code(__func__, RECORDER_ERROR_INVALID_PARAMETER);
	}

	if (device_id == NULL) {
		LOGE("device id is NULL");
		return RECORDER_ERROR_INVALID_PARAMETER;
	}

	int ret = MM_ERROR_NONE;
	recorder_s *handle = (recorder_s *)recorder;

	char *device_id_name = NULL;
	int device_id_name_size;

	ret = mm_camcorder_get_attributes(handle->mm_handle, NULL,
					MMCAM_USB_AUDIO_UDEV_ID, &device_id_name, &device_id_name_size,
					NULL);

	if ( ret == MM_ERROR_NONE ) {
		*device_id = strdup(device_id_name);
	}

	return __convert_recorder_error_code(__func__, ret);
}
