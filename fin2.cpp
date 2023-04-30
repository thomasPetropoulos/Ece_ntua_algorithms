#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int min(int a, int b) { 
    if (a == -1) return b;
    else if (b == -1) return a;
    return (a > b) ? b : a; 
}

int* minimumpricesforset(int knapsackedarrayA[], int sumwtA, int knapsackedarrayB[], int sumwtB, int knapsackedarrayC[], int sumwtC/*, int n*/){
    int sizeA = sumwtA, sizeB = sumwtB, sizeC = sumwtC;
    int minsize;

    minsize = min(sizeA, sizeB);
    minsize = min(minsize, sizeC);
    
    int *minimumprices = new int [minsize+1];
    for (int i = 1; i<= minsize; i++){
        minimumprices[i] = knapsackedarrayA[i] + knapsackedarrayB[i] + knapsackedarrayC[i];
    }
    return minimumprices;
}

int** knapSack(int wt[], int val[], int n) //minimum costs for every maximum weight 
{ 
    int i, w;
    int **K; 
    int sum=0;
    for (i=0; i<n; i++){
        sum += wt[i];
    }
    K = new int* [n+1]; 
    for (i=0; i<=n; i++){
        K[i] = new int[sum + 1];
    }
    
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= sum; w++)  
        { 
            if (i == 0 || w == 0) {
                K[i][w] = 0; 
            }
            else if (wt[i - 1] >= w) {
                if (K[i-1][w] == 0){
                    K[i][w] = val[i-1];
                }
                else {
                    K[i][w] = min(val[i - 1], K[i - 1][w]); 
                }
            }
            else { //top is -1, 0 or greater than current
                if ( K[i-1][w] == 0) K[i][w] = -1;
                else if (K[i - 1][w - wt[i - 1]] != -1){
                    K[i][w] = min(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i-1][w]);
                }
                else  K[i][w] = -1;
            }
        } 
    }
    return K; 
} 

