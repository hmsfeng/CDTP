//
// Created by Lao·Zhu on 2021/9/4.
//

#ifndef _IOCTRL_H_
#define _IOCTRL_H_

void sdtp_callback_handler(unsigned char *data);
void common_sendbyte(unsigned char data);
void common_receivebyte(unsigned char data);

#endif  // _IOCTRL_H_
