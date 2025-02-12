#include "rt_logging_mmi.h"
#include "motorFFT_2020a_capi.h"
#include <math.h>
#include "motorFFT_2020a.h"
#include "motorFFT_2020a_private.h"
#include "motorFFT_2020a_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 6 ;
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
"slprj//raccel//motorFFT_2020a//motorFFT_2020a_Jpattern.mat" ; const int_T
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
rt_ScopeBlockName [ ] = "motorFFT_2020a/Scope" ; static int_T
rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . pgnz3puzk1 . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "ScopeData" , 1 , 0 , 1 , 1.0E-7 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . pgnz3puzk1 .
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
rt_ScopeBlockName [ ] = "motorFFT_2020a/Scope1" ; static int_T
rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
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
rtDW . em5caundsj . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "ScopeData1" , 1 , 0 , 1 , 1.0E-7 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . em5caundsj .
LoggedData [ 0 ] == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0003662109375','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0 ; fromwksInfo
-> nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0 ; rtDW . i0ykffg1ze . TimePtr = fromwksInfo -> time ;
rtDW . i0ykffg1ze . DataPtr = fromwksInfo -> data ; rtDW . i0ykffg1ze .
RSimInfoPtr = fromwksInfo ; } rtDW . oiqioysmzl . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0003662109375','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo ->
nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0 ; rtDW . ldr32p4cok . TimePtr = fromwksInfo -> time ;
rtDW . ldr32p4cok . DataPtr = fromwksInfo -> data ; rtDW . ldr32p4cok .
RSimInfoPtr = fromwksInfo ; } rtDW . aa1yxvnz02 . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('4.0003662109375','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo
-> nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0 ; rtDW . cnf2j0v0jx . TimePtr = fromwksInfo -> time ;
rtDW . cnf2j0v0jx . DataPtr = fromwksInfo -> data ; rtDW . cnf2j0v0jx .
RSimInfoPtr = fromwksInfo ; } rtDW . absy2vvepd . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0003662109375','1')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_olkgbefqoo ;
fromwksInfo -> nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_ihfogtldbr ; rtDW . a25is5i5n3 . TimePtr = fromwksInfo
-> time ; rtDW . a25is5i5n3 . DataPtr = fromwksInfo -> data ; rtDW .
a25is5i5n3 . RSimInfoPtr = fromwksInfo ; } rtDW . dsmilhvssh . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0003662109375','2')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0_ayqgrylbms ;
fromwksInfo -> nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_dcjgz0pu3i ; rtDW . dtvtct1zhe . TimePtr = fromwksInfo ->
time ; rtDW . dtvtct1zhe . DataPtr = fromwksInfo -> data ; rtDW . dtvtct1zhe
. RSimInfoPtr = fromwksInfo ; } rtDW . dkld4y3dbe . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
"Simulink.signaleditorblock.SimulationData.getData('5.0003662109375','3')" ;
fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0_eeddlxo2x0 ;
fromwksInfo -> nDataPoints = 397 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0_aw5umakrsz ; rtDW . jzzvrrg0sx . TimePtr = fromwksInfo
-> time ; rtDW . jzzvrrg0sx . DataPtr = fromwksInfo -> data ; rtDW .
jzzvrrg0sx . RSimInfoPtr = fromwksInfo ; } rtDW . nzuoeuxs05 . PrevIndex = 0
; } } void MdlOutputs ( int_T tid ) { { real_T t = ssGetT ( rtS ) ; real_T *
pTimeValues = ( real_T * ) rtDW . i0ykffg1ze . TimePtr ; real_T * pDataValues
= ( real_T * ) rtDW . i0ykffg1ze . DataPtr ; int numPoints , lastPoint ;
FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . i0ykffg1ze . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <
pTimeValues [ 0 ] ) { rtB . gzdbvokcwj = 0.0 ; } else if ( t == pTimeValues [
lastPoint ] ) { rtB . gzdbvokcwj = pDataValues [ lastPoint ] ; } else if ( t
> pTimeValues [ lastPoint ] ) { rtB . gzdbvokcwj = 0.0 ; } else { int_T
currTimeIndex = rtDW . oiqioysmzl . PrevIndex ; if ( t < pTimeValues [
currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } rtB . gzdbvokcwj = pDataValues [ currTimeIndex ] ;
rtDW . oiqioysmzl . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT ( rtS
) ; real_T * pTimeValues = ( real_T * ) rtDW . ldr32p4cok . TimePtr ; real_T
* pDataValues = ( real_T * ) rtDW . ldr32p4cok . DataPtr ; int numPoints ,
lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . ldr32p4cok .
RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints
- 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . i5nivag4gq = 0.0 ; } else if ( t
== pTimeValues [ lastPoint ] ) { rtB . i5nivag4gq = pDataValues [ lastPoint ]
; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . i5nivag4gq = 0.0 ; }
else { int_T currTimeIndex = rtDW . aa1yxvnz02 . PrevIndex ; if ( t <
pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] )
{ currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1
] ) { currTimeIndex ++ ; } } rtB . i5nivag4gq = pDataValues [ currTimeIndex ]
; rtDW . aa1yxvnz02 . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . cnf2j0v0jx . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . cnf2j0v0jx . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
cnf2j0v0jx . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . itxjh5qdlr = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . itxjh5qdlr = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . itxjh5qdlr
= 0.0 ; } else { int_T currTimeIndex = rtDW . absy2vvepd . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . itxjh5qdlr = pDataValues [ currTimeIndex
] ; rtDW . absy2vvepd . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . pgnz3puzk1 .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . gzdbvokcwj ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . i5nivag4gq ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . itxjh5qdlr ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . a25is5i5n3 . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . a25is5i5n3 . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
a25is5i5n3 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . kngwwr0zmz = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . kngwwr0zmz = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . kngwwr0zmz
= 0.0 ; } else { int_T currTimeIndex = rtDW . dsmilhvssh . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . kngwwr0zmz = pDataValues [ currTimeIndex
] ; rtDW . dsmilhvssh . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . dtvtct1zhe . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . dtvtct1zhe . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
dtvtct1zhe . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . mp3esss30n = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . mp3esss30n = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . mp3esss30n
= 0.0 ; } else { int_T currTimeIndex = rtDW . dkld4y3dbe . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . mp3esss30n = pDataValues [ currTimeIndex
] ; rtDW . dkld4y3dbe . PrevIndex = currTimeIndex ; } } { real_T t = ssGetT (
rtS ) ; real_T * pTimeValues = ( real_T * ) rtDW . jzzvrrg0sx . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . jzzvrrg0sx . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
jzzvrrg0sx . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { rtB . d0jgvx3ldb = 0.0 ; }
else if ( t == pTimeValues [ lastPoint ] ) { rtB . d0jgvx3ldb = pDataValues [
lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) { rtB . d0jgvx3ldb
= 0.0 ; } else { int_T currTimeIndex = rtDW . nzuoeuxs05 . PrevIndex ; if ( t
< pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ]
) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex +
1 ] ) { currTimeIndex ++ ; } } rtB . d0jgvx3ldb = pDataValues [ currTimeIndex
] ; rtDW . nzuoeuxs05 . PrevIndex = currTimeIndex ; } } if ( ssGetLogOutput (
rtS ) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . em5caundsj .
LoggedData [ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime
= ssGetT ( rtS ) ; ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime
, 0 ) ; } { real_T up0 [ 1 ] ; up0 [ 0 ] = rtB . kngwwr0zmz ; rt_UpdateLogVar
( ( LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 1 ] ;
up1 [ 0 ] = rtB . mp3esss30n ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 )
; var = var -> next ; } { real_T up2 [ 1 ] ; up2 [ 0 ] = rtB . d0jgvx3ldb ;
rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } } UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlTerminate ( void ) { rt_FREE ( rtDW . i0ykffg1ze . RSimInfoPtr ) ; rt_FREE
( rtDW . ldr32p4cok . RSimInfoPtr ) ; rt_FREE ( rtDW . cnf2j0v0jx .
RSimInfoPtr ) ; rt_FREE ( rtDW . a25is5i5n3 . RSimInfoPtr ) ; rt_FREE ( rtDW
. dtvtct1zhe . RSimInfoPtr ) ; rt_FREE ( rtDW . jzzvrrg0sx . RSimInfoPtr ) ;
if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 8 ) ;
ssSetNumBlockIO ( rtS , 6 ) ; ssSetNumBlockParams ( rtS , 4764 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 1.0E-7 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3122028247U ) ; ssSetChecksumVal ( rtS , 1 ,
2194582210U ) ; ssSetChecksumVal ( rtS , 2 , 2685089608U ) ; ssSetChecksumVal
( rtS , 3 , 1854165697U ) ; }
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
dataTypeInfoTable = rtDataTypeInfoTable ; }
motorFFT_2020a_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "motorFFT_2020a" ) ;
ssSetPath ( rtS , "motorFFT_2020a" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; ssSetStepSize ( rtS , 1.0E-7 ) ;
ssSetFixedStepSize ( rtS , 1.0E-7 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
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
3122028247U ) ; ssSetChecksumVal ( rtS , 1 , 2194582210U ) ; ssSetChecksumVal
( rtS , 2 , 2685089608U ) ; ssSetChecksumVal ( rtS , 3 , 1854165697U ) ; {
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
