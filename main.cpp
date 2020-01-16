#ifndef ARDUINO

void setup();
void loop();

int main() {
	setup();
	while (1) loop();
}

#endif // !ARDUINO

// #define DEBUG

#include "player.hpp"
#include "biala_flaga.hpp"

MemoryReceiver<4> rec(biala_flaga);
Player<4, MemoryReceiver<4>, unsigned long> player(rec, O0, O1, O2, O3);




void setup() {

	player.loop();



}


void loop() {


}
