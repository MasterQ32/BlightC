
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

structname val =
{
    .x = 10,
    .y = 10
};

void test_for()
{
    for(i; i; i)
        ;
}

enum EnemyType
{
    A = 1,
    B = 2,
    C,
    D
};

export function main(int argc,char ** argv)
{
    level_load("test.wmb");

    ENTITY * ent = ent_create(CUBE_MDL, vector(100, 0, 0), NULL);
    while(1)
    {
        ent->pan += 2.0 * time_step;
        wait(1);
    }
}

struct foo {
    int celltype;
    float vegetation;
    float elevation;
    float zettiness;
    float streetyness;
};

typedef struct
{
	int celltype;
	float vegetation;
	float elevation;
    float zettiness;
    float streetyness;
} maploader_cell;

struct maploader_t
{
	int w, h;
	maploader_cell * cells;
	ENTITY * terrain;
};

struct maploader_t maploader;

BMAP * maploader_terrain_digital = "terrain_digital.png";
BMAP * maploader_terrain_analogue = "terrain_analogue.png";
BMAP * maploader_terrain_splatter = "terrain_splatter.png";
BMAP * maploader_terrain_street_digital = "terrain_street.png";
BMAP * maploader_terrain_street_analogue = "terrain_street2.png";
BMAP * maploader_terrain_digital_fancy = "terrain_street3.png";
BMAP * maploader_terrain_digital_wall = "terrain_street5.png";
BMAP * maploader_lava = "lava.png";

MATERIAL * maploader_terrain_material =
{
    .effect = "terrain.fx",
    .flags = PASS_SOLID | AUTORELOAD,
};

MATERIAL * maploader_water_material =
{
    .effect = "water.fx",
    .flags = PASS_SOLID | AUTORELOAD,
};

void maploader_pos_to_vec(VECTOR * v, int x, int y)
{
    int size_x = maploader_cellsize * maploader.w + maploader_cellsize - 1;
    int size_y = maploader_cellsize * maploader.h + maploader_cellsize - 1;

    v->x = x * (maploader_trisize * maploader_cellsize) - maploader_trisize * size_x / 2;
    v->y = y * (maploader_trisize * maploader_cellsize) - maploader_trisize * size_y / 2;
    v->z = maploader_tile_height(x, y);
}

void maploader_pos_for_vec(VECTOR *v, int *x, int *y)
{
    int size_x = maploader_cellsize * maploader.w + maploader_cellsize - 1;
    int size_y = maploader_cellsize * maploader.h + maploader_cellsize - 1;

    *x = (v->x + maploader_trisize * size_x / 2) / (maploader_trisize * maploader_cellsize);
    *y = (v->y + maploader_trisize * size_y / 2) / (maploader_trisize * maploader_cellsize);

    if(*x <= 0) *x = 0;
    if(*y <= 0) *y = 0;
    if(*x >= maploader.w) *x = maploader.w - 1;
    if(*y >= maploader.h) *y = maploader.h - 1;
}

void maploader_init()
{
    maploader.cells = NULL;
    bmap_to_mipmap(maploader_terrain_digital);
    bmap_to_mipmap(maploader_terrain_analogue);
    bmap_to_mipmap(maploader_terrain_splatter);
    bmap_to_mipmap(maploader_terrain_street_digital);
    bmap_to_mipmap(maploader_terrain_street_analogue);
    bmap_to_mipmap(maploader_terrain_digital_fancy);
    bmap_to_mipmap(maploader_terrain_digital_wall);
    bmap_to_mipmap(maploader_lava);
}

int maploader_grey_to_type(int gray)
{
	if(gray < 0x10)
		return MAPLOADER_TILE_BARRIER;
	if(gray < 0x30)
		return MAPLOADER_TILE_STREET;
	else if(gray <= 0x60)
		return MAPLOADER_TILE_WATER;
	else if(gray <= 0xA0)
		return MAPLOADER_TILE_LAVA;
	else if(gray <= 0xE0)
		return MAPLOADER_TILE_HOLE;
	else
		return MAPLOADER_TILE_DEFAULT;
}

void maploader_load(char const * fileName)
{
	if(maploader.cells) {
		sys_free(maploader.cells);
	}
	BMAP * bmp = bmap_create(fileName);
	if(bmp == NULL)
		error("failed to load level");
    bmap_to_mipmap(bmp);
	var format = bmap_lock(bmp, 0);

	maploader.w = bmap_width(bmp);
	maploader.h = bmap_height(bmp);
	maploader.cells = sys_malloc(sizeof(maploader_cell) * maploader.w * maploader.h);

	int x, y;
	for(x = 0; x < maploader.x; x++)
	{
        for(y = 0; y < maploader.h; y++)
        {
			var pixel = pixel_for_bmap(bmp, x, y);

			COLOR col;
			var alpha;
			pixel_to_vec(&col, &alpha, format, pixel);

            int type;
            if(col.blue >= 250)
                type = MAPLOADER_TILE_BARRIER;
            else
                type = MAPLOADER_TILE_DEFAULT;

			((maploader.cells)[maploader.w * y + x]).celltype = type;
			((maploader.cells)[maploader.w * y + x]).vegetation = col.green / 255.0;
            ((maploader.cells)[maploader.w * y + x]).elevation = col.blue * 3;
            ((maploader.cells)[maploader.w * y + x]).zettiness = 1.0 - alpha / 100.0;
            ((maploader.cells)[maploader.w * y + x]).streetyness = col.red / 255.0;
		}
	}

	bmap_unlock(bmp);
	// bmap_remove(bmp);

	int size_x = maploader_cellsize * maploader.w + maploader_cellsize - 1;
	int size_y = maploader_cellsize * maploader.h + maploader_cellsize - 1;

    collision_mode = 0;

    you = ent_createterrain(
        maploader_lava,
        vector(0, 0, 200),
        180,
        180,
        256
    );
    you.material = maploader_water_material;

    maploader.terrain = ent_createterrain(
        bmp,
        vector(0, 0, 0),
        size_x,
        size_y,
        maploader_trisize
    );

    int meshcnt = ent_status(maploader.terrain, 16);

     int iMesh;
    for(iMesh = 0; iMesh < meshcnt; iMesh++)
    {
        LPD3DXMESH mesh = ent_getmesh(maploader.terrain, iMesh, 0);

        D3DVERTEX * vertices;
        mesh->LockVertexBuffer(0, &vertices);

        int i;
        int cnt = mesh->GetNumVertices();
        for(i = 0; i < cnt; i++)
        {
            // CONTACT c;
            // ent_getvertex(maploader.terrain, &c, i);

            D3DVERTEX * v = &vertices[i];

            maploader_pos_for_vec(vector(v->x, v->z, 0), &x, &y);

            if(x <= 0) x = 0;
            if(y <= 0) y = 0;
            if(x >= maploader.w) x = maploader.w - 1;
            if(y >= maploader.h) y = maploader.h - 1;

            v->y = maploader_tile_height(x, y);
            int neighborX = minv(x + 1, maploader.w-1);
            int neighborY = minv(y + 1, maploader.h-1);
            var neighborXValue = maploader_tile_height(neighborX, y);
            var neighborYValue = maploader_tile_height(x, neighborY);

            VECTOR normalVector;
            normalVector.x = (neighborX - v->y)/255;
            normalVector.y = 1.0;
            normalVector.z = (neighborY - v->y)/255;
            vec_normalize(normalVector, 1.0);

            v->u1 = 154.0 * (float)x / (float)maploader.w / 256.0;
            v->v1 = 190.0 * (float)y / (float)maploader.h / 256.0;

            v->nx = (float)normalVector.x;
            v->ny = (float)normalVector.y;
            v->nz = (float)normalVector.z;

            // ent_setvertex(maploader.terrain, &c, i);
        }
        mesh->UnlockVertexBuffer();
    }

    set(maploader.terrain, PASSABLE);

    maploader.terrain.material = maploader_terrain_material;

    random_seed(1337);
    for(x = 0; x < maploader.w; x++)
    {
        for(y = 0; y < maploader.h; y++)
        {
            int type = maploader_tile_type(x, y);
            float v = maploader_tile_vegetation(x, y);
            float s = maploader_tile_streetyness(x, y);
            if(type != MAPLOADER_TILE_DEFAULT)
                continue;
            VECTOR pos;
            maploader_pos_to_vec(pos, x, y);

            pos.x += (maploader_cellsize * maploader_trisize) * (random(1) - 0.5);
            pos.y += (maploader_cellsize * maploader_trisize) * (random(1) - 0.5);

            if(v < 0.1 && s < 0.2 && random(100) < 3)
            {
                you = ent_create("kabel4.mdl", pos, NULL);
                you->pan = random(360);
            }
            else if(v < 0.1 && s < 0.1 && random(100) < 0.5)
            {
                you = ent_create("KisteA.mdl", pos, NULL);
                you->pan = random(360);
            }

            if(random(100) > 50)
            {
                if(v > 0.2)
                {
                    if(random(100) < pow(v, 6.0) * 30) {
                        char const * boom = "tree01.mdl";
                        var r = random(1);
                        if(r > 0.66)
                            boom = "tree02.mdl";
                        else if(r > 0.33)
                            boom = "tree03.mdl";

                        you = ent_create(boom, pos, NULL);
                        reset(you, SHADOW);
                        you->material = matTrees;
                        you->red = 100;
                        you->green = 100;
                        you->blue = 100;
                        you->pan = random(360);
                        you->tilt = random(30) - 15;
                        // you->emask &= ~DYNAMIC;
                    }
                }
            }
        }
    }
    maploader.terrain.clipfactor = 2;

    int i; for(i = -15; i <= 15; i++)
    {
        you = ent_create(
            "StrasseGerade.mdl",
            vector(580 * i, 0, 0),
            NULL
        );
        you.z = maploader_get_height(you.x);
    }

    collision_mode = 1;

    for(x = 0; x < maploader.w; x++)
    {
        for(y = 0; y < maploader.h; y++)
        {
            int type = maploader_tile_type(x, y);
            if(type != MAPLOADER_TILE_DEFAULT)
                continue;
            VECTOR pos;
            maploader_pos_to_vec(pos, x, y);

            if(random(100) > 50)
            {
                float z = maploader_tile_zettiness(x, y);

                if(random(100) < 100 * z)
                {
                   z_spawn(pos);
                }
            }
        }
    }
}

