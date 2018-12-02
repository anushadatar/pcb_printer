EESchema Schematic File Version 4
LIBS:circuit-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 5C02ACD4
P 6900 2850
F 0 "A?" H 6900 4028 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 6900 3937 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 7050 1800 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 6700 3900 50  0001 C CNN
	1    6900 2850
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A?
U 1 1 5C02AD31
P 4300 2500
F 0 "A?" H 4350 3378 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4350 3287 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4575 1750 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4400 2200 50  0001 C CNN
	1    4300 2500
	-1   0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A?
U 1 1 5C02AD9B
P 4300 4400
F 0 "A?" H 4350 5278 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4350 5187 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4575 3650 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4400 4100 50  0001 C CNN
	1    4300 4400
	-1   0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A?
U 1 1 5C02ADD1
P 4300 6250
F 0 "A?" H 4350 7128 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 4350 7037 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 4575 5500 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 4400 5950 50  0001 C CNN
	1    4300 6250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4700 2100 4800 2100
Wire Wire Line
	4800 2100 4800 2200
Wire Wire Line
	4800 2200 4700 2200
Wire Wire Line
	4700 4000 4800 4000
Wire Wire Line
	4800 4000 4800 4100
Wire Wire Line
	4800 4100 4700 4100
Wire Wire Line
	4700 5850 4800 5850
Wire Wire Line
	4800 5850 4800 5950
Wire Wire Line
	4800 5950 4700 5950
Wire Wire Line
	4700 6150 5450 6150
Wire Wire Line
	5450 3550 6400 3550
Wire Wire Line
	4700 4300 5450 4300
Connection ~ 5450 4300
Wire Wire Line
	5450 4300 5450 3550
Wire Wire Line
	4700 2400 5450 2400
Wire Wire Line
	5450 2400 5450 3550
Connection ~ 5450 3550
Wire Wire Line
	4700 2800 5350 2800
Wire Wire Line
	5350 2800 5350 3450
Wire Wire Line
	5350 3450 6400 3450
Wire Wire Line
	4700 2900 5250 2900
Wire Wire Line
	5250 2900 5250 3350
Wire Wire Line
	5250 3350 6400 3350
Wire Wire Line
	4700 3000 5150 3000
Wire Wire Line
	5150 3000 5150 3250
Wire Wire Line
	5150 3250 6400 3250
Wire Wire Line
	5150 3250 5150 4900
Wire Wire Line
	5150 4900 4700 4900
Connection ~ 5150 3250
Wire Wire Line
	5150 6750 4700 6750
Wire Wire Line
	5150 4900 5150 6750
Connection ~ 5150 4900
Wire Wire Line
	5250 6650 5250 4800
Wire Wire Line
	4700 6650 5250 6650
Connection ~ 5250 3350
Wire Wire Line
	4700 6550 5350 6550
Wire Wire Line
	5350 6550 5350 4700
Connection ~ 5350 3450
Wire Wire Line
	4700 4800 5250 4800
Connection ~ 5250 4800
Wire Wire Line
	5250 4800 5250 3350
Wire Wire Line
	4700 4700 5350 4700
Connection ~ 5350 4700
Wire Wire Line
	5350 4700 5350 3450
$Comp
L power:GND #PWR?
U 1 1 5C02F46A
P 6900 4050
F 0 "#PWR?" H 6900 3800 50  0001 C CNN
F 1 "GND" H 6905 3877 50  0000 C CNN
F 2 "" H 6900 4050 50  0001 C CNN
F 3 "" H 6900 4050 50  0001 C CNN
	1    6900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3950 6800 4050
Wire Wire Line
	6800 4050 6900 4050
Wire Wire Line
	6900 3950 6900 4050
Connection ~ 6900 4050
Wire Wire Line
	7000 3950 7000 4050
Wire Wire Line
	7000 4050 6900 4050
$Comp
L power:+5V #PWR?
U 1 1 5C030990
P 7350 1850
F 0 "#PWR?" H 7350 1700 50  0001 C CNN
F 1 "+5V" H 7365 2023 50  0000 C CNN
F 2 "" H 7350 1850 50  0001 C CNN
F 3 "" H 7350 1850 50  0001 C CNN
	1    7350 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1850 7100 1850
