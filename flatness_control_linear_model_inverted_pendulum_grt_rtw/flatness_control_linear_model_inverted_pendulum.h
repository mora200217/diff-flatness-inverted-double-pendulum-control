/*
 * flatness_control_linear_model_inverted_pendulum.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flatness_control_linear_model_inverted_pendulum".
 *
 * Model version              : 6.6
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Jun  1 00:30:01 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef flatness_control_linear_model_inverted_pendulum_h_
#define flatness_control_linear_model_inverted_pendulum_h_
#ifndef flatness_control_linear_model_inverted_pendulum_COMMON_INCLUDES_
#define flatness_control_linear_model_inverted_pendulum_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "nesl_rtw.h"
#include "flatness_control_linear_model_inverted_pendulum_afee0aca_1_gateway.h"
#endif    /* flatness_control_linear_model_inverted_pendulum_COMMON_INCLUDES_ */

#include "flatness_control_linear_model_inverted_pendulum_types.h"
#include <math.h>
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

#define flatness_control_linear_model_inverted_pendulum_M (flatness_control_linear_mode_M)

/* Block signals (default storage) */
typedef struct {
  real_T STATE_1[8];                   /* '<S24>/STATE_1' */
  real_T OUTPUT_1_0[6];                /* '<S24>/OUTPUT_1_0' */
  real_T FromWorkspace[7];             /* '<S2>/From Workspace' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T INPUT_1_1_1[4];               /* '<S24>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S24>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S24>/INPUT_3_1_1' */
} B_flatness_control_linear_mod_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete_1792859498[2];/* '<S24>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete_763144122[2];/* '<S24>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete_270306826[2];/* '<S24>/INPUT_3_1_1' */
  real_T STATE_1_Discrete;             /* '<S24>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S24>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S24>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S24>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S24>/STATE_1' */
  void* STATE_1_SimData;               /* '<S24>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S24>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S24>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S24>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S24>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S24>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S24>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S24>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S24>/OUTPUT_1_0' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S2>/From Workspace' */

  void* SINK_1_RtwLogger;              /* '<S24>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S24>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S24>/SINK_1' */
  void* SINK_1_InstRtwLogger;          /* '<S24>/SINK_1' */
  void* SINK_1_InstRtwLogBuffer;       /* '<S24>/SINK_1' */
  int_T STATE_1_Modes;                 /* '<S24>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S24>/OUTPUT_1_0' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S2>/From Workspace' */

  uint8_T STATE_1_ZcSignalDir;         /* '<S24>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S24>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S24>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S24>/OUTPUT_1_0' */
  boolean_T STATE_1_FirstOutput;       /* '<S24>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S24>/OUTPUT_1_0' */
} DW_flatness_control_linear_mo_T;

/* Continuous states (default storage) */
typedef struct {
  real_T flatness_control_linear_model_i[8];/* '<S24>/STATE_1' */
} X_flatness_control_linear_mod_T;

/* State derivatives (default storage) */
typedef struct {
  real_T flatness_control_linear_model_i[8];/* '<S24>/STATE_1' */
} XDot_flatness_control_linear__T;

/* State disabled  */
typedef struct {
  boolean_T flatness_control_linear_model_i[8];/* '<S24>/STATE_1' */
} XDis_flatness_control_linear__T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_flatness_control_linear_mod_T_ {
  real_T K_cancel[6];                  /* Variable: K_cancel
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T K_error[6];                   /* Variable: K_error
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T T[36];                        /* Variable: T
                                        * Referenced by: '<Root>/Transformacion salida plana'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_flatness_control_line_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_flatness_control_linear_mod_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_flatness_control_linear__T *contStateDisabled;
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
extern P_flatness_control_linear_mod_T flatness_control_linear_model_P;

/* Block signals (default storage) */
extern B_flatness_control_linear_mod_T flatness_control_linear_model_B;

/* Continuous states (default storage) */
extern X_flatness_control_linear_mod_T flatness_control_linear_model_X;

/* Disabled states (default storage) */
extern XDis_flatness_control_linear__T flatness_control_linear_mo_XDis;

/* Block states (default storage) */
extern DW_flatness_control_linear_mo_T flatness_control_linear_mode_DW;

/* Model entry point functions */
extern void flatness_control_linear_model_inverted_pendulum_initialize(void);
extern void flatness_control_linear_model_inverted_pendulum_step(void);
extern void flatness_control_linear_model_inverted_pendulum_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flatness_control_lin_T *const flatness_control_linear_mode_M;

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
 * '<Root>' : 'flatness_control_linear_model_inverted_pendulum'
 * '<S1>'   : 'flatness_control_linear_model_inverted_pendulum/Controlador Salida Plana'
 * '<S2>'   : 'flatness_control_linear_model_inverted_pendulum/Reference generator'
 * '<S3>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask'
 * '<S4>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Graficos escenario '
 * '<S5>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter'
 * '<S6>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter1'
 * '<S7>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter2'
 * '<S8>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter3'
 * '<S9>'   : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter4'
 * '<S10>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter5'
 * '<S11>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter'
 * '<S12>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter1'
 * '<S13>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter2'
 * '<S14>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Solver Configuration'
 * '<S15>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter/EVAL_KEY'
 * '<S16>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter1/EVAL_KEY'
 * '<S17>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter2/EVAL_KEY'
 * '<S18>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter3/EVAL_KEY'
 * '<S19>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter4/EVAL_KEY'
 * '<S20>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/PS-Simulink Converter5/EVAL_KEY'
 * '<S21>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter/EVAL_KEY'
 * '<S22>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter1/EVAL_KEY'
 * '<S23>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Simulink-PS Converter2/EVAL_KEY'
 * '<S24>'  : 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Solver Configuration/EVAL_KEY'
 */
#endif                  /* flatness_control_linear_model_inverted_pendulum_h_ */
