#ifndef LEGENDCANVAS_H
#define LEGENDCANVAS_H

#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include "Spectrum/colourmanager.h"
#include "piechart.h"
#include "starglyph.h"


class LegendCanvas : public QOpenGLWidget
{
public:
    static const int SAMPLE_POINTS = 6;
    static const int SEQUENTIAL = 0;
    static const int DIVERGING = 1;
    static const int CATEGORICAL = 2;
    static const int OUTLINE = 3;

    static const int GLYPH_CENTROID = 0;
    static const int GLYPH_EQUAL_PIE = 1;
    static const int GLYPH_VARIABLE_PIE = 2;
    static const int GLYPH_STAR = 3;

    LegendCanvas(QWidget *parent);
    void initializeGL();
    void paintGL();

    PieChart variablePie() const;
    void setVariablePie(const PieChart &VariablePie);

    void changeColorMap(int mapType);
    int currentGlyphType() const;
    void setCurrentGlyphType(int currentGlyphType);

    StarGlyph starGlyph() const;
    void setStarGlyph(const StarGlyph &starGlyph);

private:
    void initializeVariablePie();
    void paintVariablePie();
    PieChart m_variablePie;
    StarGlyph m_starGlyph;
    int m_currentGlyphType = 0;

    void glPrintString(float x, float y, std::string str);
    void glPrintString(void *font, const char *str);
    void paintStarGlyph();
    void initalizeStarGlyph();
};

#endif // LEGENDCANVAS_H