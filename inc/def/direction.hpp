#ifndef DIRECTION_HPP
# define DIRECTION_HPP

# include "../libs.hpp"

typedef enum : byte_t
{
	NOD = 0,
	XPD = 1,
	XND = 2,
	ZPD = 3,
	ZND = 4,
	YPD = 5,
	YND = 6
} dir_e;

typedef enum : byte_t
{
	CEN = NOD,
	NOR = XPD,
	SOU = XND,
	EAS = ZPD,
	WES = ZND,
	TOP = YPD,
	BOT = YND
} side_e;

typedef enum : byte_t
{
	// Center
	MMM = 0,

	// Sides ( 6 )
	NMM = 1, // North
	SMM = 2, // South
	MEM = 3, // East
	MWM = 4, // West
	MMT = 5, // Top
	MMB = 6, // Bottom

	// Edges ( 12 )
	NEM = 13, // North East
	NWM = 14, // North West
	NMT = 15, // North Top
	NMB = 16, // North Bottom
	SEM = 23, // South East
	SWM = 24, // South West
	SMT = 25, // South Top
	SMB = 26, // South Bottom
	MET = 35, // East Top
	MEB = 36, // East Bottom
	MWT = 45, // West Top
	MWB = 46, // West Bottom

	// Corners ( 8 )
	NET = 135, // North East Top
	NEB = 136, // North East Bottom
	NWT = 145, // North West Top
	NWB = 146, // North West Bottom
	SET = 235, // South East Top
	SEB = 236, // South East Bottom
	SWT = 245, // South West Top
	SWB = 246, // South West Bottom

} vertex_e;

#endif // DIRECTION_HPP