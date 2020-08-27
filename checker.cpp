#include <assert.h>

bool isInsideLimit(float value,float lowerLimit,float upperLimit)
{
  return (value>= lowerLimit && value <=upperLimit);
  
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
  return(isInsideLimit(bpm,70,150) && isInsideLimit(spo2,90,100) && isInsideLimit(respRate,30,95));
  
  
}

int main() {
  assert(isInsideLimit(80,70,150) == true);
  assert(isInsideLimit(60,70,150) == false);
  assert(isInsideLimit(150,70,150) == true);
  assert(isInsideLimit(180,70,150) == false);
  assert(isInsideLimit(80,95,25) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
