/******************************************
*
*	File: Program Interface Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

// ADMIN PASSWORD
#define ADMIN_PASS 1234

// DEFINES
#define NO 0
#define YES 1

// PROGRAM FUNCTIONS PROTOTYPES
void Main_Interface(void);
u8 Admin_Check(u16 PASS);
u8 Admin_Interface(u8 Is_Admin_Open);
u8 User_Interface(void);

#endif