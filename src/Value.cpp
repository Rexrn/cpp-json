#include "../include/RexrnCPPJSON/Value.hpp"
#include "../include/RexrnCPPJSON/details/Utility.hpp"

#include <cassert>

namespace rexrn_cpp_json
{

///////////////////////////////////////////////////////////////////////////
Value::Value()
	: _type{ Type::Null }
{
}

///////////////////////////////////////////////////////////////////////////
Value::Value(Value const& other_)
{
	*this = other_;
}

///////////////////////////////////////////////////////////////////////////
Value::Value(Value && other_)
{
	*this = std::forward<Value>(other_);
}

///////////////////////////////////////////////////////////////////////////
Value::~Value()
{
	this->cleanup();
}

///////////////////////////////////////////////////////////////////////////
Value& Value::operator=(Value const & other_)
{
	if (this != &other_)
    {
		_type = other_.getType();
		switch (_type)
		{
		case Type::Number:
			_number = other_.getNumber();
			break;
		case Type::String:
			_string = other_.getString();
			break;
		case Type::Object:
			_objectProperties = other_.getObject();
			break;
		case Type::Array:
			_array = other_.getArray();
			break;
		case Type::Comment:
			_string = other_.getString();
			break;
		default: break;
		}
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////
Value& Value::operator=(Value && other_)
{
	if (this != &other_)
    {
		_type = other_.getType();
		switch (_type)
		{
		case Type::Number:
			_number = other_.getNumber();
			break;
		case Type::String:
			_string = std::move( other_.getStringRef() );
			break;
		case Type::Object:
			_objectProperties = std::move( other_.getObjectRef() );
			break;
		case Type::Array:
			_array =  std::move( other_.getArrayRef() );
			break;
		case Type::Comment:
			_string = std::move( other_.getStringRef() );
			break;
		default: break;
		}
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////
void Value::cleanup()
{
	switch (_type)
	{
	case Type::String:
		details::callDefaultDestructor(_string);
		break;
	case Type::Object:
		details::callDefaultDestructor(_objectProperties);
		break;
	case Type::Array:
		details::callDefaultDestructor(_array);
		break;
	case Type::Comment:
		details::callDefaultDestructor(_string);
		break;
	default: break;
	}
	_type = Type::Null;
}

///////////////////////////////////////////////////////////////////////////
Value Value::number(double number_)
{
	Value result{};
	result._type = Type::Number;
	result._number = number_;
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::string(String const & string_)
{
	Value result{};
	result._type = Type::String;
	result._string = string_;
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::string(String && string_)
{
	Value result{};
	result._type = Type::String;
	result._string = std::forward<String>(string_);
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::object(std::vector<Property> const & properties_)
{
	Value result{};
	result._type = Type::Object;
	result._objectProperties = properties_;
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::object(std::vector<Property> && properties_)
{
	Value result{};
	result._type = Type::Object;
	result._objectProperties = std::forward< std::vector<Property> >(properties_);
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::array(std::vector<Value> const & values_)
{
	Value result{};
	result._type = Type::Array;
	result._array = values_;
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::array(std::vector<Value> && values_)
{
	Value result{};
	result._type = Type::Array;
	result._array = std::forward< std::vector<Value> >(values_);
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::comment(String const & text_)
{
	Value result{};
	result._type = Type::Comment;
	result._string = text_;
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::comment(String && text_)
{
	Value result{};
	result._type = Type::Comment;
	result._string = std::forward<String>(text_);
	return result;
}

///////////////////////////////////////////////////////////////////////////
Value Value::null()
{
	return Value{};
}

///////////////////////////////////////////////////////////////////////////
void Value::setNumber(double number_)
{
	this->cleanup();
	_type = Type::Number;
	_number = number_;
}

///////////////////////////////////////////////////////////////////////////
void Value::setString(String const & string_)
{
	this->cleanup();
	_type = Type::String;
	_string = string_;
}

///////////////////////////////////////////////////////////////////////////
void Value::setString(String && string_)
{
	this->cleanup();
	_type = Type::String;
	_string = std::forward<String>(string_);
}

///////////////////////////////////////////////////////////////////////////
void Value::setObject(std::vector<Property> const & properties_)
{
	this->cleanup();
	_type = Type::Object;
	_objectProperties = properties_;
}

///////////////////////////////////////////////////////////////////////////
void Value::setObject(std::vector<Property> && properties_)
{
	this->cleanup();
	_type = Type::Object;
	_objectProperties = std::forward< std::vector<Property> >(properties_);
}

///////////////////////////////////////////////////////////////////////////
void Value::setArray(std::vector<Value> const & values_)
{
	this->cleanup();
	_type = Type::Array;
	_array = values_;
}

///////////////////////////////////////////////////////////////////////////
void Value::setArray(std::vector<Value> && values_)
{
	this->cleanup();
	_type = Type::Array;
	_array = std::forward< std::vector<Value> >(values_);
}

///////////////////////////////////////////////////////////////////////////
void Value::setComment(String const & text_)
{
	this->cleanup();
	_type = Type::Comment;
	_string = text_;
}

///////////////////////////////////////////////////////////////////////////
void Value::setComment(String && text_)
{
	this->cleanup();
	_type = Type::Comment;
	_string = std::forward<String>(text_);
}

///////////////////////////////////////////////////////////////////////////
void Value::nullify()
{
	this->cleanup();
}

///////////////////////////////////////////////////////////////////////////
Value::Type Value::getType() const
{
	return _type;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isNumber() const
{
	return _type == Type::Number;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isString() const
{
	return _type == Type::String;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isObject() const
{
	return _type == Type::Object;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isArray() const
{
	return _type == Type::Array;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isComment() const
{
	return _type == Type::Comment;
}

///////////////////////////////////////////////////////////////////////////
bool Value::isNull() const
{
	return _type == Type::Null;
}

///////////////////////////////////////////////////////////////////////////
double& Value::getNumberRef()
{
	// # Assertion note:
	// You've tried to get number value, while this instance is storing other kind of value.
	assert(this->isNumber());
	return _number;
}

///////////////////////////////////////////////////////////////////////////
String& Value::getStringRef()
{
	// # Assertion note:
	// You've tried to get string value, while this instance is storing other kind of value.
	assert(this->isString());
	return _string;
}

///////////////////////////////////////////////////////////////////////////
std::vector<Property>& Value::getObjectRef()
{
	// # Assertion note:
	// You've tried to get object value, while this instance is storing other kind of value.
	assert(this->isObject());
	return _objectProperties;
}

///////////////////////////////////////////////////////////////////////////
std::vector<Value>& Value::getArrayRef()
{
	// # Assertion note:
	// You've tried to get array value, while this instance is storing other kind of value.
	assert(this->isArray());
	return _array;
}

///////////////////////////////////////////////////////////////////////////
String& Value::getCommentRef()
{
	// # Assertion note:
	// You've tried to get comment value, while this instance is storing other kind of value.
	assert(this->isComment());
	return _string;
}

///////////////////////////////////////////////////////////////////////////
double const& Value::getNumber() const
{
	// # Assertion note:
	// You've tried to get number value, while this instance is storing other kind of value.
	assert(this->isNumber());
	return _number;
}

///////////////////////////////////////////////////////////////////////////
String const& Value::getString() const
{
	// # Assertion note:
	// You've tried to get string value, while this instance is storing other kind of value.
	assert(this->isString());
	return _string;
}

///////////////////////////////////////////////////////////////////////////
std::vector<Property> const& Value::getObject() const
{
	// # Assertion note:
	// You've tried to get object value, while this instance is storing other kind of value.
	assert(this->isObject());
	return _objectProperties;
}

///////////////////////////////////////////////////////////////////////////
std::vector<Value> const& Value::getArray() const
{
	// # Assertion note:
	// You've tried to get array value, while this instance is storing other kind of value.
	assert(this->isArray());
	return _array;
}

///////////////////////////////////////////////////////////////////////////
String const& Value::getComment() const
{
	// # Assertion note:
	// You've tried to get comment value, while this instance is storing other kind of value.
	assert(this->isComment());
	return _string;
}


}