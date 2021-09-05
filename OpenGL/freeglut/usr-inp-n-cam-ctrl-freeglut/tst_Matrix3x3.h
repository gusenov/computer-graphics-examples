#pragma once
#include <gtest/gtest.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
#include "Matrix3x3.h"

using namespace testing;

TEST(Matrix3x3f, ctor_quaternion)
{
    float q[4] = { 934.89f, 952.85f, 156.81f, 662.89f };

    Quatf q_(q[0], q[1], q[2], q[3]);
    btQuaternion _q(q[0], q[1], q[2], q[3]);

    Matrix3x3f m_(q_);
    btMatrix3x3 _m(_q);

    ASSERT_FLOAT_EQ(m_.at(0, 0), _m[0][0]);
    ASSERT_FLOAT_EQ(m_.at(0, 1), _m[0][1]);
    ASSERT_FLOAT_EQ(m_.at(0, 2), _m[0][2]);

    ASSERT_FLOAT_EQ(m_.at(1, 0), _m[1][0]);
    ASSERT_FLOAT_EQ(m_.at(1, 1), _m[1][1]);
    ASSERT_FLOAT_EQ(m_.at(1, 2), _m[1][2]);

    ASSERT_FLOAT_EQ(m_.at(2, 0), _m[2][0]);
    ASSERT_FLOAT_EQ(m_.at(2, 1), _m[2][1]);
    ASSERT_FLOAT_EQ(m_.at(2, 2), _m[2][2]);
}

TEST(Matrix3x3f, multiplication_vector)
{
    float m[3][3] = {
        { 630.75f, 748.05f, 153.62f },
        { 322.98f, 226.65f, 41.73f },
        { 617.13f, 154.51f, 308.01f },
    };

    float v[3] = { 231.67f, 212.14f, 276.82f };

    Matrix3x3f m_(
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2]
    );
    Vec3f v_(v[0], v[1], v[2]);

    btMatrix3x3 _m(
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2]
    );
    btVector3 _v(v[0], v[1], v[2]);

    auto v2_ = m_ * v_;
    auto _v2 = _m * _v;

    ASSERT_FLOAT_EQ(v2_.x(), _v2.x());
    ASSERT_FLOAT_EQ(v2_.y(), _v2.y());
    ASSERT_FLOAT_EQ(v2_.z(), _v2.z());
}

TEST(Matrix3x3f, multiplication_matrix)
{
    float m1[3][3] = {
        { 793.77f, 115.95f, 236.00f },
        {  12.51f,  88.71f,   8.35f },
        { 647.18f, 305.92f, 394.91f },
    };

    float m2[3][3] = {
        {  28.01f, 671.51f, 263.32f },
        { 788.27f, 803.04f, 134.33f },
        { 243.61f, 459.39f, 394.16f },
    };

    Matrix3x3f m1_(
        m1[0][0], m1[0][1], m1[0][2],
        m1[1][0], m1[1][1], m1[1][2],
        m1[2][0], m1[2][1], m1[2][2]
    );

    Matrix3x3f m2_(
        m2[0][0], m2[0][1], m2[0][2],
        m2[1][0], m2[1][1], m2[1][2],
        m2[2][0], m2[2][1], m2[2][2]
    );

    btMatrix3x3 _m1(
        m1[0][0], m1[0][1], m1[0][2],
        m1[1][0], m1[1][1], m1[1][2],
        m1[2][0], m1[2][1], m1[2][2]
    );

    btMatrix3x3 _m2(
        m2[0][0], m2[0][1], m2[0][2],
        m2[1][0], m2[1][1], m2[1][2],
        m2[2][0], m2[2][1], m2[2][2]
    );

    auto m3_ = m1_ * m2_;
    auto _m3 = _m1 * _m2;

    ASSERT_FLOAT_EQ(m3_.at(0, 0), _m3[0][0]);
    ASSERT_FLOAT_EQ(m3_.at(0, 1), _m3[0][1]);
    ASSERT_FLOAT_EQ(m3_.at(0, 2), _m3[0][2]);

    ASSERT_FLOAT_EQ(m3_.at(1, 0), _m3[1][0]);
    ASSERT_FLOAT_EQ(m3_.at(1, 1), _m3[1][1]);
    ASSERT_FLOAT_EQ(m3_.at(1, 2), _m3[1][2]);

    ASSERT_FLOAT_EQ(m3_.at(2, 0), _m3[2][0]);
    ASSERT_FLOAT_EQ(m3_.at(2, 1), _m3[2][1]);
    ASSERT_FLOAT_EQ(m3_.at(2, 2), _m3[2][2]);
}