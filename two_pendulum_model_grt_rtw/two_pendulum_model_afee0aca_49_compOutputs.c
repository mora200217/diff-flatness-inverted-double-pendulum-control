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

PmfMessageId two_pendulum_model_afee0aca_49_compOutputs(const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  const double *input, const double *inputDot, const double *inputDdot, const
  double *discreteState, double *output, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  output[0] = state[0];
  output[1] = state[2];
  output[2] = state[4];
  output[3] = state[5];
  output[4] = state[6];
  output[5] = state[7];
  return NULL;
}
