/*
ID:
PROG:
LANG: C++
/**
 * ASCII Table: Lines (85) 100 -> 255
 * Operator Precedence Lines 9 -> 63
 * Typedefs Lines ->
 *
 * |Precedence|  Operator(s)  |                Description	              |Associativity
 * +----------+---------------+-------------------------------------------+-------------
 * |    1     |      ::       |             Scope resolution	          |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |   	      |    a++ a--    |  Suffix/postfix increment and decrement   |
 * |          |type()  type{} |              Functional cast              |
 * |    2     |      a()      |               Function call               |Left-to-right
 * |          |      a[]      |                 Subscript                 |
 * |          |      ->	      |               Member access               |
 * +----------+---------------+-------------------------------------------+-------------
 * |          |   ++a   --a   |      Prefix increment and decrement	      |
 * |          |    +a   -a    |           Unary plus and minus            |
 * |          |     !   ~     |        Logical NOT and bitwise NOT        |
 * |          |    (type)     |               C-style cast                |
 * |    3     |      *a	      |         Indirection (dereference)         |Right-to-left
 * |          |      &a	      |                Address-of                 |
 * |          |    sizeof     |                  Size-of                  |
 * |          |   new new[]   |         Dynamic memory allocation         |
 * |          |delete delete[]|        Dynamic memory deallocation        |
 * +----------+---------------+-------------------------------------------+-------------
 * |    4     |   .*   ->*    |             Pointer-to-member	          |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    5     |a*b   a/b   a%b|  Multiplication, division, and remainder  |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    6     |   a+b   a-b   |         Addition and subtraction          |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    7     |    <<   >>    |    Bitwise left shift and right shift     |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    8     |      <=>      |Three-way comparison operator (since C++20)|Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    9     |    <   <=     |                                           |Left-to-right
 * |          |    >   >=     |                                           |
 * +----------+---------------+-------------------------------------------+
 * |    10    |    ==   !=    |                                           |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    11    |       &	      |                Bitwise AND                |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    12    |       ^	      |        Bitwise XOR (exclusive or)         |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    13    |       |	      |         Bitwise OR (inclusive or)         |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    14    |      &&       |                Logical AND                |Left-to-right
 * +----------+---------------+-------------------------------------------+
 * |    15    |      ||       |                Logical OR                 |Left-to-right
 * +----------+---------------+-------------------------------------------+-------------
 * |	      |   a ? b : c   |            Ternary conditional            |
 * |          |     throw     |              throw operator               |
 * |          |       =	      |Direct assignment                          |
 * |    16    |               |     (provided by default for C++ classes) |Right-to-left
 * |          |    +=   -=    |      Compound assignment by + and -       |
 * |          | *=   /=   %=  |    Compound assignment by *, /, and %     |
 * |          |   <<=   >>=   |     Compound assignment by << and >>      |
 * |          | &=   ^=   |=  |  Compound assignment by AND, XOR, and OR  |
 * +----------+---------------+-------------------------------------------+-------------
 * |    17    |       ,	      |                   Comma                   |Left-to-right
 *
 * Common Data Structure Operations
 * Data Structure|                        Time Complexity                          |Space Complexity
 * --------------+--------------------------------+--------------------------------+----------------
 *               |            Average	          |             Worst	           |
 *               +--------------------------------+--------------------------------+     Worst
 *               |Access|Search|Insertion|Deletion|Access|Search|Insertion|Deletion|
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *     Array     | O(1) | O(n) |  O(n)   |  O(n)  | O(1) | O(n) |  O(n)   |  O(n)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *     Stack	 | O(n)	| O(n) |  O(1)	 |  O(1)  | O(n) | O(n)	|  O(1)	  |  O(1)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *     Queue	 | O(n)	| O(n) |  O(1)	 |  O(1)  | O(n) | O(n) |  O(1)	  |  O(1)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *  Forward List | O(n)	| O(n) |  O(1)	 |  O(1)  | O(n) | O(n)	|  O(1)	  |  O(1)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *     List      | O(n)	| O(n) |  O(1)   |  O(1)  | O(n) | O(n) |  O(1)   |  O(1)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *   Skip List	 |log(n)|log(n)|O(log(n))| log(n) | O(n) | O(n)	|  O(n)   |  O(n)  |  O(n log(n))
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *   Hash Table	 | N/A	| O(1) |  O(1)	 |  O(1)  | N/A	 | O(n)	|  O(n)	  |  O(n)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 * Bnry Srch Tree|log(n)|log(n)|O(log(n))| log(n) | O(n) | O(n)	|  O(n)	  |  O(n)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 * Cartesian Tree| N/A	|log(n)|O(log(n))| log(n) | N/A	 | O(n)	|  O(n)	  |  O(n)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *     B-Tree	 |log(n)|log(n)|O(log(n))| log(n) |log(n)|log(n)|O(log(n))| log(n) |	 O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 * Red-Black Tree|log(n)|log(n)|O(log(n))| log(n) |log(n)|log(n)|O(log(n))| log(n) |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *   Splay Tree	 | N/A	|log(n)|O(log(n))| log(n) | N/A	 |log(n)|O(log(n))| log(n) |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *    AVL Tree	 |log(n)|log(n)|O(log(n))| log(n) |log(n)|log(n)|O(log(n))| log(n) |	 O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 *    KD Tree	 |log(n)|log(n)|O(log(n))| log(n) | O(n) | O(n)	|  O(n)	  |  O(n)  |     O(n)
 * --------------+------+------+---------+--------+------+------+---------+--------+----------------
 */
/// general stuff
#include <iostream>
#include <algorithm> //very useful with containers and arrays
#include <cstring> //for C-style char pointers
#include <string>
#include <cassert> //debugging
#include <cfloat>
#include <climits> //useful for INT_MAX, etc.
#include <cmath> //the trigonometry functions are useful

/// data structure
#include <bitset> //such an outlier - doesn't even have begin()/end()
#include <map>
#include <queue> //pqueue included
#include <set>
#include <unordered_set> //Java HashSet and umset
#include <stack>
#include <utility> //pair, declval
#include <vector> //recommended to reserve a set space at initialization
#include <forward_list>
#include <list> //Good at growing and shrinking at ends but big on size
#include <complex> //honestly I should remove this lol
#include <deque> //double ended queue
#include <unordered_map> //Java HashMap and ummap
#include <array> //C-array more common than std::array and requires constexpr size at initialization
#include <tuple> //not really used

/// etc
#include <iterator>
#include <functional> //functions and trait classes
#include <iomanip> //sets precision, filling etc.
#include <chrono> //precise time
#include <numeric>
#include <cctype> //idk when this is used lol
#include <cxxabi.h> //"demangles" typeid(x).name() so it's actually readable
#include <cstdarg> //deals with variadic arguments in the form of "..." (typename... Args works too)
#include <regex> //used for string manipulation in the functions below
#include <cstdlib>

//provides hashing function for pairs so pairs can now be used as keys in hash sets/maps
typedef long long llng;
typedef double dbl;
typedef long double ldbl;
typedef unsigned long long ullng;
typedef unsigned uint;

