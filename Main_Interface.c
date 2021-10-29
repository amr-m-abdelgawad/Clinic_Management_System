/******************************************
*
*	File: Program Main Interface Function
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include <stdio.h>
#include <unistd.h>
#include "STD_Types.h"
#include "Interface.h"
#include "Errors.h"

#define ADMIN_MODE 0
#define USER_MODE 1
#define MAIN_INTERFACE_PROGRAM_EXIT 2

// MAIN INTERFACE
void Main_Interface(void)
{
	system("cls");
	u8 Mode, Is_Admin_Open, Is_Back;

	// MAIN INTERFACE MODE
	printf("-----------\nClinic Management System\n-----------\n-If you want: Admin Mode, press 0\n-If you want: User Mode, press 1\n-If you want: Exit, press 2\nEnter a number: ");
	scanf("%d", &Mode);

	// ADMIN MODE
	if (Mode == ADMIN_MODE)
	{
		Is_Back = NO;

		// CHECK IF USER ENTERED THE ADMIN PASSWORD RIGHT
		Is_Admin_Open = Admin_Check(ADMIN_PASS);

		// ADMIN INTERFACE
		while (1)
		{
			Is_Back = Admin_Interface(Is_Admin_Open);
			if (Is_Back == YES)
				break;
		}
	}

	// USER MODE
	else if (Mode == USER_MODE)
	{
		Is_Back = NO;
		u8 Counter = 0;
		// USER INTERFACE
		while (1)
		{
			if (Counter == 0)
			{
				system("cls");
				printf("-----------\nClinic Management System: User shall");
			}
			Is_Back = User_Interface();
			if (Is_Back == YES)
				break;
			Counter++;
		}
	}

	// EXIT PROGRAM
	else if (Mode == MAIN_INTERFACE_PROGRAM_EXIT)
		exit(0);

	// MAIN INTERFACE MODE ERROR
	else
		Error(MODE_ERROR);
}