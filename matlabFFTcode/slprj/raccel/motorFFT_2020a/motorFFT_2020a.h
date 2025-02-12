#ifndef RTW_HEADER_motorFFT_2020a_h_
#define RTW_HEADER_motorFFT_2020a_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef motorFFT_2020a_COMMON_INCLUDES_
#define motorFFT_2020a_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "motorFFT_2020a_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME motorFFT_2020a
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T gzdbvokcwj ; real_T i5nivag4gq ; real_T itxjh5qdlr ;
real_T kngwwr0zmz ; real_T mp3esss30n ; real_T d0jgvx3ldb ; } B ; typedef
struct { struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
i0ykffg1ze ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} ldr32p4cok ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } cnf2j0v0jx ; struct { void * LoggedData [ 3 ] ; } pgnz3puzk1 ; struct {
void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } a25is5i5n3 ; struct
{ void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } dtvtct1zhe ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } jzzvrrg0sx
; struct { void * LoggedData [ 3 ] ; } em5caundsj ; struct { int_T PrevIndex
; } oiqioysmzl ; struct { int_T PrevIndex ; } aa1yxvnz02 ; struct { int_T
PrevIndex ; } absy2vvepd ; struct { int_T PrevIndex ; } dsmilhvssh ; struct {
int_T PrevIndex ; } dkld4y3dbe ; struct { int_T PrevIndex ; } nzuoeuxs05 ; }
DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T fromWS_Signal1_Time0 [ 397 ] ; real_T fromWS_Signal1_Data0 [ 397
] ; real_T FromWorkspace_Time0 [ 397 ] ; real_T FromWorkspace_Data0 [ 397 ] ;
real_T FromWorkspace1_Time0 [ 397 ] ; real_T FromWorkspace1_Data0 [ 397 ] ;
real_T fromWS_Signal1_Time0_ihfogtldbr [ 397 ] ; real_T
fromWS_Signal1_Data0_olkgbefqoo [ 397 ] ; real_T
FromWorkspace_Time0_dcjgz0pu3i [ 397 ] ; real_T
FromWorkspace_Data0_ayqgrylbms [ 397 ] ; real_T
FromWorkspace1_Time0_aw5umakrsz [ 397 ] ; real_T
FromWorkspace1_Data0_eeddlxo2x0 [ 397 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * motorFFT_2020a_GetCAPIStaticMap
( void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
