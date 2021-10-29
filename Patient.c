/******************************************
*
*	File: Patient Functions
*	Author: Amr Mohamed Abdel-Gawad
*	Date: Oct 14, 2021
*
******************************************/

#include <stdio.h>
#include "STD_Types.h"
#include "Interface.h"
#include "Structs.h"
#include "Patient.h"
#include "Progress.h"
#include "Errors.h"

#define EDIT_PATIENT_NAME 0
#define EDIT_PATIENT_AGE 1
#define EDIT_PATIENT_GENDER 2
#define EDIT_EXIT 3

// PATIENT MAIN POINTERS
patient *PATIENT_HEAD = NULL;
patient *PATIENT_CURRENT = NULL;

// ADD PATIENT TO THE LINKED LIST INTERFACE
void Add_Patient_Interface(void)
{
	system("cls");
	char Patient_Name[100];
	u32 Patient_ID, Patient_Age, Patient_Gender;

	printf("-----------\nClinic Management System: Admin shall --> Add New Patient Record\n-----------\nPlease Enter Patient ID: ");
	scanf("%d", &Patient_ID);

	// HANDLING EXIST ID ERROR
	while (1)
	{
		if (Search_Patient(Patient_ID) != NULL)
		{
			printf("ID is Already Exists, Please Enter Unique Patient ID: ");
			scanf("%d", &Patient_ID);
		}
		else
			break;
	}

	getc(stdin);
	printf("Please Enter Patient Name: ");
	fgets(Patient_Name, sizeof(Patient_Name), stdin);
	printf("Please Enter Patient Age: ");
	scanf("%d", &Patient_Age);
	printf("-If Patient is Male, Press 0\n-If Patient is Female, Press 1\nEnter a Number: ");
	scanf("%u", &Patient_Gender);

	// HANDLING WRONG GENDER ANSWER
	while (1)
	{
		if ((Patient_Gender != MALE) && (Patient_Gender != FEMALE))
		{
			printf("Wrong Answer, Please Try Again: ");
			scanf("%d", &Patient_Gender);
		}
		else
			break;
	}

	// ADDING PATIENT TO PATIENTS LINKED LIST
	Add_Patient(Patient_ID, Patient_Name, Patient_Age, Patient_Gender);
	Progress(_PROGRASS_ADD_PATIENT);
}

// SEARCH IF PATIENT EXISTS & RETURN PATIENT POINTER
struct patient *Search_Patient(u32 User_ID)
{
	u8 Patient_Found = NO;
	patient *ptr = PATIENT_HEAD;
	if (ptr == NULL)
		return NULL;
	else
	{
		while (ptr != NULL)
		{
			if (ptr->ID == User_ID)
			{
				Patient_Found = YES;
				return ptr;
				break;
			}
			ptr = ptr->PATIENT_NEXT;
		}
		if (Patient_Found == NO)
			return NULL;
	}
}

// ADD NEW PATIENT TO THE LINKED LIST
void Add_Patient(u32 ID, u8 Name[], u32 Age, u32 Gender)
{
	u8 i;
	patient *ptr = (patient *)malloc(sizeof(patient));
	if (PATIENT_HEAD == NULL)
	{
		PATIENT_HEAD = ptr;
		PATIENT_CURRENT = PATIENT_HEAD;
		PATIENT_HEAD->PATIENT_NEXT = NULL;
		PATIENT_HEAD->ID = ID;
		for (i = 0; i < 50; i++)
			PATIENT_HEAD->Name[i] = Name[i];
		PATIENT_HEAD->Age = Age;
		PATIENT_HEAD->Gender = Gender;
		PATIENT_HEAD->Reservation = NO;
	}
	else
	{
		PATIENT_CURRENT->PATIENT_NEXT = ptr;
		PATIENT_CURRENT = PATIENT_CURRENT->PATIENT_NEXT;
		PATIENT_CURRENT->PATIENT_NEXT = NULL;
		PATIENT_CURRENT->ID = ID;
		for (i = 0; i < 50; i++)
			PATIENT_CURRENT->Name[i] = Name[i];
		PATIENT_CURRENT->Age = Age;
		PATIENT_CURRENT->Gender = Gender;
		PATIENT_CURRENT->Reservation = NO;
	}
}

