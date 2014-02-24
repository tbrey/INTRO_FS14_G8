/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_LDD.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.025, Driver 01.04, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-02-24, 11:41, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PE_LDD.c                                                  
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup PE_LDD_module PE_LDD module documentation
**  @{
*/         

/* MODULE PE_LDD. */

/* {Default RTOS Adapter} No RTOS includes */
/* {Default RTOS Adapter} No RTOS driver includes */

#include "PE_LDD.h"
#include "Cpu.h"

/*lint -esym(765,PE_PeripheralUsed,LDD_SetClockConfiguration,PE_CpuClockConfigurations,PE_FillMemory) Disable MISRA rule (8.10) checking for symbols (PE_PeripheralUsed,LDD_SetClockConfiguration,PE_CpuClockConfigurations,PE_FillMemory). */

/*
** ===========================================================================
** The array of clock frequencies in configured clock configurations.
** ===========================================================================
*/
/*! The array of clock configurations (frequencies) configured in configured clock configurations of the CPU component. */
const TCpuClockConfiguration PE_CpuClockConfigurations[CPU_CLOCK_CONFIG_NUMBER] = {
  /* Clock configuration 0 */
  {
    CPU_CORE_CLK_HZ_CONFIG_0,          /*!< Core clock frequency in clock configuration 0 */
    CPU_BUS_CLK_HZ_CONFIG_0,           /*!< Bus clock frequency in clock configuration 0 */
    CPU_FLEXBUS_CLK_HZ_CONFIG_0,       /*!< Flexbus clock frequency in clock configuration 0 */
    CPU_FLASH_CLK_HZ_CONFIG_0,         /*!< FLASH clock frequency in clock configuration 0 */
    CPU_USB_CLK_HZ_CONFIG_0,           /*!< USB clock frequency in clock configuration 0 */
    CPU_PLL_FLL_CLK_HZ_CONFIG_0,       /*!< PLL/FLL clock frequency in clock configuration 0 */
    CPU_MCGIR_CLK_HZ_CONFIG_0,         /*!< MCG internal reference clock frequency in clock configuration 0 */
    CPU_OSCER_CLK_HZ_CONFIG_0,         /*!< System OSC external reference clock frequency in clock configuration 0 */
    CPU_ERCLK32K_CLK_HZ_CONFIG_0,      /*!< External reference clock 32k frequency in clock configuration 0 */
    CPU_MCGFF_CLK_HZ_CONFIG_0          /*!< MCG fixed frequency clock */
  }
};

/*
** ===================================================================
**     Method      :  Cpu_PE_FillMemory (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Fills a memory area block by a specified value.
**     @param
**       SourceAddressPtr - Source address pointer.
**     @param
**       c - A value used to fill a memory block.
**     @param
**       len - Length of a memory block to fill.
*/
/* ===================================================================*/
void PE_FillMemory(register void* SourceAddressPtr, register uint8_t c, register uint32_t len)
{
  register uint8_t *ptr = (uint8_t*)SourceAddressPtr;

  if (len > 0U) {
    while (len--) {
      *ptr++ = c;
    }
  }
}

/*
** ===================================================================
**     Method      :  Cpu_PE_PeripheralUsed (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Returns information whether a peripheral is allocated by PEx 
**         or not.
**     @param
**       PrphBaseAddress - Base address of a peripheral.
**     @return
**       TRUE if a peripheral is used by PEx or FALSE if it isn't used.
*/
/* ===================================================================*/
bool PE_PeripheralUsed(uint32_t PrphBaseAddress)
{
  (void)PrphBaseAddress;               /*!< Parameter is not used, suppress unused argument warning */
  return FALSE;
}

/*
** ===================================================================
**     Method      :  Cpu_LDD_SetClockConfiguration (component MKL25Z128LK4)
*/
/*!
**     @brief
**         Changes the clock configuration of all LDD components in a 
**         project.
**     @param
**       ClockConfiguration - New CPU clock configuration changed by CPU SetClockConfiguration method.
*/
/* ===================================================================*/
void LDD_SetClockConfiguration(LDD_TClockConfiguration ClockConfiguration)
{
  (void)ClockConfiguration;            /*!< Parameter is not used, suppress unused argument warning */
  /* Just one clock configuration defined in CPU component. */
}

/* END PE_LDD. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
