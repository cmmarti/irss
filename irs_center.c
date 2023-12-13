#include "irs_center.h"
#include <stdio.h>

void initializeCenter(IRS_Center *center) {
  center->budget = 5840000;

    center->staff.examiners = 15;
    center->staff.clerks = 25;
    center->staff.managers = 5;
    center->equipment.computers = 50;
    center->equipment.filingSystems = 200;
    center->motivation = 0.75; 
}

void allocateRemainingBudget(IRS_Center *center) {
    int remainingBudget = center->budget * 0.3;
    printf("You have $%d remaining to allocate.\n", remainingBudget);

    int additionalExaminers, additionalClerks, additionalManagers, additionalComputers, additionalFilingSystems;

    int costPerExaminer = 25000;
    printf("Enter additional number of examiners (max budget allows %d): ", remainingBudget / costPerExaminer);
    scanf("%d", &additionalExaminers);
    if (additionalExaminers * costPerExaminer <= remainingBudget) {
        center->staff.examiners += additionalExaminers;
        remainingBudget -= additionalExaminers * costPerExaminer;
    } else {
        printf("Not enough budget for that many examiners.\n");
    }

    int costPerClerk = 18000;
    printf("Enter additional number of clerks (max budget allows %d): ", remainingBudget / costPerClerk);
    scanf("%d", &additionalClerks);
    if (additionalClerks * costPerClerk <= remainingBudget) {
        center->staff.clerks += additionalClerks;
        remainingBudget -= additionalClerks * costPerClerk;
    } else {
        printf("Not enough budget for that many clerks.\n");
    }

    int costPerManager = 35000;
    printf("Enter additional number of managers (max budget allows %d): ", remainingBudget / costPerManager);
    scanf("%d", &additionalManagers);
    if (additionalManagers * costPerManager <= remainingBudget) {
        center->staff.managers += additionalManagers;
        remainingBudget -= additionalManagers * costPerManager;
    } else {
        printf("Not enough budget for that many managers.\n");
    }

    int costPerComputer = 3000;
    printf("Enter additional number of computers (max budget allows %d): ", remainingBudget / costPerComputer);
    scanf("%d", &additionalComputers);
    if (additionalComputers * costPerComputer <= remainingBudget) {
        center->equipment.computers += additionalComputers;
        remainingBudget -= additionalComputers * costPerComputer;
    } else {
        printf("Not enough budget for that many computers.\n");
    }

    int costPerFilingSystem = 500;
    printf("Enter additional number of filing systems (max budget allows %d): ", remainingBudget / costPerFilingSystem);
    scanf("%d", &additionalFilingSystems);
    if (additionalFilingSystems * costPerFilingSystem <= remainingBudget) {
        center->equipment.filingSystems += additionalFilingSystems;
        remainingBudget -= additionalFilingSystems * costPerFilingSystem;
    } else {
        printf("Not enough budget for that many filing systems.\n");
    }

    printf("Resource allocation complete. Remaining budget: $%d\n", remainingBudget);
}

void adjustMotivation(IRS_Center *center) {
    double initialMotivation = center->motivation;

    if (center->staff.clerks / (float)center->staff.examiners < 0.5) {
        center->motivation -= 0.1;
        printf("Motivation decreased due to insufficient clerical support per examiner.\n");
    }
    if (center->equipment.computers / (float)center->staff.examiners < 1) {
        center->motivation -= 0.1;
        printf("Motivation decreased due to insufficient computer resources per examiner.\n");
    }

    if (center->motivation < 0) center->motivation = 0;
    if (center->motivation > 1) center->motivation = 1;

    if (center->motivation < initialMotivation) {
        printf("Overall staff motivation has decreased to %.2f.\n", center->motivation);
    } else if (center->motivation > initialMotivation) {
        printf("Overall staff motivation has increased to %.2f.\n", center->motivation);
    } else {
        printf("Staff motivation remains stable at %.2f.\n", center->motivation);
    }
}

void performSimulation(IRS_Center center) {
    const int returnsPerExaminer = 1000;
    const int returnsPerComputer = 500;

    int totalReturns = center.staff.examiners * returnsPerExaminer + center.equipment.computers * returnsPerComputer;

    double accuracy = 0.75;
    accuracy += center.staff.clerks * 0.01;
    accuracy += center.staff.managers * 0.02;
    accuracy += center.equipment.filingSystems * 0.005;

    if (accuracy > 1.0) {
        accuracy = 1.0;
    }

    double errorRate = (1 - accuracy) * (1 + (1 - center.motivation));
    int correctlyProcessed = (int)(totalReturns * (1 - errorRate));
    int wronglyProcessed = totalReturns - correctlyProcessed;

    printf("Total Returns Processed: %d\n", totalReturns);
    printf("Correctly Processed Returns: %d (%.2f%%)\n", correctlyProcessed, accuracy * 100);
    printf("Wrongly Processed Returns: %d (%.2f%%)\n", wronglyProcessed, (1 - accuracy) * 100);
}
