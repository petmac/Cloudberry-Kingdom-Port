#ifndef _STRING_H_
#define _STRING_H_

#include <string>
#include <algorithm>

int GetHashCode( const std::wstring &s )
{
	// FIXME
	return 0;
}

inline std::wstring ToLower( const std::wstring &s )
{
	std::wstring lower = s;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

	return lower;
}

inline int CompareIgnoreCase( const std::wstring &s1, const std::wstring &s2)
{
	std::wstring::const_iterator it1, it2;
	
	for( it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); ++it1, ++it2 )
	{
		int cmp = tolower( *it1 ) - tolower( *it2 );

		if( cmp != 0 )
		{
			return cmp;
		}
	}

	if( it1 == s1.end() && it2 == s2.end() )
		return 0;

	return ( it1 == s1.end() ) ? -1 : 1;
}

inline std::wstring Format( const wchar_t *fmt, ... )
{
	// FIXME: Implement this.
	return _T( "" );
}

std::vector<std::wstring> &Split( const std::wstring &s, wchar_t delim, std::vector<std::wstring> &elems )
{
    std::wstringstream ss(s);
    std::wstring item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::wstring> Split( const std::wstring &s, wchar_t delim )
{
    std::vector<std::wstring> elems;
    return Split(s, delim, elems);
}

#endif