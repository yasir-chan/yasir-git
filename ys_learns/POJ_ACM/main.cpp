
#include "..\..\include\ys_common.h"


namespace poj_1006
{
	void run() {

	}
}

int main() {
	poj_1006::run();
	return 0;
}











namespace poj {
	template<class T>
	static T clamp(const T& v, const T& min, const T& max)
	{
		if (v < min)
		{
			return min;
		}
		else if (v > max)
		{
			return max;
		}
		else
		{
			return v;
		}
	}

	template<class T>
	static T if_equ(const T& v, const T& other, const T& nval)
	{
		if (v == other)
		{
			return nval;
		}
		return v;
	}

	template<class T>
	static T if_nequ(const T& v, const T& other, const T& nval)
	{
		if (v != other)
		{
			return nval;
		}
		return v;
	}

	static std::string trim_left(const std::string &str, const std::string &mask)
	{
		size_t idx = str.find_first_not_of(mask);
		if (idx == std::string::npos)
		{
			return str;
		}

		return str.substr(idx);
	}

	static std::string trim_right(const std::string &str, const std::string &mask)
	{
		size_t idx = str.find_last_not_of(mask);
		if (idx == std::string::npos)
		{
			return str;
		}

		return str.substr(0, idx + 1);
	}

	static std::string trim(const std::string &str, const std::string &mask)
	{
		return trim_left(trim_right(str, mask), mask);
	}

	static std::string toupper(const std::string &s)
	{
		std::string str = s;
		std::transform(str.begin(), str.end(), str.begin(), _toupper);
		return str;
	}

	static std::string tolower(const std::string &s)
	{
		std::string str = s;
		std::transform(str.begin(), str.end(), str.begin(), _tolower);
		return str;
	}

	static bool contains(const std::string &str, const std::string &key, bool ignore_case = false)
	{
		if (ignore_case)
		{
			return toupper(str).find(toupper(key)) != std::string::npos;
		}
		else
		{
			return str.find(key) != std::string::npos;
		}
	}
}

