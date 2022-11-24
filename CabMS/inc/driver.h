/***************************************************************************
*                       MACROS
***************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H
#define MAX 1024

/***************************************************************************
*                       STRUCTURES
***************************************************************************/
typedef struct driver
{
	int _id;
	int phone;
	char name[20];
	char gender;
	char dName[20];
	char dPasswd[20];
	struct carDetails
	{
		char carModel[20];
		char carRegNo[20];
	}CAR;
	struct driver *next;
}DRIVER;

/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/
DRIVER* signUpDriver(DRIVER*);

int signInDriver(DRIVER *);
int findLRecDrv(DRIVER *, char *, char *);
void dispDriver(DRIVER *);
int updateDDetails(DRIVER *);
int driverMainMenu();
int writeDriDetails(DRIVER* );
DRIVER* loadDriDetails();
int tokenizeDRIVER(DRIVER *, char *);

#endif
/*END OF MACROS*/
