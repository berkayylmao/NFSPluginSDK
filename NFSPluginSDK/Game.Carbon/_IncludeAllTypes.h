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

#ifndef NFSPLUGINSDK_GAME_CARBON_INCLUDEALLTYPES_H
#define NFSPLUGINSDK_GAME_CARBON_INCLUDEALLTYPES_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/ActionData.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIAvoidable.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIGoal.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIParams.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIPerpVehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/AITarget.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleCopCar.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleEmpty.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleGhost.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleHuman.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehiclePursuit.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleRacecar.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleTraffic.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attachments.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib.h>
#include <NFSPluginSDK/Game.Carbon/Types/Behavior.h>
#include <NFSPluginSDK/Game.Carbon/Types/bList.h>
#include <NFSPluginSDK/Game.Carbon/Types/bNode.h>
#include <NFSPluginSDK/Game.Carbon/Types/Dynamics.h>
#include <NFSPluginSDK/Game.Carbon/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.Carbon/Types/FECustomizationRecord.h>
#include <NFSPluginSDK/Game.Carbon/Types/FloatSpring.h>
#include <NFSPluginSDK/Game.Carbon/Types/Game.h>
#include <NFSPluginSDK/Game.Carbon/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.Carbon/Types/GRaceStatus.h>
#include <NFSPluginSDK/Game.Carbon/Types/Grid.h>
#include <NFSPluginSDK/Game.Carbon/Types/IAttachable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IAttributeable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IAvoidable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IBody.h>
#include <NFSPluginSDK/Game.Carbon/Types/ICause.h>
#include <NFSPluginSDK/Game.Carbon/Types/ICheater.h>
#include <NFSPluginSDK/Game.Carbon/Types/ICollisionBody.h>
#include <NFSPluginSDK/Game.Carbon/Types/IDynamicsEntity.h>
#include <NFSPluginSDK/Game.Carbon/Types/IExplodeable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IHumanAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IInput.h>
#include <NFSPluginSDK/Game.Carbon/Types/IInputPlayer.h>
#include <NFSPluginSDK/Game.Carbon/Types/IPerpetrator.h>
#include <NFSPluginSDK/Game.Carbon/Types/IPlayer.h>
#include <NFSPluginSDK/Game.Carbon/Types/IPursuit.h>
#include <NFSPluginSDK/Game.Carbon/Types/IPursuitAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IRacer.h>
#include <NFSPluginSDK/Game.Carbon/Types/IRenderable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IResetable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IRigidBody.h>
#include <NFSPluginSDK/Game.Carbon/Types/ISimable.h>
#include <NFSPluginSDK/Game.Carbon/Types/ITrafficAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IVehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/IVehicleAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.Carbon/Types/Physics.h>
#include <NFSPluginSDK/Game.Carbon/Types/PhysicsObject.h>
#include <NFSPluginSDK/Game.Carbon/Types/PVehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/RideInfo.h>
#include <NFSPluginSDK/Game.Carbon/Types/Sim.h>
#include <NFSPluginSDK/Game.Carbon/Types/TimeOfDay.h>
#include <NFSPluginSDK/Game.Carbon/Types/Timer.h>
#include <NFSPluginSDK/Game.Carbon/Types/UCrc32.h>
#include <NFSPluginSDK/Game.Carbon/Types/USpline.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>
#include <NFSPluginSDK/Game.Carbon/Types/VehicleBehavior.h>
#include <NFSPluginSDK/Game.Carbon/Types/VehicleCustomizations.h>
#include <NFSPluginSDK/Game.Carbon/Types/VehicleParams.h>
#include <NFSPluginSDK/Game.Carbon/Types/WRoadNav.h>
#include <NFSPluginSDK/Game.Carbon/Types/WRoadNavInfluence.h>
#include <NFSPluginSDK/Game.Carbon/Types/WWorldPos.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/ChunkBlock.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Class.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Collection.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Database.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/DataBlock.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Definition.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/DependencyNode.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/ExportManager.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/ExportNode.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/HashMap.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Instance.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/PointerNode.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Private.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/RefSpec.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/RGBA.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Vault.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/collisionreactions.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/gameplay.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/rigidbodyspecs.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/simsurface.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/trafficpattern.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/collisionreactionslayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/gameplaylayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/pvehiclelayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/rigidbodyspecslayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/simsurfacelayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Layouts/trafficpatternlayout.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/CircularQueue.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/FixedVector.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/Listable.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/ListableSet.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/Vector.h>

#endif  // NFSPLUGINSDK_GAME_CARBON_INCLUDEALLTYPES_H
