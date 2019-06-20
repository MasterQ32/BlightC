#include <acknex.h>
#include <default.c>

int a;
extern int b;
static int c;
extern static int e;

VECTOR dir;
bool any = false;
ENTITY * it;
int weapons_disabled = 0;
uisystem_t * pausemenu_ui;
uibutton_t * pausemenu_buttons[PAUSEMENU_BUTTONS];
char const * text;
ENTITY * const * * const foo;

function main();
function main(int argc,char ** argv);
export function main();
export function main(int argc,c2har ** argv);
export async function main();
export async function main(int argc,char ** argv);


function main(int argc,char ** argv)
{
    level_load("test.wmb");

    ENTITY * ent = ent_create(CUBE_MDL, vector(100, 0, 0), NULL);
    while(1)
    {
        // ent->pan += 2.0 * time_step;
        wait(1);
    }
}
