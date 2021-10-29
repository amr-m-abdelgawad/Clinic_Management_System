/******************************************
*
*	File: Program Structs Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"
#include <stdlib.h>

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

// PATIENT STRUCT
typedef struct patient
{
	u8 Name[100];
	u8 Reservation;
	u32 ID;
	u32 Age;
	u32 Gender;
	struct patient *PATIENT_NEXT;
} patient;

// RESERVATION STRUCT
typedef struct reservation
{
	u8 ID;
	u32 Avaliable;
	u32 Press;
	struct reservation *RESERVATION_NEXT;
	struct patient *PATIENT;
} reservation;

#endif