#include "rt_logging_mmi.h"
#include "motorFFT_capi.h"
#include <math.h>
#include "motorFFT.h"
#include "motorFFT_private.h"
#include "motorFFT_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 24 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.3 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//motorFFT//motorFFT_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { RTWLogSignalInfo rt_ScopeSignalInfo
; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope1" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . fsvvqr0mni . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "raw_100v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . fsvvqr0mni .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope5" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . hk3des0jg0 . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "smooth_100v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . hk3des0jg0 .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope2" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . clrd32dre4 . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "raw_200v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . clrd32dre4 .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope6" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . okrhfkq4wg . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "smooth_200v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . okrhfkq4wg .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope3" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . aciovtayfr . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "raw_300v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . aciovtayfr .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope7" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . msjdgqazw2 . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "smooth_300v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . msjdgqazw2 .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope4" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . imhpm3odyo . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "raw_415v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . imhpm3odyo .
LoggedData [ 0 ] == ( NULL ) ) return ; } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 , 1 , 1 } ;
static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 , 1 , 1 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 , 0 , 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 }
; static int_T rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "motorFFT/Scope8" ; static int_T rt_ScopeFrameData [
] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , (
NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ; rt_ScopeSignalInfo . numCols
= rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . ekwpduodoq . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "smooth_415v" , 1 , 0 , 1 , 0.015 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . ekwpduodoq .
LoggedData [ 0 ] == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('2.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0 ; fromwksInfo
-> nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0 ; rtDW . azqf3zai0t . TimePtr = fromwksInfo -> time ;
rtDW . azqf3zai0t . DataPtr = fromwksInfo -> data ; rtDW . azqf3zai0t .
RSimInfoPtr = fromwksInfo ; } rtDW . i3mtw4xzzf . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('2.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo ->
nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0 ; rtDW . jnemuuzgzp . TimePtr = fromwksInfo -> time ;
rtDW . jnemuuzgzp . DataPtr = fromwksInfo -> data ; rtDW . jnemuuzgzp .
RSimInfoPtr = fromwksInfo ; } rtDW . pfd1w3cfyn . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('2.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo
-> nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0 ; rtDW . pzvgpjidp0 . TimePtr = fromwksInfo -> time ;
rtDW . pzvgpjidp0 . DataPtr = fromwksInfo -> data ; rtDW . pzvgpjidp0 .
RSimInfoPtr = fromwksInfo ; } rtDW . b5nhs0lacr . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('3.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_oas1myuoe3 ;
fromwksInfo -> nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_ndx3dzmkku ; rtDW . j21ldtcnma . TimePtr = fromwksInfo
-> time ; rtDW . j21ldtcnma . DataPtr = fromwksInfo -> data ; rtDW .
j21ldtcnma . RSimInfoPtr = fromwksInfo ; } rtDW . irfywsshjv . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('3.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_bw10wgblqr ;
fromwksInfo -> nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_evtpn2dlvi ; rtDW . a2z3xgtwiy . TimePtr = fromwksInfo ->
time ; rtDW . a2z3xgtwiy . DataPtr = fromwksInfo -> data ; rtDW . a2z3xgtwiy
. RSimInfoPtr = fromwksInfo ; } rtDW . mjelp1v40r . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('3.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_f5g0ewuzoj ;
fromwksInfo -> nDataPoints = 1178 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_gvxb44qtwu ; rtDW . oj2hmay041 . TimePtr = fromwksInfo
-> time ; rtDW . oj2hmay041 . DataPtr = fromwksInfo -> data ; rtDW .
oj2hmay041 . RSimInfoPtr = fromwksInfo ; } rtDW . gzrsy1zuao . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_baihte5jff ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_dv1n1hreha ; rtDW . mmlzbnupg4 . TimePtr = fromwksInfo
-> time ; rtDW . mmlzbnupg4 . DataPtr = fromwksInfo -> data ; rtDW .
mmlzbnupg4 . RSimInfoPtr = fromwksInfo ; } rtDW . jsowmhyjmc . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_pcaxh4qntv ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_b0ruuf1opz ; rtDW . l1aaxv0qvs . TimePtr = fromwksInfo ->
time ; rtDW . l1aaxv0qvs . DataPtr = fromwksInfo -> data ; rtDW . l1aaxv0qvs
. RSimInfoPtr = fromwksInfo ; } rtDW . px2wccwv40 . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_ajxnvg3fs4 ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_evphbwmxwa ; rtDW . h234jcxu2z . TimePtr = fromwksInfo
-> time ; rtDW . h234jcxu2z . DataPtr = fromwksInfo -> data ; rtDW .
h234jcxu2z . RSimInfoPtr = fromwksInfo ; } rtDW . giadlp5izi . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_nmlefzf2qh ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_ld4ysq5re5 ; rtDW . epftsymyqn . TimePtr = fromwksInfo
-> time ; rtDW . epftsymyqn . DataPtr = fromwksInfo -> data ; rtDW .
epftsymyqn . RSimInfoPtr = fromwksInfo ; } rtDW . nlmnijzpxw . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_ii4u0weofd ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_mylv0l5y5l ; rtDW . ilpn10ybkm . TimePtr = fromwksInfo ->
time ; rtDW . ilpn10ybkm . DataPtr = fromwksInfo -> data ; rtDW . ilpn10ybkm
. RSimInfoPtr = fromwksInfo ; } rtDW . poz2ms4ply . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_delfmtqm10 ;
fromwksInfo -> nDataPoints = 1170 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_jq4gg3fl1c ; rtDW . izkwmahydg . TimePtr = fromwksInfo
-> time ; rtDW . izkwmahydg . DataPtr = fromwksInfo -> data ; rtDW .
izkwmahydg . RSimInfoPtr = fromwksInfo ; } rtDW . mz45s0obsk . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('6.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_dqatlaamxd ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_knw2zejkhf ; rtDW . azgdj10ofq . TimePtr = fromwksInfo
-> time ; rtDW . azgdj10ofq . DataPtr = fromwksInfo -> data ; rtDW .
azgdj10ofq . RSimInfoPtr = fromwksInfo ; } rtDW . ffaasee41y . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('6.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_dhfho4iunp ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_ey3pumuhzx ; rtDW . i1szh3fwfk . TimePtr = fromwksInfo ->
time ; rtDW . i1szh3fwfk . DataPtr = fromwksInfo -> data ; rtDW . i1szh3fwfk
. RSimInfoPtr = fromwksInfo ; } rtDW . mxgci4hatn . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('6.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_cws5e25kve ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_nswp0gh53d ; rtDW . iuvswjitkf . TimePtr = fromwksInfo
-> time ; rtDW . iuvswjitkf . DataPtr = fromwksInfo -> data ; rtDW .
iuvswjitkf . RSimInfoPtr = fromwksInfo ; } rtDW . jfxavml4ss . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('7.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_bmzttyl35q ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_jf1ovizl0b ; rtDW . ayhphwsgwq . TimePtr = fromwksInfo
-> time ; rtDW . ayhphwsgwq . DataPtr = fromwksInfo -> data ; rtDW .
ayhphwsgwq . RSimInfoPtr = fromwksInfo ; } rtDW . emklnm5eee . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('7.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_kzvsc32h2c ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_inageeqpai ; rtDW . ajdss4dhe0 . TimePtr = fromwksInfo ->
time ; rtDW . ajdss4dhe0 . DataPtr = fromwksInfo -> data ; rtDW . ajdss4dhe0
. RSimInfoPtr = fromwksInfo ; } rtDW . j1ehnbr3p0 . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('7.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_afourxrbaa ;
fromwksInfo -> nDataPoints = 1169 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_hsp0vfmomf ; rtDW . dh3f02y2sz . TimePtr = fromwksInfo
-> time ; rtDW . dh3f02y2sz . DataPtr = fromwksInfo -> data ; rtDW .
dh3f02y2sz . RSimInfoPtr = fromwksInfo ; } rtDW . azpkt4wjbr . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('8.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_dnuljhqvk4 ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_izyjwzvjth ; rtDW . kqoyc1etwg . TimePtr = fromwksInfo
-> time ; rtDW . kqoyc1etwg . DataPtr = fromwksInfo -> data ; rtDW .
kqoyc1etwg . RSimInfoPtr = fromwksInfo ; } rtDW . hhpqhvbomw . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('8.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_l3lbhy1g0h ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_atfy3pm4jv ; rtDW . mvcdlyri2j . TimePtr = fromwksInfo ->
time ; rtDW . mvcdlyri2j . DataPtr = fromwksInfo -> data ; rtDW . mvcdlyri2j
. RSimInfoPtr = fromwksInfo ; } rtDW . kp31dep3dx . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('8.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_k4fehecuxx ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_drehnj2kvb ; rtDW . hbcms1bq4r . TimePtr = fromwksInfo
-> time ; rtDW . hbcms1bq4r . DataPtr = fromwksInfo -> data ; rtDW .
hbcms1bq4r . RSimInfoPtr = fromwksInfo ; } rtDW . pcfosdoawh . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('9.0333251953125','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_hc01az2ko0 ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_fpgnvffwdi ; rtDW . ddvlfm2hus . TimePtr = fromwksInfo
-> time ; rtDW . ddvlfm2hus . DataPtr = fromwksInfo -> data ; rtDW .
ddvlfm2hus . RSimInfoPtr = fromwksInfo ; } rtDW . ir4ldnp24c . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('9.0333251953125','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_kkea1guu30 ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_j4qtllopkd ; rtDW . l3wkq1xedj . TimePtr = fromwksInfo ->
time ; rtDW . l3wkq1xedj . DataPtr = fromwksInfo -> data ; rtDW . l3wkq1xedj
. RSimInfoPtr = fromwksInfo ; } rtDW . kxnor0qurr . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('9.0333251953125','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_gcmrjxmyv0 ;
fromwksInfo -> nDataPoints = 1198 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_gpsy5fvy5d ; rtDW . pjjr10dg4b . TimePtr = fromwksInfo
-> time ; rtDW . pjjr10dg4b . DataPtr = fromwksInfo -> data ; rtDW .
pjjr10dg4b . RSimInfoPtr = fromwksInfo ; } rtDW . nq5bs3wkyw . PrevIndex = 0
; } } void MdlOutputs ( int_T tid ) { { real_T t = ssGetT ( rtS ) ; real_T *
pTimeValues = ( real_T * ) rtDW . azqf3zai0t . TimePtr ; real_T * pDataValues
= ( real_T * ) rtDW . azqf3zai0t . DataPtr ; int numPoints , lastPoint ;
FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . azqf3zai0t . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <
pTimeValues [ 0 ] ) { rtB . gregxvrhdq = 0.0 ; } else if ( t == pTimeValues [
lastPoint ] ) { rtB . gregxvrhdq = pDataValues [ lastPoint ] ; } else if ( t
> pTimeValues [ lastPoint ] ) { rtB . gregxvrhdq = 0.0 ; } else { int_T
currTimeIndex = rtDW . i3mtw4xzzf . PrevIndex ; if ( t < pTimeValues [
currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } rtB . gregxvrhdq = pDataValues [ currTimeIndex ] ;
rtDW . i3mtw4xzzf . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT ( rtS
) ; real_T * pTimeValues = ( real_T * ) rtDW . jnemuuzgzp . TimePtr ; real_T
* pDataValues = ( real_T * ) rtDW . jnemuuzgzp . DataPtr ; int numPoints ,
lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . jnemuuzgzp .
RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints
- 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . iey5yp5yc3 = 0.0 ; } else if ( t
== pTimeValues [ lastPoint ] ) { rtB . iey5yp5yc3 = pDataValues [ lastPoint ]
; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . iey5yp5yc3 = 0.0 ; }
else { int_T currTimeIndex = rtDW . pfd1w3cfyn . PrevIndex ; if ( t <
pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] )
{ currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1
] ) { currTimeIndex ++ ; } } rtB . iey5yp5yc3 = pDataValues [ currTimeIndex ]
; rtDW . pfd1w3cfyn . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . pzvgpjidp0 . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . pzvgpjidp0 . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
pzvgpjidp0 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . ah0n04lkk0 = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . ah0n04lkk0 = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . ah0n04lkk0
= 0.0 ; } else { int_T currTimeIndex = rtDW . b5nhs0lacr . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . ah0n04lkk0 = pDataValues [ currTimeIndex
] ; rtDW . b5nhs0lacr . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . fsvvqr0mni .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . gregxvrhdq ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . iey5yp5yc3 ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . ah0n04lkk0 ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . j21ldtcnma . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . j21ldtcnma . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
j21ldtcnma . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . adgfg4spum = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . adgfg4spum = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . adgfg4spum
= 0.0 ; } else { int_T currTimeIndex = rtDW . irfywsshjv . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . adgfg4spum = pDataValues [ currTimeIndex
] ; rtDW . irfywsshjv . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . a2z3xgtwiy . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . a2z3xgtwiy . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
a2z3xgtwiy . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . hsn4any1yz = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . hsn4any1yz = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . hsn4any1yz
= 0.0 ; } else { int_T currTimeIndex = rtDW . mjelp1v40r . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . hsn4any1yz = pDataValues [ currTimeIndex
] ; rtDW . mjelp1v40r . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . oj2hmay041 . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . oj2hmay041 . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
oj2hmay041 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . ez1dpie4tk = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . ez1dpie4tk = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . ez1dpie4tk
= 0.0 ; } else { int_T currTimeIndex = rtDW . gzrsy1zuao . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . ez1dpie4tk = pDataValues [ currTimeIndex
] ; rtDW . gzrsy1zuao . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . hk3des0jg0 .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . adgfg4spum ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . hsn4any1yz ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . ez1dpie4tk ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . mmlzbnupg4 . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . mmlzbnupg4 . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
mmlzbnupg4 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . ip0uvrp3z3 = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . ip0uvrp3z3 = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . ip0uvrp3z3
= 0.0 ; } else { int_T currTimeIndex = rtDW . jsowmhyjmc . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . ip0uvrp3z3 = pDataValues [ currTimeIndex
] ; rtDW . jsowmhyjmc . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . l1aaxv0qvs . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . l1aaxv0qvs . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
l1aaxv0qvs . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . lzl45qjifg = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . lzl45qjifg = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . lzl45qjifg
= 0.0 ; } else { int_T currTimeIndex = rtDW . px2wccwv40 . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . lzl45qjifg = pDataValues [ currTimeIndex
] ; rtDW . px2wccwv40 . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . h234jcxu2z . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . h234jcxu2z . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
h234jcxu2z . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . fvz5ztlupg = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . fvz5ztlupg = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . fvz5ztlupg
= 0.0 ; } else { int_T currTimeIndex = rtDW . giadlp5izi . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . fvz5ztlupg = pDataValues [ currTimeIndex
] ; rtDW . giadlp5izi . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . clrd32dre4 .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . ip0uvrp3z3 ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . lzl45qjifg ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . fvz5ztlupg ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . epftsymyqn . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . epftsymyqn . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
epftsymyqn . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . jappjfmhaf = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . jappjfmhaf = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . jappjfmhaf
= 0.0 ; } else { int_T currTimeIndex = rtDW . nlmnijzpxw . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . jappjfmhaf = pDataValues [ currTimeIndex
] ; rtDW . nlmnijzpxw . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . ilpn10ybkm . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . ilpn10ybkm . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
ilpn10ybkm . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . hzs2cffwsh = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . hzs2cffwsh = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . hzs2cffwsh
= 0.0 ; } else { int_T currTimeIndex = rtDW . poz2ms4ply . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . hzs2cffwsh = pDataValues [ currTimeIndex
] ; rtDW . poz2ms4ply . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . izkwmahydg . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . izkwmahydg . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
izkwmahydg . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . mqr2iftmcf = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . mqr2iftmcf = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . mqr2iftmcf
= 0.0 ; } else { int_T currTimeIndex = rtDW . mz45s0obsk . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . mqr2iftmcf = pDataValues [ currTimeIndex
] ; rtDW . mz45s0obsk . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . okrhfkq4wg .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . jappjfmhaf ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . hzs2cffwsh ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . mqr2iftmcf ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . azgdj10ofq . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . azgdj10ofq . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
azgdj10ofq . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . bv141smffr = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . bv141smffr = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . bv141smffr
= 0.0 ; } else { int_T currTimeIndex = rtDW . ffaasee41y . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . bv141smffr = pDataValues [ currTimeIndex
] ; rtDW . ffaasee41y . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . i1szh3fwfk . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . i1szh3fwfk . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
i1szh3fwfk . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . n0ofmubc1v = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . n0ofmubc1v = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . n0ofmubc1v
= 0.0 ; } else { int_T currTimeIndex = rtDW . mxgci4hatn . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . n0ofmubc1v = pDataValues [ currTimeIndex
] ; rtDW . mxgci4hatn . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . iuvswjitkf . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . iuvswjitkf . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
iuvswjitkf . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . hkzej0bbqv = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . hkzej0bbqv = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . hkzej0bbqv
= 0.0 ; } else { int_T currTimeIndex = rtDW . jfxavml4ss . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . hkzej0bbqv = pDataValues [ currTimeIndex
] ; rtDW . jfxavml4ss . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . aciovtayfr .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . bv141smffr ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . n0ofmubc1v ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . hkzej0bbqv ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . ayhphwsgwq . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . ayhphwsgwq . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
ayhphwsgwq . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . hyn4m540so = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . hyn4m540so = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . hyn4m540so
= 0.0 ; } else { int_T currTimeIndex = rtDW . emklnm5eee . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . hyn4m540so = pDataValues [ currTimeIndex
] ; rtDW . emklnm5eee . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . ajdss4dhe0 . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . ajdss4dhe0 . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
ajdss4dhe0 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . i5xm4g4u24 = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . i5xm4g4u24 = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . i5xm4g4u24
= 0.0 ; } else { int_T currTimeIndex = rtDW . j1ehnbr3p0 . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . i5xm4g4u24 = pDataValues [ currTimeIndex
] ; rtDW . j1ehnbr3p0 . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . dh3f02y2sz . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . dh3f02y2sz . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
dh3f02y2sz . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . gmacchlgce = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . gmacchlgce = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . gmacchlgce
= 0.0 ; } else { int_T currTimeIndex = rtDW . azpkt4wjbr . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . gmacchlgce = pDataValues [ currTimeIndex
] ; rtDW . azpkt4wjbr . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . msjdgqazw2 .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . hyn4m540so ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . i5xm4g4u24 ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . gmacchlgce ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . kqoyc1etwg . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . kqoyc1etwg . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
kqoyc1etwg . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . phph3pe0fd = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . phph3pe0fd = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . phph3pe0fd
= 0.0 ; } else { int_T currTimeIndex = rtDW . hhpqhvbomw . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . phph3pe0fd = pDataValues [ currTimeIndex
] ; rtDW . hhpqhvbomw . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . mvcdlyri2j . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . mvcdlyri2j . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
mvcdlyri2j . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . psxmxvyoop = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . psxmxvyoop = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . psxmxvyoop
= 0.0 ; } else { int_T currTimeIndex = rtDW . kp31dep3dx . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . psxmxvyoop = pDataValues [ currTimeIndex
] ; rtDW . kp31dep3dx . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . hbcms1bq4r . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . hbcms1bq4r . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hbcms1bq4r . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . jkpzefwce0 = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . jkpzefwce0 = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . jkpzefwce0
= 0.0 ; } else { int_T currTimeIndex = rtDW . pcfosdoawh . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . jkpzefwce0 = pDataValues [ currTimeIndex
] ; rtDW . pcfosdoawh . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . imhpm3odyo .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . phph3pe0fd ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . psxmxvyoop ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . jkpzefwce0 ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . ddvlfm2hus . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . ddvlfm2hus . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
ddvlfm2hus . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . atrkvlif4k = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . atrkvlif4k = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . atrkvlif4k
= 0.0 ; } else { int_T currTimeIndex = rtDW . ir4ldnp24c . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . atrkvlif4k = pDataValues [ currTimeIndex
] ; rtDW . ir4ldnp24c . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . l3wkq1xedj . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . l3wkq1xedj . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
l3wkq1xedj . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . ekcsmuhkax = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . ekcsmuhkax = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . ekcsmuhkax
= 0.0 ; } else { int_T currTimeIndex = rtDW . kxnor0qurr . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . ekcsmuhkax = pDataValues [ currTimeIndex
] ; rtDW . kxnor0qurr . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . pjjr10dg4b . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . pjjr10dg4b . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
pjjr10dg4b . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . cwbebu3rd3 = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . cwbebu3rd3 = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . cwbebu3rd3
= 0.0 ; } else { int_T currTimeIndex = rtDW . nq5bs3wkyw . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . cwbebu3rd3 = pDataValues [ currTimeIndex
] ; rtDW . nq5bs3wkyw . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . ekwpduodoq .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . atrkvlif4k ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . ekcsmuhkax ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . cwbebu3rd3 ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlTerminate ( void ) { rt_FREE ( rtDW . azqf3zai0t . RSimInfoPtr ) ; rt_FREE
( rtDW . jnemuuzgzp . RSimInfoPtr ) ; rt_FREE ( rtDW . pzvgpjidp0 .
RSimInfoPtr ) ; rt_FREE ( rtDW . j21ldtcnma . RSimInfoPtr ) ; rt_FREE ( rtDW
. a2z3xgtwiy . RSimInfoPtr ) ; rt_FREE ( rtDW . oj2hmay041 . RSimInfoPtr ) ;
rt_FREE ( rtDW . mmlzbnupg4 . RSimInfoPtr ) ; rt_FREE ( rtDW . l1aaxv0qvs .
RSimInfoPtr ) ; rt_FREE ( rtDW . h234jcxu2z . RSimInfoPtr ) ; rt_FREE ( rtDW
. epftsymyqn . RSimInfoPtr ) ; rt_FREE ( rtDW . ilpn10ybkm . RSimInfoPtr ) ;
rt_FREE ( rtDW . izkwmahydg . RSimInfoPtr ) ; rt_FREE ( rtDW . azgdj10ofq .
RSimInfoPtr ) ; rt_FREE ( rtDW . i1szh3fwfk . RSimInfoPtr ) ; rt_FREE ( rtDW
. iuvswjitkf . RSimInfoPtr ) ; rt_FREE ( rtDW . ayhphwsgwq . RSimInfoPtr ) ;
rt_FREE ( rtDW . ajdss4dhe0 . RSimInfoPtr ) ; rt_FREE ( rtDW . dh3f02y2sz .
RSimInfoPtr ) ; rt_FREE ( rtDW . kqoyc1etwg . RSimInfoPtr ) ; rt_FREE ( rtDW
. mvcdlyri2j . RSimInfoPtr ) ; rt_FREE ( rtDW . hbcms1bq4r . RSimInfoPtr ) ;
rt_FREE ( rtDW . ddvlfm2hus . RSimInfoPtr ) ; rt_FREE ( rtDW . l3wkq1xedj .
RSimInfoPtr ) ; rt_FREE ( rtDW . pjjr10dg4b . RSimInfoPtr ) ; if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 32 ) ;
ssSetNumBlockIO ( rtS , 24 ) ; ssSetNumBlockParams ( rtS , 56580 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.015 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1039835684U ) ; ssSetChecksumVal ( rtS , 1 ,
1442330462U ) ; ssSetChecksumVal ( rtS , 2 , 3807622218U ) ; ssSetChecksumVal
( rtS , 3 , 3995259496U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } motorFFT_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"motorFFT" ) ; ssSetPath ( rtS , "motorFFT" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 63.989999999999995 ) ; ssSetStepSize ( rtS , 0.015 ) ;
ssSetFixedStepSize ( rtS , 0.015 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ;
rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo
( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ;
rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation (
ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" )
; rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
1039835684U ) ; ssSetChecksumVal ( rtS , 1 , 1442330462U ) ; ssSetChecksumVal
( rtS , 2 , 3807622218U ) ; ssSetChecksumVal ( rtS , 3 , 3995259496U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
