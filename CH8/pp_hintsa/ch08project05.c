#include <stdio.h>
#define NUM_RATES ((int) (sizeof(value)/sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main (){
	int i, j, low_rate, num_years, year;
	double value[5];
	double value_monthly;

	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);

	printf("\nYears");
	for(i = 0; i<NUM_RATES; i++){
		printf("%6d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}

	printf("\n");

	for(year = 1; year <= num_years; year++){
		printf("%3d	", year);
		for(i = 0; i<NUM_RATES; i++){
			value_monthly = value[i];
			for(j = 0; j < 12; j++){
				value_monthly += ((low_rate+i)/100.0)/12*value_monthly;
			}
			value[i] = value_monthly;
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}
	return 0;
}