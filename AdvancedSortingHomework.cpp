#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void printsort(int array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void selection(int array[], int size)
{
	for(int i = 1; i < size; i++)
	{
		int temp = array[i];
		int walk = i-1;
		while(walk >= 0 && temp < array[walk]) // goes backwards in list
		{
			array[walk+1] = array[walk]; // moves forward in the list
			walk = walk - 1; // holds index
		}

		array[walk+1] = temp; // add one to ensure access to first element of the array
	}
}

void shell(int array[], int size)
{
	int last = size - 1;
	int inc = last / 2;
	while(inc != 0)
	{
		int current = inc;
		while(current <= last)
		{
			int hold = array[current];
			int walk = current - inc;
			while(walk >= 0 && hold < array[walk])
			{
				array[walk + inc] = array[walk];
				walk = walk - inc;
			}
			array[walk + inc] = hold;
			current = current + 1;
		}
		inc = inc / 2;
	}
}

int Partition(int A[], int p, int r)
{
	  int x = A[r];
	  int i = p-1;
	  int temp = 0; //used for when I do the exchanges

		for (int j=p; j < r; j++)
		{
			  if(A[j] <= x)
        {
      	  i++;
          temp = A[i];
          A[i] = A[j];
          A[j] = temp;
        }
		}

		temp = A[i+1];
		A[i+1] = A[r];
		A[r] = temp;
		return (i+1);
}

void Quicksort(int A[], int p, int r)
{
		if(p < r)
		{
			int q = Partition(A, p, r);
			Quicksort(A, p, q-1);
			Quicksort(A, q+1, r);
		}
}

