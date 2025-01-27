#include "../../inc/class/ViewPort.hpp"

void	drawInfoBox( Camera2D *camera )
{
	static int line_count = 1;
	static int box_x = 5;
	static int box_y = 5;
	static int box_width = 420;
	static int box_height = ( int )(( 1.0f + line_count ) * DEBUG_FONT_SIZE);

	DrawRectangle(      box_x, box_y, box_width, box_height, Fade( GREEN, 0.5f ));
	DrawRectangleLines( box_x, box_y, box_width, box_height, BLACK );

	DrawText( TextFormat( "- Camera Pos : (%06.3f, %06.3f, %06.3f)", camera->target.x, camera->target.y ), 15, 15, DEBUG_FONT_SIZE, BLACK );
}

ViewPort::ViewPort()
{
	log( "ViewPort::ViewPort(1)", DEBUG );

	_center = { 0, 0 };
	_zoom = 1.0f;

	updateField();
	updateCamera();
}

ViewPort::ViewPort( ViewPort &other )
{
	_camera = *other.getCamera(); // clones the source camera
	_field = other.getField();
	_center = other.getCenter();
	_zoom = other.getZoom();
}

ViewPort &ViewPort::operator=( ViewPort &other )
{
	_camera = *other.getCamera(); // clones the source camera
	_field = other.getField();
	_center = other.getCenter();
	_zoom = other.getZoom();

	return *this;
}

ViewPort::~ViewPort() {}

void	ViewPort::setCamera( Camera2D *camera ) { _camera = *camera; }
void	ViewPort::setCenter( Vector2 pos ) { _center = pos; }
void	ViewPort::setZoom( float zoom ) { _zoom = zoom; }

Camera2D	*ViewPort::getCamera() { return &_camera; }
Rectangle	ViewPort::getField() const { return _field; }
Vector2		ViewPort::getCenter() const { return _center; }
float			ViewPort::getZoom() const { return _zoom; }

void ViewPort::setFieldByCenter( Vector2 pos, Vector2 sizes )
{
	_field = { pos.x - sizes.x / 2, pos.y - sizes.y / 2, sizes.x, sizes.y };
}

void ViewPort::setFieldByCorners( Vector2 pos1, Vector2 pos2 )
{
 _center = { ( pos1.x + pos2.x ) / 2, ( pos1.y + pos2.y ) / 2 };
 _field = { _center.x, _center.y, abs( pos1.x - pos2.x ), abs( pos1.y - pos2.y ) };
}

void ViewPort::updateField()
{
	_field = { _center.x - GetScreenWidth() / _zoom / 2, _center.y - GetScreenHeight() / _zoom / 2, GetScreenWidth() / _zoom, GetScreenHeight() / _zoom };
}

void ViewPort::updateCamera()
{
	_camera.target = { _center.x, _center.y };
	_camera.rotation = 0.0f;
	_camera.offset = { 0, 0 };
	_camera.zoom = _zoom;
}

void ViewPort::updateSelf()
{
	updateField();
	updateCamera();
}

void ViewPort::drawFromField()
{
	// TODO : draw shit here

	drawInfoBox( &_camera );
}