/*
ID:
PROG:
LANG: C++
/**
 * ASCII Table: Lines (85) 100 -> 255
 * Operator Precedence Lines 9 -> 63
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
 * |          |   ++a   --a   |      Prefix increment and decrement	  |
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
typedef unsigned short ushort;
typedef unsigned char uchar;

template <typename T> inline std::size_t hash_combine(const std::size_t& seed, const T& v) {
    return seed ^ std::hash<T>(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
    template <typename S, typename T> struct hash<pair<S, T> > {
        inline size_t operator()(const pair<S, T>& v) const {
            return hash_combine(hash_combine(0, v.first), v.second);
        }
    };
    template <> void swap<int> (int& a, int& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<llng> (llng& a, llng& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<uint> (uint& a, uint& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<ullng> (ullng& a, ullng& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<char> (char& a, char& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<uchar> (uchar& a, uchar& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<short> (short& a, short& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<ushort> (ushort& a, ushort& b){
        a ^ b && (b ^= a ^= b, a ^= b);
    }
    template <> void swap<float> (float& a, float& b){
        swap(*(int*)&a, *(int*)&b);
    }
    template <> void swap<double> (double& a, double& b){
        swap(*(llng*)&a, *(llng*)&b);
    }
};

using namespace std;
using namespace placeholders;

///shorter typenames


//these typenames remove confusion on the types of priority queues
#define pqueue priority_queue
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

typedef pair<int, int> pi;
typedef pair<llng, llng> pl;
typedef pair<dbl, dbl> pd;
typedef pair<ldbl, ldbl> pld;

typedef vector<int> vi;
typedef vector<llng> vl;
typedef vector<dbl> vd;
typedef vector<ldbl> vld;

typedef stack<int> si;
typedef stack<llng> sl;
typedef stack<dbl> sd;
typedef stack<ldbl> sld;

typedef queue<int> qi;
typedef queue<llng> ql;
typedef queue<dbl> qd;
typedef queue<ldbl> qld;

typedef deque<int> di;
typedef deque<llng> dl;
typedef deque<dbl> dd;
typedef deque<ldbl> dld;

typedef pqueue<int> pqi;
typedef pqueue<llng> pql;
typedef pqueue<dbl> pqd;
typedef pqueue<ldbl> pqdl;

typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<pld> vpld;

typedef stack<pi> spi;
typedef stack<pl> spl;
typedef stack<pd> spd;
typedef stack<pld> spld;

typedef queue<pi> qpi;
typedef queue<pl> qpl;
typedef queue<pd> qpd;
typedef queue<pld> qpld;

typedef deque<pi> dpi;
typedef deque<pl> dpl;
typedef deque<pd> dpd;
typedef deque<pld> dpld;

typedef pqueue<pi> pqpi;
typedef pqueue<pl> pqpl;
typedef pqueue<pd> pqpd;
typedef pqueue<pld> pqpld;

#define ALL(c) begin(c), end(c) //used a lot in container/iterator functions + works with C-arrays
#define RALL(c) rbegin(c), rend(c)
#define CALL(c) (c).cbegin(), (c).cend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define AALL(a) a, a + sizeof(a) / sizeof(a[0])


template <typename...> struct make_void { typedef void type; };
template <typename... Ts> using void_t = typename make_void<Ts...>::type;




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
#define iterable_v(T) iterable<T>::value

template <class, typename = void> struct iter {};
template <class T> struct iter<T, typename enable_if<is_iterator<T>::value>::type> {
    typedef T type;
};

template <class T> struct iter<T, typename enable_if<iterable<T>::value>::type> {
    typedef decltype(begin(declval<T&>())) type;
};
template <class T> using iter_t = typename iter<T>::type;

template <class T> using random_iter = is_same<random_access_iterator_tag,
                                        typename iterator_traits<iter_t<T>>::iterator_category>;
template <class T> using two_way_iter = is_base_of<bidirectional_iterator_tag,
                                        typename iterator_traits<iter_t<T>>::iterator_category>;
template <class T> using forward_iter = is_base_of<forward_iterator_tag,
                                        typename iterator_traits<iter_t<T>>::iterator_category>;
template <class T> using out_iter = is_base_of<output_iterator_tag,
                                        typename iterator_traits<iter_t<T>>::iterator_category>;
template <class T> using in_iter = is_base_of<input_iterator_tag,
                                        typename iterator_traits<iter_t<T>>::iterator_category>;

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

//false trait class for determining containers
template <class, typename = void> struct is_container : public false_type {};
template <class T> struct is_container<T, void_t< // true trait class for determining containers
                typename T::iterator,
                typename T::const_iterator,
                typename T::difference_type,
                decltype(declval<T>().cbegin()),
                decltype(declval<T>().cend()),
                decltype(declval<T>() == declval<T>()),
                decltype(declval<T>() != declval<T>()),
                decltype(declval<T>().max_size())> > :
            public integral_constant<bool, std_container<T>::value && iterable<T>::value > {};

template <class, typename = void> struct is_tuple : public false_type {};
template <class T> struct is_tuple<T, void_t< // true trait class for determining containers
            decltype(T()),
            decltype(T(declval<T>())),
            decltype(declval<T>() == declval<T>()),
            decltype(declval<T>() < declval<T>()),
            decltype(tuple_size<T>::value)> > : public true_type {};

template <class, typename = void> struct is_associative : public false_type {};
template <class T> struct is_associative<T, void_t< // true trait class for determining containers
            typename T::key_type> > : public is_container<T> {};

template <class, typename = void> struct is_map : public false_type {};
template <class T> struct is_map<T, void_t< // true trait class for determining containers
            typename T::mapped_type> > : public is_associative<T> {};

template <class, size_t, typename = void> struct val_type { };
template <class T, size_t N> struct val_type<T, N, typename enable_if<N && iterable<T>::value &&
                                                                    !is_map<T>()>::type> {
    typedef typename val_type<decltype(*declval<iter_t<T>>()), N - 1>::type type;
};
template <class T, size_t N> struct val_type<T, N, typename enable_if<N && is_map<T>::value>::type>
{
    typedef typename val_type<typename T::mapped_type, N - 1>::type type;
};
template <class T, size_t N>
                    struct val_type<T, N, typename enable_if<N && is_iterator<T>::value>::type> {
    typedef typename val_type<typename iterator_traits<T>::value_type, N - 1>::type type;
};
template <class T> struct val_type<T, 0> {
    typedef T type;
};
template <class T, size_t N = 1> using val_type_t = typename val_type<T, N>::type;

template <class, typename = void> struct is_sequential : public false_type {};
template <class T> struct is_sequential<T, void_t< // true trait class for determining containers
                decltype(declval<T>().front())> > : public is_container<T> {};

template <class, typename = void> struct can_change_back : public false_type {};
template <class T> struct can_change_back<T, void_t< // true trait class for determining containers
            decltype(declval<T&>().push_back(declval<val_type_t<T>>()))> > :
                                        public is_sequential<T> {};

template <class, typename = void> struct changes_front : public false_type {};
template <class T> struct changes_front<T, void_t< // true trait class for determining containers
            decltype(declval<T&>().push_front(declval<val_type_t<T>>()))> > :
        public integral_constant<bool, is_sequential<T>::value && !can_change_back<T>::value> {};

template <class, typename = void> struct is_adaptor : public false_type {};
template <class T> struct is_adaptor<T, void_t<
                typename T::container_type> > : public std_container<T> {};

template <class, typename = void> struct instant_size : public false_type {};
template <class T> struct instant_size<T, void_t<decltype(declval<T>().size())> > :
                                                                                public true_type {};

template <class Tuple, size_t N, size_t Last, bool canEmpty> struct same_elements :
                public integral_constant<bool, is_same<typename tuple_element<N - 1, Tuple>::type,
    typename tuple_element<N, Tuple>::type>::value &&
                                            same_elements <Tuple, N + 1, Last, canEmpty>::value> {};
template <class Tuple, size_t N, bool canEmpty> struct same_elements<Tuple, N, N, canEmpty>
                                                                            : public true_type {};
template <class Tuple, bool canEmpty> struct same_elements<Tuple, 1, 0, canEmpty> :
                                                    public integral_constant<bool, canEmpty> {};
template <class Tuple, bool canEmpty = false> struct same_e :
                            public same_elements<Tuple, 1, tuple_size<Tuple>::value, canEmpty> {};

template <class> struct is_str : public false_type {};
template <class T> struct is_str<basic_string<T>> : public true_type {};

template <typename T> struct is_bounded_array : false_type {};
template <typename T, size_t N> struct is_bounded_array<T[N]> : true_type {};

template <typename T> struct remove_cvref {
    typedef typename remove_cv<typename remove_reference<T>::type>::type type;
};
template <typename T> using remove_cvref_t = typename remove_cvref<T>::type;

template <class, typename = void> struct customPrint : public false_type {};
template <class T> struct customPrint<T, typename enable_if<is_tuple<T>::value && !is_container<T>::value>::type> : public true_type {};
template <class T> struct customPrint<T, typename enable_if<
            is_bounded_array<T>::value && !is_same<char, remove_cvref_t<val_type_t<T>>>::value ||
                    iterable<T>::value && !is_array<T>::value && !is_str<T>::value ||
                                                is_adaptor<T>::value>::type> : public true_type {};

using dummy = int[];

template <typename T, typename B> using holds = is_same<val_type_t<T>, B>;

template <typename T, typename B> struct hasChar : public integral_constant<bool,
is_same<val_type_t<T>, char>::value || is_same<val_type_t<T>, signed char>::value ||
is_same<val_type_t<T>, unsigned char>::value || is_same<val_type_t<T>, wchar_t>::value ||
is_same<val_type_t<T>, char16_t>::value || is_same<val_type_t<T>, char32_t>::value> {};

template <class, typename, typename = void> struct access : public false_type {};
template <class T, typename A>
        struct access<T, A, void_t<decltype(declval<T&>()[declval<A>()]) > > : public true_type {};

bool debugPrint = true, printLN = false;

const struct sBeautifier{
    string a;
    enum class pos{
        start, step, end
    } type;
} varsStart{"v{", sBeautifier::pos::start},
  iterStart{"{", sBeautifier::pos::start},
  tupStart{"(", sBeautifier::pos::start},
  varsStep{",", sBeautifier::pos::step},
  varsEnd{"}v", sBeautifier::pos::end},
  iterEnd{"}", sBeautifier::pos::end},
  tupEnd{")", sBeautifier::pos::end};
const sBeautifier& iterStep(varsStep), tupStep(varsStep);
template <typename T = void> string GETSTR(const sBeautifier& a, const vector<bool>& b) {
    string out = !b.at(0) && debugPrint ? a.a : "";
    switch(a.type){
    case sBeautifier::pos::start:
        return out;
    case sBeautifier::pos::step:
        return out + (customPrint<T>::value ? '\n' : ' ');
    case sBeautifier::pos::end:
        return (!b.at(1) && customPrint<T>::value ? "\n" : "") + out;
    }
};
template <typename T = void> string GETSTR(const sBeautifier& a){
    return (debugPrint ? a.a : "") + (a.type == sBeautifier::pos::step ? " " : "");
}

const string delChar = "\b \b";


///after input/output with containers is properly fixed, these following macros will be unnecessary

template <typename A, typename B = int> inline constexpr int sgn (const A& a, const B& b = 0) {
    return int ((a > b) - (a < b)); //returns -1 if a < b, 0 if a == b, 1 if a > b
}//C++20 spaceship operator alternative
template <typename A, typename B, typename C> inline constexpr int sgn (const A& a, const B& b, const C& tol) {
    return int ((a > b + tol) - (a < b - tol)); //returns -1 if a < b, 0 if a == b, 1 if a > b
}//C++20 spaceship operator alternative

//in these for loop macros, the I character means inclusive and the E character means exclusive
//a character before the "FOR" refers to the starting pos; after the "FOR" refers to the end pos
#define FOR(i,n) IFORE(i,0,n) //most commonly used version of the for loop
#define FORI(i,n) IFORI(i,0,n) //similar but also includes end position
#define IFORI(i,s,n) for (int i = int(s); sgn(n,i) != sgn(s,n); i += n < s ? -1 : 1)
#define IFORE(i,s,n) for (int i = int(s); sgn(n,i) == sgn(n,s); i += n < s ? -1 : 1)
#define EFORI(i,s,n) \
    for (int i = int(s) + (n < s ? -1 : 1); sgn(n,i) != sgn(s,n); i += n < s ? -1 : 1)
#define EFORE(i,s,n) \
    for (int i = int(s) + (n < s ? -1 : 1); sgn(n,i) == sgn(n,s); i += n < s ? -1 : 1)
///these macros of filling with infinity will be removed later on
#define INF(type, a, n) type a[n]; fill(ALL(a), INT_MAX);
#define NINF(type, a, n) type a[n]; fill(ALL(a), INT_MIN);

#define ARR(type, a, n) type a[n]; FOR(a##_i, n) { cin >> a[a##_i]; }
#define FARR(type, a, n, what) type a[n]; fill(a, a + n, what);
#define ARR2(type, a, m, n) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) { cin >> a[a##_i][a##_j]; } }
#define FARR2(type, a, m, n, what) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) {\
                                                                a[a##_i][a##_j] = what; } }



template <typename T, size_t S> inline constexpr int SIZE (const T (&t)[S]) {//returns the unstored array size
    return int (S);//returns as integer to prevent confusing comparisons between signed and unsigned
}
template <class T> inline auto SIZE (const T& t) -> decltype(t.size(), int()) {
    return int (t.size()); //also returned as integer
}
template <class T> inline typename
    enable_if<!instant_size<T>() && forward_iter<T>(), int>::type SIZE (const T& t) {
    return int (distance(t.begin(), t.end())); //also returned as integer
}
template <typename T> typename enable_if<is_arithmetic<T>::value, T>::type dist(const T& a, const T& b){
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


string operator * (const string& a, size_t n){ //similar to Python
    string out;
    for (; n--; out += a) {}
    return out;
}
string operator * (const size_t& n, const string& a){ //commutative property
    return a * n;
}
//Python string methods

string capitalize(const string& a){
    return !a.size() ? "" : string(1, toupper(a[0])) + a.substr(1);
}

size_t count(const string& a, const string& substr, size_t start = 0,
                                                                const size_t& end = string::npos){
    size_t out;
    for (out = 0; (start = a.find(substr, start)) < end; ++out, ++start) {}
    return out;
}

bool endsw(const string& a, const string& b){
    return SIZE(a) >= SIZE(b) && a.substr(SIZE(a) - SIZE(b)) == b;
}
string repl(const string& a, const string& old, const string& ne, size_t n = -1){
    string out;
    int prev = 0;
    for (int next = 0; n-- && (next = a.find(old, next)) != -1; prev = next) {
        out += a.substr(prev, next - prev) + ne;
        next += SIZE(old);
    }
    return out + a.substr(prev);
}
string repl(string a, const initializer_list<string>& old, const string& ne){
    for_each(ALL(old), [&a, &ne] (const string& i) { a = repl(a, i, ne); } );
    return a;
}
string expandtabs(const string& a, const size_t& tabsize = 4){
    return repl(a, "\t", string(tabsize, ' '));
}
bool isalnum(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return isalnum(i); } ) && !a.size();
}
bool isalpha(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return isalpha(i); } ) && !a.size();
}
bool isdigit(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return isdigit(i); } ) && !a.size();
}
bool islower(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return islower(i); } ) && !a.size();
}
bool isspace(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return isspace(i); } ) && !a.size();
}
bool istitle(const string& a) {
    bool anyUpper = false;
    for (size_t i = 1; i < a.size(); ++i){
        if (isupper(a[i]) && isalpha(a[i - 1]) || islower(a[i]) && !isalpha(a[i - 1])){
            return false;
        }
        anyUpper |= isupper(a[i]);
    }
    return !a.empty() && (anyUpper || isupper(a[0]));
}
bool isupper(const string& a){
    return all_of(a.cbegin(), a.cend(), [] (const char& i) { return isupper(i); } ) && !a.size();
}

template <typename... T> string joins(const string& sep, const T&... t){
    stringstream ss;
    void(dummy {0, (void(ss << t << sep), 0)... } );
    ss << sep.size() * delChar;
    return ss.str();
}
template <typename... T> string join(const T&... t){
    stringstream ss;
    void(dummy {0, (void(ss << t), 0)... } );
    return ss.str();
}
string strip(const string& a, const string& chars = " \t\n\v\f\r"){
    unordered_set<char> toRepl(CALL(chars));
    size_t l, r;
    for (l = 0; toRepl.count(a[l]) && l < a.size(); ++l) {}
    for (r = a.size(); toRepl.count(a[r - 1]) && r > 0; --r) {}
    return a.substr(l, r - l);
}

string swapcase(string a){
    for_each(a.begin(), a.end(), [] (char& i) { i = isupper(i) ? tolower(i) : toupper(i); } );
    return a;
}

string title(string a){
    for (int i = 1; i < SIZE(a); ++i){
        a[i] = isalnum(a[i - 1]) ? tolower(a[i]) : toupper(a[i]);
    }
    return a;
}
string tolower (string a){
    for_each(ALL(a), [] (char& i) { i = tolower(i); } );
    return a;
}
string toupper (string a){
    for_each(ALL(a), [] (char& i) { i = toupper(i); } );
    return a;
}
string zfill(const string& a, const size_t& width){
    return string(width < a.size() ? 0 : width - a.size(), '0') + a;
}

template <typename T> string type_name() {
    typedef typename remove_reference<T>::type noref;
    int status;
    string tname = typeid (noref).name();
    string demangled_name = abi::__cxa_demangle (tname.c_str(), nullptr, nullptr, &status);
    return regex_replace(regex_replace(status ? tname :
                                repl(repl(demangled_name, {"std::", " "}, ""), ",", ", "),
    regex(R"(\B(const(?=volatile\b)|(const|volatile)\b))"), " $&"),
                         regex(R"((unsigned|long)(?=char|short|int|long))"), "$& ") +
            (is_const<noref>::value ? " const" : "") +
            (is_volatile<noref>::value ? " volatile" : "") +
            (is_lvalue_reference<T>::value ? "&" : "") +
            (is_rvalue_reference<T>::value ? "&&" : "");
}
template <typename T> string type_name (const T& t) {//prints out string form of input type
    return type_name<T>();
}

//basically printf for cerr
#define eprintf(format, ...) fprintf(stderr, format, __VA_ARGS__);

#define VARS(type, ...) type __VA_ARGS__; SCAN(__VA_ARGS__); //create and automatically scan them
template <typename... T> istream& FSCAN(istream& is, T&... t){
    void(dummy{0, (void(is >> t), 0)... });
    return is;
}
template <typename... T> istream& SCAN (T&... t) { //recursion
    return FSCAN(cin, t...);
}

#define SVARS(type, what, ...) type __VA_ARGS__; SET_TO(what, __VA_ARGS__);
#define ZERO(type, ...) SVARS(type, 0, __VA_ARGS__) //create & automatically set them to 0
template <typename T, typename F, typename... R> F& SET_TO (const T& what, F& f, R&... r) { //recursion
    f = what;
    void(dummy{0, (void(r = what), 0)... });
    return f;
}
template <typename F, typename... R> F& SET0 (F& f, R&... r) { //recursion
    return SET_TO(F(0), f, r...);
}

#define EL cout << '\n';
template <typename F, typename... R> ostream& FOUT (ostream& os, const F& f, const R&... t) { //called for the last variable so it prints new line
    os << GETSTR(varsStart) << f;
    void (dummy{0, (void(os << GETSTR(varsStep) << t), 0)...});
    return os << GETSTR(varsEnd) << '\n';
}
template <typename... R> ostream& OUT (const R&...r) { //recursion
    return FOUT(cout, r...);
}

#define EXCEPTION(msg) throw join("Exception: ", msg, " [in ", __PRETTY_FUNCTION__,\
                                                                    " of line #", __LINE__, "]\n");
//if condition succeeds OR error occurs -> message of exception is printed
#define TRY(cond, msg) try { if (!(cond)) { EXCEPTION(msg); } } catch(string s) {\
                                                                                cerr << s << '\n'; }

template <typename T> inline T sMax (T& a, const T& b){//only sets a to b if b > a - commonly used
    return a = max (a, b);
}
template <typename T> inline T sMin (T& a, const T& b){//only sets a to b if b < a - commonly used
    return a = min (a, b);
}

bool isPowOf2(const uint& v){
    return v && !(v & (v - 1));
}

inline int log2(const int& x) {
    TRY(x > 0, "Input must be positive");
    return x ? 31 - __builtin_clz(x) : 0;
}
inline unsigned log2(const unsigned& x){
    return x ? 31 - __builtin_clz(x) : 0;
}
int log10(const int& v) {
    TRY(v > 0, "Input must be positive");
    return (v >= 1000000000) ? 9 : (v >= 100000000) ? 8 : (v >= 10000000) ? 7 :
    (v >= 1000000) ? 6 : (v >= 100000) ? 5 : (v >= 10000) ? 4 :
    (v >= 1000) ? 3 : (v >= 100) ? 2 : (v >= 10) ? 1 : 0;
}
unsigned log10 (const unsigned& v){
    return (v >= 1000000000u) ? 9u : (v >= 100000000u) ? 8u : (v >= 10000000u) ? 7u :
    (v >= 1000000u) ? 6u : (v >= 100000u) ? 5u : (v >= 10000u) ? 4u :
    (v >= 1000u) ? 3u : (v >= 100u) ? 2u : (v >= 10u) ? 1u : 0u;
}

bool negIf(const int& v, const bool& fDontNegate){
    return (!fDontNegate ^ (!fDontNegate - 1)) * v;
}

unsigned nextPowOf2(unsigned v){
    --v;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return ++v;
}
ullng interleave(const uint& x, const uint& y){
    ullng z = 0ull;
    for (int i = 0; i < numeric_limits<uint>::digits; ++i) {
        z |= (x & 1u << i) << i | (y & 1u << i) << (i + 1);
    }
    return z;
}
uint bitPermutation(const uint& v){
    uint t = v | (v - 1u); // t gets v's least significant 0 bits set to 1
    // Next set to 1 the most significant bit to change,
    // set to 0 the least significant ones, and add the necessary 1 bits.
    return (t + 1u) | (((~t & -~t) - 1u) >> (__builtin_ctz(v) + 1u));
}


int sqrt(int num){
    TRY(num >= 0 && num <= INT_MAX / 2, "Input must be nonnegative and at most 1073741823")
    int place = 1 << sizeof(int) * 8 - 2;
    while (place > num) {
        place /= 4;
    }
    int root = 0;
    while (place){
        if (num >= root + place){
            num -= root + place;
            root += place * 2;
        }
        root /= 2;
        place /= 4;
    }
    return root;
}
unsigned sqrt(unsigned num){
    unsigned place = 1 << sizeof(int) * 8 - 2;
    while (place > num) {
        place /= 4;
    }
    unsigned root = 0;
    while (place){
        if (num >= root + place){
            num -= root + place;
            root += place * 2;
        }
        root /= 2;
        place /= 4;
    }
    return root;
}
int cbrt(int x) {
    bool neg = false;
    if (x < 0){
        neg = true;
        x = -x;
    }
    unsigned y = 0, b;
    for (int s = 30; s >= 0; s -= 3) {
        y *= 2;
        b = 3 * y * (y + 1) + 1 << s;
        if (x >= b) {
            x -= b;
            ++y;
        }
    }
    return neg ? -y : y;
}
unsigned cbrt(unsigned x){
    unsigned y = 0, b;
    for (int s = 30; s >= 0; s -= 3) {
        y *= 2;
        b = 3 * y * (y + 1) + 1 << s;
        if (x >= b) {
            x -= b;
            ++y;
        }
    }
    return y;
}

inline int dig (const int& a, const int& i, const int& base = 10) {//get digit of a number
    return int(double(a) / pow (base, i)) % base;
}
inline bool bit (const llng& a, const size_t& i) {//get bit in the binary form of a number
    return (a >> i) & 1;
}
template <typename T = int> inline T mask(const int& end, const int& start){
    return (1 << end - start) - 1 << start;
}
template <typename T = int> inline T mask(const int& start){
    return mask(numeric_limits<T>::digits(), start);
}


template <class T> typename enable_if<changes_front<T>::value,
                                                typename T::value_type>::type pop(T& t){
    typename T::value_type v = t.front();
    t.popf();
    return v;
}
template <class T> typename enable_if<can_change_back<T>::value,
                                                typename T::value_type>::type pop(T& t){
    typename T::value_type v = t.back();
    t.popb();
    return v;
}
template <class T> typename enable_if<is_adaptor<T>::value &&
                is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                                                    typename T::value_type>::type pop(T& t){
    typename T::value_type v = t.front();
    t.pop();
    return v;
}
template <class T> typename enable_if<is_adaptor<T>::value &&
                !is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                                                    typename T::value_type>::type pop(T& t){
    typename T::value_type v = t.top();
    t.pop();
    return v;
}

///debugging macros
template <typename T> string sepNum (const T& value, const int& amt = 3,
                                        const string& sep = "\'"){
    stringstream ss; //formats a string of a number to have comma separators
    ss << fixed << value;
    return regex_replace (ss.str(), regex (join(R"(\B(?=(\d{)", amt, R"(})+(?!\d)\.?))")), sep);
}



template <typename T> typename enable_if<!customPrint<T>::value, ostream&>::type INSERT(ostream& os, const T& t, const bool& b){
    return os << t;
}

template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
            && N == tuple_size<T>::value, ostream&>::type INSERT(ostream& os, const T& t, const bool& b) {
    return os << GETSTR<typename conditional<N, typename tuple_element<N - 1, T>::type,
                                                            void>::type>(tupEnd, {false, !!N});
}

template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
                && N < tuple_size<T>::value, ostream&>::type INSERT(ostream& os, const T& t, const bool& b) {
    return INSERT <N + 1, T> (INSERT(os << GETSTR<typename tuple_element<N, T>::type>(N ? tupStep :
                                        tupStart), get<N>(t), N >= tuple_size<T>::value - 1), t, b);
}

template <typename T, size_t S> typename enable_if<!is_same<T, char>::value, ostream&>::type
                                                    INSERT(ostream& os, const T (&t)[S], const bool& b){
    if (b){
        for (auto next = begin(t), it = next++; it != end(t); ++next, ++it){
            INSERT(os << (it == begin(t) ? GETSTR(iterStart) : GETSTR<T>(iterStep, {is_same<T, bool>::value})), *it, next == end(t));
        }
    } else {
        for (auto it = begin(t); it != end(t); ++it){
            INSERT(os << (it == begin(t) ? GETSTR(iterStart) : GETSTR<T>(iterStep, {is_same<T, bool>::value})), *it, false);
        }
    }
    return os << GETSTR<T>(iterEnd, {false, b});
}

template <class T> typename enable_if<iterable<T>::value && !is_array<T>::value &&
            !is_str<T>::value, ostream&>::type INSERT(ostream& os, const T& t, const bool& b) {
    if (b){
        for (auto next = t.begin(), it = next++; it != t.end(); ++next, ++it){
            INSERT(os << (it == t.begin() ? GETSTR(iterStart) : GETSTR<val_type_t<T>>(iterStep, {holds<T, char>::value || holds<T, bool>::value})), *it, next == end(t));
        }
    } else {
        for (auto it = t.begin(); it != t.end(); ++it){
            INSERT(os << (it == t.begin() ? GETSTR(iterStart, holds<T, char>::value) :
            GETSTR<val_type_t<T>>(iterStep, {holds<T, char>::value || holds<T, bool>::value})), *it, false);
        }
    }
    return os << GETSTR<val_type_t<T>>(iterEnd, {holds<T, char>::value, b});
}

template <class T> typename enable_if <is_adaptor<T>::value &&
                    is_base_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
                                                    ostream&>::type INSERT (ostream& os, T t, const bool& b){
    if (b){
        for (bool a = true; !t.empty(); a = false){
            val_type_t<T> v = pop(t);
            INSERT(os << (a ? GETSTR(iterStart, {holds<T, char>::value}) :
               GETSTR<val_type_t<T>>(iterStep, {holds<T, char>::value || holds<T, bool>::value})), v, t.empty());
        }
    } else {
        for (bool a = true; !t.empty(); a = false){
            INSERT(os << (a ? GETSTR(iterStart, {holds<T, char>::value}) :
               GETSTR<val_type_t<T>>(iterStep, {holds<T, char>::value || holds<T, bool>::value})), pop(t), false);
        }
    }
    return os << GETSTR<val_type_t<T>>(iterEnd, {holds<T, char>::value, b});
}
template <class T> typename enable_if <is_adaptor<T>::value &&
                !is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                                                    ostream&>::type INSERT (ostream& os, T t, const bool& b){
    typename T::container_type a;
    while (!t.empty()){
        a.pf(pop(t));
    }
    return INSERT(os, a, b);
}
template <class T> typename enable_if<customPrint<T>::value, ostream&>::type operator << (ostream& os, const T& t){
    return INSERT(os, t, printLN);
}


template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
            && N == tuple_size<T>::value, istream&>::type operator >> (istream& is, T& t) {
    return is;
}

template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
                && N < tuple_size<T>::value, istream&>::type operator >> (istream& is, T& t) {
    return operator >> <N + 1, T> (is >> get<N>(t), t);
}

template <class T> typename enable_if<changes_front<T>::value && (holds<T, char>::value ||
                            holds<T, bool>::value), istream&>::type operator >> (istream& is, T& t){
    if (t.empty()){
        string a;
        is >> a;
        for_each(CRALL(a), [&t] (const char& i) { t.pf(holds<T, bool>::value ? i != '0' : i); } );
    } else {
        for_each(ALL(t), [&is] (typename T::reference i) { is >> i; } );
    }
    return is;
}
template <class T> typename enable_if<can_change_back<T>::value && (holds<T, char>::value ||
                        holds<T, bool>::value) && !is_base_of<string, T>::value, istream&>::type
                                                                    operator >> (istream& is, T& t){
    if (t.empty()){
        string a;
        is >> a;
        for_each(CALL(a), [&t] (const char& i) { t.pb(holds<T, bool>::value ? i != '0' : i); } );
    } else {
        for_each(ALL(t), [&is] (typename T::reference i) { is >> i; } );
    }
    return is;
}
template <class T> typename enable_if<iterable<T>::value && !changes_front<T>::value &&
                        !can_change_back<T>::value, istream&>::type operator >> (istream& is, T& t){
    for_each(ALL(t), [&is] (val_type_t<T>& i) { is >> i; } );
    return is;
}

template <class T> typename enable_if<is_map<T>::value, istream&>::type
                                                                    operator >> (istream& is, T& t){
    for_each(ALL(t), [&is] (typename T::reference i) { is >> i.S; } );
    return is;
}
template <class T> typename enable_if<is_associative<T>::value && !is_map<T>::value &&
(holds<T, char>::value || holds<T, bool>::value), istream&>::type operator >> (istream& is, T& t){
    string a;
    is >> a;
    for_each(CALL(a), [&t] (const char& i) { t.insert(holds<T, bool>::value ? i != '0' : i); } );
    return is;
}
template <class T> typename enable_if<is_adaptor<T>::value &&
(holds<T, char>::value || holds<T, bool>::value), istream&>::type operator >> (istream& is, T& t){
    string a;
    is >> a;
    for_each(CALL(a), [&t] (const char& i) { t.push(holds<T, bool>::value ? i != '0' : i); } );
    return is;
}



//prints as much details of a variable
#define SHOW(a) eprintf("[%s %s called at line #%d in %s: ", type_name(a).c_str(), #a, __LINE__,\
__PRETTY_FUNCTION__); debugPrint = true; cerr << a << "]\n"; debugPrint = false;
//makes stdin an input file and stdout an output file
#define TOFILE(name) freopen(#name ".out", "w", stdout); freopen(#name ".in", "r", stdin);
//prints out details and nanosecond timing of a function and its arguments after execution
#define TIME(f) GET_TIME(f, type_name(f).c_str(), #f, __LINE__, __PRETTY_FUNCTION__);
//does the real timing; the macros just provide the details
template <typename T, typename... Ts> void GET_TIME (const T& f, const Ts&... args) {
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
    umap<char, const char*> toRepl = {{'\a', "\\a"}, {'\b', "\\b"}, {'\t', "\\t"}, {'\n', "\\n"},
                                    {'\v', "\\v"}, {'\f', "\\f"}, {'\r', "\\r"},
                                    {'\"', "\\\""}, {'\'', "\\\'"}, {'\?', "\\\?"}, {'\\', "\\\\"}};
    stringstream ss;
    for (const char& c : a){
        if (toRepl.count(c)){
            ss << toRepl[c];
        } else if (isprint(scast<unsigned char>(c))){
            ss << c;
        } else {
            ss << "\\u" << hex << setfill('0') << setw(4) <<
                                                        scast<unsigned>(scast<unsigned char>(c));
        }
    }
    return ss.str();
}

//consecutive values must be increasing or equal

template <class I, class C> typename enable_if<in_iter<I>::value, bool>::type
                must_sorted(const I& first, const I& last, const C& c, const bool& canEqual = 0){
    I n = first, p = first;
    for (++n; n != last && p != last; ++n, ++p){
        if (!c(*p, *n)){
            return false;
        }
    }
    return canEqual || *p != *first;
}

template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                        uphill(const I& first, const I& last, bool canEqual = 0){
    return must_sorted(first, last, less<val_type_t<I>>(), canEqual);
}

template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                                        ascending(const I& first, const I& last){
    return is_sorted(first, last, less_equal<val_type_t<I>>());
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                        downhill(const I& first, const I& last, bool canEqual = 0){
    return must_sorted(first, last, greater<val_type_t<I> >(), canEqual);
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                                        descending(const I& first, const I& last){
    return is_sorted(first, last, greater_equal<val_type_t<I> >());
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                                                flat(const I& first, const I& last){
    return is_sorted(first, last, equal_to<val_type_t<I> >());
}
template <class T> typename enable_if<in_iter<T>::value, bool>::type distinct(const T& t){
    return t.size() == uset<val_type_t<T, 1>>(ALL(t)).size();
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                                            distinct(const I& first, const I& last){
    return distance(first, last) == uset<val_type_t<I>>(first, last).size();
}

/*these functions replace <cmath>'s because instead of inputting an int pointer for a 2nd output,
the output comes as a pair*/
template <typename T> typename conditional<is_floating_point<T>::value, pair<T, T>, pd>::type
                                                                                modf(const T& t){
    typename conditional<is_floating_point<T>::value, T, double>::type param;
    typename conditional<is_floating_point<T>::value, T, double>::type result = modf(t, &param);
    return mp(result, param);
}
#define ln log
template <typename T>  pair<typename conditional<is_floating_point<T>::value, T, double>::type, int>
                                                                                frexp(const T& t){
    int param;
    typename conditional<is_floating_point<T>::value, T, double>::type result = frexp(t, &param);
    return mp(result, param);
}
template <class T> pair<double, int> frexp(const T& t){
    int param;
    double result = frexp(t, &param);
    return mp(result, param);
}
//this isn't a replacement function; this is a logarithm function with a custom base
template <typename T> typename conditional<is_floating_point<T>::value, T, double>::type
                                                                    log(const T& b, const T& x){
    return log(x) / log(b);
}

