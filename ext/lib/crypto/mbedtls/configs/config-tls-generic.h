/*
 * Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 * Copyright (c) 2017 Intel Corporation.
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Generic configuration for TLS, manageable by Kconfig.
 */

#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* System support */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#define MBEDTLS_PLATFORM_EXIT_ALT
#define MBEDTLS_NO_PLATFORM_ENTROPY
#define MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES
#define MBEDTLS_PLATFORM_PRINTF_ALT

#if !defined(CONFIG_ARM)
#define MBEDTLS_HAVE_ASM
#endif

#if defined(CONFIG_MBEDTLS_TEST)
#define MBEDTLS_SELF_TEST
#define MBEDTLS_DEBUG_C
#endif

/* mbedTLS feature support */

/* Supported TLS versions */
#if defined(CONFIG_TLS_VERSION_1_0)
#define MBEDTLS_SSL_PROTO_TLS1
#endif

#if defined(CONFIG_TLS_VERSION_1_1)
#define MBEDTLS_SSL_PROTO_TLS1_1
#endif

#if defined(CONFIG_TLS_VERSION_1_2)
#define MBEDTLS_SSL_PROTO_TLS1_2
#endif


#if defined(CONFIG_TLS_VERSION_1_0) || \
    defined(CONFIG_TLS_VERSION_1_1) || \
    defined(CONFIG_TLS_VERSION_1_2)

/* Modules required for TLS */
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_SSL_SRV_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_MD_C
#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH

#endif

#if defined(CONFIG_TLS_DTLS)
#define MBEDTLS_SSL_PROTO_DTLS
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY
#define MBEDTLS_SSL_COOKIE_C
#endif

/* Supported key exchange methods */

#if defined(CONFIG_TLS_KEY_EXCHANGE_PSK_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_RSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECDH_RSA_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED
#endif

#if defined(CONFIG_TLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#define MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED
#endif

/* Supported cipher modes */

#if defined(CONFIG_TLS_CIPHER_AES_ENABLED)
#define MBEDTLS_AES_C
#endif

#if defined(CONFIG_TLS_CIPHER_CAMELLIA_ENABLED)
#define MBEDTLS_CAMELLIA_C
#endif

#if defined(CONFIG_TLS_CIPHER_DES_ENABLED)
#define MBEDTLS_DES_C
#endif

#if defined(CONFIG_TLS_CIPHER_CCM_ENABLED)
#define MBEDTLS_CCM_C
#endif

#if defined(CONFIG_TLS_CIPHER_CBC_ENABLED)
#define MBEDTLS_CIPHER_MODE_CBC
#endif

/* Supported elliptic curves */

#if defined(CONFIG_TLS_ECP_DP_SECP192R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP192R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP224R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP224R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP256R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP384R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP521R1_ENABLED)
#define MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP192K1_ENABLED)
#define MBEDTLS_ECP_DP_SECP192K1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP224K1_ENABLED)
#define MBEDTLS_ECP_DP_SECP224K1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_SECP256K1_ENABLED)
#define MBEDTLS_ECP_DP_SECP256K1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_BP256R1_ENABLED)
#define MBEDTLS_ECP_DP_BP256R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_BP384R1_ENABLED)
#define MBEDTLS_ECP_DP_BP384R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_BP512R1_ENABLED)
#define MBEDTLS_ECP_DP_BP512R1_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_CURVE25519_ENABLED)
#define MBEDTLS_ECP_DP_CURVE25519_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_DP_CURVE448_ENABLED)
#define MBEDTLS_ECP_DP_CURVE448_ENABLED
#endif

#if defined(CONFIG_TLS_ECP_NIST_OPTIM)
#define MBEDTLS_ECP_NIST_OPTIM
#endif

/* Supported message authentication methods */

#if defined(CONFIG_TLS_MAC_MD5_ENABLED)
#define MBEDTLS_MD5_C
#endif

#if defined(CONFIG_TLS_MAC_SHA1_ENABLED)
#define MBEDTLS_SHA1_C
#endif

#if defined(CONFIG_TLS_MAC_SHA256_ENABLED)
#define MBEDTLS_SHA256_C
#endif

#if defined(CONFIG_TLS_MAC_SHA512_ENABLED)
#define MBEDTLS_SHA512_C
#endif

/* Automatic dependencies */

#if defined (MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#define MBEDTLS_DHM_C
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED)
#define MBEDTLS_ECDH_C
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#define MBEDTLS_RSA_C
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#define MBEDTLS_PKCS1_V15
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED)
#define MBEDTLS_X509_CRT_PARSE_C
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED)
#define MBEDTLS_ECDSA_C
#endif

#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#define MBEDTLS_ECJPAKE_C
#endif

#if defined(MBEDTLS_ECDH_C) || \
    defined(MBEDTLS_ECDSA_C) || \
    defined(MBEDTLS_ECJPAKE_C)
#define MBEDTLS_ECP_C
#endif

#if defined(MBEDTLS_X509_CRT_PARSE_C)
#define MBEDTLS_X509_USE_C
#endif

#if defined(MBEDTLS_X509_USE_C) || \
    defined(MBEDTLS_ECDSA_C)
#define MBEDTLS_ASN1_PARSE_C
#endif

#if defined(MBEDTLS_ECDSA_C)
#define MBEDTLS_ASN1_WRITE_C
#endif

#if defined(MBEDTLS_DHM_C) || \
    defined(MBEDTLS_ECP_C) || \
    defined(MBEDTLS_RSA_C) || \
    defined(MBEDTLS_X509_USE_C)
#define MBEDTLS_BIGNUM_C
#endif

#if defined(MBEDTLS_RSA_C) || \
    defined(MBEDTLS_X509_USE_C)
#define MBEDTLS_OID_C
#endif

#if defined(MBEDTLS_X509_USE_C)
#define MBEDTLS_PK_PARSE_C
#endif

#if defined(MBEDTLS_PK_PARSE_C)
#define MBEDTLS_PK_C
#endif

/* mbedTLS modules */
#if defined (CONFIG_TLS_PEM_CERTIFICATE_FORMAT) && \
    defined(MBEDTLS_X509_CRT_PARSE_C)
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_BASE64_C
#endif

#if defined(MBEDTLS_AES_C)
#define MBEDTLS_CTR_DRBG_C
#endif

#if defined(MBEDTLS_SHA256_C) || defined(MBEDTLS_SHA512_C)
#define MBEDTLS_ENTROPY_C
#endif

/* For test certificates */
#if defined(MBEDTLS_RSA_C) || defined(MBEDTLS_ECDSA_C)
#define MBEDTLS_CERTS_C
#endif

#if defined(CONFIG_MBEDTLS_DEBUG)
#define MBEDTLS_ERROR_C
#define MBEDTLS_DEBUG_C
#define MBEDTLS_SSL_DEBUG_ALL
#define MBEDTLS_SSL_ALL_ALERT_MESSAGES
#endif

#define MBEDTLS_SSL_MAX_CONTENT_LEN  CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN

/* User config file */

#if defined(CONFIG_TLS_USER_CONFIG_ENABLE)
#include CONFIG_TLS_USER_CONFIG_FILE
#endif

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
