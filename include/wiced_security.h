/*
 * Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 *  Defines cryptography functions for encryption, decryption and hashing
 *
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include "crypto_structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 * @cond               Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

#define AES_ENCRYPT     1
#define AES_DECRYPT     0

#define DES_ENCRYPT     1
#define DES_DECRYPT     0

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *              Global Variables
 ******************************************************/

/******************************************************
 *              Function Declarations
 * @endcond
 ******************************************************/

/*****************************************************************************/
/** @addtogroup crypto       Crypto functions
 *
 *  WICED Cryptography functions
 */
/*****************************************************************************/


/*****************************************************************************/
/** @addtogroup aes       AES
 *  @ingroup crypto
 *
 * AES functions
 *
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief               AES key schedule (encryption)
 *
 * @param ctx           AES context to be initialized
 * @param key           encryption key
 * @param keysize_bits  must be 128, 192 or 256
 */
void aes_setkey_enc( aes_context_t *ctx, const unsigned char *key, int32_t keysize_bits );

/**
 * @brief               AES key schedule (decryption)
 *
 * @param ctx           AES context to be initialized
 * @param key           decryption key
 * @param keysize_bits  must be 128, 192 or 256
 */
void aes_setkey_dec( aes_context_t *ctx, const unsigned char *key, int32_t keysize_bits );

/**
 * @brief          AES-ECB block encryption/decryption
 *
 * @param ctx      AES context
 * @param mode     AES_ENCRYPT or AES_DECRYPT
 * @param input    16-byte input block
 * @param output   16-byte output block
 */
void aes_crypt_ecb( aes_context_t *ctx, aes_mode_type_t mode, const unsigned char input[16], unsigned char output[16] );

/**
 * @brief          AES-CBC buffer encryption/decryption
 *
 * @param ctx      AES context
 * @param mode     AES_ENCRYPT or AES_DECRYPT
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer receiving the output data
 */
void aes_crypt_cbc( aes_context_t *ctx, aes_mode_type_t mode, int32_t length, unsigned char iv[16], const unsigned char *input, unsigned char *output );

/**
 * @brief          AES-CBC buffer encryption/decryption with partial block padding
 *
 * @param ctx      AES context
 * @param mode     AES_ENCRYPT or AES_DECRYPT
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer receiving the output data
 */
int aes_cbc_crypt_pad_length_padding( aes_context_t *ctx, aes_mode_type_t mode, uint32_t length, const unsigned char iv[16], const unsigned char *input, unsigned char *output );

/**
 * @brief          AES-CFB128 buffer encryption/decryption
 *
 * @param ctx      AES context
 * @param mode     AES_ENCRYPT or AES_DECRYPT
 * @param length   length of the input data
 * @param iv_off   offset in IV (updated after use)
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer receiving the output data
 */
void aes_crypt_cfb128( aes_context_t *ctx, int32_t mode, int32_t length, int32_t *iv_off, unsigned char iv[16], const unsigned char *input, unsigned char *output );

/**
 * @brief          AES-CTR buffer encryption/decryption
 *
 * @param ctx      AES context
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer receiving the output data
 */
int aes_crypt_ctr( aes_context_t *ctx, uint32_t length, const unsigned char iv[16], const unsigned char *input, unsigned char *output );

/**
 * @brief            AES-CCM MAC calculation
 *
 * @param ctx        AES context
 * @param length     length of the input data
 * @param aad_length length of the additional associated data
 * @param nonce      the nonce to use
 * @param aad_input  the buffer containing the additional associated data
 * @param data_input buffer holding the input data
 * @param mac_output buffer which recieves the output MAC
 */
int aes_ccm_mac( aes_context_t *ctx, uint32_t length, uint32_t aad_length, const unsigned char nonce[13], const unsigned char *aad_input, const unsigned char *data_input, unsigned char mac_output[8] );

/**
 * @brief                   AES-CCM encryption
 *
 * @param ctx               AES context
 * @param length            length of the input data
 * @param aad_length        length of the additional associated data
 * @param nonce             the nonce to use
 * @param aad_input         the buffer containing the additional associated data
 * @param plaintext_input   buffer holding the input data
 * @param ciphertext_output buffer which receives the output ciphertext
 * @param mac_output        buffer which recieves the output MAC
 */
int aes_encrypt_ccm( aes_context_t *ctx, uint32_t length, uint32_t aad_length, const unsigned char nonce[13], const unsigned char *aad_input, const unsigned char *plaintext_input, unsigned char *ciphertext_output, unsigned char mac_output[8] );

/**
 * @brief                   AES-CCM decryption
 *
 * @param ctx               AES context
 * @param length            length of the input data
 * @param aad_length        length of the additional associated data
 * @param nonce             the nonce to use
 * @param aad_input         the buffer containing the additional associated data
 * @param ciphertext_input  buffer holding the input data
 * @param plaintext_output  buffer which receives the output plaintext
 */
int aes_decrypt_ccm( aes_context_t *ctx, uint32_t length, uint32_t aad_length, const unsigned char nonce[13], const unsigned char *aad_input, const unsigned char *ciphertext_input, unsigned char *plaintext_output );


