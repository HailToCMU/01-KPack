#include<iostream>
using namespace std;

int n,vol,k;
int dp[1005][35],value[105],cost[105],A[35],B[35];

void kth_ZeroOnePack()
{
    memset(dp,0,sizeof(dp));

    int i,j,kk,a,b,c;
    for(i=1;i<=n;++i)
    {
        for(j=vol;j>=cost[i];--j)
        {
            for(kk=1;kk<=k;++kk)
            {
                A[kk]=dp[j-cost[i]][kk]+value[i];
                B[kk]=dp[j][kk];
            }

            A[kk]=B[kk]=-1;
            a=b=c=1;
            while(c<=k && (A[a]!=-1 || B[b]!=-1))
            {
                if(A[a]>B[b])
                    dp[j][c]=A[a],++a;
                else
                    dp[j][c]=B[b],++b;

                if(dp[j][c]!=dp[j][c-1])
                    ++c;
            }
        }
    }

    cout<<dp[vol][k]<<endl;
}

int main()
{
    int tCase;

    cin>>tCase;
    while(tCase--)
    {
        cin>>n>>vol>>k;

        for(int i=1;i<=n;++i)
            cin>>value[i];
        for(int j=1;j<=n;++j)
            cin>>cost[j];

        kth_ZeroOnePack();
    }

    return 0;
}

