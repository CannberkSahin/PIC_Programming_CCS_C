/******************************************************************************
*Project Name: Led Toggle
*Engineer: Canberk SAHIN
*Project Microcontroller: PIC16F877
*Version: V1
*Create Date: 14.03.2021
*Update Date: 14.03.2021
*University: Bursa Technical University
*Revision: - 
******************************************************************************/
#include <Led_Toggle.h>

void main()
{
   setup_psp(PSP_DISABLED);           //PSP unit is disabled
   setup_timer_1(T1_DISABLED);        //T1 unit is disabled
   setup_timer_2(T2_DISABLED, 0, 1);  //T2 unit is disabled
   setup_adc_ports(NO_ANALOGS);       //There is no analog input 
   setup_adc(ADC_OFF);                //ADC unit is disabled
   setup_CCP1(CCP_OFF);               //CCP1 unit is disabled.
   setup_CCP2(CCP_OFF);               //CCP2 unit is disabled.
   
   set_tris_b(0x00);                  //All pins of B port are set as outputs
   
   output_b(0x00);                    //Port B reset
  
   int16 port_b_array[8] = {pin_b0,pin_b1,pin_b2,pin_b3,pin_b4,pin_b5,pin_b6,pin_b7}; //Create Port B pins array
  
   while(TRUE)
   {
      for(int i=0; i<8; ++i){
         delay_ms(500);  //Delay 500 ms           
         output_toggle(port_b_array[i]);  //Sending the pins of the B port with the array pin_b0, pin_b1 ... etc
         delay_ms(500); //Delay 500 ms  
      }
   }

}
