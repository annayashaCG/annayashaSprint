#include <app.h>

int main()
{
	DD *dd = NULL;
	DD *headdd = NULL;
	CD *cd = NULL;
	CD *headcd = NULL;
    Customer_Car_Details *ccd = NULL;
	Customer_Car_Details *headccd = NULL;
	int ch = 0, _id=0;
    char _name[256] = {'\0', };
    memset(_name, '\0', 256);
   // char _name[30];
    //char _passwrd[30];
	headdd = loadDD(dd);/*loading driver details from DD.dat*/
	headcd = loadCD(cd);/*loading Customer details from CD.dat*/
    headccd = loadccD(ccd);
    while(1)
    {
        printf("\n\t           *************************  Welcome  ************************   \n\t");
        printf("\n\t                            CAB BOOKING MANAGEMENT SYSTEM                       \n\t");
        printf("\n\t           ************************************************************    \n\t");
        printf("\n\tPress\n\t1. Register new Customer\n\t2. Register new Cab Driver\n\t3. login as Customer\n\t4. login as Cab Driver\n\t0. Quit\n\tChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    headcd = signUpCustomer(headcd,&_id);
                    writeCD(headcd);
                    printf("\n\tSuccessfully Registered\n");
                    sleep(2);
                    break;
            case 2:
                    headdd = signUpDriver(headdd,&_id);
                    writeDD(headdd);
                    printf("\n\tSuccessfully Registered\n");
                    sleep(2);
                    break;

            case 3:
                    if(signInCustomer(headcd) == 0){
                        printf("\n\tUser/password does not match db\n");

                    }
                    else
                    {
                        printf("\n\tLogged In\n");
                        while(1)
                        {
                            
                            printf("\n\t           *************************  Welcome  ************************   \n\t");
                            printf("\n\t                                    USER SCREEN                      \n\t");
                            printf("\n\t           ************************************************************    \n\t");
                            printf("\n\tPress\n\t1. Book Trip\n\t2. Check cab Driver Details\n\t3. Check cab Details\n\t4. Check Bill\n\t5. Make Payment\n\t0. Quit\n\tChoice: ");

                            scanf("%d",&ch);
                            switch(ch)
                            {
                                case 1:
                                    headccd=bookTrip(headccd, &_id);
                                    writeccD(headccd);
                                    //bill(headccd);
                                    sleep(1);
                                    break;
                                case 2:
                                    printf("\n\t Car details are:\n");
                                    dispDD(headdd,_id);
                                    printf("\n");
                                    sleep(1);
                                    break;
                                case 3:
                                    printf("Cab Details");
                                    cab_Details();
                                    sleep(1);
                                    break;
                                case 4:
                                // bill();
                                    cap(headccd);
                                    printf("\n");
                                    sleep(1);
                                    break;
                                case 5:
                                    makePayment();
                                    printf("\n");
                                    sleep(1);
                                    break;
                                case 0:
                                      printf("\n\tReturning back to Main Menu\n");
                                      break;
                               // exit(EXIT_SUCCESS);
                        
                                default:
                                    printf("Incorrect Choice:");
                            }
			    ch = 0;
			    break;

                        }
                        //printf("\n\n");
                        //return 0;
                    }
                    
                    sleep(2);
                    break;
            case 4:
                    if(signInDriver(headdd) == 0){
                        printf("\n\tUser/password does not match db\n");

                    }
                    else
                    {
                         printf("\n\tLogged In\n");
                        while(1)
                        {
                            //dispDD(headdd);
                           // printf("\n\tLogged In\n");
                            printf("\n\t           *************************  Welcome  ************************   \n\t");
                            printf("\n\t                                    CAB DRIVER SCREEN                      \n\t");
                            printf("\n\t           ************************************************************    \n\t");
                            printf("\n\tPress\n\t1. Update Profile\n\t2. Manage Car dDetails\n\t3. Check Book Trip\n\t4. Marked completed\n\t0. Quit\n\tChoice: ");
                            scanf("%d",&ch);
                            switch(ch)
                            {
                                case 1:
                                    updateDetails(headdd);
                                    writeDD(headdd);
                                    dispDD(headdd,_id);
                                    sleep(1);
                                    break;
                                case 2:
                                    printf("\n\t Manage car details");
				    update();
				    sleep(1);
				    break;
                                
                                case 3:
                                    checkBookedTrips(headccd);
                                    sleep(1);
                                    break;
                                case 4:
                                    markCompleteTrips(headccd);
                                    sleep(1);
                                    break;
                                case 0:
                                    printf("\n\tReturning back to Main Menu\n");
                                    break;
                                default:
                                    printf("\nEnter correct choice\n");
                            }
			    ch =0;
			    break;

                        }
                        //printf("\n\n");
	                   // return 0;
                    }
                    sleep(2);
                    break;

            case 0:
		    printf("\n\t           *************************  THANK YOU  ************************   \n");
                    exit(EXIT_SUCCESS);
                    
            default:
                    printf("Incorrect Choice:");
        }
   
    }

    
	printf("\n\n");
	return 0;
}
