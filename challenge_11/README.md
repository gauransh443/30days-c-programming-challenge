Problem Statement:-
The campus is divided into five zones: 1 Academic Block, 2 Hostel, 3 Library, 4 Cafeteria, and 5 Sports Complex. For each zone, the daily water consumption (in litres) is recorded for seven days. A daily usage target is also assigned to each zone. Build WATERWISE to turn these readings into a clear water-audit report and help the campus community identify where water-saving action is needed.

Algorithm:-
1) Start
2) Define ZONES = 5 and DAYS = 7 and declare function prototype.
3) In main , declare array (usage, dailyTarget, excessByZone, overLimitByZone, spikeByZone, alertByZone) and the variables choice and     audit_done = 0.
4) Call function 1 , to take input of each day water usage
5) Usind do-while loop, display the menu and read choice , if choice>5 and choice<1 , read again .
6) If choice is 3 or 4 , display first "First generate audit using option 2 ".
7) If choice is 1 then display the data by calling fucntion 1.
8) If choice is 2 , display auditreport by calling fucntion 5 and set audit_done = 1.
9) If choice is 3 and audit_done = 1 then display ranking by calling fucntion 6.
10) If choice is 4 and audit_done = 1 thendisplay recommended conservation actions by calling fucntion 7.
11) If choice  is 5 , exit the menu and stop the program.
12) Stop

Function Prototypes:-
1) void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
2) void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
3) void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay);
4) void detectWaterAlerts(int *zoneUsage, int  dailyTarget,int *overLimitDays,int *totalExcess, int *spikeDays, int *alertDays);
5) void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES],
   int spikeByZone[ZONES], int alertByZone[ZONES]);
6) void rankZones(int excessByZone[ZONES]);
7) void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]);

NOTE :- DATA USED IS SAMPLE DATA NOT ACTUAL CAMPUS DATA.