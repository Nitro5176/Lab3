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

void namesOfDepartments(char *names[], int size){
	char temp[7];
	for(int i = 0; i < size; i++){
		printf("Please enter a 6 letter department");
		scanf("%s", temp);
		names[i] = temp;
	}
}
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

void displayTable(char depIndex[], int employeeIndex[], int sizeDep, int sizeEmployee){
	printf("\n\tEmployee\tDepartments\n");
	for(int i = 0; i < sizeEmployee; i++){
		for(int j = 0; j < sizeDep ; j++){
			printf("\t%d\t\t%d\n", i, j);
		}
	}
}

void addEmptoDept(int employee[], int sizeEmp, char departments[], int sizeDep, int value[][]){
	int empTemp;
	int deptTemp;
	printf("Enter the employee number you want to add");
	scanf("%d", &empTemp);
	printf("Enter the department number you want to add the employee to");
	scanf("%d", &deptTemp);
	for(int i = 0; i < sizeEmp;i++){
		if(empTemp == employee[i]){

	}

}

}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int sizeOfEmployee;
	int sizeOfDep;


	//department array

	sizeOfDep = numOfDepartments();
	char *departments[sizeOfDep];
	for(int i = 0 ; i < sizeOfDep; i++){
		departments[i] = (char*)malloc(sizeof(char)*8);
	}
	namesOfDepartments(&departments, sizeOfDep);

	sizeOfEmployee = employeeSize();
	int arrayEmployee[sizeOfEmployee];
	numOfEmployees(arrayEmployee, sizeOfEmployee);



	//creates a 2D array of values
	int value[sizeOfDep][sizeOfEmployee];
	for(int i= 0; i< sizeOfEmployee;i++){
		value[i][0]= 0;


	}

	//Menu options
	int menu =0;
	while(menu != 4){
		displayMenu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		if(menu == 1){
			deptTemp(arrayEmployee,sizeOfEmployee,departments, numOfDepartments, value[sizeOfDep][sizeOfEmployee] );
		}
		else if(menu == 2){

		}
		else if(menu == 3){
			displayTable(&departments, arrayEmployee, sizeOfDep, sizeOfEmployee);
		}
		else if(menu == 4){
			printf("Exiting...\n");
		}
		else{
			printf("Wrong input, please try again.\n")
		}
	}


	return 0;
}
