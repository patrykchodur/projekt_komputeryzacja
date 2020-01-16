#if !defined(ARDUINO_MOCK_HPP) && !defined(ARDUINO)
#define ARDUINO_MOCK_HPP

#include <stdint.h>

struct TKMosFet {
	TKMosFet(uint8_t pin) { }
	void on() { }
	void off() { }
};

constexpr int O0 = 0;
constexpr int O1 = 1;
constexpr int O2 = 2;
constexpr int O3 = 3;
constexpr int O4 = 4;
constexpr int O5 = 5;
constexpr int O6 = 6;
constexpr int O7 = 7;


#ifndef ARDUINO

#include <chrono>

#ifdef DEBUG
#include <iostream>
#endif


struct SerialMock {
	char tab[2] = {33, 34,};
	char* ptr = tab;
	void begin(int) { }
	int available() {
		int result = sizeof(tab)/sizeof(char) - (ptr - tab);
		result = result > 0 ? result : 0;
		return result;
	}
	int read() { return available() ? *ptr++ : -1; }
	int print(const char*) { return 0; }
	template <typename... T>
	int println(T... args) { return 0; }
	explicit operator bool() {
		return available() > 0;
	}
};

static SerialMock Serial;


long millis() {
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (
			std::chrono::system_clock::now().time_since_epoch()
			);
	return ms.count();
}

#endif // ARDUINO


#endif // ARDUINO_MOCK_HPP
