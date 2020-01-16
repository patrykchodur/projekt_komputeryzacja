#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#ifndef OCTAVE_OFFSET
	#define OCTAVE_OFFSET 0
#endif 

template <typename T, typename R>
inline T safe_shift(T left, R right) {
	return right < 0 ? left >> -right : left << right;
}

namespace Sounds {
	constexpr signed char C = 32;
	constexpr signed char Cs = C + 1;
	constexpr signed char D = C + 2;
	constexpr signed char Ds = C + 3;
	constexpr signed char E = C + 4;
	constexpr signed char F = C + 5;
	constexpr signed char Fs = C + 6;
	constexpr signed char G = C + 7;
	constexpr signed char Gs = C + 8;
	constexpr signed char A = C + 9;
	constexpr signed char As = C + 10;
	constexpr signed char B = C + 11;
	constexpr signed char C2 = C + 12;

	constexpr signed char octave = 12;
	constexpr signed char octaves(int numb) {
		return numb * octave;
	}
}



// signal length devided by 2 in microseconds
// 500 000 -      1 Hz 
//  50 000 -     10 Hz
//   5 000 -    100 Hz
//     500 -  1 000 Hz
//      50 - 10 000 Hz 
template <typename input_type>
static unsigned long convert_to_len_1(input_type input) {
	signed char sound = static_cast<signed char>(input);
	if (sound < 0)
		sound = -sound;

	// sound += 12 * number_of_octaves_higher

	switch (sound) {
		case Sounds::C:
			return (safe_shift(3822, OCTAVE_OFFSET));
		case Sounds::Cs:
			return (safe_shift(3608, OCTAVE_OFFSET));
		case Sounds::D:
			return (safe_shift(3405, OCTAVE_OFFSET));
		case Sounds::Ds:
			return (safe_shift(3214, OCTAVE_OFFSET));
		case Sounds::E:
			return (safe_shift(3034, OCTAVE_OFFSET));
		case Sounds::F:
			return (safe_shift(2863, OCTAVE_OFFSET));
		case Sounds::Fs:
			return (safe_shift(2703, OCTAVE_OFFSET));
		case Sounds::G:
			return (safe_shift(2551, OCTAVE_OFFSET));
		case Sounds::Gs:
			return (safe_shift(2408, OCTAVE_OFFSET));
		case Sounds::A:
			return (safe_shift(2273, OCTAVE_OFFSET));
		case Sounds::As:
			return (safe_shift(2145, OCTAVE_OFFSET));
		case Sounds::B:
			return (safe_shift(2025, OCTAVE_OFFSET));
		case Sounds::C2:
			return (safe_shift(1911, OCTAVE_OFFSET));
		default:
			{
				if (sound > Sounds::C2) {
					return 2 * convert_to_len_1(sound - static_cast<signed char>(12));
				}
				return ~(0L);
			}
	}
	return ~(0L);
}



#endif // CONVERTER_HPP