/** @} */

/*****************************************************************************/
/** @addtogroup des       DES
 *  @ingroup crypto
 *
 * DES functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          DES key schedule (56-bit, encryption)
 *
 * @param ctx      DES context to be initialized
 * @param key      8-byte secret key
 */
void des_setkey_enc( des_context *ctx, const unsigned char key[8] );

/**
 * @brief          DES key schedule (56-bit, decryption)
 *
 * @param ctx      DES context to be initialized
 * @param key      8-byte secret key
 */
void des_setkey_dec( des_context *ctx, const unsigned char key[8] );

/**
 * @brief          Triple-DES key schedule (112-bit, encryption)
 *
 * @param ctx      3DES context to be initialized
 * @param key      16-byte secret key
 */
void des3_set2key_enc( des3_context *ctx, const unsigned char key[16] );

/**
 * @brief          Triple-DES key schedule (112-bit, decryption)
 *
 * @param ctx      3DES context to be initialized
 * @param key      16-byte secret key
 */
void des3_set2key_dec( des3_context *ctx, const unsigned char key[16] );

/**
 * @brief          Triple-DES key schedule (168-bit, encryption)
 *
 * @param ctx      3DES context to be initialized
 * @param key      24-byte secret key
 */
void des3_set3key_enc( des3_context *ctx, const unsigned char key[24] );

/**
 * @brief          Triple-DES key schedule (168-bit, decryption)
 *
 * @param ctx      3DES context to be initialized
 * @param key      24-byte secret key
 */
void des3_set3key_dec( des3_context *ctx, const unsigned char key[24] );

/**
 * @brief          DES-ECB block encryption/decryption
 *
 * @param ctx      DES context
 * @param input    64-bit input block
 * @param output   64-bit output block
 */
void des_crypt_ecb( des_context *ctx, const unsigned char input[8], unsigned char output[8] );

/**
 * @brief          DES-CBC buffer encryption/decryption
 *
 * @param ctx      DES context
 * @param mode     DES_ENCRYPT or DES_DECRYPT
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer holding the output data
 */
void des_crypt_cbc( des_context *ctx, int32_t mode, int32_t length, unsigned char iv[8], const unsigned char *input, unsigned char *output );

/**
 * @brief          3DES-ECB block encryption/decryption
 *
 * @param ctx      3DES context
 * @param input    64-bit input block
 * @param output   64-bit output block
 */
void des3_crypt_ecb( des3_context *ctx, const unsigned char input[8], unsigned char output[8] );

/**
 * @brief          3DES-CBC buffer encryption/decryption
 *
 * @param ctx      3DES context
 * @param mode     DES_ENCRYPT or DES_DECRYPT
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer holding the output data
 */
void des3_crypt_cbc( des3_context *ctx, int32_t mode, int32_t length, unsigned char iv[8], const unsigned char *input, unsigned char *output );

/** @} */

/*****************************************************************************/
/** @addtogroup sha1       SHA1
 *  @ingroup crypto
 *
 * SHA1 functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          SHA-1 context setup
 *
 * @param ctx      context to be initialized
 */
void sha1_starts( sha1_context *ctx );

/**
 * @brief          SHA-1 process buffer
 *
 * @param ctx      SHA-1 context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void sha1_update( sha1_context *ctx, const unsigned char *input, int32_t ilen );

/**
 * @brief          SHA-1 final digest
 *
 * @param ctx      SHA-1 context
 * @param output   SHA-1 checksum result
 */
void sha1_finish( sha1_context *ctx, unsigned char output[20] );

/**
 * @brief          Output = SHA-1( input buffer )
 *
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   SHA-1 checksum result
 */
void sha1( const unsigned char *input, int32_t ilen, unsigned char output[20] );


/**
 * @brief          SHA-1 HMAC context setup
 *
 * @param ctx      HMAC context to be initialized
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 */
void sha1_hmac_starts( sha1_context *ctx, const unsigned char *key, uint32_t keylen );

/**
 * @brief          SHA-1 HMAC process buffer
 *
 * @param ctx      HMAC context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void sha1_hmac_update( sha1_context *ctx, const unsigned char *input, uint32_t ilen );

/**
 * @brief          SHA-1 HMAC final digest
 *
 * @param ctx      HMAC context
 * @param output   SHA-1 HMAC checksum result
 */
void sha1_hmac_finish( sha1_context *ctx, unsigned char output[20] );

/**
 * @brief          Output = HMAC-SHA-1( hmac key, input buffer )
 *
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   HMAC-SHA-1 result
 */
void sha1_hmac( const unsigned char *key, int32_t keylen, const unsigned char *input, int32_t ilen, unsigned char output[20] );

/** @} */

/*****************************************************************************/
/** @addtogroup sha256       SHA224 / SHA256
 *  @ingroup crypto
 *
 * SHA224 and SHA256 hashing functions
 *
 *  @{
 */
/*****************************************************************************/


