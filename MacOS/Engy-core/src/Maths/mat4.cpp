#include "mat4.h"

namespace engy { namespace maths {

	mat4::mat4()
	{
		memset(elements, 0, 4 * 4 * sizeof(float));
	}

	mat4::mat4(float diagonal)
	{
		memset(elements, 0, 4 * 4 * sizeof(float));

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	mat4::~mat4()
	{
		//destructor
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4& mat4::multi(const mat4 other)
	{
		float data[16];

		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				float sum = 0.0f;

				for (int m = 0; m < 4; m++)
				{
					sum += this->elements[row + m * 4] * other.elements[m + col * 4];
				}

				data[row + col * 4] = sum;
			}
		}

		memcpy(this, data, 4 * 4 * sizeof(float));
		return *this;
	}

	vec4& mat4::vecMulti(const vec4 other)
	{
		vec4 result;

		float vec[4] = { other.x, other.y, other.z, other.w };
		float data[4];

		for (int row = 0; row < 4; row++)
		{
			float sum = 0.0f;

			for (int m = 0; m < 4; m++)
			{
				sum += this->elements[row + m * 4] * vec[m];
			}

			data[row] = sum;
		}

		memcpy(&result, data, 4 * sizeof(float));
		return result;
	}


	mat4 operator+(mat4 left, const mat4 right) 
	{
		return left.multi(right);
	}

	mat4& mat4::operator*=(const mat4 other)
	{
		return multi(other);
	}

	mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 projection(1.0f);

		projection.elements[0 + 0 * 4] = ((float)(2) / (float)(right - left));
		projection.elements[1 + 1 * 4] = ((float)(2) / (float)(top - bottom));
		projection.elements[2 + 2 * 4] = ((float)(-2) / (float)(far - near));

		projection.elements[0 + 3 * 4] = -((float)(right + left) / (float)(right - left));
		projection.elements[1 + 3 * 4] = -((float)(top + bottom) / (float)(top - bottom));
		projection.elements[2 + 3 * 4] = -((float)(far + near) / (float)(far - near));

		return projection;
	}

	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 projection;

		float t = tan(toRadians(fov / 2));
		float aT = aspectRatio * t;

		projection.elements[0 + 0 * 4] = ((float)1 / (float)(aT));
		projection.elements[1 + 1 * 4] = ((float)1 / (float)(t));
		projection.elements[2 + 2 * 4] = -((float)(far + near) / (float)(far - near));

		projection.elements[3 + 2 * 4] = -(1.0f);
		projection.elements[2 + 3 * 4] = -((float)(2 * far * near) / (float)(far - near));

		return projection;
	}

	mat4 mat4::translate(const vec3 translation)
	{
		mat4 transform(1.0f);

		transform.elements[0 + 3 * 4] = translation.x;
		transform.elements[1 + 3 * 4] = translation.y;
		transform.elements[2 + 3 * 4] = translation.z;

		return transform;
	}

	mat4 mat4::rotate(float angle, const vec3 axis)
	{
		mat4 transform(1.0f);

		float r = toRadians(angle);
		float s = sin(r);
		float c = cos(r);

		float omc = 1.0f - c;

		transform.elements[0 + 0 * 4] = ceilf(((axis.x * axis.x) * omc + c) * 10000) / 10000;
		transform.elements[1 + 0 * 4] = ceilf(((axis.x * axis.y) * omc + axis.z * s) * 10000) / 10000;
		transform.elements[2 + 0 * 4] = ceilf(((axis.x * axis.z) * omc - axis.y * s) * 10000) / 10000;

		transform.elements[0 + 1 * 4] = ceilf(((axis.x * axis.y) * omc - axis.z * s) * 10000) / 10000;
		transform.elements[1 + 1 * 4] = ceilf(((axis.y * axis.y) * omc + c) * 10000) / 10000;
		transform.elements[2 + 1 * 4] = ceilf(((axis.y * axis.z) * omc + axis.x * s) * 10000) / 10000;

		transform.elements[0 + 2 * 4] = ceilf(((axis.x * axis.z) * omc + axis.y * s) * 10000) / 10000;
		transform.elements[1 + 2 * 4] = ceilf(((axis.y * axis.z) * omc - axis.x * s) * 10000) / 10000;
		transform.elements[2 + 2 * 4] = ceilf(((axis.z * axis.z) * omc + c) * 10000) / 10000;

		return transform;
	}

	mat4 mat4::scale(const vec3 scale)
	{
		mat4 transform(1.0f);

		transform.elements[0 + 0 * 4] = scale.x;
		transform.elements[1 + 1 * 4] = scale.y;
		transform.elements[2 + 2 * 4] = scale.z;

		return transform;
	}


	std::ostream& operator<<(std::ostream& stream, const mat4 matrix)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				stream << matrix.elements[row + col * 4] << ", ";
			}

			stream << std::endl;
		}

		return stream;
	}
} }