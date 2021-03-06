/****************************************************************************
**
** Copyright (c) 2011 libmv authors.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
**
****************************************************************************/

#ifndef UI_TRACKER_GL_H_
#define UI_TRACKER_GL_H_

#include <cmath>
#include <QString>
#include <QMap>
#include <QVector>
class QImage;
#define PI M_PI

/// Algebra structures used by GL layer following GLSL conventions

struct vec2 {
  float x, y;
  inline vec2() : x(0), y(0) {}
  inline vec2(float x, float y) : x(x), y(y) {}
  inline vec2(float v[2]) : x(v[0]), y(v[1]) {}
#ifdef QSTRING_H
  inline QString toString() const {
    return QString("%1 %2").arg(x, 0, 'f', 2).arg(y, 0, 'f', 2);
  }
#endif
};
inline vec2 operator -( vec2 a ) { return vec2( -a.x, -a.y ); }
inline vec2 operator +( vec2 a, vec2 b ) { return vec2( a.x+b.x, a.y+b.y ); }
inline vec2 operator +( vec2 a, float b ) { return vec2( a.x+b, a.y+b ); }
inline vec2 operator -( vec2 a, vec2 b ) { return vec2( a.x-b.x, a.y-b.y ); }
inline vec2 operator -( vec2 a, float b ) { return vec2( a.x-b, a.y-b ); }
inline vec2 operator *( float b, vec2 a ) { return vec2( a.x*b, a.y*b ); }
inline vec2 operator /( vec2 a, float b ) { return vec2( a.x/b, a.y/b ); }
inline vec2 operator /( float a, vec2 b ) { return vec2( a/b.x, a/b.y ); }
inline vec2 operator /( vec2 a, vec2 b ) { return vec2( a.x/b.x, a.y/b.y ); }
inline bool operator <( vec2 a, vec2 b ) { return a.x < b.x && a.y < b.y; }
inline bool operator >( vec2 a, vec2 b ) { return a.x > b.x && a.y > b.y; }

struct vec3 {
  float x, y, z;
  inline vec3() : x(0), y(0), z(0) {}
  inline vec3(float x, float y, float z) : x(x), y(y), z(z) {}
  inline vec3(vec2 v, float z) : x(v.x), y(v.y), z(z) {}
  inline vec3(float v[3]) : x(v[0]), y(v[1]), z(v[2]) {}
  inline vec3 operator -() { return vec3(-x, -y, -z); }
  inline void operator +=(vec3 a) { x += a.x, y += a.y, z += a.z; }
  inline void operator *=(float a) { x *= a, y *= a, z *= a; }
  inline void operator /=(float a) { x /= a, y /= a, z /= a; }
  inline float& operator[](int i) { return (&x)[i]; }
  inline vec2 xy() { return vec2(x, y); }
#ifdef QSTRING_H
  inline QString toString() const {
    return QString("%1 %2 %3")
        .arg(x, 0, 'f', 2).arg(y, 0, 'f', 2).arg(z, 0, 'f', 2);
  }
#endif
};
inline float dot( vec3 a, vec3 b ) { return a.x*b.x + a.y*b.y + a.z*b.z; }
inline vec3 operator +(vec3 a, vec3 b) {
  return vec3( a.x+b.x, a.y+b.y, a.z+b.z );
}
inline vec3 operator +(vec3 a, float b) {
  return vec3( a.x+b, a.y+b, a.z+b );
}
inline vec3 operator -(vec3 a, vec3 b) {
  return vec3( a.x-b.x, a.y-b.y, a.z-b.z );
}
inline vec3 operator -(vec3 a, float b) {
  return vec3( a.x-b, a.y-b, a.z-b );
}
inline vec3 operator *(vec3 a, vec3 b) {
  return vec3( a.x*b.x, a.y*b.y, a.z*b.z );
}
inline vec3 operator /(vec3 a, vec3 b) {
  return vec3( a.x/b.x, a.y/b.y, a.z/b.z );
}
inline vec3 operator *(float b, vec3 a) {
  return vec3( a.x*b, a.y*b, a.z*b );
}
inline vec3 operator *(vec3 a, float b) {
  return vec3( a.x*b, a.y*b, a.z*b );
}
inline vec3 operator /(vec3 a, float b) {
  return vec3( a.x/b, a.y/b, a.z/b );
}
inline vec3 operator /(float a, vec3 b) {
  return vec3( a/b.x, a/b.y, a/b.z );
}
inline bool operator <(vec3 a, vec3 b) {
  return a.x < b.x && a.y < b.y && a.z < b.z;
}
inline bool operator >(vec3 a, vec3 b) {
  return a.x > b.x && a.y > b.y && a.z > b.z;
}
inline float length(vec3 a) { return sqrt(dot(a, a)); }
inline vec3 normalize(vec3 a) { return a*(1.0/length(a)); }

