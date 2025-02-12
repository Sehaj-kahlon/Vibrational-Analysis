#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "motorFFT_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "motorFFT.h"
#include "motorFFT_capi.h"
#include "motorFFT_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"motorFFT/100V/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 0 , TARGET_STRING ( "motorFFT/100V/From Workspace1" ) ,
TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"motorFFT/100V/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 ,
0 } , { 3 , 0 , TARGET_STRING ( "motorFFT/100V1/From Workspace" ) ,
TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"motorFFT/100V1/From Workspace1" ) , TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 ,
0 } , { 5 , 0 , TARGET_STRING ( "motorFFT/100V1/fromWS_Signal 1" ) ,
TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"motorFFT/200V/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0
} , { 7 , 0 , TARGET_STRING ( "motorFFT/200V/From Workspace1" ) ,
TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"motorFFT/200V/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 ,
0 } , { 9 , 0 , TARGET_STRING ( "motorFFT/200V1/From Workspace" ) ,
TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"motorFFT/200V1/From Workspace1" ) , TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 ,
0 } , { 11 , 0 , TARGET_STRING ( "motorFFT/200V1/fromWS_Signal 1" ) ,
TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"motorFFT/300V/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0
} , { 13 , 0 , TARGET_STRING ( "motorFFT/300V/From Workspace1" ) ,
TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"motorFFT/300V/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 ,
0 } , { 15 , 0 , TARGET_STRING ( "motorFFT/300V1/From Workspace" ) ,
TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"motorFFT/300V1/From Workspace1" ) , TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 ,
0 } , { 17 , 0 , TARGET_STRING ( "motorFFT/300V1/fromWS_Signal 1" ) ,
TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"motorFFT/415V/From Workspace" ) , TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0
} , { 19 , 0 , TARGET_STRING ( "motorFFT/415V/From Workspace1" ) ,
TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"motorFFT/415V/fromWS_Signal 1" ) , TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 ,
0 } , { 21 , 0 , TARGET_STRING ( "motorFFT/415V1/From Workspace" ) ,
TARGET_STRING ( "Ya" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"motorFFT/415V1/From Workspace1" ) , TARGET_STRING ( "Za" ) , 0 , 0 , 0 , 0 ,
0 } , { 23 , 0 , TARGET_STRING ( "motorFFT/415V1/fromWS_Signal 1" ) ,
TARGET_STRING ( "Xa" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL )
, 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 24 , TARGET_STRING (
"motorFFT/100V/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 25 , TARGET_STRING ( "motorFFT/100V/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 26 , TARGET_STRING (
"motorFFT/100V/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 27 , TARGET_STRING ( "motorFFT/100V/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 28 , TARGET_STRING (
"motorFFT/100V/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 29 , TARGET_STRING ( "motorFFT/100V/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 30 , TARGET_STRING (
"motorFFT/100V1/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 31 , TARGET_STRING ( "motorFFT/100V1/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 32 , TARGET_STRING (
"motorFFT/100V1/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 }
, { 33 , TARGET_STRING ( "motorFFT/100V1/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 34 , TARGET_STRING (
"motorFFT/100V1/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 }
, { 35 , TARGET_STRING ( "motorFFT/100V1/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 36 , TARGET_STRING (
"motorFFT/200V/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 } ,
{ 37 , TARGET_STRING ( "motorFFT/200V/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 38 , TARGET_STRING (
"motorFFT/200V/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 } ,
{ 39 , TARGET_STRING ( "motorFFT/200V/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 40 , TARGET_STRING (
"motorFFT/200V/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 } ,
{ 41 , TARGET_STRING ( "motorFFT/200V/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 42 , TARGET_STRING (
"motorFFT/200V1/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 } ,
{ 43 , TARGET_STRING ( "motorFFT/200V1/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 44 , TARGET_STRING (
"motorFFT/200V1/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 }
, { 45 , TARGET_STRING ( "motorFFT/200V1/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 46 , TARGET_STRING (
"motorFFT/200V1/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 2 , 0 }
, { 47 , TARGET_STRING ( "motorFFT/200V1/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 48 , TARGET_STRING (
"motorFFT/300V/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 } ,
{ 49 , TARGET_STRING ( "motorFFT/300V/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 50 , TARGET_STRING (
"motorFFT/300V/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 } ,
{ 51 , TARGET_STRING ( "motorFFT/300V/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 52 , TARGET_STRING (
"motorFFT/300V/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 } ,
{ 53 , TARGET_STRING ( "motorFFT/300V/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 54 , TARGET_STRING (
"motorFFT/300V1/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 } ,
{ 55 , TARGET_STRING ( "motorFFT/300V1/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 56 , TARGET_STRING (
"motorFFT/300V1/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 }
, { 57 , TARGET_STRING ( "motorFFT/300V1/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 58 , TARGET_STRING (
"motorFFT/300V1/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 3 , 0 }
, { 59 , TARGET_STRING ( "motorFFT/300V1/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 60 , TARGET_STRING (
"motorFFT/415V/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 } ,
{ 61 , TARGET_STRING ( "motorFFT/415V/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 62 , TARGET_STRING (
"motorFFT/415V/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 } ,
{ 63 , TARGET_STRING ( "motorFFT/415V/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 64 , TARGET_STRING (
"motorFFT/415V/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 } ,
{ 65 , TARGET_STRING ( "motorFFT/415V/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 66 , TARGET_STRING (
"motorFFT/415V1/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 } ,
{ 67 , TARGET_STRING ( "motorFFT/415V1/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 68 , TARGET_STRING (
"motorFFT/415V1/From Workspace1" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 }
, { 69 , TARGET_STRING ( "motorFFT/415V1/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 70 , TARGET_STRING (
"motorFFT/415V1/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 4 , 0 }
, { 71 , TARGET_STRING ( "motorFFT/415V1/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . iey5yp5yc3 , & rtB . ah0n04lkk0 ,
& rtB . gregxvrhdq , & rtB . hsn4any1yz , & rtB . ez1dpie4tk , & rtB .
adgfg4spum , & rtB . lzl45qjifg , & rtB . fvz5ztlupg , & rtB . ip0uvrp3z3 , &
rtB . hzs2cffwsh , & rtB . mqr2iftmcf , & rtB . jappjfmhaf , & rtB .
n0ofmubc1v , & rtB . hkzej0bbqv , & rtB . bv141smffr , & rtB . i5xm4g4u24 , &
rtB . gmacchlgce , & rtB . hyn4m540so , & rtB . psxmxvyoop , & rtB .
jkpzefwce0 , & rtB . phph3pe0fd , & rtB . ekcsmuhkax , & rtB . cwbebu3rd3 , &
rtB . atrkvlif4k , & rtP . FromWorkspace_Time0 [ 0 ] , & rtP .
FromWorkspace_Data0 [ 0 ] , & rtP . FromWorkspace1_Time0 [ 0 ] , & rtP .
FromWorkspace1_Data0 [ 0 ] , & rtP . fromWS_Signal1_Time0 [ 0 ] , & rtP .
fromWS_Signal1_Data0 [ 0 ] , & rtP . FromWorkspace_Time0_evtpn2dlvi [ 0 ] , &
rtP . FromWorkspace_Data0_bw10wgblqr [ 0 ] , & rtP .
FromWorkspace1_Time0_gvxb44qtwu [ 0 ] , & rtP .
FromWorkspace1_Data0_f5g0ewuzoj [ 0 ] , & rtP .
fromWS_Signal1_Time0_ndx3dzmkku [ 0 ] , & rtP .
fromWS_Signal1_Data0_oas1myuoe3 [ 0 ] , & rtP .
FromWorkspace_Time0_b0ruuf1opz [ 0 ] , & rtP . FromWorkspace_Data0_pcaxh4qntv
[ 0 ] , & rtP . FromWorkspace1_Time0_evphbwmxwa [ 0 ] , & rtP .
FromWorkspace1_Data0_ajxnvg3fs4 [ 0 ] , & rtP .
fromWS_Signal1_Time0_dv1n1hreha [ 0 ] , & rtP .
fromWS_Signal1_Data0_baihte5jff [ 0 ] , & rtP .
FromWorkspace_Time0_mylv0l5y5l [ 0 ] , & rtP . FromWorkspace_Data0_ii4u0weofd
[ 0 ] , & rtP . FromWorkspace1_Time0_jq4gg3fl1c [ 0 ] , & rtP .
FromWorkspace1_Data0_delfmtqm10 [ 0 ] , & rtP .
fromWS_Signal1_Time0_ld4ysq5re5 [ 0 ] , & rtP .
fromWS_Signal1_Data0_nmlefzf2qh [ 0 ] , & rtP .
FromWorkspace_Time0_ey3pumuhzx [ 0 ] , & rtP . FromWorkspace_Data0_dhfho4iunp
[ 0 ] , & rtP . FromWorkspace1_Time0_nswp0gh53d [ 0 ] , & rtP .
FromWorkspace1_Data0_cws5e25kve [ 0 ] , & rtP .
fromWS_Signal1_Time0_knw2zejkhf [ 0 ] , & rtP .
fromWS_Signal1_Data0_dqatlaamxd [ 0 ] , & rtP .
FromWorkspace_Time0_inageeqpai [ 0 ] , & rtP . FromWorkspace_Data0_kzvsc32h2c
[ 0 ] , & rtP . FromWorkspace1_Time0_hsp0vfmomf [ 0 ] , & rtP .
FromWorkspace1_Data0_afourxrbaa [ 0 ] , & rtP .
fromWS_Signal1_Time0_jf1ovizl0b [ 0 ] , & rtP .
fromWS_Signal1_Data0_bmzttyl35q [ 0 ] , & rtP .
FromWorkspace_Time0_atfy3pm4jv [ 0 ] , & rtP . FromWorkspace_Data0_l3lbhy1g0h
[ 0 ] , & rtP . FromWorkspace1_Time0_drehnj2kvb [ 0 ] , & rtP .
FromWorkspace1_Data0_k4fehecuxx [ 0 ] , & rtP .
fromWS_Signal1_Time0_izyjwzvjth [ 0 ] , & rtP .
fromWS_Signal1_Data0_dnuljhqvk4 [ 0 ] , & rtP .
FromWorkspace_Time0_j4qtllopkd [ 0 ] , & rtP . FromWorkspace_Data0_kkea1guu30
[ 0 ] , & rtP . FromWorkspace1_Time0_gpsy5fvy5d [ 0 ] , & rtP .
FromWorkspace1_Data0_gcmrjxmyv0 [ 0 ] , & rtP .
fromWS_Signal1_Time0_fpgnvffwdi [ 0 ] , & rtP .
fromWS_Signal1_Data0_hc01az2ko0 [ 0 ] , } ; static int32_T * rtVarDimsAddrMap
[ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 1178 , 1 , 1170 , 1 , 1169 , 1 , 1198 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 24 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 48 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1039835684U , 1442330462U , 3807622218U , 3995259496U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * motorFFT_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void motorFFT_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void motorFFT_host_InitializeDataMapInfo ( motorFFT_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
