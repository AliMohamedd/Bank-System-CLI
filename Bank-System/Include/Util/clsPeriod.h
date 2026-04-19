#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsPeriod
{
public:
	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();


	}

	static bool IsTwoPeriodsOverlap(clsPeriod Period1, clsPeriod Period2)
	{
		if (clsDate::IsDate1AfterDate2(Period2.StartDate, Period2.EndDate) ||
			clsDate::IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate)) return false;
		else return true;
	}

	static short PeriodInDays(clsPeriod Period, bool EndDay = true)
	{
		short days = clsDate::TwoDatesDifferenceInDays(Period.StartDate, Period.EndDate);
		return (EndDay && days > 0) ? ++days : days;
	}

	short InDays(bool EndDay = true)
	{
		return PeriodInDays(*this, EndDay);
	}

	static bool IsDateWithinPeriod(clsDate Date, clsPeriod Period)
	{
		if ((clsDate::IsDate1BeforeDate2(Date, Period.EndDate) && clsDate::IsDate1AfterDate2(Date, Period.StartDate)) ||
			(clsDate::IsDate1EqualsDate2(Date, Period.StartDate)) ||
			(clsDate::IsDate1EqualsDate2(Date, Period.EndDate))) return true;
		else return false;
	}

	bool IsDateWithin(clsDate Date)
	{
		return IsDateWithinPeriod(Date, *this);
	}

	static short OverlapDaysOfTwoPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		clsDate date1, date2;
		if (clsDate::IsDate1AfterDate2(Period1.StartDate, Period2.StartDate)) date1 = Period1.StartDate;
		else date1 = Period2.StartDate;

		if (clsDate::IsDate1AfterDate2(Period1.EndDate, Period2.EndDate)) date2 = Period2.EndDate;
		else date2 = Period1.EndDate;

		bool IsOverlaped = IsTwoPeriodsOverlap(Period1, Period2);

		return (IsOverlaped) ? clsDate::TwoDatesDifferenceInDays(date1, date2) : 0;
	}

};