struct vec4 {
  float x, y, z, w;
  inline vec4() : x(0), y(0), z(0), w(0) {}
  inline vec4(float x, float y , float z, float w) : x(x), y(y), z(z), w(w) {}
  inline vec4(float x, float y , vec2 v) : x(x), y(y), z(v.x), w(v.y) {}
  inline float& operator[]( int i ) { return (&x)[i]; }
  inline vec3 xyz() { return vec3(x, y, z); }
  inline vec2 xy() { return vec2(x, y); }
};
inline float dot(vec4 a, vec4 b) {
  return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}
inline vec4 operator *(vec4 a, float b) {
  return vec4( a.x*b, a.y*b, a.z*b, a.w*b );
}
inline vec4 normalize(vec4 a) {
  return a*(1.0/length(a.xyz()));
}

struct mat4 {
  float data[4*4];
  inline mat4(int d = 1) {
    for (int i = 0; i < 16; i++) data[i] = 0;
    if (d != 0) for (int i = 0; i < 4; i++) m(i, i) = d;
  }
  inline float m(int i, int j) const { return data[j*4+i]; }
  inline float& m(int i, int j) { return data[j*4+i]; }
  inline float operator()(int i, int j) const { return m(i, j); }
  inline float& operator()(int i, int j) { return m(i, j); }
  inline vec4 operator*(vec4 v) const {
    vec4 r;
    for (int i = 0; i < 4 ; i++)
      r[i] = v.x*m(i, 0)+v.y*m(i, 1)+v.z*m(i, 2)+v.w*m(i, 3);
    return r;
  }
  inline vec3 operator*(vec3 v) const {
    vec4 r = *this*vec4(v.x, v.y, v.z, 1);
    return r.xyz()/r.w;
  }
  inline vec2 operator*(vec2 v) const {
    vec4 r = *this*vec4(v.x, v.y, 0, 1);
    return r.xy()/r.w;
  }
  inline mat4 operator*(mat4 b) const {
    mat4 r(0);
    for (int j = 0; j < 4; j++)
      for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
          r.m(i, j) += m(i, k)*b.m(k, j);
    return r;
  }
  inline void perspective(float fov, float aspect, float nearPlane,
                          float farPlane) {
    float cotan = cos(fov/2) / sin(fov/2);
    m(0, 0) = cotan / aspect;
    m(1, 1) = cotan;
    m(2, 2) = (nearPlane+farPlane) / (nearPlane-farPlane);
    m(2, 3) = (2*nearPlane*farPlane) / (nearPlane-farPlane);
    m(3, 2) = -1;
    m(3, 3) = 0;
  }
  inline void translate(vec3 v) {
    for (int i = 0;i < 4; i++)
      m(i, 3) += m(i, 0)*v.x + m(i, 1)*v.y + m(i, 2)*v.z;
  }
  inline void scale(float f) {
    for (int j = 0; j < 3; j++) for (int i = 0; i < 4; i++) m(i, j) *= f;
  }
  inline void scale(vec3 v) {
    for (int j = 0; j < 3; j++) for (int i = 0;i < 4; i++) m(i, j) *= v[j];
  }
  inline void rotateX(float angle) {
    float c = cos(angle), s = sin(angle);
    mat4 r;
    r.m(1, 1) = c;
    r.m(2, 2) = c;
    r.m(1, 2) = -s;
    r.m(2, 1) = s;
    *this = *this * r;
  }
  inline void rotateY(float angle) {
    float c = cos(angle), s = sin(angle);
    mat4 r;
    r.m(0, 0) = c;
    r.m(2, 2) = c;
    r.m(2, 0) = -s;
    r.m(0, 2) = s;
    *this = *this * r;
  }
  inline void rotateZ(float angle) {
    float c = cos(angle), s = sin(angle);
    mat4 r;
    r.m(0, 0) = c;
    r.m(1, 1) = c;
    r.m(0, 1) = -s;
    r.m(1, 0) = s;
    *this = *this * r;
  }
  inline float det3(int j0, int j1, int j2, int i0, int i1, int i2) const {
    return  m(i0, j0) * (m(i1, j1) * m(i2, j2) - m(i2, j1) * m(i1, j2)) -
        m(i0, j1) * (m(i1, j0) * m(i2, j2) - m(i2, j0) * m(i1, j2)) +
        m(i0, j2) * (m(i1, j0) * m(i2, j1) - m(i2, j0) * m(i1, j1));
  }
  inline mat4 inverse() const {
    float det = 1 / (m(0, 0) * det3(1, 2, 3, 1, 2, 3) -
                     m(0, 1) * det3(0, 2, 3, 1, 2, 3) +
                     m(0, 2) * det3(0, 1, 3, 1, 2, 3) -
                     m(0, 3) * det3(0, 1, 2, 1, 2, 3));
    mat4 inv(0);
    inv(0, 0) =  det3(1, 2, 3, 1, 2, 3) * det;
    inv(1, 0) = -det3(0, 2, 3, 1, 2, 3) * det;
    inv(2, 0) =  det3(0, 1, 3, 1, 2, 3) * det;
    inv(3, 0) = -det3(0, 1, 2, 1, 2, 3) * det;
    inv(0, 1) = -det3(1, 2, 3, 0, 2, 3) * det;
    inv(1, 1) =  det3(0, 2, 3, 0, 2, 3) * det;
    inv(2, 1) = -det3(0, 1, 3, 0, 2, 3) * det;
    inv(3, 1) =  det3(0, 1, 2, 0, 2, 3) * det;
    inv(0, 2) =  det3(1, 2, 3, 0, 1, 3) * det;
    inv(1, 2) = -det3(0, 2, 3, 0, 1, 3) * det;
    inv(2, 2) =  det3(0, 1, 3, 0, 1, 3) * det;
    inv(3, 2) = -det3(0, 1, 2, 0, 1, 3) * det;
    inv(0, 3) = -det3(1, 2, 3, 0, 1, 2) * det;
    inv(1, 3) =  det3(0, 2, 3, 0, 1, 2) * det;
    inv(2, 3) = -det3(0, 1, 3, 0, 1, 2) * det;
    inv(3, 3) =  det3(0, 1, 2, 0, 1, 2) * det;
    return inv;
  }
  inline mat4 transpose() const {
    mat4 t(0);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) t(i, j) = m(j, i);
    return t;
  }
};
inline bool operator !=(mat4 a, mat4 b) {
  for (int i = 0; i < 16; i++) if (a.data[i] != b.data[i]) return true;
  return false;
}

