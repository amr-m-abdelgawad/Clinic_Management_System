/******************************************
*
*	File: Progress Messages Function
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 14, 2021
*
******************************************/

#include <stdio.h>
#include <unistd.h>
#include "STD_Types.h"
#include "Progress.h"
#include "Errors.h"

// PROGRESS FUNCTION
void Progress(u8 Progress)
{
	switch (Progress)
	{
	case _PROGRASS_ADD_PATIENT:
		printf("--> Patient Added Successfully.");
		sleep(1);
		break;
	case _PROGRASS_EDIT_PATIENT_NAME:
		printf("--> Patient Name Edited Successfully.");
		sleep(1);
		break;
	case _PROGRASS_EDIT_PATIENT_AGE:
		printf("--> Patient Age Edited Successfully.");
		sleep(1);
		break;
	case _PROGRASS_EDIT_PATIENT_GENDER:
		printf("--> Patient Gender Edited Successfully.");
		sleep(1);
		break;
	case _PROGRASS_ADD_PATIENT_TO_RESERVATION:
		printf("--> Patient Added to Reservation Successfully.");
		sleep(1);
		break;
	case _PROGRASS_CANCEL_RESERVATION:
		printf("--> Reservation cancelled Successfully.");
		sleep(1);
		break;
	default:
		Error(UNKNOWN);
	}
}
