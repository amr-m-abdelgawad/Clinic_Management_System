/******************************************
*
*	File: Patient Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"
#include "Structs.h"

#ifndef _PATIENT_H_
#define _PATIENT_H_

// DEFINES
#define MALE 0
#define FEMALE 1

// PATIENT FUNCTIONS PROTOTYPES
void Add_Patient_Interface(void);
struct patient *Search_Patient(u32 User_ID);
void Add_Patient(u32 ID, u8 Name[], u32 Age, u32 Gender);
void View_Patient_Interface(void);
void View_Patient(u32 User_ID);
void Edit_Patient_Interface(void);

#endif