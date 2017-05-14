/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Push_Button_mode'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Sun May 14 15:54:56 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Push_Button_mode.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  Push_Button_mode_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.1;
  float systemClock = 168;

#ifndef USE_RTX

  __disable_irq();

#endif

  ;
  stm32f4xx_init_board();
  SystemCoreClockUpdate();
  bootloaderInit();
  rtmSetErrorStatus(Push_Button_mode_M, 0);
  Push_Button_mode_initialize();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(Push_Button_mode_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    runModel =
      rtmGetErrorStatus(Push_Button_mode_M) == (NULL);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Push_Button_mode_terminate();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
