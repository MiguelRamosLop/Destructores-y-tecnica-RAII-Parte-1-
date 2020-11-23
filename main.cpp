#include <iostream>
class CGameObject {
    //como una clase de por si es de carácter privado no hace falta pasarle el private:
        std::string Object_nombre;
    //especificamos que de ahora en adelante las isntrucciones son públicas
    public:
    //creo un constructor publico
    CGameObject(const std::string& name )
            : Object_nombre(name)
        {
        //hago que me indique cuando es creado mi nombre de objeto
        std::cout << "Construccion de: " << Object_nombre << std::endl;
        }
    //llamo explicitamente al destructor de la clase
    ~CGameObject() {
        std::cout << "Destruccion de: " << Object_nombre << std::endl;
    }

};

class CGameResource  {
    //me creo un puntero de tipo CGameObject
    CGameObject *objeto;
public:
    CGameResource(const std::string& name)
    : objeto (nullptr)
    {
        init(name);
    }
    ~CGameResource() {
        //hago un delete seguro, compruebo que estoy apuntando a algún sitio y luego le hago delete y lo
        //dejo como null
        if (objeto) {
            delete objeto;
            objeto = nullptr;
        }
    }
    void init (const std::string& name) {
        //aqui indico el new (constructor del objeto nombre)
        objeto = new CGameObject(name);
    }

    CGameObject *p() {
        return objeto;
    };
};

void input() {
    std::cout << "Input." << std::endl;
}

void render() {
    std::cout << "Render." << std::endl;
}

void update (bool& p) {
    std::cout << "Update." << std::endl;
    throw std::runtime_error ("Error en la ejecución.\n");
    p=false;
}

void rungame() {
    bool playing = true;
    //reservo un espacio de memoria dinámica con el new al que luego lo asigno al puntero p
    //CGameObject *g = new CGameObject("Miguel");
    CGameResource g("Miguel");

    while (playing) {
        input();
        update(playing);
        render();
    }
    //llamo al destructor y luego libero el espacio de memoria
    //delete g;
}

int main() {
    //usamos un bloque try-catch porque puede que rungame falle en algun momento y tenga que lanzar alguna excepcion
    try {
        rungame();
    } catch (std::runtime_error) {
        //recordemos que std::runtime_error informa de errores difíciles ocurridos en tiempo de ejecución
        std::cout << "Abortado! Excepcion lanzada" << std::endl;
    }
    return 0;
}
