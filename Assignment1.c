/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Stephen
 Version     :
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
void numOfDepartments(){

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




	return 0;
}
