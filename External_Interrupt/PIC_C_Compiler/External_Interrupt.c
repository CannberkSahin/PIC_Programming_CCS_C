/******************************************************************************
*Project Name: External Inteerrupt Application with Button and Led
*Engineer: Canberk SAHIN
*Project Microcontroller: PIC16F877
*Version: V1
*Create Date: 22.03.2021
*Update Date: 22.03.2021
*University: Bursa Technical University
*Revision: - 
******************************************************************************/
#include <External_Interrupt.h>

//Define Global variables
int i;

//Define a External Interrupt Funciton
#int_ext     //External Interrupt (RB0-INT Interrupt)
void ext_interrupt(void)
{
   output_high(pin_b1); //Making RB1 output pin "1"
   delay_ms(1000);      //Wait 1 second
   output_low(pin_b1);  //Making RB1 output pin "0"
   delay_ms(3000);      //Wait 3 second
   
   for(i=0; i<10;++i){
      output_high(pin_b1); //Making RB1 output pin "1"
      delay_ms(500);      //Wait half second
      output_low(pin_b1);  //Making RB1 output pin "0"
      delay_ms(500);      //Wait half second
   }
}

void main()
{
   setup_psp(PSP_DISABLED);           //PSP unit is disabled  
   setup_timer_1(T1_DISABLED);        //T1 unit is disabled
   setup_timer_2(T2_DISABLED, 0, 1);  //T2 unit is disabled
   setup_adc_ports(NO_ANALOGS);       //There is no analog input 
   setup_adc(ADC_OFF);                //ADC unit is disabled
   setup_CCP1(CCP_OFF);               //CCP1 unit is disabled.
   setup_CCP2(CCP_OFF);               //CCP2 unit is disabled.
   
   set_tris_b(0x01);           //RB1 pin is set as input
   output_b(0x00);             //B port output is reset at first moment
   
   ext_int_edge(H_TO_L);       //External interrupt is enabled on falling edge
   enable_interrupts(INT_EXT); //Enables INT_EX interrupt
   enable_interrupts(GLOBAL);  //Allows enabled interrupts
   
   while(TRUE)
     ;   //Null statement

}
