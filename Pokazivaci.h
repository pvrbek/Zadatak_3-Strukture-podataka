#include <iostream>
using namespace std;

struct zapis{
    char ime[35];
    char prezime[35];
    float stanje_racuna_tekuceg;
    float stanje_racuna_deviznog;
    
    int godina_rodjenja;
    int dan_rodjenja;
    int mjesec_rodjenja;
    
    short transakcija, prioritet;
};
struct qu{
    zapis value;
    qu *next;
};


struct que{
    qu *front;
    qu *rear;
};

typedef qu *element;
typedef que queue;

zapis FrontQ(queue *Q)
{
  return Q->front->next->value;
}
void EnQueueQ(zapis x,queue *Q)
{
    element novi = new qu;
    novi->value = x;
    novi->next = NULL;
    Q->rear->next = novi;
    Q->rear = novi;
}
void DeQueueQ(queue *Q)
{
    element ToDelete;
    ToDelete = Q->front->next;
    Q->front->next = ToDelete->next;
    delete ToDelete;
    if (Q->front->next == NULL) {
        Q->rear = Q->front;
    }
}
void InitQ(queue *Q)
{
    element empty = new qu; 
    Q->front = empty;
    Q->rear = empty;
    empty->next = NULL;
}
bool IsEmptyQ(queue *Q)
{
	if(Q->front == Q->rear) return true;
    return false;
}