/**
 * @brief          SHA-224 or SHA-256 context setup
 *
 * @param ctx      context to be initialized
 * @param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_starts( sha2_context *ctx, int32_t is224 );

/**
 * @brief          SHA-224 or SHA-256 process buffer
 *
 * @param ctx      context that has been intitialised with sha2_starts
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void sha2_update( sha2_context *ctx, const unsigned char *input, uint32_t ilen );

/**
 * @brief          SHA-224 or SHA-256 final digest
 *
 * @param ctx      context that has been intitialised with sha2_starts and filled with sha2_update
 * @param output   SHA-224/256 checksum result
 */
void sha2_finish( sha2_context *ctx, unsigned char output[32] );

/**
 * @brief          Output = SHA-224/256( input buffer )
 *
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   SHA-224/256 checksum result
 * @param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2( const unsigned char *input, uint32_t ilen, unsigned char output[32], int32_t is224 );

/**
 * @brief          SHA-224 or SHA-256 HMAC context setup
 *
 * @param ctx      HMAC context to be initialized
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 * @param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_hmac_starts( sha2_context *ctx, const unsigned char *key, uint32_t keylen, int32_t is224 );

/**
 * @brief          SHA-224 or SHA-256 HMAC process buffer
 *
 * @param ctx      HMAC context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void sha2_hmac_update( sha2_context *ctx, const unsigned char *input, uint32_t ilen );

/**
 * @brief          SHA-224 or SHA-256 HMAC final digest
 *
 * @param ctx      HMAC context
 * @param output   SHA-224/256 HMAC checksum result
 */
void sha2_hmac_finish( sha2_context *ctx, unsigned char output[32] );

/**
 * @brief          Output = HMAC-SHA-224/256( hmac key, input buffer )
 *
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   HMAC-SHA-224/256 result
 * @param is224    0 = use SHA256, 1 = use SHA224
 */
void sha2_hmac( const unsigned char *key, uint32_t keylen, const unsigned char *input, uint32_t ilen, unsigned char output[32], int32_t is224 );

/** @} */

/*****************************************************************************/
/** @addtogroup sha512       SHA384 / SHA512
 *  @ingroup crypto
 *
 * SHA384 and SHA512 hashing functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * Hash data using the SHA384 or SHA512 algorithm
 *
 * @param input_data  buffer holding the  data
 * @param input_len   length of the input data in bytes
 * @param output      receives the 64 byte SHA-384/512 hash of the supplied data
 * @param is384       0 = use SHA512, 1 = use SHA384
 */
void sha4( const unsigned char *input_data, int32_t input_len, unsigned char output[64], int32_t is384 );


/* Use the following functions for non-continguous data */

/**
 * @Start a SHA384 / SHA512 hash
 *
 * @param context  will be used as temporary storage until sha512_hash_final is called
 * @param is384    0 = use SHA512, 1 = use SHA384
 */
void sha4_starts( sha4_context *context, int32_t is384 );

/**
 * Hash a block of data using the SHA384 / SHA512 hash
 *
 * @param context       Initialised with sha4_starts, will be used as temporary storage until sha4_finish is called
 * @param input_data    buffer holding the  data
 * @param input_len     length of the input data
 */
void sha4_update( sha4_context *context, const unsigned char *input_data, int32_t input_len );

/**
 * Finish hashing data using the SHA384 / SHA512 hash
 *
 * @param context       Initialised with sha512_hash_init, filled with sha512_hash_update. No longer used after call to this function
 * @param hash_output   receives the 64 byte SHA-384/512 hash of the supplied data
 */
void sha4_finish( sha4_context *context, unsigned char hash_output[64] );

/**
 * Calculate a SHA384 / SHA512 Hash-based Message Authentication Code (HMAC)
 *
 * @param key           HMAC secret key
 * @param key_len       length of the HMAC key
 * @param input_data    buffer holding the  data
 * @param input_len     length of the input data
 * @param output        HMAC-SHA-384/512 result
 * @param is384         0 = use SHA512, 1 = use SHA384
 */
void sha4_hmac( const unsigned char *key, int32_t key_len,
                const unsigned char *input_data, int32_t input_len,
                unsigned char output[64], int32_t is384 );


/* Use the following functions for non-continguous data */

/**
 * SHA-384/SHA-512 HMAC context setup
 *
 * @param context  HMAC context to be initialized
 * @param is384    0 = use SHA512, 1 = use SHA384
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 */
void sha4_hmac_starts( sha4_context *context, const unsigned char *key, int32_t keylen, int32_t is384 );

/**
 * SHA-384/SHA-512 HMAC process buffer
 *
 * @param context  HMAC context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void sha4_hmac_update( sha4_context *context, const unsigned char *input, int32_t ilen );

/**
 * SHA-384/SHA-512 HMAC final digest
 *
 * @param context  HMAC context
 * @param output   SHA-384/512 HMAC checksum result
 */
void sha4_hmac_finish( sha4_context *context, unsigned char output[64] );


