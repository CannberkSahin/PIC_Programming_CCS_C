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
=============================
In PIC compilers, the program should inform which pins of which port will 
be used as input or output. The CCS C compiler allows to do this job 
automatically or not, as per the user's request. Since the #use fast_io(b) 
command is used in this example, the programmer himself will do the port 
input/output redirection (with set_tris_x() commands) in the program.
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

It is also specified in the program which ports and pins will be input or 
output. set_tris_b(0x00); With statement, port B is routed as complete exit.
0x00 in the command means in hexadecimal base. If we wanted to write it as a 
binary, we would write 0b00000000. 

In the program, output_b(0x00); With the command, the outputs of the B port 
are reset. Thus, with the reset made when the PIC is first energized, 
precautions are taken against the possibility that all of the register
contents are zero. 

There are 2 types of display drive method. The first of these is the direct 
drive method with the microcontroller.In this method, 7 output pins are needed 
to send information to the display.The other method is the application with 
display driver integrated circuit.This method requires 4 information pins.
In this application, a 74164 shift recorder was used and a 7-segment display 
was driven by using only 2 output pins. 

74164 Serial In Parallel Out Shift Register IC
==============================================
74164 is a high speed shift register with serial input of data and parallel 
output of data. It is an 8-bit IC. That means data goes into IC bit by bit 
serially and 8-bit data appears on the output pins. Data at serial input is fed 
through 1 input AND gate and it is synchronous with LOW to HIGH transition of the 
clock. In other words, the transition of data occurs on every positive edge of 
the input clock. It is also referred with these names such as SN54164, SN54LS164, 
SN74164, SN74LS164.

Pin Configuration Details
-------------------------
The detailed description of 74LS164 shift register IC pins is given below.

A, B : These pins are used to input serial data to IC which needs to be converted
into parallel output. In other words, these are serial data input pins. 
CP : This input pin is for a clock signal. It is an active high rising edge pin.
~MR :  This pin is used to perform the function of master Reset. This is an active 
low input pin. Signal at this pin independent of clock, sets all outputs to LOW and 
clears the register.
Q0 – Q7 :  These are output pins and used for providing parallel data of 8 bits as output.
VCC = This is +ve terminal for feeding power supply.
GND = This is the ground terminal of power supply.

74164 Shift Register Working
==============================
Following is the working of this particular IC.

~MR is an active low input master reset pin. Until its state is low, no matter what is at 
input A or B, the output will be in a low state. So it may be called Reset or clear mode 
of operation. In order to perform operation ~MR must be set high.
A and B are two input pins and serial data can be fed through any one of the two input pins 
while using another pin as an active high enables for data entry to other input pins. Any 
input pin which is not being used must be set to High. It is also possible to connect two 
input pins together.When any transition of a clock from low to high occurs, Data is shifted 
one place towards the right and Q0 is filled with AND of two data inputs at A and B. 

Data Transition on Output Pins
==============================
When A = B = High. Q0 will be High and data will be shifted towards right by one place. 
For example, if before transition of clock, data was Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = a b C D E F G H. 
Then after clock transition output will be Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = 1 a b C D E F G. Here a and b 
can be in any state 1 or 0.

At A = High and B = Low. Q0 will be low and data will be shifted towards right by one place. 
For example, if before transition of clock, data was Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = a b C D E F G H. 
Then after clock transition output will be Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = 0 a b C D E F G. Here a and b 
can be in any state 1 or 0.When A = Low and B = High. Q0 will be low and data will be shifted towards 
right by one place. For example, if before transition of clock, data was Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = 
a b C D E F G H. Then after clock transition output will be Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = 0 a b C D E F G. 
Here a and b can be in any state 1 or 0.
At A = Low and B = Low. Q0 will be low and data will be shifted towards right by one place. 
For example, if before transition of clock, data was Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = a b C D E F G H. 
Then after clock transition output will be Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7 = 0 a b C D E F G. Here a and b 
can be in any state 1 or 0.

After the general identification and setting commands are written in the program, the "data" 
constant representing the data pin of the 74164 and the "clock" constants representing the clock 
input are defined in a way to replace the relevant pins. With the first for (i = 0; i <10; ++ i) 
loop command in the program, the data information of the number values to be displayed on the 
display is provided to be sent sequentially.In the loop, the variable i will start at 0 and will 
be incremented at the beginning of each loop and the loop will be processed as long as the variable 
i is less than 10.With this loop, the values of all numbers between 0-9 will be sent to the display.
With the second for (j = 0; j <8; ++ j) loop defined in the same loop, the numerical values to be 
sent to the display are provided to be sent bit by bit. The value of j will increase by one in 
each loop starting from 0 and the loop will be processed as long as j is less than 8.
Output_bit (data, bit_test (digit [i], j)) in the loop; With the bit_test (digit [i], j) command 
contained in the command, the value of the j th bit of the digit [i] array element is learned.
Then output_bit (data, bit_test (digit [i], j)); This bit value learned with the command is sent 
to the "data" constant, ie to the output of pin_b0.Then output_high (clock); and output_low (clock); 
With commands, the clock output, ie pin_b1 output, has been changed from high to low. Thus, the 
clock signal of the 74164 IC is given. 

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.