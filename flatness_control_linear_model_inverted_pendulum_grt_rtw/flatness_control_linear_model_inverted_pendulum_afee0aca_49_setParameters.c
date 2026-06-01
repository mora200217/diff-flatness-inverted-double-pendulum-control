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

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeRuntimeParameters
  (real_T *in, real_T *out)
{
  (void) in;
  (void) out;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAsmRuntimeDerivedValuesDoubles
  (const double *rtp, double *rtdvd)
{
  (void) rtp;
  (void) rtdvd;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAsmRuntimeDerivedValuesInts
  (const double *rtp, int *rtdvi)
{
  (void) rtp;
  (void) rtdvi;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAsmRuntimeDerivedValues
  (const double *rtp, RuntimeDerivedValuesBundle *rtdv)
{
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAsmRuntimeDerivedValuesDoubles
    (rtp, rtdv->mDoubles.mValues);
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeAsmRuntimeDerivedValuesInts
    (rtp, rtdv->mInts.mValues);
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeSimRuntimeDerivedValuesDoubles
  (const double *rtp, double *rtdvd)
{
  (void) rtp;
  (void) rtdvd;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeSimRuntimeDerivedValuesInts
  (const double *rtp, int *rtdvi)
{
  (void) rtp;
  (void) rtdvi;
}

void
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeSimRuntimeDerivedValues
  (const double *rtp, RuntimeDerivedValuesBundle *rtdv)
{
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeSimRuntimeDerivedValuesDoubles
    (rtp, rtdv->mDoubles.mValues);
  flatness_control_linear_model_inverted_pendulum_afee0aca_49_computeSimRuntimeDerivedValuesInts
    (rtp, rtdv->mInts.mValues);
}
