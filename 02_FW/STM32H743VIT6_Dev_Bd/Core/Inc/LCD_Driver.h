/*
 * LCD_Driver.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Ganghyeok Lim
 */

#ifndef INC_LCD_DRIVER_H_
#define INC_LCD_DRIVER_H_

#include "main.h"

void Initialize_LCD(void);
void LCD_Command(uint8_t command);
void LCD_Data(uint8_t data);
void LCD_String(uint8_t command, uint8_t* string);
void LCD_Cursor(uint8_t row, uint8_t col);

#endif /* INC_LCD_DRIVER_H_ */
