

#ifndef CFS_ARKHE_GCS_UTILS_HELPERS_HPP
#define CFS_ARKHE_GCS_UTILS_HELPERS_HPP

#include <system_error>
#include <type_traits>
#include <memory>

namespace cfs::arkhe::gcs::utils
{
    template<class T> using has_value_impl = decltype( std::declval<T>().value );

    template <class T>
    struct is_error_type_default
    {
        static constexpr bool value = has_value<T>::value || std::is_base_of<std::exception,T>::value;
    };
    template <class T>
    struct is_type : cfs::utils::is_error_type_default<T> { };
    template <class T>
    struct is_type<T const>: is_type<T> { };
    template <class T>
    struct is_type<T const &>: is_type<T> { };
    template <class T>
    struct is_type<T &>: is_type<T> { };
    template <>
    struct is_type<std::error_code>: std::false_type { };
}
#endif

