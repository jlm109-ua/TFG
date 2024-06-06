// problem statement is in https://www.hackerrank.com/contests/w35/challenges/triple-recursion/problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define  ll long long int
#define pb push_back
#define F first
#define S second
#define pp pair<int,int>
#define mod 1e9+7
int m;

char* remove0(const char *s){
    int l = strlen(s);
    char *a = (char*)malloc(l + 1);
    int ind=0;
    for(int i=0;i<l;i++){
        if(s[i] != '0'){
            ind = i;
            break;
        }
    }
    strcpy(a, s + ind);
    return a;
}

void runMain(){
    int t=1;
    int az=89;
    while(t--){
        int n, m, k;
        n = 5;
        m = 10;
        k = 7;
        int dp[n][n];
        dp[0][0]=m;
        az=89;
        for(int i=1;i<n;i++){
            dp[i][i] = dp[i-1][i-1]+k;
        }
        az=89;
        for(int i=0;i<n;i++){
            int val = dp[i][i];
            for(int j=i+1;j<n;j++){
                dp[i][j]= --val;
            }
            val = dp[i][i];
            for(int j=i+1;j<n;j++){
                dp[j][i] = --val;
            }
        }
        az=89;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            }
        }
    }
}

int main(){
   runMain();
    return 0;
}
