// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice
#include "greenstory_interfaces/msg/detail/listen_story__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `story`
#include "rosidl_runtime_c/string_functions.h"

bool
greenstory_interfaces__msg__ListenStory__init(greenstory_interfaces__msg__ListenStory * msg)
{
  if (!msg) {
    return false;
  }
  // story
  if (!rosidl_runtime_c__String__init(&msg->story)) {
    greenstory_interfaces__msg__ListenStory__fini(msg);
    return false;
  }
  return true;
}

void
greenstory_interfaces__msg__ListenStory__fini(greenstory_interfaces__msg__ListenStory * msg)
{
  if (!msg) {
    return;
  }
  // story
  rosidl_runtime_c__String__fini(&msg->story);
}

bool
greenstory_interfaces__msg__ListenStory__are_equal(const greenstory_interfaces__msg__ListenStory * lhs, const greenstory_interfaces__msg__ListenStory * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // story
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->story), &(rhs->story)))
  {
    return false;
  }
  return true;
}

bool
greenstory_interfaces__msg__ListenStory__copy(
  const greenstory_interfaces__msg__ListenStory * input,
  greenstory_interfaces__msg__ListenStory * output)
{
  if (!input || !output) {
    return false;
  }
  // story
  if (!rosidl_runtime_c__String__copy(
      &(input->story), &(output->story)))
  {
    return false;
  }
  return true;
}

greenstory_interfaces__msg__ListenStory *
greenstory_interfaces__msg__ListenStory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__msg__ListenStory * msg = (greenstory_interfaces__msg__ListenStory *)allocator.allocate(sizeof(greenstory_interfaces__msg__ListenStory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(greenstory_interfaces__msg__ListenStory));
  bool success = greenstory_interfaces__msg__ListenStory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
greenstory_interfaces__msg__ListenStory__destroy(greenstory_interfaces__msg__ListenStory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    greenstory_interfaces__msg__ListenStory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
greenstory_interfaces__msg__ListenStory__Sequence__init(greenstory_interfaces__msg__ListenStory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__msg__ListenStory * data = NULL;

  if (size) {
    data = (greenstory_interfaces__msg__ListenStory *)allocator.zero_allocate(size, sizeof(greenstory_interfaces__msg__ListenStory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = greenstory_interfaces__msg__ListenStory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        greenstory_interfaces__msg__ListenStory__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
greenstory_interfaces__msg__ListenStory__Sequence__fini(greenstory_interfaces__msg__ListenStory__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      greenstory_interfaces__msg__ListenStory__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

greenstory_interfaces__msg__ListenStory__Sequence *
greenstory_interfaces__msg__ListenStory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__msg__ListenStory__Sequence * array = (greenstory_interfaces__msg__ListenStory__Sequence *)allocator.allocate(sizeof(greenstory_interfaces__msg__ListenStory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = greenstory_interfaces__msg__ListenStory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
greenstory_interfaces__msg__ListenStory__Sequence__destroy(greenstory_interfaces__msg__ListenStory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    greenstory_interfaces__msg__ListenStory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
greenstory_interfaces__msg__ListenStory__Sequence__are_equal(const greenstory_interfaces__msg__ListenStory__Sequence * lhs, const greenstory_interfaces__msg__ListenStory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!greenstory_interfaces__msg__ListenStory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
greenstory_interfaces__msg__ListenStory__Sequence__copy(
  const greenstory_interfaces__msg__ListenStory__Sequence * input,
  greenstory_interfaces__msg__ListenStory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(greenstory_interfaces__msg__ListenStory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    greenstory_interfaces__msg__ListenStory * data =
      (greenstory_interfaces__msg__ListenStory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!greenstory_interfaces__msg__ListenStory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          greenstory_interfaces__msg__ListenStory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!greenstory_interfaces__msg__ListenStory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
