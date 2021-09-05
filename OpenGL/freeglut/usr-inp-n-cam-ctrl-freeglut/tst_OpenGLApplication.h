#pragma once

TEST(OpenGLApplication, UpdateCamera)
{
    auto const RADIANS_PER_DEGREE = 0.01745329f;
    float const cameraPitch = 20;
    float const cameraYaw = 5;
    float const cameraDistance = 15.0f;
    float pitch = cameraPitch * RADIANS_PER_DEGREE;
    float yaw = cameraYaw * RADIANS_PER_DEGREE;

    btVector3 const upVector1(0.0f, 1.0f, 0.0f);
    Vec3f const upVector2(0.0f, 1.0f, 0.0f);

    btVector3 const cameraTarget1(0.0f, 0.0f, 0.0f);
    Vec3f const cameraTarget2(0.0f, 0.0f, 0.0f);

    btQuaternion rotation1(upVector1, yaw);
    Quatf rotation2(upVector2, yaw);
    ASSERT_FLOAT_EQ(rotation1.x(), rotation2.qx());
    ASSERT_FLOAT_EQ(rotation1.y(), rotation2.qy());
    ASSERT_FLOAT_EQ(rotation1.z(), rotation2.qz());
    ASSERT_FLOAT_EQ(rotation1.w(), rotation2.qw());

    btVector3 cameraPosition(0,0,0);
    cameraPosition[2] = -cameraDistance;

    btVector3 forward(cameraPosition[0], cameraPosition[1], cameraPosition[2]);
    if (forward.length2() < SIMD_EPSILON) {
        forward.setValue(1.f,0.f,0.f);
    }

    btVector3 right = upVector1.cross(forward);

    btQuaternion roll(right, - pitch);

    cameraPosition = btMatrix3x3(rotation1) * btMatrix3x3(roll) * cameraPosition;

    btVector3 resultCameraPosition;
    resultCameraPosition[0] = cameraPosition.getX();
    resultCameraPosition[1] = cameraPosition.getY();
    resultCameraPosition[2] = cameraPosition.getZ();
    resultCameraPosition += cameraTarget1;

//    std::clog << resultCameraPosition.x()
//    << ", " << resultCameraPosition.y()
//    << ", " << resultCameraPosition.z() << std::endl;
}