bool maploader_has_map()
{
	return (maploader.cells != NULL);
}

int maploader_size_x()
{
	return maploader.w;
}

int maploader_size_y()
{
	return maploader.h;
}

int maploader_tile_type(int x, int y)
{
	return ((maploader.cells)[maploader.w * y + x]).celltype;
}

float maploader_tile_vegetation(int x, int y)
{
	return ((maploader.cells)[maploader.w * y + x]).vegetation;
}

float maploader_tile_height(int x, int y)
{
	return ((maploader.cells)[maploader.w * y + x]).elevation;
}

float maploader_tile_zettiness(int x, int y)
{
    return ((maploader.cells)[maploader.w * y + x]).zettiness;
}

float maploader_tile_streetyness(int x, int y)
{
    return ((maploader.cells)[maploader.w * y + x]).streetyness;
}

int   maploader_get_type(VECTOR * v)
{
	int x, y;
	maploader_pos_for_vec(v, &x, &y);
	return maploader_tile_type(x, y);
}

float maploader_get_vegetation(VECTOR * v)
{
	int x, y;
	maploader_pos_for_vec(v, &x, &y);
	return maploader_tile_vegetation(x, y);
}

float maploader_get_height(VECTOR * v)
{
	int x, y;
	maploader_pos_for_vec(v, &x, &y);
	return maploader_tile_height(x, y);
}


var maploader_dist2d(VECTOR * _a, VECTOR * _b)
{
    VECTOR a,b;
    vec_set(a, _a);
    vec_set(b, _b);
    a.z = 0;
    b.z = 0;
    return vec_dist(a, b);
}

var maploader_lerp(var a, var b, float f)
{
    return (1.0 - f) * a + f * b;
}

VECTOR * maploader_trace(VECTOR *_start, VECTOR *_end)
{
    VECTOR start, end;
    vec_set(start, _start);
    vec_set(end, _end);

    VECTOR iter;
    vec_set(iter, start);

    var total = maploader_dist2d(start, end);

    while(maploader_dist2d(iter, end) > maploader_trisize)
    {
        var a = maploader_dist2d(iter, end) / total;
        iter.z = maploader_lerp(end.z, start.z, a);
        if(iter.z < maploader_get_height(iter))
            return vector(iter.x, iter.y+1, iter.z);

        VECTOR dir;
        vec_diff(dir, end, start);
        dir.z = 0;
        vec_normalize(dir, maploader_trisize);

        vec_add(iter, dir);
    }
    if(iter.z < maploader_get_height(iter))
        return vector(iter.x, iter.y+1, iter.z);

    return NULL;
}




int *grid_state;
int grid_xSize;
int grid_ySize;

void grid_init()
{
	grid_state = NULL;
}

void grid_open(int xSize, int ySize)
{
	grid_state = sys_malloc(sizeof(int)*xSize*ySize);
	grid_xSize = xSize;
	grid_ySize = ySize;

	int i;
	int on = 0;
	for(i = 0; i<xSize*ySize; ++i)
	{
		on = 1-on;
		grid_state[i] = on;

//		ent_create("cube.mdl", grid_getCellCenter_byID(i), NULL);
	}

}

void grid_close()
{
	sys_free(grid_state);
	grid_state = NULL;
}

int grid_CoordToID(int x, int y)
{
	return x + y*grid_xSize;
}

int grid_idx2X(int idx)
{
	return idx % grid_xSize;
}
int grid_idx2Y(int idx)
{
	return (int)(idx / grid_ySize);
}

void grid_errorcheck(int id)
{
	if(id < 0 || id > grid_xSize * grid_ySize)
		error("ID out of bounds beim Zugriff auf die Grid");
}


void grid_setState(int x, int y, int state)
{
	grid_setState_byID(grid_CoordToID(x,y), state);
}

void grid_resetState(int x, int y, int state)
{
	grid_resetState_byID(grid_CoordToID(x,y), state);
}

void grid_getState(int x, int y)
{
	return grid_getState_byID(grid_CoordToID(x,y));
}


void grid_setState_byID(int id, int state)
{
	grid_errorcheck(id);
	grid_state[id] |= state;

}

void grid_resetState_byID(int id, int state)
{
	grid_errorcheck(id);
	grid_state[id] &= ~state;
}

int grid_getState_byID(int id)
{
	grid_errorcheck(id);
	return grid_state[id];
}


int grid_getCellID_byPos(VECTOR pos)
{
	int x = (pos.x + GRID_CELLSIZE*grid_xSize/2) / GRID_CELLSIZE;
	int y = (pos.y + GRID_CELLSIZE*grid_ySize/2) / GRID_CELLSIZE;

	return grid_CoordToID(x,y);
}

VECTOR *grid_getCellCenter(int x, int y)
{
	grid_errorcheck(grid_CoordToID(x,y));
	x -= grid_xSize/2;
	y -= grid_ySize/2;
	return vector((x+0.5)*GRID_CELLSIZE, (y+0.5)*GRID_CELLSIZE, 400);
}

VECTOR *grid_getCellCenter_byID(int ID)
{
	return grid_getCellCenter(grid_idx2X(ID), grid_idx2Y(ID));
}



struct effects2d_animation
{
    BMAP * frames[10];
    int frame_count;
    var speed;
    var size;
};

struct effects2d_particle
{
    VECTOR pos;
    int animation;
    var frame;
};

struct effects2d_t
{
    struct effects2d_animation animations[3];

    struct effects2d_particle particles[50];
};

struct effects2d_t effects2d;

