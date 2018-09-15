#include "../include/RexrnCPPJSON/Property.hpp"

#include <utility>

namespace rexrn_cpp_json
{

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(String const &name_, Value const & value_)
	: _name{ name_ }, _value{ value_ }
{
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(String const &name_, Value && value_)
	: _name{ name_ }, _value{ std::forward<Value>(value_) }
{
	
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(String &&name_, Value const & value_)
	: _name{ std::forward<String>(name_) }, _value{ value_ }
{
	
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(String &&name_, Value && value_)
	: _name{ std::forward<String>(name_) }, _value{ std::forward<Value>(value_) }
{
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(Property const & other_)
{
	*this = other_;
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property::Property(Property && other_)
{
	*this = std::forward<Property>(other_);
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property& Property::operator=(Property const & other_)
{
	if (this != &other_)
	{
		_name = std::move(other_.getName());
		_value = std::move(other_.getValue());
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////
Property& Property::operator=(Property && other_)
{
	if (this != &other_)
	{
		_name = std::move(other_._name);
		_value = std::move(other_._value);
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Property::setName(String const & name_)
{
	_name = name_;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Property::setName(String && name_)
{
	_name = std::forward<String>(name_);
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Property::setValue(Value const & value_)
{
	_value = value_;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Property::setValue(Value && value_)
{
	_value = std::forward<Value>(value_);
}

///////////////////////////////////////////////////////////////////////////////////////////////
String const& Property::getName() const
{
	return _name;
}

///////////////////////////////////////////////////////////////////////////////////////////////
Value const& Property::getValue() const
{
	return _value;
}

}