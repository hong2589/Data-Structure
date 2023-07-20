#include "../include/Employee.h"
#include <stdio.h>
void ShowEmployeeInfo(Employee* emp){
	printf("[Name, id] = [%s, %d]\n", emp->name, emp->id);
}