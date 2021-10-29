/******************************************
*
*	File: Program Errors Function
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include <stdio.h>
#include <unistd.h>
#include "STD_Types.h"
#include "Errors.h"

// HANDLING ERROR MESSAGES
void Error(u8 Error)
{
	switch (Error)
	{
	case MODE_ERROR:
		printf("\n*** Error 0: There is No Such a Mode.");
		sleep(1);
		break;
	case ADMIN_WRONG_PASS:
		printf("\n*** Error 1: Your tries finished, Program Will Close");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		exit(0);
		break;
	case EMPTY_PATIENT_LIST:
		printf("\n*** Error 2: Patient List is Empty.\n");
		sleep(1);
		break;
	case PATIENT_NOT_FOUND:
		printf("\n*** Error 3: Patient ID Not Found.\n");
		sleep(1);
		break;
	case PATIENT_IN_RESERVATION:
		printf("\n*** Error 4: Patient Is Already in Reservation.\n");
		sleep(1);
		break;
	default:
		printf("\n*** Error: Unknown.");
		sleep(1);
	}
}