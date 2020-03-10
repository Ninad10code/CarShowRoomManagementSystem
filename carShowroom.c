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
    carModelData *carModelDataHead[3],*carModelDataTemp,*carModelDataNewnode;
    
    
} stockDetails;

// structure for car details of purchased cars
typedef struct Carnode
{
    char carName[18],carColor[10],fuelType[10],carType[10 ],insuranceEval[10],salesAgent[10];
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
    char str[18],dtr[10],agentId[5],p[5];
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
    count=0;
    bestSeller=(popularCar *)malloc(sizeof(popularCar)*16);
    count=0;
    FILE *fptr4;
    fptr4=fopen("Carmodels.txt","r");
    while (count<15)
    {
        fscanf(fptr4,"%s",&str);
        carTemp=carHead;
        strcpy(bestSeller[count].carName,str);
        printf("%s\n",bestSeller[count].carName);
        bestSeller[count].count=0;
        while (carTemp!=NULL)
        {
            if (strcmp(carTemp->carName,str)==0)
            {
                bestSeller[count].count++;
            }
            carTemp=carTemp->Carnext;

            
            
        }
        printf("%d\n",bestSeller[count].count);
        if (bestSeller[count].count>maxBestSaleCount)
        {
            maxBestSaleCount=bestSeller[count].count ;
        }
        
        count++;
        
    }
    printf("Max best sale %d\n",maxBestSaleCount);
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
    int found=0;
    float total=0.0,balance=0.0;
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
            balance=atoi(p);
            printf("Balance %f\n",balance);
            total=total+balance;
        }
        carTemp=carTemp->Carnext;
        
    }
    printf("Total %f\n",total);
    
    
}
