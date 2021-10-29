/******************************************
*
*	File: Program Admin Interface Functions
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include <stdio.h>
#include <unistd.h>
#include "STD_Types.h"
#include "Interface.h"
#include "Errors.h"
#include "Patient.h"
#include "Reservation.h"

#define CLOSED 0
#define OPENED 1
#define ADMIN_ADD_PATIENT 0
#define ADMIN_EDIT_PATIENT 1
#define ADMIN_ADD_PATIENT_TO_RESERVATION 2
#define ADMIN_CANCEL_RESERVATION 3
#define ADMIN_GO_BACK 4

// CHECK IF USER ENTERED THE ADMIN PASSWORD RIGHT
u8 Admin_Check(u16 PASS)
{
	u8 i, Is_Admin_Open = CLOSED;
	u32 Input_PASS;

	// GIVING 3 CONSECUTIVE TIMES FOR ADMIN PASSWORD
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
			printf("\nPlease enter admin password: ");
		else
			printf("\nPassword is wrong, only %d try/tries left, Please try again: ", 3 - i);
		scanf("%d", &Input_PASS);
		if (Input_PASS == PASS)
		{
			Is_Admin_Open = OPENED;
			break;
		}
	}

	// RETURN CHECK IF THE ADMIN INTERFACE OPENED OR NOT
	return Is_Admin_Open;
}

// ADMIN INTERFACE
u8 Admin_Interface(u8 Is_Admin_Open)
{
	u8 Is_Back = NO;

	// ENTERING ADMIN INTERFACE
	if (Is_Admin_Open == YES)
	{
		system("cls");
		u16 Mode;
		printf("-----------\nClinic Management System: Admin shall\n-----------\n-If you want: Add new patient record, press 0\n-If you want: Edit patient record, press 1\n-If you want: Add Patient To Reservation, press 2\n-If you want: Cancel reservation, press 3\n-If you want: Go back, press 4\nEnter a number: ");
		scanf("%d", &Mode);

		// ADD NEW PATIENT
		if (Mode == ADMIN_ADD_PATIENT)
			Add_Patient_Interface();

		// EDIT PATIENT RECORD
		else if (Mode == ADMIN_EDIT_PATIENT)
			Edit_Patient_Interface();

		// ADD PATIENT TO RESERVATION
		else if (Mode == ADMIN_ADD_PATIENT_TO_RESERVATION)
			Add_Reservation_Interface();

		// CANCEL PATIENT RESERVATION
		else if (Mode == ADMIN_CANCEL_RESERVATION)
			Cancel_Reservation_Interface();

		// GO BACK
		else if (Mode == ADMIN_GO_BACK)
			Is_Back = YES;

		// ADMIN INTERFACE MODE ERROR
		else
			Error(MODE_ERROR);
	}

	// WRONG ADMIN PASS FOR 3 CONSECUTIVE TIMES, PROGRAM EXIT
	else
		Error(ADMIN_WRONG_PASS);

	// RETURN CHECK IF USER COMEBACK TO MAIN INTERFACE
	return Is_Back;
}