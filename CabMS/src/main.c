/*************************************************************************
*
*  FILE NAME    : main.c
*
*  DESCRIPTION  : Main method of the Program
*
*  DATE      		NAME   		 REFERENCE          REASON
*
*  24-NOV-2022      ANNAYASHA    	New			   Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <common.h>
#include <cust.h>
#include <driver.h>
#include <trip.h>

/******************************************************************************
*
*       Function Name   : main
*       Description     : Calling all the function in main method
*       Returns         : Success 
*
*******************************************************************************/
int main()
{
	int ch = 0, bid=0;
	int retVal = 0, flag=0;

	CUST *hCust = NULL;
	CUST *headC = NULL;
	DRIVER *hDriver = NULL;
	DRIVER *headD = NULL;
	TRIP *hTrip = NULL;
	TRIP *headT = NULL;
	headC = loadCustDetails(hCust);/*loading driver details from DD.dat*/
	headD = loadDriDetails(hDriver);/*loading Customer details from CD.dat*/
    headT = loadTripDetails(hTrip);
	while(1){
		ch = mainMenu();
		switch(ch)
		{
			case 1:
				while(1)
				{
						ch = custMainMenu();
						switch(ch)
						{
							case 1:
								headC = signUpCust(headC);
								break;
							case 2:
								retVal = signInCust(headC);
								if(retVal == 1)
								{
									while(1){
										ch = custMenu();
										switch(ch)
										{
											case 1:
												headT = bookTrip(headT,&bid);
												writeTripDetails(headT);
												printf("\n\tYour Booking is confirmed with following details\n");
												printBook(headT, headC,headD, bid);
												break;
											case 2:
												//checkDrv();
												dispDriver(headD);
												break;
											case 3:
												//checkCab();
												//dispTrip(hTrip);
												dispDriver(headD);
												break;
											case 4:
												printf("\n\tEnter the Booking ID: ");
												scanf("%d",&bid);
												printBook(headT, headC,headD, bid);
												break;
											case 5:
												flag = 1; 
												/*printf("\n\tReturn to Main Menu");*/
												break;
											default:
												printf("\nWrong Choice\n");

										}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
								}
								break;
							case 3:
								//dispCust(hCust);
								/*printf("\n\tReturning Back to MainMenu");*/
								writeCustDetails(headC);
								flag = 1;
								break;
							default:
								printf("\n\tSomething went wrong");
						}
					if(flag == 1)
					{
						flag = 0;
						break;
					}
				}
				break;
			case 2:
				ch = driverMenu();
				switch(ch)
				{
					case 1:
						headD = signUpDriver(headD);
						writeDriDetails(headD);
						break;
					case 2:
						retVal = signInDriver(headD);
						//retVal = signInCust(hCust);
								if(retVal == 1)
								{
									while(1){
										ch = driverMainMenu();
										switch(ch)
										{
											case 1:
												updateDDetails(headD);
												dispDriver(headD);
												break;
											case 2:
												//checkDrv();
												dispTrip(headT);
												break;
											case 3:
												markCompleteTrips(headT);
												//checkCab();
												break;
											case 4:
												flag = 1; 
												/*printf("\n\tReturn to Main Menu");*/
												break;
											default:
												printf("\nWrong Choice\n");

										}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
								}
								break;
					case 3:
						dispDriver(headD);
						writeDriDetails(headD);
						printf("\n\tReturning Back to MainMenu");
						break;
					default:
						printf("\n\tSomething went wrong");
				}
				
				break;
			case 3:
				printf("\n\tThank You\n\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\n\tWrong Choice\n");

		}	
	}
	
	if(hCust != NULL)
		free(hCust);
	printf("\n\n");

	return 0;

}
