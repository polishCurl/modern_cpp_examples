Demonstrate benefits of c++11 _deleted functions_

In c++98, to prevent use of a member function it has to be declared _private_ and left without definition.
This way, the member function cannot be accessed from outside the class, neither from inside the class or by
_friend_ functions. For the latter case, the problem is that the use of forbidden member function will only be reported at link time.

In c++11, deleted public functions allow explicitly banning thw use of:
- member functions
- template instantiations

with errors reported at compile-time.