#include <iostream>

using namespace std;

 struct Vektor {
    int niz[100];
    int log_velicina;
    int fizicka_velicina;

    void vector_new()
    {
        log_velicina = 0;
        fizicka_velicina = 2;
    }

    void vector_push_back(int vrijednost)
    {
        if (log_velicina < fizicka_velicina)
        {
            niz[log_velicina] = vrijednost;
            log_velicina++;
        }
        else {
            int nova_fiz_vel = fizicka_velicina * 2;
            if (nova_fiz_vel > 100) 
            {
                nova_fiz_vel = 100;
            }

            if (nova_fiz_vel <= fizicka_velicina)
            {
                return; 
            }

            int niz2[100];
            for (int i = 0; i < log_velicina; i++)
            {
                niz2[i] = niz[i];
            }
            niz2[log_velicina] = vrijednost;
            fizicka_velicina = nova_fiz_vel;
            log_velicina++;
            for (int i = 0; i < log_velicina; i++) 
            {
                niz[i] = niz2[i];
            }
        }
    }

    void vector_pop_back()
    {
        if (log_velicina > 0)
        {
            log_velicina--;
        }
    }

    int vector_front() {
        if (log_velicina > 0) 
        {
            return niz[0];
        }
        else
        {
            return -1;
        }
    }

    int vector_back()
    {
        if (log_velicina > 0) 
        {
            return niz[log_velicina - 1];
        }
        else 
        {
            return -1;
        }
    }

    int vector_size()
    {
        return log_velicina;
    }

    void vector_delete()
    {
        log_velicina = 0;
        fizicka_velicina = 2;
        
    }
};

int main()
{
    Vektor vector;
    vector.vector_new();

    for (int i = 0; i < 20; i++) {
        vector.vector_push_back(i);
    }

    for (int i = 0; i < vector.vector_size(); i++) {
        cout << vector.niz[i] << ' ';
    }
    cout << endl;
    cout << "Prvi element je: " << vector.vector_front() << endl;
    cout << "Zadnji element je: " << vector.vector_back() << endl;

    vector.vector_pop_back();

    cout << "Velicina vektora nakon uklanjanja: " << vector.vector_size() << endl;

    vector.vector_delete();
    cout << "Logicka velicina vektora (nakon brisanja) je: " << vector.log_velicina<<endl;
    cout << "Fizicka velicina vektora (nakon brisanja) je: " << vector.fizicka_velicina << endl;
    return 0;
}
