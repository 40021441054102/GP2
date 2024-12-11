# ifndef RK_GRAPHICS_PROJECT_2
    # include "WorldModel.hpp"
    //-- Include STB Image Library
    # ifndef STBI_INCLUDE_STB_IMAGE_H
        //-- Define STB Image Implementation
        # define STB_IMAGE_IMPLEMENTATION
        //-- Include STB Image
        # include "stb_image.h"
    # endif // STBI_INCLUDE_STB_IMAGE_H
    /**
     * @brief Method to Initialize World Model Objects
     * @note This Method Initializes Objects Materials and Lights
     */
    void RKWorldModel::initObjects() {
        //-- Define Material Property Vectors
        float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
        float matShine[] = { 50.0 };
        float matAmbAndDif[] = { 0.8, 0.8, 0.8, 1.0 };
        //-- Define Light Property Vectors.
        float lightAmb[] = { 0.3, 0.3, 0.3, 1.0 };
        float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };
        float lightPos[] = { 0.0, 7.0, 3.0, 1.0 };
        // float lightPos[] = { angle_x, angle_y, angle_z, 1.0 };
        float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };
        //-- Set Material Properties of the Objects
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matAmbAndDif);
        // //-- Set Light Properties
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        //-- Set Poperties of the Ambient Light
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
        //-- Enable Lighting Calculations
        glEnable(GL_LIGHTING);
        //-- Enable Light Source
        glEnable(GL_LIGHT0);
        //-- Enable Depth Testing
        // glEnable(GL_DEPTH_TEST);
        // //-- Enable Normalization
        glEnable(GL_NORMALIZE);
    }
    /**
     * @brief Method to Show Keyboard Guide
     * @note This Method Shows Keyboard Guide for World Model Objects
     */
    void RKWorldModel::logHelp() {
        //-- Log Keyboard Guide
        logger(BLUE_GRAY "Keyboard Guide for World Model Objects :");
        logger(BLUE_GRAY "1 :" RESET " Wired Sphere");
        logger(BLUE_GRAY "2 :" RESET " Solid Sphere");
        logger(BLUE_GRAY "3 :" RESET " Textured Sphere");
        logger(BLUE_GRAY "4 :" RESET " Wired Cone");
        logger(BLUE_GRAY "5 :" RESET " Solid Cone");
        logger(BLUE_GRAY "6 :" RESET " Wired Torus");
        logger(BLUE_GRAY "7 :" RESET " Solid Torus");
        // logger(BLUE_GRAY "8:" RESET " Fractal Tree");
        // logger(BLUE_GRAY "9:" RESET " Fractal Snowflake");
        logger(YELLOW_GRAY "R :" RESET " Rotation Mode - Automatic");
        logger(YELLOW_GRAY "E :" RESET " Rotation Mode - Manual Mouse");
        logger(YELLOW_GRAY "T :" RESET " Rotation Mode - Manual Keyboard");
        logger(YELLOW_GRAY "K :" RESET " Reset Rotation");
        logger(SYN_YELLOW "I :" RESET " Y-Axis Rotation (+)");
        logger(SYN_YELLOW ", :" RESET " Y-Axis Rotation (-)");
        logger(SYN_YELLOW "l :" RESET " X-Axis Rotation (+)");
        logger(SYN_YELLOW "J :" RESET " X-Axis Rotation (-)");
        logger(SYN_YELLOW "O :" RESET " Z-Axis Rotation (+)");
        logger(SYN_YELLOW "U :" RESET " Z-Axis Rotation (-)");
        logger(GREEN "! :" RESET " Planet Earth");
        logger(GREEN "@ :" RESET " Planet Earth in Night");
        logger(GREEN "# :" RESET " Planet Mars");
        logger(GREEN "$ :" RESET " Planet Jupiter");
        logger(GREEN "% :" RESET " Planet Saturn");
        logger(GREEN "^ :" RESET " Planet Moon");
        logger(GREEN "* :" RESET " Sun");
        logger(GREEN "( :" RESET " Exoplanet 1");
        logger(GREEN ") :" RESET " Exoplanet 2");
        logger(GREEN "_ :" RESET " Exoplanet 3");
    }
    /**
     * @brief Method to Check Keyboard
     * @note This Method Checks Keyboard Inputs
     */
    void RKWorldModel::checkKeyboard() {
        //-- Check if Keyboard is Pressed
        if (window.keyboard.is_pressed == false) {
            return;
        }
        //-- Check Keyboard Inputs for Wired Sphere
        if (window.keyboard.key == SDLK_1) {
            mode = RK_WORLD_MODEL_SPHERE_WIRED;
            logger(SYN_LOG "Selected" DARK_CYAN " Wired Sphere" RESET);
        }
        //-- Check Keyboard Inputs for Solid Sphere
        if (window.keyboard.key == SDLK_2) {
            mode = RK_WORLD_MODEL_SPHERE_SOLID;
            logger(SYN_LOG "Selected" DARK_CYAN " Solid Sphere" RESET);
        }
        //-- Check Keyboard Inputs for Textured Sphere
        if (window.keyboard.key == SDLK_3) {
            mode = RK_WORLD_MODEL_SPHERE_TEXTURED;
            //-- Rotate the Matrix
            angle_x = 0.0;
            angle_y = 0.0;
            angle_z = 0.0;
            glRotatef(angle_z, 0.0, 0.0, 1.0);
            glRotatef(angle_y, 0.0, 1.0, 0.0);
            glRotatef(angle_x, 1.0, 0.0, 0.0);
            logger(SYN_LOG "Selected" DARK_CYAN " Textured Sphere" RESET);
        }
        //-- Check Keyboard Inputs for Wired Cone
        if (window.keyboard.key == SDLK_4) {
            mode = RK_WORLD_MODEL_CONE_WIRED;
            logger(SYN_LOG "Selected" DARK_CYAN " Wired Cone" RESET);
        }
        //-- Check Keyboard Inputs for Solid Cone
        if (window.keyboard.key == SDLK_5) {
            mode = RK_WORLD_MODEL_CONE_SOLID;
            logger(SYN_LOG "Selected" DARK_CYAN " Solid Cone" RESET);
        }
        //-- Check Keyboard Inputs for Wired Torus
        if (window.keyboard.key == SDLK_6) {
            mode = RK_WORLD_MODEL_TORUS_WIRED;
            logger(SYN_LOG "Selected" DARK_CYAN " Wired Torus" RESET);
        }
        //-- Check Keyboard Inputs for Solid Torus
        if (window.keyboard.key == SDLK_7) {
            mode = RK_WORLD_MODEL_TORUS_SOLID;
            logger(SYN_LOG "Selected" DARK_CYAN " Solid Torus" RESET);
        }
        //-- Check Keyboard Inputs for Rotation Mode
        if (window.keyboard.key == SDLK_r) {
            rotation_mode = RK_WORLD_MODEL_ROTATION_AUTOMATIC;
            logger(SYN_LOG "Rotation Mode - Automatic" RESET);
        }
        //-- Check Keyboard Inputs for Rotation Mode
        if (window.keyboard.key == SDLK_e) {
            rotation_mode = RK_WORLD_MODEL_ROTATION_MANUAL_MOUSE;
            logger(SYN_LOG "Rotation Mode - Manual Mouse" RESET);
        }
        //-- Check Keyboard Inputs for Rotation Mode
        if (window.keyboard.key == SDLK_t) {
            rotation_mode = RK_WORLD_MODEL_ROTATION_MANUAL_KEYBOARD;
            logger(SYN_LOG "Rotation Mode - Manual Keyboard" RESET);
        }
        //-- Check Keyboard Inputs for Reset Rotation
        if (window.keyboard.key == SDLK_k) {
            angle_x = 0.0;
            angle_y = 0.0;
            angle_z = 0.0;
            logger(SYN_LOG "Reset Rotation" RESET);
        }
        //-- Check Keyboard Inputs for Y-Axis Rotation (+)
        if (window.keyboard.key == SDLK_i) {
            angle_y += RK_WORLD_MODEL_ANGLE_INCREMENT_Y;
            logger(SYN_LOG "Y-Axis Rotation Incremented" RESET);
        }
        //-- Check Keyboard Inputs for Y-Axis Rotation (-)
        if (window.keyboard.key == SDLK_COMMA) {
            angle_y -= RK_WORLD_MODEL_ANGLE_INCREMENT_Y;
            logger(SYN_LOG "Y-Axis Rotation Decremented" RESET);
        }
        //-- Check Keyboard Inputs for X-Axis Rotation (+)
        if (window.keyboard.key == SDLK_l) {
            angle_x += RK_WORLD_MODEL_ANGLE_INCREMENT_X;
            logger(SYN_LOG "X-Axis Rotation Incremented" RESET);
        }
        //-- Check Keyboard Inputs for X-Axis Rotation (-)
        if (window.keyboard.key == SDLK_j) {
            angle_x -= RK_WORLD_MODEL_ANGLE_INCREMENT_X;
            logger(SYN_LOG "X-Axis Rotation Decremented" RESET);
        }
        //-- Check Keyboard Inputs for Z-Axis Rotation (+)
        if (window.keyboard.key == SDLK_o) {
            angle_z += RK_WORLD_MODEL_ANGLE_INCREMENT_Z;
            logger(SYN_LOG "Z-Axis Rotation Incremented" RESET);
        }
        //-- Check Keyboard Inputs for Z-Axis Rotation (-)
        if (window.keyboard.key == SDLK_u) {
            angle_z -= RK_WORLD_MODEL_ANGLE_INCREMENT_Z;
            logger(SYN_LOG "Z-Axis Rotation Decremented" RESET);
        }
        //-- Check Keyboard Inputs for Texture Earth
        if (window.keyboard.key == SDLK_z) {
            texture = RK_WORLD_MODEL_TEXTURE_EARTH_2;
            logger(SYN_LOG "Selected" DARK_CYAN " Earth" RESET);
        }
        //-- Check Keyboard Inputs for Texture Earth in Night
        if (window.keyboard.key == SDLK_x) {
            texture = RK_WORLD_MODEL_TEXTURE_EARTH_NIGHT;
            logger(SYN_LOG "Selected" DARK_CYAN " Earth in Night" RESET);
        }
        //-- Check Keyboard Inputs for Texture Mars
        if (window.keyboard.key == SDLK_c) {
            texture = RK_WORLD_MODEL_TEXTURE_MARS;
            logger(SYN_LOG "Selected" DARK_CYAN " Mars" RESET);
        }
        //-- Check Keyboard Inputs for Texture Jupiter
        if (window.keyboard.key == SDLK_v) {
            texture = RK_WORLD_MODEL_TEXTURE_JUPITER;
            logger(SYN_LOG "Selected" DARK_CYAN " Jupiter" RESET);
        }
        //-- Check Keyboard Inputs for Texture Saturn
        if (window.keyboard.key == SDLK_b) {
            texture = RK_WORLD_MODEL_TEXTURE_SATURN;
            logger(SYN_LOG "Selected" DARK_CYAN " Saturn" RESET);
        }
        //-- Check Keyboard Inputs for Texture Pluto
        if (window.keyboard.key == SDLK_n) {
            texture = RK_WORLD_MODEL_TEXTURE_PLUTO;
            logger(SYN_LOG "Selected" DARK_CYAN " Pluto" RESET);
        }
        //-- Check Keyboard Inputs for Texture Moon
        if (window.keyboard.key == SDLK_m) {
            texture = RK_WORLD_MODEL_TEXTURE_MOON;
            logger(SYN_LOG "Selected" DARK_CYAN " Moon" RESET);
        }
        //-- Check Keyboard Inputs for Texture Sun
        if (window.keyboard.key == SDLK_s) {
            texture = RK_WORLD_MODEL_TEXTURE_STAR_1;
            logger(SYN_LOG "Selected" DARK_CYAN " Sun" RESET);
        }
        //-- Check Keyboard Inputs for Texture Exoplanet 1
        if (window.keyboard.key == SDLK_d) {
            texture = RK_WORLD_MODEL_TEXTURE_EXOPLANET_1;
            logger(SYN_LOG "Selected" DARK_CYAN " Exoplanet 1" RESET);
        }
        //-- Check Keyboard Inputs for Texture Exoplanet 2
        if (window.keyboard.key == SDLK_f) {
            texture = RK_WORLD_MODEL_TEXTURE_EXOPLANET_2;
            logger(SYN_LOG "Selected" DARK_CYAN " Exoplanet 2" RESET);
        }
        //-- Check Keyboard Inputs for Texture Exoplanet 3
        if (window.keyboard.key == SDLK_g) {
            texture = RK_WORLD_MODEL_TEXTURE_EXOPLANET_3;
            logger(SYN_LOG "Selected" DARK_CYAN " Exoplanet 3" RESET);
        }
    }
    /**
     * @brief Method to Handle Rotation
     * @note This Method Handles Rotation of World Model Objects
     */
    void RKWorldModel::handleRotation() {
        //-- Check Rotation Mode
        if (rotation_mode == RK_WORLD_MODEL_ROTATION_MANUAL_MOUSE) {
            float deltaX = window.mouse.x - RK_WORLD_MODEL_WINDOW_WIDTH / 2;
            float deltaY = window.mouse.y - RK_WORLD_MODEL_WINDOW_HEIGHT / 2;
            angle_x = -deltaY / 20;
            angle_y = -deltaX / 20;

        } else if (rotation_mode == RK_WORLD_MODEL_ROTATION_AUTOMATIC) {
            //-- Rotate According to Texture Mode is On or Off
            if (mode == RK_WORLD_MODEL_SPHERE_TEXTURED) {
                if (angle_x <= 76) {
                    angle_x += RK_WORLD_MODEL_ANGLE_INCREMENT_X;
                } else {
                    angle_y -= RK_WORLD_MODEL_ANGLE_INCREMENT_Y;
                }
            } else {
                angle_x += RK_WORLD_MODEL_ANGLE_INCREMENT_X;
                angle_y += RK_WORLD_MODEL_ANGLE_INCREMENT_Y;
                angle_z += RK_WORLD_MODEL_ANGLE_INCREMENT_Z;
            }
        }
    }
    /**
     * @brief Method to Get Current Directory
     */
    std::string RKWorldModel::getCurrentDirectory() {
        char buffer[PATH_MAX];
        if (getcwd(buffer, sizeof(buffer)) == NULL) {
            logger(FAILURE, "Failed to Get Current Directory");
            return "";
        } else {
            return std::string(buffer);
        }
    }
    /**
     * @brief Method to Load Texture
     * @param path Path to Texture
     */
    void RKWorldModel::loadTexture(std::string path) {
        if (last_texture == texture) {
            return;
        }
        //-- Define Width, Height, Channels
        int width, height, channels;
        //-- Load Image
        unsigned char* image = stbi_load(
            std::string(getCurrentDirectory() + "/../GP2/WorldModel/Assets/" + path).c_str(),
            &width,
            &height,
            &channels,
            0
        );
        //-- Check if Image is Loaded
        if (!image) {
            logger(SYN_FAILURE "Failed to Load Image" RESET " : " + path);
            return;
        }

        glGenTextures(1, &object_texture);
        //-- Bind Texture
        glBindTexture(GL_TEXTURE_2D, object_texture);
        //-- Set Texture Parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //-- Load Texture
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            width, height,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            image
        );
        //-- Free Image
        stbi_image_free(image);
        //-- Log Success
        logger(SUCCESS, "Loading Texture : " + getCurrentDirectory() + path);
    }
    /**
     * @brief World Model Default Constructor
     */
    RKWorldModel::RKWorldModel() {
        //-- Set Initial Rotation Mode
        rotation_mode = RK_WORLD_MODEL_ROTATION_AUTOMATIC;
        //-- Set Initial Object Mode
        mode = RK_WORLD_MODEL_SPHERE_WIRED;
        //-- Set Initial Texture Mode
        texture = RK_WORLD_MODEL_TEXTURE_EARTH_2;
        //-- Log Help
        logHelp();
        //-- Initialize World Model Objects
        initObjects();
        //-- Set OpenGL Ortho
        glOrtho(
            -RK_WORLD_MODEL_WINDOW_WIDTH / 2,
            RK_WORLD_MODEL_WINDOW_WIDTH / 2,
            -RK_WORLD_MODEL_WINDOW_HEIGHT / 2,
            RK_WORLD_MODEL_WINDOW_HEIGHT / 2,
            -RK_WORLD_MODEL_WINDOW_LENGTH / 2,
            RK_WORLD_MODEL_WINDOW_LENGTH / 2
        );
        //-- Window Loop
        while (true) {
            //-- Clear the Window
            window.clear(0, 10, 18, 255);
            //-- Check Keyboard
            checkKeyboard();
            //-- Create Matrix
            glPushMatrix();
            //-- Handle Rotation
            handleRotation();
            //-- Rotate the Matrix
            glRotatef(angle_z, 0.0, 0.0, 1.0);
            glRotatef(angle_y, 0.0, 1.0, 0.0);
            glRotatef(angle_x, 1.0, 0.0, 0.0);
            //-- Draw Objects
            switch (mode) {
                //-- Sphere Wired
                case RK_WORLD_MODEL_SPHERE_WIRED: {
                    glutWireSphere(400, 16, 70);
                    break;
                }
                //-- Sphere Solid
                case RK_WORLD_MODEL_SPHERE_SOLID: {
                    glutSolidSphere(400, 100, 100);
                    break;
                }
                //-- Sphere Textured
                case RK_WORLD_MODEL_SPHERE_TEXTURED: {
                    //-- Handle Texture Mode
                    switch (texture) {
                        //-- Earth
                        case RK_WORLD_MODEL_TEXTURE_EARTH: {
                            loadTexture("earth.jpg");
                            break;
                        }
                        //-- Earth 2
                        case RK_WORLD_MODEL_TEXTURE_EARTH_2: {
                            loadTexture("earth2.jpg");
                            break;
                        }
                        //-- Moon
                        case RK_WORLD_MODEL_TEXTURE_MOON: {
                            loadTexture("moon.jpg");
                            break;
                        }
                        //-- Earth Night
                        case RK_WORLD_MODEL_TEXTURE_EARTH_NIGHT: {
                            loadTexture("earth_night.jpg");
                            break;
                        }
                        //-- Mars
                        case RK_WORLD_MODEL_TEXTURE_MARS: {
                            loadTexture("mars.jpg");
                            break;
                        }
                        //-- Jupiter
                        case RK_WORLD_MODEL_TEXTURE_JUPITER: {
                            loadTexture("jupiter.jpg");
                            break;
                        }
                        //-- Saturn
                        case RK_WORLD_MODEL_TEXTURE_SATURN: {
                            loadTexture("saturn.jpg");
                            break;
                        }
                        //-- Pluto
                        case RK_WORLD_MODEL_TEXTURE_PLUTO: {
                            loadTexture("pluto.jpg");
                            break;
                        }
                        //-- Star 1
                        case RK_WORLD_MODEL_TEXTURE_STAR_1: {
                            loadTexture("star1.jpg");
                            break;
                        }
                        //-- Star 2
                        case RK_WORLD_MODEL_TEXTURE_STAR_2: {
                            loadTexture("star2.jpg");
                            break;
                        }
                        //-- Star 3
                        case RK_WORLD_MODEL_TEXTURE_STAR_3: {
                            loadTexture("star3.jpg");
                            break;
                        }
                        //-- Star 4
                        case RK_WORLD_MODEL_TEXTURE_STAR_4: {
                            loadTexture("star4.jpg");
                            break;
                        }
                        //-- Exoplanet 1
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_1: {
                            loadTexture("exop1.jpg");
                            break;
                        }
                        //-- Exoplanet 2
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_2: {
                            loadTexture("exop2.jpg");
                            break;
                        }
                        //-- Exoplanet 3
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_3: {
                            loadTexture("exop3.jpg");
                            break;
                        }
                        //-- Exoplanet 4
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_4: {
                            loadTexture("exop4.png");
                            break;
                        }
                        //-- Exoplanet 5
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_5: {
                            loadTexture("exop5.png");
                            break;
                        }
                        //-- Exoplanet 6
                        case RK_WORLD_MODEL_TEXTURE_EXOPLANET_6: {
                            loadTexture("exop6.jpg");
                            break;
                        }
                        //-- Default
                        default: {
                            loadTexture("earth.jpg");
                            break;
                        }
                    }
                    //-- Enable Texture
                    glEnable(GL_TEXTURE_2D);
                    //-- Bind Texture
                    glBindTexture(GL_TEXTURE_2D, object_texture);
                    // Rotate the sphere by 90 degrees along the x-axis to fix the texture orientation
                    if (last_texture != texture) {
                        glRotatef(90.0, 1.0, 0.0, 0.0);  // Rotate by 90 degrees around the x-axis
                    }
                    //-- Create Quadric
                    GLUquadric* quad = gluNewQuadric();
                    gluQuadricTexture(quad, GL_TRUE);
                    //-- Draw Sphere with Texture
                    gluSphere(quad, 500, 50, 50);
                    // gluCylinder(quad, 500, 500, 100, 50, 50);
                    // gluDisk(quad, 0, 500, 50, 50);
                    //-- Draw Ring if Planet is Saturn
                    if (texture == RK_WORLD_MODEL_TEXTURE_SATURN) {
                        // glutSolidTorus(10, 500, 50, 50);
                    }
                    //-- Delete Quadric
                    gluDeleteQuadric(quad);
                    //-- Disable Texture
                    glDisable(GL_TEXTURE_2D);
                    //-- Set Last Texture
                    last_texture = texture;
                    break;
                }
                //-- Cone Wired
                case RK_WORLD_MODEL_CONE_WIRED: {
                    glutWireCone(400, 300, 16, 70);
                    break;
                }
                //-- Cone Solid
                case RK_WORLD_MODEL_CONE_SOLID: {
                    glutSolidCone(400, 500, 16, 70);
                    break;
                }
                //-- Torus Wired
                case RK_WORLD_MODEL_TORUS_WIRED: {
                    glutWireTorus(120, 300, 26, 70);
                    break;
                }
                //-- Torus Solid
                case RK_WORLD_MODEL_TORUS_SOLID: {
                    glutSolidTorus(120, 300, 16, 70);
                    break;
                }
                //-- Fractal Tree
                case RK_WORLD_MODEL_FRACTAL_TREE: {
                    break;
                }
                //-- Fractal Snowflake
                case RK_WORLD_MODEL_FRACTAL_SNOWFLAKE: {
                    break;
                }
            }
            //-- Pop Matrix
            glPopMatrix();
            // Update the window
            window.update();
            //-- Sleep for 20 milliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }
    /**
     * @brief World Model Destructor
     */
    RKWorldModel::~RKWorldModel() {}
# endif // RK_GRAPHICS_PROJECT_2