/* I don't know why, but, this set of functions does not work after 7600000 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


// function.forEach(this.declare())

int getNum(string sentence);
bool isPrime(int num);
void showProgress(int range, int level, int &previousStatus);
void showList(int list[], int size);


// MAIN ***
int main()
{
  // Initial
  vector<int> primes;
  int status = 0,
  startFrom = getNum("Start from"),
  endWith = getNum("End with");

  // Actual work
  for (int num = startFrom; num <= endWith; num++) {
    if (isPrime(num)) { primes.push_back(num); }
    showProgress(endWith-startFrom, num-startFrom, status);
  }

  // Vector --> Array
  int size = primes.size();
  int primeList[size];
  copy(primes.begin(), primes.end(), primeList);

  // Being user friendly
  cout << endl;
  if (size < 2) {
    switch (size) {
    case 0: cout << "No"; break;
    case 1: cout << "Only one"; break;
    } cout << " prime";
  }
  else { cout << size << " primes"; }
  cout << " found in range (" << startFrom << ", "
    << endWith << "). Want to see them? (1/0): ";

  // Do you really want to see that big list?
  bool showThem;
  cin >> showThem;
  if (showThem) { showList(primeList, size); }

  return 0;
}


// functions.forEach(this.define())

void showProgress(int range, int level, int &previousStatus) {
  int status = 10 * level / range;
  if (status != previousStatus) { cout << '#'; }
  previousStatus = status;
}


int getNum(string sentence) {
  int num;
  cout << sentence << ": ";
  cin >> num;
  return num;
}

bool isPrime(int num) {
  if (num < 2) { return 0; }
  int dividerLimit = sqrt(num);
  for (int divider = 2; divider <= dividerLimit; divider++) {
    if (num % divider == 0) { return 0; }
  }
  return 1;
}

void showList(int list[], int size) {
  cout << '[';
  if (size != 0) { cout << list[0]; }
  for (int i = 1; i < size; i++) { cout << ", " << list[i]; }
  cout << ']';
}
