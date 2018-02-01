#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#include "mat4.h"

namespace engy { namespace maths {

	const float PI = 3.14159265f;

	inline float toRadians(float degrees)
	{
		return (degrees * (PI / (float)180));
	}
} }