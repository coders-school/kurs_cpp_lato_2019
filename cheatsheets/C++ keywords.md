 # Selected C++ keywords (for C++ 17)

| keyword   | description | more | associated with |
|-|-|-|-|
|auto|placeholder for a type|[auto]|decltype|
|bool|boolean type specifier|[bool]|true, false, if  |
|break|terminates associated statements|[break]|for, do, while, switch, case|
|case|leads to different path in switch statement|[case]| switch, break|
|catch|the part of try-catch block, used for exception handling|[catch]|try, throw|
|char|single character type (8bits)|[char]|std::string|
|class|used in declaration/definition of class|[class]|struct, public, protected, private|
|const|variable - is immutable, function - will not modify|[const]|volatile|
|constexpr|expresion will be computed at compile time|[constexpr]|const|
|const_cast|converts const type to non-const and vice-versa|[const_cast]|const|
|continue|skip the rest of the loop|[continue]|break, return|
|decltype|get type of entity/expression|[decltype]|auto|
|default|switch statement - to implement default behavior (given case is not in the switch), constructor/destructor - tell compiler to generate default implementation|[default]|switch, case, constructor, destructor|
|delete|memory allocation - destroy object dynamically allocated with ```new``` operator, constructor/destructor - tells compiler not to generate given ctor/dtor|[delete]|new, memory management, heap deallocation|
|do|declares/opens the do-while loop|[do]|while|
|double|double precision floating point type|[double]|float|
|dynamic_cast|converts pointers and references in class hierarchy|[dynamic_cast]|inheritance, polymorphism, pointer|
|else|declares alternative branch for```if``` statement|[else]|if|
|enum|declares an enumeration type, whose value is limited to restricted range of values|[enum]|enum class|
|explicit|c-tor preceded by this keyword cannot be used to perform implicit conversion nor copy initialization|[explicit]|constructor|
|false|boolean literal contrary to the```true```|[false]|bool, true, if statement|
|float|single precision floating point type|[float]|double|
|for|declares "for loop"/"range-based for loop"|[for]|range based for, algorithm library|
|friend|grants access to private and protected members|[friend]|class|
|if|declares "if statement" - code inside it will be executed if the given condition is met|[if]|else, bool, true, false|
|inline|function declared inline can be defined in header file, there may be multiple definitions of this function as long as they're in different translation units|[inline]|function definition, header file, translation unit|
|int|declaration of basic integer type|[int]|long, short, unsigned|
|long|type prepended with long will have width of at least 32 bits|[long]|short|
|namespace|declare a namespace which is a method to prevent name conflicts, scoping the names|[namespace]|anonymous namespace, using|
|new|creates dynamically allocated object|[new]|delete, memory management, heap allocation, placement new|
|nullptr|pointer literal which means "uninitialized" or "empty" pointer, implicitly converted to null pointer value of any pointer type|[nullptr]|NULL|
|operator|used for customize C++ operators (operators overloading), used together with operator symbol|[operator]||
|private|access specifier which limits the access to objects of given class itself (except friends)|[private]||
|protected|access specifier which limits the access to objects of given class (except friends) and those deriving from it|[protected]||
|public|access specifier which makes members accessible from everywhere in code|[public]|class, protected, private|
|reinterpret_cast|converts to new type (by reinterpreting the underlying bit pattern)|[reinterpret_cast]|static_cast, const_cast|
|return|terminates the current function and returned specified value (non applicable for void) to its caller|[return]|function|
|short|type prepended with long will have width of at least 16 bits|[short]|long|
|sizeof|used to check size of the object or type|[sizeof]||
|static|in class: members declared static are single for all class instances, static storage duration - object is allocated for throughout program's lifetime|[static]||
|static_assert|assertion checked in compile-time|[static_assert]||
|static_cast|converts between types using a combination of implicit and user-defined conversions|[static_cast]||
|struct|declares a class with default public access|[struct]|class|
|switch|transfers control to one of the several statements, depending on the value of a condition|[switch]|case, default, break, return|
|template|used to make generic types parametrized by different types of values of given type|[template]|typename, class|
|this|```this``` pointer refers to addres of the object on which member function is being called|[this]||
|throw|signals an erroneous condition and executes an error handler|[throw]||
|true|boolean literal contrary to the```false```|[true]||
|try|declares try-block inside which thrown exceptions may be handled|[try]|throw, catch, exception|
|typename|in template declaration - declares type template parameters (alternative to ```class``` keyword)|[typename]||
|union|special class type that can hold only one if its non-static data members at a time|[union]|std::variant, visitor|
|unsigned|type modifier which "narrows" numeric type to store only positive values (without sign)|[unsigned]|int|
|using|using-directive for namespaces, using-declarations for namespace/class members, type alias|[using]|namespce, typename|
|virtual|virtual function specifier - base class member function can be overridden in derived class; virtual base class specifier - solves ingeritance diamond problem, making base class appear only once in inheritance hierarchy|[virtual]|override, class|
|void|void type - incomplete type which indicates empty set of values, can also be used in parameter list to indicate that no parameters are meant to be passed to the function|[void]||
|volatile|qualifier that prevents given object from being optimized by compiler in way that cannot be determined by compiler and its value is read from memory location rather than from temporary register|[volatile]||
|while|while/do-while loop declaration|[while]|do|