template <typename T> inline std::size_t hash_combine(const std::size_t& seed, const T& v)
{
    return seed ^ std::hash<T>(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std
{
    template <typename S, typename T> struct hash<pair<S, T> >
    {
        inline size_t operator()(const pair<S, T>& v) const
        {
            return hash_combine(hash_combine(0, v.first), v.second);
        }
    }; //you can now use pairs in a tuple
};

using namespace std;
using namespace placeholders;

///shorter typenames
#define pqueue priority_queue
//these typenames remove confusion on the types of priority queues
template <typename T> using max_heap = pqueue<T>;
template <typename T> using min_heap = pqueue<T, vector<T>, greater<T> >;
#define umap unordered_map
#define ummap unordered_multimap
#define mmap multimap
#define uset unordered_set
#define umset unordered_multiset
#define mset multi_set
#define flist forward_list
#define arr array
typedef initializer_list<string> ils;

typedef pair<int, int> pi;
typedef pair<llng, llng> pl;
typedef pair<dbl, dbl> pd;
typedef pair<ldbl, ldbl> pld;
typedef pair<uint, uint> pui;
typedef pair<ullng, ullng> pul;

typedef vector<int> vi;
typedef vector<llng> vl;
typedef vector<dbl> vd;
typedef vector<ldbl> vld;
typedef vector<uint> vui;
typedef vector<ullng> vul;

typedef stack<int> si;
typedef stack<llng> sl;
typedef stack<dbl> sd;
typedef stack<ldbl> sld;
typedef stack<uint> sui;
typedef stack<ullng> sul;

typedef queue<int> qi;
typedef queue<llng> ql;
typedef queue<dbl> qd;
typedef queue<ldbl> qld;
typedef queue<uint> qui;
typedef queue<ullng> qul;

typedef deque<int> di;
typedef deque<llng> dl;
typedef deque<dbl> dd;
typedef deque<ldbl> dld;
typedef deque<uint> dui;
typedef deque<ullng> dul;

typedef pqueue<int> pqi;
typedef pqueue<llng> pql;
typedef pqueue<dbl> pqd;
typedef pqueue<ldbl> pqdl;
typedef pqueue<uint> pqui;
typedef pqueue<ullng> pqul;

typedef min_heap<int> minhi;
typedef min_heap<llng> minhl;
typedef min_heap<dbl> minhd;
typedef min_heap<ldbl> minhld;
typedef min_heap<uint> minhui;
typedef min_heap<ullng> minhul;

typedef max_heap<int> maxhi;
typedef max_heap<llng> maxhl;
typedef max_heap<dbl> maxhd;
typedef max_heap<ldbl> maxhld;
typedef max_heap<uint> maxhui;
typedef max_heap<ullng> maxhul;

typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<pld> vpld;
typedef vector<pui> vpui;
typedef vector<pul> vpul;

typedef stack<pi> spi;
typedef stack<pl> spl;
typedef stack<pd> spd;
typedef stack<pld> spld;
typedef stack<pui> spui;
typedef stack<pul> spul;

typedef queue<pi> qpi;
typedef queue<pl> qpl;
typedef queue<pd> qpd;
typedef queue<pld> qpld;
typedef queue<pui> qpui;
typedef queue<pul> qpul;

typedef deque<pi> dpi;
typedef deque<pl> dpl;
typedef deque<pd> dpd;
typedef deque<pld> dpld;
typedef deque<pui> dpui;
typedef deque<pul> dpul;

typedef pqueue<pi> pqpi;
typedef pqueue<pl> pqpl;
typedef pqueue<pd> pqpd;
typedef pqueue<pld> pqpld;
typedef pqueue<pui> pqpui;
typedef pqueue<pul> pqpul;

typedef min_heap<pi> minhpi;
typedef min_heap<pl> minhpl;
typedef min_heap<pd> minhpd;
typedef min_heap<pld> minhpld;
typedef min_heap<pui> minhpui;
typedef min_heap<pul> minhpul;

typedef max_heap<pi> maxhpi;
typedef max_heap<pl> maxhpl;
typedef max_heap<pd> maxhpd;
typedef max_heap<pld> maxhpld;
typedef max_heap<pui> maxhpui;
typedef max_heap<pul> maxhpul;

#define int2 int, int
#define int3 int2, int
#define int4 int3, int
#define int5 int4, int
#define int6 int5, int

#define llng2 llng, llng
#define llng3 llng2, llng
#define llng4 llng3, llng
#define llng5 llng4, llng
#define llng6 llng5, llng

#define dbl2 dbl, dbl
#define dbl3 dbl2, dbl
#define dbl4 dbl3, dbl
#define dbl5 dbl4, dbl
#define dbl6 dbl5, dbl

#define ldbl2 ldbl, ldbl
#define ldbl3 ldbl2, ldbl
#define ldbl4 ldbl3, ldbl
#define ldbl5 ldbl4, ldbl
#define ldbl6 ldbl5, ldbl

#define uint2 uint, uint
#define uint3 uint2, uint
#define uint4 uint3, uint
#define uint5 uint4, uint
#define uint6 uint5, uint

#define ullng2 ullng, ullng
#define ullng3 ullng2, ullng
#define ullng4 ullng3, ullng
#define ullng5 ullng4, ullng
#define ullng6 ullng5, ullng

#define ALL(c) begin(c), end(c) //used a lot in container/iterator functions + works with C-arrays
#define RALL(c) rbegin(c), rend(c) //may not properly work with C-arrays
#define CALL(c) (c).cbegin(), (c).cend() //doesn't work with C-arrays
#define CRALL(c) (c).crbegin(), (c).crend() //doesn't work with C-arrays
#define AALL(a) a, a + sizeof(a) / sizeof(a[0]) //for unbounded arrays


template <typename...> struct make_void { typedef void type; };
template <typename... Ts> using void_t = typename make_void<Ts...>::type;
//syntatic-sugar for typename enable_if<B, T>::type
template <bool B, typename T = void> using enable_if_t = typename enable_if<B, T>::type;

template <class, typename = void> struct is_iterator : public false_type {};
template <class T> struct is_iterator<T, void_t<
            decltype(T(declval<T>())),
            decltype(declval<T&>() = declval<T>()),
            decltype(++declval<T&>()),
            decltype(declval<T&>()++),
            decltype(*declval<T&>())> > : public true_type {};

template <class, typename = void> struct iterable : public false_type {};
template <class T> struct iterable<T, void_t<
            decltype(begin(declval<T&>())),
            decltype(end(declval<T&>()))> > : public true_type {};

template <class, typename = void> struct iter {}; //extracts T's iterator type
template <class T> struct iter<T, enable_if_t<is_iterator<T>::value> >
{
    typedef T type; //return itself if already iterator
};

template <class T> struct iter<T, enable_if_t<iterable<T>::value> >
{
    typedef decltype(begin(declval<T&>())) type; //get iterator if iterable
};

template <class T> using iter_t = typename iter<T>::type;

//test if it's random access (arrays, vectors, deques, strings)
template <class T> using random_iter = is_base_of<random_access_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>;
//test if it's bidirectional (lists)
template <class T> using two_way_iter = is_base_of<bidirectional_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>;
//test if it traverses forward (forward_lists)
template <class T> using forward_iter = is_base_of<forward_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>;
//test if it's like an output stream
template <class T> using out_iter = is_base_of<output_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>;
//test if it's like an input stream
template <class T> using in_iter = is_base_of<input_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>;

//test if it can contain or is adaptor (not tuple)
template <class, typename = void> struct std_container : public false_type {};
template <class T> struct std_container<T, void_t<
                typename T::reference,
                typename T::const_reference,
                typename T::size_type,
                decltype(T(declval<T>())),
                decltype(declval<T&>() = declval<T>()),
                decltype(declval<T>().~T()),
                decltype(declval<T>().empty()),
                decltype(declval<T&>().swap(declval<T&>())),
                decltype(swap(declval<T&>(), declval<T&>()))
                > > : public true_type {};

//test if is container (not adaptor)
template <class, typename = void, typename = void> struct is_container : public false_type {};
template <class T> struct is_container<T, void_t<
                typename T::iterator,
                typename T::const_iterator,
                typename T::difference_type,
                decltype(declval<T>().cbegin()),
                decltype(declval<T>().cend()),
                decltype(declval<T>() == declval<T>()),
                decltype(declval<T>() != declval<T>()),
                decltype(declval<T>().max_size())>,
                enable_if_t<std_container<T>::value && iterable<T>::value> > : public true_type {};

//test if is tuple (doesn't include std::array since it's a container)
template <class, typename = void> struct is_tuple : public false_type {};
template <class T> struct is_tuple<T, void_t<
            decltype(T()),
            decltype(T(declval<T>())),
            decltype(declval<T>() == declval<T>()),
            decltype(declval<T>() < declval<T>()),
            decltype(tuple_size<T>::value)
            > > : public integral_constant<bool, !is_container<T>::value> {};

//test if is associative (set)
template <class, typename = void> struct is_associative : public false_type {};
template <class T> struct is_associative<T, void_t<
            typename T::key_type> > : public is_container<T> {};

//test if is map
template <class, typename = void> struct is_map : public false_type {};
template <class T> struct is_map<T, void_t<
            typename T::mapped_type> > : public is_associative<T> {};

//extract value type of an iterable
template <class, size_t, typename = void> struct val_type { };
//for any iterable (except maps because the value type gives you a pair of key and value)
template <class T, size_t N> struct val_type<T, N, enable_if_t<N && iterable<T>::value &&
        !is_map<T>::value> >
{
    typedef typename val_type<typename remove_reference<
            decltype(*declval<iter_t<T> >())>::type, N - 1>::type type;
};
//gives you the map's mapped type not pair of key and value
template <class T, size_t N> struct val_type<T, N, enable_if_t<N && is_map<T>::value> >
{
    typedef typename val_type<typename T::mapped_type, N - 1>::type type;
};
//if it's already an iterator, gives you the value type
template <class T, size_t N>
        struct val_type<T, N, enable_if_t<N && is_iterator<T>::value> >
{
    typedef typename val_type<typename iterator_traits<T>::value_type, N - 1>::type type;
};
template <class T> struct val_type<T, 0>
{
    typedef T type;
};
template <class T, size_t N = 1> using val_type_t = typename val_type<T, N>::type;

//test if it's like a vector or array or deque or string or list or forward_list
template <class, typename = void> struct is_sequential : public false_type {};
template <class T> struct is_sequential<T, void_t<
        decltype(declval<T>().front())> > : public is_container<T> {};

//test if it's like a vector or deque or string or list or forward_list
template <class, typename = void> struct can_change_back : public false_type {};
template <class T> struct can_change_back<T, void_t<
        decltype(declval<T&>().push_back(declval<val_type_t<T> >()))> > :
        public is_sequential<T> {};

//test if it's like a deque or string or list
template <class, typename = void, typename = void> struct changes_front : public false_type {};
template <class T> struct changes_front<T, void_t< 
        decltype(declval<T&>().push_front(declval<val_type_t<T> >()))>,
        enable_if_t<is_sequential<T>::value && !can_change_back<T>::value> > : public true_type {};

//test if it's a queue or stack or pqueue
template <class, typename = void> struct is_adaptor : public false_type {};
template <class T> struct is_adaptor<T, void_t<
        typename T::container_type> > : public std_container<T> {};

//test if it can you give you size (true for all containers except forward_list)
template <class, typename = void> struct instant_size : public false_type {};
template <class T> struct instant_size<T, void_t<decltype(declval<T>().size())> > :
        public true_type {};

template <typename T> struct remove_cvref
{
    typedef typename remove_cv<typename remove_reference<T>::type>::type type;
};
template <typename T> using remove_cvref_t = typename remove_cvref<T>::type;

template <class, typename = void> struct is_str : public false_type {};
template <class T> struct is_str<T, enable_if_t<is_same<remove_cvref_t<T>,
        basic_string<typename T::value_type> >::value> > : public true_type {};
template <class T> struct is_str<T, enable_if_t<is_pointer<T>::value && is_same<
        remove_cvref_t<typename remove_pointer<T>::type>, char>::value> > : public true_type {};
template <class T> struct is_str<T, enable_if_t<is_array<T>::value && is_same<
        remove_cvref_t<typename remove_extent<T>::type>, char>::value> > : public true_type {};

template <typename T> struct is_bounded_array : false_type {};
template <typename T, size_t N> struct is_bounded_array<T[N]> : true_type {};


//test if A equals at least one type of the following
template <typename A, typename T, typename... Ts> struct is_one_of :
        public integral_constant<bool, is_one_of<A, T>::value || is_one_of<A, Ts...>::value> {}; 

template <typename A, typename T> struct is_one_of<A, T> :
        public is_same<remove_cvref_t<A>, remove_cvref_t<T>> {};

template <class A, typename... Ts> using holds = is_one_of<val_type_t<A>, Ts...>;

//test if my overloaded print operators would be used

template <class, typename = void> struct custom_print : public false_type {};
/*
template <class T> struct custom_print<T, enable_if_t<is_tuple<T>::value> > : public true_type {};
template <class T> struct custom_print<T, enable_if_t<iterable<T>::value
        && !is_str<T>::value>> : public true_type {};
template <class T> struct custom_print<T, enable_if_t<std_container<T>::value> > :
        public true_type {};
*/
//test if value type needs to have a custom print
template <class, typename = void> struct shallow : public false_type {};
template <class T> struct custom_print<T, enable_if_t<custom_print<T>::value> > :
        public integral_constant<bool, !custom_print<val_type_t<T> >::value> {};



string operator "" _s(const char* str, size_t len)
{
    return string{str, len};
}
u16string operator "" _s(const char16_t* str, size_t len)
{
    return u16string{str, len};
};
u32string operator "" _s(const char32_t* str, size_t len)
{
    return u32string{str, len};
}
wstring operator "" _s(const wchar_t* str, size_t len)
{
    return wstring{str, len};
}

bool debugPrint = false;
bool printLN = false;

template <class T> enable_if_t<is_tuple<T>::value, string> GET_START()
{
    return debugPrint ? "(" : "";
}

template <class T> enable_if_t<is_container<T>::value, string> GET_START()
{
    return debugPrint && holds<T, char>::value ? "{" : "";
}

string VARS_START()
{
    return debugPrint ? "[ " : "";
}

template <class T> enable_if_t<is_tuple<T>::value, string> GET_STEP()
{
    //scalar objects don't have an arbitrary length
    return (debugPrint ? ","_s : ""_s) + (is_scalar<T>::value ? " " : "\n");
}

template <class T> enable_if_t<is_container<T>::value, string> GET_STEP()
{
    if (holds<T, bool>::value || holds<T, char>::value)
    {
        return "";
    }
    return (debugPrint ? ","_s : ""_s) + (shallow<T>::value ? "\n" : " ");
}

string VARS_STEP(){
    return ", ";
}

template <class T> enable_if_t<is_tuple<T>::value &&
        !is_container<T>::value, string> GET_END()
{
    return debugPrint ? ")" : "";
}

template <class T> enable_if_t<is_container<T>::value, string>
        GET_END(bool atEnd = false)
{
    return (!atEnd && custom_print<T>::value ? "\n"_s : ""_s) +
            (debugPrint && !holds<T, char>::value ? ")" : "");
}

string VARS_END()
{
    return debugPrint ? " ]" : "";
}

const string delChar = "\b \b";


///after input/output with containers is properly fixed, these following macros will be unnecessary

template <typename A, typename B = int> inline constexpr int sgn (A a, B b = 0)
{
    return int ((a > b) - (a < b)); //returns -1 if a < b, 0 if a == b, 1 if a > b
}//C++20 spaceship operator alternative
template <typename A, typename B, typename C> inline constexpr int sgn (A a, B b, C tol)
{
    return int ((a > b + tol) - (a < b - tol)); //returns -1 if a < b, 0 if a == b, 1 if a > b
}//C++20 spaceship operator alternative

//in these for loop macros, the I character means inclusive and the E character means exclusive
//a character before the "FOR" refers to the starting pos; after the "FOR" refers to the end pos
#define FOR(i,n) IUPE(i, 0, n) //most commonly used version of the for loop
#define IUPI(i, s, e) for (int i = (s); i <= (e); ++i)
#define IUPE(i, s, e) for (int i = (s); i < (e); ++i)
#define EUPI(i, s, e) for (int i = (s); ++i <= (e);)
#define EUPE(i, s, e) for (int i = (s); ++i < (e);)
#define IDOWNI(i, s, e) for (int i = (s); i >= (e); --i)
#define IDOWNE(i, s, e) for (int i = (s); i > (e); --i)
#define EDOWNI(i, s, e) for (int i = (s); --i >= (e);)
#define EDOWNE(i, s, e) for (int i = (s); --i > (e);)
///these macros of filling with infinity will be removed later on

#define ARR(type, a, n) type a[n]; FOR(a##_i, n) { cin >> a[a##_i]; }
#define FARR(type, a, n, what) type a[n]; fill(a, a + n, what);
#define ARR2(type, a, m, n) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) { cin >> a[a##_i][a##_j]; } }
#define FARR2(type, a, m, n, what) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) {\
                                                                a[a##_i][a##_j] = what; } }


//returns the unstored array size

template <typename T, size_t S> inline constexpr int SIZE (const T (&t)[S]) 
{
    return int (S); //returns as integer to prevent confusing comparisons between signed and unsigned
}
template <class T> inline int SIZE (const T& t)
{
    return int (t.size()); //also returned as integer
}
template <class T> inline typename
        enable_if<!instant_size<T>() && forward_iter<T>(), int>::type SIZE (const T& t)
{
    return int (distance(t.begin(), t.end())); //also returned as integer
}
template <typename T> enable_if_t<is_arithmetic<T>::value, T> dist(const T& a, const T& b)
{
    return abs(a - b);
}
#define ASIZE(a) sizeof(a) / sizeof(a[0])

///these constants may be unnecessary but have good intentions
const double PI = 3.141592653589793;
const double EULER = 2.718281828459045;
const double GR = 1.618033988749895;
///shorter names for common container modifiers
#define empl emplace //1 way containers
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define popb pop_back
#define popf pop_front
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define mt make_tuple
#define F first //accessing 1st element in pair
#define S second //accessing 2nd element in pair

//similar to python
string operator * (string str, unsigned n)
{
    if (n == 0)
    {
        return "";
    }
    else if (n == 1 || str.empty())
    {
        return str;
    }

    const unsigned period = str.size();
    if (period == 1)
    {
        return string(n, str.front());
    }
    str.reserve(period * n);
    unsigned m;
    for (m = 2; m <= n; m *= 2)
    {
        str += str;
    }
    str.append(str.c_str(), (n - m / 2) * period);
    return str;
}

//commutative property
string operator * (unsigned n, const string& a)
{
    return a * n;
}

string capitalize(const string& a)
{
    return a.empty() ? "" : string(1, toupper(a[0])) + a.substr(1);
}

unsigned count(const string& a, const string& substr,
        unsigned start = 0, unsigned end = string::npos)
{
    unsigned out;
    for (out = 0; (start = a.find(substr, start)) < end; ++out, ++start) {}
    return out;
}

bool endsw(const string& a, const string& b)
{
    return SIZE(a) >= SIZE(b) && a.substr(SIZE(a) - SIZE(b)) == b;
}
string repl(const string& a, const string& old, const string& ne, unsigned n = string::npos)
{
    if (old.empty()) { return a; }
    string out;
    size_t prev = 0;
    for (size_t next = 0; n-- && (next = a.find(old, next)) != -1; prev = next)
    {
        out += a.substr(prev, next - prev) + ne;
        next += old.size();
    }
    return out + a.substr(prev);
}
template <class T> enable_if_t<iterable<T>::value && is_str<val_type_t<T> >::value, string>
        repl(const string& a, const T& old,
        const string& ne, unsigned n = string::npos)
{
    typedef pair<size_t, size_t> location;
    auto comp = [](const location& a, const location& b){ return a.F + a.S <= b.F; };
    set<location, decltype(comp)> to_replace(comp);
    for (const auto& i : old)
    {
        size_t size = SIZE(i);
        if (size)
        {
            for (size_t j = 0; (j = a.find(i, j)) != string::npos; j += size)
            {
                to_replace.emplace(j, size);
            }
        }
    }
    string out;
    size_t prev = 0;
    for (auto it = to_replace.begin(); n-- && it != to_replace.end(); ++it)
    {    
        out += a.substr(prev, it->F - prev) + ne;
        prev = it->F + it->S;
    }
    return out + a.substr(prev);
}
string expandtabs(const string& a, unsigned tabsize = 4)
{
    return repl(a, "\t", string(tabsize, ' '));
}
bool isalnums(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::isalnum) && !a.empty();
}
bool isalphas(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::isalpha) && !a.empty();
}
bool isdigits(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::isdigit) && !a.empty();
}
bool islowers(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::islower) && !a.empty();
}
bool isspaces(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::isspace) && !a.empty();
}
bool istitle(const string& a)
{
    bool anyUpper = false;
    for (unsigned i = 1; i < a.size(); ++i)
    {
        if (isupper(a[i]) && isalpha(a[i - 1]) || islower(a[i]) && !isalpha(a[i - 1]))
        {
            return false;
        }
        anyUpper |= isupper(a[i]);
    }
    return !a.empty() && (anyUpper || isupper(a[0]));
}
bool isuppers(const string& a)
{
    return all_of(a.cbegin(), a.cend(), ::isupper) && !a.empty();
}