int main() {
    int N, M;
	cin >> N >> M;
    int whosells, howmany, offer;
    char whatobject;
    vector<pair<int, int>> salesman_1_A, salesman_1_B, salesman_1_C, salesman_2_A, salesman_2_B, salesman_2_C, salesman_3_A, salesman_3_B, salesman_3_C;
    for (int i = 0; i < M; i++) {
        scanf("%d %c %d %d", &whosells, &whatobject, &howmany, &offer);
        if (whosells == 1) {
            if (whatobject == 'A') {
                salesman_1_A.push_back(make_pair(howmany, offer));
            }
            else if (whatobject == 'B') {
                salesman_1_B.push_back(make_pair(howmany, offer));
            }
            else {
                salesman_1_C.push_back(make_pair(howmany, offer));
            }
        }
        else if (whosells == 2) {
            if (whatobject == 'A') {
                salesman_2_A.push_back(make_pair(howmany, offer));
            }
            else if (whatobject == 'B') {
                salesman_2_B.push_back(make_pair(howmany, offer));
            }
            else {
                salesman_2_C.push_back(make_pair(howmany, offer));
            }
        }
        else {
            if (whatobject == 'A') {
                salesman_3_A.push_back(make_pair(howmany, offer));
            }
            else if (whatobject == 'B') {
                salesman_3_B.push_back(make_pair(howmany, offer));
            }
            else {
                salesman_3_C.push_back(make_pair(howmany, offer));
            }
        }
    }

    int wt1A[salesman_1_A.size()], val1A[salesman_1_A.size()];
    int wt1B[salesman_1_B.size()], val1B[salesman_1_B.size()];
    int wt1C[salesman_1_C.size()], val1C[salesman_1_C.size()];
    int wt2A[salesman_2_A.size()], val2A[salesman_2_A.size()];
    int wt2B[salesman_2_B.size()], val2B[salesman_2_B.size()];
    int wt2C[salesman_2_C.size()], val2C[salesman_2_C.size()];
    int wt3A[salesman_3_A.size()], val3A[salesman_3_A.size()];
    int wt3B[salesman_3_B.size()], val3B[salesman_3_B.size()];
    int wt3C[salesman_3_C.size()], val3C[salesman_3_C.size()];

    for (int i=0;i<salesman_1_A.size();i++) {
        wt1A[i] = salesman_1_A[i].first;
        val1A[i] = salesman_1_A[i].second;
    } 
    for (int i=0;i<salesman_1_B.size();i++) {
        wt1B[i] = salesman_1_B[i].first;
        val1B[i] = salesman_1_B[i].second;
    } 
    for (int i=0;i<salesman_1_C.size();i++) {
        wt1C[i] = salesman_1_C[i].first;
        val1C[i] = salesman_1_C[i].second;
    } 

    for (int i=0;i<salesman_2_A.size();i++) {
        wt2A[i] = salesman_2_A[i].first;
        val2A[i] = salesman_2_A[i].second;
    } 
    for (int i=0;i<salesman_2_B.size();i++) {
        wt2B[i] = salesman_2_B[i].first;
        val2B[i] = salesman_2_B[i].second;
    } 
    for (int i=0;i<salesman_2_C.size();i++) {
        wt2C[i] = salesman_2_C[i].first;
        val2C[i] = salesman_2_C[i].second;
    }

    for (int i=0;i<salesman_3_A.size();i++) {
        wt3A[i] = salesman_3_A[i].first;
        val3A[i] = salesman_3_A[i].second;
    } 
    for (int i=0;i<salesman_3_B.size();i++) {
        wt3B[i] = salesman_3_B[i].first;
        val3B[i] = salesman_3_B[i].second;
    } 
    for (int i=0;i<salesman_3_C.size();i++) {
        wt3C[i] = salesman_3_C[i].first;
        val3C[i] = salesman_3_C[i].second;
    }

    int **result1A = knapSack(wt1A, val1A, salesman_1_A.size()); //from the 1st salesfag how much is the mincost of x amount of A
    int **result1B = knapSack(wt1B, val1B, salesman_1_B.size()); 
    int **result1C = knapSack(wt1C, val1C, salesman_1_C.size()); 
    int **result2A = knapSack(wt2A, val2A, salesman_2_A.size()); 
    int **result2B = knapSack(wt2B, val2B, salesman_2_B.size()); 
    int **result2C = knapSack(wt2C, val2C, salesman_2_C.size());
    int **result3A = knapSack(wt3A, val3A, salesman_3_A.size()); 
    int **result3B = knapSack(wt3B, val3B, salesman_3_B.size());
    int **result3C = knapSack(wt3C, val3C, salesman_3_C.size());
 
    int W1, W2, W3;
    int sumwt1A=0, sumwt1B=0, sumwt1C=0;
    int sumwt2A=0, sumwt2B=0, sumwt2C=0;
    int sumwt3A=0, sumwt3B=0, sumwt3C=0;

    for (int i=0; i<salesman_1_A.size(); i++) {
        sumwt1A+=wt1A[i];
    }
    for (int i=0; i<salesman_1_B.size(); i++) {
        sumwt1B+=wt1B[i];
    }
    for (int i=0; i<salesman_1_C.size(); i++) {
        sumwt1C+=wt1C[i];
    }
    for (int i=0; i<salesman_2_A.size(); i++) {
        sumwt2A+=wt2A[i];
    }
    for (int i=0; i<salesman_2_B.size(); i++) {
        sumwt2B+=wt2B[i];
    }
    for (int i=0; i<salesman_2_C.size(); i++) {
        sumwt2C+=wt2C[i];
    }

    for (int i=0; i<salesman_3_A.size(); i++) {
        sumwt3A+=wt3A[i];
    }
    for (int i=0; i<salesman_3_B.size(); i++) {
        sumwt3B+=wt3B[i];
    }
    for (int i=0; i<salesman_3_C.size(); i++) {
        sumwt3C+=wt3C[i];
    }

    W1 = min(sumwt1A, sumwt1B);
    W1 = min(W1, sumwt1C);
    W2 = min(sumwt2A, sumwt2B);
    W2 = min(W2, sumwt2C);
    W3 = min(sumwt3A, sumwt3B);
    W3 = min(W3, sumwt3C);

    int *costofsetfromguy1;
    int *costofsetfromguy2;
    int *costofsetfromguy3;

    costofsetfromguy1 = minimumpricesforset(result1A[salesman_1_A.size()], sumwt1A, result1B[salesman_1_B.size()], sumwt1B, result1C[salesman_1_C.size()], sumwt1C/*, N*/);
    costofsetfromguy2 = minimumpricesforset(result2A[salesman_2_A.size()], sumwt2A, result2B[salesman_2_B.size()], sumwt2B, result2C[salesman_2_C.size()], sumwt2C/*, N*/);
    costofsetfromguy3 = minimumpricesforset(result3A[salesman_3_A.size()], sumwt3A, result3B[salesman_3_B.size()], sumwt3B, result3C[salesman_3_C.size()], sumwt3C/*, N*/);

    costofsetfromguy1[0] = 0;
    costofsetfromguy2[0] = 0;
    costofsetfromguy3[0] = 0;
    if (W1 + W2 + W3 < N) {
        printf("-1\n");
        return 0;
    }
    int result = costofsetfromguy1[W1] + costofsetfromguy2[W2] + costofsetfromguy3[W3];
    for (int i = 0; i <= W1; i++){
        for (int j = 0; j <= W2; j++){
            if (N-i-j <= W3 && N-i-j >= 0){ 
                int temp = costofsetfromguy1[i] + costofsetfromguy2[j] + costofsetfromguy3[N-i-j]; 
                if (result > temp) {
                    result = temp;
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}