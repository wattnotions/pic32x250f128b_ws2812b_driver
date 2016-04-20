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


#define LED_PIN BIT_0
#define LED_HIGH mPORTASetBits(LED_PIN);
#define LED_LOW mPORTAClearBits(LED_PIN);

void bitbangpixel(unsigned int x);
void send_rgb(char r, char g, char b);

int main() 
{
	SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    mPORTAClearBits(BIT_0);           //Clear bits to ensure the LED is off.
    mPORTASetPinsDigitalOut(BIT_0);   //Set port as output

    int j;
	int i;

    while(1)    
    {
		
        j = 200;
        for(i=0; i<4; i++) send_rgb(0,255,0);
		 
		while(j--) {}
		
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

void send_rgb(char r, char g, char b) {    //grb
	
	unsigned int grb = 0;
	
	grb = (g << 16) | (r << 8) | b ;
	
	bitbangpixel(grb);
	
}