//include some libraries
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

//define pi
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611
//define some codes
#define APOTHEM 0
#define SIDELEN 1
#define RADIUS 2

float area(float info, int code, float n);

int main(int argc, char* argv[]) {
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL){
        printf("Improper usage. Consult help or readme for more information.\n");
        return 1;
    }
    else {
        //information is stored in argv2, the # of sides is stored in argv3
        float info = atoi(argv[2]);
        float n = atoi(argv[3]);
        float a;
	    //if the 'apothem' flag is detected
        if (strcmp(argv[1], "-a") == 0) 
	        a = area(info, APOTHEM, n);
	    //if the 'sidelength' flag is detected
	    else if (strcmp(argv[1], "-s") == 0) 
	        a = area(info, SIDELEN, n);
	    //if the 'radius' flag is detected
	    else if (strcmp(argv[1], "-r") == 0)
	        a = area(info, RADIUS, n);
	    if (a != 0)
	        printf("The area of the regular polygon is %f\n", a);
	    else {
	        printf("An error occured.");
	        return 2;
	    }
	}
}

float area(float info, int code, float n) {

    //establish the right radian of the shape to work with
    float radian = PI / n;
    //do trig
    float tanr = tan(radian);
    float sinr = sin(radian);
    float cosr = cos(radian);
    //define the variable where area will be stored
    float a;
    //if the info given is the apothem
    if (code == APOTHEM) {
        float sidelen = 2 * info * tanr;
		a = sidelen * n * .5 * info;
    }
    //if the info given is the side length
    else if (code == SIDELEN) {
        float sidelen = info;
        float top = sidelen * sidelen * n;
        float bottom = 4 * tanr;
        a = top/bottom;
    }
    else if (code == RADIUS) {
        float radius = info;
        float sidelen = 2 * radius * sinr;
        float apothem = radius * cosr;
        a = .5 * sidelen * n * apothem;;
    }
    else
        a = 0;
    return a;
}
