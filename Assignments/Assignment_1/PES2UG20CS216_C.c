#include "PES2UG20CS216_H.h"
int main()
{
    LIST spm;
    initlist(&spm);
	LISTM move;
	initlistm(&move);
	read(&spm);
	movement(&spm,&move);
	display(&move);
	return 0;
}
