/*
 * File: Push_Button_mode.c
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
#include "Push_Button_mode_private.h"

/* Exported block states */
uint8_T Button_Press_Count;            /* '<Root>/Data Store Memory' */

/* Block states (auto storage) */
DW_Push_Button_mode_T Push_Button_mode_DW;

/* Real-time model */
RT_MODEL_Push_Button_mode_T Push_Button_mode_M_;
RT_MODEL_Push_Button_mode_T *const Push_Button_mode_M = &Push_Button_mode_M_;

/* Model step function */
void Push_Button_mode_step(void)
{
  boolean_T rtb_DataTypeConversion1_0;
  uint8_T rtb_Add;
  int32_T rtb_led1;
  int32_T rtb_led2;

  /* S-Function (stm32f4_di_read): '<Root>/User Push Buttion  (GPIOA, Pin 0, PP-None, 50MHz)' */
  rtb_DataTypeConversion1_0 = MW_GPIO_ReadInputDataBit(0U, 0U);

  /* Sum: '<Root>/Add' incorporates:
   *  Delay: '<Root>/Delay'
   *  S-Function (stm32f4_di_read): '<Root>/User Push Buttion  (GPIOA, Pin 0, PP-None, 50MHz)'
   */
  rtb_Add = (uint8_T)((uint32_T)rtb_DataTypeConversion1_0 +
                      Push_Button_mode_DW.Delay_DSTATE);

  /* DataStoreWrite: '<Root>/Data Store Write' */
  Button_Press_Count = rtb_Add;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:3' */
  /* '<S1>:1:5' */
  switch ((uint8_T)((uint32_T)Button_Press_Count - ((int32_T)((uint32_T)
             Button_Press_Count >> 2) << 2))) {
   case 0U:
    /* '<S1>:1:7' */
    rtb_led1 = 0;

    /* '<S1>:1:8' */
    rtb_led2 = 0;
    break;

   case 1U:
    /* '<S1>:1:10' */
    rtb_led1 = 0;

    /* '<S1>:1:11' */
    rtb_led2 = 1;
    break;

   case 2U:
    /* '<S1>:1:13' */
    rtb_led1 = 1;

    /* '<S1>:1:14' */
    rtb_led2 = 0;
    break;

   case 3U:
    /* '<S1>:1:16' */
    rtb_led1 = 1;

    /* '<S1>:1:17' */
    rtb_led2 = 1;
    break;

   default:
    /* '<S1>:1:19' */
    rtb_led1 = 0;

    /* '<S1>:1:20' */
    rtb_led2 = 0;
    break;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* S-Function (stm32f4_do_write): '<Root>/GPIO Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  MW_GPIO_WriteBit(3U, 12U, rtb_led1 != 0);

  /* S-Function (stm32f4_do_write): '<Root>/GPIO Write1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  MW_GPIO_WriteBit(3U, 13U, rtb_led2 != 0);

  /* Update for Delay: '<Root>/Delay' */
  Push_Button_mode_DW.Delay_DSTATE = rtb_Add;
}

/* Model initialize function */
void Push_Button_mode_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Push_Button_mode_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Push_Button_mode_DW, 0,
                sizeof(DW_Push_Button_mode_T));

  /* exported global states */
  Button_Press_Count = 0U;

  /* Start for S-Function (stm32f4_di_read): '<Root>/User Push Buttion  (GPIOA, Pin 0, PP-None, 50MHz)' */
  MW_GpioInit(0U, 1U, 0U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/GPIO Write' */
  MW_GpioInit(3U, 4096U, 1U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/GPIO Write1' */
  MW_GpioInit(3U, 8192U, 1U, 0U, 0U, 0U);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Button_Press_Count = Push_Button_mode_P.DataStoreMemory_InitialValue;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Push_Button_mode_DW.Delay_DSTATE = Push_Button_mode_P.Delay_InitialCondition;
}

/* Model terminate function */
void Push_Button_mode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
