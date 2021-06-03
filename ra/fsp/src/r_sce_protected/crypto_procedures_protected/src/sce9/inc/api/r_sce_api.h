/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_INTERFACES
 * @defgroup SCE_PROTECTED_API SCE Interface
 * @brief Interface for Secure Crypto Engine (SCE) functions.
 *
 * @section SCE_PROTECTED_API_Summary Summary
 * The SCE interface provides SCE functionality.
 *
 * The SCE interface can be implemented by:
 * - @ref SCE_PROTECTED
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_SCE_API_H
#define R_SCE_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* For AES operation. */
#define HW_SCE_AES128_KEY_INDEX_WORD_SIZE                         (12U)
#define HW_SCE_AES256_KEY_INDEX_WORD_SIZE                         (16U)
#define HW_SCE_AES128_KEY_WORD_SIZE                               (4U)
#define HW_SCE_AES256_KEY_WORD_SIZE                               (8U)
#define HW_SCE_AES128_KEY_BYTE_SIZE                               (16U)
#define HW_SCE_AES256_KEY_BYTE_SIZE                               (32U)
#define HW_SCE_AES_BLOCK_BYTE_SIZE                                (16U)
#define HW_SCE_AES_BLOCK_BIT_SIZE                                 (128U)
#define HW_SCE_AES_CBC_IV_BYTE_SIZE                               (16U)
#define HW_SCE_AES_GCM_AAD_BLOCK_BYTE_SIZE                        (16U)
#define HW_SCE_AES_CCM_B_FORMAT_BYTE_SIZE                         (128U)
#define HW_SCE_AES_CCM_COUNTER_BYTE_SIZE                          (16U)

/* For SHA operation. */
#define HW_SCE_SHA256_HASH_LENGTH_BYTE_SIZE                       (32U)
#define HW_SCE_SHA384_HASH_LENGTH_BYTE_SIZE                       (48U)

/* For HMAC operation. */
#define HW_SCE_HMAC_KEY_INDEX_BYTE_SIZE                           (32U)
#define HW_SCE_HMAC_KEY_INDEX_WORD_SIZE                           (8U)

/* For RSA operation. */
#define HW_SCE_RSA_1024_KEY_N_LENGTH_BYTE_SIZE                    (128U)
#define HW_SCE_RSA_1024_KEY_E_LENGTH_BYTE_SIZE                    (4U)
#define HW_SCE_RSA_1024_KEY_D_LENGTH_BYTE_SIZE                    (128U)
#define HW_SCE_RSA_2048_KEY_N_LENGTH_BYTE_SIZE                    (256U)
#define HW_SCE_RSA_2048_KEY_E_LENGTH_BYTE_SIZE                    (4U)
#define HW_SCE_RSA_2048_KEY_D_LENGTH_BYTE_SIZE                    (256U)
#define HW_SCE_RSA_3072_KEY_N_LENGTH_BYTE_SIZE                    (96 * 4U)
#define HW_SCE_RSA_3072_KEY_E_LENGTH_BYTE_SIZE                    (4U)
#define HW_SCE_RSA_3072_KEY_D_LENGTH_BYTE_SIZE                    (96 * 4U)
#define HW_SCE_RSA_4096_KEY_N_LENGTH_BYTE_SIZE                    (128 * 4U)
#define HW_SCE_RSA_4096_KEY_E_LENGTH_BYTE_SIZE                    (4U)
#define HW_SCE_RSA_4096_KEY_D_LENGTH_BYTE_SIZE                    (128 * 4U)
#define HW_SCE_RSA_1024_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE     (1U)
#define HW_SCE_RSA_1024_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE     (36U)
#define HW_SCE_RSA_1024_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE    (1U)
#define HW_SCE_RSA_1024_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE    (68U)
#define HW_SCE_RSA_2048_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE     (1U)
#define HW_SCE_RSA_2048_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE     (68U)
#define HW_SCE_RSA_2048_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE    (1U)
#define HW_SCE_RSA_2048_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE    (132U)
#define HW_SCE_RSA_3072_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE     (1U)
#define HW_SCE_RSA_3072_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE     (19U)
#define HW_SCE_RSA_3072_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE    (1U)
#define HW_SCE_RSA_3072_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE    (132U)
#define HW_SCE_RSA_4096_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE     (1U)
#define HW_SCE_RSA_4096_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE     (19U)
#define HW_SCE_RSA_4096_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE    (1U)
#define HW_SCE_RSA_4096_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE    (132U)
#define HW_SCE_RSA_KEY_GENERATION_DUMMY_BYTE_SIZE                 (12U)
#define HW_SCE_RSA1024_NE_KEY_BYTE_SIZE                           (144U)
#define HW_SCE_RSA1024_ND_KEY_BYTE_SIZE                           (256U)
#define HW_SCE_RSA2048_NE_KEY_BYTE_SIZE                           (272U)
#define HW_SCE_RSA2048_ND_KEY_BYTE_SIZE                           (512U)
#define HW_SCE_RSA3072_NE_KEY_BYTE_SIZE                           (96 * 4 + 16U)
#define HW_SCE_RSA3072_ND_KEY_BYTE_SIZE                           (192 * 4U)
#define HW_SCE_RSA4096_NE_KEY_BYTE_SIZE                           (128 * 4 + 16U)
#define HW_SCE_RSA4096_ND_KEY_BYTE_SIZE                           (256 * 4U)
#define HW_SCE_RSA1024_NE_KEY_INDEX_WORD_SIZE                     (73U)
#define HW_SCE_RSA1024_ND_KEY_INDEX_WORD_SIZE                     (101U)
#define HW_SCE_RSA2048_NE_KEY_INDEX_WORD_SIZE                     (137U)
#define HW_SCE_RSA2048_ND_KEY_INDEX_WORD_SIZE                     (197U)
#define HW_SCE_RSA3072_NE_KEY_INDEX_WORD_SIZE                     (137U)
#define HW_SCE_RSA3072_ND_KEY_INDEX_WORD_SIZE                     (197U)
#define HW_SCE_RSA4096_NE_KEY_INDEX_WORD_SIZE                     (137U)
#define HW_SCE_RSA4096_ND_KEY_INDEX_WORD_SIZE                     (197U)
#define HW_SCE_RSA1024_RANDOM_PUBLIC_KEY_INDEX_WORD_SIZE          (76U)
#define HW_SCE_RSA1024_RANDOM_PRIVATE_KEY_INDEX_WORD_SIZE         (104U)
#define HW_SCE_RSA2048_RANDOM_PUBLIC_KEY_INDEX_WORD_SIZE          (140U)
#define HW_SCE_RSA2048_RANDOM_PRIVATE_KEY_INDEX_WORD_SIZE         (200U)

#define HW_SCE_RSA_RSAES_PKCS_MIN_KEY_N_BYTE_SIZE    (11U)
#define HW_SCE_RSA_1024_DATA_BYTE_SIZE               (128U)
#define HW_SCE_RSA_2048_DATA_BYTE_SIZE               (256U)
#define HW_SCE_RSA_3072_DATA_BYTE_SIZE               (96 * 4U)
#define HW_SCE_RSA_4096_DATA_BYTE_SIZE               (128 * 4U)

/* RSA HASH type. */
#define HW_SCE_RSA_HASH_SHA256                       (0x03) /* SHA-256 */

/* For ECC operation. */
#define HW_SCE_ECC_KEY_LENGTH_BYTE_SIZE                             (112U)
#define HW_SCE_ECC_PUBLIC_KEY_MANAGEMENT_INFO_WORD_SIZE             (4U)
#define HW_SCE_ECC_PRIVATE_KEY_MANAGEMENT_INFO_WORD_SIZE            (20U)
#define HW_SCE_ECC_PUBLIC_KEY_BYTE_SIZE                             (64U)
#define HW_SCE_ECC_P384_PUBLIC_KEY_BYTE_SIZE                        (96U)
#define HW_SCE_ECC_PRIVATE_KEY_BYTE_SIZE                            (32U)
#define HW_SCE_ECC_P384_PRIVATE_KEY_BYTE_SIZE                       (48U)
#define HW_SCE_ECDSA_DATA_BYTE_SIZE                                 (64U)
#define HW_SCE_ECDSA_P384_DATA_BYTE_SIZE                            (96U)
#define HW_SCE_SHARED_SECRET_KEY_INDEX_WORD_SIZE                    (16U)
#define HW_SCE_ALGORITHM_ID_ENCODED_DATA_BYTE_SIZE                  (7U)

/* Key update. */
#define HW_SCE_UPDATE_KEY_RING_INDEX_WORD_SIZE                      (16U)

#define SCE_OEM_KEY_SIZE_DUMMY_INST_DATA_WORD                       (0)
#define SCE_OEM_KEY_SIZE_AES128_INST_DATA_WORD                      (8)
#define SCE_OEM_KEY_SIZE_AES256_INST_DATA_WORD                      (12)

