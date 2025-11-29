#include <stdio.h>
#include <string.h>
#include <stdint.h>

// --- CPU Definition ---
typedef struct {
    uint8_t A;           // accumulator
    uint8_t B;           // second register
    uint8_t PC;          // program counter
    uint8_t memory[256]; // RAM
    uint8_t halted;      // 0 = running, 1 = stop
} CPU;

// --- Reset CPU ---
void cpu_reset(CPU *cpu) {
    cpu->A = 0;
    cpu->B = 0;
    cpu->PC = 0;
    cpu->halted = 0;
    memset(cpu->memory, 0, sizeof(cpu->memory));
}

// --- Load Program ---
void cpu_load(CPU *cpu, uint8_t *prog, size_t size) {
    for (size_t i = 0; i < size; i++)
        cpu->memory[i] = prog[i];
}

// --- Execute Single Instruction ---
void cpu_execute(CPU *cpu, uint8_t opcode) {
    switch (opcode) {
        case 0x01: // LDA imm
            cpu->A = cpu->memory[cpu->PC++];
            break;
        case 0x02: // LDB imm
            cpu->B = cpu->memory[cpu->PC++];
            break;
        case 0x03: // ADD A + B → A
            cpu->A = cpu->A + cpu->B;
            break;
        case 0x04: { // STA addr
            uint8_t addr = cpu->memory[cpu->PC++];
            cpu->memory[addr] = cpu->A;
            break;
        }
        case 0x05: { // JMP addr
            uint8_t addr = cpu->memory[cpu->PC++];
            cpu->PC = addr;
            break;
        }
        case 0xFF: // HLT
            cpu->halted = 1;
            break;
        default:
            printf("Unknown opcode %02X at PC=%d\n", opcode, cpu->PC-1);
            cpu->halted = 1;
    }
}

// --- Run CPU ---
void cpu_run(CPU *cpu) {
    while (!cpu->halted) {
        uint8_t opcode = cpu->memory[cpu->PC++];
        cpu_execute(cpu, opcode);
    }
}

// --- Main Program ---
int main() {
    CPU cpu;
    cpu_reset(&cpu);

    // Tiny program:
    // LDA 10 ; B = 5 ; ADD ; STA 0x80 ; HLT
    uint8_t program[] = {
        0x01, 0x0A, // LDA 10
        0x02, 0x05, // LDB 5
        0x03,       // ADD (A = A + B)
        0x04, 0x80, // STA 0x80
        0xFF        // HLT
    };

    cpu_load(&cpu, program, sizeof(program));
    cpu_run(&cpu);

    printf("A = %d\n", cpu.A);
    printf("B = %d\n", cpu.B);
    printf("Memory[0x80] = %d\n", cpu.memory[0x80]);

    return 0;
}
