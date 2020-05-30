# UUID

A module for Garry's Mod that allows the generation of version 4 [UUID](https://en.wikipedia.org/wiki/Universally_unique_identifier#Version_4_(random)) strings using the Boost library.

## Download

I only release prebuilt binaries for x64 on Linux & Windows. However, feel free to modify and build the code if you need x86 or macOS support. I don't offer support for these myself because x86 is old and I can't afford to test my code on macOS.

After downloading the binary of your choice, rename the `gm_` prefix appropriately depending on which realm you'll be using it in. For more information, check [this](https://wiki.facepunch.com/gmod/Creating_Binary_Modules#naminglocation) wiki article.

Downloads for the latest binaries:

* [Windows](https://github.com/viral32111/gm_uuid/releases/latest/download/gm_uuid_win64.dll)
* [Linux](https://github.com/viral32111/gm_uuid/releases/latest/download/gm_uuid_linux64.dll)

## Usage

Here's a simple example of how you would use this:

```lua
require( "uuid" )

-- The only argument is a boolean for including the dashes, it defaults to true.
print( GenerateUUID() ) -- 123e4567-e89b-12d3-a456-426655440000
print( GenerateUUID( true ) ) -- 123e4567-e89b-12d3-a456-426655440000
print( GenerateUUID( false ) ) -- 123e4567e89b12d3a456426655440000
```

## Building

### Windows

1. Download a copy of [the repository](https://github.com/viral32111/gm_uuid/archive/master.zip) and extract it into a folder.
2. Download and extract [Premake 5 (for Windows)](https://github.com/premake/premake-core/releases/download/v5.0.0-alpha15/premake-5.0.0-alpha15-windows.zip) into the repository folder (or add it to your environment path, if you're going to use it again later).
3. Open Command Prompt in the repository folder (`cd` into the folder).
4. Run `premake5 --file=scripts/premake5.lua vs2019` to generate a Visual Studio 2019 project.
5. Open the Visual Studio 2019 solution file created at `projects/windows/uuid.sln`.
6. Press `Build` > `Build Solution` to build the project (the module will be placed in `deploy/gm_uuid_win64.dll`).

### Linux

1. Download a copy of [the repository](https://github.com/viral32111/gm_uuid/archive/master.zip) and extract it into a folder.
2. Download and extract [Premake 5 (for Linux)](https://github.com/premake/premake-core/releases/download/v5.0.0-alpha15/premake-5.0.0-alpha15-linux.tar.gz) into the repository folder (or add it to your environment path, if you're going to use it again later).
3. Open your favourite terminal in the repository folder (`cd` into the folder).
4. Make the extracted `premake5` file executable (`chmod +x premake5`).
5. Run `premake5 --file=scripts/premake5.lua gmake` to generate a Make project.
6. Navigate to `project/linux/` (`cd /project/linux`).
7. Run `make` to build the project (the module will be placed in `deploy/gm_uuid_linux64.dll`).

## Licence

Copyright (C) 2020 [viral32111](https://github.com/viral32111). Licenced under [GNU AGPLv3](https://www.gnu.org/licenses/agpl-3.0.html).