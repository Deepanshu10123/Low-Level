// Practice: Composite
// Read theory/22_composite.md first if you haven't.
// Building this one tiny piece at a time. Don't look ahead.

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// STEP 1: write ONLY the FileSystemItem interface — ONE pure virtual
// method, getSize() returning int, plus a virtual destructor.
// Nothing else yet, no File.
class FileSystemItem{
    public:
        virtual int getSize()=0;
        virtual ~FileSystemItem()=default;
};
class File : public FileSystemItem{
    int size;
    public:
        File(int s): size(s){}
        int getSize() override{
            return size;
        }
};
class Folder: public FileSystemItem{
    vector<unique_ptr<FileSystemItem>> children;
    public:
        void add(unique_ptr<FileSystemItem> item){
            children.push_back(move(item));
        }
        int getSize() override{
            int total = 0 ;
            for(int i = 0 ; i<children.size(); i++)
            {
                total = total + children[i]->getSize();
            }
            return total;
        }
};
int main() {
    Folder root;
    root.add(make_unique<File>(100));
    auto sub = make_unique<Folder>();
    sub->add(make_unique<File>(50));
    root.add(move(sub));
    cout<<root.getSize();
    return 0;
}
