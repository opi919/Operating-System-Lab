#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

std::chrono::system_clock::time_point getTime() {
    return std::chrono::system_clock::now();
}

void timeRequestor() {
    // while (true) {
        std::cout << "Ask for time." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
}

void timeResponder() {
    // while (true) {
        std::time_t result = std::chrono::system_clock::to_time_t(getTime());
        std::cout << "Time: " << std::ctime(&result) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
}

int main() {
    std::thread requestor(timeRequestor);
    std::thread responder(timeResponder);

    requestor.join();
    responder.join();

    return 0;
}
