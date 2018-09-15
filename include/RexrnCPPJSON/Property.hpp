#pragma once

#include "Value.hpp"
#include "String.hpp"

#include <vector>
#include <memory>

namespace rexrn_cpp_json
{

/// <summary>
/// 	A JSON property with a name and a value.
/// </summary>
class Property
{
public:

	/// <summary>
	/// 	Construct a new <see cref="Property"/> object.
	/// </summary>
	/// <param name="name_">Property name.</param>
	/// <param name="value_">Property value (null by default).</param>
	explicit Property(String const &name_, Value const & value_={});

	/// <summary>
	/// 	Construct a new <see cref="Property"/> object.
	/// 	Moves value from `value_` passed as rvalue ref.
	/// </summary>
	/// <param name="name_">Property name.</param>
	/// <param name="value_">Property value (null by default).</param>
	explicit Property(String const &name_, Value && value_={});

	/// <summary>
	/// 	Construct a new <see cref="Property"/> object.
	/// 	Moves value from `name_` passed as rvalue ref.
	/// </summary>
	/// <param name="name_">Property name.</param>
	/// <param name="value_">Property value (null by default).</param>
	explicit Property(String &&name_, Value const & value_={});

	/// <summary>
	/// 	Construct a new <see cref="Property"/> object.
	/// 	Moves value from `name_` passed as rvalue ref.
	/// 	Moves value from `value_` passed as rvalue ref.
	/// </summary>
	/// <param name="name_">Property name.</param>
	/// <param name="value_">Property value (null by default).</param>
	explicit Property(String &&name_, Value && value_={});
	
	/// <summary>
	/// 	Construct a new <see cref="Property"> object. Copies values from the other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Property"/> instance.</param>
	Property(Property const & other_);

	/// <summary>
	/// 	Construct a new <see cref="Property"> object. Moves values from the other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Property"/> instance.</param>
	Property(Property && other_);

	/// <summary>
	/// 	Assigns values copied from the other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Property"/> instance.</param>
	Property& operator=(Property const & other_);

	/// <summary>
	/// 	Assigns values moved from the other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Property"/> instance.</param>
	Property& operator=(Property && other_);

	/// <summary>
	/// 	Sets the name of the property.
	/// </summary>
	/// <param name="name_">Property name.</param>
	void setName(String const & name_);

	/// <summary>
	/// 	Sets the name of the property (uses move semantics).
	/// </summary>
	/// <param name="name_">Property name.</param>
	void setName(String && name_);

	/// <summary>
	/// 	Sets the value of the property.
	/// </summary>
	/// <param name="value_">Property value.</param>
	void setValue(Value const & value_);

	/// <summary>
	/// 	Sets the value of the property (uses move semantics).
	/// </summary>
	/// <param name="value_">Property value.</param>
	void setValue(Value && value_);

	/// <summary>
	/// 	Returns ref to the property name.
	/// </summary>
	/// <returns>
	/// 	ref to the property name.
	/// </returns>
	String const& getName() const;

	/// <summary>
	/// 	Returns ref to the property value.
	/// </summary>
	/// <returns>
	/// 	ref to the property value.
	/// </returns>
	Value const& getValue() const;

private:
	String 	_name;
	Value 	_value;
};

}