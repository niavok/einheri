/*
 * MonsterAI.cpp
 *
 *  Created on: 5 sept. 2010
 *      Author: fred
 */

#include "PhysicEntity.h"

#include <iostream>

namespace ein {

PhysicEntity::PhysicEntity(Movable *movable) :
    movable(movable) {

    sphereShape = new btSphereShape(0.4);

    motionState = new KinematicMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)), movable);

    btScalar mass = 1;
    btVector3 sphereInertia(0, 0, 0);
    sphereShape->calculateLocalInertia(mass, sphereInertia);

    btRigidBody::btRigidBodyConstructionInfo sphereRigidBodyCI(mass, motionState, sphereShape, sphereInertia);
    rigidBody = new btRigidBody(sphereRigidBodyCI);
    rigidBody->setLinearFactor(btVector3(1, 1, 0));
    rigidBody->setAngularFactor(btVector3(0, 0, 1));
    rigidBody->setUserPointer(this);
}

PhysicEntity::~PhysicEntity() {
    delete rigidBody;
    delete motionState;
    delete sphereShape;

}

void PhysicEntity::SetMass(EinValue mass) {
    btVector3 sphereInertia(0, 0, 0);
    sphereShape->calculateLocalInertia(mass, sphereInertia);
    rigidBody->setMassProps(mass, sphereInertia);
}


void PhysicEntity::Import() {

    btTransform trans = rigidBody->getCenterOfMassTransform();
    trans.setOrigin(btVector3(movable->GetPosition().getX(), movable->GetPosition().getY(), 0));
    rigidBody->setCenterOfMassTransform(trans);

    //trans.setRotation(btQuaternion(btVector3(0,0,1), movable->GetAngle()));

    EinValue maxAcc = 0.1;

    EinValue accX = movable->GetTargetedSpeed().getX() - movable->GetSpeed().getX();
    if (accX > maxAcc) {
        accX = maxAcc;
    }

    if (accX < -maxAcc) {
        accX = -maxAcc;
    }

    EinValue accY = movable->GetTargetedSpeed().getY() - movable->GetSpeed().getY();
    if (accY > maxAcc) {
        accY = maxAcc;
    }

    if (accY < -maxAcc) {
        accY = -maxAcc;
    }

    rigidBody->setLinearVelocity(btVector3(movable->GetSpeed().getX() + accX, movable->GetSpeed().getY() + accY, 0));

    rigidBody->activate(true);

}

void PhysicEntity::Export() {
    //btTransform trans;
    //rigidBody->getMotionState()->getWorldTransform(trans);
    //movable->SetPosition(Vector(trans.getOrigin().x(),trans.getOrigin().y()));

    //movable->SetAngle(trans.getRotation().getAngle());

    movable->SetSpeed(Vector(rigidBody->getLinearVelocity().x(), rigidBody->getLinearVelocity().y()));

}

}