using dummy = int[];

template <typename T, typename... Ts> string joins(const string& sep, const T& t, const Ts&... ts)
{
    stringstream ss;
    ss << t;
    void(dummy {0, (void(ss << sep << ts), 0)... } );
    return ss.str();
}
template <typename T, typename... Ts> string join(const T& t, const Ts&... ts)
{
    stringstream ss;
    ss << t;
    void(dummy {0, (void(ss << ts), 0)... } );
    return ss.str();
}
template <class... Ts> string joinstr(string t, const Ts&... ts)
{
    void(dummy{0, (void(t += ts), 0)... } );
    return t;
}

template <class... Ts> string joinstrs(const string& sep, string t, const Ts&... ts)
{
    void(dummy{0, (void(t += sep + ts), 0)... } );
    return t;
}
string strip(const string& a, const string& chars = " \t\n\v\f\r")
{
    unordered_set<char> toRepl(CALL(chars));
    unsigned l, r;
    for (l = 0; toRepl.count(a[l]) && l < a.size(); ++l) {}
    for (r = a.size(); toRepl.count(a[r - 1]) && r > 0; --r) {}
    return a.substr(l, r - l);
}
string std_strip(const string& a, const string& chars = " \t\n\v\f\r")
{
    //ttabt
    unsigned l = a.find_first_not_of(chars);
    return a.substr(l, a.find_last_not_of(chars) - l + 1);
}

