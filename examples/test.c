#include <acknex.h>
#include <default.c>

function main()
{
    level_load(NULL);

    ENTITY * ent = ent_create(CUBE_MDL, vector(100, 0, 0), NULL);
    while(1)
    {
        ent->pan += 2.0 * time_step;
        wait(1);
    }
}
