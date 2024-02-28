/*
 * Keypad_driver.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Ganghyeok Lim
 */

#ifndef INC_KEYPAD_DRIVER_H_
#define INC_KEYPAD_DRIVER_H_

#include "main.h"

void Keypad_Save_Value(uint8_t value);
uint8_t Keypad_Get_Value(uint8_t row, uint8_t col);
void Keypad_Row_Drive(void);




#endif /* INC_KEYPAD_DRIVER_H_ */
