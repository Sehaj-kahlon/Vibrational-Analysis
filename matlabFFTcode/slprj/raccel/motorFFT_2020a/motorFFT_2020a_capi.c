#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "motorFFT_2020a_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "motorFFT_2020a.h"
#include "motorFFT_2020a_capi.h"
#include "motorFFT_2020a_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0
, 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/From Workspace1" ) , TARGET_STRING ( "Za" ) , 0
, 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) , 0
, 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0
, 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace1" ) , TARGET_STRING ( "Za" ) ,
0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) ,
0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 6 ,
TARGET_STRING ( "motorFFT_2020a/Signal Editor/From Workspace" ) ,
TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } , { 7 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/From Workspace" ) , TARGET_STRING ( "Data0" ) ,
0 , 1 , 0 } , { 8 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/From Workspace1" ) , TARGET_STRING ( "Time0" )
, 0 , 1 , 0 } , { 9 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/From Workspace1" ) , TARGET_STRING ( "Data0" )
, 0 , 1 , 0 } , { 10 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" )
, 0 , 1 , 0 } , { 11 , TARGET_STRING (
"motorFFT_2020a/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING ( "Data0" )
, 0 , 1 , 0 } , { 12 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace" ) , TARGET_STRING ( "Time0" )
, 0 , 1 , 0 } , { 13 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace" ) , TARGET_STRING ( "Data0" )
, 0 , 1 , 0 } , { 14 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace1" ) , TARGET_STRING ( "Time0" )
, 0 , 1 , 0 } , { 15 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/From Workspace1" ) , TARGET_STRING ( "Data0" )
, 0 , 1 , 0 } , { 16 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" )
, 0 , 1 , 0 } , { 17 , TARGET_STRING (
"motorFFT_2020a/Signal Editor1/fromWS_Signal 1" ) , TARGET_STRING ( "Data0" )
, 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . i5nivag4gq , & rtB . itxjh5qdlr ,
& rtB . gzdbvokcwj , & rtB . mp3esss30n , & rtB . d0jgvx3ldb , & rtB .
kngwwr0zmz , & rtP . FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0
[ 0 ] , & rtP . FromWorkspace1_Time0 [ 0 ] , & rtP . FromWorkspace1_Data0 [ 0
] , & rtP . fromWS_Signal1_Time0 [ 0 ] , & rtP . fromWS_Signal1_Data0 [ 0 ] ,
& rtP . FromWorkspace_Time0_dcjgz0pu3i [ 0 ] , & rtP .
FromWorkspace_Data0_ayqgrylbms [ 0 ] , & rtP .
FromWorkspace1_Time0_aw5umakrsz [ 0 ] , & rtP .
FromWorkspace1_Data0_eeddlxo2x0 [ 0 ] , & rtP .
fromWS_Signal1_Time0_ihfogtldbr [ 0 ] , & rtP .
fromWS_Signal1_Data0_olkgbefqoo [ 0 ] , } ; static int32_T * rtVarDimsAddrMap
[ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 397 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 6 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 12 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 3122028247U , 2194582210U , 2685089608U , 1854165697U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * motorFFT_2020a_GetCAPIStaticMap
( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void motorFFT_2020a_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void motorFFT_2020a_host_InitializeDataMapInfo (
motorFFT_2020a_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
