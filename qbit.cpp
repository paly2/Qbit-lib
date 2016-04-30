#include <vector>
#include <cmath>
#include <random>
#include "qbit.h"

using namespace std;

Qbit::Qbit(STATE State) {
	state.push_back(State);
}
Qbit::Qbit(vState State) {
	state = State;
}

void Qbit::set_state(vState new_state) {
	state = new_state;
}

vState Qbit::get_state() const {
	return state;
}

void Qbit::add_state(STATE new_state) {
	state.push_back(new_state);
}

// A human is not (yet?) capable to determine what state will appear if he looks at a qbit, so he says it's random. Well, this function returns a (pseudo-)random state. However, I am sure it's not really random, it's only random *for a human*. I don't think true random exists anywhere.
STATE Qbit::read() const {
	random_device rd;
	return state[rd() % state.size()];
}

Qbit& Qbit::operator|=(Qbit const& qbit) {
	vState new_state;
	const vState state2 = qbit.get_state();
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		for (vState::const_iterator it2 = state2.begin() ; it2 != state2.end() ; it2++) {
			new_state.push_back((*it == HIGH || *it2 == HIGH) ? HIGH : LOW);
		}
	}
	state = new_state;
	
	return *this;
}
Qbit& Qbit::operator&=(Qbit const& qbit) {
	vState new_state;
	const vState state2 = qbit.get_state();
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		for (vState::const_iterator it2 = state2.begin() ; it2 != state2.end() ; it2++) {
			new_state.push_back((*it == HIGH && *it2 == HIGH) ? HIGH : LOW);
		}
	}
	state = new_state;
	
	return *this;
}
Qbit& Qbit::operator^=(Qbit const& qbit) {
	vState new_state;
	const vState state2 = qbit.get_state();
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		for (vState::const_iterator it2 = state2.begin() ; it2 != state2.end() ; it2++) {
			new_state.push_back((*it == HIGH ^ *it2 == HIGH) ? HIGH : LOW);
		}
	}
	state = new_state;
	
	return *this;
}

Qbit operator|(Qbit const &qbit1, Qbit qbit2) {
	return qbit2 |= qbit1;
}
Qbit operator&(Qbit const& qbit1, Qbit qbit2) {
	return qbit2 &= qbit1;
}
Qbit operator^(Qbit const& qbit1, Qbit qbit2) {
	return qbit2 ^= qbit1;
}

Qbit operator!(Qbit const& qbit) {
	Qbit new_qbit;
	const vState state = qbit.get_state();
	for (vState::const_iterator it = state.begin() ; it != state.end() ; it++) {
		new_qbit.add_state((*it == HIGH) ? LOW : HIGH);
	}
	
	return new_qbit;
}


ostream& operator<<(ostream &stream, const Qbit& qbit) {
	stream << (qbit.read() == HIGH) ? '1' : '0';
	return stream;
}

bool Qbit::all_high() {
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		if (*it == LOW)
			return false;
	}
	return true;
}
bool Qbit::all_low() {
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		if (*it == HIGH)
			return false;
	}
	return true;
}
bool Qbit::check(bool (*function)(STATE)) {
	for (vState::iterator it = state.begin() ; it != state.end() ; it++) {
		if (function(*it) == false)
			return false;
	}
	return true;
}

