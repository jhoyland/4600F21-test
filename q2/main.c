/*

QUESTION 2:

	write a function which will calculate the sin or cos using the series expansion. The user of the function should be able to specify the the number of terms to calculate.
*/

// ***************  MARK:  9/10

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float Expansion(int type, double x, int n)
{
	int i,j, alt, f;
	double sin, cos;  //JAMES: Note that sin and cos are the math.h names for the sine and cosine functions
										// using those neames here means your local variables will mask the math.h functions
										// and so they cannot be called in this function
	//type 1 = sin, type 2 = cos
	//if type is sin then do series expansion with sin
	sin = x;
	//printf("%f\n\n", sin);
	cos = 1;
	alt = 0;
	if (type == 1)
	{
		for(i=1; i < n; i++)
		{
			f = i;
			//calculate factorial

			// JAMES: Good but remember you are recalculating the same thing
			// several times here. If you have calculated 6! you only need to multiply by 7 to get 7!
			for (j=(i-1); j > 1; j--)
			{
				f *= j;
			}
			printf("%d,%d \n\n", i,f);
			//alternate calls
			 if (alt == 0)
			 {
			 	sin += -(pow(x,i)/f);
			 	printf("sin = %f\n\n",sin);
			 	alt = 1;
			 	//printf("Altcheck = %d \n\n",alt);
			 }
			 else
			 {
			 	sin += (pow(x,i)/f);
			 	alt = 0;
			 	//printf("Altcheck = %d \n\n",alt);
			 }

		}

		return sin;
	}
	//else type 2 for cos (or mistype)
	else
	{
		for(i=1; i < n; i++)
		{
			//calculate factorial
			f = i;
			for (j=(i-1); j > 1; j--)
			{
				f *= j;
			}
			//alternate calls
			 if (alt == 0)
			 {
			 	cos += -(pow(x,i)/f);
			 	alt = 1;
			 	//printf("Altcheck = %d \n\n",alt);
			 }
			 else
			 {
			 	cos += (pow(x,i)/f);
			 	alt = 0;
			 	//printf("Altcheck = %d \n\n",alt);
			 }
		}

	return cos;
}
}

int main(int argc, char** argv)
{
	//check sin function
	float X;
	char type = 1;
	double x = 4;
	int n1 = 20;
	X = Expansion(type, x, n1);
	printf("Sin(%5.2f) by expansion of %i factors is %5.6f\n\n",x,n1,X);

	//check cos function
	float Y;
	char ty = 2;
	double y = 3.14;
	int n2 = 20;
	Y = Expansion(ty, y, n2);
	printf("Cos(%5.2f) by expansion of %d factors is %5.6f\n\n",y,n2,Y);

	// both generate incorrect values ):
	// checked that alternating variable is working
	// when I set to 20, alternating seems to be breaking off?
	// checked that factorial value value is correct (checked up to 5!)

	// JAMES: I can't immediately see why that would happen. You could be overflowing though,
	// The factorials get quite big at 20 and you may be losing precision.

  return 0;
}
