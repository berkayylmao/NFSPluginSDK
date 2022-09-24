// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IVEHICLEAI_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IVEHICLEAI_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
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
    virtual bool                  GetNOSAllowed()                                                                  = 0;
    virtual float                 GetDriveSpeed()                                                                  = 0;
    virtual void                  SetDriveSpeed(float driveSpeed)                                                  = 0;
    virtual void                  SetDriveTarget(const UMath::Vector3& destination)                                = 0;
    virtual float                 GetLookAhead()                                                                   = 0;
    virtual const UMath::Vector3& GetDriveTarget()                                                                 = 0;
    virtual WRoadNav*             GetDriveToNav()                                                                  = 0;
    virtual bool                  GetDrivableToDriveToNav()                                                        = 0;
    virtual void                  ResetDriveToNav(eLaneSelection laneSelection)                                    = 0;
    virtual void                  ResetVehicleToRoadNav(WRoadNav* otherNav)                                        = 0;
    virtual void                  ResetVehicleToRoadNav(std::int16_t segInd, char laneInd, float timeStep)         = 0;
    virtual void      ResetVehicleToRoadPos(const UMath::Vector3& position, const UMath::Vector3& forwardVector)   = 0;
    virtual float     GetPathDistanceRemaining()                                                                   = 0;
    virtual AITarget* GetTarget()                                                                                  = 0;
    virtual bool      GetDrivableToTargetPos()                                                                     = 0;
    virtual bool      GetDrivableToPursuitTargetPos()                                                              = 0;
    virtual AITarget* GetPursuitTarget()                                                                           = 0;
    virtual const eastl::list<AIAvoidable*>& GetAvoidableList()                                                    = 0;
    virtual void                             SetAvoidableRadius(float radius)                                      = 0;
    virtual float                            GetTopSpeed()                                                         = 0;
    virtual float                            GetAcceleration(float at)                                             = 0;
    virtual void  GetWorldAvoidanceInfo(float dT, UMath::Vector3& leftCollNormal, UMath::Vector3& rightCollNormal) = 0;
    virtual bool  HasWorldCollision(const UMath::Vector3&)                                                         = 0;
    virtual float GetLastSpawnTime()                                                                               = 0;
    virtual void  SetSpawned()                                                                                     = 0;
    virtual void  UnSpawn()                                                                                        = 0;
    virtual bool  CanRespawn(bool setRespawnAvailable)                                                             = 0;
    virtual const Attrib::Gen::aivehicle& GetAttributes()                                                          = 0;
    virtual void                          EnableSimplePhysics()                                                    = 0;
    virtual bool                          IsSimplePhysicsActive()                                                  = 0;
    virtual void                          DisableSimplePhysics()                                                   = 0;
    virtual void*                         GetPursuit()                                                             = 0;
    virtual AIPursuit*                    AttachPursuit(AIPursuit*)                                                = 0;
    virtual AIRoadBlock*                  AttachRoadBlock(AIRoadBlock*)                                            = 0;
    virtual UMath::Vector3&               GetPursuitOffset()                                                       = 0;
    virtual IRoadBlock*                   GetRoadBlock()                                                           = 0;
    virtual IVehicle*                     GetLeader()                                                              = 0;
    virtual AIWingman*                    GetWingman()                                                             = 0;
    virtual float                         GetStunTime()                                                            = 0;
    virtual void                          SetStunTime(float stunTime)                                              = 0;
    virtual const UMath::Vector3&         GetSeekAheadPosition()                                                   = 0;
    virtual const UMath::Vector3&         GetFarFuturePosition()                                                   = 0;
    virtual const UMath::Vector3&         GetFarFutureDirection()                                                  = 0;
    virtual WRoadNav*                     GetCurrentRoad()                                                         = 0;
    virtual WRoadNav*                     GetFutureRoad()                                                          = 0;
    virtual bool                          IsCurrentGoal(const UCrc32& goal)                                        = 0;
    virtual UCrc32&                       GetGoalName()                                                            = 0;
    virtual void                          SetGoal(const UCrc32& goal)                                              = 0;
    virtual bool                          IsGoalAccomplished()                                                     = 0;
    virtual void                          ResetVehicleCollisionReactions()                                         = 0;
    virtual bool                          IsCurrentAction(const UCrc32& action)                                    = 0;
    virtual UCrc32                        GetActionName()                                                          = 0;
    virtual float                         GetSkill()                                                               = 0;
    virtual float                         GetBaseSkill()                                                           = 0;
    virtual float                         GetShortcutSkill()                                                       = 0;
    virtual float                         GetPercentRaceComplete()                                                 = 0;
    virtual bool                          IsCrashed()                                                              = 0;
    virtual void                          SetCrashed(bool crashed)                                                 = 0;
    virtual bool                          IsOnHighway()                                                            = 0;
    virtual WRoadNavInfluence&            GetNavInfluence()                                                        = 0;
    virtual bool                          IsWingman(ISimable* target)                                              = 0;
    virtual bool                          IsCrewMate(ISimable* target)                                             = 0;
    virtual bool                          IsCopVehicle()                                                           = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4036A0)(); }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(IVehicleAI::DriveFlags)
#endif
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IVEHICLEAI_H
