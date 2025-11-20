#include <iostream>
#include <queue>
#include <string>


void display(std::queue<std::string> q) {
    std::queue<std::string> temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::string students[] = {"Nikko", "David", "Jeus", "Heidee", "Akira"};
    int n = sizeof(students) / sizeof(students[0]);
    std::queue<std::string> studentQueue;
    for (int i = 0; i < n; i++) {
        studentQueue.push(students[i]);
    }
    std::cout << "Students in queue: ";
    display(studentQueue);

    std::cout << "Front of queue: " << studentQueue.front() << std::endl;
    std::cout << "Back of queue: " << studentQueue.back() << std::endl;

    std::cout << "Removing: " << studentQueue.front() << std::endl;
    studentQueue.pop();

    std::cout << "Queue after one removal: ";
    display(studentQueue);

    return 0;
}
#ifndef QUEUELINK_H
#define QUEUELINK_H
#include <iostream>

