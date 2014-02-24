/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MC13213
**     Component   : MC13214
**     Version     : Component 01.065, Driver 01.40, CPU db: 2.87.133
**     Datasheet   : MC1321xRM Rev. 1.1 10/2006
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-02-24, 11:47, # CodeGen: 0
**     Abstract    :
**         This component "MC13214" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.40
** @brief
**         This component "MC13214" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR register */
volatile byte CCR_lock;                /* Nesting level of critical regions */


/*
** ===================================================================
**     Method      :  Cpu_VicgInterrupt (component MC13214)
**
**     Description :
**         This ISR services the 'Loss of lock' or the 'Loss of clock' 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_VicgInterrupt)
{
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm("LDA _ICGS1");
  /*lint -restore Enable MISRA rule (1.1) checking. */
  ICGS1_ICGIF = 1U;                    /* Clear ICG interrupt flag */
}

/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC13214)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC13214)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC13214)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC13214)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC13214 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT: COPE=0,COPT=1,STOPE=0,??=1,??=0,??=0,BKGDPE=1,??=1 */
  setReg8(SOPT, 0x53U);                 
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,??=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LVWF=0,LVWACK=0,LVDV=0,LVWV=0,PPDF=0,PPDACK=0,PDC=0,PPDC=0 */
  setReg8(SPMSC2, 0x00U);               
  /*  System clock initialization */
  /* ICGC1: HGO=0,RANGE=1,REFS=0,CLKS1=0,CLKS0=0,OSCSTEN=1,LOCD=0,??=0 */
  setReg8(ICGC1, 0x44U);                
  /* ICGFLT: ??=0,??=0,??=0,??=0,FLT11=0,FLT10=0,FLT9=0,FLT8=0,FLT7=1,FLT6=1,FLT5=0,FLT4=0,FLT3=0,FLT2=0,FLT1=0,FLT0=0 */
  setReg16(ICGFLT, 0xC0U);             /* Initialization of the filter value */ 
  /* ICGC2: LOLRE=0,MFD2=0,MFD1=0,MFD0=0,LOCRE=0,RFD2=0,RFD1=0,RFD0=0 */
  setReg8(ICGC2, 0x00U);                
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(uint8_t*)0xFFBEU != 0xFFU) {   /* Test if the device trim value is stored on the specified address */
    ICGTRM = *(uint8_t*)0xFFBEU;       /* Initialize ICGTRM register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */

  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm   jmp _Startup ;               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC13214)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* Common initialization of the CPU registers */
  /* PTASE: PTASE7=0,PTASE6=0,PTASE5=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  setReg8(PTASE, 0x00U);                
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE2=0,PTDSE0=0 */
  clrReg8Bits(PTDSE, 0xF5U);            
  /* PTESE: PTESE7=0,PTESE6=0,PTESE1=0,PTESE0=0 */
  clrReg8Bits(PTESE, 0xC3U);            
  /* PTGSE: PTGSE2=0,PTGSE1=0,PTGSE0=0 */
  clrReg8Bits(PTGSE, 0x07U);            
  /* ### Shared modules init code ... */
  CCR_lock = (byte)0;
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPOPEN=1,FPDIS=1,FPS2=1,FPS1=1,FPS0=1,??=1,??=1,??=1 */
static const uint8_t NVPROT_INIT @0x0000FFBDU = 0xFFU;
/* NVOPT: KEYEN=0,FNORED=1,??=1,??=1,??=1,??=1,SEC01=1,SEC00=0 */
static const uint8_t NVOPT_INIT @0x0000FFBFU = 0x7EU;
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
