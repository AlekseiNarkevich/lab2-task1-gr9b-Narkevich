#include <stdio.h>
#include <stdbool.h>
bool is_leap_year(int year) 
{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int days_since_epoch(int day, int month, int year) {
		int days = 0;
		// Считаем дни за полные годы от 1970 до (year - 1)
		for (int y = 1970; y < year; y++) {
				days += is_leap_year(y) ? 366 : 365;
		}
		// Определяем количество дней в каждом месяце текущего года
		int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (is_leap_year(year))
				month_days[1] = 29;
		// Добавляем дни за полные месяцы текущего года
		for (int m = 0; m < month - 1; m++) 
		{
				days += month_days[m];
		}
		// Добавляем оставшиеся дни (вычитаем 1, так как 1 января — нулевой день)
		days += day - 1;
		return days;
}
int main()
{
		int day, month, year;
		printf("Введите дату (день месяц год): ");
		if (scanf("%d %d %d", &day, &month, &year) != 3) {
				printf("Ошибка ввода! Попробуйте снова.\n");
				return 1;
		}
		int total_days = days_since_epoch(day, month, year);
		printf("Количество дней от 1 января 1970 до %02d.%02d.%d: %d\n", day, month, year, total_days);
		return 0;
}