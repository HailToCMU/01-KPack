#include <iostream>
using namespace std;

int n,vol,k;
int dp[1005][35],value[1005],cost[105],A[35],B[35];

void kth_ZeroOnePack(){
    memset(dp,0, sizeof(dp));
    int i,j,kk,a,b,c;
    for(i = 1;i<=n;i++){
        for(j = vol;j>=cost[i];j--){
            for(kk = 1;kk<=k;k++){
                A[kk] = dp[j-cost[i]][kk]+value[i];
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}