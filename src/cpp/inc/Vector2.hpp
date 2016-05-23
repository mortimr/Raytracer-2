//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef SFML_VECTOR2_HPP
#define SFML_VECTOR2_HPP


namespace sf
{
  template <typename T>
  class Vector2
  {
  public :

    Vector2();

    Vector2(T X, T Y);

    template <typename U>
    explicit Vector2(const Vector2<U>& vector);

    // Member data
    T x;
    T y;
  };

  template <typename T>
  Vector2<T> operator -(const Vector2<T>& right);

  template <typename T>
  Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);

  template <typename T>
  Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);

  template <typename T>
  Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

  template <typename T>
  Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

  template <typename T>
  Vector2<T> operator *(const Vector2<T>& left, T right);

  template <typename T>
  Vector2<T> operator *(T left, const Vector2<T>& right);

  template <typename T>
  Vector2<T>& operator *=(Vector2<T>& left, T right);

  template <typename T>
  Vector2<T> operator /(const Vector2<T>& left, T right);

  template <typename T>
  Vector2<T>& operator /=(Vector2<T>& left, T right);

  template <typename T>
  bool operator ==(const Vector2<T>& left, const Vector2<T>& right);

  template <typename T>
  bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

#include <SFML/System/Vector2.inl>

  // Define the most common types
  typedef Vector2<int>          Vector2i;
  typedef Vector2<unsigned int> Vector2u;
  typedef Vector2<float>        Vector2f;

} // namespace sf

#endif // SFML_VECTOR2_HPP
