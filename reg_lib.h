


#include <stdlib.h>
#include <stdio.h>


#define MSB_MASK 0xFF000000
#define MASK_B3  0x00FF0000
#define MASK_B2  0x0000FF00
#define LSB_MASK 0x000000FF


typedef struct Register
{


    int registerValue;

    // The actual bytes of the 32-bit register
    int byteFour; // MSB
    int byteThree;
    int byteTwo;
    int byteOne; // LSB

    // The representation of the common assembly registers
    int eax;
    int ax;
    int ah;
    int al;

    // 32 Bit Operations
    void movl(int val);
    void addl(int val);
    void subl(int val);


    // Utility Functions 
    void updateRegisters(void);
    void updateBytes(void);
    void updateAll(void);

    
} Register;


void Register::updateRegisters(void)
{

    eax = ((byteFour << 24) | (byteThree << 16) | (byteTwo << 8) | byteOne);
    ax = ((byteFour << 8) | (byteThree));
    ah = byteTwo;
    al = byteOne;

    return;
}

void Register::updateBytes(void)
{

    byteOne = (registerValue & LSB_MASK);
    byteTwo = (registerValue & MASK_B2) >> 8;
    byteThree = (registerValue & MASK_B3) >> 16;
    byteFour = (registerValue & MSB_MASK) >> 24;

    return;
}

void Register::updateAll(void)
{

    updateBytes();
    updateRegisters();

    return;
}


void Register::movl(int val)
{

    registerValue = val;
    updateAll();
}

void Register::addl(int val)
{

    registerValue += val;
    updateAll();
}


void Register::subl(int val)
{
    registerValue -= val;
    updateAll();
}





