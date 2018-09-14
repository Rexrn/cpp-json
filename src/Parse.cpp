#include <RexrnCPPJSON/Parse.hpp>

#include <RexrnCPPJSON/Property.hpp>

namespace rexrn_cpp_json
{

/////////////////////////////////////////////////////////////////////////////
template <typename TChar>
Property parse(std::basic_string<TChar> const &JSONContents_)
{
    throw std::logic_error("Not implemented yet.");
}

// Explicitly link templates for following types:
template Property parse<char>(std::basic_string<char> const &);
template Property parse<wchar_t>(std::basic_string<wchar_t> const &);
template Property parse<char16_t>(std::basic_string<char16_t> const &);
template Property parse<char32_t>(std::basic_string<char32_t> const &);

}