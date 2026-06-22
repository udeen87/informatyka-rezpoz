#ifndef MYSTACK_STACK_H
#define MYSTACK_STACK_H

// STOS
int isStackEmpty(void);
int isStackFull(void);
int Pop(void);
int Top(void);
void Push(int val);

// KOLEJKA
int isQueueEmpty(void);
int isQueueFull(void);
int Dequeue(void);
int Front(void);
void Enqueue(int val);

#endif //MYSTACK_STACK_H