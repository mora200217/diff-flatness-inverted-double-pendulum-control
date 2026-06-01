/*
 * two_pendulum_model.c
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

#include "two_pendulum_model.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "two_pendulum_model_private.h"

/* Block signals (default storage) */
B_two_pendulum_model_T two_pendulum_model_B;

/* Continuous states */
X_two_pendulum_model_T two_pendulum_model_X;

/* Disabled State Vector */
XDis_two_pendulum_model_T two_pendulum_model_XDis;

/* Block states (default storage) */
DW_two_pendulum_model_T two_pendulum_model_DW;

/* Real-time model */
static RT_MODEL_two_pendulum_model_T two_pendulum_model_M_;
RT_MODEL_two_pendulum_model_T *const two_pendulum_model_M =
  &two_pendulum_model_M_;

/* Projection for root system: '<Root>' */
void two_pendulum_model_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[12];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[4];
  boolean_T tmp;

  /* Projection for SimscapeExecutionBlock: '<S22>/STATE_1' */
  simulationData = (NeslSimulationData *)two_pendulum_model_DW.STATE_1_SimData;
  time = two_pendulum_model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 8;
  simulationData->mData->mContStates.mX =
    &two_pendulum_model_X.two_pendulum_modelSistema_No_li[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &two_pendulum_model_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &two_pendulum_model_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (two_pendulum_model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&two_pendulum_model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&two_pendulum_model_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = two_pendulum_model_B.INPUT_1_1_1[0];
  tmp_0[1] = two_pendulum_model_B.INPUT_1_1_1[1];
  tmp_0[2] = two_pendulum_model_B.INPUT_1_1_1[2];
  tmp_0[3] = two_pendulum_model_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = two_pendulum_model_B.INPUT_2_1_1[0];
  tmp_0[5] = two_pendulum_model_B.INPUT_2_1_1[1];
  tmp_0[6] = two_pendulum_model_B.INPUT_2_1_1[2];
  tmp_0[7] = two_pendulum_model_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = two_pendulum_model_B.INPUT_3_1_1[0];
  tmp_0[9] = two_pendulum_model_B.INPUT_3_1_1[1];
  tmp_0[10] = two_pendulum_model_B.INPUT_3_1_1[2];
  tmp_0[11] = two_pendulum_model_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)
    two_pendulum_model_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    two_pendulum_model_DW.STATE_1_Simulator, NESL_SIM_PROJECTION, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(two_pendulum_model_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S22>/STATE_1' */
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  two_pendulum_model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  two_pendulum_model_step();
  two_pendulum_model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  two_pendulum_model_step();
  two_pendulum_model_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  two_pendulum_model_step();
  two_pendulum_model_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void two_pendulum_model_step(void)
{
  if (rtmIsMajorTimeStep(two_pendulum_model_M)) {
    /* set solver stop time */
    if (!(two_pendulum_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&two_pendulum_model_M->solverInfo,
                            ((two_pendulum_model_M->Timing.clockTickH0 + 1) *
        two_pendulum_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&two_pendulum_model_M->solverInfo,
                            ((two_pendulum_model_M->Timing.clockTick0 + 1) *
        two_pendulum_model_M->Timing.stepSize0 +
        two_pendulum_model_M->Timing.clockTickH0 *
        two_pendulum_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(two_pendulum_model_M)) {
    two_pendulum_model_M->Timing.t[0] = rtsiGetT
      (&two_pendulum_model_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_5[20];
    real_T tmp_1[12];
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_tmp;
    real_T time_tmp_0;
    int32_T tmp_3;
    int_T tmp_6[5];
    int_T tmp_2[4];
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_4;

    /* SimscapeExecutionBlock: '<S22>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S22>/OUTPUT_1_0'
     *  SimscapeInputBlock: '<S22>/INPUT_2_1_1'
     *  SimscapeInputBlock: '<S22>/INPUT_3_1_1'
     *  Step: '<Root>/Step'
     */
    simulationData = (NeslSimulationData *)two_pendulum_model_DW.STATE_1_SimData;
    time_tmp = two_pendulum_model_M->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 8;
    simulationData->mData->mContStates.mX =
      &two_pendulum_model_X.two_pendulum_modelSistema_No_li[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &two_pendulum_model_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &two_pendulum_model_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    tmp = rtmIsMajorTimeStep(two_pendulum_model_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&two_pendulum_model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_0 = rtsiIsModeUpdateTimeStep(&two_pendulum_model_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_2[0] = 0;
    tmp_1[0] = two_pendulum_model_B.INPUT_1_1_1[0];
    tmp_1[1] = two_pendulum_model_B.INPUT_1_1_1[1];
    tmp_1[2] = two_pendulum_model_B.INPUT_1_1_1[2];
    tmp_1[3] = two_pendulum_model_B.INPUT_1_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = two_pendulum_model_B.INPUT_2_1_1[0];
    tmp_1[5] = two_pendulum_model_B.INPUT_2_1_1[1];
    tmp_1[6] = two_pendulum_model_B.INPUT_2_1_1[2];
    tmp_1[7] = two_pendulum_model_B.INPUT_2_1_1[3];
    tmp_2[2] = 8;
    tmp_1[8] = two_pendulum_model_B.INPUT_3_1_1[0];
    tmp_1[9] = two_pendulum_model_B.INPUT_3_1_1[1];
    tmp_1[10] = two_pendulum_model_B.INPUT_3_1_1[2];
    tmp_1[11] = two_pendulum_model_B.INPUT_3_1_1[3];
    tmp_2[3] = 12;
    simulationData->mData->mInputValues.mN = 12;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    simulationData->mData->mOutputs.mN = 8;
    simulationData->mData->mOutputs.mX = &two_pendulum_model_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_tmp_0 = two_pendulum_model_M->Timing.t[0];
    time_0 = time_tmp_0;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diagnosticManager = (NeuDiagnosticManager *)
      two_pendulum_model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)
      two_pendulum_model_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
      if (tmp_4) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(two_pendulum_model_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S22>/STATE_1' */

    /* SimscapeExecutionBlock: '<S22>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)
      two_pendulum_model_DW.OUTPUT_1_0_SimData;
    time_1 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &two_pendulum_model_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &two_pendulum_model_DW.OUTPUT_1_0_Modes;
    tmp_4 = false;
    simulationData->mData->mFoundZcEvents = tmp_4;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_4 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_4;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp_0;
    tmp_6[0] = 0;
    tmp_5[0] = two_pendulum_model_B.INPUT_1_1_1[0];
    tmp_5[1] = two_pendulum_model_B.INPUT_1_1_1[1];
    tmp_5[2] = two_pendulum_model_B.INPUT_1_1_1[2];
    tmp_5[3] = two_pendulum_model_B.INPUT_1_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = two_pendulum_model_B.INPUT_2_1_1[0];
    tmp_5[5] = two_pendulum_model_B.INPUT_2_1_1[1];
    tmp_5[6] = two_pendulum_model_B.INPUT_2_1_1[2];
    tmp_5[7] = two_pendulum_model_B.INPUT_2_1_1[3];
    tmp_6[2] = 8;
    tmp_5[8] = two_pendulum_model_B.INPUT_3_1_1[0];
    tmp_5[9] = two_pendulum_model_B.INPUT_3_1_1[1];
    tmp_5[10] = two_pendulum_model_B.INPUT_3_1_1[2];
    tmp_5[11] = two_pendulum_model_B.INPUT_3_1_1[3];
    tmp_6[3] = 12;
    memcpy(&tmp_5[12], &two_pendulum_model_B.STATE_1[0], sizeof(real_T) << 3U);
    tmp_6[4] = 20;
    simulationData->mData->mInputValues.mN = 20;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 6;
    simulationData->mData->mOutputs.mX = &two_pendulum_model_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_2 = time_tmp_0;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diagnosticManager = (NeuDiagnosticManager *)
      two_pendulum_model_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)
      two_pendulum_model_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(two_pendulum_model_M, msg_0);
      }
    }

    if (rtmIsMajorTimeStep(two_pendulum_model_M)) {
    }

    /* Step: '<Root>/Step' */
    if (time_tmp_0 < two_pendulum_model_P.Step_Time) {
      /* Step: '<Root>/Step' */
      two_pendulum_model_B.Step = two_pendulum_model_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      two_pendulum_model_B.Step = two_pendulum_model_P.Step_YFinal;
    }

    /* SimscapeInputBlock: '<S22>/INPUT_1_1_1' */
    two_pendulum_model_B.INPUT_1_1_1[0] = two_pendulum_model_B.Step;
    two_pendulum_model_B.INPUT_1_1_1[1] = 0.0;
    two_pendulum_model_B.INPUT_1_1_1[2] = 0.0;
    two_pendulum_model_B.INPUT_1_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S22>/INPUT_2_1_1' */
    two_pendulum_model_B.INPUT_2_1_1[0] = 0.0;
    two_pendulum_model_B.INPUT_2_1_1[1] = 0.0;
    two_pendulum_model_B.INPUT_2_1_1[2] = 0.0;
    if (tmp) {
      two_pendulum_model_DW.INPUT_2_1_1_Discrete_763144122[0] =
        !(two_pendulum_model_B.INPUT_2_1_1[0] ==
          two_pendulum_model_DW.INPUT_2_1_1_Discrete_763144122[1]);
      two_pendulum_model_DW.INPUT_2_1_1_Discrete_763144122[1] =
        two_pendulum_model_B.INPUT_2_1_1[0];
    }

    two_pendulum_model_B.INPUT_2_1_1[0] =
      two_pendulum_model_DW.INPUT_2_1_1_Discrete_763144122[1];
    two_pendulum_model_B.INPUT_2_1_1[3] =
      two_pendulum_model_DW.INPUT_2_1_1_Discrete_763144122[0];

    /* SimscapeInputBlock: '<S22>/INPUT_3_1_1' */
    two_pendulum_model_B.INPUT_3_1_1[0] = 0.0;
    two_pendulum_model_B.INPUT_3_1_1[1] = 0.0;
    two_pendulum_model_B.INPUT_3_1_1[2] = 0.0;
    if (tmp) {
      two_pendulum_model_DW.INPUT_3_1_1_Discrete_270306826[0] =
        !(two_pendulum_model_B.INPUT_3_1_1[0] ==
          two_pendulum_model_DW.INPUT_3_1_1_Discrete_270306826[1]);
      two_pendulum_model_DW.INPUT_3_1_1_Discrete_270306826[1] =
        two_pendulum_model_B.INPUT_3_1_1[0];
    }

    two_pendulum_model_B.INPUT_3_1_1[0] =
      two_pendulum_model_DW.INPUT_3_1_1_Discrete_270306826[1];
    two_pendulum_model_B.INPUT_3_1_1[3] =
      two_pendulum_model_DW.INPUT_3_1_1_Discrete_270306826[0];
  }

  if (rtmIsMajorTimeStep(two_pendulum_model_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(two_pendulum_model_M->rtwLogInfo,
                        (two_pendulum_model_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(two_pendulum_model_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[12];
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[4];
    boolean_T tmp;

    /* Update for SimscapeExecutionBlock: '<S22>/STATE_1' */
    simulationData = (NeslSimulationData *)two_pendulum_model_DW.STATE_1_SimData;
    time = two_pendulum_model_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 8;
    simulationData->mData->mContStates.mX =
      &two_pendulum_model_X.two_pendulum_modelSistema_No_li[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &two_pendulum_model_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &two_pendulum_model_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (two_pendulum_model_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&two_pendulum_model_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&two_pendulum_model_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = two_pendulum_model_B.INPUT_1_1_1[0];
    tmp_0[1] = two_pendulum_model_B.INPUT_1_1_1[1];
    tmp_0[2] = two_pendulum_model_B.INPUT_1_1_1[2];
    tmp_0[3] = two_pendulum_model_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = two_pendulum_model_B.INPUT_2_1_1[0];
    tmp_0[5] = two_pendulum_model_B.INPUT_2_1_1[1];
    tmp_0[6] = two_pendulum_model_B.INPUT_2_1_1[2];
    tmp_0[7] = two_pendulum_model_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = two_pendulum_model_B.INPUT_3_1_1[0];
    tmp_0[9] = two_pendulum_model_B.INPUT_3_1_1[1];
    tmp_0[10] = two_pendulum_model_B.INPUT_3_1_1[2];
    tmp_0[11] = two_pendulum_model_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    simulationData->mData->mInputValues.mN = 12;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)
      two_pendulum_model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      two_pendulum_model_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(two_pendulum_model_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S22>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(two_pendulum_model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(two_pendulum_model_M)!=-1) &&
          !((rtmGetTFinal(two_pendulum_model_M)-
             (((two_pendulum_model_M->Timing.clockTick1+
                two_pendulum_model_M->Timing.clockTickH1* 4294967296.0)) *
              0.0001)) > (((two_pendulum_model_M->Timing.clockTick1+
                            two_pendulum_model_M->Timing.clockTickH1*
                            4294967296.0)) * 0.0001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(two_pendulum_model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&two_pendulum_model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++two_pendulum_model_M->Timing.clockTick0)) {
      ++two_pendulum_model_M->Timing.clockTickH0;
    }

    two_pendulum_model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&two_pendulum_model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      two_pendulum_model_M->Timing.clockTick1++;
      if (!two_pendulum_model_M->Timing.clockTick1) {
        two_pendulum_model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void two_pendulum_model_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_two_pendulum_model_T *_rtXdot;
  char *msg;
  real_T tmp_0[12];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[4];
  boolean_T tmp;
  _rtXdot = ((XDot_two_pendulum_model_T *) two_pendulum_model_M->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S22>/STATE_1' */
  simulationData = (NeslSimulationData *)two_pendulum_model_DW.STATE_1_SimData;
  time = two_pendulum_model_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 8;
  simulationData->mData->mContStates.mX =
    &two_pendulum_model_X.two_pendulum_modelSistema_No_li[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &two_pendulum_model_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &two_pendulum_model_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (two_pendulum_model_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&two_pendulum_model_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&two_pendulum_model_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = two_pendulum_model_B.INPUT_1_1_1[0];
  tmp_0[1] = two_pendulum_model_B.INPUT_1_1_1[1];
  tmp_0[2] = two_pendulum_model_B.INPUT_1_1_1[2];
  tmp_0[3] = two_pendulum_model_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = two_pendulum_model_B.INPUT_2_1_1[0];
  tmp_0[5] = two_pendulum_model_B.INPUT_2_1_1[1];
  tmp_0[6] = two_pendulum_model_B.INPUT_2_1_1[2];
  tmp_0[7] = two_pendulum_model_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = two_pendulum_model_B.INPUT_3_1_1[0];
  tmp_0[9] = two_pendulum_model_B.INPUT_3_1_1[1];
  tmp_0[10] = two_pendulum_model_B.INPUT_3_1_1[2];
  tmp_0[11] = two_pendulum_model_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 8;
  simulationData->mData->mDx.mX = &_rtXdot->two_pendulum_modelSistema_No_li[0];
  diagnosticManager = (NeuDiagnosticManager *)
    two_pendulum_model_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    two_pendulum_model_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES,
    simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(two_pendulum_model_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S22>/STATE_1' */
}

/* Model initialize function */
void two_pendulum_model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)two_pendulum_model_M, 0,
                sizeof(RT_MODEL_two_pendulum_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&two_pendulum_model_M->solverInfo,
                          &two_pendulum_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&two_pendulum_model_M->solverInfo, &rtmGetTPtr
                (two_pendulum_model_M));
    rtsiSetStepSizePtr(&two_pendulum_model_M->solverInfo,
                       &two_pendulum_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&two_pendulum_model_M->solverInfo,
                 &two_pendulum_model_M->derivs);
    rtsiSetContStatesPtr(&two_pendulum_model_M->solverInfo, (real_T **)
                         &two_pendulum_model_M->contStates);
    rtsiSetNumContStatesPtr(&two_pendulum_model_M->solverInfo,
      &two_pendulum_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&two_pendulum_model_M->solverInfo,
      &two_pendulum_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&two_pendulum_model_M->solverInfo,
      &two_pendulum_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&two_pendulum_model_M->solverInfo,
      &two_pendulum_model_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&two_pendulum_model_M->solverInfo, (boolean_T**)
      &two_pendulum_model_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&two_pendulum_model_M->solverInfo, (&rtmGetErrorStatus
      (two_pendulum_model_M)));
    rtsiSetRTModelPtr(&two_pendulum_model_M->solverInfo, two_pendulum_model_M);
  }

  rtsiSetSimTimeStep(&two_pendulum_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&two_pendulum_model_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&two_pendulum_model_M->solverInfo, false);
  two_pendulum_model_M->intgData.y = two_pendulum_model_M->odeY;
  two_pendulum_model_M->intgData.f[0] = two_pendulum_model_M->odeF[0];
  two_pendulum_model_M->intgData.f[1] = two_pendulum_model_M->odeF[1];
  two_pendulum_model_M->intgData.f[2] = two_pendulum_model_M->odeF[2];
  two_pendulum_model_M->contStates = ((X_two_pendulum_model_T *)
    &two_pendulum_model_X);
  two_pendulum_model_M->contStateDisabled = ((XDis_two_pendulum_model_T *)
    &two_pendulum_model_XDis);
  two_pendulum_model_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&two_pendulum_model_M->solverInfo, (void *)
                    &two_pendulum_model_M->intgData);
  rtsiSetSolverName(&two_pendulum_model_M->solverInfo,"ode3");
  rtmSetTPtr(two_pendulum_model_M, &two_pendulum_model_M->Timing.tArray[0]);
  rtmSetTFinal(two_pendulum_model_M, 10.0);
  two_pendulum_model_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    two_pendulum_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(two_pendulum_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(two_pendulum_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(two_pendulum_model_M->rtwLogInfo, "tout");
    rtliSetLogX(two_pendulum_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(two_pendulum_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(two_pendulum_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(two_pendulum_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(two_pendulum_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(two_pendulum_model_M->rtwLogInfo, 1);
    rtliSetLogY(two_pendulum_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(two_pendulum_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(two_pendulum_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &two_pendulum_model_B), 0,
                sizeof(B_two_pendulum_model_T));

  /* states (continuous) */
  {
    (void) memset((void *)&two_pendulum_model_X, 0,
                  sizeof(X_two_pendulum_model_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&two_pendulum_model_XDis, 0,
                  sizeof(XDis_two_pendulum_model_T));
  }

  /* states (dwork) */
  (void) memset((void *)&two_pendulum_model_DW, 0,
                sizeof(DW_two_pendulum_model_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(two_pendulum_model_M->rtwLogInfo, 0.0,
    rtmGetTFinal(two_pendulum_model_M), two_pendulum_model_M->Timing.stepSize0,
    (&rtmGetErrorStatus(two_pendulum_model_M)));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for SimscapeExecutionBlock: '<S22>/STATE_1' */
    tmp = nesl_lease_simulator(
      "two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1",
      0, 0);
    two_pendulum_model_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(two_pendulum_model_DW.STATE_1_Simulator);
    if (tmp_0) {
      two_pendulum_model_afee0aca_1_gateway();
      tmp = nesl_lease_simulator(
        "two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1",
        0, 0);
      two_pendulum_model_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    two_pendulum_model_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    two_pendulum_model_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 0.0001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 7.02158854E+8;
    modelParameters.mZcDisabled = true;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      two_pendulum_model_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      two_pendulum_model_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(two_pendulum_model_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S22>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S22>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator(
      "two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1",
      1, 0);
    two_pendulum_model_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(two_pendulum_model_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      two_pendulum_model_afee0aca_1_gateway();
      tmp = nesl_lease_simulator(
        "two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1",
        1, 0);
      two_pendulum_model_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    two_pendulum_model_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    two_pendulum_model_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 0.0001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 7.02158854E+8;
    modelParameters_0.mZcDisabled = true;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      two_pendulum_model_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      two_pendulum_model_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(two_pendulum_model_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(two_pendulum_model_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S22>/OUTPUT_1_0' */
  }
}

/* Model terminate function */
void two_pendulum_model_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S22>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    two_pendulum_model_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    two_pendulum_model_DW.STATE_1_SimData);
  nesl_erase_simulator("two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S22>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    two_pendulum_model_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    two_pendulum_model_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration_1");
  nesl_destroy_registry();
}
