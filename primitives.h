//
// Created by ansarimn on 12/11/23.
//

#ifndef DSA2_PRIMITIVES_H
#define DSA2_PRIMITIVES_H

#endif //DSA2_PRIMITIVES_H
#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>




/*
 *
    struct timespec initial0, final0;
    struct timespec initial1, final1;

    timespec_get (&initial1, TIME_UTC);
    clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);


    timespec_get(&final1, TIME_UTC);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

    print_time (&initial0, &final0, 0);
    print_time (&initial1, &final1, 1);
 */




#define STACK_SIZE 10
#define ELEMENT_SIZE_LARGE (4 * STACK_SIZE)
#define ELEMENT_SIZE_BASIC (2 * STACK_SIZE)
#define INPUT_DATA "Enter appointment date: "
#define OUTPUT_DATA_SUCCESS "Latest appointment date is: "
#define OUTPUT_DATA_FAILURE "No dates have been added;"




long mod (long a);
long get_memory_usage (long baseline);
char * input_string (char * s1);
int * input_int (char * s1);








long mod (long a)  {
    if (a < 0) {
        return (- a);
    }

    else {
        return a;
    }
}


long get_memory_usage (long baseline) {
    struct rusage current;

    getrusage (RUSAGE_SELF, &current);

    return (mod (baseline - current.ru_maxrss));
}


int convert (char* str) {
    int i, id;
    i = 0;
    id = 0;

    while (str[i] != '\0') {
        id = id + str [i];
        i++;
    }

    return id;
}


char * input_string (char * s1) {
    char * buffer = (char *) malloc (20);
    memset (buffer, 0, ELEMENT_SIZE_BASIC);

    printf ("\n%s\n", s1);
    scanf (" %19[^\n]", buffer);

    return buffer;
}


int * input_int (char * s1) {
    int * buffer = (int *) malloc (4);
    memset (buffer, 0, 4);

    printf ("\n%s\n", s1);
    scanf (" %19[^\n]", buffer);

    return buffer;
}




void stderror (char * s1) {
    printf ("\nError;\n");
    printf ("%s\n\n", s1);
}