// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice
#include "greenstory_interfaces/srv/detail/tell_story__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
greenstory_interfaces__srv__TellStory_Request__init(greenstory_interfaces__srv__TellStory_Request * msg)
{
  if (!msg) {
    return false;
  }
  // serial_number
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    greenstory_interfaces__srv__TellStory_Request__fini(msg);
    return false;
  }
  return true;
}

void
greenstory_interfaces__srv__TellStory_Request__fini(greenstory_interfaces__srv__TellStory_Request * msg)
{
  if (!msg) {
    return;
  }
  // serial_number
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
greenstory_interfaces__srv__TellStory_Request__are_equal(const greenstory_interfaces__srv__TellStory_Request * lhs, const greenstory_interfaces__srv__TellStory_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // serial_number
  if (lhs->serial_number != rhs->serial_number) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
greenstory_interfaces__srv__TellStory_Request__copy(
  const greenstory_interfaces__srv__TellStory_Request * input,
  greenstory_interfaces__srv__TellStory_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // serial_number
  output->serial_number = input->serial_number;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

greenstory_interfaces__srv__TellStory_Request *
greenstory_interfaces__srv__TellStory_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Request * msg = (greenstory_interfaces__srv__TellStory_Request *)allocator.allocate(sizeof(greenstory_interfaces__srv__TellStory_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(greenstory_interfaces__srv__TellStory_Request));
  bool success = greenstory_interfaces__srv__TellStory_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
greenstory_interfaces__srv__TellStory_Request__destroy(greenstory_interfaces__srv__TellStory_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    greenstory_interfaces__srv__TellStory_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
greenstory_interfaces__srv__TellStory_Request__Sequence__init(greenstory_interfaces__srv__TellStory_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Request * data = NULL;

  if (size) {
    data = (greenstory_interfaces__srv__TellStory_Request *)allocator.zero_allocate(size, sizeof(greenstory_interfaces__srv__TellStory_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = greenstory_interfaces__srv__TellStory_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        greenstory_interfaces__srv__TellStory_Request__fini(&data[i - 1]);
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
greenstory_interfaces__srv__TellStory_Request__Sequence__fini(greenstory_interfaces__srv__TellStory_Request__Sequence * array)
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
      greenstory_interfaces__srv__TellStory_Request__fini(&array->data[i]);
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

greenstory_interfaces__srv__TellStory_Request__Sequence *
greenstory_interfaces__srv__TellStory_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Request__Sequence * array = (greenstory_interfaces__srv__TellStory_Request__Sequence *)allocator.allocate(sizeof(greenstory_interfaces__srv__TellStory_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = greenstory_interfaces__srv__TellStory_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
greenstory_interfaces__srv__TellStory_Request__Sequence__destroy(greenstory_interfaces__srv__TellStory_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    greenstory_interfaces__srv__TellStory_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
greenstory_interfaces__srv__TellStory_Request__Sequence__are_equal(const greenstory_interfaces__srv__TellStory_Request__Sequence * lhs, const greenstory_interfaces__srv__TellStory_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!greenstory_interfaces__srv__TellStory_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
greenstory_interfaces__srv__TellStory_Request__Sequence__copy(
  const greenstory_interfaces__srv__TellStory_Request__Sequence * input,
  greenstory_interfaces__srv__TellStory_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(greenstory_interfaces__srv__TellStory_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    greenstory_interfaces__srv__TellStory_Request * data =
      (greenstory_interfaces__srv__TellStory_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!greenstory_interfaces__srv__TellStory_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          greenstory_interfaces__srv__TellStory_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!greenstory_interfaces__srv__TellStory_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `story`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
greenstory_interfaces__srv__TellStory_Response__init(greenstory_interfaces__srv__TellStory_Response * msg)
{
  if (!msg) {
    return false;
  }
  // story
  if (!rosidl_runtime_c__String__init(&msg->story)) {
    greenstory_interfaces__srv__TellStory_Response__fini(msg);
    return false;
  }
  return true;
}

void
greenstory_interfaces__srv__TellStory_Response__fini(greenstory_interfaces__srv__TellStory_Response * msg)
{
  if (!msg) {
    return;
  }
  // story
  rosidl_runtime_c__String__fini(&msg->story);
}

bool
greenstory_interfaces__srv__TellStory_Response__are_equal(const greenstory_interfaces__srv__TellStory_Response * lhs, const greenstory_interfaces__srv__TellStory_Response * rhs)
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
greenstory_interfaces__srv__TellStory_Response__copy(
  const greenstory_interfaces__srv__TellStory_Response * input,
  greenstory_interfaces__srv__TellStory_Response * output)
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

greenstory_interfaces__srv__TellStory_Response *
greenstory_interfaces__srv__TellStory_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Response * msg = (greenstory_interfaces__srv__TellStory_Response *)allocator.allocate(sizeof(greenstory_interfaces__srv__TellStory_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(greenstory_interfaces__srv__TellStory_Response));
  bool success = greenstory_interfaces__srv__TellStory_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
greenstory_interfaces__srv__TellStory_Response__destroy(greenstory_interfaces__srv__TellStory_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    greenstory_interfaces__srv__TellStory_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
greenstory_interfaces__srv__TellStory_Response__Sequence__init(greenstory_interfaces__srv__TellStory_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Response * data = NULL;

  if (size) {
    data = (greenstory_interfaces__srv__TellStory_Response *)allocator.zero_allocate(size, sizeof(greenstory_interfaces__srv__TellStory_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = greenstory_interfaces__srv__TellStory_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        greenstory_interfaces__srv__TellStory_Response__fini(&data[i - 1]);
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
greenstory_interfaces__srv__TellStory_Response__Sequence__fini(greenstory_interfaces__srv__TellStory_Response__Sequence * array)
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
      greenstory_interfaces__srv__TellStory_Response__fini(&array->data[i]);
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

greenstory_interfaces__srv__TellStory_Response__Sequence *
greenstory_interfaces__srv__TellStory_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  greenstory_interfaces__srv__TellStory_Response__Sequence * array = (greenstory_interfaces__srv__TellStory_Response__Sequence *)allocator.allocate(sizeof(greenstory_interfaces__srv__TellStory_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = greenstory_interfaces__srv__TellStory_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
greenstory_interfaces__srv__TellStory_Response__Sequence__destroy(greenstory_interfaces__srv__TellStory_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    greenstory_interfaces__srv__TellStory_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
greenstory_interfaces__srv__TellStory_Response__Sequence__are_equal(const greenstory_interfaces__srv__TellStory_Response__Sequence * lhs, const greenstory_interfaces__srv__TellStory_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!greenstory_interfaces__srv__TellStory_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
greenstory_interfaces__srv__TellStory_Response__Sequence__copy(
  const greenstory_interfaces__srv__TellStory_Response__Sequence * input,
  greenstory_interfaces__srv__TellStory_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(greenstory_interfaces__srv__TellStory_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    greenstory_interfaces__srv__TellStory_Response * data =
      (greenstory_interfaces__srv__TellStory_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!greenstory_interfaces__srv__TellStory_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          greenstory_interfaces__srv__TellStory_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!greenstory_interfaces__srv__TellStory_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
