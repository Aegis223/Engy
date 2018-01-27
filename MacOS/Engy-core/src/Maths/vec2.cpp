#include "vec2.h"

namespace engy { namespace maths {

	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float x, const float y)
	{
		(*this).x = x;
		(*this).y = y;
	}

	vec2::~vec2()
	{
		//destructor
	}

	vec2& vec2::add(const vec2 other)
	{
		(*this).x += other.x;
		(*this).y += other.y;
		return *this;
	}

	vec2& vec2::sub(const vec2 other)
	{
		(*this).x -= other.x;
		(*this).y -= other.y;
		return *this;
	}

	vec2& vec2::multi(const vec2 other)
	{
		(*this).x *= other.x;
		(*this).y *= other.y;
		return *this;
	}

	vec2& vec2::divide(const vec2 other)
	{
		(*this).x /= other.x;
		(*this).y /= other.y;
		return *this;
	}

	vec2 operator+(vec2 left, const vec2 right)
	{
		return left.add(right);
	}

	vec2 operator-(vec2 left, const vec2 right)
	{
		return left.sub(right);
	}

	vec2 operator*(vec2 left, const vec2 right)
	{
		return left.multi(right);
	}

	vec2 operator/(vec2 left, const vec2&right)
	{
		return left.divide(right);
	}

	vec2& vec2::operator+=(const vec2 other)
	{
		return add(other);
	}

	vec2& vec2::operator-=(const vec2 other)
	{
		return sub(other);
	}

	vec2& vec2::operator*=(const vec2 other)
	{
		return multi(other);
	}

	vec2& vec2::operator/=(const vec2 other)
	{
		return divide(other);
	}

	bool vec2::operator==(const vec2 other)
	{
		return ((*this).x == other.x && (*this).y == other.y);
	}

	bool vec2::operator!=(const vec2 other)
	{
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
} }