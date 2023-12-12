#include "Utils.h"

// Linux
#include <unistd.h>
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

std::string Utils::GetCurrentPath() {
  char curr_path[1024];
  getcwd(curr_path, 1024);
  sprintf(curr_path, "%s/", curr_path);
  std::string currentPath = curr_path;
  return currentPath;
}

/**
 * 通过一张图片生成纹理
 */
int Utils::CreateTexture(std::string path) {
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(
      true);  // tell stb_image.h to flip loaded texture's on the y-axis.

  unsigned char* data =
      stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);
  return texture;
}