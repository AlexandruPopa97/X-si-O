#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void afisareTabla(char tabla[3][3])
{
    cout<<"___________________"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"|     |     |     |"<<endl;
        for(int j=0;j<3;j++)
        {
            cout<<"|  "<<tabla[i][j]<<"  ";
        }
        cout<<"|"<<endl;
        cout<<"|_____|_____|_____|"<<endl;
    }
}

void initializareTabla(char tabla[3][3])
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            tabla[i][j] = '.';
}

void updateTabla(char tabla[3][3],int poz,char caracter)
{
    if(poz == 7)
        tabla[0][0] = caracter;
    else if(poz == 8)
        tabla[0][1] = caracter;
    else if(poz == 9)
        tabla[0][2] = caracter;
    else if(poz == 4)
        tabla[1][0] = caracter;
    else if(poz == 5)
        tabla[1][1] = caracter;
    else if(poz == 6)
        tabla[1][2] = caracter;
    else if(poz == 1)
        tabla[2][0] = caracter;
    else if(poz == 2)
        tabla[2][1] = caracter;
    else if(poz == 3)
        tabla[2][2] = caracter;
}

bool pozitieValida(char tabla[3][3],int poz)
{
    if(poz == 7)
    {
        if(tabla[0][0] == '.')
            return true;
    }
    else if(poz == 8)
    {
       if(tabla[0][1] == '.')
            return true;
    }
    else if(poz == 9)
    {
       if(tabla[0][2] == '.')
            return true;
    }
    else if(poz == 4)
    {
       if(tabla[1][0] == '.')
            return true;
    }
    else if(poz == 5)
    {
       if(tabla[1][1] == '.')
            return true;
    }
    else if(poz == 6)
    {
       if(tabla[1][2] == '.')
            return true;
    }
    else if(poz == 1)
    {
       if(tabla[2][0] == '.')
            return true;
    }
    else if(poz == 2)
    {
       if(tabla[2][1] =='.')
            return true;
    }
    else if(poz == 3)
    {
       if(tabla[2][2] == '.')
            return true;
    }
    return false;
}

bool gameWin(char tabla[3][3])
{
    for(int i=0;i<3;i++)
        if(tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2] && (tabla[i][0] == 'X' || tabla[i][0] == 'O'))
            return true;
    for(int j=0;j<3;j++)
        if(tabla[0][j] == tabla[1][j] && tabla[1][j] == tabla[2][j] && (tabla[0][j] == 'X' || tabla[0][j] == 'O'))
            return true;
    if(tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && (tabla[0][0] == 'X' || tabla[0][0] == 'O'))
        return true;
    else if(tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && (tabla[0][2] == 'X' || tabla[0][2] == 'O'))
        return true;
    return false;
}

int blocheazax(char tabla[3][3])
{
    for(int i=0;i<3;i++)
        if((tabla[i][0] == tabla[i][1]) && tabla[i][0] == 'X')
        {
            if(tabla[i][2] == '.')
            return i*3+3;
        }
        else if ((tabla[i][1] == tabla[i][2]) && (tabla[i][1] == 'X'))
        {
            if(tabla[i][0] == '.')
            return i*3+1;
        }
        else if ((tabla[i][0] == tabla[i][2]) && (tabla[i][0] == 'X'))
        {
            if(tabla[i][1] == '.')
            return i*3+2;
        }
    for(int j=0;j<3;j++)
        if((tabla[0][j] == tabla[1][j]) && (tabla[1][j] == 'X'))
        {
            if(tabla[2][j] == '.')
            return j+1;
        }
        else if ((tabla[0][j] == tabla[2][j]) && (tabla[0][j] == 'X'))
        {
            if(tabla[1][j] == '.')
            return j+4;
        }
        else if ((tabla[1][j] == tabla[2][j]) && (tabla[1][j] == 'X'))
        {
            if(tabla[0][j] == '.')
            return j+7;
        }
    if(tabla[0][0] == tabla[1][1] && tabla[1][1] == 'X')
        if(tabla[2][2] == '.')
            return 3;
    if(tabla[0][0] == tabla[2][2] && tabla[0][0] == 'X')
        if(tabla[1][1] == '.')
            return 5;
    if(tabla[2][2] == tabla[1][1] && tabla[1][1] == 'X')
        if(tabla[0][0] == '.')
            return 7;
    return 0;
}

