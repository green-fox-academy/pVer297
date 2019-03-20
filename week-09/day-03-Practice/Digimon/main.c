#include <stdio.h>
#include "digimon.h"

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

#define MAX_DIGIMONS 100

int main()
{
    digimon_t digimon[MAX_DIGIMONS];
    generateTestArray(digimon, MAX_DIGIMONS);
    printData(digimon, MAX_DIGIMONS);

    int minHPIndex = getMinHealth(digimon, MAX_DIGIMONS);
    printf("%s's %s has the less health, %d\n",
           digimon[minHPIndex].tamer_name,
           digimon[minHPIndex].name,
           digimon[minHPIndex].health);

    puts("");
    printf("There is %d digimon with 'Mega' level\n", getLevelCount(digimon, MAX_DIGIMONS, MEGA));
    printf("John Doe has %d digimons\n", getDigimonCount(digimon, MAX_DIGIMONS, "John Doe"));
    printf("Joska Bacsi's digimons have %.2f average health\n", getAvgHealth(digimon, MAX_DIGIMONS, "Joska Bacsi"));
    return 0;
}
