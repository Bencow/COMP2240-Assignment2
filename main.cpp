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

//Struct containing all the arguments passed to the threads
struct thread_data
{
  //identifer of the thread
  int id;
  //idkyet
  int count;
};


void *routineTest(void* thread_arg)
{
  //casting the void* pointer to a thread_data*
  thread_data* data = (thread_data*)thread_arg;

  while(true)
  {
    // std::cout << data->id << " ";
    data->count++;
  }
  pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
  //Creation of an array of pointers to the data of a thread
  thread_data* data[N_THREADS];
  for(int i = 0 ; i < N_THREADS ; ++i)
  {
    //Initialize the data of each thread
    data[i] = new thread_data;
    data[i]->id = i;
    data[i]->count = 0;
  }

  pthread_t threads[N_THREADS];
  long error;

  //pthread_create(pthread_t* thread, void* attribute, void* start_routine, thread_data)
  //Note : start_routine is a functer
  //Note : thread_data is the argument passed to the start_routine function
  for(int i = 0 ; i < N_THREADS ; i++)
  {
    //Exucuting each thread (and returning error code if something wrong happened)
    error = pthread_create(&threads[i], NULL, routineTest, (void *) data[i]);

    //test if there's a problem during the creation of the thread
    if(error){
      std::cout << "ERROR, return code from thread " << i << " is " << error <<'\n';
      exit(-1);
    }
  }
  int wait;
  std::cin >> wait;
  for (int i = 0; i < N_THREADS; i++) {
    std::cout << i << " " << data[i]->count << '\n';

  }
  
  pthread_exit(NULL);
  return 0;
}
