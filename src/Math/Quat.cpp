#include "Math/Quat.h"

#include <cmath>

#include "Math/Matrix4.h"

namespace glwl {

	Quat::Quat(float scalar, Vector3 & vector) : scalar(scalar), vector(vector) {}

	Quat::Quat(float scalar, float x, float y, float z) : Quat(scalar, Vector3(x, y, z)) {}

	Quat::Quat(Vector3 & axis, float angle) {
		Vector3 norm = axis.getNormalize();
		angle *= PI / 180;

		scalar = std::cos(angle / 2);
		setVector(
			norm.getX() * std::sin(angle / 2),
			norm.getY() * std::sin(angle / 2),
			norm.getZ() * std::sin(angle / 2)
		);
	}

	Quat::Quat(Vector3 & angles) {
		Quat x(Vector3(1, 0, 0), angles.getX());
		Quat y(Vector3(0, 1, 0), angles.getY());
		Quat z(Vector3(0, 0, 1), angles.getZ());

		*this = z * y * x;
	}

	void Quat::setScalar(float scalar) {
		this->scalar = scalar;
	}

	void Quat::setVector(Vector3 & vector) {
		this->vector = vector;
	}

	void Quat::setVector(float x, float y, float z) {
		setVector(Vector3(x, y, z));
	}

	float Quat::getScalar() {
		return scalar;
	}

	Vector3 Quat::getVector() {
		return vector;
	}

	Quat Quat::getStar() {
		return Quat(scalar, -vector);
	}

	Matrix4 Quat::getMatrix() {
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

	Quat Quat::operator+() {
		return *this;
	}

	Quat Quat::operator-() {
		return Quat(-scalar, -vector);
	}

	Quat & Quat::operator+=(Quat & rquat) {
		scalar += rquat.scalar;
		vector += rquat.vector;
		return *this;
	}

	Quat & Quat::operator-=(Quat & rquat) {
		scalar -= rquat.scalar;
		vector -= rquat.vector;
		return *this;
	}

	Quat & Quat::operator*=(Quat & rquat) {
		return (*this = Quat(
			scalar * rquat.scalar - Vector3::dot(vector, rquat.vector),
			scalar * rquat.vector + rquat.scalar * vector + Vector3::cross(vector, rquat.vector)
		));
	}

	Quat Quat::operator+(Quat & rquat) {
		Quat result = *this;

		return (*this += rquat);
	}

	Quat Quat::operator-(Quat & rquat) {
		Quat result = *this;

		return (*this -= rquat);
	}

	Quat Quat::operator*(Quat & rquat) {
		Quat result = *this;

		return (*this *= rquat);
	}

}