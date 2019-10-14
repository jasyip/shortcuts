/*
ID:
PROG:
LANG: C++
*/
#include <iostream>
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cassert> 
#include <cfloat>
#include <climits> 
#include <cmath> 

#include <bitset> 
#include <map>
#include <queue> 
#include <set>
#include <unordered_set> 
#include <stack>
#include <utility> 
#include <vector> 
#include <forward_list>
#include <list> 
#include <complex> 
#include <deque> 
#include <unordered_map> 
#include <array> 
#include <tuple> 
#include <valarray> 


#include <iterator>
#include <functional> 
#include <iomanip> 
#include <chrono> 
#include <numeric>
#include <cctype> 
#include <cxxabi.h> 
#include <cstdarg> 
#include <regex> 
#include <cstdlib>


typedef long long llng;
typedef double dbl;
typedef long double ldbl;
typedef unsigned long long ullng;
typedef unsigned uint;

using namespace std;
using namespace placeholders;


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

#define ALL(c) begin(c), end(c) 
#define RALL(c) rbegin(c), rend(c) 
#define CALL(c) (c).cbegin(), (c).cend() 
#define CRALL(c) (c).crbegin(), (c).crend() 
#define AALL(a) a, a + sizeof(a) / sizeof(a[0]) 


template <typename...> struct make_void { typedef void type; };
template <typename... Ts> using void_t = typename make_void<Ts...>::type;

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

template <class, typename = void> struct iter {}; 
template <class T> struct iter<T, enable_if_t<is_iterator<T>::value> >
{
    typedef T type; 
};

template <class T> struct iter<T, enable_if_t<iterable<T>::value> >
{
    typedef decltype(begin(declval<T&>())) type; 
};

template <typename T> struct remove_cvref
{
    typedef typename remove_cv<typename remove_reference<T>::type>::type type;
};
template <typename T> using remove_cvref_t = typename remove_cvref<T>::type;


template <typename A, typename T, typename... Ts> struct is_one_of :
        public integral_constant<bool, is_one_of<T, A>::value || is_one_of<A, Ts...>::value> {}; 
template <typename B, typename D> struct is_one_of<B, D> : public integral_constant<bool,
        is_same<remove_cvref_t<B>, remove_cvref_t<D> >::value
        || is_base_of<typename remove_reference<B>::type, typename remove_reference<D>::type
        >::value> {};


template <class T> using iter_t = typename iter<T>::type;

template <class, typename = void> struct in_iter : public false_type {};
template <class T> struct in_iter<T, enable_if_t<is_one_of<input_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>::value> > : public true_type {};

template <class, typename = void> struct out_iter : public false_type {};
template <class T> struct out_iter<T, enable_if_t<is_one_of<output_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>::value> > : public true_type {};

template <class, typename = void> struct forward_iter : public false_type {};
template <class T> struct forward_iter<T, enable_if_t<is_one_of<forward_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>::value> > : public true_type {};

template <class, typename = void> struct two_way_iter : public false_type {};
template <class T> struct two_way_iter<T, enable_if_t<is_one_of<bidirectional_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>::value> > : public true_type {};

template <class, typename = void> struct random_iter : public false_type {};
template <class T> struct random_iter<T, enable_if_t<is_one_of<random_access_iterator_tag,
        typename iterator_traits<iter_t<T> >::iterator_category>::value> > : public true_type {};



template <class, typename = void> struct std_container : public false_type {};
template <class T> struct std_container<T, void_t<
        typename T::reference,
        typename T::const_reference,
        typename T::size_type,
        decltype(T(declval<T>())),
        decltype(declval<T>().~T()),
        decltype(declval<T>().empty()),
        decltype(declval<T&>().swap(declval<T&>())),
        decltype(swap(declval<T&>(), declval<T&>()))
        > > : public true_type {};


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


template <class> struct is_tuple : public false_type {};
template <typename... Ts> struct is_tuple<tuple<Ts...> > : public true_type {};
template <typename A, typename B> struct is_tuple<pair<A, B> > : public true_type {};

template <class, typename = void> struct safe_tuple_size {};
template <class T> struct safe_tuple_size<T, enable_if_t<!is_tuple<T>::value> >
        : public integral_constant<int, -1> {};
template <class T> struct safe_tuple_size<T, enable_if_t<is_tuple<T>::value> >
        : public tuple_size<T> {};

template <class, typename = void> struct is_associative : public false_type {};
template <class T> struct is_associative<T, void_t<
        typename T::key_type> > : public is_container<T> {};


template <class, typename = void> struct is_map : public false_type {};
template <class T> struct is_map<T, void_t<
        typename T::mapped_type> > : public is_associative<T> {};




template <class, typename = void> struct is_adaptor : public false_type {};
template <class T> struct is_adaptor<T, void_t<
        typename T::container_type> > : public std_container<T> {};



template <class, size_t, typename = void> struct val_type { };
template <class T, size_t N> struct val_type<T, N,
        enable_if_t<N && is_one_of<vector<bool>, T>::value> > 
{
    typedef bool type;
};

template <class T, size_t N> struct val_type<T, N, enable_if_t<N && iterable<T>::value &&
        !is_map<T>::value && !is_one_of<T, vector<bool> >::value> >
{
    typedef typename val_type<typename remove_reference<
            decltype(*declval<iter_t<T> >())>::type, N - 1>::type type;
};

template <class T, size_t N> struct val_type<T, N, enable_if_t<N && is_map<T>::value> >
{
    typedef typename val_type<typename T::mapped_type, N - 1>::type type;
};

template <class T, size_t N> struct val_type<T, N, enable_if_t<N && is_adaptor<T>::value> >
{
    typedef typename val_type<typename T::value_type, N - 1>::type type;
};

template <class T, size_t N> struct val_type<T, N, enable_if_t<N && is_iterator<T>::value> >
{
    typedef typename val_type<typename iterator_traits<T>::value_type, N - 1>::type type;
};
template <class T> struct val_type<T, 0>
{
    typedef T type;
};
template <class T, size_t N = 1> using val_type_t = typename val_type<T, N>::type;
template <class A, typename... Ts> using holds = is_one_of<val_type_t<A>, Ts...>;


template <class, typename = void> struct is_sequential : public false_type {};
template <class T> struct is_sequential<T, void_t<
        decltype(declval<T>().front())> > : public is_container<T> {};


template <class, typename = void> struct can_change_back : public false_type {};
template <class T> struct can_change_back<T, void_t<
        decltype(declval<T&>().push_back(declval<val_type_t<T> >()))> > :
        public is_sequential<T> {};


template <class, typename = void, typename = void> struct changes_front : public false_type {};
template <class T> struct changes_front<T, void_t< 
        decltype(declval<T&>().push_front(declval<val_type_t<T> >()))>,
        enable_if_t<is_sequential<T>::value && !can_change_back<T>::value> > : public true_type {};


template <class, typename = void> struct instant_size : public false_type {};
template <class T> struct instant_size<T, void_t<decltype(declval<T>().size())> > :
        public true_type {};


