/*
 * LCD_Driver.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Ganghyeok Lim
 */


#include "LCD_Driver.h"

void Initialize_LCD(void)
{
    // 1. Wait for 100us
    HAL_Delay(100);

    // 2. Set GPIO Pin Output of LCD to LOW
    HAL_GPIO_WritePin(MCU_CHAR_LCD_RW_GPIO_Port, MCU_CHAR_LCD_RW_Pin, LOW);		// Write mode
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_RS_GPIO_Port, MCU_CHAR_LCD_RS_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA0_GPIO_Port, MCU_CHAR_LCD_DATA0_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA1_GPIO_Port, MCU_CHAR_LCD_DATA1_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA2_GPIO_Port, MCU_CHAR_LCD_DATA2_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA3_GPIO_Port, MCU_CHAR_LCD_DATA3_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA4_GPIO_Port, MCU_CHAR_LCD_DATA4_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA5_GPIO_Port, MCU_CHAR_LCD_DATA5_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA6_GPIO_Port, MCU_CHAR_LCD_DATA6_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA7_GPIO_Port, MCU_CHAR_LCD_DATA7_Pin, LOW);

    // 3. Function Set (8bit, 2 Line, 5x7 dot)
    LCD_Command(0x38);

    // 4. Display Control (Display ON, Cursor OFF)
    LCD_Command(0x0C);

    // 5. Entry Mode Set (Increment, Not Shift)
    LCD_Command(0x06);

    // 6. Clear Display
    LCD_Command(0x01);
    HAL_Delay(2);
}

void LCD_Command(uint8_t command)
{
    // 1. E = 0, RS = 0
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_RS_GPIO_Port, MCU_CHAR_LCD_RS_Pin, LOW);
    Delay_us(1);

    // 2. Write Command
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA0_GPIO_Port, MCU_CHAR_LCD_DATA0_Pin, (command & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA1_GPIO_Port, MCU_CHAR_LCD_DATA1_Pin, ((command >> 1) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA2_GPIO_Port, MCU_CHAR_LCD_DATA2_Pin, ((command >> 2) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA3_GPIO_Port, MCU_CHAR_LCD_DATA3_Pin, ((command >> 3) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA4_GPIO_Port, MCU_CHAR_LCD_DATA4_Pin, ((command >> 4) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA5_GPIO_Port, MCU_CHAR_LCD_DATA5_Pin, ((command >> 5) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA6_GPIO_Port, MCU_CHAR_LCD_DATA6_Pin, ((command >> 6) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA7_GPIO_Port, MCU_CHAR_LCD_DATA7_Pin, ((command >> 7) & 0x01));
    Delay_us(1);

    // 3. E = 1
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, HIGH);

    // 4. Wait for 1us
    Delay_us(1);

    // 5. E = 0
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, LOW);

    // 6. Wait for 50us
    Delay_us(50);
}


void LCD_Data(uint8_t data)
{
    // 1. E = 0, RS = 1
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, LOW);
    HAL_GPIO_WritePin(MCU_CHAR_LCD_RS_GPIO_Port, MCU_CHAR_LCD_RS_Pin, HIGH);
    Delay_us(1);

    // 2. Write Command
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA0_GPIO_Port, MCU_CHAR_LCD_DATA0_Pin, (data & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA1_GPIO_Port, MCU_CHAR_LCD_DATA1_Pin, ((data >> 1) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA2_GPIO_Port, MCU_CHAR_LCD_DATA2_Pin, ((data >> 2) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA3_GPIO_Port, MCU_CHAR_LCD_DATA3_Pin, ((data >> 3) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA4_GPIO_Port, MCU_CHAR_LCD_DATA4_Pin, ((data >> 4) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA5_GPIO_Port, MCU_CHAR_LCD_DATA5_Pin, ((data >> 5) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA6_GPIO_Port, MCU_CHAR_LCD_DATA6_Pin, ((data >> 6) & 0x01));
    HAL_GPIO_WritePin(MCU_CHAR_LCD_DATA7_GPIO_Port, MCU_CHAR_LCD_DATA7_Pin, ((data >> 7) & 0x01));
    Delay_us(1);

    // 3. E = 1
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, HIGH);

    // 4. Wait for 1us
    Delay_us(1);

    // 5. E = 0
    HAL_GPIO_WritePin(MCU_CHAR_LCD_E_GPIO_Port, MCU_CHAR_LCD_E_Pin, LOW);

    // 6. Wait for 50us
    Delay_us(50);
}


void LCD_String(uint8_t command, uint8_t* string)
{
    LCD_Command(command);

    while(*string != '\0')
    {
        LCD_Data(*string);
        string++;
    }
}


void LCD_Cursor(uint8_t row, uint8_t col)
{
	uint8_t temp;

	if(row == 1)
	{
		temp = 0x80 + (col-1);
		LCD_Command(temp);
	}
	else if(row == 2)
	{
		temp = 0xC0 + (col-1);
		LCD_Command(temp);
	}
}
