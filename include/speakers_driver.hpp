#ifndef SPEAKERS_DRIVER_HPP
#define SPEAKERS_DRIVER_HPP

/*
SpeakersDriver synopsis

template <int speakers_no, class speaker_type>
class SpeakersDriver {
public:
	typedef speaker_type;
	typedef sound_len_t;
	static constexpr int speakers_no;

	template <typename... T>
	SpeakersDriver(T... args);

	void update_state(sound_len_t elapsed);
	void start_sound(sound_len_t new_sound);
	void stop_sound(sound_len_t to_stop);

};

 */



template <int SpeakersNo, class SpeakerType>
class SpeakersDriver {
public:
	using speaker_type = SpeakerType;
	using sound_len_t = typename speaker_type::sound_len_t;
	static constexpr int speakers_no = SpeakersNo;

private:
	speaker_type m_speakers[speakers_no];

	// m_order_of_speakers[0] is first to play new sound
	int m_order_of_speakers[speakers_no];

	// returns speaker index which should be used
	// to play sound
	int get_first_speaker_to_use_index() {
		// first look for usused speaker
		for (int iter = 0; iter < speakers_no; iter++) {
			int index = m_order_of_speakers[iter];
			if (!m_speakers[index].is_playing())
				return index;
		}

		// return first one
		return m_order_of_speakers[0];
	}

	speaker_type& get_first_speaker_to_use() {
		return m_speakers[get_first_speaker_to_use_index()];
	}

	// index of speaker from m_speakers
	void set_as_last_speaker_to_use(int index) {
		if (index >= speakers_no || index < 0)
			*static_cast<volatile int*>(0) = 0;
		int iter = 0;
		while (m_order_of_speakers[iter] != index && iter < speakers_no)
			++iter;
		for (; iter < speakers_no - 1; iter++) {
			m_order_of_speakers[iter] = m_order_of_speakers[iter + 1];
		}
		m_order_of_speakers[speakers_no - 1] = index;
	}

	speaker_type& speaker(int index) {
		return m_speakers[m_order_of_speakers[index]];
	}


public:

	template <typename ...T>
	explicit SpeakersDriver(T... args) : m_speakers{speaker_type(args)...} { 
		for (int iter = 0; iter < speakers_no; iter++)
			m_order_of_speakers[iter] = iter;
	}

	void update_state(sound_len_t elapsed) {
		for (speaker_type& iter : m_speakers) {
			iter.update_state(elapsed);
		}
	}

	void start_sound(sound_len_t new_sound) {
		int index = get_first_speaker_to_use_index();
		m_speakers[index].set_sound_and_start(new_sound);
		set_as_last_speaker_to_use(index);
	}

	void stop_sound(sound_len_t to_stop) {
		for (int iter = 0; iter < speakers_no; iter++) {
			if (speaker(iter).is_playing_this(to_stop)) {
				speaker(iter).stop_playing();
				return;
			}
		}
	}


};



#endif // SPEAKERS_DRIVER_HPP
