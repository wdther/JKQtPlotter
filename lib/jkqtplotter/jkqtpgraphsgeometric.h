/*
    Copyright (c) 2008-2018 Jan W. Krieger (<jan@jkrieger.de>)

    

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License (LGPL) as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License (LGPL) for more details.

    You should have received a copy of the GNU Lesser General Public License (LGPL)
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/




/**
 * \defgroup jkqtplotter_geoplots Geometric Elements (Lines, Rectangles, ...)
 * \ingroup jkqtplotter_elements

 */

/** \file jkqtpgraphsgeometric.h
  * \ingroup jkqtplotter_geoplots
  */

#include <QString>
#include <QPainter>
#include <QPair>
#include "jkqtplotter/jkqtpgraphs.h"
#include "jkqtplottertools/jkqtptools.h"
#include "jkqtplottertools/jkqtp_imexport.h"
#include "jkqtmathtext/jkqtmathtext.h"

#ifndef jkqtpgraphsgeometric_H_INCLUDED
#define jkqtpgraphsgeometric_H_INCLUDED


/*! \brief This JKQTPplotObject is used as base class for geometric drawing
           elements that only consist of lines (i.e. no filling of any kind is done)
    \ingroup jkqtplotter_geoplots

 */
class LIB_EXPORT JKQTPgeoBaseLine: public JKQTPplotObject {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param color color of drawing
            \param style line style of drawing
            \param lineWidth lineWidth of drawing
         */
        explicit JKQTPgeoBaseLine(QColor color, double lineWidth, Qt::PenStyle style=Qt::SolidLine, JKQtBasePlotter* parent=nullptr);
        /*! \brief class contructor

            \param color color of drawing
            \param style line style of drawing
            \param lineWidth lineWidth of drawing
         */
        explicit JKQTPgeoBaseLine(QColor color, double lineWidth, Qt::PenStyle style, JKQtPlotter* parent);


        JKQTPGET_SET_MACRO(QColor, color)
        JKQTPGET_SET_MACRO(Qt::PenStyle, style)
        JKQTPGET_SET_MACRO(double, lineWidth)

        /** \brief sets the alpha-channel of the \a color (i.e. its transparency) */
        virtual void setAlpha(float alpha);

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor() override;

    protected:
        /** \brief color of the graph */
        QColor color;

        /** \brief linestyle of the graph lines */
        Qt::PenStyle style;
        /** \brief width (pixels) of the graph */
        double lineWidth;
        /** \brief return a pen, that may be used for drawing */
        QPen getPen(JKQTPEnhancedPainter &painter);
};


/*! \brief This JKQTPplotObject is used as base class for geometric drawing
           elements that only consist of lines (i.e. no filling of any kind is done)
    \ingroup jkqtplotter_geoplots

 */
class LIB_EXPORT JKQTPgeoBaseFilled: public JKQTPgeoBaseLine {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param color color of drawing
            \param fillColor color of the filling in the drawing
            \param style line style of drawing
            \param fillStyle filling style of the graph
            \param lineWidth lineWidth of drawing
         */
        JKQTPgeoBaseFilled(QColor color, QColor fillColor, double lineWidth, Qt::PenStyle style=Qt::SolidLine, Qt::BrushStyle fillStyle=Qt::SolidPattern, JKQtBasePlotter* parent=nullptr);
        /*! \brief class contructor

            \param color color of drawing
            \param fillColor color of the filling in the drawing
            \param style line style of drawing
            \param fillStyle filling style of the graph
            \param lineWidth lineWidth of drawing
         */
        JKQTPgeoBaseFilled(QColor color, QColor fillColor, double lineWidth, Qt::PenStyle style, Qt::BrushStyle fillStyle, JKQtPlotter* parent);
        /*! \brief class contructor

            \param color color of drawing
            \param fillColor color of the filling in the drawing
            \param style line style of drawing
            \param lineWidth lineWidth of drawing
         */
        JKQTPgeoBaseFilled(QColor color, QColor fillColor, double lineWidth, Qt::PenStyle style, JKQtPlotter* parent);
        /*! \brief class contructor

            \param color color of drawing
            \param fillColor color of the filling in the drawing
            \param lineWidth lineWidth of drawing
         */
        JKQTPgeoBaseFilled(QColor color, QColor fillColor, double lineWidth, JKQtPlotter* parent);
        /*! \brief class contructor

            \param color color of drawing
            \param fillColor color of the filling in the drawing
         */
        JKQTPgeoBaseFilled(QColor color, QColor fillColor, JKQtPlotter* parent);

