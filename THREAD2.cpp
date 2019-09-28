#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> set1(false);
atomic<bool> set2(false);
atomic<bool> set3(false);

atomic<int> counter1(0);
atomic<int> counter2(0);
atomic<int> counter3(0);

void lottery1(int id) {
	while (!set1){
	  this_thread::yield();
		}
	for (volatile int i = 1; i < 55; ++i) {
		++counter1;
		if (counter1 <= 6) {
			cout << id << " ";
		}
	}
}
void lottery2(int id) {
	while (!set2){
	  this_thread::yield();
		}
	for (volatile int i = 1; i < 55; ++i) {
		++counter2;
		if (counter2 <= 6) {
			cout << id << " ";
		}
	}
}
void lottery3(int id) {
	while (!set3){
	  this_thread::yield();
		}
	for (volatile int i = 1; i < 55; ++i) {
		++counter3;
		if (counter3 <= 6) {
			cout << id<<" ";
		}
	}
}
int main()
{
	int i = 1;
	thread mythreads1[55];
	thread mythreads2[55];
	thread mythreads3[55];
	cout << "Lotto Winners!\n";

	for (int i = 1; i < 7; ++i) mythreads1[i] = std::thread(lottery1, i);
	cout << "\nFirst Winner: ";
	set1 = true;
	this_thread::sleep_for(chrono::seconds(1));
	mythreads1[i].join();

	for (int i = 1; i < 7; ++i) mythreads2[i] = std::thread(lottery2, i);
	cout << "\nSecond Winner: ";
	set2 = true;
	this_thread::sleep_for(chrono::seconds(2));
	mythreads2[i].join();

	for (int i = 1; i < 7; ++i) mythreads3[i] = std::thread(lottery3, i);
	cout << "\nThird Winner: ";
	set3 = true;
	this_thread::sleep_for(chrono::seconds(3));
	mythreads3[i].join();
	return 0;

}
