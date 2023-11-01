#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

class CircularQueue {
    int front, rear;
    int items[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if ((rear + 1) % MAX_SIZE == front)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Unable to enqueue." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            items[rear] = data;
        }
    }

    int dequeue() {
        int dequeuedItem;
        if (isEmpty()) {
            cout << "Queue is empty. Unable to dequeue." << endl;
            return -1;
        } else if (front == rear) {
            dequeuedItem = items[front];
            front = rear = -1;
        } else {
            dequeuedItem = items[front];
            front = (front + 1) % MAX_SIZE;
        }
        return dequeuedItem;
    }
};

void roundRobinScheduling(int processes[], int n, int burstTime[], int timeQuantum) {
    CircularQueue readyQueue;
    int remainingBurstTime[n];

    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0;

    while (true) {
        bool allProcessesComplete = true;

        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                allProcessesComplete = false;

                if (remainingBurstTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingBurstTime[i] -= timeQuantum;
                    readyQueue.enqueue(processes[i]);
                } else {
                    currentTime += remainingBurstTime[i];
                    remainingBurstTime[i] = 0;
                    cout << "Process " << processes[i] << " completed at time " << currentTime << endl;
                }
            }
        }

        if (allProcessesComplete)
            break;

        while (!readyQueue.isEmpty()) {
            int frontProcess = readyQueue.dequeue();
            cout << "Process " << frontProcess << " resumed execution at time " << currentTime << endl;

            if (remainingBurstTime[frontProcess] > timeQuantum) {
                currentTime += timeQuantum;
                remainingBurstTime[frontProcess] -= timeQuantum;
                readyQueue.enqueue(frontProcess);
            } else {
                currentTime += remainingBurstTime[frontProcess];
                remainingBurstTime[frontProcess] = 0;
                cout << "Process " << frontProcess << " completed at time " << currentTime << endl;
            }
        }
    }
}

int main() {
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burstTime[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the process ID for process " << i + 1 << ": ";
        cin >> processes[i];
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
    }

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    roundRobinScheduling(processes, n, burstTime, timeQuantum);

    return 0;
}