NoConn ~ 7000 1850
NoConn ~ 6800 1850
$Comp
L power:GND #PWR?
U 1 1 5C032A79
P 4100 3350
F 0 "#PWR?" H 4100 3100 50  0001 C CNN
F 1 "GND" H 4105 3177 50  0000 C CNN
F 2 "" H 4100 3350 50  0001 C CNN
F 3 "" H 4100 3350 50  0001 C CNN
	1    4100 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0331D9
P 4100 5250
F 0 "#PWR?" H 4100 5000 50  0001 C CNN
F 1 "GND" H 4105 5077 50  0000 C CNN
F 2 "" H 4100 5250 50  0001 C CNN
F 3 "" H 4100 5250 50  0001 C CNN
	1    4100 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0332B2
P 4100 7100
F 0 "#PWR?" H 4100 6850 50  0001 C CNN
F 1 "GND" H 4105 6927 50  0000 C CNN
F 2 "" H 4100 7100 50  0001 C CNN
F 3 "" H 4100 7100 50  0001 C CNN
	1    4100 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 7050 4100 7050
Wire Wire Line
	4100 7100 4100 7050
Connection ~ 4100 7050
Wire Wire Line
	4100 5250 4100 5200
Wire Wire Line
	4300 5200 4100 5200
Connection ~ 4100 5200
Wire Wire Line
	4100 3350 4100 3300
Wire Wire Line
	4300 3300 4100 3300
Connection ~ 4100 3300
$Comp
L power:+5V #PWR?
U 1 1 5C036958
P 4750 1800
F 0 "#PWR?" H 4750 1650 50  0001 C CNN
F 1 "+5V" H 4765 1973 50  0000 C CNN
F 2 "" H 4750 1800 50  0001 C CNN
F 3 "" H 4750 1800 50  0001 C CNN
	1    4750 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1800 4300 1800
$Comp
L power:+5V #PWR?
U 1 1 5C03808D
P 4750 3700
F 0 "#PWR?" H 4750 3550 50  0001 C CNN
F 1 "+5V" H 4765 3873 50  0000 C CNN
F 2 "" H 4750 3700 50  0001 C CNN
F 3 "" H 4750 3700 50  0001 C CNN
	1    4750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3700 4750 3700
$Comp
L power:+5V #PWR?
U 1 1 5C0397D8
P 4750 5550
F 0 "#PWR?" H 4750 5400 50  0001 C CNN
F 1 "+5V" H 4765 5723 50  0000 C CNN
F 2 "" H 4750 5550 50  0001 C CNN
F 3 "" H 4750 5550 50  0001 C CNN
	1    4750 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5550 4750 5550
$Comp
L power:+12V #PWR?
U 1 1 5C03A730
P 3750 5550
F 0 "#PWR?" H 3750 5400 50  0001 C CNN
F 1 "+12V" H 3765 5723 50  0000 C CNN
F 2 "" H 3750 5550 50  0001 C CNN
F 3 "" H 3750 5550 50  0001 C CNN
	1    3750 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5550 3750 5550
$Comp
L power:+12V #PWR?
U 1 1 5C03B464
P 3750 3700
F 0 "#PWR?" H 3750 3550 50  0001 C CNN
F 1 "+12V" H 3765 3873 50  0000 C CNN
F 2 "" H 3750 3700 50  0001 C CNN
F 3 "" H 3750 3700 50  0001 C CNN
	1    3750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3700 3750 3700
$Comp
L power:+12V #PWR?
U 1 1 5C03C358
P 3750 1800
F 0 "#PWR?" H 3750 1650 50  0001 C CNN
F 1 "+12V" H 3765 1973 50  0000 C CNN
F 2 "" H 3750 1800 50  0001 C CNN
F 3 "" H 3750 1800 50  0001 C CNN
	1    3750 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1800 4100 1800
