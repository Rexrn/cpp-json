#include <RexrnCPPJSON/details/String.hpp>

#include <cassert>

namespace rexrn_cpp_json
{

namespace details
{

////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(char const* first_, char const* last_, bool readOnly_)
{
    this->set(first_, last_, readOnly_);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(String const & other_)
{
    *this = other_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(String && other_)
{
    *this = std::forward<String>(other_);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String& String::operator=(String && other_)
{
    _readOnly = other_.isReadOnly();

    if (!other_.isReadOnly()) {
        _string = std::move(other_.getString());
    }
    else {
        _begin = other_.begin();
        _end = other_.end();
    }
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String& String::operator=(String const & other_)
{
    this->set(other_.begin(), other_.end(), other_.isReadOnly());
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void String::set(char const* first_, char const* last_, bool readOnly_)
{
    _readOnly = readOnly_;

    if (_readOnly) {
        _begin = first_;
        _end = last_;
    }
    else {
        _string = std::string(first_, last_);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void String::makeManuallyAllocated()
{
    if ( this->isReadOnly() )
    {
        this->set(_begin, _end, false);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool String::isReadOnly() const
{
    return _readOnly;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
char const* String::begin() const
{
    return this->isReadOnly() ? _begin : _string.data();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
char const* String::end() const
{
    return this->isReadOnly() ? _end : _string.data() + _string.size();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const & String::getString() const
{
    // # Assertion note:
    // You've tried to get reference to underlying string, while this instance is storing read-only string.
    assert(!this->isReadOnly());
    return _string;
}

} // namespace details

} // namespace rexrn_cpp_json