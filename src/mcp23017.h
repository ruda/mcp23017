// Copyright (c) 2018 Rudá Moura <ruda.moura@gmail.com>
// License: The MIT License (MIT)

#if defined(STM32F103xB)
# include "stm32f1xx_hal.h"
#endif

#if defined(STM32F401xC)
# include "stm32f4xx_hal.h"
#endif

#if defined(STM32F407xx)
# include "stm32f4xx_hal.h"
#endif

#if defined(STM32H750xx)
# include "stm32h7xx_hal.h"
#endif

// Ports
#define MCP23017_PORTA			0x00
#define MCP23017_PORTB			0x01

// Registers
#define MCP23017_REGISTER_IODIRA	0x00
#define MCP23017_REGISTER_IODIRB	0x01
#define MCP23017_REGISTER_IPOLA		0x02
#define MCP23017_REGISTER_IPOLB		0x03
#define MCP23017_REGISTER_GPINTENA	0x04
#define MCP23017_REGISTER_GPINTENB	0x05
#define MCP23017_REGISTER_DEFVALA	0x06
#define MCP23017_REGISTER_DEFVALB	0x07
#define MCP23017_REGISTER_INTCONA	0x08
#define MCP23017_REGISTER_INTCONB	0x09
#define MCP23017_REGISTER_IOCON     0x0A

//	IOCON			0x0A
//	IOCON			0x0B
#define MCP23017_REGISTER_GPPUA		0x0C
#define MCP23017_REGISTER_GPPUB		0x0D
#define MCP23017_REGISTER_INTFA		0x0E
#define MCP23017_REGISTER_INTFB		0x0F
#define MCP23017_REGISTER_INTCAPA	0x10
#define MCP23017_REGISTER_INTCAPB	0x11
#define MCP23017_REGISTER_GPIOA		0x12
#define MCP23017_REGISTER_GPIOB		0x13
#define MCP23017_REGISTER_OLATA		0x14
#define MCP23017_REGISTER_OLATB		0x15

// Address (A0-A2)
#define MCP23017_ADDRESS_20		0x20
#define MCP23017_ADDRESS_21		0x21
#define MCP23017_ADDRESS_22		0x22
#define MCP23017_ADDRESS_23		0x23
#define MCP23017_ADDRESS_24		0x24
#define MCP23017_ADDRESS_25		0x25
#define MCP23017_ADDRESS_26		0x26
#define MCP23017_ADDRESS_27		0x27

// I/O Direction
// Default state: MCP23017_IODIR_ALL_INPUT
#define MCP23017_IODIR_ALL_OUTPUT	0x00
#define MCP23017_IODIR_ALL_INPUT	0xFF
#define MCP23017_IODIR_IO0_INPUT	0x01
#define MCP23017_IODIR_IO1_INPUT	0x02
#define MCP23017_IODIR_IO2_INPUT	0x04
#define MCP23017_IODIR_IO3_INPUT	0x08
#define MCP23017_IODIR_IO4_INPUT	0x10
#define MCP23017_IODIR_IO5_INPUT	0x20
#define MCP23017_IODIR_IO6_INPUT	0x40
#define MCP23017_IODIR_IO7_INPUT	0x80

// Input Polarity
// Default state: MCP23017_IPOL_ALL_NORMAL
#define MCP23017_IPOL_ALL_NORMAL	0x00
#define MCP23017_IPOL_ALL_INVERTED	0xFF
#define MCP23017_IPOL_IO0_INVERTED	0x01
#define MCP23017_IPOL_IO1_INVERTED	0x02
#define MCP23017_IPOL_IO2_INVERTED	0x04
#define MCP23017_IPOL_IO3_INVERTED	0x08
#define MCP23017_IPOL_IO4_INVERTED	0x10
#define MCP23017_IPOL_IO5_INVERTED	0x20
#define MCP23017_IPOL_IO6_INVERTED	0x40
#define MCP23017_IPOL_IO7_INVERTED	0x80

// Pull-Up Resistor
// Default state: MCP23017_GPPU_ALL_DISABLED
#define MCP23017_GPPU_ALL_DISABLED	0x00
#define MCP23017_GPPU_ALL_ENABLED	0xFF
#define MCP23017_GPPU_IO0_ENABLED	0x01
#define MCP23017_GPPU_IO1_ENABLED	0x02
#define MCP23017_GPPU_IO2_ENABLED	0x04
#define MCP23017_GPPU_IO3_ENABLED	0x08
#define MCP23017_GPPU_IO4_ENABLED	0x10
#define MCP23017_GPPU_IO5_ENABLED	0x20
#define MCP23017_GPPU_IO6_ENABLED	0x40
#define MCP23017_GPPU_IO7_ENABLED	0x80

typedef struct {
	I2C_HandleTypeDef*	hi2c;
	uint16_t		addr;
	uint8_t			gpio[2];
} MCP23017_HandleTypeDef;

void    		mcp23017_init(MCP23017_HandleTypeDef *hdev, I2C_HandleTypeDef *hi2c, uint16_t addr);
HAL_StatusTypeDef	mcp23017_read(MCP23017_HandleTypeDef *hdev, uint16_t reg, uint8_t *data);
HAL_StatusTypeDef	mcp23017_write(MCP23017_HandleTypeDef *hdev, uint16_t reg, uint8_t *data);
HAL_StatusTypeDef	mcp23017_iodir(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t iodir);
HAL_StatusTypeDef	mcp23017_ipol(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t ipol);
HAL_StatusTypeDef	mcp23017_ggpu(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t pu);
HAL_StatusTypeDef	mcp23017_read_gpio(MCP23017_HandleTypeDef *hdev, uint8_t port); // port index [0,1] or MCP23017_PORTA/MCP23017_PORTB
HAL_StatusTypeDef	mcp23017_write_gpio(MCP23017_HandleTypeDef *hdev, uint8_t port);