string swapcase(string a)
{
    for (char& i : a)
    {
        i = isupper(i) ? tolower(i) : toupper(i);
    }
    return a;
}

string title(string a)
{
    for (unsigned i = 1; i < a.size(); ++i){
        a[i] = isalnum(a[i - 1]) ? tolower(a[i]) : toupper(a[i]);
    }
    return a;
}
string tolowers (string a)
{
    transform(ALL(a), begin(a), ::tolower);
    return a;
}
string touppers (string a)
{
    transform(ALL(a), begin(a), ::toupper);
    return a;
}
string zfill(const string& a, unsigned width)
{
    return string(width < a.size() ? 0 : width - a.size(), '0') + a;
}

template <typename T> string type_name()
{
    typedef typename remove_reference<T>::type noref;
    int status;
    string tname = typeid (noref).name();
    string demangled_name = abi::__cxa_demangle (tname.c_str(), nullptr, nullptr, &status);
    string out;
    if (status) { out = tname; }
    else
    {
        out = repl(repl(demangled_name, ils{"std::", " "}, ""), ",", ", ");
    }
    out = regex_replace(out, regex(R"(\B(const(?=volatile\b)|(const|volatile)\b))"), " $&");
    out = regex_replace(out, regex(R"((unsigned|long)(?=char|short|int|long))"), "$& ");
    if (is_const<noref>::value) { out += " const"; }
    if (is_volatile<noref>::value) { out += " volatile"; }
    if (is_lvalue_reference<T>::value) { out += "&"; }
    else if (is_rvalue_reference<T>::value) {out += "&&"; }
    return out;
}

//prints out string form of input type
template <typename T> string type_name (const T& t)
{
    return type_name<T>();
}

//basically printf for cerr
#define eprintf(format, ...) fprintf(stderr, format, __VA_ARGS__);

#define VARS(type, ...) type __VA_ARGS__; SCAN(__VA_ARGS__); //create and automatically scan them
template <typename... T> istream& FSCAN(istream& is, T&... t)
{
    void(dummy{0, (void(is >> t), 0)... });
    return is;
}
template <typename... T> istream& SCAN (T&... t) 
{
    return FSCAN(cin, t...);
}

#define SVARS(type, what, ...) type __VA_ARGS__; SET_TO(what, __VA_ARGS__);
#define ZERO(type, ...) SVARS(type, 0, __VA_ARGS__) //create & automatically set them to 0

template <typename T, typename F, typename... R> F& SET_TO (const T& what, F& f, R&... r)
{
    f = what;
    void(dummy{0, (void(r = what), 0)... });
    return f;
}
template <typename F, typename... R> F& SET0 (F& f, R&... r)
{ 
    return SET_TO(F(0), f, r...);
}

