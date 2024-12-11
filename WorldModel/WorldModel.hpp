# ifndef RK_GRAPHICS_PROJECT_2
    /**
     * @file WorldModel.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Ramtin Kosari's World Model - Term 7 Graphics Project 2
     * @date 2024-12-08
     */
    # define RK_GRAPHICS_PROJECT_2
    /**
     * @brief Ramtin Kosari's World Model
     * @def RK_GRAPHICS_PROJECT_WORLD_MODEL
     * @note This is Part of Term 7 Graphics Project 2
     */
    # define RK_GRAPHICS_PROJECT_WORLD_MODEL
    //-- Check if Project is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configuration File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS2
            # error "Configuration File is Required for RK Graphics Project 2"
        # endif // RK_GRAPHICS_PROJECT_2_CONFIGS
        //-- Check if RKLogger is Configured
        # ifndef HAS_RKACPB_MODULE_RKLOGGER
            # error "RKLogger is Required for RK Graphics Project 2"
        # endif // HAS_RKACPB_MODULE_RKLOGGER
        //-- Check if RKOGLT is Configured
        # ifndef HAS_RKACPB_MODULE_RKOGLT
            # error "RKOGLT is Required for RK Graphics Project 2"
        # endif // HAS_RKACPB_MODULE_RKOGLT
        //-- Check if Window is Configured
        # ifndef HAS_RKACPB_MODULE_WINDOW
            # error "Window is Required for RK Graphics Project 2"
        # endif // HAS_RKACPB_MODULE_WINDOW
        //-- Check if Line is Configured
        # ifndef HAS_RKACPB_MODULE_LINE
            # error "Line is Required for RK Graphics Project 2"
        # endif // HAS_RKACPB_MODULE_LINE
        //-- Check if Polygon is Configured
        # ifndef HAS_RKACPB_MODULE_POLYGON
            # error "Polygon is Required for RK Graphics Project 2"
        # endif // HAS_RKACPB_MODULE_POLYGON
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef RK_GRAPHICS_PROJECT_2_CONFIGS
        # include "Configs2.hpp"
    # endif // RK_GRAPHICS_PROJECT_2_CONFIGS
    //-- Include RKLogger
    # ifndef RKLOGGER
        # include "RKLogger.hpp"
    # endif // RKLOGGER
    //-- Include RKOGLT
    # ifndef RKOGLT
        # include "RKOGLT.hpp"
    # endif // RKOGLT
    //-- Include Window
    # ifndef SYNESTIA_GRAPHICS_WINDOW
        # include "Window.hpp"
    # endif // SYNESTIA_GRAPHICS_WINDOW
    //-- Include Line
    # ifndef SYNESTIA_GRAPHICS_LINE
        # include "Line.hpp"
    # endif // SYNESTIA_GRAPHICS_LINE
    //-- Include Polygon
    # ifndef SYNESTIA_GRAPHICS_POLYGON
        # include "Polygon.hpp"
    # endif // SYNESTIA_GRAPHICS_POLYGON
    //-- Include Glut
    # ifndef __FREEGLUT_H__
        # include <GL/freeglut.h>
    # endif // __FREEGLUT_H__
    //-- Include Thread Library
    # ifndef _GLIBCXX_THREAD
        # include <thread>
    # endif // _GLIBCXX_THREAD
    //-- Include Chrono Library
    # ifndef _GLIBCXX_CHRONO
        # include <chrono>
    # endif // _GLIBCXX_CHRONO
    //-- Include Deque Library
    # ifndef _GLIBCXX_DEQUE
        # include <deque>
    # endif // _GLIBCXX_DEQUE
    //-- Include Unistd Library
    # ifndef _UNISTD_H
        # include <unistd.h>
    # endif // _UNISTD_H
    //-- Include Limits Library
    # ifndef _LIBC_LIMITS_H_
        # include <limits.h>
    # endif // _LIBC_LIMITS_H_
