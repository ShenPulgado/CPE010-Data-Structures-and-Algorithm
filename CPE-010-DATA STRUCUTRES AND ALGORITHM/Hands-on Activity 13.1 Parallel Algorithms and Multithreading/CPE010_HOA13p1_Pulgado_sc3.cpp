#include <iostream>
#include <thread>
#include <mutex>

int globalVar = 0;

std::mutex mtx;

void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    globalVar += value;
    std::cout << "Thread adding " << value << ", globalVar = " << globalVar << std::endl;
}

int main() {
    std::thread t1(add, 5);
    std::thread t2(add, 10);
    std::thread t3(add, 15);

    std::cout << "\n[Before any join] globalVar = " << globalVar << std::endl;

    t1.join();
    std::cout << "[After T1.join()] globalVar = " << globalVar << std::endl;

    t2.join();
    std::cout << "[After T2.join()] globalVar = " << globalVar << std::endl;

    t3.join();
    std::cout << "[After T3.join()] globalVar = " << globalVar << std::endl;

    return 0;
}
