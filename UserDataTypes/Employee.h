class Employee {
public:
	static const float TAX;
	static const short MAX_DAYS = 7;
	static const short MAX_HOURS = 24;

private:
	unsigned char name[32];
	unsigned short age;
	unsigned int zipcode;
	float wage;
	unsigned short daysWorked;
	float hoursWorkedPerDay[MAX_DAYS];
	float totalHours;
	float grossIncome;
	float netIncome;

public:
	void Read();
	void Write();
};
