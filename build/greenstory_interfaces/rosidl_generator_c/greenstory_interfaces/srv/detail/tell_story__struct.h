// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_H_
#define GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TellStory in the package greenstory_interfaces.
typedef struct greenstory_interfaces__srv__TellStory_Request
{
  int64_t serial_number;
  rosidl_runtime_c__String name;
} greenstory_interfaces__srv__TellStory_Request;

// Struct for a sequence of greenstory_interfaces__srv__TellStory_Request.
typedef struct greenstory_interfaces__srv__TellStory_Request__Sequence
{
  greenstory_interfaces__srv__TellStory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} greenstory_interfaces__srv__TellStory_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'story'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TellStory in the package greenstory_interfaces.
typedef struct greenstory_interfaces__srv__TellStory_Response
{
  rosidl_runtime_c__String story;
} greenstory_interfaces__srv__TellStory_Response;

// Struct for a sequence of greenstory_interfaces__srv__TellStory_Response.
typedef struct greenstory_interfaces__srv__TellStory_Response__Sequence
{
  greenstory_interfaces__srv__TellStory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} greenstory_interfaces__srv__TellStory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_H_
