# include "../../inc/class/Player.hpp"

Player::Player()
{
	log( "Player::Player()", INFO );
	_camera.projection = CAMERA_PERSPECTIVE;
	_camera.position = { 0.0f, 0.0f, 0.0f };
	_camera.target = { 1.0f, 0.0f, 0.0f };
	_camera.fovy = PLAYER_FOV;
	_camera.up = { 0.0f, 1.0f, 0.0f };
}

Player::~Player()
{
	log( "Player::~Player()", INFO );
}

// ================================ ACCESSORS

Camera3D *Player::getCamera() { return &_camera; }

void Player::setPosition( Vector3 pos )
{
	_position = pos;
	_camera.position = _position; // NOTE : temporary
}
void Player::moveBy( Vector3 movement )
{
	_position.x += movement.x;
	_position.y += movement.y;
	_position.z += movement.z;

	_camera.position = _position; // NOTE : temporary
}

void Player::setTarget( Vector3 target ) { _camera.target = target; }
void Player::setDirection( Vector3 direction )
{
	_camera.target.x = _camera.position.x + direction.x;
	_camera.target.y = _camera.position.y + direction.y;
	_camera.target.z = _camera.position.z + direction.z;
}


void Player::setFOV( float fovy ) { _camera.fovy = fovy; }

Vector3 Player::getPosition() const { return _position; }
Vector3 Player::getDirection() const
{
	return (Vector3){
		_camera.target.x - _camera.position.x,
		_camera.target.y - _camera.position.y,
		_camera.target.z - _camera.position.z
	};
}
Vector3 Player::getTarget() const { return _camera.target; }

// ================================ CORE METHODS

void Player::update() // TODO : refactor this shit m8
{
	int run = 1;
	if( IsKeyDown( KEY_LEFT_CONTROL )){ run = 2; }

	UpdateCameraPro( &_camera,
		(Vector3){
			(IsKeyDown( KEY_W ) || IsKeyDown( KEY_UP ))	* MOVE_FACTOR * run -	// Move forward-backward
			(IsKeyDown( KEY_S ) || IsKeyDown( KEY_DOWN ))	* MOVE_FACTOR * run,

			(IsKeyDown( KEY_D ) || IsKeyDown( KEY_RIGHT ))	* MOVE_FACTOR * run -	// Move right-left
			(IsKeyDown( KEY_A ) || IsKeyDown( KEY_LEFT ))	* MOVE_FACTOR * run,

			(IsKeyDown( KEY_SPACE ) || IsKeyDown( KEY_RIGHT_CONTROL ))	* MOVE_FACTOR * run -	// Move up-down
			(IsKeyDown( KEY_LEFT_SHIFT ) || IsKeyDown( KEY_KP_0 ))		* MOVE_FACTOR * run
		},
		( Vector3 ){
			GetMouseDelta().x * TURN_FACTOR,	// Rotation: yaw
			GetMouseDelta().y * TURN_FACTOR,	// Rotation: pitch
			0.0f							// Rotation: roll
		},
		0.0f);	// Move to target (zoom)
}