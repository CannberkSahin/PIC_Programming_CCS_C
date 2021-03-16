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
#use delay (crystal = 20000000) macro is used in delay commands (delay_ms () etc.)
used in the program to let the compiler know the oscillator frequency used.

#use fast_io(b)                 //Port processing commands are valid for B port
#use fast_io(a)                 //Port processing commands are valid for A port
=============================
In PIC compilers, the program should inform which pins of which port will 
be used as input or output. The CCS C compiler allows to do this job 
automatically or not, as per the user's request. Since the #use fast_io(b) 
and #use fast_io(b) command is used in this example, the programmer himself 
will do the port input/output redirection (with set_tris_x() commands) in the program.
If one of the #use xxx_io() macros is not used in the CCS C compiler, 
the #use standard_io() command is considered to have been automatically 
used by the compiler.Thanks to this command, the program does not need to 
declare which port will input which port will be output. Because the compiler
automatically redirects ports as input and output according to the commands 
used. 

After the necessary pre-definitions are completed, the main function 
part is written in the program. The PIC16F877 controller contains various 
hardware units (ADC, EEPROM, CCP etc.). As a result, the same pin can 
have many functions. In order to prevent unused pin features from creating 
unwanted effects in the program while writing a program, unused features 
should be disabled with program commands. For this reason, hardware units 
that are not used at the beginning of the main function have been made passive.

In this example, a global variable has been defined. int1 read_RA0_pin; 
With the command, a 1-bit integer type variable (which can only take 0 and 1 value) 
named read_RA0_pin is defined. Note that the variable is global. This is because 
its global variables are static storage.

It is also specified in the program which ports and pins will be input or 
output. set_tris_b(0x00); With statement, port B is routed as complete exit.
0x00 in the command means in hexadecimal base. If we wanted to write it as a 
binary, we would write 0b00000000. set_tris_b (0x00); With command, RA0 pin 
of port A is set as input pin.

In the program, output_b (0x00); With the command, the outputs of the B port 
are reset. Thus, with the reset made when the PIC is first energized, 
precautions are taken against the possibility that all of the register
contents are zero.input (pin_a0); With the command, the state of the RA0 pin 
is read. 

Normally, when the button is not pressed, RA0 pin is at logic-0 level. 
When the button is pressed, the RA0 pin will be logic-1. The while (true) 
loop is used for the continuous operation of the program. In the program, 
it is requested that the LED light is turned on when the button is pressed 
and it goes off when the button is pressed. Therefore, the state of the RA0 
pin is checked with the if check statement. If the value of the variable 
named read_RA0_pin read from the input is 1, the led turns on, but if the 
value of the variable is 0, that is, if it is not 1, the led turns off.

When a button is pressed, an arc is created in the signal from the button. 
These arcs can be perceived by the fast-sensing controller as the button 
has been pressed more than once. Therefore, it is necessary to give a delay 
of approximately 15-20 milliseconds after the command that checks whether 
the button is pressed or not.

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.