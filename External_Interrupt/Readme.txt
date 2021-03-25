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

EXTERNAL INTERRUPT
==================

PIC products usually have an outer shear pin. This pin is RB0 / INT pin.In this application, 
a button is connected to the RB0 pin. When this button is pressed, external interrupt (ext_int) 
is created and the LED connected to the RB1 pin is turned on. In the program's interrupt function, 
the LED was turned on for 1 second, and after 3 seconds, the LED was turned off. Then the LED was 
turned on and off 10 times at 500 millisecond intervals. Thus, it can be seen that if the button 
is pressed while performing the cutting function, a new cut will not occur. For the controller 
to respond to a new external interrupt, the program must have exited the interrupt function. 
In the program, before the main function, the interrupt function that contains the commands to 
be executed when the interrupt occurs with the #int_ext command is defined. In the main function 
ext_int_edge(H_TO_L); With command, the external interrupt is provided to be at the end of the 
transition from the high edge to the low edge of the input signal. If we wanted the external 
interrupt to be from the low edge to the high edge ext_int_edge (L_TO_H); Should have used the 
command. After these operations enable_interrupts(INT_EXT); With the command, we activate the 
external interrupt (RB0/INT). However, activating the requested interrupt is not enough. 
PIC controllers also need to allow all activated interrupts. In the program for granting 
enable_interrupts(GLOBAL); command has been used. Finally, while (TRUE); An infinite loop was 
created with the command and the program was provided to continue in this way.

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.