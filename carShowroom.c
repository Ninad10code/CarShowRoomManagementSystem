#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stockchild
{
    char carName[18];
    char carColor[10] ;
    char fuelType[10];
    char carType[10] ;
    struct stockchild *childnext;
} carModelData;

// structure for stock details in showroom
typedef struct stocknode
{
    char noOfCarModels[10] ;
    char soldCarsNo[10];
    int avialCarsInStock;
    char reqStock[10];
    struct stocknode *Stocknext;
    carModelData *carModelDataHead,*carModelDataTemp,*carModelDataNewnode;
    
    
} stockDetails;

// structure for car details of purchased cars
typedef struct Carnode
{

    char carName[18],carColor[10],fuelType[10],carType[10],insuranceEval[10],salesAgent[10];
    char customerName[11],customerMob[11],carRegNo[4];
    char ActualPrice[10],EMI[10],balancedAmount[10],servicingCount[2];
    int traverseStatus;
    struct Carnode *Carnext;    

} purchasedCar;

//structure for Sales Person
typedef struct SPnode
{
    char spId[10],spName[10],spDOB[11],spAddr[10];
    char salesTarget[10],salesAchieved[10],commission[10];
    int data;
    struct SPnode *next;
} salesPerson;

// Structure for best Salesperson award
typedef struct SPAward
{
    int carCount;
    char *salesAgentId[16],carName[18];
} carAward;

typedef struct bestSelling
{
    int count;
    char carName[18];
} popularCar;



salesPerson *SPhead=NULL,*SPtemp,*newNode;
stockDetails *showRoomHead=NULL,*showRoomtemp,*stocckNewNode; 
purchasedCar *carHead=NULL,*carTemp,*carNewNode;
popularCar *bestSeller;

void storeShowRoomDetails()
{
    stockDetails *showRoomTemp, *stockNewNode;
    carModelData *carModelDataNewnode, *carModelDataTemp;
    int showRoomCount, availCarNo, num, countModel, i, count;
    char str[15];
    FILE *fptr;
    fptr = fopen("stockDetails.txt", "r");
    showRoomCount = 3;
    countModel = count = i = 0;
    while (count < showRoomCount)
    {
        stockNewNode = (stockDetails *)malloc(sizeof(stockDetails));
        fscanf(fptr, "%s", &str);
        strcpy(stockNewNode->noOfCarModels, str);
        fscanf(fptr, "%s", &str);
        strcpy(stockNewNode->soldCarsNo, str);
        fscanf(fptr, "%d", &num);
        stockNewNode->avialCarsInStock = num;
        availCarNo = num;
        fscanf(fptr, "%s", &str);
        strcpy(stockNewNode->reqStock, str);
        stockNewNode->carModelDataHead = NULL;
        while (countModel < availCarNo)
        {
            carModelDataNewnode = (carModelData *)malloc(sizeof(carModelData));
            fscanf(fptr, "%s", &str);
            strcpy(carModelDataNewnode->carName, str);
            fscanf(fptr, "%s", &str);
            strcpy(carModelDataNewnode->carColor, str);
            fscanf(fptr, "%s", &str);
            strcpy(carModelDataNewnode->fuelType, str);
            fscanf(fptr, "%s", &str);
            strcpy(carModelDataNewnode->carType, str);
            carModelDataNewnode->childnext = NULL;
            if (stockNewNode->carModelDataHead == NULL)
            {
                stockNewNode->carModelDataHead = carModelDataNewnode;
                carModelDataTemp = carModelDataNewnode;
            }
            else
            {
                carModelDataTemp->childnext = carModelDataNewnode;
                carModelDataTemp = carModelDataNewnode;
            }
            countModel++;
        }
        stockNewNode->Stocknext = NULL;
        if (showRoomHead == NULL)
        {
            showRoomHead = stockNewNode;
            showRoomTemp = stockNewNode;
        }
        else
        {
            showRoomTemp->Stocknext = stockNewNode;
            showRoomTemp = stockNewNode;
        }
        count++;
        countModel = 0;
    }
    fclose(fptr);
}

