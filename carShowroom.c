#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stockchild
{
    char carName[18];
    char carColor[10];
    char fuelType[10];
    char carType[10];
    struct stockchild *childnext;
} carModelData;

// structure for stock details in showroom
typedef struct stocknode
{
    char noOfCarModels[10];
    char soldCarsNo[10];
    int availCarsInStock;
    char reqStock[10];
    struct stocknode *Stocknext;
    carModelData *carModelDataHead;
} stockDetails;

// structure for car details of purchased cars
typedef struct Carnode
{
    char carName[18],carColor[10],fuelType[10],carType[10 ],insuranceEval[10],salesAgent[10];
    char customerName[10],customerMob[11],carRegNo[4];
    char ActualPrice[10],EMI[10],balancedAmount[10],servicingCount[2];
    struct Carnode *Carnext;
} purchasedCar;
purchasedCar *carHead=NULL,*carTemp,*carNewNode;

//structure for Sales Person
typedef struct SPnode
{
    char spId[10], spName[10], spDOB[11], spAddr[10];
    char salesTarget[10], salesAchieved[10], commission[10];
    int data;
    struct SPnode *next;
} salesPerson;

//structure for bestselling car
typedef struct bestSelling
{
    int count;
    char carName[18];
} popularCar;

//Global variables
salesPerson *SPhead = NULL;
stockDetails *showRoomHead = NULL;
popularCar *bestSeller;
void storeSalesPerson()
{
    salesPerson *SPtemp, *newNode;
    char str[18], *p;
    int count = 0;
    FILE *fptr;
    fptr = fopen("salesPerson.txt", "r");
    while (count < 15)
    {
        newNode = (salesPerson *)malloc(sizeof(salesPerson));
        fscanf(fptr, "%s", &str);
        strcpy(newNode->spId, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->spName, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->spDOB, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->spAddr, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->salesTarget, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->salesAchieved, str);
        fscanf(fptr, "%s", &str);
        strcpy(newNode->commission, str);
        newNode->next = NULL;

        if (SPhead == NULL)
        {
            SPhead = newNode;
            SPtemp = newNode;
        }
        else
        {
            SPtemp->next = newNode;
            SPtemp = newNode;
        }

        count++;
    }
    fclose(fptr);
}

void printSalesPerson()
{
    salesPerson *SPtemp;
    SPtemp = SPhead;
    printf("\nSales Person Details:\n");
    while (SPtemp != NULL)
    {
        printf("%s ", SPtemp->spId);
        printf("%s ", SPtemp->spName);
        printf("%s ", SPtemp->spDOB);
        printf("%s ", SPtemp->spAddr);
        printf("%s ", SPtemp->salesTarget);
        printf("%s ", SPtemp->salesAchieved);
        printf("%s\n", SPtemp->commission);
        SPtemp = SPtemp->next;
    }
}

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
        stockNewNode->availCarsInStock = num;
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
        printf("%d ", showRoomTemp->availCarsInStock);
        printf("%s\n", showRoomTemp->reqStock);
        availCarNo = showRoomTemp->availCarsInStock;
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

carModelData * MergeShowRoom()
{
    carModelData *mergedAvailCar, *carModelDataTemp;
    stockDetails *showRoomTemp;
    int count = 1;
    int availCarNo = showRoomHead->availCarsInStock;
    mergedAvailCar = showRoomHead->carModelDataHead;
    carModelDataTemp = mergedAvailCar;
    while(count < availCarNo){
        carModelDataTemp = carModelDataTemp->childnext;
        count++;
    }
    count = 1;
    showRoomTemp = showRoomTemp->Stocknext;
    availCarNo = showRoomTemp->availCarsInStock;
    carModelDataTemp->childnext = showRoomTemp->carModelDataHead;
    carModelDataTemp = carModelDataTemp->childnext;
    while (count < availCarNo)
    {
        carModelDataTemp = carModelDataTemp->childnext;
        count++;
    }
    showRoomTemp = showRoomHead->Stocknext;
    carModelDataTemp->childnext = showRoomTemp->carModelDataHead;
    carModelDataTemp = carModelDataTemp->childnext;
    return mergedAvailCar;
}

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
        printf("Car %s Agent %s\n", purchasedCarBucketArray[count]->carName, agentIDMax);
    }
}

