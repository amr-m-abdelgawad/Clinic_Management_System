/******************************************
*
*	File: Patient Reservation Functions
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 28, 2021
*
******************************************/

#include <stdio.h>
#include "STD_Types.h"
#include "Reservation.h"
#include "Structs.h"
#include "Interface.h"
#include "Errors.h"
#include "Patient.h"
#include "Progress.h"

// DEFINES
#define NO_PRESS 5

// PATIENT MAIN POINTERS
reservation *RESERVATION_HEAD = NULL;
reservation *RESERVATION_CURRENT = NULL;
extern patient *PATIENT_HEAD;
extern patient *PATIENT_CURRENT;

// ADD PATIENT TO RESERVATION INTERFACE
void Add_Reservation_Interface(void)
{
    system("cls");
    u8 Slot_Num;
    u8 Patient_Slot_ID;
    patient *ptr = PATIENT_HEAD;
    printf("-----------\nClinic Management System: Admin shall --> Add Patient to Reservation\n-----------\n");
    if (ptr == NULL)
        Error(EMPTY_PATIENT_LIST);
    else
    {
        printf("Available Reservation Durations:\n");
        View_Reservation_Slots(YES);
        printf("Please Enter a Number: ");
        while (1)
        {
            scanf("%d", &Slot_Num);
            if (Is_Available_Slot(Slot_Num) == 0)
                printf("There Is No Such a Slot, Try Again: ");
            else
            {
                printf("Please Enter Patient ID: ");
                scanf(" %d", &Patient_Slot_ID);
                if (Search_Patient(Patient_Slot_ID) == NULL)
                    Error(PATIENT_NOT_FOUND);
                else if (Search_Patient(Patient_Slot_ID)->Reservation == 1)
                    Error(PATIENT_IN_RESERVATION);
                else
                {
                    Add_Patient_Reservation(Patient_Slot_ID, Slot_Num);
                    Progress(_PROGRASS_ADD_PATIENT_TO_RESERVATION);
                }
                break;
            }
        }
    }
}

// CANCEL PATIENT RESERVATION INTERFACE
void Cancel_Reservation_Interface(void)
{
    system("cls");
    u32 Patient_Reservation_ID;
    printf("-----------\nClinic Management System: Admin shall --> Cancel Reservation\n-----------\n");
    printf("Today's Reservations:\n");
    u8 Reservation_found = View_Reservation_Slots(NO);
    if (Reservation_found == 1)
    {
        printf("\nPlease Enter Patient ID: ");
        scanf(" %d", &Patient_Reservation_ID);
        if (Search_Patient(Patient_Reservation_ID) == NULL)
            Error(PATIENT_NOT_FOUND);
        else
        {
            Cancel_Reservation(Patient_Reservation_ID);
            Progress(_PROGRASS_CANCEL_RESERVATION);
        }
    }
}

// ALLOCATE RESERVATION SLOTS IN MEMORY FUNCTION
void Add_Reservation_Slot(u16 ID)
{
    reservation *ptr = (reservation *)malloc(sizeof(reservation));
    if (RESERVATION_HEAD == NULL)
    {
        RESERVATION_HEAD = ptr;
        RESERVATION_CURRENT = RESERVATION_HEAD;
        RESERVATION_HEAD->RESERVATION_NEXT = NULL;
        RESERVATION_HEAD->Avaliable = YES;
        RESERVATION_HEAD->ID = ID;
        RESERVATION_HEAD->PATIENT = NULL;
    }
    else
    {
        RESERVATION_CURRENT->RESERVATION_NEXT = ptr;
        RESERVATION_CURRENT = RESERVATION_CURRENT->RESERVATION_NEXT;
        RESERVATION_CURRENT->RESERVATION_NEXT = NULL;
        RESERVATION_CURRENT->Avaliable = YES;
        RESERVATION_CURRENT->ID = ID;
        RESERVATION_CURRENT->PATIENT = NULL;
    }
}

