#include <xboxrt/debug.h>
#include <pbkit/pbkit.h>
#include <hal/xbox.h>
#include "stdio.h"

void main(void)
{
    int i;

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
        XSleep(1500);
        debugPrint("proudly presented by DaveX ;)\n\n");
        XSleep(1500);
        debugPrint("make sure to run Xqemu with: -soundhw pcspk\n");
        debugPrint("e.g. ./qemu-system-xbox -soundhw pcspk -machine xbox, [...]\nor\n");
        debugPrint("./qemu-system-i386 -soundhw pcspk -cpu pentium3  [...]\n\n");
        XSleep(1700);
        debugPrint("get ready!\n");
        XSleep(2002);

      /*
        assembled with:  https://defuse.ca/online-x86-assembler.htm#disassembly

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

        // </asm code>

*/
             

         char Beep[] = "\x66\xB8\xB8\x01\xE8\x13\x00\x00\x00\x66\x31\xC0\xCD\x16\xE8\x02\x00\x00\x00\xCD\x20\xE4\x61\x24\xFC\xE6\x61\xC3\x66\x89\xC3\x66\xBA\x12\x00\x66\xB8\xDC\x34\x66\xF7\xF3\x88\xC3\xB0\xB6\xE6\x43\x88\xD8\xE6\x42\x88\xE0\xE6\x42\xE4\x61\x0C\x03\xE6\x61\xC3";
                     
      void(*beep)();
      beep = (void(*)()) Beep;
      // (void)(*beep)();
      beep();       
      //dead code now below!

      XSleep(2000);

    }

    pb_kill();
    XReboot();
}