/*
 * @brief          HMAC Key Derivation Function for SHA-512 / SHA-384
 *
 * @description    Generates keying material using HKDF.
 *
 * @param salt[in]      The optional salt value (a non-secret random value);
 *                      if not provided (salt == NULL), it is set internally
 *                      to a string of HashLen(whichSha) zeros.
 * @param salt_len[in]  The length of the salt value.  (Ignored if salt == NULL.)
 * @param ikm[in]       Input keying material.
 * @param ikm_len[in]   The length of the input keying material.
 * @param info[in]      The optional context and application specific information.
 *                      If info == NULL or a zero-length string, it is ignored.
 * @param info_len[in]  The length of the optional context and application specific
 *                      information.  (Ignored if info == NULL.)
 * @param okm[out]      Where the HKDF is to be stored.
 * @param okm_len[in]   The length of the buffer to hold okm.
 *                      okm_len must be <= 255 * USHABlockSize(whichSha)
 * @param is384         0 = use SHA512, 1 = use SHA384
 *
 * @return              0 = success
 *
 */
int sha4_hkdf(
    const unsigned char *salt, int salt_len,
    const unsigned char *ikm, int ikm_len,
    const unsigned char *info, int info_len,
    uint8_t okm[ ], int okm_len,
    int32_t is384);


/** @} */

/*****************************************************************************/
/** @addtogroup Poly1305       Poly1305
 *  @ingroup crypto
 *
 * Poly1305 Message-Authentication Code (MAC) functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 *  Get the poly1305 Message-Authentication code for a buffer of message data
 *  The Key MUST ONLY BE USED ONCE ONLY
 *  The sender MUST NOT use poly1305_auth to authenticate
 *  more than one message under the same key. Authenticators
 *  for two messages under the same key should be expected
 *  to reveal enough information to allow forgeries of
 *  authenticators on other messages.
 *
 *  @param mac           the output message-authentication code
 *  @param message_data  the message data to be processed through the authenticator
 *  @param bytes         number of bytes of message data to read
 *  @param key           the UNIQUE 32 byte key to be used for this session
 */
void poly1305_auth   ( unsigned char mac[16], const unsigned char *message_data, size_t bytes, const unsigned char key[32]);



/*  Use these functions for processing non-contiguous data */

/**
 *  Initialise a poly1305 session with a key.
 *  The Key MUST ONLY BE USED ONCE ONLY
 *  The sender MUST NOT use poly1305_auth to authenticate
 *  more than one message under the same key. Authenticators
 *  for two messages under the same key should be expected
 *  to reveal enough information to allow forgeries of
 *  authenticators on other messages.
 *
 *  @param context a poly1305_context which will be used for scratch space
 *                 until poly1305_finish is called
 *  @param key     the UNIQUE 32 byte key to be used for this session
 */
void poly1305_init   ( poly1305_context *context, const unsigned char key[32]);

/**
 *  Process message data through poly1305 authenticator
 *
 *  @param context       a poly1305_context which has been initialised with poly1305_init
 *                       and will be used for scratch space until poly1305_finish is called
 *  @param message_data  the message data to be processed through the authenticator
 *  @param bytes         number of bytes of message data to read
 */
void poly1305_update ( poly1305_context *context, const unsigned char *message_data, size_t bytes);

/**
 *  Finish processing a poly1305 authenticator session
 *
 *  @param context       a poly1305_context which has been filled via poly1305_init and
 *                       poly1305_update. Will not be be used subsequently.
 *  @param mac           the output message-authentication code
 */
void poly1305_finish ( poly1305_context *context, unsigned char mac[16]);


/**
 *  Verify that two Message-Authentication Codes match
 *
 *  @param mac1  the second message-authentication code
 *  @param mac2  the second message-authentication code
 *
 *  @return  1 if mac1 matches mac2,    0 otherwise
 */
int poly1305_verify(const unsigned char mac1[16], const unsigned char mac2[16]);

/** @} */

/*****************************************************************************/
/** @addtogroup chacha       ChaCha
 *  @ingroup crypto
 *
 * ChaCha cipher functions
 *
 *  @{
 */
/*****************************************************************************/


/**
 * Initialise ChaCha context with a key
 *
 * @param context  A chacha_context_t that will be used as temporary storage whilst performing ChaCha calculations
 * @param key      The key data - must be either 256 bits (32 bytes) or 128 bits (16 bytes) in length
 * @param key_bits The length of the key - must be either 256 or 128
 */
extern void chacha_keysetup       ( chacha_context_t *context, const uint8_t *key, uint32_t key_bits );

/**
 * Add an initial value to a ChaCha context
 *
 * @param context       A chacha_context_t that has been initialised with chacha_keysetup
 * @param initial_value The initial value data - 8 bytes
 */
extern void chacha_ivsetup        ( chacha_context_t *context, const uint8_t *initial_value );

/**
 * Add an nonce initial value to a ChaCha20 block context
 *
 * @param context       A chacha_context_t that has been initialised with chacha_keysetup
 * @param nonce         The initial value data - 12 bytes
 * @param block_count   The sequence number
 */
