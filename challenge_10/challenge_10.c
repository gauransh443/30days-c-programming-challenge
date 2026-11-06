#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]);
void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
     float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]);
void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS],
     int riskDays[ZONES]);
void computeGreenIndex(float avgTemp[ZONES], 
    float avgHumidity[ZONES], float avgAQI[ZONES], float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES],
     float avgAQI[ZONES], int riskDays[ZONES]);



int main(){
    int choice,i;
    float temp[ZONES][DAYS],humidity[ZONES][DAYS];
    int aqi[ZONES][DAYS],riskDays[ZONES];
    int dataReady = 0;
    float avgTemp[ZONES], avgHumidity[ZONES], avgAQI[ZONES],greenIndex[ZONES];
    do{
        printf("Menu :- \n");
        printf("1-Input/Update Data \n");
        printf("2- Display data \n");
        printf("3 - Zone Wise Average \n");
        printf("4 - Detect Risk Days \n");
        printf("5 - Green Index and Ranking \n");
        printf("6 - Recommandations \n");
        printf("7 - Exit \n");

        printf("Enter choice (1-7) : ");
        scanf("%d",&choice);

        while(choice<1||choice>7){
            printf("Invalid choice number , enter again :");
            scanf("%d",&choice);
        }

        if(choice == 1){
            inputData(temp,humidity,aqi);
            dataReady=1;
        }

        else if(choice >= 2 && choice <= 6 && dataReady==0){
            printf("No data entered \n");
        }

        else if(choice == 2){
            displayData(temp,humidity,aqi);
        }

        else if(choice == 3){
            calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
        }

        else if(choice == 4){
            detectRiskZones(temp,humidity,aqi,riskDays);
        }

        else if(choice == 5){
            calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
            computeGreenIndex(avgTemp,avgHumidity,avgAQI,greenIndex);
            displayRanking(greenIndex);
        }

        else if(choice == 6){
            calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
            detectRiskZones(temp,humidity,aqi,riskDays);
            displayRecommendations(avgTemp,avgHumidity,avgAQI,riskDays);
        }

        if(choice==7){
            printf("You have exited successfully .");
        }

    

    }while(choice != 7 );

    return 0;
}

void inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
    int i,j;
    for(i=0;i<ZONES;i++){
        printf("Zone %d \n",i+1);
        for(j=0;j<DAYS;j++){
            do{
                printf("Enter temperature for day %d : ",j+1);
                scanf("%f",&temp[i][j]);
                if (temp[i][j] < 10 || temp[i][j] > 50){
                    printf("Invalid Temperature \n");
                }
            }while(temp[i][j] < 10 || temp[i][j] > 50);

            do{
                printf("Enter humidity for day %d : ",j+1);
                scanf("%f",&humidity[i][j]);
                if (humidity[i][j] < 0 || humidity[i][j] > 100){
                    printf("Invalid humidity \n");
                }
            }while(humidity[i][j] < 0 || humidity[i][j] > 100);

            do{
                printf("Enter AQI for day %d : ",j+1);
                scanf("%d",&aqi[i][j]);
                if (aqi[i][j] < 0 || aqi[i][j] > 500){
                    printf("Invalid AQI \n");
                }
            }while(aqi[i][j] < 0 || aqi[i][j] > 500);



        }
    }
}

void displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS]){
    int i,j;

    printf(" Temperature Matrix \n");
    for(j=0;j<DAYS;j++){
        printf("\tDay%d ",j+1);
    }
    printf("\n");
    for(i=0;i<ZONES;i++){
        printf("Zone %d\t",i+1);
        for(j=0;j<DAYS;j++){
            printf("%.2f\t",temp[i][j]);
        }
        printf("\n");
    }

    printf(" Humidity Matrix \n");
    for(j=0;j<DAYS;j++){
        printf("\tDay%d ",j+1);
    }
    printf("\n");
    for(i=0;i<ZONES;i++){
        printf("Zone %d\t",i+1);
        for(j=0;j<DAYS;j++){
            printf("%.2f\t",humidity[i][j]);
        }
        printf("\n");
    }

    printf(" AQI Matrix \n");
    for(j=0;j<DAYS;j++){
        printf("\tDay%d ",j+1);
    }
    printf("\n");
    for(i=0;i<ZONES;i++){
        printf("Zone %d\t",i+1);
        for(j=0;j<DAYS;j++){
            printf("%d\t",aqi[i][j]);
        }
        printf("\n");
    }
}

