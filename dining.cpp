#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const int NUM_PHILOSOPHERS = 5;
mutex forks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    this_thread::sleep_for(chrono::milliseconds(1000));

    while (true) {
        forks[left_fork].lock();
        cout << "Philosopher " << id << " picks up left fork " << left_fork << endl;

        forks[right_fork].lock();
        cout << "Philosopher " << id << " picks up right fork " << right_fork << endl;

        cout << "Philosopher " << id << " is eating" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        forks[right_fork].unlock();
        cout << "Philosopher " << id << " puts down right fork " << right_fork << endl;

        forks[left_fork].unlock();
        cout << "Philosopher " << id << " puts down left fork " << left_fork << endl;

        cout << "Philosopher " << id << " is thinking" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = thread(philosopher, i);
    }
    
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}
