// Generated by gencpp from file pubsub/Person.msg
// DO NOT EDIT!


#ifndef PUBSUB_MESSAGE_PERSON_H
#define PUBSUB_MESSAGE_PERSON_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pubsub
{
template <class ContainerAllocator>
struct Person_
{
  typedef Person_<ContainerAllocator> Type;

  Person_()
    : name()
    , age(0)
    , height(0.0)  {
    }
  Person_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , age(0)
    , height(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef int64_t _age_type;
  _age_type age;

   typedef double _height_type;
  _height_type height;





  typedef boost::shared_ptr< ::pubsub::Person_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pubsub::Person_<ContainerAllocator> const> ConstPtr;

}; // struct Person_

typedef ::pubsub::Person_<std::allocator<void> > Person;

typedef boost::shared_ptr< ::pubsub::Person > PersonPtr;
typedef boost::shared_ptr< ::pubsub::Person const> PersonConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pubsub::Person_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pubsub::Person_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pubsub::Person_<ContainerAllocator1> & lhs, const ::pubsub::Person_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.age == rhs.age &&
    lhs.height == rhs.height;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pubsub::Person_<ContainerAllocator1> & lhs, const ::pubsub::Person_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pubsub

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::pubsub::Person_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pubsub::Person_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pubsub::Person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pubsub::Person_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pubsub::Person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pubsub::Person_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pubsub::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "20458e4846ce455a621bd267dd1d7b9d";
  }

  static const char* value(const ::pubsub::Person_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x20458e4846ce455aULL;
  static const uint64_t static_value2 = 0x621bd267dd1d7b9dULL;
};

template<class ContainerAllocator>
struct DataType< ::pubsub::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pubsub/Person";
  }

  static const char* value(const ::pubsub::Person_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pubsub::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n"
"int64 age\n"
"float64 height\n"
;
  }

  static const char* value(const ::pubsub::Person_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pubsub::Person_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.age);
      stream.next(m.height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Person_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pubsub::Person_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pubsub::Person_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "age: ";
    Printer<int64_t>::stream(s, indent + "  ", v.age);
    s << indent << "height: ";
    Printer<double>::stream(s, indent + "  ", v.height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PUBSUB_MESSAGE_PERSON_H
