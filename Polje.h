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
typedef zapis element;

struct qu{
    zapis klijenti[10000];
    int front, rear;
};

typedef qu queue;

int AddOne(int n)
{
    return (n+1)%10000;
}
zapis FrontQ(queue *Q)
{
  return Q->klijenti[Q->front];
}
void EnQueueQ(zapis x,queue *Q)
{
	Q->rear = AddOne(Q->rear);
    Q->klijenti[Q->rear] = x;
}
void DeQueueQ(queue *Q)
{
	Q->front = AddOne(Q->front);
}
void InitQ(queue *Q)
{
    Q->front = 0;
    Q->rear = 9999;
}
bool IsEmptyQ(queue *Q)
{
	if(AddOne(Q->rear) == Q->front) return true;
    return false;
}
