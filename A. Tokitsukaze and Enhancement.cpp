#include<bits/stdc++.h>
using namespace std;

void ans(int n)
{
    n=n%4;
    if(n==1){
        printf("0 A\n");
    }
    else{
        if(n==3) printf("2 A\n");
        else if(n==2) printf("1 B\n");
        else printf("1 A\n");
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    ans(n);
    return 0;
}
