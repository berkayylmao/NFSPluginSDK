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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib.h>
#include <OpenSpeed/Game.ProStreet/Types/EventSequencer.h>
#include <OpenSpeed/Game.ProStreet/Types/FECustomizationRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/UCrc32.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IVehicle : UTL::COM::IUnknown {
    enum class ForceStopType : std::uint8_t {
      ForceStop   = 1 << 0,
      InstantStop = 1 << 1,
      ForceCoast  = 1 << 2,
      StopOnline  = 1 << 4
    };

    virtual ~IVehicle();
    virtual ISimable*                    GetSimable()                                                           = 0;
    virtual const ISimable*              GetSimable() const                                                     = 0;
    virtual const UMath::Vector3&        GetPosition()                                                          = 0;
    virtual void                         SetBehaviorOverride(UCrc32, UCrc32)                                    = 0;
    virtual void                         RemoveBehaviorOverride(UCrc32)                                         = 0;
    virtual void                         CommitBehaviorOverrides()                                              = 0;
    virtual void                         ReleaseBehaviorAudio()                                                 = 0;
    virtual void                         SetStaging(bool isStaging)                                             = 0;
    virtual bool                         IsStaging()                                                            = 0;
    virtual void                         SetDragStaging(bool isDragStaging)                                     = 0;
    virtual bool                         IsDragStaging()                                                        = 0;
    virtual void                         SetUseDragStagingCamera(bool useDragStatingCamera)                     = 0;
    virtual bool                         ShouldUseDragStagingCamera()                                           = 0;
    virtual void                         Launch()                                                               = 0;
    virtual float                        GetPerfectLaunch()                                                     = 0;
    virtual void                         SetDriverStyle(DriverStyle newDriverStyle)                             = 0;
    virtual DriverStyle                  GetDriverStyle()                                                       = 0;
    virtual void                         SetPhysicsMode(PhysicsMode newPhysicsMode)                             = 0;
    virtual PhysicsMode                  GetPhysicsMode()                                                       = 0;
    virtual void                         SetDraftZoneModifier(float modifier)                                   = 0;
    virtual float                        GetDraftZoneModifier()                                                 = 0;
    virtual std::int32_t                 GetModelType()                                                         = 0;
    virtual bool                         IsSpooled()                                                            = 0;
    virtual bool                         IsLowRez()                                                             = 0;
    virtual const UCrc32&                GetVehicleClass()                                                      = 0;
    virtual const Attrib::Gen::pvehicle& GetVehicleAttributes()                                                 = 0;
    virtual const char*                  GetVehicleName()                                                       = 0;
    virtual Attrib::StringKey            GetVehicleKey()                                                        = 0;
    virtual Attrib::StringKey            GetStockVehicleKey()                                                   = 0;
    virtual void                         SetDriverClass(DriverClass newDriverClass)                             = 0;
    virtual DriverClass                  GetDriverClass()                                                       = 0;
    virtual bool                         IsLoading()                                                            = 0;
    virtual float                        GetOffScreenTime()                                                     = 0;
    virtual float                        GetOnScreenTime()                                                      = 0;
    virtual bool                         SetVehicleOnGround(const UMath::Vector3&, const UMath::Vector3&, bool) = 0;
    virtual void                         ForceStopOn(ForceStopType type)                                        = 0;
    virtual void                         ForceStopOff(ForceStopType type)                                       = 0;
    virtual ForceStopType                GetForceStop()                                                         = 0;
    virtual bool                         InShock()                                                              = 0;
    virtual bool                         IsDestroyed()                                                          = 0;
    virtual void                         Activate()                                                             = 0;
    virtual void                         Deactivate()                                                           = 0;
    virtual bool                         IsActive()                                                             = 0;
    virtual float                        GetSpeedometer()                                                       = 0;
    virtual float                        GetSpeed()                                                             = 0;
    virtual void                         SetSpeed(float newSpeed)                                               = 0;
    virtual void                         SetVelocity(float x, float y, float z)                                 = 0;
    virtual float                        GetAbsoluteSpeed()                                                     = 0;
    virtual bool                         IsGlareOn(VehicleFX::LightID fxId)                                     = 0;
    virtual void                         GlareOn(VehicleFX::LightID fxId)                                       = 0;
    virtual void                         GlareOff(VehicleFX::LightID fxId)                                      = 0;
    virtual bool                         IsCollidingWithSoftBarrier()                                           = 0;
    virtual IVehicleAI*                  GetAIVehiclePtr()                                                      = 0;
    virtual float                        GetSlipAngle()                                                         = 0;
    virtual const UMath::Vector3&        GetLocalVelocity()                                                     = 0;
    virtual void                         ComputeHeading(UMath::Vector3* out)                                    = 0;
    virtual bool                         IsAnimating()                                                          = 0;
    virtual void                         SetAnimating(bool isAnimating)                                         = 0;
    virtual bool                         IsOffWorld()                                                           = 0;
    virtual VehicleCustomizations*       GetCustomizations()                                                    = 0;
    virtual void                         SetCustomizations(VehicleCustomizations* customizations)               = 0;
    // null function
    virtual Physics::Tunings* GetTunings() = 0;
    // null function
    virtual void        SetTunings(const Physics::Tunings& tunings)                                = 0;
    virtual bool        GetPerformance(Physics::Info::CorrectedPerformance& to)                    = 0;
    virtual const char* GetCacheName()                                                             = 0;
    virtual bool        GetDynamicData(EventSequencer::System* system, void* pOutEventDynamicData) = 0;
    virtual bool        IsDriverAidOn(DriverAidType)                                               = 0;
    virtual void        SetDriverAidLevel(DriverAidType, int, bool)                                = 0;
    virtual int         GetDriverAidLevel(DriverAidType)                                           = 0;
    virtual int         GetDriverAidMaxLevel(DriverAidType)                                        = 0;
    virtual void        RestoreDriverAidLevels_All()                                               = 0;
    virtual void        RestoreDriverAidLevel(DriverAidType)                                       = 0;
    virtual ISimable*   SpawnPart(UCrc32, UCrc32, UCrc32)                                          = 0;
    virtual void        HidePart(UCrc32)                                                           = 0;
    virtual void        ResetPart(UCrc32)                                                          = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x402440)(); }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(IVehicle::ForceStopType)
#endif
}  // namespace OpenSpeed::ProStreet
