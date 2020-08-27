#include <assert.h>

bool bpmAreOk(flaot bpm)
{
  return !(bpm < 70 || bpm > 150);
}

bool spo2AreOk(float spo2)
{
  return !(spo2<90)
}

bool respRate(float respRate)
{
  return !(respRate < 30 || respRate > 95)
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(!bpmAreOk(bpm))
  {
    return false;
  }
  else if(!spo2AreOk(spo2))
  {
    return false;
  }
  else if(!respRate(respRate))
  {
    return false
  }
  return true;
    
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
