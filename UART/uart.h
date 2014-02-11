/***************************************************************************************************************
    This file is part of Library for PIC.

    Library for PIC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for PIC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for PIC.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/

/***
**   File       : uart.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the include file for PIC uart driver
***/

#ifndef __uart_h__
#define __uart_h__

#include <pic.h>
#include <stdio.h>            // Standard input/output file used in Serialintwrite (sprintf)


// UART RX Interrupt (If not required comment below line)
//#define SERIAL_RX_INTERRUPT_ENABLE   1

// UART Buffer Size
#define UART_RX_BUFFER_SIZE          64

// New Line Index Buffer Size
#define NEW_LINE_INDEX_BUFFER_SIZE   10

// If interrupt is enable
#ifdef SERIAL_RX_INTERRUPT_ENABLE
#include <avr/interrupt.h>
#endif


// ASCII Code Definitions
#define NUL 0x00                          // Null Character
#define SOH 0x01                          // Start Of Heading
#define STX 0x02                          // Start Of Text
#define ETX 0x03                          // End Of Text
#define EOT 0x04                          // End of Transmission
#define ENQ 0x05                          // Enquiry
#define ACK 0x06                          // Acknowledgement
#define BEL 0x07                          // Bell
#define BS  0x08                          // Back Space
#define TAB 0x09                          // Horizontal TAB
#define LF  0x0A                          // Line Feed (Newline)
#define VT  0x0B                          // Vertical TAB
#define NP  0x0C                          // New Page
#define CR  0x0D                          // Carriage Return
#define SO  0x0E                          // Shift OUT
#define SI  0x0F                          // Shift IN
#define DLE 0x10                          // Data Link Escape
#define DC1 0x11                          // Device Control 1
#define DC2 0x12                          // Device Control 2
#define DC3 0x13                          // Device Control 3
#define DC4 0x14                          // Device Control 4
#define NAK 0x15                          // Negative Acknowledgement
#define SYN 0x16                          // Synchronous Idle
#define ETB 0x17                          // End of Trans. Block
#define CAN 0x18                          // Cancel
#define EM  0x19                          // End of Medium
#define SUB 0x1A                          // Substitute
#define ESC 0x1B                          // Escape
#define FS  0x1C                          // File Seperator
#define GS  0x1D                          // Group Seperator
#define RS  0x1E                          // Record Seperator
#define US  0x1F                          // Unit Seperator

#define CHAR_NULL  '\0'                   // Null charactor


// Radix for Serial Integer Print
#define HEX 16
#define DEC 10
#define OCT 8
#define BIN 2



/***************** Prototypes ****************************/
extern void           Serialbegin(unsigned long,unsigned long);
extern unsigned char  Serialavailable(void);
extern void           Serialwrite(unsigned char);
extern void           Serialprint(unsigned char *);
extern unsigned char  Serialread(void);
extern void           SerialIntWrite(signed int,unsigned char);

#ifdef SERIAL_RX_INTERRUPT_ENABLE
extern void          setSerialinterrupt(void);
extern void          Serialflush(void);

extern volatile unsigned char          uartNewLineFlag;
extern volatile unsigned char          uartReadBuffer[UART_RX_BUFFER_SIZE];
extern volatile unsigned int           uartReadCount;
extern volatile unsigned char          uartNewLineCount;
extern volatile unsigned char          uartNewLineIndexes[NEW_LINE_INDEX_BUFFER_SIZE];
#endif



#endif

