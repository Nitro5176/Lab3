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
int numOfDepartments(){
	int numOfDep;
	printf("Enter the number of departments you wish to register: ");
	scanf("%d", &numOfDep);
	numOfDep++;
	return numOfDep;
	}

void menu(){

	printf("*****Menu*****\n");
	printf("1. Please enter the size of the departments. \n");
	printf("2. Please enter the amount of employee\n");
	printf("3. Display the Association Table\n");
	printf("4.Exit program\n");

}

int employeeSize(){
	int number;
	printf("Please enter the amount of employees: ");
	scanf("%d", &number);
	return number;
}

void displayTable(){

}


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int sizeOfArray;
	int sizeOfDep;


	//department array


	//Menu options
	int menu =0;
	while(menu != 4){
		menu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		if(menu == 1){
			sizeOfDep = numbersOfDepartments();
			char departments[sizeOfDep];
			namesOfDepartments();

		}
		else if (menu == 2){
			sizeOfArray = employeeSize();
			int arrayEmployee[sizeOfArray];
			numOfEmployees(arrayEmployee, sizeOfArray);
		}
		else if(menu == 3){
			displayTable();
		}
		else if(menu == 4){
			printf("Exiting...\n");
		}
		else{
			printf("Please try again.\n");
		}
	}


	return 0;
}
