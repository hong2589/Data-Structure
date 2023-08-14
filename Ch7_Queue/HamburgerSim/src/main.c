#include "../include/ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CUS_COME_TERM 15 // 고객의 주문 간격

#define CHE_BUR 0 // 0. 치즈버거
#define BUL_BUR 1 // 1. 불고기버거
#define DUB_BUR 2 // 2. 더블불고기버거

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void){
	int sec;
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	Queue que;
	
	Init(&que);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++){
		if (sec % CUS_COME_TERM == 0){ // event occurs
			switch(rand() % 3){
				case CHE_BUR:
					Enqueue(&que, CHE_TERM);
					cheOrder += 1;
					break;
				case BUL_BUR:
					Enqueue(&que, BUL_TERM);
					bulOrder += 1;
					break;
				case DUB_BUR:
					Enqueue(&que, DUB_TERM);
					dubOrder += 1;
					break;
			}
		}
		if (makeProc <= 0 && !IsEmpty(&que)){
			makeProc = Dequeue(&que);
		}
		makeProc -= 1;
	}
	
	// Report
	printf("Simulation Report\n");
	printf("Cheese Burger : %d\n", cheOrder);
	printf("Bulgogi Burger : %d\n", bulOrder);
	printf("Double Burger : %d\n", dubOrder);
}