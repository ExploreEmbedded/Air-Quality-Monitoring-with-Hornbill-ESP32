EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:VOC_iaqcorec
LIBS:Hornbill-cache
LIBS:oled_i2c
LIBS:Hornbill iAQ-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Air Quality Monitoring with Hornbill ESP32"
Date "2017-02-07"
Rev ""
Comp "ExploreEmbedded.com"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R-RESCUE-Hornbill R4
U 1 1 5899808F
P 6290 3430
F 0 "R4" V 6370 3430 50  0000 C CNN
F 1 "10K" V 6290 3430 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6220 3430 50  0001 C CNN
F 3 "" H 6290 3430 50  0000 C CNN
	1    6290 3430
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-Hornbill C1
U 1 1 58998093
P 5490 3230
F 0 "C1" V 5630 3190 50  0000 L CNN
F 1 "10uF" V 5340 3100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5528 3080 50  0001 C CNN
F 3 "" H 5490 3230 50  0000 C CNN
	1    5490 3230
	0    1    1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 58998094
P 5290 3280
F 0 "#PWR01" H 5290 3030 50  0001 C CNN
F 1 "GND" H 5160 3220 50  0000 C CNN
F 2 "" H 5290 3280 50  0000 C CNN
F 3 "" H 5290 3280 50  0000 C CNN
	1    5290 3280
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Hornbill R3
U 1 1 58998095
P 5990 3430
F 0 "R3" V 6070 3430 50  0000 C CNN
F 1 "10K" V 5990 3430 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5920 3430 50  0001 C CNN
F 3 "" H 5990 3430 50  0000 C CNN
	1    5990 3430
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Hornbill R2
U 1 1 58998096
P 4350 3930
F 0 "R2" V 4430 3930 50  0000 C CNN
F 1 "10K" V 4350 3930 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4280 3930 50  0001 C CNN
F 3 "" H 4350 3930 50  0000 C CNN
	1    4350 3930
	0    1    1    0   
$EndComp
NoConn ~ 4690 3780
Text Notes 4330 4570 0    70   ~ 14
Temperature and
Text GLabel 3010 2310 1    47   Input ~ 0
+5V
Text Notes 1960 4700 0    80   ~ 16
Hornbill ESP32 Dev
$Comp
L ESP32_Breakout1 U1
U 1 1 589980BE
P 2360 3260
F 0 "U1" H 2400 4500 80  0000 C CNN
F 1 "ESP32_Breakout1" H 2410 2110 80  0001 C CNN
F 2 "ee:ESP32_Breakout" H 2360 3260 80  0001 C CNN
F 3 "" H 2360 3260 80  0000 C CNN
	1    2360 3260
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Hornbill R1
U 1 1 589980C4
P 4340 3630
F 0 "R1" V 4420 3630 50  0000 C CNN
F 1 "10K" V 4340 3630 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4270 3630 50  0001 C CNN
F 3 "" H 4340 3630 50  0000 C CNN
	1    4340 3630
	0    1    1    0   
$EndComp
$Comp
L SHT31-DIS RH1
U 1 1 589980DD
P 5140 3880
F 0 "RH1" H 4990 4280 60  0000 C CNN
F 1 "SHT31-DIS" H 4940 3510 60  0000 C CNN
F 2 "nosuz lib:DFN-8_SHT-3x-DIS" H 5290 3880 60  0001 C CNN
F 3 "" H 5290 3880 60  0000 C CNN
	1    5140 3880
	1    0    0    -1  
$EndComp
$Comp
L iAQCOREC U2
U 1 1 589A06B2
P 7970 4020
F 0 "U2" H 7960 4420 50  0000 C CNN
F 1 "iAQCOREC" H 7930 3640 50  0000 C CNN
F 2 "" H 7240 4400 50  0000 C CNN
F 3 "" H 7240 4400 50  0000 C CNN
	1    7970 4020
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Hornbill R5
U 1 1 589A1221
P 7170 3570
F 0 "R5" V 7250 3570 50  0000 C CNN
F 1 "10K" V 7170 3570 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7100 3570 50  0001 C CNN
F 3 "" H 7170 3570 50  0000 C CNN
	1    7170 3570
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Hornbill R6
U 1 1 589A1514
P 8900 3570
F 0 "R6" V 8980 3570 50  0000 C CNN
F 1 "10K" V 8900 3570 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8830 3570 50  0001 C CNN
F 3 "" H 8900 3570 50  0000 C CNN
	1    8900 3570
	1    0    0    -1  
$EndComp
NoConn ~ 8460 4020
NoConn ~ 7490 3810
Text Label 3710 1200 0    100  ~ 20
SCL
Text Label 4550 1460 0    100  ~ 20
SDA
$Comp
L OLED_I2C U3
U 1 1 589A5D01
P 10060 3730
F 0 "U3" H 9710 3970 50  0000 C CNN
F 1 "OLED_I2C" H 10070 3680 50  0000 C CNN
F 2 "" H 9330 4110 50  0000 C CNN
F 3 "" H 9330 4110 50  0000 C CNN
	1    10060 3730
	1    0    0    -1  
