#include <iostream>
#include <mutex> 
#include <condition_variable>
#include <thread>


void ObserveMutex();
void SetMutex();

unsigned int getCounter();
unsigned int getFlag();