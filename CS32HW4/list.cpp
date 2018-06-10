//
//  main.cpp
//  hw4-4
//
//  Created by XiaoJia Quan on 5/28/18.
//

void listAll(string path, const File* f)  // two-parameter overload
{
    string s;
    if (f->files() == NULL) {
        cout<<"/"<<path<<f->name()<<endl;
        return;
    }
    
    if (f->name()!="") {
        cout<<"/"<<path<<f->name()<<endl;
    }

    for(vector<File*>::const_iterator temp = f->files()->begin();temp != f->files()->end(); temp++ )
    {
        if (f->name() != "") {
            s = path+f->name()+"/";
        }
        listAll(s, *temp);
    }
}
