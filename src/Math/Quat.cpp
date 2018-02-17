#include "Math/Quat.h"

#include <cmath>

#include "Math/Matrix4.h"

namespace glwl {

	Quat::Quat(float scalar, const Vector3 & vector) : scalar(scalar), vector(vector) {}

	Quat::Quat(float scalar, float x, float y, float z) : Quat(scalar, Vector3(x, y, z)) {}

	Quat::Quat(const Vector3 & axis, float angle) {
		Vector3 norm = axis.getNormalize();
		angle *= PI / 180;

		scalar = std::cos(angle / 2);
		setVector(
			norm.getX() * std::sin(angle / 2),
			norm.getY() * std::sin(angle / 2),
			norm.getZ() * std::sin(angle / 2)
		);
	}

	Quat::Quat(const Vector3 & angles) {
		Quat x(Vector3(1, 0, 0), angles.getX());
		Quat y(Vector3(0, 1, 0), angles.getY());
		Quat z(Vector3(0, 0, 1), angles.getZ());

		*this = z * y * x;
	}

	void Quat::setScalar(float scalar) {
		this->scalar = scalar;
	}

	void Quat::setVector(const Vector3 & vector) {
		this->vector = vector;
	}

	void Quat::setVector(float x, float y, float z) {
		setVector(Vector3(x, y, z));
	}

	float Quat::getScalar() const {
		return scalar;
	}

	Vector3 Quat::getVector() const {
		return vector;
	}

	Quat Quat::getStar() const {
		return Quat(scalar, -vector);
	}

	Matrix4 Quat::getMatrix() const {
		float aa = scalar * scalar;
		float bb = vector.getX() * vector.getX();
		float cc = vector.getY() * vector.getY();
		float dd = vector.getZ() * vector.getZ();

		float ab = scalar * vector.getX();
		float ac = scalar * vector.getY();
		float ad = scalar * vector.getZ();
		float bc = vector.getX() * vector.getY();
		float bd = vector.getX() * vector.getZ();
		float cd = vector.getY() * vector.getZ();

		float values[] = {
			aa + bb - cc - dd	, 2 * bc + 2 * ad	, 2 * bd - 2 * ac	, 0,
			2 * bc - 2 * ad		, aa - bb + cc - dd	, 2 * cd + 2 * ab	, 0,
			2 * bd + 2 * ac		, 2 * cd - 2 * ab	, aa - bb - cc + dd	, 0,
			0					, 0					, 0					, 1
		};

		return Matrix4(values);
	}

	Quat Quat::operator+() const {
		return *this;
	}

	Quat Quat::operator-() const {
		return Quat(-scalar, -vector);
	}

	Quat & Quat::operator+=(const Quat & rquat) {
		scalar += rquat.scalar;
		vector += rquat.vector;
		return *this;
	}

	Quat & Quat::operator-=(const Quat & rquat) {
		scalar -= rquat.scalar;
		vector -= rquat.vector;
		return *this;
	}

	Quat & Quat::operator*=(const Quat & rquat) {
		return (*this = Quat(
			scalar * rquat.scalar - Vector3::dot(vector, rquat.vector),
			scalar * rquat.vector + rquat.scalar * vector + Vector3::cross(vector, rquat.vector)
		));
	}

	Quat Quat::operator+(const Quat & rquat) const {
		Quat result = *this;

		return (result += rquat);
	}

	Quat Quat::operator-(const Quat & rquat) const {
		Quat result = *this;

		return (result -= rquat);
	}

	Quat Quat::operator*(const Quat & rquat) const {
		Quat result = *this;

		return (result *= rquat);
	}

}