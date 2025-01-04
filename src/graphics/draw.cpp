#include "../../inc/gfx/draw.hpp"

void	drawInfoBox( Camera *camera )
{
	static int line_count = 2;
	static int box_x = 5;
	static int box_y = 5;
	static int box_width = 420;
	static int box_height = ( int )(( 1.5f + line_count ) * DEBUG_FONT_SIZE);

	DrawRectangle(      box_x, box_y, box_width, box_height, Fade( GREEN, 0.5f ));
	DrawRectangleLines( box_x, box_y, box_width, box_height, BLACK );

	DrawText( TextFormat( "- Cam Pos : (%06.3f, %06.3f, %06.3f)",    camera->position.x, camera->position.y, camera->position.z ), 15, 15, DEBUG_FONT_SIZE, BLACK );
	DrawText( TextFormat( "- Target Pos : (%06.3f, %06.3f, %06.3f)", camera->target.x, camera->target.y, camera->target.z ),       15, 40, DEBUG_FONT_SIZE, BLACK );
}