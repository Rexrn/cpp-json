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
/// 	Parses JSON contents accessed using iterators from range [first, last).
/// </summary>
/// <typename name="TForwardIterator">Type of the forward iterator used to access JSON content.</typename> 
/// <param name="first_">Param</param>
/// <param name="last_">Param</param>
/// <returns>
/// 	ReturnDescription
/// </returns>
template <typename TForwardIterator>
Property parse(TForwardIterator first_, TForwardIterator last_)
{
	throw std::logic_error("Not implemented.");
}

/// <summary>
///     Parses JSON contents stored within specified string.
/// </summary>
/// <param name="jsonContents_">JSON string.</param>
/// <returns>
///     Root property of the specified JSON.
/// </returns>
template <typename TChar>
Property parse(std::basic_string<TChar> const &JSONContents_)
{
	return parse(JSONContents_.data(), JSONContents_.data() + JSONContents_.length());
}

}