$EndComp
NoConn ~ 2960 2460
NoConn ~ 2960 2560
NoConn ~ 2960 2660
NoConn ~ 2960 2760
NoConn ~ 2960 2860
NoConn ~ 2960 2960
NoConn ~ 2960 3060
NoConn ~ 2960 3160
NoConn ~ 2960 3260
NoConn ~ 2960 3360
NoConn ~ 2960 3460
NoConn ~ 2960 3560
NoConn ~ 2960 3660
NoConn ~ 2960 3760
NoConn ~ 2960 3860
NoConn ~ 2960 3960
NoConn ~ 2960 4060
NoConn ~ 1760 2360
NoConn ~ 1760 2460
NoConn ~ 1760 2560
NoConn ~ 1760 2660
NoConn ~ 1760 2760
NoConn ~ 1760 3560
NoConn ~ 1760 3450
NoConn ~ 1760 3360
NoConn ~ 1760 3260
NoConn ~ 1760 3160
NoConn ~ 1760 3060
NoConn ~ 1760 2960
NoConn ~ 1760 2860
NoConn ~ 1760 3860
NoConn ~ 1760 3760
NoConn ~ 1760 4060
Text Notes 8190 4800 0    80   ~ 16
VOC Sensor
Text Notes 10200 4810 0    80   ~ 16
OLED
$Comp
L GND #PWR02
U 1 1 589C812B
P 6110 4890
F 0 "#PWR02" H 6110 4640 50  0001 C CNN
F 1 "GND" H 6110 4740 50  0000 C CNN
F 2 "" H 6110 4890 50  0000 C CNN
F 3 "" H 6110 4890 50  0000 C CNN
	1    6110 4890
	1    0    0    -1  
$EndComp
Entry Wire Line
	3240 4060 3140 4160
Entry Wire Line
	3990 2770 4090 2870
Entry Wire Line
	5640 2770 5740 2870
Entry Wire Line
	5890 2770 5990 2870
Entry Wire Line
	6190 2770 6290 2870
Entry Wire Line
	7070 2770 7170 2870
Entry Wire Line
	8510 2770 8610 2870
Entry Wire Line
	8800 2770 8900 2870
Entry Wire Line
	9930 2770 10030 2870
$Comp
L +3.3V #PWR03
U 1 1 589CFD80
P 5640 2770
F 0 "#PWR03" H 5640 2620 50  0001 C CNN
F 1 "+3.3V" H 5640 2910 50  0000 C CNN
F 2 "" H 5640 2770 50  0000 C CNN
F 3 "" H 5640 2770 50  0000 C CNN
	1    5640 2770
	1    0    0    -1  
$EndComp
Entry Wire Line
	4320 4790 4420 4890
Entry Wire Line
	5240 4790 5340 4890
Entry Wire Line
	6010 4790 6110 4890
Entry Wire Line
	7160 4790 7260 4890
Entry Wire Line
	9500 4790 9600 4890
Entry Wire Line
	1610 4790 1710 4890
Wire Wire Line
	5990 3680 5990 3780
Wire Wire Line
	6290 3680 6290 3930
Wire Wire Line
	5740 3630 5690 3630
Wire Wire Line
	5740 2870 5740 3630
Connection ~ 5740 3230
Wire Wire Line
	1400 3660 1760 3660
Wire Wire Line
	1170 3960 1760 3960
Wire Wire Line
	3010 2310 3010 2360
Wire Wire Line
	5990 2870 5990 3180
Wire Wire Line
	6290 2870 6290 3180
Wire Wire Line
	5690 3230 5740 3230
Wire Wire Line
	5290 3280 5290 3230
Wire Wire Line
	4090 2870 4090 3630
Wire Wire Line
	5690 4080 6010 4080
Wire Wire Line
	5690 3930 6560 3930
Wire Wire Line
	5690 3780 6160 3780
Wire Wire Line
	4690 3630 4590 3630
Wire Wire Line
	4320 4080 4690 4080
Wire Wire Line
	4690 3930 4600 3930
Wire Wire Line
	8610 3810 8460 3810
Wire Wire Line
	8610 2870 8610 3810
Wire Wire Line
	6870 4020 7490 4020
Wire Wire Line
	7170 4020 7170 3820
Wire Wire Line
	8460 4270 9210 4270
Wire Wire Line
	8900 4270 8900 3820
Wire Wire Line
	7160 4270 7490 4270
Wire Wire Line
	8900 2870 8900 3320
Wire Wire Line
	7170 2870 7170 3320
Wire Wire Line
	1610 4160 1760 4160
Wire Wire Line
	3010 2360 2960 2360
Wire Wire Line
	1400 3660 1400 1460
Wire Wire Line
	1400 1460 10290 1460
Wire Wire Line
	10290 1460 10290 3340
Wire Wire Line
	1170 3960 1170 1200
Wire Wire Line
	1170 1200 10160 1200
Wire Wire Line
	10160 1200 10160 3340
Wire Wire Line
	6160 3780 6160 1460
Connection ~ 6160 1460
Connection ~ 5990 3780
Wire Wire Line
	6560 3930 6560 1200
Connection ~ 6560 1200
Connection ~ 6290 3930
Wire Wire Line
	6870 4020 6870 1460
Connection ~ 6870 1460
Connection ~ 7170 4020
Wire Wire Line
	9210 4270 9210 1200
Connection ~ 9210 1200
Connection ~ 8900 4270
Wire Wire Line
	9500 3290 9880 3290
Wire Wire Line
	9880 3290 9880 3340
Wire Wire Line
	2960 4160 3140 4160
Wire Bus Line
	3240 2770 3240 4320
Wire Bus Line
	3240 2770 9980 2770
Wire Wire Line
	10030 3340 10030 2870
Wire Wire Line
	4320 4080 4320 4790
Wire Wire Line
	5240 4380 5240 4790
Wire Wire Line
	6010 4080 6010 4790
Wire Wire Line
	7160 4270 7160 4790
Wire Wire Line
	9500 3290 9500 4790
Wire Bus Line
	1480 4890 10540 4890
Wire Wire Line
	1610 4790 1610 4160
Text Notes 4290 4740 0    70   ~ 14
 Humidity Sensor
$EndSCHEMATC
