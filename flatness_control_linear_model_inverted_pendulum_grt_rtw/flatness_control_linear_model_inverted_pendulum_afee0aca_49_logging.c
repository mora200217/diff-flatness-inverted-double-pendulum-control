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
#include "flatness_control_linear_model_inverted_pendulum_afee0aca_49_geometries.h"

PmfMessageId
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_recordLog(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, double *logVector, double *errorResult,
  NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[1];
  double xx[65];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) inputDot;
  (void) inputDdot;
  (void) neDiagMgr;
  xx[0] = 57.29577951308232;
  xx[1] = 5.5;
  xx[2] = 3.33336469537926e-10;
  xx[3] = 2.0;
  xx[4] = 0.5;
  xx[5] = xx[4] * state[6];
  xx[6] = cos(xx[5]);
  xx[7] = xx[6] * xx[6];
  xx[8] = 1.0;
  xx[9] = xx[3] * xx[7] - xx[8];
  xx[10] = xx[2] * xx[9];
  xx[11] = sin(xx[5]);
  xx[5] = xx[3] * xx[6] * xx[11];
  xx[12] = 3.300000001;
  xx[13] = xx[12] * xx[5];
  xx[14] = xx[10] * xx[9] + xx[5] * xx[13];
  xx[15] = 3.333338050026668e-10;
  xx[16] = xx[4] * state[4];
  xx[4] = cos(xx[16]);
  xx[17] = xx[4] * xx[4];
  xx[18] = xx[3] * xx[17] - xx[8];
  xx[19] = xx[15] * xx[18];
  xx[20] = sin(xx[16]);
  xx[16] = xx[3] * xx[4] * xx[20];
  xx[21] = 3.000000001;
  xx[22] = xx[21] * xx[16];
  xx[23] = xx[19] * xx[18] + xx[16] * xx[22];
  xx[24] = xx[1] + xx[14] + xx[23];
  xx[25] = 0.0;
  xx[26] = xx[3] * (xx[7] + xx[11] * xx[11]) - xx[8];
  xx[7] = xx[12] * xx[26] * xx[26];
  xx[27] = xx[3] * (xx[17] + xx[20] * xx[20]) - xx[8];
  xx[8] = xx[21] * xx[27] * xx[27];
  xx[17] = xx[1] + xx[7] + xx[8];
  xx[28] = xx[24];
  xx[29] = xx[25];
  xx[30] = xx[25];
  xx[31] = xx[17];
  ii[0] = factorSymmetricPosDef(xx + 28, 2, xx + 32);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "physmod:sm:core:compiler:mechanism:mechanism:degenerateMassFoll",
      "'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Rectangular Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[1] = 0.6303000000954999;
  xx[32] = 0.1909999999710606;
  xx[33] = (2.893940642678672e-11 * input[2] + xx[32] * input[2]) /
    0.1203873000121604;
  xx[34] = xx[1] * xx[33] - input[2];
  xx[35] = 1.26000000021;
  xx[36] = 0.41999999993;
  xx[37] = (7.000000579182597e-11 * input[1] + xx[36] * input[1]) /
    0.5292000000588001;
  xx[38] = xx[35] * xx[37] - input[1];
  xx[39] = input[0] - (xx[34] - xx[3] * (xx[1] * state[7] * state[7] * xx[11] *
    xx[6] + xx[34] * xx[11] * xx[11]) + xx[38] - xx[3] * (xx[35] * state[5] *
    state[5] * xx[20] * xx[4] + xx[38] * xx[20] * xx[20]));
  xx[40] = xx[25];
  solveSymmetricPosDef(xx + 28, xx + 39, 2, 1, xx + 34, xx + 41);
  xx[1] = 9.800000000000001;
  xx[38] = xx[32] * xx[11];
  xx[32] = 0.2159999999710606 - xx[3] * xx[38] * xx[11];
  xx[39] = xx[36] * xx[20];
  xx[36] = 0.44499999993 - xx[3] * xx[39] * xx[20];
  xx[40] = xx[3] * xx[38] * xx[6];
  xx[38] = xx[3] * xx[39] * xx[4];
  xx[41] = xx[25];
  xx[42] = - (xx[7] * xx[32] + xx[8] * xx[36]);
  xx[43] = xx[14] * xx[32] - xx[40] * (xx[5] * xx[12] * xx[9] - xx[2] * xx[5] *
    xx[9]) - 6.366722193399829e-11 * xx[9] * xx[26] + xx[23] * xx[36] - xx[38] *
    (xx[16] * xx[21] * xx[18] - xx[15] * xx[16] * xx[18]) -
    1.400001148421546e-10 * xx[18] * xx[27];
  xx[44] = xx[25];
  xx[45] = xx[25];
  xx[46] = xx[40] * xx[7] + xx[38] * xx[8];
  xx[47] = xx[24];
  xx[48] = xx[25];
  xx[49] = xx[25];
  xx[50] = xx[17];
  xx[51] = xx[13] * xx[9] - xx[10] * xx[5] + xx[22] * xx[18] - xx[19] * xx[16];
  xx[52] = xx[25];
  solveSymmetricPosDef(xx + 28, xx + 41, 2, 6, xx + 53, xx + 7);
  xx[2] = xx[34] - xx[1] * xx[63];
  logVector[0] = state[0];
  logVector[1] = state[1];
  logVector[2] = state[2];
  logVector[3] = state[3];
  logVector[4] = xx[0] * state[4];
  logVector[5] = xx[0] * state[5];
  logVector[6] = xx[0] * state[6];
  logVector[7] = xx[0] * state[7];
  logVector[8] = xx[2];
  logVector[9] = xx[35] - xx[1] * xx[64];
  logVector[10] = xx[0] * (xx[37] - 2.380952381084656 * (xx[2] - xx[3] * (xx[1] *
    xx[20] * xx[4] + xx[2] * xx[20] * xx[20])));
  logVector[11] = xx[0] * (xx[33] - 5.235602094505258 * (xx[2] - xx[3] * (xx[1] *
    xx[11] * xx[6] + xx[2] * xx[11] * xx[11])));
  errorResult[0] = xx[25];
  return NULL;
}
