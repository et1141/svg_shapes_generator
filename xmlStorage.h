#ifndef XMLSTORAGE_H_INCLUDED
#define XMLSTORAGE_H_INCLUDED

#include <fstream>
#include <unordered_map>
#include <list>
#include <iterator>


class createXmlFigure{
    public:
     string version;
     createXmlFigure(string figure,string filename);

};

class Content{
    public:
        friend ostream& operator << (ostream &os, const Content &content);
    public:
        virtual void print(ostream &os) const{};
};

inline ostream& operator << (ostream &os, const Content &content){
  content.print(os);
  return os;
}



class IndexP : public Content{
    string name;
    unordered_map<string, string> atributes;

    public:
        IndexP (string name):name(name){};

        void addAtribute(string key, string val){
                atributes[key] = val;
            }
        void print (ostream &os)const{
            os<<lt<<name;
            for(auto el : atributes){
                os<<attr(el.first,el.second);
            }
            os<<"/"<<gt;
            }
};



class IndexS : public Content{
        string name;
        unordered_map<string, string> atributes;
        list <Content*> cont;

        public:
            IndexS(string name):name(name){};
            IndexS (const IndexS &old){
                name=old.name;
                atributes=old.atributes;
                cont=old.cont;
            }
            void addAtribute(string key, string val){
                atributes[key] = val;
            }
            void addContent(Content *newCnt){
                cont.push_back(newCnt);
            }

            void print (ostream &os)const{
                os<<lt<<name;
                 for(auto el : atributes){
                    os<<attr(el.first,el.second);
                }
                os<<gt<<endl;
                for(auto el: cont){
                   os<< (*el);
                }

                os<<endl<<lt<<"/"<<name<<gt;
            }
};

class Text : public Content{
    public:
        string txt;
        Text (string text):txt(text){};

        void print (ostream &os)const{
             os<<txt;
            }

};

#endif // XMLSTORAGE_H_INCLUDED
