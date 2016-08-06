/*
 * FourierBasisTest.cpp
 *
 *  Created on: Aug 5, 2016
 *      Author: sabeyruw
 */

#include "FourierBasisTest.h"

RLLIB_TEST_MAKE(FourierBasisTest)

void FourierBasisTest::testFourierBasis1()
{
  const int nbInputs = 2;
  const int order = 3;
  std::vector<std::vector<double>> expected = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 0.0, 2.0 },
      { 0.0, 3.0 }, { 1.0, 0.0 }, { 1.0, 1.0 }, { 1.0, 2.0 }, { 1.0, 3.0 }, { 2.0, 0.0 },
      { 2.0, 1.0 }, { 2.0, 2.0 }, { 2.0, 3.0 }, { 3.0, 0.0 }, { 3.0, 1.0 }, { 3.0, 2.0 },
      { 3.0, 3.0 } };

  FourierCoefficientGenerator<double>* generator = new FullFourierCoefficientGenerator<double>();
  std::vector<Vector<double>*> multipliers;
  generator->computeFourierCoefficients(multipliers, nbInputs, order);

  ASSERT(static_cast<int>(multipliers.size()) == std::pow(order + 1, nbInputs));

  for (size_t i = 0; i < multipliers.size(); i++)
  {
    for (int k = 0; k < nbInputs; k++)
    {
      ASSERT(expected[i][k] == multipliers[i]->getEntry(k));
      std::cout << multipliers[i]->getEntry(k) << " ";
    }
    std::cout << std::endl;
  }

  for (auto iter = multipliers.begin(); iter != multipliers.end(); ++iter)
  {
    delete *iter;
  }
  delete generator;
}

