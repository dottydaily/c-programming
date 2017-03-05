#include <stdio.h>
#define SIZE 31 // 30 days start with 0.

int check_month_year(int month, int year)
{	

	if (year <= 0 || month < 1 || month > 12)
		return 0;	
	return 1;
}

void find_max(float arr[], float max[])
{
	int day;
	float max_val = 0;

	for (day = 1 ; day < SIZE ; day++){
		if (arr[day] > max_val){
			max_val = arr[day];
			max[0] = max_val;
			max[1] = day;
		}
	}
}

void find_min(float arr[], float min[], float max)
{
	int day;
	float min_val;

	min_val = max;
	for (day = 2 ; day < SIZE ; day++){
		if (arr[day] < min_val && arr[day] != 0){
			min_val = arr[day];
			min[0] = min_val;
			min[1] = day;
		}
	}
}

int main()
{
	float income[SIZE], expense[SIZE], sum_income = 0, sum_expense = 0, 
		avg_income, avg_expense, max[2] = {0,0}, min[2] = {0,0};
	//[0] contain max/min income or expense, [1] contain day
	int month, year, day, cnt_day = 0, logic = 0;

	//set every block of two arrays with 0
	for (day = 0 ; day < SIZE ; day++){
		income[day] = 0;
		expense[day] = 0;
	}

	//Input Month and Year
	printf("Month : ");
	scanf("%d", &month);
	printf("Year : ");
	scanf("%d", &year);

	logic = check_month_year(month, year);

	if (!logic)
		printf("\nERROR");
	else
	{	
		//Input Income
		printf("\nIncome :\n");
		for (day = 6 ; day <= 30 ; day+= 6){
			printf(">> Day %2d : ", day);
			scanf("%f", &income[day]);

			if (income[day] <= 1){
				logic = 0;
				printf("\nERROR");
				break;
			}

			sum_income += income[day];
		}

		//logic = 0 when input of income is wrong.
		if (logic){
			//Input Expense
			printf("\nExpense :\n");

			//start input expense
			do{	
				printf(">> Day : ");
				scanf("%d", &day);

				//if day is out of range, this loop will be stop.
				if(day > 0 && day < 31){
					printf("= ");
					scanf("%f", &expense[day]);
					
					if (expense[day] < 1){
						logic = 0;
						break;
					}

					sum_expense += expense[day];
					cnt_day++;
					putchar('\n');
				}
				else
					printf("***** End *****\n\n");
			} while (day > 0 && day < 31) ;

			//logic = 0 when expense is wrong.
			if (logic == 0)
				printf("\nERROR");
			else{
				//Find max income and print it.
				find_max(income, max);
				printf("Max income : %.2f Baht. %02.0f/%02d/%d\n", max[0], max[1], month, year);

				//Find min income by use max from previous statement and print it.
				find_min(income, min, max[0]);
				printf("Min income : %.2f Baht. %02.0f/%02d/%d\n", min[0], min[1], month, year);
				
				//Find max expense and print it.
				find_max(expense, max);
				printf("Max expense : %.2f Baht.", cnt_day==0?0:max[0]);
				if(sum_expense!=0)
					printf(" %02.0f/%02d/%d",  max[1], month, year);
				
				//Find min expense by use max from previous statement and print it.
				find_min(expense, min, max[0]);
				printf("\nMin expense : %.2f Baht.", cnt_day==0?0:min[0]);
				if(sum_expense!=0)
					printf(" %02.0f/%02d/%d",  min[1], month, year);
				
				//Find avg income and expense, then print it.
				avg_income = sum_income/5.0;
				avg_expense = sum_expense/cnt_day;
				printf("\nAvg income : %.2f Baht.\n", avg_income);
				printf("Avg expense : %.2f Baht.\n\n", cnt_day==0?0:avg_expense);

				//Compare value of avg_income and avg_expense
				if (avg_income > avg_expense)
					printf("You have average income more than average expense.");
				else if (avg_expense > avg_income)
					printf("You have average expense more than average income.");
				else
					printf("You have average income equal to average expense.");
			}
		}
	}	
}