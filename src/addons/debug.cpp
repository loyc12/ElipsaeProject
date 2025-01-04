#include "../../inc/deps.hpp"

int log( const char *msg, log_level_e lvl )
{
	if ( lvl > LOG_LVL ) return 1;

	string	time_str = get_time_str();
	const char *time = time_str.c_str();

	switch ( lvl )
	{
		case DEBUG:
			cout << time << " " << CLR_BLU << "[DEBUG] " << CLR_RST << msg << endl;
			break;

		case INFO:
			cout << time << " " << CLR_GRN << "[INFO]  " << CLR_RST << msg << endl;
			break;

		case WARN:
			cout << time << " " << CLR_YEL << "[WARN]  " << CLR_RST << msg << endl;
			break;

		case ERROR:
			cout << time << " " << CLR_RED << "[ERROR] " << CLR_RST << msg << endl;
			break;

		default:
			cout << time << " " << CLR_MAG << "[????]  " << CLR_RST << msg << endl;
			break;
	}
	return 0;
}

bool divtest( byte_t d )
{
	if ( d == 0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	return false;
}

bool divtest( word_t d )
{
	if ( d == 0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	return false;
}

bool divtest( short d )
{
	if ( d == 0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	return false;
}

bool divtest( int d )
{
	if ( d == 0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	return false;
}

bool divtest( long d )
{
	if ( d == 0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	return false;
}

bool divtest( float d )
{
	if ( d == 0.0f )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	if ( d == NAN )
	{
		log( "Trying to divide a pos3 by NAN", ERROR );
		return true;
	}
	if ( d == INFINITY )
	{
		log( "Trying to divide a pos3 by INFINITY", ERROR );
		return true;
	}
	if ( d == -INFINITY )
	{
		log( "Trying to divide a pos3 by -INFINITY", ERROR );
		return true;
	}
	return false;
}

bool divtest( double d )
{
	if ( d == 0.0 )
	{
		log( "Trying to divide by zero", ERROR );
		return true;
	}
	if ( d == NAN )
	{
		log( "Trying to divide a pos3 by NAN", ERROR );
		return true;
	}
	if ( d == INFINITY )
	{
		log( "Trying to divide a pos3 by INFINITY", ERROR );
		return true;
	}
	if ( d == -INFINITY )
	{
		log( "Trying to divide a pos3 by -INFINITY", ERROR );
		return true;
	}
	return false;
}