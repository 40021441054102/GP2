# ifndef RK_GRAPHICS_PROJECT_2_CONFIGS
    /**
     * @file Configs2.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Configuration File for World Model
     * @def RK_GRAPHICS_PROJECT_2_CONFIGS
     * @date 2024-12-08
     */
    # define RK_GRAPHICS_PROJECT_2_CONFIGS
    //-- Behave According to Android or Linux
    # ifdef __ANDROID__
        /**
         * @brief World Model Window Width
         * @def RK_WORLD_MODEL_WINDOW_WIDTH
         */
        # define RK_WORLD_MODEL_WINDOW_WIDTH 1080
        /**
         * @brief World Model Window Height
         * @def RK_WORLD_MODEL_WINDOW_HEIGHT
         */
        # define RK_WORLD_MODEL_WINDOW_HEIGHT 2400
        /**
         * @brief World Model Window Length
         * @def RK_WORLD_MODEL_WINDOW_LENGTH
         */
        # define RK_WORLD_MODEL_WINDOW_LENGTH 1800
    # else
        /**
         * @brief World Model Window Width
         * @def RK_WORLD_MODEL_WINDOW_WIDTH
         */
        # define RK_WORLD_MODEL_WINDOW_WIDTH 2200
        /**
         * @brief World Model Window Height
         * @def RK_WORLD_MODEL_WINDOW_HEIGHT
         */
        # define RK_WORLD_MODEL_WINDOW_HEIGHT 1440
        /**
         * @brief World Model Window Length
         * @def RK_WORLD_MODEL_WINDOW_LENGTH
         */
        # define RK_WORLD_MODEL_WINDOW_LENGTH 1800
    # endif // __ANDROID__
    /**
     * @brief World Model X-Axis Rotation Angle Increment
     * @def RK_WORLD_MODEL_ANGLE_INCREMENT_X
     * @note This is the Increment Value for Rotation of X-Axis
     */
    # define RK_WORLD_MODEL_ANGLE_INCREMENT_X 1.0
    /**
     * @brief World Model Y-Axis Rotation Angle Increment
     * @def RK_WORLD_MODEL_ANGLE_INCREMENT_Y
     * @note This is the Increment Value for Rotation of Y-Axis
     */
    # define RK_WORLD_MODEL_ANGLE_INCREMENT_Y 0.1
    /**
     * @brief World Model Z-Axis Rotation Angle Increment
     * @def RK_WORLD_MODEL_ANGLE_INCREMENT_Z
     * @note This is the Increment Value for Rotation of Z-Axis
     */
    # define RK_WORLD_MODEL_ANGLE_INCREMENT_Z 2.0
    /**
     * @brief World Model Textures Path
     * @def RK_WORLD_MODEL_TEXTURES_PATH
     * @note This is the Path to Textures for World Model
     */
    # define RK_WORLD_MODEL_TEXTURES_PATH "../GP2/WoldModel/Assets/"
# endif // RK_GRAPHICS_PROJECT_2_CONFIGS