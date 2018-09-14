// Include Rexrn C++ JSON:
#define REXRN_CPP_JSON_HEADER_ONLY
#include <RexrnCPPJSON/Everything.hpp>

// Includes std
#include <iostream>
#include <string>

namespace json = rexrn_cpp_json;

int main()
{
	// The test case JSON:
	std::string weapons = R"json(
		[
			{
				name: "Short Sword",
				attack: 20,
				requirements: {
					minStrength: 20
					minLevel: 4
				}
			},
			{
				name: "Longsword",
				attack: 32,
				requirements: {
					minStrength: 27
					minLevel: 6
				}
			}
		]
	)json";

	// Parsing and error handling:
	try {
		json::Property root = json::parse(weapons);
	}
	catch (json::ParseException& exc) {
		std::cerr << "Could not parse test case JSON.\nDetails: \"" << exc.what() << "\"" << std::endl;
	}
	catch (std::exception & exc) {
		std::cerr << "Unexpected error ocurred while parsing JSON test case.\nDetails: \"" << exc.what() << "\"" << std::endl;
	}
	catch(...) {
		std::cerr << "Unexpected error ocurred while parsing JSON test case.\nNo details available." << std::endl;
	}
}