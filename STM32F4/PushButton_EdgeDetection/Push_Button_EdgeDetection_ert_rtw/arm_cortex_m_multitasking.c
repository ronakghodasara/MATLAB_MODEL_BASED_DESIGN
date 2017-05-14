#include "Push_Button_EdgeDetection.h"
#include "mw_force_no_optimization.h"
#include "arm_cortex_m_multitasking.h"
/* Re-entrant function for multi-tasking: arm_cortex_m_call_thread_with_context_switch*/

__attribute__ ((naked)) void arm_cortex_m_call_thread_with_context_switch(void (* isr_routine_ptr)(void)) {
#if (defined(__FPU_PRESENT) && (__FPU_PRESENT == 1)) && (defined(__FPU_USED) && (__FPU_USED == 1))
     __asm volatile ("     TST  LR, #0x10");
     __asm volatile ("     IT EQ");
     __asm volatile ("     VMOVEQ S0, S0");
#endif
     __asm volatile ("     PUSH {R0, R1}");
     __asm volatile ("     SUB SP, SP, #0x20");
     __asm volatile ("     ADR R0,Call_isr_routine_in_thread_mode");
     __asm volatile ("     STR R0,[SP, #24]");
     __asm volatile ("     MOV R0,#0x01000000");
     __asm volatile ("     STR R0,[SP, #28]");
     __asm volatile ("     MVNS R0,#0x6");
     __asm volatile ("     MOV LR, R0");
     __asm volatile ("     BX LR");
     __asm volatile ("Call_isr_routine_in_thread_mode:");
     __asm volatile ("     POP {R0, R1}");
     __asm volatile ("     BLX R0");
     __asm volatile ("     ISB");
     __asm volatile ("     SVC #0");
     __asm volatile ("Unknown_Execution:");
     __asm volatile ("     B Unknown_Execution");
}
/* SVC Interrupt service routine to restore the context: SVC_Handler*/

__attribute__ ((naked)) void SVC_Handler(void) {
#if (defined(__FPU_PRESENT) && (__FPU_PRESENT == 1)) && (defined(__FPU_USED) && (__FPU_USED == 1))
     __asm volatile ("     TST  LR, #0x10");
     __asm volatile ("     IT EQ");
     __asm volatile ("     VMOVEQ S0, S0");
#endif
     __asm volatile ("     TST LR, #0x4");
     __asm volatile ("     ITE EQ");
     __asm volatile ("     MRSEQ R0, MSP");
     __asm volatile ("     MRSNE R0, PSP");
     __asm volatile ("     LDR R1, [R0, #24]");
     __asm volatile ("     LDRB.W R0, [R1, #-2]");
     __asm volatile ("     CBZ R0, svc_service_0");
     __asm volatile ("     B Unknown_SVC_Request");
     __asm volatile ("svc_service_0:");
#if (defined(__FPU_PRESENT) && (__FPU_PRESENT == 1)) && (defined(__FPU_USED) && (__FPU_USED == 1))
     __asm volatile ("     TST LR, #0x10");
     __asm volatile ("     ITE EQ");
     __asm volatile ("     ADDEQ SP, SP, #104");
     __asm volatile ("     ADDNE SP, SP, #32");
#else
     __asm volatile ("     ADD SP, SP, #32");
#endif
     __asm volatile ("     POP {R0, R1}");
     __asm volatile ("     MSR APSR_nzcvq, R0");
     __asm volatile ("     BX R1");
     __asm volatile ("Unknown_SVC_Request:");
     __asm volatile ("     B Unknown_SVC_Request");
}
