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
		float type;
		float lowerLimt;
		float upperLimit;
		AlertAbstract *alert;
public:
	bool isLow(float, float);
	bool isHigh(float, float);
	bool isInsideLimit(float, float, float);

};

bool LimitChecker::isLow(float value, float lowerLimit)
{
	return(value <= lowerLimit);
}
bool LimitChecker::isHigh(float value, float upperLimit)
{
	return(value >= upperLimit);
}
bool LimitChecker::isInsideLimit(float value, float lowerLimit, float upperLimit)
{
	return (value >= lowerLimit && value <= upperLimit);

}

class vital
{
	
	public:
		void Checker(AlertAbstract*, const char*,float,float,float);


};


void vital::Checker(AlertAbstract *a, const char* type ,float value,float lowerLimit, float  upperLimit)
{
	LimitChecker lm;
	if (lm.isHigh(value, upperLimit))
		a->raiseAlert(type, "HIGH");
	else if(lm.isLow(value, lowerLimit))
		a->raiseAlert(type, "LOW");


}

int main() {

	vital v;
	AlertAbstract *a = new AlertWithSMS;
	v.Checker(a, "bpm", 30, 65, 150);

}