#define EL cout << '\n';
template <typename F, typename... R> ostream& FOUT (ostream& os, const F& f, const R&... t)
{
    os << VARS_START() << f;
    void (dummy{0, (void(os << VARS_STEP() << t), 0)...});
    return os << VARS_END() << '\n';
}
template <typename... R> ostream& OUT (const R&...r)
{ 
    return FOUT(cout, r...);
}
#define VEQ(a) join(#a, " => ", a)
#define VOUT(a) OUT(VEQ(a));

#define EXCEPTION(msg) throw join("Exception: ", msg, " [in ", __PRETTY_FUNCTION__,\
        " of line #", __LINE__, "]\n");
//if condition succeeds OR error occurs -> message of exception is printed
#define ASSERT(cond, msg) if (!(cond))\
{\
    EXCEPTION(msg);\
}\

//only sets a to b if b > a - commonly used
template <typename T> inline T sMax (T& a, const T& b)
{    
    return a = max (a, b);
}

//only sets a to b if b < a - commonly used
template <typename T> inline T sMin (T& a, const T& b)
{
    return a = min (a, b);
}

template <typename T> enable_if_t<is_unsigned<T>::value, bool> isPowOf2(T v)
{
    return v && !(v & (v - 1));
}
template <typename T> enable_if_t<is_signed<T>::value, bool> isPowOf2(T v)
{
    T a = v > 0 ? v : ~v;
    return !(a & (a - sgn(v)));
}

uint log2(uint x){
    ASSERT(x != 0, "Input must be positive.")
    return 31 - __builtin_clz(x);
}
ullng log2(ullng x){
    ASSERT(x != 0, "Input must be positive.")
    return 63 - __builtin_clzll(x);
}
template <typename T> enable_if_t<is_one_of<T, int, llng>::value> log2(T x)
{
    ASSERT(x > 0, "Input must be positive.")
    return log2(typename make_unsigned<T>::type(x));
}

const ullng powsOf10[] = {1, 10, 100, 1000,
        10000,  100000, 1000000, 10000000,
        100000000, 1000000000, 10000000000LL, 100000000000LL,
        1000000000000LL, 10000000000000LL, 100000000000000LL, 1000000000000000LL,
        10000000000000000LL, 100000000000000000LL, 1000000000000000000LL, 1000000000000000000LL};

template <typename T> enable_if_t<is_integral<T>::value, int> log10(T v)
{
    ASSERT(v > 0, "Input must be positive.")
    typedef typename conditional<numeric_limits<T>::digits < 31,
            uint, typename make_unsigned<T>::type>::type properInput;
    int t = (log2(properInput(v)) + 1) * 1233 >> 12;
    return t - (v < powsOf10[t]);
}

template <typename T> enable_if_t<is_unsigned<T>::value> nextPowOf2(T v){
    --v;
    for (int i = 1; i < numeric_limits<T>::digits; i <<= 1)
    {
        v |= v >> i;
    }
    return ++v;
}

ullng interleave(uint x, uint y){
    ullng z = 0;
    for (int i = 0; i < numeric_limits<uint>::digits; ++i) {
        z |= (x & 1uLL << i) << i | (y & 1uLL << i) << (i + 1);
    }
    return z;
}
llng interleave(int x, int y){
    llng z = 0;
    for (int i = 0; i < numeric_limits<uint>::digits; ++i) {
        z |= (x & 1LL << i) << i | (y & 1LL << i) << (i + 1);
    }
    return z;
}

template <typename T> enable_if_t<is_one_of<T, int, uint>::value, T> bitPermutation(T v){
    typedef typename make_unsigned<T>::type uT;
    T t = v | (v - T(1)); // t gets v's least significant 0 bits set to 1
    // Next set to 1 the most significant bit to change,
    // set to 0 the least significant ones, and add the necessary 1 bits.
    return (t + T(1)) | (((~t & -~t) - uT(1)) >> (__builtin_ctz(v) + 1));
}

template <typename T> enable_if_t<is_one_of<T, llng, ullng>::value, T> bitPermutation(T v){
    typedef typename make_unsigned<T>::type uT;
    T t = v | (v - T(1)); // t gets v's least significant 0 bits set to 1
    // Next set to 1 the most significant bit to change,
    // set to 0 the least significant ones, and add the necessary 1 bits.
    return (t + T(1)) | (((~t & -~t) - uT(1)) >> (__builtin_ctzll(v) + 1));
}

template <typename T> enable_if_t<is_unsigned<T>::value, T> isqrt(T num)
{
    T place = T(1) << sizeof(T) * 8 - 2;
    while (place > num)
    {
        place /= 4;
    }
    T root = 0;
    while (place)
    {
        if (num >= root + place)
        {
            num -= root + place;
            root += place * 2;
        }
        root /= 2;
        place /= 4;
    }
    return root;
}
template <typename T> enable_if_t<is_signed<T>::value && is_integral<T>::value, T> isqrt(T num)
{
    typedef typename make_unsigned<T>::type uT;
    ASSERT(num >= 0, "Input must be nonnegative.")
    return sqrt(uT(num));
}
unsigned cbrt(unsigned x)
{
    unsigned y = 0, b;
    for (int s = 30; s >= 0; s -= 3) 
    {
        y *= 2;
        b = 3 * y * (y + 1) + 1 << s;
        if (x >= b) 
        {
            x -= b;
            ++y;
        }
    }
    return y;
}
int cbrt(int x)
{
    if (x < 0) { return -int(cbrt(unsigned(-x))); }
    return cbrt(unsigned(x));
}

template <typename B, typename E> enable_if_t<is_integral<B>::value && is_unsigned<E>::value, B>
        ipow(B x, E n)
{
    B value = 1;
    do
    {
        if (n & 1) { value *= x; }
        n >>= 1;
        x *= x;
    }
    while (n);
    return value;
}

template <typename B, typename E> enable_if_t<is_integral<B>::value
        && is_signed<E>::value && is_integral<E>::value, B> ipow(B x, E n)
{
    ASSERT(x >= 0, "Input must be nonnegative")
    return ipow(x, typename make_unsigned<E>::type(n));
}
//get digit of a number (in base 10)
template <typename T> enable_if_t<is_signed<T>::value, int> dig(T a, int i)
{
    ASSERT(i >= 0, "Digit # must be nonnegative")
    ASSERT(i <= log10(a), "Digit # is too large")
    return abs(a) / powsOf10[i] % 10;
}
template <typename T> enable_if_t<is_unsigned<T>::value, int> dig(T a, int i)
{
    ASSERT(i >= 0, "Digit # must be nonnegative")
    ASSERT(i <= log10(a), "Digit # is too large")
    return a / powsOf10[i] % 10;
}

//get digit of a number of certain base
template <typename T> enable_if_t<is_unsigned<T>::value, int> dig (T a, int i, int base)
{
    ASSERT(i >= 0, "Digit # must be nonnegative")
    ASSERT(base > 1, "Base must be greater than 2")
    return a / ipow(base, i) % base;
}
template <typename T> enable_if_t<is_signed<T>::value, int> dig (T a, int i, int base)
{
    return dig(typename make_signed<T>::type(abs(a)), i, base);
}
template <typename T> enable_if_t<is_floating_point<T>::value, int> dig(T a, int i)
{
    if (i < 0)
    {
        a = modf(abs(a), nullptr);
        for (int j = 0; j < -i; ++j)
        {
            int integral;
            a *= 10;
            a = modf(a, &integral);
            a += integral % 10;
        }
        return a;
    }
    return int(abs(a) / powsOf10[i]) % 10;
}

//get bit in the binary form of a number
template <typename T> enable_if_t<is_integral<T>::value, bool> bit (T a, int i) 
{
    ASSERT(i >= 0, "Bit # must be nonnegative")
    ASSERT(i < numeric_limits<typename make_unsigned<T>::type>::digits, "Bit # is too large")
    return (a >> i) & 1;
}

//get bit mask from start to end
template <typename T = uint> inline T mask(int start, int end = numeric_limits<T>::digits()){
    return (1 << end - start) - 1 << start;
}


