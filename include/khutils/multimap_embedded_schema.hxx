#include <string>

const std::string multimap_embedded_schema(
R"(
namespace khutils.string_multimap;

/// simple simili-multimap type for Flatbuffers
/// maps a key to a number of values
/// key: string
/// values: array of strings
table MapEntry
{
key:
	string(key);
values:
	[string];
}

/// container for multimap entries
table Map
{
entries:
	[MapEntry];
}

)");
