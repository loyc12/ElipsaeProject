#ifndef NOISE_HPP
# define NOISE_HPP

#include "../libs.hpp"


class Noise
{
	public:

		Noise();
		Noise(int64_t seed);
		~Noise() = default;

		// The following functions return a value between -1 and 1.

		//2D Open Simplex Noise.
		double eval(const double x, const double y) const;
		//3D Open Simplex Noise.
		double eval(double x, double y, double z) const;
		//4D Open Simplex Noise.
		double eval(double x, double y, double z, double w) const;

	private:

		const double m_stretch2d;
		const double m_squish2d;
		const double m_stretch3d;
		const double m_squish3d;
		const double m_stretch4d;
		const double m_squish4d;

		const double m_norm2d;
		const double m_norm3d;
		const double m_norm4d;

		const long m_defaultSeed;

		std::array< short, 256 > m_perm;
		std::array< short, 256 > m_permGradIndex3d;
		std::array< char, 16 > m_gradients2d;
		std::array< char, 72 > m_gradients3d;
		std::array< char, 256 > m_gradients4d;

		double extrapolate( int xsb, int ysb, double dx, double dy ) const;
		double extrapolate( int xsb, int ysb, int zsb, double dx, double dy, double dz ) const;
		double extrapolate( int xsb, int ysb, int zsb, int wsb, double dx, double dy, double dz, double dw)	const;
};

Noise *getNoise();

double getNoiseValue( double x, double y );
double getNoiseValue( double x, double y, double z );
double getNoiseValue( double x, double y, double z, double w );

#endif // NOISE_HPP