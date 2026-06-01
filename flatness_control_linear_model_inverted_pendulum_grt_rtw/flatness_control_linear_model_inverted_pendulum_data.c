/*
 * flatness_control_linear_model_inverted_pendulum_data.c
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

#include "flatness_control_linear_model_inverted_pendulum.h"

/* Block parameters (default storage) */
P_flatness_control_linear_mod_T flatness_control_linear_model_P = {
  /* Variable: K_cancel
   * Referenced by: '<S1>/Gain1'
   */
  { 0.0, 0.0, -2568.5546565127729, 0.0, 118.15484689830244, 0.0 },

  /* Variable: K_error
   * Referenced by: '<S1>/Gain'
   */
  { 26250.0, 29125.0, 13425.0, 3290.0, 452.0, 33.0 },

  /* Variable: T
   * Referenced by: '<Root>/Transformacion salida plana'
   */
  { 0.004594023323615159, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.004594023323615159,
    0.0, 0.0, 0.0, 0.0, 0.0035388022457891444, 0.0, 0.082572052401746712, 0.0,
    1.9266812227074235, 0.0, 0.0, 0.0035388022457891444, 0.0,
    0.082572052401746712, 0.0, 1.9266812227074235, -0.00073185399506028208, 0.0,
    -0.037550623830318125, 0.0, -1.9266812227074217, 0.0, 0.0,
    -0.00073185399506028208, 0.0, -0.037550623830318125, 0.0,
    -1.9266812227074217 }
};
