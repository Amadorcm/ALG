




#include <stdio.h>
#include <dos.h>
#include <string.h>
#define BYTE unsigned char


BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

int colortexto, colorback;
int i=0;
BYTE color;

/**
 textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
 **/
void textcolor(unsigned char color){
    union REGS regs;
    regs.h.ah = 0x0F;
    regs.h.bh = 0;
    regs.h.bl = color;
    int86(0x10, &regs, &regs)
}
/**
 textbackground(): modifica el color de fondo con que se mostrarán los caracteres
 **/
void textbackground(int color){
    colorback=color;
}

void cputchar(char c){
    union REGS inregs, outregs;
    color=colorback << 4 | colortexto;
    inregs.h.ah = 2;
    inregs.h.bl = color;
    inregs.h.dl = c;
    int86(0x21, &inregs, &outregs);
}


/**
 mi_printf(): saca por pantalla utilizando cputchar() una cadena de caracteres
 **/
void mi_printf(char *str){
    printf("\n");
    
    for(i; i<strlen(str); i++){
        cputchar(str[i]);
    }
    i=0;
}
/**
 main(): funcion principal deonde probamos todas las funciones
 **/
int main(){
    
    
    textcolor(0x02);
    mi_printf("Color de texto cambiado");
    textbackground(0x03);
    mi_printf("Color de fondo cambiado");
   
    
    
    return 0;
}
