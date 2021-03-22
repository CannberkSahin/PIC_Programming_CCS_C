/******************************************************************************
*Project Name: Port Multiplexing With 74138 IC
*Engineer: Canberk SAHIN
*Project Microcontroller: PIC16F877
*Version: V1
*Create Date: 20.03.2021
*Update Date: 20.03.2021
*University: Bursa Technical University
*Revision: - 
******************************************************************************/
#include <Port_Multiplexing_74138_IC.h>

//Define global variable
int i;

void main()
{
   setup_psp(PSP_DISABLED);           //PSP unit is disabled  
   setup_timer_1(T1_DISABLED);        //T1 unit is disabled
   setup_timer_2(T2_DISABLED, 0, 1);  //T2 unit is disabled
   setup_adc_ports(NO_ANALOGS);       //There is no analog input 
   setup_adc(ADC_OFF);                //ADC unit is disabled
   setup_CCP1(CCP_OFF);               //CCP1 unit is disabled.
   setup_CCP2(CCP_OFF);               //CCP2 unit is disabled.
   
   set_tris_b(0x00);    //Port A is completely set as output
   
   while(TRUE)
   {
      for(i=0; i<8; ++i){
         output_b(i|0b00000000);  //The first 74138 is selected and the outputs are activated sequentially.
         delay_ms(250);  //250 ms delay
      }
      
      for(i=0; i<8; ++i){
         output_b(i|0b00010000);  //The second 74138 is selected and the outputs are activated sequentially.
         delay_ms(250);  //250 ms delay
      }
      
      for(i=0; i<8; ++i){
         output_b(i|0b00100000);  //The third 74138 is selected and the outputs are activated sequentially.
         delay_ms(250);  //250 ms delay
      }
      
      for(i=0; i<8; ++i){
         output_b(i|0b00110000);  //The fourth 74138 is selected and the outputs are activated sequentially.
         delay_ms(250);  //250 ms delay
      }
   }

}
