#include <assert.h>

bool bpmAreOk(float bpm)
{
  return !(bpm < 70 || bpm > 150);
}

bool spo2AreOk(float spo2)
{
  return !(spo2<90);
}

bool respRateAreOk(float respRate)
{
  return !(respRate < 30 || respRate > 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
  return(bpmAreOk(bpm) && spo2AreOk(spo2) && respRateAreOk(respRate));
    
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
