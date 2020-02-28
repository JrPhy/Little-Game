#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <math.h>

void GenerateAnswer(char answer[][2], unsigned int n)
{
	unsigned int sum[n], zeroToNine[10], i, j, count = 0, temp[n];
	for(i=0; i<10; i++) zeroToNine[i] = i; 
	for(i=0; i<n; i++) 
	{
		j = rand()%10;
		temp[i] = zeroToNine[j];
		zeroToNine[j] = 10;
	}
	for(i=0; i<n; i++) 
	{
		if(temp[i] == 10)
		{
			sum[count] = i;
			count++;
		}
	}
	for(i=0; i<count; i++) temp[sum[i]] = sum[i];
	for(i=0; i<n; i++) 
	{
		sprintf(answer[i], "%d", temp[i]);
		answer[i][1] = '\0';
	}
}

void Guess(char answer[][2], unsigned int n)
{
	printf("請輸入由0~9所組成的 %d 位不重複的數字\n",n);
	unsigned int countGuess = 0, countA = 0, countB = 0, i, j;
	char guess[n+1][2], playerGuess[n+1];
	while(countA != n)
	{
		printf("第 %d 次猜測\n",countGuess+1);
		scanf("%s",playerGuess);
		while(sizeof(playerGuess) > n+1 || sizeof(playerGuess) == 0)
		{
			printf("請輸入 %d 位數字\n",n);
			scanf("%s",playerGuess);
		}
		for(i=0; i<n; i++) 
		{
			guess[i][0] = playerGuess[i];
			guess[i][1] = '\0';
			printf("%s",guess[i]);
		}
		printf("\n");
		for(i=0; i<n; i++) 
		{
			if(answer[i][0] == guess[i][0]) countA++;
			for(j=0; j<n; j++) if(answer[i][0] == guess[j][0] && i != j) countB++;
		}
		printf("%dA%dB\n",countA,countB);
		printf("\n");
		countGuess++;
		if (countA == n) break;
		countA = 0;
		countB = 0;
	}
	printf("恭喜你在猜了 %d 次後答對了", countGuess);
}

int main()
{
	unsigned int n;
	printf("請輸入數字個數，介於4~9之間\n");
	scanf("%d",&n);
	printf("\n");
	while(n < 4 || n > 9)
	{
		printf("請輸入4~9之間的一個整數\n");
		scanf("%d",&n);
		printf("\n");
	}
	char answer[n][2];
	printf("遊戲開始\n");
	GenerateAnswer(answer, n);
	Guess(answer, n);
	return 0;
}
