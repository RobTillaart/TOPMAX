//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2023-05-18
// PURPOSE: unit tests for the TOPMAX library
//          https://github.com/RobTillaart/TOPMAX
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "TOPMAX.h"



unittest_setup()
{
  fprintf(stderr, "TOPMAX_LIB_VERSION: %s\n", (char *) TOPMAX_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(constructor)
{
  TOPMAX tm(5);
  assertEqual(5, tm.size());
  assertEqual(0, tm.count());
}


unittest(add)
{
  TOPMAX tm(5);
  assertEqual(5, tm.size());

  for (int i = 0; i < 5; i++)
  {
    assertEqual(i, tm.count());
    tm.add(i);
  }
  for (int i = 0; i < 5; i++)
  {
    assertEqual(5, tm.count());
    tm.add(i);
  }
}




unittest_main()


//  -- END OF FILE --

