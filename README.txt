MCP23017 library for STM32.

Library to use MCP23017 I/O Expander chip with STM32 via i2c interface.


	       .---------.
	GPB0<->|1  \_/ 28|<->GPA7
	GPB1<->|         |<->GPA6
	GPB2<->|    M    |<->GPA5
	GPB3<->|    C    |<->GPA4
	GPB4<->|    P    |<->GPA3
	GPB5<->|    2    |<->GPA2
	GPB6<->|    3    |<->GPA1
	GPB7<->|    0    |<->GPA0
	 VDD-->|    1    |-->INTA
	 VSS-->|    7    |-->INTB
	  NC---|         |-->~RESET
	 SCL-->|         |<--A2
	 SDA<->|         |<--A1
	  NC---|14     15|<--A0
	       '---------'


Example: Read bits from GPA then copy bits to GPB.

#include "mcp23017.h"

MCP23017_HandleTypeDef hmcp;

mcp23017_init(&hmcp, &hi2c1, MCP23017_ADDRESS_20);
mcp23017_iodir(&hmcp, MCP23017_PORTA, MCP23017_IODIR_ALL_INPUT);
mcp23017_iodir(&hmcp, MCP23017_PORTB, MCP23017_IODIR_ALL_OUTPUT);

while (1) {
	mcp23017_read_gpio(&hmcp, MCP23017_PORTA);
	hmcp.gpio[MCP23017_PORTB] = hmcp.gpio[MCP23017_PORTA];
	mcp23017_write_gpio(&hmcp, MCP23017_PORTB);
}