void FourierBasisTest::testFourierBasis2()
{
  const int nbInputs = 4;
  const int order = 3;

  std::vector<std::vector<double>> expected =
      { { 0.0, 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0, 1.0 }, { 0.0, 0.0, 0.0, 2.0 },
          { 0.0, 0.0, 0.0, 3.0 }, { 0.0, 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0, 1.0 }, { 0.0, 0.0, 1.0,
              2.0 }, { 0.0, 0.0, 1.0, 3.0 }, { 0.0, 0.0, 2.0, 0.0 }, { 0.0, 0.0, 2.0, 1.0 }, { 0.0,
              0.0, 2.0, 2.0 }, { 0.0, 0.0, 2.0, 3.0 }, { 0.0, 0.0, 3.0, 0.0 },
          { 0.0, 0.0, 3.0, 1.0 }, { 0.0, 0.0, 3.0, 2.0 }, { 0.0, 0.0, 3.0, 3.0 }, { 0.0, 1.0, 0.0,
              0.0 }, { 0.0, 1.0, 0.0, 1.0 }, { 0.0, 1.0, 0.0, 2.0 }, { 0.0, 1.0, 0.0, 3.0 }, { 0.0,
              1.0, 1.0, 0.0 }, { 0.0, 1.0, 1.0, 1.0 }, { 0.0, 1.0, 1.0, 2.0 },
          { 0.0, 1.0, 1.0, 3.0 }, { 0.0, 1.0, 2.0, 0.0 }, { 0.0, 1.0, 2.0, 1.0 }, { 0.0, 1.0, 2.0,
              2.0 }, { 0.0, 1.0, 2.0, 3.0 }, { 0.0, 1.0, 3.0, 0.0 }, { 0.0, 1.0, 3.0, 1.0 }, { 0.0,
              1.0, 3.0, 2.0 }, { 0.0, 1.0, 3.0, 3.0 }, { 0.0, 2.0, 0.0, 0.0 },
          { 0.0, 2.0, 0.0, 1.0 }, { 0.0, 2.0, 0.0, 2.0 }, { 0.0, 2.0, 0.0, 3.0 }, { 0.0, 2.0, 1.0,
              0.0 }, { 0.0, 2.0, 1.0, 1.0 }, { 0.0, 2.0, 1.0, 2.0 }, { 0.0, 2.0, 1.0, 3.0 }, { 0.0,
              2.0, 2.0, 0.0 }, { 0.0, 2.0, 2.0, 1.0 }, { 0.0, 2.0, 2.0, 2.0 },
          { 0.0, 2.0, 2.0, 3.0 }, { 0.0, 2.0, 3.0, 0.0 }, { 0.0, 2.0, 3.0, 1.0 }, { 0.0, 2.0, 3.0,
              2.0 }, { 0.0, 2.0, 3.0, 3.0 }, { 0.0, 3.0, 0.0, 0.0 }, { 0.0, 3.0, 0.0, 1.0 }, { 0.0,
              3.0, 0.0, 2.0 }, { 0.0, 3.0, 0.0, 3.0 }, { 0.0, 3.0, 1.0, 0.0 },
          { 0.0, 3.0, 1.0, 1.0 }, { 0.0, 3.0, 1.0, 2.0 }, { 0.0, 3.0, 1.0, 3.0 }, { 0.0, 3.0, 2.0,
              0.0 }, { 0.0, 3.0, 2.0, 1.0 }, { 0.0, 3.0, 2.0, 2.0 }, { 0.0, 3.0, 2.0, 3.0 }, { 0.0,
              3.0, 3.0, 0.0 }, { 0.0, 3.0, 3.0, 1.0 }, { 0.0, 3.0, 3.0, 2.0 },
          { 0.0, 3.0, 3.0, 3.0 }, { 1.0, 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0, 1.0 }, { 1.0, 0.0, 0.0,
              2.0 }, { 1.0, 0.0, 0.0, 3.0 }, { 1.0, 0.0, 1.0, 0.0 }, { 1.0, 0.0, 1.0, 1.0 }, { 1.0,
              0.0, 1.0, 2.0 }, { 1.0, 0.0, 1.0, 3.0 }, { 1.0, 0.0, 2.0, 0.0 },
          { 1.0, 0.0, 2.0, 1.0 }, { 1.0, 0.0, 2.0, 2.0 }, { 1.0, 0.0, 2.0, 3.0 }, { 1.0, 0.0, 3.0,
              0.0 }, { 1.0, 0.0, 3.0, 1.0 }, { 1.0, 0.0, 3.0, 2.0 }, { 1.0, 0.0, 3.0, 3.0 }, { 1.0,
              1.0, 0.0, 0.0 }, { 1.0, 1.0, 0.0, 1.0 }, { 1.0, 1.0, 0.0, 2.0 },
          { 1.0, 1.0, 0.0, 3.0 }, { 1.0, 1.0, 1.0, 0.0 }, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0,
              2.0 }, { 1.0, 1.0, 1.0, 3.0 }, { 1.0, 1.0, 2.0, 0.0 }, { 1.0, 1.0, 2.0, 1.0 }, { 1.0,
              1.0, 2.0, 2.0 }, { 1.0, 1.0, 2.0, 3.0 }, { 1.0, 1.0, 3.0, 0.0 },
          { 1.0, 1.0, 3.0, 1.0 }, { 1.0, 1.0, 3.0, 2.0 }, { 1.0, 1.0, 3.0, 3.0 }, { 1.0, 2.0, 0.0,
              0.0 }, { 1.0, 2.0, 0.0, 1.0 }, { 1.0, 2.0, 0.0, 2.0 }, { 1.0, 2.0, 0.0, 3.0 }, { 1.0,
              2.0, 1.0, 0.0 }, { 1.0, 2.0, 1.0, 1.0 }, { 1.0, 2.0, 1.0, 2.0 },
          { 1.0, 2.0, 1.0, 3.0 }, { 1.0, 2.0, 2.0, 0.0 }, { 1.0, 2.0, 2.0, 1.0 }, { 1.0, 2.0, 2.0,
              2.0 }, { 1.0, 2.0, 2.0, 3.0 }, { 1.0, 2.0, 3.0, 0.0 }, { 1.0, 2.0, 3.0, 1.0 }, { 1.0,
              2.0, 3.0, 2.0 }, { 1.0, 2.0, 3.0, 3.0 }, { 1.0, 3.0, 0.0, 0.0 },
          { 1.0, 3.0, 0.0, 1.0 }, { 1.0, 3.0, 0.0, 2.0 }, { 1.0, 3.0, 0.0, 3.0 }, { 1.0, 3.0, 1.0,
              0.0 }, { 1.0, 3.0, 1.0, 1.0 }, { 1.0, 3.0, 1.0, 2.0 }, { 1.0, 3.0, 1.0, 3.0 }, { 1.0,
              3.0, 2.0, 0.0 }, { 1.0, 3.0, 2.0, 1.0 }, { 1.0, 3.0, 2.0, 2.0 },
          { 1.0, 3.0, 2.0, 3.0 }, { 1.0, 3.0, 3.0, 0.0 }, { 1.0, 3.0, 3.0, 1.0 }, { 1.0, 3.0, 3.0,
              2.0 }, { 1.0, 3.0, 3.0, 3.0 }, { 2.0, 0.0, 0.0, 0.0 }, { 2.0, 0.0, 0.0, 1.0 }, { 2.0,
              0.0, 0.0, 2.0 }, { 2.0, 0.0, 0.0, 3.0 }, { 2.0, 0.0, 1.0, 0.0 },
          { 2.0, 0.0, 1.0, 1.0 }, { 2.0, 0.0, 1.0, 2.0 }, { 2.0, 0.0, 1.0, 3.0 }, { 2.0, 0.0, 2.0,
              0.0 }, { 2.0, 0.0, 2.0, 1.0 }, { 2.0, 0.0, 2.0, 2.0 }, { 2.0, 0.0, 2.0, 3.0 }, { 2.0,
              0.0, 3.0, 0.0 }, { 2.0, 0.0, 3.0, 1.0 }, { 2.0, 0.0, 3.0, 2.0 },
          { 2.0, 0.0, 3.0, 3.0 }, { 2.0, 1.0, 0.0, 0.0 }, { 2.0, 1.0, 0.0, 1.0 }, { 2.0, 1.0, 0.0,
              2.0 }, { 2.0, 1.0, 0.0, 3.0 }, { 2.0, 1.0, 1.0, 0.0 }, { 2.0, 1.0, 1.0, 1.0 }, { 2.0,
              1.0, 1.0, 2.0 }, { 2.0, 1.0, 1.0, 3.0 }, { 2.0, 1.0, 2.0, 0.0 },
          { 2.0, 1.0, 2.0, 1.0 }, { 2.0, 1.0, 2.0, 2.0 }, { 2.0, 1.0, 2.0, 3.0 }, { 2.0, 1.0, 3.0,
              0.0 }, { 2.0, 1.0, 3.0, 1.0 }, { 2.0, 1.0, 3.0, 2.0 }, { 2.0, 1.0, 3.0, 3.0 }, { 2.0,
              2.0, 0.0, 0.0 }, { 2.0, 2.0, 0.0, 1.0 }, { 2.0, 2.0, 0.0, 2.0 },
          { 2.0, 2.0, 0.0, 3.0 }, { 2.0, 2.0, 1.0, 0.0 }, { 2.0, 2.0, 1.0, 1.0 }, { 2.0, 2.0, 1.0,
              2.0 }, { 2.0, 2.0, 1.0, 3.0 }, { 2.0, 2.0, 2.0, 0.0 }, { 2.0, 2.0, 2.0, 1.0 }, { 2.0,
              2.0, 2.0, 2.0 }, { 2.0, 2.0, 2.0, 3.0 }, { 2.0, 2.0, 3.0, 0.0 },
          { 2.0, 2.0, 3.0, 1.0 }, { 2.0, 2.0, 3.0, 2.0 }, { 2.0, 2.0, 3.0, 3.0 }, { 2.0, 3.0, 0.0,
              0.0 }, { 2.0, 3.0, 0.0, 1.0 }, { 2.0, 3.0, 0.0, 2.0 }, { 2.0, 3.0, 0.0, 3.0 }, { 2.0,
              3.0, 1.0, 0.0 }, { 2.0, 3.0, 1.0, 1.0 }, { 2.0, 3.0, 1.0, 2.0 },
          { 2.0, 3.0, 1.0, 3.0 }, { 2.0, 3.0, 2.0, 0.0 }, { 2.0, 3.0, 2.0, 1.0 }, { 2.0, 3.0, 2.0,
              2.0 }, { 2.0, 3.0, 2.0, 3.0 }, { 2.0, 3.0, 3.0, 0.0 }, { 2.0, 3.0, 3.0, 1.0 }, { 2.0,
              3.0, 3.0, 2.0 }, { 2.0, 3.0, 3.0, 3.0 }, { 3.0, 0.0, 0.0, 0.0 },
          { 3.0, 0.0, 0.0, 1.0 }, { 3.0, 0.0, 0.0, 2.0 }, { 3.0, 0.0, 0.0, 3.0 }, { 3.0, 0.0, 1.0,
              0.0 }, { 3.0, 0.0, 1.0, 1.0 }, { 3.0, 0.0, 1.0, 2.0 }, { 3.0, 0.0, 1.0, 3.0 }, { 3.0,
              0.0, 2.0, 0.0 }, { 3.0, 0.0, 2.0, 1.0 }, { 3.0, 0.0, 2.0, 2.0 },
          { 3.0, 0.0, 2.0, 3.0 }, { 3.0, 0.0, 3.0, 0.0 }, { 3.0, 0.0, 3.0, 1.0 }, { 3.0, 0.0, 3.0,
              2.0 }, { 3.0, 0.0, 3.0, 3.0 }, { 3.0, 1.0, 0.0, 0.0 }, { 3.0, 1.0, 0.0, 1.0 }, { 3.0,
              1.0, 0.0, 2.0 }, { 3.0, 1.0, 0.0, 3.0 }, { 3.0, 1.0, 1.0, 0.0 },
          { 3.0, 1.0, 1.0, 1.0 }, { 3.0, 1.0, 1.0, 2.0 }, { 3.0, 1.0, 1.0, 3.0 }, { 3.0, 1.0, 2.0,
              0.0 }, { 3.0, 1.0, 2.0, 1.0 }, { 3.0, 1.0, 2.0, 2.0 }, { 3.0, 1.0, 2.0, 3.0 }, { 3.0,
              1.0, 3.0, 0.0 }, { 3.0, 1.0, 3.0, 1.0 }, { 3.0, 1.0, 3.0, 2.0 },
          { 3.0, 1.0, 3.0, 3.0 }, { 3.0, 2.0, 0.0, 0.0 }, { 3.0, 2.0, 0.0, 1.0 }, { 3.0, 2.0, 0.0,
              2.0 }, { 3.0, 2.0, 0.0, 3.0 }, { 3.0, 2.0, 1.0, 0.0 }, { 3.0, 2.0, 1.0, 1.0 }, { 3.0,
              2.0, 1.0, 2.0 }, { 3.0, 2.0, 1.0, 3.0 }, { 3.0, 2.0, 2.0, 0.0 },
          { 3.0, 2.0, 2.0, 1.0 }, { 3.0, 2.0, 2.0, 2.0 }, { 3.0, 2.0, 2.0, 3.0 }, { 3.0, 2.0, 3.0,
              0.0 }, { 3.0, 2.0, 3.0, 1.0 }, { 3.0, 2.0, 3.0, 2.0 }, { 3.0, 2.0, 3.0, 3.0 }, { 3.0,
              3.0, 0.0, 0.0 }, { 3.0, 3.0, 0.0, 1.0 }, { 3.0, 3.0, 0.0, 2.0 },
          { 3.0, 3.0, 0.0, 3.0 }, { 3.0, 3.0, 1.0, 0.0 }, { 3.0, 3.0, 1.0, 1.0 }, { 3.0, 3.0, 1.0,
              2.0 }, { 3.0, 3.0, 1.0, 3.0 }, { 3.0, 3.0, 2.0, 0.0 }, { 3.0, 3.0, 2.0, 1.0 }, { 3.0,
              3.0, 2.0, 2.0 }, { 3.0, 3.0, 2.0, 3.0 }, { 3.0, 3.0, 3.0, 0.0 },
          { 3.0, 3.0, 3.0, 1.0 }, { 3.0, 3.0, 3.0, 2.0 }, { 3.0, 3.0, 3.0, 3.0 } };

  FourierCoefficientGenerator<double>* generator = new FullFourierCoefficientGenerator<double>();
  std::vector<Vector<double>*> multipliers;
  generator->computeFourierCoefficients(multipliers, nbInputs, order);

  ASSERT(static_cast<int>(multipliers.size()) == std::pow(order + 1, nbInputs));

  for (size_t i = 0; i < multipliers.size(); i++)
  {
    for (int k = 0; k < nbInputs; k++)
    {
      ASSERT(expected[i][k] == multipliers[i]->getEntry(k));
      //std::cout << multipliers[i]->getEntry(k) << " ";
    }
    //std::cout << std::endl;
  }

  for (auto iter = multipliers.begin(); iter != multipliers.end(); ++iter)
  {
    delete *iter;
  }
  delete generator;
}

