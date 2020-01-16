#ifndef RECEIVER_HPP
#define RECEIVER_HPP

/*
SerialReceiver synopsis
class SerialReceiver {
public:
	explicit SerialReceiver(int baud_rate);
	int get_next();
	explicit operator bool();
};

MemoryReceiver synopsis
template <int number_of_lines>
class MemoryReceiver {
	explicit MemoryReceiver(const char* tab[number_of_lines]);
	explicit MemoryReceiver(const signed char* tab[number_of_lines]);

	int get_next();
	explicit operator bool();
};

 */

#ifndef ARDUINO
	#include "arduino_mock.hpp"
#endif // ARDUINO

class SerialReceiver {
public:
	explicit SerialReceiver(int rate) {
		Serial.begin(rate);
	}
	
	signed char get_next() {
		return Serial.read();
	}

	explicit operator bool() {
		return static_cast<bool>(Serial.available() > 0);
	}

};


// first byte of data is bpm
// data is in 1/32 notes
// data is null terminated
// 1 is hold on
// bpm is number of quarter notes in minute
// one receiver is for one line
template <int number_of_lines>
class MemoryReceiver {
	const signed char* m_data[number_of_lines];
	unsigned char m_bpm[number_of_lines];
	// next note to be played
	const signed char*  m_current_position[number_of_lines];
	long m_start;

	const signed char* position_in_time(int line, long elapsed_miliseconds) {
		return m_data[line] + (elapsed_miliseconds * m_bpm[line] * 8 / 60000L);
	}




public:

	explicit MemoryReceiver(const signed char* data[number_of_lines]) {
		m_start = -1;
		for (int iter = 0; iter < number_of_lines; iter++) {
			m_data[iter] = data[iter] + 1;
			m_bpm[iter] = *(data[iter]);
			m_current_position[iter] = m_data[iter];
		}

	}

	explicit MemoryReceiver(const char* _data[number_of_lines]) {
		const signed char* data[number_of_lines] = reinterpret_cast<const signed char* [number_of_lines]>(_data);
		for (int iter = 0; iter < number_of_lines; iter++) {
			m_data[iter] = data[iter] + 1;
			m_bpm[iter] = *(data[iter]);
			m_current_position[iter] = m_data[iter];
		}

	}

	signed char get_next() {
		if (m_start < 0)
			m_start = millis();
		bool finish = true;
		for (const signed char* iter : m_current_position)
			if(*iter) {
				finish = false;
				break;
			}
		if (finish)
			return -1;
		for (int iter = 0; iter < number_of_lines; iter++) {
			if (m_current_position[iter] < position_in_time(iter, millis() - m_start)) {
				return *(m_current_position[iter])++;
			}
		}
		return -1;
	}


	explicit operator bool() {
		for (int iter = 0; iter < number_of_lines; iter++)
			if (*m_current_position[iter] && m_current_position[iter] < 
					position_in_time(iter, millis() - m_start))
				return true;
		return false;
	}


};


#endif // RECEIVER_HPP
