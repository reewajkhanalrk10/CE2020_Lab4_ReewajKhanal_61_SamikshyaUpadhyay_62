
#pragma once //using #pragma once will delegate the task, of detecting subsequent #include statements for the same file, to the compiler.
class AbstractBST

{
    public:
    virtual bool isempty()=0;
    virtual void add(int key)=0;
    virtual void exists (int key)=0;
};