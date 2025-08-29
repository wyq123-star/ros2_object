// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "greenstory_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "greenstory_interfaces/msg/detail/listen_story__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace greenstory_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
cdr_serialize(
  const greenstory_interfaces::msg::ListenStory & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  greenstory_interfaces::msg::ListenStory & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
get_serialized_size(
  const greenstory_interfaces::msg::ListenStory & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
max_serialized_size_ListenStory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace greenstory_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, greenstory_interfaces, msg, ListenStory)();

#ifdef __cplusplus
}
#endif

#endif  // GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
