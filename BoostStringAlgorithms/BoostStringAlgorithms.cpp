#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <string>
#include <locale>
#include <vector>
#include <iostream>

using namespace boost::algorithm;

int main()
{
	std::string s = "Boost C++ Libraries";
	std::cout << to_upper_copy(s) << std::endl;

	s = "Boost C++ k\xfct\xfcphaneleri";
	std::string upper_case1 = to_upper_copy(s);
	std::string upper_case2 = to_upper_copy(s, std::locale{ "Turkish" });
	std::locale::global(std::locale{ "Turkish" });
	std::cout << upper_case1 << std::endl;
	std::cout << upper_case2 << std::endl;

	s = "Boost C++ Libraries";
	std::cout << erase_first_copy(s, "s") << std::endl;
	std::cout << erase_nth_copy(s, "s", 0) << std::endl;
	std::cout << erase_last_copy(s, "s") << std::endl;
	std::cout << erase_all_copy(s, "s") << std::endl;
	std::cout << erase_head_copy(s, 5) << std::endl;
	std::cout << erase_tail_copy(s, 9) << std::endl;

	s = "Boost C++ Libraries";
	boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
	std::cout << r << std::endl;
	r = find_first(s, "xyz");
	std::cout << r << std::endl;

	std::vector<std::string> v{ "Boost", "C++", "Libraries" };
	std::cout << join(v, " ") << std::endl;

	s = "Boost C++ Libraries";
	std::cout << replace_first_copy(s, "+", "-") << std::endl;
	std::cout << replace_nth_copy(s, "+", 0, "-") << std::endl;
	std::cout << replace_last_copy(s, "+", "-") << std::endl;
	std::cout << replace_head_copy(s, 5, "BOOST") << std::endl;
	std::cout << replace_tail_copy(s, 9, "LIBRARIES") << std::endl;

	s = "\t Boost C++ Libraries \t";
	std::cout << "_" << trim_left_copy(s) << "_" << std::endl;
	std::cout << "_" << trim_right_copy(s) << "_" << std::endl;
	std::cout << "_" << trim_copy(s) << "_" << std::endl;

	s = "--Boost C++ Libraries--";
	std::cout << trim_left_copy_if(s, is_any_of("-")) << std::endl;
	std::cout << trim_right_copy_if(s, is_any_of("-")) << std::endl;
	std::cout << trim_copy_if(s, is_any_of("-")) << std::endl;

	s = "123456789Boost C++ Libraries123456789";
	std::cout << trim_left_copy_if(s, is_digit()) << std::endl;
	std::cout << trim_right_copy_if(s, is_digit()) << std::endl;
	std::cout << trim_copy_if(s, is_digit()) << std::endl;

	s = "Boost C++ Libraries";
	std::cout.setf(std::ios::boolalpha);
	std::cout << starts_with(s, "Boost") << std::endl;
	std::cout << ends_with(s, "Libraries") << std::endl;
	std::cout << contains(s, "C++") << std::endl;
	std::cout << lexicographical_compare(s, "Boost") << std::endl;

	s = "Boost C++ Libraries";
	std::vector<std::string> v1;
	split(v, s, is_space());
	std::cout << v.size() << std::endl;

	s = "Boost C++ Libraries";
	boost::iterator_range<std::string::iterator> r1 = find_regex(s, boost::regex{ "\\w\\+\\+" });
	std::cout << r1 << std::endl;
}

