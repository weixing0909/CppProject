#include"main.h"

using namespace std;

/*
Accumulators
Framework for incremental calculation, and collection of statistical accumulators.
Algorithm
A collection of useful generic algorithms.
Align
Memory alignment functions, allocators, and traits.
Any
Safe, generic container for single values of different value types.
Array
STL compliant container wrapper for arrays of constant size.
Asio
Portable networking and other low-level I/O, including sockets, timers, hostname resolution, socket iostreams, serial ports, file descriptors and Windows HANDLEs.
Assert
Customizable assert macros.
Assign
Filling containers with constant or generated data has never been easier.
Atomic
C++11-style atomic<>.
Beast
Portable HTTP, WebSocket, and network operations using only C++11 and Boost.Asio
Bimap
Bidirectional maps library for C++. With Boost.Bimap you can create associative containers in which both types can be used as key.
Bind
boost::bind is a generalization of the standard functions std::bind1st and std::bind2nd. It supports arbitrary function objects, functions, function pointers, and member function pointers, and is able to bind any argument to a specific value or route input arguments into arbitrary positions.
Call Traits
Defines types for passing parameters.
CallableTraits
A spiritual successor to Boost.FunctionTypes, Boost.CallableTraits is a header-only C++11 library for the compile-time inspection and manipulation of all 'callable' types. Additional support for C++17 features.
Chrono
Useful time utilities. C++11.
Circular Buffer
A STL compliant container also known as ring or cyclic buffer.
Compatibility
Help for non-conforming standard libraries.
Compressed Pair
Empty member optimization.
Compute
Parallel/GPU-computing library
Concept Check
Tools for generic programming.
Config
Helps Boost library developers adapt to compiler idiosyncrasies; not intended for library users.
Container
Standard library containers and extensions.
Container Hash
An STL-compatible hash function object that can be extended to hash user defined types.
Context
(C++11) Context switching library.
Contract
Contract programming for C++. All contract programming features are supported: Subcontracting, class invariants, postconditions (with old and return values), preconditions, customizable actions on assertion failure (e.g., terminate or throw), optional compilation and checking of assertions, etc.
Conversion
Polymorphic casts.
Convert
An extendible and configurable type-conversion framework.
Core
A collection of simple core utilities with minimal dependencies.
Coroutine (deprecated)
Coroutine library.
Coroutine2
(C++11) Coroutine library.
CRC
The Boost CRC Library provides two implementations of CRC (cyclic redundancy code) computation objects and two implementations of CRC computation functions. The implementations are template-based.
Date Time
A set of date-time libraries based on generic programming concepts.
DLL
Library for comfortable work with DLL and DSO.
Dynamic Bitset
The dynamic_bitset class represents a set of bits. It provides accesses to the value of individual bits via an operator[] and provides all of the bitwise operators that one can apply to builtin integers, such as operator& and operator<<. The number of bits in the set is specified at runtime via a parameter to the constructor of the dynamic_bitset.
Enable If
Selective inclusion of function template overloads.
Endian
Types and conversion functions for correct byte ordering and more regardless of processor endianness.
Exception
The Boost Exception library supports transporting of arbitrary data in exception objects, and transporting of exceptions between threads.
Fiber
(C++11) Userland threads library.
Filesystem
The Boost Filesystem Library provides portable facilities to query and manipulate paths, files, and directories.
Flyweight
Design pattern to manage large quantities of highly redundant objects.
Foreach
In C++, writing a loop that iterates over a sequence is tedious. We can either use iterators, which requires a considerable amount of boiler-plate, or we can use the std::for_each() algorithm and move our loop body into a predicate, which requires no less boiler-plate and forces us to move our logic far from where it will be used. In contrast, some other languages, like Perl, provide a dedicated "foreach" construct that automates this process. BOOST_FOREACH is just such a construct for C++. It iterates over sequences for us, freeing us from having to deal directly with iterators or write predicates.
Format
The format library provides a type-safe mechanism for formatting arguments according to a printf-like format-string.
Function
Function object wrappers for deferred calls or callbacks.
Function Types
Boost.FunctionTypes provides functionality to classify, decompose and synthesize function, function pointer, function reference and pointer to member types.
Functional
The Boost.Function library contains a family of class templates that are function object wrappers.
Functional/Factory
Function object templates for dynamic and static object creation
Functional/Forward
Adapters to allow generic function objects to accept arbitrary arguments
Functional/Overloaded Function
Overload different functions into a single function object.
Fusion
Library for working with tuples, including various containers, algorithms, etc.
Geometry
The Boost.Geometry library provides geometric algorithms, primitives and spatial index.
Geometry Extensions
The Boost.Geometry library provides geometric algorithms, primitives and spatial index.
Geometry Index
The Boost.Geometry library provides geometric algorithms, primitives and spatial index.
GIL
Generic Image Library
Graph
The BGL graph interface and graph components are generic, in the same sense as the Standard Template Library (STL).
GraphParallel
The PBGL graph interface and graph components are generic, in the same sense as the the Standard Template Library (STL).
Hana
A modern C++ metaprogramming library. It provides high level algorithms to manipulate heterogeneous sequences, allows writing type-level computations with a natural syntax, provides tools to introspect user-defined types and much more.
Heap
Priority queue data structures.
Histogram
Fast multi-dimensional histogram with convenient interface for C++14
HOF
Higher-order functions for C++
ICL
Interval Container Library, interval sets and maps and aggregation of associated values
Identity Type
Wrap types within round parenthesis so they can always be passed as macro parameters.
In Place Factory, Typed In Place Factory
Generic in-place construction of contained objects with a variadic argument-list.
Integer
The organization of boost integer headers and classes is designed to take advantage of <stdint.h> types from the 1999 C standard without resorting to undefined behavior in terms of the 1998 C++ standard. The header <boost/cstdint.hpp> makes the standard integer types safely available in namespace boost without placing any names in namespace std.
Interprocess
Shared memory, memory mapped files, process-shared mutexes, condition variables, containers and allocators.
Interval
Extends the usual arithmetic functions to mathematical intervals.
Intrusive
Intrusive containers and algorithms.
IO State Savers
The I/O sub-library of Boost helps segregate the large number of Boost headers. This sub-library should contain various items to use with/for the standard I/O library.
Iostreams
Boost.IOStreams provides a framework for defining streams, stream buffers and i/o filters.
Iterator
The Boost Iterator Library contains two parts. The first is a system of concepts which extend the C++ standard iterator requirements. The second is a framework of components for building iterators based on these extended concepts and includes several useful iterator adaptors.
Lambda
Define small unnamed function objects at the actual call site, and more.
Lexical Cast
General literal text conversions, such as an int represented a string, or vice-versa.
Local Function
Program functions locally, within other functions, directly within the scope where they are needed.
Locale
Provide localization and Unicode handling tools for C++.
Lockfree
Lockfree data structures.
Log
Logging library.
Math
Boost.Math includes several contributions in the domain of mathematics: The Greatest Common Divisor and Least Common Multiple library provides run-time and compile-time evaluation of the greatest common divisor (GCD) or least common multiple (LCM) of two integers. The Special Functions library currently provides eight templated special functions, in namespace boost. The Complex Number Inverse Trigonometric Functions are the inverses of trigonometric functions currently present in the C++ standard. Quaternions are a relative of complex numbers often used to parameterise rotations in three dimentional space. Octonions, like quaternions, are a relative of complex numbers.
Math Common Factor
Greatest common divisor and least common multiple.
Math Octonion
Octonions.
Math Quaternion
Quaternions.
Math/Special Functions
A wide selection of mathematical special functions.
Math/Statistical Distributions
A wide selection of univariate statistical distributions and functions that operate on them.
Member Function
Generalized binders for function/object/pointers and member functions.
Meta State Machine
A very high-performance library for expressive UML2 finite state machines.
Metaparse
A library for generating compile time parsers parsing embedded DSL code as part of the C++ compilation process
Min-Max
Standard library extensions for simultaneous min/max and min/max element computations.
Move
Portable move semantics for C++03 and C++11 compilers.
Mp11
A C++11 metaprogramming library.
MPI
Message Passing Interface library, for use in distributed-memory parallel application programming.
MPL
The Boost.MPL library is a general-purpose, high-level C++ template metaprogramming framework of compile-time algorithms, sequences and metafunctions. It provides a conceptual foundation and an extensive set of powerful and coherent tools that make doing explict metaprogramming in C++ as easy and enjoyable as possible within the current language.
Multi-Array
Boost.MultiArray provides a generic N-dimensional array concept definition and common implementations of that interface.
Multi-Index
The Boost Multi-index Containers Library provides a class template named multi_index_container which enables the construction of containers maintaining one or more indices with different sorting and access semantics.
Multiprecision
Extended precision arithmetic types for floating point, integer andrational arithmetic.
Numeric Conversion
Optimized Policy-based Numeric Conversions.
Odeint
Solving ordinary differential equations.
Operators
Templates ease arithmetic classes and iterators.
Optional
A value-semantic, type-safe wrapper for representing 'optional' (or 'nullable') objects of a given type. An optional object may or may not contain a value of the underlying type.
Outcome
A deterministic failure handling library partially simulating lightweight exceptions.
Parameter
Boost.Parameter Library - Write functions that accept arguments by name.
Parameter Python Bindings
Boost.Parameter Library Python bindings.
Phoenix
Define small unnamed function objects at the actual call site, and more.
Pointer Container
Containers for storing heap-allocated polymorphic objects to ease OO-programming.
PolyCollection
Fast containers of polymorphic objects.
Polygon
Voronoi diagram construction and booleans/clipping, resizing/offsetting and more for planar polygons with integral coordinates.
Pool
Memory pool management.
Predef
This library defines a set of compiler, architecture, operating system, library, and other version numbers from the information it can gather of C, C++, Objective C, and Objective C++ predefined macros or those defined in generally available headers.
Preprocessor
Preprocessor metaprogramming tools including repetition and recursion.
Process
Library to create processes in a portable way.
Program Options
The program_options library allows program developers to obtain program options, that is (name, value) pairs from the user, via conventional methods such as command line and config file.
Property Map
Concepts defining interfaces which map key objects to value objects.
Property Tree
A tree data structure especially suited to storing configuration data.
Proto
Expression template library and compiler construction toolkit for domain-specific embedded languages.
Python
The Boost Python Library is a framework for interfacing Python and C++. It allows you to quickly and seamlessly expose C++ classes functions and objects to Python, and vice-versa, using no special tools -- just your C++ compiler.
QVM
Generic {CPP} library for working with Quaternions Vectors and Matrices.
Random
A complete system for random number generation.
Range
A new infrastructure for generic algorithms that builds on top of the new iterator concepts.
Ratio
Compile time rational arithmetic. C++11.
Rational
A rational number class.
Ref
A utility library for passing references to generic functions.
Regex
Regular expression library.
Result Of
Determines the type of a function call expression.
Safe Numerics
Guaranteed Correct Integer Arithmetic
Scope Exit
Execute arbitrary code at scope exit.
Serialization
Serialization for persistence and marshalling.
Signals2
Managed signals & slots callback implementation (thread-safe version 2).
Smart Ptr
Smart pointer class templates.
Sort
High-performance templated sort functions.
Spirit
LL parser framework represents parsers directly as EBNF grammars in inlined C++.
Spirit Classic
LL parser framework represents parsers directly as EBNF grammars in inlined C++.
Spirit Repository
The Spirit repository is a community effort collecting different reusable components (primitives, directives, grammars, etc.) for Qi parsers and Karma generators.
Stacktrace
Gather, store, copy and print backtraces.
Statechart
Boost.Statechart - Arbitrarily complex finite state machines can be implemented in easily readable and maintainable C++ code.
Static Assert
Static assertions (compile time assertions).
String Algo
String algorithms library.
Swap
Enhanced generic swap function.
System
Operating system support, including the diagnostics support that will be part of the C++0x standard library.
Test
Support for simple program testing, full unit testing, and for program execution monitoring.
Thread
Portable C++ multi-threading. C++03, C++11, C++14, C++17.
ThrowException
A common infrastructure for throwing exceptions from Boost libraries.
Timer
Event timer, progress timer, and progress display classes.
Tokenizer
Break of a string or other character sequence into a series of tokens.
Tribool
3-state boolean type library.
TTI
Type Traits Introspection library.
Tuple
Ease definition of functions returning multiple values, and more.
Type Erasure
Runtime polymorphism based on concepts.
Type Index
Runtime/Compile time copyable type info.
Type Traits
Templates for fundamental properties of types.
Typeof
Typeof operator emulation.
uBLAS
uBLAS provides tensor, matrix, and vector classes as well as basic linear algebra routines. Several dense, packed and sparse storage schemes are supported.
Units
Zero-overhead dimensional analysis and unit/quantity manipulation and conversion.
Unordered
Unordered associative containers.
Utility
Class noncopyable plus checked_delete(), checked_array_delete(), next(), prior() function templates, plus base-from-member idiom.
Uuid
A universally unique identifier.
Value Initialized
Wrapper for uniform-syntax value initialization, based on the original idea of David Abrahams.
Variant
Safe, generic, stack-based discriminated union container.
VMD
Variadic Macro Data library.
Wave
The Boost.Wave library is a Standards conformant, and highly configurable implementation of the mandated C99/C++ preprocessor functionality packed behind an easy to use iterator interface.
Xpressive
Regular expressions that can be written as strings or as expression templates, and which can refer to each other and themselves recursively with the power of context-free grammars.
YAP
An expression template library for C++14 and later.
*/

int main(int argc, char** argv)
{
    cout << "entry c++ boost practice" << endl;
	int index = 0;
	switch (index)
	{
	case 0: boost_filesystem_test(); break;
	default:break;
	}
    return 0;
}