void printShowRoomDetails(){
    stockDetails *showRoomTemp;
    carModelData *carModelDataTemp;
    int countModel, availCarNo;
    showRoomTemp = showRoomHead;
    printf("\nShow Room Details:\n");
    while(showRoomTemp != NULL){
        printf("\nShow Room:\n");
        printf("%s ", showRoomTemp->noOfCarModels);
        printf("%s ", showRoomTemp->soldCarsNo);
        printf("%d ", showRoomTemp->avialCarsInStock);
        printf("%s\n", showRoomTemp->reqStock);
        availCarNo = showRoomTemp->avialCarsInStock;
        countModel = 0;
        carModelDataTemp = showRoomTemp->carModelDataHead;
        while (countModel < availCarNo)
        {
            printf("%s ", carModelDataTemp->carName);
            printf("%s ", carModelDataTemp->carColor);
            printf("%s ", carModelDataTemp->fuelType);
            printf("%s\n", carModelDataTemp->carType);
            carModelDataTemp = carModelDataTemp->childnext;
            countModel++;
        }
        showRoomTemp = showRoomTemp->Stocknext;
    }
}

void bestSellingCar()
{
    //start of best selling car
    int count=0,maxBestSaleCount=0;
    char str[18];
    count=0;
    FILE *fptr4;
    /*
    fptr4=fopen("Carmodels.txt","r");
    while (count<15)
    {
        fscanf(fptr4,"%s",&str);
        printf("%s\n",str);
        // carTemp=carHead;
        // while (carTemp!=NULL)
        // {
        //     SPtemp=SPhead;
        //     if (strcmp(carTemp->carName,str)==0 && carTemp->traverseStatus!=1)
        //     {
        //         carTemp->traverseStatus=1;


        //     }
            
        // }
        
        count++;
    }
    fclose(fptr4);
    */
    bestSeller=(popularCar *)malloc(sizeof(popularCar)*16);
    count=0;
    fptr4=fopen("Carmodels.txt","r");
    while (count<15)
    {
        fscanf(fptr4,"%s",&str);
        carTemp=carHead;
        strcpy(bestSeller[count].carName,str);
        // printf("%s\n",bestSeller[count].carName);
        bestSeller[count].count=0;
        while (carTemp!=NULL)
        {
            if (strcmp(carTemp->carName,str)==0)
            {
                bestSeller[count].count++;
            }
            carTemp=carTemp->Carnext;

            
            
        }
        // printf("%d\n",bestSeller[count].count);
        if (bestSeller[count].count>maxBestSaleCount)
        {
            maxBestSaleCount=bestSeller[count].count ;
        }
        
        count++;
        
    }
    printf("Max best sale of a car is %d\n",maxBestSaleCount);
    fclose(fptr4);
    count=0;
    printf("Best seller car/cars are\n");
    while (count<16)
    {
        if (bestSeller[count].count==maxBestSaleCount)
        {
            printf("%s ",bestSeller[count].carName);
        }
        count++;
        
    }
    printf("\n");
//end of best selling
}

void loanPending()
{
    //start of loan pending
    int found=0,i=0;
    float total=0.0,balance=0.0;
    char str[18],agentName[10],agentId[5],p[5];

    printf("Enter the sales agent name\n");
    scanf("%s",&agentName);
    printf("Agent name is %s\n",agentName);
    SPtemp=SPhead;
    while (SPtemp!=NULL && found!=1)
    {
        if (strcmp(SPtemp->spName,agentName)==0)
        {
            found=1;
            strcpy(agentId,SPtemp->spId);
        }
        else
        {
            SPtemp=SPtemp->next;
        }
        
    }
    carTemp=carHead;
    while (carTemp!=NULL)
    {
        if (strcmp(carTemp->salesAgent,agentId)==0)
        {
            i=0;
            while (carTemp->balancedAmount[i]!='l')
            {
                p[i]=carTemp->balancedAmount[i];
                i++;
            }
            // printf("%s\n",p);
            balance=atof(p);
            // printf("Balance %f\n",balance);
            total=total+balance;
        }
        carTemp=carTemp->Carnext;
        
    }
    printf("Total loan pending is %flkh\n",total);
    //End of loan pending
}

