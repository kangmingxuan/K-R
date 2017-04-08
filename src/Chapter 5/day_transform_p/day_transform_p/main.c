#include <stdio.h>

static char day_tab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year_p(int year, int month, int day);
void month_day_p(int year, int yearday, int *pmonth, int *pday);

/* This is the solution to K&R C 5-9 */
main(){
	int month, day, yearday, year;

	month = 12;
	day = 27;
	year = 2009;

	if (yearday = day_of_year_p(year, month, day))
		printf("%d-%d is %d day of %d.\n", month, day, yearday, year);

	month_day_p(year, yearday, &month, &day);
	if (month != 0 && day != 0)
	{
		printf("%d day of %d is %d-%d.\n", yearday, year, month, day);
	}
	

	return 0;
}
/* day_of_year_p: set day of year from month & day, 
 * when the input is invalid return 0 */
int day_of_year_p(int year, int month, int day)
{
	int i, leap;

	if (year < 0)
	{
		printf("Invalid year!\n");
		return 0;
	}
	else if (month < 1 || month > 12)
	{
		printf("Invalid month!\n");
		return 0;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (day < 1 || day > *(*(day_tab + leap) + month))
	{
		printf("Invalid day!\n");
		return 0;
	}

	for (i = 1; i < month; i++)
	{
		day += *(*(day_tab+leap) + i);
	}

	return day;
}
/* month_day_p: convert yearday of some year into */
void month_day_p(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;

	if (year < 0)
	{
		printf("Invalid year!\n");
		*pmonth = 0;
		*pday = 0;
		return;
	}
	else if (yearday < 1)
	{
		printf("Invalid yearday!\n");
		*pmonth = 0;
		*pday = 0;
		return;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for (i = 1; i <= 12 && yearday > *(*(day_tab+leap) + i); i++)
	{
		yearday -= *(*(day_tab+leap) + i);
	}

	if (i > 12)
	{
		printf("Invalid yearday!\n");
		*pmonth = 0;
		*pday = 0;
		return;
	}

	*pmonth = i;
	*pday = yearday;
	return;
}