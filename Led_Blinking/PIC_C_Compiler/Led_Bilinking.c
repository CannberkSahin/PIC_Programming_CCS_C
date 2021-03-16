/******************************************************************************
*Project Name: Led Blinking                                                   *
*                                                                             *
*Program's Aim: To apply led blinking with Pic 16F877A                        *
*Engineer: Canberk SAHIN                                                      *
*Project Microcontroller: PIC 16F877A                                         *
*Version: V1                                                                  *
*Create Date: 08.03.2021                                                      *
*Update Date: 14.03.2021                                                      *
*University: Bursa Technical University                                       *
*Revision: -                                                                  *
******************************************************************************/
#include <Led_Bilinking.h>

void main()
{
   set_tris_b(0x00); /*Not standart in C func: set_tris_b(0b00000000) 
   PIC's port b all pin is set as output
   */
   
   while(TRUE)
   {
      output_high(pin_b0);  //Turn on led
      delay_ms(500);  //Half a second delay
      output_low(pin_b0);  //Turn off led
      delay_ms(500);  //Half a second delay
   }

}
