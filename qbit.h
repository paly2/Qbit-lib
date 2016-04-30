#include <vector>
#include <ostream>

using namespace std;

enum STATE { LOW = 0, HIGH  = 1 }; // STATE type
typedef vector<STATE> vState; // STATE vector (descriptor of a qbit)

class Qbit {
	public:
	Qbit(STATE); // Creates a qbit with a first classic state (recommanded).
	Qbit(vector<STATE>); // Creates a quantum qbit with vState descriptor
	
	void set_state(vector<STATE> new_state); // Use this function only if you know what you are doing.
	
	vector<STATE> get_state() const; // Returns the list of superposed states of qbit.
	void add_state(STATE new_state); // Superposes another state.
	
	STATE read() const; // Reads qbit (returns random state in superposed states).
	
	Qbit& operator|=(Qbit const& qbit); // "OR" quantum logic operator
	Qbit& operator&=(Qbit const& qbit); // "AND" quantum logic operator
	Qbit& operator^=(Qbit const& qbit); // "XOR" quantum logic operator
	
	bool all_high(); // Returns true if qbit is completely high (it's impossible to get low if you read it)
	bool all_low(); // Returns true if qbit is completely low (it's impossible to get high if you read it)
	bool check(bool (*function)(STATE)); // Check the return of a function for all qbit, returns true if the function returns always true.
	
	private:
	vector<STATE> state;
};

ostream& operator<<(ostream &stream, const Qbit& qbit); // Pushes a Qbit into a flush

Qbit operator|(Qbit const& qbit1, Qbit qbit2); // "OR" quantum logic operator
Qbit operator&(Qbit const& qbit1, Qbit qbit2); // "AND" quantum logic operator
Qbit operator^(Qbit const& qbit1, Qbit qbit2); // "XOR" quantum logic operator
Qbit operator!(Qbit const& qbit); // "NOT" quantom logic operator

