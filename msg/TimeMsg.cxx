// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file TimeMsg.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "TimeMsg.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

TimeMsg::TimeMsg()
{
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@553a3d88
    m_message ="";
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7a30d1e6
    m_index = 0;
    // m_hour com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5891e32e
    m_hour = 0;
    // m_minute com.eprosima.idl.parser.typecode.PrimitiveTypeCode@cb0ed20
    m_minute = 0;
    // m_second com.eprosima.idl.parser.typecode.PrimitiveTypeCode@8e24743
    m_second = 0;

}

TimeMsg::~TimeMsg()
{





}

TimeMsg::TimeMsg(
        const TimeMsg& x)
{
    m_message = x.m_message;
    m_index = x.m_index;
    m_hour = x.m_hour;
    m_minute = x.m_minute;
    m_second = x.m_second;
}

TimeMsg::TimeMsg(
        TimeMsg&& x)
{
    m_message = std::move(x.m_message);
    m_index = x.m_index;
    m_hour = x.m_hour;
    m_minute = x.m_minute;
    m_second = x.m_second;
}

TimeMsg& TimeMsg::operator =(
        const TimeMsg& x)
{

    m_message = x.m_message;
    m_index = x.m_index;
    m_hour = x.m_hour;
    m_minute = x.m_minute;
    m_second = x.m_second;

    return *this;
}

TimeMsg& TimeMsg::operator =(
        TimeMsg&& x)
{

    m_message = std::move(x.m_message);
    m_index = x.m_index;
    m_hour = x.m_hour;
    m_minute = x.m_minute;
    m_second = x.m_second;

    return *this;
}

size_t TimeMsg::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t TimeMsg::getCdrSerializedSize(
        const TimeMsg& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.message().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void TimeMsg::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_message;
    scdr << m_index;
    scdr << m_hour;
    scdr << m_minute;
    scdr << m_second;

}

void TimeMsg::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_message;
    dcdr >> m_index;
    dcdr >> m_hour;
    dcdr >> m_minute;
    dcdr >> m_second;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void TimeMsg::message(
        const std::string& _message)
{
    m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void TimeMsg::message(
        std::string&& _message)
{
    m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::string& TimeMsg::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::string& TimeMsg::message()
{
    return m_message;
}
/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void TimeMsg::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t TimeMsg::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& TimeMsg::index()
{
    return m_index;
}

/*!
 * @brief This function sets a value in member hour
 * @param _hour New value for member hour
 */
void TimeMsg::hour(
        uint32_t _hour)
{
    m_hour = _hour;
}

/*!
 * @brief This function returns the value of member hour
 * @return Value of member hour
 */
uint32_t TimeMsg::hour() const
{
    return m_hour;
}

/*!
 * @brief This function returns a reference to member hour
 * @return Reference to member hour
 */
uint32_t& TimeMsg::hour()
{
    return m_hour;
}

/*!
 * @brief This function sets a value in member minute
 * @param _minute New value for member minute
 */
void TimeMsg::minute(
        uint32_t _minute)
{
    m_minute = _minute;
}

/*!
 * @brief This function returns the value of member minute
 * @return Value of member minute
 */
uint32_t TimeMsg::minute() const
{
    return m_minute;
}

/*!
 * @brief This function returns a reference to member minute
 * @return Reference to member minute
 */
uint32_t& TimeMsg::minute()
{
    return m_minute;
}

/*!
 * @brief This function sets a value in member second
 * @param _second New value for member second
 */
void TimeMsg::second(
        uint32_t _second)
{
    m_second = _second;
}

/*!
 * @brief This function returns the value of member second
 * @return Value of member second
 */
uint32_t TimeMsg::second() const
{
    return m_second;
}

/*!
 * @brief This function returns a reference to member second
 * @return Reference to member second
 */
uint32_t& TimeMsg::second()
{
    return m_second;
}


size_t TimeMsg::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;








    return current_align;
}

bool TimeMsg::isKeyDefined()
{
    return false;
}

void TimeMsg::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
         
}
