#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

	static int visited[201][201];
	int i, j;

	for (i = 0; i < 201; i++)
	{
		for (j = 0; j < 201; j++)
		{
			visited[i][j] = 0;
		}
	}

	int x = 0;
	int y = 0;
	visited[x + 100][y + 100] = 1;
	int count = 1;

	while (1)
	{
		int r = rand() % 4;

		if (r == 0)
			y = y + 1; 
		else if (r == 1)
			x = x + 1; 
		else if (r == 2)
			y = y - 1;
		else
			x = x - 1;


		if (x == -n || x == n || y == -n || y == n)
		{
			break;
		}

		if (visited[x + 100][y + 100] == 0)
		{
			visited[x + 100][y + 100] = 1;
			count = count + 1;
		}
	}

	double total = (2 * n - 1) * (2 * n - 1);
	return count / total;

}

//Do not change the code below
int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}

