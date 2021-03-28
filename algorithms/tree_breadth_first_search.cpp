#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <regex>
#include <stack>
#include <queue>
using namespace std;

class FileSearch {
  private:
  // DFS模式，需要将front()改成top()
  //stack<string> path; // 路径栈
  // BFS模式
  queue<string> path; // 路径队列

  public:
  /**
   * Detail: 显示ubuntu指定目录下文件
   * basePath- 文件路径
   * return: null
   */
  void searchFile(char *basePath) {
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    char temp[1000];
    // 路径入栈(队列)
    path.push(basePath);
    // 遍历开始
    while (!path.empty()) {
      // 打开当前目录
      strcpy(temp, path.front().c_str());
      path.pop();
      cout << "Current path: " << temp << endl;
      if ((dir = opendir(temp)) == NULL) {
        perror("Open dir error, please input the right path");
        exit(1);
      }
      // 显示当前路径下的文件
      while ((ptr = readdir(dir)) != NULL) {
        // 忽略隐藏文件和隐藏路径
        if (regex_match(ptr->d_name, regex("\\.(.*)"))) {
          continue;
        }
        if (ptr->d_type == 8) {
          // A regular file
          //cout << "file: " << basePath << "/" << ptr->d_name << endl;
          cout << ptr->d_name << endl;
        } else if (ptr->d_type == 4) {
          // 检测为文件夹
          memset(base, '\0', sizeof(base));
          strcpy(base, temp);
          strcat(base, "/");
          strcat(base, ptr->d_name);
          path.push(base);
          continue;
        }
      }
    }
    // 关闭文件
    closedir(dir);
  }
};

int main(void) {
  FileSearch test;

  // 需要遍历的文件夹目录
  char basePath[] = {"/home/joe/Desktop/leetcode"};

  test.searchFile(basePath);
  return 0;
}
