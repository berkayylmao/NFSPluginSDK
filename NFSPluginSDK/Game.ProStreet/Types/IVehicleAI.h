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
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/vehicle.h>
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
    virtual ISimable*                        GetSimable()                                                        = 0;
    virtual IVehicle*                        GetVehicle()                                                        = 0;
    virtual AISplinePath*                    GetSplinePath()                                                     = 0;
    virtual void                             SetReverseOverride(float time)                                      = 0;
    virtual bool                             GetReverseOverride()                                                = 0;
    virtual DriveFlags                       GetDriveFlags()                                                     = 0;
    virtual void                             ClearDriveFlags()                                                   = 0;
    virtual void                             DoReverse()                                                         = 0;
    virtual void                             DoSteering()                                                        = 0;
    virtual void                             DoGasBrake()                                                        = 0;
    virtual void                             DoDriving(DriveFlags flags)                                         = 0;
    virtual const UMath::Vector3&            GetDriveDirection()                                                 = 0;
    virtual void                             SetDriveDirection(const UMath::Vector3&)                            = 0;
    virtual const UMath::Vector3&            GetVectorToPath()                                                   = 0;
    virtual void                             SetVectorToPath(const UMath::Vector3&)                              = 0;
    virtual float                            GetDriveSpeed()                                                     = 0;
    virtual void                             SetDriveSpeed(float driveSpeed)                                     = 0;
    virtual float                            GetMaxThrottle()                                                    = 0;
    virtual void                             SetMaxThrottle(float)                                               = 0;
    virtual const UMath::Vector3&            GetDriveTarget()                                                    = 0;
    virtual void                             SetDriveTarget(const UMath::Vector3&)                               = 0;
    virtual float                            GetRoadOffset()                                                     = 0;
    virtual float                            GetRoadCurvature()                                                  = 0;
    virtual float                            GetCornerAngle()                                                    = 0;
    virtual float                            GetLookAhead()                                                      = 0;
    virtual void                             SetDriverStyle(DriverStyle)                                         = 0;
    virtual WRoadNav*                        GetDriveToNav()                                                     = 0;
    virtual bool                             GetDrivableToDriveToNav()                                           = 0;
    virtual void                             Reset()                                                             = 0;
    virtual void                             ResetDriveToNav(eLaneSelection)                                     = 0;
    virtual bool                             ResetVehicleToRoadNav(short, char, float)                           = 0;
    virtual bool                             ResetVehicleToRoadNav(WRoadNav*)                                    = 0;
    virtual bool                             ResetVehicleToRoadPos(const UMath::Vector3&, const UMath::Vector3&) = 0;
    virtual float                            GetPathDistanceRemaining()                                          = 0;
    virtual AITarget*                        GetTarget()                                                         = 0;
    virtual bool                             GetDrivableToTargetPos()                                            = 0;
    virtual bool                             GetDrivableToPursuitTargetPos()                                     = 0;
    virtual AITarget*                        GetPursuitTarget()                                                  = 0;
    virtual const eastl::list<AIAvoidable*>& GetAvoidableList()                                                  = 0;
    virtual void                             SetAvoidableRadius(float)                                           = 0;
    virtual float                            GetTopSpeed()                                                       = 0;
    virtual float                            GetAcceleration(float)                                              = 0;
    virtual bool                             GetWorldAvoidanceInfo(float, UMath::Vector3&, UMath::Vector3&)      = 0;
    virtual bool                             HasWorldCollision(const UMath::Vector3&)                            = 0;
    virtual float                            GetLastSpawnTime()                                                  = 0;
    virtual void                             SetSpawned()                                                        = 0;
    virtual void                             UnSpawn()                                                           = 0;
    virtual bool                             CanRespawn(bool)                                                    = 0;
    virtual const Attrib::Gen::aivehicle&    GetAttributes()                                                     = 0;
    virtual void                             EnableSimplePhysics()                                               = 0;
    virtual bool                             IsSimplePhysicsActive()                                             = 0;
    virtual void                             DisableSimplePhysics(bool)                                          = 0;
    virtual UMath::Vector3&                  GetPursuitOffset()                                                  = 0;
    virtual float                            GetStunTime()                                                       = 0;
    virtual void                             SetStunTime(float)                                                  = 0;
    virtual bool                             IsCurrentGoal(const UCrc32&)                                        = 0;
    virtual UCrc32&                          GetGoalName()                                                       = 0;
    virtual void                             SetGoal(const UCrc32&)                                              = 0;
    virtual bool                             IsGoalAccomplished()                                                = 0;
    virtual void                             ResetVehicleCollisionReactions()                                    = 0;
    virtual bool                             IsCurrentAction(const UCrc32&)                                      = 0;
    virtual UCrc32                           GetActionName()                                                     = 0;
    virtual float                            GetSkill()                                                          = 0;
    virtual float                            GetBaseSkill()                                                      = 0;
    virtual float                            GetShortcutSkill()                                                  = 0;
    virtual float                            GetPercentRaceComplete()                                            = 0;
    virtual bool                             IsCrashed()                                                         = 0;
    virtual void                             SetCrashed(const bool)                                              = 0;
    virtual bool                             IsOnHighway()                                                       = 0;
    virtual WRoadNavInfluence&               GetNavInfluence()                                                   = 0;
    virtual bool                             IsCopVehicle()                                                      = 0;
    virtual void                             UpdateNavPos(float, const UMath::Vector3&, float)                   = 0;
    virtual void                             CheckOffPath(bool)                                                  = 0;
    virtual void*                            GetGateVector()                                                     = 0;
    virtual UMath::Vector3&                  GetLineStartPoint()                                                 = 0;
    virtual void                             CopyLineToGates(float, int, int, bool, bool)                        = 0;
    virtual void                             CleanUpGateVector()                                                 = 0;
    virtual void                             DetectPossibleCollisions(float, float)                              = 0;
    virtual void                             ClearCollisions()                                                   = 0;
    virtual void                             HandleCollisions(float)                                             = 0;
    virtual void*                            GetCollisionInfos()                                                 = 0;
    virtual void                             EnableObstacleAvoidance()                                           = 0;
    virtual void                             DisableObstacleAvoidance()                                          = 0;
    virtual float                            GetSpeedLevel()                                                     = 0;
    virtual void                             SetSpeedLevel(float)                                                = 0;
    virtual void                             SetBrakeAggression(float)                                           = 0;
    virtual void                             SetMinBrakeAggression(float)                                        = 0;
    virtual float                            GetBrakeAggression()                                                = 0;
    virtual void                             SetCornerAggression(float)                                          = 0;
    virtual void                             SetMinCornerAggression(float)                                       = 0;
    virtual float                            GetCornerAggression()                                               = 0;
    virtual void                             SetPassingAggression(float)                                         = 0;
    virtual float                            GetPassingAggression()                                              = 0;
    virtual void                             SetObstacleAvoidanceSafetyMargin(float)                             = 0;
    virtual float                            GetObstacleAvoidanceSafetyMargin()                                  = 0;
    virtual void                             SetTargetLineOffset(float)                                          = 0;
    virtual float                            GetTargetLineOffset()                                               = 0;
    virtual void                             DriftHelp(Attrib::Gen::vehicle&, bool, float, float)                = 0;
    virtual void*                            GetDataRepository()                                                 = 0;
    virtual void*                            GetStrategy()                                                       = 0;
    virtual void                             DoStrategy(float)                                                   = 0;
    virtual void                             SmoothCutGates()                                                    = 0;
    virtual void*                            GetMistakeContainer()                                               = 0;
    virtual void                             DoMistakes(float)                                                   = 0;
    virtual void                             SetDynamicGateCount(int)                                            = 0;
    virtual bool                      GetDriftLine(unsigned int, float, float, UMath::Vector3&, UMath::Vector3&) = 0;
    virtual bool                      GetDriftLinePoint(unsigned int, float, float, UMath::Vector3&)             = 0;
    virtual GRace::AI_AggressionLevel GetAggressionLevel()                                                       = 0;
    virtual GRace::AI_MistakeLevel    GetMistakeLevel()                                                          = 0;
    virtual std::int32_t              GetTurnIndicatorLevel()                                                    = 0;
    virtual void                      SetReadyToStart(bool)                                                      = 0;
    virtual void                      SetCanStart(bool)                                                          = 0;
    virtual bool                      ReadyToStart()                                                             = 0;
    virtual bool                      CanStart()                                                                 = 0;
    virtual bool                      LookAheadForCurve(int, void*, float&, int&, int&, int)                     = 0;
    virtual float                     GetCornerSpeed(float)                                                      = 0;
    virtual float                     GetCornerSpeed()                                                           = 0;
    virtual float                     GetDriftCornerSpeed(float)                                                 = 0;
    virtual float                     GetDriftCornerSpeed()                                                      = 0;
    virtual void                      SetForceBrakeLightsOn(bool)                                                = 0;
    virtual bool                      GetForceBrakeLightsOn()                                                    = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*>(0x4028A0); }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(IVehicleAI::DriveFlags)
#endif
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IVEHICLEAI_H
