#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{

    //TODO
    thread_arg_t * arg = (thread_arg_t *) p_arg;
    TMatrix * m = arg->m;
    TMatrix * n = arg->n;
    TMatrix * t = arg->t;

    unsigned int row_start = 0, row_end = m->nrows;
    unsigned int col_start = 0, col_end = n->ncols;

    if (m->nrows >= n->ncols) {
        unsigned int chunk = m->nrows / NUM_THREADS;
        row_start = arg->id * chunk;
        row_end   = (arg->id == NUM_THREADS - 1) ? m->nrows : row_start + chunk;
    } else {
        unsigned int chunk = n->ncols / NUM_THREADS;
        col_start = arg->id * chunk;
        col_end   = (arg->id == NUM_THREADS - 1) ? n->ncols : col_start + chunk;
    }

    for (unsigned int i = row_start; i < row_end; i++) {
        for (unsigned int j = col_start; j < col_end; j++) {
            TElement sum = (TElement) 0;
            for (unsigned int k = 0; k < m->ncols; k++)
                sum += m->data[i][k] * n->data[k][j];
            t->data[i][j] = sum;
        }
    }

    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t args[NUM_THREADS];

    for (unsigned int i = 0; i < NUM_THREADS; i++) {
        args[i].id = i;
        args[i].m = m;
        args[i].n = n;
        args[i].t = t;
        if (pthread_create(&threads[i], NULL, thread_main, &args[i]) != 0) {
            fprintf(stderr, "Error: pthread_create failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (unsigned int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error: pthread_join failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return t;
}
