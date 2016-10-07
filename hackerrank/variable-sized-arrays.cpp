#include <iostream>
using namespace std;

int main() {
	int N, Q;

	scanf("%d %d", &N, &Q);

	int** va = (int **)alloca(sizeof(int*) * N);

	for (int i = 0; i<N; i++) {
		int M;
		scanf("%d", &M);

    	int* subVa = (int *)alloca(sizeof(int) * M);
		for (int j = 0; j<M; j++)
			scanf("%d", &subVa[j]);
		va[i] = subVa;
	}

	for (int i = 0; i<Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", va[a][b]);
	}

	return 0;
}
