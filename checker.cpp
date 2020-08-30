#include <iostream>
#include <string>
using namespace std;
#include <assert.h>
class AlertAbstract
{
public:
	virtual void raiseAlert(string id,const char* vitalName, const char* level) = 0;

};

class AlertWithSMS :public AlertAbstract
{
public:
	void raiseAlert(string id,const char* vitalName, const char* level) override
	{
		cout << "SMS:" << "person"<<" "<<id<<vitalName << " " << level << endl;
	}
};
class AlertWithSound :public AlertAbstract
{
public:
	void raiseAlert(string id,const char* vitalName, const char* level) override
	{
		cout << "sound:" <<"person" <<" "<<id<<vitalName << " " << level << endl;
	}
};

class LimitChecker
{
private:
	const char* type;
	float lowerLimit;
	float upperLimit;
public:
	LimitChecker(const char* type,float lowerLimit, float upperLimit) :
		type(type),
		lowerLimit(lowerLimit),
		upperLimit(upperLimit)
	{
	}
	bool isLow(float, float);
	bool isHigh(float, float);
	bool isInsideLimit(float, float, float);
	void Checker(string id,AlertAbstract*, float);

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
void LimitChecker::Checker(string id,AlertAbstract *a,float value)
{
	if (this->isHigh(value, this->upperLimit))
		a->raiseAlert(id,this->type, "HIGH");
	else if (this->isLow(value, this->lowerLimit))
		a->raiseAlert(id,this->type, "LOW");


}
struct PersonsVital
{

	string id;//id or name
	AlertAbstract *alert;
	float bpmValue;
	float spo2Value;
	float respRateValue;

};

class vitalIntegrator
{
	LimitChecker bpmCheck, spo2Check, respRateCheck;
public:
	vitalIntegrator():bpmCheck("bpm",70, 150),
		spo2Check("spo2",90, 100),
		respRateCheck("respRate",35,90)
		
	{
		
				

	}
	void checkAllVitals(PersonsVital p[], int n_person)
	{
		for (int i_person = 0; i_person < n_person; i_person++)
		{
			bpmCheck.Checker(p[i_person].id, p[i_person].alert, p[i_person].bpmValue);
			spo2Check.Checker(p[i_person].id, p[i_person].alert, p[i_person].spo2Value);
			respRateCheck.Checker(p[i_person].id, p[i_person].alert, p[i_person].bpmValue);
		}
	}


};
int main() {
	PersonsVital p[2];
	for (int i = 0; i < 2; i++)
	{
		p[i].id = to_string(i+1);
		cout << "Enter the Alert type integer 0:AlertWithSms 1:AlertWithSound" << endl;
		int alert;
		cin >> alert;
		if (alert == 0)
		{
			p[i].alert = new AlertWithSMS;
		}
		else
		{
			p[i].alert = new AlertWithSound;
		}

		cout << "Enter the Bpm value" << endl;
		cin >> p[i].bpmValue;
		cout << "Enter the spo2 value" << endl;
		cin >> p[i].spo2Value;
		cout << "Enter the respRate value" << endl;
		cin >> p[i].respRateValue;
		
	}
	vitalIntegrator v1;
	v1.checkAllVitals(p, 2);
	

	
}
