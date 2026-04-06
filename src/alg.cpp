// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int n = i + 1; n < len; n++) {
      if (arr[i] + arr[n] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  int posLeft = 0;
  int posRight = len - 1;
  while (posLeft < posRight) {
    int num = arr[posLeft] + arr[posRight];
    if (num == value) {
      if (arr[posLeft] == arr[posRight]) {
        counter += (posRight - posLeft +1) * (posRight - posLeft) / 2;
        break;
      }
      int counterLeft = 0;
      int counterRight = 0;
      int copyLeft = posLeft;
      int copyRight = posRight;
      while (copyLeft <= copyRight && arr[copyLeft] == arr[posLeft]) {
        counterLeft++;
        copyLeft++;
      }
      while (copyRight >= posLeft && arr[copyRight] == arr[posRight]) {
        counterRight++;
        copyRight--;
      }
      counter += counterLeft * counterRight;
      posLeft = copyLeft;
      posRight = copyRight;
    } else if (num < value)  {
      posLeft++;
    } else {
      posRight--;
    }
  }
  return counter;
}
int bin (int *arr, int left, int right, int num) {
  while (left <= right) {
    int centr = left + (right - left) / 2;
    if (arr[centr] == num) {
      return centr;
    }
    if (arr[centr] < num) {
      left = centr + 1;
    } else {
      right = centr - 1;
    }
  }
  return -1;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    int num = value - arr[i];
    int poiskNum = bin(arr, i + 1, len - 1, num);
    if (poiskNum != -1) {
      if (arr[i] == num) {
        int counterI = 0;
        int copyI = i;
        while (copyI < len && arr[copyI] == num) {
          counterI++;
          copyI++;
        }
        counter += counterI * (counterI -1) / 2;
        i = copyI -1;
      } else {
        int counterRight = 0;
        int copyPoiskNum = poiskNum;
        while (copyPoiskNum > i && arr[copyPoiskNum] == num) {
          counterRight++;
          copyPoiskNum--;
        }
        copyPoiskNum = poiskNum + 1;
        while (copyPoiskNum < len && arr[copyPoiskNum] == num) {
          counterRight++;
          copyPoiskNum++;
        }
        int counterLeft = 0;
        int copyI = i;
        while (copyI < len && arr[copyI] == arr[i]) {
          counterLeft++;
          copyI++;
        }
        counter += counterLeft * counterRight;
        i = copyI - 1;
      }
    }
  }
  return counter;
}