void insertionSort(int array[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = array[i];
       j = i-1;

       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int main()
{
	int array1[20];
	int array2[20];
	int array3[20];
	int array4[20];
	int array5[20];

	// used for quicksort
	int p = 0;
	int r = 19;

	int size = 20;

	for(int i = 0; i < 20; i++)
	{
		array1[i] = array2[i] = array3[i] = array4[i] = array5[i] = rand() % 20 + 1; // Fills identical arrays with random number from 1-20
	}
	cout << "\n       _________Original Unsorted Array - Random_________\n";
	cout << "       ";
	for(int j = 0; j < 20; j++)
	{
		cout << array1[j] << " ";
	}
	cout << endl << endl << "       Shell Sort:" << endl;
	shell(array1, size);
	cout << "       ";
	printsort(array1,size);

		int left = 0;
		int right = size - 1;

	cout << "       Quick Sort:" << endl;
	Quicksort(array2, p, r);
	cout << "       ";
	printsort(array2,size);

	cout << "       Selection Sort:" << endl;
	selection(array3,size);
	cout << "       ";
	printsort(array3,size);

	cout << "       Insertion Sort:" << endl;
	insertionSort(array4,size);
	cout << "       ";
	printsort(array4,size);

	cout << "       Bubble Sort:" << endl;
	bubbleSort(array5,size);
	cout << "       ";
	printsort(array5,size);
	cout << endl;

	cout << "       ______Original Unsorted Array - Already Sorted______\n";
	int array6[20];
	int array7[20];
	int array8[20];
	int array9[20];
	int array10[20];

	for(int i = 0; i < 20; i++)
	{
		array6[i] = array7[i] = array8[i] = array9[i] = array10[i] = i; // Fills identical arrays with random number from 1-20
	}
	cout << "       ";
	for(int j = 0; j < 20; j++)
	{
		cout << array6[j] << " ";
	}
	cout << endl << endl << "       " << "Shell Sort:" << endl;

	shell(array6, size);
	cout << "       ";
	printsort(array6,size);

	cout << "       Quicksort:" << endl;
	Quicksort(array7, p, r);
	cout << "       ";
	printsort(array7,size);

	cout << "       Selection Sort:" << endl;

	selection(array8,size);
	cout << "       ";
	printsort(array8,size);

	cout << "       Insertion Sort:" << endl;
	insertionSort(array9,size);
	cout << "       ";
	printsort(array9,size);

	cout << "       Bubble Sort:" << endl;
	bubbleSort(array10,size);
	cout << "       ";
	printsort(array10,size);
	cout << endl;

	cout << "       ______Original Unsorted Array - Same Numbers______\n";
	int array11[20];
	int array12[20];
	int array13[20];
	int array14[20];
	int array15[20];

	for(int i = 0; i < 20; i++)
	{
		array11[i] = array12[i] = array13[i] = array14[i] = array15[i] = 1; // Fills identical arrays with random number from 1-20
	}
	cout << "       ";
	for(int j = 0; j < 20; j++)
	{
		cout << array11[j] << " ";
	}
	cout << endl << endl;
	cout << "       Shell Sort:" << endl;

	shell(array11, size);
	cout << "       ";
	printsort(array11,size);

	cout << "       Quicksort:" << endl;
	Quicksort(array12, p, r);
	cout << "       ";
	printsort(array12,size);

	cout << "       Selection Sort:" << endl;
	selection(array13,size);
	cout << "       ";
	printsort(array13,size);

	cout << "       Insertion Sort:" << endl;
	insertionSort(array14,size);
	cout << "       ";
	printsort(array14,size);

	cout << "       Bubble Sort:" << endl;
	bubbleSort(array15,size);
	cout << "       ";
	printsort(array15,size);

	cout << "\n [] Beginning test times for sorting 10,000 elements...";

	int bigarray1[10000];
	int bigarray2[10000];
	int bigarray3[10000];
	int bigarray4[10000];
	int bigarray5[10000];

	r = 9999; //used for quicksort
	int bigsize = 10000;

	int shelltime = 0;
	int quicktime = 0;
	int selectiontime = 0;
	int insertiontime = 0;
	int bubbletime = 0;
	int shelltime2 = 0;
	int quicktime2 = 0;
	int selectiontime2 = 0;
	int insertiontime2 = 0;
	int bubbletime2 = 0;
	int shelltime3 = 0;
	int quicktime3 = 0;
	int selectiontime3 = 0;
	int insertiontime3 = 0;
	int bubbletime3 = 0;

	srand(time(NULL));


for(int i = 0; i < 10000; i++)
	{
		bigarray1[i] = bigarray2[i] = bigarray3[i] = bigarray4[i] = bigarray5[i] = rand() % 10000 + 1; // Fills identical arrays with random number from 1-10000
	}

	clock_t start, end;

	// Big Shell sort
	start = clock();
	shell(bigarray1, bigsize);
	end = clock();

	double milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	shelltime = milli_time;

	double timestore = milli_time;
	int slowest = 1;

	// Big Quick sort
	start = clock();
	Quicksort(bigarray2, p, r);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	quicktime = milli_time;

	// Big Selection sort
	start = clock();
	selection(bigarray3, bigsize);
	end = clock();


	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	selectiontime = milli_time;

	// Big Inertion sort
	start = clock();
	insertionSort(bigarray4, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	insertiontime = milli_time;

	// Big Bubble sort
	start = clock();
	bubbleSort(bigarray5, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	bubbletime = milli_time;
	cout << endl << endl;


	int bigarray6[10000];
	int bigarray7[10000];
	int bigarray8[10000];
	int bigarray9[10000];
	int bigarray10[10000];

	for(int i = 0; i < 10000; i++)
	{
		bigarray6[i] = bigarray7[i] = bigarray8[i] = bigarray9[i] = bigarray10[i] = i ; // Fills identical arrays with sorted numbers from 1-10000
	}

	// Big Shell sort
	start = clock();
	shell(bigarray6, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	shelltime2 = milli_time;

	// Big Quick sort
	start = clock();
	Quicksort(bigarray7, p, r);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	quicktime2 = milli_time;

	// Big Selection sort
	start = clock();
	selection(bigarray8, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	selectiontime2 = milli_time;

	// Big Inertion sort
	start = clock();
	insertionSort(bigarray9, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	insertiontime2 = milli_time;

	// Big Bubble sort
	start = clock();
	bubbleSort(bigarray10, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	bubbletime2 = milli_time;

	int bigarray11[10000];
	int bigarray12[10000];
	int bigarray13[10000];
	int bigarray14[10000];
	int bigarray15[10000];

	for(int i = 0; i < 10000; i++)
	{
		bigarray11[i] = bigarray12[i] = bigarray13[i] = bigarray14[i] = bigarray15[i] = 1 ; // Fills identical arrays with all 1's
	}

	// Big Shell sort
	start = clock();
	shell(bigarray11, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	shelltime3 = milli_time;

	// Big Quick sort
	start = clock();
	Quicksort(bigarray12, p, r);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	quicktime3 = milli_time;

	// Big Selection sort
	start = clock();
	selection(bigarray13, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	selectiontime3 = milli_time;

	// Big Inertion sort
	start = clock();
	insertionSort(bigarray14, bigsize);
	end = clock();

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	insertiontime3 = milli_time;

	// Big Bubble sort
	start = clock();
	bubbleSort(bigarray15, bigsize);
	end = clock();

	cout << "              Shell Sort      Quick Sort      Selection Sort      Insertion Sort      Bubble Sort\n";
	cout << "\nRandom           " << shelltime << "                 " << quicktime << "                  " << selectiontime << "                  " << insertiontime << "                " << bubbletime;
	cout << "\nIn-order         " << shelltime2 << "                 " << quicktime2 << "                " << selectiontime2 << "                   " << insertiontime2 << "                 " << bubbletime2;
	cout << "\nSame number      " << shelltime3 << "                 " << quicktime3 << "                " << selectiontime3 << "                   " << insertiontime3 << "                 " << bubbletime3 << endl << endl;

	milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	bubbletime3 = milli_time;

	return 0;
}
