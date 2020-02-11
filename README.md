# UUID

**Project started: 11/2/2020, Last updated: 11/2/2020**

This is a C++ module for Garry's Mod which allows developers to generate [UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier) strings using the C++ Boost library.

### Documentation
This module only provides 1 new function:
```lua
string uuid.generate(boolean includeDashes=true)
```

### Usage
This is a basic example of how to use this module:
```lua
require("uuid")

local myUUID = uuid.generate() -- The include dashes parameter is optional and by default true
local noDashesUUID = uuid.generate(false)

print(myUUID)
print(noDashesUUID)
```

Example output of this:
```
123e4567-e89b-12d3-a456-426655440000
123e4567e89b12d3a456426655440000
```

###### [Copyright 2020 viral32111](LICENSE.md)