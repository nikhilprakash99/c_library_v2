#pragma once
// MESSAGE PROBE_DATA PACKING

#define MAVLINK_MSG_ID_PROBE_DATA 68

MAVPACKED(
typedef struct __mavlink_probe_data_t {
 uint64_t timestamp; /*<   Timestamp of reading */
 float thickness; /*< [mm] The thickness of the wall*/
 uint32_t contact; /*<  Contact*/
 uint16_t status; /*<   The current status of the sensor*/
}) mavlink_probe_data_t;

#define MAVLINK_MSG_ID_PROBE_DATA_LEN 18
#define MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN 18
#define MAVLINK_MSG_ID_68_LEN 18
#define MAVLINK_MSG_ID_68_MIN_LEN 18

#define MAVLINK_MSG_ID_PROBE_DATA_CRC 174
#define MAVLINK_MSG_ID_68_CRC 174



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PROBE_DATA { \
    68, \
    "PROBE_DATA", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_probe_data_t, timestamp) }, \
         { "status", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_probe_data_t, status) }, \
         { "thickness", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_probe_data_t, thickness) }, \
         { "contact", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_probe_data_t, contact) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PROBE_DATA { \
    "PROBE_DATA", \
    4, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_probe_data_t, timestamp) }, \
         { "status", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_probe_data_t, status) }, \
         { "thickness", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_probe_data_t, thickness) }, \
         { "contact", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_probe_data_t, contact) }, \
         } \
}
#endif

/**
 * @brief Pack a probe_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp   Timestamp of reading 
 * @param status   The current status of the sensor
 * @param thickness [mm] The thickness of the wall
 * @param contact  Contact
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_probe_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint16_t status, float thickness, uint32_t contact)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PROBE_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, thickness);
    _mav_put_uint32_t(buf, 12, contact);
    _mav_put_uint16_t(buf, 16, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PROBE_DATA_LEN);
#else
    mavlink_probe_data_t packet;
    packet.timestamp = timestamp;
    packet.thickness = thickness;
    packet.contact = contact;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PROBE_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PROBE_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
}

/**
 * @brief Pack a probe_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp   Timestamp of reading 
 * @param status   The current status of the sensor
 * @param thickness [mm] The thickness of the wall
 * @param contact  Contact
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_probe_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint16_t status,float thickness,uint32_t contact)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PROBE_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, thickness);
    _mav_put_uint32_t(buf, 12, contact);
    _mav_put_uint16_t(buf, 16, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PROBE_DATA_LEN);
#else
    mavlink_probe_data_t packet;
    packet.timestamp = timestamp;
    packet.thickness = thickness;
    packet.contact = contact;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PROBE_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PROBE_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
}

/**
 * @brief Encode a probe_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param probe_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_probe_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_probe_data_t* probe_data)
{
    return mavlink_msg_probe_data_pack(system_id, component_id, msg, probe_data->timestamp, probe_data->status, probe_data->thickness, probe_data->contact);
}

/**
 * @brief Encode a probe_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param probe_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_probe_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_probe_data_t* probe_data)
{
    return mavlink_msg_probe_data_pack_chan(system_id, component_id, chan, msg, probe_data->timestamp, probe_data->status, probe_data->thickness, probe_data->contact);
}

/**
 * @brief Send a probe_data message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp   Timestamp of reading 
 * @param status   The current status of the sensor
 * @param thickness [mm] The thickness of the wall
 * @param contact  Contact
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_probe_data_send(mavlink_channel_t chan, uint64_t timestamp, uint16_t status, float thickness, uint32_t contact)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PROBE_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, thickness);
    _mav_put_uint32_t(buf, 12, contact);
    _mav_put_uint16_t(buf, 16, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PROBE_DATA, buf, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
#else
    mavlink_probe_data_t packet;
    packet.timestamp = timestamp;
    packet.thickness = thickness;
    packet.contact = contact;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PROBE_DATA, (const char *)&packet, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
#endif
}

/**
 * @brief Send a probe_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_probe_data_send_struct(mavlink_channel_t chan, const mavlink_probe_data_t* probe_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_probe_data_send(chan, probe_data->timestamp, probe_data->status, probe_data->thickness, probe_data->contact);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PROBE_DATA, (const char *)probe_data, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_PROBE_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_probe_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint16_t status, float thickness, uint32_t contact)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, thickness);
    _mav_put_uint32_t(buf, 12, contact);
    _mav_put_uint16_t(buf, 16, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PROBE_DATA, buf, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
#else
    mavlink_probe_data_t *packet = (mavlink_probe_data_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->thickness = thickness;
    packet->contact = contact;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PROBE_DATA, (const char *)packet, MAVLINK_MSG_ID_PROBE_DATA_MIN_LEN, MAVLINK_MSG_ID_PROBE_DATA_LEN, MAVLINK_MSG_ID_PROBE_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE PROBE_DATA UNPACKING


/**
 * @brief Get field timestamp from probe_data message
 *
 * @return   Timestamp of reading 
 */
static inline uint64_t mavlink_msg_probe_data_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from probe_data message
 *
 * @return   The current status of the sensor
 */
static inline uint16_t mavlink_msg_probe_data_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field thickness from probe_data message
 *
 * @return [mm] The thickness of the wall
 */
static inline float mavlink_msg_probe_data_get_thickness(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field contact from probe_data message
 *
 * @return  Contact
 */
static inline uint32_t mavlink_msg_probe_data_get_contact(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a probe_data message into a struct
 *
 * @param msg The message to decode
 * @param probe_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_probe_data_decode(const mavlink_message_t* msg, mavlink_probe_data_t* probe_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    probe_data->timestamp = mavlink_msg_probe_data_get_timestamp(msg);
    probe_data->thickness = mavlink_msg_probe_data_get_thickness(msg);
    probe_data->contact = mavlink_msg_probe_data_get_contact(msg);
    probe_data->status = mavlink_msg_probe_data_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PROBE_DATA_LEN? msg->len : MAVLINK_MSG_ID_PROBE_DATA_LEN;
        memset(probe_data, 0, MAVLINK_MSG_ID_PROBE_DATA_LEN);
    memcpy(probe_data, _MAV_PAYLOAD(msg), len);
#endif
}
