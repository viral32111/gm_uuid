# UUID

A module for Garry's Mod that allows the generation of [UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier) strings using the Boost library.

## Usage

Here's a simple example of how you would use this:

```lua
require( "uuid" )

-- The only argument is a boolean for including the dashes, it defaults to true.
print( uuid.generate() ) -- 123e4567-e89b-12d3-a456-426655440000
print( uuid.generate( true ) ) -- 123e4567-e89b-12d3-a456-426655440000
print( uuid.generate( false ) ) -- 123e4567e89b12d3a456426655440000
```

###### [Copyright 2020 viral32111](LICENSE.md)