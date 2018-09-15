#pragma once

#include "String.hpp"

#include <vector>

namespace rexrn_cpp_json
{
class Property;

/// <summary>
/// 	Stores JSON value.
/// </summary>
class Value
{
public:

	/// <summary>
	/// 	Enumeration of every possible type of JSON value.
	/// </summary>
	enum class Type
	{
		Number,
		String,
		Object,
		Array,
		Comment,
		Null
	};
	
	/// <summary>
	/// 	Construct a new <see cref="Value"/> object with null value.
	/// </summary>
	Value();

	/// <summary>
	/// 	Construct a new <see cref="Value"/> object. Copies content from other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Value"/> instance to copy from.</param>
	Value(Value const& other_);

	/// <summary>
	/// 	Construct a new <see cref="Value"/> object. Moves content from other instance.
	/// </summary>
	/// <param name="other_">Other <see cref="Value"/> instance to move from.</param>
	Value(Value && other_);

	/// <summary>
	/// 	Destroy the <see cref="Value"/> object
	/// </summary>
	~Value();

	/// <summary>
	/// 	Assigns new value to the instance. Copies values from other instance of the <see cref="Value"/>.
	/// </summary>
	/// <param name="other_">Other <see cref="Value"/> instance to copy from.</param>
	/// <returns>
	/// 	Reference to self.
	/// </returns>
	Value& operator=(Value const & other_);

	/// <summary>
	/// 	Assigns new value to the instance. Moves values from other instance of the <see cref="Value"/>.
	/// </summary>
	/// <param name="other_">Other <see cref="Value"/> instance to move from.</param>
	/// <returns>
	/// 	Reference to self.
	/// </returns>
	Value& operator=(Value && other_);  

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns number to it.
	/// </summary>
	/// <param name="number_">The number.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value number(double number_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns string to it.
	/// </summary>
	/// <param name="string_">The string.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value string(String const & string_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns string to it (uses move semantics).
	/// </summary>
	/// <param name="string_">The string.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value string(String && string_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns object to it.
	/// </summary>
	/// <param name="properties_">Properies of the object.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value object(std::vector<Property> const & properties_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns object to it (uses move semantics).
	/// </summary>
	/// <param name="properties_">Properies of the object.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value object(std::vector<Property> && properties_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns array to it.
	/// </summary>
	/// <param name="values_">Values of the array.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value array(std::vector<Value> const & values_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns array to it (uses move semantics).
	/// </summary>
	/// <param name="values_">Values of the array.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value array(std::vector<Value> && values_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns comment to it.
	/// </summary>
	/// <param name="text_">The comment text.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value comment(String const & text_);

	/// <summary>
	/// 	Creates new instance of the <see cref="Value"/> class and assigns comment to it (uses move semantics).
	/// </summary>
	/// <param name="text_">The comment text.</param>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value comment(String && text_);

	/// <summary>
	/// 	Creates new, nulled instance of the <see cref="Value"/>.
	/// </summary>
	/// <returns>
	/// 	Created <see cref="Value"/> instance.
	/// </returns>
	static Value null();