void FourierBasisTest::testFourierBasis3()
{
  const int nbInputs = 4;
  const int order = 3;
  std::vector<std::vector<double>> expected =
      { { 0.0, 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0, 0.0 }, { 2.0, 0.0, 0.0, 0.0 },
          { 3.0, 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0, 0.0 }, { 0.0, 2.0, 0.0, 0.0 }, { 0.0, 3.0, 0.0,
              0.0 }, { 0.0, 0.0, 1.0, 0.0 }, { 0.0, 0.0, 2.0, 0.0 }, { 0.0, 0.0, 3.0, 0.0 }, { 0.0,
              0.0, 0.0, 1.0 }, { 0.0, 0.0, 0.0, 2.0 }, { 0.0, 0.0, 0.0, 3.0 } };

  FourierCoefficientGenerator<double>* generator =
      new IndependentFourierCoefficientGenerator<double>();
  std::vector<Vector<double>*> multipliers;
  generator->computeFourierCoefficients(multipliers, nbInputs, order);

  ASSERT(static_cast<int>(multipliers.size()) == ((order * nbInputs) + 1));

  for (size_t i = 0; i < multipliers.size(); i++)
  {
    for (int k = 0; k < nbInputs; k++)
    {
      ASSERT(expected[i][k] == multipliers[i]->getEntry(k));
      std::cout << multipliers[i]->getEntry(k) << " ";
    }
    std::cout << std::endl;
  }

  for (auto iter = multipliers.begin(); iter != multipliers.end(); ++iter)
  {
    delete *iter;
  }
  delete generator;
}

void FourierBasisTest::run()
{
  testFourierBasis1();
  testFourierBasis2();
  testFourierBasis3();
}
