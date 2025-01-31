#include <lib/magic_enum.hpp>
#include <string>
#include <type_traits>

// A macro that returns a std::string with enumerator names separated by commas,
// skipping the sentinel enumerator named "COUNT" if present:
#define ENUM_TO_STRING(EnumType, CountEnumerator) \
    ([](){ \
        constexpr auto _names = magic_enum::enum_names<EnumType>(); \
        std::string _result; \
        bool _first = true; \
        for (auto _name : _names) { \
            if (_name == #CountEnumerator) { \
                continue; \
            } \
            if (!_first) { \
                _result += ","; \
            } \
            _result += std::string{_name}; \
            _first = false; \
        } \
        return _result; \
    }())