/*


namespace poj_1006
{
	// 欧几里得算法 - 最大公约数
	int gcd(int a, int b)
	{
		if (a == 0 || b == 0) return 1;
		int r = 0;
		while (b != 0)
		{
			r = b;
			b = a % b;
			a = r;
		};
		return a;
	}

	// 扩展欧几里得算法
	int exgcd(int a, int b, int &x, int &y)
	{
		if (b == 0)
		{
			x = 1;
			y = 0;
			return a;
		}

		int r = exgcd(b, a%b, x, y);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return r;
	}


	int a[3], m[3];

	// 中国剩余定理，这里ai分别为p、e、i然后mi分别为 23、28、33
	int CRT(int a[], int m[], int n)
	{
		// M = m1 * m2 ... * mk
		// Mi = M / mi, Mi-1 = Mi模mi的逆元
		// return X = (a1*M1*M1-1 + ...ak*Mk*Mk-1) % M
		int M = 1;
		int X = 0;
		int i = 0;
		for (i = 0; i < n; ++i) M *= m[i];
		for (i = 0; i < n; ++i)
		{
			int Mi = M / m[i];
			int Mi_1, y;
			// 这里 Mi-1为Mi模mi的逆元，数学公式 Mi*Mi-1 = 1(mod mi)
			// ==> Mi*Mi-1 + mi*y = 1
			// 欧几里得扩展 ax + by = gcd(a,b), 根据定义 Mi 和 mi互素，所以gcd(Mi, mi)==1
			// 综上自然可以使用exgcd计算出 x==Mi-1，带入下面函数
			poj::exgcd(Mi, m[i], Mi_1, y);
			X += a[i] * Mi * Mi_1;
		}
		X = X % M;
		if (X < 0) X += M;
		return X;
	}

	
	void run()
	{
		int p, e, i, d;
		int idx = 0;
		m[0] = 23, m[1] = 28, m[2] = 33;
		while (scanf("%d %d %d %d", &p, &e, &i, &d))
		{
			if (p == -1 && e == -1 && i == -1 && -1 == d)
				break;
			a[0] = p, a[1] = e, a[2] = i;
			int X = CRT(a, m, 3);
			if (X <= d)
			{
				X += 21252;
			}
			printf("Case %d: the next triple peak occurs in %d days.\n", ++idx, X - d);
		}
	}
}

namespace poj_1003
{
	// 由于题目规定最大是5.20f所以可以使用这种方式
	const int max_n = 277; // n=276时等式大于5.2
	std::vector<float> vals;

	void init()
	{
		float v = 0.0f;
		vals.resize(max_n);
		vals[0] = 0.0f;
		std::vector<float>::iterator itr = vals.begin() + 1;
		for (int n = 1; n < max_n; ++n, ++itr)
		{
			v += 1.0f / (n + 1);
			*itr = v;
		}
	}
	void run()
	{
		init();
		float v;
		std::vector<float>::iterator itr;
		while (scanf("%f", &v) && v)
		{
			itr = std::lower_bound(vals.begin(), vals.end(), v);
			printf("%d card(s)\n", int(itr-vals.begin()));
		}
	}
}

namespace poj_1002
{
	int ALPHA_2_NUM[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0 };
	char CHAR_2_NUM[256];
	std::map<int, int> phones;

	void init()
	{
		int i = 0;
		for (i = '0'; i <= '9'; ++i) CHAR_2_NUM[i] = i - '0';
		for (i = 'A'; i <= 'Z'; ++i) CHAR_2_NUM[i] = ALPHA_2_NUM[i - 'A'];
	}

	void handle_a_phone(const char *s, size_t len)
	{ 
		int num = 0;
		for (size_t i = 0; i < len; ++i)
			if (s[i] != '-') num = num * 10 + CHAR_2_NUM[s[i]];
		++phones[num];
	}

	void print_phone(int num, int n) 
	{
		printf("%03d-%04d %d\n", num / 10000, num % 10000, n);
	}

	void run()
	{
		init();

		int n;
		scanf("%d", &n);

		char buf[256];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			handle_a_phone(buf, strlen(buf));
		}

		std::map<int, int>::iterator itr;
		bool has_flag = false;
		for (itr = phones.begin(); itr != phones.end(); ++itr)
		{
			if (itr->second > 1)
			{
				print_phone(itr->first, itr->second);
				has_flag = true;
			}
		}
		if (!has_flag)
		{
			printf("No duplicates.\n");
		}
	}
}

namespace poj_1001
{
	std::vector<short> _temp_result;
	void multiply(const std::vector<char>& a, const std::vector<char>& b, std::vector<char>& result)
	{
		int i, j, k;
		// a x b, 最少位数 100*100 = len(a+b)-1位， 最多 999*999 = len(a+b)位
		// 这里默认用 少一位，多了再用insert，主要是为了代码简洁（效率不是最高）
		int max_len = (int)a.size() + (int)b.size() - 1;

		//常规大数相乘都采用‘常人数学思维’，导致代码荣誉，除法、取模 次数太多
		//这里采用‘逆向思维’，就是所有数据都是相反的
		//如： 1234 * 987 如下
		//len-1							0 （字符串地址）
		//-                     4 3 2 1 x 9
		//-                   4 3 2 1 x 8
		//-                 4 3 2 1 x 7
		//因为输出时也是从0~len-1所以，把上面想象成镜像就是（数学思维）
		//-                 1 2 3 4 x 9
		//-                   1 2 3 4 x 8
		//-                     1 2 3 4 x 7
		
		// 综上，‘每一列’结果，由于最大的列为9行，超出char范围，所以需要一个short类型的temp_result
		if (_temp_result.size() <= max_len)
		{
			_temp_result.resize(max_len * 2);
		}

		for (i = 0; i < max_len; i++)
		{
			_temp_result[i] = 0;
		}

		// 把数据全部相加，后面再考虑进位问题
		for (i = 0; i < a.size(); i++)
		{
			k = i;
			for (j = 0; j < b.size(); j++)
			{
				_temp_result[k++] += a[i] * b[j];
			}
		}

		// 处理进位，输出结果
		result.resize(max_len);
		for (k = max_len - 1; k >= 0; --k)
		{
			if (_temp_result[k] <= 9)
			{
				result[k] = (char)_temp_result[k];
				continue;
			}

			if (k != 0)
			{
				_temp_result[k - 1] += _temp_result[k] / 10;
				result[k] = _temp_result[k] % 10;
			}
			else   //如果是第一项大于9则添加一项于头部   
			{
				int tmp = _temp_result[k] / 10;
				result[k] = _temp_result[k] % 10;
				result.insert(result.begin(), tmp);
			}

namespace poj_1002
{
	int ALPHA_2_NUM[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0 };
	char CHAR_2_NUM[256];
	std::hash_map<int, int> temp_phones;
	std::map<int, int> order_phones;

	void init()
	{
		int i = 0;
		for (i = '0'; i <= '9'; ++i) CHAR_2_NUM[i] = i - '0';
		for (i = 'A'; i <= 'Z'; ++i) CHAR_2_NUM[i] = ALPHA_2_NUM[i - 'A'];
	}

	void handle_a_phone(const char *s, size_t len)
	{ 
		int num = 0;
		for (size_t i = 0; i < len; ++i)
			if (s[i] != '-') num = num * 10 + CHAR_2_NUM[s[i]];
		++temp_phones[num];
	}

	void print_phone(int num, int n) 
	{
		printf("%03d-%04d %d\n", num / 10000, num % 10000, n);
	}

	void run()
	{
		init();

		int n;
		scanf("%d", &n);

		char buf[256];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			handle_a_phone(buf, strlen(buf));
		}

		std::hash_map<int, int>::iterator itr;
		for (itr = temp_phones.begin(); itr != temp_phones.end(); ++itr)
		{
			if (itr->second > 1)
			{
				order_phones[itr->first] = itr->second;
			}
		}

		if (order_phones.size() > 0)
		{
			std::map<int, int>::iterator itr;
			for (itr = order_phones.begin(); itr != order_phones.end(); ++itr)
			{
				print_phone(itr->first, itr->second);
		std::map<int, int> order_phones;
			}
		}
		else
		{
			printf("No duplicates.\n");
		}
	}
}
		}
	}

	struct float_big_number
	{
	public:
		void from_string(const std::string &str)
		{
			num.clear();
			pos = 0;

			std::string s = poj::trim_left(str, " 0");
			size_t dot_pos = s.find('.');
			if (dot_pos != std::string::npos)
			{
				s = poj::trim_right(s, " 0");
				pos = poj::clamp(int(s.size() - dot_pos - 1), int(0), (int)(s.size() - 1));
				s.erase(dot_pos, 1);
			}
			else
			{
				s = poj::trim_right(s, " ");
			}

			for (size_t i = 0; i < s.length(); i++)
			{
				num.push_back(s[i] - '0');
			}

			if (num.empty())
			{
				num.push_back(0);
				pos = 0;
			}
		}

		std::string to_string()
		{
			std::string str;
			str.reserve(num.size() + 1);
			for (size_t i = 0; i < num.size(); i++)
			{
				str.append(1, num[i] + '0');
			}
			if (pos != 0)
			{
				if ((size_t)pos > num.size())
				{
					// 补0
					str.insert(0, pos - num.size(), '0');
					str.insert(0, 1, '.');
				}
				else
				{
					str.insert(num.size() - (size_t)pos, 1, '.');
				}
			}
			return str;
		}

		void multiply(const float_big_number &other)
		{
			poj_1001::multiply(num, other.num, num);
			pos = pos + other.pos;
		}

		std::vector<char> num;
		int pos;	// 小数点位置, 从右到左数
	};

	void run()
	{
		std::string str;
		float_big_number r;
		float_big_number res;
		int n;

		while (cin >> str >> n)
		{
			res.from_string("1");
			r.from_string(str);
			for (int i = 0; i < n; i++)
			{
				res.multiply(r);
			}
			cout << res.to_string() << endl;
		};
	}
}

*/




