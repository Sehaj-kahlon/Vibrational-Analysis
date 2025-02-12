#ifndef RTW_HEADER_motorFFT_2020a_cap_host_h_
#define RTW_HEADER_motorFFT_2020a_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
motorFFT_2020a_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void motorFFT_2020a_host_InitializeDataMapInfo (
motorFFT_2020a_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
