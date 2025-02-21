//
// Created by Lao·Zhu on 2021/9/4.
//

#include "encrypt.h"
#include "ioctrl.h"

/*!
    \brief        small capacity data transmission protocol packing function
    \param[in]    data: received data array of size 3 bytes
    \param[out]   none
    \retval       none
*/
void sdtp_data_transmit(const unsigned char *data) {
    unsigned char transmit_buffer[4], transmit_counter;
    /* add packet header after splitting data bytes */
    transmit_buffer[0] = (data[0] >> 2);
    transmit_buffer[1] = (0x01 << 6) | ((data[0] & 0x03) << 4) | (data[1] >> 4);
    transmit_buffer[2] = (0x01 << 7) | ((data[1] & 0x0f) << 2) | (data[2] >> 6);
    transmit_buffer[3] = (0x03 << 6) | (data[2] & 0x3f);
    /* traverse the buffer array and send all bytes through general sendbyte function */
    for (transmit_counter = 0; transmit_counter < 4; transmit_counter++)
        /* transmit single byte through general sendbyte function */
        common_sendbyte(transmit_buffer[transmit_counter]);
}
