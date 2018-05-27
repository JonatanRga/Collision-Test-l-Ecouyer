#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <random>
#include <vector>
#include <cstdio>
#include <gsl/gsl_rng.h>
#define M_E        2.71828182845904523536
#include <fstream>

void hello()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout  << "Collision test L' Ecueyer" << std::endl;
    std::cout << "------------------------------------------------";

}

void automata()
{
    std::cout << std::endl << "Please choose your way of running program:          ||| Type 0 or exit to exit" << std::endl;
    std::cout << "1. Manual - select specific instructions what do you want to do." << std::endl;
    std::cout << "2. Semi-Automatic - set running parameters." << std::endl;
    std::cout << "3. Run Automatic!" << std::endl << std::endl;
}

void choose1()
{
        std::cout << std::endl <<  "Please choose random number generator:              ||| Type 0 or exit to exit" << std::endl;
        std::cout << "1. Ran0" << std::endl;
        std::cout << "2. Ranlxs0" << std::endl;
        std::cout << "3. Mersenne Twister 19937" << std::endl;
        std::cout << "4. Gfsr4" << std::endl;
        std::cout << "5. Minstd"  << std::endl;
        std::cout << std::endl;
}


int main()
{
    int check_state2=1;
   {
    do
	{
	    int stop = 10;
	    int sub = 4;
	    int w_1=15;

        int automat =1;
	    int g_2=1;
        int w=w_1-1;
        int z=w-sub;
        int g=1;
        int check_state=0;
        int check_state1=0;
        stop=w+stop;

        gsl_rng *r;

    	hello();
    	automata();
    	std::cin>> automat;
    	if (automat == 2)
            {
                std::cout << "------------------------------------------------";
                std::cout << std::endl << "Please set N:" << std::endl;
                std::cout << "start: " ;
                std::cin>> w_1;
                std::cout << "finish: ";
                std::cin>> stop;
                std::cout << "Please set diffrerence between N and t: ";
                std::cin>> sub;
                std::cout << "------------------------------------------------"<< std::endl;
                w=w_1-1;
                z=w-sub;
                check_state1=1;
            }
        else if (automat == 0) return 0;
        else if (automat == 1) check_state1=0;
        else
        {
            check_state1=1;
            std::cout << std::endl << "Going into automatic mode ... " << std::endl;
        }

          std::fstream log( "log.txt", std::ios::out );
            if( log.good() )
            {
                log << "Collision test L' Ecueyer " << std::endl<< std::endl;
                log << "Generator, " << "N, " << "t, " << "Colission, " << "Lambda, " << "Probability, " << std::endl;
                log.flush();
                check_state=1;

            }
            else
            {
                std::cout << "Could not create file log.txt! Please note: Log will not append in this raport!" << std::endl;
            }

        do
            {
        if(check_state1==0)
            {
                choose1();
                std::cin >> g ;
                std::cout << std::endl;
            }

        do
            {
        if (check_state1==1)
          {
            w++;
            z++;
        }

        switch (g)
        {

            case 1:
                if ((r = gsl_rng_alloc(gsl_rng_ran0)) == NULL)
                {
                    std::cout << "ERROR.";
                    exit(1);
                }
                else std::cout << "Selected generator ran0   ";
                break;
            case 2:
                if ((r = gsl_rng_alloc(gsl_rng_ranlxs0)) == NULL)
                {
                    std::cout << "ERROR.";
                    exit(1);
                }
                else std::cout << "Selected generator ranlxs0";
                break;
            case 3:
                if ((r = gsl_rng_alloc(gsl_rng_mt19937)) == NULL)
                {
                    std::cout << "ERROR.";
                    exit(1);
                }
                else std::cout << "Selected generator mt19937";
                break;
            case 4:
                if ((r = gsl_rng_alloc(gsl_rng_gfsr4)) == NULL)
                {
                    std::cout << "ERROR.";
                    exit(1);
                }
                else std::cout << "Selected generator gfsr4  ";
                break;
            case 5:
                if ((r = gsl_rng_alloc(gsl_rng_minstd)) == NULL)
                {
                    std::cout << "ERROR.";
                    exit(1);
                }
                else std::cout << "Selected generator minstd ";
                break;

                case 0:
                return 0;
            default:
                std::cout << "Choose another number" << std::endl << std::endl;

                break;


        }
        if (g>5)
        {
            std::cin >> g ;
            std::cout << std::endl;
        }


        } while (g>5);

        if (check_state1==0)
        {
        std::cout << std::endl << "------------------------------------------------" << std::endl;
		std::cout << "Exponent of Test Number:  ";
		std::cin  >> w;
        std::cout <<"Exponent of Lenght:  " ;
        std::cin  >> z;
        std::cout << "------------------------------------------------" << std::endl;
        }



		long long int N = pow(2,w);        //Ilosc kolejnych powtorzen testu
		int d = 2;     // Ilosc wymiarow kostki
		long long int l = 0;       //Ilosc na ktora bedziemy dzielic nasza kostke
		long long int t = pow(2,z);    //Wielkosc boku dla kazdego wymiaru
		long double U1=0.0;
		long double U2=0.0;
		long long int xcoord =0;
		long long int ycoord =0;
		long long int boxnumber =0;
		long double lambda =0;



        l=pow(t,d);


        if (check_state1==0)
        {
		std::cout << "N: " << N << std::endl;
		std::cout << "t: " << t << std::endl;
		std::cout << "d: " << d << std::endl;
        std::cout << "l: " << l << std::endl;
        }

        long long * dane = new long long[N];

        for( long long int i = 0; i < N; i++ )
        {
            U1 = gsl_rng_uniform(r);
            xcoord = floor(U1*t);

            U2 = gsl_rng_uniform(r);
            ycoord =floor(U2*t);

            boxnumber = xcoord +ycoord*t;
            dane[i]=boxnumber;
        }

        int sum=0;

        std::sort(dane, dane + N);

        for( unsigned long j = 0; j <N; j++ )
        {
        if (dane[j]==dane[j+1]) sum++ ;
        }

    lambda =((N*N)/(2*l));

    int k = sum;
    double exponent = std::pow(M_E, -(lambda));
    double poisson = exponent;
    double p_j1;
    double p_j = exponent;

    for(int j=0; j<k; j++)
    {
        p_j1 = (lambda/(j+1))*p_j;
        poisson += p_j1;
        p_j = p_j1;
    }

    if (check_state1==0)
    {
    std::cout << "Collision: "<< sum << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Poisson [lambda or expected value]:                                " << lambda << std::endl;
    std::cout << "Poisson [Probability that such collision number event will occur]: " << poisson<< std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    }
    else
        {
            std::cout <<", N: "<<w<<", t: "<<z<< ", Colission: "<< sum <<", Probability: "<< poisson <<std::endl;
        }

    if (check_state==1)
    {
        // log << "Generator, " << "N, " << "t, " << "Colission " << "Lambda, " << "Probability, " << std::endl;
        log << g <<", "<< w <<", "<< z<<", "<<sum<<", "<< lambda <<", " << poisson<<", "<<std::endl;
        log.flush();
    }
    if (w>(stop-1) && check_state1==1)
    {
        w=w_1-1;
        z=w_1-sub-1;
        g++;
        g_2++;
    }


    } while (g_2<6);

    if (check_state==1)
    {
        log.close();
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Please check generated log.txt file!"<< std::endl << "Please note if You repeat procedure, stored data in the log file will be replaced!"<< std::endl;
        std::cout << "Enter 0 or exit, to exit the program. " << std::endl ;
        std::cout << "Enter 1 or other number, to repeat procedure"<< std::endl << std::endl ;
        std::cin>> check_state2 ;
        std::cout << std::endl;
    }
    } while (check_state2>0);

	system("pause");
	}
	return 0;
	}
