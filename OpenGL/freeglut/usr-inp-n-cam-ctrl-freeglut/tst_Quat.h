#pragma once
#include <gtest/gtest.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
#include "Quat.h"

using namespace testing;

TEST(Quatf, dot)
{
    float q1[4] = { 934.89f, 952.85f, 156.81f, 662.89f };
    float q2[4] = { 279.08f, 272.97f, 616.44f, 2.43f };

    Quatf q1_(q1[0], q1[1], q1[2], q1[3]);
    Quatf q2_(q2[0], q2[1], q2[2], q2[3]);

    btQuaternion _q1(q1[0], q1[1], q1[2], q1[3]);
    btQuaternion _q2(q2[0], q2[1], q2[2], q2[3]);

    ASSERT_FLOAT_EQ(q1_.dot(q2_), _q1.dot(_q2));
}