int castigaO(char tabla[3][3])
{
    for(int i=0;i<3;i++)
        if((tabla[i][0] == tabla[i][1]) && tabla[i][0] == 'O')
        {
            if(tabla[i][2] == '.')
            return 3*i + 3;
        }
        else if ((tabla[i][1] == tabla[i][2]) && (tabla[i][1] == 'O'))
        {
            if(tabla[i][0] == '.')
            return i*3+1;
        }
        else if ((tabla[i][0] == tabla[i][2]) && (tabla[i][0] == 'O'))
        {
            if(tabla[i][1] == '.')
            return i*3+2;
        }
    for(int j=0;j<3;j++)
        if((tabla[0][j] == tabla[1][j]) && (tabla[1][j] == 'O'))
        {
            if(tabla[2][j] == '.')
            return j+1;
        }
        else if ((tabla[0][j] == tabla[2][j]) && (tabla[0][j] == 'O'))
        {
            if(tabla[1][j] == '.')
            return j+4;
        }
        else if ((tabla[1][j] == tabla[2][j]) && (tabla[1][j] == 'O'))
        {
            if(tabla[0][j] == '.')
            return j+7;
        }
    if(tabla[0][0] == tabla[1][1] && tabla[1][1] == 'O')
        if(tabla[2][2] == '.')
            return 7;
    if(tabla[0][0] == tabla[2][2] && tabla[0][0] == 'O')
        if(tabla[1][1] == '.')
            return 5;
    if(tabla[2][2] == tabla[1][1] && tabla[1][1] == 'O')
        if(tabla[0][0] == '.')
            return 3;
    return 0;
}

int main()
{
    char tabla_joc[3][3];
    //initializareTabla(tabla_joc);
    afisareTabla(tabla_joc);

    srand(time(NULL));
    int pozX;
    int pozO;
    bool gameOn = true;
    int nrMutari = 0;
    int vreauSaJoc = 1;
    int nrWinX = 0;
    int nrWinO = 0;

    while (vreauSaJoc == 1)
    {
        start:
        initializareTabla(tabla_joc);
        gameOn = true;
        nrMutari = 0;
    while(gameOn)
    {
        system("cls");
        afisareTabla(tabla_joc);
        if(nrMutari < 9)
        {
            cout<<"Introduceti cifra corespunzatoare pozitiei unde doriti sa plasati 'X' "; cin>>pozX;
            while(pozitieValida(tabla_joc,pozX) == false)
            {
                cout<<"Introduceti o pozitie neocupata "; cin>>pozX;
            }
            updateTabla(tabla_joc,pozX,'X');
        }
        nrMutari ++;
        system("cls");
        afisareTabla(tabla_joc);
        if(gameWin(tabla_joc) == true)
        {
            system("cls");
            afisareTabla(tabla_joc);
            cout<<"Felicitari ati castigat!"<<endl;
            gameOn = false;
            nrWinX ++;
            break;
        }
        pozO = 0;
        /*
        pozO = castigaO(tabla_joc);
        if(pozO != 0 && nrMutari < 9 && pozitieValida(tabla_joc,pozO))
        {
            updateTabla(tabla_joc,pozO,'O');
            goto saritura;
        }
        */
        pozO = blocheazax(tabla_joc);
        if(pozO != 0 && nrMutari < 9 && pozitieValida(tabla_joc,pozO))
        {
                updateTabla(tabla_joc,pozO,'O');
                goto saritura;
        }
        else if(nrMutari < 9)
        {
            pozO = rand() % 9 + 1;
            while(pozitieValida(tabla_joc,pozO) == false && nrMutari<9)
                pozO = rand() % 9 + 1;
            updateTabla(tabla_joc,pozO,'O');
        }
        saritura:
        nrMutari++;
        if(gameWin(tabla_joc) == true)
        {
            system("cls");
            afisareTabla(tabla_joc);
            cout<<"Ati pierdut :("<<endl;
            nrWinO ++;
            gameOn = false;
        }
        else if(nrMutari >= 9)
        {
            system("cls");
            afisareTabla(tabla_joc);
            cout<<"Egalitate"<<endl;
            gameOn = false;
        }
    }
    cout<<"Scor curent:"<<endl;
    cout<<"X a castigat de "<<nrWinX<<" ori."<<endl;
    cout<<"O a castigat de "<<nrWinO<<" ori."<<endl;
    cout<<"Doriti sa mai jucati? (1=DA/2=NU) ";cin>>vreauSaJoc;
    }
    return 0;
}
