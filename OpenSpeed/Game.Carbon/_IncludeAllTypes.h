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

#ifndef OPENSPEED_GAME_CARBON_INCLUDEALLTYPES_H
#define OPENSPEED_GAME_CARBON_INCLUDEALLTYPES_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/ActionData.h>
#include <OpenSpeed/Game.Carbon/Types/AIAvoidable.h>
#include <OpenSpeed/Game.Carbon/Types/AIGoal.h>
#include <OpenSpeed/Game.Carbon/Types/AIParams.h>
#include <OpenSpeed/Game.Carbon/Types/AIPerpVehicle.h>
#include <OpenSpeed/Game.Carbon/Types/AITarget.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicle.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleCopCar.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleEmpty.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleGhost.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleHuman.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehiclePid.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehiclePursuit.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleRacecar.h>
#include <OpenSpeed/Game.Carbon/Types/AIVehicleTraffic.h>
#include <OpenSpeed/Game.Carbon/Types/Attachments.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib.h>
#include <OpenSpeed/Game.Carbon/Types/Behavior.h>
#include <OpenSpeed/Game.Carbon/Types/bList.h>
#include <OpenSpeed/Game.Carbon/Types/bNode.h>
#include <OpenSpeed/Game.Carbon/Types/Dynamics.h>
#include <OpenSpeed/Game.Carbon/Types/EventSequencer.h>
#include <OpenSpeed/Game.Carbon/Types/FECustomizationRecord.h>
#include <OpenSpeed/Game.Carbon/Types/FloatSpring.h>
#include <OpenSpeed/Game.Carbon/Types/Game.h>
#include <OpenSpeed/Game.Carbon/Types/GRacerInfo.h>
#include <OpenSpeed/Game.Carbon/Types/GRaceStatus.h>
#include <OpenSpeed/Game.Carbon/Types/Grid.h>
#include <OpenSpeed/Game.Carbon/Types/IAttachable.h>
#include <OpenSpeed/Game.Carbon/Types/IAttributeable.h>
#include <OpenSpeed/Game.Carbon/Types/IAvoidable.h>
#include <OpenSpeed/Game.Carbon/Types/IBody.h>
#include <OpenSpeed/Game.Carbon/Types/ICause.h>
#include <OpenSpeed/Game.Carbon/Types/ICheater.h>
#include <OpenSpeed/Game.Carbon/Types/ICollisionBody.h>
#include <OpenSpeed/Game.Carbon/Types/IDynamicsEntity.h>
#include <OpenSpeed/Game.Carbon/Types/IExplodeable.h>
#include <OpenSpeed/Game.Carbon/Types/IHumanAI.h>
#include <OpenSpeed/Game.Carbon/Types/IInput.h>
#include <OpenSpeed/Game.Carbon/Types/IInputPlayer.h>
#include <OpenSpeed/Game.Carbon/Types/IPerpetrator.h>
#include <OpenSpeed/Game.Carbon/Types/IPlayer.h>
#include <OpenSpeed/Game.Carbon/Types/IPursuit.h>
#include <OpenSpeed/Game.Carbon/Types/IPursuitAI.h>
#include <OpenSpeed/Game.Carbon/Types/IRacer.h>
#include <OpenSpeed/Game.Carbon/Types/IRenderable.h>
#include <OpenSpeed/Game.Carbon/Types/IResetable.h>
#include <OpenSpeed/Game.Carbon/Types/IRigidBody.h>
#include <OpenSpeed/Game.Carbon/Types/ISimable.h>
#include <OpenSpeed/Game.Carbon/Types/ITrafficAI.h>
#include <OpenSpeed/Game.Carbon/Types/IVehicle.h>
#include <OpenSpeed/Game.Carbon/Types/IVehicleAI.h>
#include <OpenSpeed/Game.Carbon/Types/IVehicleCache.h>
#include <OpenSpeed/Game.Carbon/Types/Physics.h>
#include <OpenSpeed/Game.Carbon/Types/PhysicsObject.h>
#include <OpenSpeed/Game.Carbon/Types/PVehicle.h>
#include <OpenSpeed/Game.Carbon/Types/RideInfo.h>
#include <OpenSpeed/Game.Carbon/Types/Sim.h>
#include <OpenSpeed/Game.Carbon/Types/TimeOfDay.h>
#include <OpenSpeed/Game.Carbon/Types/Timer.h>
#include <OpenSpeed/Game.Carbon/Types/UCrc32.h>
#include <OpenSpeed/Game.Carbon/Types/USpline.h>
#include <OpenSpeed/Game.Carbon/Types/UTL.h>
#include <OpenSpeed/Game.Carbon/Types/VehicleBehavior.h>
#include <OpenSpeed/Game.Carbon/Types/VehicleCustomizations.h>
#include <OpenSpeed/Game.Carbon/Types/VehicleParams.h>
#include <OpenSpeed/Game.Carbon/Types/WRoadNav.h>
#include <OpenSpeed/Game.Carbon/Types/WRoadNavInfluence.h>
#include <OpenSpeed/Game.Carbon/Types/WWorldPos.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/ChunkBlock.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Class.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Collection.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Database.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/DataBlock.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Definition.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/DependencyNode.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/ExportManager.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/ExportNode.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/HashMap.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Instance.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/PointerNode.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Private.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/RefSpec.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/RGBA.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Vault.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/collisionreactions.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/gameplay.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/pvehicle.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/rigidbodyspecs.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/simsurface.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/trafficpattern.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/collisionreactionslayout.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/gameplaylayout.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/pvehiclelayout.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/rigidbodyspecslayout.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/simsurfacelayout.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Layouts/trafficpatternlayout.h>
#include <OpenSpeed/Game.Carbon/Types/UTL/CircularQueue.h>
#include <OpenSpeed/Game.Carbon/Types/UTL/FixedVector.h>
#include <OpenSpeed/Game.Carbon/Types/UTL/Listable.h>
#include <OpenSpeed/Game.Carbon/Types/UTL/ListableSet.h>
#include <OpenSpeed/Game.Carbon/Types/UTL/Vector.h>

#endif  // OPENSPEED_GAME_CARBON_INCLUDEALLTYPES_H
