// device_functions.h
#include <stdio.h>

#pragma once

#include <cuda_runtime.h>

__device__ float x_pixels_frac = (float) 0.50;
__device__ float y_pixels_frac = (float) 0.50;
__device__ bool print_on = false;

// Function to print ray information
__device__ void printRayInfo(auto LP, int2 pixelID, auto ray, auto payload, const char* Tag){

// Define the pixel(s) to show the information out
int x_pixel = LP.frameSize.x*x_pixels_frac;
int y_pixel = LP.frameSize.y*y_pixels_frac;

// Check if pixelID matches the current x_pixel and y_pixel
if(pixelID.x == x_pixel && pixelID.y ==y_pixel && print_on){
	printf("\n### %-*s ",25, Tag);
	printf(" Pixel[%d, %d]", pixelID.x, pixelID.y);
	printf(" Origin(%f, %f, %f)"	,ray.origin.x, ray.origin.y, ray.origin.z);
	printf(" Direction(%f, %f, %f)",ray.direction.x, ray.direction.y, ray.direction.z);
	printf(" Raytime: %f", ray.time);
	printf(" tHit: %f", payload.tHit);
	printf("\n");
	}
}

// Function to print ray information and adicional parameter, overloaded fucntion
__device__ void printRayInfo(auto LP, int2 pixelID, auto ray, auto payload, const char* Tag, float parameter){

// Define the pixel(s) to show the information out
int x_pixel = LP.frameSize.x*x_pixels_frac;
int y_pixel = LP.frameSize.y*y_pixels_frac;

// Check if pixelID matches the current x_pixel and y_pixel
if(pixelID.x == x_pixel && pixelID.y ==y_pixel && print_on){
	printf("\n### %-*s ",25, Tag);
	printf(" Pixel[%d, %d]", pixelID.x, pixelID.y);
	printf(" Origin(%f, %f, %f)"	,ray.origin.x, ray.origin.y, ray.origin.z);
	printf(" Direction(%f, %f, %f)",ray.direction.x, ray.direction.y, ray.direction.z);
	printf(" Raytime: %f", ray.time);
	printf(" tHit: %f", payload.tHit);
	printf(" Value: %f", parameter);
	printf("\n");
	}
}

// Function to print ray information and adicional vector, overloaded fucntion
__device__ void printRayInfo(auto LP, int2 pixelID, auto ray, auto payload, const char* Tag, float3 vector){

// Define the pixel(s) to show the information out
int x_pixel = LP.frameSize.x*x_pixels_frac;
int y_pixel = LP.frameSize.y*y_pixels_frac;

// Check if pixelID matches the current x_pixel and y_pixel
if(pixelID.x == x_pixel && pixelID.y ==y_pixel && print_on){
	printf("\n### %-*s ",25, Tag);
	printf(" Pixel[%d, %d]", pixelID.x, pixelID.y);
	printf(" Origin(%f, %f, %f)"	,ray.origin.x, ray.origin.y, ray.origin.z);
	printf(" Direction(%f, %f, %f)",ray.direction.x, ray.direction.y, ray.direction.z);
	printf(" Raytime: %f", ray.time);
	printf(" tHit: %f", payload.tHit);
	printf(" Vector(%f,%f,%f)", vector.x, vector.y, vector.z);
	printf("\n");
	}
}

// Function to normalize a float3 vector

/*__device__ float3 normalize(float3 v) {
    float norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    float3 result = {v.x / norm, v.y / norm, v.z / norm};
    return result;
}*/

// Function to compute sines and cosecants for a given set of direction cosines
__device__ void computeSinesAndCosecants(float3 cosines, float3 *sines, float3 *cosecants) {
    sines->x = sqrt(1 - cosines.x * cosines.x);
    sines->y = sqrt(1 - cosines.y * cosines.y);
    sines->z = sqrt(1 - cosines.z * cosines.z);

    cosecants->x = 1 / sines->x;
    cosecants->y = 1 / sines->y;
    cosecants->z = 1 / sines->z;
}

