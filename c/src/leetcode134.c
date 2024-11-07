int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
  int start = 0, curr = 0, total = 0, diff = 0;
  for (int i = 0; i < gasSize; i++) {
    diff = gas[i] - cost[i];
    curr += diff;
    total += diff;
    if (curr < 0) {
      curr = 0;
      start = i + 1;
    }
  }
  if (total >= 0) {
    return start;
  }
  return -1;
}
