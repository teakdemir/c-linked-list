#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>

template <class T>
class Queue {
private:
    T *list;         // Array to hold the queue elements
    int maxsize;     // Maximum size of the queue
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int cnt;         // Current number of elements in the queue

public:
    // Constructor
    Queue(int n);

    // Destructor
    ~Queue();

    // Check if the queue is empty
    bool isEmpty() const;

    // Check if the queue is full
    bool isFull() const;

    // Insert an element into the queue
    void insert(T &data);

    // Delete an element from the queue
    T remove();

    // Access the front element
    T getFront() const;

    // Access the rear element
    T getRear() const;

    // Destroy the queue
    void destroyQueue();
};

// Implementation of the Queue methods

// Constructor
template <class T>
Queue<T>::Queue(int n) {
    maxsize = n;
    list = new T[maxsize];
    front = 0;
    cnt = 0;
    rear = maxsize - 1; // Initialize rear as the last index for wrap-around logic
}

// Destructor
template <class T>
Queue<T>::~Queue() {
    delete[] list;
}

// Check if the queue is empty
template <class T>
bool Queue<T>::isEmpty() const {
    return (cnt == 0);
}

// Check if the queue is full
template <class T>
bool Queue<T>::isFull() const {
    return (cnt == maxsize);
}

// Insert an element into the queue
template <class T>
void Queue<T>::insert(T &data) {
    assert(!isFull());  // Ensure the queue is not full
    rear = (rear + 1) % maxsize;  // Move rear forward (circular)
    list[rear] = data;  // Insert data
    cnt++;  // Increment element count
}

// Delete an element from the queue
template <class T>
T Queue<T>::remove() {
    assert(!isEmpty());  // Ensure the queue is not empty
    T temp = list[front];  // Store the front element
    front = (front + 1) % maxsize;  // Move front forward (circular)
    cnt--;  // Decrement element count
    return temp;  // Return the removed element
}

// Access the front element
template <class T>
T Queue<T>::getFront() const {
    assert(!isEmpty());  // Ensure the queue is not empty
    return list[front];
}

// Access the rear element
template <class T>
T Queue<T>::getRear() const {
    assert(!isEmpty());  // Ensure the queue is not empty
    return list[rear];
}

// Destroy the queue
template <class T>
void Queue<T>::destroyQueue() {
    front = 0;
    cnt = 0;
    rear = maxsize - 1;
}

#endif // QUEUE_H