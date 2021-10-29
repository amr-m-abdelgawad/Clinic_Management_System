/******************************************
*
*	File: Program Main Interface
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 13, 2021
*
******************************************/

#include "Interface.h"
#include "STD_Types.h"
#include "Reservation.h"

// MAIN INTERFACE
int main(void)
{
	// ADD 5 RESERVATION SLOTS
	u8 SlotID;
	for (SlotID = 0; SlotID < 5; SlotID++)
		Add_Reservation_Slot(SlotID);

	// MAIN INTERFACE
	while (1)
	{
		Main_Interface();
	}

	// END OF PROGRAM
	return 0;
}