        JKQTPGET_SET_MACRO(QColor, fillColor)
        JKQTPGET_SET_MACRO(Qt::BrushStyle, fillStyle)

        /** \brief sets the alpha-channel of the \a color and \a fillColor (i.e. its transparency) to the same value */
        virtual void setAlpha(float alpha) override;
        /** \brief sets the alpha-channel of the \a color and \a fillColor (i.e. its transparency) */
        virtual void setAlpha(float alphaLine, float alphaFill);

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
    protected:

        /** \brief filling color of the graph */
        QColor fillColor;
        /** \brief fill style for the curve */
        Qt::BrushStyle fillStyle;
        /** \brief return a brush that may be used for drawing */
        QBrush getBrush(JKQTPEnhancedPainter& painter);

};



/*! \brief This virtual JKQTPgraph descendent may be used to display a single symbol (marker).
    \ingroup jkqtplotter_geoplots

 */
class LIB_EXPORT JKQTPgeoSymbol: public JKQTPplotObject {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of symbol center
            \param y y-coordinate of symbol center
            \param symbol symbol type
            \param symbolSize size of the symbol in pt
            \param color color of drawing
            \param fillColor fill color of the symbol (if filled)
         */
        JKQTPgeoSymbol(JKQtBasePlotter* parent, double x, double y, JKQTPgraphSymbols symbol=JKQTPcross, double symbolSize=10, QColor color=QColor("black"), QColor fillColor=QColor("grey"));
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of symbol center
            \param y y-coordinate of symbol center
            \param symbol symbol type
            \param symbolSize size of the symbol in pt
            \param color color of drawing
            \param fillColor fill color of the symbol (if filled)
         */
        JKQTPgeoSymbol(JKQtPlotter* parent, double x, double y, JKQTPgraphSymbols symbol=JKQTPcross, double symbolSize=10, QColor color=QColor("black"), QColor fillColor=QColor("grey"));

        JKQTPGET_SET_MACRO(QColor, color)
        JKQTPGET_SET_MACRO(QColor, fillColor)
        JKQTPGET_SET_MACRO(JKQTPgraphSymbols, symbol)
        JKQTPGET_SET_MACRO(double, symbolSize)
        JKQTPGET_SET_MACRO(double, symbolWidth)
        JKQTPGET_SET_MACRO(double, x)
        JKQTPGET_SET_MACRO(double, y)

        /** \copydoc JKQTPgraph::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero);
        /** \copydoc JKQTPgraph::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero);

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter);

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect);
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor();

    protected:
        double x,y;

        /** \brief color of the graph */
        QColor color;
        /** \brief fill-color of the graph */
        QColor fillColor;

        /** \brief size of the symbol in pt */
        double symbolSize;
        /** \brief width of the symbol lines in pt */
        double symbolWidth;
        /** \brief type of the symbol */
        JKQTPgraphSymbols symbol;
};


/*! \brief This JKQTPplotObject is used to display text. It uses the JKQTMathText
           class in order to display LaTeX formulas.
    \ingroup jkqtplotter_geoplots

 */
class LIB_EXPORT JKQTPgeoText: public JKQTPplotObject {
        Q_OBJECT
    public:
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
            \param color color of drawing
            \param fontSize base font size of text
         */
        JKQTPgeoText(JKQtBasePlotter* parent, double x, double y, QString text, double fontSize=10, QColor color=QColor("black"));
        /*! \brief class contructor

            \param parent parent plotter widget
            \param x x-coordinate of text
            \param y y-coordinate of text
            \param text the text to display
            \param color color of drawing
            \param fontSize base font size of text
         */
        JKQTPgeoText(JKQtPlotter* parent, double x, double y, QString text, double fontSize=10, QColor color=QColor("black"));

