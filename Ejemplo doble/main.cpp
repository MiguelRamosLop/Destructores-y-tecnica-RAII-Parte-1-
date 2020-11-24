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
    Puntero *p = new Puntero("JuanFran");

    while (empezando) {
        start();
        update(empezando);
        finish();
    }

    //throw std::runtime_error ("Excepcion");
    delete p;

}

int main() {
    try {
        rungame();
    } catch (...) {
        std::cout << "Abortado! excepcion acontecida." << std::endl;
    }
    return 0;
}
