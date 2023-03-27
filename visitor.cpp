#include <iostream>
#include <vector>
using namespace std;

class Pear;
class Rose;
class Strawberry;

// интерфейс посетителя
__interface Visitor {
    void visit(Pear& pear);
    void visit(Rose& rose);
    void visit(Strawberry& strawberry);
};

// абстрактный класс для всех посещаемых элементов
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Конкретный тип посещённого элемента - дерево Груша
class Pear : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    void pearMethod() {
        cout << "собираем груши...\n";
    }
};

// Конкретный тип посещённого элемента - куст Роза
class Rose : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    void roseMethod() {
        cout << "нюхаем цветы...\n";
    }
};

// Конкретный тип посещённого элемента - трава Земляника
class Strawberry : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    void strawberryMethod() {
        cout << "земляника... или клубника... не понятно\n";
    }
};

// Конкретная реализация Посетителя - Садовник
class Gardener : public Visitor {
public:
    void visit(Pear& pear) override {
        cout << "садовник околачивает груши.\n";
        pear.pearMethod();
    }
    void visit(Rose& rose) override {
        cout << "садовник поливает куст розы.\n";
        rose.roseMethod();
    }
    void visit(Strawberry& strawberry) override {
        cout << "садовник собирает землянику.\n";
        strawberry.strawberryMethod();
    }
};

int main() {
    setlocale(0, "");
    vector<Element*> elements = {
        new Pear, new Rose, new Strawberry };

    Gardener gardener;
    for (auto element : elements)
        element->accept(gardener);

    for (auto element : elements)
        delete element;
}

/*
Данный код демонстрирует реализацию паттерна "Посетитель"
(Visitor pattern), который позволяет добавлять новые операции
над объектами, не изменяя их классы.

Классы Pear, Rose, Strawberry являются конкретными элементами,
которые будут посещаться. Они наследуются от абстрактного класса
Element, который определяет интерфейс метода
accept(Visitor& visitor).

Класс Gardener является конкретной реализацией посетителя,
который реализует методы visit для каждого типа посещаемых
элементов.

В функции main() создаются объекты элементов и сохраняются
в векторе elements. Затем создается объект gardener класса
Gardener, который посещает каждый элемент в векторе elements
с помощью метода accept. Каждый раз, когда объект Gardener
посещает элемент, вызывается соответствующий метод visit,
который выполняет необходимую операцию над элементом.

После выполнения всех операций осуществляется освобождение
памяти, выделенной под элементы.

Код ясно структурирован и демонстрирует хороший пример
использования паттерна "Посетитель". Однако, в зависимости
от конкретной задачи, данный подход может быть избыточным
и неоправданным.
*/

// https://refactoring.guru/ru/design-patterns/visitor

/*
Посетитель — это поведенческий паттерн проектирования,
который позволяет добавлять в программу новые операции,
не изменяя классы объектов, над которыми эти операции
могут выполняться.
*/