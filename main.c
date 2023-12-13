#include "irs_center.h"

int main() {
  IRS_Center center;
  initializeCenter(&center);
  allocateRemainingBudget(&center);

  adjustMotivation(&center);
  performSimulation(center);

  return 0;
}
