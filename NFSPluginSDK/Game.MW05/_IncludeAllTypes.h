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

#ifndef NFSPLUGINSDK_GAME_MW05_INCLUDEALLTYPES_H
#define NFSPLUGINSDK_GAME_MW05_INCLUDEALLTYPES_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/ActionData.h>
#include <NFSPluginSDK/Game.MW05/Types/ActionQueue.h>
#include <NFSPluginSDK/Game.MW05/Types/AIAvoidable.h>
#include <NFSPluginSDK/Game.MW05/Types/AICopManager.h>
#include <NFSPluginSDK/Game.MW05/Types/AIGoal.h>
#include <NFSPluginSDK/Game.MW05/Types/AIParams.h>
#include <NFSPluginSDK/Game.MW05/Types/AIPerpVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/AIPursuit.h>
#include <NFSPluginSDK/Game.MW05/Types/AISpawnManager.h>
#include <NFSPluginSDK/Game.MW05/Types/AITarget.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleCopCar.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleEmpty.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleHelicopter.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleHuman.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePursuit.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleRacecar.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleTraffic.h>
#include <NFSPluginSDK/Game.MW05/Types/Attachments.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib.h>
#include <NFSPluginSDK/Game.MW05/Types/AudioSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/Behavior.h>
#include <NFSPluginSDK/Game.MW05/Types/BehaviorParams.h>
#include <NFSPluginSDK/Game.MW05/Types/bList.h>
#include <NFSPluginSDK/Game.MW05/Types/bNode.h>
#include <NFSPluginSDK/Game.MW05/Types/CareerPursuitScores.h>
#include <NFSPluginSDK/Game.MW05/Types/CareerSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/CARP.h>
#include <NFSPluginSDK/Game.MW05/Types/CarPart.h>
#include <NFSPluginSDK/Game.MW05/Types/cFinishedRaceStats.h>
#include <NFSPluginSDK/Game.MW05/Types/cFrontendDatabase.h>
#include <NFSPluginSDK/Game.MW05/Types/CollisionGeometry.h>
#include <NFSPluginSDK/Game.MW05/Types/CostToStateScores.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageCopCar.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageDragster.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageHeli.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageRacer.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageZone.h>
#include <NFSPluginSDK/Game.MW05/Types/DebugVehicleSelection.h>
#include <NFSPluginSDK/Game.MW05/Types/Dynamics.h>
#include <NFSPluginSDK/Game.MW05/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.MW05/Types/FECareerRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FECustomizationRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FEImage.h>
#include <NFSPluginSDK/Game.MW05/Types/FEImpoundData.h>
#include <NFSPluginSDK/Game.MW05/Types/FEInfractionsData.h>
#include <NFSPluginSDK/Game.MW05/Types/FEKeyboardSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/FEMinList.h>
#include <NFSPluginSDK/Game.MW05/Types/FEMinNode.h>
#include <NFSPluginSDK/Game.MW05/Types/FEMultiImage.h>
#include <NFSPluginSDK/Game.MW05/Types/FEngHud.h>
#include <NFSPluginSDK/Game.MW05/Types/FEObject.h>
#include <NFSPluginSDK/Game.MW05/Types/FEPlayerCarDB.h>
#include <NFSPluginSDK/Game.MW05/Types/FinishedRaceStatsEntry.h>
#include <NFSPluginSDK/Game.MW05/Types/FloatSpring.h>
#include <NFSPluginSDK/Game.MW05/Types/Game.h>
#include <NFSPluginSDK/Game.MW05/Types/GameplaySettings.h>
#include <NFSPluginSDK/Game.MW05/Types/GCharacter.h>
#include <NFSPluginSDK/Game.MW05/Types/GenericMessage.h>
#include <NFSPluginSDK/Game.MW05/Types/GEventTimer.h>
#include <NFSPluginSDK/Game.MW05/Types/GIcon.h>
#include <NFSPluginSDK/Game.MW05/Types/GManager.h>
#include <NFSPluginSDK/Game.MW05/Types/GPS.h>
#include <NFSPluginSDK/Game.MW05/Types/GRaceBin.h>
#include <NFSPluginSDK/Game.MW05/Types/GRaceParameters.h>
#include <NFSPluginSDK/Game.MW05/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/GRaceStatus.h>
#include <NFSPluginSDK/Game.MW05/Types/Grid.h>
#include <NFSPluginSDK/Game.MW05/Types/GroundSupportRequest.h>
#include <NFSPluginSDK/Game.MW05/Types/GRuntimeInstance.h>
#include <NFSPluginSDK/Game.MW05/Types/GTimer.h>
#include <NFSPluginSDK/Game.MW05/Types/GTrigger.h>
#include <NFSPluginSDK/Game.MW05/Types/HeliSheetCoordinate.h>
#include <NFSPluginSDK/Game.MW05/Types/HighScoresDatabase.h>
#include <NFSPluginSDK/Game.MW05/Types/HudElement.h>
#include <NFSPluginSDK/Game.MW05/Types/IAIHelicopter.h>
#include <NFSPluginSDK/Game.MW05/Types/IArticulatedVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/IAttachable.h>
#include <NFSPluginSDK/Game.MW05/Types/IAttributeable.h>
#include <NFSPluginSDK/Game.MW05/Types/IAudible.h>
#include <NFSPluginSDK/Game.MW05/Types/IBody.h>
#include <NFSPluginSDK/Game.MW05/Types/ICause.h>
#include <NFSPluginSDK/Game.MW05/Types/ICheater.h>
#include <NFSPluginSDK/Game.MW05/Types/ICollisionBody.h>
#include <NFSPluginSDK/Game.MW05/Types/ICopMgr.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageable.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageableVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/IDisposable.h>
#include <NFSPluginSDK/Game.MW05/Types/IDynamicsEntity.h>
#include <NFSPluginSDK/Game.MW05/Types/IEngine.h>
#include <NFSPluginSDK/Game.MW05/Types/IExplodeable.h>
#include <NFSPluginSDK/Game.MW05/Types/IGenericMessage.h>
#include <NFSPluginSDK/Game.MW05/Types/IHud.h>
#include <NFSPluginSDK/Game.MW05/Types/IHumanAI.h>
#include <NFSPluginSDK/Game.MW05/Types/IInput.h>
#include <NFSPluginSDK/Game.MW05/Types/IInputPlayer.h>
#include <NFSPluginSDK/Game.MW05/Types/IModel.h>
#include <NFSPluginSDK/Game.MW05/Types/InputControls.h>
#include <NFSPluginSDK/Game.MW05/Types/InputPlayer.h>
#include <NFSPluginSDK/Game.MW05/Types/IPerpetrator.h>
#include <NFSPluginSDK/Game.MW05/Types/IPlayer.h>
#include <NFSPluginSDK/Game.MW05/Types/IPursuit.h>
#include <NFSPluginSDK/Game.MW05/Types/IPursuitAI.h>
#include <NFSPluginSDK/Game.MW05/Types/IRacer.h>
#include <NFSPluginSDK/Game.MW05/Types/IRBVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/IRenderable.h>
#include <NFSPluginSDK/Game.MW05/Types/IResetable.h>
#include <NFSPluginSDK/Game.MW05/Types/IRigidBody.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimable.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimpleBody.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimpleChopper.h>
#include <NFSPluginSDK/Game.MW05/Types/ISpikeable.h>
#include <NFSPluginSDK/Game.MW05/Types/ISuspension.h>
#include <NFSPluginSDK/Game.MW05/Types/ITrafficAI.h>
#include <NFSPluginSDK/Game.MW05/Types/ITransmission.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleAI.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.MW05/Types/JukeboxEntry.h>
#include <NFSPluginSDK/Game.MW05/Types/LocalPlayer.h>
#include <NFSPluginSDK/Game.MW05/Types/MilestoneTypeInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/Minimap.h>
#include <NFSPluginSDK/Game.MW05/Types/MinimapItem.h>
#include <NFSPluginSDK/Game.MW05/Types/ObjectStateBlockHeader.h>
#include <NFSPluginSDK/Game.MW05/Types/OptionsSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/Physics.h>
#include <NFSPluginSDK/Game.MW05/Types/PhysicsObject.h>
#include <NFSPluginSDK/Game.MW05/Types/PInput.h>
#include <NFSPluginSDK/Game.MW05/Types/PlayerSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/PursuitScore.h>
#include <NFSPluginSDK/Game.MW05/Types/PVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/RaceParameters.h>
#include <NFSPluginSDK/Game.MW05/Types/RacePreparationInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/RaceSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/RaceTypeHighScores.h>
#include <NFSPluginSDK/Game.MW05/Types/RBGrid.h>
#include <NFSPluginSDK/Game.MW05/Types/RBSmackable.h>
#include <NFSPluginSDK/Game.MW05/Types/RBTractor.h>
#include <NFSPluginSDK/Game.MW05/Types/RBVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/ResetCar.h>
#include <NFSPluginSDK/Game.MW05/Types/RideInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/RigidBody.h>
#include <NFSPluginSDK/Game.MW05/Types/Sim.h>
#include <NFSPluginSDK/Game.MW05/Types/SimpleChopper.h>
#include <NFSPluginSDK/Game.MW05/Types/SimpleRigidBody.h>
#include <NFSPluginSDK/Game.MW05/Types/Smackable.h>
#include <NFSPluginSDK/Game.MW05/Types/SmackableParams.h>
#include <NFSPluginSDK/Game.MW05/Types/SMSMessage.h>
#include <NFSPluginSDK/Game.MW05/Types/TimeOfDay.h>
#include <NFSPluginSDK/Game.MW05/Types/Timer.h>
#include <NFSPluginSDK/Game.MW05/Types/TopEvadedPursuitDetail.h>
#include <NFSPluginSDK/Game.MW05/Types/TrackHighScore.h>
#include <NFSPluginSDK/Game.MW05/Types/TrackInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/UCircularQueue.h>
#include <NFSPluginSDK/Game.MW05/Types/UCrc32.h>
#include <NFSPluginSDK/Game.MW05/Types/UMath.h>
#include <NFSPluginSDK/Game.MW05/Types/UserProfile.h>
#include <NFSPluginSDK/Game.MW05/Types/USpline.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleParams.h>
#include <NFSPluginSDK/Game.MW05/Types/VideoSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/WCollisionMgr.h>
#include <NFSPluginSDK/Game.MW05/Types/WRoadNav.h>
#include <NFSPluginSDK/Game.MW05/Types/WTrigger.h>
#include <NFSPluginSDK/Game.MW05/Types/WWorldPos.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/ChunkBlock.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Class.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Collection.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Database.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/DataBlock.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Definition.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/DependencyNode.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/ExportManager.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/ExportNode.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/HashMap.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Instance.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/PointerNode.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Private.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/RefSpec.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/RGBA.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Vault.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/camerainfo.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/chopperspecs.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/collisionreactions.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/damagespecs.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/gameplay.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/presetride.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pursuitescalation.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pursuitlevels.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pursuitsupport.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/rigidbodyspecs.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/simsurface.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/smackable.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/timeofdaylighting.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/trafficpattern.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/camerainfolayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/collisionreactionslayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/damagespecslayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/gameplaylayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/pvehiclelayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/rigidbodyspecslayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/simsurfacelayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/timeofdaylightinglayout.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Layouts/trafficpatternlayout.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/CircularQueue.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/FixedVector.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/Listable.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/ListableSet.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/Vector.h>

#endif  // NFSPLUGINSDK_GAME_MW05_INCLUDEALLTYPES_H
