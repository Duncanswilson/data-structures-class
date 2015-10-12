//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include "config.h" 
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.cpp"
#else
#   include "QueueArray.cpp"
#endif

using namespace std;
void simFunc();
int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
                                 //   joined the line
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        timeArrived,             // Time dequeued customer arrived
        waitTime,                // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0,         // Number of new arrivals
        k=0;

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand(7);

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.
 for(int i = 0; i < simLength; i++)
     {
      minute++; 
      timeArrived = minute; 
      // test if empty, if not serve customers and update stats 
      if(!custQ.isEmpty())
        {
         waitTime = (minute - custQ.dequeue());
         totalServed++;
         if(waitTime > maxWait)
           {  
            maxWait = waitTime; 
           } 
         totalWait += waitTime; 
        }
      k = rand() % 4; 
      //one customer in line 
      if(k == 1)
        {
         custQ.enqueue(timeArrived);
        }
      //two customers in line 
      else if(k == 2)
        {
         custQ.enqueue(timeArrived);
         custQ.enqueue(timeArrived);
        } 
     }



    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}
 
