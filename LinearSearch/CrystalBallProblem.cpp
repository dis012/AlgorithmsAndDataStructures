#include <iostream>
#include <cmath>

using namespace std;

// Pass the size of the array as an additional parameter
int twoCrystalBall(bool breaks[], int size) {
  // Calculate the jump amount using integer division
  int jmpAmount = sqrt(size);

  // Use the first ball to see where the breaking point is.
  int i = jmpAmount;
  for (; i < size; i += jmpAmount) {
    if (breaks[i]) {
      break;
    }
  }

  // Check bounds and correct overshoot
  i -= jmpAmount;
  for (int j = 0; j < jmpAmount && i < size; j++, i++) {
    if (breaks[i]) {
      return i;
    }
  }
  return -1; // Return -1 if no break point is found
}

int main() {
  bool breaks[20] = {false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true};
  
  // Pass the array along with its size
  int result = twoCrystalBall(breaks, sizeof(breaks)/sizeof(breaks[0]));
  if (result == -1) {
    cout << "Element is not present in the array." << endl;
  } else {
    cout << "Element is present at index " << result << endl;
  }

  return 0;
}

