// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice
#include "greenstory_interfaces/msg/detail/listen_story__rosidl_typesupport_fastrtps_cpp.hpp"
#include "greenstory_interfaces/msg/detail/listen_story__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: story
  cdr << ros_message.story;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  greenstory_interfaces::msg::ListenStory & ros_message)
{
  // Member: story
  cdr >> ros_message.story;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
get_serialized_size(
  const greenstory_interfaces::msg::ListenStory & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: story
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.story.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_greenstory_interfaces
max_serialized_size_ListenStory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: story
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = greenstory_interfaces::msg::ListenStory;
    is_plain =
      (
      offsetof(DataType, story) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ListenStory__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const greenstory_interfaces::msg::ListenStory *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ListenStory__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<greenstory_interfaces::msg::ListenStory *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ListenStory__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const greenstory_interfaces::msg::ListenStory *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ListenStory__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ListenStory(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ListenStory__callbacks = {
  "greenstory_interfaces::msg",
  "ListenStory",
  _ListenStory__cdr_serialize,
  _ListenStory__cdr_deserialize,
  _ListenStory__get_serialized_size,
  _ListenStory__max_serialized_size
};

static rosidl_message_type_support_t _ListenStory__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ListenStory__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace greenstory_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_greenstory_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<greenstory_interfaces::msg::ListenStory>()
{
  return &greenstory_interfaces::msg::typesupport_fastrtps_cpp::_ListenStory__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, greenstory_interfaces, msg, ListenStory)() {
  return &greenstory_interfaces::msg::typesupport_fastrtps_cpp::_ListenStory__handle;
}

#ifdef __cplusplus
}
#endif
