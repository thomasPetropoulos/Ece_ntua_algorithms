#include <bits/stdc++.h>
#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int parent[10000001], size[10000001];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[][3], int low, int high) 
{ 
    int pivot = arr[high][2]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j][2] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
            swap(&arr[i][2], &arr[j][2]); 
        } 
    } 
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    swap(&arr[i + 1][2], &arr[high][2]); 
    return (i + 1); 
} 
void quickSort(int arr[][3], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int pin[1000001], portals[1000001][3];
int main(int argc, char *argv[]) {
    FILE *f;
    if ((f = fopen(argv[1], "rt")) == nullptr)
    return 1;
    
    int N,M;
    fscanf(f, "%d %d", &N, &M);
    for (int i=0; i < N ; i++){
        fscanf(f, "%d", &pin[i]);
    }
    for (int j=0 ; j<M; j++){
        fscanf(f, "%d %d %d", &portals[j][0], &portals[j][1], &portals[j][2]);
    }
    quickSort(portals,0,M-1);


    int start = 0, end = M-1, mid = (start+end)/2;
    for(int i=mid; i<M-1; i++){
        union_sets(portals[i][0],portals[i][1]);
    }

    for(int k=0 ; k<N ; k++){
        cout << parent[k];
    }



}