void predictSales()
{
    //start of sales prediction
    int count=0;
    char str[18];
    float x,y;
    float found=0,total=0;
    bestSeller=(popularCar *)malloc(sizeof(popularCar)*16);
    count=0;
    FILE *fptr4;
    fptr4=fopen("Carmodels.txt","r");
    while (count<15)
    {
        fscanf(fptr4,"%s",&str);
        carTemp=carHead;
        strcpy(bestSeller[count].carName,str);
        // printf("%s\n",bestSeller[count].carName);
        bestSeller[count].count=0;
        while (carTemp!=NULL)
        {
            if (strcmp(carTemp->carName,str)==0)
            {
                bestSeller[count].count++;
            }
            carTemp=carTemp->Carnext;

            
            
        }
        // printf("%d\n",bestSeller[count].count);
        
        
        count++;
        
    }
    fclose(fptr4);
    count=0;
    printf("Enter the car name to predict sales\n");
    scanf("%s",&str);
    for ( count = 0; count < 15 && found!=1; count++)
    {
        if (strcmp(str,bestSeller[count].carName)==0)
        {
            found=1;
        }
        
    }
    count--;
    // printf("%d %s\n",count,bestSeller[count].carName);
    carTemp=carHead;
    while (carTemp!=NULL)
    {
        SPtemp=SPhead;
        if (strcmp(carTemp->carName,str)==0)
        {
            while (SPtemp!=NULL)
            {
                if (strcmp(carTemp->salesAgent,SPtemp->spId)==0)
                {
                    x=atof(SPtemp->salesTarget);
                    y=atof(SPtemp->salesAchieved);
                    total=total+(y/x);
                    // printf("Total %f\n",total);
                }
                SPtemp=SPtemp->next;
                
            }
            
        }
        carTemp=carTemp->Carnext;
        
    }
    total=bestSeller[count].count*total;
    printf("Sales prediction is %d no of cars will get sold\n",(int)total);
    //end of sales prediction
}

void logTocustomerDetails()
{
    int found=0,customFound=0;
    char agentId[5],customerName[18];
    SPtemp=SPhead;
    carTemp=carHead;
    printf("Enter your sales ID to verify\n");
    scanf("%s",&agentId);
    while (SPtemp!=NULL && found!=1)
    {
        if (strcmp(agentId,SPtemp->spId)==0)
        {
            found=1;
            printf("Verified\n");
            printf("Enter the customer name you want to search for\n");
            scanf("%s",&customerName);
            while (carTemp!=NULL && customFound!=1)
            {
                if (strcmp(carTemp->customerName,customerName)==0)
                {
                    customFound=1;
                    printf("Customer Name: %s\n",carTemp->customerName);
                    printf("Customer Mobile: %s\n",carTemp->customerMob);
                    printf("Car name: %s\n",carTemp->carName);
                    printf("Car color: %s\n",carTemp->carColor);
                    printf("Registeration no: %s\n",carTemp->carRegNo);
                    printf("Fuel type: %s\n",carTemp->fuelType);
                    printf("Car type: %s\n",carTemp->carType);
                    printf("Servicing count: %s\n",carTemp->servicingCount);
                    printf("Car price: %s\n",carTemp->ActualPrice);
                    printf("EMI: %s\n",carTemp->EMI);
                    printf("Pending balanced: %s\n",carTemp->balancedAmount);
                    printf("Agent name: %s\n",carTemp->salesAgent);
                }
                carTemp=carTemp->Carnext;
                
            }
            if (customFound!=1)
            {
                printf("Customer name invalid\n");
            }
            
            
        }
        SPtemp=SPtemp->next;
        
    }
    if (found!=1)
    {
        printf("Invalid sales ID\n");
    }
    
    
}

