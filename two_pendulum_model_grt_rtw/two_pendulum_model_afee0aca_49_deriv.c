/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'two_pendulum_model/Sistema No lineal Multibody Mask/Solver Configuration'.
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
#include "two_pendulum_model_afee0aca_49_geometries.h"

PmfMessageId two_pendulum_model_afee0aca_49_compDerivs(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *deriv, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[1];
  double xx[64];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 10.0;
  xx[1] = 3.333417986084442e-10;
  xx[2] = 2.0;
  xx[3] = 0.5;
  xx[4] = xx[3] * state[6];
  xx[5] = cos(xx[4]);
  xx[6] = xx[5] * xx[5];
  xx[7] = 1.0;
  xx[8] = xx[2] * xx[6] - xx[7];
  xx[9] = xx[1] * xx[8];
  xx[10] = sin(xx[4]);
  xx[4] = xx[2] * xx[5] * xx[10];
  xx[11] = 2.000000001;
  xx[12] = xx[11] * xx[4];
  xx[13] = xx[9] * xx[8] + xx[4] * xx[12];
  xx[14] = 3.333338050026668e-10;
  xx[15] = xx[3] * state[4];
  xx[3] = cos(xx[15]);
  xx[16] = xx[3] * xx[3];
  xx[17] = xx[2] * xx[16] - xx[7];
  xx[18] = xx[14] * xx[17];
  xx[19] = sin(xx[15]);
  xx[15] = xx[2] * xx[3] * xx[19];
  xx[20] = 3.000000001;
  xx[21] = xx[20] * xx[15];
  xx[22] = xx[18] * xx[17] + xx[15] * xx[21];
  xx[23] = xx[0] + xx[13] + xx[22];
  xx[24] = 0.0;
  xx[25] = xx[2] * (xx[6] + xx[10] * xx[10]) - xx[7];
  xx[6] = xx[11] * xx[25] * xx[25];
  xx[26] = xx[2] * (xx[16] + xx[19] * xx[19]) - xx[7];
  xx[7] = xx[20] * xx[26] * xx[26];
  xx[16] = xx[0] + xx[6] + xx[7];
  xx[27] = xx[23];
  xx[28] = xx[24];
  xx[29] = xx[24];
  xx[30] = xx[16];
  ii[0] = factorSymmetricPosDef(xx + 27, 2, xx + 31);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "physmod:sm:core:compiler:mechanism:mechanism:degenerateMassFoll",
      "'two_pendulum_model/Sistema No lineal Multibody Mask/Rectangular Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[0] = 0.20000000005;
  xx[31] = 0.099999999975;
  xx[32] = (2.500000206850927e-11 * input[2] + xx[31] * input[2]) /
    0.02000000000333342;
  xx[33] = xx[0] * xx[32] - input[2];
  xx[34] = 1.2000000002;
  xx[35] = 0.3999999999333334;
  xx[36] = (6.666661667154017e-11 * input[1] + xx[35] * input[1]) /
    0.4800000000533335;
  xx[37] = xx[34] * xx[36] - input[1];
  xx[38] = input[0] - (xx[33] - xx[2] * (xx[0] * state[7] * state[7] * xx[10] *
    xx[5] + xx[33] * xx[10] * xx[10]) + xx[37] - xx[2] * (xx[34] * state[5] *
    state[5] * xx[19] * xx[3] + xx[37] * xx[19] * xx[19]));
  xx[39] = xx[24];
  solveSymmetricPosDef(xx + 27, xx + 38, 2, 1, xx + 33, xx + 40);
  xx[0] = 9.800000000000001;
  xx[37] = xx[31] * xx[10];
  xx[31] = 0.124999999975 - xx[2] * xx[37] * xx[10];
  xx[38] = xx[35] * xx[19];
  xx[35] = 0.4249999999333334 - xx[2] * xx[38] * xx[19];
  xx[39] = xx[2] * xx[37] * xx[5];
  xx[37] = xx[2] * xx[38] * xx[3];
  xx[40] = xx[24];
  xx[41] = - (xx[6] * xx[31] + xx[7] * xx[35]);
  xx[42] = xx[13] * xx[31] - xx[39] * (xx[4] * xx[11] * xx[8] - xx[1] * xx[4] *
    xx[8]) - 3.333416942745674e-11 * xx[8] * xx[25] + xx[22] * xx[35] - xx[37] *
    (xx[15] * xx[20] * xx[17] - xx[14] * xx[15] * xx[17]) -
    1.333334139282454e-10 * xx[17] * xx[26];
  xx[43] = xx[24];
  xx[44] = xx[24];
  xx[45] = xx[39] * xx[6] + xx[37] * xx[7];
  xx[46] = xx[23];
  xx[47] = xx[24];
  xx[48] = xx[24];
  xx[49] = xx[16];
  xx[50] = xx[12] * xx[8] - xx[9] * xx[4] + xx[21] * xx[17] - xx[18] * xx[15];
  xx[51] = xx[24];
  solveSymmetricPosDef(xx + 27, xx + 40, 2, 6, xx + 52, xx + 6);
  xx[1] = xx[33] - xx[0] * xx[62];
  deriv[0] = state[2];
  deriv[1] = state[3];
  deriv[2] = xx[1];
  deriv[3] = xx[34] - xx[0] * xx[63];
  deriv[4] = state[5];
  deriv[5] = xx[36] - 2.500000000138888 * (xx[1] - xx[2] * (xx[0] * xx[19] * xx
    [3] + xx[1] * xx[19] * xx[19]));
  deriv[6] = state[7];
  deriv[7] = xx[32] - 10.00000000083329 * (xx[1] - xx[2] * (xx[0] * xx[10] * xx
    [5] + xx[1] * xx[10] * xx[10]));
  errorResult[0] = xx[24];
  return NULL;
}

PmfMessageId two_pendulum_model_afee0aca_49_numJacPerturbLoBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[2];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 1.0e-9;
  xx[1] = 1.0e-8;
  bounds[0] = xx[0];
  bounds[1] = xx[0];
  bounds[2] = xx[0];
  bounds[3] = xx[0];
  bounds[4] = xx[1];
  bounds[5] = xx[1];
  bounds[6] = xx[1];
  bounds[7] = xx[1];
  errorResult[0] = 0.0;
  return NULL;
}

PmfMessageId two_pendulum_model_afee0aca_49_numJacPerturbHiBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[2];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = +pmf_get_inf();
  xx[1] = 1.0;
  bounds[0] = xx[0];
  bounds[1] = xx[0];
  bounds[2] = xx[0];
  bounds[3] = xx[0];
  bounds[4] = xx[1];
  bounds[5] = xx[0];
  bounds[6] = xx[1];
  bounds[7] = xx[0];
  errorResult[0] = 0.0;
  return NULL;
}
