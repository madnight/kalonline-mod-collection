/*
	---------------------------------------------------------------------------
	Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>, Germany.
	All rights reserved.

	Distributed under the terms of the GNU General Public License v2.

	This software is provided 'as is' with no explicit or implied warranties
	in respect of its properties, including, but not limited to, correctness 
	and/or fitness for purpose.
	---------------------------------------------------------------------------
*/

#include "sizehash.h"

void sizehash32_begin(unsigned long *uHashCtx)
{
	*uHashCtx = 0;
}

void sizehash32_hash(unsigned long *uHashCtx, unsigned long uBufferLen)
{
	*uHashCtx += uBufferLen;
}

void sizehash32_end(unsigned long *uHashCtx)
{
}
