//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                     ossim.cs
//
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "PriorityQueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int getPriority () const
        { return priority; }     // Returns the priority. Needed by the heap.

    int priority,                // Task's priority
        arrived;                 // Time when task was enqueued

};


//--------------------------------------------------------------------

int main ()
{
    PriorityQueue<TaskData, int, Less<int> > taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals,             // Number of new tasks arriving
        j;                       // Loop counter

    // Seed the random number generator
    srand( 7 );

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    for ( minute = 0 ; minute < simLength ; minute++ )
    {
     if(!taskPQ.isEmpty())
       { 
        task = taskPQ.dequeue();
        cout << "At " <<minute <<" dequeued : " 
             << task.getPriority() <<' '
             << task.arrived <<' '
             << minute - task.arrived <<endl; 
       }
     numArrivals = rand() % 4; 
     if(numArrivals == 1)
      {
       TaskData newItem; 
       newItem.arrived = minute;
       newItem.priority = rand()%numPtyLevels; 
       taskPQ.enqueue(newItem);  
      }
     if(numArrivals == 2) 
      {
       TaskData newItemOne, newItemTwo; 
       newItemOne.arrived = newItemTwo.arrived = minute; 
       newItemOne.priority = rand()%numPtyLevels; 
       newItemTwo.priority = rand()%numPtyLevels; 
       taskPQ.enqueue(newItemOne); 
       taskPQ.enqueue(newItemTwo); 
      }
    }

    return 0;
}

