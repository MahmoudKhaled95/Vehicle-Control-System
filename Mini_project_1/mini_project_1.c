/*
 ***************************************************************************************************************************************
 Name        : project1.c
 Author      : Mahmoud Khaled
 Deadline    : 16/04/2022
 Description : Vehicle Control System Project
 ***************************************************************************************************************************************
 */

#include <stdio.h>

//Functions prototype
void MainOptions(void);
void TrafficLight(void);
void RoomTemp(void);
void EngineTemp(void);
void PrintConsole(void);

//To define states that used in the project
typedef enum
{
	False,		 //False = 0
	True,  		 //True = 1
	OFF = 0,	 //OFF = 0
	ON			 //NO = 1
}bool;

//global variables (Initial values for each sensor measurement and states )
bool EngineState = OFF;
int VehicleSpeed = 60;
int Enginetemp = 90;
int TempInsideRoom = 27;
bool AirCondition = OFF;
bool EngineTemperatureController = OFF;

int main(void)
{
	setvbuf(stdout, NULL,_IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//calling the main function responsible for control vehicle system
	MainOptions();
	return 0;
}

//Core function of the project that contain the state of system and sensors set menu
void MainOptions(void)
{
	bool system = True;
	char user_selection;
	while(system != False)
	{
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");

		//input from the user to select which option does he/she wants
		scanf(" %c",&user_selection);

		//Turn on vehicle engine option
		if( (user_selection == 'a') || (user_selection == 'A') )
		{
			char inputTurnOnEngine;
			EngineState = ON;
			//set menu of sensors when Vehicle Engine is On
			while(EngineState == ON)
			{
				printf("a. Turn off the engine\n");
				printf("b. Set the traffic light color.\n");
				printf("c. Set the room temperature (Temperature Sensor)\n");
				printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
				scanf(" %c",&inputTurnOnEngine);
				if(inputTurnOnEngine == 'a' || inputTurnOnEngine == 'A')
				{
					EngineState = OFF;
				}
				else if (inputTurnOnEngine == 'b' || inputTurnOnEngine == 'B')
				{
					TrafficLight();
					PrintConsole();
				}
				else if (inputTurnOnEngine == 'c' || inputTurnOnEngine == 'C')
				{
					RoomTemp();
					PrintConsole();
				}
				else if (inputTurnOnEngine == 'd' || inputTurnOnEngine == 'D')
				{
					EngineTemp();
					PrintConsole();
				}
			}
		}
		//Turn off vehicle engine option
		else if((user_selection == 'b') || (user_selection == 'B'))
		{
			printf("Turn oFF the Vehicle Engine\n\n");
		}
		//Turn off the system
		else if( (user_selection == 'c') || (user_selection == 'C') )
		{
			printf("Quit the system\n");
			system = False;
			break;
		}
		//in case of entering other letter
		else
		{
			printf("Select from choice a, b, and c\n\n");
		}
	}
}

//Traffic light function
void TrafficLight(void)
{
	char UserInputTraffic;
	printf("Enter the required color:\n");
	scanf(" %c", &UserInputTraffic);
	if ( (UserInputTraffic == 'G') || (UserInputTraffic == 'g') )
	{
		VehicleSpeed = 100;
	}
	else if ( (UserInputTraffic == 'O') || (UserInputTraffic == 'o') )
	{
		VehicleSpeed = 30;
	}
	else if ( (UserInputTraffic == 'R') || (UserInputTraffic == 'r') )
	{
		VehicleSpeed = 0;
	}
}

//Set room temperature by using RoomTemp function
void RoomTemp(void)
{
	printf("Enter The required room Temp:\n");
	scanf(" %d",&TempInsideRoom);
	if (TempInsideRoom < 10)
	{
		AirCondition = ON;
		TempInsideRoom = 20;
	}
	else if (TempInsideRoom > 30)
	{
		AirCondition = ON;
		TempInsideRoom = 20;
	}
	else
		AirCondition = OFF;
}


//Setting temperature of engine and control the state of Engine Temperature Controller by using EngineTemp function
void EngineTemp(void)
{
	printf("Enter the required Engine temperature:\n");
	scanf(" %d",&Enginetemp);
	if(Enginetemp < 100)
	{
		EngineTemperatureController = ON;
		Enginetemp = 125;
	}
	else if (Enginetemp > 150)
	{
		EngineTemperatureController = ON;
		Enginetemp = 125;
	}
	else
	{
		EngineTemperatureController = OFF;
	}
}

//Function responsible for displaying current vehicle states after applying all sensors measurements
void PrintConsole(void)
{
	if(VehicleSpeed == 30)
	{
		if(AirCondition == OFF)
			AirCondition = ON;

		TempInsideRoom = TempInsideRoom*(1.25)+1;

		if( EngineTemperatureController == OFF)
			EngineTemperatureController = ON;

		Enginetemp = Enginetemp*(1.25)+1;
	}

	if (EngineState == ON)
		printf("\nEngine is ON\n");

	if (AirCondition == OFF)
		printf("AC is OFF\n");
	else
		printf("AC is ON\n");

	printf("Vehicle Speed %d Km/Hr\n",VehicleSpeed);

	printf("Room Temperature: %d C\n", TempInsideRoom);

	if (EngineTemperatureController == OFF)
		printf("Engine Temperature Controller is OFF\n");
	else
		printf("Engine Temperature Controller is ON\n");

	printf("Engine Temperature: %d C\n",Enginetemp);
	printf("\n");
}
