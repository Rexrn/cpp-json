#pragma once

#include <string>

namespace rexrn_cpp_json
{

namespace details
{

/// <summary>
/// 	Wraps either read-only or manually allocated string.
/// </summary>
class String
{
	/// <summary>
	/// 	Construct a new <see cref="String"/>. Assigns specified characters to the string (either in read-only mode or not).
	/// </summary>
	/// <param name="first_">Pointer to the first string element.</param>
	/// <param name="last_">Pointer to the last+1 string element.</param>
	/// <param name="readOnly_">Whether to assign it in read-only mode or not.</param>
	String(char const* first_, char const* last_, bool readOnly_ = true);

	/// <summary>
	/// 	Construct a new <see cref="String"/> object using rvalue reference to moved other instance of the <see cref="String"/>.
	/// </summary>
	/// <param name="other_">rvalue ref to moved other instance of the <see cref="String"/></param>
	String(String && other_);

	/// <summary>
	/// 	Assigns specified characters to the string (either in read-only mode or not).
	/// </summary>
	/// <param name="first_">Pointer to the first string element.</param>
	/// <param name="last_">Pointer to the last+1 string element.</param>
	/// <param name="readOnly_">Whether to assign it in read-only mode or not.</param>
	void set(char const* first_, char const* last_, bool readOnly_ = true);

	/// <summary>
	/// 	Ensures that string is manually allocated. Will reallocate read-only string.
	/// </summary>
	void makeManuallyAllocated();

	/// <summary>
	/// 	Determines whether string is read-only or manually allocated.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if string is read-only; otherwise, <c>false</c>.
	/// </returns>
	bool isReadOnly() const;

	/// <summary>
	/// 	Pointer to const first element of the string (works for both read-only and non r-o strings).
	/// </summary>
	/// <returns>
	/// 	Pointer to const first element of the string.
	/// </returns>
	char const* begin() const;

	/// <summary>
	/// 	Pointer to const last+1 element of the string (works for both read-only and non r-o strings).
	/// </summary>
	/// <returns>
	/// 	Pointer to const last+1 element of the string.
	/// </returns>
	char const* end() const;

	/// <summary>
	/// 	cref to the underlying string. Results in undefined behaviour if string is read-only;
	/// </summary>
	/// <returns>
	/// 	cref to the underlying string.
	/// </returns>
	std::string const & getString() const;
	
private:
	bool _readOnly;
	union {
		struct {
			char const* _begin;
			char const* _end;
		};
		std::string _string;
	};
};

}

}