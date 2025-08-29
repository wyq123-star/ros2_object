// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice
#include "greenstory_interfaces/srv/detail/tell_story__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "greenstory_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "greenstory_interfaces/srv/detail/tell_story__struct.h"
#include "greenstory_interfaces/srv/detail/tell_story__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// forward declare type support functions


using _TellStory_Request__ros_msg_type = greenstory_interfaces__srv__TellStory_Request;

static bool _TellStory_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TellStory_Request__ros_msg_type * ros_message = static_cast<const _TellStory_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: serial_number
  {
    cdr << ros_message->serial_number;
  }

  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TellStory_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TellStory_Request__ros_msg_type * ros_message = static_cast<_TellStory_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: serial_number
  {
    cdr >> ros_message->serial_number;
  }

  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_greenstory_interfaces
size_t get_serialized_size_greenstory_interfaces__srv__TellStory_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TellStory_Request__ros_msg_type * ros_message = static_cast<const _TellStory_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name serial_number
  {
    size_t item_size = sizeof(ros_message->serial_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TellStory_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_greenstory_interfaces__srv__TellStory_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_greenstory_interfaces
size_t max_serialized_size_greenstory_interfaces__srv__TellStory_Request(
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

  // member: serial_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: name
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
    using DataType = greenstory_interfaces__srv__TellStory_Request;
    is_plain =
      (
      offsetof(DataType, name) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TellStory_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_greenstory_interfaces__srv__TellStory_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TellStory_Request = {
  "greenstory_interfaces::srv",
  "TellStory_Request",
  _TellStory_Request__cdr_serialize,
  _TellStory_Request__cdr_deserialize,
  _TellStory_Request__get_serialized_size,
  _TellStory_Request__max_serialized_size
};

static rosidl_message_type_support_t _TellStory_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TellStory_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, greenstory_interfaces, srv, TellStory_Request)() {
  return &_TellStory_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "greenstory_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "greenstory_interfaces/srv/detail/tell_story__struct.h"
// already included above
// #include "greenstory_interfaces/srv/detail/tell_story__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // story
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // story

// forward declare type support functions


using _TellStory_Response__ros_msg_type = greenstory_interfaces__srv__TellStory_Response;

static bool _TellStory_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TellStory_Response__ros_msg_type * ros_message = static_cast<const _TellStory_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: story
  {
    const rosidl_runtime_c__String * str = &ros_message->story;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TellStory_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TellStory_Response__ros_msg_type * ros_message = static_cast<_TellStory_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: story
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->story.data) {
      rosidl_runtime_c__String__init(&ros_message->story);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->story,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'story'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_greenstory_interfaces
size_t get_serialized_size_greenstory_interfaces__srv__TellStory_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TellStory_Response__ros_msg_type * ros_message = static_cast<const _TellStory_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name story
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->story.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TellStory_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_greenstory_interfaces__srv__TellStory_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_greenstory_interfaces
size_t max_serialized_size_greenstory_interfaces__srv__TellStory_Response(
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

  // member: story
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
    using DataType = greenstory_interfaces__srv__TellStory_Response;
    is_plain =
      (
      offsetof(DataType, story) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TellStory_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_greenstory_interfaces__srv__TellStory_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TellStory_Response = {
  "greenstory_interfaces::srv",
  "TellStory_Response",
  _TellStory_Response__cdr_serialize,
  _TellStory_Response__cdr_deserialize,
  _TellStory_Response__get_serialized_size,
  _TellStory_Response__max_serialized_size
};

static rosidl_message_type_support_t _TellStory_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TellStory_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, greenstory_interfaces, srv, TellStory_Response)() {
  return &_TellStory_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "greenstory_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "greenstory_interfaces/srv/tell_story.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t TellStory__callbacks = {
  "greenstory_interfaces::srv",
  "TellStory",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, greenstory_interfaces, srv, TellStory_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, greenstory_interfaces, srv, TellStory_Response)(),
};

static rosidl_service_type_support_t TellStory__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &TellStory__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, greenstory_interfaces, srv, TellStory)() {
  return &TellStory__handle;
}

#if defined(__cplusplus)
}
#endif
