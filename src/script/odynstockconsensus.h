// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ODYNSTOCK_ODYNSTOCKCONSENSUS_H
#define ODYNSTOCK_ODYNSTOCKCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_ODYNSTOCK_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/odynstock-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBODYNSTOCKCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ODYNSTOCKCONSENSUS_API_VER 1

typedef enum odynstockconsensus_error_t
{
    odynstockconsensus_ERR_OK = 0,
    odynstockconsensus_ERR_TX_INDEX,
    odynstockconsensus_ERR_TX_SIZE_MISMATCH,
    odynstockconsensus_ERR_TX_DESERIALIZE,
    odynstockconsensus_ERR_AMOUNT_REQUIRED,
} odynstockconsensus_error;

/** Script verification flags */
enum
{
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    odynstockconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int odynstockconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, odynstockconsensus_error* err);

EXPORT_SYMBOL int odynstockconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, odynstockconsensus_error* err);

EXPORT_SYMBOL unsigned int odynstockconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // ODYNSTOCK_ODYNSTOCKCONSENSUS_H
