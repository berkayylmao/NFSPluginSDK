// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Core/EASTL/EASTL/list.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UMath.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IVehicleAI : UTL::COM::IUnknown {
    enum class DriveFlags {
      Steer    = 1 << 0,
      GasBrake = 1 << 1,
      Reverse  = 1 << 2,
      All      = (std::uint32_t)Steer | (std::uint32_t)GasBrake | (std::uint32_t)Reverse,
    };

    virtual ~IVehicleAI();
    virtual ISimable*             GetSimable()                                                                     = 0;
    virtual IVehicle*             GetVehicle()                                                                     = 0;
    virtual AISplinePath*         GetSplinePath()                                                                  = 0;
    virtual void                  SetReverseOverride(float time)                                                   = 0;
    virtual bool                  GetReverseOverride()                                                             = 0;
    virtual DriveFlags            GetDriveFlags()                                                                  = 0;
    virtual void                  ClearDriveFlags()                                                                = 0;
    virtual void                  DoReverse()                                                                      = 0;
    virtual void                  DoSteering()                                                                     = 0;
    virtual void                  DoGasBrake()                                                                     = 0;
    virtual void                  DoDriving(DriveFlags flags)                                                      = 0;
    virtual void                  DoNOS()                                                                          = 0;
    virtual float                 GetDriveSpeed()                                                                  = 0;
    virtual void                  SetDriveSpeed(float driveSpeed)                                                  = 0;
    virtual void                  SetDriveTarget(const UMath::Vector3& destination)                                = 0;
    virtual float                 GetLookAhead()                                                                   = 0;
    virtual const UMath::Vector3& GetDriveTarget()                                                                 = 0;
    virtual WRoadNav*             GetDriveToNav()                                                                  = 0;
    virtual bool                  GetDrivableToDriveToNav()                                                        = 0;
    virtual void                  ResetDriveToNav(eLaneSelection laneSelection)                                    = 0;
    virtual void                  ResetDriveToNav(const UMath::Vector3&)                                           = 0;
    virtual void                  ResetVehicleToRoadNav(WRoadNav* otherNav)                                        = 0;
    virtual void                  ResetVehicleToRoadNav(std::int16_t segInd, char laneInd, float timeStep)         = 0;
    virtual void      ResetVehicleToRoadPos(const UMath::Vector3& position, const UMath::Vector3& forwardVector)   = 0;
    virtual float     GetPathDistanceRemaining()                                                                   = 0;
    virtual AITarget* GetTarget()                                                                                  = 0;
    virtual bool      GetDrivableToTargetPos()                                                                     = 0;
    virtual const eastl::list<AIAvoidable*>& GetAvoidableList()                                                    = 0;
    virtual void                             SetAvoidableRadius(float radius)                                      = 0;
    virtual float                            GetTopSpeed()                                                         = 0;
    virtual float                            GetAcceleration(float at)                                             = 0;
    virtual void  GetWorldAvoidanceInfo(float dT, UMath::Vector3& leftCollNormal, UMath::Vector3& rightCollNormal) = 0;
    virtual void  GetCollNav(const UMath::Vector3& forwardVector, float predictTime)                               = 0;
    virtual float GetLastSpawnTime()                                                                               = 0;
    virtual void  SetSpawned()                                                                                     = 0;
    virtual void  UnSpawn()                                                                                        = 0;
    virtual void  CanRespawn(bool respawnAvailable)                                                                = 0;
    virtual const Attrib::Gen::aivehicle& GetAttributes()                                                          = 0;
    virtual void                          EnableSimplePhysics()                                                    = 0;
    virtual void                          DisableSimplePhysics()                                                   = 0;
    virtual IPursuit*                     GetPursuit()                                                             = 0;
    virtual IRoadBlock*                   GetRoadBlock()                                                           = 0;
    virtual const UMath::Vector3&         GetSeekAheadPosition()                                                   = 0;
    virtual const UMath::Vector3&         GetFarFuturePosition()                                                   = 0;
    virtual const UMath::Vector3&         GetFarFutureDirection()                                                  = 0;
    virtual WRoadNav*                     GetCurrentRoad()                                                         = 0;
    virtual WRoadNav*                     GetFutureRoad()                                                          = 0;
    virtual bool                          IsCurrentGoal(const UCrc32& name)                                        = 0;
    virtual UCrc32&                       GetGoalName()                                                            = 0;
    virtual bool                          IsCurrentAction(const UCrc32& name)                                      = 0;
    virtual UCrc32                        GetActionName()                                                          = 0;
    virtual float                         GetSkill()                                                               = 0;
    virtual float                         GetShortcutSkill()                                                       = 0;
    virtual float                         GetPercentRaceComplete()                                                 = 0;

    static IHandle* GetHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x403700)(); }
  };
}  // namespace OpenSpeed::MW05