#include <limits.h>
    /**
     * @brief Ramtin Kosari's World Model Objects
     * @enum RKWorldModelObjects
     * @note This Enum Defines World Model Objects
     * @param RK_WORLD_MODEL_CUBE_WIRED Wired Cube
     * @param RK_WORLD_MODEL_CUBE_SOLID Solid Cube
     * @param RK_WORLD_MODEL_SPHERE_WIRED Wired Sphere
     * @param RK_WORLD_MODEL_SPHERE_SOLID Solid Sphere
     * @param RK_WORLD_MODEL_SPHERE_TEXTURED Textured Sphere
     * @param RK_WORLD_MODEL_CONE_WIRED Wired Cone
     * @param RK_WORLD_MODEL_CONE_SOLID Solid Cone
     * @param RK_WORLD_MODEL_TORUS_WIRED Wired Torus
     * @param RK_WORLD_MODEL_TORUS_SOLID Solid Torus
     * @param RK_WORLD_MODEL_FRACTAL_TREE Tree Fractal
     * @param RK_WORLD_MODEL_FRACTAL_SNOWFLAKE Snowflake Fractal
     */
    enum RKWorldModelObjects {
        RK_WORLD_MODEL_CUBE_WIRED,
        RK_WORLD_MODEL_CUBE_SOLID,
        RK_WORLD_MODEL_SPHERE_WIRED,
        RK_WORLD_MODEL_SPHERE_SOLID,
        RK_WORLD_MODEL_SPHERE_TEXTURED,
        RK_WORLD_MODEL_CONE_WIRED,
        RK_WORLD_MODEL_CONE_SOLID,
        RK_WORLD_MODEL_TORUS_WIRED,
        RK_WORLD_MODEL_TORUS_SOLID,
        RK_WORLD_MODEL_FRACTAL_TREE,
        RK_WORLD_MODEL_FRACTAL_SNOWFLAKE,
    };
    /**
     * @brief Ramtin Kosari's World Model Textures
     * @enum RKWorldModelTextures
     * @note This Enum Defines World Model Textures
     * @param RK_WORLD_MODEL_TEXTURE_EARTH Earth Texture
     * @param RK_WORLD_MODEL_TEXTURE_EARTH_2 Earth 2 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EARTH_NIGHT Earth Night Texture
     * @param RK_WORLD_MODEL_TEXTURE_MARS Mars Texture
     * @param RK_WORLD_MODEL_TEXTURE_JUPITER Jupiter Texture
     * @param RK_WORLD_MODEL_TEXTURE_SATURN Saturn Texture
     * @param RK_WORLD_MODEL_TEXTURE_PLUTO Pluto Texture
     * @param RK_WORLD_MODEL_TEXTURE_MOON Moon Texture
     * @param RK_WORLD_MODEL_TEXTURE_STAR_1 Star 1 Texture
     * @param RK_WORLD_MODEL_TEXTURE_STAR_2 Star 2 Texture
     * @param RK_WORLD_MODEL_TEXTURE_STAR_3 Star 3 Texture
     * @param RK_WORLD_MODEL_TEXTURE_STAR_4 Star 4 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_1 Exoplanet 1 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_2 Exoplanet 2 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_3 Exoplanet 3 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_4 Exoplanet 4 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_5 Exoplanet 5 Texture
     * @param RK_WORLD_MODEL_TEXTURE_EXOPLANET_6 Exoplanet 6 Texture
     */
    enum RKWorldModelTextures {
        RK_WORLD_MODEL_TEXTURE_EARTH,
        RK_WORLD_MODEL_TEXTURE_EARTH_2,
        RK_WORLD_MODEL_TEXTURE_EARTH_NIGHT,
        RK_WORLD_MODEL_TEXTURE_MARS,
        RK_WORLD_MODEL_TEXTURE_JUPITER,
        RK_WORLD_MODEL_TEXTURE_SATURN,
        RK_WORLD_MODEL_TEXTURE_PLUTO,
        RK_WORLD_MODEL_TEXTURE_MOON,
        RK_WORLD_MODEL_TEXTURE_STAR_1,
        RK_WORLD_MODEL_TEXTURE_STAR_2,
        RK_WORLD_MODEL_TEXTURE_STAR_3,
        RK_WORLD_MODEL_TEXTURE_STAR_4,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_1,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_2,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_3,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_4,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_5,
        RK_WORLD_MODEL_TEXTURE_EXOPLANET_6
    };
    /**
     * @brief Ramtin Kosari's World Model Rotation
     * @enum RKWorldModelRotation
     * @note This Enum Defines World Model Rotation
     * @param RK_WORLD_MODEL_ROTATION_AUTOMATIC Automatic Rotation
     * @param RK_WORLD_MODEL_ROTATION_MANUAL_MOUSE Manual Rotation with Mouse
     * @param RK_WORLD_MODEL_ROTATION_MANUAL_KEYBOARD Manual Rotation with Keyboard
     */
    enum RKWorldModelRotation {
        RK_WORLD_MODEL_ROTATION_AUTOMATIC,
        RK_WORLD_MODEL_ROTATION_MANUAL_MOUSE,
        RK_WORLD_MODEL_ROTATION_MANUAL_KEYBOARD,
    };
    /**
     * @brief Ramtin Kosari's World Model Class
     * @class RKWorldModel
     */
    class RKWorldModel {
        public:
            /**
             * @brief Window that Displays the 3D World Model
             */
            synwin::SynWindow window = synwin::SynWindow(
                "Synestia Graphics",
                RK_WORLD_MODEL_WINDOW_HEIGHT,
                RK_WORLD_MODEL_WINDOW_WIDTH
            );
            /**
             * @brief Construct a New World Model Object
             */
            RKWorldModel();
            /**
             * @breif Destroy the World Model Object
             */
            ~RKWorldModel();
            /**
             * @brief Initialize World Model Objects
             * @note This Method Initializes Objects Materials and Lights
             */
            void initObjects();
            /**
             * @brief Method to Show Keyboard Guide
             * @note This Method Shows Keyboard Guide for World Model Objects
             */
            void logHelp();
            /**
             * @brief Method to Check Keyboard
             * @note This Method Checks Keyboard Inputs
             */
            void checkKeyboard();
            /**
             * @brief Method to Handle Rotation
             * @note This Method Handles Rotation of World Model Objects
             */
            void handleRotation();
            /**
             * @brief Method to Load Texture
             * @param path Path to Texture
             */
            void loadTexture(std::string path);
            /**
             * @brief Method to Get Current Directory
             */
            std::string getCurrentDirectory();
            /**
             * @brief Object Mode
             */
            RKWorldModelObjects mode;
            /**
             * @brief Rotation Mode
             */
            RKWorldModelRotation rotation_mode;
            /**
             * @brief World Model Texture
             */
            RKWorldModelTextures texture, last_texture;
            /**
             * @brief Object Texture
             */
            GLuint object_texture;
            /**
             * @brief Define Axis Angles
             */
            float angle_x, angle_y, angle_z;
    };
# endif // RK_GRAPHICS_PROJECT_2