template <class, typename = void> struct is_str : public false_type {};
template <class T> struct is_str<T, enable_if_t<is_one_of<basic_string<typename T::value_type>,
        typename remove_reference<T>::type >::value> > : public true_type {};
template <class T> struct is_str<T, enable_if_t<is_pointer<T>::value && is_same<
        remove_cvref_t<typename remove_pointer<T>::type>, char>::value> > : public true_type {};
template <class T> struct is_str<T, enable_if_t<is_array<T>::value && is_same<
        remove_cvref_t<typename remove_extent<T>::type>, char>::value> > : public true_type {};

template <typename T> struct is_bounded_array : false_type {};
template <typename T, size_t N> struct is_bounded_array<T[N]> : true_type {};




template <class, typename = void> struct custom_print : public false_type {};
template <class T> struct custom_print<T, enable_if_t<is_tuple<T>::value> > : public true_type {};
template <class T> struct custom_print<T, enable_if_t<(iterable<T>::value || std_container<T>::value)
        && !is_str<T>::value> > : public true_type {};


template <class, typename = void> struct shallow : public false_type {};
template <class T> struct shallow<T, enable_if_t<custom_print<T>::value> > :
        public integral_constant<bool, !custom_print<val_type_t<T> >::value> {};

template <typename R, class F, typename... Args> struct is_invocable_r :
        is_constructible<function<typename conditional<is_function<R>::value, R&, R>::type(Args...)>,
        reference_wrapper<typename remove_reference<F>::type> > {};

template <class F, typename... Args> struct is_invocable : public is_invocable_r<void, F, Args...> {};


string operator "" _s(const char* str, size_t len) { return string{str, len}; }
u16string operator "" _s(const char16_t* str, size_t len) { return u16string{str, len}; }
u32string operator "" _s(const char32_t* str, size_t len) { return u32string{str, len}; }
wstring operator "" _s(const wchar_t* str, size_t len) { return wstring{str, len}; }

bool debugPrint = false;
bool printLN = false;

template <class T> enable_if_t<is_tuple<T>::value, string> GET_START()
{
    return debugPrint ? "(" : "";
}

template <class T> enable_if_t<iterable<T>::value || std_container<T>::value, string> GET_START()
{
    return debugPrint && !holds<T, char>::value ? "{" : "";
}

string VARS_START() { return debugPrint ? "[ " : ""; }

template <class T, size_t N> enable_if_t<is_tuple<remove_cvref_t<T> >::value, string> GET_STEP()
{
    
    return (debugPrint ? ","_s : ""_s)
            + (is_scalar<typename tuple_element<N, T>::type>::value ? " " : "\n");
}

template <class T> enable_if_t<(iterable<T>::value || std_container<T>::value)
        && holds<T, char, bool>::value, string> GET_STEP()
{
    return "";
}
template <class T> enable_if_t<(iterable<T>::value || std_container<T>::value)
        && !holds<T, char, bool>::value, string> GET_STEP()
{
    return (debugPrint ? ","_s : ""_s) + (printLN && !shallow<T>::value ? "\n" : " ");
}

string VARS_STEP() { return ", "; }

template <class T> enable_if_t<is_tuple<T>::value, string> GET_END()
{
    return debugPrint ? ")" : "";
}

template <class T> enable_if_t<iterable<T>::value || std_container<T>::value, string>
        GET_END(bool atEnd)
{
    return (printLN && !atEnd && !shallow<T>::value ? "\n"_s : ""_s)
            + (debugPrint && !holds<T, char>::value ? "}" : "");
}

string VARS_END()
{
    return debugPrint ? " ]" : "";
}

const string delChar = "\b \b";




template <typename A, typename B = int> inline constexpr int sgn (A a, B b = 0)
{
    return int ((a > b) - (a < b)); 
}
template <typename A, typename B, typename C> inline constexpr int sgn (A a, B b, C tol)
{
    return int ((a > b + tol) - (a < b - tol)); 
}



#define FOR(i,n) IUPE(i, 0, n) 
#define IUPI(i, s, e) for (int i = (s); i <= (e); ++i)
#define IUPE(i, s, e) for (int i = (s); i < (e); ++i)
#define EUPI(i, s, e) for (int i = (s); ++i <= (e);)
#define EUPE(i, s, e) for (int i = (s); ++i < (e);)
#define IDOWNI(i, s, e) for (int i = (s); i >= (e); --i)
#define IDOWNE(i, s, e) for (int i = (s); i > (e); --i)
#define EDOWNI(i, s, e) for (int i = (s); --i >= (e);)
#define EDOWNE(i, s, e) for (int i = (s); --i > (e);)


