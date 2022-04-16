// Copyright (c) 2018 Rudá Moura <ruda.moura@gmail.com>
// License: The MIT License (MIT)

#include "mcp23017.h"

#define I2C_TIMEOUT		10

void mcp23017_init(MCP23017_HandleTypeDef *hdev, I2C_HandleTypeDef *hi2c, uint16_t addr)
{
	hdev->hi2c = hi2c;
	hdev->addr = addr << 1; // tested using logan
	// hdev->addr = addr;
}

HAL_StatusTypeDef mcp23017_read(MCP23017_HandleTypeDef *hdev, uint16_t reg, uint8_t *data)
{
	return HAL_I2C_Mem_Read(hdev->hi2c, hdev->addr, reg, 1, data, 1, I2C_TIMEOUT);
}

HAL_StatusTypeDef mcp23017_write(MCP23017_HandleTypeDef *hdev, uint16_t reg, uint8_t *data)
{
	return HAL_I2C_Mem_Write(hdev->hi2c, hdev->addr, reg, 1, data, 1, I2C_TIMEOUT);
}

HAL_StatusTypeDef mcp23017_iodir(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t iodir)
{
	uint8_t data[1] = {iodir};
	return mcp23017_write(hdev, MCP23017_REGISTER_IODIRA|port, data);
}

HAL_StatusTypeDef mcp23017_ipol(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t ipol)
{
	uint8_t data[1] = {ipol};
	return mcp23017_write(hdev, MCP23017_REGISTER_IPOLA|port, data);
}

HAL_StatusTypeDef mcp23017_ggpu(MCP23017_HandleTypeDef *hdev, uint8_t port, uint8_t pu)
{
	uint8_t data[1] = {pu};
	return mcp23017_write(hdev, MCP23017_REGISTER_GPPUA|port, data);
}

HAL_StatusTypeDef mcp23017_read_gpio(MCP23017_HandleTypeDef *hdev, uint8_t port)
{
	uint8_t data[1];
	HAL_StatusTypeDef status;
	status = mcp23017_read(hdev, MCP23017_REGISTER_GPIOA|port, data);
	if (status == HAL_OK)
		hdev->gpio[port] = data[0];
	return status;
}

HAL_StatusTypeDef mcp23017_write_gpio(MCP23017_HandleTypeDef *hdev, uint8_t port)
{
	uint8_t data[1] = {hdev->gpio[port]};
	return mcp23017_write(hdev, MCP23017_REGISTER_GPIOA|port, data);
}
