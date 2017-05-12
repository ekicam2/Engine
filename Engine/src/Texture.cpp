#include "Texture.h"

#include <glm\vec2.hpp>


Texture::Texture(const std::string& fileName, Type textureType)
    : _type(textureType)
{
  //  bitmap_image image(fileName);
  //  glm::vec2 size(image.width(), image.height());
  //
  //  glGenTextures(1, &_handler);
  //
  //  glBindTexture(_type, _handler);
  //
  //  glTextureStorage2D(_type, 4, GL_RGBA, size.x, size.y);
  //  glTextureSubImage2D(_type, 4, 0, 0, size.x, size.y, GL_RGB, GL_UNSIGNED_BYTE, image.data());
  //
  //  glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  //  glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}


Texture::~Texture()
{
    // glDeleteTextures(1, &_handler);
}