template <class T> enable_if_t<changes_front<T>::value,
        typename T::value_type> pop(T& t)
{
    typename T::value_type v = t.front();
    t.popf();
    return v;
}
template <class T> enable_if_t<can_change_back<T>::value,
        typename T::value_type> pop(T& t)
{
    typename T::value_type v = t.back();
    t.popb();
    return v;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                typename T::value_type> pop(T& t)
{
    typename T::value_type v = t.front();
    t.pop();
    return v;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        !is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                typename T::value_type> pop(T& t)
{
    typename T::value_type v = t.top();
    t.pop();
    return v;
}

///debugging macros
template <typename T> enable_if_t<is_arithmetic<T>::value, string>
        sepNum (T value, int amt = 3, const string& sep = "\'")
{
    stringstream ss; //formats a string of a number to have comma separators
    ss << fixed << value;
    return regex_replace (ss.str(), regex (join(R"(\B(?=(\d{)", amt, R"(})+(?!\d)\.?))")), sep);
}
/*


template <typename T> enable_if_t<!custom_print<T>::value, ostream&>
        INSERT(ostream& os, const T& t, bool b)
{
    return os << t;
}

//
template <class T> enable_if_t<is_tuple<T>::value
        && !tuple_size<T>::value, ostream&> INSERT(ostream& os, const T&, bool)
{
    return os << GET_START<T>() << GET_END<T>();
}

template <size_t N, class T> enable_if_t<is_tuple<T>::value
        && N == tuple_size<T>::value - 1, ostream&> INSERT(ostream& os, const T& t, bool b)
{
    return INSERT(os, get<N>(t), b) << GET_END<T>(b);
}

template <size_t N, class T> enable_if_t<is_tuple<T>::value
        && N < tuple_size<T>::value - 1, ostream&> INSERT(ostream& os, const T& t, bool b)
{
    return INSERT <N + 1> (INSERT(os, get<N>(t), false) << GET_STEP<T>(), t, b);
}
template <class T> enable_if_t<is_tuple<T>::value && tuple_size<T>::value, ostream&>
        INSERT(ostream& os, const T& t, bool b)
{
    return INSERT<0>(os << GET_START<T>(), t, b);
}


template <class T> enable_if_t<iterable<T>::value && two_way_iter<T>::value
        && !is_bounded_array<T>::value && !is_str<T>::value
        || is_bounded_array<T>::value && !holds<T, char>::value, ostream&>
        INSERT(ostream& os, const T& t, bool b)
{
    os << GET_START<T>();
    if (!t.empty())
    {
        const auto e = prev(end(t));
        for (auto it = begin(t); it != e; ++it)
        {
            INSERT(os, *it, false) << GET_STEP<T>();
        }
        INSERT(os, *e, b);
    }
    return os << GET_END<T>(b);
}

template <class T> enable_if_t<iterable<T>::value &&
        !two_way_iter<T>::value, ostream&> INSERT(ostream& os, const T& t, bool b) {
    os << GET_START<T>();
    if (!t.empty())
    {
        const auto e = t.end();
        if (b) 
        {
            auto it = t.begin();
            for (auto next = it; ++next != t.end(); ++it)
            {
                INSERT(os, *it, false) << GET_STEP<T>();
            }
            INSERT(os, *it, b);
        }
        else 
        {
            INSERT(os, *t.begin(), false);
            for (auto it = t.begin(); ++it != e; ++it)
            {
                INSERT(os << GET_STEP<T>(), *it, false);
            }
        }
    }
    return os << GET_END<T>();
}

template <class T> enable_if_t<is_adaptor<T>::value &&
        is_base_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
        ostream&> INSERT (ostream& os, T t, bool b)
{
    os << GET_START<T>();
    for (bool a = true; !t.empty(); a = false)
    {
        INSERT((a ? os : os << GET_STEP<T>()), pop(t), b && t.empty());
    }
    return os << GET_END<T>();
}
template <class T> enable_if_t <is_adaptor<T>::value &&
        !is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
        ostream&> INSERT (ostream& os, T t, bool b)
{
    typename T::container_type a;
    while (!t.empty()) { a.pf(pop(t)); }
    return INSERT(os, a, b);
}
template <class T> enable_if_t<custom_print<T>::value, ostream&> operator << (ostream& os, const T& t)
{
    return INSERT(os, t, printLN);
}

template <class M> enable_if_t<is_map<M>::value, val_type_t<M> >
        GET_DEF(const M& m, const typename M::mapped_type& k, const val_type_t<M>& def)
{
    typename M::const_iterator it = m.find(k);
    return it == m.cend() ? def : it->S;
}

template <class A> enable_if_t<is_associative<A>::value && !is_map<A>::value, val_type_t<A> >
        GET_DEF(const A& m, const val_type_t<A>& v, const val_type_t<A>& def)
{
    typename A::const_iterator it = m.find(v);
    return it == m.cend() ? def : *it;
}

//typename <class S> enable_if_t<is_sequential<S>::value, val_type_t>

unordered_map<char, bool> input_as{{'1',true},{'0',true}};


template <size_t N = 0, typename T> enable_if_t<is_tuple<T>::value
        && N == tuple_size<T>::value, istream&> operator >> (istream& is, T& t)
{
    return is;
}

template <size_t N = 0, typename T> enable_if_t<is_tuple<T>::value
        && N < tuple_size<T>::value, istream&> operator >> (istream& is, T& t)
{
    return operator >> <N + 1, T> (is >> get<N>(t), t);
}

/*
template <class T> enable_if<changes_front<T>::value && holds<T, char, bool>::value,
        istream&> operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        if (holds<T, char>::value) { copy(CRALL(a), front_inserter(t)); }
        else
        {
            for (auto it = a.crbegin(); it != a.crend(); ++it)
            {
                t.pf(GET_DEF(input_as, *it, false));
            }
        }
    }
    else { for (auto& i : t) { is >> i; } }
    return is;
}
*/
/*
template <class T> enable_if_t<can_change_back<T>::value && holds<T, char, bool>::value
        && !is_str<T>::value, istream&> operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        if (holds<T, char>::value) { copy(CALL(a), back_inserter(t)); }
        else
        {
            for (auto it = a.crbegin(); it != a.crend(); ++it)
            {
                t.pb((GET_DEF(input_as, *it, false));
            }
        }
    }
    else { for (auto& i : t) { is >> i; } }
    return is;
}
*/
/*
template <class T> enable_if_t<iterable<T>::value && !changes_front<T>::value
        && !can_change_back<T>::value && !is_associative<T>::value, istream&>
        operator >> (istream& is, T& t)
{
    for (auto& i : t) { is >> i; }
    return is;
}
*/
/*
template <class T> enable_if_t<is_map<T>::value, istream&> operator >> (istream& is, T& t)
{
    for (auto& i : t) { is >> i.S; }
    return is;
}
*/
/*
template <class T> enable_if_t<is_associative<T>::value && !is_map<T>::value &&
        holds<T, char, bool>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    if (holds<T, char>::value) { copy(CALL(a), inserter(t)); }
    else { for (auto i : a) { t.insert(GET_DEF(input_as, i, false)); } }
    return is;
}
*/
/*
template <class T> enable_if_t<is_adaptor<T>::value &&
        is_base_of<queue<val_type_t<T>, typename T::container_type>, T>::value
        && holds<T, char, bool>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    if (holds<T, char>::value) { for (auto i : a) { t.push(i); } }
    else { for (auto i : a) { t.push(GET_DEF(input_as, i, false)); } }
    return is;
}
*/
/*
template <class T> enable_if_t<is_adaptor<T>::value &&
        !is_base_of<queue<val_type_t<T>, typename T::container_type>, T>::value
        && holds<T, char, bool>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    if (holds<T, char>::value)
    {
        for (auto it = a.crbegin(); it != a.crend(); ++it) { t.push(it); }
    }
    else { for (auto i : a) { t.push(GET_DEF(input_as, i, false)); } }
    return is;
}
*/
//prints as much details of a variable
#define SHOW(a) eprintf("[%s %s called at line #%d in %s: ", type_name(a).c_str(), #a, __LINE__,\
    __PRETTY_FUNCTION__); debugPrint = true; cerr << a << "]\n"; debugPrint = false;
//makes stdin an input file and stdout an output file
#define TOFILE string name = argv[0]; name = name.substr(0, name.find_last_of(".")); \
    freopen(name + ".out", "w", stdout); freopen(name + ".in", "r", stdin);
//prints out details and nanosecond timing of a function and its arguments after execution
#define TIME(f) GET_TIME(f, type_name(f).c_str(), #f, __LINE__, __PRETTY_FUNCTION__);
//does the real timing; the macros just provide the details
template <typename T, typename... Ts> void GET_TIME (const T& f, const Ts&... args)
{
    typedef typename conditional<chrono::high_resolution_clock::is_steady,
                                chrono::high_resolution_clock, chrono::steady_clock>::type clock;
    auto s = clock::now();
    f();
    auto e = clock::now();
    eprintf("[%s %s called at line #%d in %s taking %s ns]\n", args...,
                        sepNum((e - s).count()).c_str());
}
//shorter names for the casts
#define scast static_cast
#define dcast dynamic_cast
#define ccast const_cast
#define rcast reinterpret_cast
//converts a string to raw string, but doesn't necessarily work with special characters that much
string asRaw(const string& a){
    umap<char, const char*> toRepl = {
            {'\a', "\\a"}, {'\b', "\\b"}, {'\t', "\\t"}, {'\n', "\\n"},
            {'\v', "\\v"}, {'\f', "\\f"}, {'\r', "\\r"},
            {'\"', "\\\""}, {'\'', "\\\'"}, {'\?', "\\\?"}, {'\\', "\\\\"}
            };
    stringstream ss;
    for (const char& c : a)
    {
        if (toRepl.count(c)) { ss << toRepl[c]; }
        else if (isprint(scast<unsigned char>(c))) { ss << c; }
        else
        {
            ss << "\\u" << hex << setfill('0') << setw(4) <<
                    scast<unsigned>(scast<unsigned char>(c));
        }
    }
    return ss.str();
}

//consecutive values must be increasing or equal

template <class I, class C> enable_if_t<in_iter<I>::value, bool>
                must_sorted(I first, I last, C c, bool canEqual = false){
    I n = first, p = first;
    for (++n; n != last && p != last; ++n, ++p) { if (!c(*p, *n)) { return false; } }
    return canEqual || *p != *first;
}

template <class I> enable_if_t<in_iter<I>::value, bool>
        uphill(I first, I last, bool canEqual = false)
{
    return must_sorted(first, last, less<val_type_t<I>>(), canEqual);
}

template <class I> enable_if_t<in_iter<I>::value, bool> ascending(I first, I last)
{
    return is_sorted(first, last, less_equal<val_type_t<I>>());
}
template <class I> enable_if_t<in_iter<I>::value, bool>
        downhill(I first, I last, bool canEqual = false)
{
    return must_sorted(first, last, greater<val_type_t<I> >(), canEqual);
}
template <class I> enable_if_t<in_iter<I>::value, bool> descending(I first, I last)
{
    return is_sorted(first, last, greater_equal<val_type_t<I> >());
}
template <class I> enable_if_t<in_iter<I>::value, bool> flat(I first, I last)
{
    return is_sorted(first, last, equal_to<val_type_t<I> >());
}
template <class T> enable_if_t<in_iter<T>::value, bool> distinct(const T& t)
{
    return t.size() == uset<val_type_t<T, 1>>(ALL(t)).size();
}
template <class I> enable_if_t<in_iter<I>::value, bool> distinct(I first, I last)
{
    return distance(first, last) == uset<val_type_t<I>>(first, last).size();
}

/*these functions replace <cmath>'s because instead of inputting an int pointer for a 2nd output,
the output comes as a pair*/
template <typename T> typename conditional<is_floating_point<T>::value, pair<T, T>, pd>::type
        modf(T t)
{
    typename conditional<is_floating_point<T>::value, T, double>::type param;
    typename conditional<is_floating_point<T>::value, T, double>::type result = modf(t, &param);
    return mp(result, param);
}
#define ln log
template <typename T> pair<typename conditional<is_floating_point<T>::value, T, double>::type, int>
        frexp(T t)
{
    int param;
    typename conditional<is_floating_point<T>::value, T, double>::type result = frexp(t, &param);
    return mp(result, param);
}
template <class T> pair<double, int> frexp(T t)
{
    int param;
    double result = frexp(t, &param);
    return mp(result, param);
}
//this isn't a replacement function; this is a logarithm function with a custom base
template <typename T> typename conditional<is_floating_point<T>::value, T, double>::type
        log(T b, T x)
{
    return log(x) / log(b);
}

template <typename T> pair<typename conditional<is_floating_point<T>::value, T, double>::type, int>
        remquo(T n, T d)
{
    int param;
    typename conditional<is_floating_point<T>::value, T, double>::type r = remquo(n, d, &param);
    return mp(r, param);
}

//converts std::min_element from pointer to reference
template <class I> enable_if_t<in_iter<I>::value, val_type_t<I>&> min_e(I first, I last)
{
    return *min_element(first, last);
}
template <class I, class C> enable_if_t<in_iter<I>::value, val_type_t<I>&>
        min_e(I first, I last, C c)
{
    return *min_element(first, last, c);
}
template <class I> enable_if_t<in_iter<I>::value, val_type_t<I>&> max_e(I first, I last)
{
    return *max_element(first, last);
}
template <class I, class C> enable_if_t<in_iter<I>::value, val_type_t<I>&>
        max_e(I first, I last, C c)
{
    return *max_element(first, last, c);
}


template <class T, typename I> auto at(T& t, const I& i) -> decltype(t.at(i))
{
    return t.at(i);
}
template <class T, size_t S, typename I> enable_if_t<is_signed<I>::value, T&> at(T (&t) [S], I i)
{
    if (!(i >= 0 && i < S))
    {
        throw out_of_range(join("what(): ", type_name(t), "::operator[]: __n (which is ",
                int(i), ")"));
    }
    return t[i];
}

template <class T, size_t S, typename I> enable_if_t<is_unsigned<I>::value, T&> at(T (&t) [S], I i)
{
    if (i >= S)
    {
        throw out_of_range(join("what(): ", type_name(t), "::operator[]: __n (which is ", i, ")"));
    }
    return t[i];
}

template <class T, typename I, typename... Is> val_type_t<T, sizeof...(Is) + 1>&
        at(T& t, const I& i, const Is&... is)
{
    return at(at(t, i), is...);
}
template <class T> val_type_t<T>& to(T& t, int i)
{
    return t[(i % SIZE(t) + SIZE(t)) % SIZE(t)];
}
template <class T, typename... Is> val_type_t<T, sizeof...(Is) + 1>&
        to(T& t, int i, Is... is)
{
    return to(to(t, i), is...);
}

template <class T> enable_if_t<random_iter<T>::value, bool> val(T& t, unsigned i)
{
    return i < SIZE(t);
}

template <class T, typename... Is> enable_if_t<random_iter<T>::value, bool>
        val(T& t, unsigned i, const Is&... is)
{
    return i < SIZE(t) && val(*next(t, i), is...);
}


template <class T> enable_if_t<is_map<T>::value, bool>
        val(const T& t, const typename T::key_type& i)
{
    return t.count(i);
}
template <class T, typename... Is> enable_if_t<is_map<T>::value, bool>
        val(const T& t, const typename T::key_type& i, const Is&... is)
{
    const auto it = t.find(i);
    return it != end(t) && val(*it, is...);
}

#define popcount __builtin_popcount //count how many bits are 1 in int
#define ffs __builtin_ffs
#define clz __builtin_clz //get number of leading 0s
#define ctz __builtin_ctz //get number of trailing 0s
#define clrsb __builtin_clrsb
#define powi __builtin_powi //power function where exponent is integer
#define bswap __builtin_bswap32 //reverse the bits
#define bswapl __builtin_bswap64 //reverse the bits

#define eps 1e-8 //epsilon
#define MOD 10000007

#define type_ind(type) type_index(typeid(type))

#define STATS(n, f) GET_STATS(n, f, type_name(f).c_str(), #f, sepNum(n).c_str(),\
        __LINE__, __PRETTY_FUNCTION__);
