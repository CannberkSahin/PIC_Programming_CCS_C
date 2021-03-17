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

#use fast_io(a)                 //Port processing commands are valid for A port
#use fast_io(b)                 //Port processing commands are valid for B port
=============================
In PIC compilers, the program should inform which pins of which port will 
be used as input or output. The CCS C compiler allows to do this job 
automatically or not, as per the user's request. Since the #use fast_io(b) 
and  #use fast_io(a) command are used in this example, the programmer himself 
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

In this application, the control of a 7-segment display with a controller 
has been examined. For this, a counter application that counts from 
0 to F with a 7-segment display has been implemented. 
7-segment Display
=================
An LED or Light Emitting Diode, is a solid state optical pn-junction diode 
which emits light energy in the form of photons. The emission of these photons 
occurs when the diode junction is forward biased by an external voltage allowing 
current to flow across its junction, and in Electronics we call this process 
electroluminescence.The actual colour of the visible light emitted by an LED, 
ranging from blue to red to orange, is decided by the spectral wavelength of the 
emitted light which itself is dependent upon the mixture of the various impurities 
added to the semiconductor materials used to produce it. Light emitting diodes have 
many advantages over traditional bulbs and lamps, with the main ones being their 
small size, long life, various colours, cheapness and are readily available, 
as well as being easy to interface with various other electronic components and 
digital circuits.But the main advantage of light emitting diodes is that because 
of their small die size, several of them can be connected together within one 
small and compact package producing what is generally called a 7-segment Display.
The 7-segment display, also written as “seven segment display”, consists of seven 
LEDs (hence its name) arranged in a rectangular fashion as shown. Each of the seven 
LEDs is called a segment because when illuminated the segment forms part of a 
numerical digit (both Decimal and Hex) to be displayed. An additional 8th LED is 
sometimes used within the same package thus allowing the indication of a decimal point, 
(DP) when two or more 7-segment displays are connected together to display numbers 
greater than ten.Each one of the seven LEDs in the display is given a positional 
segment with one of its connection pins being brought straight out of the rectangular 
plastic package. These individually LED pins are labelled from a through to g representing 
each individual LED. The other LED pins are connected together and wired to form a common pin.
So by forward biasing the appropriate pins of the LED segments in a particular order, some 
segments will be light and others will be dark allowing the desired character pattern of the 
number to be generated on the display. This then allows us to display each of the ten decimal 
digits 0 through to 9 on the same 7-segment display.The displays common pin is generally used 
to identify which type of 7-segment display it is. As each LED has two connecting pins, one 
called the “Anode” and the other called the “Cathode”, there are therefore two types of LED 
7-segment display called: Common Cathode (CC) and Common Anode (CA).
The difference between the two displays, as their name suggests, is that the common cathode 
has all the cathodes of the 7-segments connected directly together and the common anode has 
all the anodes of the 7-segments connected together and is illuminated as follows.

1. The Common Cathode (CC)
==========================
In the common cathode display, all the cathode connections of the LED segments are joined 
together to logic “0” or ground. The individual segments are illuminated by application of 
a “HIGH”, or logic “1” signal via a current limiting resistor to forward bias the individual 
Anode terminals (a-g).

2. The Common Anode (CA)
========================
In the common anode display, all the anode connections of the LED segments are joined together 
to logic “1”. The individual segments are illuminated by applying a ground, logic “0” or “LOW” 
signal via a suitable current limiting resistor to the Cathode of the particular segment (a-g).

In general, common anode displays are more popular as many logic circuits can sink more current 
than they can source. Also note that a common cathode display is not a direct replacement in a 
circuit for a common anode display and vice versa, as it is the same as connecting the LEDs in 
reverse, and hence light emission will not take place.

Depending upon the decimal digit to be displayed, the particular set of LEDs is forward biased. 
For instance, to display the numerical digit 0, we will need to light up six of the LED segments 
corresponding to a, b, c, d, e and f. Thus the various digits from 0 through 9 can be displayed 
using a 7-segment display as shown.

7-segment Display Truth Table
=============================
-----------------------------------------------------------
Decimal
Digit		Individual Segments Illuminated
-----------------------------------------------------------
	a	b	c	d	e	f	g |
-----------------------------------------------------------
0	×	×	×	×	×	×	  |
-----------------------------------------------------------
1	 	×	×	 	 	 	  |
-----------------------------------------------------------
2	×	×	 	×	×	 	× |
-----------------------------------------------------------
3	×	×	×	×	 	 	× |
-----------------------------------------------------------
4	 	×	×	 	 	×	× |
-----------------------------------------------------------
5	×	 	×	×	 	×	× |
-----------------------------------------------------------
6	×	 	×	×	×	×	× |
-----------------------------------------------------------
7	×	×	×	 	 	 	  |
-----------------------------------------------------------
8	×	×	×	×	×	×	× |
-----------------------------------------------------------
9	×	×	×	 	 	×	× |
-----------------------------------------------------------

Driving a 7-segment Display
===========================
Although a 7-segment display can be thought of as a single display, it is still seven individual 
LEDs within a single package and as such these LEDs need protection from over current. LEDs produce 
light only when it is forward biased with the amount of light emitted being proportional to the 
forward current.
This means then that an LEDs light intensity increases in an approximately linear manner with an 
increasing current. So this forward current must be controlled and limited to a safe value by an 
external resistor to prevent damage to the LED segments.
The forward voltage drop across a red LED segment is very low at about 2-to-2.2 volts, (blue and white 
LEDs can be as high as 3.6 volts) so to illuminate correctly, the LED segments should be connected to 
a voltage source in excess of this forward voltage value with a series resistance used to limit the 
forward current to a desirable value.
Typically for a standard red coloured 7-segment display, each LED segment can draw about 15 mA to 
illuminated correctly, so on a 5 volt digital logic circuit, the value of the current limiting 
resistor would be about 200Ω (5v – 2v)/15mA, or 220Ω to the nearest higher preferred value.

Variable i has been defined to be used as a counter in the program. Then, with the const int [16] 
command, an integer array named "digit" is defined, where the data to be sent to the B port to be 
displayed on the display is kept.Since array members will not change in the program, they are 
defined as a constant, not a variable, const keyword. output_a (0x01) in the program; RA0 output 
is made logic-1 with command. Therefore, the Q1 transistor has passed on to the conduction.
In this way, the common cathode end of the display will be connected to the chassis (+ 5V).
Displays consume current according to their size. If the controller does not provide the current 
consumed by the Diplay (especially large displays), displays are driven by driver elements. 
(transistor, high current driver integrated etc.).With the for (i = 0; i <16; ++ i) command, 
the variable i starts at 0, and each loop rotation is incremented by 1 to return the loop as long as 
it is less than 16. Thus, the numbers from 0 to F will appear on the display and it will return to 
the beginning again. Output_b (digit [i]) in the loop; With the command, the ith element of the digit 
array is sent to the B port. delay_ms (500); command, a delay of 500 milliseconds was provided.
For example, since the value of i will be 0 at first, it will take the value of digit [0] = 0x3F 
and when this value is sent to the B port, the display will show a "0" value. In the second round 
of the loop, the value of i will be increased by one and since its value will be 1, the first element 
of the digit array will take the value digit [1] = 0x06. When this value is sent to the B port, the 
value "1" will appear on the display. The cycle continues in this way and the numbers from 0 to F 
will appear on the display, respectively.

The program has proteus drawings. It can be run by inserting the hex code 
of the program into it.

Good work and Best Regards.