#include <iostream>
#include <fstream>

#include "manipulators.h"
#include "svg.h"
#include <unordered_map>
#include <list>



using namespace std;



int main()
{
    //manipulatory ostream:
    cout<<"quot: "<<quot<<endl;
    cout<<"amp: "<<amp<<endl;
    cout<<"lt: "<<lt<<endl;
    cout<<"gt: "<<gt<<endl;
    cout <<"attr:"<<attr("*****", "***") << endl;
    cout<<endl<<endl;

    //manipulatory istream:
    istringstream iss{"whatssupp AA \n    \n NewLINE"};
    string s1;
    iss>>clearline>>s1;
    cout<<"clearline: "<<s1<<endl;

    istringstream iss2{"1234567899999"};
    string s2;
    iss2>>Ignore(8)>>s2;
    cout<<"ignore: "<<s2<<endl;


    //File Print example:
    ifstream infile;
    infile.open("Sth.txt", ios::in );
    string s3;
    infile>>Ignore(8)>>s3;
    cout<<"ignore: "<<s3<<endl;

    cout<<endl<<endl<<"SVG Example: "<<endl;
    IndexS test1 = IndexS("CV");
    test1.addAtribute("Age","42");
    test1.addAtribute("Experiance","lack of");
    test1.addAtribute("sth","AAA");
    IndexS test2=IndexS("occupation");
    Text test3= Text("programmer");
    cout<<"Test3: "<<test3<<endl;
    test2.addContent(&test3);
    cout<<test2<<endl;
    cout<<test1<<endl;
    test1.addContent(&test2);
    cout<<test1<<endl;




    //Figure initialization:
    InitPicture picture = InitPicture();
    FigureConfig conf1 = FigureConfig();
    conf1.x="50";
    conf1.y="300";
    Rectangle rect1 = Rectangle(conf1);
    conf1.stroke="blue";
    conf1.x="70";
    Rectangle rect2 = Rectangle(conf1);
    picture.addPainting(&rect1.index);
    picture.addPainting(&rect2.index);


    Circle circle1 = Circle("100","75","50",conf1);
    picture.addPainting(&circle1.index);

    conf1.stroke="black";
    Circle circle2 = Circle("220","75","50",conf1);
    picture.addPainting(&circle2.index);

    conf1.stroke="red";
    Circle circle3 = Circle("340","75","50",conf1);
    picture.addPainting(&circle3.index);

    conf1.stroke="yellow";
    Circle circle4 = Circle("160","125","50",conf1);
    picture.addPainting(&circle4.index);

    conf1.stroke="green";
    Circle circle5 = Circle("270","125","50",conf1);
    picture.addPainting(&circle5.index);


     Ellipse ellipse1 = Ellipse("200","300","50","20",conf1);
    picture.addPainting(&ellipse1.index);
        conf1.stroke="red";
    Ellipse ellipse2 = Ellipse("280","300","50","20",conf1);
    picture.addPainting(&ellipse2.index);

    conf1.stroke="black";
    Line line1 = Line("80","460","320","320",conf1);
    picture.addPainting(&line1.index);


    Polyline polyline1 = Polyline("60, 110 65, 120 70, 115 75, 130 80, 125 85, 140 90, 135 95, 150 100, 145",conf1);

    picture.addPainting(&polyline1.index);
    picture.save("picture1.html");

    return 0;
}

