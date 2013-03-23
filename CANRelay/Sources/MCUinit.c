/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE INTERRUPT SERVICE ROUTINES
**     OR EXPLICITLY MARKED SECTIONS
**
**     Project     : DeviceInitialization
**     Processor   : MC9S08DZ32CLC
**     Version     : Component 01.043, Driver 01.08, CPU db: 3.00.025
**     Datasheet   : MC9S08DZ60 Rev. 3 10/2007
**     Date/Time   : 2013-03-23, 17:31, # CodeGen: 1
**     Abstract    :
**         This module contains device initialization code 
**         for selected on-chip peripherals.
**     Contents    :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

/* MODULE MCUinit */

#include <mc9s08dz32.h>                /* I/O map for MC9S08DZ32CLC */
#include "MCUinit.h"

/* Standard ANSI C types */
#ifndef int8_t
typedef signed char int8_t;
#endif
#ifndef int16_t
typedef signed int int16_t;
#endif
#ifndef int32_t
typedef signed long int int32_t;
#endif

#ifndef uint8_t
typedef unsigned char uint8_t;
#endif
#ifndef uint16_t
typedef unsigned int uint16_t;
#endif
#ifndef uint32_t
typedef unsigned long int uint32_t;
#endif

/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */


/*
** ===================================================================
**     Method      :  MCU_init (component MC9S08DZ60_32)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/
void MCU_init(void)
{
  /* ### MC9S08DZ60_32 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPT=0,STOPE=0,SCI2PS=0,IICPS=0 */
  SOPT1 = 0x00U;                                   
  /* SOPT2: COPCLKS=0,COPW=0,ADHTS=0,MCSEL=0 */
  SOPT2 = 0x00U;                                   
  /* SPMSC1: LVWF=0,LVWACK=0,LVWIE=0,LVDRE=1,LVDSE=1,LVDE=1,BGBE=0 */
  SPMSC1 = 0x1CU;                                   
  /* SPMSC2: LVDV=0,LVWV=0,PPDF=0,PPDACK=0,PPDC=0 */
  SPMSC2 = 0x00U;                                   
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(unsigned char*far)0xFFAFU != 0xFFU) { /* Test if the device trim value is stored on the specified address */
    MCGTRM = *(unsigned char*far)0xFFAFU; /* Initialize MCGTRM register from a non volatile memory */
    MCGSC = *(unsigned char*far)0xFFAEU; /* Initialize MCGSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* MCGC2: BDIV=1,RANGE=1,HGO=0,LP=0,EREFS=1,ERCLKEN=1,EREFSTEN=0 */
  MCGC2 = 0x66U;                       /* Set MCGC2 register */
  /* MCGC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=0,IREFSTEN=0 */
  MCGC1 = 0x04U;                       /* Set MCGC1 register */
  /* MCGC3: LOLIE=0,PLLS=0,CME=0,VDIV=1 */
  MCGC3 = 0x01U;                       /* Set MCGC3 register */
  while(MCGSC_LOCK == 0U) {            /* Wait until FLL is locked */
  }
  

  /* Common initialization of the CPU registers */
  /* PTASE: PTASE7=0,PTASE6=0,PTASE5=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  PTASE = 0x00U;                                   
  /* PTBSE: PTBSE1=0,PTBSE0=0 */
  PTBSE &= (unsigned char)~(unsigned char)0x03U;                     
  /* PTDSE: PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  PTDSE &= (unsigned char)~(unsigned char)0x3FU;                     
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE0=0 */
  PTESE &= (unsigned char)~(unsigned char)0xFDU;                     
  /* PTGSE: PTGSE1=0,PTGSE0=0 */
  PTGSE &= (unsigned char)~(unsigned char)0x03U;                     
  /* PTADS: PTADS7=0,PTADS6=0,PTADS5=0,PTADS4=0,PTADS3=0,PTADS2=0,PTADS1=0,PTADS0=0 */
  PTADS = 0x00U;                                   
  /* PTBDS: PTBDS7=0,PTBDS6=0,PTBDS5=0,PTBDS4=0,PTBDS3=0,PTBDS2=0,PTBDS1=0,PTBDS0=0 */
  PTBDS = 0x00U;                                   
  /* PTDDS: PTDDS7=0,PTDDS6=0,PTDDS5=0,PTDDS4=0,PTDDS3=0,PTDDS2=0,PTDDS1=0,PTDDS0=0 */
  PTDDS = 0x00U;                                   
  /* PTEDS: PTEDS7=0,PTEDS6=0,PTEDS5=0,PTEDS4=0,PTEDS3=0,PTEDS2=0,PTEDS1=0,PTEDS0=0 */
  PTEDS = 0x00U;                                   
  /* PTGDS: PTGDS5=0,PTGDS4=0,PTGDS3=0,PTGDS2=0,PTGDS1=0,PTGDS0=0 */
  PTGDS = 0x00U;                                   
  /* ### Init_GPIO init code */
  /* PTAD: PTAD7=0,PTAD6=0,PTAD5=0,PTAD4=0,PTAD3=0,PTAD2=0,PTAD1=0,PTAD0=0 */
  PTAD = 0x00U;                                   
  /* PTADD: PTADD7=1,PTADD6=1,PTADD5=1,PTADD4=1,PTADD3=1,PTADD2=1,PTADD1=1,PTADD0=1 */
  PTADD = 0xFFU;                                   
  /* ### Init_GPIO init code */
  /* PTBD: PTBD1=0,PTBD0=0 */
  PTBD &= (unsigned char)~(unsigned char)0x03U;                     
  /* PTBDD: PTBDD1=1,PTBDD0=1 */
  PTBDD |= (unsigned char)0x03U;                      
  /* ### Init_GPIO init code */
  /* PTDD: PTDD5=0,PTDD4=0,PTDD3=0,PTDD2=0,PTDD1=0,PTDD0=0 */
  PTDD &= (unsigned char)~(unsigned char)0x3FU;                     
  /* PTDDD: PTDDD5=0,PTDDD4=1,PTDDD3=1,PTDDD2=1,PTDDD1=1,PTDDD0=1 */
  PTDDD = (PTDDD & (unsigned char)~(unsigned char)0x20U) | (unsigned char)0x1FU;
  /* ### Init_GPIO init code */
  /* PTED: PTED3=0,PTED2=0 */
  PTED &= (unsigned char)~(unsigned char)0x0CU;                     
  /* PTEDD: PTEDD3=1,PTEDD2=1 */
  PTEDD |= (unsigned char)0x0CU;                      
  /* ### Init_MSCAN init code */
  /* CANCTL0: INITRQ=1 */
  CANCTL0 |= (unsigned char)0x01U;                      
  while(CANCTL1_INITAK == 0U) {        /* Wait for init acknowledge */
  }
  /* CANCTL1: CANE=0,CLKSRC=0,LOOPB=0,LISTEN=1,BORM=0,WUPM=0,SLPAK=0,INITAK=1 */
  CANCTL1 = 0x11U;                                   
  /* CANBTR1: SAMP=0,TSEG22=0,TSEG21=0,TSEG20=0,TSEG13=0,TSEG12=0,TSEG11=0,TSEG10=0 */
  CANBTR1 = 0x00U;                                   
  /* CANBTR0: SJW1=0,SJW0=0,BRP5=0,BRP4=0,BRP3=0,BRP2=1,BRP1=1,BRP0=1 */
  CANBTR0 = 0x07U;                                   
  /* CANIDAC: IDAM1=0,IDAM0=0,IDHIT2=0,IDHIT1=0,IDHIT0=0 */
  CANIDAC = 0x00U;                                   
  /* CANIDAR0: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR0 = 0x00U;                                   
  /* CANIDAR1: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR1 = 0x00U;                                   
  /* CANIDAR2: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR2 = 0x00U;                                   
  /* CANIDAR3: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR3 = 0x00U;                                   
  /* CANIDAR4: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR4 = 0x00U;                                   
  /* CANIDAR5: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR5 = 0x00U;                                   
  /* CANIDAR6: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR6 = 0x00U;                                   
  /* CANIDAR7: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  CANIDAR7 = 0x00U;                                   
  /* CANIDMR0: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR0 = 0x00U;                                   
  /* CANIDMR1: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR1 = 0x00U;                                   
  /* CANIDMR2: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR2 = 0x00U;                                   
  /* CANIDMR3: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR3 = 0x00U;                                   
  /* CANIDMR4: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR4 = 0x00U;                                   
  /* CANIDMR5: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR5 = 0x00U;                                   
  /* CANIDMR6: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR6 = 0x00U;                                   
  /* CANIDMR7: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  CANIDMR7 = 0x00U;                                   
  /* CANCTL0: RXFRM=0,RXACT=0,CSWAI=0,SYNCH=0,TIME=0,WUPE=0,SLPRQ=0,INITRQ=1 */
  CANCTL0 = 0x01U;                                   
  /* ### */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm CLI;                             /* Enable interrupts */
  /*lint -restore Enable MISRA rule (1.1) checking. */

} /*MCU_init*/