void effects2d_init()
{
    // GOTO
    effects2d.animations[0].frame_count = 5;
    effects2d.animations[0].speed = 1;
    effects2d.animations[0].size = 0.5;
    effects2d.animations[0].frames[0] = bmap_create("Cursor1.png");
    effects2d.animations[0].frames[1] = bmap_create("Cursor2.png");
    effects2d.animations[0].frames[2] = bmap_create("Cursor3.png");
    effects2d.animations[0].frames[3] = bmap_create("Cursor4.png");
    effects2d.animations[0].frames[4] = bmap_create("Cursor5.png");

    // ATTACK
    effects2d.animations[1].frame_count = 4;
    effects2d.animations[1].speed = 0.75;
    effects2d.animations[1].size = 0.5;
    effects2d.animations[1].frames[0] = bmap_create("Attack_C.png");
    effects2d.animations[1].frames[1] = bmap_create("Attack_C1.png");
    effects2d.animations[1].frames[2] = bmap_create("Attack_C2.png");
    effects2d.animations[1].frames[3] = bmap_create("Attack_C3.png");

    // MINE
    effects2d.animations[2].frame_count = 4;
    effects2d.animations[2].speed = 1.0;
    effects2d.animations[2].size = 0.5;
    effects2d.animations[2].frames[0] = bmap_create("De_Build1.png");
    effects2d.animations[2].frames[1] = bmap_create("De_Build2.png");
    effects2d.animations[2].frames[2] = bmap_create("De_Build3.png");
    effects2d.animations[2].frames[3] = bmap_create("De_Build4.png");
}

void effects2d_open()
{
    int i; for(i = 0; i < EFFECTS2D_PARTICLE_COUNT; i++)
        effects2d.particles[i].animation = 0;
}

void effects2d_update()
{
    int i; for(i = 0; i < EFFECTS2D_PARTICLE_COUNT; i++)
    {
        struct effects2d_particle * p = &effects2d.particles[i];
        if(p->animation == 0)
            continue;

        struct effects2d_animation * a = &effects2d.animations[p->animation - 1];

        if(p->frame >= a->frame_count) {
            p->animation = 0;
            continue;
        }

        BMAP * tex = a->frames[(int)p->frame];

        int w = bmap_width(tex);
        int h = bmap_height(tex);

        VECTOR pos;
        vec_set(pos, &p->pos);
        if(vec_to_screen(pos, camera))
        {
            draw_quad(
                tex,
                vector(pos.x - a->size * w/2, pos.y - a->size * h/2, 0),
                NULL,
                vector(w, h, 0),
                vector(a->size, a->size, 0),
                NULL,
                80,
                0
            );
        }

        p->frame += a->speed * time_step;
    }
}

void effects2d_close()
{

}