void salesPersonLogin()
{
    char agentId[5];
    int found=0;
    SPtemp=SPhead;
    printf("Enter your sales ID\n");
    scanf("%s",&agentId);
    while (SPtemp!=NULL && found!=1)
    {
        if (strcmp(SPtemp->spId,agentId)==0)
        {
            found=1;
            printf("Verified\n");
            printf("Here are your details\n");
            printf("Sales ID: %s\n",SPtemp->spId);
            printf("Name: %s\n",SPtemp->spName);
            printf("DOB: %s\n",SPtemp->spDOB);
            printf("Address: %s\n",SPtemp->spAddr);
            printf("Sales Target: %s\n",SPtemp->salesTarget);
            printf("Sales Achieved: %s\n",SPtemp->salesAchieved);
            printf("Sales Commission: %s\n",SPtemp->commission);
        }
        
        SPtemp=SPtemp->next;
    }
    
}
void showRoomDetails()
{
    int showRoomCount=3,availCarNo,num,countModel=0,i=0,count=0;
    carModelData *carModelDataTemp;

    showRoomtemp=showRoomHead;
    while (showRoomtemp!=NULL)
    {
        printf("No of car models: %s\n",showRoomtemp->noOfCarModels);
        printf("Sold cars: %s\n",showRoomtemp->soldCarsNo);
        printf("Available stock: %d\n",showRoomtemp->avialCarsInStock);
        availCarNo=showRoomtemp->avialCarsInStock;
        printf("Required stock: %s\n",showRoomtemp->reqStock);
        
        showRoomtemp->carModelDataTemp=showRoomHead->carModelDataHead/*[count]*/;
        // carModelDataTemp = carModelDataHead;
        while (countModel < availCarNo)
        {
            printf("%s ", showRoomtemp->carModelDataTemp->carName);
            printf("%s ", showRoomtemp->carModelDataTemp->carColor);
            printf("%s ", showRoomtemp->carModelDataTemp->fuelType);
            printf("%s\n", showRoomtemp->carModelDataTemp->carType);
            showRoomtemp->carModelDataTemp = showRoomtemp->carModelDataTemp->childnext;
            countModel++;
        }
        countModel=0;
        // showRoomTemp = showRoomTemp->Stocknext;
        showRoomtemp=showRoomtemp->Stocknext;
        count++;
    }
    
}

void purchasedCarsDetails()
{
    carTemp=carHead;
    while (carTemp!=NULL)
    {
        printf("%s ",carTemp->customerName);
        printf("%s ",carTemp->customerMob);
        printf("%s ",carTemp->carName);
        printf("%s ",carTemp->carColor);
        printf("%s ",carTemp->carRegNo);
        printf("%s ",carTemp->fuelType);
        printf("%s ",carTemp->carType);
        // printf("%s ",carTemp->ActualPrice);
        // printf("%s ",carTemp->EMI);
        // printf("%s ",carTemp->balancedAmount);
        printf("%s\n",carTemp->salesAgent);
        carTemp=carTemp->Carnext;
    }
    
}

