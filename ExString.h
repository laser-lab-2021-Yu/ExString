#pragma once

//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include<iostream>
#include<sstream>

// string型, const char*型への型変換が可能な可変長引数を扱える文字列クラス
class ExString
{
public:

	ExString();
	ExString(const std::string& str);
	ExString(const char* format, ...);
	ExString(const ExString&) = default;

	//----------------------------------------------------------------
	// 代入演算子
	//----------------------------------------------------------------

	const ExString& operator=(const ExString& ex);
	const ExString& operator=(const std::string& str);
	const ExString& operator=(const char* cstr);

	//----------------------------------------------------------------
	// 変換演算子
	//----------------------------------------------------------------

	// FIXME : なぜかExString型からstring型への明示的な型変換ができない
	// FIXME : ExString型からstring型への代入があいまいなせいで行えない
	operator std::string();
	operator std::string() const;
	operator const char*();
	operator const char*() const;

	//----------------------------------------------------------------
	// 挿入演算子
	//----------------------------------------------------------------

	friend std::istream& operator>>(std::istream& is, ExString& ex);

	//----------------------------------------------------------------
	// 連結演算子
	//----------------------------------------------------------------

	friend ExString operator+(const ExString& a, const ExString& b);
	const ExString& operator+=(const ExString& a);

	//----------------------------------------------------------------
	// アクセッサ
	//----------------------------------------------------------------

	std::string GetStr() const;
	const char* GetCStr() const;

	void SetStr(const std::string& str);
	void SetCStr(const char* format, ...);

	bool Debug() const;

private:

	std::string _str;
};

inline const ExString& ExString::operator=(const ExString& ex)
{
	_str = ex._str;
	return *this;
}

inline const ExString& ExString::operator=(const std::string& str)
{
	_str = str;
	return *this;
}

inline const ExString& ExString::operator=(const char* cstr)
{
	_str = cstr;
	return *this;
}

inline ExString::operator std::string()		  { return _str; }
inline ExString::operator std::string() const { return _str; }
inline ExString::operator const char*()		  { return _str.c_str(); }
inline ExString::operator const char*() const { return _str.c_str(); }

inline std::string ExString::GetStr() const  { return _str; }
inline const char* ExString::GetCStr() const { return _str.c_str(); }

inline void ExString::SetStr(const std::string& str) { _str = str; }

inline std::istream& operator>>(std::istream& is, ExString& ex) { return std::getline(is, ex._str); }

inline ExString operator+(const ExString& a, const ExString& b) { return ExString(a._str + b._str); }
inline const ExString& ExString::operator+=(const ExString& a)
{
	_str += a._str;
	return *this;
}
