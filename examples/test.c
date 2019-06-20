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
        ent->pan += 2.0 * time_step;
        wait(1);
    }
}





char iniBuffer[2048];

void ini_write(STRING *filename, STRING *section, STRING *entry, STRING *value)
{
	WritePrivateProfileString(_chr(section), _chr(entry), _chr(value), _chr(filename));
}

void ini_write_int(STRING *filename, STRING *section, STRING *entry, int value)
{
	ini_write(filename, section, entry, str_for_int(NULL, value));
}

void ini_write_var(STRING *filename, STRING *section, STRING *entry, var value)
{
	ini_write(filename, section, entry, str_for_num(NULL, value));
}

void ini_write_float(STRING *filename, STRING *section, STRING *entry, float value)
{
	ini_write(filename, section, entry, str_for_float(NULL, value));
}

int ini_read_sections(TEXT *txt, STRING *filename)
{
	int length = GetPrivateProfileString(NULL, NULL, NULL, iniBuffer, 2047, _chr(filename));
	int i = 0;
	char *str = iniBuffer;
	while(str < (iniBuffer + length))
	{
		(txt->pstring)[i] = str_create(str);
		str = str + strlen(str) + 1;
		i++;
	}
	return i;
}

int ini_read(STRING *targetValue, STRING *filename, STRING *section, STRING *entry, STRING *defaultValue)
{
	int length = GetPrivateProfileString(_chr(section), _chr(entry), _chr(defaultValue), iniBuffer, 2047, _chr(filename));
	if(targetValue != NULL)
		str_cpy(targetValue, iniBuffer);
	return length;
}

int ini_read_int(STRING *filename, STRING *section, STRING *entry, int defaultValue)
{
	STRING *tmp = "#64";
	STRING *def = "#64";
	ini_read(tmp, filename, section, entry, str_for_int(def, defaultValue));
	return str_to_int(tmp);
}

var ini_read_var(STRING *filename, STRING *section, STRING *entry, var defaultValue)
{
	STRING *tmp = "#64";
	STRING *def = "#64";
	ini_read(tmp, filename, section, entry, str_for_num(def, defaultValue));
	return str_to_num(tmp);
}

float ini_read_float(STRING *filename, STRING *section, STRING *entry, float defaultValue)
{
	STRING *tmp = "#64";
	STRING *def = "#64";
	ini_read(tmp, filename, section, entry, str_for_float(def, defaultValue));
	return str_to_float(tmp);
}

