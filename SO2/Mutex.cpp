#include "Mutex.h"

std::mutex mtx;
std::condition_variable cv;
bool stuck_flag=false;
unsigned int obeservatorsNumber=0;

void ObserveMutex()
{
    obeservatorsNumber++;
    std::unique_lock<std::mutex> lck(mtx);
    while (!stuck_flag) cv.wait(lck);
    obeservatorsNumber--;
    if(obeservatorsNumber==0)
    {
      stuck_flag = false;  
    }
}

void SetMutex()
{
    if(obeservatorsNumber==0)
    {
        return;
    }
    std::unique_lock<std::mutex> lck(mtx);
    stuck_flag = true;
    cv.notify_all();
    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	// stuck_flag = false;
}
