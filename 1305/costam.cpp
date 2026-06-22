#define STACK_SIZE 5
#define QUEUE_SIZE 5

// ==================== STOS ====================

int stack_table[STACK_SIZE] = {0};
int stack_index = 0;

int isStackEmpty(void)
{
    return (stack_index == 0) ? 1 : 0;
}

int isStackFull(void)
{
    return (stack_index == STACK_SIZE) ? 1 : 0;
}

int Pop(void)
{
    if (!isStackEmpty())
    {
        stack_index--;
        return stack_table[stack_index];
    }

    return stack_table[0];
}

int Top(void)
{
    if (!isStackEmpty())
    {
        return stack_table[stack_index - 1];
    }

    return stack_table[0];
}

void Push(int val)
{
    if (!isStackFull())
    {
        stack_table[stack_index] = val;
        stack_index++;
    }
}

// ==================== KOLEJKA ====================

int queue_table[QUEUE_SIZE] = {0};
int queue_front = 0;
int queue_rear = 0;
int queue_count = 0;

int isQueueEmpty(void)
{
    return (queue_count == 0) ? 1 : 0;
}

int isQueueFull(void)
{
    return (queue_count == QUEUE_SIZE) ? 1 : 0;
}

void Enqueue(int val)
{
    if (!isQueueFull())
    {
        queue_table[queue_rear] = val;
        queue_rear = (queue_rear + 1) % QUEUE_SIZE;
        queue_count++;
    }
}

int Dequeue(void)
{
    int temp = queue_table[queue_front];

    if (!isQueueEmpty())
    {
        temp = queue_table[queue_front];
        queue_front = (queue_front + 1) % QUEUE_SIZE;
        queue_count--;
    }

    return temp;
}

int Front(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[queue_front];
    }

    return queue_table[0];
}