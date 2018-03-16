class Fraccion
{
    
    friend Fraccion operator+(Fraccion, Fraccion);
    friend bool operator>(Fraccion, Fraccion);
    friend Fraccion operator+(Fraccion, int);
    friend Fraccion operator+(int, Fraccion);
    friend Fraccion operator++(Fraccion&);
    friend void operator += (Fraccion &f1, Fraccion f2);
    
public:
    Fraccion();
    Fraccion(int, int);
    ~Fraccion();
    
    void setNum(int);
    void setDen(int);
    
    int getNum();
    int getDen();
    
    double calcValorReal();
    void muestra();
    
    Fraccion operator*(Fraccion f1);
    Fraccion operator-();
    Fraccion operator-(Fraccion);
    bool operator <(Fraccion);
    Fraccion operator --();
    
private:
    int num;
    int den;
    
};

Fraccion::Fraccion()
{
    num = 1;
    den = 1;
}

Fraccion::Fraccion(int num, int den)
{
    this->num = num;
    this->den= den;
    
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }
}

Fraccion::~Fraccion()
{
    
}

void Fraccion::setNum(int num)
{
    this->num = num;
}

void Fraccion::setDen(int den)
{
    this->den = den;
    
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

double Fraccion::calcValorReal()
{
    return (double)num / den;
}

void Fraccion::muestra()
{
    std::cout << num << "/" << den;
}

Fraccion Fraccion::operator*(Fraccion f1)
{
    Fraccion res;
    
    res.num = num * f1.num;
    res.den = den * f1.den;
    
    return res;
}

Fraccion Fraccion::operator-()
{
    Fraccion res(-num, den);
    return res;
}

Fraccion Fraccion::operator-(Fraccion f1)
{
    Fraccion res;
    
    res.num = num * f1.den- den * f1.num;
    res.den = den* f1.den;
    
    return res;
}

Fraccion operator+(Fraccion f1, Fraccion f2)
{
    Fraccion f3;
    f3.num = f1.num* f2.den + f1.den*f2.num;
    f3.den = f1.den*f2.den;
    
    return f3;
}

bool operator> (Fraccion f1, Fraccion f2)
{
    return f1.calcValorReal() > f2.calcValorReal();
}

Fraccion operator+(Fraccion f, int e)
{
    Fraccion f2(e,1);
    return f + f2;
}

Fraccion operator+(int e, Fraccion f)
{
    return f + e;
}


Fraccion operator++(Fraccion &f1)
{
    f1 = f1 + 1;
    
    return f1;
}

bool Fraccion::operator <(Fraccion f1)
{
    return calcValorReal() > f1.calcValorReal();
}

Fraccion Fraccion::operator --()
{
    *this = *this +(-1);
    return *this;
}

void operator += (Fraccion &f1, Fraccion f2)
{
    f1 = f1 + f2;
}

