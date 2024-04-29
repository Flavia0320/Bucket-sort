#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <fstream>

void initializareStack(std::stack<float>& vect) {
    std::ifstream f("Date.txt");
    float nrElem;
    f >> nrElem;
    for (int i = 0; i < nrElem; i++) {
        float aux;
        f >> aux;
        vect.push(aux);
    }
}

std::stack<float> merge(std::stack<float>& vect1, std::stack<float>& vect2) {
    std::stack<float> final;
    while (!vect1.empty() && !vect2.empty()) {
        if (vect1.top() < vect2.top()) {
            final.push(vect1.top());
            vect1.pop();
        }
        else {
            final.push(vect2.top());
            vect2.pop();
        }
    }
    while (!vect1.empty()) {
        final.push(vect1.top());
        vect1.pop();
    }
    while (!vect2.empty()) {
        final.push(vect2.top());
        vect2.pop();
    }
    std::stack<float> sorted;
    while (!final.empty()) {
        sorted.push(final.top());
        final.pop();
    }
    return sorted;
}

std::stack<float> mergeSort(std::stack<float>& input) {
    if (input.size() <= 1) {
        return input;
    }
    std::stack<float> left, right;
    int count = 0;
    while (!input.empty()) {
        if (count < input.size() / 2) {
            left.push(input.top());
        }
        else {
            right.push(input.top());
        }
        input.pop();
        count++;
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

void print(std::stack<float> vect) {
    while (!vect.empty()) {
        std::cout << vect.top() << " ";
        vect.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<float> vect;
    initializareStack(vect);
    std::stack<float> merged = mergeSort(vect);

    std::cout << "MergeSorted vector: ";
    print(merged);

    return 0;
}
