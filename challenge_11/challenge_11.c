#include <stdio.h>
#define ZONES 5
#define DAYS 7

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay);
void detectWaterAlerts(int *zoneUsage, int  dailyTarget,int *overLimitDays,int *totalExcess, int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES],
int spikeByZone[ZONES], int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]);
const char* zoneName(int zoneIndex){
switch(zoneIndex){
case 0: return "Academic Block";
case 1: return "Hostel";
case 2: return "Library";
case 3: return "Cafeteria";
case 4: return "Sports Complex";
default: return "Invalid";
}
}


int main(){
    int usage[ZONES][DAYS];
    int dailyTarget[ZONES];
    int choice;
    int excessByZone[ZONES], overLimitByZone[ZONES],spikeByZone[ZONES], alertByZone[ZONES];
    int audit_done = 0;
    inputWaterData(usage,dailyTarget);
    do{
        printf("1 - Display water data  \n");
        printf("2 - Generate audit report \n");
        printf("3 - Zones ranking by excess \n");
        printf("4 - Display conservation action \n");
        printf("5 - Exit \n");

        printf("Enter choice(1-5): ");
        scanf("%d",&choice);

        while(choice < 1 || choice >5){
            printf("Enter choice from 1-5 \n");
            scanf("%d",&choice);
        }

        if(choice == 1){
            displayWaterData(usage,dailyTarget);
        }

        else if(choice == 2){
            audit_done = 1;
            generateAuditReport(usage,dailyTarget, excessByZone,  overLimitByZone, spikeByZone, alertByZone);
        }

        else if(choice == 3){
            if(audit_done != 1){
                printf("First generate audit using option 2 \n");
            }
            else{
            rankZones(excessByZone);
            }
        }

        else if(choice == 4){
            if(audit_done != 1){
                printf("First generate audit using option 2 \n");
            }
            else{
            displayConservationActions(overLimitByZone, spikeByZone, excessByZone);
            }
        }

        else{
            printf("You have exited successfully ");
        }

        

    }while(choice != 5);
    return 0;
}


void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]){
    int i,j;
    for(i=0;i<ZONES;i++){
        for(j=0;j<DAYS;j++){
            printf("Enter reading of %s and day %d : ",zoneName(i),j+1);
            scanf("%d",&usage[i][j]);

            while(usage[i][j]<0 || usage[i][j]>50000){
                printf("Invalid reading ,enter again : ");
                scanf("%d",&usage[i][j]);
            }
        }

        printf("Enter target reading of %s :",zoneName(i));
            scanf("%d",&dailyTarget[i]);

            while(dailyTarget[i]<100 || dailyTarget[i]>50000){
                printf("Invlaid reading,enter again : ");
                scanf("%d",&dailyTarget[i]);
            }

    }
}


void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]){
    int i,j;
    printf("WEEKLY WATER CONSUMPTION\n");
    for(i=0;i<ZONES;i++){
        printf("ZONE: %s\n",zoneName(i));
        printf("DAILY TARGET: %d litres\n",dailyTarget[i]);
        for(j=0;j<DAYS;j++){
            printf("Day %d: %d litres\n",j+1,usage[i][j]);
        }
    }
}


void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay){
    int sum = 0;
    int peak = *(zoneUsage+0);
    int day = 1;
    int i;

    for(i=0;i<DAYS;i++){
        int value = *(zoneUsage+i);
        sum = sum+value;
        if(value>peak){
            peak= value;
            day=i+1;
        }
    }

    *total = sum;
    *peakDay= day;
    *peakUsage = peak;
    *average =(float)sum/DAYS;

}


void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays){
    int i,value ,excess = 0,ocount=0;
    int previous_day,spike = 0 ;
    int alert_day = 0;
    for(i=0;i<DAYS;i++){
        int oflag = 0;
        int sflag = 0;
        value = *(zoneUsage+i);

        if(value>dailyTarget){
            oflag = 1;
            ocount++;
            excess += value - dailyTarget;
        }

        if(i>=1){
            previous_day=*(zoneUsage +i-1);
            if(value*100>previous_day*140){
            sflag = 1;
            spike++;
            }
        }

        if(oflag || sflag  ){
        alert_day++;
        }   

    }

    *overLimitDays = ocount;
    *totalExcess = excess;
    *spikeDays = spike;
    *alertDays =alert_day;

}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES],
int spikeByZone[ZONES], int alertByZone[ZONES]){
    int zone,total,peakDay,peakUsage;
    float average;

    printf("Water audit report :-\n");
    for(int zone = 0 ;zone<ZONES;zone++){
    calculateZoneStats( &usage[zone][0], &total, &average,&peakUsage, &peakDay);
    detectWaterAlerts(&usage[zone][0], dailyTarget[zone], &overLimitByZone[zone], &excessByZone[zone], &spikeByZone[zone], &alertByZone[zone]);
    printf("Zone %d: %s (Target: %d )\n", zone+1,zoneName(zone),dailyTarget[zone]);
        printf("Total            : %d\n", total);
        printf("Daily average    : %.2f\n",average);
        printf("Peak consumption : %d (Day %d) \n",peakUsage, peakDay);
        printf("Over-limit days  : %d \n",overLimitByZone[zone]);
        printf("Total excess     : %d \n",excessByZone[zone]);
        printf("Spike days       : %d \n",spikeByZone[zone]);
        printf("Unique alert days: %d \n",alertByZone[zone]);
}
}  


void rankZones(int excessByZone[ZONES]){
    int i,j,r,max = excessByZone[0];
    int rank[ZONES];
    for(i=0;i<ZONES;i++){
        rank[i]=1;
        for(j=0;j<ZONES;j++){
            if(excessByZone[j] > excessByZone[i]){
            rank[i]++;
        }
    }
}

        for(i = 1; i < ZONES; i++){
            if(excessByZone[i] > max){
                max = excessByZone[i];
            }
        }

    if(max == 0){
        printf("No zone has exceeded its daily target.\n");
    }
    else{
        printf("Highest excess %d L: \n",max);
        for(i = 0; i < ZONES; i++){
            if(excessByZone[i] == max){
                printf("%s\n",zoneName(i));
            }
        }
    }

    printf("RANKINGS: \n");
    for(r = 1; r <= ZONES; r++){
        for(i = 0; i < ZONES; i++){
            if(rank[i] == r){
                printf("Rank %d: %s (%d Litres)\n",r,zoneName(i),excessByZone[i]);
            }
        }
    }

}


void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES],int excessByZone[ZONES]){
    int i;
    for(i = 0; i< ZONES; i++){
        printf("Zone %d: %s (Total excess: %d)\n", i+1, zoneName(i), excessByZone[i]);

        if(spikeByZone[i] > 0){
            printf("Check for a leak or unexpected use around the flagged days.\n");
        }
        if(overLimitByZone[i]>= 3){
            printf("Prioritise a water audit and reduction plan.\n");
        }
        else if(overLimitByZone[i] ==1 || overLimitByZone[i] == 2){
            printf("Monitor those days and inspect taps or valves.\n");
        }
        if(overLimitByZone[i] ==0 && spikeByZone[i] == 0){
            printf("Maintain current good practices.\n");
        }
    }
}


