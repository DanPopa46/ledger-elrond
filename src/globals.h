#include "os.h"
#include "ux.h"
#include "os_io_seproxyhal.h"

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define P1_CONFIRM     0x01
#define P1_NON_CONFIRM 0x00
#define P1_FIRST       0x00
#define P1_MORE        0x80

#define FULL_ADDRESS_LENGTH 65 // hex address is 64 characters + \0 = 65
#define BIP32_PATH 5
#define COIN_TYPE_ERD 508UL
#define HRP      "erd"
#define HRP_TEST "xerd"
#define DECIMAL_PLACES 18

#define TX_VERSION 1

typedef enum {
    NETWORK_MAINNET = 0,
    NETWORK_TESTNET = 1
} network_t;

#define DEFAULT_NETWORK NETWORK_MAINNET

typedef enum {
    CONTRACT_DATA_ENABLED  = true,
    CONTRACT_DATA_DISABLED = false
} contract_data_t;

#define DEFAULT_CONTRACT_DATA CONTRACT_DATA_DISABLED

#define MSG_OK                     0x9000
#define ERR_USER_DENIED            0x6985
#define ERR_UNKNOWN_INSTRUCTION    0x6D00 // unknown INS
#define ERR_WRONG_CLA              0x6E00
#define ERR_INVALID_ARGUMENTS      0x6E01
#define ERR_INVALID_MESSAGE        0x6E02 // signTx
#define ERR_INVALID_P1             0x6E03 // signTx
#define ERR_MESSAGE_TOO_LONG       0x6E04 // signTx
#define ERR_RECEIVER_TOO_LONG      0x6E05 // signTx
#define ERR_AMOUNT_TOO_LONG        0x6E06 // signTx
#define ERR_CONTRACT_DATA_DISABLED 0x6E07 // signTx
#define ERR_MESSAGE_INCOMPLETE     0x6E08 // signTx
#define ERR_WRONG_TX_VERSION       0x6E09 // singTx

extern ux_state_t ux;
// display stepped screens
extern unsigned int ux_step;
extern unsigned int ux_step_count;

typedef struct internalStorage_t {
    unsigned char setting_network;
    unsigned char setting_contract_data;
    unsigned char setting_account;
    unsigned char setting_address_index;
    uint8_t initialized;
} internalStorage_t;

extern const internalStorage_t N_storage_real;
#define N_storage (*(volatile internalStorage_t*) PIC(&N_storage_real))
#endif
