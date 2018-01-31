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

	mat4& mat4::identity()
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

	mat4 operator*(mat4 left, const mat4 right)
	{
		return left.multi(right);
	}

	mat4& mat4::operator*=(const mat4 other)
	{
		return multi(other);
	}

	mat4& mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 projection(1.0f);

		projection.elements[0 + 0 * 4] = ((float)2 / (float)(right - left));
		projection.elements[1 + 1 * 4] = ((float)2 / (float)(top - bottom));
		projection.elements[2 + 2 * 4] = ((float)-2 / (float)(far - near));

		projection.elements[0 + 3 * 4] = -((float)(right + left) / (float)(right - left));
		projection.elements[1 + 3 * 4] = -((float)(top + bottom) / (float)(top - bottom));
		projection.elements[2 + 3 * 4] = -((float)(far + near) / (float)(far - near));

		return projection;
	}

	mat4& mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 projection;

		float T = tan(fov / 2);
		float aT = ((toRadians(aspectRatio)) * (T));

		projection.elements[0 + 0 * 4] = ((float)(1) / (float)(aT));
		projection.elements[1 + 1 * 4] = ((float)(1) / (float)(T));
		projection.elements[2 + 2 * 4] = -((float)(far + near) / (float)(far - near));

		projection.elements[2 + 3 * 4] = -((float)(2 * far * near) / (float)(far - near));
		projection.elements[3 + 2 * 4] = -(1);

		return projection;
	}

	mat4& translate(const vec3 translation)
	{
		mat4 transform(1.0f);

		transform.elements[0 + 3] = translation.x;
		transform.elements[1 + 3] = translation.y;
		transform.elements[2 + 3] = translation.z;

		return transform;
	}

	mat4& rotate(float angle, const vec3 axis)
	{
		mat4 transform(1.0f);

		float r = toRadians(angle);
		float s = sin(r);
		float c = cos(r);
		float omc = 1.0f - c;

		transform.elements[0 + 0 * 4] = (axis.x * axis.x) * omc + c;
		transform.elements[1 + 0 * 4] = (axis.x * axis.y) * omc + axis.z * s;
		transform.elements[2 + 0 * 4] = (axis.x * axis.z) * omc - axis.y * s;

		transform.elements[0 + 1 * 4] = (axis.x * axis.y) * omc - axis.z * s;
		transform.elements[1 + 1 * 4] = (axis.y * axis.y) * omc + c;
		transform.elements[2 + 1 * 4] = (axis.y * axis.z) * omc + axis.x * s;

		transform.elements[0 + 2 * 4] = (axis.x * axis.z) * omc + axis.y * s;
		transform.elements[1 + 2 * 4] = (axis.y * axis.z) * omc - axis.x * s;
		transform.elements[2 + 2 * 4] = (axis.z * axis.z) * omc + c;

		return transform;
	}

	mat4& scale(const vec3 scale)
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