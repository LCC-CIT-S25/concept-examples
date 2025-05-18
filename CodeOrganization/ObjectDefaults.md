# Object behaviors

First, let's consider declaring an object. Without declaring a constructor,
there an implicit constructor that takes no arguments. If you declare a constructor
this doesn't happen.  You must supply any non-default arguments at the time of construction.

Let's consider what we should do if we assign one object to another.

```c++
Sequence s1;
Sequence s2;
Sequence s2 = s1;
```

### Default constructor
`Sequence();`
Calls default constructors on members

### Default destructor
`~Sequence();`
Calls destructors on members

### Copy Constructor
`Sequence(const Sequence&);`
assigns members directly (shallow copy). Call member copy constructor.

### Copy Assignment
`Sequence& operator=(const Sequence&);`
assigns members directly (shallow copy). Call member copy assignment.

### Move constructor
`Sequence(Sequence &&);`
Calls move constructor on members. Assigning primitive types.

### Move assignment
`Sequence& operator=(Sequence&&);`
Call move assignment on members. Assigning primitive types.