#define ARR(type, a, n) type a[n]; FOR(a##_i, n) { cin >> a[a##_i]; }
#define FARR(type, a, n, what) type a[n]; fill(a, a + n, what);
#define ARR2(type, a, m, n) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) { cin >> a[a##_i][a##_j]; } }
#define FARR2(type, a, m, n, what) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) {\
        a[a##_i][a##_j] = what; } }




template <typename T, size_t N> enable_if_t<!is_one_of<T, char>::value || N == 0, int>
        SIZE (const T (&t)[N]) 
{
    return N;
}
template <class T> enable_if_t<instant_size<T>::value, int> SIZE (const T& t)
{
    return t.size();
}
template <class T> enable_if_t<!instant_size<T>::value && in_iter<T>::value
        && !is_str<T>::value, int> SIZE (const T& t)
{
    return distance(begin(t), end(t));
}
template <class T> enable_if_t<is_str<T>::value
        && (is_pointer<T>::value || is_array<T>::value), int> SIZE (const T& t)
{
    return strlen(t);
}
template <class T> enable_if_t<is_tuple<T>::value, int> SIZE(const T&)
{
    return tuple_size<T>::value;
}

template <typename T> enable_if_t<is_arithmetic<T>::value, T> dist(const T& a, const T& b)
{
    return abs(a - b);
}
#define ASIZE(a) sizeof(a) / sizeof(a[0])


const double PI = 3.141592653589793;
const double EULER = 2.718281828459045;
const double GR = 1.618033988749895;

#define empl emplace 
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


string capitalize(string a)
{
    typename string::iterator first_letter = find_if(ALL(a), ::isalpha);
    if (first_letter != a.cend()) { *first_letter = toupper(*first_letter); }
    return a;
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
        repl(const string& a, const T& old, const string& ne, unsigned n = string::npos)
{
    typedef pair<size_t, size_t> location;
    auto comp = [](const location& a, const location& b) { return a.first + a.second <= b.first; };
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
        out += a.substr(prev, it->first - prev) + ne;
        prev = it->first + it->second;
    }
    return out + a.substr(prev);
}
string expandtabs(const string& a, unsigned tabsize = 4)
{
    return repl(a, "\t", string(tabsize, ' '));
}
bool isalnums(const string& a) { return all_of(a.cbegin(), a.cend(), ::isalnum) && !a.empty(); }
bool isalphas(const string& a) { return all_of(a.cbegin(), a.cend(), ::isalpha) && !a.empty(); }
bool isdigits(const string& a) { return all_of(a.cbegin(), a.cend(), ::isdigit) && !a.empty(); }
bool islowers(const string& a)
{
    bool has_alpha = false;
    for (char i : a) 
    {
        if (isalpha(i))
        {
            if (!islower(i)) { return false; }
            has_alpha = true;
        }
    }
    return has_alpha;
}
bool isspaces(const string& a) { return all_of(a.cbegin(), a.cend(), ::isspace) && !a.empty(); }
bool istitle(const string& a)
{
    bool anyUpper = false;
    for (unsigned i = 1; i < a.size(); ++i)
    {
        if (!(isupper(a[i]) && !isalpha(a[i - 1]) || islower(a[i]) && isalpha(a[i - 1])))
        {
            return false;
        }
        anyUpper |= isupper(a[i]);
    }
    return !a.empty() && (anyUpper || isupper(a[0]));
}
bool isuppers(const string& a)
{
    bool has_alpha = false;
    for (char i : a) 
    {
        if (isalpha(i))
        {
            if (!isupper(i)) { return false; }
            has_alpha = true;
        }
    }
    return has_alpha;
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
    unsigned l = a.find_first_not_of(chars);
    return a.substr(l, a.find_last_not_of(chars) - l + 1);
}

string swapcase(string a)
{
    for (char& i : a) { i = isupper(i) ? tolower(i) : toupper(i); }
    return a;
}

string title(string a)
{
    if (!a.empty()) { a[0] = toupper(a[0]); }
    for (unsigned i = 1; i < a.size(); ++i)
    {
        a[i] = isalpha(a[i - 1]) ? tolower(a[i]) : toupper(a[i]);
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
    return string(max(int(width - a.size()), 0), '0') + a;
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


template <typename T> string type_name (const T& t) { return type_name<T>(); }


#define eprintf(format, ...) fprintf(stderr, format, __VA_ARGS__);

#define VARS(type, ...) type __VA_ARGS__; SCAN(__VA_ARGS__); 
template <typename... T> istream& FSCAN(istream& is, T&... t)
{
    void(dummy{0, (void(is >> t), 0)... });
    return is;
}
template <typename... T> istream& SCAN (T&... t) { return FSCAN(cin, t...); }

#define SVARS(type, what, ...) type __VA_ARGS__; SET_TO(what, __VA_ARGS__);
#define ZERO(type, ...) SVARS(type, 0, __VA_ARGS__) 

template <typename T, typename F, typename... R> F& SET_TO (const T& what, F& f, R&... r)
{
    f = what;
    void(dummy{0, (void(r = what), 0)... });
    return f;
}
template <typename F, typename... R> F& SET0 (F& f, R&... r) { return SET_TO(F(0), f, r...); }

#define EL cout << '\n';
template <typename F, typename... R> ostream& FOUT (ostream& os, const F& f, const R&... t)
{
    os << VARS_START() << f;
    void (dummy{0, (void(os << VARS_STEP() << t), 0)...});
    return os << VARS_END() << '\n';
}
template <typename... R> ostream& OUT (const R&...r) { return FOUT(cout, r...); }
#define VEQ(a) join(#a, " => (", a, ")")
#define VOUT(a) OUT(VEQ(a));

#define EXCEPTION(type, ...) throw type(join("Exception: ", __VA_ARGS__, " [in ",\
        __PRETTY_FUNCTION__, " of line #", __LINE__, " of file ", __FILE__, "]\n"));

#define ASSERT(cond, type, ...) if (!(cond)) { EXCEPTION(type, __VA_ARGS__) }


template <typename T> inline T sMax (T& a, const T& b) { return a = max (a, b); }


template <typename T> inline T sMin (T& a, const T& b) { return a = min (a, b); }

template <typename T> enable_if_t<is_unsigned<T>::value, bool> isPowOf2(T v)
{
    return v && !(v & (v - 1));
}
template <typename T> enable_if_t<is_signed<T>::value, bool> isPowOf2(T v)
{
    T a = v > 0 ? v : ~v;
    return !(a & (a - sgn(v)));
}

uint log2(uint x)
{
    ASSERT(x, domain_error, "Input must be positive (given ", x, ").")
    return 31 - __builtin_clz(x);
}
ullng log2(ullng x)
{
    ASSERT(x, domain_error, "Input must be positive (given ", x, ").")
    return 63 - __builtin_clzll(x);
}
template <typename T> enable_if_t<is_one_of<T, int, llng>::value> log2(T x)
{
    ASSERT(x > 0, domain_error, "Input must be positive (given ", x, ").")
    return log2(typename make_unsigned<T>::type(x));
}

const ullng powsOf10[] = {1, 10, 100, 1000,
        10000,  100000, 1000000, 10000000,
        100000000, 1000000000, 10000000000LL, 100000000000LL,
        1000000000000LL, 10000000000000LL, 100000000000000LL, 1000000000000000LL,
        10000000000000000LL, 100000000000000000LL, 1000000000000000000LL, 1000000000000000000LL};

template <typename T> enable_if_t<is_integral<T>::value, int> log10(T v)
{
    ASSERT(v > 0, domain_error, "Input must be positive (given ", v, ").")
    typedef typename conditional<numeric_limits<T>::digits < 31,
            uint, typename make_unsigned<T>::type>::type properInput;
    int t = (log2(properInput(v)) + 1) * 1233 >> 12;
    return t - (v < powsOf10[t]);
}

template <typename T> enable_if_t<is_unsigned<T>::value> nextPowOf2(T v)
{
    --v;
    for (int i = 1; i < numeric_limits<T>::digits; i <<= 1) { v |= v >> i; }
    return ++v;
}

ullng interleave(uint x, uint y)
{
    ullng z = 0;
    for (int i = 0; i < numeric_limits<uint>::digits; ++i)
    {
        z |= (x & 1uLL << i) << i | (y & 1uLL << i) << (i + 1);
    }
    return z;
}
llng interleave(int x, int y)
{
    llng z = 0;
    for (int i = 0; i < numeric_limits<uint>::digits; ++i)
    {
        z |= (x & 1LL << i) << i | (y & 1LL << i) << (i + 1);
    }
    return z;
}

template <typename T> enable_if_t<is_one_of<T, int, uint>::value, T> bitPermutation(T v)
{
    T t = v | (v - T(1)); 
    
    
    return (t + T(1)) | (((~t & -~t) - typename make_unsigned<T>::type(1)) >> (__builtin_ctz(v) + 1));
}

template <typename T> enable_if_t<is_one_of<T, llng, ullng>::value, T> bitPermutation(T v)
{
    T t = v | (v - T(1)); 
    
    
    return (t + T(1)) | (((~t & -~t) - typename make_unsigned<T>::type(1)) >> (__builtin_ctzll(v) + 1));
}

template <typename T> enable_if_t<is_unsigned<T>::value, T> isqrt(T num)
{
    T place = T(1) << numeric_limits<T>::digits - 2;
    while (place > num) { place /= 4; }
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
    ASSERT(num >= 0, domain_error, "Input must be nonnegative (given ", num, ").")
    return sqrt(typename make_unsigned<T>::type(num));
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
    ASSERT(x >= 0, domain_error, "Input must be nonnegative (given ", x, ").")
    return ipow(x, typename make_unsigned<E>::type(n));
}

template <typename T> enable_if_t<is_signed<T>::value && is_integral<T>::value, int>
        dig(T a, int i)
{
    ASSERT(i >= 0, out_of_range, "Digit # must be nonnegative (given ", i, ").")
    return abs(a) / powsOf10[i] % 10;
}
template <typename T> enable_if_t<is_unsigned<T>::value, int> dig(T a, int i)
{
    ASSERT(i >= 0, out_of_range, "Digit # must be nonnegative (given ", i, ").")
    return a / powsOf10[i] % 10;
}


template <typename T> enable_if_t<is_unsigned<T>::value, int> dig (T a, int i, int base)
{
    ASSERT(i >= 0, out_of_range, "Digit # must be nonnegative (given ", i, ").")
    ASSERT(base > 1, invalid_argument, "Base must be greater than 2 (given ", base, ").")
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


template <typename T> enable_if_t<is_integral<T>::value, bool> bit (T a, int i) 
{
    ASSERT(i >= 0, out_of_range, "Bit # must be nonnegative (given ", i, ").")
    ASSERT(i < numeric_limits<typename make_unsigned<T>::type>::digits, out_of_range,
            "Bit # is too large (given ", i, ").")
    return (a >> i) & 1;
}


template <typename T = uint> inline T mask(int start, int end = numeric_limits<T>::digits())
{
    return (1 << end - start) - 1 << start;
}


template <class T> enable_if_t<changes_front<T>::value, val_type_t<T> > pop(T& t)
{
    val_type_t<T> v = t.front();
    t.popf();
    return v;
}
template <class T> enable_if_t<can_change_back<T>::value, val_type_t<T> > pop(T& t)
{
    val_type_t<T> v = t.back();
    t.popb();
    return v;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        is_one_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
        val_type_t<T> > pop(T& t)
{
    val_type_t<T> v = t.front();
    t.pop();
    return v;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        !is_one_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
        val_type_t<T> > pop(T& t)
{
    val_type_t<T> v = t.top();
    t.pop();
    return v;
}



template <typename T> enable_if_t<is_integral<T>::value, string>
        sepNum (T value, int amt = 3, const string& sep = "\'", int base = 10)
{
    if (!value) { return "0"; }
    string out;
    T n = abs(value);
    for (int i = 0; n; ++i)
    {
        out.push_back('0' + n % base);
        n /= base;
        if (amt && n && i % amt == amt - 1) { out += sep; }
    }
    if (value < 0) { out.push_back('-'); }
    reverse(ALL(out));
    return out;
}
template <typename T> enable_if_t<is_floating_point<T>::value, string>
        sepNum (T value, int amt = 3, const string& sep = "\'")
{
    return regex_replace (to_string(value), regex (join(R"(\B(?=(\d{)", amt, R"(})+(?!\d)\.?))")),
            sep);
}

/*
template <typename T> enable_if_t<is_arithmetic<T>::value, string>
        sepNum (T value, int amt = 3, const string& sep = "\'")
{
    return regex_replace (to_string(value), regex (join(R"(\B(?=(\d{)", amt, R"(})+(?!\d)\.?))")),
            sep);
}
*/

template <typename T> enable_if_t<!custom_print<T>::value, ostream&>
        INSERT(ostream& os, const T& t, bool)
{
    return os << t;
}

template <class T> enable_if_t<is_tuple<T>::value
        && !safe_tuple_size<T>::value, ostream&> INSERT(ostream& os, const T&, bool)
{
    return os << GET_START<T>() << GET_END<T>(false);
}

template <size_t N, class T> enable_if_t<is_tuple<T>::value
        && N == safe_tuple_size<T>::value - 1, ostream&> INSERT(ostream& os, const T& t, bool b)
{
    return INSERT(os, get<N>(t), b) << GET_END<T>();
}

template <size_t N, class T> enable_if_t<is_tuple<T>::value
        && N < safe_tuple_size<T>::value - 1, ostream&> INSERT(ostream& os, const T& t, bool b)
{
    return INSERT <N + 1> (INSERT(os, get<N>(t), false) << GET_STEP<T, N>(), t, b);
}
template <class T> enable_if_t<is_tuple<T>::value && safe_tuple_size<T>::value, ostream&>
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
    if (SIZE(t))
    {
        const auto e = prev(end(t));
        for (auto it = begin(t); it != e; ++it) { INSERT(os, *it, false) << GET_STEP<T>(); }
        INSERT(os, *e, b);
    }
    return os << GET_END<T>(b);
}

template <class T> enable_if_t<iterable<T>::value &&
        !two_way_iter<T>::value, ostream&> INSERT(ostream& os, const T& t, bool b)
{
    os << GET_START<T>();
    if (!t.empty())
    {
        auto it = begin(t);
        const auto e = end(t);
        if (b) 
        {
            for (auto next = it; ++next != e; ++it)
            {
                INSERT(os, *it, false) << GET_STEP<T>();
            }
            INSERT(os, *it, true);
        }
        else 
        {
            INSERT(os, *it, false);
            while (++it != e) { INSERT(os << GET_STEP<T>(), *it, false); }
        }
    }
    return os << GET_END<T>(b);
}

template <class T> enable_if_t<is_adaptor<T>::value &&
        is_one_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
        ostream&> INSERT (ostream& os, T t, bool b)
{
    os << GET_START<T>();
    for (bool a = true; !t.empty(); a = false)
    {
        auto i = pop(t);
        INSERT((a ? os : os << GET_STEP<T>()), i, b && t.empty());
    }
    return os << GET_END<T>(b);
}
template <class T> enable_if_t <is_adaptor<T>::value &&
        !is_one_of<queue<val_type_t<T>, typename T::container_type>, T>::value,
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


unordered_map<char, bool> input_as {{'1', true}, {'0', false}};


template <size_t N = 0, typename T> enable_if_t<is_tuple<T>::value
        && N == safe_tuple_size<T>::value, istream&> operator >> (istream& is, T& t)
{
    return is;
}

template <size_t N = 0, typename T> enable_if_t<is_tuple<T>::value
        && N < safe_tuple_size<T>::value, istream&> operator >> (istream& is, T& t)
{
    return operator >> <N + 1, T> (is >> get<N>(t), t);
}

template <class T> enable_if_t<changes_front<T>::value && holds<T, char>::value, istream&>
        operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        move(a.rbegin(), a.rend(), front_inserter(t));
    }
    else { for (auto& i : t) { is >> i; } }
    return is;
}
template <class T> enable_if_t<changes_front<T>::value && holds<T, bool>::value, istream&>
        operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        for (auto it = a.crbegin(); it != a.crend(); ++it) { t.pf(input_as[*it]); }
    }
    else
    {
        for (auto& i : t)
        {
            char c;
            is >> c;
            i = input_as[c];
        }
    }
}
template <class T> enable_if_t<can_change_back<T>::value && holds<T, char>::value
        && !is_str<T>::value, istream&> operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        move(a.begin(), a.end(), back_inserter(t));
    }
    else { for (auto& i : t) { is >> i; } }
    return is;
}
template <class T> enable_if_t<can_change_back<T>::value && holds<T, bool>::value,
        istream&> operator >> (istream& is, T& t)
{
    if (t.empty())
    {
        string a;
        is >> a;
        for (auto i : a) { t.pb(input_as[i]); }
    }
    else
    {
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            char c;
            is >> c;
            *it = input_as[c];
        }
    }
    return is;
}
template <class T> enable_if_t<iterable<T>::value && !((changes_front<T>::value
        || can_change_back<T>::value) && holds<T, char, bool>::value
        || is_map<T>::value
        || is_associative<T>::value && holds<T, char, bool>::value) && !holds<T, bool>::value,
        istream&> operator >> (istream& is, T& t)
{
    for (auto& i : t) { is >> i; }
    return is;
}
template <class T> enable_if_t<iterable<T>::value && !((changes_front<T>::value
        || can_change_back<T>::value) && holds<T, char, bool>::value
        || is_map<T>::value
        || is_associative<T>::value && holds<T, char, bool>::value) && holds<T, bool>::value,
        istream&> operator >> (istream& is, T& t)
{
    for (auto& i : t)
    {
        char c;
        is >> c;
        i = input_as[c];
    }
    return is;
}
template <class T> enable_if_t<is_map<T>::value && !holds<T, bool>::value, istream&>
        operator >> (istream& is, T& t)
{
    for (auto& i : t) { is >> i.second; }
    return is;
}
template <class T> enable_if_t<is_map<T>::value && holds<T, bool>::value, istream&>
        operator >> (istream& is, T& t)
{
    for (auto& i : t)
    {
        char c;
        is >> c;
        i.second = input_as[c];
    }
    return is;
}
template <class T> enable_if_t<is_associative<T>::value && !is_map<T>::value &&
        holds<T, char>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    move(a.begin(), a.end(), inserter(t));
    return is;
}
template <class T> enable_if_t<is_associative<T>::value && !is_map<T>::value &&
        holds<T, bool>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    for (auto i : a) { t.insert(input_as[i]); } 
}
template <class T> enable_if_t<is_one_of<queue<char, typename T::container_type>, T>::value,
        istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    for (auto i : a) { t.push(i); }
    return is;
}
template <class T> enable_if_t<is_one_of<queue<bool, typename T::container_type>, T>::value,
        istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    for (auto i : a) { t.push(input_as[i]); }
    return is;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        !is_one_of<queue<char, typename T::container_type>, T>::value
        && holds<T, char>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    for (auto it = a.crbegin(); it != a.crend(); ++it) { t.push(*it); }
    return is;
}
template <class T> enable_if_t<is_adaptor<T>::value &&
        !is_one_of<queue<bool, typename T::container_type>, T>::value
        && holds<T, bool>::value, istream&> operator >> (istream& is, T& t)
{
    string a;
    is >> a;
    for (auto it = a.crbegin(); it != a.crend(); ++it) { t.push(input_as[*it]); }
    return is;
}

