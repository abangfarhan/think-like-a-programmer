#include <iostream>

class Interface {
  public:
    virtual ~Interface() {}
    // here we declare do_it as abstract by equalizing it to 0
    // to do that, we must also declare it as virtual
    // see https://stackoverflow.com/a/17282651
    virtual void do_it() = 0;
    virtual void do_that() = 0;
    virtual int ch2Int() = 0; // will be used by Child2. must be defined here too
    virtual int ch3Int() = 0;
};

// class M: public N means that
// class M inherits N's public methods
// see https://stackoverflow.com/a/1372858
class Base: public Interface {
  public:
    ~Base() {
        std::cout << "Base destroyed" << std::endl;
    }
    // virtual. doesn't have to be declared again
    // once virtual, always virtual
    void do_it() {
        std::cout << "Base";
    }
    void do_that() {};
    int ch2Int() {}; // will be used by Child2. must be defined here too
    int ch3Int() {};
};

class DecoratorWrapper: public Interface {
  public:
    DecoratorWrapper(Interface *inner) {
        m_wrappee = inner;
    }
    ~DecoratorWrapper() {
        delete m_wrappee;
    }
    // virtual
    void do_it() {
        m_wrappee->do_it();
    }
    int ch2Int() {
        m_wrappee->ch2Int();
    }
    int ch3Int() {
        m_wrappee->ch3Int();
    }
    void do_that() {}
  private:
    Interface *m_wrappee;
};

class Child1: public DecoratorWrapper {
  public:
    Child1(Interface *core): DecoratorWrapper(core) {}
    ~Child1() {
        std::cout << "Child1 destroyed" << "  ";
    }
    // virtual
    void do_it() {
        DecoratorWrapper::do_it();
        std::cout << "Child1";
    }
};

class Child2: public DecoratorWrapper {
  public:
    Child2(int num, Interface *core): DecoratorWrapper(core) {
        _ch2Int = num;
    }
    ~Child2() {
        std::cout << "Child2 destroyed" << "  ";
    }
    // virtual
    int ch2Int() {
        return _ch2Int;
    }
    void do_it() {
        DecoratorWrapper::do_it();
        std::cout << "Child2";
    }
  private:
    int _ch2Int;
};

class Child3: public DecoratorWrapper {
  public:
    Child3(Interface *core): DecoratorWrapper(core) {}
    ~Child3() {
        std::cout << "Child3 destroyed" << "  ";
    }
    // virtual
    void do_it() {
        DecoratorWrapper::do_it();
        std::cout << "Child3";
    }
    int ch3Int() {return 100;}
};

int main() {
    Interface * base = new Base;
    Interface * anChild1 = new Child1(new Base);
    Interface * anChild1Child2 = new Child2(500, new Child1(new Base));
    Interface * anChild2Child3 = new Child3(new Child2(800, new Base));
    // order of Child1 and Child2 doesn't matter, as long as Base is in the deepest bracket
    base->do_it();
    std::cout << std::endl;

    anChild1->do_it();
    std::cout << std::endl;

    anChild1Child2->do_it();
    std::cout << std::endl;

    anChild2Child3->do_it();
    std::cout << std::endl;

    std::cout << anChild2Child3->ch2Int() << std::endl;

    delete base;
    delete anChild1;
    delete anChild1Child2;
    delete anChild2Child3;
}