carModelData * MergeShowRoom()
{
    carModelData *mergedAvailCar, *carModelDataTemp;
    stockDetails *showRoomTemp;
    int count = 1;
    int availCarNo = showRoomHead->avialCarsInStock;
    mergedAvailCar = showRoomHead->carModelDataHead;
    carModelDataTemp = mergedAvailCar;
    while(count < availCarNo){
        carModelDataTemp = carModelDataTemp->childnext;
        count++;
    }
    count = 1;
    showRoomTemp = showRoomHead->Stocknext;
    availCarNo = showRoomTemp->avialCarsInStock;
    // carModelDataTemp = showRoomTemp->carModelDataHead;
    carModelDataTemp->childnext = showRoomTemp->carModelDataHead;
    carModelDataTemp = carModelDataTemp->childnext;
    while (count < availCarNo)
    {
        carModelDataTemp = carModelDataTemp->childnext;
        count++;
    }
    showRoomTemp = showRoomTemp->Stocknext;
    // carModelDataTemp = showRoomTemp->carModelDataHead;
    carModelDataTemp->childnext = showRoomTemp->carModelDataHead;
    carModelDataTemp = carModelDataTemp->childnext;
    return mergedAvailCar;
}

void printMergedDetails(carModelData * merged){
    carModelData *carModelDataTemp;
    int countModel, availCarNo;
    printf("\nMerged Show Room Details:\n");
    availCarNo = 31;
    countModel = 0;
    carModelDataTemp = merged;
    while (countModel < availCarNo)
        {
            printf("%s ", carModelDataTemp->carName);
            printf("%s ", carModelDataTemp->carColor);
            printf("%s ", carModelDataTemp->fuelType);
            printf("%s\n", carModelDataTemp->carType);
            carModelDataTemp = carModelDataTemp->childnext;
            countModel++;
        }
}

// try
void insert(purchasedCar **lptr, purchasedCar * node)
{
    purchasedCar *current; 
    char nodeSalesAgent[5], tempSalesAgent[5];
    strcpy(nodeSalesAgent, node->salesAgent);
    if ((*lptr)!=NULL)
    {
        strcpy(tempSalesAgent, (*lptr)->salesAgent);
    }
    else
    {
        strcpy(tempSalesAgent, "");
    }
    
    /* Special case for the head end */
    if ((*lptr) == NULL || strcmp(tempSalesAgent, nodeSalesAgent) > 0) 
    { 
        node->Carnext = *lptr; 
        *lptr = node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *lptr; 
        int flag = 0; 
        while (current->Carnext!=NULL && flag==0) 
        {
            strcpy(tempSalesAgent, current->Carnext->salesAgent);
            if(strcmp(tempSalesAgent, nodeSalesAgent) <= 0)
            {
                current = current->Carnext;
            }
            else
            {
                flag = 1;   
            }
        }
        node->Carnext = current->Carnext; 
        current->Carnext = node; 
    }
}