        JKQTPGET_SET_MACRO(QColor, color)
        JKQTPGET_SET_MACRO(QString, text)
        JKQTPGET_SET_MACRO(double, fontSize)
        JKQTPGET_SET_MACRO(double, x)
        JKQTPGET_SET_MACRO(double, y)

        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        /** \brief plots a key marker inside the specified rectangle \a rect */
        virtual void drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) override;
        /** \brief returns the color to be used for the key label */
        virtual QColor getKeyLabelColor() override;

    protected:
        double x,y;

        /** \brief color of the graph */
        QColor color;

        /** \brief base font size of text */
        double fontSize;
        /** \brief the text to display */
        QString text;
        /** \brief return a pen, that may be used for drawing */
        QPen getPen(JKQTPEnhancedPainter& painter);
};

/*! \brief This JKQTPplotObject is used to draw a line
    \ingroup jkqtplotter_geoplots

    \image html plot_geoline.png

 */
class LIB_EXPORT JKQTPgeoLine: public JKQTPgeoBaseLine {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x1 x-coordinate of first point of line
            \param y1 y-coordinate of first point of line
            \param x2 x-coordinate of second point of line
            \param y2 y-coordinate of second point of line
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoLine(JKQtBasePlotter* parent, double x1, double y1, double x2, double y2, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x1 x-coordinate of first point of line
            \param y1 y-coordinate of first point of line
            \param x2 x-coordinate of second point of line
            \param y2 y-coordinate of second point of line
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoLine(JKQtPlotter* parent, double x1, double y1, double x2, double y2, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);


        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(double, x1)
        JKQTPGET_SET_MACRO(double, y1)
        JKQTPGET_SET_MACRO(double, x2)
        JKQTPGET_SET_MACRO(double, y2)
    protected:
        double x1, y1, x2, y2;
};



/*! \brief This JKQTPplotObject is used to draw an infinite line
    \ingroup jkqtplotter_geoplots

    an infinite line has a starting point and then goes on in a given direction
    until the end of the plotting range.

    \image html plot_geoinfiniteline.png

 */
class LIB_EXPORT JKQTPgeoInfiniteLine: public JKQTPgeoBaseLine {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of start point of line
            \param y y-coordinate of start point of line
            \param dx x-direction of the line
            \param dy y-direction of the line
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoInfiniteLine(JKQtBasePlotter* parent, double x, double y, double dx, double dy, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of start point of line
            \param y y-coordinate of start point of line
            \param dx x-direction of the line
            \param dy y-direction of the line
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoInfiniteLine(JKQtPlotter* parent, double x, double y, double dx, double dy, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);


        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(double, x)
        JKQTPGET_SET_MACRO(double, y)
        JKQTPGET_SET_MACRO(double, dx)
        JKQTPGET_SET_MACRO(double, dy)
        JKQTPGET_SET_MACRO(bool, two_sided)
    protected:
        double x, y, dx, dy;
        /** \brief indicates whether the line ends at the given point \f$ (x,y) \f$ (false, default),
         *         or is infinite in both directions (true) */
        bool two_sided;
};


/*! \brief This JKQTPplotObject is used to draw a poly line
    \ingroup jkqtplotter_geoplots

    \image html plot_geolines.png

 */
class LIB_EXPORT JKQTPgeoPolyLines: public JKQTPgeoBaseLine {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoPolyLines(JKQtBasePlotter* parent, const QVector<QPointF>& points, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoPolyLines(JKQtPlotter* parent, const QVector<QPointF>& points, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoPolyLines(JKQtBasePlotter* parent, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
         */
        JKQTPgeoPolyLines(JKQtPlotter* parent, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);


        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(QVector<QPointF>, points)

        /** \brief append a point to the polygon */
        inline void appendPoint(const QPointF& p) {
            points.append(p);
        }

        /** \brief append a point to the polygon */
        inline void appendPoint(const double x, const double y) {
            points.append(QPointF(x, y));
        }
    protected:
        QVector<QPointF> points;
};

/*! \brief This JKQTPplotObject is used to draw a rectangle
    \ingroup jkqtplotter_geoplots

    \image html plot_georectangle.png
 */
class LIB_EXPORT JKQTPgeoRectangle: public JKQTPgeoBaseFilled {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtBasePlotter* parent, double x, double y, double width, double height, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtPlotter* parent, double x, double y, double width, double height, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param angle rotation angle of the rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtBasePlotter* parent, double x, double y, double width, double height, double angle, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param angle rotation angle of the rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtPlotter* parent, double x, double y, double width, double height, double angle, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param bottomleft bottom left corner of rectangle
            \param topright top right corner of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtBasePlotter* parent, QPointF bottomleft, QPointF topright, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param bottomleft bottom left corner of rectangle
            \param topright top right corner of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoRectangle(JKQtPlotter* parent, QPointF bottomleft, QPointF topright, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);



        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(double, x)
        JKQTPGET_SET_MACRO(double, y)
        JKQTPGET_SET_MACRO(double, width)
        JKQTPGET_SET_MACRO(double, height)
        JKQTPGET_SET_MACRO(double, angle)

        void set_bottomleftrectangle(double x, double y, double width, double height);
protected:
        double x,y,width,height;
        /** \brief rotation angle of rectangle */
        double angle;
        /** \brief returns the transformation matrix used for this rectangle */
        QMatrix getMatrix();
        /** \brief returns a QPolygonF which represents the rectangle after rotation, but still in the world coordinate system, not in the screen/widget system */
        QPolygonF getPolygon();
};


/*! \brief This JKQTPplotObject is used to draw a polygon
    \ingroup jkqtplotter_geoplots

    \image html plot_geopolygon.png

 */
class LIB_EXPORT JKQTPgeoPolygon: public JKQTPgeoBaseFilled {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor color of the filling
            \param fillStyle style of the filling

         */
        JKQTPgeoPolygon(JKQtBasePlotter* parent, const QVector<QPointF>& points, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param points points on the polygon
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor color of the filling
            \param fillStyle style of the filling
         */
        JKQTPgeoPolygon(JKQtPlotter* parent, const QVector<QPointF>& points, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);

        /*! \brief class constructor

            \param parent the parent plotter class
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor color of the filling
            \param fillStyle style of the filling

         */
        JKQTPgeoPolygon(JKQtBasePlotter* parent, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor color of the filling
            \param fillStyle style of the filling
         */
        JKQTPgeoPolygon(JKQtPlotter* parent, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);


        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(QVector<QPointF>, points)

        /** \brief append a point to the polygon */
        inline void appendPoint(const QPointF& p) {
            points.append(p);
        }

        /** \brief append a point to the polygon */
        inline void appendPoint(const double x, const double y) {
            points.append(QPointF(x, y));
        }

    protected:
        QVector<QPointF> points;
};

/*! \brief This JKQTPplotObject is used to draw an ellipse
    \ingroup jkqtplotter_geoplots

    \image html plot_geoellipse.png

    \see <a href="http://www.codeguru.com/cpp/g-m/gdi/article.php/c131">http://www.codeguru.com/cpp/g-m/gdi/article.php/c131</a> and
         <a href="http://en.wikipedia.org/wiki/Ellipse#General_parametric_form">http://en.wikipedia.org/wiki/Ellipse#General_parametric_form</a>
 */
class LIB_EXPORT JKQTPgeoEllipse: public JKQTPgeoRectangle {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoEllipse(JKQtBasePlotter* parent, double x, double y, double width, double height, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);

        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoEllipse(JKQtPlotter* parent, double x, double y, double width, double height, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param angle rotation angle of the rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoEllipse(JKQtBasePlotter* parent, double x, double y, double width, double height, double angle, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of rectangle
            \param y y-coordinate of center of rectangle
            \param width width of rectangle
            \param height of rectangle
            \param angle rotation angle of the rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoEllipse(JKQtPlotter* parent, double x, double y, double width, double height, double angle, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param bottomleft bottom left corner of rectangle
            \param topright top right corner of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoEllipse(JKQtBasePlotter* parent, QPointF bottomleft, QPointF topright, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param bottomleft bottom left corner of rectangle
            \param topright top right corner of rectangle
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of rectangle
            \param fillStyle filling style of rectangle
         */
        JKQTPgeoEllipse(JKQtPlotter* parent, QPointF bottomleft, QPointF topright, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);


        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(unsigned int, controlPoints)
    protected:
        /** \brief number of steps/control points to draw the ellipse */
        unsigned int controlPoints;
};


/*! \brief This JKQTPplotObject is used to draw an arc
    \ingroup jkqtplotter_geoplots

    \image html plot_geoarc.png
 */
class LIB_EXPORT JKQTPgeoArc: public JKQTPgeoBaseLine {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style

         */
        JKQTPgeoArc(JKQtBasePlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style

         */
        JKQTPgeoArc(JKQtPlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine);

        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;


        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(unsigned int, controlPoints)
        JKQTPGET_SET_MACRO(double, angleStart)
        JKQTPGET_SET_MACRO(double, angleStop)
        JKQTPGET_SET_MACRO(double, x)
        JKQTPGET_SET_MACRO(double, y)
        JKQTPGET_SET_MACRO(double, width)
        JKQTPGET_SET_MACRO(double, height)
        JKQTPGET_SET_MACRO(double, angle)
    protected:
        double x,y,width,height;
        /** \brief rotation angle of rectangle */
        double angle;
        /** \brief if we only draw an arc, this is the starting angle in degrees */
        double angleStart;
        /** \brief if we only draw an arc, this is the ending angle in degrees */
        double angleStop;
        /** \brief closing mode for arcs: secand or pie */
        double angle_start;
        /** \brief if we only draw an arc, this is the ending angle */
        double angle_end;
        /** \brief closing mode for arcs: secand or pie */
        /** \brief returns the transformation matrix used for this rectangle */
        QMatrix getMatrix();
        /** \brief returns a QPolygonF which represents the rectangle after rotation, but still in the world coordinate system, not in the screen/widget system */
        QPolygonF getPolygon();
        /** \brief number of steps/control points to draw the ellipse */
        unsigned int controlPoints;
};




/*! \brief This JKQTPplotObject is used to draw a pie
    \ingroup jkqtplotter_geoplots

    \image html plot_geopie.png
 */
class LIB_EXPORT JKQTPgeoPie: public JKQTPgeoEllipse {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoPie(JKQtBasePlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoPie(JKQtPlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);


        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;


        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;

        JKQTPGET_SET_MACRO(double, angleStart)
        JKQTPGET_SET_MACRO(double, angleStop)
    protected:
         /** \brief if we only draw an arc, this is the starting angle */
        double angleStart;
         /** \brief if we only draw an arc, this is the ending angle */
        double angleStop;
};




/*! \brief This JKQTPplotObject is used to draw a chord
    \ingroup jkqtplotter_geoplots

    \image html plot_geochord.png
 */
class LIB_EXPORT JKQTPgeoChord: public JKQTPgeoPie {
        Q_OBJECT
    public:
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoChord(JKQtBasePlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);
        /*! \brief class constructor

            \param parent the parent plotter class
            \param x x-coordinate of center of ellipse
            \param y y-coordinate of center of ellipse
            \param width width of ellipse (2 * half axis)
            \param height of ellipse (2 * half axis)
            \param color color of line
            \param lineWidth width of line
            \param style line style
            \param fillColor filling color of ellipse
            \param fillStyle filling style of ellipse
         */
        JKQTPgeoChord(JKQtPlotter* parent, double x, double y, double width, double height, double angleStart, double angleStop, QColor color=QColor("black"), double lineWidth=1, Qt::PenStyle style=Qt::SolidLine, QColor fillColor=QColor("transparent"), Qt::BrushStyle fillStyle=Qt::SolidPattern);

        /** \copydoc JKQTPplotObject::getXMinMax()        */
        virtual bool getXMinMax(double& minx, double& maxx, double& smallestGreaterZero) override;
        /** \copydoc JKQTPplotObject::getYMinMax()        */
        virtual bool getYMinMax(double& miny, double& maxy, double& smallestGreaterZero) override;

        /** \brief plots the graph to the plotter object specified as parent */
        virtual void draw(JKQTPEnhancedPainter& painter) override;
};


#endif // jkqtpgraphsgeometric_H_INCLUDED
