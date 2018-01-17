#include <vector>
#include <list>
#include <math.h>
#include <time.h>

using namespace std;

namespace Physics {
	class Punto
	{
	public:
		Punto() :x(0), y(0), z(0) {};
		Punto(const Punto& other) : x(other.x), y(other.y), z(other.z) {};
		Punto(float x, float y, float z) : x(x), y(y), z(z) {};
		~Punto() {};

		inline float getX() const { return x; };
		inline float getY() const { return y; };
		inline float getZ() const { return z; };

		inline void setX(float nx) { x = nx; };
		inline void setY(float ny) { y = ny; };
		inline void setZ(float nz) { z = nz; };

		inline void set(float x_, float y_, float z_) { x = x_;	y = y_;	z = z_; };
		Punto operator+(const Punto& other) {
			return Punto(x + other.x, y + other.y, z + other.z);
		}

		Punto& operator+= (const Punto& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Punto operator*(const Punto& other) const
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
		Vector(const Vector& other) :x(other.x), y(other.y), z(other.z) {};

		Vector(Punto p0, Punto p1) {
			x = p1.getX() - p0.getX();
			y = p1.getY() - p0.getY();
			z = p1.getZ() - p0.getZ();
		}
		Vector(float x, float y, float z) : x(x), y(y), z(z) {};
		~Vector() {};


		//Getters and setters///////
		inline void setX(float a) { x = a; };
		inline void setY(float a) { y = a; };
		inline void setZ(float a) { z = a; };
		inline const float getX() const { return x; };
		inline const float getY() const { return y; };
		inline const float getZ() const { return z; };
		inline float getX() { return x; };
		inline float getY() { return y; };
		inline float getZ() { return z; };

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
		Vector& operator=(const Vector& other) {
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		float modulo() {
			return sqrt((x*x) + (y*y) + (z*z));
		}
		Vector& escalar(float escalar) {
			x *= escalar;
			y *= escalar;
			z *= escalar;
			return *this;
		}
		//Other methods
		void randomize(float maxX, float minX, float maxY, float minY, float maxZ, float minZ) {
			srand(time(0));
			x = minX + (((float)rand() / (float)RAND_MAX) * (maxX - minX));
			y = minY + (((float)rand() / (float)RAND_MAX) * (maxY - minY));
			z = minZ + (((float)rand() / (float)RAND_MAX) * (maxZ - minZ));
		}
	private:
		float x, y, z;
	};

	static Vector productoVectorial(const Vector& u, const Vector& v) {
		float wx = (u.getY() * v.getZ()) - (u.getZ() * v.getY());
		float wy = (u.getZ() * v.getX()) - (u.getX() * v.getZ());
		float wz = (u.getX() * v.getY()) - (u.getY() * v.getX());
		return Vector(wx, wy, wz);
	}

	class Plano {
	public:
		Plano(const Punto& p_, const Punto& q_, const Punto& r_) :
			p(p_), q(q_), r(r_),
			pq(Vector(p, q)), pr(Vector(p, r)), n(productoVectorial(pq, pr))
		{
			a = n.getX();
			b = n.getY();
			c = n.getZ();

			d = -(p.getX()) * n.getX();
			d += -(p.getY()) * n.getY();
			d += -(p.getZ()) * n.getZ();
		}

		Plano(const Vector& vNormal, const Punto& centro) {
			//A·(x-x0) + B·(y-y0) + C·(z-z0) = 0
			//nv.x * (x- c.x) + nv.y * (y - c.y) + nv*(z - c.z) = 0
			//a * x + b * y + c * z = d
			a = vNormal.getX();
			b = vNormal.getY();
			c = vNormal.getZ();
			d = vNormal.getX() * (-centro.getX()) + (vNormal.getY() * (-centro.getY())) + ( vNormal.getZ() * (-centro.getZ()));

			//x= 0, y = 0 z =-d/C
			p = Punto(0, 0, d / c);

			//x= 0, z = 0 y = -d/B
			q = Punto(0, d / b, 0);

			//y= 0, z = 0 x = -d/
			r = Punto(d / a, 0, 0);

			pq = Vector(p, q);
			pr = Vector(p, r);
			n = vNormal;



		}
		//Getters
		inline float getA() { return a; }
		inline float getB() { return b; }
		inline float getC() { return c; }
		inline float getD() { return d; }

		inline const Vector&	getPQ()		const { return pq; }
		inline const Vector&	getPR()		const { return pr; }
		inline const Punto&		getPunto()	const { return p; }
		inline const Vector&	getNormal()	const { return n; }

		inline Punto&	getPunto()	{ return p; }
		inline Vector&	getNormal()	{ return n; }


		void cambiarNormal(const Vector& newNormal, const Punto& centro) {
			a = newNormal.getX();
			b = newNormal.getY();
			c = newNormal.getZ();
			d = newNormal.getX() * (-centro.getX()) + (newNormal.getY() * (-centro.getY())) + (newNormal.getZ() * (-centro.getZ()));

			//x= 0, y = 0 z =-d/C
			p = Punto(0, 0, d / c);

			//x= 0, z = 0 y = -d/B
			q = Punto(0, d / b, 0);

			//y= 0, z = 0 x = -d/
			r = Punto(d / a, 0, 0);

			pq = Vector(p, q);
			pr = Vector(p, r);
			n = newNormal;
		}
	private:
		float a, b, c, d;
		Punto p;
		Punto q;
		Punto r;
		Vector pq;
		Vector pr;
		Vector n;
	};
	class Recta {
		Recta(Punto& p0, Punto& p1) : p(p0), v(Vector(p0, p1)) {};
		Recta(Punto& p, Vector& v) :p(p), v(v) {};
		Punto p;
		Vector v;
	};

	class Esfera {
	public:
		Esfera(Punto& centro, float radio) :centro(centro), radio(radio) {};
		~Esfera() {}
		inline const float getRadio()const { return radio; };
		inline float getRadio() { return radio; };
		inline const Punto& getCentro() const { return centro; };
		inline Punto& getCentro() { return centro; }
	private:
		float radio;
		Punto centro;
	};
	static Vector fuerzaResultante(std::list<Vector*> fuerzas) {
		float x, y, z;
		for (auto f : fuerzas) {
			x += f->getX();
			y += f->getY();
			z += f->getZ();
		}
		return Vector(x, y, z);
	}

	static double distanceBetweenPoints(const Punto& a, const Punto& b) {
		return abs(Vector(a, b).modulo());
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

	static double productoEscalar(Vector& u, Vector& v) {

		return ((u.getX() * v.getX()) + (u.getY() * v.getY()) + (u.getZ() * u.getZ()));
	}

	static double angleBetweenVectors(Vector& v, Vector& u) {
		return std::acos(productoEscalar(v, u) / (v.modulo() * u.modulo()));
	}

	template<class T>
	T clamp(T& value, T minCap, T maxCap) {
		if (value > maxCap) { value = maxCap; return maxCap; }
		if (value < minCap) { value = minCap; return minCap; };
		return value;
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
		static bool spheres(const Esfera& a, const Esfera& b) {
			double disMin = a.getRadio() + b.getRadio();
			return disMin >= distanceBetweenPoints(a.getCentro(), b.getCentro());
		}

		static bool sphereAndPlane(Esfera& s, Plano& p, Punto& outCollisionPoint) {
			float anglePlaneNormalAndSphereCenter =
				angleBetweenVectors(p.getNormal(), Vector(s.getCentro(), p.getPunto()));
			Vector s_p(s.getCentro(), p.getPunto());
			float maxAngle = asinf(s.getRadio() / s_p.modulo());
			if (anglePlaneNormalAndSphereCenter >= maxAngle) {
				//Need comprobation//////////////////////////////////
				float x = p.getNormal().getX() + s.getCentro().getX();
				float y = p.getNormal().getY() + s.getCentro().getY();
				float z = p.getNormal().getY() + s.getCentro().getY();
				outCollisionPoint = Punto(x, y, z);
				/////////////////////////////////////////////////////
				return true;
			}
			return false;
		}

	}
}