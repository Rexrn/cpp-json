#pragma once

#include "Property.hpp"

#include <string>
#include <stdexcept>

namespace rexrn_cpp_json
{
class Property;

/// <summary>
/// 	Exception that ocurred during and is directly associated with JSON parsing.
/// </summary>
struct ParseException : std::exception {
    using std::exception::exception;
};

/// <summary>
///     Parses JSON contents stored within specified string.
/// </summary>
/// <param name="jsonContents_">JSON string.</param>
/// <summary>
///     Root property of the specified JSON.
/// </summary>
template <typename TChar>
Property parse(std::basic_string<TChar> const &JSONContents_);

}