#include <stdio.h>
#include <math.h>

int main()
{
    FILE*datos;
    FILE*resultados;
    int deltaf=0, i;
    float masap=0, masae=0, tevo=0, deltaT=0, xi=0, vxi=0, yi=0, vyi=0, zi=0, vzi=0;
    datos = fopen("datos","r");
    fscanf(datos, "%f", &masap);
    fscanf(datos, "%f", &masae);
    fscanf(datos, "%f", &tevo);
    fscanf(datos, "%f", &deltaT);
    fscanf(datos, "%f", &xi);
    fscanf(datos, "%f", &vxi); //lectura de datos desde archivo
    fscanf(datos, "%f", &yi);
    fscanf(datos, "%f", &vyi);
    fscanf(datos, "%f", &zi);
    fscanf(datos, "%f", &vzi);
    fclose(datos);
    deltaf=tevo/deltaT;
    float x[deltaf], y[deltaf], z[deltaf], vx[deltaf], vy[deltaf], vz[deltaf]; //asignacion de varialbes
    float xo=xi, vxo=vxi, yo=yi, vyo=vyi, zo=zi, vzo=vzi, r;
    for(i=0;i<deltaf;i++){   //calculos de la orbita
        r=sqrt(xo*xo+yo*yo*+zo*zo);
        x[i]= xo+(vxo*deltaT);
        y[i]= yo+(vyo*deltaT);// se guardan dentro de arreglos
        z[i]= zo+(vzo*deltaT);
        vx[i]= vxo-(deltaT*4*3.14*3.14*masae*xo)/(r*r*r);
        vy[i]= vyo-(deltaT*4*3.14*3.14*masae*yo)/(r*r*r);
        vz[i]= vzo-(deltaT*4*3.14*3.14*masae*zo)/(r*r*r);
        xo=x[i];
        yo=y[i];
        zo=z[i];
        vxo=vx[i];
        vyo=vy[i];
        vzo=vz[i];
    }
    resultados=fopen("resultados","w");
    for(i=0;i<deltaf;i++){
    fprintf(resultados,"%f %f %f %f %f %f \n", x[i], y[i], z[i], vx[i], vy[i], vz[i]); //se imprimen los resultados a un documento
    }
    fclose(resultados);
    return 0;
}
