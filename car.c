/* 
 * File:   car.c
 * Author: Itsarthurbih
 *
 * Created on August 4, 2022, 5:54 PM
 */
// Github repository created 8/13/2022
// Current state: buttons and pic installed. currently using a pn2222 transistor in between the pic and the motor. 
// Notice that the transistor is not amplifying enough current, so I will be using an optocoupler with a larger voltage source of 9v for the motor part of the car.
// Will still be using a 5v source for the pic and buttons associated with the car.
// Also thinking about adding an interrupt for an emergency stop function of the car. 

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#define Wheel1 PORTBbits.RB4
#define Wheel2 PORTAbits.RA3
#define Wheel3 PORTDbits.RD4
#define Wheel4 PORTCbits.RC0
#define Switch1 PORTBbits.RB0
#define Switch2 PORTAbits.RA7
#define Switch3 PORTDbits.RD3
#define Switch4 PORTCbits.RC3





/*
 * 
 */
int main ()
{
    
    ADCON1 = 0x0f;
    TRISAbits.RA7 = 0xff;
    TRISBbits.RB0 = 0xff;
    TRISCbits.RC3 = 0xff;
    TRISDbits.RD3 = 0xff;
    

    TRISAbits.RA3 = 0x00;
    TRISBbits.RB4 = 0x00;
    TRISCbits.RC0 = 0x00;
    TRISDbits.RD4 = 0x00;
    
    while (1)
    {
        if (Switch1 == 0)
        { 
            Wheel1 = 1;
            
        }
        else if (Switch1 == 1)
        {
            Wheel1 = 0;
        }
        if (Switch2 == 0)
        {
            Wheel2 = 1;
        }
        else if (Switch2 == 1)
        {
            Wheel2 = 0;
        }
        if (Switch3 == 0)
        {
            Wheel3 = 1;
            
        }
        else if (Switch3 == 1)
        {
            Wheel3 = 0;
        }
        
        if (Switch4 == 0)
        {
            Wheel4 = 1;
            
        }
        else if (Switch4 == 1)
        {
            Wheel4 =0;
        }
    }
    
    return (EXIT_SUCCESS);
    
    
       
}

