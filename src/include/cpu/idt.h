#ifndef _CPU_IDT_H
#define _CPU_IDT_H

#include "../utypes.h"

#define KERNEL_CS 0x08

typedef struct {
    uint16 low_offset; 
    uint16 sel; 
    uint8 always0;
  
    uint8 flags; 
    uint16 high_offset; 
} __attribute__((packed)) idt_gate_t ;

typedef struct {
    uint16 limit;
    uint32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, uint32 handler);
void set_idt();

#endif 
