#include <iostream>
#include <cmath>
#include <array>
#include "Pusher.h"
#include "Tools/ProjectTypes.h"
#define EV 1.6021766208e-19
#define E_M 9.10938356e-31


void test_pusher() {
    cout << "test_pusher start" << endl;

    //initialize data
    int Ntot = 1e6; //vary in range [1e5, 1e6, 1e7, 1e8]
    auto* pos_z = new scalar[Ntot];
    auto* pos_r = new scalar[Ntot];
    auto* vel_z = new scalar[Ntot];
    auto* vel_r = new scalar[Ntot];
    auto* vel_y = new scalar[Ntot];
    auto* Ez = new scalar[Ntot];
    auto* Er = new scalar[Ntot];
    auto* Bz = new scalar[Ntot];
    auto* Br = new scalar[Ntot];

    scalar dt = 1e-11;
    scalar m = E_M;
    scalar q = -1*EV;
    scalar energy = EV;
    scalar vel = sqrt(2*energy/m);
    scalar E = 1e5;
    scalar B = 0.1;
    for (int i = 0; i < Ntot; i++) {
        pos_z[i] = 1; pos_r[i] = 1;
        vel_z[i] = vel; vel_r[i] = vel; vel_y[i] = vel;
        Ez[i] = E; Er[i] = E; Bz[i] = B; Br[i] = 0;
    }

    //test function
    //scalar start = omp_get_wtime();
    int it_num = 1e2;
    for (int it = 0; it < it_num; it++) {
        ParticlePush(pos_z, pos_r, vel_z, vel_r, vel_y, Ez, Er, Bz, Br, dt, q, m, Ntot);
    }
    //scalar end = omp_get_wtime();
    //cout << "time: " << (end - start) / it_num << endl;

    delete[] pos_z;
    delete[] pos_r;
    delete[] vel_z;
    delete[] vel_r;
    delete[] vel_y;
    delete[] Ez;
    delete[] Er;
    delete[] Bz;
    delete[] Br;

    cout << "test_pusher end" << endl;
}

int main() {
    test_pusher();
    return 0;
}
