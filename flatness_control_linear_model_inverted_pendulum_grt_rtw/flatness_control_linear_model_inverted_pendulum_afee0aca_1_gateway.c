/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "flatness_control_linear_model_inverted_pendulum_afee0aca_49.h"
#include "flatness_control_linear_model_inverted_pendulum_afee0aca_1_gateway.h"

void flatness_control_linear_model_inverted_pendulum_afee0aca_1_gateway(void)
{
  NeModelParameters modelparams = { (enum NeSolverTypeTag)0, 0.001, 0.001, 0.001,
    FALSE, FALSE, (enum NeModifyAbsTolTag)0, 0.0001, 0.0, FALSE, FALSE, FALSE, (
    enum SscLoggingSettingTag)0, 702192511.0, TRUE, FALSE, FALSE };

  NeSolverParameters solverparams = { TRUE, TRUE, FALSE, FALSE, FALSE, FALSE,
    TRUE, FALSE, FALSE, 0.001, 0.001, 1e-09, FALSE, FALSE, 100U, FALSE, 1U, (
    enum NeConsistencySolverTag)2, (enum NeIndexReductionMethodTag)1, FALSE,
    1e-09, (enum NeToleranceSourceTag)1, 0.001, 0.001, 0.001, FALSE, (enum
    NeLocalSolverChoiceTag)0, TRUE, 1U, 0.001, FALSE, 3U, 2U, FALSE, 2U, (enum
    NeLinearAlgebraChoiceTag)0, 0U, (enum NeEquationFormulationChoiceTag)0,
    1024U, TRUE, 0.001, (enum NePartitionStorageMethodTag)0, 1024U, (enum
    NePartitionMethodTag)0, FALSE, (enum NeMultibodyLocalSolverChoiceTag)0,
    0.001 };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int* rtpDaes = NULL;
  int rtwLogDaes[1] = { 0 };

  int* solverHitDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0U, 0U }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  flatness_control_linear_model_inverted_pendulum_afee0aca_49_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group(
    "flatness_control_linear_model_inverted_pendulum/Sistema No lineal Multibody Mask/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    0,
    rtpDaes,
    1,
    rtwLogDaes,
    0,
    solverHitDaes);
}
