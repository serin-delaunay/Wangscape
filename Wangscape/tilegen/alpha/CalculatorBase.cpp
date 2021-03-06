#include "CalculatorBase.h"
#include <algorithm>
#include "common.h"

namespace tilegen
{
namespace alpha
{

CalculatorBase::CalculatorBase():
    mAlphas((int)CORNERS)
{
    zeroAlphas();
}

void CalculatorBase::zeroAlphas()
{
    for (auto& alpha : mAlphas)
        alpha = 0;
}

sf::Uint8 & CalculatorBase::getAlpha(size_t index)
{
    return mAlphas[index];
}

const CalculatorBase::Alphas & CalculatorBase::getAlphas() const
{
    return mAlphas;
}

void CalculatorBase::updateAlphas(const Weights & weights)
{
    zeroAlphas();
    updateAlphasAux(weights);
}

} // namespace alpha
} // namespace tilegen
