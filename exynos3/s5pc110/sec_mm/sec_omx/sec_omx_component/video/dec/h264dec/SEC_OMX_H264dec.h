/*
 *
 * Copyright 2010 Samsung Electronics S.LSI Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * @file    SEC_OMX_H264dec.h
 * @brief
 * @author    SeungBeom Kim (sbcrux.kim@lenovo.com)
 * @version    1.0
 * @history
 *   2010.7.15 : Create
 */

#ifndef SEC_OMX_H264_DEC_COMPONENT
#define SEC_OMX_H264_DEC_COMPONENT

#include "SEC_OMX_Def.h"
#include "OMX_Component.h"
#include "OMX_Video.h"


typedef struct _SEC_MFC_H264DEC_HANDLE
{
    OMX_HANDLETYPE hMFCHandle;
    OMX_PTR pMFCStreamBuffer;
    OMX_PTR pMFCStreamPhyBuffer;
    OMX_U32    indexTimestamp;
    OMX_BOOL bConfiguredMFC;
    OMX_BOOL bThumbnailMode;
    OMX_S32  returnCodec;
} SEC_MFC_H264DEC_HANDLE;

typedef struct _SEC_H264DEC_HANDLE
{
    /* OMX Codec specific */
    OMX_VIDEO_PARAM_AVCTYPE AVCComponent[ALL_PORT_NUM];
    OMX_VIDEO_PARAM_ERRORCORRECTIONTYPE errorCorrectionType[ALL_PORT_NUM];

    /* SEC MFC Codec specific */
    SEC_MFC_H264DEC_HANDLE hMFCH264Handle;

    /* For Non-Block mode */
    SEC_MFC_NBDEC_THREAD NBDecThread;
    OMX_BOOL bFirstFrame;
    MFC_DEC_INPUT_BUFFER MFCDecInputBuffer[MFC_INPUT_BUFFER_NUM_MAX];
    OMX_U32  indexInputBuffer;
} SEC_H264DEC_HANDLE;

#ifdef __cplusplus
extern "C" {
#endif

OSCL_EXPORT_REF OMX_ERRORTYPE SEC_OMX_ComponentInit(OMX_HANDLETYPE hComponent, OMX_STRING componentName);
OMX_ERRORTYPE SEC_OMX_ComponentDeinit(OMX_HANDLETYPE hComponent);

#ifdef __cplusplus
};
#endif

#endif
