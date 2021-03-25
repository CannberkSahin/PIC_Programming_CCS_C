Canberk ŞAHİN
E-Mail: canberk_cas@hotmail.com

In this reporisitory, basic level programs were written with PIC16xxx series 
microcontrollers produced by Microchip. The programs were drawn and simulated 
in the ISIS section of the Proteus program. Programs are written in the CCS C 
compiler and in the C language. Thus it provides a basis for understanding 
embedded systems.

The header file of the controller that will be used first while 
writing the program has been defined (#include <16f877.h>)
#include <16fxxx.h> this command must be in every program.
If you are using the PIC16F877A controller in your application, 
you have to change the header file to 16F977A.h.Do not forget 
to change the title file name with the same logic for other controller 
models.

#include <16f877.h>
===================
Then, definitions of configuration bits related to the controller 
used are specified. This command should be in every program. 
The CCS C compiler has included these commands in a header file 
identical to the filename to avoid confusion. If you create the 
project from the wizard tab, this header file comes automatically.
In the program we wrote, this file is #include <Led_Blinking_877.h>.
Configuration macros are available in this file. The configuration 
macros used in the project are as follows:

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES XT                       //Crystal or ceramic resonator (Xtal)
#FUSES NOPROTECT                //No protection against reading to ROM memory
#FUSES NOPUT                    //No Power Up Timer. Defines if PUT is not desired
#FUSES NOWRT                    //Program memory not write protected
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOCPD                    //No Code Protected Data. Used when protection of EEPROM memory is not requested

#use delay(crystal=20000000)    //Oscillator frequency used for the delay function
============================
#use delay (crystal = 20000000) macro is used in delay commands (delay_ms() etc.)
used in the program to let the compiler know the oscillator frequency used.

Change interrupt at B4 ... B7 pins on B port
============================================

In PIC controllers, when the status of one of the pins B4, B5, B6, B7 of the B port changes 
(for example, if the input value is logic-1, logic-0 or vice versa), the B port can create 
a change interrupt. In this application, this interrupt was activated and changes were made 
to these pins with the buttons connected to the B4, B5, B6, B7 pin inputs. The LED connected 
to the pins RB0, RB1, RB2 or RB3 turns on for 2 seconds, and then turns off, whichever of the 
B4 ... B7 pins is changed, that is, whichever button is pressed. Thus, it is seen in the LEDs 
which pin has changed. In the circuit, the button inputs are connected to RB4 ... RB7 inputs 
and the inputs are normally logic-0. When the button is pressed, it becomes logic-1.In other 
words, changes occur in the entries.In the program, the RB4 ... RB7 change interrupt function 
has been created with the expressions #int_RB and void change_b_interrupt(void).In the interrupt 
function, the RB4 input is read with the if (input (pin_b4)) command and if the input value 
is "1" then output_high (pin_b0); command is operated.With this command, RB0 output is made logic-1, 
that is, the LED connected to this output is turned on.If the RB4 input value is not "1" 
output_high(pin_b0); command will not be processed and will be skipped to other if commands.
With other if commands, RB5, RB6 and RB7 inputs are to be read. Whichever input is "1", the 
corresponding LED is turned on. Thus, which pin has changed can be seen in the LEDs connected 
to the RB0, RB1, RB2 and RB3 pins.In order to see the changes that occur more easily, delay_ms(2000) 
after the if commands in the interrupt function; command, 2 seconds delay was given.Output_b(0x00) 
at the interrupt function output to detect that a new interrupt has occurred; B port outputs are 
completely reset with the command. In the main program, only while (TRUE); An infinite loop was 
created with the command and the program was enabled to continue working in this way.

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.