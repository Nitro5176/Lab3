/*
 ============================================================================
 Name        : Assignment1Retry.c
 Author      : Stephen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void namesOfDepartments(char names[], int size){
	char temp[7];
	for(int i = 0; i < size; i++){
		printf("Please enter a 6 letter department: ");
		scanf("%s", temp);
		names[i] = temp;
	}
}
void numOfEmployees(int seats[], int size){
	int temp;
	for(int i = 0; i < size;i++){
		printf("Please enter a 5 digit number for the employee: ");
		scanf("%d", &temp);
		seats[i] = temp;
	}
}
int numOfDepartments(){
	int numOfDep;
	printf("Enter the number of departments you wish to register: ");
	scanf("%d", &numOfDep);
	return numOfDep;
	}

void displayMenu(){

	printf("*****Menu*****\n");
	printf("1. Add employee to department\n");
	printf("2. Remove an employee from department\n");
	printf("3. Display the Association Table\n");
	printf("4.Exit program\n");

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

	size_t sizeOfEmployee;
	size_t sizeOfDep;


	//department array

	sizeOfDep = numOfDepartments();
	char *departments[sizeOfDep];
	for(int i = 0 ; i < sizeOfDep; i++){
		departments[i] = (char*)malloc(sizeof(char)*8);
	}
	namesOfDepartments(&departments[sizeOfDep], sizeOfDep);

	sizeOfEmployee = employeeSize();
	int arrayEmployee[sizeOfEmployee];
	numOfEmployees(arrayEmployee, sizeOfEmployee);



	//creates a 2D array of values
	int values[sizeOfDep][sizeOfEmployee];
	initilaize2DArray(*values, sizeOfDep, sizeOfEmployee);


	//Menu options
	int menu =0;
	while(menu != 4){
		displayMenu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		//1. Add employee to department
		if(menu == 1){

		}

		//2.Remove an employee from department
		else if(menu == 2){

		}

		//3. Display the Association Table
		else if(menu == 3){
			print2DArray(*values, sizeOfDep, sizeOfEmployee);
		}
		//4. Exiting
		else if(menu == 4){
			printf("Exiting...\n");
		}
		else{
			printf("Wrong input, please try again.\n");
		}
	}


	return 0;
}
