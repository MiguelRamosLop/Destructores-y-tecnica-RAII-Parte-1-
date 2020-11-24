#include <iostream>

class Puntero {
private:
    std::string nombre_puntero;
public:
    Puntero (const std::string& n)
    : nombre_puntero(n)
    {
        std::cout << "Construccion de: " << nombre_puntero << std::endl;
    }
    ~Puntero ()
    {
        std::cout << "Destruccion de: " << nombre_puntero << std::endl;
    }

};

class PunteroRAII {
private:
    Puntero *punteroQ;
public:
    PunteroRAII( const std::string& n)
            : punteroQ(nullptr)
    {
       init(n);

    }
    ~PunteroRAII() {
        if (punteroQ) {
            delete punteroQ;
            punteroQ = nullptr;
        }
    }

    void init(const std::string& n) {
        punteroQ = new Puntero(n);
    }

};

void start() {
    std::cout << "Empezado!" << std::endl;
}

void update(bool& n) {
    std::cout << "update!" << std::endl;
    n = false;
}

void finish() {
    std::cout << "Finalizado!" << std::endl;
}

void rungame() {
    bool empezando = true;
    PunteroRAII p("ers");

    while (empezando) {
        start();
        update(empezando);
        finish();
    }

    throw std::runtime_error ("Excepcion");

}

int main() {
    try {
        rungame();
    } catch (...) {
        std::cout << "Abortado! excepcion acontecida." << std::endl;
    }
    return 0;
}
