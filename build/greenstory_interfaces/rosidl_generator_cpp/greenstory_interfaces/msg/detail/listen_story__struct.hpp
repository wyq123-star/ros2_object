// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_HPP_
#define GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__greenstory_interfaces__msg__ListenStory __attribute__((deprecated))
#else
# define DEPRECATED__greenstory_interfaces__msg__ListenStory __declspec(deprecated)
#endif

namespace greenstory_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ListenStory_
{
  using Type = ListenStory_<ContainerAllocator>;

  explicit ListenStory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->story = "";
    }
  }

  explicit ListenStory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : story(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->story = "";
    }
  }

  // field types and members
  using _story_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _story_type story;

  // setters for named parameter idiom
  Type & set__story(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->story = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    greenstory_interfaces::msg::ListenStory_<ContainerAllocator> *;
  using ConstRawPtr =
    const greenstory_interfaces::msg::ListenStory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::msg::ListenStory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::msg::ListenStory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__greenstory_interfaces__msg__ListenStory
    std::shared_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__greenstory_interfaces__msg__ListenStory
    std::shared_ptr<greenstory_interfaces::msg::ListenStory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ListenStory_ & other) const
  {
    if (this->story != other.story) {
      return false;
    }
    return true;
  }
  bool operator!=(const ListenStory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ListenStory_

// alias to use template instance with default allocator
using ListenStory =
  greenstory_interfaces::msg::ListenStory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace greenstory_interfaces

#endif  // GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__STRUCT_HPP_
