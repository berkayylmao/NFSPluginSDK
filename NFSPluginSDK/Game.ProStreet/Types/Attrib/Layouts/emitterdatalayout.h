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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_EMITTERDATALAYOUT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_EMITTERDATALAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/RefSpec.h>

namespace NFSPluginSDK::ProStreet::Attrib::Layouts {
  enum class EffectParticleAnimation : std::uint32_t {
    ANIMATE_PARTICLE_NONE  = 0x0,
    ANIMATE_PARTICLE_2x2   = 1 << 1,
    ANIMATE_PARTICLE_4x4   = 1 << 2,
    ANIMATE_PARTICLE_8x8   = 1 << 3,
    ANIMATE_PARTICLE_16x16 = 1 << 4,
  };
  struct ParticleAnimationInfo {
    EffectParticleAnimation AnimType;
    char                    FPS;
    char                    RandomStartFrame;
  };
  enum class eTEG_ParticleTextures : std::uint32_t {
    FX_GRASS01_BLEND_ANIM              = 0xFBBC7865,
    FX_CONFETTI2                       = 0xEC70A5AA,
    FX_GRAVEL_BLEND_ANIM               = 0x7884D1C5,
    FX_SMK01_BLEND                     = 0x82A192AC,
    FX_SMK06_BLEND                     = 0x384C271,
    FX_SMOKESHADER                     = 0x277A2772,
    FX_GLOW02_ADDITIVE                 = 0x85817260,
    FX_SMK07_BLEND                     = 0x507EFF32,
    FX_DEBRIS_GREY                     = 0xF7BEC12B,
    FX_CACTUS_BLEND_ANIM               = 0x7A3C53C7,
    FX_BUZZARD_01                      = 0x3E86ED5E,
    FX_DEBRIS01_BLEND_ANIM             = 0x7357B3E,
    FX_SPARK05_ADDITIVE                = 0xD5873F0B,
    FX_SMK04_BLEND                     = 0x699048EF,
    FX_SMK05_BLEND                     = 0xB68A85B0,
    FX_DEBRISSTONE1_BLEND              = 0x1647BD33,
    FX_STRIPE03_ADDITIVE               = 0x935611BF,
    FX_SMK02_BLEND                     = 0xCF9BCF6D,
    FX_SPARK04_ADDITIVE                = 0xD17CADEA,
    FX_SMK03_BLEND                     = 0x1C960C2E,
    FX_STRIPE01_ADDITIVE               = 0x8B40EF7D,
    FX_WOOD_PLANKS_BLEND_ANIM_COLR     = 0x773FE834,
    FX_GLASS01_BLEND_ANIM              = 0x8AA12C5F,
    FX_GLOW01_ADDITIVE                 = 0x8176E13F,
    FX_SPARK02_ADDITIVE                = 0xC9678BA8,
    FX_HAZE1                           = 0x7E5ECB75,
    FX_DEBRIS02_BLEND                  = 0x9E6479BB,
    FX_SMOKESHADER2                    = 0x16BF15E4,
    FX_STRIPE01_BLEND                  = 0x8D2E6C98,
    FX_WOOD_PLANKS_DRK_BLEND_ANIM_COLR = 0x945CF2D4,
    FX_SPARK01_ADDITIVE                = 0xC55CFA87,
    FX_WATER02_BLEND                   = 0xA8F05A25,
    FX_BEAN_BLEND                      = 0x8D746D76,
    FX_HAZE2                           = 0x7E5ECB76,
    FX_SPARK01_ADDITIVE_ANIM           = 0xEA4DB8EB,
    FX_FLARE_01_ADDITIVE               = 0x81AD168F,
    FX_SMK04_ADDITIVE                  = 0x90D50074,
    FX_WOOD_PLANKS_BLEND_ANIM          = 0xA665E9A5,
    FX_STRIPE02_ADDITIVE               = 0x8F4B809E,
    FX_WATER01_BLEND                   = 0x5BF61D64,
    FX_WATER03_BLEND                   = 0xF5EA96E6,
    FX_CONFETTI                        = 0x35B5D678,
    FX_GREYGRAD32                      = 0x54E298F6,
    FX_SPARK03_ADDITIVE                = 0xCD721CC9,
    FX_GREYGRAD32_ADD                  = 0xC607597E,
  };
  struct ParticleTextureRecord {
    eTEG_ParticleTextures mEnum;
    std::uint32_t         mIndex;
  };
  enum class EmitterPostProcessingEffect : std::uint32_t {
    EmitterPostProcessingEffect_NONE  = 0x0,
    EmitterPostProcessingEffect_SMOKE = 0x1,
  };
  enum class EffectParticleConstraint : std::uint32_t {
    CONSTRAIN_PARTICLE_NONE    = 0x0,
    CONSTRAIN_PARTICLE_XY_AXIS = 0x6,
    CONSTRAIN_PARTICLE_XZ_AXIS = 0x5,
    CONSTRAIN_PARTICLE_YZ_AXIS = 0x3,
    CONSTRAIN_PARTICLE_CAMERA  = 0x8,
  };

  struct emitterdatalayout {
    UMath::Vector4              VolumeExtent;
    UMath::Vector4              VolumeCenter;
    UMath::Vector4              VelocityStart;
    UMath::Vector4              VelocityDelta;
    UMath::Vector4              Size;
    UMath::Vector4              KeyPositions;
    UMath::Vector4              AccelStart;
    UMath::Vector4              AccelDelta;
    const char*                 CollectionName;
    ParticleAnimationInfo       TextureAnimation;
    ParticleTextureRecord       Texture;
    bool                        StartDelayRandomVariance;
    float                       StartDelay;
    std::int32_t                SpreadAsDisc;
    float                       SpreadAngle;
    float                       SpeedVariance;
    float                       Speed;
    float                       SizeVariance;
    float                       RotationVariance;
    float                       RotationalVelocityEnd;
    float                       RotationalVelocity;
    std::int32_t                RandomRotationDirection;
    EmitterPostProcessingEffect PostProcessingEffect;
    float                       OnCycleVariance;
    float                       OnCycle;
    float                       OffCycleVariance;
    float                       OffCycle;
    float                       NumParticlesVariance;
    float                       NumParticles;
    std::int32_t                MotionLive;
    float                       MotionInheritVariance;
    float                       MotionInherit;
    float                       LifeVariance;
    float                       Life;
    bool                        IsOneShot;
    float                       InitialAngleRange;
    float                       Gravity;
    float                       FarClip;
    bool                        EliminateUnnecessaryRandomness;
    float                       Drag;
    float                       ColorVariance;
    std::uint32_t               Color4;
    std::uint32_t               Color3;
    std::uint32_t               Color2;
    std::uint32_t               Color1;
    float                       BounceDampen;
    EffectParticleConstraint    AxisConstraint;
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_EMITTERDATALAYOUT_H
