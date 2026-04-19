#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
#include"clsString.h"

using namespace std;

class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string Date)
	{
		*this = StringToDate(Date);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short YearDay, short Year)
	{
		string Date;
		Date = DateFromTotalDaysFromTheYearBeginning(YearDay, Year);
		*this = StringToDate(Date);
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	// Main Function
	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));
	}

	static clsDate StringToDate(string StringDate)
	{
		clsDate date;

		vector <string> vDate = clsString::Split(StringDate, "/");

		date._Day = stoi(vDate[0]);
		date._Month = stoi(vDate[1]);
		date._Year = stoi(vDate[2]);

		return date;
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(short Number)
	{
		if (Number % 100 == 0)
		{
			if (Number % 400 == 0)
				return true;
			else
				return false;
		}
		else
		{
			if (Number % 4 == 0)
				return true;
			else
				return false;
		}
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12) return 0;

		short days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : days[Month - 1];

	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}

	static short TotalDaysFromTheYearBeginning(short Year, short Month, short Day)
	{
		short totalDays = 0;
		for (short i = 1; i < Month; i++)
			totalDays += NumberOfDaysInAMonth(Year, i);
		return totalDays += Day;
	}

	short TotalDaysFromTheYearBeginning()
	{
		return TotalDaysFromTheYearBeginning(_Year, _Month, _Day);
	}

	static string DateFromTotalDaysFromTheYearBeginning(short Year, short Days)
	{
		short totalDays = Days;
		short monthDays = 0;
		short month = 1;
		while (true)
		{
			monthDays = NumberOfDaysInAMonth(Year, month);
			if (totalDays > monthDays)
			{
				totalDays -= monthDays;
				month++;
			}
			else
				break;
		}
		string date = to_string(totalDays) + "/" + to_string(month) + "/" + to_string(Year);
		return date;
	}

	string DateFromTotalDaysFromTheYearBeginning(short Days)
	{
		return DateFromTotalDaysFromTheYearBeginning(_Year, Days);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short DayNameInYear(short Year, short Month, short Day)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + (12 * a) - 2;
		return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
	}

	short DayNameInYear()
	{
		return DayNameInYear(*this);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thus", "Fri", "Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName()
	{
		return DayShortName(DayNameInYear());
	}

	static string MonthShortName(short Month)
	{
		string MonthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun"
							  , "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return MonthNames[Month - 1];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Year, short Month)
	{
		short MonthDaysNumber = NumberOfDaysInAMonth(Year, Month);
		short firstDay = DayNameInYear(Year, Month, 1);
		short count = 1;
		cout << "\n\n  ---------------" << MonthShortName(Month) << "---------------"
			<< "\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n  ";
		for (short i = 0; i < 7; i++)
		{
			if (i >= firstDay) cout << setfill(' ') << setw(3) << count++ << "  ";
			else cout << setfill(' ') << setw(3) << ' ' << "  ";
		}
		cout << "\n  ";
		for (short i = 0; i < 4; i++)
		{
			for (short i = 0; i < 7; i++)
			{
				if (count <= MonthDaysNumber)
					cout << setfill(' ') << setw(3) << count++ << "  ";
			}
			cout << "\n  ";
		}
		cout << "\n  ---------------------------------" << endl;
	}

	void printMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n\n  ---------------------------------\n\n");
		printf("           Calendar - %i", Year);
		printf("\n\n  ---------------------------------\n");
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year < Date2._Year)
			return true;
		else
		{
			if (Date1._Year == Date2._Year)
			{
				if (Date1._Month < Date2._Month)
					return true;
				else
				{
					if (Date1._Month == Date2._Month)
					{
						if (Date1._Day < Date2._Day) return true;
						else false;
					}
					return false;
				}
			}
			return false;
		}
	}

	bool IsBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualsDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year != Date2._Year) ? false : (Date1._Month != Date2._Month) ? false : (Date1._Day == Date2._Day) ? true : false;
	}

	bool IsEqualsDate2(clsDate Date2)
	{
		return IsDate1EqualsDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2);
	}

	bool IsAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		short LastDay = NumberOfDaysInAMonth(Date._Year, Date._Month);
		return (Date._Day == LastDay) ? true : false;
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12) ? true : false;
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate temp;
		temp._Year = Date1._Year;
		temp._Month = Date1._Month;
		temp._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;

		Date2._Year = temp._Year;
		Date2._Month = temp._Month;
		Date2._Day = temp._Day;
	}

	void SwapDates(clsDate& Date)
	{
		SwapDates(*this, Date);
	}

	static short TwoDatesDifferenceInDays(clsDate Date1, clsDate Date2, bool AddEndDay = false)
	{
		short FlagOfSwap = 1;
		if (IsDate1BeforeDate2(Date2, Date1))
		{
			SwapDates(Date1, Date2);
			FlagOfSwap = -1;
		}
		short yearsDate2 = 0;
		short diffDays = 0;
		if (Date1._Year < Date2._Year)
		{
			yearsDate2 = Date2._Year;
			while (Date1._Year != --yearsDate2)
			{
				diffDays += (IsLeapYear(yearsDate2)) ? 366 : 365;
			}
		}
		short totalDays1 = 0, totalDays2 = 0;
		totalDays1 = TotalDaysFromTheYearBeginning(Date1._Year, Date1._Month, Date1._Day);
		totalDays2 = TotalDaysFromTheYearBeginning(Date2._Year, Date2._Month, Date2._Day);

		short result = (AddEndDay) ? 1 : 0;

		if (Date1._Year < Date2._Year)
		{
			totalDays2 += (IsLeapYear(Date2._Year)) ? 366 : 365;
			if (totalDays2 >= totalDays1)
				result += ((totalDays2 - totalDays1) + diffDays + result) * FlagOfSwap;
			return result;
		}
		else if (Date1._Year == Date2._Year)
		{
			if (totalDays2 >= totalDays1)
				result += ((totalDays2 - totalDays1) + diffDays + result) * FlagOfSwap;
			return result;
		}
		return -1;
	}

	short TwoDatesDifferenceInDays(clsDate Date2, bool AddEndDay = false)
	{
		return TwoDatesDifferenceInDays(*this, Date2, AddEndDay);
	}

	static short CalculateAge(clsDate Date)
	{
		clsDate date1;
		time_t t = time(0);
		tm* now = localtime(&t);
		date1._Year = now->tm_year + 1900;
		date1._Month = now->tm_mon + 1;
		date1._Day = now->tm_mday;
		cout << date1._Year << " " << date1._Month << " " << date1._Day << endl;
		return TwoDatesDifferenceInDays(Date, date1);
	}

	static string DateAfterAddingDays(short Year, short Month, short Day, short Days)
	{
		Days += TotalDaysFromTheYearBeginning(Year, Month, Day);
		Month = 1;
		short monthDays = 0;
		while (Days > 31)
		{
			if (Month > 12)
			{
				Year++;
				Month = 1;
			}
			monthDays -= NumberOfDaysInAMonth(Year, Month++);
			if (Days > monthDays)
			{
				Days -= monthDays;
			}
			else
				break;

		}
		return to_string(Days) + "/" + to_string(Month) + "/" + to_string(Year);
	}

	string AfterAddingDays(short Days)
	{
		return DateAfterAddingDays(_Year, _Month, _Day, Days);
	}

	static clsDate DateAfterDayPlus(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
				Date._Day = 1;
			}
			else
			{
				Date._Month++;
				Date._Day = 1;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}

	void AfterDayPlus()
	{
		*this = DateAfterDayPlus(*this);
	}

	static clsDate IncreaseDateByXDays(clsDate Date, int Days)
	{
		while (Days--)
			Date = DateAfterDayPlus(Date);
		return Date;
	}

	void IncreaseByXDays(int Days)
	{
		*this = IncreaseDateByXDays(*this, Days);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		short week = 7;
		short MonthDays = 0;

		MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
		if ((Date._Day + week) > MonthDays)
		{
			Date._Day = (Date._Day + week) - MonthDays;
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Year++;
				Date._Month = 1;
			}
			else
				Date._Month++;
		}
		else
			Date._Day += week;

		return Date;
	}

	void IncreaseByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, int Weeks)
	{
		while (Weeks--)
			Date = IncreaseDateByOneWeek(Date);
		return Date;
	}

	void IncreaseByXWeeks(int Weeks)
	{
		*this = IncreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		short monthDays = 0;
		if (IsLastMonthInYear(Date._Month))
		{
			Date._Year++;
			Date._Month = 1;
			monthDays = 31;
			if (monthDays < Date._Day)
			{
				Date._Month++;
				Date._Day = Date._Day - monthDays;
			}
		}
		else
		{
			Date._Month++;
			monthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
			if (monthDays < Date._Day)
			{
				Date._Month++;
				Date._Day = Date._Day - monthDays;
			}
		}

		return Date;
	}

	void IncreaseByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, short Months)
	{
		while (Months--)
			Date = IncreaseDateByOneMonth(Date);
		return Date;
	}

	void IncreaseByXMonths(short Months)
	{
		*this = IncreaseDateByXMonths(*this, Months);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate Date, short Years)
	{
		Date._Year = Date._Year + Years;
		return Date;
	}

	void IncreaseByXYears(short Years)
	{
		*this = IncreaseDateByXYears(*this, Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		for (short i = 0; i < 10; i++)
			Date = IncreaseDateByOneYear(Date);
		return Date;
	}

	void IncreaseByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate Date, short Decades)
	{
		Date._Year += Decades * 10;
		return Date;
	}

	void IncreaseByXDecades(short Decades)
	{
		*this = IncreaseDateByXDecades(*this, Decades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;
		return Date;
	}

	void IncreaseByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}

	void IncreaseByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}

	static bool IsFirstDayInMonth(short Day)
	{
		return (Day == 1) ? true : false;
	}

	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(_Day);
	}

	static bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1) ? true : false;
	}

	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(_Month);
	}

	static clsDate DateAfterDayMinus(clsDate Date)
	{
		if (IsFirstDayInMonth(Date._Day))
		{
			if (IsFirstMonthInYear(Date._Month))
			{
				Date._Year--;
				Date._Month = 12;
				Date._Day = 31;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}

	void AfterDayMinus()
	{
		*this = DateAfterDayMinus(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate Date, int Days)
	{
		while (Days--)
			Date = DateAfterDayMinus(Date);
		return Date;
	}

	void DecreaseByXDays(int Days)
	{
		*this = DecreaseDateByXDays(*this, Days);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		short week = 7;
		short MonthDays = 0;

		if ((Date._Day - week) < 0)
		{
			if (IsFirstMonthInYear(Date._Month))
			{
				Date._Year--;
				Date._Month = 12;
				MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
				Date._Day = (Date._Day + MonthDays) - week;
			}
			else
			{
				Date._Month--;
				MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
				Date._Day = (Date._Day + MonthDays) - week;
			}
		}
		else
			Date._Day -= week;

		return Date;
	}

	void DecreaseByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, short Weeks)
	{
		while (Weeks--)
			Date = DecreaseDateByOneWeek(Date);
		return Date;
	}

	void DecreaseByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		short monthDays = 0;
		if (IsFirstMonthInYear(Date._Month))
		{
			Date._Year--;
			Date._Month = 12;
			monthDays = 31;
		}
		else
		{
			Date._Month--;
			monthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
			if (monthDays < Date._Day)
			{
				Date._Day = Date._Day - monthDays;
				Date._Month--;
				monthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
				Date._Day = monthDays - Date._Day;
			}
		}

		return Date;
	}

	void DecreaseByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, short Months)
	{
		while (Months--)
			Date = DecreaseDateByOneMonth(Date);
		return Date;
	}

	void DecreaseByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(*this, Months);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}

	void DecreaseByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate Date, short Years)
	{
		Date._Year = Date._Year - Years;
		return Date;
	}

	void DecreaseByXYears(short Years)
	{
		*this = DecreaseDateByXYears(*this, Years);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		for (short i = 0; i < 10; i++)
			Date = DecreaseDateByOneYear(Date);
		return Date;
	}

	void DecreaseByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate Date, short Decades)
	{
		Date._Year -= Decades * 10;
		return Date;
	}

	void DecreaseByXDecades(short Decades)
	{
		*this = DecreaseDateByXDecades(*this, Decades);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;
	}

	void DecreaseByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static short DayNameInYear(clsDate Date)
	{
		return DayNameInYear(Date._Year, Date._Month, Date._Day);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		short dayWeek = DayNameInYear(Date);
		return (dayWeek == 6) ? true : false;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short dayWeek = DayNameInYear(Date);
		return (dayWeek == 5 || dayWeek == 6) ? true : false;
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		short dayWeek = DayNameInYear(Date);
		return 6 - dayWeek;
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		return NumberOfDaysInAMonth(Date._Year, Date._Month) - Date._Day + 1;
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		short YearDays = (IsLeapYear(Date._Year)) ? 366 : 365;
		return YearDays - TotalDaysFromTheYearBeginning(Date._Year, Date._Month, Date._Day) + 1;
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short StartDateExcludeDays(clsDate Date)
	{
		short dayOrder = DayNameInYear(Date);
		return (dayOrder == 6) ? 1 : 2;
	}

	short StartDateExcludeDays()
	{
		return StartDateExcludeDays(*this);
	}

	static short EndDateExcludeDays(clsDate Date)
	{
		short dayOrder = DayNameInYear(Date);
		return (dayOrder == 5) ? 1 : (dayOrder == 6) ? 2 : 0;
	}

	short EndDateExcludeDays()
	{
		return EndDateExcludeDays(*this);
	}

	static short VacationDays(clsDate Date1, clsDate Date2)
	{
		//when two days weekend together you get -1 
		//when the difference less than 4 u get the result minus 1
		//now the code it should be ok after Last Edit
		//****This Function calculate the days, it supposes the last day is last day in vacation.****
		short Excludes = 0;
		short TotalDays = TwoDatesDifferenceInDays(Date1, Date2) + 1;
		short Weeks = (TotalDays / 7);
		if (DayNameInYear(Date1) == DayNameInYear(Date2) && IsWeekEnd(Date1)) return 0;
		if (DayNameInYear(Date1) == (DayNameInYear(Date2) - 1) && IsWeekEnd(Date1)) return 0;
		Excludes = StartDateExcludeDays(Date1);
		if (DayNameInYear(Date2) >= DayNameInYear(Date1)) Excludes = 0;
		Excludes += EndDateExcludeDays(Date2);
		if (IsWeekEnd(Date2) && TotalDays < 8) return  ++TotalDays - (Excludes + (Weeks * 2));
		if (Excludes != 0 && TotalDays > 5) TotalDays++;
		//cout << "\n\n********" << Excludes << ' ' << Weeks << "*********\n\n";
		return  TotalDays - (Excludes + (Weeks * 2));
	}

	short VacationDays(clsDate Date2)
	{
		return VacationDays(*this, Date2);
	}

	static clsDate VacationReturnDate(clsDate Date1, short VacationDuration)
	{
		while (VacationDuration--)
		{
			if (IsWeekEnd(Date1))
				VacationDuration++;
			Date1 = IncreaseDateByXDays(Date1, 1);
		}
		while (IsWeekEnd(Date1)) Date1 = IncreaseDateByXDays(Date1, 1);
		return Date1;
	}

	clsDate VacationReturnDate(short VacationDuration)
	{
		return VacationReturnDate(*this, VacationDuration);
	}

	static short CompareTwoDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2)) return -1;
		else if (IsDate1EqualsDate2(Date1, Date2)) return 0;
		else return 1;
	}

	short CompareWithOtherDate(clsDate Date2)
	{
		return CompareTwoDates(*this, Date2);
	}

	static bool IsDayInMonth(clsDate Date)
	{
		short LastDay = NumberOfDaysInAMonth(Date._Year, Date._Month);
		return (Date._Day && Date._Day < ++LastDay) ? true : false;
	}

	bool IsDayInMonth()
	{
		return IsDayInMonth(*this);
	}

	static bool IsMonthInYear(clsDate Date)
	{
		return (Date._Month > 0 && Date._Month < 13) ? true : false;
	}

	bool IsMonthInYear()
	{
		IsMonthInYear(*this);
	}

	static bool IsValidYear(clsDate Date)
	{
		return (Date._Year > 0) ? true : false;
	}

	bool IsValidYear()
	{
		return IsValidYear(*this);
	}

	static bool IsValidDate(clsDate Date)
	{
		return (IsValidYear(Date) &&
			IsMonthInYear(Date) &&
			IsDayInMonth(Date)) ? true : false;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormatedDateString = "";

		FormatedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormatedDateString = clsString::ReplaceWord(FormatedDateString, "mm", to_string(Date._Month));
		FormatedDateString = clsString::ReplaceWord(FormatedDateString, "yyyy", to_string(Date._Year));

		return FormatedDateString;
	}

	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}
};

