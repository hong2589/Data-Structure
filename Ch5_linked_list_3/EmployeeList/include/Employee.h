#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct _employee {
	char name[100];
	int id;
} Employee;

void ShowEmployeeInfo(Employee* emp);

#endif