extern void chacha20_block_ivsetup( chacha_context_t *context, const uint8_t nonce[12], uint32_t block_count );

/**
 * Add an nonce initial value to a ChaCha20 TLS context
 *
 * @param context       A chacha_context_t that has been initialised with chacha_keysetup
 * @param nonce         The initial value data - 8 bytes
 * @param block_count   The sequence number
 */
extern void chacha20_tls_ivsetup( chacha_context_t *context, const uint8_t nonce[8], uint64_t block_count );

/**
 * Encrypt data with the ChaCha Cipher
 *
 * @param context    A chacha_context_t that has been initialised with chacha_keysetup
 * @param plaintext  The plaintext data to be encoded.
 * @param ciphertext Receives the output encrypted data
 * @param bytes      Size in bytes of the plaintext (and encrypted) data
 * @param rounds     Number of encryption loops to perform e.g. ChaCha20 = 20 rounds
 */
extern void chacha_encrypt_bytes  ( chacha_context_t *context, const uint8_t *plaintext, uint8_t *ciphertext, uint32_t bytes, uint8_t rounds);

/**
 * Decrypt data with the ChaCha Cipher
 *
 * @param context    A chacha_context_t that has been initialised with chacha_keysetup
 * @param ciphertext The encrypted data to be decrypted.
 * @param plaintext  Receives the output plaintext data
 * @param bytes      Size in bytes of the encrypted (and plaintext) data
 * @param rounds     Number of encryption loops to perform e.g. ChaCha20 = 20 rounds
 */
extern void chacha_decrypt_bytes  ( chacha_context_t *context, const uint8_t *ciphertext, uint8_t *plaintext, uint32_t bytes, uint8_t rounds );

/**
 * Generates a stream that can be used for key material using the chacha cipher
 *
 * @param context    A chacha_context_t that has been initialised with chacha_keysetup
 * @param stream     The buffer that will receive the key stream data
 * @param bytes      The number of bytes of keystream data to write to the buffer
 * @param rounds     Number of encryption loops to perform e.g. ChaCha20 = 20 rounds
 */
extern void chacha_keystream_bytes( chacha_context_t *context, uint8_t *stream, uint32_t bytes, uint8_t rounds );

/**
 * Pseudo-random key generator using the ChaCha20 Cipher
 *
 * As per section 2.3 of draft-nir-cfrg-chacha20-poly1305-05
 *
 * @param key           A 256 bit chacha key
 * @param nonce         A 96 bit nonce - THIS MUST NEVER BE REUSED WITH THE SAME KEY
 * @param block_count   Sequence number
 * @param output_random The buffer that will receive the 64 bit random data
 */
extern void chacha20_block_function( const uint8_t key[32],
                                     const uint8_t nonce[12],
                                     uint32_t block_count,
                                     uint8_t output_random[64] );


/**
 * Encrypt / Decrypt using ChaCha20-Poly1305 AEAD  (IETF CFRG version)
 *
 * @param key                                    The 256 bit key
 * @param fixed_common_value                     32 bit fixed value for nonce
 * @param non_repeating_initial_value            initial value for nonce
 *                                               THIS VALUE MUST *NEVER* BE REPEATED FOR THE SAME
 *                                               KEY. USE A COUNTER IF POSSIBLE.
 * @param additional_authenticated_data          Additional data (non encrypted) to be authenticated in tag
 * @param additional_authenticated_data_length   The length of the additional data in bytes
 * @param input_crypt_data                       The data to be encrypted/decrypted
 * @param crypt_data_length                      Length of the data being encrypted/decrypted
 * @param output_crypt_data                      The output encrypted or decrypted data.
 * @param output_tag                             The authentication tag calculated for the data
 */
extern void chacha20_poly1305_aead_irtf_cfrg(
        const uint8_t                       key[32],
        const uint8_t                       fixed_common_value[4],
        const uint8_t                       non_repeating_initial_value[8],
        const uint8_t*                      additional_authenticated_data,
        uint64_t                            additional_authenticated_data_length,
        const uint8_t*                      input_crypt_data,
        uint64_t                            crypt_data_length,
        uint8_t*                            output_crypt_data,
        uint8_t                             output_tag[16] );

/**
 * Encrypt using ChaCha20-Poly1305 AEAD (TLS version)
 *
 * @param key                                    The 256 bit key
 * @param nonce                                  8 byte nonce
 * @param additional_authenticated_data          Additional data (non encrypted) to be authenticated in tag
 * @param additional_authenticated_data_length   The length of the additional data in bytes
 * @param input_crypt_data                       The data to be encrypted
 * @param crypt_data_length                      Length of the data being encrypted/decrypted
 * @param output_crypt_data                      The output encrypted or decrypted data.
 * @param output_tag                             The authentication tag calculated for the data
 */
void chacha20_poly1305_aead_tls_encrypt(
        const uint8_t                       key[32],
        const uint8_t                       nonce[8],
        const uint8_t*                      additional_authenticated_data,
        uint64_t                            additional_authenticated_data_length,
        const uint8_t*                      input_crypt_data,
        uint64_t                            crypt_data_length,
        uint8_t*                            output_crypt_data,   /* length is same as input_crypt_data */
        uint8_t                             output_tag[16] );

