#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>

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

void printIntro() {
  printf("\n\nBienvenue a notre evenement principal, les fans de course numerique !\nJ'espere que tout le monde a pris son gouter car nous allons commencer !\n\n");
}

void printCountDown() {
    int i;
    printf("Coureurs prets ! Dans...\n");
    for (i=5;i>0;i--){
      sleep(1); 
      printf("\n%d\n",i);
    }
    sleep(1); 
    printf("\nCourse !\n");
}

void printFirstPlaceAfterLap(struct Race race){

printf("Apres le tour numero %d\n",race.currentLap);
printf("La premiere place est occupee par : %s dans la voiture de course %s !\n",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race){
  printf("Felicitons tous %s, dans la voiture de course %s, pour son incroyable performance.\n",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
  printf("Félicitons tous Ahmed, dans la voiture de course orange, pour son incroyable performance.\n");
}

int calculateTimeToCompleteLap(){
  int vitesse, acceleration, nerves;
  srand(time(NULL));
  vitesse = (rand()%3)+1; 
  acceleration = (rand()%3)+1; 
  nerves = (rand()%3)+1; 
  return vitesse+acceleration+nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime = calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
// raceCar1
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) printf()

}

int main () {
    struct Race race1;
    struct RaceCar raceCar1;
    struct RaceCar * ptraceCar1 = &raceCar1;
    strcpy(raceCar1.driverName,"Ahmed");
    strcpy(raceCar1.raceCarColor,"Black");
    raceCar1.totalLapTime = 0;
    // race1.numberOfLaps = 5;
    // race1.currentLap = 2;
    // strcpy(race1.firstPlaceDriverName,"Hicham");
    // strcpy(race1.firstPlaceRaceCarColor,"Red");
    // printIntro();
    // printCountDown();
    // printFirstPlaceAfterLap(race1);
    updateRaceCar(ptraceCar1);
    printf("\n\n%d\n\n.",calculateTimeToCompleteLap());
    return 0;
}