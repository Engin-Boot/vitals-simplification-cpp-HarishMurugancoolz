#include <iostream>
using namespace std;
#include <assert.h>
class AlertAbstract
{
public:
	virtual void raiseAlert(const char* vitalName, const char* level) = 0;

};

class AlertWithSMS :public AlertAbstract
{
public:
	void raiseAlert(const char* vitalName, const char* level)
	{
		cout << "SMS:" << vitalName << " " << level << endl;
	}
};
class AlertWithSound :public AlertAbstract
{
public:
	void raiseAlert(const char* vitalName, const char* level)
	{
		cout << "sound:" << vitalName << " " << level << endl;
	}
};

class LimitChecker
{
private:
	const char* type;
	float lowerLimit;
	float upperLimit;
public:
	LimitChecker(AlertAbstract *alert,const char* type, float value,float lowerLimit, float upperLimit) :
		type(type),
		lowerLimit(lowerLimit),
		upperLimit(upperLimit)
	{
		this->Checker(alert, value);
	}
	bool isLow(float, float);
	bool isHigh(float, float);
	bool isInsideLimit(float, float, float);
	void Checker(AlertAbstract*, float);

};

bool LimitChecker::isLow(float value, float lowerLimit)
{
	return(value < lowerLimit);
}
bool LimitChecker::isHigh(float value, float upperLimit)
{
	return(value > upperLimit);
}
bool LimitChecker::isInsideLimit(float value, float lowerLimit, float upperLimit)
{
	return (value >= lowerLimit && value <= upperLimit);

}
void LimitChecker::Checker(AlertAbstract *a,float value)
{
	if (this->isHigh(value, this->upperLimit))
		a->raiseAlert(this->type, "HIGH");
	else if (this->isLow(value, this->lowerLimit))
		a->raiseAlert(this->type, "LOW");
}


class vitalIntegrator
{
	LimitChecker bpmCheck, spo2Check, respRateCheck;
public:
	vitalIntegrator(AlertAbstract* alert, float bpm, float spo2, float respRate) :bpmCheck(alert,"bpm", bpm,70, 150),
		spo2Check(alert,"spo2",spo2 ,90, 100),
		respRateCheck(alert,"respRate", respRate,35, 90){}
};
int main() {

	
	AlertAbstract *a = new AlertWithSMS;
	vitalIntegrator v(a,80,90,170);
}
