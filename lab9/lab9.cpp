#include <iostream>
#include <queue>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
std::queue <int> Q;

int** createG(int size) {
    int** G;
    G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void BFS(int** G, int size, int s, int* dist) {
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        for (int i = 0; i < size; i++) {
            if (G[s][i] == 1 && dist[i] == INT_MAX) {
                Q.push(i);
                dist[i] = dist[s] + G[s][i];
                //cout << dist[i] << " ";

            }
        }
    }
}

void main(void) {
    setlocale(LC_ALL, "Russian");

    int** G = NULL;
    int nG, s;
    printf("Введите размер графа : ");
    scanf("%d", &nG);
    G = createG(nG);
    printG(G, nG);
    printf("Введите стартовую вершину: ");
    scanf("%d", &s);

    int* dist = NULL;
    dist = (int*)malloc(nG * sizeof(int));

    for (int i = 0; i < nG; i++) {
        dist[i] = INT_MAX;
    }

    BFS(G, nG, s, dist);
    
    for (int i = 0; i < nG; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
        printf("Расстояния от вершины %d до вершины %d = %d \n", s, i, dist[i]);
    }
}