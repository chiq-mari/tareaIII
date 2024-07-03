#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

struct Dot{
    float x;
    float y;
    float z;

    Dot(float x, float y, float z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

struct Dot2{
    float x;
    float y;
    Dot2(float x, float y){
        this->x=x;
        this->y=y;
    }
};

float distancia(float, float, float, float);

float distancia(float, float, float, float, float, float);

Dot suma(float, float, float, float);

Dot suma(float, float, float, float, float, float);

Dot resultanteArreglo(Dot[], int, bool); // bool = true -> 3D

float productPunto(float,float,float,float);

float productPunto(float,float,float,float,float,float);

Dot productCruz(float,float,float,float);

Dot productCruz(float,float,float,float,float,float);

void vectorPlano(float, float, float);

int main(){
    cout<<"Test funcion distancia"<<endl;
    cout<<"Puntos (1,2) y (4,5): "<<distancia(1,2,4,5)<<endl;
    cout<<"Puntos (1,7,5) y (4,8,7): "<<distancia(1,7,5,4,8,7)<<endl;
    cout<<endl;

    cout<<"Test funcion suma"<<endl;
    cout<<"Puntos (1,5) y (8.7,6.7): "<<'('<<suma(1,5,8.7,6.7).x<<','<<suma(1,5,8.7,6.7).y<<')'<<endl;
    cout<<"Puntos (2.3,5,9) y (8.7,4.7,0): "<<'('<<suma(2.3,5,9,8.7,4.7,0).x<<','<<suma(2.3,5,9,8.7,4.7,0).y<<','<<suma(2.3,5,9,8.7,4.7,0).z<<')'<<endl;
    cout<<endl;

    Dot trialList[]={{1,8,7},{7,8,4},{0,0,2},{7,4,6},{5,5,1},{8,4,2}};
    cout<<"Test resultante Arreglo"<<endl;
    cout<<"Arreglo: {{1,8,7},{7,8,4},{0,0,2},{7,4,6},{5,5,1},{8,4,2}}"<<endl;
    cout<<"2D: "<<'('<<resultanteArreglo(trialList, 6, false).x<<','<<resultanteArreglo(trialList, 6, false).y<<','<<resultanteArreglo(trialList, 6, false).z<<')'<<endl;
    cout<<"3D: "<<'('<<resultanteArreglo(trialList, 6, true).x<<','<<resultanteArreglo(trialList, 6, true).y<<','<<resultanteArreglo(trialList, 6, true).z<<')'<<endl;
    cout<<endl;

    cout<<"Test producto punto"<<endl;
    cout<<"Puntos (1,2) y (5,6): "<<productPunto(1,2,5,6)<<endl;
    cout<<"Puntos (2,5,8) y (4,7,10): "<<productPunto(2,5,8,4,7,10)<<endl;
    cout<<endl;

    cout<<"Test producto cruz"<<endl;
    cout<<"Puntos (9, 8) y (10,11): "<<productCruz(9,8,10,11).z<<'k'<<endl;
    cout<<"Puntos (1,4,6) y (5,8,9): "<<'('<<productCruz(1,4,6,5,8,9).x<<','<<productCruz(1,4,6,5,8,9).y<<','<<productCruz(1,4,6,5,8,9).z<<')'<<endl;
    cout<<endl;

    cout<<"Test funcion vectorPlano"<<endl;
    cout<<"(0, 8, 7): ";
    vectorPlano(0,8,7);
    cout<<"(9, -8, 7): ";
    vectorPlano(9,-8,7);
    cout<<"(-3, 8, -7): ";
    vectorPlano(-3,8,-7);
    cout<<"(2, 8, 7): ";
    vectorPlano(2,8,7);
}

float distancia(float x1, float y1, float x2, float y2){
    float d;
    d=sqrt(pow(x2-x1, 2)+pow(y2-y1,2));
    return d;
}

float distancia(float x1, float y1, float z1, float x2, float y2, float z2){
    float d;
    d=sqrt(pow(x2-x1, 2)+pow(y2-y1,2)+pow(z2-z1, 2));
    return d;
}

Dot suma(float x1, float y1, float x2, float y2){
    Dot v3= {x1+x2, y1+y2, 0};
    return v3;
}
Dot suma(float x1, float y1, float z1, float x2, float y2, float z2){
    Dot v3= {x1+x2, y1+y2, z1+z2};
    return v3;
}

Dot resultanteArreglo(Dot lista[], int a, bool b){
    Dot r={0,0,0};
    if(b){
    for (int i=0; i<a; i++){
        r.x+=lista[i].x;
        r.y+=lista[i].y;
        r.z+=lista[i].z;
    }
    }else{
        for (int i=0; i<a; i++){
        r.x+=lista[i].x;
        r.y+=lista[i].y;
    }
    }
    return r;
}

float productPunto(float x1, float y1, float x2 ,float y2){
    float p;
    p=x1*x2+y1*y2;
    return p;
}

float productPunto(float x1, float y1, float z1, float x2 ,float y2, float z2){
    float p;
    p=x1*x2+y1*y2+z1*z2;
    return p;

}

Dot productCruz(float x1, float y1, float x2 ,float y2){
    Dot r={0, 0, x1*y2-x2*y1};
    return r;
}

Dot productCruz(float x1, float y1, float z1, float x2 ,float y2, float z2){
    Dot r={(y1*z2-z1*y2), -(x1*z2-z1*x2), (x1*y2-y1*x2)};
    return r;
}

void vectorPlano(float x, float y, float z){
    cout<<x<<"i+"<<y<<"j+"<<z<<'k'<<endl;

    if( x==0 && y==0 && z==0){
        cout<<"El vector es el origen"<<endl;
    }else if( y==0 && z==0){
        cout<<"El vector esta en el eje X"<<endl;
    }else if(x==0 && z==0){
        cout<<"El vector esta en el eje Y"<<endl;
    }else if(x==0 && y==0){
        cout<<"El vector esta en el eje Z"<<endl;
    }else if(x==0){
        cout<<"El vector esta en el plano YZ"<<endl;
    }else if(y==0){
        cout<<"El vector esta en el plano XZ"<<endl;
    }else if(z==0){
        cout<<"El vector esta en el plano XY"<<endl;
    }else if(x>0 && y>0 && z>0){
        cout<<"El vector esta en el octante I"<<endl;
    }else if(x<0 && y>0 && z>0){
        cout<<"El vector esta en el octante II"<<endl;
    }else if(x<0 && y<0 && z>0){
        cout<<"El vector esta en el octante III"<<endl;
    }else if(x>0 && y<0 && z>0){
        cout<<"El vector esta en el octante IV"<<endl;    
    }else if(x>0 && y>0 && z<0){
        cout<<"El vector esta en el octante V"<<endl;
    }else if(x<0 && y>0 && z<0){
        cout<<"El vector esta en el octante VI"<<endl;
    }else if(x<0 && y<0 && z<0){
        cout<<"El vector esta en el octante VII"<<endl;
    }else{
        cout<<"El vector esta en el octante VIII"<<endl;
    }

}