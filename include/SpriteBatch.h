#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H
#include "vertex.h"
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <algorithm>
enum class glyphSortType{
NONE,FRONT_TO_BACK,BACK_TO_FRONT,TEXT
};
struct Glyph{
    GLuint text;
    float depth;
    Vertex topLeft;
    Vertex botLeft;
    Vertex botRight;
    Vertex topRight;
};
struct renderBatchs{
    renderBatchs(GLuint Offset,GLuint NumVerts,GLuint Text):offset(Offset),numVerts(NumVerts),text(Text){};
    GLuint offset;
    GLuint numVerts;
    GLuint text;
};
class SpriteBatch
{
    public:
        SpriteBatch();
        virtual ~SpriteBatch();
        void init();
        void begin(glyphSortType s=glyphSortType::TEXT);
        void end();
        void draw(const glm::vec4& dimensions,const glm::vec4& uv,GLuint& text,Color colour,const float& depth);
        void renderBatch();

    protected:

    private:
        void createRenderBatches();
        void createVertArray();
        /*
        static bool compareFrontToBack(const Glyph*a,const Glyph*b);
        static bool compareBackToFront(const Glyph*a,const Glyph*b);
        static bool compareTexture(const Glyph*a,const Glyph*b);
        */
        static bool compareFrontToBack(const std::shared_ptr<Glyph>a,const std::shared_ptr<Glyph>b);
        static bool compareBackToFront(const std::shared_ptr<Glyph>a,const std::shared_ptr<Glyph>b);
        static bool compareTexture(const std::shared_ptr<Glyph>a,const std::shared_ptr<Glyph>b);
        void sortGlyph();
        GLuint _vbo;
        GLuint _vao;
        glyphSortType _sortType;
        //std::vector<Glyph*> _glyphs;
        std::vector<std::shared_ptr<Glyph> > _glyphs;
        std::vector<renderBatchs> _renderBatchs;
};

#endif // SPRITEBATCH_H
