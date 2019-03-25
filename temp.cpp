/*
ID:
PROG:
LANG: C++
/**
 * ASCII Table: Lines (85) 100 -> 255
 * Operator Precedence Lines 9 -> 63
 * |Precedence|  Operator(s)  |                Description	          |Associativity
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * ASCII control characters (character code 0-31)
 * The first 32 characters in the ASCII-table are unprintable control codes and are used to control
 *     peripherals such as printers.
 * ASCII printable characters (character code 32-127)
 * Codes 32-127 are common for all the different variations of the ASCII table, they are called
 *  printable characters, represent letters,  *digits, punctuation marks, and a few miscellaneous
 *      symbols. You will find almost every character on your keyboard. Character 127 represents
 *          the command DEL.
 * The extended ASCII codes (character code 128-255)
 * There are several different variations of the 8-bit ASCII table. The table below is according to
 *  Windows-1252 (CP-1252) which is a superset of ISO 8859-1, also called ISO Latin-1, in terms of
 *      printable characters, but differs from the IANA's ISO-8859-1 by using displayable characters
 *          rather than control characters in the 128 to 159 range. Characters that differ from
 *              ISO-8859-1 is marked by light blue color.
 * DEC	OCT	HEX	BIN	Symbol	HTML Number	HTML Name	Description
 * 0	000	00	00000000	NUL	&#000;	        	Null char
 * 1	001	01	00000001	SOH	&#001;	        	Start of Heading
 * 2	002	02	00000010	STX	&#002;	         	Start of Text
 * 3	003	03	00000011	ETX	&#003;	         	End of Text
 * 4	004	04	00000100	EOT	&#004;	         	End of Transmission
 * 5	005	05	00000101	ENQ	&#005;      	 	Enquiry
 * 6	006	06	00000110	ACK	&#006;      	 	Acknowledgment
 * 7	007	07	00000111	BEL	&#007;      	 	Bell
 * 8	010	08	00001000	BS	&#008;      	 	Back Space
 * 9	011	09	00001001	HT	&#009;      	 	Horizontal Tab
 * 10	012	0A	00001010	LF	&#010;  	       	Line Feed
 * 11	013	0B	00001011	VT	&#011;      	 	Vertical Tab
 * 12	014	0C	00001100	FF	&#012;  	       	Form Feed
 * 13	015	0D	00001101	CR	&#013;              	Carriage Return
 * 14	016	0E	00001110	SO	&#014;              	Shift Out / X-On
 * 15	017	0F	00001111	SI	&#015;	 	        Shift In / X-Off
 * 16	020	10	00010000	DLE	&#016;	 	        Data Line Escape
 * 17	021	11	00010001	DC1	&#017;	 	        Device Control 1 (oft. XON)
 * 18	022	12	00010010	DC2	&#018;	        	Device Control 2
 * 19	023	13	00010011	DC3	&#019;	        	Device Control 3 (oft. XOFF)
 * 20	024	14	00010100	DC4	&#020;	        	Device Control 4
 * 21	025	15	00010101	NAK	&#021;	        	Negative Acknowledgement
 * 22	026	16	00010110	SYN	&#022;	        	Synchronous Idle
 * 23	027	17	00010111	ETB	&#023;	            	End of Transmit Block
 * 24	030	18	00011000	CAN	&#024;	 	        Cancel
 * 25	031	19	00011001	EM	&#025;	 	        End of Medium
 * 26	032	1A	00011010	SUB	&#026;	        	Substitute
 * 27	033	1B	00011011	ESC	&#027;	         	Escape
 * 28	034	1C	00011100	FS	&#028;      	 	File Separator
 * 29	035	1D	00011101	GS	&#029;	         	Group Separator
 * 30	036	1E	00011110	RS	&#030;	         	Record Separator
 * 31	037	1F	00011111	US	&#031;	         	Unit Separator
 * 32	040	20	00100000	 	&#32;               	Space
 * 33	041	21	00100001	!	&#33;	 	        Exclamation mark
 * 34	042	22	00100010	"	&#34;	&quot;      	Double quotes (or speech marks)
 * 35	043	23	00100011	#	&#35;	    	    	Number
 * 36	044	24	00100100	$	&#36;	 	        Dollar
 * 37	045	25	00100101	%	&#37;   	 	Per cent sign
 * 38	046	26	00100110	&	&#38;	&amp;       	Ampersand
 * 39	047	27	00100111	'	&#39;	        	Single quote
 * 40	050	28	00101000	(	&#40;	        	Open parenthesis (or open bracket)
 * 41	051	29	00101001	)	&#41;	        	Close parenthesis (or close bracket)
 * 42	052	2A	00101010	*	&#42;	        	Asterisk
 * 43	053	2B	00101011	+	&#43;	        	Plus
 * 44	054	2C	00101100	,	&#44;	        	Comma
 * 45	055	2D	00101101	-	&#45;	        	Hyphen
 * 46	056	2E	00101110	.	&#46;	        	Period, dot or full stop
 * 47	057	2F	00101111	/	&#47;	        	Slash or divide
 * 48	060	30	00110000	0	&#48;	        	Zero
 * 49	061	31	00110001	1	&#49;	        	One
 * 50	062	32	00110010	2	&#50;	        	Two
 * 51	063	33	00110011	3	&#51;	        	Three
 * 52	064	34	00110100	4	&#52;	        	Four
 * 53	065	35	00110101	5	&#53;	 	        Five
 * 54	066	36	00110110	6	&#54;	        	Six
 * 55	067	37	00110111	7	&#55;	        	Seven
 * 56	070	38	00111000	8	&#56;	        	Eight
 * 57	071	39	00111001	9	&#57;	        	Nine
 * 58	072	3A	00111010	:	&#58;	        	Colon
 * 59	073	3B	00111011	;	&#59;	        	Semicolon
 * 60	074	3C	00111100	<	&#60;	&lt;        	Less than (or open angled bracket)
 * 61	075	3D	00111101	=	&#61;	 	        Equals
 * 62	076	3E	00111110	>	&#62;	&gt;    	Greater than (or close angled bracket)
 * 63	077	3F	00111111	?	&#63;	 	        Question mark
 * 64	100	40	01000000	@	&#64;	        	At symbol
 * 65	101	41	01000001	A	&#65;	        	Uppercase A
 * 66	102	42	01000010	B	&#66;	        	Uppercase B
 * 67	103	43	01000011	C	&#67;	        	Uppercase C
 * 68	104	44	01000100	D	&#68;	        	Uppercase D
 * 69	105	45	01000101	E	&#69;	        	Uppercase E
 * 70	106	46	01000110	F	&#70;	        	Uppercase F
 * 71	107	47	01000111	G	&#71;	        	Uppercase G
 * 72	110	48	01001000	H	&#72;	        	Uppercase H
 * 73	111	49	01001001	I	&#73;	        	Uppercase I
 * 74	112	4A	01001010	J	&#74;	        	Uppercase J
 * 75	113	4B	01001011	K	&#75;	        	Uppercase K
 * 76	114	4C	01001100	L	&#76;	        	Uppercase L
 * 77	115	4D	01001101	M	&#77;	        	Uppercase M
 * 78	116	4E	01001110	N	&#78;	        	Uppercase N
 * 79	117	4F	01001111	O	&#79;	        	Uppercase O
 * 80	120	50	01010000	P	&#80;	        	Uppercase P
 * 81	121	51	01010001	Q	&#81;	        	Uppercase Q
 * 82	122	52	01010010	R	&#82;	        	Uppercase R
 * 83	123	53	01010011	S	&#83;	        	Uppercase S
 * 84	124	54	01010100	T	&#84;	        	Uppercase T
 * 85	125	55	01010101	U	&#85;	        	Uppercase U
 * 86	126	56	01010110	V	&#86;	        	Uppercase V
 * 87	127	57	01010111	W	&#87;	        	Uppercase W
 * 88	130	58	01011000	X	&#88;	        	Uppercase X
 * 89	131	59	01011001	Y	&#89;	        	Uppercase Y
 * 90	132	5A	01011010	Z	&#90;	        	Uppercase Z
 * 91	133	5B	01011011	[	&#91;	        	Opening bracket
 * 92	134	5C	01011100	\	&#92;	        	Backslash
 * 93	135	5D	01011101	]	&#93;	        	Closing bracket
 * 94	136	5E	01011110	^	&#94;	        	Caret - circumflex
 * 95	137	5F	01011111	_	&#95;	        	Underscore
 * 96	140	60	01100000	`	&#96;	        	Grave accent
 * 97	141	61	01100001	a	&#97;	        	Lowercase a
 * 98	142	62	01100010	b	&#98;	        	Lowercase b
 * 99	143	63	01100011	c	&#99;	        	Lowercase c
 * 100	144	64	01100100	d	&#100;	        	Lowercase d
 * 101	145	65	01100101	e	&#101;	        	Lowercase e
 * 102	146	66	01100110	f	&#102;	        	Lowercase f
 * 103	147	67	01100111	g	&#103;	        	Lowercase g
 * 104	150	68	01101000	h	&#104;	        	Lowercase h
 * 105	151	69	01101001	i	&#105;	        	Lowercase i
 * 106	152	6A	01101010	j	&#106;	        	Lowercase j
 * 107	153	6B	01101011	k	&#107;	        	Lowercase k
 * 108	154	6C	01101100	l	&#108;	        	Lowercase l
 * 109	155	6D	01101101	m	&#109;	        	Lowercase m
 * 110	156	6E	01101110	n	&#110;	        	Lowercase n
 * 111	157	6F	01101111	o	&#111;	        	Lowercase o
 * 112	160	70	01110000	p	&#112;	        	Lowercase p
 * 113	161	71	01110001	q	&#113;	        	Lowercase q
 * 114	162	72	01110010	r	&#114;	        	Lowercase r
 * 115	163	73	01110011	s	&#115;	 	        Lowercase s
 * 116	164	74	01110100	t	&#116;	        	Lowercase t
 * 117	165	75	01110101	u	&#117;	    	    	Lowercase u
 * 118	166	76	01110110	v	&#118;	    	    	Lowercase v
 * 119	167	77	01110111	w	&#119;	        	Lowercase w
 * 120	170	78	01111000	x	&#120;	        	Lowercase x
 * 121	171	79	01111001	y	&#121;	        	Lowercase y
 * 122	172	7A	01111010	z	&#122;	        	Lowercase z
 * 123	173	7B	01111011	{	&#123;	        	Opening brace
 * 124	174	7C	01111100	|	&#124;	        	Vertical bar
 * 125	175	7D	01111101	}	&#125;	        	Closing brace
 * 126	176	7E	01111110	~	&#126;	        	Equivalency sign - tilde
 * 127	177	7F	01111111		&#127;	        	Delete
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
template <typename T> inline std::size_t hash_combine(const std::size_t& seed, const T& v) {
    return seed ^ std::hash<T>(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std {
    template <typename S, typename T> struct hash<pair<S, T> > {
        inline size_t operator()(const pair<S, T>& v) const {
            return hash_combine(hash_combine(0, v.first), v.second);
        }
    };
};

using namespace std;
using namespace placeholders;

///shorter typenames
typedef long long llng;
typedef double dbl;
typedef long double ldbl;

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
#define RALL(c) (c).rbegin(), (c).rend()
#define CALL(c) (c).cbegin(), (c).cend()
#define CRALL(c) (c).crbegin(), (c).crend()


const array<const string, 2> varsStart = {"v{"}, varsStep = {", ", " "}, varsEnd = {"}v"};
const array<const string, 2> iterStart = {"{"}, iterEnd = {"}"};
const array<const string, 2> tupStart = {"("}, tupEnd = {")"};
const auto& iterStep = varsStep, tupStep = varsStep;

const string delChar = "\b \b";

bool debugPrint = false;

template <typename T> string GETSTR(const T& what, const bool& condition = 0){
    return condition ? "" : what.at(!debugPrint);
}

template<typename...> struct make_void { typedef void type; };
template<typename... Ts> using void_t = typename make_void<Ts...>::type;

template <class, typename = void> struct is_iterator : public false_type {};
template <class T> struct is_iterator<T, void_t<
            decltype(T(declval<T>())),
            decltype(declval<T&>() = declval<T>()),
            decltype(++declval<T&>()),
            decltype(declval<T&>()++),
            decltype(*declval<T&>())> > : public true_type {};
template <class T> inline constexpr bool is_iterator_v(const T& t) { return is_iterator<T>::value; }

template <class, typename = void> struct iterable : public false_type {};
template <class T> struct iterable<T, void_t<
                decltype(begin(declval<T&>())),
                decltype(end(declval<T&>()))> > : public true_type {};
template <class T> inline constexpr bool iterable_v(const T& t) { return iterable<T>::value; }

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

template <class T> inline constexpr bool out_iter_v(const T& t) { return out_iter<T>::value; }
template <class T> inline constexpr bool in_iter_v(const T& t) { return in_iter<T>::value; }
template <class T> inline constexpr bool forward_iter_v(const T& t) { return forward_iter<T>::value; }
template <class T> inline constexpr bool two_way_iter_v(const T& t) { return two_way_iter<T>::value; }
template <class T> inline constexpr bool random_iter_v(const T& t) { return random_iter<T>::value; }

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
template <class T> inline constexpr bool std_container_v(const T& t) { return std_container<T>::value; }

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
            public integral_constant<bool, std_container<T>::value && iterable<T>::value> {};
template <class T> inline constexpr bool is_container_v(const T& t) { return is_container<T>::value; }

template <class, typename = void> struct is_tuple : public false_type {};
template <class T> struct is_tuple<T, void_t< // true trait class for determining containers
            decltype(T()),
            decltype(T(declval<T>())),
            decltype(declval<T>() == declval<T>()),
            decltype(declval<T>() < declval<T>()),
            decltype(tuple_size<T>::value)> > : public true_type {};
template <class T> inline constexpr bool is_tuple_v(const T& t) { return is_tuple<T>::value; }

template <class, typename = void> struct is_sequential : public false_type {};
template <class T> struct is_sequential<T, void_t< // true trait class for determining containers
                decltype(declval<T>().front())> > : public is_container<T> {};
template <class T> inline constexpr bool is_sequential_v(const T& t) { return is_sequential<T>::value; }

template <class, typename = void> struct can_change_back : public false_type {};
template <class T> struct can_change_back<T, void_t< // true trait class for determining containers
            decltype(declval<T&>().push_back(declval<typename T::value_type>()))> > :
                                        public is_sequential<T> {};
template <class T> inline constexpr bool can_change_back_v(const T& t) { return can_change_back<T>::value; }

template <class, typename = void> struct changes_front : public false_type {};
template <class T> struct changes_front<T, void_t< // true trait class for determining containers
            decltype(declval<T&>().push_front(declval<typename T::value_type>()))> > :
            public integral_constant<bool, is_sequential<T>::value && !can_change_back<T>::value> {};
template <class T> inline constexpr bool changes_front_v(const T& t) { return changes_front<T>::value; }

template <class, typename = void> struct is_associative : public false_type {};
template <class T> struct is_associative<T, void_t< // true trait class for determining containers
            typename T::key_type> > : public is_container<T> {};
template <class T> inline constexpr bool is_associative_v(const T& t) { return is_associative<T>::value; }

template <class, typename = void> struct is_map : public false_type {};
template <class T> struct is_map<T, void_t< // true trait class for determining containers
            typename T::mapped_type> > : public is_associative<T> {};
template <class T> inline constexpr bool is_map_v(const T& t) { return is_map<T>::value; }


template <class, typename = void> struct is_adaptor : public false_type {};
template <class T> struct is_adaptor<T, void_t<
                typename T::container_type> > : public std_container<T> {};
template <class T> inline constexpr bool is_adaptor_v(const T& t) { return is_adaptor<T>::value; }

template <class, typename = void> struct instant_size : public false_type {};
template <class T> struct instant_size<T, void_t<decltype(declval<T>().size())> > : public true_type {};
template <class T> inline constexpr bool instant_size_v(const T& t) { return instant_size<T>::value; }

template <class Tuple, size_t N, size_t Last, bool canEmpty> struct same_elements :
                public integral_constant<bool, is_same<typename tuple_element<N - 1, Tuple>::type,
    typename tuple_element<N, Tuple>::type>::value && same_elements <Tuple, N + 1, Last, canEmpty>::value> {};
template <class Tuple, size_t N, bool canEmpty> struct same_elements<Tuple, N, N, canEmpty>
                                                                            : public true_type {};
template <class Tuple, bool canEmpty> struct same_elements<Tuple, 1, 0, canEmpty> :
                                                    public integral_constant<bool, canEmpty> {};
template <class Tuple, bool canEmpty = false> struct same_e : public same_elements<Tuple, 1, tuple_size<Tuple>::value, canEmpty> {};
template <class Tuple, bool canEmpty = false> inline constexpr bool same_e_v(const Tuple& t) { return same_e<Tuple, canEmpty>::value; }

template <class, size_t, typename = void> struct val_type { };
template <class T, size_t N> struct val_type<T, N, typename enable_if<N && iterable<T>::value &&
                                                                    !is_map<T>()>::type> {
    typedef typename val_type<decltype(*declval<iter_t<T>>()), N - 1>::type type;
};
template <class T, size_t N> struct val_type<T, N, typename enable_if<N && is_map<T>::value>::type> {
    typedef typename val_type<typename T::mapped_type, N - 1>::type type;
};
template <class T, size_t N> struct val_type<T, N, typename enable_if<N && is_iterator<T>::value>::type> {
    typedef typename val_type<typename iterator_traits<T>::value_type, N - 1>::type type;
};
template <class T> struct val_type<T, 0> {
    typedef T type;
};
template <class T, size_t N> using val_type_t = typename val_type<T, N>::type;




///after input/output with containers is properly fixed, these following macros will be unnecessary

template <typename F> inline constexpr int sgn (const F& a, const F& b = F(0)) {
    return int ((a > b) - (a < b)); //returns -1 if a < b, 0 if a == b, 1 if a > b
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
#define FARR(type, a, n, what) type a[n]; fill(ALL(a), what);
#define ARR2(type, a, m, n) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) { cin >> a[a##_i][a##_j]; } }
#define FARR2(type, a, m, n, what) type a[n]; FOR(a##_i, n) { FOR(a##_j, n) {\
                                                                a[a##_i][a##_j] = what; } }

using dummy = int[];

template <typename T, typename B> using holds = is_same<typename T::value_type, B>;

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

size_t count(const string& a, const string& substr, size_t start = 0, const size_t& end = string::npos){
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
string zfill(const string& a, const size_t& width){
    return string(width < a.size() ? 0 : width - a.size(), '0') + a;
}

template <typename T> string type_name() {
    typedef typename remove_reference<T>::type actual;
    int status;
    string tname = typeid (actual).name();
    string demangled_name = abi::__cxa_demangle (tname.c_str(), nullptr, nullptr, &status);
    return (status ? tname : repl(repl(demangled_name, {"std::", " "}, ""), ",", ", ")) +
            (is_const<actual>::value ? " const" : "") +
            (is_volatile<actual>::value ? " volatile" : "") +
            (is_lvalue_reference<actual>::value ? "&" : "") +
            (is_rvalue_reference<actual>::value ? "&&" : "");
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
template <typename... T> ostream& FOUT (ostream& os, const T&... t) { //called for the last variable so it prints new line
    os << GETSTR(varsStart);
    void (dummy{0, (void(os << t << GETSTR(varsStep)), 0)...});
    return os << GETSTR(varsStep).size() * delChar << GETSTR(varsEnd) << '\n';
}
template <typename...R> ostream& OUT (const R&...r) { //recursion
    return FOUT(cout, r...);
}


template <typename T> inline T sMax (T& a, const T& b){//only sets a to b if b > a - commonly used
    return a = max (a, b);
}
template <typename T> inline T sMin (T& a, const T& b){//only sets a to b if b < a - commonly used
    return a = min (a, b);
}
template <typename T> typename enable_if<is_arithmetic<T>::value, T>::type pow(T x, int n) {
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    T value = T(1);
    while (n) {
        if (n & 1) {
            value *= x; //for n odd
        }
        n >>= 1;
        x *= x;
    }
    return value;
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
#define EXCEPTION(msg) throw join("Exception: ", msg, " [in ", __PRETTY_FUNCTION__,\
                                                                    " of line #", __LINE__, "]\n");
//if condition succeeds OR error occurs -> message of exception is printed
#define TRY(cond, msg) try { if (!(cond)) { EXCEPTION(msg); } } catch(string s) { cerr << s << '\n'; }




template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
            && N == tuple_size<T>::value, ostream&>::type operator << (ostream& os, const T& t) {
    return os << GETSTR(tupEnd, !N);
}

template <size_t N = 0, typename T> typename enable_if<is_tuple<T>::value && !is_container<T>::value
                && N < tuple_size<T>::value, ostream&>::type operator << (ostream& os, const T& t) {
    return operator << <N + 1, T> (os << GETSTR(N ? tupStep : tupStart) << get<N>(t), t);
}

template <typename T, size_t S> typename enable_if<!is_same<T, char>::value, ostream&>::type
                                                        operator << (ostream& os, const T (&t)[S]){
    os << GETSTR(iterStart);
    for_each(ALL(t), [&os] (const T& i) { os << i << GETSTR(iterStep, is_same<T, bool>::value); } );
    return os << GETSTR(iterStep, is_same<T, bool>::value).size() * delChar << GETSTR(iterEnd);
}
template <class T> typename enable_if<iterable<T>::value && !is_array<T>::value &&
            !is_base_of<string, T>::value, ostream&>::type operator << (ostream& os, const T& t) {
    os << GETSTR(iterStart, holds<T, char>::value);
    for_each(CALL(t), [&os] (typename T::const_reference i) { os << i <<
                GETSTR(iterStep, holds<T, char>::value || holds<T, bool>::value); } );
    return os << GETSTR(iterStep, holds<T, char>::value || holds<T, bool>::value).size() * delChar
                                                        << GETSTR(iterEnd, holds<T, char>::value);
}

template <class T> typename enable_if <is_adaptor<T>::value &&
                    is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                                                    ostream&>::type operator << (ostream& os, T t){
    os << GETSTR(iterStart, holds<T, char>::value);
    while (!t.empty()){
        os << pop(t) << GETSTR(iterStep, holds<T, char>::value || holds<T, bool>::value);
    }
    return os << GETSTR(iterStep, holds<T, char>::value || holds<T, bool>::value).size() * delChar
                                                        << GETSTR(iterEnd, holds<T, char>::value);
}
template <class T> typename enable_if <is_adaptor<T>::value &&
                    !is_base_of<queue<typename T::value_type, typename T::container_type>, T>::value,
                                                    ostream&>::type operator << (ostream& os, T t){
    deque<typename T::value_type> a;
    while (!t.empty()){
        a.pf(pop(t));
    }
    return os << a;
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
template <class T> typename enable_if<is_sequential<T>::value && !changes_front<T>::value && !can_change_back<T>::value,
                                                    istream&>::type operator >> (istream& is, T& t){
    for_each(ALL(t), [&is] (typename T::reference i) { is >> i; } );
    return is;
}

template <class T> typename enable_if<is_map<T>::value, istream&>::type operator >> (istream& is, T& t){
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
    auto s = chrono::high_resolution_clock::now();
    f();
    auto e = chrono::high_resolution_clock::now();
    eprintf("[%s %s called at line #%d in %s taking %s ns]\n", args...,
                        sepNum(chrono::duration_cast<chrono::nanoseconds> (e - s).count()).c_str());
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
                                                must_sorted(const I& first, const I& last, C c, const bool& canEqual = 0){
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
    return must_sorted(first, last, less<val_type_t<I, 1>>(), canEqual);
}

template <class I> typename enable_if<in_iter<I>::value, bool>::type ascending(const I& first, const I& last){
    return is_sorted(first, last, less_equal<val_type_t<I, 1>>());
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type
                                                            downhill(const I& first, const I& last, bool canEqual = 0){
    return must_sorted(first, last, greater<val_type_t<I, 1> >(), canEqual);
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type descending(const I& first, const I& last){
    return is_sorted(first, last, greater_equal<val_type_t<I, 1> >());
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type flat(const I& first, const I& last){
    return is_sorted(first, last, equal_to<val_type_t<I, 1> >());
}
template <class T> typename enable_if<in_iter<T>::value, bool>::type distinct(const T& t){
    return t.size() == uset<val_type_t<T, 1>>(ALL(t)).size();
}
template <class I> typename enable_if<in_iter<I>::value, bool>::type distinct(const I& first, const I& last){
    return distance(first, last) == uset<val_type_t<I, 1>>(first, last).size();
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

template <class T> typename enable_if<iterable<T>::value, typename T::reference>::type
                                            min_e(const T& t){
    return min_e(t, less<val_type_t<T, 1>>());
}
template <class T, class C> typename enable_if<iterable<T>::value, typename T::reference>::type min_e(const T& t, C c){
    return *min_element(ALL(t), c);
}
template <class T> typename enable_if<iterable<T>::value, typename T::reference>::type
                                            max_e(const T& t){
    return max_e(t, less<val_type_t<T, 1>>());
}
template <class T, class C> typename enable_if<iterable<T>::value, typename T::reference>::type
                                            max_e(const T& t, C c){
    return *max_element(ALL(t), c);
}

template <class T> typename enable_if<two_way_iter<T>::value, reverse_iterator<iter_t<T> > >::type rbegin(T& t) {
    return reverse_iterator<iter_t<T> >(end(t));
}
template <class T> typename enable_if<two_way_iter<T>::value, reverse_iterator<iter_t<T> > >::type rend(T& t) {
    return reverse_iterator<iter_t<T> >(begin(t));
}

template <class, typename, typename = void> struct access : public false_type {};
template <class T, typename A> struct access<T, A, void_t<decltype(declval<T&>()[declval<A>()]) > > : public true_type {};

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
template <class T> val_type_t<T, 1>& to(T& t, const int& i) {
    return t[(i % SIZE(t) + SIZE(t)) % SIZE(t)];
}
template <class T, typename... Is> val_type_t<T, sizeof...(Is) + 2>&
                                        to(T& t, const int& i, const int& i2, const Is&... is) {
    return to(to(t, i), i2, is...);
}

template <class T> typename enable_if<is_sequential<T>::value && access<T, int>::value, bool>::type val(T& t, const int& i){
    return i < SIZE(t);
}
template <class T, typename I> typename enable_if<is_map<T>::value && access<T, I>::value, bool>::type val(T& t, const I& i){
    return t.count(i);
}

template <class T, typename I, typename I2, typename... Is>
            bool val(T& t, const I& i, const I2& i2, const Is&... is) {
    if (!val(t, i)){
        return false;
    }
    return val(at(t, i), i2, is...);
}



inline int log2(const int& x) {
    TRY(x > 0, "Input must be positive.");
    return x ? 31 - __builtin_clz(x) : 0;
}
inline unsigned log2(const unsigned& x){
    return x ? 31 - __builtin_clz(x) : 0;
}
const int digsOf2Pows[33] = {
    0, 0, 0, 0, 1, 1, 1, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 5, 5, 5,
    6, 6, 6, 6, 7, 7, 7, 8, 8, 8,
    9, 9, 9
};
const int tenToThe[] = {
    1, 10, 100, 1000, 10000, 100000,
    1000000, 10000000, 100000000, 1000000000
};
int log10(const int& x) {
    return digsOf2Pows[log2(x) + 1];
}
unsigned log10 (const unsigned& x){
    return digsOf2Pows[log2(x) + 1];
}
int isqrt(int num){
    TRY(num >= 0, "Input must be nonnegative")
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
unsigned isqrt(unsigned num){
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
int icbrt(int x) {
    cout << "I";
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
unsigned icbrt(unsigned x){
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






int main() {
	//TOFILE( )





	cout.flush();
	fclose(stdout);
	return 0;
}
