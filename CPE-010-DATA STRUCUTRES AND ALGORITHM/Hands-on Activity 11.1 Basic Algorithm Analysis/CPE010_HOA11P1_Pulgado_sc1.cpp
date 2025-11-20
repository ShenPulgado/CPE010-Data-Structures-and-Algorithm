#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    auto get_name() const { return name; }
    auto is_vaccinated() const { return vaccinated; }

    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};
auto generate_random_Student(int max) {
    std::random_device rd;
    std::mt19937 rand(rd());
    std::uniform_int_distribution<int> uniform_dist(1, max);

    auto random_name = std::make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = uniform_dist(rand) % 2 ? true : false;
    return Student(random_name, is_vaccinated);
}
bool needs_vaccination(const Student& P, const std::vector<Student>& people) {
    int left = 0;
    int right = people.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const auto& mid_student = people[mid];

        if (mid_student == P)
            return !mid_student.is_vaccinated();
        else if (mid_student > P)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return true;
}

void search_test(int size, const Student& p) {
    std::vector<Student> people;
    people.reserve(size);

    for (int i = 0; i < size; i++)
        people.push_back(generate_random_Student(size));

    std::sort(people.begin(), people.end());

    auto begin = std::chrono::steady_clock::now();
    bool search_result = needs_vaccination(p, people);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search (" << size << " students): "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;

    auto name = p.get_name();
    if (search_result)
        std::cout << "Student (" << name.first << ", " << name.second << ") needs vaccination.\n";
    else
        std::cout << "Student (" << name.first << ", " << name.second << ") does not need vaccination.\n";
}

int main() {
    auto p = generate_random_Student(1000);
    search_test(1000, p);
    search_test(1000000, p);
    search_test(10000000, p);
    return 0;
}
