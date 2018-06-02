#include <iostream>
#include <stdint.h>
using namespace std;

// Register structure
struct Reg {
    //register clock or some shit
    int m;
    int t;
    //8-bit registers
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint8_t f;
    //16-bit registers
    uint16_t pc;
    uint16_t sp;
};

//Clock Structure
struct Clock {
    //Internal State
    //clock
    int m;
    int t;
};

struct CPU {
    Reg r;
    Clock c;
};

//Memory managedment functions
int readByte(uint16_t addr) { return 1; } //Read 8-bit byte from an address
int readWord(uint16_t addr) { return 1; } //Read 16-bit word from address
int writeByte(uint16_t addr, int val) { return 1; } //Write 8-bit byte to address
int writeWord(uint16_t addr, int val) { return 1; } //Write 16-bit word to address

//Reset registers to 0
void reset(Reg* reg) {
    reg->m = 0;
    reg->t = 0;
    reg->a = 0;
    reg->b = 0;
    reg->c = 0;
    reg->d = 0;
    reg->e = 0;
    reg->h = 0;
    reg->l = 0;
    reg->f = 0;
    reg->pc = 0;
    reg->sp = 0;
    std::cout << "Finished reseting registers" << std::endl;
}

void dispatcher(Reg* r) {
    int op = readByte(r->pc++);
    switch(op) {
        case 0x00: break;
        case 0xE1:      //POPHL
            r->l = readByte(r->sp);
            r->sp++;
            r->h = readByte(r->sp);
            r->sp++;
            r->m = 3; r->t =12;
		case 0x
    }
}

int main() {
    Clock c;
    Reg reg;
    reg.a = 6;
    std::cout << (unsigned)reg.a << std::endl;
    reset(&reg);
    std::cout << (unsigned)reg.a << std::endl;
    return 0;
}