/*lint -save  -e765 Disable MISRA rule (8.10) checking. */
/*
** ===================================================================
**     Interrupt handler : isrVcantx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isrVcantx(void)
{
  /* Write your interrupt code here ... */
}
/* end of isrVcantx */


/*
** ===================================================================
**     Interrupt handler : isrVcanrx
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isrVcanrx(void)
{
  /* Write your interrupt code here ... */
	can_rx_ISR();
}
/* end of isrVcanrx */


/*
** ===================================================================
**     Interrupt handler : isrVcanerr
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isrVcanerr(void)
{
  /* Write your interrupt code here ... */

}
/* end of isrVcanerr */


/*
** ===================================================================
**     Interrupt handler : isrVcanwu
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
__interrupt void isrVcanwu(void)
{
  /* Write your interrupt code here ... */

}
/* end of isrVcanwu */


/*lint -restore Enable MISRA rule (8.10) checking. */

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NVPROT: EPS=3,FPS=0x3F */
static const unsigned char NVPROT_INIT @0x0000FFBDU = 0xFFU;
/* NVOPT: KEYEN=0,FNORED=1,EPGMOD=1,SEC1=1,SEC0=0 */
static const unsigned char NVOPT_INIT @0x0000FFBFU = 0x7EU;
/*lint -restore Enable MISRA rule (1.1) checking. */



