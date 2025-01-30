/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:54:22 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/30 09:01:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *mythread(void *arg)
{
	printf("Starting Thread Execution...\n");
	int *c = (int *)malloc(sizeof(4));
	*c = 4;

	printf("Finished Thread Execution...\n");
	return (c);
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	int i = 0;
	int *result = NULL;

	printf("Starting Execution...\n");
	pthread_create(&thread, NULL, mythread, NULL);

	printf("Starting While Execution...\n");
	while (i < 1000000000)
		i++;
	printf("Finished While Execution...\n");
	pthread_join(thread, (void **)&result);
	printf("Waited for the thread to finish its execution...\n");
	if (result)
		printf("Here is the result of the thread function %d\n", *result);
	return (EXIT_SUCCESS);
}

