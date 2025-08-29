// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__TRAITS_HPP_
#define GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "greenstory_interfaces/srv/detail/tell_story__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace greenstory_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TellStory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TellStory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TellStory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace greenstory_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use greenstory_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const greenstory_interfaces::srv::TellStory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  greenstory_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use greenstory_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const greenstory_interfaces::srv::TellStory_Request & msg)
{
  return greenstory_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<greenstory_interfaces::srv::TellStory_Request>()
{
  return "greenstory_interfaces::srv::TellStory_Request";
}

template<>
inline const char * name<greenstory_interfaces::srv::TellStory_Request>()
{
  return "greenstory_interfaces/srv/TellStory_Request";
}

template<>
struct has_fixed_size<greenstory_interfaces::srv::TellStory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<greenstory_interfaces::srv::TellStory_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<greenstory_interfaces::srv::TellStory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace greenstory_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TellStory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: story
  {
    out << "story: ";
    rosidl_generator_traits::value_to_yaml(msg.story, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TellStory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: story
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "story: ";
    rosidl_generator_traits::value_to_yaml(msg.story, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TellStory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace greenstory_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use greenstory_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const greenstory_interfaces::srv::TellStory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  greenstory_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use greenstory_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const greenstory_interfaces::srv::TellStory_Response & msg)
{
  return greenstory_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<greenstory_interfaces::srv::TellStory_Response>()
{
  return "greenstory_interfaces::srv::TellStory_Response";
}

template<>
inline const char * name<greenstory_interfaces::srv::TellStory_Response>()
{
  return "greenstory_interfaces/srv/TellStory_Response";
}

template<>
struct has_fixed_size<greenstory_interfaces::srv::TellStory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<greenstory_interfaces::srv::TellStory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<greenstory_interfaces::srv::TellStory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<greenstory_interfaces::srv::TellStory>()
{
  return "greenstory_interfaces::srv::TellStory";
}

template<>
inline const char * name<greenstory_interfaces::srv::TellStory>()
{
  return "greenstory_interfaces/srv/TellStory";
}

template<>
struct has_fixed_size<greenstory_interfaces::srv::TellStory>
  : std::integral_constant<
    bool,
    has_fixed_size<greenstory_interfaces::srv::TellStory_Request>::value &&
    has_fixed_size<greenstory_interfaces::srv::TellStory_Response>::value
  >
{
};

template<>
struct has_bounded_size<greenstory_interfaces::srv::TellStory>
  : std::integral_constant<
    bool,
    has_bounded_size<greenstory_interfaces::srv::TellStory_Request>::value &&
    has_bounded_size<greenstory_interfaces::srv::TellStory_Response>::value
  >
{
};

template<>
struct is_service<greenstory_interfaces::srv::TellStory>
  : std::true_type
{
};

template<>
struct is_service_request<greenstory_interfaces::srv::TellStory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<greenstory_interfaces::srv::TellStory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__TRAITS_HPP_