// Function to compute the vectors (cos(a1+a2), cos(b1+b2), cos(c1+c2)) and (sin(a1+a2), sin(b1+b2), sin(c1+c2))
__device__ void computeVectorSum(float3 cos_alp_be_ga, float3 sin_alp_be_ga, float3 cos_HG, float3 sin_HG,
                      float3 *cos_alp_be_ga_1, float3 *sin_alp_be_ga_1) {
    cos_alp_be_ga_1->x = cos_alp_be_ga.x * cos_HG.x - sin_alp_be_ga.x * sin_HG.x;
    cos_alp_be_ga_1->y = cos_alp_be_ga.y * cos_HG.y - sin_alp_be_ga.y * sin_HG.y;
    cos_alp_be_ga_1->z = cos_alp_be_ga.z * cos_HG.z - sin_alp_be_ga.z * sin_HG.z;

    sin_alp_be_ga_1->x = sin_alp_be_ga.x * cos_HG.x + cos_alp_be_ga.x * sin_HG.x;
    sin_alp_be_ga_1->y = sin_alp_be_ga.y * cos_HG.y + cos_alp_be_ga.y * sin_HG.y;
    sin_alp_be_ga_1->z = sin_alp_be_ga.z * cos_HG.z + cos_alp_be_ga.z * sin_HG.z;
}

__device__ void computeDeviatedVectors(
    float3* w_alpha,
    float3* w_beta,
    float3* w_gamma,
    float3* w_i,
    float3 cos_alp_be_ga_1,
    float3 sin_alp_be_ga_1,
    float3 cos_alp_be_ga,
    float3 sin_alp_be_ga,
    float3 csc_alp_be_ga
    ){
        w_alpha->x=cos_alp_be_ga_1.x;
        w_alpha->y=sin_alp_be_ga_1.x*csc_alp_be_ga.x*cos_alp_be_ga.y;
        w_alpha->z=sin_alp_be_ga_1.x*csc_alp_be_ga.x*cos_alp_be_ga.z;

        w_beta->x=sin_alp_be_ga_1.y*csc_alp_be_ga.y*cos_alp_be_ga.x;
        w_beta->y=cos_alp_be_ga_1.y;
        w_beta->z=sin_alp_be_ga_1.y*csc_alp_be_ga.y*cos_alp_be_ga.z;

        w_gamma->x=sin_alp_be_ga_1.z*csc_alp_be_ga.z*cos_alp_be_ga.x;
        w_gamma->y=sin_alp_be_ga_1.z*csc_alp_be_ga.z*cos_alp_be_ga.y;
        w_gamma->z=cos_alp_be_ga_1.z;

        w_i->x=w_alpha->x + w_beta->x + w_gamma->x;
        w_i->y=w_alpha->y + w_beta->y + w_gamma->y;
        w_i->z=w_alpha->z + w_beta->z + w_gamma->z;

    }

__device__ float3 DeviatedVector(
    float3 w_o,
    float3 cos_HG,
    float *dot_w_o_w_i
    ){
        w_o = normalize(w_o);
        
        // Compute sines and cosecants for the angles got from Henyey GReenstein distribution
        float3 sin_HG, csc_HG;
        computeSinesAndCosecants(cos_HG, &sin_HG, &csc_HG);

        // Compute sines and cosecants
        float3 cos_alp_be_ga = w_o;
        float3 sin_alp_be_ga, csc_alp_be_ga;
        computeSinesAndCosecants(cos_alp_be_ga, &sin_alp_be_ga, &csc_alp_be_ga);

        // Compute the sum of vectors
        float3 cos_alp_be_ga_1, sin_alp_be_ga_1;
        computeVectorSum(cos_alp_be_ga, sin_alp_be_ga, cos_HG, sin_HG, &cos_alp_be_ga_1, &sin_alp_be_ga_1);
        
        float3 w_alpha={0,0,0};
        float3 w_beta={0,0,0};
        float3 w_gamma={0,0,0};
        float3 w_i;

        computeDeviatedVectors(
            &w_alpha,
            &w_beta,
            &w_gamma,
            &w_i,
            cos_alp_be_ga_1,
            sin_alp_be_ga_1,
            cos_alp_be_ga,
            sin_alp_be_ga,
            csc_alp_be_ga);

        w_i = normalize(w_i);
        *dot_w_o_w_i = w_i.x*w_o.x + w_i.y*w_o.y + w_i.z*w_o.z;
    return w_i;
    }
