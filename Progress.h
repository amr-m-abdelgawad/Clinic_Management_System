/******************************************
*
*	File: Progress Messages Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"

#ifndef _PROGRESS_H_
#define _PROGRESS_H_

// DEFINES
#define _PROGRASS_ADD_PATIENT 0
#define _PROGRASS_EDIT_PATIENT_NAME 1
#define _PROGRASS_EDIT_PATIENT_AGE 2
#define _PROGRASS_EDIT_PATIENT_GENDER 3
#define _PROGRASS_ADD_PATIENT_TO_RESERVATION 4
#define _PROGRASS_CANCEL_RESERVATION 5

// PATIENT FUNCTIONS PROTOTYPES
void Progress(u8 Progress);

#endif