Text Notes 3500 2000 0    50   ~ 0
Stepper X
Text Notes 3500 3900 0    50   ~ 0
Stepper Y
Text Notes 3500 5750 0    50   ~ 0
Stepper Z
Text Label 6200 3250 0    50   ~ 0
MS1
Text Label 6200 3350 0    50   ~ 0
MS2
Text Label 6200 3450 0    50   ~ 0
MS3
Text Label 6100 3550 0    50   ~ 0
~ENABLE~
$Comp
L Device:C C?
U 1 1 5C03F521
P 3300 1950
F 0 "C?" H 3415 1996 50  0000 L CNN
F 1 "C_100uF" H 3150 1950 50  0000 L CNN
F 2 "" H 3338 1800 50  0001 C CNN
F 3 "~" H 3300 1950 50  0001 C CNN
	1    3300 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C03F5FF
P 3300 2100
F 0 "#PWR?" H 3300 1850 50  0001 C CNN
F 1 "GND" H 3305 1927 50  0000 C CNN
F 2 "" H 3300 2100 50  0001 C CNN
F 3 "" H 3300 2100 50  0001 C CNN
	1    3300 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1800 3300 1800
Connection ~ 3750 1800
$Comp
L Device:C C?
U 1 1 5C0405C1
P 3300 3850
F 0 "C?" H 3415 3896 50  0000 L CNN
F 1 "C_100uF" H 3150 3850 50  0000 L CNN
F 2 "" H 3338 3700 50  0001 C CNN
F 3 "~" H 3300 3850 50  0001 C CNN
	1    3300 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0405C8
P 3300 4000
F 0 "#PWR?" H 3300 3750 50  0001 C CNN
F 1 "GND" H 3305 3827 50  0000 C CNN
F 2 "" H 3300 4000 50  0001 C CNN
F 3 "" H 3300 4000 50  0001 C CNN
	1    3300 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3700 3300 3700
$Comp
L Device:C C?
U 1 1 5C04169E
P 3300 5700
F 0 "C?" H 3415 5746 50  0000 L CNN
F 1 "C_100uF" H 3150 5700 50  0000 L CNN
F 2 "" H 3338 5550 50  0001 C CNN
F 3 "~" H 3300 5700 50  0001 C CNN
	1    3300 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0416A5
P 3300 5850
F 0 "#PWR?" H 3300 5600 50  0001 C CNN
F 1 "GND" H 3305 5677 50  0000 C CNN
F 2 "" H 3300 5850 50  0001 C CNN
F 3 "" H 3300 5850 50  0001 C CNN
	1    3300 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5550 3300 5550
Wire Wire Line
	4700 2500 5500 2500
Wire Wire Line
	5500 2500 5500 3150
Wire Wire Line
	5500 3150 6400 3150
Wire Wire Line
	4700 2600 5550 2600
Wire Wire Line
	5550 3050 6400 3050
Text Label 6150 3050 0    50   ~ 0
DIRX
Text Label 6150 3150 0    50   ~ 0
STEPX
Wire Wire Line
	5550 2600 5550 3050
Wire Wire Line
	6400 2550 5600 2550
Wire Wire Line
	5600 2550 5600 4500
Wire Wire Line
	5600 4500 4700 4500
Wire Wire Line
	6400 2650 5650 2650
Wire Wire Line
	5650 2650 5650 4400
Wire Wire Line
	5650 4400 4700 4400
Text Label 6150 2550 0    50   ~ 0
DIRY
Text Label 6150 2650 0    50   ~ 0
STEPY
Connection ~ 3750 5550
Connection ~ 3750 3700
Wire Wire Line
	6400 2850 5700 2850
Wire Wire Line
	5700 2850 5700 6350
Wire Wire Line
	5700 6350 4700 6350
Wire Wire Line
	4700 6250 5750 6250
Wire Wire Line
	5750 6250 5750 2950
Wire Wire Line
	5750 2950 6400 2950
Text Label 6150 2850 0    50   ~ 0
DIRZ
Text Label 6150 2950 0    50   ~ 0
STEPZ
Wire Wire Line
	2950 2400 3800 2400
Wire Wire Line
	3800 2700 2950 2700
Wire Wire Line
	2950 4300 3800 4300
Wire Wire Line
	3800 4600 2950 4600
Wire Wire Line
	2950 6150 3800 6150
