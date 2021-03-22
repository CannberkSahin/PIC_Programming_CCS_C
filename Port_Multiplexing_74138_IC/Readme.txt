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

74138 Integrated Circuit
========================
74LS138 is a member from ‘74xx’family of TTL logic gates. The chip is designed 
for decoding or de-multiplexing applications and comes with 3 inputs to 8 output setup. 
The design is also made for the chip to be used in high-performance memory-decoding or 
data-routing applications, requiring very short propagation delay times. In high 
performance memory systems these decoders can be used to minimize the effects of system 
decoding. The three enable pins of chip (in which Two active-low and one active-high) 
reduce the need for external gates or inverters when expanding. A 24-line decoder can 
be implemented with no external inverters, and a 32-line decoder requires only one inverter.

74LS138 is used in de-multiplexing applications by using enable pin as data input pin.
Also the chip inputs are clamped with high-performance Schottky diodes to suppress 
line-ringing and simplify system design.

74LS138 Pin configuration
---------------------------
Pin	Name	Description
-------------------------------------------
1	A	Address input pin
-------------------------------------------
2	B	Address input pin
-------------------------------------------
3	C	Address input pin
-------------------------------------------
4	G2A	Enable input (active LOW)
-------------------------------------------
5	G2B	Enable input (active LOW)
-------------------------------------------
6	G1	Enable input (active HIGH)
-------------------------------------------
7	Y7	Output pin 7
-------------------------------------------
8	GND	Ground
-------------------------------------------
9	Y6	Output pin 6
-------------------------------------------
10	Y5	Output pin 5
-------------------------------------------
11	Y4	Output pin 4
-------------------------------------------
12	Y3	Output pin 3
-------------------------------------------
13	Y2	Output pin 2
-------------------------------------------
14	Y1	Output pin 1
-------------------------------------------
15	Y0	Output pin 0
-------------------------------------------
16	VCC	Power supply pin
-------------------------------------------

Features and Electrical characteristics of 74LS138 Decoder
==========================================================
-Designed specifically for high speed
-Incorporates three enable pins to simplify cascading
-De-multiplexing capability
-Schottky clamped for high performance
-ESD protection
-Balanced propagation delays
-Inputs accept voltages higher than VCC
-Supply voltage: 1.0V to 5.5V
-Typical propagation delay: 21nS
-Low power consumption: 32mW
-Operating temperature: -40ºC to +125ºC

Overview of 74LS138 Decoder
===========================
As mentioned earlier the chip is specifically designed to be used in high-performance 
memory-decoding or data-routing applications which require very short propagation delay 
times. The memory unit data exchange rate determines the performance of any application 
and the delays of any kind are not tolerable there. In such applications using 74LS138 
line decoder is ideal because the delay times of this device are less than the typical 
access time of the memory. This means that the effective system delay introduced by the 
decoder is negligible to affect the performance.

For understanding the working let us consider the truth table of the device.
----------------------------------------------------------------------------

      INPUTS 	             OUTPUTS
---------------------------------------------
E1 E2 E3   A0 A1 A2   O0 O1 O2 O3 O4 O5 O6 O7
---------------------------------------------
H  X  X    X  X  X    H  H  H  H  H  H  H  H
---------------------------------------------
X  H  X    X  X  X    H  H  H  H  H  H  H  H
---------------------------------------------
X  X  L    X  X  X    H  H  H  H  H  H  H  H
---------------------------------------------
L  L  H    L  L  L    L  H  H  H  H  H  H  H
---------------------------------------------
L  L  H    H  L  L    H  L  H  H  H  H  H  H
---------------------------------------------
L  L  H    L  H  L    H  H  L  H  H  H  H  H
---------------------------------------------
L  L  H    H  H  L    H  H  H  L  H  H  H  H
---------------------------------------------
L  L  H    L  L  H    H  H  H  H  L  H  H  H
---------------------------------------------
L  L  H    H  L  H    H  H  H  H  H  L  H  H
---------------------------------------------
L  L  H    L  H  H    H  H  H  H  H  H  L  H
---------------------------------------------
L  L  H    H  H  H    H  H  H  H  H  H  H  L
---------------------------------------------
H = HIGH, L = LOW and X = Don’t Care

Working of circuit
==================
As shown in table first three rows the enable pins needed to be connected 
appropriately or irrespective of input lines all outputs will be high. 
After connecting the enable pins as shown in circuit diagram you can use 
the input line to get the output.
After powering, if all buttons are not pressed Y0 will be LOW and remaining 
output will be HIGH as shown in table. After only B1 is pressed, A0=HIGH 
and Y1 will become LOW while remaining will be HIGH. Following if only B2 
is pressed, A1=HIGH and Y2 will become LOW while remaining will be HIGH. 
This way we can realize all the truth table by toggling the three buttons 
B1, B2 and B3 (Three inputs A0, A1 and A2) and with that we have three input 
to eight output decoder.

Applications
------------
-Line decoders
-Servers
-Digital systems
-Line De-multiplexing
-Telecom circuits
-Memory circuits

In this application, port multiplexing has been made with the 74138 integration.
In the application circuit, 32 outputs were obtained by using only 6 pins of 
PIC16F877 with 5 74138 integrated circuits.By connecting LEDs to the outputs, 
it is ensured that the status of the output that is active in turn can be visually 
displayed.4 of the 5 74138 integrated circuits used in the circuit were used to 
select the 4 integral for the output and 1 for the output.The outputs of the 74138 
integrated circuit, which is used selectively, are logically inverted. (Not gate).
Therefore, the anodes of the LEDs connected to the outputs are combined and connected 
to + 5v. The cathode of each LED is connected to the corresponding output. 
In the circuit, RB0, RB1 and RB2 pins are used to select the output end numbers of 
the multiplexing integrations. RB4, RB5 and RB6 ends are used to activate (select) 
4 multiplexing integrations in the circuit.In the program, at first, it was aimed 
to control the output ends of the first 74138 IC with for (i = 0; i <8; ++ i) loop.
Output_b (i | 0b00000000) in the loop; With the command, the value of the variable 
i has been OR operation with the number 0b00000000.The first 3 low-order bits 
(RB0, RB1, RB2) of the information sent to port B represent the selection of the 
multiplexed output ends.For example, the value of i is 0 at the first moment, and 
this value is 0b00000000 when you enter the OR operation with the value 0b00000000.
Therefore, when looking at the first three low-valued bits coming to the obtained 
integrated selection circuit, it is seen that the first integrated bits are selected 
and the 0th output of the selected integrated is selected when the first three bits 
of high-value bits are examined.In the second round of the loop, the value of i will 
be 1. As a result of the OR operation, this time the number 0b00000001 will be obtained. 
Accordingly, the first integrated will be selected again, but this time it is seen that 
the 1st output of the selected integrated is selected.The selected output will be logic-0 
and the LED connected to the output will be turned on.All 8 outputs of the first 74138 
integrated circuit selected in this way will be logic-0, respectively, and the first 
loop will exit.After exiting the first for loop in the program, the second for loop 
will be entered. In the second for loop output_b (i | 0b00010000); This time with the 
command, the value of the i variable value 0b00010000 enters the job OR operation.
The reason for this is to enable the integrated selector integrated to activate the 
second 74138 integration.With the same logic, this time, all outputs of the second 
74138 IC are activated sequentially.The program works with this logic and 32 outputs 
are activated sequentially. A delay of 250 ms is given to see the LEDs in between.

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.