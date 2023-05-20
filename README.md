
[![Arduino CI](https://github.com/RobTillaart/TOPMAX/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/TOPMAX/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/TOPMAX/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/TOPMAX/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/TOPMAX/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/TOPMAX/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/TOPMAX.svg?maxAge=3600)](https://github.com/RobTillaart/TOPMAX/releases)


# TOPMAX

Arduino library to track the top N maxima.

## Description

This experimental library tracks the top N maxima of a series of values. 
It can be used e.g. to track the top 5 peak temperatures over a given 
period of time.

The library implements two classes:
- **TOPMAX** just tracks the values. (smaller footprint).
- **TOPMAXext** also tracks a user defined tag (e.g. timestamp).


#### Links

- https://github.com/RobTillaart/TOPMAX
- https://github.com/RobTillaart/TOPMIN
- https://github.com/RobTillaart/runningAverage
- https://github.com/RobTillaart/MINMAX


## Interface

```cpp
#include "TOPMAX.h"
```

#### TOPMAX

- **TOPMAX(uint8_t size = 5)** Constructor, defines the number of elements it can hold.
Default number of elements is 5. If size < 3 it becomes 3.
- **uint8_t count()** returns the number of elements in the internal array.
- **uint8_t size()** returns the maximum number of elements in the internal array. 
- **void reset()** reset the internal counter to 0, clearing the system.
- **bool add(float value)** add a value to the TOPMAX object to check of it needs to be 
in the top N of maxima.
- **float getValue(uint8_t index)** get an element of the internal array.
index <= count().
- **bool fill(float value)** convenience function to fill the internal array 
with a single value e.g. 0.


#### TOPMAXext

Derived from TOPMAX, extended with a tag field.

- **TOPMAXext(uint8_t size = 5)** Constructor, defines the number of elements it can hold.
Default number of elements is 5. If size < 3 it becomes 3.
- **bool add(float value, uint32_t tag)** add a value to the TOPMAXext object to check if
it needs to be in the top N of maxima. If so add **tag** too (at same index).
**tag** is typical an index, counter or timestamp.
- **uint32_t getTag(uint8_t index)** get the tag from an element of the internal array.
index <= count().
- **bool fill(float value, uint32_t tag)** convenience function to fill the internal array 
with a single value e.g. 0. (tag idem).


# Future

#### Must

- keep functional in sync with TOPMIN.
- improve documentation.


#### Should

- add unit tests.
- add more examples.


#### Could

- create template class.


#### Wont

