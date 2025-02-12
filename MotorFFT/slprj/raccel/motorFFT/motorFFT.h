#ifndef RTW_HEADER_motorFFT_h_
#define RTW_HEADER_motorFFT_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef motorFFT_COMMON_INCLUDES_
#define motorFFT_COMMON_INCLUDES_
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
#include "motorFFT_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME motorFFT
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (24) 
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
typedef struct { real_T gregxvrhdq ; real_T iey5yp5yc3 ; real_T ah0n04lkk0 ;
real_T adgfg4spum ; real_T hsn4any1yz ; real_T ez1dpie4tk ; real_T ip0uvrp3z3
; real_T lzl45qjifg ; real_T fvz5ztlupg ; real_T jappjfmhaf ; real_T
hzs2cffwsh ; real_T mqr2iftmcf ; real_T bv141smffr ; real_T n0ofmubc1v ;
real_T hkzej0bbqv ; real_T hyn4m540so ; real_T i5xm4g4u24 ; real_T gmacchlgce
; real_T phph3pe0fd ; real_T psxmxvyoop ; real_T jkpzefwce0 ; real_T
atrkvlif4k ; real_T ekcsmuhkax ; real_T cwbebu3rd3 ; } B ; typedef struct {
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } azqf3zai0t
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
jnemuuzgzp ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} pzvgpjidp0 ; struct { void * LoggedData [ 3 ] ; } fsvvqr0mni ; struct {
void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } j21ldtcnma ; struct
{ void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } a2z3xgtwiy ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } oj2hmay041
; struct { void * LoggedData [ 3 ] ; } hk3des0jg0 ; struct { void * TimePtr ;
void * DataPtr ; void * RSimInfoPtr ; } mmlzbnupg4 ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } l1aaxv0qvs ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } h234jcxu2z ; struct { void
* LoggedData [ 3 ] ; } clrd32dre4 ; struct { void * TimePtr ; void * DataPtr
; void * RSimInfoPtr ; } epftsymyqn ; struct { void * TimePtr ; void *
DataPtr ; void * RSimInfoPtr ; } ilpn10ybkm ; struct { void * TimePtr ; void
* DataPtr ; void * RSimInfoPtr ; } izkwmahydg ; struct { void * LoggedData [
3 ] ; } okrhfkq4wg ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } azgdj10ofq ; struct { void * TimePtr ; void * DataPtr ; void
* RSimInfoPtr ; } i1szh3fwfk ; struct { void * TimePtr ; void * DataPtr ;
void * RSimInfoPtr ; } iuvswjitkf ; struct { void * LoggedData [ 3 ] ; }
aciovtayfr ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} ayhphwsgwq ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } ajdss4dhe0 ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } dh3f02y2sz ; struct { void * LoggedData [ 3 ] ; } msjdgqazw2
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
kqoyc1etwg ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} mvcdlyri2j ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } hbcms1bq4r ; struct { void * LoggedData [ 3 ] ; } imhpm3odyo ; struct {
void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } ddvlfm2hus ; struct
{ void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } l3wkq1xedj ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } pjjr10dg4b
; struct { void * LoggedData [ 3 ] ; } ekwpduodoq ; struct { int_T PrevIndex
; } i3mtw4xzzf ; struct { int_T PrevIndex ; } pfd1w3cfyn ; struct { int_T
PrevIndex ; } b5nhs0lacr ; struct { int_T PrevIndex ; } irfywsshjv ; struct {
int_T PrevIndex ; } mjelp1v40r ; struct { int_T PrevIndex ; } gzrsy1zuao ;
struct { int_T PrevIndex ; } jsowmhyjmc ; struct { int_T PrevIndex ; }
px2wccwv40 ; struct { int_T PrevIndex ; } giadlp5izi ; struct { int_T
PrevIndex ; } nlmnijzpxw ; struct { int_T PrevIndex ; } poz2ms4ply ; struct {
int_T PrevIndex ; } mz45s0obsk ; struct { int_T PrevIndex ; } ffaasee41y ;
struct { int_T PrevIndex ; } mxgci4hatn ; struct { int_T PrevIndex ; }
jfxavml4ss ; struct { int_T PrevIndex ; } emklnm5eee ; struct { int_T
PrevIndex ; } j1ehnbr3p0 ; struct { int_T PrevIndex ; } azpkt4wjbr ; struct {
int_T PrevIndex ; } hhpqhvbomw ; struct { int_T PrevIndex ; } kp31dep3dx ;
struct { int_T PrevIndex ; } pcfosdoawh ; struct { int_T PrevIndex ; }
ir4ldnp24c ; struct { int_T PrevIndex ; } kxnor0qurr ; struct { int_T
PrevIndex ; } nq5bs3wkyw ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T fromWS_Signal1_Time0 [ 1178 ] ;
real_T fromWS_Signal1_Data0 [ 1178 ] ; real_T FromWorkspace_Time0 [ 1178 ] ;
real_T FromWorkspace_Data0 [ 1178 ] ; real_T FromWorkspace1_Time0 [ 1178 ] ;
real_T FromWorkspace1_Data0 [ 1178 ] ; real_T fromWS_Signal1_Time0_ndx3dzmkku
[ 1178 ] ; real_T fromWS_Signal1_Data0_oas1myuoe3 [ 1178 ] ; real_T
FromWorkspace_Time0_evtpn2dlvi [ 1178 ] ; real_T
FromWorkspace_Data0_bw10wgblqr [ 1178 ] ; real_T
FromWorkspace1_Time0_gvxb44qtwu [ 1178 ] ; real_T
FromWorkspace1_Data0_f5g0ewuzoj [ 1178 ] ; real_T
fromWS_Signal1_Time0_dv1n1hreha [ 1170 ] ; real_T
fromWS_Signal1_Data0_baihte5jff [ 1170 ] ; real_T
FromWorkspace_Time0_b0ruuf1opz [ 1170 ] ; real_T
FromWorkspace_Data0_pcaxh4qntv [ 1170 ] ; real_T
FromWorkspace1_Time0_evphbwmxwa [ 1170 ] ; real_T
FromWorkspace1_Data0_ajxnvg3fs4 [ 1170 ] ; real_T
fromWS_Signal1_Time0_ld4ysq5re5 [ 1170 ] ; real_T
fromWS_Signal1_Data0_nmlefzf2qh [ 1170 ] ; real_T
FromWorkspace_Time0_mylv0l5y5l [ 1170 ] ; real_T
FromWorkspace_Data0_ii4u0weofd [ 1170 ] ; real_T
FromWorkspace1_Time0_jq4gg3fl1c [ 1170 ] ; real_T
FromWorkspace1_Data0_delfmtqm10 [ 1170 ] ; real_T
fromWS_Signal1_Time0_knw2zejkhf [ 1169 ] ; real_T
fromWS_Signal1_Data0_dqatlaamxd [ 1169 ] ; real_T
FromWorkspace_Time0_ey3pumuhzx [ 1169 ] ; real_T
FromWorkspace_Data0_dhfho4iunp [ 1169 ] ; real_T
FromWorkspace1_Time0_nswp0gh53d [ 1169 ] ; real_T
FromWorkspace1_Data0_cws5e25kve [ 1169 ] ; real_T
fromWS_Signal1_Time0_jf1ovizl0b [ 1169 ] ; real_T
fromWS_Signal1_Data0_bmzttyl35q [ 1169 ] ; real_T
FromWorkspace_Time0_inageeqpai [ 1169 ] ; real_T
FromWorkspace_Data0_kzvsc32h2c [ 1169 ] ; real_T
FromWorkspace1_Time0_hsp0vfmomf [ 1169 ] ; real_T
FromWorkspace1_Data0_afourxrbaa [ 1169 ] ; real_T
fromWS_Signal1_Time0_izyjwzvjth [ 1198 ] ; real_T
fromWS_Signal1_Data0_dnuljhqvk4 [ 1198 ] ; real_T
FromWorkspace_Time0_atfy3pm4jv [ 1198 ] ; real_T
FromWorkspace_Data0_l3lbhy1g0h [ 1198 ] ; real_T
FromWorkspace1_Time0_drehnj2kvb [ 1198 ] ; real_T
FromWorkspace1_Data0_k4fehecuxx [ 1198 ] ; real_T
fromWS_Signal1_Time0_fpgnvffwdi [ 1198 ] ; real_T
fromWS_Signal1_Data0_hc01az2ko0 [ 1198 ] ; real_T
FromWorkspace_Time0_j4qtllopkd [ 1198 ] ; real_T
FromWorkspace_Data0_kkea1guu30 [ 1198 ] ; real_T
FromWorkspace1_Time0_gpsy5fvy5d [ 1198 ] ; real_T
FromWorkspace1_Data0_gcmrjxmyv0 [ 1198 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * motorFFT_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
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