[auto]: https://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
[bool]: https://www.geeksforgeeks.org/bool-data-type-in-c/
[break]: https://www.geeksforgeeks.org/break-statement-cc/
[case]: https://www.geeksforgeeks.org/switch-statement-cc/
[catch]: https://www.geeksforgeeks.org/exception-handling-c/
[char]: https://www.geeksforgeeks.org/char-vs-stdstring-vs-char-c/
[class]: https://www.geeksforgeeks.org/c-classes-and-objects/
[const]: https://stackoverflow.com/questions/4064286/c-const-keyword-explanation
[constexpr]: https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/
[const_cast]: https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/#targetText=const_cast%20is%20used%20to%20cast,inside%20a%20const%20member%20function.&targetText=The%20variable%20'val'%20is%20a,modify%20'val'%20using%20const_cast.
[continue]: https://www.programiz.com/cpp-programming/break-continue
[decltype]: https://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
[default]: https://en.cppreference.com/w/cpp/keyword/default
[delete]: https://en.cppreference.com/w/cpp/keyword/delete
[do]: https://www.programiz.com/cpp-programming/do-while-loop
[double]: https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double
[dynamic_cast]: https://stackoverflow.com/questions/2253168/dynamic-cast-and-static-cast-in-c
[else]: https://www.programiz.com/cpp-programming/if-else
[enum]: https://stackoverflow.com/questions/12183008/how-to-use-enums-in-c
[explicit]: https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
[false]: https://stackoverflow.com/questions/20343114/bool-type-true-and-false
[float]: https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double
[for]: https://en.cppreference.com/w/cpp/language/range-for
[friend]: https://www.geeksforgeeks.org/friend-class-function-cpp/
[if]: https://www.programiz.com/cpp-programming/if-else
[inline]: https://www.geeksforgeeks.org/inline-functions-cpp/
[int]: https://en.cppreference.com/w/cpp/language/types
[long]: https://en.cppreference.com/w/cpp/language/types
[namespace]: https://www.geeksforgeeks.org/namespace-in-c/
[new]: https://en.cppreference.com/w/cpp/language/new
[nullptr]: https://www.geeksforgeeks.org/understanding-nullptr-c/
[operator]: https://www.geeksforgeeks.org/operators-c-c/#targetText=Operators%20in%20C%20%2F%20C%2B%2B&targetText=The%20addition%20operator%20tells%20the,arithmetic%2Fmathematical%20operations%20on%20operands.
[private]: https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
[protected]: https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
[public]: https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
[reinterpret_cast]: https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
[return]: https://en.cppreference.com/w/cpp/language/return
[short]: https://en.cppreference.com/w/cpp/language/types
[sizeof]: https://stackoverflow.com/questions/589575/what-does-the-c-standard-state-the-size-of-int-long-type-to-be
[static]: https://www.geeksforgeeks.org/static-keyword-cpp/
[static_assert]: https://stackoverflow.com/questions/1647895/what-does-static-assert-do-and-what-would-you-use-it-for
[static_cast]: https://stackoverflow.com/questions/2253168/dynamic-cast-and-static-cast-in-c
[struct]: https://www.learncpp.com/cpp-tutorial/47-structs/
[switch]: https://www.geeksforgeeks.org/switch-statement-cc/
[template]: https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
[this]: https://stackoverflow.com/questions/6779645/use-of-this-keyword-in-c
[throw]: https://www.geeksforgeeks.org/exception-handling-c/
[true]: https://stackoverflow.com/questions/20343114/bool-type-true-and-false
[try]: https://www.geeksforgeeks.org/exception-handling-c/
[typename]: https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
[union]: https://stackoverflow.com/questions/2310483/purpose-of-unions-in-c-and-c
[unsigned]: https://en.cppreference.com/w/cpp/language/types
[using]: https://stackoverflow.com/questions/20790932/what-is-the-logic-behind-the-using-keyword-in-c
[virtual]: https://en.cppreference.com/w/cpp/keyword/virtual
[void]: https://stackoverflow.com/questions/1043034/what-does-void-mean-in-c-c-and-c
[volatile]: https://stackoverflow.com/questions/72552/why-does-volatile-exist
[while]: https://www.programiz.com/cpp-programming/do-while-loop