void bestSalesPersonSort()
{
    purchasedCar *purchasedCarDataTemp, *purchasedCarDataNext;
    int purchaseCount, soldCarsCount;
    purchaseCount = 0;
    soldCarsCount = 60;
    char str[15];
    purchasedCarDataTemp = carHead;
    purchasedCar * purchasedCarBucketArray[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    while (purchaseCount < soldCarsCount)
    {
        strcpy(str, purchasedCarDataTemp->carName);
        purchasedCarDataNext = purchasedCarDataTemp->Carnext;
        purchasedCarDataTemp->Carnext = NULL;
        if(strcmp(str, "Swift") == 0)
        {
            insert(&purchasedCarBucketArray[0], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Ciaz") == 0)
        {
            insert(&purchasedCarBucketArray[1], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Brezza") == 0)
        {
            insert(&purchasedCarBucketArray[2], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Cellero") == 0)
        {
            insert(&purchasedCarBucketArray[3], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Baleno") == 0)
        {
            insert(&purchasedCarBucketArray[4], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Alto") == 0)
        {
            insert(&purchasedCarBucketArray[5], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Alto800") == 0)
        {
            insert(&purchasedCarBucketArray[6], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Ertiga") == 0)
        {
            insert(&purchasedCarBucketArray[7], purchasedCarDataTemp);
        }
        else if (strcmp(str, "WagonR") == 0)
        {
            insert(&purchasedCarBucketArray[8], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Dzire") == 0)
        {
            insert(&purchasedCarBucketArray[9], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Mercedes-S-Class") == 0)
        {
            insert(&purchasedCarBucketArray[10], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Mercedes-AMG") == 0)
        {
            insert(&purchasedCarBucketArray[11], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Audi-A6") == 0)
        {
            insert(&purchasedCarBucketArray[12], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Audi-Q7") == 0)
        {
            insert(&purchasedCarBucketArray[13], purchasedCarDataTemp);
        }
        else if (strcmp(str, "Evoque") == 0)
        {
            insert(&purchasedCarBucketArray[14], purchasedCarDataTemp);
        }
        purchasedCarDataTemp = purchasedCarDataNext;
        purchaseCount++;
    }
    int count;
    char agentID[5], agentIDMax[5];
    int salesCount, salesCountMax;
    purchasedCarDataNext = NULL;
    for(count =0; count<15; count++)
    {
        purchasedCarDataTemp = purchasedCarBucketArray[count];
        salesCount = 0;
        salesCountMax = 0;
        strcpy(agentID, purchasedCarDataTemp->salesAgent); 
        strcpy(agentIDMax, purchasedCarDataTemp->salesAgent);
        while(purchasedCarDataTemp!=NULL){
            if(strcmp(agentID, purchasedCarDataTemp->salesAgent) == 0)
            {
                salesCount++;
            }
            else
            {
                if(salesCount > salesCountMax)
                {
                    strcpy(agentIDMax, agentID);
                    salesCountMax = salesCount;
                }
                salesCount = 1;
                strcpy(agentID, purchasedCarDataTemp->salesAgent);
            }
            printf("%s %s\n", purchasedCarDataTemp->carName, purchasedCarDataTemp->salesAgent);
            purchasedCarDataTemp = purchasedCarDataTemp->Carnext;
        }
        if(salesCount > salesCountMax)
        {
            strcpy(agentIDMax, agentID);
            salesCountMax = salesCount;
        }
        printf("Award for best sales person of  %s goes to Agent %s\n", purchasedCarBucketArray[count]->carName, agentIDMax);
    }
}
// end of try

void bestSalesPerson()
{

}
int main()
{

    char str[18],agentName[10],agentId[5],p[5];


    // str[10]=(char *)malloc(sizeof(char)*105);
    int count=0;
    FILE *fptr;
    fptr=fopen("salesPerson.txt","r");
    while (count<15)
    {
        // printf("inside while\n");
        newNode=(salesPerson *)malloc(sizeof(salesPerson));
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spId,str);
        // printf("%s ",newNode->spId);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spName,str);
        // printf("%s ",newNode->spName);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spDOB,str);
        // printf("%s ",newNode->spDOB);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spAddr,str);
        // printf("%s ",newNode->spAddr);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->salesTarget,str);
        // printf("%s ",newNode->salesTarget);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->salesAchieved,str);
        // printf("%s ",newNode->salesAchieved);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->commission,str);
        // printf("%s\n",newNode->commission);
        newNode->next=NULL;

        if (SPhead==NULL)
        {
            SPhead=newNode;
            SPtemp=newNode;
        }
        else
        {
            SPtemp->next=newNode;
            SPtemp=newNode;
        }
        
        
        count++;
        // unnecessary
        // printf("%d\n",count);
        //
        // newNode=(salesPerson *)malloc(sizeof(salesPerson));
        // fscanf(fptr,"%s",&newNode->spId);
        // fscanf(fptr,"%s",&newNode->spName);
        // fscanf(fptr,"%s",&newNode->spDOB);
        // fscanf(fptr,"%s",&newNode->spAddr);
        // fscanf(fptr,"%s",&newNode->salesTarget);
        // fscanf(fptr,"%s",&newNode->salesAchieved);
        // fscanf(fptr,"%s",&newNode->commission);
        // newNode->next=NULL;
        // if (SPhead==NULL)
        // {
        //     SPhead=newNode;
        //     SPtemp=newNode;
        // }
        // else
        // {
        //     SPtemp->next=newNode;
        //     SPtemp=newNode;
        // }
        // end of unnecessary
        
    }
    fclose(fptr);
    // printf("File closed\n");
    // printing of salesperson
    // SPtemp=SPhead;
    // while (SPtemp!=NULL)
    // {
    //     printf("%s ",SPtemp->spId);
    //     printf("%s ",SPtemp->spName);
    //     printf("%s ",SPtemp->spDOB);
    //     printf("%s ",SPtemp->spAddr);
    //     printf("%s ",SPtemp->salesTarget);
    //     printf("%s ",SPtemp->salesAchieved);
    //     printf("%s\n",SPtemp->commission);
    //     SPtemp=SPtemp->next;

    // }
    // end of printing of sales person 
    // Showroom insertion
    // int showRoomCount=3,availCarNo,num,countModel=0,i=0;
    // FILE *fptr2;
    // fptr2=fopen("stockDetails.txt","r");
    // count=0;
    // while (count<showRoomCount)
    // {
    //     stocckNewNode=(stockDetails *)malloc(sizeof(stockDetails));
    //     fscanf(fptr2,"%s",&str);
    //     strcpy(stocckNewNode->noOfCarModels,str);
    //     // printf("%s ",stocckNewNode->noOfCarModels);
    //     fscanf(fptr2,"%s",&str);
    //     strcpy(stocckNewNode->soldCarsNo,str);
    //     // printf("%s ",stocckNewNode->soldCarsNo);
    //     fscanf(fptr2,"%d",&num);
    //     stocckNewNode->avialCarsInStock=num;
    //     availCarNo=num;
    //     // printf("%d ",stocckNewNode->avialCarsInStock);
    //     fscanf(fptr2,"%s",&str);
    //     strcpy(stocckNewNode->reqStock,str);
    //     // printf("%s\n",stocckNewNode->reqStock);
    //     stocckNewNode->carModelDataHead/*[count]*/=NULL;
    //     while (countModel<availCarNo)
    //     {
    //         stocckNewNode->carModelDataNewnode=(carModelData *)malloc(sizeof(carModelData));
    //         fscanf(fptr2,"%s",&str);
    //         strcpy(stocckNewNode->carModelDataNewnode->carName,str);
    //         // printf("%s ",stocckNewNode->carModelDataNewnode->carName);
    //         fscanf(fptr2,"%s",&str);
    //         strcpy(stocckNewNode->carModelDataNewnode->carColor,str);
    //         // printf("%s ",stocckNewNode->carModelDataNewnode->carColor);
    //         fscanf(fptr2,"%s",&str);
    //         strcpy(stocckNewNode->carModelDataNewnode->fuelType,str);
    //         // printf("%s ",stocckNewNode->carModelDataNewnode->fuelType);
    //         fscanf(fptr2,"%s",&str);
    //         strcpy(stocckNewNode->carModelDataNewnode->carType,str);
    //         // printf("%s\n",stocckNewNode->carModelDataNewnode->carType);
    //         stocckNewNode->carModelDataNewnode->childnext=NULL;
    //         if (stocckNewNode->carModelDataHead/*[count]*/==NULL)
    //         {
    //             stocckNewNode->carModelDataHead/*[count]*/=stocckNewNode->carModelDataNewnode;
    //             stocckNewNode->carModelDataTemp=stocckNewNode->carModelDataNewnode;
    //         }
    //         else
    //         {
    //             stocckNewNode->carModelDataTemp->childnext=stocckNewNode->carModelDataNewnode;
    //             stocckNewNode->carModelDataTemp=stocckNewNode->carModelDataNewnode;
    //         }
    //         countModel++;
            
    //     }
    //     stocckNewNode->Stocknext=NULL;
    //     if (showRoomHead==NULL)
    //     {
    //         showRoomHead=stocckNewNode;
    //         showRoomtemp=stocckNewNode;
    //     }
    //     else
    //     {
    //         showRoomtemp->Stocknext=stocckNewNode;
    //         showRoomtemp=stocckNewNode;
    //     }
        
    //     count++;
    //     countModel=0;
        
        
    // }
    // fclose(fptr2);
    // End of showroom insertion

    storeShowRoomDetails();

    int soldCarsCount=60;
    count=0;
    FILE *fptr3;
    fptr3=fopen("purchasedCar.txt","r");
    while (count<soldCarsCount)
    {
        carNewNode=(purchasedCar *)malloc(sizeof(purchasedCar));
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->customerName,str);
        // printf("%s ",carNewNode->customerName);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->customerMob,str);
        // printf("%s ",carNewNode->customerMob);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carName,str);
        // printf("%s ",carNewNode->carName);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carColor,str);
        // printf("%s ",carNewNode->carColor);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carRegNo,str);
        // printf("%s ",carNewNode->carRegNo);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->fuelType,str);
        // printf("%s ",carNewNode->fuelType);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carType,str);
        // printf("%s ",carNewNode->carType);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->servicingCount,str);
        // printf("%s ",carNewNode->servicingCount);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->ActualPrice,str);
        // printf("%s ",carNewNode->ActualPrice);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->EMI,str);
        // printf("%s ",carNewNode->EMI);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->balancedAmount,str);
        // printf("%s ",carNewNode->balancedAmount);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->salesAgent,str);
        // printf("%s\n",carNewNode->salesAgent);
        carNewNode->Carnext=NULL;
        if (carHead==NULL)
        {
            carHead=carNewNode;
            carTemp=carNewNode;
        }
        else
        {
            carTemp->Carnext=carNewNode;
            carTemp=carNewNode;
        }
        
        
        count++;
    }

    fclose(fptr3);
    

    
    

    // carAward *defaultCar,*newcar;
    // defaultCar=(carAward*)malloc(sizeof(carAward));
    // fptr=fopen("salesPerson.txt","r");
    // count=0;
    // SPtemp=SPhead;
    // defaultCar->salesAgentId[16]=(char *)malloc(sizeof(malloc)*5);
    // while (SPtemp!=NULL)
    // {
    //     strcpy(defaultCar->salesAgentId[count],SPtemp->spId);
    //     printf("%s\n",defaultCar->salesAgentId[count]);
    //     SPtemp=SPtemp->next;
    //     count++;
    // }
    // fclose(fptr);
    int userInput,stop=0;
    carModelData *merged;
    while (stop!=1)
    {
        printf("----------------\n");
        printf("Enter the input to perform following operation\n");
        printf("1. Merge the databases of stock and caar details\n");
        printf("2. To find most popular car\n");
        printf("3. Total amount of loan pending for cars sold by sales person\n");
        printf("4. Sales person award for every car\n");
        printf("5. Predict sales of given car\n");
        printf("6. Log in to see customer details\n");
        printf("7. Login as Sales person\n");
        printf("8. Print showroom details\n");
        printf("9. Print the details of all purchased cars\n");
        printf("10. Exit\n");
        printf("----------------\n");
        scanf("%d",&userInput);
        switch (userInput)
        {
        case 1:
            merged=MergeShowRoom();
            printMergedDetails(merged);
            
            break;
        case 2:
            bestSellingCar();
            break;
        case 3:
            loanPending();
            break;
        case 4:
            bestSalesPersonSort();
            break;
        case 5:
            predictSales();
            break;
        case 6:
            logTocustomerDetails();
            break;
        case 7:
            salesPersonLogin();
            break;
        case 8:
            //showRoomDetails();
            printShowRoomDetails();
            break;
        case 9:
            purchasedCarsDetails();
            break;
        case 10:
            stop=1;
            printf("Thank you\n");
            break;
        default:
        printf("Invalid input\n");
            break;
        }
    }
    
    


    
    
}
