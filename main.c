#include <LPC21xx.h>

#define width 24
#define height 16
#define name_length 72
#define direction_controller_pin 25
#define speed_control_pin 24
# define font_selector_pin 23
#define to_right 1
#define to_left -1

// the char variable is built with MX-Coder software
const unsigned char name[]= 
	{
  0x00,0x00,	//	0002		. . . . . . . . . . . . . . . . 
	0x7E,0x00,	//	0004		. # # # # # # . . . . . . . . . 
	0x7E,0x00,	//	0006		. # # # # # # . . . . . . . . . 
	0x60,0x00,	//	0008		. # # . . . . . . . . . . . . . 
	0x60,0x00,	//	000A		. # # . . . . . . . . . . . . . 
	0x6C,0x00,	//	000C		. # # . # # . . . . . . . . . . 
	0x6C,0x00,	//	000E		. # # . # # . . . . . . . . . . 
	0x6C,0x00,	//	0010		. # # . # # . . . . . . . . . . 
	0x7C,0x00,	//	0012		. # # # # # . . . . . . . . . . 
	0x7C,0x00,	//	0014		. # # # # # . . . . . . . . . . 
	0x0C,0x00,	//	0016		. . . . # # . . . . . . . . . . 
	0x0C,0x00,	//	0018		. . . . # # . . . . . . . . . . 
	0x6F,0x80,	//	001A		. # # . # # # # # . . . . . . . 
	0x6F,0x80,	//	001C		. # # . # # # # # . . . . . . . 
	0x00,0x00,	//	001E		. . . . . . . . . . . . . . . . 
	0x6F,0x80,	//	0020		. # # . # # # # # . . . . . . . 
	0x6F,0x80,	//	0022		. # # . # # # # # . . . . . . . 
	0x6D,0x80,	//	0024		. # # . # # . # # . . . . . . . 
	0x6D,0x80,	//	0026		. # # . # # . # # . . . . . . . 
	0x6D,0x80,	//	0028		. # # . # # . # # . . . . . . . 
	0x7F,0x80,	//	002A		. # # # # # # # # . . . . . . . 
	0x7F,0x80,	//	002C		. # # # # # # # # . . . . . . . 
	0x0C,0x00,	//	002E		. . . . # # . . . . . . . . . . 
	0x0C,0x00,	//	0030		. . . . # # . . . . . . . . . . 
	0x0F,0xC0,	//	0032		. . . . # # # # # # . . . . . . 
	0x0F,0xD8,	//	0034		. . . . # # # # # # . # # . . . 
	0x0C,0xD8,	//	0036		. . . . # # . . # # . # # . . . 
	0x0C,0xD8,	//	0038		. . . . # # . . # # . # # . . . 
	0x0F,0xD8,	//	003A		. . . . # # # # # # . # # . . . 
	0x0F,0xC0,	//	003C		. . . . # # # # # # . . . . . . 
	0x0C,0x00,	//	003E		. . . . # # . . . . . . . . . . 
	0x0C,0x00,	//	0040		. . . . # # . . . . . . . . . . 
	0x0F,0x80,	//	0042		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	0044		. . . . # # # # # . . . . . . . 
	0x0D,0x80,	//	0046		. . . . # # . # # . . . . . . . 
	0x0F,0x80,	//	0048		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	004A		. . . . # # # # # . . . . . . . 
	0x0C,0x00,	//	004C		. . . . # # . . . . . . . . . . 
	0x6C,0x00,	//	004E		. # # . # # . . . . . . . . . . 
	0x6C,0x00,	//	0050		. # # . # # . . . . . . . . . . 
	0x6F,0x80,	//	0052		. # # . # # # # # . . . . . . . 
	0x6F,0x80,	//	0054		. # # . # # # # # . . . . . . . 
	0x00,0x00,	//	0056		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	0058		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	005A		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	005C		. . . . . . . . . . . . . . . . 
	0x0C,0x00,	//	005E		. . . . # # . . . . . . . . . . 
	0x0D,0x80,	//	0060		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	0062		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	0064		. . . . # # . # # . . . . . . . 
	0x0F,0x80,	//	0066		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	0068		. . . . # # # # # . . . . . . . 
	0x0C,0x00,	//	006A		. . . . # # . . . . . . . . . . 
	0x0C,0x00,	//	006C		. . . . # # . . . . . . . . . . 
	0x0F,0x80,	//	006E		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	0070		. . . . # # # # # . . . . . . . 
	0x0D,0x80,	//	0072		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	0074		. . . . # # . # # . . . . . . . 
	0x0F,0x80,	//	0076		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	0078		. . . . # # # # # . . . . . . . 
	0x0C,0x00,	//	007A		. . . . # # . . . . . . . . . . 
	0x0D,0x80,	//	007C		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	007E		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	0080		. . . . # # . # # . . . . . . . 
	0x0D,0x80,	//	0082		. . . . # # . # # . . . . . . . 
	0x0F,0x80,	//	0084		. . . . # # # # # . . . . . . . 
	0x0F,0x80,	//	0086		. . . . # # # # # . . . . . . . 
	0x0C,0x00,	//	0088		. . . . # # . . . . . . . . . . 
	0x00,0x00,	//	008A		. . . . . . . . . . . . . . . . 
	0x0F,0xFC,	//	008C		. . . . # # # # # # # # # # . . 
	0x0F,0xFC,	//	008E		. . . . # # # # # # # # # # . . 
	0x00,0x00 	//	0090		. . . . . . . . . . . . . . . . 
};


