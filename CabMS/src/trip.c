#include <common.h>
#include <trip.h>


TRIP * bookTrip(TRIP * head, int *bid)
{
	TRIP *newNode = NULL;
	TRIP *tmpNode = head;

	newNode = (TRIP*)malloc(sizeof(TRIP));
	newNode->next = NULL;
	printf("\n\t============Booking============\n");
	printf("\n\tEnter,");
	printf("\n\tTrip ID: ");
	scanf("%d",&newNode->_tid);
	printf("\n\tCust ID: ");
	scanf("%d",&newNode->_cid);
	printf("\n\tDriver ID: ");
	scanf("%d",&newNode->_did);
	printf("\n\tSource: ");
	getchar();
	scanf("%[^\n]s", newNode->src);
	printf("\n\tDestination: ");
	getchar();
	scanf("%[^\n]s", newNode->dst);
	printf("\n\tTravel Date: ");
	getchar();
	scanf("%[^\n]s", newNode->tdate);
	newNode->status = 0;

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

	*bid =  newNode->_tid;
	return head;
}

void printBook(TRIP* thead, CUST* chead, DRIVER* dhead, int _tid)
{
	char cName[20], dName[20], cabType[20], cabRegNo[20];
	char tStatus[20];
	int flag = 0;
	while(thead!=NULL)
	{
		if(thead->_tid == _tid)
		{
			flag = 1;
			break;
		}
		thead = thead->next;
	}

	
	printf("\n\t===========Booking Details===============\n");
	if(flag == 1){
		while(chead != NULL)
		{
			if(chead->_id == thead->_cid){
				strcpy(cName, chead->name);
				break;
			}
			chead = chead->next;
		}

		while(dhead != NULL)
		{
			if(dhead->_id == thead->_did){
				strcpy(dName, dhead->name);
				strcpy(cabType, dhead->CAR.carModel);
				strcpy(cabRegNo, dhead->CAR.carRegNo);
				break;
			}
			dhead = dhead->next;
		}
		if(thead->status == 0)
			strcpy(tStatus, "Ongoing");
		else
			strcpy(tStatus,"Completed");
		printf("\n\tBooking ID: %d", thead->_tid);
		printf("\n\tCustomer Name: %s", cName);
		printf("\n\tSource: %s", thead->src);
		printf("\n\tDestination: %s", thead->dst);
		printf("\n\tTravel Date: %s", thead->tdate);
		printf("\n\tCab Driver Name: %s", dName);
		printf("\n\tCar Model: %s", cabType);
		printf("\n\tCab Reg No: %s", cabRegNo);	
		printf("\n\tStatus: %s", tStatus);
	}
	else
		printf("\n\tNo Booking on %d ID", _tid);
}


//int checkDrv(TRIP *, DRIVER*, int);

void dispTrip(TRIP *head)
{
	TRIP _dd;
	printf("\n Enter your id :");
	getchar();
	scanf("%d",&_dd._tid);
	while(head != NULL)
	{
		if(head->_tid == _dd._tid)
		{
			printf("\n\tTrip id:%d",head->_tid);
			printf("\n\tCus id:%d",head->_cid);
			printf("\n\tDri id:%d",head->_did);
			printf("\n\tStatus:%d",head->status);
			printf("\n\tsrc :%s",head->src);
			printf("\n\tDest :%s",head->dst);
			printf("\n\tDate :%s",head->tdate);
			head = head->next;
		}
	}
}

int markCompleteTrips(TRIP *thead)
{
    int choice;
     int amt;
     int a;
     char tStatus[20];
     printf("\n\t1.Trip Completed\n\t2.Exit\n\tchoice: ");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:
             printf("\n\tEnter the amount of your customer:");
             scanf("%d",&amt);
             printf("\n\tEnter 1 for Status:");
             scanf("%d",&a);
             if(thead->status == 0)
                 strcpy(tStatus, "Ongoing");
			else
                 strcpy(tStatus,"Completed");
             break;
         case 2:
             exit(0);
         default:
             printf("INVALID CHOICE");
     }
     return thead->status;
}


int writeTripDetails(TRIP* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/TRIP.dat","w+");
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
		fprintf(fp,"%d, %d, %d, %d, %s, %s, %s\n",head->_tid,head->_cid,head->_did,head->status,head->src,head->dst,head->tdate);
		head = head->next;
	}
	fclose(fp);
	return 0;
}


TRIP* loadTripDetails()
{
	FILE *fp = NULL;
	TRIP *newNode = NULL;
	TRIP *head = NULL;
	TRIP *trip; 
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };
	
	fp = fopen("./data/TRIP.dat","r+");
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
				newNode = (TRIP *)malloc(sizeof(TRIP));
				newNode->next = NULL;
				head = newNode;
				trip = newNode;
				tokenizeTRIP(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (TRIP *)malloc(sizeof(TRIP));
				newNode->next = NULL;
				trip->next = newNode;
				tokenizeTRIP(newNode, tmpBuff);
				trip = trip->next;	
			}
			

		}

	}

	fclose(fp);
	// printf("\n\tHead : %u\nlast node: %u\n", head, pd);
	return head;
}


int tokenizeTRIP(TRIP *trip, char *tmpBuff)
{
	char *tokens;
	//int i, count;
	//char *tmpBuff1;
	tokens = strtok(tmpBuff, ",");
	trip->_tid = atoi(tokens);
	tokens = strtok(tmpBuff, ",");
	trip->_cid = atoi(tokens);
	tokens = strtok(tmpBuff, ",");
	trip->_did = atoi(tokens);
	tokens = strtok(tmpBuff, ",");
	trip->status = atoi(tokens);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,trip->src);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,trip->dst);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,trip->tdate);
	tokens = strtok(NULL, ",");
	//cd->_gender = tokens[0];
    return 0;

	//dispPD(pd);
}

