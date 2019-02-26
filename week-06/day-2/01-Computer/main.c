#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer
{
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct
{
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer myPC = {4.7, 16, 64};
    Notebook myNotebook = {2.0, 8, 64};

    printf("My PC has a %.1fGHz processor, with %dGB RAM and a %d bit system\n",
           myPC.cpu_speed_GHz,
           myPC.ram_size_GB,
           myPC.bits);

    printf("My notebook has a %.1fGHz processor, with %dGB RAM and a %d bit system\n",
           myNotebook.cpu_speed_GHz,
           myNotebook.ram_size_GB,
           myNotebook.bits);
    return 0;
}