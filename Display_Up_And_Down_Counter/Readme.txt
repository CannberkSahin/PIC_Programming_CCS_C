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

#use fast_io(b)                 //Port processing commands are valid for B port
#use fast_io(a)                 //Port processing commands are valid for A port
=============================
In PIC compilers, the program should inform which pins of which port will 
be used as input or output. The CCS C compiler allows to do this job 
automatically or not, as per the user's request. Since the #use fast_io(b)
and #use fast_io(a) command are used in this example, the programmer himself 
will do the port input/output redirection (with set_tris_x() commands) in 
the program. If one of the #use xxx_io() macros is not used in the CCS C 
compiler,the #use standard_io() command is considered to have been automatically 
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

It is also specified in the program which ports and pins will be input or 
output. set_tris_b(0x00); With statement, port B is routed as complete exit.
0x00 in the command means in hexadecimal base. If we wanted to write it as a 
binary, we would write 0b00000000. set_tris_a(0x03); With the command, RA0, 
RA1 pins and other A port pins are input. 0x03 = (0b0000 0011)

In most system designs, controller outputs may not be sufficient for the system.
For this reason, 7 segment display decoder (mux) integrations from BCD are used for display 
drive operation. In this way, the number of pins used is reduced. For common cathode display, 
the 7448 IC can be used as a display driver IC for the common anode display. Information can 
be sent to a display with 4 bits through this integration. Thus, instead of using 7 pins to 
send data, 4 pins are used.Two buttons are used in the application circuit. One is the 
increase and the other is the decrease button. An integrated common cathode display containing 
two displays is used as a display. The 7448 IC has 4 control pins and 8 output pins. Whichever 
output is desired, it is sufficient to give it directly to that data input as 4 bits.
For example, if 6 data is desired to be seen on the display, it is sufficient to send the value 
6, ie 0110 as binary, to the input ends of the 7448. Output ends are connected to the display 
with 220 ohm resistors. The RB4 and RB5 pins of the B port are used for the display selection, 
while the RA0 and RA1 pins of the A port are used for the buttons. Thus, a complete display drive 
operation was performed with only 6 bits of the B port. Display selection pins are controlled by 
NPN transistors. Integretin A, B, C, D pins BCD input pins a, b, c, d, e, f, g pins are output 
pins of the display segment. Integrated LT pin is display test BI / RBO and RBI pins are display 
dimming pins.These three pins should normally be connected to positive supply voltage.

Important Note:
===============
When you try the circuit in the proteus program, you may not be able to fully simulate.
When you try the circuit in proteus program, connect display selection pins directly from controller 
to display.Do not use transistors in between. Do not forget to reverse the outputs in the program 
while simulating in this way. Normally, the transistor must be active for the desired display to be 
active.Therefore, display control output should be made logic-1.Thus, the transistor is conducting 
and the common cathode end of the display is connected to the ground. Thus, the desired display is 
selected. However, if the simulation is to be made in the proteus program without using a transistor, 
the control output should be inverted and logic-0 to make the desired display active. For example 
output_high (display_2); For example output_low (display_2) by inverting the command; should be written 
in the form. The program has been tested in the proteus environment!!

After the general definitions are made in the program, "increase" and "decrease" button entries have been 
fixed with the #define command for convenience in the program. After this command, the compiler program 
will write "pin_a1" where it sees the word "pin_a0" "decrease" instead of the word "increase". 
After defining the variables and constants used in the program, the main function has been passed.
The ports used in the main function are directed according to the input/output status in the circuit.
The ones and tens digits of the "num" variable to be displayed are computed. output_b (digit [ones]) | 0b00010000); 
With the command, the ones digit of the "num" variable is sent to the B port. However, with this command, 
the ones digit is also sent to the B port after the OR operation with data 0b00010000 binary.
The reason for this is that while the ones digit value of the "num" variable is sent to port B, the first 
display is active and the second display is passive. Note that only the 5th and 6th bits are set as 1 or 0 
in the OR operation. The 5th and 6th bits of the information correspond to the RB4 and RB5 bits.
These bits are the display selection pins. Other bits are always zero. Thus, only the display selection 
bits RB4 and RB5 bits were changed in the OR operation. Since the other bits will always enter an OR 
operation with 0, their values will not change. To keep the number displayed on the display open for a certain 
time after this command delay_ms (5); The delay is given with the command. 
Then output_b (digit [tens]) | (0b00100000)); With the command, the first display is passive and the second 
display is activated and the tens digit of the "num" variable is sent to the B port. Note that the 4th bit 
of the OR operation number in this command is 0. So RB4 output is logic-0. Hence the first dsiplay is passive. 
The 5th bit of the number is 1. So RB5 output is logic-1. Therefore, the second display is active. After this 
command, a delay of 5 milliseconds was given.Since the contents of the ones and tens variables are 0 at the 
beginning, 00 will appear on the displays. With the if (input (increase)) command, it is checked whether 
the "increase" button is pressed or not.As seen in the circuit diagram, when the button is not pressed, 
logic-0 information is sent to the input, and logic-1 information is sent to the input. When the increase 
button is pressed, the input (increase) command returns with a value of 1.So the command takes the form of 
if(1), the condition is true, and the commands under the if loop are executed. In the loop commands, at first 
++num; increases the number value by 1. The ones used after this command = num% 10; and tens = num / 10;
The ones and tens digits of the number to be displayed in dsiplay are calculated. With the while(input(increase)) 
command, it is possible to see the current number value in the displays until the button is pressed.When 
the increment button is pressed once, the value of the "num" variable increases by one and this value appears 
on the displays. As long as the button is kept pressed, the number displayed on the display will not increase 
any more. In this way, even if we do not take our hand from the button, the increase will only be once.
When we take our hand from the button, logic-0 information will come to the input. The if command will take 
the value of if (0), so it will exit the loop because the condition will be false. With the command 
if(input(decrease) && (num! = 0)), it is checked whether the decrease button is pressed or not. 
In order for this loop to work, both the decrease button must be pressed and the content of the "num" 
variable must not be zero. Note that the logical AND operator is used in the command for this operation.
The condition for the "num" variable not to be equal to zero is that if the "num" variable is zero, the 
"num" variable should be decreased and not be negative. When the decrease button is pressed --num; The 
"num" variable value was decreased by one with the command. In the decrease button loop, as in the increase 
loop, while (input (decrease)) command, it is ensured that no further reduction operations are made 
as long as the button is pressed. Other commands in the loop are the same as the increment button loop.
Finally, with the if (num == 99) command, it is checked whether the value of the "num" variable reaches 
99 or not. If the "num" value is 99, the variable content is reset. The program continues to work in this way.


The program has proteus drawings. It can be run by inserting the hex code 
of the program into it. 

Good work and Best Regards.