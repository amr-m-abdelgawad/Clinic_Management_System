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

#define USER_VIEW_PATIENT 0
#define USER_TODAY_RESERVATIONS 1
#define USER_GO_BACK 2

// USER INTERFACE
u8 User_Interface(void)
{
	u8 Is_Back = NO;

	// ENTERING ADMIN INTERFACE
	u16 Mode;
	printf("\n-----------\n-If you want: View patient record, press 0\n-If you want: View today's reservations, press 1\n-If you want: Go back, press 2\nEnter a number: ");
	scanf("%d", &Mode);

	// VIEW PATIENT RECORD
	if (Mode == USER_VIEW_PATIENT)
		View_Patient_Interface();

	// VIEW TODAY'S RESERVATIONS
	else if (Mode == USER_TODAY_RESERVATIONS)
	{
		printf("\n");
		View_Reservation_Slots(NO);
	}

	// GO BACK
	else if (Mode == USER_GO_BACK)
		Is_Back = YES;

	// USER INTERFACE MODE ERROR
	else
		Error(MODE_ERROR);

	// RETURN CHECK IF USER COMEBACK TO MAIN INTERFACE
	return Is_Back;
}