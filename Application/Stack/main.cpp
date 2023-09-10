#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	int N;
	queue <int> q;
	int val;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		q.push(i);
	}
	
	while (q.size() > 1){
		q.pop();
		val = q.front();
		q.pop();
		q.push(val);
	}
	printf("%d\n", q.front());
	return 0;
}