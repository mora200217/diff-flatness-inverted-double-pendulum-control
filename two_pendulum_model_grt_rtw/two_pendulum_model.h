/*
 * two_pendulum_model.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "two_pendulum_model".
 *
 * Model version              : 6.0
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sun May 31 15:07:42 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef two_pendulum_model_h_
#define two_pendulum_model_h_
#ifndef two_pendulum_model_COMMON_INCLUDES_
#define two_pendulum_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "nesl_rtw.h"
#include "two_pendulum_model_afee0aca_1_gateway.h"
#endif                                 /* two_pendulum_model_COMMON_INCLUDES_ */

#include "two_pendulum_model_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T STATE_1[8];                   /* '<S22>/STATE_1' */
  real_T OUTPUT_1_0[6];                /* '<S22>/OUTPUT_1_0' */
  real_T Step;                         /* '<Root>/Step' */
  real_T INPUT_1_1_1[4];               /* '<S22>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S22>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S22>/INPUT_3_1_1' */
} B_two_pendulum_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete_1792859498[2];/* '<S22>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete_763144122[2];/* '<S22>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete_270306826[2];/* '<S22>/INPUT_3_1_1' */
  real_T STATE_1_Discrete;             /* '<S22>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S22>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S22>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S22>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S22>/STATE_1' */
  void* STATE_1_SimData;               /* '<S22>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S22>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S22>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S22>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S22>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S22>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S22>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S22>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S22>/OUTPUT_1_0' */
  void* SINK_1_RtwLogger;              /* '<S22>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S22>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S22>/SINK_1' */
  void* SINK_1_InstRtwLogger;          /* '<S22>/SINK_1' */
  void* SINK_1_InstRtwLogBuffer;       /* '<S22>/SINK_1' */
  int_T STATE_1_Modes;                 /* '<S22>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S22>/OUTPUT_1_0' */
  uint8_T STATE_1_ZcSignalDir;         /* '<S22>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S22>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S22>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S22>/OUTPUT_1_0' */
  boolean_T STATE_1_FirstOutput;       /* '<S22>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S22>/OUTPUT_1_0' */
} DW_two_pendulum_model_T;

/* Continuous states (default storage) */
typedef struct {
  real_T two_pendulum_modelSistema_No_li[8];/* '<S22>/STATE_1' */
} X_two_pendulum_model_T;

/* State derivatives (default storage) */
typedef struct {
  real_T two_pendulum_modelSistema_No_li[8];/* '<S22>/STATE_1' */
} XDot_two_pendulum_model_T;

/* State disabled  */
typedef struct {
  boolean_T two_pendulum_modelSistema_No_li[8];/* '<S22>/STATE_1' */
} XDis_two_pendulum_model_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_two_pendulum_model_T_ {
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_two_pendulum_model_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_two_pendulum_model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_two_pendulum_model_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_two_pendulum_model_T two_pendulum_model_P;

/* Block signals (default storage) */
extern B_two_pendulum_model_T two_pendulum_model_B;

/* Continuous states (default storage) */
extern X_two_pendulum_model_T two_pendulum_model_X;

/* Disabled states (default storage) */
extern XDis_two_pendulum_model_T two_pendulum_model_XDis;

/* Block states (default storage) */
extern DW_two_pendulum_model_T two_pendulum_model_DW;

/* Model entry point functions */
extern void two_pendulum_model_initialize(void);
extern void two_pendulum_model_step(void);
extern void two_pendulum_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_two_pendulum_model_T *const two_pendulum_model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'two_pendulum_model'
 * '<S1>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask'
 * '<S2>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/Graficos escenario '
 * '<S3>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter'
 * '<S4>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter1'
 * '<S5>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter2'
 * '<S6>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter3'
 * '<S7>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter4'
 * '<S8>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter5'
 * '<S9>'   : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter'
 * '<S10>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter1'
 * '<S11>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter2'
 * '<S12>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration'
 * '<S13>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter/EVAL_KEY'
 * '<S14>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter1/EVAL_KEY'
 * '<S15>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter2/EVAL_KEY'
 * '<S16>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter3/EVAL_KEY'
 * '<S17>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter4/EVAL_KEY'
 * '<S18>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/PS-Simulink Converter5/EVAL_KEY'
 * '<S19>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter/EVAL_KEY'
 * '<S20>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter1/EVAL_KEY'
 * '<S21>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Simulink-PS Converter2/EVAL_KEY'
 * '<S22>'  : 'two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* two_pendulum_model_h_ */
