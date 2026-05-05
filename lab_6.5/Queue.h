#ifndef QUEUE_H
#define QUEUE_H

#include "Vect.h"

template <typename T>
class Queue {
private:
    Vect<T> container; // Ñåğâåğíèé êëàñ B ÿê åëåìåíò êëàñó A

public:
    void enqueue(const T& value) { container.push_back(value); }

    void dequeue() {
        if (container.empty()) {
         
            // ÃÅÍÅĞÓÂÀÍÍß ÂÈÍßÒÊÓ ÄËß ÎÁĞÎÁÊÈ ÇÀ ÏÎÑÈËÀÍÍßÌ
           
            throw DerivedException("Queue: attempt to dequeue from empty queue!");
        }
        container.erase_front();
    }

    T front() {
        if (container.empty()) {
            
            // ÃÅÍÅĞÓÂÀÍÍß ÂÈÍßÒÊÓ ÄËß ÎÁĞÎÁÊÈ ÇÀ ÇÍÀ×ÅÍÍßÌ
           
            throw MyCustomException("Queue: queue is empty!");
        }
        return container.front();
    }

    bool isEmpty() const { return container.empty(); }
};

#endif