Wire Wire Line
	3800 6450 2950 6450
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 5C07C0E5
P 8750 2500
F 0 "SW?" V 8796 2270 50  0000 R CNN
F 1 "Rotary_Encoder_Switch" V 8705 2270 50  0000 R CNN
F 2 "" H 8600 2660 50  0001 C CNN
F 3 "~" H 8750 2760 50  0001 C CNN
	1    8750 2500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C083D15
P 8250 3050
F 0 "R?" H 8320 3096 50  0000 L CNN
F 1 "R_1k" H 8320 3005 50  0000 L CNN
F 2 "" V 8180 3050 50  0001 C CNN
F 3 "~" H 8250 3050 50  0001 C CNN
	1    8250 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C083D66
P 8250 2700
F 0 "R?" H 8320 2746 50  0000 L CNN
F 1 "R_1k" H 8320 2655 50  0000 L CNN
F 2 "" V 8180 2700 50  0001 C CNN
F 3 "~" H 8250 2700 50  0001 C CNN
	1    8250 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C083DD0
P 8450 3400
F 0 "C?" H 8565 3446 50  0000 L CNN
F 1 "C_10nF" H 8565 3355 50  0000 L CNN
F 2 "" H 8488 3250 50  0001 C CNN
F 3 "~" H 8450 3400 50  0001 C CNN
	1    8450 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2850 8250 2900
Wire Wire Line
	8250 3200 8250 3250
Wire Wire Line
	8250 3250 8450 3250
Wire Wire Line
	8650 3250 8450 3250
Wire Wire Line
	8650 3250 8650 2800
$Comp
L Device:R R?
U 1 1 5C08E748
P 9250 3050
F 0 "R?" H 9180 3096 50  0000 R CNN
F 1 "R_1k" H 9180 3005 50  0000 R CNN
F 2 "" V 9180 3050 50  0001 C CNN
F 3 "~" H 9250 3050 50  0001 C CNN
	1    9250 3050
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C08E74F
P 9050 3400
F 0 "C?" H 8935 3446 50  0000 R CNN
F 1 "C_10nF" H 8935 3355 50  0000 R CNN
F 2 "" H 9088 3250 50  0001 C CNN
F 3 "~" H 9050 3400 50  0001 C CNN
	1    9050 3400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9250 3200 9250 3250
Wire Wire Line
	9250 3250 9050 3250
Wire Wire Line
	8850 3250 9050 3250
Wire Wire Line
	8850 3250 8850 2800
Connection ~ 9050 3250
Connection ~ 8450 3250
$Comp
L power:GND #PWR?
U 1 1 5C09D00C
P 8750 3650
F 0 "#PWR?" H 8750 3400 50  0001 C CNN
F 1 "GND" H 8755 3477 50  0000 C CNN
F 2 "" H 8750 3650 50  0001 C CNN
F 3 "" H 8750 3650 50  0001 C CNN
	1    8750 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2800 8750 3550
Wire Wire Line
	8450 3550 8750 3550
Connection ~ 8750 3550
Wire Wire Line
	8750 3550 8750 3650
Wire Wire Line
	9050 3550 8750 3550
$Comp
L Device:R R?
U 1 1 5C0A6098
P 9250 2700
F 0 "R?" H 9320 2746 50  0000 L CNN
F 1 "R_1k" H 9320 2655 50  0000 L CNN
F 2 "" V 9180 2700 50  0001 C CNN
F 3 "~" H 9250 2700 50  0001 C CNN
	1    9250 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2850 9250 2900
$Comp
L power:+5V #PWR?
U 1 1 5C0A9446
P 8250 2500
F 0 "#PWR?" H 8250 2350 50  0001 C CNN
F 1 "+5V" H 8265 2673 50  0000 C CNN
F 2 "" H 8250 2500 50  0001 C CNN
F 3 "" H 8250 2500 50  0001 C CNN
	1    8250 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C0A9498
P 9250 2500
F 0 "#PWR?" H 9250 2350 50  0001 C CNN
F 1 "+5V" H 9265 2673 50  0000 C CNN
F 2 "" H 9250 2500 50  0001 C CNN
F 3 "" H 9250 2500 50  0001 C CNN
	1    9250 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2500 9250 2550
