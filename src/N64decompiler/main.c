#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "values.h"

typedef struct
{
    uint8_t memory[RAM_SIZE];
    uint32_t PC;
    bool stop;
}CPU;

void cpu_reset(CPU *cpu){
    memset(cpu->memory, 0, sizeof(cpu->memory));
    cpu->PC = 0;
    cpu->stop = false;
}

uint32_t GetMemoryValue(uint32_t x){
    if (x < RAM_SIZE) {
        x;
    }
    else{
        printf("Ram Overflow!\n");
        return 0xFFFFFFFF;
    }
}

uint32_t ReadMemoryValue(uint32_t address, CPU *cpu){
    uint32_t offset = address - RAM_MAPPING_START;

    return (cpu->memory[offset] << 24) | (cpu->memory[offset + 1] << 16) | 
    (cpu->memory[offset + 2] << 8) | cpu->memory[offset + 3];
}

void WriteMemoryValue(uint32_t adress, uint32_t value, CPU *cpu){
    uint32_t offset = adress - RAM_MAPPING_START;
    cpu->memory[offset] = (value >> 24);
    cpu->memory[offset+1] = (value >> 16);
    cpu->memory[offset+2] = (value >> 8);
    cpu->memory[offset+3] = value;
}

void Decode(CPU *cpu, uint32_t opcode);

void DecodeProg(CPU *cpu, int*prog, size_t size){
    for(int i = 0; i < size; i++){
        cpu->memory[GetMemoryValue(i)] = prog[i];
    }
    while (!cpu->stop)
    {
        Decode(cpu, cpu->memory[cpu->PC++]);
    }
    
}


int main(){
    
    return 0;
}