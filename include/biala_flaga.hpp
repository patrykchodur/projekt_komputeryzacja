#ifndef BIALA_FLAGA_HPP
#define BIALA_FLAGA_HPP

#include "converter.hpp"

#include "notes.hpp"
// NOTE(note, nominator, denominator)
// WARNING!!!
// you cannot switch notes on single track
// switching note off requires 1/32
// you have to remember about 1/32 delay after each switch off
// or use 15/32 instead of a half note

// one node is 1/32 note
using namespace Sounds;

static signed char bf_data0[] = {static_cast<signed char>(138), 
	NOTE(D + octave, 11, 32) NOTE(D + octave, 3, 32) NOTE(F + octave, 11, 32) NOTE(F + octave, 3, 32)
	NOTE(C + octave, 11, 32) NOTE(C + octave, 3, 32) NOTE(Gs , 7, 32) NOTE (Gs, 7, 32)
	NOTE(D + octave, 11, 32) NOTE(D + octave, 3, 32) NOTE(F + octave, 11, 32) NOTE(F + octave, 3, 32)
	NOTE(C + octave, 11, 32) NOTE(C + octave, 3, 32) NOTE(Gs , 7, 32) NOTE (Gs, 7, 32)
	0,
};
static signed char bf_data1[] = {static_cast<signed char>(138), 
	NOTE(D + octaves(2), 11, 32) NOTE(D + octaves(2), 3, 32) NOTE(F + octaves(2), 11, 32) NOTE(F + octaves(2), 3, 32)
	NOTE(C + octaves(2), 11, 32) NOTE(C + octaves(2), 3, 32) NOTE(Gs + octave , 7, 32) NOTE (Gs + octave, 7, 32)
	NOTE(D + octaves(2), 11, 32) NOTE(D + octaves(2), 3, 32) NOTE(F + octaves(2), 11, 32) NOTE(F + octaves(2), 3, 32)
	NOTE(C + octaves(2), 11, 32) NOTE(C + octaves(2), 3, 32) NOTE(Gs + octave , 7, 32) NOTE (Gs + octave, 7, 32)
	0,
};
static signed char bf_data2[] = {static_cast<signed char>(138), 
	HOLD(7, 32)  NOTE(F + octaves(3), 3, 32) NOTE(D + octaves(3), 3, 32) HOLD(7, 32)  NOTE(A + octaves(3), 3, 32) NOTE(F + octaves(3), 3, 32)
	HOLD(7, 32)  NOTE(E + octaves(3), 3, 32) NOTE(C + octaves(3), 3, 32) HOLD(3, 32) NOTE(Gs + octaves(2), 3, 32) HOLD(3, 32) NOTE(Gs + octaves(2), 3, 32)
	HOLD(7, 32)  NOTE(F + octaves(3), 3, 32) NOTE(D + octaves(3), 3, 32) HOLD(7, 32)  NOTE(A + octaves(3), 3, 32) NOTE(F + octaves(3), 3, 32)
	HOLD(7, 32)  NOTE(E + octaves(3), 3, 32) NOTE(C + octaves(3), 3, 32) HOLD(3, 32) NOTE(Gs + octaves(2), 3, 32) HOLD(3, 32) NOTE(Gs + octaves(2), 3, 32)
	0,
};
static signed char bf_data3[] = {static_cast<signed char>(138), 
	HOLD(7, 32)  NOTE(A + octaves(3), 3, 32) HOLD(3, 32) HOLD(7, 32)  NOTE(C + octaves(4), 3, 32) HOLD(3, 32) 
	HOLD(7, 32)  NOTE(G + octaves(3), 3, 32) HOLD(3, 32) HOLD(3, 32) NOTE(D + octaves(3), 3, 32) HOLD(3, 32) NOTE(C + octaves(3), 3, 32)
	HOLD(7, 32)  NOTE(A + octaves(3), 3, 32) HOLD(3, 32) HOLD(7, 32)  NOTE(C + octaves(4), 3, 32) HOLD(3, 32) 
	HOLD(7, 32)  NOTE(G + octaves(3), 3, 32) HOLD(3, 32) HOLD(3, 32) NOTE(D + octaves(3), 3, 32) HOLD(3, 32) NOTE(C + octaves(3), 3, 32)
	0,
};

static const signed char* biala_flaga[4] = {bf_data0, bf_data1, bf_data2, bf_data3};



#endif