#define SHOW(a) eprintf("[%s %s called at line #%d in %s: ", type_name(a).c_str(), #a, __LINE__,\
    __PRETTY_FUNCTION__); debugPrint = true; cerr << a << "]\n"; debugPrint = false;

#define TOFILE string name = argv[0]; name = name.substr(0, name.find_last_of(".")); \
    freopen(name + ".out", "w", stdout); freopen(name + ".in", "r", stdin);

#define TIME(f) GET_TIME(f, type_name(f).c_str(), #f, __LINE__, __PRETTY_FUNCTION__);

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

#define scast static_cast
#define dcast dynamic_cast
#define ccast const_cast
#define rcast reinterpret_cast


string asRaw(const string& a)
{
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



template <class I, class C> enable_if_t<in_iter<I>::value, bool>
                strict_sorted(I first, I last, C c, bool canEqual = false)
{
    if (first == last) { return true; }
    I n = first, p = first;
    for (; ++n != last; ++p) { if (c(*n, *p)) { return false; } }
    return canEqual || *p != *first;
}

template <class I> enable_if_t<in_iter<I>::value, bool>
        uphill(I first, I last, bool canEqual = false)
{
    return strict_sorted(first, last, less<val_type_t<I>>(), canEqual);
}

template <class I> enable_if_t<in_iter<I>::value, bool> ascending(I first, I last)
{
    return is_sorted(first, last, less_equal<val_type_t<I>>());
}
template <class I> enable_if_t<in_iter<I>::value, bool>
        downhill(I first, I last, bool canEqual = false)
{
    return strict_sorted(first, last, greater<val_type_t<I> >(), canEqual);
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
    return SIZE(t) == uset<val_type_t<T, 1>>(ALL(t)).size();
}
template <class I> enable_if_t<in_iter<I>::value, bool> distinct(I first, I last)
{
    return distance(first, last) == uset<val_type_t<I>>(first, last).size();
}

/*these functions replace <cmath>'s because instead of inputting an int pointer for a 2nd output,
the output comes as a pair*/
template <typename T> enable_if_t<is_floating_point<T>::value, T> modf(T t)
{
    T param;
    T result = modf(t, &param);
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

template <typename T> pair<typename conditional<is_floating_point<T>::value, T, double>::type, int>
        remquo(T n, T d)
{
    int param;
    typename conditional<is_floating_point<T>::value, T, double>::type r = remquo(n, d, &param);
    return mp(r, param);
}


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
template <class T, size_t S, typename I> enable_if_t<is_integral<I>::value, T&> at(T (&t) [S], I i)
{
    ASSERT(i >= 0 && i < S, out_of_range,
            "what(): ", type_name(t), "::operator[]: __n (which is ", i, ")")
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
template <class T, typename... Is> enable_if_t<!is_map<T>::value, bool>
        val(const T& t, unsigned i, const Is&... is)
{
    return val(t, i) && val(t[i], is...);
}


template <class M> enable_if_t<is_map<M>::value, val_type_t<M> >
        get_def(const M& m, const typename M::mapped_type& k, const val_type_t<M>& def)
{
    typename M::const_iterator it = m.find(k);
    return it == m.cend() ? def : it->second;
}

template <class A> enable_if_t<is_associative<A>::value && !is_map<A>::value, val_type_t<A> >
        get_def(const A& m, const val_type_t<A>& v, const val_type_t<A>& def)
{
    typename A::const_iterator it = m.find(v);
    return it == m.cend() ? def : *it;
}

template <class R> enable_if_t<random_iter<R>::value, val_type_t<R> >
        get_def(const R& r, unsigned i, const val_type_t<R>& def)
{
    return val(r, i) ? r[i] : def;
}


#define popcount __builtin_popcount 
#define ffs __builtin_ffs
#define clz __builtin_clz 
#define ctz __builtin_ctz 
#define clrsb __builtin_clrsb
#define powi __builtin_powi 
#define bswap __builtin_bswap32 
#define bswapl __builtin_bswap64 

#define eps 1e-8 
#define MOD 10000007

#define type_ind(type) type_index(typeid(type))

#define STATS(n, f) GET_STATS(n, f, type_name(f).c_str(), #f, sepNum(n).c_str(),\
        __LINE__, __PRETTY_FUNCTION__);

template <typename F, typename... Args> void GET_STATS (int tests, F f, const Args&... args)
{
    typedef typename conditional<chrono::high_resolution_clock::is_steady,
            chrono::high_resolution_clock, chrono::steady_clock>::type clock;
    ullng times[tests];
    FOR(i, tests)
    {
        auto s = clock::now();
        f();
        auto e = clock::now();
        times[i] = (e - s).count();
        
    }
    ullng mean = accumulate(times, times + tests, 0ull) / tests;
    ldbl std_dev = 0;
    FOR(i, tests) { std_dev += pow(ldbl(llng(times[i] - mean)), 2); }
    std_dev = sqrt(std_dev / (tests - 1));
    eprintf("[%s %s called %s times at line #%d in %s with mean %s ns and std deviation %.3Le]\n",
            args..., sepNum(mean).c_str(), std_dev);
}

#define TIE(t, type, ...) type __VA_ARGS__; tie(__VA_ARGS__) <<= t;
#define ignore2 ignore, ignore
#define ignore3 ignore2, ignore
#define ignore4 ignore3, ignore
#define ignore5 ignore4, ignore
#define ignore6 ignore5, ignore

template <size_t N = 0, class A, class B> enable_if_t<N >= safe_tuple_size<A>::value
        || N >= safe_tuple_size<B>::value, A&> operator <<= (A& a, const B&)
{
    return a;
}

template <size_t N = 0, class A, class B> enable_if_t<N < safe_tuple_size<A>::value
        && N < safe_tuple_size<B>::value, A&> operator <<= (A& a, const B& b)
{
    get<N>(a) = get<N>(b);
    return operator <<= <N + 1> (a, b);
}

template <size_t N, class A, class I> enable_if_t<N >= safe_tuple_size<A>::value
        && is_iterator<I>::value, A&> tupCopy(A& a, I it, I end)
{
    return a;
}
template <size_t N, class A, class I> enable_if_t<N < safe_tuple_size<A>::value
        && is_iterator<I>::value, A&> tupCopy(A& a, I it, I end)
{
    if (it != end)
    {
        get<N>(a) = *it;
        return tupCopy<N + 1>(a, ++it);
    }
    return a;
}
template <size_t N, class I, class T> enable_if_t<N >= safe_tuple_size<T>::value
        && is_iterator<I>::value> tupCopy(I it, I end, const T& b) {}
template <size_t N, class I, class T> enable_if_t<N < safe_tuple_size<T>::value
        && is_iterator<I>::value> tupCopy(I it, I end, const T& b)
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
        b = b && cur < a;
        cur = a;
        return *this;
    }
    chain_comparer& operator > (const T& a)
    {
        b = b && cur > a;
        cur = a;
        return *this;
    }
    chain_comparer& operator <= (const T& a)
    {
        b = b && cur <= a;
        cur = a;
        return *this;
    }
    chain_comparer& operator >= (const T& a)
    {
        b = b && cur >= a;
        cur = a;
        return *this;
    }
    chain_comparer& operator == (const T& a)
    {
        b = b && cur == a;
        cur = a;
        return *this;
    }
    chain_comparer& operator != (const T& a)
    {
        b = b && cur != a;
        cur = a;
        return *this;
    }
    operator bool() { return b; }
};
template <typename T> chain_comparer<T> st(const T& t)
{
    return chain_comparer<T>(t, true);
}
template <class, typename = void> struct is_tree_set : public false_type {};
template <class T> struct is_tree_set<T, enable_if_t<is_one_of<T,
        set<typename T::key_type, typename T::key_compare> >::value> > : public true_type {};

