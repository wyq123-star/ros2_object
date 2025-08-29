// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__TRAITS_HPP_
#define GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "greenstory_interfaces/msg/detail/listen_story__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace greenstory_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ListenStory & msg,
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
  const ListenStory & msg,
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

inline std::string to_yaml(const ListenStory & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace greenstory_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use greenstory_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const greenstory_interfaces::msg::ListenStory & msg,
  std::ostream & out, size_t indentation = 0)
{
  greenstory_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use greenstory_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const greenstory_interfaces::msg::ListenStory & msg)
{
  return greenstory_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<greenstory_interfaces::msg::ListenStory>()
{
  return "greenstory_interfaces::msg::ListenStory";
}

template<>
inline const char * name<greenstory_interfaces::msg::ListenStory>()
{
  return "greenstory_interfaces/msg/ListenStory";
}

template<>
struct has_fixed_size<greenstory_interfaces::msg::ListenStory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<greenstory_interfaces::msg::ListenStory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<greenstory_interfaces::msg::ListenStory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__TRAITS_HPP_