//Python's floating point modulus
template <typename T> inline typename enable_if<is_floating_point<T>::value, T>::type
                                                                operator % (const T& a, const T& b){
    return fmod(a, b);
}
template <typename T> pair<typename conditional<is_floating_point<T>::value, T, double>::type, int>
                                                                    remquo(const T& n, const T& d){
    int param;
    typename conditional<is_floating_point<T>::value, T, double>::type r = remquo(n, d, &param);
    return mp(r, param);
}

template <class I> typename enable_if<in_iter<I>::value, val_type_t<I>&>::type
                                            min_e(const I& first, const I& last){
    return *min_element(first, last);
}
template <class I, class C> typename enable_if<in_iter<I>::value, val_type_t<I>&>::type
                                                min_e(const I& first, const I& last, const C& c){
    return *min_element(first, last, c);
}
template <class I> typename enable_if<in_iter<I>::value, val_type_t<I>&>::type
                                            max_e(const I& first, const I& last){
    return *max_element(first, last);
}
template <class I, class C> typename enable_if<in_iter<I>::value, val_type_t<I>&>::type
                                            max_e(const I& first, const I& last, const C& c){
    return *max_element(first, last, c);
}

template <class T> typename enable_if<two_way_iter<T>::value, reverse_iterator<iter_t<T> > >::type
                                                                                    rbegin(T& t) {
    return reverse_iterator<iter_t<T> >(end(t));
}
template <class T> typename enable_if<two_way_iter<T>::value, reverse_iterator<iter_t<T> > >::type
                                                                                        rend(T& t) {
    return reverse_iterator<iter_t<T> >(begin(t));
}



