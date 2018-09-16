//Author : Benoit Coville
//Student number c3316165
//Course : COMP2240
//Assessment 2

#include <pthread.h>
#include <iostream>

#define  N_THREADS 3




void sharingTheBridge()
{
  //This data, will be input in further versions
  //int N = 2;
  //int S = 2;


  //Creating 2 threads for the north


  //Creating 2 threads for the south


  //run all the threads
  /*
  while(true)
  {
    for(int i = 0 ; i < threads.size() ; i++)
    {ns
      if(thread[i].isWaiting())
      {
        if(theBridgeIsFree)
        {
          theBridgeIsFree = false;
          thread[i].startCrossingTheBridge()
        }
        else
        {
          //continue waiting
        }
      }
      if(threads[i].isCrossingTheBridge())
      {
          threads[i].walkOnTheBridge();
          if(threads[i].distanceWalked() >= BRIDGE_LENGTH)
          {
            threads.setWaiting(theOtherIsland);
            theBridgeIsFree = true;
          }
      }
  }*/

  //description of the life of a thread


  //critical section

}

struct Arg
{
  int id;
  int count;
};


void *routineTest(void* arg)
{
  Arg data = arg;

  while(true)
  {
    std::cout << data.id;
    data.count++;
  }
  pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
  //sharingTheBridge();

  //Creation of an array of threads

  Arg data[N_THREADS];
  for(int i = 0 ; i < N_THREADS ; ++i)
  {
    data[i].id = i;
    data[i].count = 0;
  }

  pthread_t threads[N_THREADS];
  long rc;

  //pthread_create(pthread_t* thread, void* attribute, void* start_routine, arg)
  //Note : start_routine is a functer
  //Note : arg is the argument passed to the start_routine function

  long i;

  for( i = 0 ; i < N_THREADS ; i++)
  {
    rc = pthread_create(&threads[i], NULL, routineTest, (void *)data[i]);
    //test if there's a prooblem during the creation of the thread
    if(rc)
    {
      std::cout << "ERROR, return code from thread " << i << " is " << rc <<'\n';
      exit(-1);
    }
  }

  pthread_exit(NULL);
  return 0;
}