void calculateAverages(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES]){
    int i,j;
    float sum_temp, sum_humidity, sum_aqi;

    for(i=0;i<ZONES;i++){
        sum_temp= 0;
        sum_humidity = 0;
        sum_aqi = 0;
        for(j=0;j<DAYS;j++){
            sum_temp = sum_temp + temp[i][j];
            sum_humidity = sum_humidity + humidity[i][j];
            sum_aqi = sum_aqi + aqi[i][j];
        }
        avgTemp[i] = sum_temp / DAYS;
        avgHumidity[i] = sum_humidity / DAYS;
        avgAQI[i] = sum_aqi / DAYS;
        printf("Zone %d : Avg Temp = %.2f, Avg Humidity = %.2f, Avg AQI = %.2f \n"
            ,i+1,avgTemp[i],avgHumidity[i],avgAQI[i]);
    

    }
}


void detectRiskZones(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS], int riskDays[ZONES]){
    int i,j;

    printf("Risk Report \n");
    for(i=0;i<ZONES;i++){
        riskDays[i] = 0;
        printf("Zone %d : \n",i+1);
        printf("Days : ");
        for(j=0;j<DAYS;j++){
            if(aqi[i][j] > 150 || temp[i][j] > 35 || humidity[i][j] > 80){
                printf("%d ",j+1);
                riskDays[i]++;
            }
        }
        if(riskDays[i] == 0){
            printf("No risk days");
        }
        printf("Risk days count = %d \n",riskDays[i]);
    }
}


void computeGreenIndex(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], float greenIndex[ZONES]){
    int i;
    float aqiScore, tempScore, humScore, diff;

    printf("Green Index \n");
    for(i=0;i<ZONES;i++){

        aqiScore = 100 - (avgAQI[i] / 5);
        if(aqiScore < 0){
            aqiScore = 0;
        }

        diff = avgTemp[i] - 25;
        if(diff < 0){
            diff = -diff;
        }
        tempScore = 100 - (4 * diff);
        if(tempScore < 0){
            tempScore = 0;
        }

        diff = avgHumidity[i] - 50;
        if(diff < 0){
            diff = -diff;
        }
        humScore = 100 - (2 * diff);
        if(humScore < 0){
            humScore = 0;
        }

        greenIndex[i] = (0.4 * aqiScore) + (0.3 * tempScore) + (0.3 * humScore);

        printf("Zone %d : Green Index = %.2f \n",i+1,greenIndex[i]);
    }
}

void displayRanking(float greenIndex[ZONES]){
    int i,j,pos;
    int rank[ZONES];

    for(i=0;i<ZONES;i++){
        rank[i] = 1;
        for(j=0;j<ZONES;j++){
            if(greenIndex[j] > greenIndex[i]){
                rank[i]++;
            }
        }
    }

    printf("Green Index Ranking (best to worst)\n");
    for(pos=1;pos<=ZONES;pos++){
        for(i=0;i<ZONES;i++){
            if(rank[i] == pos){
                printf("Rank %d : Zone %d , Green Index = %.2f \n",rank[i],i+1,greenIndex[i]);
            }
        }
    }
}



void displayRecommendations(float avgTemp[ZONES], float avgHumidity[ZONES], float avgAQI[ZONES], int riskDays[ZONES]){
    int i;
    int counter;

    printf("Recommendetions \n");
    for(i=0;i<ZONES;i++){
        counter = 0;
        printf("Zone %d : \n",i+1);

        if(avgAQI[i] > 150){
            printf("improve ventilation\n");
            counter= 1;
        }
        if(avgTemp[i] >35){
            printf("Add shade or green cover.\n");
            counter =1;
        }
        if(avgHumidity[i]> 80){
            printf("Check ventilation of water sources \n");
            counter = 1;
        }

        if(counter==0){
            if(riskDays[i] > 0){
                printf("only few days flagged reviewing those dates\n");
            }
            else{
                printf("No risk detected, continue monitoring.\n");
            }
        }
    }
}