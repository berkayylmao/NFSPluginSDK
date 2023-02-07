</table><img src=".github/logo.png" align="right" height="333" width="333"/>

# NFSPluginSDK 

An attempt to reverse compiled types of BlackBox era Need for Speed games to allow creating plugins/scipt mods easily.

Given the workload of finding leaked builds, cross-referencing compiled code, finding references to the variables inside structures and hand-crafting each of them; and also working alone, some structures may not have all of their features and/or have missing functions/variables. However, NFSPluginSDK is mature enough to be used as a base. [NFS Chat Chaos Mod](https://github.com/berkayylmao/NFS-Chat-Chaos-Mod) and [B.A.M.](https://github.com/berkayylmao/BerkaysAssortedMods) already use it.

| Game                 | Progress |       Attrib       |      PVehicle      |     AIVehicle      |     \*Pursuit      |
| :------------------- | :------: | :----------------: | :----------------: | :----------------: | :----------------: |
| NFS Most Wanted 2005 |   ≈60%   | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| NFS Carbon           |   ≈40%   | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| NFS ProStreet        |   ≈75%   | :white_check_mark: | :white_check_mark: |                    |                    |

## Usage
NFSPluginSDK does not need a seperate build, it's only a bunch of header files. Simply add it to your C++20 (or above) project, `#include` it and enjoy!

The easiest way to use NFSPluginSDK is to add it as a submodule.

`> git submodule add https://github.com/berkayylmao/NFSPluginSDK`

Include the header of the game you are working with.

`#include <NFSPluginSDK/NFSPluginSDK/Game.MW05/MW05.h>`

And use it!

```cpp
using namespace NFSPluginSDK;

MW05::Game::BlowEngine(MW05::PlayerEx::GetPlayerInstance());
```

All gameplay functionality of [NFS Chat Chaos Mod](https://github.com/berkayylmao/NFS-Chat-Chaos-Mod) and [B.A.M.](https://github.com/berkayylmao/BerkaysAssortedMods) are provided by NFSPluginSDK.

## Thanks
Massive thanks to [@nlgxzef](https://github.com/nlgxzef) and [@heyitsleo](https://github.com/LeoCodes21) for all their help.

## Legal
NFSPluginSDK is not affiliated in any way with EA.

Released under the BSD 3-Clause License.
