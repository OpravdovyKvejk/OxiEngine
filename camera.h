#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SDL2/SDL.h>
#include <iostream>


class Camera
{
    public:
        Camera(float aspect = 1280/720, const glm::vec3& pos = glm::vec3(0, 0, 0), bool mouselook = false, float speed = 0.1f, float fov = 80.0f, float zNear = 0.01f, float zFar = 1000.0f)
        {
            m_perspective = glm::perspective(glm::radians(fov), aspect, zNear, zFar);
            m_position = pos;
            m_forward = glm::vec3(0, 0, 0);
            m_up = glm::vec3(0, -1, 0);
            m_rotation = glm::vec3(0, 0, 0);
            m_speed = speed;
            m_mouselook = mouselook;
        }

        inline glm::mat4 GetViewProjection() const
        {
            //glm::mat4 returnMatrix = glm::lookAt(m_position, m_position + m_forward, m_up);
            glm::mat4 returnMatrix = glm::lookAt(m_position, m_forward, m_up);
            returnMatrix = m_perspective * returnMatrix;
            return returnMatrix;
        }

        void MoveForward(glm::vec3 angleOffset)
        {
            m_position.x += glm::sin(m_rotation.y + angleOffset.y) * m_speed;//Y
            m_position.z += glm::cos(m_rotation.y + angleOffset.y) * m_speed;//Y
            UpdateForward();
        }

        void SetRotation(glm::vec3 rotation)
        {
            m_rotation = rotation;
            UpdateForward();
        }

        void AddRotation(glm::vec3 rotation)
        {
            m_rotation += rotation;
            UpdateForward();
        }

        void UpdateForward()
        {
            m_forward.x = m_position.x + glm::sin(m_rotation.y); //Yrot

            m_forward.y = m_position.y + glm::sin(m_rotation.x); //Xrot

            m_forward.z = m_position.z + glm::cos(m_rotation.x) * glm::cos(m_rotation.y); //Xrot & Yrot
        }

        void SetSpeed(float speed)
        { m_speed = speed; }

        void AddSpeed(float speed)
        { m_speed += speed; }

        float GetSpeed()
        { return m_speed; }

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_up;

        glm::vec3 m_rotation;
        float m_speed;
        bool m_mouselook;
};

#endif // CAMERA_H
