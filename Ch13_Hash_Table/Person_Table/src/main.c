#include "../include/Table.h"
#include "../include/Person.h"
#include <stdio.h>
#include <stdlib.h>
int MyHashFunc(int k){
	return k % 100;
}
int main(void){
	Table table;
	Person* p1;
	Person* p2;
	Person* p3;

	// 1. Insert
	Init(&table, MyHashFunc);
	p1 = MakePersonData(20120003, "Lee", "Seoul");
	Insert(&table, GetSSN(p1), p1);

	p1 = MakePersonData(20130012, "Kim", "Jeju");
	Insert(&table, GetSSN(p1), p1);

	p1 = MakePersonData(20170049, "Han", "Kangwon");
	Insert(&table, GetSSN(p1), p1);

	// 2. Search
	p2 = Search(&table, 20120003);
	ShowPersonInfo(p2);
	p2 = Search(&table, 20130012);
	ShowPersonInfo(p2);
	p2 = Search(&table, 20170049);
	ShowPersonInfo(p2);

	// 3. Delete
	p3 = Delete(&table, 20120003);
	free(p3);
	p3 = Delete(&table, 20130012);
	free(p3);
	p3 = Delete(&table, 20170049);
	free(p3);

	return 0;

}