extern near void _Startup(void);

/* Interrupt vector table */
#ifndef UNASSIGNED_ISR
  #define UNASSIGNED_ISR ((void(*near const)(void)) 0xFFFF) /* unassigned interrupt service routine */
#endif

/*lint -save  -e923 Disable MISRA rule (11.3) checking. */
/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static void (* near const _vect[])(void) @0xFFC0 = { /* Interrupt vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
         UNASSIGNED_ISR,               /* Int.no. 31 VReserved31 (at FFC0)           Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 30 Vacmp1 (at FFC2)                Unassigned */
         isrVcantx,                    /* Int.no. 29 Vcantx (at FFC4)                Used */
         isrVcanrx,                    /* Int.no. 28 Vcanrx (at FFC6)                Used */
         isrVcanerr,                   /* Int.no. 27 Vcanerr (at FFC8)               Used */
         isrVcanwu,                    /* Int.no. 26 Vcanwu (at FFCA)                Used */
         UNASSIGNED_ISR,               /* Int.no. 25 Vrtc (at FFCC)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 24 Viic (at FFCE)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 23 Vadc (at FFD0)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 22 Vport (at FFD2)                 Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 21 Vsci2tx (at FFD4)               Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 20 Vsci2rx (at FFD6)               Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 19 Vsci2err (at FFD8)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 18 Vsci1tx (at FFDA)               Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 17 Vsci1rx (at FFDC)               Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 16 Vsci1err (at FFDE)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 15 Vspi (at FFE0)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 14 Vtpm2ovf (at FFE2)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 13 Vtpm2ch1 (at FFE4)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 12 Vtpm2ch0 (at FFE6)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 11 Vtpm1ovf (at FFE8)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no. 10 VReserved10 (at FFEA)           Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  9 VReserved9 (at FFEC)            Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  8 Vtpm1ch3 (at FFEE)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  7 Vtpm1ch2 (at FFF0)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  6 Vtpm1ch1 (at FFF2)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  5 Vtpm1ch0 (at FFF4)              Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  4 Vlol (at FFF6)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  3 Vlvd (at FFF8)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  2 Virq (at FFFA)                  Unassigned */
         UNASSIGNED_ISR,               /* Int.no.  1 Vswi (at FFFC)                  Unassigned */
         _Startup                      /* Int.no.  0 Vreset (at FFFE)                Reset vector */
};
/*lint -restore Enable MISRA rule (11.3) checking. */




/* END MCUinit */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
