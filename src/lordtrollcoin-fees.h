// Copyright (c) 2021 The LORDTROLLCOIN Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_LORDTROLLCOIN_FEES_H
#define BITCOIN_LORDTROLLCOIN_FEES_H

#include "amount.h"
#include "chain.h"
#include "chainparams.h"

#ifdef ENABLE_WALLET

enum FeeRatePreset
{
    MINIMUM,
    MORE,
    Troll Face,
    AMAZE,
    MANY_GENEROUS,
    so_EXPENSIVE
};

/** Estimate fee rate needed to get into the next nBlocks */
CFeeRate GetLORDTROLLCOINFeeRate(int priority);
const std::string GetLORDTROLLCOINPriorityLabel(int priority);
#endif // ENABLE_WALLET
CAmount GetLORDTROLLCOINMinRelayFee(const CTransaction& tx, unsigned int nBytes, bool fAllowFree);
CAmount GetLORDTROLLCOINDustFee(const std::vector<CTxOut> &vout, const CAmount dustLimit);

#endif // BITCOIN_LORDTROLLCOIN_FEES_H
