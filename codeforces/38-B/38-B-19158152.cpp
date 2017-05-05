#include <bits/stdc++.h>

using namespace std;

char a1,a2;
int b1,b2,ans;

int main(){
	scanf("%c%d\n%c%d\n",&a1,&b1,&a2,&b2);
	for(char a3 = 'a'; a3 < 'i'; a3++)
		for(int b3 = 1; b3 < 9; b3++)
			ans += (((a3-a1)*(a3-a1) + (b3-b1)*(b3-b1) != 5) and ((a3-a2)*(a3-a2) + (b3-b2)*(b3-b2) != 5) and a3 != a1 and b3 != b1);
	printf("%d\n",ans-1);
	return 0;
}