/** @} */

/**
 * Decrypt using ChaCha20-Poly1305 AEAD (TLS version)
 *
 * @param key                                    The 256 bit key
 * @param nonce                                  8 byte nonce
 * @param additional_authenticated_data          Additional data (non encrypted) to be authenticated in tag
 * @param additional_authenticated_data_length   The length of the additional data in bytes
 * @param input_crypt_data                       The data to be decrypted
 * @param crypt_data_length                      Length of the data being encrypted/decrypted
 * @param output_crypt_data                      The output encrypted or decrypted data.
 * @param output_tag                             The authentication tag calculated for the data
 */
void chacha20_poly1305_aead_tls_decrypt(
        const uint8_t                       key[32],
        const uint8_t                       nonce[8],
        const uint8_t*                      additional_authenticated_data,
        uint64_t                            additional_authenticated_data_length,
        const uint8_t*                      input_crypt_data,
        uint64_t                            crypt_data_length,
        uint8_t*                            output_crypt_data,   /* length is same as input_crypt_data */
        uint8_t                             output_tag[16] );
/*****************************************************************************/
/** @addtogroup curve25519       Curve25519
 *  @ingroup crypto
 *
 * Curve25519 elliptic curve key generation functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * Calculate a public (shared) key given a basepoint and secret key
 *
 * @param mypublic_output Receives the 32 byte output shared key
 * @param secret          The 32 byte secret key. Must have been randomly
 *                        generated then have the following operations performed
 *                        on it:
 *                               secret[0]  &= 248;
 *                               secret[31] &= 127;
 *                               secret[31] |= 64;
 * @param basepoint       The starting point for the calculation - usually the
 *                        public key of the other party
 *
 * @return 0 when successful
 */
int curve25519( uint8_t *mypublic_output, const uint8_t *secret, const uint8_t *basepoint );

/** @} */

/*****************************************************************************/
/** @addtogroup ed25519       Ed25519
 *  @ingroup crypto
 *
 * Ed25519 digital signature functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * Generate a Ed25519 public key from a secret key
 *
 * @param  secret_key The 32 byte secret key
 * @param  public_key Receives the 32 byte output public key
 */
void ed25519_publickey( const ed25519_secret_key secret_key, ed25519_public_key public_key );


/**
 * Sign a message using Ed25519
 *
 * @param  message_data     The message data to sign
 * @param  message_len      The length in bytes of the message data
 * @param  secret_key       The 32 byte secret key
 * @param  public_key       The 32 byte public key
 * @param  signature_output Receives the 64 byte output signature
 */
void ed25519_sign( const unsigned char *message_data, size_t message_len, const ed25519_secret_key secret_key, const ed25519_public_key public_key, ed25519_signature signature_output );

/**
 * Verify an Ed25519 message signature
 *
 * @param  message_data     The message data to verify
 * @param  message_len      The length in bytes of the message data
 * @param  public_key       The 32 byte public key
 * @param  signature Receives the 64 byte output signature
 *
 * @return 0 if signature matches
 */
int ed25519_sign_open( const unsigned char *message_data, size_t message_len, const ed25519_public_key public_key, const ed25519_signature signature);


/** @} */

/*****************************************************************************/
/** @addtogroup md5       MD5
 *  @ingroup crypto
 *
 * MD5 functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          MD5 context setup
 *
 * @param ctx      context to be initialized
 */
void md5_starts( md5_context *ctx );

/**
 * @brief          MD5 process buffer
 *
 * @param ctx      MD5 context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void md5_update( md5_context *ctx, const unsigned char *input, int32_t ilen );

/**
 * @brief          MD5 final digest
 *
 * @param ctx      MD5 context
 * @param output   MD5 checksum result
 */
void md5_finish( md5_context *ctx, unsigned char output[16] );

/**
 * @brief          Output = MD5( input buffer )
 *
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   MD5 checksum result
 */
void md5( const unsigned char *input, int32_t ilen, unsigned char output[16] );

/**
 * @brief          MD5 HMAC context setup
 *
 * @param ctx      HMAC context to be initialized
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 */
void md5_hmac_starts( md5_context *ctx, const unsigned char *key, uint32_t keylen );

/**
 * @brief          MD5 HMAC process buffer
 *
 * @param ctx      HMAC context
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 */
void md5_hmac_update( md5_context *ctx, const unsigned char *input, uint32_t ilen );

/**
 * @brief          MD5 HMAC final digest
 *
 * @param ctx      HMAC context
 * @param output   MD5 HMAC checksum result
 */
void md5_hmac_finish( md5_context *ctx, unsigned char output[16] );

/**
 * @brief          Output = HMAC-MD5( hmac key, input buffer )
 *
 * @param key      HMAC secret key
 * @param keylen   length of the HMAC key
 * @param input    buffer holding the  data
 * @param ilen     length of the input data
 * @param output   HMAC-MD5 result
 */