void effects2d_spawn(VECTOR * worldpos, int type)
{
    int i; for(i = 0; i < EFFECTS2D_PARTICLE_COUNT; i++)
    {
        if(effects2d.particles[i].animation != 0)
            continue;

        effects2d.particles[i].animation = type;
        effects2d.particles[i].frame = 0;
        // effects2d.particles[i].x = x;
        vec_set(&effects2d.particles[i].pos, worldpos);
        break;
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



void game_init(void)
{
	ui_game_init();
    UnitMangement_init();
    grid_init();
	buildingPlacement_init();
	presetsInit();
    effects2d_init();
	ai_init(1); // parameter = difficulty

    effect_load(mtl_model, "units.fx");
}

void game_open(void)
{
//	#ifdef GAME_OPEN_DEBUG
		cprintf1("\n game_open: START at frame %d, calling framework_load_level() now...", (int)total_frames);
//	#endif
	framework_load_level(NULL);

    sun_light = 100;

//	#ifdef GAME_OPEN_DEBUG
		cprintf0("\n - calling jpsMapLoadFromFile() now...");
//	#endif
	int loadResult = (jpsMapLoadFromFile("map0.txt") != NULL);
//	#ifdef GAME_OPEN_DEBUG
		cprintf1(" result: %d", loadResult);
		cprintf0("\n - calling maploader_load() now...");
//	#endif
	maploader_load("the-core.png");

//	#ifdef GAME_OPEN_DEBUG
		cprintf0("\n - calling ui_game_open() now...");
//	#endif
	ui_game_open();
	topdown_camera_open();

    UnitMangement_open();
    fow_open();

    //SetupPostprocessing();

	SPUTNIK_Init();
	SPAWNER_Init();
	Z_Init();
	stub_init(); //hook debug shit here

	grid_open(50,50);
	buildingPlacement_open();
//	#ifdef GAME_OPEN_DEBUG
		cprintf1("\n game_open: END at frame %d", (int)total_frames);
//	#endif

    effects2d_open();

    music_start("media/ingame.mp3", 2.0, 1);
}

void game_update(void)
{
    //updateRenderTargetsIfNeeded();
    topdown_camera_update();
    ui_game_update();
    ai_update();
	jpsGameUpdate(mapGetCurrent());
	SPUTNIK_Update();
	SPAWNER_Update();
	Z_Update();
	stub_update(); //hook debug shit here
    UnitMangement_update();
    fow_update();
	buildingPlacement_update();

    effects2d_update();
}

void game_close(void)
{
	ui_game_close();
	grid_close();
    effects2d_close();
    fow_close();
    framework_load_level(NULL);
}

bool game_is_done(void)
{
	return key_esc;
}

SOUND* sputnik_snd_death   = "sputnik_death.wav";
SOUND* sputnik_snd_attack1 = "sputnik_attack1.wav";
SOUND* sputnik_snd_attack2 = "sputnik_attack2.wav";
SOUND* sputnik_snd_attack3 = "sputnik_attack3.wav";


void Sputnik()
{
	framework_setup(my, SUBSYSTEM_UNIT_SPUTNIK);
	my->SPUTNIK_RUNSPEED = 30;
	my->SPUTNIK_TURNSPEED = 50;
	my->SPUTNIK_ATTACKSPEED = 5;
	my->SPUTNIK_ATTACKRANGE = 200;
	my->SPUTNIK_ANIMSTATEATK = 0;
	my->SPUTNIK_IDLECOUNTER = 0;
	my->HEALTH = 23;
	my->MAXHEALTH = my->HEALTH;
    reset(my, SHADOW);
	c_setminmax(me);
	my->min_z += SPUTNIK_FEET;
	my->ENTITY_STATE = ENTITY_STATE_WAIT_OR_WALK;
	my->ENTITY_DAMAGE = 5;
}

void SPUTNIK_Init()
{
}


void SPUTNIK__wait_or_walk(ENTITY * ptr)
{
	UNIT* unit = jpsAllowMovementForEntity(ptr, true);
	if(!unit) return;

	vec_set(ptr->x, unit->pos3d);
	VECTOR diff, temp;
	vec_diff(diff, unit->pos3d, unit->prevPos3d);

	var len = vec_to_angle(temp, diff)/time_step;

	if(len > 8) ptr->SPUTNIK_RUNCOUNTER = 4;
	//if(unit->isMoving) ptr->SPUTNIK_RUNCOUNTER = 12;

	if(ptr->SPUTNIK_RUNCOUNTER > 0)
	{
		ptr->SPUTNIK_RUNCOUNTER = maxv(ptr->SPUTNIK_RUNCOUNTER-time_step,0);
		if(len > 8) ptr->pan += ang(temp.x-ptr->pan)*0.5*time_step;

		ptr->SPUTNIK_DIDATTACK = 0;
		ptr->SPUTNIK_ANIMSTATEATK = 0;
		ptr->SPUTNIK_ANIMSTATE += len*0.425*time_step;//0.5 * ptr->SPUTNIK_RUNSPEED * time_step;
		ent_animate(ptr, SPUTNIK_WALKANIM, ptr->SPUTNIK_ANIMSTATE, ANM_CYCLE);

		ptr->SPUTNIK_IDLECOUNTER = 0;
	}
	else
	{
		ptr->SPUTNIK_IDLECOUNTER += time_step;
		ptr->SPUTNIK_ANIMSTATE += 7 * time_step;
		ent_animate(ptr, SPUTNIK_WAITANIM, ptr->SPUTNIK_ANIMSTATE, ANM_CYCLE);
	}

	//sputnik was hit
	if (ptr->DAMAGE_HIT > 0)
	{
		if (ptr->ENTITY_STATE != ENTITY_STATE_HIT)
		{
			ptr->HEALTH = maxv(0, ptr->HEALTH - ptr->DAMAGE_HIT);
			ptr->ENTITY_STATE = ENTITY_STATE_HIT;
			ptr->ENTITY_HITTHRESHOLD = 5;
		}
		ptr->DAMAGE_HIT = 0;
	}
	else
	{
		//selected victim is near - attack
		if (SCAN_IsEntityNear(ptr, unit_getVictim(ptr), ptr->SPUTNIK_ATTACKRANGE))
		{
			ptr->ENTITY_STATE = ENTITY_STATE_ATTACK;
		}
		//nothing to do? go mining
		if(ptr->SPUTNIK_IDLECOUNTER > SPUTNIK_MAXIDLE && !unit_getVictim(ptr))
		{
			unit_findNextVictim(ptr, UNIT_Z);
		}

		//victim is selected but is not alive anymore --> pick new one
		if (unit_getVictim(ptr) == NULL && ptr->ENTITY_VICTIMTYPE != UNIT_INVALID)
		{
			if (!unit_findNextVictim(ptr))
			{
				//nothing in range
				ptr->ENTITY_VICTIMTYPE = UNIT_INVALID;
			}
		}

	}
}


void SPUTNIK_Update()
{
	ENTITY * ptr;
	for(ptr = ent_next(NULL); ptr != NULL; ptr = ent_next(ptr)) if(ptr.skill99 == SUBSYSTEM_UNIT_SPUTNIK)
	{
		if(ptr->ENTITY_STATE != ENTITY_STATE_WAIT_OR_WALK)
			ptr->SPUTNIK_IDLECOUNTER = 0;

		jpsAllowMovementForEntity(ptr, false);

		switch(ptr->ENTITY_STATE)
		{
			case ENTITY_STATE_WAIT_OR_WALK:
			{
				SPUTNIK__wait_or_walk(ptr);
				break;
			}

			case ENTITY_STATE_ATTACK:
			{
				SPUTNIK__attack(ptr);
				break;
			}

			case ENTITY_STATE_DIE:
			{
				SPUTNIK__die(ptr);
				break;
			}

			case ENTITY_STATE_HIT:
			{
				SPUTNIK__hit(ptr);
				break;
			}

			default:
			{
				break;
			}
		}

		if (ptr->ENTITY_STATE != ENTITY_STATE_DIE && ptr->ENTITY_STATE != ENTITY_STATE_DEAD)
		{
			UNIT* unit = jpsUnitGetFromEntity(ptr);
			if(unit)
			{
				TILE* tile = unit->tile;
				if(tile)
				{
                    if(!tile->value) ptr->z = maploader_get_height(ptr->x) - ptr->min_z - SPUTNIK_FEET;
				}
			}
		}
	}
}

void SPUTNIK__hit(ENTITY* ptr)
{
	ptr->ENTITY_HITTHRESHOLD -= time_step;
	if (ptr->HEALTH <= 0)
	{
		ptr->ENTITY_STATE = ENTITY_STATE_DIE;
		ptr->SPUTNIK_ANIMSTATE = 0;
		snd_play(sputnik_snd_death, 100, 0);
		set(ptr, PASSABLE);
		unit_deactivate(ptr);
	}
	else if (ptr->ENTITY_HITTHRESHOLD <= 0)
	{
		ptr->ENTITY_STATE = ENTITY_STATE_WAIT_OR_WALK;
	}
	else
	{
		var percent = (1 - (ptr->ENTITY_HITTHRESHOLD/5)) * 56;
		if (percent > 28)
		percent = 56-percent;
		ent_animate(ptr, SPUTNIK_ATTACKANIM, percent, 0);
	}
}

void SPUTNIK__attack(ENTITY* ptr)
{
	ANG_turnToPos(ptr, unit_getTarget(ptr), ptr->SPUTNIK_TURNSPEED, 5);
	if (ptr->SPUTNIK_ANIMSTATEATK == 0)
	{
		if (num_sounds < 6)
		{
			switch(integer(random(2)))
			{
				case 0: snd_play(sputnik_snd_attack1, 30+random(10), 0); break;
				case 1: snd_play(sputnik_snd_attack2, 30+random(10), 0); break;
				case 2: snd_play(sputnik_snd_attack3, 30+random(10), 0); break;
			}
		}
	}
	ptr->SPUTNIK_ANIMSTATEATK += ptr->SPUTNIK_ATTACKSPEED * time_step;
	ptr->SPUTNIK_ANIMSTATEATK = minv(ptr->SPUTNIK_ANIMSTATEATK, 100);
	ptr->SPUTNIK_ANIMSTATE = 0;
	ent_animate(ptr, SPUTNIK_ATTACKANIM, ptr->SPUTNIK_ANIMSTATEATK, 0);

	if (ptr->SPUTNIK_ANIMSTATEATK > 50)
	{
		if (ptr->SPUTNIK_DIDATTACK == 0)
		{
			ENTITY* victim = unit_getVictim(ptr);
			if (SCAN_IsEntityNear(ptr, victim, ptr->SPUTNIK_ATTACKRANGE))
			{
				//DEBUG
				if (victim == ptr) error ("attacking myself :O");
				unit_setDamage(victim, ptr);
			}
		}
		ptr->SPUTNIK_DIDATTACK = 1;
	}
	else
	{
		ptr->SPUTNIK_DIDATTACK = 0;
	}

	if (ptr->SPUTNIK_ANIMSTATEATK >= 100)
	{
		//unit_findNextVictim(ptr);
		ptr->SPUTNIK_ANIMSTATEATK = 0;
		ptr->ENTITY_STATE = ENTITY_STATE_WAIT_OR_WALK;
	}

}

void SPUTNIK__die(ENTITY* ptr)
{
	ptr->SPUTNIK_ANIMSTATE += 5 * time_step;
	ent_animate(ptr, SPUTNIK_DIEANIM, ptr->SPUTNIK_ANIMSTATE, 0);
	if(ptr->SPUTNIK_ANIMSTATE >= 90)
	{
		ptr->ENTITY_STATE = ENTITY_STATE_DEAD;
	}
}



void ui_spawn_event_sputnik(var num, PANEL *panel)
{
	ENTITY *ent = panel->skill_y;
	if (!ent) { return; } // NOOOO
	spawner_produce(ent);
	ent->SELCTED_SKILL = 1;
}

void ui_destroy_event_sputnik(var num, PANEL *panel)
{
	ENTITY *ent= panel->skill_y;
	if (!ent) { return; } // NOOOO
	ent->HEALTH = 0;
	ent->ENTITY_STATE = 4;
}

void ui_place_building(var num, PANEL *panel)
{
	buildingPlacement_beginConstruction(num - 2);
}

void ui_show_commando_groups()
{
	ui_command_group_status = !ui_command_group_status;
}

void ui_rescale_radial(PANEL *rad)
{
	PANEL *icon = ptr_for_handle(rad->skill_x);
	rad->scale_x = 1;
	rad->scale_y = 1;
	rad->size_x = bmap_width(ui_radial_n);
	rad->size_y = bmap_height(ui_radial_n);
	rad->scale_x = scale_factor_x;
	rad->scale_y = scale_factor_x;
	icon->scale_x = scale_factor_x;
	icon->scale_y = scale_factor_x;
}

void ui_scale_radial(PANEL *rad, var scale)
{
	PANEL *icon = ptr_for_handle(rad->skill_x);
	rad->size_x = bmap_width(ui_radial_n);
	rad->size_y = bmap_height(ui_radial_n);
	rad->scale_x = scale;
	rad->scale_y = scale;
	icon->scale_x = scale;
	icon->scale_y = scale;
}

void ui_orbit_radial(PANEL *rad, int x, int y, var angle, var dist)
{
	VECTOR res;
	rad->pos_x = x + sinv(angle) * dist;
	rad->pos_y = y + cosv(angle) * dist;
	if(rad->skill_x)
	{
		PANEL *icon = ptr_for_handle(rad->skill_x);
		icon->pos_x = rad->pos_x;
		icon->pos_y = rad->pos_y;
	}
}

void ui_show_radial(PANEL *rad)
{
	PANEL *icon = ptr_for_handle(rad->skill_x);
	icon->flags |= SHOW;
	rad->flags |= SHOW;
}

void ui_hide_radial(PANEL *rad)
{
	if(!rad) { return; }
	PANEL *icon = ptr_for_handle(rad->skill_x);

	icon->flags &= ~SHOW;
	rad->flags &= ~SHOW;
}

void ui_repos_radial(PANEL *rad, int x, int y)
{
	PANEL *icon = ptr_for_handle(rad->skill_x);
	icon->pos_x = x;
	icon->pos_y = y;
	rad->pos_x = x;
	rad->pos_y = y;
}

PANEL* ui_create_radial_button(BMAP *initial_icon, void *ev)
{
	PANEL *rad = pan_create("", 2);

	rad->size_x = bmap_width(ui_radial_n);
	rad->size_y = bmap_height(ui_radial_n);

	pan_setbutton(rad, 0, 0, 0, 0, ui_radial_o, ui_radial_n, ui_radial_o, ui_radial_n, ev, NULL, NULL);

	rad->scale_x = scale_factor_x;
	rad->scale_y = scale_factor_x;

	PANEL *icon = pan_create("", 3);
	icon->bmap = initial_icon;
	icon->scale_x = scale_factor_x;
	icon->scale_y = scale_factor_x;
	icon->flags |= UNTOUCHABLE;


	rad->skill_x = handle(icon);
	return rad;
}

void update_or_create_lifebar(ENTITY *ent)
{
	if( ui_lifebar_counter >= 2000 ) { return; }

	var health = unit_getHealth(ent);
	var fac = health;

	VECTOR sc;
	vec_set(sc, ent.x);
	vec_to_screen(sc, camera);
	vec_sub(sc, vector(15, 35, 0));

	var p1 = 30 * (1 - fac);
	var p2 = 30 * fac;

	if(ui_life_indicator[ui_lifebar_counter])
	{
		pan_setwindow(ui_life_indicator[ui_lifebar_counter], 1, 0, 0, p1, 2, ui_bmap_dead_indicator, 0, 0);
		pan_setwindow(ui_life_indicator[ui_lifebar_counter], 2, p1, 0, p2, 2, ui_bmap_life_indicator, 0, 0);
	}
	else
	{
		ui_life_indicator[ui_lifebar_counter] = pan_create("", 1);
		pan_setwindow(ui_life_indicator[ui_lifebar_counter], 0, 0, 0, p1, 2, ui_bmap_dead_indicator, 0, 0);
		pan_setwindow(ui_life_indicator[ui_lifebar_counter], 0, p1, 0, p2, 2, ui_bmap_life_indicator, 0, 0);
	}

	ui_life_indicator[ui_lifebar_counter]->skill_x = handle(ent);
	ui_life_indicator[ui_lifebar_counter]->pos_x = sc.x;
	ui_life_indicator[ui_lifebar_counter]->pos_y = sc.y;
	ui_life_indicator[ui_lifebar_counter]->alpha = 60;
	ui_life_indicator[ui_lifebar_counter]->flags |= (SHOW | UNTOUCHABLE | TRANSLUCENT);

	ui_lifebar_counter++;
}

void ui_add_dot_to_minimap(ENTITY *ent, int size, BMAP *dot, int counter)
{
	var px = (16000 - abs(ent->y + 8000)) / 16000;
	var py = (16000 - abs(ent->x + 8000)) / 16000;
	var t1 = pan_setwindow(ui_minimap, counter, px * bmap_width(ui_mm), py * bmap_height(ui_mm), size, size, dot, 0, 0);
	if(!t1)
	{
		pan_setwindow(ui_minimap, 0, px * bmap_width(ui_mm) * scale_factor_x * mini_map_extra_scale_x, py * bmap_height(ui_mm) * scale_factor_x * mini_map_extra_scale_y, size, size, dot, 0, 0);
	}
}

void ui_add_camera_to_minimap()
{
	var px = (16000 - abs(camera->y + 8000)) / 16000;
	var py = (16000 - abs(camera->x + 8000)) / 16000;
	var t1 = pan_setneedle(ui_minimap, 1, px * bmap_width(ui_mm), py * bmap_height(ui_mm), ui_bmap_camera, 8, 16, 0, 0, 360, camera.pan );
	if(!t1)
	{
		pan_setneedle(ui_minimap, 0, px * bmap_width(ui_mm) * scale_factor_x * mini_map_extra_scale_x, py * bmap_height(ui_mm) * scale_factor_x * mini_map_extra_scale_y, ui_bmap_camera, 8, 16, 0, 0, 360, camera.pan );
	}
}

void ui_minimap_click(PANEL *panel)
{
	var mpx = mouse_pos.x - panel->pos_x - (bmap_width(ui_mm) * scale_factor_x * mini_map_extra_scale_x) / 2;
	var mpy = mouse_pos.y - panel->pos_y - (bmap_height(ui_mm) * scale_factor_x * mini_map_extra_scale_y) / 2;

	mpx /= (bmap_width(ui_mm) * scale_factor_x * mini_map_extra_scale_x);
	mpy /= (bmap_height(ui_mm) * scale_factor_x * mini_map_extra_scale_y);

	mpx = mpx * 16000 * -1;
	mpy = mpy * 16000 * -1;
	topdown_camera_set_pos(vector(mpy, mpx, camera.z));
}

void ui_game_init()
{
	scale_factor_x = screen_size.x / 1920;
	scale_factor_y = screen_size.y / 1080;

	ui_radial_delete = ui_create_radial_button(NULL, ui_destroy_event_sputnik);
	ui_radial_counter = pan_create("", 2);
	ui_radial_cbabe = ui_create_radial_button(ui_icon_cbabe, ui_spawn_event_sputnik);
	ui_radial_sputnik = ui_create_radial_button(ui_icon_sputnik, ui_spawn_event_sputnik);
	ui_radial_skull = ui_create_radial_button(ui_icon_skull, ui_spawn_event_sputnik);
	ui_radial_esel = ui_create_radial_button(ui_icon_esel, ui_spawn_event_sputnik);

	ui_main_resources = pan_create("", 99);
	ui_unit_meta = pan_create("", 99);
	ui_game_menu = pan_create("", 99);
	ui_portrait = pan_create("", 99);
	ui_minimap = pan_create("", 100);
	ui_monitor = pan_create("", 99);

	ui_radial_counter->bmap = ui_radial_n;
	ui_radial_counter->flags = CENTER_X | CENTER_Y | UNTOUCHABLE;
	pan_setwindow(ui_radial_counter, 0, -5, -4, 128, 128, ui_radial_progress, 0, 0);
	pan_setdigits(ui_radial_counter, 0, bmap_width(ui_radial_n) / 2, bmap_height(ui_radial_n) / 2 , "%.0f", ui_hud_font, 1, &a_dummy_var);

	pan_setbutton(ui_game_menu, 0, 0, 1, 151, ui_hide_button_p, ui_hide_button_n, ui_hide_button_o, ui_hide_button_n, ui_show_commando_groups, NULL, NULL);

	pan_setbutton(ui_game_menu, 0, 4, 15, 134, ui_icon_tower_o, ui_icon_tower, ui_icon_tower_o, ui_icon_tower, ui_place_building, NULL, NULL);
	pan_setbutton(ui_game_menu, 0, 4, 15, 242, ui_icon_farm_o, ui_icon_farm, ui_icon_farm_o, ui_icon_farm, ui_place_building, NULL, NULL);
	pan_setbutton(ui_game_menu, 0, 4, 15, 350, ui_icon_blank_o, ui_icon_blank, ui_icon_blank_o, ui_icon_blank, ui_place_building, NULL, NULL);
	pan_setbutton(ui_game_menu, 0, 4, 15, 458, ui_icon_bank_o, ui_icon_bank, ui_icon_bank_o, ui_icon_bank, ui_place_building, NULL, NULL);

	ui_bmap_cbabe[0] = ui_face_cbabe1;
	ui_bmap_cbabe[1] = ui_face_cbabe2;
	ui_bmap_cbabe[2] = ui_face_cbabe3;

	ui_bmap_sputnik[0] = ui_face_sputnik1;
	ui_bmap_sputnik[1] = ui_face_sputnik2;
	ui_bmap_sputnik[2] = ui_face_sputnik3;

	ui_bmap_noise[0] = ui_face_noise1;
	ui_bmap_noise[1] = ui_face_noise2;
	ui_bmap_noise[2] = ui_face_noise3;

	ui_bmap_esel[0] = ui_face_esel1;
	ui_bmap_esel[1] = ui_face_esel2;
	ui_bmap_esel[2] = ui_face_esel3;

	ui_bmap_eye[0] = ui_face_eye1;
	ui_bmap_eye[1] = ui_face_eye2;
	ui_bmap_eye[2] = ui_face_eye3;

	pan_setwindow(ui_unit_meta, 0, 0, 0, 0, 0, ui_bmap_cbabe[0], 0, 0);

	ui_bmap_dead_indicator = bmap_createblack(8, 8, 24);
	ui_bmap_life_indicator = bmap_createblack(8, 8, 24);

	bmap_fill(ui_bmap_dead_indicator, vector(0, 0, 255), 100);
	bmap_fill(ui_bmap_life_indicator, vector(0, 255, 0), 100);

	bmap_fill(ui_bmap_red, vector(0, 0, 255), 100);
	bmap_fill(ui_bmap_green, vector(0, 255, 0), 100);
	bmap_fill(ui_bmap_blue, vector(255, 0, 0), 100);
	bmap_fill(ui_bmap_yellow, vector(0, 255, 255), 100);
	bmap_fill(ui_bmap_cyan, vector(255, 255, 0), 100);
	bmap_fill(ui_bmap_magenta, vector(255, 0, 255), 100);

	ui_unit_meta->bmap = ui_bmap_units;
	ui_unit_meta->pos_x = 3;

	ui_game_menu->bmap = ui_bmap_gamemenu;

	ui_main_resources->bmap = ui_bmap_resources;
	ui_main_resources->pos_x = 3;
	ui_main_resources->pos_y = 3;
	ui_main_resources->flags |= ARIGHT;
	pan_setdigits(ui_main_resources, 0, bmap_width(ui_bmap_resources) - 50, 13, "%.0f", ui_hud_font, 1, &a_stupid_var );

	ui_monitor->bmap = ui_bmap_monitor;
	ui_minimap->bmap = ui_mm;
	ui_minimap->event = ui_minimap_click;

}

void ui_game_open()
{
	ui_monitor->flags |= SHOW;
	ui_minimap->flags |= SHOW;
	ui_minimap->pos_x = 46;
	ui_minimap->pos_y = screen_size.y - (bmap_height(ui_bmap_monitor) + 14)  * scale_factor_x;

	ui_game_menu->pos_x = screen_size.x - bmap_width(ui_bmap_gamemenu) + 100;
	ui_game_menu->pos_y = screen_size.y * 0.15;

	ui_unit_meta->pos_y = screen_size.y - bmap_height(ui_bmap_units);
	ui_main_resources->flags |= SHOW;

	ui_game_menu->flags |= SHOW;
}

void ui_game_close()
{
	ui_main_resources->flags &= ~SHOW;
	ui_unit_meta->flags &= ~SHOW;
	ui_hide_radial(ui_radial_sputnik);
	ui_hide_radial(ui_radial_cbabe);
	ui_hide_radial(ui_radial_skull);
	ui_hide_radial(ui_radial_esel);
	ui_game_menu->flags &= ~SHOW;
	ui_radial_counter->flags &= ~SHOW;
	ui_portrait->flags &= ~SHOW;
	ui_minimap->flags &= ~SHOW;
	ui_radial_delete->flags &= ~SHOW;
	ui_monitor->flags &= ~SHOW;

	int i; for(i = 0; i < 2000; i++)
	{
		if( ui_life_indicator[i] )
		{
			ui_life_indicator[i]->flags &= ~SHOW;
		}
	}
}

void ui_game_update()
{

	int i; for(i = 0; i < ui_lifebar_counter; i++)
	{
		ENTITY *ent = ptr_for_handle(ui_life_indicator[i]->skill_x);
		if(ent)
		{
			if( !ent->SELCTED_SKILL )
			{
				ui_life_indicator[i]->flags &= ~SHOW;
			}
		}
	}

	scale_factor_x = screen_size.x / 1920;
	scale_factor_y = screen_size.y / 1080;

	if(key_m)
	{
		BMAP* bmp = mapGetBitmap(NULL);
		if(bmp)
		{
			int size = 4;
			draw_quad(bmp,vector(000,0,0),NULL,NULL,vector(size,size,0),NULL,100,0);
			int unitDrawSize = 4;
			int currentPlayer;
			for(currentPlayer = 0; currentPlayer < MAX_PLAYERS; currentPlayer++)
			{
				UNIT *unit = mapCurrent.unitFirst[currentPlayer];
				while(unit)
				{
					if(unit->isActive)
					{
						draw_quad(NULL,vector(unit->pos2d.x*size-unitDrawSize/2,unit->pos2d.y*size-unitDrawSize/2,0),NULL,vector(4,4,0),NULL,COLOR_RED,50,0);
					}
					unit = unit->next;
				}
			}
		}
	}

	ui_add_camera_to_minimap();

	if( buildingState() == -1 )
	{
		button_state(ui_game_menu, 2, 0);
		button_state(ui_game_menu, 3, 0);
		button_state(ui_game_menu, 4, 0);
		button_state(ui_game_menu, 5, 0);
	}

	var scale_factor_x = screen_size.x / 1920;
	var scale_factor_y = screen_size.y / 1080;


	ui_main_resources->scale_x = scale_factor_x;
	ui_main_resources->scale_y = scale_factor_x;

	ui_unit_meta->scale_x = scale_factor_x;
	ui_unit_meta->scale_y = scale_factor_x;

	ui_game_menu->scale_x = scale_factor_x;
	ui_game_menu->scale_y = scale_factor_x;

	ui_portrait->scale_x = scale_factor_x;
	ui_portrait->scale_y = scale_factor_x;

	ui_minimap->scale_x = scale_factor_x * mini_map_extra_scale_x;
	ui_minimap->scale_y = scale_factor_x * mini_map_extra_scale_y;

	ui_monitor->scale_x = scale_factor_x;
	ui_monitor->scale_y = scale_factor_x;
	ui_monitor->pos_y = screen_size.y - bmap_height(ui_bmap_monitor) * scale_factor_x;
	ui_minimap->pos_x = floor(46 * scale_factor_x + 0.5);
	ui_minimap->pos_y = screen_size.y - bmap_height(ui_mm) * scale_factor_x - 12 * scale_factor_x;// + 18;// * scale_factor_x;

	ui_lifebar_counter = 0;

	ENTITY * ent;
	int ui_has_ents = 0;
	int ui_has_building = 0;
	int ui_count_sputniks = 0;
	int ui_count_esel = 0;
	int ui_count_cbabes = 0;
	int ui_count_skull = 0;

	if( !ui_command_group_status )
	{
		ui_game_menu->pos_x = screen_size.x - bmap_width(ui_bmap_gamemenu) * scale_factor_x + 100 * scale_factor_x;
		ui_game_menu->pos_y = screen_size.y * 0.15 * scale_factor_x;
	}
	else
	{
		ui_game_menu->pos_x = screen_size.x - bmap_width(ui_bmap_gamemenu) * scale_factor_x;
		ui_game_menu->pos_y = screen_size.y * 0.15 * scale_factor_x;
	}

	ui_unit_meta->pos_y = screen_size.y - bmap_height(ui_bmap_units) * scale_factor_x - 3;

	int ui_max_type = 0;
	int counter = 1;
	for(ptr = ent_next(NULL); ptr != NULL; ptr = ent_next(ptr)) if(ptr.skill99 == SUBSYSTEM_SPAWNER)
	{
		if( ent->SELCTED_SKILL && ent->HEALTH > 0 )
		{
			if( ent->group == GROUP_PLAYER_SPAWNER )
			{
				ui_has_building = 1;
				ui_active_building = ent;

				update_or_create_lifebar(ent);

				switch(ent->ENTITY_UNITTYPE)
				{
					case UNIT_SPUTNIK:
					ui_radial_active = ui_radial_sputnik;
					ui_radial_sputnik->skill_y = 0;
					break;
					case UNIT_LERCHE:
					ui_radial_active = ui_radial_esel;
					ui_radial_esel->skill_y = 0;
					break;
					case UNIT_EYE:
					ui_radial_active = ui_radial_skull;
					ui_radial_skull->skill_y = 0;
					break;
					case UNIT_BABE:
					ui_radial_cbabe->skill_y = 0;
					ui_radial_active = ui_radial_cbabe;
					break;
				}

				ui_radial_active->skill_y = ent;
				ui_radial_delete->skill_y = ent;
				ui_radial_counter->skill_y = ent;

				a_dummy_var = spawner_getQueue(ent);
			}
		}

        TILE* tile = mapGetTileFromVector(mapGetCurrent(), &ent->x);
        if(tile)
        {
            if (fow_isVisible(tile))
            {
                if( ent->group == GROUP_ENEMY_SPAWNER )
                {
                    ui_add_dot_to_minimap(ent, 3, ui_bmap_green, counter);
                    counter++;
                } else {
                    ui_add_dot_to_minimap(ent, 3, ui_bmap_red, counter);
                    counter++;
                }
            }
        }
	}
	for(ent = ent_next(NULL); ent != NULL; ent = ent_next(ent))
	{
		if( ent->group == GROUP_PLAYER_UNIT)
		{
			if( ent->SELCTED_SKILL )
			{
				ui_has_ents = 1;

				switch(unit_getType(ent))
				{
					case UNIT_SPUTNIK:
					ui_count_sputniks++;
					break;
					case UNIT_LERCHE:
					ui_count_esel++;
					break;
					case UNIT_EYE:
					ui_count_skull++;
					break;
					case UNIT_BABE:
					ui_count_cbabes++;
					break;
				}

				if( str_cmp(ent->type, "SPUTNIK.MDL") )
				{
					ui_count_sputniks++;
				}
				update_or_create_lifebar(ent);
			}
		}

        TILE* tile = mapGetTileFromVector(mapGetCurrent(), &ent->x);
        if(tile)
        {
            if (fow_isVisible(tile))
            {
                if(ent->group == GROUP_PLAYER_UNIT)
                {
                    ui_add_dot_to_minimap(ent, 1, ui_bmap_cyan, counter);
                    counter++;
                }
                else if( ent->group == GROUP_ENEMY_UNIT && ent->ENTITY_UNITTYPE != UNIT_Z)
                {
                    ui_add_dot_to_minimap(ent, 1, ui_bmap_red, counter);
                    counter++;
                }
            }
        }
	}

	for(ptr = ent_next(NULL); ptr != NULL; ptr = ent_next(ptr)) if(ptr.skill99 == SUBSYSTEM_Z)
	{
        TILE* tile = mapGetTileFromVector(mapGetCurrent(), &ent->x);
        if(tile)
        {
            if (fow_isVisible(tile))
            {
                ui_add_dot_to_minimap(ent, 1, ui_bmap_yellow, counter);
                counter++;
            }
        }
	}

	if(ui_has_ents)
	{
		ui_unit_meta->flags |= SHOW;
		ui_monitor->flags &= ~SHOW;
		ui_minimap->flags &= ~SHOW;

		if( ui_count_sputniks >= ui_count_esel && ui_count_sputniks >= ui_count_cbabes && ui_count_sputniks >= ui_count_skull )
		{
			ui_max_type = UI_SPUTNIK;
			ui_active_portrait = ui_bmap_sputnik;
		}
		else if( ui_count_cbabes >= ui_count_esel && ui_count_cbabes >= ui_count_sputniks && ui_count_sputniks >= ui_count_skull )
		{
			ui_max_type = UI_CBABE;
			ui_active_portrait = ui_bmap_cbabe;
		}
		else if( ui_count_skull >= ui_count_esel && ui_count_skull >= ui_count_sputniks && ui_count_skull >= ui_count_cbabes )
		{
			ui_max_type = UI_SKULL;
			ui_active_portrait = ui_bmap_eye;
		}
		else if( ui_count_esel >= ui_count_skull && ui_count_esel >= ui_count_sputniks && ui_count_esel >= ui_count_cbabes )
		{
			ui_max_type = UI_ESEL;
			ui_active_portrait = ui_bmap_esel;
		}
	}
	else
	{
		ui_unit_meta->flags &= ~SHOW;
		ui_monitor->flags |= SHOW;
		ui_minimap->flags |= SHOW;
	}



	VECTOR screen;

	a_stupid_var = z_get(PLAYER_ID_PLAYER);

	if( last_building != ui_active_building)
	{
		ui_hide_radial(ui_radial_sputnik);
		ui_hide_radial(ui_radial_cbabe);
		ui_hide_radial(ui_radial_skull);
		ui_hide_radial(ui_radial_esel);
		ui_anim_state = UI_ANIM_RESTARTED;
		last_building = ui_active_building;
	}

	if( ui_max_type != ui_selected_max_type )
	{
		ui_anim_unit_state = UI_ANIM_UNIT_RESTARTED;
		ui_anim_state = UI_ANIM_OFF;
		ui_selected_max_type = ui_max_type;
	}

	if( !ui_selected_max_type)
	{
		ui_anim_unit_state = UI_ANIM_UNIT_OFF;
	}

	if( ui_anim_unit_state == UI_ANIM_UNIT_RESTARTED )
	{

		ui_switch_frame = 0;
		pan_setwindow(ui_unit_meta, 1, 408, 98, 196, 186, (ui_active_portrait)[0], 0, 0);
		ui_anim_unit_state = UI_ANIM_UNIT_PROGRESS;
	}
	else if( ui_anim_unit_state == UI_ANIM_UNIT_PROGRESS )
	{
		ui_switch_frame += time_step * UI_ANIM_UNIT_SPEED;
		ui_switch_frame %= 19;
		if ( ui_switch_frame >= 13 && ui_switch_frame < 18)
		{
			ui_active_portrait = ui_bmap_noise;
		}
		else if( ui_switch_frame >= 18 )
		{
			ui_anim_unit_state = UI_ANIM_UNIT_OFF;
		}

		pan_setwindow(ui_unit_meta, 1, 408, 98, 196, 186, (ui_active_portrait)[ui_frame_order[ui_switch_frame]], 0, 0);
	}
	else if( ui_anim_unit_state == UI_ANIM_UNIT_ON )
	{

	}
	else if ( ui_anim_unit_state == UI_ANIM_UNIT_OFF )
	{
		pan_setwindow(ui_unit_meta, 1, 0, 0, 0, 0, (ui_bmap_cbabe)[0], 0, 0);
		if( ui_unit_meta->flags & SHOW )
		{
			ui_minimap->pos_x = 412 * scale_factor_x;
			ui_minimap->pos_y = screen_size.y - (202 * scale_factor_x);
			mini_map_extra_scale_x = 0.69;
			mini_map_extra_scale_y = 0.58;
			ui_minimap->scale_x = scale_factor_x * mini_map_extra_scale_x;
			ui_minimap->scale_y = scale_factor_x * mini_map_extra_scale_y;
			ui_minimap->flags |= SHOW;
		}
		else
		{
			mini_map_extra_scale_x = 1;
			mini_map_extra_scale_y = 1;
		}
	}


	if(!last_building || !ui_has_building)
	{
		last_building = NULL;
		ui_anim_state = UI_ANIM_OFF;
	}
	else
	{
		vec_set(screen, last_building.x);
		vec_to_screen(screen, camera);
	}

	if( ui_radial_active )
	{

		if( ui_anim_state == UI_ANIM_RESTARTED )
		{
			ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
			ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
			ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

			ui_anim_unit_state = UI_ANIM_UNIT_OFF;

			ui_show_radial(ui_radial_active);
			ui_scale_radial(ui_radial_active, 0.1);

			ui_show_radial(ui_radial_delete);
			ui_scale_radial(ui_radial_delete, 0.1);

			ui_radial_counter->flags |= SHOW;
			ui_radial_counter->scale_x = 0.1;
			ui_radial_counter->scale_y = 0.1;

			ui_anim_state = UI_ANIM_PROGRESS;
		}
		else if( ui_anim_state == UI_ANIM_PROGRESS )
		{
			ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
			ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
			ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

			if( ui_scale1 <= scale_factor_x )
			{
				ui_scale1 += time_step * UI_ANIM_SPEED;
			}
			if( ui_scale1 >= 0.5 * scale_factor_x )
			{
				ui_scale2 += time_step * UI_ANIM_SPEED;
			}
			if( ui_scale2 >= 0.5* scale_factor_x )
			{
				ui_scale3 += time_step * UI_ANIM_SPEED;
			}

			if (ui_scale1 >= scale_factor_x)
			{
				ui_scale1 = scale_factor_x;
			}
			if (ui_scale2 >= scale_factor_x)
			{
				ui_scale2 = scale_factor_x;
			}
			if (ui_scale3 >= scale_factor_x)
			{
				ui_scale3 = scale_factor_x;
			}

			ui_scale_radial(ui_radial_active, ui_scale1);
			ui_scale_radial(ui_radial_delete, ui_scale2);

			ui_radial_counter->scale_x = ui_scale3;
			ui_radial_counter->scale_y = ui_scale3;

			if( ui_scale1 == scale_factor_x && ui_scale2 == scale_factor_x && ui_scale3 == scale_factor_x)
			{
				ui_anim_state = UI_ANIM_ON;
			}
		}
		else if( ui_anim_state == UI_ANIM_ON )
		{
			ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
			ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
			ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

			ui_scale_radial(ui_radial_active, scale_factor_x);
			ui_scale_radial(ui_radial_delete, scale_factor_x);

			ui_radial_counter->scale_x = scale_factor_x;
			ui_radial_counter->scale_y = scale_factor_x;


		}
		else if ( ui_anim_state == UI_ANIM_OFF )
		{
			ui_hide_radial(ui_radial_active);
			ui_hide_radial(ui_radial_delete);
			ui_radial_counter->flags &= ~SHOW;

			ui_scale1 = 0.1;
			ui_scale2 = 0.1;
			ui_scale3 = 0.1;
		}

	}
}

var ui_game_isdone()
{

}

void ui_game_after_all()
{
	ENTITY * ent = ui_radial_counter->skill_y;
	if(ent)
	progressbar_radial_render(ui_radial_progress, 100 - 100 * spawner_getProgress(ent), 60, vector(0, 1, 0), 50);
}

var unit__dmgtable[UNIT_TABLESIZE] = {
    7,9,2,2,1,
    2,5,7,7,1,
    9,5,3,3,1,
    2,5,7,7,1,
    0,0,0,0,0
};

var unit_setTarget(ENTITY* ent, VECTOR* pos)
{
	VECTOR target2D;
	MAP* map = mapGetCurrent();
	mapGetVector2DFromVector3D(map, target2D, pos);

	//cprintf2("\n unit_setTarget(%p): group(%d)", ent, ent->group);

	if (ent != NULL)
	{
		if (ent->group == GROUP_PLAYER_UNIT || ent->group == GROUP_ENEMY_UNIT)
		{
			vec_set(ent->UNIT_TARGET, pos);
			unitSetTargetFromVector2D(map, jpsUnitGetFromEntity(ent), target2D);
			unit_setVictim(ent, NULL);
			return 1;
		}
	}
	return 0;

}

VECTOR* unit_getTarget(ENTITY* ent)
{
	return &ent->UNIT_TARGET;
}

var unit_setVictim(ENTITY* ent, ENTITY* victim)
{
	if (ent != NULL)
	{
		if (ent->group == GROUP_PLAYER_UNIT || ent->group == GROUP_ENEMY_UNIT)
		{
			if (victim != NULL)
			{
				//if (victim->group == GROUP_UNIT)
				{
					ent->ENTITY_VICTIM = handle(victim);
					ent->ENTITY_VICTIMTYPE = victim->ENTITY_UNITTYPE;
					return 1;
				}
			}
			ent->ENTITY_VICTIMTYPE = UNIT_INVALID;
			ent->ENTITY_VICTIM = NULL;
		}
	}
	return 0;
}

ENTITY* unit_getVictim(ENTITY* ent)
{
	if (ent != NULL)
	{
		ENTITY* victim = ptr_for_handle(ent->ENTITY_VICTIM);
		if (victim != NULL)
		{
			if (victim->ENTITY_STATE == ENTITY_STATE_DIE || victim->ENTITY_STATE == ENTITY_STATE_DEAD)
				return NULL;
		}
		return victim;
	}
	return NULL;
}

ENTITY* unit_spawn(int unittype, VECTOR* pos, var owner)
{
	return unit_spawn(unittype, pos, pos, owner);
}

ENTITY* unit_spawn(int unittype, VECTOR* pos, VECTOR* targetPos, var owner)
{
	ENTITY* ent = NULL;
	switch (unittype)
	{
		case UNIT_SPUTNIK:
			ent = ent_create("sputnik.mdl", pos, Sputnik);
			break;

		case UNIT_LERCHE:
			ent = ent_create("cEselslerche.mdl", pos, Sputnik);
			break;

		case UNIT_EYE:
			ent = ent_create("eye.mdl", pos, Sputnik);
			break;

		case UNIT_BABE:
			ent = ent_create("cbabe.mdl", pos, Sputnik);
			break;

		default:
			break;
	}

	if (ent != NULL)
	{
		ent->OWNER = owner;
		if (owner == PLAYER_ID_AI)
		{
			ent->group = GROUP_ENEMY_UNIT;
			ent->SK_ENTITY_JPS_POINTER_TO_UNIT_STRUCT = jpsUnitCreate(PLAYER_ID_AI, unittype, ent);
		}
		else
		{
			ent->group = GROUP_PLAYER_UNIT;
			ent->SK_ENTITY_JPS_POINTER_TO_UNIT_STRUCT = jpsUnitCreate(PLAYER_ID_PLAYER, unittype, ent);
		}

		ent->ENTITY_UNITTYPE = unittype;
		unit_setTarget(ent, targetPos);
		unit_setVictim(ent,NULL);
	}

	return ent;
}

var unit_getHealth(ENTITY* ent)
{
	return ent->HEALTH / ent->MAXHEALTH;
}

var unit_setDamage(ENTITY* victim, ENTITY* attacker)
{
	if (victim != NULL && attacker != NULL)
	{
		var index = UNIT_CLASSES * clamp(attacker->ENTITY_UNITTYPE,0,UNIT_CLASSES-1) + clamp(victim->ENTITY_UNITTYPE,0,UNIT_CLASSES-1);
		victim->DAMAGE_HIT = unit__dmgtable[index];
		victim->DAMAGE_ENT = handle(attacker);

		return unit__dmgtable[index];
	}
	return 0;
}

int unit_getType(ENTITY* ent)
{
	if (ent != NULL)
	{
		return ent->ENTITY_UNITTYPE;
	}
	return -1;
}

ENTITY* unit_findNextVictim(ENTITY* ptr, var unittype)
{
	ptr->ENTITY_VICTIMTYPE = unittype;
	return unit_findNextVictim(ptr);
}

ENTITY* unit_findNextVictim(ENTITY* ptr)
{

	if (unit_getVictim(ptr) == NULL && ptr->ENTITY_VICTIMTYPE != UNIT_INVALID)
	{
		cprintf0("\n unit__findNextVictim: TRYFIND...");
		ENTITY* ent;
		if(ptr->ENTITY_VICTIMTYPE == UNIT_Z)
		{
			ent = z_findNear(&ptr->x, 2000);
			if(ent)
			{
				unit_setTarget(ptr, &ent->x);
				unit_setVictim(ptr, ent);
			}
		}
		else
		{
		//error("searching");
			if (mapGetNearbyUnitsOfTypeForPos(ptr->x, ptr->ENTITY_VICTIMTYPE, ptr->OWNER, 2000, 1) > 0)
			{
				ent = jpsGetEntityFromUnitArray(0);
				//set new target and victim
				//error(str_for_num(NULL,ent->HEALTH));
				unit_setTarget(ptr, &ent->x);
				unit_setVictim(ptr, ent);
				return ent;
			}
		}
	}
	return NULL;
}

void unit_deactivate(ENTITY* ptr)
{
	UnitMangement_unselect(ptr);
	jpsUnitDestroy(jpsUnitGetFromEntity(ptr));
	ptr->group = 0;
}
