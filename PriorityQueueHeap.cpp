#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

template <typename T>
void printArray (T EmailQueue[], int n) {
  for (int i = 0; i < n; i++)
    cout << EmailQueue[i] << " ";
  cout << endl;
}

template <typename T>
class PriorityQueue {
  vector<T> EmailQueue;

  void heapEnqueue (int index)
  {                                     // used in enqueue.
    if (index == 0)                    // if already at root.
      return;

    // parent index
    int parentIndex = (index - 1) / 2;

    // swap if parent is smaller
    if(EmailQueue[index] > EmailQueue[parentIndex])
    {
        swap(EmailQueue[index], EmailQueue[parentIndex]);

        // recursion - best solution instead of using a loop
        heapEnqueue(parentIndex);
    }
  }

  void heapDequeue (int index) {   // used in dequeue.
    int highestIndex;             // highestIndex index, used to remove the element once founded

    //Variables used to find the left and right child index and for comparision with the parent index
    // left child index
    int leftChildIndex = 2 * index + 1;

    // right child index
    int rightChildIndex = 2 * index + 2;

    // compare with highest index
    if(leftChildIndex < EmailQueue.size() && EmailQueue[leftChildIndex] > EmailQueue[index])
    {
      //The highest index will be queue to the left child node
      highestIndex = leftChildIndex;
    }
    else
    {
      //The highest index will be assign to current child
      highestIndex = index;
    }

    //Comparing right child and the highest index
    if(rightChildIndex < EmailQueue.size() && EmailQueue[rightChildIndex] > EmailQueue[highestIndex])
    {
      highestIndex = rightChildIndex;
    }

    //If the highest index is not equal to the parent index
    if (highestIndex != index)
    {
      swap (EmailQueue[index], EmailQueue[highestIndex]);
      heapDequeue (highestIndex);
    }
  }

 public:
    void clear()
    {
      EmailQueue.clear();
    }
    void enqueue (T element)
    {
      EmailQueue.push_back (element); //Inserts the new element to the end of the vector

      heapEnqueue (EmailQueue.size() - 1);  // start at last element.
    }

    T dequeue() {
      T removed_element = EmailQueue[0];
      EmailQueue[0] = EmailQueue[EmailQueue.size()-1];          // copy last element to parent.
      EmailQueue.pop_back();                                    // remove last element.
      heapDequeue (0);                                      // start at root.
      return removed_element;
    }

    int size() {
      return EmailQueue.size();
    }

    void print() {
      for (int i = 0; i < EmailQueue.size(); i++)
        cout << EmailQueue[i] << " ";
      cout << endl;
    }

    //Finding the root of the hash
    int highest()
    {
      if(EmailQueue.size() == 0)
      {
        cout << "The Heap has not been created yet!" << endl;
      }
      else
      {
        return EmailQueue.at(0);
      }
    }
};