	/// <summary>
	/// 	Sets type to the <see cref="Type::Number"/> and assigns its value.
	/// </summary>
	/// <param name="number_">The number.</param>
	void setNumber(double number_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::String"/> and assigns its value.
	/// </summary>
	/// <param name="string_">The string.</param>
	void setString(String const & string_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::String"/> and assigns its value (uses move semantics).
	/// </summary>
	/// <param name="string_">The string.</param>
	void setString(String && string_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Object"/> and assigns its value.
	/// </summary>
	/// <param name="properties_">Properties of the object.</param>
	void setObject(std::vector<Property> const & properties_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Object"/> and assigns its value (uses move semantics).
	/// </summary>
	/// <param name="properties_">Properties of the object.</param>
	void setObject(std::vector<Property> && properties_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Array"/> and assigns its value.
	/// </summary>
	/// <param name="values_">Values of the array.</param>
	void setArray(std::vector<Value> const & values_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Array"/> and assigns its value (uses move semantics).
	/// </summary>
	/// <param name="values_">Values of the array.</param>
	void setArray(std::vector<Value> && values_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Comment"/> and assigns its value.
	/// </summary>
	/// <param name="text_">The comment text.</param>
	void setComment(String const & text_);

	/// <summary>
	/// 	Sets type to the <see cref="Type::Comment"/> and assigns its value (uses move semantics).
	/// </summary>
	/// <param name="text_">The comment text.</param>
	void setComment(String && text_);

	/// <summary>
	/// 	Drops current value and makes this instance a null one.
	/// </summary>
	void nullify();

	/// <summary>
	/// 	Returns type of the JSON value.
	/// </summary>
	/// <returns>
	/// 	<see cref="Type"/> of the JSON value.
	/// </returns>
	Type getType() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::Number"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::Number"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isNumber() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::String"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::String"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isString() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::Object"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::Object"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isObject() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::Array"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::Array"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isArray() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::Comment"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::Comment"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isComment() const;

	/// <summary>
	/// 	Determines whether value is of type <see cref="Type::Null"/>.
	/// </summary>
	/// <returns>
	/// 	<c>true</c> if value is of type <see cref="Type::Null"/>; otherwise, <c>false</c>.
	/// </returns>
	bool isNull() const;

	/// <summary>
	/// 	Returns ref to the stored number.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Number"/>.
	/// </summary>
	/// <returns>
	/// 	ref to the stored number.
	/// </returns>
	double& getNumberRef();

	/// <summary>
	/// 	Returns ref to the stored string.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::String"/>.
	/// </summary>
	/// <returns>
	/// 	ref to the stored string.
	/// </returns>
	String& getStringRef();

	/// <summary>
	/// 	Returns ref to the stored object (vector of <see cref="Property"/>).
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Object"/>.
	/// </summary>
	/// <returns>
	/// 	ref to the stored object.
	/// </returns>
	std::vector<Property>& getObjectRef();

	/// <summary>
	/// 	Returns ref to the stored array (vector of <see cref="Value"/>).
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Array"/>.
	/// </summary>
	/// <returns>
	/// 	ref to the stored array.
	/// </returns>
	std::vector<Value>& getArrayRef();

	/// <summary>
	/// 	Returns ref to the stored comment text.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Comment"/>.
	/// </summary>
	/// <returns>
	/// 	ref to the stored comment text.
	/// </returns>
	String& getCommentRef();

	/// <summary>
	/// 	Returns cref to the stored number.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Number"/>.
	/// </summary>
	/// <returns>
	/// 	cref to the stored number.
	/// </returns>
	double const& getNumber() const;

	/// <summary>
	/// 	Returns cref to the stored string.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::String"/>.
	/// </summary>
	/// <returns>
	/// 	cref to the stored string.
	/// </returns>
	String const& getString() const;

	/// <summary>
	/// 	Returns cref to the stored object (vector of <see cref="Property"/>).
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Object"/>.
	/// </summary>
	/// <returns>
	/// 	cref to the stored object.
	/// </returns>
	std::vector<Property> const& getObject() const;

	/// <summary>
	/// 	Returns cref to the stored array (vector of <see cref="Value"/>).
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Array"/>.
	/// </summary>
	/// <returns>
	/// 	cref to the stored array.
	/// </returns>
	std::vector<Value> const& getArray() const;

	/// <summary>
	/// 	Returns cref to the stored comment text.
	///     Results in undefined behaviour if this instance is not of type <see cref="Type::Comment"/>.
	/// </summary>
	/// <returns>
	/// 	cref to the stored comment text.
	/// </returns>
	String const& getComment() const;
private:

	/// <summary>
	/// 	Destroys current value and sets type to <see cref="Type::Null"/>.
	/// </summary>
	void cleanup();

	Type _type;
	union
	{
		double                      _number;
		String                      _string;
		std::vector<Property>       _objectProperties;
		std::vector<Value>          _array;
	};
};

}