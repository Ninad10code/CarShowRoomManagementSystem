#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stockchild
{
    char carName[15];
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
    char carName[15],carColor[10],fuelType[10],carType[10 ],insuranceEval[10],salesAgent[10];
    char customerName[10],customerMob[10],carRegNo[4];
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

//Global variables
salesPerson *SPhead = NULL;
stockDetails *showRoomHead = NULL;

void storeSalesPerson()
{
    salesPerson *SPtemp, *newNode;
    char str[15], dtr[10], *p;
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

int main()
{
    storeSalesPerson();
    printSalesPerson();
    storeShowRoomDetails();
    printShowRoomDetails();
    
    FILE *fptr3;
    fptr3=fopen("purchasedCar.txt","r");
    while (count<soldCarsCount)
    {
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
        strcpy(carNewNode->balancedAmount,str);
        printf("%s ",carNewNode->balancedAmount);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->EMI,str);
        printf("%s ",carNewNode->EMI);
        fscanf(fptr3,"%s",&str);
        strcpy(carNewNode->salesAgent,str);
        printf("%s ",carNewNode->salesAgent);


    }
    fclose(fptr3);
}