// VIEW PATIENT RECORD INTERFACE
void View_Patient_Interface(void)
{
	u32 User_ID;
	patient *ptr = PATIENT_HEAD;
	if (ptr == NULL)
		Error(EMPTY_PATIENT_LIST);
	else
	{
		printf("Please Enter Patient ID: ");
		scanf("%d", &User_ID);
		View_Patient(User_ID);
	}
}

// VIEW PATIENT RECORD
void View_Patient(u32 User_ID)
{
	u8 Patient_Found = NO;
	patient *ptr = PATIENT_HEAD;
	while (ptr != NULL)
	{
		if (ptr->ID == User_ID)
		{
			Patient_Found = YES;
			printf("\n-> Patient ID:	%d\n	Name: %s	Age: %d\n	Gender: ", ptr->ID, ptr->Name, ptr->Age);
			if (ptr->Gender == MALE)
				printf("Male");
			else
				printf("Female");
			if (ptr->Reservation == 1)
				printf("\n	Patient in Reservation.");
			else
				printf("\n	Patient is not in Reservation.");
			printf("\n");
			break;
		}
		ptr = ptr->PATIENT_NEXT;
	}
	if (Patient_Found == NO)
		Error(PATIENT_NOT_FOUND);
}

// EDIT PATIENT RECORD
void Edit_Patient_Interface(void)
{
	system("cls");
	char Patient_Name[100];
	u32 Patient_ID, Patient_Age, Patient_Gender;
	u8 i, Edit_Mode;
	printf("-----------\nClinic Management System: Admin shall --> Edit Patient Record\n-----------\nPlease Enter Patient ID: ");
	scanf(" %d", &Patient_ID);
	if (Search_Patient(Patient_ID) == NULL)
		Error(PATIENT_NOT_FOUND);
	else
	{
		View_Patient(Patient_ID);
		printf("If You Want to Edit:\n-Name, Press 0\n-Age, Press 1\n-Gender, Press 2\n-If You Want To Exit, Press 3\nEnter a Number: ");
		scanf("%d", &Edit_Mode);

		// EDIT PATIENT NAME
		if (Edit_Mode == EDIT_PATIENT_NAME)
		{
			getc(stdin);
			printf("Please Enter Patient Name: ");
			fgets(Patient_Name, sizeof(Patient_Name), stdin);
			for (i = 0; i < 50; i++)
				Search_Patient(Patient_ID)->Name[i] = Patient_Name[i];
			Progress(_PROGRASS_EDIT_PATIENT_NAME);
		}

		// EDIT PATIENT AGE
		else if (Edit_Mode == EDIT_PATIENT_AGE)
		{
			printf("Please Enter Patient Age: ");
			scanf(" %d", &Patient_Age);
			Search_Patient(Patient_ID)->Age = Patient_Age;
			Progress(_PROGRASS_EDIT_PATIENT_AGE);
		}
		else if (Edit_Mode == EDIT_PATIENT_GENDER)
		{
			printf("-If Patient is Male, Press 0\n-If Patient is Female, Press 1\nEnter a Number: ");
			scanf("%u", &Patient_Gender);
			// HANDLING WRONG GENDER ANSWER
			while (1)
			{
				if ((Patient_Gender != MALE) && (Patient_Gender != FEMALE))
				{
					printf("Wrong Answer, Please Try Again: ");
					scanf("%d", &Patient_Gender);
				}
				else
					break;
			}
			Search_Patient(Patient_ID)->Gender = Patient_Gender;
			Progress(_PROGRASS_EDIT_PATIENT_GENDER);
		}
		else if (Edit_Mode == EDIT_EXIT)
		{
		}
		else
			Error(MODE_ERROR);
	}
}
