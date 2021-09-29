// Baivab Saha - 2012038

#include<stdio.h>
#define N 5000

char last[N], secondLast[N], current[N], carry=0;
int k=N-1;
void fibboNumber(int n){
    if(n==0){
        printf("%d", 0);
        return;
    }
    else if(n==1){
        printf("%d", 1);
        return;
    }
    last[N-1]=1;
    secondLast[N-1]=0;
    for(int i=2; i<=n; i++){
        for(int i=N-1; i>=k; i--){
            int l = last[i]+secondLast[i]+carry;
            current[i]=(l%10);
            carry=l/10;
            if(i==k && carry>0) k--;
        }
        for(int i=N-1; i>=k; i--){
            secondLast[i]=last[i];
            last[i]=current[i];   
        }
    }
    for(int i=k; i<N; i++)
        printf("%d", current[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    fibboNumber(n);
    return 0;
}
