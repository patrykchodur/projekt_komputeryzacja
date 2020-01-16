#ifndef NOTES_HPP
#define NOTES_HPP

#define _NOTE_BEGIN(x) (x),
#define _NOTE_END(x) -(x),

#define _NOTE_32 1,
#define _NOTE_16 1, 1, 
#define _NOTE_8  1, 1, 1, 1,
#define _NOTE_4  1, 1, 1, 1, 1, 1, 1, 1, 
#define _NOTE_2  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 

#define _NOTE_32_F
#define _NOTE_16_F 1, 
#define _NOTE_8_F 1, 1, 1,
#define _NOTE_4_F 1, 1, 1, 1, 1, 1, 1, 
#define _NOTE_2_F 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 

#define _1_NOTE_INTERIOR(denom) _NOTE_ ## denom ## _F
#define _2_NOTE_INTERIOR(denom) _1_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _3_NOTE_INTERIOR(denom) _2_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _4_NOTE_INTERIOR(denom) _3_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _5_NOTE_INTERIOR(denom) _4_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _6_NOTE_INTERIOR(denom) _5_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _7_NOTE_INTERIOR(denom) _6_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _8_NOTE_INTERIOR(denom) _7_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _9_NOTE_INTERIOR(denom) _8_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _10_NOTE_INTERIOR(denom) _9_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _11_NOTE_INTERIOR(denom) _10_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _12_NOTE_INTERIOR(denom) _11_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _13_NOTE_INTERIOR(denom) _12_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _14_NOTE_INTERIOR(denom) _13_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _15_NOTE_INTERIOR(denom) _14_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _16_NOTE_INTERIOR(denom) _15_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _17_NOTE_INTERIOR(denom) _16_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _18_NOTE_INTERIOR(denom) _17_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _19_NOTE_INTERIOR(denom) _18_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _20_NOTE_INTERIOR(denom) _19_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _21_NOTE_INTERIOR(denom) _20_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _22_NOTE_INTERIOR(denom) _21_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _23_NOTE_INTERIOR(denom) _22_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _24_NOTE_INTERIOR(denom) _23_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _25_NOTE_INTERIOR(denom) _24_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _26_NOTE_INTERIOR(denom) _25_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _27_NOTE_INTERIOR(denom) _26_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _28_NOTE_INTERIOR(denom) _27_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _29_NOTE_INTERIOR(denom) _28_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _30_NOTE_INTERIOR(denom) _29_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _31_NOTE_INTERIOR(denom) _30_NOTE_INTERIOR(denom) _NOTE_ ## denom
#define _32_NOTE_INTERIOR(denom) _31_NOTE_INTERIOR(denom) _NOTE_ ## denom

#define NOTE(note, nom, denom) _NOTE_BEGIN(note) _ ## nom ## _NOTE_INTERIOR(denom) _NOTE_END(note)
#define HOLD(nom, denom) NOTE(1, nom, denom)


#endif // NOTES_HPP