template <class T, typename I> auto at(T& t, const I& i) -> decltype(t.at(i)) {
    return t.at(i);
}
template <class T, size_t S> T& at(T (&t) [S], const size_t& i){
    if (i >= S) {
        throw out_of_range(join("what(): ", type_name(t), "::operator[]: __n (which is ",
                                                int(i), " or ", i, ") >= _Nm (which is ", S, ")"));
    }
    return t[i];
}

template <class T, typename I, typename I2, typename... Is>
            val_type_t<T, sizeof...(Is) + 2>& at(T& t, const I& i, const I2& i2, const Is&... is) {
    return at(at(t, i), i2, is...);
}
template <class T> val_type_t<T>& to(T& t, const int& i) {
    return t[(i % SIZE(t) + SIZE(t)) % SIZE(t)];
}
template <class T, typename... Is> val_type_t<T, sizeof...(Is) + 2>&
                                        to(T& t, const int& i, const int& i2, const Is&... is) {
    return to(to(t, i), i2, is...);
}

template <class T> typename enable_if<is_sequential<T>::value && access<T, int>::value, bool>::type
                                                                            val(T& t, const int& i){
    return i < SIZE(t);
}
template <class T, typename I>
    typename enable_if<is_map<T>::value && access<T, I>::value, bool>::type val(T& t, const I& i){
    return t.count(i);
}