template <class, typename = void> struct is_uset : public false_type {};
template <class T> struct is_uset<T, enable_if_t<is_one_of<T,
        unordered_set<typename T::key_type, typename T::hasher, typename T::key_equal> >::value> >
        : public true_type {};

template <class T> struct is_set : public integral_constant<bool, is_tree_set<T>::value
        || is_uset<T>::value> {};

template <class T> enable_if_t<is_set<T>::value, bool> operator <= (const T& a, const T& b)
{
    for (const auto& i : a) { if (!b.count(i)) { return false; } }
    return true;
}
template <class T> enable_if_t<is_set<T>::value, bool> operator < (const T& a, const T& b)
{
    return a <= b && a.size() != b.size();
}
template <class T> enable_if_t<is_set<T>::value, bool> operator > (const T& a, const T& b)
{
    return b < a;
}
template <class T> enable_if_t<is_set<T>::value, bool> operator >= (const T& a, const T& b)
{
    return b <= a;
}


template <class T> enable_if_t<is_tree_set<T>::value, T> operator | (T a, const T& b)
{
    a.insert(b.cbegin(), b.cend());
    return a;
}
template <class T> enable_if_t<is_uset<T>::value, T> operator | (T a, const T& b)
{
    a.reserve(a.size() + b.size());
    a.insert(b.cbegin(), b.cend());
    return a;
}
template <class T> enable_if_t<is_tree_set<T>::value, T> operator & (const T& a, const T& b)
{
    T out;
    if (a.size() < b.size()) { for (const auto& i : a) { if (b.count(i)) { out.insert(i); } }}
    else  { for (const auto& i : b) { if (a.count(i)) { out.insert(i); } } }
    return out;
}
template <class T> enable_if_t<is_uset<T>::value, T> operator & (const T& a, const T& b)
{
    T out;
    if (a.size() < b.size())
    {
        out.reserve(a.size());
        for (const auto& i : a) { if (b.count(i)) { out.insert(i); } }
    }
    else
    {
        out.reserve(b.size());
        for (const auto& i : b) { if (a.count(i)) { out.insert(i); } }
    }
    return out;
}

