// flag{s0_s3cr3t_y3t_s0_fr33}
// This course was really awesome! Great job :)

#include <stdio.h>
#include <stdlib.h>

// checks if a valid register is accessed (by testing if op < 8)
// exits if op >= 8 as it makes the instruction illegal
void check_index(unsigned char op)
{
	if(op < 8) {
		return;
	}
	else {
		printf("Illegal instruction\n%i\n", op);
		exit(-1);
	}
}

unsigned char memory[256] = {
	0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x02,0x1C,0x03,0x00,0x01,0x08,0x03,0x00,0x02,
	0x03,0x07,0x05,0x03,0x00,0x04,0x00,0x01,0x01,0x01,0x01,0x02,0x02,0x01,0x06,0x02,
	0x09,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x6d,0x73,0x68,0x6e,0x82,0x7a,0x37,0x66,0x7a,0x3a,0x6a,0x79,0x3a,0x7b,0x66,0x80,
	0x3a,0x7b,0x66,0x7a,0x37,0x66,0x6d,0x79,0x3a,0x3a,0x84,0x11,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char registers[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

int main ()
{
	int instruction_pointer = 0;
	
	while(1) {
		unsigned char op0 = memory[instruction_pointer+0];
		unsigned char op1 = memory[instruction_pointer+1];
		unsigned char op2 = memory[instruction_pointer+2];
		
		instruction_pointer += 3;

		switch(op0) {
			case 0x00:
				check_index(op1);
				registers[op1] = op2;
				break;
			case 0x01:
				check_index(op1);
				registers[op1] += op2;
				break;
			case 0x02:
				check_index(op1);
				registers[op1] -= op2;
				break;
			case 0x03:
				check_index(op1);
				check_index(op2);
				registers[op1] += registers[op2];
				break;
			case 0x04:
				check_index(op1);
				check_index(op2);
				registers[op1] -= registers[op2];
				break;
			case 0x05:
				check_index(op1);
				printf("%c", registers[op1]);
				break;
			case 0x06:
				check_index(op1);
				if (registers[op1] != 0) {
					instruction_pointer = op2;
				}
				break;
			case 0x07:
				check_index(op1);
				if (registers[op1] == 0) {
					instruction_pointer = op2;
				}
				break;
			case 0x08:
				check_index(op1);
				check_index(op2);
				registers[op1] = memory[registers[op2]];
				break;
			case 0x09:
				check_index(op1);
				check_index(op2);
				memory[registers[op2]] = registers[op1];
				break;
			case 0xff:
				exit(0);
			default:
				printf("Illegal instruction\n");
				return -1;
		}
	}

	return 0;
}