int main()
{
    char str[18],agentName[10],agentId[5],p[5];
    storeSalesPerson();
    printSalesPerson();
    storeShowRoomDetails();
    printShowRoomDetails();
    
    int soldCarsCount=60;
    int count=0;
    FILE *fptr3;
    fptr3=fopen("purchasedCar.txt","r");
    while (count<soldCarsCount)
    {
        carNewNode=(purchasedCar *)malloc(sizeof(purchasedCar));
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->customerName,str);
        printf("%s ",carNewNode->customerName);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->customerMob,str);
        printf("%s ",carNewNode->customerMob);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carName,str);
        printf("%s ",carNewNode->carName);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carColor,str);
        printf("%s ",carNewNode->carColor);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carRegNo,str);
        printf("%s ",carNewNode->carRegNo);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->fuelType,str);
        printf("%s ",carNewNode->fuelType);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->carType,str);
        printf("%s ",carNewNode->carType);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->servicingCount,str);
        printf("%s ",carNewNode->servicingCount);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->ActualPrice,str);
        printf("%s ",carNewNode->ActualPrice);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->EMI,str);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->balancedAmount,str);
        printf("%s ",carNewNode->balancedAmount);
        printf("%s ",carNewNode->EMI);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->salesAgent,str);
        printf("%s\n",carNewNode->salesAgent);
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

    bestSalesPersonSort();

    // FILE *fptr4;
    // fptr4=fopen("Carmodels.txt","r");
    // bestSeller=(popularCar *)malloc(sizeof(popularCar)*16);
    // count=0;
    // fptr4=fopen("Carmodels.txt","r");
    // while (count<15)
    // {
    //     fscanf(fptr4,"%s",&str);
    //     carTemp=carHead;
    //     strcpy(bestSeller[count].carName,str);
    //     printf("%s\n",bestSeller[count].carName);
    //     bestSeller[count].count=0;
    //     while (carTemp!=NULL)
    //     {
    //         if (strcmp(carTemp->carName,str)==0)
    //         {
    //             bestSeller[count].count++;
    //         }
    //         carTemp=carTemp->Carnext;

            
            
    //     }
    //     printf("%d\n",bestSeller[count].count);
    //     if (bestSeller[count].count>maxBestSaleCount)
    //     {
    //         maxBestSaleCount=bestSeller[count].count ;
    //     }
        
    //     count++;
        
    // }
    // printf("Max best sale %d\n",maxBestSaleCount);
    // fclose(fptr4);
    // count=0;
    // printf("Best seller car/cars are\n");
    // while (count<16)
    // {
    //     if (bestSeller[count].count==maxBestSaleCount)
    //     {
    //         printf("%s ",bestSeller[count].carName);
    //     }
    //     count++;
        
    // }
    // printf("\n");
    // int found=0;
    // float total=0.0,balance=0.0;
    // printf("Enter the sales agent name\n");
    // scanf("%s",&agentName);
    // printf("Agent name is %s\n",agentName);
    // SPtemp=SPhead;
    // while (SPtemp!=NULL && found!=1)
    // {
    //     if (strcmp(SPtemp->spName,agentName)==0)
    //     {
    //         found=1;
    //         strcpy(agentId,SPtemp->spId);
    //     }
    //     else
    //     {
    //         SPtemp=SPtemp->next;
    //     }
        
    // }
    // carTemp=carHead;
    // while (carTemp!=NULL)
    // {
    //     if (strcmp(carTemp->salesAgent,agentId)==0)
    //     {
    //         i=0;
    //         while (carTemp->balancedAmount[i]!='l')
    //         {
    //             p[i]=carTemp->balancedAmount[i];
    //             i++;
    //         }
    //         balance=atoi(p);
    //         printf("Balance %f\n",balance);
    //         total=total+balance;
    //     }
    //     carTemp=carTemp->Carnext;
        
    // }
    // printf("Total %f\n",total);
    
    // //start of predict sales for a given car
    // float x,y;
    // found=0,total=0;
    // printf("Enter the car name to predict sales\n");
    // scanf("%s",&str);
    // for ( count = 0; count < 15 && found!=1; count++)
    // {
    //     if (strcmp(str,bestSeller[count].carName)==0)
    //     {
    //         found=1;
    //     }
        
    // }
    // count--;
    // printf("%d %s\n",count,bestSeller[count].carName);
    // carTemp=carHead;
    // while (carTemp!=NULL)
    // {
    //     SPtemp=SPhead;
    //     if (strcmp(carTemp->carName,str)==0)
    //     {
    //         while (SPtemp!=NULL)
    //         {
    //             if (strcmp(carTemp->salesAgent,SPtemp->spId)==0)
    //             {
    //                 x=atof(SPtemp->salesTarget);
    //                 y=atof(SPtemp->salesAchieved);
    //                 total=total+(bestSeller[count].count*(y/x));
    //                 printf("Total %f\n",total);
    //             }
    //             SPtemp=SPtemp->next;
                
    //         }
            
    //     }
    //     carTemp=carTemp->Carnext;
        
    // }
    return 0;
}
