/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Stephen To & Winfield Chan
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void numOfEmployees(int seats[], int size){
	int temp;
	for(int i = 0; i < size;i++){
		printf("Please enter a 5 digit number for the employee");
		scanf("%d", &temp);
		seats[i] = temp;
	}
}
void numOfDepartments()

	{
		int numOfDep;
			printf("Enter the number of departments you wish to register: ");
			scanf("%d", &numOfDep);
			numOfDep++;
			return numOfDep;
		}
	}

void menu(){

		prinf("*****Menu*****\n");
		prinf("1. Add an employee to a department\n");
		prinf("2. Remove an employee to a department\n");
		prinf("3.Display the Association Table\n");
		prinf("4.Exit program\n");

}

int employeeSize(){
	int number;
	printf("Please enter the amount of employees: ");
	scanf("%d", &number);
	return number;
}


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int sizeOfArray = employeeSize();

	int arrayEmployee[sizeOfArray];

	numOfEmployees(arrayEmployee, sizeOfArray);

	//department array

	char Departments[numberOfDepartments()];


	//Menu options
	int menu =0;
	while(menu != 4){
		menu();
		printf("Select menu option: ");
		scanf("%d", &menu);
	}


	return 0;
}
