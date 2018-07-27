/* Generated by D:\Study\openDDS\OpenDDS-DDS\bin\opendds_idl version 3.12.2 (ACE version 6.5.0) running on input file DataA.idl */
#include "DataATypeSupportImpl.h"

#include <cstring>
#include <stdexcept>
#include "dds/DCPS/BuiltInTopicUtils.h"
#include "dds/DCPS/ContentFilteredTopicImpl.h"
#include "dds/DCPS/DataReaderImpl_T.h"
#include "dds/DCPS/DataWriterImpl_T.h"
#include "dds/DCPS/FilterEvaluator.h"
#include "dds/DCPS/MultiTopicDataReader_T.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/PublicationInstance.h"
#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/RakeData.h"
#include "dds/DCPS/RakeResults_T.h"
#include "dds/DCPS/ReceivedDataElementList.h"
#include "dds/DCPS/Registered_Data_Types.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/SubscriberImpl.h"
#include "dds/DCPS/Util.h"
#include "dds/DCPS/debug.h"
#include "dds/DdsDcpsDomainC.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: TestA */



/* Begin STRUCT: DataA */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const TestA::DataA& stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.pos);
  find_size_ulong(size, padding);
  size += ACE_OS::strlen(stru.name.in()) + 1;
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.length);
}

bool operator<<(Serializer& strm, const TestA::DataA& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm << stru.pos)
    && (strm << stru.name.in())
    && (strm << stru.length);
}

bool operator>>(Serializer& strm, TestA::DataA& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm >> stru.pos)
    && (strm >> stru.name.out())
    && (strm >> stru.length);
}

size_t gen_max_marshaled_size(const TestA::DataA& stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 0;
}

size_t gen_max_marshaled_size(KeyOnly<const TestA::DataA> stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 4;
}

void gen_find_size(KeyOnly<const TestA::DataA> stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.t.pos);
}

bool operator<<(Serializer& strm, KeyOnly<const TestA::DataA> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm << stru.t.pos);
}

bool operator>>(Serializer& strm, KeyOnly<TestA::DataA> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm >> stru.t.pos);
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace TestA {
::DDS::DataWriter_ptr DataATypeSupportImpl::create_datawriter()
{
  typedef OpenDDS::DCPS::DataWriterImpl_T<DataA> DataWriterImplType;
  ::DDS::DataWriter_ptr writer_impl = ::DDS::DataWriter::_nil();
  ACE_NEW_NORETURN(writer_impl,
                   DataWriterImplType());
  return writer_impl;
}
::DDS::DataReader_ptr DataATypeSupportImpl::create_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<DataA> DataReaderImplType;
  ::DDS::DataReader_ptr reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(reader_impl,
                   DataReaderImplType());
  return reader_impl;
}
#ifndef OPENDDS_NO_MULTI_TOPIC
::DDS::DataReader_ptr DataATypeSupportImpl::create_multitopic_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<DataA> DataReaderImplType;
  typedef OpenDDS::DCPS::MultiTopicDataReader_T<DataA, DataReaderImplType> MultiTopicDataReaderImplType;
  ::DDS::DataReader_ptr multitopic_reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(multitopic_reader_impl,
                   MultiTopicDataReaderImplType());
  return multitopic_reader_impl;
}
#endif /* !OPENDDS_NO_MULTI_TOPIC */
#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
const OpenDDS::DCPS::MetaStruct& DataATypeSupportImpl::getMetaStructForType()
{
  return OpenDDS::DCPS::getMetaStruct<DataA>();
}
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */
bool DataATypeSupportImpl::has_dcps_key()
{
  return TraitsType::gen_has_key ();
}
const char* DataATypeSupportImpl::default_type_name() const
{
  return TraitsType::type_name();
}
DataATypeSupport::_ptr_type DataATypeSupportImpl::_narrow(CORBA::Object_ptr obj)
{
  return TypeSupportType::_narrow(obj);
}
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
struct MetaStructImpl<TestA::DataA> : MetaStruct {
  typedef TestA::DataA T;

#ifndef OPENDDS_NO_MULTI_TOPIC
  void* allocate() const { return new T; }

