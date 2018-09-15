#pragma once

#include <string>

namespace rexrn_cpp_json
{

/// <summary>
/// 	Wraps either read-only or manually allocated string.
/// </summary>
class String
{
public:

	/// <summary>
	/// 	Construct a new, nulled <see cref="String"/> instance.
	/// </summary>
	String();

	/// <summary>
	/// 	Construct a new <see cref="String"/>. Copies and assigns bytes of the specified string.
	/// </summary>
	template <typename TChar>
	String(std::basic_string<TChar> const & string_)
		: _readOnly{ false }
	{
		if (!string_.empty())
		{
			_string.assign(
					reinterpret_cast<char const*>(string_.data()),
					reinterpret_cast<char const*>(string_.data() + string_.size())
				);
		}
	}

	/// <summary>
	/// 	Construct a new <see cref="String"/>. Assigns specified characters to the string (either in read-only mode or not).
	/// </summary>
	/// <param name="first_">Pointer to the first string element.</param>
	/// <param name="last_">Pointer to the last+1 string element.</param>
	/// <param name="readOnly_">Whether to assign it in read-only mode or not.</param>
	String(char const* first_, char const* last_, bool readOnly_ = true);

	/// <summary>
	/// 	Construct a new <see cref="String"/> object using cref to other instance of the <see cref="String"/>.
	/// </summary>
	/// <param name="other_">cref to other instance of the <see cref="String"/></param>
	String(String const & other_); // to impl

	/// <summary>
	/// 	Construct a new <see cref="String"/> object using rvalue reference to moved other instance of the <see cref="String"/>.
	/// </summary>
	/// <param name="other_">rvalue ref to moved other instance of the <see cref="String"/></param>
	String(String && other_);

	/// <summary>
	/// 	Destroy the String object
	/// </summary>
	~String();

	/// <summary>
	/// 	Assigns new value to the instance. Moves values from other instance of the <see cref="String"/>.
	/// </summary>
	/// <param name="other_">rvalue ref to moved other instance of the <see cref="String"/></param>
	String& operator=(String && other_); // to impl

	/// <summary>
	/// 	Assigns new value to the instance. Copies values from other instance of the <see cref="String"/>.
	/// </summary>
	/// <param name="other_">cref to other instance of the <see cref="String"/></param>
	String& operator=(String const & other_); // to impl

	/// <summary>
	/// 	Resets this instance to null string.
	/// </summary>
	void reset();

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
	
	/// <summary>
	/// 	Determines whether string is not set at all.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if string is not set; otherwise, <c>false</c>.
	/// </returns>
	bool isNull() const;

private:

	/// <summary>
	/// 	Calls destructor for members in union (this needs to be done manually).
	/// </summary>
	void cleanup();

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