template <class T> enable_if_t<is_tree_set<T>::value, T> operator - (const T& a, const T& b)
{
    T out;
    for (const auto& i : a) { if (!b.count(i)) { out.insert(i); } }
    return out;
}
template <class T> enable_if_t<is_uset<T>::value, T> operator - (const T& a, const T& b)
{
    T out;
    out.reserve(a.size());
    for (const auto& i : a) { if (!b.count(i)) { out.insert(i); } }
    return out;
}
template <class T> enable_if_t<is_tree_set<T>::value, T> operator ^ (const T& a, const T& b)
{
    T out;
    for (const auto& i : a) { if (!b.count(i)) { out.insert(i); } }
    for (const auto& i : b) { if (!a.count(i)) { out.insert(i); } }
    return out;
}
template <class T> enable_if_t<is_uset<T>::value, T> operator ^ (const T& a, const T& b)
{
    T out;
    out.reserve(a.size() + b.size());
    for (const auto& i : a) { if (!b.count(i)) { out.insert(i); } }
    for (const auto& i : b) { if (!a.count(i)) { out.insert(i); } }
    return out;
}

template <class A, class B> enable_if_t<is_set<A>::value && is_set<B>::value, bool>
        disjoint (const A& a, const B& b)
{
    if (a.size() < b.size()) { for (const auto& i : a) { if (b.count(i)) { return false; } } }
    else { for (const auto& i : b) { if (a.count(i)) { return false; } } }
    return true;
}
template <class A, class B> enable_if_t<is_set<A>::value && is_set<B>::value, bool>
        ADD_DISJOINT(A& a, const B& b)
{
    for (const auto& i : b) { if (a.count(&i)) { return false; } }
    return true;
}
template <class A, class B, class... C> enable_if_t<is_set<A>::value && is_set<B>::value, bool>
        ADD_DISJOINT(A& a, const B& b, const C&... c)
{
    for (const auto& i : b) { if (!a.insert(&i).second) { return false; } }
    return ADD_DISJOINT(a, c...);
}
template <class A, class... B> enable_if_t<is_tree_set<A>::value, bool>
        disjoint(const A& a, const B&... b)
{
    auto comp = [&a](typename A::const_pointer e1, typename A::const_pointer e2)
    {
        return a.key_comp()(*e1, *e2);
    };
    set<typename A::const_pointer, decltype(comp)> cp(comp);
    return ADD_DISJOINT(cp, a, b...);
}
template <class A, class... B> enable_if_t<is_uset<A>::value, bool>
        disjoint(const A& a, const B&... b)
{
    auto h = [&a] (typename A::const_pointer e1) { return a.hash_function()(*e1); };
    auto comp = [&a](typename A::const_pointer e1, typename A::const_pointer e2)
    {
        return a.key_eq()(*e1, *e2);
    };
    unordered_set<typename A::const_pointer, decltype(h), decltype(comp)> cp(0, h, comp);
    return ADD_DISJOINT(cp, a, b...);
}


