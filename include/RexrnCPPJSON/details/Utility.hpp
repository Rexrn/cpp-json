#pragma once

namespace rexrn_cpp_json
{

namespace details
{

/// <summary>
/// 	Calls default destructor for the specified object.
/// </summary>
/// <typename name="T">Type of the object.</typename>
/// <param name="object_">The object.</param>
template <typename T>
void callDefaultDestructor(T & object_)
{
	object_.~T();
}

} // namespace details

} // namespace rexrn_cpp_json