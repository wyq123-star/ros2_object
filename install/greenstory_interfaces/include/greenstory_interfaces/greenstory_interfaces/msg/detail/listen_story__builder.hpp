// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from greenstory_interfaces:msg/ListenStory.idl
// generated code does not contain a copyright notice

#ifndef GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__BUILDER_HPP_
#define GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "greenstory_interfaces/msg/detail/listen_story__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace greenstory_interfaces
{

namespace msg
{

namespace builder
{

class Init_ListenStory_story
{
public:
  Init_ListenStory_story()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::greenstory_interfaces::msg::ListenStory story(::greenstory_interfaces::msg::ListenStory::_story_type arg)
  {
    msg_.story = std::move(arg);
    return std::move(msg_);
  }

private:
  ::greenstory_interfaces::msg::ListenStory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::greenstory_interfaces::msg::ListenStory>()
{
  return greenstory_interfaces::msg::builder::Init_ListenStory_story();
}

}  // namespace greenstory_interfaces

#endif  // GREENSTORY_INTERFACES__MSG__DETAIL__LISTEN_STORY__BUILDER_HPP_