Wire Wire Line
	8250 2550 8250 2500
Wire Wire Line
	8250 3250 7400 3250
Connection ~ 8250 3250
Wire Wire Line
	6400 2450 6100 2450
Wire Wire Line
	6100 2450 6100 1500
Wire Wire Line
	6100 1500 9900 1500
Wire Wire Line
	9900 1500 9900 3250
Wire Wire Line
	9900 3250 9250 3250
Connection ~ 9250 3250
NoConn ~ 7400 2250
NoConn ~ 7400 2450
NoConn ~ 7400 2650
NoConn ~ 6400 2250
NoConn ~ 6400 2350
NoConn ~ 7400 2850
NoConn ~ 7400 2950
NoConn ~ 7400 3050
NoConn ~ 7400 3150
NoConn ~ 7400 3550
NoConn ~ 7400 3650
NoConn ~ 6400 2750
$Comp
L Device:R_POT RV?
U 1 1 5C0EA8C4
P 7900 2800
F 0 "RV?" H 7831 2754 50  0000 R CNN
F 1 "R_POT_10k" H 8050 3000 50  0000 R CNN
F 2 "" H 7900 2800 50  0001 C CNN
F 3 "~" H 7900 2800 50  0001 C CNN
	1    7900 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	8250 2550 7900 2550
Wire Wire Line
	7900 2550 7900 2650
Connection ~ 8250 2550
Wire Wire Line
	7900 2950 7900 3550
Wire Wire Line
	7900 3550 8450 3550
Connection ~ 8450 3550
Wire Wire Line
	7750 2800 7700 2800
Wire Wire Line
	7700 2800 7700 3350
Wire Wire Line
	7700 3350 7400 3350
Text Label 7450 3250 0    50   ~ 0
EncA
Text Label 6150 2450 0    50   ~ 0
EncB
$Comp
L Device:LED D?
U 1 1 5C072CD8
P 9200 5150
F 0 "D?" V 9238 5033 50  0000 R CNN
F 1 "LED" V 9147 5033 50  0000 R CNN
F 2 "" H 9200 5150 50  0001 C CNN
F 3 "~" H 9200 5150 50  0001 C CNN
	1    9200 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5C072CDF
P 9200 4600
F 0 "#PWR?" H 9200 4450 50  0001 C CNN
F 1 "+12V" H 9215 4773 50  0000 C CNN
F 2 "" H 9200 4600 50  0001 C CNN
F 3 "" H 9200 4600 50  0001 C CNN
	1    9200 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C072CE5
P 9200 5400
F 0 "#PWR?" H 9200 5150 50  0001 C CNN
F 1 "GND" H 9205 5227 50  0000 C CNN
F 2 "" H 9200 5400 50  0001 C CNN
F 3 "" H 9200 5400 50  0001 C CNN
	1    9200 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 5300 9200 5400
$Comp
L Device:LED D?
U 1 1 5C072CEC
P 9600 5150
F 0 "D?" V 9638 5033 50  0000 R CNN
F 1 "LED" V 9547 5033 50  0000 R CNN
F 2 "" H 9600 5150 50  0001 C CNN
F 3 "~" H 9600 5150 50  0001 C CNN
	1    9600 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C072CF3
P 9600 5400
F 0 "#PWR?" H 9600 5150 50  0001 C CNN
F 1 "GND" H 9605 5227 50  0000 C CNN
F 2 "" H 9600 5400 50  0001 C CNN
F 3 "" H 9600 5400 50  0001 C CNN
	1    9600 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5300 9600 5400
$Comp
L power:+5V #PWR?
U 1 1 5C072CFA
P 9600 4600
F 0 "#PWR?" H 9600 4450 50  0001 C CNN
F 1 "+5V" H 9615 4773 50  0000 C CNN
F 2 "" H 9600 4600 50  0001 C CNN
F 3 "" H 9600 4600 50  0001 C CNN
	1    9600 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C072D00
