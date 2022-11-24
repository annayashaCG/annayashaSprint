/*************************************************************************
*
*  FILE NAME    : cust.c
*
*  DESCRIPTION  : Perform the function of Customer
*
*  DATE     	 NAME   	 REFERENCE          REASON
*	
*  24-NOV-2022  ANNAYASHA  		  New       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <common.h>
#include <cust.h>

/******************************************************************************
*
*       Function Name   : custMenu
*       Description     : Showing the menu in Customer Page 
*       Returns         : Success 
*
*******************************************************************************/
int custMenu()
{
	int ch = 0;
	printf("\n\t===============Customer Trip Menu==========\n");
	printf("\n\tPress,");
	printf("\n\t1. Book Trip");
	printf("\n\t2. Check Driver Details");
	printf("\n\t3. Check Cab Details");
	printf("\n\t4. Print Booking Details");
	printf("\n\t5. Return Back to Main Menu");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

/******************************************************************************
*
*       Function Name   : signUpCust
*       Description     : This function use for Sing up the customer
*       Returns         : Success 
*
*******************************************************************************/
CUST * signUpCust(CUST *head)
{
	CUST *newNode = NULL;
	CUST *tmpNode = head;

	newNode = (CUST*)malloc(sizeof(CUST));
	newNode->next = NULL;
	printf("\n\tEnter Customer Details,");
	printf("\n\tName: ");
	getchar();
	scanf("%[^\n]s",newNode->name);
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tGender: ");
	getchar();
	scanf("%c",&newNode->gender);
	printf("\n\tPhone Number: ");
	scanf("%d", &newNode->phone);
	printf("\n\tUser Name: ");
	scanf("%s",newNode->cName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->cPasswd);

	if(head == NULL)
	{
		head = newNode;
		tmpNode = newNode;
	}
	else
	{
		while(tmpNode->next != NULL){
			tmpNode = tmpNode->next;
		}
		tmpNode->next = newNode;
		tmpNode = tmpNode->next;
	}

	

	return head;
}

/******************************************************************************
*
*       Function Name   : signInCust
*       Description     : This function use for Sing in the customer
*       Returns         : Success 
*
*******************************************************************************/
int signInCust(CUST *head)
{
	char lName[20], lPasswd[20];
	int ret = 0;
	printf("\n\t===============Customer Login=================\n");
	printf("\n\tEnter,");
	printf("\n\tUser Name: ");
	scanf("%s",lName);
	printf("\n\tPassword: ");
	scanf("%s",lPasswd);

	/*

	logic to find user name exists
	 */

	ret = findLRecCust(head, lName, lPasswd);
	if(ret == 1)
		printf("\n\tLogged In");
	else
		printf("\n\tTry Again");

	return ret;
}

/******************************************************************************
*
*       Function Name   : findLRecCust
*       Description     : Find the Customer
*       Returns         : Success
*
*******************************************************************************/
int findLRecCust(CUST *head, char *lName, char *lPasswd)
{
	int flag = 0;
	while(head != NULL)
	{
		if((strcmp(head->cName, lName) == 0)&&(strcmp(head->cPasswd, lPasswd) == 0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	return flag;	
}

/******************************************************************************
*
*       Function Name   : dispCust
*       Description     : Display the customer
*       Returns         : Success 
*
*******************************************************************************/
void dispCust(CUST *head)
{
	while(head != NULL)
	{
		printf("\n\t%d",head->_id);
		head = head->next;
	}
}

/******************************************************************************
*
*       Function Name   : writeCustDetails
*       Description     : Writting Customer details
*       Returns         : Success 
*
*******************************************************************************/
int writeCustDetails(CUST* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/CUST.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t No Records Present\n");
		return 0;
	}
	while(head != NULL){
		fprintf(fp,"%d, %d, %s, %c, %s, %s\n",head->_id,head->phone,head->name, head->gender, head->cName, head->cPasswd);
		head = head->next;
	}
	fclose(fp);
	return 0;
}

/******************************************************************************
*
*       Function Name   : loadCustDetails
*       Description     : Loading Customer details
*       Returns         : Success 
*
*******************************************************************************/
CUST* loadCustDetails()
{
	FILE *fp = NULL;
	CUST *newNode = NULL;
	CUST *head = NULL;
	CUST *cust; 
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };
	
	fp = fopen("./data/CUST.dat","r+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		
		while(fgets(tmpBuff, 256, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				head = newNode;
				cust = newNode;
				//tokenizeCUST(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				cust->next = newNode;
				tokenizeCUST(newNode, tmpBuff);
				cust = cust->next;	
			}
			

		}

	}

	fclose(fp);
	// printf("\n\tHead : %u\nlast node: %u\n", head, pd);
	return head;
}

/******************************************************************************
*
*       Function Name   : tokenizeCUST
*       Description     : Tokenise the data by comma
*       Returns         : Success 
*
*******************************************************************************/
int tokenizeCUST(CUST *cust, char *tmpBuff)
{
	char *tokens;
	//int i, count;
	//char *tmpBuff1;
	tokens = strtok(tmpBuff, ",");
	cust->_id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->name);
	tokens = strtok(tmpBuff, ",");
	cust->phone = atoi(tokens);
    tokens = strtok(NULL, ",");
	cust->gender =  atoi(tokens);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->cName);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->cPasswd);
	removeTrailing(cust->cPasswd);
    
	tokens = strtok(NULL, ",");
	//cd->_gender = tokens[0];
    return 0;

	//dispPD(pd);
}