template <class T, typename I, typename I2, typename... Is>
            bool val(T& t, const I& i, const I2& i2, const Is&... is) {
    if (!val(t, i)){
        return false;
    }
    return val(at(t, i), i2, is...);
}

#define INARR(a) FOR(a##i, sizeof(a) / sizeof(a[0])) { cin >> a[a##i]; }
#define INARR2(a) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) { cin >> a[a##i][a##j]; } }

#define PARR(a) cout << GETSTR(iterStart, is_same<char, decay<decltype(a[0])>::type>::value);\
    bool a##step = is_same<bool, decay<decltype(a[0])>::type>::value || is_same<char, decay<decltype(a[0])>::type>::value;\
    FOR(a##i, sizeof(a) / sizeof(a[0])) {\
        cout << a[a##i] << GETSTR(iterStep, a##step); }\
    cout << GETSTR(iterStep, a##step).size() * delChar << GETSTR(iterEnd, is_same<char, decay<decltype(a[0])>::type>::value);

#define PARR2(a) \
    bool a##ends = is_same<char, decay<decltype(a[0][0])>::type>::value; \
    bool a##step = is_same<bool, decay<decltype(a[0][0])>::type>::value || a##ends;\
    cout << GETSTR(iterStart, a##ends);\
    FOR(a##i, sizeof(a) / sizeof(a[0])) {\
        cout << GETSTR(iterStart, a##ends);\
        FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) {\
            cout << a[a##i][a##j] << GETSTR(iterStep, a##step); }\
        cout << GETSTR(iterStep, a##step).size() * delChar << GETSTR(iterEnd, a##ends) << GETSTR(iterStep, a##step); }\
    cout << GETSTR(iterStep, a##step).size() * delChar << GETSTR(iterEnd, a##ends);
#define SARR(a, what) FOR(a##i, sizeof(a) / sizeof(a[0])) { a[a##i] = what; }
#define SARR2(a, what) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) { a[a##i][a##j] = what; } }

#define SARR3(a) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) {\
            FOR(a##k, sizeof(a[0][0]) / sizeof(a[0][0][0])) { a[a##i][a##j][a##k] = what; } } }
#define SARR4(a) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) {\
            FOR(a##k, sizeof(a[0][0]) / sizeof(a[0][0][0])) {\
            FOR(a##l, sizeof(a[0][0][0]) / sizeof(a[0][0][0][0])) {\
                                                        a[a##i][a##j][a##k][a##l] = what; } } } }
#define SARR5(a) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) {\
            FOR(a##k, sizeof(a[0][0]) / sizeof(a[0][0][0])) {\
            FOR(a##l, sizeof(a[0][0][0]) / sizeof(a[0][0][0][0])) {\
            FOR(a##m, sizeof(a[0][0][0][0]) / sizeof(a[0][0][0][0][0])) {\
                                                a[a##i][a##j][a##k][a##l][a##m] = what; } } } } }
#define SARR6(a) FOR(a##i, sizeof(a) / sizeof(a[0])) {\
            FOR(a##j, sizeof(a[0]) / sizeof(a[0][0])) {\
            FOR(a##k, sizeof(a[0][0]) / sizeof(a[0][0][0])) {\
            FOR(a##l, sizeof(a[0][0][0]) / sizeof(a[0][0][0][0])) {\
            FOR(a##m, sizeof(a[0][0][0][0]) / sizeof(a[0][0][0][0][0])) {\
            FOR(a##n, sizeof(a[0][0][0][0][0]) / sizeof(a[0][0][0][0][0][0])) {\
                                        a[a##i][a##j][a##k][a##l][a##m][a##n] = what; } } } } } }

#define popcount __builtin_popcount //count how many bits are 1 in int
#define ffs __builtin_ffs
#define clz __builtin_clz //get number of leading 0s
#define ctz __builtin_ctz //get number of trailing 0s
#define clrsb __builtin_clrsb
#define powi __builtin_powi //power function where exponent is integer
#define bswap __builtin_bswap32 //reverse the bits

#define eps 1e-8 //epsilon
#define MOD 10000007

#define type_ind(type) type_index(typeid(type))





int main() {
	//TOFILE( )
    debugPrint = 1;
    printLN = 1;








	cout.flush();
	fclose(stdout);
	return 0;
}

