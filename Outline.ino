1: include <SPI.h>                                                 #Library to communicate with 24 bit ADC ADS1256

2: include <digitalWriteFast.h>                                    #Library to communicate with 24 bit ADC ADS1256

3: Define all digital output channels to control 4 decoders

4: Begin serial communication at 500000 bps

5: Begin SPI library

6: Initialize 24 bit ADC ADS1256

7: While(true)                                                     #repeat indefinitely


8:          Set parameters to sample measurements in test unit     #Number of samples (250), number of electrodes (16)

9:          While(n = 0, n < 16, n + + )                           #Cycle to perform the adjacent voltage measurement method

10:                 Select pair of probes to inject current

11:                 While(m = 0, n < 12, m + + )                   #Cycle to perform the adjacent voltage measurement method

12:                        Select pair of probes to measure voltage 

13:                        Take k samples with 24 bit ADC ADS1256  #250 samples set, ADC and MCU communicates through SPI

14:                        Discard first 130 values #Values of the transitory state

15:                        Calculate the statistics mean of the rest of the sample vector

16:                        Send the value to serial port as raw data.

17:                        Deselect pair of probes to measure voltage

18:                 End While

19:                 Deselect pair of probes to inject current

20:         End While

21: End While
22: End Routine
