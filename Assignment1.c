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

void displayTable(int sizeDep, int sizeEmployee, int value[][50]){
	printf("\n\tEmployee\tDepartments\tValues\n");
	for(int i = 0; i < sizeEmployee; i++){
		for(int j = 0; j < sizeDep ; j++){
			printf("\t%d\t\t%d\t\t%d\n", value[0][i], value[1][i], value[2][i]);
		}
	}
}
//****************************************************************ERROR
void addEmpToDept(int employee[], int sizeEmp, char departments[], int sizeDep, int *value[][50]){
	int empTemp;
	char deptTemp[7];
	int indexOfEmp = 0;
	int indexOfDep = 0;
	printf("Enter the employee number you want to add: ");
	scanf("%d", &empTemp);
	printf("Enter the department number you want to add the employee to: ");
	scanf("%s", deptTemp);
	for(int i = 0; i < sizeEmp; i++){
		if(empTemp == employee[i]){
			indexOfEmp = i;
		}
		if(*deptTemp == departments[i]){
			indexOfDep = i;
		}
	}

	for(int i = 0; i < (sizeEmp*sizeDep); i++){
			if((*value[0][i] == indexOfEmp) && (*value[1][0] == indexOfDep)){
				*value[2][i] = 1;
			}
	}

}
//TODO
void remEmpToDept(int employee[], int sizeEmp, char departments[], int sizeDep, int *value[][50]){

}
//************************************************************************ERROR
void initializeValues(int *value, char dep[], int emp[], int depSize, int empSize){
	int temp = 0;
	int empIncrement = 0;
	int depIncrement = 0;
	for(int i = 0; i < 2; i++){
		/*
		if(temp == depSize){
			temp = 0;
			depIncrement = 0;
			empIncrement++;
		}*/
		for(int j = 0; j < depSize*empSize; j++){
			if(i == 0){
				if(temp == 2){
					temp = 0;
					empIncrement++;
				}
				*(value+(i*empSize)+j) = empIncrement+50;
			}
			if(i == 1){
				if(temp == depSize){
					temp = 0;
					depIncrement = 0;
				}
				*(value+(i*empSize)+j) = depIncrement+20;
				depIncrement++;
			}
			//depIncrement++;
			temp++;
		}
		//the employee
		//value[0][i] = empIncrement;
		//the department
		//value[1][i] = depIncrement;

		//*(value + 0*(empSize*(depSize+1))+i+1) = 2;
		//*(value + i*2+1) = 2;
		//depIncrement++;
		//temp++;
	}
	//test if the array has been stored
//	for(int i = 0; i < empSize*depSize; i++){
//		printf("%d, %d\n", value[0][i], value[1][i]);
//	}
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

	int value[3][sizeOfEmployee*sizeOfDep];
	size_t replaceDepSize = sizeOfDep+1;

	initilaize2DArray(value, replaceDepSize, sizeOfEmployee);
	initializeValues(value, departments[7], arrayEmployee, sizeOfDep, sizeOfEmployee);

	//testing
	for(int i = 0; i < (sizeOfEmployee*sizeOfDep); i++){
		printf("%d, %d\n", value[0][i], value[1][i]);
	}
	//Menu options
	int menu =0;
	while(menu != 4){
		displayMenu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		//1. Add employee to department
		if(menu == 1){
			addEmpToDept(arrayEmployee[sizeOfEmployee],sizeOfEmployee,departments, sizeOfDep, &value[3][sizeOfEmployee]);
		}

		//2.Remove an employee from department
		else if(menu == 2){
			remEmpToDept(arrayEmployee[sizeOfEmployee],sizeOfEmployee,departments, sizeOfDep, &value[3][sizeOfEmployee]);
		}

		//3. Display the Association Table
		else if(menu == 3){
			displayTable(sizeOfDep, sizeOfEmployee, value[3][sizeOfEmployee]);
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
