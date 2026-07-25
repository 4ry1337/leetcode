
/* https://leetcode.com/problems/design-parking-system/ */

class ParkingSystem {
 private:
  int m_big, m_medium, m_small;

 public:
  ParkingSystem(int big, int medium, int small)
      : m_big(big), m_medium(medium), m_small(small) {}

  bool addCar(int carType) {
    if (carType == 1) {
      return m_big-- > 0;
    } else if (carType == 2) {
      return m_medium-- > 0;
    } else {
      return m_small-- > 0;
    }
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