template <class T> enable_if_t<is_tree_set<T>::value, T&> operator |= (T& a, const T& b)
{
    a.insert(b.cbegin(), b.cend());
    return a;
}
template <class T> enable_if_t<is_uset<T>::value, T&> operator |= (T& a, const T& b)
{
    a.reserve(a.size() + b.size());
    a.insert(b.cbegin(), b.cend());
    return a;
}
template <class T> enable_if_t<is_set<T>::value, T&> operator &= (T& a, const T& b)
{
    typename T::iterator next = a.begin(), prev;
    while (next != a.cend())
    {
        prev = next++;
        if (!b.count(*prev)) { a.erase(prev); }
    }   
    return a;
}
template <class T> enable_if_t<is_set<T>::value, T&> operator -= (T& a, const T& b)
{
    typename T::iterator next = a.begin(), prev;
    while (next != a.cend())
    {
        prev = next++;
        if (b.count(*prev)) { a.erase(prev); }
    }   
    return a;
}

template <class T> enable_if_t<is_set<T>::value, T&> operator ^= (T& a, const T& b)
{
    typename T::iterator next = b.cbegin(), prev;
    T to_add;
    while (next != b.cend())
    {
        prev = next++;
        auto found = a.find(*prev);
        if (found != a.cend()) { a.erase(found); } else { to_add.insert(*prev); }
    }
    return a |= to_add;
}

#define APPLY(o, a, b) a = o(a); b = o(b);
#define APPLY3(o, a, b, c) APPLY(a, b) c = o(c);
#define APPLY4(o, a, b, c, d) APPLY3(a, b, c) d = o(d);
#define APPLY5(o, a, b, c, d, e) APPLY4(a, b, c, d); e = o(e);
#define APPLY6(o, a, b, c, d, e, f) APPLY5(a, b, c, d, e); f = o(f);

template <class T, typename = void> struct can_reserve : public false_type {};
template <class T> struct can_reserve<T, void_t<decltype(declval<T&>().reserve())> > :
        public std_container<T> {};

template <class T> enable_if_t<can_reserve<T>::value> try_reserving(T& t, unsigned n)
{
    t.reserve(n);
}
template <class T> enable_if_t<!can_reserve<T>::value> try_reserving(T&, unsigned) {}


template <class T> enable_if_t<can_change_back<T>::value && two_way_iter<T>::value, T&>
        MULTIPLY (T& t, int frac, double dec = 0.0)
{
    const unsigned period = t.size();
    if (period == 1)
    {
        t.insert(t.end(), frac - 1, t.front());
        return t;
    }
    try_reserving(t, period * (frac + dec));
    unsigned m;
    for (m = 2; m <= frac; m *= 2) { t.insert(t.end(), t.cbegin(), t.cend()); }
    t.insert(t.cend(), t.cbegin(), next(t.cbegin(), round(period * (frac - m / 2 + dec))));
    return t;
}
template <class T> enable_if_t<can_change_back<T>::value && two_way_iter<T>::value, T&>
        DIVIDE(T& t, double n)
{
    t.erase(n < 0.5 ? next(t.begin(), round(t.size() * n))
            : prev(t.begin(), round(t.size() * (1 - n))), t.cend());
    return t;
}
template <class T> enable_if_t<changes_front<T>::value, T&>
        MULTIPLY (T& t, int frac, double dec = 0.0)
{
    typename T::const_iterator prev = t.cbegin();
    unsigned period = 0;
    for (auto next = t.cbegin(); ++next != t.cend(); ++prev) { ++period; }
    if (period == 1)
    {
        t.insert_after(t.cbefore_begin(), frac - 1, t.front());
        return t;
    }
    unsigned m;
    for (m = 2; m <= frac; m *= 2) { prev = t.insert_after(prev, t.cbegin(), t.cend()); }
    unsigned e = period * (frac - m / 2 + dec);
    if (e) { t.insert_after(prev, t.cbegin(), next(t.cbegin(), e + 1)); }
    return t;
}

template <class T> enable_if_t<changes_front<T>::value, T&> DIVIDE(T& t, double amt)
{
    t.erase(next(t.begin(), t.size() * amt), t.cend());
    return t;
}
template <class, typename = void> struct is_multi_assoc : public false_type {};
template <class T> struct is_multi_assoc<T, enable_if_t<is_one_of<T,
        multiset<typename T::key_type, typename T::key_compare> >::value> > : public true_type {};
template <class T> struct is_multi_assoc<T, enable_if_t<is_one_of<T,
        multimap<typename T::key_type, typename T::mapped_type, typename T::key_compare>
        >::value> > : public true_type {};
template <class T> struct is_multi_assoc<T, enable_if_t<is_one_of<T,
        unordered_multiset<typename T::key_type, typename T::hasher, typename T::key_equal>
        >::value> > : public true_type {};
