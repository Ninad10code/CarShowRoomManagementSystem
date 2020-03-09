#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stockchild
{
    char carName[15];
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
    carModelData *carModelDataHead[3],*carModelDataTemp,*carModelDataNewnode;
    
    
} stockDetails;

// structure for car details of purchased cars
typedef struct Carnode
{
    char carName[15],carColor[10],fuelType[10],carType[10 ],insuranceEval[10],salesAgent[10];
    char customerName[10],customerMob[10],carRegNo[3];
    int ActualPrice,EMI,balancedAmount,servicingCount;
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

salesPerson *SPhead=NULL,*SPtemp,*newNode;
stockDetails *showRoomHead=NULL,*showRoomtemp,*stocckNewNode; 
purchasedCar *carHead=NULL,*carTemp,*carNewNode;
int main()
{
    char str[15],dtr[10],*p;
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
        printf("%s ",newNode->spId);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spName,str);
        printf("%s ",newNode->spName);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spDOB,str);
        printf("%s ",newNode->spDOB);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->spAddr,str);
        printf("%s ",newNode->spAddr);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->salesTarget,str);
        printf("%s ",newNode->salesTarget);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->salesAchieved,str);
        printf("%s ",newNode->salesAchieved);
        fscanf(fptr,"%s",&str);
        strcpy(newNode->commission,str);
        printf("%s\n",newNode->commission);
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
        
        
    }
    fclose(fptr);
    printf("File closed\n");
    SPtemp=SPhead;
    while (SPtemp!=NULL)
    {
        printf("%s ",SPtemp->spId);
        printf("%s ",SPtemp->spName);
        printf("%s ",SPtemp->spDOB);
        printf("%s ",SPtemp->spAddr);
        printf("%s ",SPtemp->salesTarget);
        printf("%s ",SPtemp->salesAchieved);
        printf("%s\n",SPtemp->commission);
        SPtemp=SPtemp->next;

    }
    int showRoomCount=3,availCarNo,num,countModel=0,i=0;
    FILE *fptr2;
    fptr2=fopen("stockDetails.txt","r");
    count=0;
    while (count<showRoomCount)
    {
        stocckNewNode=(stockDetails *)malloc(sizeof(stockDetails));
        fscanf(fptr2,"%s",&str);
        strcpy(stocckNewNode->noOfCarModels,str);
        printf("%s ",stocckNewNode->noOfCarModels);
        fscanf(fptr2,"%s",&str);
        strcpy(stocckNewNode->soldCarsNo,str);
        printf("%s ",stocckNewNode->soldCarsNo);
        fscanf(fptr2,"%d",&num);
        stocckNewNode->avialCarsInStock=num;
        availCarNo=num;
        printf("%d ",stocckNewNode->avialCarsInStock);
        fscanf(fptr2,"%s",&str);
        strcpy(stocckNewNode->reqStock,str);
        printf("%s\n",stocckNewNode->reqStock);
        stocckNewNode->carModelDataHead[count]=NULL;
        while (countModel<availCarNo)
        {
            stocckNewNode->carModelDataNewnode=(carModelData *)malloc(sizeof(carModelData));
            fscanf(fptr2,"%s",&str);
            strcpy(stocckNewNode->carModelDataNewnode->carName,str);
            printf("%s ",stocckNewNode->carModelDataNewnode->carName);
            fscanf(fptr2,"%s",&str);
            strcpy(stocckNewNode->carModelDataNewnode->carColor,str);
            printf("%s ",stocckNewNode->carModelDataNewnode->carColor);
            fscanf(fptr2,"%s",&str);
            strcpy(stocckNewNode->carModelDataNewnode->fuelType,str);
            printf("%s ",stocckNewNode->carModelDataNewnode->fuelType);
            fscanf(fptr2,"%s",&str);
            strcpy(stocckNewNode->carModelDataNewnode->carType,str);
            printf("%s\n",stocckNewNode->carModelDataNewnode->carType);
            stocckNewNode->carModelDataNewnode->childnext=NULL;
            if (stocckNewNode->carModelDataHead[count]==NULL)
            {
                stocckNewNode->carModelDataHead[count]=stocckNewNode->carModelDataNewnode;
                stocckNewNode->carModelDataTemp=stocckNewNode->carModelDataNewnode;
            }
            else
            {
                stocckNewNode->carModelDataTemp->childnext=stocckNewNode->carModelDataNewnode;
                stocckNewNode->carModelDataTemp=stocckNewNode->carModelDataNewnode;
            }
            countModel++;
            
        }
        stocckNewNode->Stocknext=NULL;
        if (showRoomHead==NULL)
        {
            showRoomHead=stocckNewNode;
            showRoomtemp=stocckNewNode;
        }
        else
        {
            showRoomtemp->Stocknext=stocckNewNode;
            showRoomtemp=stocckNewNode;
        }
        
        count++;
        countModel=0;
        
        
    }
    fclose(fptr2);
    int soldCarsCount=60;
    count=0;
    // FILE *fptr3;
    // fptr3=fopen("purchasedCar.txt","r");
    // while (count<soldCarsCount)
    // {
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->customerName,str);
    //     printf("%s ",carNewNode->customerName);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->customerMob,str);
    //     printf("%s ",carNewNode->customerMob);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->carName,str);
    //     printf("%s ",carNewNode->carName);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->carColor,str);
    //     printf("%s ",carNewNode->carColor);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->carRegNo,str);
    //     printf("%s ",carNewNode->carRegNo);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->fuelType,str);
    //     printf("%s ",carNewNode->fuelType);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->carType,str);
    //     printf("%s ",carNewNode->carType);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->servicingCount,str);
    //     printf("%s ",carNewNode->servicingCount);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->ActualPrice,str);
    //     printf("%s ",carNewNode->ActualPrice);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->balancedAmount,str);
    //     printf("%s ",carNewNode->balancedAmount);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->EMI,str);
    //     printf("%s ",carNewNode->EMI);
    //     fscanf(fptr3,"%s",&str);
    //     strcpy(carNewNode->salesAgent,str);
    //     printf("%s ",carNewNode->salesAgent);


    // }
    // fclose(fptr3);
    
    
}