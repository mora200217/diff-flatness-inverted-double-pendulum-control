/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "pm_default_allocator.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ssc_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_CTarget.h"

void flatness_control_linear_model_inverted_pendulum_afee0aca_49_setTargets(
  const RuntimeDerivedValuesBundle *rtdv, CTarget *targets)
{
  (void) rtdv;
  (void) targets;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_resetAsmStateVector
  (const void *mech, double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = xx[0];
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_initializeTrackedAngleState
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, const int
   *modeVector, const double *motionData, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeDiscreteState
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, const int
   *modeVector, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
}

void flatness_control_linear_model_inverted_pendulum_afee0aca_49_adjustPosition(
  const void *mech, const double *dofDeltas, double *state)
{
  (void) mech;
  state[0] = state[0] + dofDeltas[0];
  state[1] = state[1] + dofDeltas[1];
  state[4] = state[4] + dofDeltas[2];
  state[6] = state[6] + dofDeltas[3];
}

static void perturbAsmJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbAsmJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[2] = state[2] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbAsmJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[3] = state[3] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_0(double mag, double *state)
{
  state[4] = state[4] + mag;
}

static void perturbAsmJointPrimitiveState_1_0v(double mag, double *state)
{
  state[4] = state[4] + mag;
  state[5] = state[5] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_2_0(double mag, double *state)
{
  state[6] = state[6] + mag;
}

static void perturbAsmJointPrimitiveState_2_0v(double mag, double *state)
{
  state[6] = state[6] + mag;
  state[7] = state[7] - 0.875 * mag;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_perturbAsmJointPrimitiveState
  (const void *mech, size_t stageIdx, size_t primIdx, double mag, boolean_T
   doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbAsmJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbAsmJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbAsmJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbAsmJointPrimitiveState_0_1v(mag, state);
    break;

   case 12:
    perturbAsmJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbAsmJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbAsmJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbAsmJointPrimitiveState_2_0v(mag, state);
    break;
  }
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computePosDofBlendMatrix
  (const void *mech, size_t stageIdx, size_t primIdx, const double *state, int
   partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeVelDofBlendMatrix
  (const void *mech, size_t stageIdx, size_t primIdx, const double *state, int
   partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_projectPartiallyTargetedPos
  (const void *mech, size_t stageIdx, size_t primIdx, const double *origState,
   int partialType, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void flatness_control_linear_model_inverted_pendulum_afee0aca_49_propagateMotion
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, const double *state,
   double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[16];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  xx[0] = 0.0;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[4];
  xx[3] = cos(xx[2]);
  xx[4] = sin(xx[2]);
  xx[2] = 2.0;
  xx[5] = 0.41999999993;
  xx[6] = xx[5] * xx[4];
  xx[7] = xx[2] * xx[6] * xx[3];
  xx[8] = 0.02500000000000002;
  xx[9] = xx[2] * xx[6] * xx[4] - xx[5];
  xx[6] = xx[1] * state[6];
  xx[1] = cos(xx[6]);
  xx[10] = sin(xx[6]);
  xx[6] = 0.1909999999710606;
  xx[11] = xx[6] * xx[10];
  xx[12] = xx[2] * xx[11] * xx[1];
  xx[13] = xx[2] * xx[11] * xx[10] - xx[6];
  xx[11] = 0.04999999999999999;
  xx[14] = state[2] * xx[4];
  xx[15] = state[2] * xx[10];
  motionData[0] = - 1.0;
  motionData[1] = xx[0];
  motionData[2] = xx[0];
  motionData[3] = xx[0];
  motionData[4] = state[0];
  motionData[5] = state[1];
  motionData[6] = 0.02499999999999997;
  motionData[7] = - xx[3];
  motionData[8] = xx[0];
  motionData[9] = - xx[4];
  motionData[10] = xx[0];
  motionData[11] = xx[7];
  motionData[12] = xx[0];
  motionData[13] = xx[8] - xx[9];
  motionData[14] = - xx[1];
  motionData[15] = xx[0];
  motionData[16] = - xx[10];
  motionData[17] = xx[0];
  motionData[18] = xx[12];
  motionData[19] = xx[0];
  motionData[20] = xx[8] - xx[13];
  motionData[21] = xx[3];
  motionData[22] = xx[0];
  motionData[23] = xx[4];
  motionData[24] = xx[0];
  motionData[25] = state[0] + xx[7];
  motionData[26] = state[1];
  motionData[27] = xx[11] - xx[9];
  motionData[28] = xx[1];
  motionData[29] = xx[0];
  motionData[30] = xx[10];
  motionData[31] = xx[0];
  motionData[32] = state[0] + xx[12];
  motionData[33] = state[1];
  motionData[34] = xx[11] - xx[13];
  motionData[35] = xx[0];
  motionData[36] = xx[0];
  motionData[37] = xx[0];
  motionData[38] = state[2];
  motionData[39] = state[3];
  motionData[40] = xx[0];
  motionData[41] = xx[0];
  motionData[42] = state[5];
  motionData[43] = xx[0];
  motionData[44] = state[2] - xx[2] * xx[14] * xx[4] + xx[5] * state[5];
  motionData[45] = state[3];
  motionData[46] = xx[2] * xx[14] * xx[3];
  motionData[47] = xx[0];
  motionData[48] = state[7];
  motionData[49] = xx[0];
  motionData[50] = state[2] - xx[2] * xx[15] * xx[10] + xx[6] * state[7];
  motionData[51] = state[3];
  motionData[52] = xx[2] * xx[15] * xx[1];
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeTransforms(
  const void *mech, const RuntimeDerivedValuesBundle *rtdv, const double *state,
  double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[13];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  xx[0] = 0.0;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[4];
  xx[3] = cos(xx[2]);
  xx[4] = sin(xx[2]);
  xx[2] = 2.0;
  xx[5] = 0.41999999993;
  xx[6] = xx[5] * xx[4];
  xx[7] = xx[2] * xx[6] * xx[3];
  xx[8] = 0.02500000000000002;
  xx[9] = xx[2] * xx[6] * xx[4] - xx[5];
  xx[5] = xx[1] * state[6];
  xx[1] = cos(xx[5]);
  xx[6] = sin(xx[5]);
  xx[5] = 0.1909999999710606;
  xx[10] = xx[5] * xx[6];
  xx[11] = xx[2] * xx[10] * xx[1];
  xx[12] = xx[2] * xx[10] * xx[6] - xx[5];
  xx[2] = 0.04999999999999999;
  motionData[0] = - 1.0;
  motionData[1] = xx[0];
  motionData[2] = xx[0];
  motionData[3] = xx[0];
  motionData[4] = state[0];
  motionData[5] = state[1];
  motionData[6] = 0.02499999999999997;
  motionData[7] = - xx[3];
  motionData[8] = xx[0];
  motionData[9] = - xx[4];
  motionData[10] = xx[0];
  motionData[11] = xx[7];
  motionData[12] = xx[0];
  motionData[13] = xx[8] - xx[9];
  motionData[14] = - xx[1];
  motionData[15] = xx[0];
  motionData[16] = - xx[6];
  motionData[17] = xx[0];
  motionData[18] = xx[11];
  motionData[19] = xx[0];
  motionData[20] = xx[8] - xx[12];
  motionData[21] = xx[3];
  motionData[22] = xx[0];
  motionData[23] = xx[4];
  motionData[24] = xx[0];
  motionData[25] = state[0] + xx[7];
  motionData[26] = state[1];
  motionData[27] = xx[2] - xx[9];
  motionData[28] = xx[1];
  motionData[29] = xx[0];
  motionData[30] = xx[6];
  motionData[31] = xx[0];
  motionData[32] = state[0] + xx[11];
  motionData[33] = state[1];
  motionData[34] = xx[2] - xx[12];
}

size_t
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAssemblyPosError
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, size_t
   constraintIdx, const int *modeVector, const double *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) modeVector;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAssemblyJacobian
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, size_t
   constraintIdx, boolean_T forVelocitySatisfaction, const double *state, const
   int *modeVector, const double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) modeVector;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeFullAssemblyJacobian
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, const double *state,
   const int *modeVector, const double *motionData, double *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
  (void) J;
  return 0;
}

boolean_T
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_isInKinematicSingularity
  (const void *mech, const RuntimeDerivedValuesBundle *rtdv, size_t
   constraintIdx, const int *modeVector, const double *motionData)
{
  (void) mech;
  (void) rtdv;
  (void) modeVector;
  (void) motionData;
  switch (constraintIdx)
  {
  }

  return 0;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_convertStateVector
  (const void *asmMech, const RuntimeDerivedValuesBundle *rtdv, const void
   *simMech, const double *asmState, const int *asmModeVector, const int
   *simModeVector, double *simState)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) asmMech;
  (void) rtdvd;
  (void) rtdvi;
  (void) simMech;
  (void) asmModeVector;
  (void) simModeVector;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  simState[4] = asmState[4];
  simState[5] = asmState[5];
  simState[6] = asmState[6];
  simState[7] = asmState[7];
}
