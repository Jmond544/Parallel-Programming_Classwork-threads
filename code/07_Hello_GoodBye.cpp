#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>
#include <iostream>

// a simple function that says hello or goodbye infinitely
void greeting_thread(const std::string &message)
{
    printf("!! %s CPU Process ID: %d\n", message.c_str(), getpid());
    std::cout << "* " << message << " Thread ID " << std::this_thread::get_id() << std::endl;
    while (true)
    {
        std::cout << message << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    printf("Main Process ID: %d\n", getpid());
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread hello_thread(greeting_thread, "Hello");
    std::thread goodbye_thread(greeting_thread, "Goodbye");

    while (true)
    { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Note: The program will never reach this point, as the threads are running indefinitely.
    hello_thread.join();
    goodbye_thread.join();

    return 0;
}
