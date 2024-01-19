#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>
#include <iostream>

// a simple function that wastes CPU cycles "forever"
void cpu_waster()
{
    printf("CPU Waster Process ID: %d\n", getpid());
    std::cout << "CPU Waster Thread ID " << std::this_thread::get_id() << std::endl;
    while (true)
        continue;
}

int main()
{
    printf("Main Process ID: %d\n", getpid());
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);
    std::thread thread3(cpu_waster);
    std::thread thread4(cpu_waster);
    std::thread thread5(cpu_waster);
    std::thread thread6(cpu_waster);

    while (true)
    { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
