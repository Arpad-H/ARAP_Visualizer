//
// Created by quint on 12/4/2025.
//

#ifndef ARAP_VISUALIZER_TEXTURE_H
#define ARAP_VISUALIZER_TEXTURE_H


#include <iostream>
#include <map>

#ifdef WIN32
#include <GL/glew.h>
#include <glfw/glfw3.h>
#else
#define GLFW_INCLUDE_GLCOREARB
#define GLFW_INCLUDE_GLEXT
#include <glfw/glfw3.h>
#endif

class RGBImage;

class Texture
{
public:
    Texture();
    Texture(unsigned int width, unsigned int height, unsigned char* data);
    Texture(const char* Filename );
    ~Texture();
    bool load(const char* Filename);
    bool create(unsigned int width, unsigned int height, unsigned char* data);
    void activate(int slot=0) const;
    void deactivate() const;
    bool isValid() const;
    const RGBImage* getRGBImage() const;
    static Texture* defaultTex();
    static const Texture* LoadShared(const char* Filename);
    static void ReleaseShared( const Texture* pTex );
    GLuint getTextureID() const { return m_TextureID; }

protected:
    unsigned char* LoadBMP( const char* Filename, unsigned int& width, unsigned int& height );
    RGBImage* createImage( unsigned char* Data, unsigned int width, unsigned int height );
    GLuint m_TextureID;
    RGBImage* m_pImage;
    mutable int CurrentTextureUnit;
    static Texture* pDefaultTex;

    struct TexEntry
    {
        int RefCount;
        const Texture* pTex;
    };
    typedef std::map<std::string, TexEntry> SharedTexMap;
    static SharedTexMap SharedTextures;

};


#endif //ARAP_VISUALIZER_TEXTURE_H