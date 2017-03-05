#include <stdio.h>
#include <string.h>
#define SIZE 31 // 30 days start with 0.

int check_month_year(int month, int year)
{	

	if (year <= 0)
		return 0;

	if (month < 1 || month > 12){
		//puts("Wrong Month");
		return 0;
	}
	
	return 1;
}

void find_max(float arr[], float max[])
{
	int day;
	float max_val = 0;

	for (day = 1 ; day <= SIZE ; day++){
		if (arr[day] > max_val){
			max[0] = arr[day];
			max[1] = day;
		}
	}
}

void find_min(float arr[], float min[])
{
	int day;
	float min_val;

	min_val = arr[1];
	for (day = 2 ; day <= SIZE ; day++){
		if (arr[day] < min_val){
			min[0] = arr[day];
			min[1] = day;
		}
	}
}

int main()
{
	float income[SIZE], expense[SIZE], sum_income = 0, sum_expense = 0, avg_income, avg_expense, max[2], min[2];
	//[0] contain max/min income or expense, [1] contain day
	int month, year, day, cnt_day = 0, logic = 0;

	//set every block of two arrays with 0
	for (day = 1 ; day <= SIZE ; day++){
		income[day] = 0;
		expense[day] = 0;
	}

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
			scanf("%f", income[day]);

			if (income[day] <= 1){
				logic = 0;
				break;
			}

			sum_income += income[day];
		}

		//Input Expense
		printf("\nExpense :\n");

		do{	
			printf(">> Day : ");
			scanf("%d", day);

			if(day > 0 || day < 31){
				printf("= ");
				scanf("%f", expense[day]);
				
				if (expense[day] < 1){
					logic = 0;
					break;
				}

				sum_expense += expense[day];
				cnt_day++;
			}
			else
				printf("***** End *****\n\n");
		} while (day > 0 || day < 31) ;

		if (logic == 0)
			printf("\nERROR");
		else{
			//Find max, min, avg and print it.
			find_max(income, max);
			printf("Max income : %.2f Baht. %2.0f/%d/%d", max[0], max[1], month, year);
			
			find_min(income, max);
			printf("Min income : %.2f Baht. %2.0f/%d/%d", min[0], min[1], month, year);

			find_max(expense, max);
			printf("Max expense : %.2f Baht.", max[0]);
			if(sum_expense!=0)
				printf(" %2.0f/%d/%d\n",  max[1], month, year);

			find_min(expense, max);
			printf("Min expense : %.2f Baht.", min[0]);
			if(sum_expense!=0)
				printf(" %2.0f/%d/%d\n",  min[1], month, year);
			
			avg_income = sum_income/5.0;
			avg_expense = sum_expense/cnt_day;
			printf("Avg income : %.2f Baht.\n", avg_income);
			printf("Avg expense : %.2f Baht.\n", avg_expense);

			if (avg_income != avg_expense)
				printf("You have average %s more than average %s.", 
					(avg_income>avg_expense?/*"income":"expense"));*/("income","expense"):("expense","income")));
			else
				printf("You have average income equal to average expense.");
		}
	}
}