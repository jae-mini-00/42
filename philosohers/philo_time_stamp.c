#include "philo.h"

static long long *start_time(void)
{
    static long long time = 0;

    return (&time);
}

static long long get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void time_stamp_init(void)
{
	*start_time() = get_ms();
}

long long get_time_stamp_ms(void)
{
	return (get_ms()- *start_time());
}