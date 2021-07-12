//
// Created by Giuseppe Muschetta on 12/07/21.
//

#include "queue.h"

node_t *createNode(int info){
    if(info < 0){
        fprintf(stderr,"task job in ms cannot be negative\n");
        exit(EXIT_FAILURE);
    }
    node_t *nuovo = (node_t*)malloc(sizeof(*nuovo));
    ec_null(nuovo)
    nuovo->next = NULL;
    nuovo->info = info;
    return nuovo;
}

//in this implementation it will be limitless
queue_t *createQueue(int priority_){
    queue_t *queue = (queue_t*)malloc(sizeof(*queue));
    ec_null(queue)
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->priority = priority_; //the lower the higher the priority is
    return queue;
}

//implementation FIFO: adding to tail and removing from the head of the queue
bool insertNode(queue_t *q, int info){
    if(q == NULL)
        return false;

    //before inserting we need to allocate a node_t
    node_t *nuovo = createNode(info);
    assert(nuovo != NULL);

    //append code:
    if(q->head!=NULL){
        assert(q->tail != NULL);
        q->tail->next = nuovo;
        q->tail = nuovo;
    }
    else{
        assert(q->tail == NULL);
        q->head = nuovo;
        q->tail = q->head;
    }
    q->size++;
    return true;
}

//node will be removed from the headof the queue
node_t *getNode(queue_t *q){
    if(q == NULL)
        return NULL;

    if(q->head == NULL)
        return NULL;

    node_t *current = q->head;
    if(q->head->next != NULL){
        q->head = q->head->next;
        q->size--;
    }
    else{
        q->head = NULL;
        q->tail = q->head;
    }
    return current;
}

void destroyNode(node_t *node){
    if(node == NULL)
        return;
    free(node);
}

void destroyQueue(queue_t *q){
    if(q == NULL)
        return;

    //caso base semplice:
    if(q->head == NULL){
        assert(q->tail == NULL);
        free(q);
        return;
    }

    //passo induttivo:
    //deallochiamo ogni elemento della coda e poi la coda stessa
    node_t *current = q->head;
    node_t *temp = NULL;
    while(current != NULL){
        temp = current->next;
        destroyNode(current);
        current = temp;
    }
    q->head = NULL;
    q->tail = NULL;
    free(q);
}


bool isEmpty(queue_t *q){
    if(q == NULL){
        fprintf(stderr,"Queue is not empty, worse... it isn't even allocated! \n");
        return false;
    }
    return(q->size == 0);
}

int getSize(queue_t *q){
    if(q == NULL){
        fprintf(stderr,"Create a queue first! \n");
        return -1;
    }
    return q->size;
}

bool contains(queue_t *q, int info){
    if(q == NULL)
        return false;
    if(info < 0){
        return false;
    }
    bool stop = false;
    node_t *current = q->head;
    while(current != NULL && !stop){
        if(current->info == info){
            stop = true;
        }
        else{
            current=current->next;
        }
    }
    return stop;
}

int *toArray(queue_t *q){
    if(q == NULL)
        return NULL;

    int dim = q->size;
    int *array = (int*)malloc(dim*sizeof(*array));
    ec_null(array)

    node_t *current = q->head;
    int i=0;
    while(current!=NULL){
        array[i] = current->info;
        i++;
        current=current->next;
    }

    return array;
}


void displayQueue(queue_t *q){
    if(q == NULL)
        return;
    node_t *current=q->head;
    while(current!=NULL){
        if(current->next == NULL){
            printf("%d - NULL\n",current->info);
        }
        else{
            printf("%d - ",current->info);
        }
        current=current->next;
    }
}

void displayArray(int *array, int dim){
    int i;
    for (i = 0; i < dim; ++i) {
        if(i == dim -1)
            printf("%d ",array[i]);
        else
            printf("%d - ",array[i]);
    }
}

int getPriority(queue_t *q){
    if(q == NULL)
        return -1;
    return q->priority;
}
