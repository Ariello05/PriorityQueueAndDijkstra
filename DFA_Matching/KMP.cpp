#include "KMP.h"


KMP::KMP()
{
}

void KMP::runMatcher(const string& text, const string& pattern)
{
	Printer r;
	std::vector<int> offsets;

	pi.clear();
	compute_prefix_function(pattern);
	size_t n = text.size();
	size_t m = pattern.size();
	size_t q = 0;
	for (size_t i = 0; i < n; ++i) {
		while (q > 0 && pattern[q] != text[i]) {
			q = pi[q-1];
		}
		if (pattern[q] == text[i]) {
			q++;
		}
		if (q == m) {
			offsets.push_back(i - m + 1);
			q = pi[q-1];
		}
	}
	r.read(offsets, text, pattern);
}

void KMP::compute_prefix_function(const string & pattern)
{
	size_t n = pattern.size();
	pi.push_back(0);
	size_t k = 0;
	for (size_t q = 1; q < n; q++) {
		int k = pi[q - size_t(1)];
		while (k > 0 && pattern[q] != pattern[k])
			k = pi[k - size_t(1)];
		if (pattern[q] == pattern[k])
			k++;
		pi[q] = k;
	}
}
