#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <random>
#include <vector>
#include <cstdio>
#include <gsl/gsl_rng.h>
//#include <ctime>


int main()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout  << "Collision test L' Ecueyer" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Chose Your Generator" << std::endl;
    std::cout << "1. Ran0" << std::endl;
    std::cout << "2. Ranlxs0" << std::endl;
    std::cout << "3. Mersenne Twister 19937" << std::endl;
    gsl_rng *r;
    int g;
    std::cin >> g;

    switch (g)
    {
        case 1:
            if ((r = gsl_rng_alloc(gsl_rng_ran0)) == NULL)
            {
                std::cout << "ERROR." << std::endl;
                exit(1);
            }
            else std::cout << "Selected generator ran0" << std::endl;
            break;
        case 2:
            if ((r = gsl_rng_alloc(gsl_rng_ranlxs0)) == NULL)
            {
                std::cout << "ERROR." << std::endl;
                exit(1);
            }
            else std::cout << "Selected generator ranlxs0" << std::endl;
            break;
        case 3:
            if ((r = gsl_rng_alloc(gsl_rng_mt19937)) == NULL)
            {
                std::cout << "ERROR." << std::endl;
                exit(1);
            }
            else std::cout << "Selected generator mt19937" << std::endl;
            break;
        case 4:
            if ((r = gsl_rng_alloc(gsl_rng_gfsr4)) == NULL)
            {
                std::cout << "ERROR." << std::endl;
                exit(1);
            }
            else std::cout << "Selected generator gfsr4" << std::endl;
            break;


        default:
            std::cout << "Choose another number" << std::endl;
            break;
    }

    r = gsl_rng_alloc(gsl_rng_ranlxs0);
	{

	    /*
        int w=12;
        int z=5;

    	std::cout << "------------------------------------------------" << std::endl;
		std::cout  << "Collision test L' Ecueyer" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		*/
		std::cout << "number of tests: " << std::endl;
		std::cin  >> w;
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Lenght of cube edge: " << std::endl;
        std::cin  >> z;


		unsigned long N=pow(2,w);        //Ilosc kolejnych powtorzen testu
		unsigned long d=2;     // Ilosc wymiarow kostki
		unsigned long l=0;       //Ilosc na ktora bedziemy dzielic nasza kostke
		unsigned long t=pow(2,z);    //Wielkosc boku dla każdego wymiaru

		//std::mt19937 generator(101);
        //std::uniform_real_distribution<double> dis(0.00, 1.00);




		std::cout << "N: " << N << std::endl;
		std::cout << "t: " << t << std::endl;



        l=pow(t,d);
       // std::cout << "l: " << l << std::endl;
       // double lambda =((N*N)/(2*l));

        //std::cout << "Lambda: " << lambda << std::endl;

        //std::cout << l << std::endl; <- kontrolne czy dziala - dziala

        //double long box_size = 1/l;      //dzielimy 1 na ilosc elementow kostki, to beda nasze sektory boxa

        unsigned long dane[N+1]={};

        for( int i = 0; i < N; i++ )
        {
        double U = gsl_rng_uniform(r);
        unsigned long box_number = (U*l);  // floor(U*l)
        box_number = (unsigned long)box_number;
        dane[i] = box_number ;
        }

        unsigned long sum=0;
        std::sort(dane, dane + N);

        for( int j = 0; j < N; j++ )
        {
        //std::cout << dane[j] << std::endl;
        if (dane[j]==dane[j+1]) sum++ ;
        }

    std::cout << "Suma: "<< sum << std::endl;
	system("pause");
	}
	return 0;
	}
