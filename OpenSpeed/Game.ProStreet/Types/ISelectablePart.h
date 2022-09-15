// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_ISELECTABLEPART_H
#define OPENSPEED_GAME_PROSTREET_TYPES_ISELECTABLEPART_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/AutoSculpt.h>
#include <OpenSpeed/Game.ProStreet/Types/bNode.h>
#include <OpenSpeed/Game.ProStreet/Types/FECust.h>
#include <OpenSpeed/Game.ProStreet/Types/FEPartDetail.h>

namespace OpenSpeed::ProStreet {
  struct ISelectablePart : bTNode<ISelectablePart> {
    std::uint32_t mOverrideNameHash;

    virtual ~ISelectablePart();
    virtual std::uint32_t    CartComparisonValue()                            = 0;
    virtual ISelectablePart* CopyPart()                                       = 0;
    virtual bool             Install(RideInfo*)                               = 0;
    virtual bool             Install(FECustomizationRecord*, BluePrintNumber) = 0;
    virtual void             Preview(bool)                                    = 0;
    virtual float            GetSculptZoneAmount(AutoSculpt::ZoneID, FECust::SelectableRegion);
    virtual std::uint32_t    GetHALIDHash() = 0;
    virtual std::uint32_t    GetActionLanguageHash();
    virtual std::uint32_t    GetCategoryHash() = 0;
    virtual std::int32_t     GetPrice()        = 0;
    virtual std::int32_t     GetTier();
    virtual std::uint32_t    GetBrandNameHash();
    virtual std::uint32_t    GetLogoHash();
    virtual bool             GetIsUnlocked();
    virtual bool             IsValidForMode(DALVehicleCommands::RaceMode);
    virtual bool             GetIsStock();
    virtual bool             GetIsInInventory(FECustomizationRecord*);
    virtual bool             GetIsInstalled(FECustomizationRecord*, BluePrintNumber);
    virtual DBCarPart*       GetPart();
    virtual CarSlotId        GetSlotId();
    virtual bool             IsEqualTo(ISelectablePart* other);
    virtual std::uint32_t    GetUniquePartID() = 0;
    virtual bool             IsCarbon();
    virtual bool             HasOwnSliderValues();
    virtual bool             GetColourPartData(FECust::ColourPartData*);
    virtual bool             ResetAutosculptValues();
    virtual std::uint32_t    GetDetailHash();
    virtual FEPartDetail*    GetPartDetails();
    virtual bool             IsReallyAutosculptable();
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_ISELECTABLEPART_H
