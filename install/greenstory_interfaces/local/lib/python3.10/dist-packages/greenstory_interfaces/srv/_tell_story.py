# generated from rosidl_generator_py/resource/_idl.py.em
# with input from greenstory_interfaces:srv/TellStory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TellStory_Request(type):
    """Metaclass of message 'TellStory_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('greenstory_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'greenstory_interfaces.srv.TellStory_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__tell_story__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__tell_story__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__tell_story__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__tell_story__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__tell_story__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TellStory_Request(metaclass=Metaclass_TellStory_Request):
    """Message class 'TellStory_Request'."""

    __slots__ = [
        '_serial_number',
        '_name',
    ]

    _fields_and_field_types = {
        'serial_number': 'int64',
        'name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.serial_number = kwargs.get('serial_number', int())
        self.name = kwargs.get('name', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.serial_number != other.serial_number:
            return False
        if self.name != other.name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def serial_number(self):
        """Message field 'serial_number'."""
        return self._serial_number

    @serial_number.setter
    def serial_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'serial_number' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'serial_number' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._serial_number = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TellStory_Response(type):
    """Metaclass of message 'TellStory_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('greenstory_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'greenstory_interfaces.srv.TellStory_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__tell_story__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__tell_story__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__tell_story__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__tell_story__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__tell_story__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TellStory_Response(metaclass=Metaclass_TellStory_Response):
    """Message class 'TellStory_Response'."""

    __slots__ = [
        '_story',
    ]

    _fields_and_field_types = {
        'story': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.story = kwargs.get('story', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.story != other.story:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def story(self):
        """Message field 'story'."""
        return self._story

    @story.setter
    def story(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'story' field must be of type 'str'"
        self._story = value


class Metaclass_TellStory(type):
    """Metaclass of service 'TellStory'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('greenstory_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'greenstory_interfaces.srv.TellStory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__tell_story

            from greenstory_interfaces.srv import _tell_story
            if _tell_story.Metaclass_TellStory_Request._TYPE_SUPPORT is None:
                _tell_story.Metaclass_TellStory_Request.__import_type_support__()
            if _tell_story.Metaclass_TellStory_Response._TYPE_SUPPORT is None:
                _tell_story.Metaclass_TellStory_Response.__import_type_support__()


class TellStory(metaclass=Metaclass_TellStory):
    from greenstory_interfaces.srv._tell_story import TellStory_Request as Request
    from greenstory_interfaces.srv._tell_story import TellStory_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
