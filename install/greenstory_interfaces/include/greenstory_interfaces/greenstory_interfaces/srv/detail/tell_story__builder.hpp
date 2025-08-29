// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from greenstory_interfaces:srv/TellStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__BUILDER_HPP_
#define GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "greenstory_interfaces/srv/detail/tell_story__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace greenstory_interfaces
{

namespace srv
{

namespace builder
{

class Init_TellStory_Request_name
{
public:
  explicit Init_TellStory_Request_name(::greenstory_interfaces::srv::TellStory_Request & msg)
  : msg_(msg)
  {}
  ::greenstory_interfaces::srv::TellStory_Request name(::greenstory_interfaces::srv::TellStory_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::greenstory_interfaces::srv::TellStory_Request msg_;
};

class Init_TellStory_Request_serial_number
{
public:
  Init_TellStory_Request_serial_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TellStory_Request_name serial_number(::greenstory_interfaces::srv::TellStory_Request::_serial_number_type arg)
  {
    msg_.serial_number = std::move(arg);
    return Init_TellStory_Request_name(msg_);
  }

private:
  ::greenstory_interfaces::srv::TellStory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::greenstory_interfaces::srv::TellStory_Request>()
{
  return greenstory_interfaces::srv::builder::Init_TellStory_Request_serial_number();
}

}  // namespace greenstory_interfaces


namespace greenstory_interfaces
{

namespace srv
{

namespace builder
{

class Init_TellStory_Response_story
{
public:
  Init_TellStory_Response_story()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::greenstory_interfaces::srv::TellStory_Response story(::greenstory_interfaces::srv::TellStory_Response::_story_type arg)
  {
    msg_.story = std::move(arg);
    return std::move(msg_);
  }

private:
  ::greenstory_interfaces::srv::TellStory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::greenstory_interfaces::srv::TellStory_Response>()
{
  return greenstory_interfaces::srv::builder::Init_TellStory_Response_story();
}

}  // namespace greenstory_interfaces

#endif  // GREENSTORY_INTERFACES__SRV__DETAIL__TELL_STORY__BUILDER_HPP_
