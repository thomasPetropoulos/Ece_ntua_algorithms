#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
#include <vector>
using namespace std;

int arr[200001],lis[200001],lds[200001], res=0,finish_res=0,pseftiko_size=0;
// bs gia to pou tha valw to epomeno stoixeio sthn stiva
vector <stack<int>> v1;
vector <stack<int>> v2;

int bs(int start,int end,int f){
    while(start < end-1){
    int mid = (start+end)/2;
    if (f < v1[mid].top()) end = mid;
    else if (f == v1[mid].top()) return mid;
    else start=mid;
    }
    if (f <= v1[start].top()) return start;
    return end;
}

int bs_rev(int start,int end,int f){
    while(start < end-1){
    int mid = (start+end)/2;
    if (f < v2[mid].top()) start = mid;
    else if (f == v2[mid].top()) return mid;
    else end=mid;
    }
    if (f >= v2[start].top()) return start;
    return end;
}
//vazw stoixia se stoiva h dhmiourgw nea , lis= max mhkos apo aristera
void stackize(int i){
    int apotelesma = bs(0,v1.size(),arr[i]);
    if(apotelesma<v1.size()) v1[apotelesma].push(arr[i]);
    else {
        stack <int> neww;
        neww.push(arr[i]);
        v1.push_back(neww);
    }
    lis[i]= apotelesma;
}

void stackize_lds(int j) {
    int apotelesma = bs_rev(0,v2.size(),arr[j]);
    if(apotelesma<v2.size()) v2[apotelesma].push(arr[j]);
    else {
        stack <int> neww;
        neww.push(arr[j]);
        v2.push_back(neww);
    }
    lds[j]=apotelesma;
}

void anti_stackize(int l,int k){
    int key= arr[l]+k;
    v1[lis[l]].pop();
    if(v1[lis[l]].empty()) pseftiko_size--;
    int apotelesma = bs(0,pseftiko_size,key);
    res= apotelesma + lds[l] + 1;
    if(res>finish_res) finish_res = res;
}
int main(int argc, char *argv[]){
  /*FILE *f;
  if ((f = fopen(argv[1], "rt")) == nullptr)
    return 1;*/
    int n,k;
    scanf("%d %d", &n, &k);
    for (int i=0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //arxikopoiw stack1 kai lis
    stack <int > stack1;
    stack1.push(arr[0]);
    v1.push_back(stack1);
    lis[0]=0;
    stack <int > stack2;
    stack2.push(arr[n-1]);
    v2.push_back(stack2);
    lds[n-1]=0;
    for (int i=1 ; i < n ; i++){
        stackize(i);
    }
    for (int j=n-2 ; j>=0 ; j--){
        stackize_lds(j);
    }
    pseftiko_size=v1.size();
    res = lds[0];
    for (int l=n-1; l >0 ; l--){
        anti_stackize(l,k);
    }

    /*for (int i = 0; i < n; i++) cout << lis[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << lds[i] << " ";
    cout << endl;*/
  cout << finish_res<< endl;
  return 0;
}
