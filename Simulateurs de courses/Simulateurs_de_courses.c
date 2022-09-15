#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct Race {   
  int numberOfLaps;  
  int currentLap;
  char firstPlaceDriverName[20]; 
  char firstPlaceRaceCarColor[20];
}; 

struct RaceCar {   
  int totalLapTime;
  char driverName[20]; 
  char raceCarColor[20];
}; 

void printFirstPlaceAfterLap(struct Race race){

printf("Apre le tour numero %d\n",race.currentLap);
printf("La premiere place est occupee par : %s dans la voiture de course %s !\n",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}

void delay(int number_of_seconds)
{
int milli_seconds = 1000 * number_of_seconds;
clock_t start_time = clock();
while (clock() < start_time + milli_seconds) ;
}

void printIntro() {
  printf("\n\nBienvenue a notre evenement principal, les fans de course numerique !\nJ'espere que tout le monde a pris son gouter car nous allons commencer !\n\n");
}

void printCountDown() {
    int i;
    printf("Coureurs prets ! Dans...\n");
    for (i=5;i>0;i--){
        delay(1); 
        printf("\n%d\n",i);
    }
    delay(1); 
    printf("\nCourse !\n");
}

int main () {
    struct Race race1;
    race1.numberOfLaps = 5;
    race1.currentLap = 2;
    strcpy(race1.firstPlaceDriverName,"Hicham");
    strcpy(race1.firstPlaceRaceCarColor,"Red");
    printIntro();
    printCountDown();
    printFirstPlaceAfterLap(race1);
    return 0;
}