#pragma once
#include <gtest/gtest.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
#include "Vec3.h"

using namespace testing;

TEST(Vec3f, length)
{
    float v[3] = { 934.89f, 952.85f, 156.81f };
    Vec3f v1(v[0], v[1], v[2]);
    btVector3 v2(v[0], v[1], v[2]);
    ASSERT_FLOAT_EQ(v1.length(), v2.length());
}

TEST(Vec3f, length2)
{
    float v[3] = { 565.61f, 158.04f, 346.05f };
    Vec3f v1(v[0], v[1], v[2]);
    btVector3 v2(v[0], v[1], v[2]);
    ASSERT_FLOAT_EQ(v1.length2(), v2.length2());
}

TEST(Vec3f, normalize)
{
    float v[3] = { 316.82f, 549.44f, 480.40f };
    Vec3f v1(v[0], v[1], v[2]);
    btVector3 v2(v[0], v[1], v[2]);

    v1.normalize();
    v2.normalize();

    ASSERT_FLOAT_EQ(v1.x(), v2.x());
    ASSERT_FLOAT_EQ(v1.y(), v2.y());
    ASSERT_FLOAT_EQ(v1.z(), v2.z());
}

TEST(Vec3f, cross)
{
    float v1[3] = { 943.11f, 376.64f, 80.97f };
    float v2[3] = { 616.82f, 560.51f, 31.14f };

    Vec3f v1_(v1[0], v1[1], v1[2]);
    Vec3f v2_(v2[0], v2[1], v2[2]);
    auto v3_ = v1_.cross(v2_);

    btVector3 _v1(v1[0], v1[1], v1[2]);
    btVector3 _v2(v2[0], v2[1], v2[2]);
    auto _v3 = _v1.cross(_v2);

    ASSERT_FLOAT_EQ(v3_.x(), _v3.x());
    ASSERT_FLOAT_EQ(v3_.y(), _v3.y());
    ASSERT_FLOAT_EQ(v3_.z(), _v3.z());
}

TEST(Vec3f, addition)
{
    float v1[3] = { 231.26f, 174.39f, 960.72f };
    float v2[3] = { 551.04f, 54.79f, 731.49f };

    Vec3f v1_(v1[0], v1[1], v1[2]);
    Vec3f v2_(v2[0], v2[1], v2[2]);
    auto v3_ = v1_ + v2_;

    btVector3 _v1(v1[0], v1[1], v1[2]);
    btVector3 _v2(v2[0], v2[1], v2[2]);
    auto _v3 = _v1 + _v2;

    ASSERT_FLOAT_EQ(v3_.x(), _v3.x());
    ASSERT_FLOAT_EQ(v3_.y(), _v3.y());
    ASSERT_FLOAT_EQ(v3_.z(), _v3.z());
}

TEST(Vec3f, addition_assignment)
{
    float v1[3] = { 151.51f, 986.78f, 412.47f };
    float v2[3] = { 5.08f, 783.87f, 409.65f };

    Vec3f v1_(v1[0], v1[1], v1[2]);
    Vec3f v2_(v2[0], v2[1], v2[2]);
    v1_ += v2_;

    btVector3 _v1(v1[0], v1[1], v1[2]);
    btVector3 _v2(v2[0], v2[1], v2[2]);
    _v1 += _v2;

    ASSERT_FLOAT_EQ(v1_.x(), _v1.x());
    ASSERT_FLOAT_EQ(v1_.y(), _v1.y());
    ASSERT_FLOAT_EQ(v1_.z(), _v1.z());
}

TEST(Vec3f, subtraction)
{
    float v1[3] = { 7.85f, 184.46f, 513.38f };
    float v2[3] = { 786.02f, 241.50f, 211.28f };

    Vec3f v1_(v1[0], v1[1], v1[2]);
    Vec3f v2_(v2[0], v2[1], v2[2]);
    auto v3_ = v1_ - v2_;

    btVector3 _v1(v1[0], v1[1], v1[2]);
    btVector3 _v2(v2[0], v2[1], v2[2]);
    auto _v3 = _v1 - _v2;

    ASSERT_FLOAT_EQ(v3_.x(), _v3.x());
    ASSERT_FLOAT_EQ(v3_.y(), _v3.y());
    ASSERT_FLOAT_EQ(v3_.z(), _v3.z());
}

TEST(Vec3f, subscript)
{
    float v[3] = { 471.91f, 353.48f, 945.39f };
    Vec3f v1(v[0], v[1], v[2]);
    btVector3 v2(v[0], v[1], v[2]);
    ASSERT_FLOAT_EQ(v1[0], v2[0]);
    ASSERT_FLOAT_EQ(v1[1], v2[1]);
    ASSERT_FLOAT_EQ(v1[2], v2[2]);
}