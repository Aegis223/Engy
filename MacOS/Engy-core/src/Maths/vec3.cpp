#include "vec3.h"

namespace engy { namespace maths {

	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float x, const float y, const float z)
	{
		(*this).x = x;
		(*this).y = y;
		(*this).z = z;
	}

	vec3::~vec3()
	{
		//destructor
	}

	vec3& vec3::add(const vec3 other)
	{
		(*this).x += other.x;
		(*this).y += other.y;
		(*this).z += other.z;
		return *this;
	}

	vec3& vec3::sub(const vec3 other)
	{
		(*this).x -= other.x;
		(*this).y -= other.y;
		(*this).z -= other.z;
		return *this;
	}

	vec3& vec3::multi(const vec3 other)
	{
		(*this).x *= other.x;
		(*this).y *= other.y;
		(*this).z *= other.z;
		return *this;
	}

	vec3& vec3::divide(const vec3 other)
	{
		(*this).x /= other.x;
		(*this).y /= other.y;
		(*this).z /= other.z;
		return *this;
	}

	vec3 operator+(vec3 left, const vec3 right)
	{
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3 right)
	{
		return left.sub(right);
	}

	vec3 operator*(vec3 left, const vec3 right)
	{
		return left.multi(right);
	}

	vec3 operator/(vec3 left, const vec3&right)
	{
		return left.divide(right);
	}

	vec3& vec3::operator+=(const vec3 other)
	{
		return add(other);
	}

	vec3& vec3::operator-=(const vec3 other)
	{
		return sub(other);
	}

	vec3& vec3::operator*=(const vec3 other)
	{
		return multi(other);
	}

	vec3& vec3::operator/=(const vec3 other)
	{
		return divide(other);
	}

	bool vec3::operator==(const vec3 other)
	{
		return ((*this).x == other.x && (*this).y == other.y && (*this).z == other.z);
	}

	bool vec3::operator!=(const vec3 other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
} }