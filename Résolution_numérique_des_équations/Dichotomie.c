#include<stdio.h>
#include<stdlib.h>
void Dichotomie(double a , double b, double eps , int itMax, double (*f)(double x))
{
	double M;
	int it=0;
	printf("it=%d [%14.12f  %14.12f] \n",it,a,b);
	while ( (b-a) > eps && it <= itMax)
	    {
	    	M =( a+b)/2;
	    	if( (*f)(a)*(*f)(M) < 0)
	    	  b=M;
	    	else if( (*f)(b)*(*f)(M) < 0)
	    	  a=M;
	    	else
			  {
			  	a=M;
			  	b=M;
		      }
		      it++;
		 printf("it=%d [%14.12f  %14.12f] \n",it,a,b);


	    }
	if( (b-a) <= eps)
	  {

	     printf("la solution de l'equation  a %14.12f pres est %14.12f \n",eps,(a+b)/2);
	     printf("le nombre d'iterations est %d \n",it);
      }
    else
	 printf("precision pas atteinte apres %d iterations\n",itMax);
}