void md5_hmac( const unsigned char *key, int32_t keylen, const unsigned char *input, int32_t ilen, unsigned char output[16] );

/** @} */

/*****************************************************************************/
/** @addtogroup arc4       ARC4
 *  @ingroup crypto
 *
 * ARC4 functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          ARC4 key schedule
 *
 * @param ctx      ARC4 context to be initialized
 * @param key      the secret key
 * @param keylen   length of the key in bits
 */
void arc4_setup( arc4_context *ctx, const unsigned char *key, int32_t keylen_bits );

/**
 * @brief          ARC4 cipher function
 *
 * @param ctx      ARC4 context
 * @param buf      buffer to be processed
 * @param buflen   amount of data in buf
 */
void arc4_crypt( arc4_context *ctx, unsigned char *buf, int32_t buflen );

/** @} */

/*****************************************************************************/
/** @addtogroup rsa       RSA
 *  @ingroup crypto
 *
 * RSA functions
 *
 *  @{
 */
/*****************************************************************************/


/**
 * @brief          Initialize an RSA context
 *
 * @param ctx      RSA context to be initialized
 * @param padding  RSA_PKCS_V15 or RSA_PKCS_V21
 * @param hash_id  RSA_PKCS_V21 hash identifier
 * @param f_rng    RNG function
 * @param p_rng    RNG parameter
 *
 * @note           The hash_id parameter is actually ignored when using RSA_PKCS_V15 padding.
 * @note           RSA_PKCS_V21 padding is not supported.
 */
void rsa_init( rsa_context *ctx, int32_t padding, int32_t hash_id, int32_t (*f_rng)( void * ), void *p_rng );

/**
 * @brief          Generate an RSA keypair
 *
 * @param ctx      RSA context that will hold the key
 * @param nbits    size of the public key in bits
 * @param exponent public exponent (e.g., 65537)
 *
 * @note           rsa_init() must be called beforehand to setup the RSA context (especially f_rng and p_rng).
 *
 * @return         0 if successful
 */
int32_t rsa_gen_key( rsa_context *ctx, int32_t nbits, int32_t exponent );

/**
 * @brief          Check a public RSA key
 *
 * @param ctx      RSA context to be checked
 *
 * @return         0 if successful
 */
int32_t rsa_check_pubkey( rsa_context *ctx );

/**
 * @brief          Check a private RSA key
 *
 * @param ctx      RSA context to be checked
 *
 * @return         0 if successful
 */
int32_t rsa_check_privkey( rsa_context *ctx );

/**
 * @brief          Do an RSA public key operation
 *
 * @param ctx      RSA context
 * @param input    input buffer
 * @param output   output buffer
 *
 * @return         0 if successful
 *
 * @note           This function does NOT take care of message padding. Also, be sure to set input[0] = 0.
 * @note           The input and output buffers must be large enough (eg. 128 bytes if RSA-1024 is used).
 */
int32_t rsa_public( rsa_context *ctx, const unsigned char *input, unsigned char *output );

/**
 * @brief          Do an RSA private key operation
 *
 * @param ctx      RSA context
 * @param input    input buffer
 * @param output   output buffer
 *
 * @return         0 if successful
 *
 * @note           The input and output buffers must be large enough (eg. 128 bytes if RSA-1024 is used).
 */
int32_t rsa_private( rsa_context *ctx, const unsigned char *input, unsigned char *output );

/**
 * @brief          Add the message padding, then do an RSA operation
 *
 * @param ctx      RSA context
 * @param mode     RSA_PUBLIC or RSA_PRIVATE
 * @param ilen     contains the the plaintext length
 * @param input    buffer holding the data to be encrypted
 * @param output   buffer that will hold the ciphertext
 *
 * @return         0 if successful
 *
 * @note           The output buffer must be as large as the size of ctx->N (eg. 128 bytes if RSA-1024 is used).
 */
int32_t rsa_pkcs1_encrypt( rsa_context *ctx, int32_t mode, int32_t ilen, const unsigned char *input, unsigned char *output );

/**
 * @brief          Do an RSA operation, then remove the message padding
 *
 * @param ctx      RSA context
 * @param mode     RSA_PUBLIC or RSA_PRIVATE
 * @param input    buffer holding the encrypted data
 * @param output   buffer that will hold the plaintext
 * @param olen     will contain the plaintext length
 * @param output_max_len    maximum length of the output buffer
 *
 * @return         0 if successful
 *
 * @note           The output buffer must be as large as the size of ctx->N (eg. 128 bytes if RSA-1024 is used)
 */
int32_t rsa_pkcs1_decrypt( rsa_context *ctx, int32_t mode, int32_t *olen, const unsigned char *input, unsigned char *output, int32_t output_max_len );

