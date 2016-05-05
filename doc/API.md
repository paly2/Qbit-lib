# Qbit lib API documentation

The `qbit.h` file allows you to use the Qbit class.

## Qbit class

### Note about possible states of a Qbit

A qbit always have a state among three states :

#### Empty

This state is a state which doesn't exist in a true quantic computer. It's very specific and you should be careful with it.  
An empty Qbit is neither high, nor low, nor both. It's just... empty. It obtains a true state if you use the `add_state` or the `set_state` method.  
If you try to use the `read` method or `operator<<` function on an empty qbit, you DO have a segment error.

#### Classic

Only one state : LOW or HIGH. If you read a "classic" qbit (so a simple bit), you obtain everytime the same state.

#### Quantum

Many superposed states. Strangest state, which gives random state if you read it (but with different probabilities). A true Qbit.

### Constructors

There are three constructors :

#### Qbit::Qbit();

This creates an empty Qbit, with no state.

#### Qbit::Qbit(STATE);

This constructor creates a Qbit with a fixed state - a classic bit, in fact.

#### Qbit::Qbit(vState);

This constructor creates a Qbit which has already a quantic state, described using a vState vector (see Types part of this documentation).

### Low-level methods

You are able to do EVERYTHING on a Qbit using only two methods: `set_state` and `get_state`. However, if you can, please use high-level methods instead.

#### void Qbit::set_state(vState new_state);

This method replaces the entire Qbit state using the new state passed as argument using a vState vector. It doesn't return, and doesn't do any verification.

#### vState Qbit::get_state() const;

This returns the actual Qbit state in a vState vector.

### High-level methods

#### void Qbit::add_state(STATE new_state);

This method could be considered as a low-level function.  
It superposes another state to the Qbit.

#### STATE Qbit::read() const;

This method works like if you look at the Qbit... The quantic state is broken (not definitively of course, just during the reading operation) and you get only one state, which is returned.

#### Qbit& operator|=(Qbit const& qbit); Qbit& operator&=(Qbit const& qbit); Qbit& operator^=(Qbit const& qbit);

These methods are the quantum equivalents of respectively the classic OR, AND and XOR logic operators.

#### bool all_high() const; bool all_low() const;

These methods verify if the Qbit is completely high or completely low (respectively).

#### bool check(bool (*function)(STATE)) const;

This method checks if the return value of the `function` function is true. It returns true then, or false if the function `function` returned false at least one time.

## Types

### enum STATE { LOW = 0, HIGH  = 1 };

The STATE enum.

### typedef vector<STATE> vState;

The vState vector is used to describe a quantum state: many classic STATEs superposed.
