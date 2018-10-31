#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Camera
{
    public:
        Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
        {
            m_perspective = glm::perspective(fov, aspect, zNear, zFar);
            m_position = pos;
            m_forward = glm::vec3(0, 0, 1);
            m_up = glm::vec3(0, -1, 0);
            m_rotation = glm::vec3(0, 0, 0);
        }

        inline glm::mat4 GetViewProjection() const
        {
            glm::mat4 returnMatrix = glm::lookAt(m_position, m_position + m_forward, m_up);
            returnMatrix = m_perspective * returnMatrix;
            return returnMatrix;
        }

        void SetRotation(glm::vec3 rotation)
        {
            m_rotation = rotation;
            if (m_rotation.y != 0)
            {
                m_forward.x = glm::sin(m_rotation.y); //Y
                m_forward.z = glm::cos(m_rotation.y); //Y
            }
            if (m_rotation.x != 0)
            {
                m_forward.y = glm::sin(m_rotation.x); //X
                m_forward.z = glm::cos(m_rotation.x); //X
            }
        }

        void AddRotation(glm::vec3 rotation)
        {
            m_rotation += rotation;
            if (m_rotation.y != 0)
            {
                m_forward.x = glm::sin(m_rotation.y); //Y
                m_forward.z = glm::cos(m_rotation.y); //Y
            }
            if (m_rotation.x != 0)
            {
                m_forward.y = glm::sin(m_rotation.x); //X
                m_forward.z = glm::cos(m_rotation.x); //X
            }
        }

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_up;

        glm::vec3 m_rotation;
};

#endif // CAMERA_H
