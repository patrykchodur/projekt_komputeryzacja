#ifndef SPEAKER_HPP
#define SPEAKER_HPP

/*
Speaker synopsis

template <typename sound_len_t>
class Speaker {
public:
	typedef sound_len_t;

	Speaker(uint8_t pin);

	void set_sound(sound_len_t new_len);
	void set_sound_and_start(sound_len_t new_len);
	void start_playing();
	void stop_playing();
	void turn_on();
	void turn_off();
	// time elapsed since last update
	void update_state(sound_len_t elapsed);
	bool is_playing();
	bool is_playing_this(sound_len_t sound);
};


 */
#ifdef ARDUINO
	#include <TinkerKit.h>
#else
	#include "arduino_mock.hpp"
#endif

// entity representing speaker and sound its playing
template <typename SoundLengthType>
class Speaker {
public:
	using sound_len_t = SoundLengthType;
private:

	// sound length in any time measure
	// (for example miliseconds)
	//  _________       ______
	//  |       |       |
	// -|- - - -|- - - -|- - - 
	// _|       |_______|
	//
	//  <------->
	//   that length
	sound_len_t m_sound_length;
	// time elapsed since beginning
	// usefull to get stable frequency
	sound_len_t m_elapsed;
	// indicator whether speaker is on or of
	bool m_is_playing;
	// internal indicator whether relay is on
	// used only for switching it
	bool m_is_relay_on;
	// relay associated with physical speaker
	TKMosFet m_relay;

	void switch_relay() {
		if (!m_is_playing)
			return;
		if (m_is_relay_on) {
			m_relay.off();
			m_is_relay_on = false;
		}
		else {
			m_relay.on();
			m_is_relay_on = true;
		}
	}
public:

	explicit Speaker(uint8_t pin) : m_relay(pin) {
		m_relay.off();
		m_is_relay_on = false;
		m_is_playing = false;
		m_sound_length = ~static_cast<sound_len_t>(0);
	}
	void set_sound(sound_len_t new_len) {
		m_sound_length = new_len;
		m_elapsed = 0;
	}
	void set_sound_and_start(sound_len_t new_len) {
		set_sound(new_len);
		turn_on();
	}
	void start_playing() {
		turn_on();
	}
	void stop_playing() {
		turn_off();
	}
	void turn_on() {
		m_is_playing = true;
		m_elapsed = 0;
	}
	void turn_off() {
		m_is_playing = false;
	}
	// this function must be put in main loop
	// and get elapsed time since last update
	void update_state(sound_len_t elapsed) {
		m_elapsed += elapsed;
		if (m_elapsed > m_sound_length) {
			switch_relay();
			m_elapsed -= m_sound_length;
		}
	}
	bool is_playing() {
		return m_is_playing;
	}
	bool is_playing_this(sound_len_t sound) {
		return is_playing() && sound == m_sound_length;
	}
};


#endif // SPEAKER_HPP
