// Author: François Faure, INRIA-UJF, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
#include "SpringForceField.inl"
#include "Common/Vec3Types.h"
#include "Sofa/Core/MechanicalObject.h"
#include "Common/ObjectFactory.h"

//#include <typeinfo>

namespace Sofa
{

namespace Components
{

SOFA_DECL_CLASS(SpringForceField)

using namespace Common;

template class SpringForceField<Vec3dTypes>;
template class SpringForceField<Vec3fTypes>;

template<class DataTypes>
void create(SpringForceField<DataTypes>*& obj, ObjectDescription* arg)
{
    XML::createWithParentAndFilename< SpringForceField<DataTypes>, Core::MechanicalObject<DataTypes> >(obj, arg);
    if (obj == NULL) // try the InteractionForceField initialization
        XML::createWith2ObjectsAndFilename< SpringForceField<DataTypes>, Core::MechanicalObject<DataTypes>, Core::MechanicalObject<DataTypes> >(obj, arg);
}

Creator< ObjectFactory, SpringForceField<Vec3dTypes> > SpringInteractionForceFieldVec3dClass("SpringForceField", true);
Creator< ObjectFactory, SpringForceField<Vec3fTypes> > SpringInteractionForceFieldVec3fClass("SpringForceField", true);

} // namespace Components

} // namespace Sofa
