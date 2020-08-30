# Micro-library to add const to types

Given: 

```C++
#include <let.hpp>

foo** ye_olde_c_api();
let ptr = ye_olde_c_api();
```

Then, the following holds: 
```
static_assert(std::is_same_v<decltype(ptr), const foo *const *const>);
```

Dependencies: C++17.

This is not D-like deep-const - nothing can be done for pointers contained inside structures.