/// Convenient GL abstraction layer

struct GLUniform {
  explicit GLUniform(int id) : id(id) {}
  void operator=(int);
  void operator=(double);
  void operator=(vec2);
  void operator=(vec3);
  void operator=(vec4);
  void operator=(mat4);
  void set(vec3*, int);
  void set(vec4*, int);

  int id;
};

struct GLShader {
  GLShader() : id(0) {}
  bool compile(QString vertex, QString fragment);
  void bind();
  int attribLocation(const char*);
  GLUniform operator[](const char*);

  uint id;
  // using pointer lookup (only works with string literals)
  QMap<const char*, int> attribLocations;
  QMap<const char*, int> uniformLocations;
};

struct GLBuffer {
  GLBuffer() : vertexBuffer(0), vertexCount(0), vertexSize(0),
    indexBuffer(0), indexCount(0), primitiveType(3) {}
  operator bool() { return vertexBuffer; }
  void upload(const void* data, int count);
  void upload(const void* data, int count, int size);
  void bind();
  void bindAttribute(GLShader* program, const char* name, int elementSize,
                     size_t offset = 0);
  void draw();

  uint vertexBuffer;
  uint vertexCount;
  uint vertexSize;
  uint indexBuffer;
  uint indexCount;
  uint primitiveType;
};

struct GLTexture {
  GLTexture() : id(0), width(0), height(0) {}
  void upload(QImage image);
  void bind(int sampler);

  uint id;
  int width, height, depth;
};

void glInitialize();
void glBindWindow(int x, int y, int w, int h, bool clear);
void glSmooth();
void glHard();
void glQuad(vec4 quad[4]);
QString glsl(QString tags);

#endif
