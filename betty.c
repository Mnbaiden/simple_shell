#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * This is the main function htat serves as the entry point of the program.
 * It shows the usage of the function to calc bmi
 *
 * Return: Alwasys 0 (Success).
 */
int main(void)
{
	float weight, height, bmi;

	printf("Please input weight in kg: \n");
	scanf("%f", &weight);

	printf("Please input height in metres: \n");
	scanf("%f", &height);

	bmi =  weight / (height * height);

	printf("Your BMI is: %1.2f\n", bmi);

	return (0);
}