#define SCE_OEM_KEY_SIZE_RSA1024_PUBLICK_KEY_INST_DATA_WORD         (40)
#define SCE_OEM_KEY_SIZE_RSA1024_PRIVATE_KEY_INST_DATA_WORD         (68)
#define SCE_OEM_KEY_SIZE_RSA2048_PUBLICK_KEY_INST_DATA_WORD         (72)
#define SCE_OEM_KEY_SIZE_RSA2048_PRIVATE_KEY_INST_DATA_WORD         (132)
#define SCE_OEM_KEY_SIZE_RSA3072_PUBLICK_KEY_INST_DATA_WORD         (104)
#define SCE_OEM_KEY_SIZE_RSA3072_PRIVATE_KEY_INST_DATA_WORD         (196)
#define SCE_OEM_KEY_SIZE_RSA4096_PUBLICK_KEY_INST_DATA_WORD         (136)
#define SCE_OEM_KEY_SIZE_RSA4096_PRIVATE_KEY_INST_DATA_WORD         (260)

#define SCE_OEM_KEY_SIZE_ECCP192_PUBLICK_KEY_INST_DATA_WORD         (20)
#define SCE_OEM_KEY_SIZE_ECCP192_PRIVATE_KEY_INST_DATA_WORD         (12)
#define SCE_OEM_KEY_SIZE_ECCP224_PUBLICK_KEY_INST_DATA_WORD         (20)
#define SCE_OEM_KEY_SIZE_ECCP224_PRIVATE_KEY_INST_DATA_WORD         (12)
#define SCE_OEM_KEY_SIZE_ECCP256_PUBLICK_KEY_INST_DATA_WORD         (20)
#define SCE_OEM_KEY_SIZE_ECCP256_PRIVATE_KEY_INST_DATA_WORD         (12)
#define SCE_OEM_KEY_SIZE_ECCP384_PUBLICK_KEY_INST_DATA_WORD         (28)
#define SCE_OEM_KEY_SIZE_ECCP384_PRIVATE_KEY_INST_DATA_WORD         (16)
#define SCE_OEM_KEY_SIZE_HMAC_SHA256_INST_DATA_WORD                 (12)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Data lifecycle */
typedef enum
{
    SCE_CM = 1,
    SCE_SSD,
    SCE_NSECSD,
    SCE_DPL,
    SCE_LCK_DBG,
    SCE_LCK_BOOT,
    SCE_RMA_REQ,
    SCE_RMA_ACK,
} lifecycle_t;

/** Byte data structure */
typedef struct sce_byte_data
{
    uint8_t * pdata;                           ///< pointer
    uint32_t  data_length;                     ///< data_length
    uint32_t  data_type;                       ///< data type
} sce_byte_data_t;

/** RSA byte data structure */
typedef sce_byte_data_t sce_rsa_byte_data_t;   ///< byte data

/** ECDSA byte data structure */
typedef sce_byte_data_t sce_ecdsa_byte_data_t; ///< byte data

/** AES wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_aes_wrapped_key
{
    uint32_t type;                                     ///< key type

    /* AES128, AES256 are supported */
    uint32_t value[HW_SCE_AES256_KEY_INDEX_WORD_SIZE]; ///< wrapped key value   
} sce_aes_wrapped_key_t;

/** HMAC-SHA wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_hmac_sha_wrapped_key
{
    uint32_t type;                                   ///< key type

    /* HMAC-SHA256 is supported */
    uint32_t value[HW_SCE_HMAC_KEY_INDEX_WORD_SIZE]; ///< wrapped key value   
} sce_hmac_sha_wrapped_key_t;

/** RSA 1024bit public wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa1024_public_wrapped_key
{
    uint32_t type;                                                                            ///< key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_1024_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_1024_KEY_N_LENGTH_BYTE_SIZE];                               ///< RSA 1024-bit public key n (plaintext)
        uint8_t  key_e[HW_SCE_RSA_1024_KEY_E_LENGTH_BYTE_SIZE];                               ///< RSA 1024-bit public key e (plaintext)
        uint8_t  dummy[HW_SCE_RSA_KEY_GENERATION_DUMMY_BYTE_SIZE];                            ///< dummy
        uint32_t key_management_info2[HW_SCE_RSA_1024_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa1024_public_wrapped_key_t;

/** RSA 1024bit private wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa1024_private_wrapped_key
{
    uint32_t type;                                                                             ///< key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_1024_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_1024_KEY_N_LENGTH_BYTE_SIZE];                                ///< RSA 1024-bit private key n (plaintext)
        uint32_t key_management_info2[HW_SCE_RSA_1024_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa1024_private_wrapped_key_t;

/** RSA 2048bit public wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa2048_public_wrapped_key
{
    uint32_t type;                                                                            ///< Key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_2048_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_2048_KEY_N_LENGTH_BYTE_SIZE];                               ///< RSA 2048-bit public key n (plaintext)
        uint8_t  key_e[HW_SCE_RSA_2048_KEY_E_LENGTH_BYTE_SIZE];                               ///< RSA 2048-bit public key e (plaintext)
        uint8_t  dummy[HW_SCE_RSA_KEY_GENERATION_DUMMY_BYTE_SIZE];                            ///< dummy
        uint32_t key_management_info2[HW_SCE_RSA_2048_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa2048_public_wrapped_key_t;

/** RSA 2048bit private wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa2048_private_wrapped_key
{
    uint32_t type;                                                                             ///< key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_2048_PRIVATE_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_2048_KEY_N_LENGTH_BYTE_SIZE];                                ///< RSA 2048-bit private key n (plaintext)
        uint32_t key_management_info2[HW_SCE_RSA_2048_PRIVATE_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa2048_private_wrapped_key_t;

/** RSA 3072bit public wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa3072_public_wrapped_key
{
    uint32_t type;                                                                            ///< Key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_3072_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_3072_KEY_N_LENGTH_BYTE_SIZE];                               ///< RSA 3072-bit public key n (plaintext)
        uint8_t  key_e[HW_SCE_RSA_3072_KEY_E_LENGTH_BYTE_SIZE];                               ///< RSA 3072-bit public key e (plaintext)
        uint8_t  dummy[HW_SCE_RSA_KEY_GENERATION_DUMMY_BYTE_SIZE];                            ///< dummy
        uint32_t key_management_info2[HW_SCE_RSA_3072_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa3072_public_wrapped_key_t;

/** RSA 4096bit public wrapped key data structure. DO NOT MODIFY. */
typedef struct sce_rsa4096_public_wrapped_key
{
    uint32_t type;                                                                            ///< Key type
    struct
    {
        uint32_t key_management_info1[HW_SCE_RSA_4096_PUBLIC_KEY_MANAGEMENT_INFO1_WORD_SIZE]; ///< key management information
        uint8_t  key_n[HW_SCE_RSA_4096_KEY_N_LENGTH_BYTE_SIZE];                               ///< RSA 4096-bit public key n (plaintext)
        uint8_t  key_e[HW_SCE_RSA_4096_KEY_E_LENGTH_BYTE_SIZE];                               ///< RSA 4096-bit public key e (plaintext)
        uint8_t  dummy[HW_SCE_RSA_KEY_GENERATION_DUMMY_BYTE_SIZE];                            ///< dummy
        uint32_t key_management_info2[HW_SCE_RSA_4096_PUBLIC_KEY_MANAGEMENT_INFO2_WORD_SIZE]; ///< key management information
    } value;
} sce_rsa4096_public_wrapped_key_t;

/** RSA 1024bit wrapped key pair structure. DO NOT MODIFY. */
typedef struct sce_rsa1024_wrapped_pair_key
{
    sce_rsa1024_private_wrapped_key_t private; ///< RSA 1024-bit private wrapped key
    sce_rsa1024_public_wrapped_key_t public;   ///< RSA 1024-bit public wrapped key
} sce_rsa1024_wrapped_pair_key_t;

/** RSA 2048bit wrapped key pair structure. DO NOT MODIFY. */
typedef struct sce_rsa2048_wrapped_pair_key
{
    sce_rsa2048_private_wrapped_key_t private; ///< RSA 2048-bit private wrapped key
    sce_rsa2048_public_wrapped_key_t public;   ///< RSA 2048-bit public wrapped key
} sce_rsa2048_wrapped_pair_key_t;

/** ECC P-192/224/256 public wrapped key data structure */
typedef struct sce_ecc_public_wrapped_key
{
    uint32_t type;                                                                     ///< key type
    struct
    {
        uint32_t key_management_info[HW_SCE_ECC_PUBLIC_KEY_MANAGEMENT_INFO_WORD_SIZE]; ///< key management information
        uint8_t  key_q[HW_SCE_ECC_KEY_LENGTH_BYTE_SIZE];                               ///< ECC public key Q (plaintext)
    } value;
} sce_ecc_public_wrapped_key_t;

/** ECC P-192/224/256 private wrapped key data structure */
typedef struct sce_ecc_private_wrapped_key
{
    uint32_t type;                                                    ///< key type
    uint32_t value[HW_SCE_ECC_PRIVATE_KEY_MANAGEMENT_INFO_WORD_SIZE]; ///< wrapped key value   
} sce_ecc_private_wrapped_key_t;

/** ECC P-192/224/256 wrapped key pair structure */
typedef struct sce_ecc_wrapped_pair_key
{
    sce_ecc_private_wrapped_key_t private; ///< ECC private wrapped key
    sce_ecc_public_wrapped_key_t public;   ///< ECC public wrapped key
} sce_ecc_wrapped_pair_key_t;

/** ECDH wrapped key data structure */
typedef struct sce_ecdh_wrapped_key_t
{
    uint32_t type;                                            ///< key type
    uint32_t value[HW_SCE_SHARED_SECRET_KEY_INDEX_WORD_SIZE]; ///< wrapped key value   
} sce_ecdh_wrapped_key_t;

