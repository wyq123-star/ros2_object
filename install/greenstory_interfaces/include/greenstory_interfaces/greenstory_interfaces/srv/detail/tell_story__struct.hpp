// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_HPP_
#define GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__greenstory_interfaces__srv__TellStory_Request __attribute__((deprecated))
#else
# define DEPRECATED__greenstory_interfaces__srv__TellStory_Request __declspec(deprecated)
#endif

namespace greenstory_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TellStory_Request_
{
  using Type = TellStory_Request_<ContainerAllocator>;

  explicit TellStory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->serial_number = 0ll;
      this->name = "";
    }
  }

  explicit TellStory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->serial_number = 0ll;
      this->name = "";
    }
  }

  // field types and members
  using _serial_number_type =
    int64_t;
  _serial_number_type serial_number;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__serial_number(
    const int64_t & _arg)
  {
    this->serial_number = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__greenstory_interfaces__srv__TellStory_Request
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__greenstory_interfaces__srv__TellStory_Request
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TellStory_Request_ & other) const
  {
    if (this->serial_number != other.serial_number) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const TellStory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TellStory_Request_

// alias to use template instance with default allocator
using TellStory_Request =
  greenstory_interfaces::srv::TellStory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace greenstory_interfaces


#ifndef _WIN32
# define DEPRECATED__greenstory_interfaces__srv__TellStory_Response __attribute__((deprecated))
#else
# define DEPRECATED__greenstory_interfaces__srv__TellStory_Response __declspec(deprecated)
#endif

namespace greenstory_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TellStory_Response_
{
  using Type = TellStory_Response_<ContainerAllocator>;

  explicit TellStory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->story = "";
    }
  }

  explicit TellStory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__greenstory_interfaces__srv__TellStory_Response
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__greenstory_interfaces__srv__TellStory_Response
    std::shared_ptr<greenstory_interfaces::srv::TellStory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TellStory_Response_ & other) const
  {
    if (this->story != other.story) {
      return false;
    }
    return true;
  }
  bool operator!=(const TellStory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TellStory_Response_

// alias to use template instance with default allocator
using TellStory_Response =
  greenstory_interfaces::srv::TellStory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace greenstory_interfaces

namespace greenstory_interfaces
{

namespace srv
{

struct TellStory
{
  using Request = greenstory_interfaces::srv::TellStory_Request;
  using Response = greenstory_interfaces::srv::TellStory_Response;
};

}  // namespace srv

}  // namespace greenstory_interfaces

#endif  // GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__STRUCT_HPP_
