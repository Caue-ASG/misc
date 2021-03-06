#include <math.h>
#include <iostream>
struct point
{
    double x = 0.0, y = 0.0, z = 0.0;
    point() = default;
    point( double x, double y, double z): x(x), y(y), z(z){};
};


struct Sphere
{
    point c;
    double r;
    Sphere() = default;
    Sphere(point c, double r): c(c), r(r){};
};

struct line
{
    point p;
    point v;
    double t;
    line() = default;
    line(point p, point v): p(p), v(v){};
};


double distance(point p1, point p2)
{
    return (std::pow(p2.x-p1.x,2) + std::pow(p2.y-p1.y,2) + std::pow(p2.y-p1.y,2));
}


bool DoesIntersect(Sphere e, line l)
{
    double a = (e.c.x - l.p.x), 
           b = (e.c.y - l.p.y),
           c = (e.c.z - l.p.z);

    l.t = ((a*a + b*b + c*c)/(a*l.v.x + b*l.v.y + c*l.v.z));
    point u = {l.p.x + l.v.x*l.t, l.p.y + l.v.y*l.t ,l.p.z + l.v.z*l.t};
 
    // da pra ótimizar o tempo usando a ideia de probabilidade,  e um losangulo dentro do circulo
    return ((distance(e.c, u) - std::pow(e.r,2))<= 0);
}


int main(int argc, char const *argv[])
{
    Sphere bola = {{7.2,5.3,24.1}, 3.45};
    line reta = {{31,0.6,5}, {-24.5, 3.7, 21.5}};
    
    if(DoesIntersect(bola,reta))
        std::cout << "Deu match";
    else
        std::cout << "Não deu";
    return 0;
}

