/******************************************
*
*	File: Program Errors Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"

#ifndef _ERRORS_H_
#define _ERRORS_H_

// DEFINES
#define MODE_ERROR 0
#define ADMIN_WRONG_PASS 1
#define EMPTY_PATIENT_LIST 2
#define PATIENT_NOT_FOUND 3
#define PATIENT_IN_RESERVATION 4
#define UNKNOWN 100

// ERROR FUNCTION PROTOTYPE
void Error(u8 Error);

#endif