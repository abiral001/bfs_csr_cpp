#ifndef _QUEUE_H
#define _QUEUE_H

class Queue {
    private:
        int queue[50];
        int queuePointer = 0;
        int *retArr;
    public:
        Queue() {}
        ~Queue() {
            delete [] retArr;
        }

        void enqueue(int data) {
            this->queue[this->queuePointer++] = data; 
        }

        int dequeue() {
            if (this->queuePointer <= 0) {
                return -1;
            }
            int returningData = this->queue[0];
            for (int i = 0; i < this->queuePointer; i++) {
                this->queue[i] = this->queue[i+1];
            }
            this->queuePointer--;
            return returningData;
        }

        int getQueueSize() {
            return this->queuePointer;
        }

        int * getQueue() { 
            this->retArr = new int[this->queuePointer];
            for (int i = 0; i < this->queuePointer; i++) {
                this->retArr[i] = this->queue[i];
            }
            return this->retArr;
        }
};

#endif