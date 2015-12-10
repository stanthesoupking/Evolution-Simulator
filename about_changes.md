
Jarvis: My thoughts on the changes I have made in this branch are as below.

I don't want to be pushy, on the other hand you might want to know some of the things that could be done with these headers.

Having finished writing it now:
I definitely don't want to be pushy
Maybe some of the things you did in order for them to be better practice,
but these are just my thoughts in case you would also prefer them.

If any of this is extremely ugly to you then we'll work it out before merging these style changes back into master.

In-class definitions of get() and set()
=======================================

getX() and setX() have very specific names, and effectively always mean
    XType getX() {return x;}
	void setX(XType _x) {x = _x;}
to the point where it would be misleading to give them a different definition.

So since header files are the place to check for what methods a class has anyway, these (monotonous)
get and set methods are much nicer in-class, I think.

In addition to this, the simplicity of get and set means that it will never cause conflicts
because pointer assignment only needs forward declaration, and copy assignment needs full header inclusion,
but these will already be met in order for the class to have the member of XType.

Defaulting or delegating constructors
=====================================

Similar to above, if the practice of specifying constructors and destructors is desired,
it is neater and less boring to use delegation or defaulting for predictable data structures
(I'm not sure that interesting code style is the point but that's me...)

    ObviousClass (Member _x, Member _y):
	    x(_x), y(_y);
I think the predictability of that structure justifies putting it in-class
    ObviousClass ():
	    x(), y();
or
    ObviousClass ():
	    ObviousClass(0, 0);
or for the especially obvious classes
    ObviousClass () = default;

When classes don't actually do anything in their destructor then defaulting or even leaving them out saves
a lot of "oh there is a destructor - checks cpp definition - oh it is empty"

Especially since documenting such destructors would look like:
    ~EmptyStruct (); //default definition
when the following
    ~EmptyStruct () = default;
communicates the same thing, but also saves from needing to write the obvious destructor in the cpp

I am also aware that a lot of these classes will be un-defaulted in the future and that's okay.

Header inclusion practices
==========================

#pragma once
is quite cool I hadn't seen that.
It means that there is no worry with including headers more than once
this provides an opportunity to include headers in a java-like way, wherever they are depended upon.

The other thing is that in situations when pointers are used instead of actual members I think forward declaring is better than inclusion.
The full inclusion can take place in the cpp, and everything will be legal, it just means that the interfacing effects of headers will be stronger.

I think both of these header things only really matter if a fully fleshed out makefile is used, but there are some readability benefits as well.

Class Virtualization
====================

On one hand things like CBehavior and COrganism could be abstract classes, by giving them a pure virtual function,
On the other hand the virtuals could be given with simple definitions like {return false;} (inline plz) and then they
could be used as a default class for initializing a behavior table.
Generally it is good practice to have an abstract class for all polymorphic families, but in this case the nature of the classes might 
forgive the null-implementation approach.

I certainly can't decide
