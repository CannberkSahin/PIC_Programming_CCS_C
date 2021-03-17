/******************************************************************************
*Project Name: Display Application-1 (0-F) Counter
*Engineer: Canberk SAHIN
*Project Microcontroller: PIC16F877
*Version: V1
*Create Date: 17.03.2021
*Update Date: 17.03.2021
*University: Bursa Technical University
*Revision: - 
******************************************************************************/
#include <(0-F)_Display_Counter.h>

int8 i;  //An 8-bit global variable is defined

/*Data values for common cathode display*/
const int digit[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void main()
{
   setup_psp(PSP_DISABLED);           //PSP unit is disabled
   setup_timer_1(T1_DISABLED);        //T1 unit is disabled
   setup_timer_2(T2_DISABLED, 0, 1);  //T2 unit is disabled
   setup_adc_ports(NO_ANALOGS);       //There is no analog input 
   setup_adc(ADC_OFF);                //ADC unit is disabled
   setup_CCP1(CCP_OFF);               //CCP1 unit is disabled.
   setup_CCP2(CCP_OFF);               //CCP2 unit is disabled.
   
   set_tris_a(0x00);  //Port A is completely set as output
   set_tris_b(0x00);  //Port A is completely set as output

   output_b(0x00);  //B port outputs are reset
   output_a(0x02);  //RA1 pin logic-1, other pins logic-0 to activate display

   while(TRUE)
   {
      for(i=0; i<16; ++i){
         output_b(digit[i]); //Digit [i] value is sent to port B
         delay_ms(500);  //500 ms delay
      }
   }

}
