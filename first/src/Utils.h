#ifndef Utils_H
#define Utils_H
#include <iostream>

class Utils {
 public:
  /**
   *获取当前进程的路径
   */
  std::string GetCurrentPath();

  /**
   * 通过一张图片生成纹理
   */
  int CreateTexture(std::string path);
};
#endif