#ifndef PTRN_ITERATORS_H
#define PTRN_ITERATORS_H

#ifndef PATTERNS_H
#define PATTERNS_H

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
    virtual void first() {It ->First();};
    virtual void next() {It ->Next();};
    virtual bool isDone() const {return It ->IsDone();};
    virtual Type getCurrent() const {return It ->GetCurrent();};
};
#endif // PATTERNS_H_INCLUDED


#endif // PTRN_ITERATORS_H
