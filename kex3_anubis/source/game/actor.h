//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "gameObject.h"
#include "sdNodes.h"
#include "world.h"

typedef enum
{
    AT_INVALID  = -1,
    AT_PLAYER   = 0,
    AT_ANUBIS,
    AT_BASTET,
    AT_CROW,
    AT_QUEEN,
    AT_MANTIS,
    AT_MUMMY,
    AT_MOSQUITO,
    AT_FISH,
    AT_SELKIS,
    AT_SENTRY,
    AT_SET,
    AT_SPIDER,
    AT_MAGIC8BALL,
    AT_MISC1,
    AT_MISC2,
    AT_MISC3,
    AT_MISC4,
    AT_MISC5,
    AT_MISC6,
    AT_MISC7,
    AT_MISC8,
    AT_MISC9,
    AT_MISC10,
    AT_MISC11,
    AT_MISC12,
    AT_MISC13,
    AT_MISC14,
    AT_MISC15,
    AT_BUGKEY,
    AT_TIMEKEY,
    AT_XKEY,
    AT_PLANTKEY,
    AT_PYRAMID,
    AT_SANDALS,
    AT_MASK,
    AT_SHAWL,
    AT_ANKLETS,
    AT_SCEPTER,
    AT_FEATHER,
    AT_HEALTH,
    AT_AMMO,
    AT_PISTOL,
    AT_M60,
    AT_ANUSBOMB,
    AT_FLAMER,
    AT_STAFF,
    AT_RING,
    AT_MANACLE,
    AT_FLAMEPOT,
    AT_SNAKEPOT,
    AT_FULLAMMO,
    AT_FULLHEALTH,
    AT_VESSEL1,
    AT_VESSEL2,
    AT_VESSEL3,
    AT_VESSEL4,
    AT_VESSEL5,
    AT_CAMEL,
    AT_MISC16,
    AT_MISC17,
    AT_MISC18,
    AT_MISC19,
    AT_MISC20,
    AT_MISC21,
    AT_MISC22,
    AT_BLOW1,
    AT_BLOW2,
    AT_BLOW3,
    AT_BLOW4,
    AT_BLOW5,
    AT_BLOW6,
    AT_BLOW7,
    AT_BLOW8,
    AT_CBANG,
    AT_DOG,
    AT_KBANG,
    AT_MBANG,
    AT_PBANG,
    AT_SBANG,
    AT_TBANG,
    AT_TOMB1,
    AT_VAS,
    AT_BOWL,
    AT_CAMP1,
    AT_CAMP2,
    AT_CAMP3,
    AT_CHAOS1,
    AT_CHAOS2,
    AT_COL1,
    AT_COL2,
    AT_COL3,
    AT_FLAME,
    AT_GLOW,
    AT_HANT1,
    AT_HANT2,
    AT_HANT3,
    AT_HANT4,
    AT_MAGMA1,
    AT_MAGMA2,
    AT_MARSH1,
    AT_MUMY1,
    AT_PERIL1,
    AT_QUAR1,
    AT_SELKIS1,
    AT_SELKIS2,
    AT_SET1,
    AT_SET2,
    AT_SET3,
    AT_SET4,
    AT_THOTH1,
    AT_THOTH2,
    AT_THOTH3,
    AT_TOM1,
    AT_TOM2,
    AT_OOOPS,
    AT_TOWN1,
    AT_WALLTORCH,
    AT_WALLTORCH1,
    AT_WALLTORCH2,
    AT_WTRLITE,
    AT_PLANT1,
    AT_PLANT2,
    AT_PLANT3,
    AT_PLANT4,
    AT_BUBBLE1,
    AT_FISH2,
    AT_FALS,
    AT_WTRBUBS,
    AT_BRANCH1,
    AT_GLOW1,
    AT_CHOPPER,
    AT_TRANS1,
    AT_TRANS2,
    AT_TRANS3,
    AT_TRANS4,
    AT_TRANS5,
    AT_TRANS6,
    AT_TRANS7,
    AT_TRANS8,
    AT_MISC23,
    AT_MISC24,
    AT_MISC25,
    AT_MISC26,
    AT_MISC27,
    AT_MISC28,
    AT_MISC29,
    AT_TEAMDOLL1,
    AT_TEAMDOLL2,
    AT_TEAMDOLL3,
    AT_TEAMDOLL4,
    AT_TEAMDOLL5,
    AT_TEAMDOLL6,
    AT_TEAMDOLL7,
    AT_TEAMDOLL8,
    AT_TEAMDOLL9,
    AT_TEAMDOLL10,
    AT_TEAMDOLL11,
    AT_TEAMDOLL12,
    AT_TEAMDOLL13,
    AT_TEAMDOLL14,
    AT_TEAMDOLL15,
    AT_TEAMDOLL16,
    AT_TEAMDOLL17,
    AT_TEAMDOLL18,
    AT_TEAMDOLL19,
    AT_TEAMDOLL20,
    AT_TEAMDOLL21,
    AT_TEAMDOLL22,
    AT_TEAMDOLL23,
    AT_R1,
    AT_R2,
    AT_R3,
    AT_R4,
    AT_R5,
    AT_R6,
    NUMACTORTYPES
} actorType_t;

typedef enum
{
    AF_FLOORFRICTION    = BIT(0),
    AF_CEILINGFRICTION  = BIT(1)
} actorFlags_t;

//-----------------------------------------------------------------------------
//
// kexActor
//
//-----------------------------------------------------------------------------

BEGIN_EXTENDED_KEX_CLASS(kexActor, kexGameObject);
public:
    kexActor(void);
    ~kexActor(void);

    virtual void                    Tick(void);

    void                            Spawn(void);
    bool                            FindSector(const kexVec3 &pos);
    void                            LinkArea(void);
    void                            UnlinkArea(void);

    kexVec3                         &Velocity(void) { return velocity; }
    kexVec3                         &Movement(void) { return movement; }
    mapSector_t                     *Sector(void) { return sector; }
    void                            SetSector(mapSector_t *s) { sector = s; }
    mapActor_t                      *MapActor(void) { return mapActor; }
    kexLinklist<kexActor>           &Link(void) { return link; }
    kexBBox                         &Bounds(void) { return bounds; }
    const actorType_t               Type(void) const { return type; }
    int16_t                         &Health(void) { return health; }
    void                            SetMapActor(mapActor_t *ma) { mapActor = ma; }
    const float                     Radius(void) const { return radius; }
    const float                     Height(void) const { return height; }
    const float                     StepHeight(void) const { return stepHeight; }
    const float                     Gravity(void) const { return gravity; }
    unsigned int                    &Flags(void) { return flags; }
    float                           &FloorHeight(void) { return floorHeight; }
    float                           &CeilingHeight(void) { return ceilingHeight; }

    kexSDNodeRef<kexActor>          &AreaLink(void) { return areaLink; }

protected:
    kexSDNodeRef<kexActor>          areaLink;

    float                           radius;
    float                           height;
    float                           scale;
    float                           stepHeight;
    float                           gravity;
    int16_t                         health;
    kexVec3                         velocity;
    kexVec3                         movement;
    kexLinklist<kexActor>           link;
    kexBBox                         bounds;
    mapSector_t                     *sector;
    mapActor_t                      *mapActor;
    actorType_t                     type;
    unsigned int                    flags;
    float                           floorHeight;
    float                           ceilingHeight;
END_KEX_CLASS();

#endif