const unsigned char other_name[]=
{
	0x00,0x00,	//	0002		. . . . . . . . . . . . . . . . 
	0x1C,0x00,	//	0004		. . . # # # . . . . . . . . . . 
	0x20,0x00,	//	0006		. . # . . . . . . . . . . . . . 
	0x20,0x00,	//	0008		. . # . . . . . . . . . . . . . 
	0x20,0x00,	//	000A		. . # . . . . . . . . . . . . . 
	0x20,0x00,	//	000C		. . # . . . . . . . . . . . . . 
	0x20,0x00,	//	000E		. . # . . . . . . . . . . . . . 
	0x23,0x00,	//	0010		. . # . . . # # . . . . . . . . 
	0x24,0x80,	//	0012		. . # . . # . . # . . . . . . . 
	0x18,0x80,	//	0014		. . . # # . . . # . . . . . . . 
	0x03,0x00,	//	0016		. . . . . . # # . . . . . . . . 
	0x04,0x00,	//	0018		. . . . . # . . . . . . . . . . 
	0x08,0x00,	//	001A		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	001C		. . . . # . . . . . . . . . . . 
	0x28,0x00,	//	001E		. . # . # . . . . . . . . . . . 
	0x07,0x00,	//	0020		. . . . . # # # . . . . . . . . 
	0x00,0x00,	//	0022		. . . . . . . . . . . . . . . . 
	0x47,0x00,	//	0024		. # . . . # # # . . . . . . . . 
	0x48,0x80,	//	0026		. # . . # . . . # . . . . . . . 
	0x28,0x80,	//	0028		. . # . # . . . # . . . . . . . 
	0x1F,0x00,	//	002A		. . . # # # # # . . . . . . . . 
	0x08,0x00,	//	002C		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	002E		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	0030		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	0032		. . . . # . . . . . . . . . . . 
	0x0B,0x00,	//	0034		. . . . # . # # . . . . . . . . 
	0x04,0x90,	//	0036		. . . . . # . . # . . # . . . . 
	0x04,0x80,	//	0038		. . . . . # . . # . . . . . . . 
	0x0B,0x10,	//	003A		. . . . # . # # . . . # . . . . 
	0x08,0x00,	//	003C		. . . . # . . . . . . . . . . . 
	0x09,0x80,	//	003E		. . . . # . . # # . . . . . . . 
	0x0A,0x80,	//	0040		. . . . # . # . # . . . . . . . 
	0x04,0x80,	//	0042		. . . . . # . . # . . . . . . . 
	0x0A,0x80,	//	0044		. . . . # . # . # . . . . . . . 
	0x09,0x80,	//	0046		. . . . # . . # # . . . . . . . 
	0x08,0x00,	//	0048		. . . . # . . . . . . . . . . . 
	0x28,0x00,	//	004A		. . # . # . . . . . . . . . . . 
	0x08,0x00,	//	004C		. . . . # . . . . . . . . . . . 
	0x27,0x00,	//	004E		. . # . . # # # . . . . . . . . 
	0x00,0x00,	//	0050		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	0052		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	0054		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	0056		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	0058		. . . . . . . . . . . . . . . . 
	0x08,0x00,	//	005A		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	005C		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	005E		. . . . # . . . . . . . . . . . 
	0x08,0xC0,	//	0060		. . . . # . . . # # . . . . . . 
	0x07,0x00,	//	0062		. . . . . # # # . . . . . . . . 
	0x08,0x00,	//	0064		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	0066		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	0068		. . . . # . . . . . . . . . . . 
	0x07,0x00,	//	006A		. . . . . # # # . . . . . . . . 
	0x08,0x80,	//	006C		. . . . # . . . # . . . . . . . 
	0x08,0x80,	//	006E		. . . . # . . . # . . . . . . . 
	0x08,0x80,	//	0070		. . . . # . . . # . . . . . . . 
	0x07,0x00,	//	0072		. . . . . # # # . . . . . . . . 
	0x04,0x00,	//	0074		. . . . . # . . . . . . . . . . 
	0x08,0x00,	//	0076		. . . . # . . . . . . . . . . . 
	0x08,0x00,	//	0078		. . . . # . . . . . . . . . . . 
	0x08,0x80,	//	007A		. . . . # . . . # . . . . . . . 
	0x08,0x80,	//	007C		. . . . # . . . # . . . . . . . 
	0x04,0x80,	//	007E		. . . . . # . . # . . . . . . . 
	0x04,0x80,	//	0080		. . . . . # . . # . . . . . . . 
	0x05,0x00,	//	0082		. . . . . # . # . . . . . . . . 
	0x03,0x00,	//	0084		. . . . . . # # . . . . . . . . 
	0x01,0x00,	//	0086		. . . . . . . # . . . . . . . . 
	0x00,0x00,	//	0088		. . . . . . . . . . . . . . . . 
	0x00,0x00,	//	008A		. . . . . . . . . . . . . . . . 
	0x0F,0xF8,	//	008C		. . . . # # # # # # # # # . . . 
	0x00,0x00,	//	008E		. . . . . . . . . . . . . . . . 
	0x00,0x00 	//	0090		. . . . . . . . . . . . . . . . 
};

