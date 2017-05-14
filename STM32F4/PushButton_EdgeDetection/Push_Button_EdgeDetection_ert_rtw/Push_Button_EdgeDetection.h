/*
 * File: Push_Button_EdgeDetection.h
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

#ifndef RTW_HEADER_Push_Button_EdgeDetection_h_
#define RTW_HEADER_Push_Button_EdgeDetection_h_
#include <stddef.h>
#include <string.h>
#ifndef Push_Button_EdgeDetection_COMMON_INCLUDES_
# define Push_Button_EdgeDetection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "stm32f4discovery_wrapper.h"
#endif                                 /* Push_Button_EdgeDetection_COMMON_INCLUDES_ */

#include "Push_Button_EdgeDetection_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T Delay_DSTATE;              /* '<S2>/Delay' */
} DW_Push_Button_EdgeDetection_T;

/* Parameters (auto storage) */
struct P_Push_Button_EdgeDetection_T_ {
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S2>/Delay'
                                        */
  uint8_T DataStoreMemory_InitialValue;/* Computed Parameter: DataStoreMemory_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  boolean_T Delay_InitialCondition;    /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S2>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Push_Button_EdgeDetec_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Push_Button_EdgeDetection_T Push_Button_EdgeDetection_P;

/* Block states (auto storage) */
extern DW_Push_Button_EdgeDetection_T Push_Button_EdgeDetection_DW;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint8_T Button_Press_Count;     /* '<Root>/Data Store Memory' */

/* Model entry point functions */
extern void Push_Button_EdgeDetection_initialize(void);
extern void Push_Button_EdgeDetection_step(void);
extern void Push_Button_EdgeDetection_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Push_Button_EdgeDete_T *const Push_Button_EdgeDetection_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Push_Button_EdgeDetection'
 * '<S1>'   : 'Push_Button_EdgeDetection/BitExtract'
 * '<S2>'   : 'Push_Button_EdgeDetection/Edge Detector'
 * '<S3>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits'
 * '<S4>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits1'
 * '<S5>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits10'
 * '<S6>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits11'
 * '<S7>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits12'
 * '<S8>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits13'
 * '<S9>'   : 'Push_Button_EdgeDetection/BitExtract/Extract Bits2'
 * '<S10>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits3'
 * '<S11>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits4'
 * '<S12>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits5'
 * '<S13>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits6'
 * '<S14>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits7'
 * '<S15>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits8'
 * '<S16>'  : 'Push_Button_EdgeDetection/BitExtract/Extract Bits9'
 * '<S17>'  : 'Push_Button_EdgeDetection/Edge Detector/Check Signal Attributes'
 * '<S18>'  : 'Push_Button_EdgeDetection/Edge Detector/Check Signal Attributes1'
 */
#endif                                 /* RTW_HEADER_Push_Button_EdgeDetection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
