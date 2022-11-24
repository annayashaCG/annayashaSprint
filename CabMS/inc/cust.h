/***************************************************************************
*                       MACROS
***************************************************************************/
#ifndef CUST_H
#define CUST_H

/***************************************************************************
*                       STRUCTURES
***************************************************************************/
typedef struct customer
{
	int _id;
	int phone;
	char name[20];
	char gender;
	char cName[20];
	char cPasswd[20];
	struct customer *next;

}CUST;

/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/
int custMenu();

CUST* signUpCust(CUST *);

int signInCust(CUST *);
int findLRecCust(CUST *, char *, char *);
void dispCust(CUST *);

int writeCustDetails(CUST*);
CUST* loadCustDetails();
int tokenizeCUST(CUST *, char *);


#endif
/*END OF MACRO*/
