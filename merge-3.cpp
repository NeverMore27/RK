#include <iostream> 
#include <iterator>

using namespace std;

template <typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output)->Iterator2
{
	while ((first1<last1) || (first2<last2))
	{
		if (*first1 < *first2)
		{
			*output = *first1;
			output++;
			first1++;
		}
		if (*first1 > *first2)
		{
			*output = *first2;
			output++;
			first2++;
		}
		else
		{
			*output = *first1;
			output++;
			*output = *first2;
			first1++; first2++;
		}
	}
	if (first1 == last1)
		while (first2 < last2)
		{
			*output = *first2;
			output++; first2++;
		}
	else
	{
		*output = *first1;
		output++; first1++;
	}
	return output;
}

int main()
{
	int a[] = { 0, 2, 8, 17 };
	int b[] = { 1, 4, 7, 18 };
	int c[10];
	merge(a, a + 4, b, b + 4, c);
	for (int i = 0; i < 8; i++) std::cout << c[i] << endl;
	int ci;
	cin >> ci;
	return 0;
}
