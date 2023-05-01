#ifndef BOARD_H
#define BOARD_H

//BoxLambda Board Definitions for SDSPI SW, derived from 
//https://github.com/ZipCPU/zbasic/blob/master/sw/zlib/board.h

#define _BOARD_HAS_SDSPI

#define	SDSPI_SETAUX	0x0000ff
#define	SDSPI_READAUX	0x0000bf
#define	SDSPI_CMD		0x000040
#define	SDSPI_ACMD		(0x040+55) // CMD55
#define	SDSPI_FIFO_OP	0x000800	// Read only
#define	SDSPI_WRITEOP	0x000c00	// Write to the FIFO
#define	SDSPI_ALTFIFO	0x001000
#define	SDSPI_BUSY		0x004000
#define	SDSPI_ERROR		0x008000
#define	SDSPI_CLEARERR	0x008000
// #define	SDSPI_CRCERR	0x010000
// #define	SDSPI_ERRTOK	0x020000
#define	SDSPI_REMOVED	0x040000
#define	SDSPI_PRESENTN	0x080000
#define	SDSPI_RESET		0x100000	// Read only
#define	SDSPI_WATCHDOG	0x200000	// Read only
#define	SDSPI_GO_IDLE	((SDSPI_REMOVED|SDSPI_CLEARERR|SDSPI_CMD)+0)
#define	SDSPI_READ_SECTOR	((SDSPI_CMD|SDSPI_CLEARERR|SDSPI_FIFO_OP)+17)
#define	SDSPI_WRITE_SECTOR	((SDSPI_CMD|SDSPI_CLEARERR|SDSPI_WRITEOP)+24)

typedef	struct SDSPI_S {
	unsigned	sd_ctrl, sd_data, sd_fifo[2];
} SDSPI;

static volatile SDSPI *const _sdcard = ((SDSPI *)0x10000020);

#endif //BOARD_H