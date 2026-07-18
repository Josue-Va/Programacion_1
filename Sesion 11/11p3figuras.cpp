#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Figura
{
public:
    virtual void dibujar() const = 0;
    virtual double area() const = 0;
};

class Circulo : public Figura
{
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    void dibujar() const override
    {
        cout << "Dibujando circulo de radio " << radio << endl;
    }

    double area() const override
    {
        return 3.14159 * radio * radio;
    }
};

class Rectangulo : public Figura
{
private:
    double ancho, alto;
public:
    Rectangulo(double base, double alt) : ancho(base), alto(alt) {}

    void dibujar() const override
    {
        cout << "Dibujando Rectangulo de " << ancho << " de ancho y " << alto << " de alto" << endl;
    }

    double area() const override
    {
        return ancho * alto;
    }
};

int main()
{
    vector<unique_ptr<Figura>> figuras;
    figuras.push_back(make_unique<Circulo>(5.0));
    figuras.push_back(make_unique<Rectangulo>(4, 6));

    for(const auto& f : figuras)
    {
        f->dibujar();
        cout << "Area: " << f->area() << endl << endl;
    }

    return 0;
}