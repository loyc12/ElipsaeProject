#ifndef BLOCKTYPE_HPP
# define BLOCKTYPE_HPP

# include "../libs.hpp"

typedef enum : byte_t
{
	AIR = 0,
	GRASS,
	DIRT,
	STONE,
	SAND,
	WATER,
	WOOD,
	LEAVES,

	BTYPE_COUNT
} vox_type_e;

#endif // BLOCKTYPE_HPP
