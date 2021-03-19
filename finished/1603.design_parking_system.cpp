/*
请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。

请你实现 ParkingSystem 类：

ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem
类，三个参数分别对应每种停车位的数目。 bool addCar(int carType) 检查是否有
carType 对应的停车位。 carType 有三种类型：大，中，小， 分别用数字 1， 2 和 3
表示。一辆车只能停在  carType 对应尺寸的停车位中。 如果没有空车位，请返回 false
，否则将该车停入车位并返回 true 。

示例 1：

输入：
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
输出：
[null, true, true, false, false]

解释：
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // 返回 true ，因为有 1 个空的大车位
parkingSystem.addCar(2); // 返回 true ，因为有 1 个空的中车位
parkingSystem.addCar(3); // 返回 false ，因为没有空的小车位
parkingSystem.addCar(1); // 返回 false
，因为没有空的大车位，唯一一个大车位已经被占据了

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-parking-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small)
      : avail_space_{big, medium, small} {}

  bool addCar(int carType) {
    unsigned int ind = carType - 1;
    if (avail_space_[ind] > 0) {
      avail_space_[ind]--;
      return true;
    } else {
      return false;
    }
  }

private:
  int avail_space_[3]; // 空闲车位数组
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
