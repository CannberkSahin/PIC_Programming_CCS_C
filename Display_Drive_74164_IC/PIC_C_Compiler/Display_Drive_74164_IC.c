/******************************************************************************
*Project Name: Display Drive With 74164 IC(Integrated Circuit)
*Engineer: Canberk SAHIN
*Project Microcontroller: PIC16F877
*Version: V1
*Create Date: 20.03.2021
*Update Date: 20.03.2021
*University: Bursa Technical University
*Revision: - 
******************************************************************************/
#include <Display_Drive_74164_IC.h>

//Define Macros
#define  data   pin_b0   //data name is assigned to pin_b0
#define  clock  pin_b1   //clock name is assigned to pin_b1

/*Data values for common cathode display*/
const int digit[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};

//Define global variable
char i=0, j=0; //Becasuse char type is 8 bit

void main()
{
   setup_psp(PSP_DISABLED);           //PSP unit is disabled  
   setup_timer_1(T1_DISABLED);        //T1 unit is disabled
   setup_timer_2(T2_DISABLED, 0, 1);  //T2 unit is disabled
   setup_adc_ports(NO_ANALOGS);       //There is no analog input 
   setup_adc(ADC_OFF);                //ADC unit is disabled
   setup_CCP1(CCP_OFF);               //CCP1 unit is disabled.
   setup_CCP2(CCP_OFF);               //CCP2 unit is disabled.
   
   set_tris_b(0x00);     //Port B is completely set as output
   output_b(0x00);       //Port B ppins are completely reset

   while(TRUE)
   {
      for(i=0; i<10; ++i){ //For numbers 0-9 to be displayed on the display
         for(j=0; j<8; ++j){ //To send the values of the numbers as 8 bits through the b port
            output_bit(data, bit_test(digit[i], j)); //Bit value is sent to data pin
            
            //Sending the clock pulse
            output_high(clock); // Clock signal is being made logic-1
            output_low(clock);  // Clock signal is being made logic-0 (Trigger falling down)
         }
         delay_ms(500); //Delay 500 mili seconds
      }
   }
}
