#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "speaker.hpp"
#include "speakers_driver.hpp"
#include "converter.hpp"
#include "receiver.hpp"


template <int SpeakersNo, class Receiver, typename SoundLengthType = long>
class Player {
public:
	using sound_len_t = SoundLengthType;
	using speaker_type = Speaker<sound_len_t>;
	static constexpr int speakers_no = SpeakersNo;
	using receiver_type = Receiver;

private:
	SpeakersDriver<speakers_no, speaker_type> m_driver;
	receiver_type m_receiver;

	void start_sound(sound_len_t new_sound) {
#ifdef DEBUG
		std::cout << "Starting sound: " << new_sound << std::endl;
#endif
		m_driver.start_sound(new_sound);
	}
	void stop_sound(sound_len_t to_stop) {
#ifdef DEBUG
		std::cout << "Stopping sound: " << to_stop << std::endl;
#endif
		m_driver.stop_sound(to_stop);
	}

public:

	template <typename ...T>
	explicit Player(Receiver rec, T... args) : m_driver(args...),
			m_receiver(rec) { 
		
	}

	void loop() {
		unsigned long start = micros();
		while(1) {
			while (m_receiver) {
				signed char tmp = m_receiver.get_next();
				if (tmp >= 32)
					start_sound(convert_to_len_1(tmp));
				else if (tmp <= -32)
					stop_sound(convert_to_len_1(tmp));

			}
			unsigned long elapsed = micros() - start;
			start = start + elapsed;

			m_driver.update_state(elapsed);
		}
	}

};




#endif // PLAYER_HPP
