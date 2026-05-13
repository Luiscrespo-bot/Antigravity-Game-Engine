#include "PerspectiveCamera.h"

namespace Engine {

    PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip)
        : Camera(glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip)), m_ViewMatrix(1.0f) {
        m_ViewProjectionMatrix = m_Projection * m_ViewMatrix;
    }

    void PerspectiveCamera::SetProjection(float fov, float aspectRatio, float nearClip, float farClip) {
        m_Projection = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
        m_ViewProjectionMatrix = m_Projection * m_ViewMatrix;
    }

    void PerspectiveCamera::RecalculateViewMatrix() {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
            glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

        m_ViewMatrix = glm::inverse(transform);
        m_ViewProjectionMatrix = m_Projection * m_ViewMatrix;
    }

}
