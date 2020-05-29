# UUID

A module for Garry's Mod that allows the generation of [UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier) strings using the Boost library.

## Download

I only release prebuilt binaries for x64 on Linux & Windows. However, feel free to modify and recompile the code if you need x86 or macOS support. I don't offer support for these myself because x86 is old and I can't afford to test my code on macOS.

After downloading the binary of your choice, rename the `gm_` prefix appropriately depending on which realm you'll be using it in. For more information, check [this](https://wiki.facepunch.com/gmod/Creating_Binary_Modules#naminglocation) wiki article.

Downloads for the latest binaries:

* [Windows (x64)](https://github.com/viral32111/gm_uuid/releases/latest/download/gm_uuid_win64.dll)
* [Linux (x64)](https://github.com/viral32111/gm_uuid/releases/latest/download/gm_uuid_linux64.dll)

## Usage

Here's a simple example of how you would use this:

```lua
require( "uuid" )

-- The only argument is a boolean for including the dashes, it defaults to true.
print( GenerateUUID() ) -- 123e4567-e89b-12d3-a456-426655440000
print( GenerateUUID( true ) ) -- 123e4567-e89b-12d3-a456-426655440000
print( GenerateUUID( false ) ) -- 123e4567e89b12d3a456426655440000
```

> Copyright (C) 2020 [viral32111](https://github.com/viral32111). Licenced under [GNU AGPLv3](https://www.gnu.org/licenses/agpl-3.0.html).