int main ()
{
  system("cls");
  
  string emailString;
  ifstream dataEntryFile;
  PriorityQueue<string> priorityQueue;
  vector<string> emailDataset;

  vector<string> datasetSelected;
  vector<string> processSelected;

  vector<double> timeDuration;
  //vector<string> timeRecord;
  int sizeDequeue;
  int datasetASize = 10; //to be changed to 100?
  int datasetBSize = 100000;
  int datasetCSize = 500000;

  int dataSetChoice;
  int choiceSelection;
  while (true)
  {
    cout << "----------------------------------------------" << endl;
    printf("\t Priority Queue Using Heap \t\n");
    cout << "----------------------------------------------" << endl;
    cout << "Please select an option to continue the program." << endl;

    printf("1. Enqueue and Dequeue Process\n2. Time Record of Each Process\n3. Quit Program\nChoice: ");
    cin >> choiceSelection;

    while(cin.fail())
    {
      printf("That is not a valid option, please try again.\nChoice: ");
      cin.clear();
      cin.ignore();
      cin >> choiceSelection;
    }
    system("cls");

    priorityQueue.clear(); //Clear out the previous priority Queue done

    //Enqueue and Dequeue of the Dataset A
    if (choiceSelection == 1)
    {
      cout << "---------------------------------------------------------" << endl;
      cout << "Please select the DataSet " << endl;
      cout << "1. DataSetA\n2. DataSetB\n3. DataSetC" << endl;
      cout << "---------------------------------------------------------" << endl;
      cin  >> dataSetChoice;

      while(cin.fail())
      {
        printf("That is not a valid option, please try again.\nChoice: ");
        cin.clear();
        cin.ignore();
        cin >> dataSetChoice;
      }
      system("cls");
      
      if (dataSetChoice == 1)
      {
          cout << "---------------------------------------------------------" << endl;
          cout << "Enqueue of the Dataset A : Consist of 100 Email Addresses" << endl;
          cout << "---------------------------------------------------------\n" << endl;
          dataEntryFile.open("EmailSetA.txt");
          datasetSelected.push_back("Dataset A"); //For Insertion Process
          datasetSelected.push_back("Dataset A"); //For Search

          if (dataEntryFile.is_open())
		      {
            system("cls"); //Clear the command prompt
            processSelected.push_back("Enqueue/Insertion Process into Priority Queue");

            auto iStart = std::chrono::system_clock::now();

              while(!dataEntryFile.eof())
              {
                getline(dataEntryFile, emailString);
                cout << emailString << "\t: ";
                priorityQueue.enqueue (emailString);
                priorityQueue.print();
              }

              auto iEnd = std::chrono::system_clock::now();
              auto iDuration = std::chrono::duration_cast<chrono::nanoseconds>(iEnd - iStart);
              //Inserting Time Duration to Record History
              timeDuration.push_back(iDuration.count() * 1e-9);
              cout<<"Insert Time: ";
              cout<<iDuration.count() * 1e-9 <<" seconds\n";



              sizeDequeue = datasetASize * (0.1);
              cout << "---------------------------------------------------------" << endl;
              cout << "Dequeue of the Dataset A : Consist of 100 Email Addresses" << endl;
              cout << "---------------------------------------------------------\n" << endl;


              processSelected.push_back("Dequeue Process Priority Queue");
			        auto sStart = std::chrono::high_resolution_clock::now();

              for (int i = 0; i < sizeDequeue; i++)
              {
                cout << "To be Dequeued: "<< priorityQueue.dequeue() << endl;
                priorityQueue.print();
              }

              auto sEnd = std::chrono::high_resolution_clock::now();
              auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);

              timeDuration.push_back(sDuration.count() * 1e-9);

              cout << "Dequeue Time: ";
              cout << sDuration.count() * 1e-9 << " seconds\n";
		    }
      }
      else if (dataSetChoice == 2)
      {
          cout << "---------------------------------------------------------" << endl;
          cout << "Enqueue of the Dataset B : Consist of 100000 Email Addresses" << endl;
          cout << "---------------------------------------------------------\n" << endl;
          dataEntryFile.open("EmailSetB.txt");
          datasetSelected.push_back("Dataset B"); //For Insertion Process
          datasetSelected.push_back("Dataset B"); //For Search

          if (dataEntryFile.is_open())
		      {
                system("cls"); //Clear the command prompt
                processSelected.push_back("Enqueue/Insertion Process into Priority Queue");

                auto iStart = std::chrono::system_clock::now();

              while(!dataEntryFile.eof())
              {
                getline(dataEntryFile, emailString);
                cout << emailString << "\t: ";
                priorityQueue.enqueue (emailString);
                priorityQueue.print();
              }

              auto iEnd = std::chrono::system_clock::now();
              auto iDuration = std::chrono::duration_cast<chrono::nanoseconds>(iEnd - iStart);
              //Inserting Time Duration to Record History
              timeDuration.push_back(iDuration.count() * 1e-9);
              cout<<"Insert Time: ";
              cout<<iDuration.count() * 1e-9 <<" seconds\n";

              sizeDequeue = datasetBSize * (0.1);
              cout << "---------------------------------------------------------" << endl;
              cout << "Dequeue of the Dataset B : Consist of 100000 Email Addresses" << endl;
              cout << "---------------------------------------------------------\n" << endl;


              processSelected.push_back("Dequeue Process Priority Queue");
              auto sStart = std::chrono::high_resolution_clock::now();

              for (int i = 0; i < sizeDequeue; i++)
              {
                cout << "To be Dequeued: "<< priorityQueue.dequeue() << endl;
                priorityQueue.print();
              }

              auto sEnd = std::chrono::high_resolution_clock::now();
              auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);

              timeDuration.push_back(sDuration.count() * 1e-9);

              cout << "Dequeue Time: ";
              cout << sDuration.count() * 1e-9 << " seconds\n";
		      }
      }
      else if (dataSetChoice == 3)
      {
          cout << "---------------------------------------------------------" << endl;
          cout << "Enqueue of the Dataset C : Consist of 500000 Email Addresses" << endl;
          cout << "---------------------------------------------------------\n" << endl;
          dataEntryFile.open("EmailSetC.txt");
          datasetSelected.push_back("Dataset C"); //For Insertion Process
          datasetSelected.push_back("Dataset C"); //For Search

          if (dataEntryFile.is_open())
		      {
                system("cls"); //Clear the command prompt
                processSelected.push_back("Enqueue/Insertion Process into Priority Queue");

                auto iStart = std::chrono::system_clock::now();

              while(!dataEntryFile.eof())
              {
                getline(dataEntryFile, emailString);
                cout << emailString << "\t: ";
                priorityQueue.enqueue (emailString);
                priorityQueue.print();
              }

              auto iEnd = std::chrono::system_clock::now();
              auto iDuration = std::chrono::duration_cast<chrono::nanoseconds>(iEnd - iStart);
              //Inserting Time Duration to Record History
              timeDuration.push_back(iDuration.count() * 1e-9);
              cout<<"Insert Time: ";
              cout<<iDuration.count() * 1e-9 <<" seconds\n";

              sizeDequeue = datasetCSize * (0.1);
              cout << "---------------------------------------------------------" << endl;
              cout << "Dequeue of the Dataset C : Consist of 500000 Email Addresses" << endl;
              cout << "---------------------------------------------------------\n" << endl;

              processSelected.push_back("Dequeue Process Priority Queue");
              auto sStart = std::chrono::high_resolution_clock::now();

              for (int i = 0; i < sizeDequeue; i++)
              {
                cout << "To be Dequeued: "<< priorityQueue.dequeue() << endl;
                priorityQueue.print();
              }

              auto sEnd = std::chrono::high_resolution_clock::now();
              auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);

              timeDuration.push_back(sDuration.count() * 1e-9);

              cout << "Dequeue Time: ";
              cout << sDuration.count() * 1e-9 << " seconds\n";
		      }
      }

      dataEntryFile.close();
    }
    else if(choiceSelection == 2)
    {
        if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
			{
				system("cls"); //Clear the command prompt
				cout << "There is no dataset being inserted yet. Please make a process beforehand" << endl;
			}
			else
			{
				system("cls");
				cout << "---------------------" << endl;
				cout << "Time Duration History" << endl;
				cout << "---------------------" << endl;

				for (int i = 0; i < timeDuration.size(); i++)
				{
					cout << datasetSelected[i] << endl;
					cout << processSelected[i] << endl;
					cout << timeDuration[i] << endl << endl;
				}
			}
    }
    else if(choiceSelection == 3)
    {
      break;
    }
  }



}
