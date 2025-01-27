#ifndef VIEWPORT_HPP
# define VIEWPORT_HPP

# include "../deps.hpp"
# include "../class/Orbiter.hpp"


#define BKGRND { 32, 32, 32, 255 }
#define DRAW_FACES_OUTLINES false


void drawInfoBox( Camera2D *camera );

class ViewPort
{
	private:
		Camera2D	_camera;
		Rectangle	_field;
		Vector2		_center;
		float			_zoom;

		void setFieldByCenter(  Vector2 pos, Vector2 sizes );
		void setFieldByCorners( Vector2 pos1, Vector2 pos2 );

	public:
		ViewPort();
		ViewPort( ViewPort &other );
		ViewPort &operator=( ViewPort &other );
		~ViewPort();

		void setCamera( Camera2D *camera );
		void setCenter( Vector2 pos );
		void setZoom( float zoom );

		Camera2D	*getCamera();
		Rectangle	getField() const;
		Vector2		getCenter() const;
		float			getZoom() const;

		void updateField();
		void updateCamera();
		void updateSelf();

		void drawFromField();
};


#endif // VIEWPORT_HPP