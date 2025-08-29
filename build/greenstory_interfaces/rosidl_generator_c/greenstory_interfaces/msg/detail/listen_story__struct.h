// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_H_
#define GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'story'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ListenStory in the package greenstory_interfaces.
typedef struct greenstory_interfaces__msg__ListenStory
{
  rosidl_runtime_c__String story;
} greenstory_interfaces__msg__ListenStory;

// Struct for a sequence of greenstory_interfaces__msg__ListenStory.
typedef struct greenstory_interfaces__msg__ListenStory__Sequence
{
  greenstory_interfaces__msg__ListenStory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} greenstory_interfaces__msg__ListenStory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_H_
