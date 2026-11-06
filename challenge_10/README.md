## Problem Statement 
The campus is divided into five zones: 1 Academic Block, 2 Hostel, 3 Library, 4 Cafeteria, and 5 Sports Area. For each zone, record three environmental parameters for seven days. Store the readings in three separate two-dimensional arrays. The system must analyse the data through user-defined functions and help you to identify where an environmental improvement could make the greatest difference.

## Data Input Rules

Use ZONES = 5 and DAYS = 7. Create temp[ZONES][DAYS], humidity[ZONES][DAYS], and aqi[ZONES][DAYS]. Temperature must be 10–50 °C, humidity 0–100%, and AQI 0–500. Re-enter any invalid reading. Clearly label any simulated data; do not present simulated values as real campus measurements.

## Function
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


## Algorithm
1. Start
2. Add function prototypes and define ZONES 5 and DAYS 7.
3. Declare variables choice, temp[ZONES][DAYS], humidity[ZONES][DAYS], aqi[ZONES][DAYS], riskDays[ZONES], avgTemp[ZONES], avgHumidity[ZONES], avgAQI[ZONES], greenIndex[ZONES] and set dataReady = 0.
4. Show the menu (1 to 7) using do-while loop and read choice.
5. While choice is less than 1 or greater than 7, print "Invalid choice number" and read it again.
6. If choice is 1,call inputData and set dataReady = 1.
7. If choice is 2 to6 and dataReady is 0, display "No data entered" and return to the menu.
8. If choice is 2,call displayData.
9. If choice is 3, call calculateAverages.
10. If choice is 4, call detectRiskZones.
11. If choice is 5,call calculateAverages, then computeGreenIndex, then displayRanking.
12. If choice is 6, call calculateAverages, then detectRiskZones, then displayRecommendations.
13. If choice is 7, print the exit message.
14. Repeat the menu until choice is 7.
15. Stop.


inputData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])

1. For each zone i from 0 to 4, print the zone number i + 1.
2. For each day j from 0 to 6, read temperature using do-while loop.
3. If temperature is less than 10 or greater than 50, print "Invalid Temperature" and read it again.
4. Read humidity using do-while loop. If it is less than 0 or greater than 100, print "Invalid humidity" and read it again.
5. Read AQI using do-while loop. If it is less than 0 or greater than 500, print "Invalid AQI" and read it again.

displayData(float temp[ZONES][DAYS], float humidity[ZONES][DAYS], int aqi[ZONES][DAYS])

1. Print "Temperature Matrix" and the headings Day1 to Day7 using for loop.
2. For each zone, print the zone number and its 7 temperature values on one line.
3. Repeat steps 1 and 2 for the humidity matrix.
4. Repeat steps 1 and 2 for the AQI matrix.

calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI)

1. For each zone i from 0 to 4, set sum_temp = 0, sum_humidity = 0, sum_aqi = 0.
2. For each day j from 0 to 6, add temp[i][j], humidity[i][j] and aqi[i][j] to their sums.
3. Calculate the averages for the zone:
   using avgTemp[i] = sum_temp/days , avgAQI[i] = sum_aqi/days , avgHUMIDITY[i] = sum_humidity/days
4. Print the zone number with its three averages.

detectRiskZones(temp, humidity, aqi, riskDays)

1. For each zone i from 0 to 4, set riskDays[i] = 0 and print "Zone i + 1".
2. For each day j from 0 to 6, check if aqi[i][j] is greater than 150 or temp[i][j] is greater than 35 or humidity[i][j] is greater than 80.
3. If the condition is true, print the day number j + 1 and add 1 to riskDays[i]. (All three checks are in one if, so a day is counted only once.)
4. If riskDays[i] is 0, print "No risk days".
5. Print the risk days count for the zone.

computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex)

1. Declare variables i, aqiScore, tempScore, humScore, diff.
2. For each zone i from 0 to 4, calculate the AQI score using aqiScore = 100-(avgAQI[i]/5).
3. If aqiScore is less than 0, set aqiScore = 0.
4. Set diff = avgTemp[i] − 25. If diff is less than 0, set diff = −diff.
5. Set tempScore = 100 − (4 × diff). If tempScore is less than 0, set tempScore = 0.
6. Set diff = avgHumidity[i] − 50. If diff is less than 0, set diff = −diff.
7. Set humScore = 100 − (2 × diff). If humScore is less than 0, set humScore = 0.
8. Calculate greenIndex[i] = (0.4 × aqiScore) + (0.3 × tempScore) + (0.3 × humScore).
9. Print the zone number with its Green Index.

displayRanking(float greenIndex[ZONES])

1. Declare variables i, j, pos and the array rank[5].
2. For each zone i from 0 to 4, set rank[i] = 1.
3. Using inner loop j from 0 to 4, if greenIndex[j] is greater than greenIndex[i], add 1 to rank[i]. (Equal scores do not add, so tied zones get the same rank.)
4. Print "Green Index Ranking (best to worst)".
5. For each position pos from 1 to 5, use a for loop over all zones i from 0 to 4.
6. If rank[i] equals pos, print the rank, zone number i + 1 and its Green Index.

displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays)

1. Declare variables i and counter.
2. For each zone i from 0 to 4, set counter = 0 and print the zone number.
3. If avgAQI[i] is greater than 150, print "improve ventilation" and set counter = 1.
4. If avgTemp[i] is greater than 35, print "Add shade or green cover" and set counter = 1.
5. If avgHumidity[i] is greater than 80, print "Check ventilation or stagnant-water sources" and set counter = 1.
6. If counter is 0 and riskDays[i] is greater than 0, print "Only few days flagged, review those dates".
7. Otherwise, if counter is 0, print "No risk detected, continue monitoring".
