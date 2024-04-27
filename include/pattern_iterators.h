#ifndef PTRN_ITERATORS_H
#define PTRN_ITERATORS_H

template<class Type>
class Iterator{
protected:
    Iterator(){}

public:
    virtual ~Iterator(){}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Type getCurrent() const = 0;
};

template<class Type>
class IteratorDecorator : public Iterator<Type>{
protected:
    Iterator<Type> *It;

public:
    IteratorDecorator(Iterator<Type> *it){
        It = it;
    }
    virtual ~IteratorDecorator(){delete It;}
    virtual void first() {It->first();};
    virtual void next() {It->next();};
    virtual bool isDone() const {return It->isDone();};
    virtual Type getCurrent() const {return It->getCurrent();};
};

#endif // PTRN_ITERATORS_H
