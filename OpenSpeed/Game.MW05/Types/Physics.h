// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Physics {
  class Tunings {
    const std::size_t _getMemberCount() const { return sizeof(Tunings) / sizeof(float); }

   public:
    static inline const float g_GameDisplayMultiplier = 5.0f;

    float Steering     = 0.0f;
    float Handling     = 0.0f;
    float Brakes       = 0.0f;
    float RideHeight   = 0.0f;
    float Aerodynamics = 0.0f;
    float NOS          = 0.0f;
    float Turbo        = 0.0f;  // or Supercharger

    float&       operator[](std::size_t index) { return ((float*)this)[index]; }
    const float& operator[](std::size_t index) const { return ((float*)this)[index]; }
    bool         operator==(const Tunings& rhs) const {
      std::size_t _matches = 0;
      for (std::size_t i = 0; i < _getMemberCount(); i++) {
        if ((*this)[i] == rhs[i])
          _matches++;
        else
          break;
      }

      return _matches == _getMemberCount();
    }
    void operator=(const Tunings& newTunings) { std::memcpy(this, &newTunings, sizeof(Tunings)); }
  };

}  // namespace OpenSpeed::MW05::Physics
