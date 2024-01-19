#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>
#include <iostream>

// A simple function that adds two numbers entered per screen
void calculator()
{
    printf("Calculator Process ID: %d\n", getpid());
    std::cout << "Calculator Thread ID " << std::this_thread::get_id() << std::endl;

    while (true)
    {
        int num1, num2;
        
        // Prompt the user to enter two numbers
        std::cout << "Enter the first number: ";
        std::cin >> num1;

        std::cout << "Enter the second number: ";
        std::cin >> num2;

        // Calculate and display the sum
        int sum = num1 + num2;
        std::cout << "Sum: " << sum << std::endl;
    }
}

int main()
{
    printf("Main Process ID: %d\n", getpid());
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;

    // Create six threads for the calculator function
    std::thread thread1(calculator);
    std::thread thread2(calculator);
    std::thread thread3(calculator);
    std::thread thread4(calculator);
    std::thread thread5(calculator);
    std::thread thread6(calculator);

    // Keep the main thread alive "forever"
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