  void deallocate(void* stru) const { delete static_cast<T*>(stru); }
  size_t numDcpsKeys() const { return 1; }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  Value getValue(const void* stru, const char* field) const
  {
    const TestA::DataA& typed = *static_cast<const TestA::DataA*>(stru);
    if (std::strcmp(field, "pos") == 0) {
      return typed.pos;
    }
    if (std::strcmp(field, "name") == 0) {
      return typed.name.in();
    }
    if (std::strcmp(field, "length") == 0) {
      return typed.length;
    }
    ACE_UNUSED_ARG(typed);
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct TestA::DataA)");
  }

  Value getValue(Serializer& ser, const char* field) const
  {
    if (std::strcmp(field, "pos") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'pos' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'pos' could not be skipped");
      }
    }
    if (std::strcmp(field, "name") == 0) {
      TAO::String_Manager val;
      if (!(ser >> val.out())) {
        throw std::runtime_error("Field 'name' could not be deserialized");
      }
      return val;
    } else {
      ACE_CDR::ULong len;
      if (!(ser >> len)) {
        throw std::runtime_error("String 'name' length could not be deserialized");
      }
      if (!ser.skip(len)) {
        throw std::runtime_error("String 'name' contents could not be skipped");
      }
    }
    if (std::strcmp(field, "length") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'length' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'length' could not be skipped");
      }
    }
    if (!field[0]) {
      return 0;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not valid for struct TestA::DataA");
  }

  ComparatorBase::Ptr create_qc_comparator(const char* field, ComparatorBase::Ptr next) const
  {
    ACE_UNUSED_ARG(next);
    if (std::strcmp(field, "pos") == 0) {
      return make_field_cmp(&T::pos, next);
    }
    if (std::strcmp(field, "name") == 0) {
      return make_field_cmp(&T::name, next);
    }
    if (std::strcmp(field, "length") == 0) {
      return make_field_cmp(&T::length, next);
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct TestA::DataA)");
  }

#ifndef OPENDDS_NO_MULTI_TOPIC
  const char** getFieldNames() const
  {
    static const char* names[] = {"pos", "name", "length", 0};
    return names;
  }

  const void* getRawField(const void* stru, const char* field) const
  {
    if (std::strcmp(field, "pos") == 0) {
      return &static_cast<const T*>(stru)->pos;
    }
    if (std::strcmp(field, "name") == 0) {
      return &static_cast<const T*>(stru)->name;
    }
    if (std::strcmp(field, "length") == 0) {
      return &static_cast<const T*>(stru)->length;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct TestA::DataA)");
  }

  void assign(void* lhs, const char* field, const void* rhs,
    const char* rhsFieldSpec, const MetaStruct& rhsMeta) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    ACE_UNUSED_ARG(rhsFieldSpec);
    ACE_UNUSED_ARG(rhsMeta);
    if (std::strcmp(field, "pos") == 0) {
      static_cast<T*>(lhs)->pos = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "name") == 0) {
      static_cast<T*>(lhs)->name = *static_cast<const TAO::String_Manager*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "length") == 0) {
      static_cast<T*>(lhs)->length = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct TestA::DataA)");
  }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool compare(const void* lhs, const void* rhs, const char* field) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    if (std::strcmp(field, "pos") == 0) {
      return static_cast<const T*>(lhs)->pos == static_cast<const T*>(rhs)->pos;
    }
    if (std::strcmp(field, "name") == 0) {
      return 0 == ACE_OS::strcmp(static_cast<const T*>(lhs)->name.in(), static_cast<const T*>(rhs)->name.in());
    }
    if (std::strcmp(field, "length") == 0) {
      return static_cast<const T*>(lhs)->length == static_cast<const T*>(rhs)->length;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct TestA::DataA)");
  }
};

template<>
const MetaStruct& getMetaStruct<TestA::DataA>()
{
  static MetaStructImpl<TestA::DataA> msi;
  return msi;
}

bool gen_skip_over(Serializer& ser, TestA::DataA*)
{
  ACE_UNUSED_ARG(ser);
  MetaStructImpl<TestA::DataA>().getValue(ser, "");
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: DataA */

/* End MODULE: TestA */
