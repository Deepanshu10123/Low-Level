# Composite

Treat a single object and a **group** of objects the same way, through
one shared interface — useful for tree-shaped data like files/folders.

Real-world example: a company org chart. "What's your total headcount?"
works the same way whether you ask one employee or an entire department
(which might contain more employees, or whole sub-departments).

## The problem it solves
A file has a size. A folder's "size" is the sum of everything inside it —
which could be more files, or more folders, nested arbitrarily deep.
Composite lets you call `getSize()` on either, the same way, without
caring whether it's one item or a whole nested tree.

## The shape
```cpp
class FileSystemItem {
public:
    virtual int getSize() = 0;
    virtual ~FileSystemItem() = default;
};

class File : public FileSystemItem {
public:
    File(int s) : size(s) {}
    int getSize() override { return size; }
private:
    int size;
};

class Folder : public FileSystemItem {
public:
    void add(unique_ptr<FileSystemItem> item) { children.push_back(move(item)); }
    int getSize() override {
        int total = 0;
        for (const auto& c : children) total += c->getSize();
        return total;
    }
private:
    vector<unique_ptr<FileSystemItem>> children;
};
```

Using it:
```cpp
Folder root;
root.add(make_unique<File>(100));
auto sub = make_unique<Folder>();
sub->add(make_unique<File>(50));
root.add(move(sub));
cout << root.getSize();   // 150
```

## The one new idea
`Folder` **is-a** `FileSystemItem`, but also **holds a list of that same
interface type** (`vector<unique_ptr<FileSystemItem>>`). That's what
enables nesting — a `Folder`'s children can be `File`s, or more `Folder`s,
mixed freely. `getSize()` keeps calling itself down through however many
layers actually exist, without knowing the depth in advance.

## In UML
- `File`, `Folder` → `FileSystemItem`: generalization.
- `Folder` → `FileSystemItem` (the `children` list): composition (owns
  and holds the children, filled diamond) — and notably, it's composition
  of the **same type** `Folder` itself inherits from.

## One-line summary
Leaf and container share one interface; the container holds a list of
that same interface, so operations work uniformly at any depth.
