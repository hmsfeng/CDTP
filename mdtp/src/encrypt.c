/*****************************************************************************
    \file     encrypt.c
    \brief    Medium capacity transport protocol packing function source file.
    \author   Lao·Zhu
    \version  V1.0.3
    \date     3. December 2021
******************************************************************************/

#include "encrypt.h"
#include "ioctrl.h"

/*!
    \brief      medium capacity data transmission protocol packing function
    \param[in]    pid: medium capacity transport protocol package id
    \param[in]    buffer: transmit data array of size 8 bytes
    \retval none
*/
void mdtp_data_transmit(unsigned char pid, const unsigned char *buffer) {
    unsigned char temp_buf[12] = {0xA5, 0x00, 0x00, 0x00, 0x00, 0x00,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0xA5};
    unsigned char mdtp_pack_counter;

    /* traverse the array to determine whether there are bytes to be adjusted */
    for (mdtp_pack_counter = 0; mdtp_pack_counter < 8; mdtp_pack_counter++) {
        if (buffer[mdtp_pack_counter] == 0xA5) {
            temp_buf[2 + mdtp_pack_counter] = 0x00;
            temp_buf[10] = (temp_buf[10] | (1 << mdtp_pack_counter));
        } else
            temp_buf[2 + mdtp_pack_counter] = buffer[mdtp_pack_counter];
    }

    /* judge whether the adjust frame is 0xA5 */
    if (temp_buf[10] == 0xA5)
        temp_buf[10] = temp_buf[2] = 0x81;

    /* load self checking packet id byte */
    temp_buf[1] = pid << 4 | ((~pid) & 0x0f);

    /* traverse the buffer array and send all bytes through UART0 */
    for (mdtp_pack_counter = 0; mdtp_pack_counter < 12; mdtp_pack_counter++)
        common_sendbyte(temp_buf[mdtp_pack_counter]);
}
