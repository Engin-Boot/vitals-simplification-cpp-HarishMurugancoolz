#include <iostream>
#include <string>
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
	float vitalValue[3];

};

class vitalIntegrator
{
	LimitChecker bpmCheck, spo2Check, respRateCheck;
public:
	vitalIntegrator():bpmCheck("bpm",70,150),
		spo2Check("spo2",90,100),
		respRateCheck("respRate",35,90)
		
	{
				

	}
	void checkAllVitals(PersonsVital p[],int n_persons)
	{
		for (int i_person = 0; i_person <n_persons; i_person++)
		{
			bpmCheck.Checker(p[i_person].id, p[i_person].alert, p[i_person].vitalValue[0]);
			spo2Check.Checker(p[i_person].id, p[i_person].alert, p[i_person].vitalValue[1]);
			respRateCheck.Checker(p[i_person].id, p[i_person].alert, p[i_person].vitalValue[2]);
		}
	}


};

int main() {
	PersonsVital p[2];
	for (int i = 0; i < 2; i++)
	{
		p[i].id = to_string(i + 1);
		cout << "Enter the Alert type integer 0:AlertWithSms 1:AlertWithSound 2" << endl;
		int alert;
		cin >> alert;
		if (alert == 0)
		{
			p[i].alert = new AlertWithSMS;
		}
		else if (alert == 1)
		{
			p[i].alert = new AlertWithSound;
		}
		cout << "Enter the Bpm value" << endl;
		cin >> p[i].vitalValue[0];
		cout << "Enter the spo2 value" << endl;
		cin >> p[i].vitalValue[1];
		cout << "Enter the respRate value" << endl;
		cin >> p[i].vitalValue[2];


	}
	vitalIntegrator v1;
	v1.checkAllVitals(p,2);
	return 0;
	

	
}