//args is for the arguments passed by STATS, not for f
template <typename F, typename... Args> void GET_STATS (int tests, F f, const Args&... args)
{
    typedef typename conditional<chrono::high_resolution_clock::is_steady,
            chrono::high_resolution_clock, chrono::steady_clock>::type clock;
    llng times[tests];
    FOR(i, tests)
    {
        auto s = clock::now();
        f();
        auto e = clock::now();
        times[i] = (e - s).count();
        //eprintf("Test #%d: %d ns\n", i, times[i]);
    }
    llng mean = accumulate(times, times + tests, 0) / tests, std_dev = 0;
    FOR(i, tests) { std_dev += pow(times[i] - mean, 2); }
    std_dev = sqrt(std_dev / (tests - 1));
    eprintf("[%s %s called %s times at line #%d in %s with mean %s ns and std deviation %s ns]\n",
            args..., sepNum(mean).c_str(), sepNum(std_dev).c_str());
}

#define TIE(t, type, ...) type __VA_ARGS__; tie(__VA_ARGS__) <<= t;
#define ignore2 ignore, ignore
#define ignore3 ignore2, ignore
#define ignore4 ignore3, ignore
#define ignore5 ignore4, ignore
#define ignore6 ignore5, ignore

template <size_t N = 0, class A, class B> enable_if_t<N >= tuple_size<A>::value
        || N >= tuple_size<B>::value, A&> operator <<= (A& a, const B&)
{
    return a;
}