/** Update key ring index data structure. DO NOT MODIFY. */
typedef struct sce_key_update_key
{
    uint32_t type;                                          ///< key type
    uint32_t value[HW_SCE_UPDATE_KEY_RING_INDEX_WORD_SIZE]; ///< wrapped key value   
} sce_key_update_key_t;

/** The work area for AES. DO NOT MODIFY. */
typedef struct sce_aes_handle
{
    uint32_t              id;                                                       ///< serial number of this handle
    sce_aes_wrapped_key_t wrapped_key;                                              ///< wrapped key
    uint32_t              current_input_data_size;                                  ///< text size under encryption / decryption
    uint8_t               last_1_block_as_fraction[HW_SCE_AES_BLOCK_BYTE_SIZE];     ///< text array less than the block long
    uint8_t               last_2_block_as_fraction[HW_SCE_AES_BLOCK_BYTE_SIZE * 2]; ///< reserved
    uint8_t               current_initial_vector[HW_SCE_AES_CBC_IV_BYTE_SIZE];      ///< current initialization vector used in CBC mode
    uint8_t               flag_call_init;                                           ///< control flag of calling function
} sce_aes_handle_t;

/** The work area for GCM. DO NOT MODIFY. */
typedef struct sce_gcm_handle
{
    uint32_t              id;                                                 ///< serial number of this handle
    sce_aes_wrapped_key_t wrapped_key;                                        ///< wrapped key
    uint8_t               gcm_buffer[HW_SCE_AES_BLOCK_BYTE_SIZE];             ///< text array less than the block long
    uint8_t               gcm_aad_buffer[HW_SCE_AES_GCM_AAD_BLOCK_BYTE_SIZE]; ///< AAD array less than the block long
    uint32_t              all_received_length;                                ///< entire length of text
    uint32_t              all_received_aad_length;                            ///< entire length of text
    uint32_t              buffering_length;                                   ///< text array length less than the block long
    uint32_t              buffering_aad_length;                               ///< AAD array length less than the block long
    uint8_t               flag_call_init;                                     ///< control flag of calling function
    uint8_t               flag_update_input_data;                             ///< control flag of next input data
} sce_gcm_handle_t;

/** The work area for CCM. DO NOT MODIFY. */
typedef struct sce_ccm_handle
{
    uint32_t              id;                                                ///< serial number of this handle
    sce_aes_wrapped_key_t wrapped_key;                                       ///< wrapped key
    uint8_t               formatted_data[HW_SCE_AES_CCM_B_FORMAT_BYTE_SIZE]; ///< formatted data area
    uint8_t               counter[HW_SCE_AES_CCM_COUNTER_BYTE_SIZE];         ///< counter of CTR mode
    uint8_t               ccm_buffer[HW_SCE_AES_BLOCK_BYTE_SIZE];            ///< text array less than the block long
    uint32_t              all_received_length;                               ///< entire length of text
    uint32_t              buffering_length;                                  ///< text array length less than the block long
    uint8_t               flag_call_init;                                    ///< control flag of calling function
} sce_ccm_handle_t;

/** The work area for CMAC. DO NOT MODIFY. */
typedef struct sce_cmac_handle
{
    uint32_t              id;                                      ///< serial number of this handle
    sce_aes_wrapped_key_t wrapped_key;                             ///< wrapped key
    uint8_t               cmac_buffer[HW_SCE_AES_BLOCK_BYTE_SIZE]; ///< message array less than the block long
    uint32_t              all_received_length;                     ///< entire length of message
    uint32_t              buffering_length;                        ///< message array length less than the block long
    uint8_t               flag_call_init;                          ///< control flag of calling function
} sce_cmac_handle_t;

/** The work area for SHA. DO NOT MODIFY. */
typedef struct sce_sha_md5_handle
{
    uint32_t id;                                                  ///< serial number of this handle
    uint8_t  sha_buffer[HW_SCE_SHA256_HASH_LENGTH_BYTE_SIZE * 4]; ///< message array length less than the block long
    uint32_t all_received_length;                                 ///< entire length of message
    uint32_t buffering_length;                                    ///< message array length less than the block long

    /* SHA1(20byte), SHA256(32byte), MD5(16byte) are supported */
    uint8_t current_hash[HW_SCE_SHA256_HASH_LENGTH_BYTE_SIZE];    ///< last hash value
    uint8_t flag_call_init;                                       ///< control flag of calling function
} sce_sha_md5_handle_t;

/** The work area for HMAC-SHA. DO NOT MODIFY. */
typedef struct sce_hmac_sha_handle
{
    uint32_t id;                                                   ///< serial number of this handle
    sce_hmac_sha_wrapped_key_t wrapped_key;                        ///< wrapped key
    uint8_t  hmac_buffer[HW_SCE_SHA256_HASH_LENGTH_BYTE_SIZE * 4]; ///< message array length less than the block long
    uint32_t all_received_length;                                  ///< entire length of message
    uint32_t buffering_length;                                     ///< message array length less than the block long
    uint8_t  flag_call_init;                                       ///< control flag of calling function
} sce_hmac_sha_handle_t;

/** The work area for ECDH */
typedef struct sce_ecdh_handle
{
    uint32_t id;                       ///< serial number of this handle
    uint32_t flag_use_key_id;          ///< control frag that the key_id has already used or not
    uint32_t key_id;                   ///< serial number of the wrapped key
    uint32_t key_type;                 ///< key type
    uint8_t  flag_call_init;           ///< control flag of calling function
    uint8_t  flag_call_make_public;    ///< control flag of calling function
    uint8_t  flag_call_read_public;    ///< control flag of calling function
    uint8_t  flag_call_shared_secret;  ///< control flag of calling function
} sce_ecdh_handle_t;

/** SCE Control block. Allocate an instance specific control block to pass into the API calls.
 * @par Implemented as
 * - sce_instance_ctrl_t
 */
typedef void sce_ctrl_t;

/** User configuration structure, used in open function */
typedef struct st_sce_cfg
{
    lifecycle_t lifecycle;             ///< Data lifecycle
} sce_cfg_t;