P 9200 4800
F 0 "R?" H 9270 4846 50  0000 L CNN
F 1 "R_1k" H 9270 4755 50  0000 L CNN
F 2 "" V 9130 4800 50  0001 C CNN
F 3 "~" H 9200 4800 50  0001 C CNN
	1    9200 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C072D07
P 9600 4800
F 0 "R?" H 9670 4846 50  0000 L CNN
F 1 "R_200" H 9670 4755 50  0000 L CNN
F 2 "" V 9530 4800 50  0001 C CNN
F 3 "~" H 9600 4800 50  0001 C CNN
	1    9600 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4600 9200 4650
Wire Wire Line
	9200 4950 9200 5000
Wire Wire Line
	9600 4600 9600 4650
Wire Wire Line
	9600 4950 9600 5000
$Comp
L Relay:UMS05-1A80-75L K?
U 1 1 5C076FB4
P 6850 5150
F 0 "K?" H 7130 5196 50  0000 L CNN
F 1 "UMS05-1A80-75L" H 7130 5105 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_UMS" H 7150 5100 50  0001 L CNN
F 3 "https://standexelectronics.com/de/produkte/ums-reed-relais/" H 6850 5150 50  0001 C CNN
	1    6850 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5C07726E
P 6550 5800
F 0 "Q?" H 6755 5846 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 6755 5755 50  0000 L CNN
F 2 "" H 6750 5900 50  0001 C CNN
F 3 "~" H 6550 5800 50  0001 C CNN
	1    6550 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 5450 6650 5600
Wire Wire Line
	6650 6000 6650 6100
$Comp
L power:GND #PWR?
U 1 1 5C07F8CB
P 6650 6100
F 0 "#PWR?" H 6650 5850 50  0001 C CNN
F 1 "GND" H 6655 5927 50  0000 C CNN
F 2 "" H 6650 6100 50  0001 C CNN
F 3 "" H 6650 6100 50  0001 C CNN
	1    6650 6100
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M?
U 1 1 5C07FC71
P 7650 5750
F 0 "M?" H 7808 5746 50  0000 L CNN
F 1 "Motor_DC" H 7808 5655 50  0000 L CNN
F 2 "" H 7650 5660 50  0001 C CNN
F 3 "~" H 7650 5660 50  0001 C CNN
	1    7650 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 5450 7050 5550
Wire Wire Line
	7050 5550 7650 5550
Wire Wire Line
	7650 6050 7650 6100
$Comp
L power:GND #PWR?
U 1 1 5C0887E8
P 7650 6100
F 0 "#PWR?" H 7650 5850 50  0001 C CNN
F 1 "GND" H 7655 5927 50  0000 C CNN
F 2 "" H 7650 6100 50  0001 C CNN
F 3 "" H 7650 6100 50  0001 C CNN
	1    7650 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4850 7050 4600
Wire Wire Line
	6650 4850 6650 4700
$Comp
L power:+12V #PWR?
U 1 1 5C091656
P 6650 4700
F 0 "#PWR?" H 6650 4550 50  0001 C CNN
F 1 "+12V" H 6665 4873 50  0000 C CNN
F 2 "" H 6650 4700 50  0001 C CNN
F 3 "" H 6650 4700 50  0001 C CNN
	1    6650 4700
	1    0    0    -1  
$EndComp
Text Label 7050 4600 0    50   ~ 0
12V_Dremel
$Comp
L formula:NMOS_GSD_30V Q?
U 1 1 5C0A89C4
P 6050 6050
F 0 "Q?" H 6256 6096 50  0000 L CNN
F 1 "NMOS_GSD_30V" H 6256 6005 50  0000 L CNN
F 2 "footprints:SOT-23F" H 6250 6150 50  0001 C CNN
F 3 "https://www.digikey.com/products/en?keywords=SSM3K333RLFCT-ND" H 6250 6100 50  0001 C CNN
F 4 "Digi-Key" H 6050 6050 60  0001 C CNN "MFN"
F 5 "SSM3K333RLFCT-ND" H 6050 6050 60  0001 C CNN "MPN"
F 6 "Value" H 6050 6050 60  0001 C CNN "Package"
F 7 "https://www.digikey.com/products/en?keywords=SSM3K333RLFCT-ND" H 6650 6500 60  0001 C CNN "PurchasingLink"
	1    6050 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0AD349
