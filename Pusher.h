#ifndef PROBLEM_1_PUSHER_H
#define PROBLEM_1_PUSHER_H


#include <cstddef>
#include "Tools/ProjectTypes.h"
using namespace std;


void CrossProduct(const scalar v1[], const scalar v2[], scalar result[]);

void RotateToRZ(scalar& pos_r, scalar& pos_y, scalar& vel_r, scalar& vel_y);

void UpdateSingleVelocityBoris(scalar& vel_z, scalar& vel_r, scalar& vel_y, scalar Ez,
                               scalar Er, scalar Bz, scalar Br, scalar dt, scalar q,
                               scalar m);

void UpdateVelocity(scalar vel_z[], scalar vel_r[], scalar vel_y[], const scalar Ez[],
                    const scalar Er[], const scalar Bz[], const scalar Br[],
                    const scalar dt, const scalar q, const scalar m, const size_t Ntot);

void UpdatePosition(scalar pos_z[], scalar pos_r[], scalar vel_z[], scalar vel_r[],
                    scalar vel_y[], const scalar dt, const size_t Ntot);

void ParticlePush(scalar pos_z[], scalar pos_r[], scalar vel_z[], scalar vel_r[],
                  scalar vel_y[], const scalar Ez[], const scalar Er[], const scalar Bz[],
                  const scalar Br[], const scalar dt, const scalar q, const scalar m,
                  const size_t Ntot);


#endif //PROBLEM_1_PUSHER_H
