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
#include <string.h>
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
int
void addEmpToDept(int employee[], int sizeEmp, char departments[], int sizeDep, int *value[][10], int currentIndex){
	int empTemp;
	char deptTemp[7];
	printf("Enter the employee number you want to add: ");
	scanf("%d", &empTemp);
	printf("Enter the department number you want to add the employee to: ");
	scanf("%s", deptTemp);

	for(int i = 0; i < sizeDep; i++){
		printf("hi");

		if(*deptTemp == departments[i]){
			printf("hi");+
			*value[0][currentIndex] = i;
			if(empTemp == employee[i]){
				*value[1][currentIndex] = i;
				*value[2][currentIndex] = 1;
				printf("hi");
			}
		}


	}

}
void remEmpToDept(int employee[], int sizeEmp, char departments[], int sizeDep, int *value[][10], int currentIndex){
	int empTemp;
	char deptTemp[8];
	printf("Enter the employee number you want to add: ");
	scanf("%d", &empTemp);
	printf("Enter the department number you want to add the employee to: ");
	scanf("%s", deptTemp);

	for(int i = 0; i < sizeDep; i++){
		if(strcmp(deptTemp, departments[i])){
			*value[1][currentIndex] = i;
			if(empTemp == employee[i]){
				*value[2][currentIndex] = 0;
			}
		}
	}

}




int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	size_t sizeOfEmployee;
	size_t sizeOfDep;
	int currentIndex = 0;

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
	int values[sizeOfDep+1][sizeOfEmployee];
	initilaize2DArray(*values, sizeOfDep, sizeOfEmployee);


	//Menu options
	int menu =0;
	while(menu != 4){
		displayMenu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		//1. Add employee to department
		if(menu == 1){
			addEmpToDept( arrayEmployee, sizeOfEmployee, departments, sizeOfDep+1, &values, currentIndex);
			currentIndex++;
		}

		//2.Remove an employee from department
		else if(menu == 2){
			remEmpToDept( arrayEmployee, sizeOfEmployee, departments, sizeOfDep+1, &values, currentIndex);
			currentIndex++;
		}

		//3. Display the Association Table
		else if(menu == 3){
			print2DArray(*values, sizeOfDep+1, sizeOfEmployee);
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