template <class T> struct is_multi_assoc<T, enable_if_t<is_one_of<T,
        unordered_multimap<typename T::key_type, typename T::mapped_type,
        typename T::hasher, typename T::key_equal> >::value> > : public true_type {};

template <class T> enable_if_t<is_multi_assoc<T>::value, T&> MULTIPLY(T& t, int frac, double = 0.0)
{
    try_reserving(t, t.size() * frac);
    for (auto it = t.cbegin(); it != t.cend(); )
    {
        typename T::const_iterator upper = t.equal_range(*it).second;
        for (; it != upper; ++it) { FOR(i, frac - 1) { t.insert(it, *it); } }
    }
    return t;
}
template <class T> enable_if_t<is_multi_assoc<T>::value, T&> DIVIDE(T& t, double dec)
{
    for (auto it = t.cbegin(); it != t.cend(); )
    {
        typename T::const_iterator upper = t.equal_range(*it).second;
        t.erase(it, next(it, ceil(distance(it, upper) * (1 - dec))));
        it = upper;
    }
}

template <class T> struct custom_arith : public integral_constant<bool, can_change_back<T>::value
        && two_way_iter<T>::value || changes_front<T>::value
        || is_multi_assoc<T>::value || is_adaptor<T>::value> {};

template <class T> enable_if_t<custom_arith<T>::value, T&> operator *= (T& t, int n)
{
    ASSERT(n >= 0, domain_error, "Input ", n, " must be positive.")
    if (n == 0) { t.clear(); }
    if (n == 1 || t.empty()) { return t; } 
    return MULTIPLY(t, n);
}
template <class T> enable_if_t<custom_arith<T>::value, T&> operator *= (T& t, double n)
{
    ASSERT(n > -eps, domain_error, "Input ", n, " must be positive.")
    if (abs(n) < eps) { t.clear(); }
    if (t.empty() || abs(n - 1) < eps) { return t; }
    int frac = n;
    n -=  frac;
    return frac ? MULTIPLY(t, frac, n) : DIVIDE(t, n);
}
template <class T> enable_if_t<custom_arith<T>::value, T&> operator /= (T& t, int n)
{
    ASSERT(n > 0, domain_error, "Input ", n, " must be positive.")
    if (n == 1 || t.empty()) { return t; } 
    return DIVIDE(t, 1.0 / n);
}
template <class T> enable_if_t<custom_arith<T>::value, T&> operator /= (T& t, double n)
{
    ASSERT(n > eps, domain_error, "Input ", n, " must be positive.")
    if (t.empty() || abs(n - 1) < eps) { return t; }
    return n > 1 ? DIVIDE(t, 1.0 / n) : t *= 1.0 / n;
}

template <class T, typename N> enable_if_t<custom_arith<T>::value && is_arithmetic<N>::value, T>
        operator * (T t, N n)
{
    return t *= double(n);
}
template <class T, typename N> enable_if_t<custom_arith<T>::value && is_arithmetic<N>::value, T>
        operator * (N n, T t)
{
    return t *= double(n);
}
template <class T, typename N> enable_if_t<custom_arith<T>::value && is_arithmetic<N>::value, T>
        operator / (T t, N n)
{
    return t /= double(n);
}
template <class T, typename N> enable_if_t<custom_arith<T>::value && is_arithmetic<N>::value, T>
        operator / (N n, T t)
{
    return t /= double(n);
}

template <class A, class B> enable_if_t<can_change_back<A>::value && two_way_iter<A>::value
        && iterable<B>::value && !is_one_of<B, val_type_t<A> >::value, A&>
        operator += (A& a, const B& b)
{
    try_reserving(a, a.size() + SIZE(b));
    a.insert(a.cend(), begin(b), end(b));
    return a;
}
template <class A, class B> enable_if_t<can_change_back<A>::value && two_way_iter<A>::value
        && is_one_of<B, val_type_t<A>>::value, A&> operator += (A& a, const B& b)
{
    try_reserving(a, a.size() + 1);
    a.push_back(b);
    return a;
}

template <class A, class B> enable_if_t<changes_front<A>::value && iterable<B>::value
        && !is_one_of<B, val_type_t<A> >::value, A&> operator += (A& a, const B& b)
{
    a.insert(a.cbefore_begin(), begin(b), end(b));
    return a;
}
template <class A, class B> enable_if_t<can_change_back<A>::value
        && is_one_of<B, val_type_t<A> >::value, A&> operator += (A& a, const B& b)
{
    a.push_front(b);
    return a;
}
template <class A, class B> enable_if_t<is_multi_assoc<A>::value && iterable<B>::value
        && !is_one_of<B, val_type_t<A> >::value, A&> operator += (A& a, const B& b)
{
    try_reserving(a, a.size() + SIZE(b));
    a.insert(begin(b), end(b));
    return a;
}
template <class A, class B> enable_if_t<is_multi_assoc<A>::value
        && is_one_of<B, val_type_t<A> >::value, A&> operator += (A& a, const B& b)
{
    try_reserving(a, a.size() + 1);
    a.insert(b);
    return a;
}
template <class A, class B> enable_if_t<is_adaptor<A>::value && iterable<B>::value
        && !is_one_of<B, val_type_t<A> >::value, A&> operator += (A& a, const B& b)
{
    for (const auto& i : b) { a.push(i); }
    return a;
}

template <class A, class B> enable_if_t<custom_arith<A>::value, A> operator + (A a, const B& b)
{
    return a += b;
}
template <class A, class B> enable_if_t<!custom_arith<A>::value && custom_arith<B>::value, B>
        operator + (const A& a, B b)
{
    return b += a;
}


template <class T, typename = void> struct myhash
{
    size_t operator () (const T& t) const { return hash<T>()(t); }
};
template <typename T> size_t& hash_combine(size_t&, const T&);

template <class T> struct myhash<T, enable_if_t<iterable<T>::value
        && !is_one_of<T, vector<bool> >::value && !is_str<T>::value> >
{
    size_t operator () (const T& t) const
    {
        size_t seed = SIZE(t);
        for (const auto& i : t) { hash_combine(seed, i); }
        return seed;
    }
};
template <class T> struct myhash<T, enable_if_t<is_tuple<T>::value> >
{
    template <size_t N = 0> enable_if_t<N == tuple_size<T>::value, size_t>
            operator () (const T&, size_t seed = tuple_size<T>::value) const
    {
        return seed;
    }
    template <size_t N = 0> enable_if_t<N < tuple_size<T>::value, size_t>
            operator () (const T& t, size_t seed = tuple_size<T>::value) const
    {
        return this->operator()<N + 1>(t, hash_combine(seed, get<N>(t)));
    }
};
template <typename T> size_t& hash_combine(size_t& seed, const T& t)
{
    return seed ^= myhash<T>()(t) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}






int main(int argc, char* argv[])
{
    
    debugPrint = true;
    printLN = true;











    cout.flush();
    fclose(stdout);
    return 0;
}
