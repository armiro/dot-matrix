# Running dot-matrix via ARM7 LPC21xx
Simple running of 6 sticked-together 8-by-8 dot-matrices via NXP's LPC2124 ARM7 microcontroller.
This project is triggered for displaying rtl writing languages (persian, arabic)

## Softwares required?
1. Keil uvision (v5.25 or newer), also known as MDK-ARM: www.keil.com/demo/eval/arm.htm
2. Keil's Legacy support for ARM7, ... package: www.keil.com/mdk5/legacy
3. Proteus Professional (v8.6 or newer)

## how to run?
Simply clone and extract the repo, open the dot-matrix.uvproj, build the project (F7);
Open the dot-matrix.pdsprj, double click on the LPC2124 in the schematic, from the "program file" browse for the location of the HEX file (/dot-matrix/Objects/dot-matrix.hex) and load it on the microcontroller, finally click on <play> button in Proteus to see the project running.

## How to change the displaying text?
Input "char" array is built via third-party software MX-Coder; downloadable at: https://goo.gl/xK1e9p.
Download the .exe file and write your own text. Then, click on "Generate" (F5) to see the code containing HEX equivalent. Copy the "char" variable and paste it where the "char" variable is defined inside the "main.c"
