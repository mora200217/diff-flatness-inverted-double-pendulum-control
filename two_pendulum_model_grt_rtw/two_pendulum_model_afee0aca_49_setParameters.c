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

void two_pendulum_model_afee0aca_49_computeRuntimeParameters(real_T *in, real_T *
  out)
{
  (void) in;
  (void) out;
}

void two_pendulum_model_afee0aca_49_computeAsmRuntimeDerivedValuesDoubles(const
  double *rtp, double *rtdvd)
{
  (void) rtp;
  (void) rtdvd;
}

void two_pendulum_model_afee0aca_49_computeAsmRuntimeDerivedValuesInts(const
  double *rtp, int *rtdvi)
{
  (void) rtp;
  (void) rtdvi;
}

void two_pendulum_model_afee0aca_49_computeAsmRuntimeDerivedValues(const double *
  rtp, RuntimeDerivedValuesBundle *rtdv)
{
  two_pendulum_model_afee0aca_49_computeAsmRuntimeDerivedValuesDoubles(rtp,
    rtdv->mDoubles.mValues);
  two_pendulum_model_afee0aca_49_computeAsmRuntimeDerivedValuesInts(rtp,
    rtdv->mInts.mValues);
}

void two_pendulum_model_afee0aca_49_computeSimRuntimeDerivedValuesDoubles(const
  double *rtp, double *rtdvd)
{
  (void) rtp;
  (void) rtdvd;
}

void two_pendulum_model_afee0aca_49_computeSimRuntimeDerivedValuesInts(const
  double *rtp, int *rtdvi)
{
  (void) rtp;
  (void) rtdvi;
}

void two_pendulum_model_afee0aca_49_computeSimRuntimeDerivedValues(const double *
  rtp, RuntimeDerivedValuesBundle *rtdv)
{
  two_pendulum_model_afee0aca_49_computeSimRuntimeDerivedValuesDoubles(rtp,
    rtdv->mDoubles.mValues);
  two_pendulum_model_afee0aca_49_computeSimRuntimeDerivedValuesInts(rtp,
    rtdv->mInts.mValues);
}
