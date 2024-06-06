#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int prime[1000005];
int an1[1000005];
int an2[1000005];

void runMain(){
    int i,j;
    prime[0]=prime[1]=1;
    for(i=2;i<=1000000;i++) {
        if(!prime[i]) {
            for(j=2*i;j<=1000000;j+=i)
                prime[j]=1;
        }
    }
    int x=-1;
    for(i=0;i<=1000000;i++) {
        if(prime[i]==0)
            x=i;
        an1[i]=x;
    }
    x=-1;
    for(i=1000000;i>=0;i--) {
        if(prime[i]==0)
            x=i;
        an2[i]=x;
    }
    int q;
    int queries[][2] = {{2, 5}, {2, 2}, {24, 28}};
    int num_queries = sizeof(queries) / sizeof(queries[0]);
    for (int q_idx = 0; q_idx < num_queries; q_idx++) {
        int a = queries[q_idx][0];
        int b = queries[q_idx][1];
        int di=an1[b]-an2[a];
        if(an1[b]<an2[a])
            di=0;
    }
}

int main() {
    runMain();
    return 0;
}
