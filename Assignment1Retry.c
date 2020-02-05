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
#include <string.h>
#include "helper.h"



void displayMenu(){

	printf("*****Menu*****\n");
	printf("1. Add employee to department\n");
	printf("2. Remove an employee from department\n");
	printf("3. Display the Association Table\n");
	printf("4.Exit program\n");

}

int numOfDep(){

	int numOfDep;
	printf("Enter the number of departments you wish to register: ");
	scanf("%d", &numOfDep);
	return numOfDep;

}
int employeeSize(){

	int number;
	printf("Please enter the amount of employees: ");
	scanf("%d", &number);
	return number;

}
void namesOfDepartments(char *names[], int size){

	for(int i = 0; i < size; i++){
		printf("Please enter a 7 letter department: ");
		scanf("%s", names[i]);
	}

}
void numOfEmployees(int seats[], int size){


	for(int i = 0; i < size;i++){
		printf("Please enter a 5 digit number for the employee: ");
		scanf("%d", &seats[i]);
	}

}

void displayTable(int sizeDep, int sizeEmployee, int *value){

       int z=0;
       printf("\tIndex\tEmployee\tDepartment\tValue\n");
       for(int i=0 ; i< sizeEmployee ; i++){
			for(int j=0; j< sizeDep ; j++){
        		/*we print the index of  value, index of employer, index of department follow by value of value.*/
            	printf("\t%d\t\t%d\t\t%d\t\t%d\n", z, i, j, *((value+i*sizeDep)+j));
           		z++;
	    	}
	   }
}

void addEmpToDept(int employee[], int sizeEmp, char *departments[], int sizeDep, int *value){

    char *dep_name  = (char *) malloc(sizeof(char)*8);
	int empToAdd = 0;
    int row_index, column_index =0;
    printf("Enter the employee number you want to add: ");
	scanf("%d", &empToAdd);
	printf("Enter the department number you want to add the employee to: ");
	scanf("%s", dep_name);

    for(int i=0 ; i<sizeEmp ; i++){
		if(empToAdd == employee[i]){
			row_index=i;
		}
	}
	for(int j=0 ; j< sizeDep ; j++){
		if(strcmp(dep_name, departments[j])==0){
			column_index = j;
		}
	}

    *((value+row_index*sizeDep)+column_index) = 1;
	free(dep_name);

}
void removeEmpToDept(int employee[], int sizeEmp, char *departments[], int sizeDep, int *value){
    char *dep_name  = (char *) malloc(sizeof(char)*8);
	int empToAdd = 0;
    int row_index, column_index =0;
    printf("Enter the employee number you want to remove: ");
	scanf("%d", &empToAdd);
	printf("Enter the department number you want to remove the employee from: ");
	scanf("%s", dep_name);

    for(int i=0 ; i<sizeEmp ; i++){
		if(empToAdd == employee[i]){
			row_index=i;
		}
	}
	for(int j=0 ; j< sizeDep ; j++){
		if(strcmp(dep_name, departments[j])==0){
			column_index = j;
		}
	}

    *((value+row_index*sizeDep)+column_index) = 0;
	free(dep_name);

}

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int sizeOfEmployee, sizeOfDep;


    sizeOfDep= numOfDep();

    char *departments[sizeOfDep];

    for(int i = 0 ; i < sizeOfDep; i++){

		departments[i] = (char*)malloc(sizeof(char)*8);

	}

    namesOfDepartments(departments, sizeOfDep);

	//Using the printStringArray to test if values are stored correctly
    printStringArray(departments, sizeOfDep);

    sizeOfEmployee = employeeSize();
    int employee_id[sizeOfEmployee];
    numOfEmployees(employee_id, sizeOfEmployee);

	//Using printIntArray to test if values are stored correcty
    printIntArray(employee_id, sizeOfEmployee);

    int assoc_table[sizeOfEmployee][sizeOfDep];

	//Here we initialize the 2DArray
    initilaize2DArray(*assoc_table, sizeOfEmployee, sizeOfDep);
    int menu =0;

	while(menu != 4){

		displayMenu();
		printf("Select menu option: ");
		scanf("%d", &menu);

		//1. Add employee to department
		if(menu == 1){
		addEmpToDept(employee_id, sizeOfEmployee, departments,  sizeOfDep, *assoc_table);
		}

		//2.Remove an employee from department
		else if(menu == 2){
			removeEmpToDept(employee_id, sizeOfEmployee, departments,  sizeOfDep, *assoc_table);
		}

		//3. Display the Association Table
		else if(menu == 3){
			displayTable(sizeOfDep,  sizeOfEmployee, *assoc_table);
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




