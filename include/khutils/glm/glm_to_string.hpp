﻿#ifndef KHUTILS_GLM_TO_STRING_HPP_INC
#define KHUTILS_GLM_TO_STRING_HPP_INC

#include <glm/fwd.hpp>
#include <iosfwd>
#include <string>

namespace khutils
{
	const std::string to_string(const glm::quat& q);
	const std::string to_string(const glm::vec2& v);
	const std::string to_string(const glm::vec3& v);
	const std::string to_string(const glm::vec4& v);
	const std::string to_string(const glm::mat4& m);

	const std::string to_string(const glm::dquat& q);
	const std::string to_string(const glm::dvec2& v);
	const std::string to_string(const glm::dvec3& v);
	const std::string to_string(const glm::dvec4& v);
	const std::string to_string(const glm::dmat4& m);

	const std::string to_string(const glm::ivec2& v);
	const std::string to_string(const glm::ivec3& v);
	const std::string to_string(const glm::ivec4& v);

	std::ostream& operator<<(std::ostream& os, const glm::quat& q);
	std::ostream& operator<<(std::ostream& os, const glm::vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::vec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::mat4& m);
	std::ostream& operator<<(std::ostream& os, const glm::dquat& q);
	std::ostream& operator<<(std::ostream& os, const glm::dvec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::dvec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::dvec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::dmat4& m);
	std::ostream& operator<<(std::ostream& os, const glm::ivec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::ivec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::ivec4& v);

}	// namespace khutils

#if defined(KHUTILS_GLM_TO_STRING_IMPL)

#define GLM_SWIZZLE
#define GLM_FORCE_RADIANS
#define GLM_PRECISION_HIGHP_FLOAT
#include <fmt/format.h>

#include "khutils/glm/glm_to_string.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>
#include <string>

namespace khutils
{
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////

	const std::string to_string(const glm::quat& q)
	{
		return "({0} i + {1} j + {2} k + {3})\n"_format(q.x, q.y, q.z, q.w);
	}

	const std::string to_string(const glm::vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::mat4& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "({0},\n{1},\n{2},\n{3})"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	const std::string to_string(const glm::dquat& q)
	{
		return "({0} i + {1} j + {2} k + {3})\n"_format(q.x, q.y, q.z, q.w);
	}

	const std::string to_string(const glm::dvec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::dvec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::dvec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::dmat4& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "({0},\n{1},\n{2},\n{3})"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	const std::string to_string(const glm::ivec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::ivec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::ivec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	//////////////////////////////////////////////////////////////////////////

	std::ostream& operator<<(std::ostream& os, const glm::quat& q)
	{
		os << "glm::quat" << to_string(q);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec2& v)
	{
		os << "glm::vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec3& v)
	{
		os << "glm::vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec4& v)
	{
		os << "glm::vec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::mat4& m)
	{
		os << "glm::mat4" << to_string(m);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dquat& q)
	{
		os << "glm::dquat" << to_string(q);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec2& v)
	{
		os << "glm::dvec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec3& v)
	{
		os << "glm::dvec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec4& v)
	{
		os << "glm::dvec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dmat4& m)
	{
		os << "glm::dmat4" << to_string(m);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ivec2& v)
	{
		os << "glm::ivec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ivec3& v)
	{
		os << "glm::ivec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ivec4& v)
	{
		os << "glm::ivec4" << to_string(v);
		return os;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_TO_STRING_IMPL)

#endif	// !KHUTILS_GLM_TO_STRING_HPP_INC
