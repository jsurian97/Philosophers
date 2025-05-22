#include <stdio.h>
#include <sys/time.h>

time_t getime(time_t start)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	
	return ((tv.tv_usec/1000 + tv.tv_sec *1000) - start);

}

int main()
{
	time_t actuel = 0;
	time_t final = getime(0) + 5000;

	while (actuel < final)
	{
		actuel = getime(0);
		printf("%ld\n", actuel);
	}
	return 0;
}