// ADD PATIENT TO RESERVATION
void Add_Patient_Reservation(u32 User_ID, u8 Slot)
{
    reservation *reservation_ptr = RESERVATION_HEAD;
    while (reservation_ptr != NULL)
    {
        if (reservation_ptr->Press == Slot)
        {
            reservation_ptr->PATIENT = Search_Patient(User_ID);
            reservation_ptr->PATIENT->Reservation = YES;
            reservation_ptr->Avaliable = NO;
            reservation_ptr->Press = NO_PRESS;
        }
        reservation_ptr = reservation_ptr->RESERVATION_NEXT;
    }
}

// CANCEL PATIENT RESERVATION
u8 Cancel_Reservation(u32 User_ID)
{
    u8 found = NO;
    reservation *ptr = RESERVATION_HEAD;
    while (ptr != NULL)
    {
        if (ptr->Avaliable == NO)
        {
            if (ptr->PATIENT->ID == User_ID)
            {
                found = YES;
                ptr->PATIENT->Reservation = NO;
                ptr->PATIENT = NULL;
                ptr->Avaliable = YES;
            }
        }
        ptr = ptr->RESERVATION_NEXT;
    }
    return found;
}

// RETURN IF THE CHOSEN RESERVATION SLOT IS AVALIABLE OR NOT
u8 Is_Available_Slot(u8 Slot)
{
    u8 found = NO;
    reservation *reservation_ptr = RESERVATION_HEAD;
    while (reservation_ptr != NULL)
    {
        if (reservation_ptr->Avaliable == YES)
        {
            if (reservation_ptr->Press == Slot)
                found = YES;
        }
        reservation_ptr = reservation_ptr->RESERVATION_NEXT;
    }
    return found;
}

u8 View_Reservation_Slots(u8 IsAvaliable)
{
    u8 found = NO, count = 0;
    reservation *ptr = RESERVATION_HEAD;
    while (ptr != NULL)
    {
        if (IsAvaliable == YES)
        {
            if (ptr->Avaliable == IsAvaliable)
            {
                found = YES;
                if (ptr->ID == _2PM)
                    printf("-From 2pm to 2:30pm, Press %d\n", count);
                else if (ptr->ID == _230PM)
                    printf("-From 2:30pm to 3pm, Press %d\n", count);
                else if (ptr->ID == _3PM)
                    printf("-From 3pm to 3:30pm, Press %d\n", count);
                else if (ptr->ID == _4PM)
                    printf("-From 4pm to 4:30pm, Press %d\n", count);
                else
                    printf("-From 4:30pm to 5pm, Press %d\n", count);
                ptr->Press = count;
                count++;
            }
        }
        else
        {
            if (ptr->Avaliable == IsAvaliable)
            {
                found = 1;
                if (ptr->ID == _2PM)
                    printf("-From 2pm to 2:30pm --> Patient ID: %d, Patient Name: %s", ptr->PATIENT->ID, ptr->PATIENT->Name);
                else if (ptr->ID == _230PM)
                    printf("-From 2:30pm to 3pm --> Patient ID: %d, Patient Name: %s", ptr->PATIENT->ID, ptr->PATIENT->Name);
                else if (ptr->ID == _3PM)
                    printf("-From 3pm to 3:30pm --> Patient ID: %d, Patient Name: %s", ptr->PATIENT->ID, ptr->PATIENT->Name);
                else if (ptr->ID == _4PM)
                    printf("-From 4pm to 4:30pm --> Patient ID: %d, Patient Name: %s", ptr->PATIENT->ID, ptr->PATIENT->Name);
                else
                    printf("-From 4:30pm to 5pm, Patient ID: %d --> Patient Name: %s", ptr->PATIENT->ID, ptr->PATIENT->Name);
            }
        }

        ptr = ptr->RESERVATION_NEXT;
    }
    if (IsAvaliable == YES)
    {
        if (found == NO)
            printf("\n--> There is no Reservation Avaliable.");
    }
    else
    {
        if (found == NO)
            printf("\n--> There is no Reservations For Today.\n");
    }
    return found;
}