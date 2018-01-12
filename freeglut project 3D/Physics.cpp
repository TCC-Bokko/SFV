//#include "PuntoVector3D.h"
#include <vector>
#include <math.h>

using namespace std;

namespace Physics {
	class Punto
	{
	public:
		Punto() :x(0), y(0), z(0) {};
		Punto(Punto& other) {
			x = other.x;
			y = other.y;
			z = other.z;
		};
		Punto(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		};
		~Punto() {};

		inline float getX() const { return x; };
		inline float getY() const { return y; };
		inline float getZ() const { return z; };

		inline void set(const float x_, const float y_, const float z_)
		{
			x = x_;
			y = y_;
			z = z_;
		}
		Punto operator+(const Punto& other) {
			return Punto(x + other.x, y + other.y, z + other.z);
		}
		Punto& operator += (const Punto& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Punto operator*(Punto& other)
		{
			return Punto(x * other.x, y * other.y, z * other.z);
		}
		Punto& operator*=(Punto& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

	private:
		float x, y, z;
	};

	class Vector
	{
	public:
		Vector() :x(0), y(0), z(0) {};
		Vector(const Vector& other) {
			x = other.x;
			y = other.y;
			z = other.z;
		};
		Vector(Punto p0, Punto p1) {
			x = p1.getX() - p0.getX();
			y = p1.getY() - p0.getY();
			z = p1.getZ() - p0.getZ();
		}
		Vector(const float x, const float y, const float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		};
		~Vector() {};

		//Getters and setters///////
		inline float getX() { return x; };
		inline float getY() { return z; };
		inline float getZ() { return y; };

		//Operations///////////////
		Vector operator+(const Vector& other) {
			return Vector(x + other.x, y + other.y, z + other.z);
		}
		Vector& operator+=(const Vector& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
		Vector& operator*=(const float escalar) {
			x *= escalar;
			y *= escalar;
			z *= escalar;
			return *this;
		}
		float modulo() {
			return sqrt((x*x) + (y*y) + (z*z));
		}

	private:
		float x, y, z;
	};

	static Vector productoVectorial(Vector* u, Vector* v) {
		float wx = (u->getY() * v->getZ()) - (u->getZ() * v->getY());
		float wy = (u->getZ() * v->getX()) - (u->getX() * v->getZ());
		float wz = (u->getX() * v->getY()) - (u->getY() * v->getX());
		return Vector(wx, wy, wz);
	}

	class Plano {
	public:
		Plano(Punto* p_, Punto* q_, Punto* r_) :p(p_), q(q_), r(r_)
		{
			pq = new Vector(*p, *q);
			pr = new Vector(*p, *r);
			n = &productoVectorial(pq, pr);

			a = n->getX();
			b = n->getY();
			c = n->getZ();

			d = -(p->getX()) * n->getX();
			d += -(p->getY()) * n->getY();
			d += -(p->getZ()) * n->getZ();
		}
		//Getters
		inline const float getA() { return a; }
		inline const float getB() { return b; }
		inline const float getC() { return c; }
		inline const float getD() { return d; }

		inline Vector	getPQ()		const { return *pq; }
		inline Vector	getPR()		const { return *pr; }
		inline Punto	getPunto()	const { return *p; }
		inline Vector	getNormal()	const { return *n; }

	private:
		float a, b, c, d;
		Punto* p;
		Punto* q;
		Punto* r;
		Vector* pq;
		Vector* pr;
		Vector* n;

	};
	class Recta {
		Recta(Punto* p0, Punto* p1) {
			this->p = p0;
			this->v = new Vector(*p0, *p1);
		};
		Recta(Punto* p, Vector* v) {
			this->p = p;
			this->v = v;
		};
		Punto* p;
		Vector* v;
	};

	class Esfera {
	public:
		Esfera(Punto* centro, float radio) {
			this->centro = centro;
			this->radio = radio;
		};
		~Esfera() {}

		float radio;
		Punto* centro;
	};
	static Vector fuerzaResultante(std::vector<Vector*> fuerzas) {
		float x, y, z;
		for (auto f : fuerzas) {
			x += f->getX();
			y += f->getY();
			z += f->getZ();
		}
		return Vector(x, y, z);
	}

	static double distanceBetweenPoints(Punto* a, Punto* b) {
		return abs(a - b);
	}
	static double distancePoint2Plane(Punto* p, Plano* pl) {
		double num = abs(
			(pl->getA() * p->getX()) +
			(pl->getB() * p->getY()) +
			(pl->getC() * p->getZ()) +
			pl->getD()
		);
		float den = pl->getNormal().modulo();
		return num / den;
	}

	static double productoEscalar(Vector* u, Vector* v) {
		float resul = u->getX() * v->getX();
		resul += u->getY() * v->getY();
		resul += u->getZ() * u->getZ();
		return resul;
	}

	static double angleBetweenVectors(Vector* v, Vector* u) {
		return std::acos(productoEscalar(v, u) / (v->modulo()*u->modulo()));
	}
	template <class T>
	T determinante3x3(T det[3][3]) {
		T result = 0;
		result += det[0][0] * det[1][1] * det[2][2];
		result += det[1][0] * det[2][1] * det[0][2];
		result += det[0][1] * det[2][1] * det[2][0];
		result -= det[0][2] * det[1][1] * det[2][0];
		result -= det[0][1] * det[1][0] * det[2][2];
		result -= det[1][2] * det[2][1] * det[0][0];
		return result;
	}
	template<class T>
	T determinante2x2(T det[2][2]) {
		return (det[0][1]) - (det[1][0]);
	}
	namespace Collisions {
		static bool spheres(Esfera* a, Esfera* b) {
			double disMin = a->radio + b->radio;
			return disMin >= distanceBetweenPoints(a->centro, b->centro);
		}

		static bool sphereAndPlane(Esfera* s, Plano* p) {
			return s->radio > distancePoint2Plane(s->centro, p);
		}

	}
}