template <size_t N = 0, class A, class B> enable_if_t<N < tuple_size<A>::value
        && N < tuple_size<B>::value, A&> operator <<= (A& a, const B& b)
{
    get<N>(a) = get<N>(b);
    return operator <<= <N + 1> (a, b);
}

template <size_t N, class A, class I> enable_if_t<N >= tuple_size<A>::value
        && is_iterator<I>::value, A&> tupCopy(A& a, I it, I end)
{
    return a;
}
template <size_t N, class A, class I> enable_if_t<N < tuple_size<A>::value
        && is_iterator<I>::value, A&> tupCopy(A& a, I it, I end)
{
    if (it != end)
    {
        get<N>(a) = *it;
        return tupCopy<N + 1>(a, ++it);
    }
    return a;
}
template <size_t N, class I, class T> enable_if_t<N >= tuple_size<T>::value && is_iterator<I>::value>
        tupCopy(I it, I end, const T& b) {}
template <size_t N, class I, class T> enable_if_t<N < tuple_size<T>::value && is_iterator<I>::value>
        tupCopy(I it, I end, const T& b)
{
    if (it != end)
    {
        *it = get<N>(b);
        return tupCopy<N + 1>(++it, b);
    }
}

template <class A, class B> enable_if_t<is_tuple<A>::value && iterable<B>::value, A&>
        operator <<= (A& a, const B& b)
{
    return tupCopy<0>(a, begin(b), end(b));
}
template <class A, class B> enable_if_t<iterable<A>::value && is_tuple<B>::value>
        operator <<= (A& a, const B& b)
{
    return tupCopy<0>(begin(a), end(a), b);
}

#define delf(c) c.erase(begin(c))
#define delb(c) c.erase(c.rbegin())


template <typename T> class chain_comparer
{
    reference_wrapper<const T> cur;
    bool b;
    public:
    chain_comparer(const T& a, bool b) : cur(a), b(b) {};
    
    chain_comparer& operator < (const T& a)
    {
        b &= cur < a;
        cur = a;
        return *this;
    }
    chain_comparer& operator > (const T& a)
    {
        b &= cur > a;
        cur = a;
        return *this;
    }
    chain_comparer& operator <= (const T& a)
    {
        b &= cur <= a;
        cur = a;
        return *this;
    }
    chain_comparer& operator >= (const T& a)
    {
        b &= cur >= a;
        cur = a;
        return *this;
    }
    chain_comparer& operator == (const T& a)
    {
        b &= cur == a;
        cur = a;
        return *this;
    }
    chain_comparer& operator != (const T& a)
    {
        b &= cur != a;
        cur = a;
        return *this;
    }
    operator bool() { return b; }
};
template <typename T> chain_comparer<T> chain(const T& t)
{
    return chain_comparer<T>(t, true);
}

template <typename T> bool operator <= (const unordered_set<T>& a, const unordered_set<T>& b)
{
    return all_of(a.cbegin(), a.cend(), [&b](const T& t){ return b.count(t); });
}
template <typename T> bool operator < (const unordered_set<T>& a, const unordered_set<T>& b)
{
    return a <= b && a.size() != b.size();
}
template <typename T> bool operator > (const unordered_set<T>& a, const unordered_set<T>& b)
{
    return b < a;
}
template <typename T> bool operator >= (const unordered_set<T>& a, const unordered_set<T>& b)
{
    return b <= a;
}
template <size_t A, size_t B> typename enable_if<(A <= B), bool>::type
        operator < (const bitset<A>& a, const bitset<B>& b)
{
    if ((b >> A).any()) { return true; }
    for (int i = A; --i >= 0; ) { if (a[i] ^ b[i]) { return b[i]; } }
    return false;
}
template <size_t A, size_t B> typename enable_if<(A > B), bool>::type
        operator < (const bitset<A>& a, const bitset<B>& b)
{
    if ((a >> B).any()) { return true; }
    for (int i = B; --i >= 0; ) { if (a[i] ^ b[i]) { return b[i]; } }
    return false;
}
template <size_t A, size_t B> bool operator <= (const bitset<A>& a, const bitset<B>& b)
{
    return !(b < a);
}
template <size_t A, size_t B> bool operator >= (const bitset<A>& a, const bitset<B>& b)
{
    return !(a < b);
}
template <size_t A, size_t B> bool operator > (const bitset<A>& a, const bitset<B>& b)
{
    return b < a;
}

template <typename T> unordered_set<T> operator | (const unordered_set<T>& a, const unordered_set<T>& b)
{
    unordered_set<T> out(a);
    copy(b.begin(), b.end(), inserter(out, out.begin()));
    return out;
}
template <typename T> unordered_set<T> operator & (const unordered_set<T>& a, const unordered_set<T>& b)
{
    unordered_set<T> out;
    copy_if(a.begin(), a.end(), inserter(out, out.begin()), [&b] (const T& t) { return b.count(t); } );
    return out;
}

template <typename T> unordered_set<T> operator - (const unordered_set<T>& a, const unordered_set<T>& b)
{
    unordered_set<T> out;
    copy_if(a.begin(), a.end(), inserter(out, out.begin()), [&b] (const T& t) { return !b.count(t); } );
    return out;
}

template <typename T> unordered_set<T> operator ^ (const unordered_set<T>& a, const unordered_set<T>& b)
{
    unordered_set<T> out;
    copy_if(a.cbegin(), a.cend(), inserter(out, out.begin()), [&b] (const T& t) { return !b.count(t); } );
    copy_if(b.cbegin(), b.cend(), inserter(out, out.begin()), [&a] (const T& t) { return !a.count(t); } );
    return out;
}

template <typename T> unordered_set<T>& operator |= (unordered_set<T>& a, const unordered_set<T>& b)
{
    copy(b.begin(), b.end(), inserter(a, a.begin()));
    return a;
}
template <typename T> unordered_set<T>& operator &= (unordered_set<T>& a, const unordered_set<T>& b)
{
    typename unordered_set<T>::iterator next = a.begin(), prev;
    while (next != a.cend()){
        prev = next++;
        if (!b.count(*prev)) { a.erase(prev); }
    }   
    return a;
}

template <typename T> unordered_set<T>& operator -= (unordered_set<T>& a, const unordered_set<T>& b)
{
    typename unordered_set<T>::iterator next = a.begin(), prev;
    while (next != a.cend())
    {
        prev = next++;
        if (b.count(*prev)) { a.erase(prev); }
    }   
    return a;
}

template <typename T> unordered_set<T>& operator ^= (unordered_set<T>& a, const unordered_set<T>& b)
{
    for (auto& i : b) { if (a.count(i)) { a.erase(i); } else { a.insert(i); } };
    return a;
}

#define APPLY(o, a, b) a = o(a); b = o(b);
#define APPLY3(o, a, b, c) APPLY(a, b) c = o(c);
#define APPLY4(o, a, b, c, d) APPLY3(a, b, c) d = o(d);
#define APPLY5(o, a, b, c, d, e) APPLY4(a, b, c, d); e = o(e);
#define APPLY6(o, a, b, c, d, e, f) APPLY5(a, b, c, d, e); f = o(f);

int main(int argc, char* argv[])
{
	//TOFILE
    debugPrint = true;
    






	cout.flush();
	fclose(stdout);
	return 0;
}
