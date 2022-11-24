/*************************************************************************
** 
**  FILE NAME    : app.c
**
**  DESCRIPTION  : Program to to extract Customer and cab driver details and perform login operation
**                
**
**  Revision History:
**  DATE         NAME                REFERENCE          REASON
**
**  21-11-22    yamini talla           New           Initial creation
**
**  Copyright 2022, Altran Group All Rights Reserved
**
***************************************************************************
**                    STANDARD HEADER FILES
*****************************************************************************/
#include<app.h>
/**************************************************************************
**
** FUNCTION NAME: signUpCustomer
**
** DESCRIPTION:  It read the data from Customer
**
** RETURNS:  SUCCESS 
*****************************************************************************/


CD* signUpCustomer(CD *cd, int *_id)
{
	CD *newNode =NULL;
	CD *head = NULL;
	head = cd;

	newNode = (CD *)malloc(sizeof(CD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		cd = newNode;
	}
	else
	{
		while(cd->next != NULL)
			cd = cd->next;

		cd->next = newNode;
		cd = cd->next;
	}
	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
    printf("\n\tEnter Passwrd: ");
	getchar();
	scanf("%[^\n]s",newNode->_passwrd);
    printf("\n\tEnter your Place: ");
	getchar();
	scanf("%[^\n]s",newNode->_place);
    printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	*_id = newNode->_id;
	
	return head;
    
}

/**************************************************************************
**
** FUNCTION NAME: signUpDriver
**
** DESCRIPTION:  It read the data from Cab Driver
**
** RETURNS:  SUCCESS 
*****************************************************************************/


DD* signUpDriver(DD *dd, int *_id)
{
	DD *newNode =NULL;
	DD *head = NULL;
	head = dd;
	newNode = (DD *)malloc(sizeof(DD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		dd = newNode;
	}
	else
	{
		while(dd->next != NULL)
			dd = dd->next;

		dd->next = newNode;
		dd = dd->next;
	}
	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
	printf("\n\tEnter Passwrd: ");
	getchar();
	scanf("%[^\n]s",newNode->_passwrd);
    printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	*_id = newNode->_id;

	
	return head;
}

/**************************************************************************
**
** FUNCTION NAME: signInCustomer
**
** DESCRIPTION:  It read the data from Customer details and comparing user name and password
**
** RETURNS:  SUCCESS 
*****************************************************************************/
int signInCustomer(CD *head)
{
	CD _cd;
	int flag = 0;
	
	printf("\n\tEnter User Name: ");
    getchar();
    scanf("%[^\n]",_cd._name);
	//scanf("%s", _cd._name);
	printf("\n\tEnter Password: ");
	//scanf("%s",_cd._passwrd);
    getchar();
    scanf("%[^\n]",_cd._passwrd);
	while(head != NULL)
	{
		if((strcmp(head->_name, _cd._name)==0)&&(strcmp(head->_passwrd, _cd._passwrd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}

/**************************************************************************
**
** FUNCTION NAME: signInDriver
**
** DESCRIPTION:  It read the data from Cab Driver details and comparing user name and password
**
** RETURNS:  SUCCESS 
*****************************************************************************/

int signInDriver(DD *head)
{
	DD _dd;
	int flag = 0;
	
	printf("\n\tEnter User Name: ");
	getchar();
    scanf("%[^\n]",_dd._name);
    printf("\n\tEnter Password: ");
	getchar();
    scanf("%[^\n]",_dd._passwrd);
	while(head != NULL)
	{
		if((strcmp(head->_name, _dd._name)==0)&&(strcmp(head->_passwrd, _dd._passwrd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}


DD* loadDD()
{
	FILE *fp = NULL;
	DD *newNode = NULL;
	DD *head = NULL;
	DD *dd; 
	int _fSize = 0;
	char tmpBuff[MAX] = {'\0', };
	
	fp = fopen("./data/DD.dat","r");
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
		memset(tmpBuff,'\0', MAX);
		// head = newNode;
		while(fgets(tmpBuff, MAX, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				head = newNode;
				dd = newNode;
				tokenizeDD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				dd->next = newNode;
				tokenizeDD(newNode, tmpBuff);
				dd = dd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}


CD* loadCD()
{
	FILE *fp = NULL;
	CD *newNode = NULL;
	CD *head = NULL;
	CD *cd; 
	int _fSize = 0;
	char tmpBuff[MAX] = {'\0', };
	
	fp = fopen("./data/CD.dat","r");
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
		memset(tmpBuff,'\0', MAX);
		// head = newNode;
		while(fgets(tmpBuff, MAX, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CD *)malloc(sizeof(CD));
				newNode->next = NULL;
				head = newNode;
				cd = newNode;
				tokenizeCD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CD *)malloc(sizeof(CD));
				newNode->next = NULL;
				cd->next = newNode;
				tokenizeCD(newNode, tmpBuff);
				cd = cd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}



int tokenizeDD(DD *dd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, "|");
	dd->_id = atoi(tokens);

	tokens = strtok(NULL, "|");
	removeLeading(tokens,dd->_name);
	
	tokens = strtok(NULL, "|");
    removeLeading(tokens,dd->_passwrd);
	removeTrailing(dd->_passwrd);
	tokens = strtok(NULL, "|");
	dd->_phonenum =  atoi(tokens);
	tokens = strtok(NULL, "|");
	dd->_gender =  atoi(tokens);
	tokens = strtok(NULL, "|");
	//dd->_gender = tokens[0];
    return 0;
}

int tokenizeCD(CD *cd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, "|");
	cd->_id = atoi(tokens);

	tokens = strtok(NULL, "|");
	removeLeading(tokens,cd->_name);

	tokens = strtok(NULL, "|");
	removeLeading(tokens,cd->_passwrd);
	removeTrailing(cd->_passwrd);
	tokens = strtok(NULL, "|");
	removeLeading(tokens,cd->_place);
	tokens = strtok(NULL, "|");
	cd->_phonenum =  atoi(tokens);
    tokens = strtok(NULL, "|");
	cd->_gender =  atoi(tokens);
	tokens = strtok(NULL, "|");
	//cd->_gender = tokens[0];
    return 0;
}

int writeDD(DD *dd)
{
	FILE *fp = NULL;

	fp = fopen("./data/DD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(dd == NULL)
		printf("\n\t NULL Write pd");
	while(dd != NULL){
		fprintf(fp,"%d| %s| %s| %d| %c\n",dd->_id,dd->_name,dd->_passwrd,dd->_phonenum,dd->_gender);
		dd = dd->next;
	}

	fclose(fp);
    return 0;

}



int writeCD(CD *cd)
{
	FILE *fp = NULL;

	fp = fopen("./data/CD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(cd == NULL)
		printf("\n\t NULL Write pd");
	while(cd != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%d| %s| %s| %s| %d| %c\n",cd->_id,cd->_name,cd->_passwrd,cd->_place,cd->_phonenum,cd->_gender);
		cd = cd->next;
	}

	fclose(fp);
    return 0;
}

void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';
 
}

void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
    {
    	str[strlen(str)-1] = '\0';
    }

}

int dispDD(DD *dd,int _id)
{
	
	DD _dd;
	//int flag = 0;
	printf("\n Enter driver id:");
	scanf("%d",&_dd._id);
	while(dd!=NULL)
	{
		if(dd->_id == _dd._id)
		{
		
			printf("\n\tID: ");
			printf("%d",dd->_id);
			printf("\tName: ");
			printf("%s",dd->_name);
			printf("\tpasswrd: ");
			printf("%s",dd->_passwrd);
			printf("\n\tphone number: ");
			printf("%d",dd->_phonenum);
			printf("\tGender (M/F/O): ");
			printf("%c\n",dd->_gender);
			//dd = dd->next;
			//break;
		}	
		dd = dd->next;
	}
	return 0;
}

Customer_Car_Details* bookTrip(Customer_Car_Details *ccd, int *_id)
{
	Customer_Car_Details *newNode =NULL;
	Customer_Car_Details *head = NULL;
	head = ccd;
	int _status;

	newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		ccd = newNode;
	}
	else
	{
		while(ccd->next != NULL)
			ccd = ccd->next;

		ccd->next = newNode;
		ccd = ccd->next;
	}
	printf("\n\tEnter No of seats: ");
	scanf("%d",&newNode->capacity);
	//scanf("%s",&newNode->capacity);
	printf("\n\tEnter Customer Name: ");
	getchar();
	scanf("%[^\n]s",newNode->cust_name);
    printf("\n\tEnter Pick address: ");
	getchar();
	scanf("%[^\n]s",newNode->pick);
    printf("\n\tEnter drop address: ");
	getchar();
	scanf("%[^\n]s",newNode->drop);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	printf("\n\tEnter 1/0 for booking : ");
	//getchar();
	scanf("%d",&_status);
	if(_status == 1){
		printf("\n\tBooking succesfull");
		//cap(ccd);
		//scanf("%d",&_status);
	}
	else{
		printf("\n Booking cancelled");
	}
	*_id = newNode->capacity;
	
	return head;
    
}



Customer_Car_Details* loadccD()
{
	FILE *fp = NULL;
	Customer_Car_Details *newNode = NULL;
	Customer_Car_Details *head = NULL;
	Customer_Car_Details *ccd; 
	int _fSize = 0;
	char tmpBuff[MAX] = {'\0', };
	
	fp = fopen("./data/Customer_Car_Details.dat","r+");
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
		memset(tmpBuff,'\0', MAX);
		// head = newNode;
		while(fgets(tmpBuff, MAX, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
				newNode->next = NULL;
				head = newNode;
				ccd = newNode;
				tokenizeccd(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
				newNode->next = NULL;
				ccd->next = newNode;
				tokenizeccd(newNode, tmpBuff);
				ccd = ccd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}

int writeccD(Customer_Car_Details *ccd)
{
	FILE *fp = NULL;

	fp = fopen("./data/Customer_Car_Details.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(ccd == NULL)
		printf("\n\t NULL Write ccd");
	while(ccd != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%d| %s| %s| %s| %c\n",ccd->capacity,ccd->cust_name,ccd->pick,ccd->drop,ccd->_gender);
		ccd = ccd->next;
	}

	fclose(fp);
    return 0;
}


int tokenizeccd(Customer_Car_Details *ccd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, "|");
	//tokens = strtok(NULL, ",");
	//removeLeading(tokens,ccd->capacity);
	ccd->capacity = atoi(tokens);

	tokens = strtok(NULL, "|");
	removeLeading(tokens,ccd->cust_name);

	tokens = strtok(NULL, "|");
	removeLeading(tokens,ccd->pick);
	tokens = strtok(NULL, "|");
	removeLeading(tokens,ccd->drop);
	//removeTrailing(cd->_passwrd);
    tokens = strtok(NULL, "|");
	ccd->_gender =  atoi(tokens);
	tokens = strtok(NULL, "|");
	//ccd->_gender = tokens[0];
	 //tokens[0];
    return 0;
}


int cap(Customer_Car_Details *ccd)
{
	
	int cost=653;
	int price=0;
	FILE *fp = NULL;
	fp = fopen("./data/Customer_Car_Details.dat","w+"); 
     //while(ccd != NULL){
	fseek(fp, 0L, SEEK_END);
	if(ccd != NULL)
	{
		printf("\n\tCapacity: ");
		printf("%d",ccd->capacity);
		
		//printf("\n\tEnter cost: ");
		//getchar();
		//scanf("%d",&cost);
		price = (ccd->capacity) * cost;
		printf("\n\tcost is %d\n\t",price);
		}
		//exit(EXIT_SUCCESS);
		//ccd = ccd->next;
	 //}break;
	 return 0;
}

int updateDetails(DD *head)
{
	//int _id;
	DD _dd;
	int flag = 0;
	printf("\n Enter your id to update:");
	getchar();
	//scanf("%d",&newNode->_id);
	scanf("%d",&_dd._id);
	while(head != NULL)
	{
		if(head->_id == _dd._id)
		{
			//flag = 1;
			printf("\n Enter name to update:");
			getchar();
			scanf("%[^\n]s",_dd._name);
			//head->_name == _dd._name;
			strcpy(head->_name,_dd._name);
			//free(head);
			writeDD(head);
			//dispDD(head);
			break;
		}
		head = head->next;
	}
	//writeDD(head);

	if(flag == 1)
		return 1;
	return 0;
}

void checkBookedTrips(Customer_Car_Details *ccd)
{
	char name[20];
	printf("\n\tEnter your name :");
	scanf("%s",name);
        while(ccd != NULL)
        {
		if(strcmp(ccd->cust_name,name)==0)
		{
                printf("\n\tCapacity: ");
                printf("%d",ccd->capacity);
                printf("\tCustomer Name: ");
                printf("%s",ccd->cust_name);
                printf("\n\tpick up address: ");
                printf("%s",ccd->pick);
                printf("\tDrop off address: ");
                printf("%s",ccd->drop);
	        printf("\tGender: ");
                printf("%c",ccd->_gender);
		}
		ccd = ccd->next;
      }
	  
}

int markCompleteTrips(Customer_Car_Details *ccd)
{
  int choice;
  int amt;
  int a;
  printf("\n\t1.Trip Completed\n\t2.Exit\n\tchoice: ");
  scanf("%d",&choice);
  switch(choice)
         {
           case 1:
		   		   //cap(ccd);
                   printf("\n\tEnter the amount of your customer:");
                   scanf("%d",&amt);
		   printf("\nYour Amount is %d ",amt);
		   printf("\n\tEnter 1 for completed the trip : ");
		   scanf("%d",&a);
				   if(a==1)
				   {
                  		 printf("\n\tThe Trip is Completed\n");
				   }
				   else
				   {
					printf("\n payment has not done");
				   }
                   break;
           case 2:
                   exit(0);
           default:
                    printf("INVALID CHOICE");
		 }
		 return 0;
}

int makePayment()
{ 
	int ch =0;
	//cap(Customer_Car_Details);
	printf("\n\tEnter value 1/0 to make payment:\n");
    scanf("%d",&ch);
    if(ch==1)
	{
        printf("\n Payment is done");
	}
    else
	{
        printf("\n Not done");
	}
	return 0;
}

int bill()
{
	int cap=0;
	int bill=0;
	printf("\n\tEnter capacity:");
	scanf("%d",&cap);
	bill=cap*150;
	printf("Your amount is:%d", bill);
	return 0;

}

void cab_Details()
{
        FILE* ptr;
        char ch;

        ptr = fopen("./data/cab.txt", "r");


         if (NULL == ptr) {

          printf("file can't be opened \n");
            }


           printf(": D_ID  C_TYPE  NO_OF_SEATS \n");
           do {

                 ch = fgetc(ptr);

                  printf("%c", ch);

                 } while (ch != EOF);

         fclose(ptr);

}
int update()
{
	FILE *ft;
	char name[20];
	ft = fopen("./data/cab.txt", "r+");
	if(ft==NULL)
	{
		printf("can not open target file\n");
		exit(1);
	}
	printf("\n\t Enter name:");
	scanf("%s",name);
	fprintf(ft,"%s",name);
	fclose(ft);
	return 0;

}
/*
int isValidDate(struct tm dt)
 {
     if(dt.tm_year >= 2020 && dt.tm_year <= 2022)
     {
         //check month
         if(dt.tm_mon>=1 && dt.tm_mon<=12)
         {
         //check days
             if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 ||                                                    dt.tm_mon==10 || dt.tm_mon==12))
                 return (1);

             else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
                 return (1);
             else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                 return (1);
             else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
                 return (1);
             else
             return 0;
         }
         else
         {
             return 0;
         }
     }
     else
     {
         return 0;
     }
}


ST* scheduleTrip(ST *st, int *_id)
{
    ST *newNode =NULL;
    ST *head = NULL;
    head = st;
    int _status;
    int i;

    newNode = (ST *)malloc(sizeof(ST));
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
         st = newNode;
    }
    else
    {
        while(st->next != NULL)
        st = st->next;
        st->next = newNode;
        st = st->next;
    }
    printf("\n\tEnter No of seats: ");
     scanf("%d",&newNode->capacity);
     printf("\n\tEnter Customer Name: ");
     getchar();
     scanf("%[^\n]s",newNode->cust_name);
     printf("\n\tEnter Pick address: ");
     getchar();
     scanf("%[^\n]s",newNode->pick);
     printf("\n\tEnter drop address: ");
     getchar();
     scanf("%[^\n]s",newNode->drop);
     printf("\n\tEnter Gender (M/F/O): ");
     getchar();
     scanf("%c",&newNode->_gender);
     printf("Enter start date (dd/m/yyyy):");
     if(i==1)
     {
         do
         {
             scanf("%d/%d/%d",&st->sd.tm_mday,&st->sd.tm_mon,&st->sd.tm_year);
             int datevalid=isValidDate(st->sd);
             if(datevalid==0)
             {
                 printf("wrong date");
             }
             else
                 break;
         }
         while(1);

         printf("Enter end date (dd/m/yyyy):");
         do
         {
             scanf("%d/%d/%d",&st->ed.tm_mday,&st->ed.tm_mon,&st->ed.tm_year);
             int datevalid=isValidDate(st->ed);
             if(datevalid==0)
             {
                 printf("wrong date");
             }
             else
             {
                 printf("\n\tEnter 1/0 for booking : ");
                 scanf("%d",&_status);
                 if(_status == 1)
                 {
                     printf("\n\tBooking succesfull");
                     //  cap(ccd);
                     //scanf("%d",&_status);
                 }
                 else
                 {
                     printf("\n Booking cancelled");
                 }
                 break;
                 //  *_id = newNode->capacity;
             }

         }
 }

     *_id = newNode->capacity;
     return head;
 }

*/
