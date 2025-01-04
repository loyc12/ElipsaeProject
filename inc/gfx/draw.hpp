#ifndef RENDER_HPP
# define RENDER_HPP

# include "../deps.hpp"
# include "../class/Orbiter.hpp"

#define XPC PINK
#define XNC RED
#define ZPC YELLOW
#define ZNC GREEN
#define YPC BLUE
#define YNC VIOLET
#define NOC WHITE

#define BKGRND { 32, 32, 32, 255 }
#define DRAW_FACES_OUTLINES false


bool shouldDrawFace( vox_type_e src, vox_type_e dst, dir_e dir );
Color getColour( vox_type_e type, dir_e dir );
Vector3 getNormal( dir_e dir );
// textureID getTextureID( vox_type_e type, dir_e dir );

void drawVoxel( pos3_s voxelPos, Orbiter *c );
void drawFace( float x, float y, float z, vox_type_e type, dir_e dir ); // TODO : add shade based on dir, and set colour based on vox_type
void drawFace( int x, int y, int z, vox_type_e type, dir_e dir );
void drawFace( Vector3 voxelPos, vox_type_e type, dir_e dir );
void drawFace( pos3_s voxelPos, vox_type_e type, dir_e dir );

void drawInfoBox( Camera *camera );

#endif // RENDER_HPP