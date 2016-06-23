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

#ifndef ___SIZEHASH_H___
#define ___SIZEHASH_H___

void sizehash32_begin(unsigned long *uHashCtx);
void sizehash32_hash(unsigned long *uHashCtx, unsigned long uBufferLen);
void sizehash32_end(unsigned long *uHashCtx);

#endif // ___SIZEHASH_H___
