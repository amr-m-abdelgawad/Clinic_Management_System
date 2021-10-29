/******************************************
*
*	File: Patient Reservation Header
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "STD_Types.h"

#ifndef _RESERVATION_H_
#define _RESERVATION_H_

// DEFINES
#define _2PM 0
#define _230PM 1
#define _3PM 2
#define _4PM 3
#define _430PM 4

// PATIENT FUNCTIONS PROTOTYPES
void Add_Reservation_Interface(void);
void Cancel_Reservation_Interface(void);
void Add_Reservation_Slot(u16 ID);
void Add_Patient_Reservation(u32 User_ID, u8 Slot);
u8 Cancel_Reservation(u32 User_ID);
u8 Is_Available_Slot(u8 Slot);
u8 View_Reservation_Slots(u8 IsAvaliable);

#endif