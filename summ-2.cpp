
#include <iostream> 
#include <algorithm>
#include <iterator>

using namespace std;

template <typename Iterator, typename T>
auto find_two_elements_with_sum(Iterator first, Iterator last, T c)->std::pair<bool, std::pair<Iterator, Iterator>>
{
	//first - Unidirectional
	//last - Bidirectional
	std::pair<bool, std::pair<Iterator, Iterator>> p;
	p.first = false;
	p.second.first = nullptr;
	p.second.second = nullptr;
	if (std::distance(first, last) == 0) throw "?";
	while (!p.first)
	{
		if (*first + *last < c) first++;
		if (*first + *last > c) last--;
		if (*first + *last == c)
		{
			p.first = true;
			p.second.first = first;
			p.second.second = last;
		}
		if (std::distance(first, last) == 0) break;
	}

}