/**
 * @brief          Do a private RSA to sign a message digest
 *
 * @param ctx      RSA context
 * @param mode     RSA_PUBLIC or RSA_PRIVATE
 * @param hash_id  RSA_RAW, RSA_MD{2,4,5} or RSA_SHA{1,256}
 * @param hashlen  message digest length (for RSA_RAW only)
 * @param hash     buffer holding the message digest
 * @param sig      buffer that will hold the ciphertext
 *
 * @return         0 if the signing operation was successful
 *
 * @note           The "sig" buffer must be as large as the size of ctx->N (eg. 128 bytes if RSA-1024 is used).
 */
int32_t rsa_pkcs1_sign( rsa_context *ctx, int32_t mode, int32_t hash_id, int32_t hashlen, const unsigned char *hash, unsigned char *sig );

/**
 * @brief          Do a public RSA and check the message digest
 *
 * @param ctx      points to an RSA public key
 * @param mode     RSA_PUBLIC or RSA_PRIVATE
 * @param hash_id  RSA_RAW, RSA_MD{2,4,5} or RSA_SHA{1,256}
 * @param hashlen  message digest length (for RSA_RAW only)
 * @param hash     buffer holding the message digest
 * @param sig      buffer holding the ciphertext
 *
 * @return         0 if the verify operation was successful
 *
 * @note           The "sig" buffer must be as large as the size of ctx->N (eg. 128 bytes if RSA-1024 is used).
 */
int32_t rsa_pkcs1_verify( rsa_context *ctx, int32_t mode, int32_t hash_id, int32_t hashlen, const unsigned char *hash, const unsigned char *sig );

/**
 * @brief          Free the components of an RSA key
 */
void rsa_free( rsa_context *ctx );


/** @} */


/*****************************************************************************/
/** @addtogroup Camellia       Camellia
 *  @ingroup crypto
 *
 * Camellia cipher functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          CAMELLIA key schedule (encryption)
 *
 * @param ctx      CAMELLIA context to be initialized
 * @param key      encryption key
 * @param keysize  must be 128, 192 or 256
 */
void camellia_setkey_enc(camellia_context * ctx, const unsigned char *key,
             int keysize);

/**
 * @brief          CAMELLIA key schedule (decryption)
 *
 * @param ctx      CAMELLIA context to be initialized
 * @param key      decryption key
 * @param keysize  must be 128, 192 or 256
 */
void camellia_setkey_dec(camellia_context * ctx, const unsigned char *key,
             int keysize);

/**
 * @brief          CAMELLIA-ECB block encryption/decryption
 *
 * @param ctx      CAMELLIA context
 * @param mode     CAMELLIA_ENCRYPT or CAMELLIA_DECRYPT
 * @param input    16-byte input block
 * @param output   16-byte output block
 */
void camellia_crypt_ecb(camellia_context * ctx,
            int mode,
            const unsigned char input[16],
            unsigned char output[16]);

/**
 * @brief          CAMELLIA-CBC buffer encryption/decryption
 *
 * @param ctx      CAMELLIA context
 * @param mode     CAMELLIA_ENCRYPT or CAMELLIA_DECRYPT
 * @param length   length of the input data
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer holding the output data
 */
void camellia_crypt_cbc(camellia_context * ctx,
            int mode,
            int length,
            unsigned char iv[16],
            const unsigned char *input, unsigned char *output);

/**
 * @brief          CAMELLIA-CFB128 buffer encryption/decryption
 *
 * @param ctx      CAMELLIA context
 * @param mode     CAMELLIA_ENCRYPT or CAMELLIA_DECRYPT
 * @param length   length of the input data
 * @param iv_off   offset in IV (updated after use)
 * @param iv       initialization vector (updated after use)
 * @param input    buffer holding the input data
 * @param output   buffer holding the output data
 */
void camellia_crypt_cfb128(camellia_context * ctx,
               int mode,
               int length,
               int *iv_off,
               unsigned char iv[16],
               const unsigned char *input, unsigned char *output);


/** @} */



/*****************************************************************************/
/** @addtogroup SEED       SEED
 *  @ingroup crypto
 *
 * SEED cipher functions
 *
 *  @{
 */
/*****************************************************************************/

/**
 * @brief          Set SEED key
 *
 * @param rawkey   encryption key
 * @param ctx      SEED context to be initialized
 */
void seed_set_key(const unsigned char rawkey[16], seed_context_t *ks);

/**
 * @brief          SEED-CBC buffer encryption
 *
 * @param ctx      SEED context
 * @param ivec     initialization vector (updated after use)
 * @param in       buffer holding the input data
 * @param len      length of the input data
 * @param out      buffer that receives the output data
 */
void seed_cbc_encrypt(const seed_context_t* ctx, uint8_t ivec[16], const uint8_t *in, uint32_t len, uint8_t *out);

/**
 * @brief          SEED-CBC buffer decryption
 *
 * @param ctx      SEED context
 * @param ivec     initialization vector (updated after use)
 * @param in       buffer holding the input data
 * @param len      length of the input data
 * @param out      buffer that receives the output data
 */
void seed_cbc_decrypt(const seed_context_t* ctx, uint8_t ivec[16], const uint8_t *in, uint32_t len, uint8_t *out);


/** @} */

#ifdef __cplusplus
} /*extern "C" */
#endif
