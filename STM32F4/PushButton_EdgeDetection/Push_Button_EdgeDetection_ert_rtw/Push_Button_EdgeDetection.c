/*
 * File: Push_Button_EdgeDetection.c
 *
 * Code generated for Simulink model 'Push_Button_EdgeDetection'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Sun May 14 15:38:40 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Push_Button_EdgeDetection.h"
#include "Push_Button_EdgeDetection_private.h"

/* Exported block states */
uint8_T Button_Press_Count;            /* '<Root>/Data Store Memory' */

/* Block states (auto storage) */
DW_Push_Button_EdgeDetection_T Push_Button_EdgeDetection_DW;

/* Real-time model */
RT_MODEL_Push_Button_EdgeDete_T Push_Button_EdgeDetection_M_;
RT_MODEL_Push_Button_EdgeDete_T *const Push_Button_EdgeDetection_M =
  &Push_Button_EdgeDetection_M_;

/* Model step function */
void Push_Button_EdgeDetection_step(void)
{
  uint8_T rtb_ExtractDesiredBits;
  boolean_T rtb_DataTypeConversion3;
  uint8_T rtb_ExtractDesiredBits_b;
  boolean_T rtb_UserPushButtionGPIOAPin0PPN;

  /* DataStoreRead: '<Root>/Data Store Read' */
  rtb_ExtractDesiredBits = Button_Press_Count;

  /* S-Function (stm32f4_di_read): '<Root>/User Push Buttion  (GPIOA, Pin 0, PP-None, 50MHz)' */
  rtb_UserPushButtionGPIOAPin0PPN = MW_GPIO_ReadInputDataBit(0U, 0U);

  /* Logic: '<S2>/Logical Operator1' incorporates:
   *  Delay: '<S2>/Delay'
   *  Logic: '<S2>/Logical Operator'
   */
  rtb_DataTypeConversion3 = (rtb_UserPushButtionGPIOAPin0PPN &&
    (!Push_Button_EdgeDetection_DW.Delay_DSTATE));

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  Sum: '<Root>/Add'
   */
  Button_Press_Count = (uint8_T)((uint32_T)Button_Press_Count +
    rtb_DataTypeConversion3);

  /* DataTypeConversion: '<S3>/Extract Desired Bits' */
  rtb_ExtractDesiredBits_b = (uint8_T)(rtb_ExtractDesiredBits & 15);

  /* DataTypeConversion: '<S4>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)(rtb_ExtractDesiredBits_b & 3);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S9>/Extract Desired Bits'
   */
  rtb_DataTypeConversion3 = ((rtb_ExtractDesiredBits & 1) != 0);

  /* S-Function (stm32f4_do_write): '<Root>/LED1' */
  MW_GPIO_WriteBit(3U, 12U, rtb_DataTypeConversion3);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S10>/Extract Desired Bits'
   */
  rtb_DataTypeConversion3 = ((int32_T)((uint32_T)rtb_ExtractDesiredBits >> 1) !=
    0);

  /* S-Function (stm32f4_do_write): '<Root>/LED2' */
  MW_GPIO_WriteBit(3U, 13U, rtb_DataTypeConversion3);

  /* DataTypeConversion: '<S6>/Extract Desired Bits' */
  rtb_ExtractDesiredBits = (uint8_T)((uint32_T)rtb_ExtractDesiredBits_b >> 2);

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S14>/Extract Desired Bits'
   */
  rtb_DataTypeConversion3 = ((rtb_ExtractDesiredBits & 1) != 0);

  /* S-Function (stm32f4_do_write): '<Root>/LED3' */
  MW_GPIO_WriteBit(3U, 14U, rtb_DataTypeConversion3);

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S11>/Extract Desired Bits'
   */
  rtb_DataTypeConversion3 = ((int32_T)((uint32_T)rtb_ExtractDesiredBits >> 1) !=
    0);

  /* S-Function (stm32f4_do_write): '<Root>/LED4' */
  MW_GPIO_WriteBit(3U, 15U, rtb_DataTypeConversion3);

  /* Update for Delay: '<S2>/Delay' */
  Push_Button_EdgeDetection_DW.Delay_DSTATE = rtb_UserPushButtionGPIOAPin0PPN;
}

/* Model initialize function */
void Push_Button_EdgeDetection_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Push_Button_EdgeDetection_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Push_Button_EdgeDetection_DW, 0,
                sizeof(DW_Push_Button_EdgeDetection_T));

  /* exported global states */
  Button_Press_Count = 0U;

  /* Start for S-Function (stm32f4_di_read): '<Root>/User Push Buttion  (GPIOA, Pin 0, PP-None, 50MHz)' */
  MW_GpioInit(0U, 1U, 0U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/LED1' */
  MW_GpioInit(3U, 4096U, 1U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/LED2' */
  MW_GpioInit(3U, 8192U, 1U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/LED3' */
  MW_GpioInit(3U, 16384U, 1U, 0U, 0U, 0U);

  /* Start for S-Function (stm32f4_do_write): '<Root>/LED4' */
  MW_GpioInit(3U, 32768U, 1U, 0U, 0U, 0U);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Button_Press_Count = Push_Button_EdgeDetection_P.DataStoreMemory_InitialValue;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  Push_Button_EdgeDetection_DW.Delay_DSTATE =
    Push_Button_EdgeDetection_P.Delay_InitialCondition;
}

/* Model terminate function */
void Push_Button_EdgeDetection_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
