#include <iostream>

using namespace std;
#include <assert.h>
class Alert
{
    public:
        virtual void raiseAlert(const char* vitalName,const char* level)=0;
     
    
};

class AlertWithSMS:public Alert
{
    public:
        void raiseAlert(const char* vitalName,const char* level) 
        {
            cout<<"SMS:"<<vitalName<<" "<<level<<endl;
        }
};
class AlertWithSound:public Alert
{
    public:
        void raiseAlert(const char* vitalName,const char* level)
        {
            cout<<"sound:"<<vitalName<<" "<<level<<endl;
        }
};

class vital
{
    Alert *a;
    
    public:
    
    bool isInsideLimit(float,float ,float );
    bool isLow(float,float);
    bool isHigh(float,float);
    void vitalsAreOk(float, float , float);
    void bpmCheck(Alert*,float );
    void spo2Check(Alert*,float );
    void respRateCheck(Alert*,float );
        
    
};

void vital::bpmCheck(Alert *a,float bpm)
{
    if(isInsideLimit(bpm,70,150))
    {
        a->raiseAlert("bpm","normal");
    }
    else if(isLow(bpm,70))
    {
        a->raiseAlert("bpm","LOW");
    }
    else if(isHigh(bpm,150))
    {
        a->raiseAlert("bpm","High");
    }
}
void vital::spo2Check(Alert *a,float spo2)
{
    if(isInsideLimit(spo2,90,100))
    {
        a->raiseAlert("spo2","normal");
    }
    else if(isLow(spo2,90))
    {
        a->raiseAlert("spo2","LOW");
    }
    else if(isHigh(spo2,100))
    {
        a->raiseAlert("spo2","High");
    }
}
void vital::respRateCheck(Alert *a,float respRate)
{
    if(isInsideLimit(respRate,35,90))
    {
        a->raiseAlert("respRate","normal");
    }
    else if(isLow(respRate,35))
    {
        a->raiseAlert("respRate","LOW");
    }
    else if(isHigh(respRate,90))
    {
        a->raiseAlert("respRete","High");
    }
}

bool vital::isLow(float value,float lowerLimit)
{
    return(value<=lowerLimit);
}
bool vital::isHigh(float value,float upperLimit)
{
    return(value>=upperLimit);
}
bool vital::isInsideLimit(float value,float lowerLimit,float upperLimit)
{
  return (value>= lowerLimit && value <=upperLimit);
  
}

void vital::vitalsAreOk(float bpm, float spo2, float respRate) {
  
  Alert *a=new AlertWithSMS;
  bpmCheck(a,bpm);
  spo2Check(a,spo2);
  respRateCheck(a,respRate);
}

int main() {
  
  vital v;
  v.vitalsAreOk(80,90,180);
  
}
