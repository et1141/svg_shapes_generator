#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include "xmlStorage.h"

#include <fstream>


class XmlConfig{
    public:
     string version = "1.0";
     string encoding = "utf-8";

};

class SvgConfig{
    public:
     string xmlns="http://www.w3.org/2000/svg";
     string width="500";
     string height="500";
     string version="1.1";
};


class InitPicture{
    IndexS svg=IndexS("svg");
    IndexP xml=IndexP("?xml");
public:
    InitPicture(XmlConfig configXml = XmlConfig(),SvgConfig configSvg = SvgConfig())
    {
         xml.addAtribute("encoding",configXml.encoding);
         xml.addAtribute("version",configXml.version);

         svg.addAtribute("version",configSvg.version);
         svg.addAtribute("height",configSvg.height);
         svg.addAtribute("width",configSvg.width);
         svg.addAtribute("xmlns",configSvg.xmlns);
    }
  void addPainting(Content *newCnt){
    svg.addContent(newCnt);
  }
  void save(string outputName){
     fstream file;
     file.open(outputName,ios::out);
     file<<xml;
     file<<svg;
     file.close();
  }

};


class FigureConfig{ //default config
    public:
     string x="10";
     string y="10";
     string rx="10";
     string ry="10";
     string width="30";
     string height="30";
     string stroke="black";
     string fill="transparent";
     string stroke_width="5";
};


//rectange,line,circle,ellipse,polygon<wielokat>


class Rectangle{
    public:
    IndexP index=IndexP("rect");
    Rectangle(FigureConfig conf=FigureConfig()){
        index.addAtribute("x",conf.x);
        index.addAtribute("y",conf.y);
        index.addAtribute("rx",conf.rx);
        index.addAtribute("ry",conf.ry);
        index.addAtribute("width",conf.width);
        index.addAtribute("height",conf.height);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};

class Circle{
    public:
    IndexP index=IndexP("circle");
    Circle(string cx,string cy,string r,FigureConfig conf=FigureConfig()){
        index.addAtribute("cx",cx);
        index.addAtribute("cy",cy);
        index.addAtribute("r",r);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};

class Ellipse{
    public:
    IndexP index=IndexP("ellipse");
    Ellipse(string cx,string cy,string rx,string ry,FigureConfig conf=FigureConfig()){
        index.addAtribute("cx",cx);
        index.addAtribute("cy",cy);
        index.addAtribute("rx",rx);
        index.addAtribute("ry",ry);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};

class Line{
    public:
    IndexP index=IndexP("line");
    Line(string x1,string x2, string y1,string y2,FigureConfig conf=FigureConfig()){
        index.addAtribute("x1",x1);
        index.addAtribute("x2",x2);
        index.addAtribute("y1",y1);
        index.addAtribute("y2",y2);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};

class Polygon{
    public:
    IndexP index=IndexP("polygon");
    Polygon(FigureConfig conf=FigureConfig()){
        index.addAtribute("x",conf.x);
        index.addAtribute("y",conf.y);
        index.addAtribute("rx",conf.rx);
        index.addAtribute("ry",conf.ry);
        index.addAtribute("width",conf.width);
        index.addAtribute("height",conf.height);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};

class Polyline{
    public:
    IndexP index=IndexP("polyline");
    Polyline(string points, FigureConfig conf=FigureConfig()){
        index.addAtribute("points",points);
        index.addAtribute("stroke",conf.stroke);
        index.addAtribute("fill",conf.fill);
        index.addAtribute("stroke-width",conf.stroke_width);
    }
};



#endif // SVG_H_INCLUDED