/** Functions implemented at the HAL layer will follow this API. */
typedef struct st_sce_api
{
    /** Enables use of SCE functionality.
     * @par Implemented as
     * - @ref R_SCE_Open()
     *
     * @param[in]     p_ctrl       Pointer to control structure.
     * @param[in]     p_cfg        Pointer to pin configuration structure.
     */

    /***** TODO: Replace "struct st_sce_ctrl" to  "void" *****/
    fsp_err_t (* open)(sce_ctrl_t * const p_ctrl, sce_cfg_t const * const p_cfg);

    /** Stops supply of power to the SCE.
     * @par Implemented as
     * - @ref R_SCE_Close()
     *
     * @param[in]     p_ctrl       Pointer to control structure.
     */
    fsp_err_t (* close)(sce_ctrl_t * const p_ctrl);

    /** Software reset to SCE.
     * @par Implemented as
     * - @ref R_SCE_SoftwareReset()
     *
     */
    fsp_err_t (* softwareReset)(void);

    /** Generates 4 words random number.
     * @par Implemented as
     * - @ref R_SCE_RandomNumberGenerate()
     *
     * @param[in,out] random Stores 4words (16 bytes) random data.
     */
    fsp_err_t (* randomNumberGenerate)(uint32_t * random);

    /** This API outputs 128-bit AES wrapped key.
     * @par Implemented as
     * - @ref R_SCE_AES128_WrappedKeyGenerate()
     *
     * @param[in,out] wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* AES128_WrappedKeyGenerate)(sce_aes_wrapped_key_t * wrapped_key);

    /** This API outputs 256-bit AES wrapped key.
     * @par Implemented as
     * - @ref R_SCE_AES256_WrappedKeyGenerate()
     *
     * @param[in,out] wrapped_key 256-bit AES wrapped key
     */
    fsp_err_t (* AES256_WrappedKeyGenerate)(sce_aes_wrapped_key_t * wrapped_key);

    /** This API outputs 128-bit AES wrapped key.
     * @par Implemented as
     * - @ref R_SCE_AES128_EncryptedKeyWrap()
     *
     * @param[in]     initial_vector Initialization vector when generating encrypted_key
     * @param[in]     encrypted_key  User key encryptedand MAC appended
     * @param[in]     key_update_key Key update keyring
     * @param[in,out] wrapped_key    128-bit AES wrapped key
     */
    fsp_err_t (* AES128_EncryptedKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                          sce_key_update_key_t * key_update_key, sce_aes_wrapped_key_t * wrapped_key);

    /** This API outputs 256-bit AES wrapped key.
     * @par Implemented as
     * - @ref R_SCE_AES256_EncryptedKeyWrap()
     *
     * @param[in]     initial_vector Initialization vector when generating encrypted_key
     * @param[in]     encrypted_key  User key encryptedand MAC appended
     * @param[in]     key_update_key Key update keyring
     * @param[in,out] wrapped_key    256-bit AES wrapped key
     */
    fsp_err_t (* AES256_EncryptedKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                          sce_key_update_key_t * key_update_key, sce_aes_wrapped_key_t * wrapped_key);

    /** Initialize AES128ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_EncryptInit()
     *
     * @param[in,out] handle      AES handler (work area)
     * @param[in]     wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* AES128ECB_EncryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES128ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_EncryptUpdate()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in,out] plain_length plaintext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES128ECB_EncryptUpdate)(sce_aes_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES128ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_EncryptFinal()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in,out] cipher        ciphertext data area (nothing ever written here)
     * @param[in,out] cipher_length ciphertext data length (0 always written here)
     */
    fsp_err_t (* AES128ECB_EncryptFinal)(sce_aes_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length);

    /** Initialize AES128ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_DecryptInit()
     *
     * @param[in,out] handle      AES handler (work area)
     * @param[in]     wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* AES128ECB_DecryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES128ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_DecryptUpdate()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in,out] cipher_length ciphertext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES128ECB_DecryptUpdate)(sce_aes_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES128ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128ECB_DecryptFinal()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in,out] plain        plaintext data area (nothing ever written here)
     * @param[in,out] plain_length plaintext data length (0 always written here)
     */
    fsp_err_t (* AES128ECB_DecryptFinal)(sce_aes_handle_t * handle, uint8_t * plain, uint32_t * plain_length);

    /** Initialize AES256ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_EncryptInit()
     *
     * @param[in,out] handle      AES handler (work area)
     * @param[in]     wrapped_key 256-bit AES wrapped key
     */
    fsp_err_t (* AES256ECB_EncryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES256ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_EncryptUpdate()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in,out] plain_length plaintext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES256ECB_EncryptUpdate)(sce_aes_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES256ECB encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_EncryptFinal()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in,out] cipher        ciphertext data area (nothing ever written here)
     * @param[in,out] cipher_length ciphertext data length (0 always written here)
     */
    fsp_err_t (* AES256ECB_EncryptFinal)(sce_aes_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length);

    /** Initialize AES256ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_DecryptInit()
     *
     * @param[in,out] handle      AES handler (work area)
     * @param[in]     wrapped_key 256-bit AES wrapped key
     */
    fsp_err_t (* AES256ECB_DecryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES256ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_DecryptUpdate()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in,out] cipher_length ciphertext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES256ECB_DecryptUpdate)(sce_aes_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES256ECB decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256ECB_DecryptFinal()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in,out] plain        plaintext data area (nothing ever written here)
     * @param[in,out] plain_length plaintext data length (0 always written here)
     */
    fsp_err_t (* AES256ECB_DecryptFinal)(sce_aes_handle_t * handle, uint8_t * plain, uint32_t * plain_length);

    /** Initialize AES128CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_EncryptInit()
     *
     * @param[in,out] handle         AES handler (work area)
     * @param[in]     wrapped_key    128-bit AES wrapped key
     * @param[in]     initial_vector initial vector area (16byte)
     */
    fsp_err_t (* AES128CBC_EncryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector);

    /** Update AES128CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_EncryptUpdate()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in,out] plain_length plaintext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES128CBC_EncryptUpdate)(sce_aes_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES128CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_EncryptFinal()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in,out] cipher        ciphertext data area (nothing ever written here)
     * @param[in,out] cipher_length ciphertext data length (0 always written here)
     */
    fsp_err_t (* AES128CBC_EncryptFinal)(sce_aes_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length);

    /** Initialize AES128CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_DecryptInit()
     *
     * @param[in,out] handle         AES handler (work area)
     * @param[in]     wrapped_key    128-bit AES wrapped key
     * @param[in]     initial_vector initial vector area (16byte)
     */
    fsp_err_t (* AES128CBC_DecryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector);

    /** Update AES128CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_DecryptUpdate()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in,out] cipher_length ciphertext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES128CBC_DecryptUpdate)(sce_aes_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES128CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CBC_DecryptFinal()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in,out] plain        plaintext data area (nothing ever written here)
     * @param[in,out] plain_length plaintext data length (0 always written here)
     */
    fsp_err_t (* AES128CBC_DecryptFinal)(sce_aes_handle_t * handle, uint8_t * plain, uint32_t * plain_length);

    /** Initialize AES256CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_EncryptInit()
     *
     * @param[in,out] handle         AES handler (work area)
     * @param[in]     wrapped_key    256-bit AES wrapped key
     * @param[in]     initial_vector initial vector area (16byte)
     */
    fsp_err_t (* AES256CBC_EncryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector);

    /** Update AES256CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_EncryptUpdate()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in,out] plain_length plaintext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES256CBC_EncryptUpdate)(sce_aes_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES256CBC encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_EncryptFinal()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in,out] cipher        ciphertext data area (nothing ever written here)
     * @param[in,out] cipher_length ciphertext data length (0 always written here)
     */
    fsp_err_t (* AES256CBC_EncryptFinal)(sce_aes_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length);

    /** Initialize AES256CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_DecryptInit()
     *
     * @param[in,out] handle         AES handler (work area)
     * @param[in]     wrapped_key    256-bit AES wrapped key
     * @param[in]     initial_vector initial vector area (16byte)
     */
    fsp_err_t (* AES256CBC_DecryptInit)(sce_aes_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector);

    /** Update AES256CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_DecryptUpdate()
     *
     * @param[in,out] handle        AES handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in,out] cipher_length ciphertext data length (must be a multiple of 16)
     */
    fsp_err_t (* AES256CBC_DecryptUpdate)(sce_aes_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES256CBC decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CBC_DecryptFinal()
     *
     * @param[in,out] handle       AES handler (work area)
     * @param[in,out] plain        plaintext data area (nothing ever written here)
     * @param[in,out] plain_length plaintext data length (0 always written here)
     */
    fsp_err_t (* AES256CBC_DecryptFinal)(sce_aes_handle_t * handle, uint8_t * plain, uint32_t * plain_length);

    /** Initialize AES128GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_EncryptInit()
     *
     * @param[in,out] handle                AES-GCM handler (work area)
     * @param[in]     wrapped_key           128-bit AES wrapped key
     * @param[in]     initial_vector        initialization vector area (initial_vector_length byte)
     * @param[in]     initial_vector_length initialization vector length (1 ore more bytes)
     */
    fsp_err_t (* AES128GCM_EncryptInit)(sce_gcm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector, uint32_t initial_vector_length);

    /** Update AES128GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_EncryptUpdate()
     *
     * @param[in,out] handle            AES-GCM handler (work area)
     * @param[in]     plain             plaintext data area
     * @param[in,out] cipher            ciphertext data area
     * @param[in]     plain_data_length plaintext data length (0 or more bytes)
     * @param[in]     aad               additional authentication data (aad_length byte)
     * @param[in]     aad_length        additional authentication data length (0 or more bytes)
     */
    fsp_err_t (* AES128GCM_EncryptUpdate)(sce_gcm_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_data_length, uint8_t * aad, uint32_t aad_length);

    /** Finalize AES128GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_EncryptFinal()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] cipher             ciphertext data area (cipher_data_length byte)
     * @param[in,out] cipher_data_length ciphertext data length (0 always written here)
     * @param[in,out] atag               authentication tag area
     */
    fsp_err_t (* AES128GCM_EncryptFinal)(sce_gcm_handle_t * handle, uint8_t * cipher, uint32_t * cipher_data_length,
                                         uint8_t * atag);

    /** Initialize AES128GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_DecryptInit()
     *
     * @param[in,out] handle                AES-GCM handler (work area)
     * @param[in]     wrapped_key           128-bit AES wrapped key
     * @param[in]     initial_vector        initialization vector area (initial_vector_length byte)
     * @param[in]     initial_vector_length initialization vector length (1 ore more bytes)
     */
    fsp_err_t (* AES128GCM_DecryptInit)(sce_gcm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector, uint32_t initial_vector_length);

    /** Update AES128GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_DecryptUpdate()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] cipher             ciphertext data area
     * @param[in]     plain              plaintext data area
     * @param[in]     cipher_data_length ciphertext data length (0 or more bytes)
     * @param[in]     aad                additional authentication data (aad_length byte)
     * @param[in]     aad_length         additional authentication data length (0 or more bytes)
     */
    fsp_err_t (* AES128GCM_DecryptUpdate)(sce_gcm_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_data_length, uint8_t * aad, uint32_t aad_length);

    /** Finalize AES128GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128GCM_DecryptFinal()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] plain              plaintext data area (cipher_data_length byte)
     * @param[in,out] plain_data_length  plaintext data length (0 always written here)
     * @param[in,out] atag               authentication tag area (atag_length byte)
     * @param[in]     atag_length        authentication tag length (4,8,12,13,14,15,16 bytes)
     */
    fsp_err_t (* AES128GCM_DecryptFinal)(sce_gcm_handle_t * handle, uint8_t * plain, uint32_t * plain_data_length,
                                         uint8_t * atag, uint32_t atag_length);

    /** Initialize AES256GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_EncryptInit()
     *
     * @param[in,out] handle                AES-GCM handler (work area)
     * @param[in]     wrapped_key           256-bit AES wrapped key
     * @param[in]     initial_vector        initialization vector area (initial_vector_length byte)
     * @param[in]     initial_vector_length initialization vector length (1 ore more bytes)
     */
    fsp_err_t (* AES256GCM_EncryptInit)(sce_gcm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector, uint32_t initial_vector_length);

    /** Update AES256GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_EncryptUpdate()
     *
     * @param[in,out] handle            AES-GCM handler (work area)
     * @param[in]     plain             plaintext data area
     * @param[in,out] cipher            ciphertext data area
     * @param[in]     plain_data_length plaintext data length (0 or more bytes)
     * @param[in]     aad               additional authentication data (aad_length byte)
     * @param[in]     aad_length        additional authentication data length (0 or more bytes)
     */
    fsp_err_t (* AES256GCM_EncryptUpdate)(sce_gcm_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_data_length, uint8_t * aad, uint32_t aad_length);

    /** Finalize AES256GCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_EncryptFinal()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] cipher             ciphertext data area (cipher_data_length byte)
     * @param[in,out] cipher_data_length ciphertext data length (0 always written here)
     * @param[in,out] atag               authentication tag area
     */
    fsp_err_t (* AES256GCM_EncryptFinal)(sce_gcm_handle_t * handle, uint8_t * cipher, uint32_t * cipher_data_length,
                                         uint8_t * atag);

    /** Initialize AES256GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_DecryptInit()
     *
     * @param[in,out] handle                AES-GCM handler (work area)
     * @param[in]     wrapped_key           256-bit AES wrapped key
     * @param[in]     initial_vector        initialization vector area (initial_vector_length byte)
     * @param[in]     initial_vector_length initialization vector length (1 ore more bytes)
     */
    fsp_err_t (* AES256GCM_DecryptInit)(sce_gcm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key,
                                        uint8_t * initial_vector, uint32_t initial_vector_length);

    /** Update AES256GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_DecryptUpdate()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] cipher             ciphertext data area
     * @param[in]     plain              plaintext data area
     * @param[in]     cipher_data_length ciphertext data length (0 or more bytes)
     * @param[in]     aad                additional authentication data (aad_length byte)
     * @param[in]     aad_length         additional authentication data length (0 or more bytes)
     */
    fsp_err_t (* AES256GCM_DecryptUpdate)(sce_gcm_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_data_length, uint8_t * aad, uint32_t aad_length);

    /** Finalize AES256GCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256GCM_DecryptFinal()
     *
     * @param[in,out] handle             AES-GCM handler (work area)
     * @param[in,out] plain              plaintext data area (cipher_data_length byte)
     * @param[in,out] plain_data_length  plaintext data length (0 always written here)
     * @param[in,out] atag               authentication tag area (atag_length byte)
     * @param[in]     atag_length        authentication tag length (4,8,12,13,14,15,16 bytes)
     */
    fsp_err_t (* AES256GCM_DecryptFinal)(sce_gcm_handle_t * handle, uint8_t * plain, uint32_t * plain_data_length,
                                         uint8_t * atag, uint32_t atag_length);

    /** Initialize AES128CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_EncryptInit()
     *
     * @param[in,out] handle         AES-CCM handler (work area)
     * @param[in]     wrapped_key    128-bit AES wrapped key
     * @param[in]     nonce          Nonce
     * @param[in]     nonce_length   Nonce data length (7 to 13 bytes)
     * @param[in]     adata          additional authentication data
     * @param[in]     a_length       additional authentication data length (0 to 110 bytes)
     * @param[in]     payload_length Payload length (any number of bytes)
     * @param[in]     mac_length     MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES128CCM_EncryptInit)(sce_ccm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key, uint8_t * nonce,
                                        uint32_t nonce_length, uint8_t * adata, uint8_t a_length,
                                        uint32_t payload_length, uint32_t mac_length);

    /** Update AES128CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_EncryptUpdate()
     *
     * @param[in,out] handle       AES-CCM handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in]     plain_length plaintext data length
     */
    fsp_err_t (* AES128CCM_EncryptUpdate)(sce_ccm_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES128CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_EncryptFinal()
     *
     * @param[in,out] handle        AES-CCM handler (work area)
     * @param[in,out] cipher        ciphertext data area
     * @param[in,out] cipher_length ciphertext data length
     * @param[in,out] mac           MAC area
     * @param[in]     mac_length    MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES128CCM_EncryptFinal)(sce_ccm_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length,
                                         uint8_t * mac, uint32_t mac_length);

    /** Initialize AES128CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_DecryptInit()
     *
     * @param[in,out] handle         AES-CCM handler (work area)
     * @param[in]     wrapped_key    128-bit AES wrapped key
     * @param[in]     nonce          Nonce
     * @param[in]     nonce_length   Nonce data length (7 to 13 bytes)
     * @param[in]     adata          additional authentication data
     * @param[in]     a_length       additional authentication data length (0 to 110 bytes)
     * @param[in]     payload_length Payload length (any number of bytes)
     * @param[in]     mac_length     MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES128CCM_DecryptInit)(sce_ccm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key, uint8_t * nonce,
                                        uint32_t nonce_length, uint8_t * adata, uint8_t a_length,
                                        uint32_t payload_length, uint32_t mac_length);

    /** Update AES128CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_DecryptUpdate()
     *
     * @param[in,out] handle        AES-CCM handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in]     cipher_length ciphertext data length
     */
    fsp_err_t (* AES128CCM_DecryptUpdate)(sce_ccm_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES128CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES128CCM_DecryptFinal()
     *
     * @param[in,out] handle       AES-CCM handler (work area)
     * @param[in,out] plain        plaintext data area
     * @param[in,out] plain_length plaintext data length
     * @param[in]     mac          MAC area
     * @param[in]     mac_length   MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES128CCM_DecryptFinal)(sce_ccm_handle_t * handle, uint8_t * plain, uint32_t * plain_length,
                                         uint8_t * mac, uint32_t mac_length);

    /** Initialize AES256CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_EncryptInit()
     *
     * @param[in,out] handle         AES-CCM handler (work area)
     * @param[in]     wrapped_key    256-bit AES wrapped key
     * @param[in]     nonce          Nonce
     * @param[in]     nonce_length   Nonce data length (7 to 13 bytes)
     * @param[in]     adata          additional authentication data
     * @param[in]     a_length       additional authentication data length (0 to 110 bytes)
     * @param[in]     payload_length Payload length (any number of bytes)
     * @param[in]     mac_length     MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES256CCM_EncryptInit)(sce_ccm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key, uint8_t * nonce,
                                        uint32_t nonce_length, uint8_t * adata, uint8_t a_length,
                                        uint32_t payload_length, uint32_t mac_length);

    /** Update AES256CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_EncryptUpdate()
     *
     * @param[in,out] handle       AES-CCM handler (work area)
     * @param[in]     plain        plaintext data area
     * @param[in,out] cipher       ciphertext data area
     * @param[in]     plain_length plaintext data length
     */
    fsp_err_t (* AES256CCM_EncryptUpdate)(sce_ccm_handle_t * handle, uint8_t * plain, uint8_t * cipher,
                                          uint32_t plain_length);

    /** Finalize AES256CCM encryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_EncryptFinal()
     *
     * @param[in,out] handle        AES-CCM handler (work area)
     * @param[in,out] cipher        ciphertext data area
     * @param[in,out] cipher_length ciphertext data length
     * @param[in,out] mac           MAC area
     * @param[in]     mac_length    MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES256CCM_EncryptFinal)(sce_ccm_handle_t * handle, uint8_t * cipher, uint32_t * cipher_length,
                                         uint8_t * mac, uint32_t mac_length);

    /** Initialize AES256CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_DecryptInit()
     *
     * @param[in,out] handle         AES-CCM handler (work area)
     * @param[in]     wrapped_key    256-bit AES wrapped key
     * @param[in]     nonce          Nonce
     * @param[in]     nonce_length   Nonce data length (7 to 13 bytes)
     * @param[in]     adata          additional authentication data
     * @param[in]     a_length       additional authentication data length (0 to 110 bytes)
     * @param[in]     payload_length Payload length (any number of bytes)
     * @param[in]     mac_length     MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES256CCM_DecryptInit)(sce_ccm_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key, uint8_t * nonce,
                                        uint32_t nonce_length, uint8_t * adata, uint8_t a_length,
                                        uint32_t payload_length, uint32_t mac_length);

    /** Update AES256CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_DecryptUpdate()
     *
     * @param[in,out] handle        AES-CCM handler (work area)
     * @param[in]     cipher        ciphertext data area
     * @param[in,out] plain         plaintext data area
     * @param[in]     cipher_length ciphertext data length
     */
    fsp_err_t (* AES256CCM_DecryptUpdate)(sce_ccm_handle_t * handle, uint8_t * cipher, uint8_t * plain,
                                          uint32_t cipher_length);

    /** Finalize AES256CCM decryption.
     * @par Implemented as
     * - @ref R_SCE_AES256CCM_DecryptFinal()
     *
     * @param[in,out] handle       AES-CCM handler (work area)
     * @param[in,out] plain        plaintext data area
     * @param[in,out] plain_length plaintext data length
     * @param[in]     mac          MAC area
     * @param[in]     mac_length   MAC length (4, 6, 8, 10, 12, 14, or 16 bytes)
     */
    fsp_err_t (* AES256CCM_DecryptFinal)(sce_ccm_handle_t * handle, uint8_t * plain, uint32_t * plain_length,
                                         uint8_t * mac, uint32_t mac_length);

    /** Initialize AES128CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_GenerateInit()
     *
     * @param[in,out] handle      AES-CMAC handler (work area)
     * @param[in]     wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* AES128CMAC_GenerateInit)(sce_cmac_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES128CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_GenerateUpdate()
     *
     * @param[in,out] handle         AES-CMAC handler (work area)
     * @param[in]     message        message data area (message_length byte)
     * @param[in]     message_length message data length (0 or more bytes)
     */
    fsp_err_t (* AES128CMAC_GenerateUpdate)(sce_cmac_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize AES128CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_GenerateFinal()
     *
     * @param[in,out] handle AES-CMAC handler (work area)
     * @param[in,out] mac    MAC data area (16byte)
     */
    fsp_err_t (* AES128CMAC_GenerateFinal)(sce_cmac_handle_t * handle, uint8_t * mac);

    /** Initialize AES128CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_VerifyInit()
     *
     * @param[in,out] handle      AES-CMAC handler (work area)
     * @param[in]     wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* AES128CMAC_VerifyInit)(sce_cmac_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES128CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_VerifyUpdate()
     *
     * @param[in,out] handle         AES-CMAC handler (work area)
     * @param[in]     message        message data area (message_length byte)
     * @param[in]     message_length message data length (0 or more bytes)
     */
    fsp_err_t (* AES128CMAC_VerifyUpdate)(sce_cmac_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize AES128CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES128CMAC_VerifyFinal()
     *
     * @param[in,out] handle     AES-CMAC handler (work area)
     * @param[in,out] mac        MAC data area (mac_length byte)
     * @param[in,out] mac_length MAC data length (2 to 16 bytes)
     */
    fsp_err_t (* AES128CMAC_VerifyFinal)(sce_cmac_handle_t * handle, uint8_t * mac, uint32_t mac_length);

    /** Initialize AES256CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_GenerateInit()
     *
     * @param[in,out] handle      AES-CMAC handler (work area)
     * @param[in]     wrapped_key 256-bit AES wrapped key
     */
    fsp_err_t (* AES256CMAC_GenerateInit)(sce_cmac_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES256CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_GenerateUpdate()
     *
     * @param[in,out] handle         AES-CMAC handler (work area)
     * @param[in]     message        message data area (message_length byte)
     * @param[in]     message_length message data length (0 or more bytes)
     */
    fsp_err_t (* AES256CMAC_GenerateUpdate)(sce_cmac_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize AES256CMAC generation.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_GenerateFinal()
     *
     * @param[in,out] handle AES-CMAC handler (work area)
     * @param[in,out] mac    MAC data area (16byte)
     */
    fsp_err_t (* AES256CMAC_GenerateFinal)(sce_cmac_handle_t * handle, uint8_t * mac);

    /** Initialize AES256CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_VerifyInit()
     *
     * @param[in,out] handle      AES-CMAC handler (work area)
     * @param[in]     wrapped_key 256-bit AES wrapped key
     */
    fsp_err_t (* AES256CMAC_VerifyInit)(sce_cmac_handle_t * handle, sce_aes_wrapped_key_t * wrapped_key);

    /** Update AES256CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_VerifyUpdate()
     *
     * @param[in,out] handle         AES-CMAC handler (work area)
     * @param[in]     message        message data area (message_length byte)
     * @param[in]     message_length message data length (0 or more bytes)
     */
    fsp_err_t (* AES256CMAC_VerifyUpdate)(sce_cmac_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize AES256CMAC verification.
     * @par Implemented as
     * - @ref R_SCE_AES256CMAC_VerifyFinal()
     *
     * @param[in,out] handle     AES-CMAC handler (work area)
     * @param[in,out] mac        MAC data area (mac_length byte)
     * @param[in,out] mac_length MAC data length (2 to 16 bytes)
     */
    fsp_err_t (* AES256CMAC_VerifyFinal)(sce_cmac_handle_t * handle, uint8_t * mac, uint32_t mac_length);

    /** Initialize SHA-256 Calculation.
     * @par Implemented as
     * - @ref R_SCE_SHA256_Init()
     *
     * @param[in,out] handle SHA handler (work area)
     */
    fsp_err_t (* SHA256_Init)(sce_sha_md5_handle_t * handle);

    /** Update SHA-256 Calculation.
     * @par Implemented as
     * - @ref R_SCE_SHA256_Update()
     *
     * @param[in,out] handle         SHA handler (work area)
     * @param[in]     message        message data area
     * @param[in]     message_length message data length
     */
    fsp_err_t (* SHA256_Update)(sce_sha_md5_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize SHA-256 Calculation.
     * @par Implemented as
     * - @ref R_SCE_SHA256_Final()
     *
     * @param[in,out] handle        SHA handler (work area)
     * @param[in,out] digest        hasha data area
     * @param[in,out] digest_length hash data length (32bytes)
     */
    fsp_err_t (* SHA256_Final)(sce_sha_md5_handle_t * handle, uint8_t * digest, uint32_t * digest_length);

    /** This API outputs 1024-bit RSA wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_RSA1024_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* RSA1024_WrappedKeyPairGenerate)(sce_rsa1024_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs 2048-bit RSA wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_RSA2048_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_key 128-bit AES wrapped key
     */
    fsp_err_t (* RSA2048_WrappedKeyPairGenerate)(sce_rsa2048_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs 1024-bit RSA public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA1024_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 1024-bit RSA public wrapped key
     */
    fsp_err_t (* RSA1024_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                 sce_key_update_key_t * key_update_key,
                                                 sce_rsa1024_public_wrapped_key_t * wrapped_key);

    /** This API outputs 1024-bit RSA private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA1024_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 1024-bit RSA private wrapped key
     */
    fsp_err_t (* RSA1024_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                  sce_key_update_key_t * key_update_key,
                                                  sce_rsa1024_private_wrapped_key_t * wrapped_key);

    /** This API outputs 2048-bit RSA public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA2048_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 2048-bit RSA public wrapped key
     */
    fsp_err_t (* RSA2048_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                 sce_key_update_key_t * key_update_key,
                                                 sce_rsa2048_public_wrapped_key_t * wrapped_key);

    /** This API outputs 2048-bit RSA private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA2048_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 2048-bit RSA private wrapped key
     */
    fsp_err_t (* RSA2048_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                  sce_key_update_key_t * key_update_key,
                                                  sce_rsa2048_private_wrapped_key_t * wrapped_key);

    /** This API outputs 3072-bit RSA public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA3072_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 3072-bit RSA public wrapped key
     */
    fsp_err_t (* RSA3072_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                 sce_key_update_key_t * key_update_key,
                                                 sce_rsa3072_public_wrapped_key_t * wrapped_key);

    /** This API outputs 4096-bit RSA public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_RSA4096_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key 4096-bit RSA public wrapped key
     */
    fsp_err_t (* RSA4096_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                 sce_key_update_key_t * key_update_key,
                                                 sce_rsa4096_public_wrapped_key_t * wrapped_key);

    /** RSASSA-PKCS1-V1_5 signature generation.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS1024_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Inputs the 1024-bit RSA private wrapped key.
     * @param[in]     hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS1024_SignatureGenerate)(sce_rsa_byte_data_t * message_hash, sce_rsa_byte_data_t * signature,
                                                    sce_rsa1024_private_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSASSA-PKCS1-V1_5 signature generation.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS2048_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Inputs the 2048-bit RSA private wrapped key.
     * @param[in]     hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS2048_SignatureGenerate)(sce_rsa_byte_data_t * message_hash, sce_rsa_byte_data_t * signature,
                                                    sce_rsa2048_private_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSASSA-PKCS1-V1_5 signature verification.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS1024_SignatureVerify()
     *
     * @param[in] signature    Signature text information to verify
     * @param[in] message_hash Message text or hash value to verify
     * @param[in] wrapped_key  Inputs the 1024-bit RSA public wrapped key.
     * @param[in] hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS1024_SignatureVerify)(sce_rsa_byte_data_t * signature, sce_rsa_byte_data_t * message_hash,
                                                  sce_rsa1024_public_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSASSA-PKCS1-V1_5 signature verification.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS2048_SignatureVerify()
     *
     * @param[in] signature    Signature text information to verify
     * @param[in] message_hash Message text or hash value to verify
     * @param[in] wrapped_key  Inputs the 2048-bit RSA public wrapped key.
     * @param[in] hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS2048_SignatureVerify)(sce_rsa_byte_data_t * signature, sce_rsa_byte_data_t * message_hash,
                                                  sce_rsa2048_public_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSASSA-PKCS1-V1_5 signature verification.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS3072_SignatureVerify()
     *
     * @param[in] signature    Signature text information to verify
     * @param[in] message_hash Message text or hash value to verify
     * @param[in] wrapped_key  Inputs the 3072-bit RSA public wrapped key.
     * @param[in] hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS3072_SignatureVerify)(sce_rsa_byte_data_t * signature, sce_rsa_byte_data_t * message_hash,
                                                  sce_rsa3072_public_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSASSA-PKCS1-V1_5 signature verification.
     * @par Implemented as
     * - @ref R_SCE_RSASSA_PKCS4096_SignatureVerify()
     *
     * @param[in] signature    Signature text information to verify
     * @param[in] message_hash Message text or hash value to verify
     * @param[in] wrapped_key  Inputs the 4096-bit RSA public wrapped key.
     * @param[in] hash_type    Only HW_SCE_RSA_HASH_SHA256 is supported
     */
    fsp_err_t (* RSASSA_PKCS4096_SignatureVerify)(sce_rsa_byte_data_t * signature, sce_rsa_byte_data_t * message_hash,
                                                  sce_rsa4096_public_wrapped_key_t * wrapped_key, uint8_t hash_type);

    /** RSAES-PKCS1-V1_5 encryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS1024_Encrypt()
     *
     * @param[in]     plain       plaintext
     * @param[in,out] cipher      ciphertext
     * @param[in]     wrapped_key Inputs the 1024-bit RSA public wrapped key.
     */
    fsp_err_t (* RSAES_PKCS1024_Encrypt)(sce_rsa_byte_data_t * plain, sce_rsa_byte_data_t * cipher,
                                         sce_rsa1024_public_wrapped_key_t * wrapped_key);

    /** RSAES-PKCS1-V1_5 encryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS2048_Encrypt()
     *
     * @param[in]     plain       plaintext
     * @param[in,out] cipher      ciphertext
     * @param[in]     wrapped_key Inputs the 2048-bit RSA public wrapped key.
     */
    fsp_err_t (* RSAES_PKCS2048_Encrypt)(sce_rsa_byte_data_t * plain, sce_rsa_byte_data_t * cipher,
                                         sce_rsa2048_public_wrapped_key_t * wrapped_key);

    /** RSAES-PKCS1-V1_5 encryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS3072_Encrypt()
     *
     * @param[in]     plain       plaintext
     * @param[in,out] cipher      ciphertext
     * @param[in]     wrapped_key Inputs the 3072-bit RSA public wrapped key.
     */
    fsp_err_t (* RSAES_PKCS3072_Encrypt)(sce_rsa_byte_data_t * plain, sce_rsa_byte_data_t * cipher,
                                         sce_rsa3072_public_wrapped_key_t * wrapped_key);

    /** RSAES-PKCS1-V1_5 encryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS4096_Encrypt()
     *
     * @param[in]     plain       plaintext
     * @param[in,out] cipher      ciphertext
     * @param[in]     wrapped_key Inputs the 4096-bit RSA public wrapped key.
     */
    fsp_err_t (* RSAES_PKCS4096_Encrypt)(sce_rsa_byte_data_t * plain, sce_rsa_byte_data_t * cipher,
                                         sce_rsa4096_public_wrapped_key_t * wrapped_key);

    /** RSAES-PKCS1-V1_5 decryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS1024_Decrypt()
     *
     * @param[in]     cipher      ciphertext
     * @param[in,out] plain       plaintext
     * @param[in]     wrapped_key Inputs the 1024-bit RSA private wrapped key.
     */
    fsp_err_t (* RSAES_PKCS1024_Decrypt)(sce_rsa_byte_data_t * cipher, sce_rsa_byte_data_t * plain,
                                         sce_rsa1024_private_wrapped_key_t * wrapped_key);

    /** RSAES-PKCS1-V1_5 decryption.
     * @par Implemented as
     * - @ref R_SCE_RSAES_PKCS2048_Decrypt()
     *
     * @param[in]     cipher      ciphertext
     * @param[in,out] plain       plaintext
     * @param[in]     wrapped_key Inputs the 2048-bit RSA private wrapped key.
     */
    fsp_err_t (* RSAES_PKCS2048_Decrypt)(sce_rsa_byte_data_t * cipher, sce_rsa_byte_data_t * plain,
                                         sce_rsa2048_private_wrapped_key_t * wrapped_key);

    /** This API outputs HMAC-SHA256 wrapped key.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_EncryptedKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key HMAC-SHA256 wrapped key
     */
    fsp_err_t (* SHA256HMAC_EncryptedKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                              sce_key_update_key_t * key_update_key,
                                              sce_hmac_sha_wrapped_key_t * wrapped_key);

    /** Initialize HMAC-SHA256 generation.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_GenerateInit()
     *
     * @param[in,out] handle        SHA-HMAC handler (work area)
     * @param[in]     wrapped_key   MAC wrapped key
     */
    fsp_err_t (* SHA256HMAC_GenerateInit)(sce_hmac_sha_handle_t * handle, sce_hmac_sha_wrapped_key_t * wrapped_key);

    /** Update HMAC-SHA256 generation.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_GenerateUpdate()
     *
     * @param[in,out] handle         SHA-HMAC handle (work area)
     * @param[in]     message        Message area
     * @param[in]     message_length Message length
     */
    fsp_err_t (* SHA256HMAC_GenerateUpdate)(sce_hmac_sha_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize HMAC-SHA256 generation.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_GenerateFinal()
     *
     * @param[in,out] handle SHA-HMAC handle (work area)
     * @param[in,out] mac    HMAC area (32 bytes)
     */
    fsp_err_t (* SHA256HMAC_GenerateFinal)(sce_hmac_sha_handle_t * handle, uint8_t * mac);

    /** Initialize HMAC-SHA256 verification.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_VerifyInit()
     *
     * @param[in,out] handle      SHA-HMAC handler (work area)
     * @param[in]     wrapped_key MAC wrapped key
     */
    fsp_err_t (* SHA256HMAC_VerifyInit)(sce_hmac_sha_handle_t * handle, sce_hmac_sha_wrapped_key_t * wrapped_key);

    /** Update HMAC-SHA256 verification.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_VerifyUpdate()
     *
     * @param[in,out] handle         SHA-HMAC handle (work area)
     * @param[in]     message        Message area
     * @param[in]     message_length Message length
     */
    fsp_err_t (* SHA256HMAC_VerifyUpdate)(sce_hmac_sha_handle_t * handle, uint8_t * message, uint32_t message_length);

    /** Finalize HMAC-SHA256 verification.
     * @par Implemented as
     * - @ref R_SCE_SHA256HMAC_VerifyFinal()
     *
     * @param[in,out] handle     SHA-HMAC handle (work area)
     * @param[in]     mac        HMAC area
     * @param[in]     mac_length HMAC length
     */
    fsp_err_t (* SHA256HMAC_VerifyFinal)(sce_hmac_sha_handle_t * handle, uint8_t * mac, uint32_t mac_length);

    /** This API outputs secp192r1 wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp192r1_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_pair_key Wrapped pair key for secp192r1 public key and private key pair
     */
    fsp_err_t (* ECC_secp192r1_WrappedKeyPairGenerate)(sce_ecc_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs secp224r1 wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp224r1_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_pair_key Wrapped pair key for secp224r1 public key and private key pair
     */
    fsp_err_t (* ECC_secp224r1_WrappedKeyPairGenerate)(sce_ecc_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs secp256r1 wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp256r1_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_pair_key Wrapped pair key for secp256r1 public key and private key pair
     */
    fsp_err_t (* ECC_secp256r1_WrappedKeyPairGenerate)(sce_ecc_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs secp384r1 wrapped pair key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp384r1_WrappedKeyPairGenerate()
     *
     * @param[in,out] wrapped_pair_key Wrapped pair key for secp384r1 public key and private key pair
     */
    fsp_err_t (* ECC_secp384r1_WrappedKeyPairGenerate)(sce_ecc_wrapped_pair_key_t * wrapped_pair_key);

    /** This API outputs secp192r1 public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp192r1_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp192r1 public wrapped key
     */
    fsp_err_t (* ECC_secp192r1_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                       sce_key_update_key_t * key_update_key,
                                                       sce_ecc_public_wrapped_key_t * wrapped_key);

    /** This API outputs secp224r1 public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp224r1_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp224r1 public wrapped key
     */
    fsp_err_t (* ECC_secp224r1_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                       sce_key_update_key_t * key_update_key,
                                                       sce_ecc_public_wrapped_key_t * wrapped_key);

    /** This API outputs secp256r1 public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp256r1_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp256r1 public wrapped key
     */
    fsp_err_t (* ECC_secp256r1_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                       sce_key_update_key_t * key_update_key,
                                                       sce_ecc_public_wrapped_key_t * wrapped_key);

    /** This API outputs secp384r1 public wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp384r1_EncryptedPublicKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp384r1 public wrapped key
     */
    fsp_err_t (* ECC_secp384r1_EncryptedPublicKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                       sce_key_update_key_t * key_update_key,
                                                       sce_ecc_public_wrapped_key_t * wrapped_key);

    /** This API outputs secp192r1 private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp192r1_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp192r1 private wrapped key
     */
    fsp_err_t (* ECC_secp192r1_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                        sce_key_update_key_t * key_update_key,
                                                        sce_ecc_private_wrapped_key_t * wrapped_key);

    /** This API outputs secp224r1 private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp224r1_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp224r1 private wrapped key
     */
    fsp_err_t (* ECC_secp224r1_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                        sce_key_update_key_t * key_update_key,
                                                        sce_ecc_private_wrapped_key_t * wrapped_key);

    /** This API outputs secp256r1 private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp256r1_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp256r1 private wrapped key
     */
    fsp_err_t (* ECC_secp256r1_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                        sce_key_update_key_t * key_update_key,
                                                        sce_ecc_private_wrapped_key_t * wrapped_key);

    /** This API outputs secp384r1 private wrapped key.
     * @par Implemented as
     * - @ref R_SCE_ECC_secp384r1_EncryptedPrivateKeyWrap()
     *
     * @param[in] initial_vector  Initialization vector when generating encrypted_key
     * @param[in] encrypted_key   User key encryptedand MAC appended
     * @param[in] key_update_key  Key update keyring
     * @param[in,out] wrapped_key secp384r1 private wrapped key
     */
    fsp_err_t (* ECC_secp384r1_EncryptedPrivateKeyWrap)(uint8_t * initial_vector, uint8_t * encrypted_key,
                                                        sce_key_update_key_t * key_update_key,
                                                        sce_ecc_private_wrapped_key_t * wrapped_key);

    /** ECDSA signature generation.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp192r1_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Input wrapped key of secp192r1 private key.
     */
    fsp_err_t (* ECDSA_secp192r1_SignatureGenerate)(sce_ecdsa_byte_data_t         * message_hash,
                                                    sce_ecdsa_byte_data_t         * signature,
                                                    sce_ecc_private_wrapped_key_t * wrapped_key);

    /** ECDSA signature generation.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp224r1_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Input wrapped key of secp224r1 private key.
     */
    fsp_err_t (* ECDSA_secp224r1_SignatureGenerate)(sce_ecdsa_byte_data_t         * message_hash,
                                                    sce_ecdsa_byte_data_t         * signature,
                                                    sce_ecc_private_wrapped_key_t * wrapped_key);

    /** ECDSA signature generation.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp256r1_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Input wrapped key of secp256r1 private key.
     */
    fsp_err_t (* ECDSA_secp256r1_SignatureGenerate)(sce_ecdsa_byte_data_t         * message_hash,
                                                    sce_ecdsa_byte_data_t         * signature,
                                                    sce_ecc_private_wrapped_key_t * wrapped_key);

    /** ECDSA signature generation.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp384r1_SignatureGenerate()
     *
     * @param[in]     message_hash Message or hash value to which to attach signature
     * @param[in,out] signature    Signature text storage destination information
     * @param[in]     wrapped_key  Input wrapped key of secp384r1 private key.
     */
    fsp_err_t (* ECDSA_secp384r1_SignatureGenerate)(sce_ecdsa_byte_data_t         * message_hash,
                                                    sce_ecdsa_byte_data_t         * signature,
                                                    sce_ecc_private_wrapped_key_t * wrapped_key);

    /** ECDSA signature verification.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp192r1_SignatureVerify()
     *
     * @param[in]     signature    Signature text information to be verified
     * @param[in,out] message_hash Message or hash value to be verified
     * @param[in]     wrapped_key  Input wrapped key of secp192r1 public key.
     */
    fsp_err_t (* ECDSA_secp192r1_SignatureVerify)(sce_ecdsa_byte_data_t        * signature,
                                                  sce_ecdsa_byte_data_t        * message_hash,
                                                  sce_ecc_public_wrapped_key_t * wrapped_key);

    /** ECDSA signature verification.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp224r1_SignatureVerify()
     *
     * @param[in]     signature    Signature text information to be verified
     * @param[in,out] message_hash Message or hash value to be verified
     * @param[in]     wrapped_key  Input wrapped key of secp224r1 public key.
     */
    fsp_err_t (* ECDSA_secp224r1_SignatureVerify)(sce_ecdsa_byte_data_t        * signature,
                                                  sce_ecdsa_byte_data_t        * message_hash,
                                                  sce_ecc_public_wrapped_key_t * wrapped_key);

    /** ECDSA signature verification.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp256r1_SignatureVerify()
     *
     * @param[in]     signature    Signature text information to be verified
     * @param[in,out] message_hash Message or hash value to be verified
     * @param[in]     wrapped_key  Input wrapped key of secp256r1 public key.
     */
    fsp_err_t (* ECDSA_secp256r1_SignatureVerify)(sce_ecdsa_byte_data_t        * signature,
                                                  sce_ecdsa_byte_data_t        * message_hash,
                                                  sce_ecc_public_wrapped_key_t * wrapped_key);

    /** ECDSA signature verification.
     * @par Implemented as
     * - @ref R_SCE_ECDSA_secp384r1_SignatureVerify()
     *
     * @param[in]     signature    Signature text information to be verified
     * @param[in,out] message_hash Message or hash value to be verified
     * @param[in]     wrapped_key  Input wrapped key of secp384r1 public key.
     */
    fsp_err_t (* ECDSA_secp384r1_SignatureVerify)(sce_ecdsa_byte_data_t        * signature,
                                                  sce_ecdsa_byte_data_t        * message_hash,
                                                  sce_ecc_public_wrapped_key_t * wrapped_key);

    /** secp256r1 ECDH Initialization.
     * @par Implemented as
     * - @ref R_SCE_ECDH_secp256r1_Init()
     *
     * @param[in,out] handle     ECDH handler (work area)
     * @param[in]     key_type   Key exchange type
     * @param[in]     use_key_id use key_id or not
     */
    fsp_err_t (* ECDH_secp256r1_Init)(sce_ecdh_handle_t * handle, uint32_t key_type, uint32_t use_key_id);

    /** secp256r1 ECDH public key Signature.
     * @par Implemented as
     * - @ref R_SCE_ECDH_secp256r1_PublicKeySign()
     *
     * @param[in,out] handle                  ECDH handler (work area)
     * @param[in]     ecc_public_wrapped_key  For ECDHE, input a null pointer. For ECDH, input the wrapped key of a secp256r1 public key.
     * @param[in]     ecc_private_wrapped_key secp256r1 private key  for signature generation
     * @param[in,out] public_key              User secp256r1 public key (512-bit) for key exchange.
     * @param[in,out] signature               Signature text storage destination information
     * @param[in,out] wrapped_key             For ECDHE, a private wrapped key generated from a random number. Not output for ECDH.
     */
    fsp_err_t (* ECDH_secp256r1_PublicKeySign)(sce_ecdh_handle_t * handle,
                                               sce_ecc_public_wrapped_key_t * ecc_public_wrapped_key,
                                               sce_ecc_private_wrapped_key_t * ecc_private_wrapped_key,
                                               uint8_t * public_key, sce_ecdsa_byte_data_t * signature,
                                               sce_ecc_private_wrapped_key_t * wrapped_key);

    /** secp256r1 ECDH public key verification.
     * @par Implemented as
     * - @ref R_SCE_ECDH_secp256r1_PublicKeyVerify()
     *
     * @param[in,out] handle                 ECDH handler (work area)
     * @param[in]     ecc_public_wrapped_key Public wrapped key area for signature verification
     * @param[in]     public_key_data        secp256r1 public key (512-bit)
     * @param[in]     signature              ECDSA secp256r1 signature of ecc_public_wrapped_key
     * @param[in,out] wrapped_key            wrapped key of ecc_public_wrapped_key
     */
    fsp_err_t (* ECDH_secp256r1_PublicKeyVerify)(sce_ecdh_handle_t * handle,
                                                 sce_ecc_public_wrapped_key_t * ecc_public_wrapped_key,
                                                 uint8_t * public_key_data, sce_ecdsa_byte_data_t * signature,
                                                 sce_ecc_public_wrapped_key_t * wrapped_key);

    /** secp256r1 ECDH shared secret calculation.
     * @par Implemented as
     * - @ref R_SCE_ECDH_secp256r1_SharedSecretCalculate()
     *
     * @param[in,out] handle                    ECDH handler (work area)
     * @param[in]     ecc_public_wrapped_key    Public wrapped key
     * @param[in]     ecc_private_wrapped_key   Private wrapped key
     * @param[in,out] shared_secret_wrapped_key Wrapped key of shared secret Z calculated by ECDH key exchange
     */
    fsp_err_t (* ECDH_secp256r1_SharedSecretCalculate)(sce_ecdh_handle_t             * handle,
                                                       sce_ecc_public_wrapped_key_t  * ecc_public_wrapped_key,
                                                       sce_ecc_private_wrapped_key_t * ecc_private_wrapped_key,
                                                       sce_ecdh_wrapped_key_t        * shared_secret_wrapped_key);

    /** secp256r1 ECDH key derivation.
     * @par Implemented as
     * - @ref R_SCE_ECDH_secp256r1_KeyDerivation()
     *
     * @param[in,out] handle                    ECDH handler (work area)
     * @param[in]     shared_secret_wrapped_key Z wrapped key calculated by R_SCE_ECDH_secp256r1_SharedSecretCalculate
     * @param[in]     key_type                  Derived key type
     * @param[in]     kdf_type                  Algorithm used for key derivation calculation
     * @param[in]     other_info                Additional data used for key derivation calculation
     * @param[in]     other_info_length         Data length of other_info
     * @param[in]     salt_wrapped_key          Salt wrapped key
     * @param[in,out] wrapped_key               Wrapped key corresponding to key_type.
     */
    fsp_err_t (* ECDH_secp256r1_KeyDerivation)(sce_ecdh_handle_t * handle,
                                               sce_ecdh_wrapped_key_t * shared_secret_wrapped_key, uint32_t key_type,
                                               uint32_t kdf_type, uint8_t * other_info,
                                               uint32_t other_info_length,
                                               sce_hmac_sha_wrapped_key_t * salt_wrapped_key,
                                               sce_aes_wrapped_key_t * wrapped_key);
} sce_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_sce_instance
{
    sce_ctrl_t      * p_ctrl;          ///< Pointer to the control structure for this instance
    sce_cfg_t const * p_cfg;           ///< Pointer to the configuration structure for this instance
    sce_api_t const * p_api;           ///< Pointer to the API structure for this instance
} sce_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_SCE_API_H */

/*******************************************************************************************************************//**
 * @} (end addtogroup SCE_PROTECTED_API)
 **********************************************************************************************************************/