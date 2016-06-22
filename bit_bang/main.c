#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define SYS_FREQ 80000000
#include <plib.h>


#pragma config   JTAGEN    = OFF    // JTAG Enable OFF
#pragma config   FNOSC     = FRCPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_2  // PLL in 8mHz/2 = 4mHz
#pragma config   FPLLMUL   = MUL_20 // PLL mul 4mHz * 20 = 80mHz 24??
#pragma config   FPLLODIV  = DIV_2  // PLL Out 8mHz/2= 4 mHz system frequency osc
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = OFF    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog


#define LED_PIN BIT_13
#define LED_HIGH mPORTBSetBits(LED_PIN);
#define LED_LOW mPORTBClearBits(LED_PIN);

void bitbangpixel(unsigned int x);
void send_rgb(unsigned int r, unsigned int g, unsigned int b);

int main() 
{
	SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    mPORTBClearBits(BIT_13);           //Clear bits to ensure the LED is off.
    mPORTBSetPinsDigitalOut(BIT_13);   //Set port as output

    int j;
	int i;

    while(1)    
    {
		
        j = 200;
        for(i=0; i<120; i++) send_rgb(0,0,50);
		 
		while(j--) {}   //50us delay for latch
		
    }
}

void bitbangpixel(unsigned int x) {
	
    char i = 24;

    do {
        if ((x >> --i) & 1) {
            LED_HIGH
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
			Nop();
            Nop();
            Nop();
            Nop();
            Nop();
			Nop();
            Nop();
            Nop();
            Nop();
            Nop();
			Nop();
            Nop();
            Nop();
            Nop();
            Nop();
			Nop();
			Nop();
            LED_LOW
        } else {
            LED_HIGH
            Nop();
            Nop();
			Nop();
            Nop();
			Nop();
			Nop();
            Nop();
			Nop();
            Nop();
			Nop();
            LED_LOW
            Nop();
            Nop();
            Nop();
            Nop();
			Nop();
            Nop();
            Nop();
            Nop();
			Nop();
            Nop();
            Nop();
            Nop();
        }
    } while (i > 0);
}

void send_rgb(unsigned int r, unsigned int g, unsigned int b) {    //grb
	
	unsigned int grb = 0;
	
	g = g << 16;
	r = r << 8;
	
	
	grb = g | r | b;
	
	bitbangpixel(grb);
	
}

unsigned long getRainbow()
{   // Cycle through the colours of the rainbow (non-uniform brightness however)
	// Inspired by : http://academe.co.uk/2012/04/arduino-cycling-through-colours-of-the-rainbow/
	static unsigned Red = 255;
	static unsigned Green = 0;
	static unsigned Blue = 0;
	static int State = 0;
	switch (State)
	{
		case 0:{
			Green++;
			if (Green == 255)
				State = 1;
			break;
		}
		case 1:{
			Red--;
			if (Red == 0)
				State = 2;
			break;
		}
		case 2:{
			Blue++;
			if (Blue == 255)
				State = 3;			
			break;
		}
		case 3:{
			Green--;
			if (Green == 0)
				State = 4;
			break;
		}
		case 4:{
			Red++;
			if (Red == 255)
				State = 5;
			break;
		}
		case 5:{
			Blue --;
			if (Blue == 0)
				State = 0;
			break;
		}		
	}
	return (Green << 16) + (Red << 8) + Blue;
}