// Declaration of structures and function prototypes

#ifndef IRS_CENTER_H
#define IRS_CENTER_H

typedef struct {
  int examiners;
  int clerks;
  int managers;
} Staff;

typedef struct {
  int computers;
  int filingSystems;
} Equipment;

typedef struct {
  Staff staff;
  Equipment equipment;
  int budget;
  double motivation;
} IRS_Center;

void initializeCenter(IRS_Center *center);
void allocateRemainingBudget(IRS_Center *center);
void adjustMotivation(IRS_Center *center);
void performSimulation(IRS_Center center);

#endif // IRS_CENTER_H