int fullName[name_length];
int shownName[width];
int tempStep = 0, step = 0; // the step variable declares how much the visible name is slided away
int direction = 1; // the direction of the name

void init();
void delay(int);
void fullNameToShownName();
void charachersToFullName();
void showShownName();
void slideTheName();
void reverseSlideDirection();
						
int main()
{
	// first initialization
	init();
	// import characters into fullName array
	charachersToFullName();
	// build visible name
	fullNameToShownName();
	
	while (1) {
		// display the name on dot-matrix
		showShownName();
		// slide the name on the dot-matrix, (update the value of step variable)
		slideTheName();
		// update visible name according to step and full name
		fullNameToShownName();
		// reverse direction if needed
		reverseSlideDirection();
	}
}

void init()
{
	PINSEL0 = 0x00000000; // setting all pins of port0 to GPIO
	IODIR0 = 0xFFFFFFFF; // setting port0 to Output
	IODIR0 &= ~(1 << direction_controller_pin); // but the direction pin is Input
	IODIR0 &= ~(1 << speed_control_pin); // the speed pin is also set as Input
	IODIR0 &= ~(1 << font_selector_pin); // finally, font selector pin also need to be set as Input
}

void delay(int time_length){
	for (int i = 0; i < time_length; i++)
		__nop();	
}

void charachersToFullName() {
	// import characters from MX-Coder's generated 'hex' into the fullName array
	if (IOPIN0 & (1 << font_selector_pin)){
		for (int i = 0; i < name_length; i++) {
			// we could flip the picture vertically and horizontally (in MX-Coder) instead of writing 
			// complex statement below, but we wanted easier software usage.
			fullName[name_length - 1 - i] = name[2 * i + 1] | (name[2 * i] << 8);
		}
	}
	else{
		for (int i = 0; i < name_length; i++) {
			fullName[name_length - 1 - i] = other_name[2 * i + 1] | (other_name[2 * i] << 8);
		}
	}
}

void fullNameToShownName() {
	// clear the screen
	for (int i = 0; i < width; i++) {
		shownName[i] = 0;
	}
	// copy visible part of the fullName into shownName
	for (int i = 0; i < width; i++) {
		shownName[i] = fullName[(step + i) % name_length];
		// 'step' variable is used for shifting the name
		// may wonder why the remainder sign (%) is used?
		// when showing the name, it's actually shownName[i] = fullName[i]
		// but when the full name is finished, we want to repeat it again from the first!
	}
}

void showShownName() {
	for (int i = 0; i < width; i++) {
		// clear the screen
		IOCLR0 = 0xFFFFFFFF;
		// select the i-th column(via decoder) to show the character on it
		IOSET0 = shownName[i] | (i << 16);
		
		delay(10);
	}
}

void slideTheName () {
	tempStep += direction;
	
	if (IOPIN0 & (1 << speed_control_pin)){
		if (tempStep % 5 == 0)
			step += direction;
	}
	else{
		if (tempStep % 10 == 0)
			step += direction;
	}
	
	if (step > name_length || step < -name_length) {
		// if the name is completely slided then slide it again
		// by resetting the step variable
		tempStep = 0;
		step = 0;
	}
}

void reverseSlideDirection() {
	// define the direction based on the direction controller pin
	if (IOPIN0 & (1 << direction_controller_pin)) {
		direction = to_right;
	} 
	else {
		direction = to_left;
	}
}

