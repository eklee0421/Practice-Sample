#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int W[500];
int V[500];
int DP[500][100000];

int main() {
   int test;
   cin >> test;
   while (test--)
   {
      
      cin >> N >> K;
      for (int i = 1; i<= N; i++) {
         cin >> W[i]; //물건 무게
      }
      for (int i = 1; i <= N; i++) {
         cin >> V[i];//가치
      }
      
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= K; j++) {
            if (j >= W[i]) {
               DP[i][j] = max(DP[i - 1][j],DP[i-1][j-W[i]]+V[i]);
            }
            else {
               DP[i][j] = DP[i - 1][j];
            }
         }
      }
      cout << DP[N][K] << "\n";
   }
}
