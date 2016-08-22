#include "SpriteBatch.h"

SpriteBatch::SpriteBatch():_vbo(0),_vao(0)
{
    //ctor
}

SpriteBatch::~SpriteBatch()
{
    //dtor
}
void SpriteBatch::init(){
    createVertArray();
}
void SpriteBatch::begin(glyphSortType s/*TEXTURE default */){
_sortType=s;
_renderBatchs.clear();
_glyphs.clear();
}
void SpriteBatch::end(){
sortGlyph();
createRenderBatches();
}

void SpriteBatch::draw(glm::vec4 dimensions,glm::vec4 uv,GLuint text,Color colour,const float& depth){
    auto newGlyph=std::make_shared<Glyph>();
    //auto newGlyph = new Glyph;
    newGlyph->text=text;
    newGlyph->depth=depth;

    newGlyph->topLeft.color=colour;
    newGlyph->topLeft.pos.x = dimensions.x;
    newGlyph->topLeft.pos.y = dimensions.y+dimensions.w;
    newGlyph->topLeft.setUV(uv.x,uv.y+uv.w);

    newGlyph->topRight.color=colour;
    newGlyph->topRight.pos.x = dimensions.x+dimensions.z;
    newGlyph->topRight.pos.y = dimensions.y+dimensions.w;
    newGlyph->topRight.setUV(uv.x+uv.z,uv.y+uv.w);

    newGlyph->botLeft.color=colour;
    newGlyph->botLeft.pos.x = dimensions.x;
    newGlyph->botLeft.pos.y = dimensions.y;
    newGlyph->botLeft.setUV(uv.x,uv.y);

    newGlyph->botRight.color=colour;
    newGlyph->botRight.pos.x = dimensions.x+dimensions.z;
    newGlyph->botRight.pos.y = dimensions.y;
    newGlyph->botRight.setUV(uv.x+uv.z,uv.y);
    _glyphs.push_back(newGlyph);
}
void SpriteBatch::renderBatch(){
    /*for(auto i:_renderBatchs){
        glBindTexture(GL_TEXTURE_2D,_renderBatchs[i]->text);
    }*/
    glBindVertexArray(_vao);
    for(int i = 0;i<_renderBatchs.size();++i){
        glBindTexture(GL_TEXTURE_2D,_renderBatchs[i].text);
        glDrawArrays(GL_TRIANGLES,_renderBatchs[i].offset,_renderBatchs[i].numVerts);
    }glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches(){
    if(_glyphs.empty()) return;
    std::vector<Vertex> vertices;
    vertices.resize(_glyphs.size()*6);
    //renderBatch newBatch(0,6,_glyphs[0]->text);
    _renderBatchs.emplace_back(0,6,_glyphs[0]->text);
    int cv = 0;
    vertices[cv++]=_glyphs[0]->topLeft;
    vertices[cv++]=_glyphs[0]->botLeft;
    vertices[cv++]=_glyphs[0]->botRight;
    vertices[cv++]=_glyphs[0]->botRight;
    vertices[cv++]=_glyphs[0]->topRight;
    vertices[cv++]=_glyphs[0]->topLeft;

    for(int cg = 1;cg<_glyphs.size();++cg){
        if(_glyphs[cg]->text!=_glyphs[cg-1]->text){
            _renderBatchs.emplace_back(cg*6,6,_glyphs[cg]->text);
        }else{
            _renderBatchs.back().numVerts+=6;
        }
        vertices[cv++]=_glyphs[cg]->topLeft;
        vertices[cv++]=_glyphs[cg]->botLeft;
        vertices[cv++]=_glyphs[cg]->botRight;
        vertices[cv++]=_glyphs[cg]->botRight;
        vertices[cv++]=_glyphs[cg]->topRight;
        vertices[cv++]=_glyphs[cg]->topLeft;
    }
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(Vertex),nullptr,GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER,0,vertices.size()*sizeof(Vertex),vertices.data());
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
void SpriteBatch::createVertArray(){
    if(!_vao)glGenVertexArrays(1,&_vao);
    glBindVertexArray(_vao);
    if(!_vbo)glGenBuffers(1,&_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,pos));
    glVertexAttribPointer(1,4,GL_UNSIGNED_BYTE,GL_TRUE,sizeof(Vertex),(void*)offsetof(Vertex,color));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,uv));
    glBindVertexArray(0);
}
/*
void SpriteBatch::sortGlyph() {

    switch (_sortType) {
        case glyphSortType::BACK_TO_FRONT:
            std::stable_sort(_glyphs.begin(), _glyphs.end(), compareBackToFront);
            break;
        case glyphSortType::FRONT_TO_BACK:
            std::stable_sort(_glyphs.begin(), _glyphs.end(), compareFrontToBack);
            break;
        case glyphSortType::TEXT:
            std::stable_sort(_glyphs.begin(), _glyphs.end(), compareTexture);
            break;
    }
}

bool SpriteBatch::compareFrontToBack(const Glyph* a,const Glyph* b) {
    return (a->depth < b->depth);
}

bool SpriteBatch::compareBackToFront(const Glyph* a,const Glyph* b) {
    return (a->depth > b->depth);
}

bool SpriteBatch::compareTexture(const Glyph* a,const Glyph* b) {
    return (a->text < b->text);
}*/

void SpriteBatch::sortGlyph(){
    switch(_sortType){
        case glyphSortType::BACK_TO_FRONT:
            std::stable_sort(_glyphs.begin(),_glyphs.end(),compareBackToFront);
            break;
        case glyphSortType::FRONT_TO_BACK:
            std::stable_sort(_glyphs.begin(),_glyphs.end(),compareFrontToBack);
            break;
        case glyphSortType::TEXT:
            std::stable_sort(_glyphs.begin(),_glyphs.end(),compareTexture);
            break;
    }
}

bool SpriteBatch::compareFrontToBack(const std::shared_ptr<Glyph> a,const std::shared_ptr<Glyph>b){
    return (a->depth>b->depth);
}
bool SpriteBatch::compareBackToFront(const std::shared_ptr<Glyph>a,const std::shared_ptr<Glyph>b){
    return a->depth<b->depth;
}
bool SpriteBatch::compareTexture(const std::shared_ptr<Glyph>a,const std::shared_ptr<Glyph>b){
    return a->text<b->text;
}/*
bool SpriteBatch::compareFrontToBack(const Glyph* a,const Glyph*b){
    return (a->depth>b->depth);
}
bool SpriteBatch::compareBackToFront(const Glyph*a,const Glyph*b){
    return a->depth<b->depth;
}
bool SpriteBatch::compareTexture(const Glyph*a,const Glyph*b){
    return a->text<b->text;
}
*/
