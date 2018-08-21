#include <xboxrt/debug.h>
#include <pbkit/pbkit.h>
#include <hal/xbox.h>
#include "stdio.h"

#define delayAfterBeep 100

void beep(int freq, int duration) // freq in [hz], duration in [ms]
{
   register int reg_ax asm ("ax");
   reg_ax = freq;  

   asm("mov %ax,%bx");
   asm("mov $0x12,%dx");
   asm("mov $0x34dc,%ax");
   asm("div %bx");
   asm("mov %al,%bl");
   asm("mov $0xb6,%al");
   asm("out %al,$0x43");
   asm("mov %bl,%al");
   asm("out %al,$0x42");
   asm("mov %ah,%al");
 
   asm("out %al,$0x42");
   asm("in $0x62,%al");
   asm("or $0x3,%al");
   asm("out %al,$0x61");
   asm("xor %ax,%ax");

   XSleep(duration);
   asm("in $0x61,%al");
   asm("and $0xfc,%al");
   asm("out %al,$0x61");

   XSleep(delayAfterBeep);
}


void main(void)
{

    switch(pb_init())
    {
        case 0: break;
        default:
            XSleep(2000);
            XReboot();
            return;
    }

    pb_show_debug_screen();

    while(1) {
        XSleep(500);
        debugPrint("thx JayFoxRox!\n\n");
        XSleep(1100);
        debugPrint("proudly presented by DaveX ;)\n\n");
        XSleep(1100);
        debugPrint("if run in Xqemu make sure to use: -soundhw pcspk\n");
        debugPrint("e.g. ./qemu-system-xbox -soundhw pcspk -machine xbox, [...]\nor\n");
        debugPrint("./qemu-system-i386 -soundhw pcspk -cpu pentium3  [...]\n\n");
        XSleep(1100);
        debugPrint("get ready!\n");
        XSleep(1002);


	beep(440,100);
	XSleep(700);

	beep(222,600);
	XSleep(300);

	beep(111,2200);
	XSleep(700);

	beep(440,200);
	XSleep(700);

	debugPrint("now => \n");
	XSleep(700);


	beep(659,406);
	beep(494,203);
	beep(523,203);
	beep(587,406);
	beep(523,203);
	beep(494,203);
	beep(440,406);
	beep(440,203);
	beep(523,203);
	beep(659,406);
	beep(587,203);
	beep(523,203);
	beep(494,609);
	beep(523,203);
	beep(587,406);
	beep(659,406);
	beep(523,406);
	beep(440,406);
	beep(440,203);
	beep(440,203);
	beep(494,203);
	beep(523,203);
	beep(587,609);
	beep(698,203);
	beep(880,406);
	beep(784,203);
	beep(698,203);
	beep(659,609);
	beep(523,203);
	beep(659,406);
	beep(587,203);
	beep(523,203);
	beep(494,406);
	beep(494,203);
	beep(523,203);
	beep(587,406);
	beep(659,406);
	beep(523,406);
	beep(440,406);
	beep(440,406);

        XSleep(1953);

	/* Imp March
	   stolen from (/thx at) https://gist.github.com/tagliati/1804108
	*/
    
	beep(440, 500); 
	beep(440, 500);     
	beep(440, 500); 
	beep(349, 350); 
	beep(523, 150);

	beep(440, 500);
	beep(349, 350);
	beep(523, 150);
	beep(440, 1000);
	//first bit

	beep(659, 500);
	beep(659, 500);
	beep(659, 500);    
	beep(698, 350); 
	beep(523, 150);

	beep(415, 500);
	beep(349, 350);
	beep(523, 150);
	beep(440, 1000);
	//second bit...

	beep(880, 500);
	beep(440, 350); 
	beep(440, 150);
	beep(880, 500);
	beep(830, 250); 
	beep(784, 250);

	beep(740, 125);
	beep(698, 125);    
	beep(740, 250);
	XSleep(250);
	beep(455, 250);    
	beep(622, 500);  
	beep(587, 250);  
	beep(466, 250);  
	//start of the interesting bit

	beep(523, 125);  
	beep(466, 125);  
	beep(523, 250);      
	XSleep(250);
	beep(349, 125);  
	beep(415, 500);  
	beep(349, 375);  
	beep(440, 125); 

	beep(523, 500); 
	beep(440, 375);  
	beep(523, 125); 
	beep(659, 1000); 
	//more interesting stuff (this doesn't quite get it right somehow)

	beep(880, 500);
	beep(440, 350); 
	beep(440, 150);
	beep(880, 500);
	beep(830, 250); 
	beep(784, 250);

	beep(740, 125);
	beep(698, 125);    
	beep(740, 250);
	XSleep(250);
	beep(455, 250);    
	beep(622, 500);  
	beep(587, 250);  
	beep(466, 250);  
	//repeat... repeat

	beep(523, 125);  
	beep(466, 125);  
	beep(523, 250);      
	XSleep(250);
	beep(349, 250);  
	beep(415, 500);  
	beep(349, 375);  
	beep(523, 125); 
	   
	beep(440, 500);            
	beep(349, 375);            
	beep(261, 125);            
	beep(440, 1000);       
	//and we're done \ó/ 
        // end March



	XSleep(1776);
        debugPrint("thx bb :)\n");


      XSleep(7887);

    }

    pb_kill();
    XReboot();
}



 /*  CREDIZ
        from user "Matrix" https://board.flatassembler.net/topic.php?t=1813

        // <asm code>
	mov ax,440
	call sound
	xor ax,ax
	int 22
	call nosound
	int 32


	nosound:
	in al,0x61
	and al,0xFC;
	out 0x61,al
	ret

	sound:
	mov bx,ax
	mov dx,0x12
	mov ax,0x34DC
	div bx
	mov bl,al
	mov al,0xB6
	out 0x43,al
	mov al,bl
	out 0x42,al
	mov al,ah
	out 0x42,al
	in al,0x61
	or al,3
	out 0x61,al
	ret
      */