P 6150 6350
F 0 "#PWR?" H 6150 6100 50  0001 C CNN
F 1 "GND" H 6155 6177 50  0000 C CNN
F 2 "" H 6150 6350 50  0001 C CNN
F 3 "" H 6150 6350 50  0001 C CNN
	1    6150 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 6250 6150 6350
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5C0B261F
P 6050 5550
F 0 "Q?" H 6256 5504 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 6256 5595 50  0000 L CNN
F 2 "" H 6250 5650 50  0001 C CNN
F 3 "~" H 6050 5550 50  0001 C CNN
	1    6050 5550
	1    0    0    1   
$EndComp
Wire Wire Line
	5450 4300 5450 5550
Wire Wire Line
	5850 6050 5450 6050
Connection ~ 5450 6050
Wire Wire Line
	5450 6050 5450 6150
Wire Wire Line
	5850 5550 5450 5550
Connection ~ 5450 5550
Wire Wire Line
	5450 5550 5450 6050
Wire Wire Line
	6150 5750 6150 5800
Wire Wire Line
	6150 5800 6350 5800
Wire Wire Line
	6150 5800 6150 5850
Connection ~ 6150 5800
Wire Wire Line
	6150 4700 6150 5350
$Comp
L power:+5V #PWR?
U 1 1 5C0E252A
P 6150 4700
F 0 "#PWR?" H 6150 4550 50  0001 C CNN
F 1 "+5V" H 6165 4873 50  0000 C CNN
F 2 "" H 6150 4700 50  0001 C CNN
F 3 "" H 6150 4700 50  0001 C CNN
	1    6150 4700
	1    0    0    -1  
$EndComp
NoConn ~ 5650 4600
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 5C0FA387
P 2400 6450
F 0 "M?" H 2588 6573 50  0000 L CNN
F 1 "Stepper_Motor_bipolar" H 2588 6482 50  0000 L CNN
F 2 "" H 2410 6440 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 2410 6440 50  0001 C CNN
	1    2400 6450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 5950 2950 5950
Wire Wire Line
	2950 5950 2950 6150
Wire Wire Line
	2500 6150 2800 6150
Wire Wire Line
	2800 6150 2800 6250
Wire Wire Line
	2800 6250 3800 6250
Wire Wire Line
	2300 5950 2300 6150
Wire Wire Line
	2700 6350 3800 6350
Wire Wire Line
	2950 6450 2950 6550
Wire Wire Line
	2950 6550 2700 6550
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 5C126A88
P 2400 4600
F 0 "M?" H 2588 4723 50  0000 L CNN
F 1 "Stepper_Motor_bipolar" H 2588 4632 50  0000 L CNN
F 2 "" H 2410 4590 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 2410 4590 50  0001 C CNN
	1    2400 4600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 4100 2950 4100
Wire Wire Line
	2500 4300 2800 4300
Wire Wire Line
	2300 4100 2300 4300
Wire Wire Line
	2700 4500 3800 4500
Wire Wire Line
	2950 4700 2700 4700
Wire Wire Line
	2800 4300 2800 4400
Wire Wire Line
	2800 4400 3800 4400
Wire Wire Line
	2950 4100 2950 4300
Wire Wire Line
	2950 4600 2950 4700
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 5C14DC99
P 2400 2700
F 0 "M?" H 2588 2823 50  0000 L CNN
F 1 "Stepper_Motor_bipolar" H 2588 2732 50  0000 L CNN
F 2 "" H 2410 2690 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 2410 2690 50  0001 C CNN
	1    2400 2700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 2200 2950 2200
Wire Wire Line
	2500 2400 2800 2400
Wire Wire Line
	2300 2200 2300 2400
Wire Wire Line
	2700 2600 3800 2600
Wire Wire Line
	2950 2800 2700 2800
Wire Wire Line
	2800 2400 2800 2500
Wire Wire Line
	2800 2500 3800 2500
Wire Wire Line
	2950 2700 2950 2800
Wire Wire Line
	2950 2200 2950 2400
$EndSCHEMATC
