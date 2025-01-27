#ifndef ORBITER_HPP
# define ORBITER_HPP

# include "../deps.hpp"

class World;

class Orbiter
{
	private:

	Vector2 _orbiterPos;
	string _posStr;

	bool _isGenerated; // Whether the orbiter mesh is up to date
	bool _isActivated; // Whether the orbiter is currently visible


	public:

	// ================================ CONSTRUCTORS
	Orbiter();
	Orbiter( Vector2 orbiterPos );
	Orbiter( const Orbiter &other );
	Orbiter &operator=( const Orbiter &other );
	~Orbiter();

	// ================================ ACCESSORS

	World *getWorld() const;
	Vector2 getOrbiterPos() const;
	string getOrbiterPosString();
	string getOrbiterPosSentence( const char* str);

	void setOrbiterPos( int x, int y );

	// ================================ BOOLEAN METHODS

	bool isGenerated() const;
	bool isActivated() const;

	// ================================ CORE METHODS

	bool initiate();
	bool generate();
	bool activate();
	bool deactivate();

	void drawSelf();
};


#endif // ORBITER_HPP