# 1 "main.c"
# 1 "<eingebaut>"
# 1 "<Kommandozeile>"
# 31 "<Kommandozeile>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<Kommandozeile>" 2
# 1 "main.c"
# 1 "/home/felix/gstudio8/include/acknex.h" 1






# 1 "/home/felix/gstudio8/include/litec.h" 1
# 25 "/home/felix/gstudio8/include/litec.h"
typedef char byte;
typedef long HINSTANCE;
typedef long HMODULE;
typedef long HWND;
typedef long HDC;
typedef long BOOL;
typedef long LRESULT;
typedef long UINT;
typedef long WPARAM;
typedef long LPARAM;
typedef long DWORD;
typedef void VOID;
typedef long HRESULT;
typedef long LONG;
typedef void* HANDLE;
typedef void* LPVOID;
typedef long HBITMAP;
typedef char BYTE;
typedef short WORD;
typedef char* LPCSTR;
typedef char* LPTSTR;
typedef char* LPSTR;
typedef long HMENU;
typedef long HBRUSH;
typedef void* UINT_PTR;

typedef struct _RECT{
 long left;
 long top;
 long right;
 long bottom;
}RECT;




double __cdecl acos(double);
double __cdecl asin(double);
double __cdecl atan(double);
double __cdecl atan2(double,double);
double __cdecl cos(double);
double __cdecl cosh(double);
double __cdecl exp(double);
double __cdecl abs(double);
double __cdecl fabs(double);
long __cdecl labs(long);
double __cdecl floor(double);
double __cdecl fmod(double, double);
double __cdecl log(double);
double __cdecl log10(double);
double __cdecl pow(double, double);
double __cdecl sin(double);
double __cdecl sinh(double);
double __cdecl tan(double);
double __cdecl tanh(double);
double __cdecl sqrt(double);
int __cdecl rand();
void __cdecl srand(int seed);



int __cdecl memcmp(void *, void *, long);
void * __cdecl memcpy(void *, void *, long);
void * __cdecl memset(void *, int, long);
void * __cdecl malloc(long);
void __cdecl free(void*);
void * __cdecl realloc(void*,long);

char * __cdecl strcpy(char *, const char *);
char * __cdecl strcat(char *, const char *);

int __cdecl strcmp(const char *, const char *);
int __cdecl strlen(const char *);



int __cdecl Sleep(int);

long printf(char*,...);
long __stdcall DefineApi(long);
# 8 "/home/felix/gstudio8/include/acknex.h" 2
# 1 "/home/felix/gstudio8/include/compat.h" 1
# 148 "/home/felix/gstudio8/include/compat.h"
int trace_floor;
# 9 "/home/felix/gstudio8/include/acknex.h" 2

typedef fixed var;
typedef fixed function;
typedef void action;

# 1 "/home/felix/gstudio8/include/atypes.h" 1
# 302 "/home/felix/gstudio8/include/atypes.h"
typedef struct VECTOR {
 var x,y,z;
} VECTOR;

typedef struct ANGLE {
 var pan,tilt,roll;
} ANGLE;

typedef struct COLOR {
 var blue,green,red;
} COLOR;

typedef struct COLOR4 {
 var blue,green,red,alpha;
} COLOR4;





typedef struct C_LINK {
 long index;
 struct C_LINK *next;
 char *name;
} C_LINK;

typedef byte* EVENT;


typedef struct STRING {
 C_LINK link;
 char *chars;
 long length;
 long flags;
 byte pad[8];
} STRING;

typedef struct SOUND {
 C_LINK link;
 long length;
 byte *buffer;
 long type;
} SOUND;

typedef struct BMAP {
 C_LINK link;
 long width,height;
 long bytespp;
 void *ptr;
 byte *pixels;
 long flags;
 void *d3dtex;
 float u1,v1,u2,v2;
 long u,v;
 long refcount;
 long finalwidth,finalheight,finalbytespp;
 long pitch,finalpitch;
 long miplevels;
 long finalformat;
 void *finalbits;
} BMAP;

typedef struct {
 float x,y,z;
 float nx,ny,nz;
 float u1,v1;
 float u2,v2;
 float x3,y3,z3,w3;
 float tu4,tv4;
} D3DVERTEX;



typedef struct MATERIAL {
 C_LINK link;
 var ambient_blue,ambient_green,ambient_red;
 var diffuse_blue,diffuse_green,diffuse_red;
 var specular_blue,specular_green,specular_red;
 var emissive_blue,emissive_green,emissive_red;
 var map_blue,map_green,map_red;
 var alpha;
 var power;
 var albedo;
 var scale1,scale2;
 var cycle;
 var skill[20];
 float matrix[16];
 long flags;
 char *effect;
 var lod;
 BMAP *skin1,*skin2,*skin3,*skin4;
 EVENT event;
 void* d3deffect;
 void* d3dmaterial;
 char* technique;
 var maxbones;
 byte pad[436];
} MATERIAL;

typedef struct ENTITY {
 C_LINK link;
 char *type;
 var x,y,z;
 var pan,tilt,roll;
 var scale_x,scale_y,scale_z;
 long flags;
 var frame;
 var next_frame;
 var skin;
 var ambient;
 var albedo;
 var alpha;
 var lightrange;
 var blue,green,red;
 long emask;
 long eflags;
 var min_x,min_y,min_z;
 var max_x,max_y,max_z;
 var trigger_range;
 var push;
 var floor_dist;
 long smask;
 var client_id;

 var skill[100];
 var pose;
 MATERIAL* material;
 var u,v;
 var group;
 long flags2;
 char *attachname;
 EVENT event;
 EVENT local;
 var layer;
 long vmask;
 char *string1,*string2;
 float fRadius;
 long path_index;
 void* model;
 struct ENTITY* shadow;
 struct ENTITY* parent;
 BMAP* lightmap;
 void* body;
 var clipfactor;
} ENTITY;

typedef struct PARTICLE {
 C_LINK link;
 var lifespan;
 var x,y,z;
 var vel_x,vel_y,vel_z;
 var size;
 BMAP *bmap;
 EVENT event;
 long flags;
 var skill_x,skill_y,skill_z;
 var gravity;
 var angle;
 var alpha;
 ENTITY *creator;
 var blue,green,red;
 var skill[4];
   void* d3dmesh;
   MATERIAL* material;
} PARTICLE;

typedef struct CONTACT {
 D3DVERTEX *v;
 var x,y,z;
 var nx,ny,nz;
 var u1,v1;
 var u2,v2;
 var vertex;
 var triangle;
 var chunk;
 void* model;
 var light;
 var alpha;
 var blue,green,red;
 long flags;
   ENTITY* entity;
 BMAP *skin1,*skin2,*skin3,*skin4;
   char* texname;
   var subset;
} CONTACT;





typedef struct FONT {
 C_LINK link;
 int dx,dy;
 int num;
 int cpl;
 char *type;
 BMAP bmap;
   byte pad[64];
} FONT;

typedef struct TEXT {
 C_LINK link;
 long type;
 var layer;
 var pos_x,pos_y;
 long flags;
 var alpha;
 var offset_y;
 var size_y;
 FONT* font;
 long length;
 STRING* *pstring;
 var scale_x,scale_y;
 var blue,green,red;
 var strings;
 BMAP* target_map;
 var offset_x;
 var size_x;
 var skill_x,skill_y;
 byte pad[12];
} TEXT;

typedef struct PANEL {
 C_LINK link;
 long type;
 var layer;
 var pos_x,pos_y;
 long flags;
 var alpha;
 BMAP *bmap;
 var scale_x,scale_y;
 var blue,green,red;
 var size_x,size_y;
 var angle;
 var center_x,center_y;
 BMAP *mouse_map;
 BMAP *target_map;
 EVENT event;
 var skill_x,skill_y;
 byte pad[24];
} PANEL;

typedef struct VIEW {
 C_LINK link;
 long type;
 var layer;
 var pos_x,pos_y;
 long flags;
 var size_x,size_y;
 var x,y,z;
 var pan,tilt,roll;
 var offset_x,offset_y;
 var arc;
 var aspect;
 var ambient;
 var bg;
 var alpha;
 var portal_x,portal_y,portal_z;
 var pnormal_x,pnormal_y,pnormal_z;
 var fog_start,fog_end;
 var depth;
 ENTITY *genius;
 struct VIEW *portal;
 BMAP *bmap;
 var clip_near,clip_far;
 MATERIAL *material;
 struct VIEW *stage;
 var monitor;
 var skill_x,skill_y;
 var lod;
 var left,right,bottom,top;
 BMAP *target1,*target2,*target3;
 byte pad[48];
} VIEW;
# 15 "/home/felix/gstudio8/include/acknex.h" 2






# 1 "/home/felix/gstudio8/include/afuncs.h" 1
# 13 "/home/felix/gstudio8/include/afuncs.h"
var ang(var);
var sign(var);
var fraction(var);
var integer(var);
var floorv(var);
var random(var);
var randomize();
var random_seed(var);
var absv(var);
var sinv(var);
var cosv(var);
var tanv(var);
var asinv(var);
var acosv(var);
var atanv(var);
var atan2v(var,var);
var expv(var);
var logv(var);
var log10v(var);
var sqrtv(var);
var powv(var,var);
var maxv(var,var);
var minv(var,var);
var fsin(var,var);
var fcos(var,var);
var ftan(var,var);
var fasin(var,var);
var facos(var,var);
var fatan(var,var);
var accelerate(var*,var,var);
var clamp(var,var,var);
var cycle(var,var,var);
var ifelse(var,var,var);
var smooth(var*,var);
var floatv(var);
var floatd(var,var);
var floatr(var);


 ANGLE* ang_add(ANGLE*,ANGLE*);
 ANGLE* ang_rotate(ANGLE*,ANGLE*);
 ANGLE* ang_diff(ANGLE *a,ANGLE *a1,ANGLE *a2);
 ANGLE* ang_for_axis(ANGLE *a, VECTOR* v,var rot);
 ANGLE* ang_for_matrix(ANGLE *a,float* m);
 float* ang_to_matrix(ANGLE *a,float* m);

var vec_length(VECTOR*);
var vec_dist(VECTOR*,VECTOR*);
var vec_cross(VECTOR* a,VECTOR* b,VECTOR* c);
var vec_dot(VECTOR*,VECTOR*);
 VECTOR* vec_mul(VECTOR*,VECTOR*);
 VECTOR* vec_normalize(VECTOR*,var);
 VECTOR* vec_accelerate(VECTOR*,VECTOR*,VECTOR*,var);
 VECTOR* vec_bounce(VECTOR *vRay,VECTOR *vNormal);
 VECTOR* vec_add(VECTOR*,VECTOR*);
 VECTOR* vec_diff(VECTOR*,VECTOR*,VECTOR*);
 VECTOR* vec_inverse(VECTOR*);
 VECTOR* vec_lerp(VECTOR*,VECTOR*,VECTOR*,var);
 VECTOR* vec_rotate(VECTOR*,ANGLE*);
 VECTOR* vec_rotateback(VECTOR*,ANGLE*);
 VECTOR* vec_rotateaxis(VECTOR *v,VECTOR *axis,var angle);
 VECTOR* vec_scale(VECTOR*,var);
 VECTOR* vec_set(VECTOR*,VECTOR*);
 VECTOR* vec_fill(VECTOR*,var);
 VECTOR* vec_sub(VECTOR*,VECTOR*);
 VECTOR* vec_for_angle(VECTOR*,ANGLE*);
var vec_to_angle(ANGLE*,VECTOR*);
 VECTOR* vec_for_bone(VECTOR*,ENTITY*,char* bonename);
 ANGLE* ang_for_bone(ANGLE*,ENTITY*,char* bonename);
 VECTOR* vec_for_normal(VECTOR*,ENTITY*,var);
 VECTOR* vec_for_vertex(VECTOR*,ENTITY*,var);
 VECTOR* vec_for_ent(VECTOR*,ENTITY*);
 VECTOR* vec_to_ent(VECTOR*,ENTITY*);
 VECTOR* vec_for_min(VECTOR*,ENTITY*);
 VECTOR* vec_for_max(VECTOR*,ENTITY*);
 VECTOR* vec_for_mesh(VECTOR*,ENTITY*,var);
 VECTOR* vec_to_mesh(VECTOR*,ENTITY*,var);
 VECTOR* vec_for_uv(VECTOR*,ENTITY*,var);
 VECTOR* vec_to_uv(VECTOR*,ENTITY*,var);
 VECTOR* vec_for_screen(VECTOR*,VIEW*);
 VECTOR* vec_to_screen(VECTOR*,VIEW*);
 VECTOR* rel_for_screen(VECTOR*,VIEW*);
 VECTOR* rel_to_screen(VECTOR*,VIEW*);
 VECTOR* vector(var,var,var);


 float* mat_identity(float*);
 float* mat_inverse(float*,float*);
 float* mat_multiply(float*,float*);
 float* mat_scale(float*,var,var,var);
 float* mat_set(float*,float*);
 float* mat_transpose(float*,float*);




 STRING* str_create(char *content);
 STRING* str_createw(short *content);
var str_remove(STRING*);
 STRING* str_cpy(STRING* to,char* from);
 STRING* str_cat(STRING* to,char* from);
 STRING* str_cat_num(STRING *s1,char *s2,var num);
 STRING* str_printf(STRING *s1,char *s2,...);
 STRING* str_clip(STRING*,var);
 STRING* str_trunc(STRING*,var);
 STRING* str_lwr(STRING*);
 STRING* str_upr(STRING*);
var str_cmp(STRING*,char*);
var str_cmpi(STRING*,char*);
var str_cmpni(STRING*,char*);
var str_len(char*);
var str_chr(STRING*,var start,var chr);
var str_setchr(STRING*,var pos,var chr);
var str_getchr(STRING*,var pos);
var str_stri(STRING*,char*);
 STRING* str_for_asc(STRING*,var);
var str_to_asc(char*);
 STRING* str_for_float(STRING*,double);
 STRING* str_for_int(STRING*,long);
 STRING* str_for_num(STRING*,var);
 double str_to_float(char*);
 long str_to_int(char*);
var str_to_num(char*);
var str_cursor(STRING*);
var str_width(char* s,FONT* font);
 STRING* str_for_entname(STRING*,ENTITY*);
 STRING* str_for_entfile(STRING*,ENTITY*);
 STRING* str_for_id(STRING*,var client_id);


 BMAP* bmap_create(char* filename);
 BMAP* bmap_createblack(var width,var height,var format);
 BMAP* bmap_createpart(char* filename,var x,var y,var width,var height);
 void bmap_remove(BMAP* bmap);
 BMAP* bmap_for_entity(ENTITY*,var frame);
 BMAP* bmap_for_screen(BMAP*,var,var);
 BMAP* bmap_for_buffer(var mode);
 BMAP* bmap_for_texture(char* texname);
 void* bmap_preload(BMAP*);
 void* bmap_purge(BMAP*);
 BMAP* bmap_load(BMAP*,char* filename,var flags);
 BMAP* bmap_save(BMAP*,char *filename);
 BMAP* bmap_to_alpha(BMAP*,var factor);
 BMAP* bmap_to_cubemap(BMAP*);
 BMAP* bmap_to_mipmap(BMAP*);
 BMAP* bmap_to_normals(BMAP*,var);
 BMAP* bmap_to_uv(BMAP*);
 BMAP* bmap_to_format(BMAP*,var format);
var bmap_height(BMAP*);
var bmap_width(BMAP*);
var bmap_format(BMAP*);
var bmap_lock(BMAP*,var);
var bmap_unlock(BMAP*);
var bmap_blit(BMAP* bDest,BMAP* bSrc,VECTOR* vPos,VECTOR* vSize);
var bmap_blitpart(BMAP* bDest,BMAP* bSrc,VECTOR* vDestPos,VECTOR* vDestSize,VECTOR* vSrcPos,VECTOR* vSrcSize);
 BMAP* bmap_fill(BMAP* bmap,COLOR* color,var alpha);
 BMAP* bmap_process(BMAP *bDest,BMAP *bSrc,MATERIAL* mtl);
var bmap_rendertarget(BMAP* bmap,var num,var face);
var bmap_zbuffer(BMAP* bmap);
var pixel_for_bmap(BMAP*,var,var);
var pixel_to_bmap(BMAP*,var x,var y,var pixel);
var pixel_for_vec(COLOR*,var,var);
 COLOR* pixel_to_vec(COLOR*,var*,var,var pixel);


var cd_play(var from,var to);
var cd_pause();
var cd_start();
var cd_track();
var media_play(char* filename,BMAP* target,var volume);
var media_loop(char* filename,BMAP* target,var volume);
var media_pause(var handle);
var media_playing(var handle);
var media_start(var handle);
var media_stop(var handle);
var media_tune(var handle,var volume,var pitch,var balance);


 SOUND* snd_create(char *filename);
var snd_remove(SOUND*);
var snd_buffer(SOUND* snd,void** pDesc,void*** ppSample);
var snd_play(SOUND*,var,var);
var snd_loop(SOUND*,var,var);
var snd_playing(var handle);
var snd_pause(var handle);
var snd_start(var handle);
var snd_stop(var handle);
var snd_tune(var handle,var,var,var);
var snd_add(var handle,var offset,void* Sample, var length);
var snd_stopall(var);
var ent_playloop(ENTITY*,SOUND*,var);
var ent_playloop2(ENTITY*,SOUND*,var vol,var range);
var ent_playsound(ENTITY*,SOUND*,var);
var ent_playsound2(ENTITY*,SOUND*,var vol,var range);


var c_intersect(VECTOR* min1,VECTOR* max1,VECTOR* vel1,VECTOR* min2,VECTOR* max2,VECTOR* vel2);
var c_content(VECTOR*,var mode);
var c_scan(VECTOR*,VECTOR*,VECTOR*,var mode);
var c_trace(VECTOR*,VECTOR*,var mode);
var c_move(ENTITY*,VECTOR*,VECTOR*,var mode);
var c_rotate(ENTITY*,VECTOR*,var mode);
var c_setminmax(ENTITY*);
var c_updatehull(ENTITY*,var);
var c_ignore(var,...);


 MATERIAL* mtl_create();
 void mtl_remove(MATERIAL*);
var effect(EVENT,var,VECTOR*,VECTOR*);
var effect_layer(EVENT,var,VECTOR*,VECTOR*);
var effect_local(EVENT,var,VECTOR*,VECTOR*);
 void* effect_cpy(MATERIAL* to,MATERIAL* from);
 void* effect_load(MATERIAL* mtl,char *filename);
var mat_effect(float *matrix);


 ENTITY* ent_create(char* filename,VECTOR* position,EVENT);
 ENTITY* ent_createlocal(char* filename,VECTOR*,EVENT);
 ENTITY* ent_createlayer(char* filename,var flags,var layer);
 ENTITY* ent_createterrain(BMAP* bmap,VECTOR* pos,var nx,var ny,var size);
 ENTITY* ent_next(ENTITY*);
 ENTITY* ent_nextlight(ENTITY*,var n);
var ent_nextvertex(ENTITY*,VECTOR*);
 ENTITY* ent_pvs(var n,var mode);
 ENTITY* ent_for_name(char* name);
 ENTITY* ent_for_file(char *s);
 void* ent_mesh(ENTITY* ent,var num);
 void* ent_getmesh(ENTITY* ent,var num,var lod);
var ent_setmesh(ENTITY* ent,void* mesh,var num,var lod);
var ent_buffers(ENTITY *e,var n,var lod,void** verts,void** tris,void** attribs);
 CONTACT* ent_getvertex(ENTITY *e,CONTACT* c,var num);
 CONTACT* ent_setvertex(ENTITY *e,CONTACT* c,var num);
 PARTICLE* ent_decal(ENTITY*,BMAP*,var size,var angle);
 PARTICLE* ent_getdecal(ENTITY* e,var chunk,var num);
 ENTITY* ent_clone(ENTITY*);
 ENTITY* ent_cloneskin(ENTITY*);
var ent_morph(ENTITY*,char *filename);
var ent_morphskin(ENTITY*,char *filename);
 MATERIAL* ent_mtlset(ENTITY*,MATERIAL*,var skin);
 BMAP* ent_getskin(ENTITY*,var skin);
 BMAP* ent_setskin(ENTITY*,BMAP*,var skin);
var ent_preload(ENTITY*);
var ent_purge(ENTITY*);
var ent_reload(ENTITY*);
var ent_remove(ENTITY*);
var ent_animate(ENTITY*,char *scenename,var,var);
var ent_animatefrom(ENTITY*,ENTITY*,char *scenename,var,var);
var ent_blend(STRING*,var,var);
var ent_blendframe(ENTITY*,ENTITY*,char *scenename,var,var);
var ent_blendpose(ENTITY*,var,var,var);
 STRING* ent_bonename(ENTITY*,STRING*,var);
var ent_bonereset_all(ENTITY*);
var ent_bonereset(ENTITY*,char *bonename);
var ent_bonereset_branch(ENTITY*,char *bonename);
var ent_bonerotate(ENTITY*,char *bonename,VECTOR*);
var ent_bonerotate_parent(ENTITY*,char *bonename,VECTOR*);
var ent_bonemove(ENTITY*,char *bonename,VECTOR*);
var ent_bonescale(ENTITY*,char *bonename,VECTOR*);
 long ent_bonehandle(ENTITY*,char *bonename,var index);
 long ent_boneparent(ENTITY*,char *bonename,var index);
var ent_fixnormals(ENTITY*,var);
var ent_type(ENTITY*);
var ent_status(ENTITY*,var mode);
var ent_frames(ENTITY*);
var ent_skins(ENTITY*);
var ent_bones(ENTITY*);
var ent_vertices(ENTITY*);


var path_create(ENTITY*,var,var);
var path_set(ENTITY*,char *name);
var path_next(ENTITY*);
var* path_getedge(ENTITY*,var,var,var* skills);
var* path_setedge(ENTITY*,var,var,var* skills);
var* path_getnode(ENTITY*,var,VECTOR* position,var* skills);
var* path_setnode(ENTITY*,var,VECTOR* position,var* skills);
var path_nextnode(ENTITY*,var,var);
var path_scan(ENTITY*,VECTOR* position,ANGLE* direction,VECTOR* sector);
var path_scanpath(ENTITY*,VECTOR* position,ANGLE* direction,VECTOR* sector);
var path_scannode(ENTITY*,var number);
var path_length(ENTITY*);
var path_spline(ENTITY*,VECTOR* position,var dist);
var region_check(char* name,VECTOR* vMin, VECTOR* vMax);
var region_create(char* name,VECTOR* vMin, VECTOR* vMax);
 STRING* region_find(STRING* name,VECTOR* pos);
var region_set(char* name,var mode);
var region_get(char* name,var num,VECTOR* vMin, VECTOR* vMax);


 char* file_cpy(char *name_to,char *name_from);
 char* file_rename(char *name_old,char *name_new);
 char* file_for_screen(char *name,var number);
 long file_date(char *name);
 char* file_delete(char *name);
 void* file_exists(char *name);
 void* file_load(char *name,void* buffer,long* size);
 void* file_save(char *name,void* buffer,long size);
var file_open_append(char *name);
var file_open_game(char *name);
var file_open_read(char *name);
var file_open_write(char *name);
var file_close(var handle);
var file_length(var handle);
var file_find(var handle,char *str);
var file_seek(var handle,var offset,var mode);
var file_asc_read(var handle);
var file_asc_write(var handle,var);
var file_chr_read(var handle,STRING*);
var file_str_read(var handle,STRING*);
var file_str_readto(var handle,STRING *s,char *delimit,var length);
var file_str_readtow(var handle,STRING *s,char *delimit,var length);
var file_str_write(var handle,char*);
var file_str_writeto(var handle,char*,var length);
var file_var_read(var handle);
var file_var_write(var handle,var);


var key_for_str(char*);
 STRING* str_for_key(STRING*,var);
var key_pressed(var);
var key_set(var,EVENT);


var level_load(char *filename);
 void level_mark();
 void level_free();
var game_save(char *filename,var,var);
var game_load(char *filename,var);

 long sys_active(char *title);
var sys_exit(char *message);
var sys_message(char *message);
var sys_metrics(var);
var sys_record(char *filename,var mode);
var sys_replay(char *filename);
var sys_trial(char* section,char *name,var days);
var sys_setstr(char* section,char *name,char* str);
 STRING* sys_getstr(char* section,char *name,char* str);
var sys_setvar(char* section,char *name,var val);
var sys_getvar(char* section,char *name);

var video_set(var,var,var,var);
var video_switch(var,var,var);
var video_window(VECTOR*,VECTOR*,var,char *title);
var video_border(BMAP* border,var x,var y,var dx,var dy);


 PANEL* pan_create(char* content,var layer);
var pan_remove(PANEL*);
var pan_setbmap(PANEL*,var type,var number,BMAP* bmap);
var pan_setcolor(PANEL*,var type,var number,COLOR*);
var pan_setevent(PANEL*,var type,var number,EVENT event);
var pan_setpos(PANEL*,var type,var number,VECTOR* xy);
var pan_getpos(PANEL*,var type,var number,VECTOR* xy);
var pan_setvar(PANEL*,var type,var number,var* v);
var pan_setbutton(PANEL* p,var num,var type,var x,var y,
    BMAP* bmapOn,BMAP* bmapOff,BMAP* bmapOver,BMAP* bmapOverOff,
    void* functionClick,void* functionLeave,void* functionOver);
var pan_setdigits(PANEL* p,var num,var x,var y,
    char* format,FONT* font,var factor,var* pv);
var pan_setneedle(PANEL* p,var num,var x,var y,
    BMAP* bmap,var cx,var cy,var angle,var min,var max,var* pv);
var pan_setslider(PANEL* p,var num,var x,var y,
    BMAP* bmapBg,BMAP* bmapKnob,var min,var max,var* pv);
var pan_setstring(PANEL* p,var num,var x,var y,
    FONT* font,char* string);
var pan_setwindow(PANEL* p,var num,var x,var y,
    var dx,var dy,BMAP* bmap,var* px,var* py);
var digits_set(PANEL*,var number,var* digit);
var button_state(PANEL*,var number,var state);
var layer_sort(void *element,var layer);

 TEXT* txt_create(var strings,var layer);
 void txt_remove(TEXT*);
var txt_for_dir(TEXT*,char *path);
var txt_sort(TEXT*);
var txt_load(TEXT*,char *filename);
var txt_loadw(TEXT*,char *filename);
var txt_addstring(TEXT *t,char *s);
var txt_setinvisible(TEXT*,var);
var txt_setvisible(TEXT*,var);
 STRING* txt_str(TEXT*,int n);

 FONT* font_create(char* content);
 void font_remove(FONT*);

 VIEW* view_create(var layer);
var view_check(VIEW* view,VECTOR* vMin,VECTOR* vMax);
var view_to_light(VIEW* view,var num,var mode);
 float* view_to_matrix(VIEW* view,float *matView,float *matProj);
 float* view_to_split(VIEW* view,var split1,var split2,VIEW* split,float* matSplit);


 void* draw_begin();
var draw_line(VECTOR* xy,COLOR*,var alpha);
var draw_line3d(VECTOR* xyz,COLOR*,var alpha);
var draw_box3d(VECTOR* vMin,VECTOR* vMax,COLOR*,var alpha);
var draw_obj(void* ptr);
var draw_point3d(VECTOR* vPos,COLOR*,var alpha,var size);
var draw_quad(BMAP* bmap,VECTOR* vPos,VECTOR* vOffs,
    VECTOR* vSize,VECTOR* vScale,COLOR* vColor,var alpha,var angle);
var draw_text(char* text,var,var,COLOR*);
var draw_textmode(char* fontname,var,var,var);


var proc_client(ENTITY*,EVENT);
var proc_local(ENTITY*,EVENT);
var send_data_to(ENTITY*,void* buffer,var size);
var send_data_id(var client_id,void* buffer,var size);
var send_skill(var* skill,var mode);
var send_skill_to(ENTITY*,var* skill,var mode);
var send_skill_id(var client_id,var* skill,var mode);
var send_string(STRING*);
var send_string_to(ENTITY*,STRING*);
var send_string_id(var client_id,STRING*);
var send_var(void*);
var send_var_to(ENTITY*,void*);
var send_var_id(var client_id,void*);
 void session_close();
var session_connect(char* sessionname,char *hostname);
var session_open(char* sessionname);
var client_drop(char* name);
var client_drop_id(var client_id);
var client_find(var num);
var ent_sendnow(ENTITY*);

var socket_connect(char *IP,var port,var mode);
var socket_select(var num);
var socket_receive(void* buffer,var size);
var socket_send(void* buffer,var size);


var beep();
var diag(char *text);
var diag_var(char *format,var);
var diag_frame(var *v);
var diag_status();
var error(char *text);
var timer();
 double dtimer();
var breaks();


var port_in(var port);
var port_out(var port,var data);
var wiimote_handle(var num);
var input_init(var num);


var exec(char* program,char *cmdline);
var exec_wait(char* program,char *cmdline);
var proc_kill(var);
var proc_kill2(void* code,ENTITY* ent);
var proc_status(void* code);
var proc_status2(void* code,ENTITY* ent);
var execute(char *command);
 void* var_for_name(char* name);
 void* ptr_first(void* object);
 void* ptr_remove(void* object);
 void* ptr_for_handle(var handle);
var handle(void* object);
 void* sys_malloc(long size);
 void* sys_nxalloc(long size);
 void sys_free(void* ptr);
 void* sys_marker(char* mark);




 char* _chr(STRING*);


 STRING* _str(char*);


 VECTOR* _vec(float x,float y,float z);


var add_buffer(char* name,void* buffer,long size);


var add_folder(char* pathname);


var add_resource(char* content);


var add_new();


var add_struct(void* data,long size);


 long engine_getobj(char *name);



 void* engine_getvar(char *name,long* type);
# 523 "/home/felix/gstudio8/include/afuncs.h"
 long engine_getvarinfo(void* address,char *name,char *structname,long *offset);




 long engine_getfunc(char *name);


 long engine_getscript(char *name);


 long engine_getscriptinfo(void* address,char **name);


 long engine_gettaskinfo(long num,char **name,ENTITY **me);



var engine_callname4(char *name,long p1,long p2,long p3,long p4);
var engine_callscript4(long address,long p1,long p2,long p3,long p4);


var engine_debugposition(char **scriptname,long *offset,long *line);







var engine_debugbreakpoint(char *scriptname,long line, long on);







 long engine_debugstep(long mode);






 long engine_status(long code);
# 22 "/home/felix/gstudio8/include/acknex.h" 2


var abs(var);
var acos(var);
var asin(var);
var atan(var);
var atan2(var,var);
var cos(var);
var sin(var);
var tan(var);
STRING* txt_str(TEXT*);


var wait(var);
var inchar(STRING*);
var inkey(STRING*);
# 54 "/home/felix/gstudio8/include/acknex.h"
int ackFirst;

# 1 "/home/felix/gstudio8/include/avars.h" 1







extern var version;
extern var edition;
extern var compatibility;
extern var logo;
extern var nexus;
extern var event_type;
extern var warn_level;
extern var max_loops;
extern var freeze_mode;
extern var debug_mode;
extern var debug_external;
extern var mtl_mode;
extern var last_error;
extern var proc_mode;
extern var run_mode;
extern var patch;
extern var result;
extern var max_nexus;
extern var diag_mode;
extern var record_mode;


extern var time_step;
extern var time_factor;
extern var time_smooth;
extern var time_frame;
extern var total_ticks;
extern var total_secs;
extern var total_frames;
extern var fps_max;
extern var fps_min;
extern var fps_lock;
extern var reserved01[3];

extern var time_actions;
extern var time_render;
extern var time_level;
extern var time_entities;
extern var time_effects;
extern var time_pfuncs;
extern var time_portals;
extern var time_sky;
extern var time_client;
extern var time_server;
extern var time_panels;
extern var time_update;
extern var time_physics;
extern var time_total;
extern var time_idle;
extern var time_draw;
extern var time_scope;

extern var sys_seconds;
extern var sys_minutes;
extern var sys_hours;
extern var sys_day;
extern var sys_month;
extern var sys_year;
extern var sys_dow;
extern var sys_doy;
extern var sys_memory;
extern var sys_winversion;
extern var reserved03[4];


extern var enable_joystick;
extern var num_joysticks;
extern var joy_sense;
extern VECTOR joy_force;
extern VECTOR joy_raw;
extern VECTOR joy_rot;
extern var joy_hat;
extern VECTOR joy2_raw;
extern VECTOR joy2_rot;
extern var joy2_hat;
extern var joy_buttons;
extern var joy2_buttons;
extern var reserved04[1];

extern var enable_mouse;
extern var mouse_mode;
extern var mouse_sense;
extern VECTOR mouse_force;
extern VECTOR mouse_pos;
extern VECTOR mouse_spot;
extern var mouse_pointer;
extern var mouse_range;
extern var mouse_time;
extern var mouse_moving;
extern var mouse_calm;
extern var mouse_sync;
extern var mouse_valid;
extern var touch_state;
extern VECTOR mickey;
extern VECTOR mouse_cursor;
extern VECTOR mouse_pos3d;
extern VECTOR mouse_dir3d;
extern var reserved05[3];

extern var enable_key;
extern var key_sense;
extern VECTOR key_force;
extern var shift_sense;
extern var key_shift;
extern var key_any;
extern var key_lastpressed;
extern var inkey_active;
extern var text_outline;
extern var decal_clip;


extern var video_aspect;
extern var video_mode;
extern var video_depth;
extern var video_screen;
extern VECTOR screen_size;
extern COLOR screen_color;
extern var window_focus;
extern var video_gamma;
extern VECTOR window_pos;
extern var d3d_antialias;
extern var mip_levels;
extern COLOR ambient_color;


extern var d3d_caps;
extern var d3d_optimize;
extern var d3d_mode;
extern var d3d_nobsp;
extern var d3d_noents;
extern var d3d_novis;
extern var d3d_notex;
extern var d3d_flags;
extern var d3d_lightres;
extern var d3d_monochrome;
extern var d3d_lines;
extern var d3d_anisotropy;
extern var d3d_instancing;
extern var d3d_lockable;
extern var effect_lod;
extern var d3d_autotransparency;
extern var d3d_automaterial;
extern var d3d_shaderversion;
extern var shadow_offset;
extern var shadow_threshold;
extern var shadow_range;
extern var shadow_stencil;
extern var d3d_shadowdepth;
extern var d3d_alphadepth;
extern var shadow_lod;
extern var d3d_texsmaps;
extern var d3d_texbmaps;
extern var d3d_texskins;
extern var d3d_texsurfs;
extern var d3d_textotal;
extern var d3d_texmemory;
extern var d3d_alpharef;
extern var d3d_texfree;
extern var d3d_texdepth;
extern var d3d_texmax;
extern var d3d_texlimit;
extern var d3d_entsort;
extern var d3d_near_sprites;
extern var d3d_mipmapping;
extern var d3d_near_models;
extern var d3d_triplebuffer;
extern VECTOR d3d_lodfactor;
extern VECTOR d3d_pointlightfalloff;
extern VECTOR d3d_spotlightfalloff;
extern VECTOR d3d_spotlightcone;
extern var tree_range;
extern var clip_factor;
extern var clip_particles;
extern var d3d_near_decals;
extern var floor_range;
extern var particle_mode;
extern var mip_shaded;
extern var mip_flat;
extern var mip_sprites;
extern var shadow_mode;
extern var group_mode;


extern var max_particles;
extern var max_entities;
extern var max_lights;
extern COLOR sky_color;
extern var max_bones;
extern var sky_blend;
extern VECTOR sky_speed;
extern VECTOR cloud_speed;
extern var d3d_skydepth;
extern var sky_curve;
extern var sky_clip;
extern var terrain_chunk;
extern var terrain_lod;
extern var num_lights;
extern var num_sounds;
extern var sun_light;
extern COLOR sun_color;
extern ANGLE sun_angle;
extern VECTOR sun_pos;
extern var preload_mode;
extern var fog_color;
extern COLOR d3d_fogcolor1;
extern COLOR d3d_fogcolor2;
extern COLOR d3d_fogcolor3;
extern COLOR d3d_fogcolor4;
extern var max_paths;
extern var num_paths;
extern var tex_cycles;
extern var detail_size;
extern var pos_resolution;
extern var tex_share;
extern var map_subents;


extern var num_particles;
extern var num_entities;
extern var num_visents;
extern var num_vismappolys;
extern var num_visentpolys;
extern var num_vistriangles;
extern var num_actions;


extern var connection;
extern var dplay_maxclients;
extern var dplay_bandwidth;
extern var dplay_unreliable;
extern var dplay_smooth;
extern var dplay_localfunction;
extern var dplay_compression;
extern var dplay_entupdate;
extern var dplay_pingrate;
extern var dplay_entrate;
extern var dplay_packetsize;
extern var dplay_timeout;
extern var dplay_latency;
extern var dplay_bps;
extern var dplay_bpspeak;
extern var dplay_bpsreliable;
extern var dplay_bpsunreliable;
extern var dplay_dropped;
extern var recbuf_size;
extern var dplay_diag;
extern var num_clients;
extern var dplay_encrypt;
extern var dplay_port;
extern var dplay_id;
extern var dplay_status;
extern var reserved63;


extern var sound_vol;
extern var cdaudio_vol;
extern var midi_vol;
extern var media_handle;
extern var media_layer;
extern var num_mediastreams;
extern var doppler_factor;
extern var master_vol;
extern var video_alpha;
extern var reserved64;


extern VECTOR hull_fatmin;
extern VECTOR hull_fatmax;
extern VECTOR hull_narrowmin;
extern VECTOR hull_narrowmax;

extern var max_ph_entities;
extern var collision_mode;
extern var trace_mode;
extern var move_mode;
extern var move_friction;
extern var move_restrict;
extern VECTOR normal;
extern VECTOR bounce;
extern VECTOR target;
extern VECTOR vglide;
extern var on_passable;
extern var in_passable;
extern var in_solid;
extern var tex_light;
extern COLOR tex_color;
extern var tex_fog;
extern var tex_flag1;
extern var tex_flag2;
extern var tex_flag3;
extern var tex_flag4;
extern var tex_flag5;
extern var tex_flag6;
extern var tex_flag7;
extern var tex_flag8;
extern var hitvertex;
extern var terrain_cell_size;
extern var trace_hit;
extern var num_bodies;
extern var num_contacts;
extern var ph_iterations;
extern var ph_fps_max_lock;
extern var move_min_z;
extern var disable_z_glide;
extern var ph_max_contacts;
extern var ph_check_distance;
extern var ph_num_collisions;
extern var move_pushback;
extern var shadow_meshsize;
extern var security_mode;
extern var last_skill;


extern var reserved8[14];


extern var key_bksp;
extern var key_enter;
extern var key_esc;
extern var key_alt;
extern var key_ctrl;
extern var key_shiftl;
extern var key_shiftr;
extern var key_space;
extern var key_tab;
extern var key_f1;
extern var key_f2;
extern var key_f3;
extern var key_f4;
extern var key_f5;
extern var key_f6;
extern var key_f7;
extern var key_f8;
extern var key_f9;
extern var key_f10;
extern var key_f11;
extern var key_f12;
extern var key_a;
extern var key_b;
extern var key_c;
extern var key_d;
extern var key_e;
extern var key_f;
extern var key_g;
extern var key_h;
extern var key_i;
extern var key_j;
extern var key_k;
extern var key_l;
extern var key_m;
extern var key_n;
extern var key_o;
extern var key_p;
extern var key_q;
extern var key_r;
extern var key_s;
extern var key_t;
extern var key_u;
extern var key_v;
extern var key_w;
extern var key_x;
extern var key_y;
extern var key_z;
extern var key_cuu;
extern var key_cud;
extern var key_cur;
extern var key_cul;
extern var key_pgup;
extern var key_pgdn;
extern var key_home;
extern var key_end;
extern var key_ins;
extern var key_del;
extern var key_car;
extern var key_cal;
extern var key_slash;
extern var key_equals;
extern var key_period;
extern var key_comma;
extern var key_brackl;
extern var key_brackr;
extern var key_semic;
extern var key_bksl;
extern var key_apos;
extern var key_minusc;
extern var key_grave;
extern var key_caps;
extern var key_scrlk;
extern var key_plus;
extern var key_sz;
extern var key_ae;
extern var key_ue;
extern var key_oe;
extern var key_1;
extern var key_2;
extern var key_3;
extern var key_4;
extern var key_5;
extern var key_6;
extern var key_7;
extern var key_8;
extern var key_9;
extern var key_0;
extern var key_pause;

extern var mouse_left;
extern var mouse_right;
extern var mouse_middle;

extern var joy_1;
extern var joy_2;
extern var joy_3;
extern var joy_4;
extern var joy_5;
extern var joy_6;
extern var joy_7;
extern var joy_8;
extern var joy_9;
extern var joy_10;
extern var joy_11;
extern var joy_12;

extern var joy2_1;
extern var joy2_2;
extern var joy2_3;
extern var joy2_4;
extern var joy2_5;
extern var joy2_6;
extern var joy2_7;
extern var joy2_8;
extern var joy2_9;
extern var joy2_10;
extern var joy2_11;
extern var joy2_12;

extern var reserved9[10];


extern EVENT on_bksp;
extern EVENT on_enter;
extern EVENT on_esc;
extern EVENT on_alt;
extern EVENT on_ctrl;
extern EVENT on_shiftl;
extern EVENT on_shiftr;
extern EVENT on_space;
extern EVENT on_tab;
extern EVENT on_f1;
extern EVENT on_f2;
extern EVENT on_f3;
extern EVENT on_f4;
extern EVENT on_f5;
extern EVENT on_f6;
extern EVENT on_f7;
extern EVENT on_f8;
extern EVENT on_f9;
extern EVENT on_f10;
extern EVENT on_f11;
extern EVENT on_f12;
extern EVENT on_a;
extern EVENT on_b;
extern EVENT on_c;
extern EVENT on_d;
extern EVENT on_e;
extern EVENT on_f;
extern EVENT on_g;
extern EVENT on_h;
extern EVENT on_i;
extern EVENT on_j;
extern EVENT on_k;
extern EVENT on_l;
extern EVENT on_m;
extern EVENT on_n;
extern EVENT on_o;
extern EVENT on_p;
extern EVENT on_q;
extern EVENT on_r;
extern EVENT on_s;
extern EVENT on_t;
extern EVENT on_u;
extern EVENT on_v;
extern EVENT on_w;
extern EVENT on_x;
extern EVENT on_y;
extern EVENT on_z;
extern EVENT on_cuu;
extern EVENT on_cud;
extern EVENT on_cur;
extern EVENT on_cul;
extern EVENT on_pgup;
extern EVENT on_pgdn;
extern EVENT on_home;
extern EVENT on_end;
extern EVENT on_ins;
extern EVENT on_del;
extern EVENT on_car;
extern EVENT on_cal;
extern EVENT on_slash;
extern EVENT on_equals;
extern EVENT on_period;
extern EVENT on_comma;
extern EVENT on_brackl;
extern EVENT on_brackr;
extern EVENT on_semic;
extern EVENT on_bksl;
extern EVENT on_apos;
extern EVENT on_minusc;
extern EVENT on_grave;
extern EVENT on_caps;
extern EVENT on_scrlk;
extern EVENT on_plus;
extern EVENT on_sz;
extern EVENT on_ae;
extern EVENT on_ue;
extern EVENT on_oe;
extern EVENT on_1;
extern EVENT on_2;
extern EVENT on_3;
extern EVENT on_4;
extern EVENT on_5;
extern EVENT on_6;
extern EVENT on_7;
extern EVENT on_8;
extern EVENT on_9;
extern EVENT on_0;
extern EVENT on_pause;

extern EVENT on_mouse_left;
extern EVENT on_mouse_right;
extern EVENT on_mouse_middle;

extern EVENT on_joy1;
extern EVENT on_joy2;
extern EVENT on_joy3;
extern EVENT on_joy4;
extern EVENT on_joy5;
extern EVENT on_joy6;
extern EVENT on_joy7;
extern EVENT on_joy8;
extern EVENT on_joy9;
extern EVENT on_joy10;
extern EVENT on_joy11;
extern EVENT on_joy12;

extern EVENT on_joy2_1;
extern EVENT on_joy2_2;
extern EVENT on_joy2_3;
extern EVENT on_joy2_4;
extern EVENT on_joy2_5;
extern EVENT on_joy2_6;
extern EVENT on_joy2_7;
extern EVENT on_joy2_8;
extern EVENT on_joy2_9;
extern EVENT on_joy2_10;
extern EVENT on_joy2_11;
extern EVENT on_joy2_12;

extern EVENT on_anykey;
extern EVENT on_click;
extern EVENT on_mouse_stop;

extern EVENT on_close;
extern EVENT on_load;
extern EVENT on_level;

extern EVENT on_server;
extern EVENT on_client;

extern EVENT on_d3d_lost;
extern EVENT on_d3d_reset;

extern EVENT render_sky;
extern EVENT render_world;
extern EVENT render_entities;
extern EVENT render_solid;

extern EVENT on_exit;
extern EVENT on_frame;
extern EVENT on_message;

extern EVENT on_maximize;
extern EVENT on_minimize;
extern EVENT on_resize;

extern EVENT on_level_load;
extern EVENT on_ent_remove;
extern EVENT render_layer;
extern EVENT on_reserved[10];


extern VIEW* camera;
extern VIEW* light_view;
extern VIEW* render_view;

extern ENTITY* watched;
extern ENTITY* me;
extern ENTITY* you;
extern ENTITY* sky_cube_level;
extern ENTITY* sky_dome_level;
extern ENTITY* mouse_ent;

extern BMAP* mouse_map;
extern BMAP* render_map[4];
void* render_mesh;

extern MATERIAL* mtl;
extern MATERIAL* mtl_flat;
extern MATERIAL* mtl_shaded;
extern MATERIAL* mtl_model;
extern MATERIAL* mtl_terrain;
extern MATERIAL* mtl_sprite;
extern MATERIAL* mtl_particle;
extern MATERIAL* mtl_metal;
extern MATERIAL* mtl_sky;
extern MATERIAL* mtl_shadow;
extern MATERIAL* mtl_unlit;

extern STRING* debug_str;
extern STRING* watch_str;
extern STRING* delimit_str;
extern STRING* tex_name;
extern STRING* app_name;
extern STRING* level_name;
extern STRING* player_name;
extern STRING* session_name;
extern STRING* server_name;
extern STRING* server_ip;
extern STRING* work_dir;
extern STRING* save_dir;
extern STRING* exe_dir;

extern ENTITY* player;
extern STRING* user_name;
extern ENTITY* passable_ent;
extern STRING* path_name;
extern STRING* command_str;
extern ENTITY* level_ent;
extern PANEL* mouse_panel;
extern long epunused1[1];

extern void* render_d3dmaterial;
extern void* render_d3dxeffect;
extern MATERIAL* render_material;
extern BMAP* render_target;
extern BMAP* render_stencil;
extern void* render_zbuffer;
extern BMAP* video_overlay;
extern BMAP* render_lightmap;
extern long epunused2[1];
extern CONTACT* hit;


extern float* matTexture;
extern float* matEffect;
extern float* matView;
extern float* matViewInv;
extern float* matProj;
extern float* matWorld;
extern float* matViewProj;
extern float* matProjInv;


extern long eunused1[1];
# 680 "/home/felix/gstudio8/include/avars.h"
extern EVENT on_sendpacket;
extern EVENT on_receivepacket;
extern EVENT on_scanmessage;
extern long eunused2[5];

extern BOOL isPointer;
extern void *EngineFunctions;
extern long eunused3[10];





extern void* pdi;
extern void* pdimouse;
extern void* pdikbd;
extern void* pdijoy;

extern void** pbody;
extern void* pvertexdecl;
extern void* dunused1[2];

extern void* pds;
extern void* pdsb;

extern void* pd3d;
extern void* pd3ddev;
extern HWND hWnd;
extern void* pd3dcaps;

extern long hInstance;
extern HWND hWndTarget;
extern RECT* pRectTarget;
extern char** pPaths;
extern void* pVars;
extern HWND hWndParent;
extern void* dunused2[3];
extern void* pdsbs;

extern float* mat_effect1;
extern float* mat_effect2;
extern float* mat_effect3;
extern float* mat_effect4;
extern float* mat_effect5;
extern float* mat_effect6;
extern float* mat_effect7;
extern float* mat_effect8;
# 57 "/home/felix/gstudio8/include/acknex.h" 2


void ackStructs()
{
 VECTOR* v; v->x = 0;
 COLOR* c; c->blue = 0;
 COLOR4* c4; c4->blue = 0;
 ANGLE* a; a->pan = 0;
 C_LINK* cl; cl->index = 0;
 STRING* s; s->length = 0;
 SOUND* o; o->length = 0;
 BMAP* b; b->width = 0;
 D3DVERTEX* d3dx; d3dx->x = 0;
 CONTACT* x; x->x = 0;
 MATERIAL* m; m->power = 0;
 ENTITY* e; e->x = 0;
 PARTICLE* p; p->x = 0;
 FONT* f; f->dx = 0;
 TEXT* t; t->layer = 0;
 PANEL* pa; pa->layer = 0;
 VIEW* v; v->layer = 0;
}



extern ENTITY* my;
extern ENTITY* your;

VECTOR* nullvector = { x=0; y=0; z=0; };






void reset_emask() { my->emask &= ~(1<<event_type); }
# 2 "main.c" 2
# 10 "main.c"
# 1 "/home/felix/gstudio8/include/default.c" 1
# 9 "/home/felix/gstudio8/include/default.c"
var def_dfps,def_dtps,def_dtlv,def_dtcs,def_dtac,def_dtrf,def_dsnd;
ANGLE def_cang;
var uu1,uu2;

function pX_stats(var);

VIEW* viewMap =
{
 flags = (1<<16) | (1<<19);
 layer = 1;
 roll = 270;
 tilt = -90;
 arc = 10;
};

PANEL* def_debug_pan =
{
   pos_x = 5;
 pos_y = 5;
 layer = 998;

 digits(0,2,"%4.0fx",*,1,screen_size.x);
 digits(30,2,"%.0f",*,1,screen_size.y);
   digits(0,12,"fps%5.0f",*,16,def_dfps);
   digits(0,22,"pps%5.0fk",*,0.016,def_dtps);
 digits(0,32,"x%7.0f",*,1,camera.x);
 digits(0,42,"y%7.0f",*,1,camera.y);
 digits(0,52,"z%7.0f",*,1,camera.z);
 digits(0,62,"pan%5.0f",*,1,def_cang.pan);
 digits(0,72,"til%5.0f",*,1,def_cang.tilt);
 digits(0,82,"rol%5.0f",*,1,def_cang.roll);


 digits(65,2,"ms/frame",*,0,0);
 digits(65,12,"geo%5.1f",*,1,def_dtlv);
 digits(65,22,"ent%5.1f",*,1,time_entities);
 digits(65,32,"par%5.1f",*,1,time_effects);
 digits(65,42,"drw%5.1f",*,1,time_draw);
 digits(65,52,"pan%5.1f",*,1,time_panels);
 digits(65,62,"ref%5.1f",*,1,def_dtrf);
 digits(65,72,"srv%5.1f",*,1,def_dtcs);
 digits(65,82,"fnc%5.1f",*,1,def_dtac);



 digits(130,2,"count of",*,0,0);
 digits(130,12,"ent%5.0f",*,1,num_entities);
 digits(130,22,"vis%5.0f",*,1,num_visents);
 digits(130,32,"tri%5.0fk",*,0.001,num_vistriangles);
 digits(130,42,"par%5.0f",*,1,num_particles);
 digits(130,52,"lit%5.0f",*,1,num_lights);
 digits(130,62,"snd%5.0f",*,1,def_dsnd);
 digits(130,72,"fnc%5.0f",*,1,num_actions);
 digits(130,82,"bdy%5.0f",*,1,num_bodies);

 digits(200,2,"memory MB",*,0,0);
 digits(200,12,"nex%5.0f",*,1,nexus);
 digits(200,22,"mem%5.0f",*,1,sys_memory);
 digits(200,32,"geo%5.0f",*,1,d3d_texsurfs);
 digits(200,42,"shd%5.0f",*,1,d3d_texsmaps);
 digits(200,52,"ent%5.0f",*,1,d3d_texskins);
 digits(200,62,"fre%5.0f",*,1,d3d_texfree);



 digits(270,2,"network",*,0,0);
 digits(270,12,"lat%4.0f",*,1,dplay_latency);
 digits(270,22,"bps%4.0f",*,1,dplay_bps);
 digits(270,32,"rel%4.0f",*,1,dplay_bpsreliable);
 digits(270,42,"unr%4.0f",*,1,dplay_bpsunreliable);
 digits(270,52,"com%4.0f",*,1,dplay_compression);
 digits(270,62,"num%4.0f",*,1,num_clients);
};

void def_box(var x1,var y1,var x2,var y2,VECTOR* color)
{
    draw_line(vector(x1,y1,0),0,100);
    draw_line(vector(x2,y1,0),color,100);
    draw_line(vector(x2,y2,0),color,100);
    draw_line(vector(x1,y2,0),color,100);
    draw_line(vector(x1,y1,0),color,100);
}

var def_oldmouse = 0;

void def_debug()
{
    beep();
    if(key_alt)
    {
        diag_status();
        return;
    }

 if(key_shift)
 {
        diag_status();
        freeze_mode = !freeze_mode;
        if (freeze_mode) {
            def_oldmouse = mouse_mode;
            mouse_mode = 4;
            mouse_pointer = 2;
        } else {
         mouse_mode = def_oldmouse;
        }
        while (freeze_mode) {
            if(mouse_left)
     watched = mouse_ent;
            wait(1);
        }
        return;
    }

    if (key_ctrl) {
  viewMap->flags ^= ((1<<14));
  while (viewMap->flags & ((1<<14))) {
   vec_set(&viewMap->x,&camera->x);
   viewMap->z += 10000;
   wait(1);
  }
  return;
    }

 if(d3d_lines) {
  def_debug_pan->flags &= ~((1<<14));
  d3d_lines = 0;
  diag_mode &= ~1;
    } else {
  if (def_debug_pan->flags & ((1<<14))) {
   d3d_lines = 3;
  } else {
   def_debug_pan->flags |= ((1<<14));
   diag_mode |= 1;
   while (def_debug_pan->flags & ((1<<14))) {
    def_dfps = 0.9*def_dfps+0.1/time_frame;
    def_dtps = 0.9*def_dtps+0.1*num_vistriangles/time_frame;
    def_dtlv = time_level+time_sky;
    def_dtcs = time_client+time_server;
    def_dtrf = time_update+time_idle;
    def_dtac = time_actions+time_pfuncs;
    def_dsnd = num_mediastreams + num_sounds;
    def_cang.pan = cycle(camera->pan,0,360);
    def_cang.tilt = cycle(camera->tilt,-180,180);
    def_cang.roll = cycle(camera->roll,-180,180);
    def_box(def_debug_pan->pos_x-3,def_debug_pan->pos_y-2,
                    def_debug_pan->pos_x+314,def_debug_pan->pos_y+103,
                    vector(255,255,255));


    wait(1);
   }
  }
 }
}

void def_exit()
{
 if (!key_f4 || key_alt)
  sys_exit(0);
}

var def_shot_num = 0;
void def_shot()
{
 file_for_screen("shot_",def_shot_num);
 beep();
 def_shot_num++;
}

void def_save()
{
 game_save(app_name,1,0x000FFFFF -(1<<1));
 beep();
}

void def_load()
{
 game_load(app_name,1);
}

void def_video()
{
 var mode = video_mode;
 while(1) {
  if (!key_shift)
   mode++;
  else
   mode--;
  mode = cycle(mode,6,12);
  if (video_switch(mode,0,0))
   break;
   }
}

void def_screen()
{
 if (!key_alt)
  return;
 var mode = video_screen + 1;
 if (mode > 2)
  mode = 1;
 if (video_switch(0,0,mode) == 0)
  beep();
}

var def_mvol = 50;
var def_svol = 50;
void def_sound()
{
    if (sound_vol==0) {
  sound_vol = def_svol;
  midi_vol = def_mvol;
  return;
 }
    if (midi_vol==0) {
  def_svol = sound_vol;
  sound_vol = 0;
  return;
 }
    def_mvol = midi_vol;
 midi_vol = 0;
}


var def_camera = 0;
VECTOR* def_cam_dist = { x=100; y=0; z=100; }


void def_move()
{
 VECTOR force,speed,dist;
 ANGLE aforce,aspeed;


 ((var*)&(speed))[0] = 0; ((var*)&(speed))[1] = 0; ((var*)&(speed))[2] = 0;
 ((var*)&(aspeed))[0] = 0; ((var*)&(aspeed))[1] = 0; ((var*)&(aspeed))[2] = 0;
 ((var*)&(dist))[0] = 0; ((var*)&(dist))[1] = 0; ((var*)&(dist))[2] = 0;

  if (1 > def_camera)
     def_camera = 1;
 if (1 < run_mode && run_mode < 5)
  def_camera = 2;

 while (def_camera)
 {
  aforce.tilt = 5*(key_pgup - key_pgdn + mouse_right*mouse_force.y);
  if (key_alt==0) {
      aforce.pan = -5*(key_force.x + mouse_right*mouse_force.x + joy_force.x);
      aforce.roll = 0;
  } else {
      aforce.pan = 0;
      aforce.roll = 5*(key_force.x + mouse_right*mouse_force.x + joy_force.x);
  }
  vec_add(&camera->pan,vec_accelerate(&dist,&aspeed,&aforce,0.8));

  force.x = 7*(key_force.y + key_w - key_s + joy_force.y);
  force.y = 3*(key_comma - key_period + key_a - key_d);
  force.z = 3*(key_home - key_end);
  vec_accelerate(&dist,&speed,&force,0.5);

  if (0 != player && 1 == def_camera) {
      c_move(player,&dist,nullvector,(1<<2)|(1<<3)|(1<<18));
      camera->genius = player;
      vec_set(&player->pan,&camera->pan);
      vec_set(&camera->x,def_cam_dist);
      vec_rotate(&camera->x,&camera->pan);
      vec_add(&camera->x,&player->x);
  } else {
      camera->genius = 0;
      vec_add(&camera->x,vec_rotate(&dist,&camera->pan));
  }
  wait(1);
  }
}

void def_moveset()
{
    def_camera += 1;
 if (0 != player)
  def_camera = cycle(def_camera,0,3);
 else
  def_camera = cycle(def_camera,0,2);
    if (!key_shift && def_camera > 0) {
        beep();
  def_move();
    }
}

TEXT* def_ctxt = { string("Enter var or STRING","#80"); layer = 999; }

void def_console()
{
   def_ctxt->pos_x = 2;
   def_ctxt->pos_y = screen_size.y-30;
   def_ctxt->flags ^= ((1<<14));
   while (def_ctxt->flags & ((1<<14))) {
     beep();
     inkey((def_ctxt->pstring)[1]);
  if (13 == result) {
  void* found = var_for_name((def_ctxt->pstring)[1]);
  if (!found) execute((def_ctxt->pstring)[1]);
  } else
  def_ctxt->flags &= ~((1<<14));
   }
}

TEXT* def_dtxt = {
   pos_x = 2; pos_y = 2; layer = 999;
   string = watch_str;
   flags = (1<<14);
}

void def_startup()
{
 if (!on_f2) on_f2 = def_save;
 if (!on_f3) on_f3 = def_load;
 if (!on_f5) on_f5 = def_video;
 if (!on_f4) on_f4 = def_exit;
 if (!on_f6) on_f6 = def_shot;
 if (!on_f11) on_f11 = def_debug;
 if (!on_f12) on_f12 = def_sound;

 if (!on_0) on_0 = def_moveset;
 if (!on_enter) on_enter = def_screen;
 if (!on_tab) on_tab = def_console;
 if (!on_esc) on_esc = def_exit;
 if (!on_close) on_close = def_exit;
}
# 11 "main.c" 2






# 1 "src/framework.h" 1
# 9 "src/framework.h"
void framework_init(void);


void framework_update(void);



void framework_load_level(char const * msg);




void framework_setup(ENTITY * ent, int subsystem);


void framework_freeze(ENTITY * ent);


void framework_remove(ENTITY * ent);
# 18 "main.c" 2




BMAP * shader_noise = "noise.png";
BMAP * ColorLUT = "pal.png";

function main()
{
 framework_init();
}





# 1 "src/framework.c" 1
# 1 "src/framework.h" 1
# 2 "src/framework.c" 2
# 1 "src/global.h" 1






typedef int bool;
# 3 "src/framework.c" 2
# 1 "src/ui_menu.h" 1




int uimenu_last_layer = 0;
int uimenu_window_id = 0;
FONT * uimenu_default_font = "Arial#14";
FONT * uimenu_default_font_bold = "Arial#14b";
# 66 "src/ui_menu.h"
typedef struct uimenu_element_t
{

    int type;
    var x, y;
    var width, height;
    BMAP * bmap;
    BMAP * bmap_active;
    BMAP * bmap_hover;
    void * evt_on_click;
    void * evt_on_cancel;
    void * evt_on_enter;
    void * evt_on_leave;
    void * evt_on_select;
    int element_index;
    var * var_pointer;

    var skill[10];


    struct uimenu_element_t * _next;
    struct uimenu_element_t * _related;
    void * _parent;
    void * _child;
    int _is_initialized;
    int _is_dirty;
    int _is_pressed;
    int _is_hover;

} uimenu_element_t;

typedef struct uimenu_window_t
{

    int id;
    var x, y;
    var width, height;
    int layer;
    char * title;


    PANEL * _panel;
    PANEL * _content_panel;
    uimenu_element_t * _first;
    struct uimenu_window_t * _child;
    struct uimenu_window_t * _next;
    struct uimenu_window_t * _parent;
    var _moving_start_offset[3];
    int _is_initialized;
    int _is_visible;
    int _is_borderless;
    int _is_dirty;
    int _is_moving;
    int _is_titlebar_active;
    int _title_element_index;
    int _title_element_bg_index;
    BMAP * _title_element_bg_current_bmap;
    BMAP * _title_element_bg_active_bmap;
    BMAP * _title_element_bg_inactive_bmap;
    BMAP * _content_panel_bg_bmap;
    BMAP * _forced_background;
} uimenu_window_t;

typedef struct uimenu_listitem_t
{
    char * text;
    var value;
} uimenu_listitem_t;


void uimenu_update();
void uimenu_update_chain(uimenu_window_t * window);


uimenu_window_t * uimenu_window_create(var x, var y, var width, var height, char * title);
uimenu_window_t * uimenu_window_create_borderless(var x, var y, var width, var height);
uimenu_element_t * uimenu_element_create(int type, var x, var y, var width, var height);

void uimenu_add_element_to_window(uimenu_window_t * window, uimenu_element_t * element);
void uimenu_slave_window_to_window(uimenu_window_t * master, uimenu_window_t * slave);

uimenu_element_t * uimenu_make_text(var x, var y, var width, var height, char * text, COLOR * colorBGR, FONT * font);
uimenu_element_t * uimenu_make_button(var x, var y, var width, var height, BMAP * bmap, BMAP * bmapHover, BMAP * bmapActive, void * evt_on_click);
uimenu_element_t * uimenu_make_button(var x, var y, BMAP * bmap, BMAP * bmapHover, BMAP * bmapActive, void * evt_on_click);
uimenu_element_t * uimenu_make_simple_button(var x, var y, var width, var height, char * text, FONT * font, void * evt_on_click);
uimenu_element_t * uimenu_make_simple_button(var x, var y, var height, char * text, FONT * font, void * evt_on_click);

uimenu_element_t * uimenu_make_image(var x, var y, var width, var height, BMAP * bmap);
uimenu_element_t * uimenu_make_dropdown(var x, var y, var width, var height, var * currentValue, uimenu_listitem_t * items, int numItems);

void uimenu_window_initialize(uimenu_window_t * window);
void uimenu_window_to_top(uimenu_window_t * window);
int uimenu_is_top_window(uimenu_window_t * window);

void uimenu_window_show(uimenu_window_t * window);
void uimenu_window_hide(uimenu_window_t * window);

void uimenu_window_destroy(uimenu_window_t * window);


BMAP * uimenu__make_button_graphic(int width, int height, int pressed, int tab);
BMAP * uimenu__make_field_graphic(int width, int height);
BMAP * uimenu__make_slider_bg_graphic(int width);
BMAP * uimenu__make_slider_knob_graphic(int width, int height);

VECTOR * uimenu__get_element_screen_offset(uimenu_element_t * element);
VECTOR * uimenu__get_cursor_offset_to_window(uimenu_element_t * element);
int uimenu__is_cursor_in_window_titlebar(uimenu_window_t * window);
int uimenu__is_cursor_in_window(uimenu_window_t * window);
int uimenu__is_cursor_in_element(uimenu_element_t * element);

void uimenu__window_initialize(uimenu_window_t * window);
void uimenu__element_initialize(uimenu_window_t * window, uimenu_element_t * element);
void uimenu__sync_panel_with_window(uimenu_window_t * window);
void uimenu__window_make_dirty(uimenu_window_t * window);
void uimenu__window_update(uimenu_window_t * window);
void uimenu__element_update(uimenu_element_t * element);

uimenu_window_t * uimenu__first_window = 0;
uimenu_window_t * uimenu__top_window = 0;
# 4 "src/framework.c" 2
# 1 "src/mainmenu.h" 1





int mainmenu_current_response = 0;
var mainmenu_buzz_wait_time = 2;
var mainmenu_buzz_handle;

uimenu_window_t * mainmenu_wndMenuBackground;
uimenu_window_t * mainmenu_wndMenuBackgroundBright;
uimenu_window_t * mainmenu_wndMenuMain;
uimenu_element_t * mainmenu_btnNewGame;
uimenu_element_t * mainmenu_btnOptions;
uimenu_element_t * mainmenu_btnCredits;
uimenu_element_t * mainmenu_btnExit;
uimenu_window_t * mainmenu_wndMenuOptions;
uimenu_window_t * mainmenu_wndMenuOptionsGeneral;
uimenu_window_t * mainmenu_wndMenuOptionsVideo;
uimenu_window_t * mainmenu_wndMenuOptionsAudio;
uimenu_window_t * mainmenu_wndMenuOptionsControls;

SOUND *mainmenu_buzz = "bzzt.wav";

BMAP * mainmenu_btn_new_game = "NewGame.png";
BMAP * mainmenu_btn_options = "Options.png";
BMAP * mainmenu_btn_credits = "Credits.png";
BMAP * mainmenu_btn_exit = "exit.png";

BMAP * mainmenu_background_bright = "MenueBackground_fc.png";
BMAP * mainmenu_background = "MenueBackground_fc2.png";






void mainmenu_init(void);
void mainmenu_open(void);
void mainmenu_update(void);
void mainmenu_resolution_update(void);
void mainmenu_close(void);

void mainmenu_set_start(void);
void mainmenu_show_options(void);
void mainmenu_show_options_general(void);
void mainmenu_show_options_video(void);
void mainmenu_show_options_audio(void);
void mainmenu_show_options_controls(void);
void mainmenu_hide_options(void);
void mainmenu_set_credits(void);
void mainmenu_set_exit(void);

void mainmenu_add_item();


int mainmenu_get_response(void);
# 5 "src/framework.c" 2
# 1 "src/game.h" 1







void game_init(void);

void game_open(void);
void game_update(void);
void game_close(void);

bool game_is_done(void);
# 6 "src/framework.c" 2
# 1 "src/credits.h" 1
# 17 "src/credits.h"
void credits_init();
void credits_open();
void credits_close();
void credits_update();
var credits_isdone();
# 7 "src/framework.c" 2
# 1 "src/music_player.h" 1






void music_init();




void music_start(STRING* file, var crossFadeTime, var loop);


void music_speedup(var speed);


void music_stop();


var music_is_playing();


var music_get_position();


var music_get_time();


void music_update();


void music_set_master_volume(var vol);
# 8 "src/framework.c" 2
# 1 "src/jps.h" 1
# 16 "src/jps.h"
 int jpsExtraWidth = 0;



 struct _LIST
 {
  void* data;
  struct _LIST *next;
 };
 typedef struct _LIST LIST;






 struct _TILE
 {
  int pos[2];
  int value;
  int value2;
  int flags;
  int visibility;

  int jpsType;
  int numNeighbors;
  LIST *neighborList;
  int *neighborCost;
  int targetCost;
  int targetReachable;
  int currentCost;
  int totalCost;
  LIST *unitList;
  int numUnits[2];
  void *unitArray[16];
  struct _TILE *prev;
 };
 typedef struct _TILE TILE;

 struct _JPSPATH
 {
  int length, maxLength, currentNode;
  TILE** tiles;
  TILE* startTile;
  TILE* targetTile;
 };
 typedef struct _JPSPATH JPSPATH;



 struct _UNIT_PRESET
 {
  int ID;
  char file[32];
  float maxSpeed;
  int maxHP;
  var radius;
 };
 typedef struct _UNIT_PRESET UNIT_PRESET;
 UNIT_PRESET unitPresets[5];


 struct _UNIT
 {
  int presetID;
  int playerID;
  int isActive;
  int isMoving;
  int allowMovement;
  int HP;
  int speed;
  VECTOR pos2d, pos3d, prevPos3d;
  VECTOR target2d, prevTarget2d, currentTarget2d;
  ENTITY* ent;
  TILE* tile;
  TILE* prevTile;
  TILE* targetTile;
  JPSPATH *jpsPath;
  struct _UNIT *next;
 };
 typedef struct _UNIT UNIT;

 struct _PROJECTILE_PRESET
 {
  int ID;
  int damage;
  int range;

 };
 typedef struct _PROJECTILE_PRESET PROJECTILE_PRESET;

 struct _PROJECTILE
 {
  int presetID;
  int playerID;
  int isActive;
  int lifetime;
  VECTOR pos2d, pos3d;
  struct _PROJECTILE *next;
 };
 typedef struct _PROJECTILE PROJECTILE;

 struct _MAP
 {
  int size[2];
  TILE* tiles;
  BMAP* bmp;
  LIST* JPSTileList;
  JPSPATH *jpsPath;

  VECTOR vMin, vMax, vSize;
  var tileSize;
  UNIT *unitFirst[2];
  PROJECTILE *projectileFirst[2];
 };
 typedef struct _MAP MAP;
 MAP* mapCurrent = 0;

 ENTITY* entJPSDummyPlane = 0;


# 1 "src/console.h" 1




# 1 "/home/felix/gstudio8/include/windows.h" 1
# 6462 "/home/felix/gstudio8/include/windows.h"
typedef struct RECTL{
 long Left;
 long Top;
 long Right;
 long Bottom;
}RECTL;

typedef struct POINTAPI{
 long x;
 long y;
}POINTAPI;
typedef struct POINT{
 long x;
 long y;
}POINT;
typedef struct _POINTL{
 long x;
 long y;
}POINTL;

typedef struct SIZE{
 long cx;
 long cy;
}SIZE;

typedef struct POINTS{
 int x ;
 int y ;
}POINTS;

typedef struct _MSG{
 long hwnd;
 long message;
 long wParam;
 long lParam;
 long time;
 POINTAPI pt;
}MSG;

typedef struct _WNDCLASSEX{
 long cbSize;
 long style;
 long lpfnWndProc;
 long cbClsExtra;
 long cbWndExtra;
 long hInstance;
 long hIcon;
 long hCursor;
 long hbrBackground;
 char* lpszMenuName;
 char* lpszClassName;
 long hIconSm;
}WNDCLASSEX;

typedef struct _PAINTSTRUCT{
 long hdc;
 long fErase;
 RECT rcPaint;
 long fRestore;
 long fIncUpdate;
 char rgbReserved[32];
}PAINTSTRUCT;

typedef struct _OPENFILENAME{
 long lStructSize;
 long hwndOwner;
 long hInstance;
 char* lpstrFilter;
 char* lpstrCustomFilter;
 long nMaxCustFilter;
 long nFilterIndex;
 char* lpstrFile;
 long nMaxFile;
 char* lpstrFileTitle;
 long nMaxFileTitle;
 char* lpstrInitialDir;
 char* lpstrTitle;
 long Flags;
 short nFileOffset;
 short nFileExtension;
 char* lpstrDefExt;
 long lCustData;
 long lpfnHook;
 char* lpTemplateName;
}OPENFILENAME;

typedef struct _ULARGE_INTEGER
{
 DWORD LowPart;
 DWORD HighPart;
}ULARGE_INTEGER;

typedef struct _GUID
{
    long Data1;
    short Data2;
    short Data3;
    char Data4[8];
} GUID;

typedef struct _IID
{
    long Data1;
    short Data2;
    short Data3;
    char Data4[8];
} IID;

typedef struct _WNDCLASS
{
    long style;
    long lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    long hInstance;
    long hIcon;
    long hCursor;
    long hbrBackground;
    char* lpszMenuName;
    char* lpszClassName;
} WNDCLASS;

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;


typedef struct _WIN32_FIND_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    char* cFileName[260];
    char* cAlternateFileName[14];
} WIN32_FIND_DATA;






VOID __stdcall CopyMemory(long Destination,long Source,DWORD Length);
VOID __stdcall FillMemory(long Destination,DWORD Length,char Fill);
VOID __stdcall ZeroMemory(long Destination,DWORD Length);





DWORD __stdcall GetOpenFileName(DWORD);
DWORD __stdcall GetSaveFileName(DWORD);

API(GetOpenFileName,comdlg32)
API(GetSaveFileName,comdlg32)

long __stdcall LoadKeyboardLayout(long pwszKLID,long Flags);
long __stdcall ActivateKeyboardLayout(long hkl,long Flags);
long __stdcall ActivateKeyboardLayout(long hkl,long Flags);

long __stdcall UnloadKeyboardLayout(long hkl);
long __stdcall GetKeyboardLayoutName(long pwszKLID);
long __stdcall GetKeyboardLayoutList(long nBuff,long lpList);
long __stdcall GetKeyboardLayout(long dwLayout);

APIA(LoadKeyboardLayout,user32)
API(ActivateKeyboardLayout,user32)
API(UnloadKeyboardLayout,user32)
APIA(GetKeyboardLayoutName,user32)

long __stdcall ToUnicodeEx(long wVirtKey,long wScanCode,long lpKeyState,long pwszBuff,long cchBuff,long wFlags,long dwhkl);

API(ToUnicodeEx,user32)

long __stdcall CreateDesktop(long lpszDesktop,long lpszDevice,long pDevmode,long dwFlags,long dwDesiredAccess,long lpsa);
long __stdcall OpenDesktop(long lpszDesktop,long dwFlags,long fInherit,long dwDesiredAccess);
long __stdcall OpenInputDesktop(long dwFlags,long fInherit,long dwDesiredAccess);
long __stdcall CloseDesktop(long hDesktop);
long __stdcall EnumDesktops(long hwinsta,long lpEnumFunc,long lParam);
long __stdcall EnumDesktopWindows(long hDesktop,long lpfn,long lParam);
long __stdcall SwitchDesktop(long hDesktop);
long __stdcall SetThreadDesktop(long hDesktop);
long __stdcall GetThreadDesktop(long dwThreadId);

APIA(CreateDesktop,user32)
APIA(OpenDesktop,user32)
API(OpenInputDesktop,user32)
API(CloseDesktop,user32)
APIA(EnumDesktops,user32)
API(EnumDesktopWindows,user32)
API(SwitchDesktop,user32)
API(SetThreadDesktop,user32)
API(GetThreadDesktop,user32)

long __stdcall CreateWindowStation(long lpwinsta,long dwReserved,long dwDesiredAccess,long lpsa);
long __stdcall OpenWindowStation(long lpszWinSta,long fInherit,long dwDesiredAccess);
long __stdcall EnumWindowStations(long lpEnumFunc,long lParam);
long __stdcall CloseWindowStation(long hWinSta);
long __stdcall SetProcessWindowStation(long hWinSta);
long __stdcall GetProcessWindowStation(long);

APIA(CreateWindowStation,user32)
APIA(OpenWindowStation,user32)
API(CloseWindowStation,user32)
API(GetProcessWindowStation,user32)
API(SetProcessWindowStation,user32)

long __stdcall SetUserObjectSecurity(long hObj,long pSIRequested,long pSID);
long __stdcall GetUserObjectSecurity(long hObj,long pSIRequested,long pSID,long nLength,long lpnLengthNeeded);
long __stdcall GetUserObjectInformation(long hObj,long nIndex,long pvInfo,long nLength,long lpnLengthNeeded);
long __stdcall SetUserObjectInformation(long hObj,long nIndex,long pvInfo,long nLength);

API(SetUserObjectSecurity,user32)
API(GetUserObjectSecurity,user32)
APIA(GetUserObjectInformation,user32)
APIA(SetUserObjectInformation,user32)

long __stdcall TrackMouseEvent(long lpEventTrack);
API(TrackMouseEvent,user32)

long __stdcall DrawEdge(long hdc,long qrc,long edge,long grfFlags);
long __stdcall DrawFrameControl(long,long,long,long);
long __stdcall DrawCaption(long,long,long ,long);
long __stdcall DrawAnimatedRects(long hwnd,long idAni,long lprcFrom,long lprcTo);

API(DrawEdge,user32)
API(DrawFrameControl,user32)
API(DrawCaption,user32)
API(DrawAnimatedRects,user32)

long __stdcall GetMessage(long lpMsg,long hWnd,long wMsgFilterMin,long wMsgFilterMax);
long __stdcall RegisterWindowMessage(long lpString);
long __stdcall TranslateMessage(long lpMsg);
long __stdcall DispatchMessage(long lpMsg);
long __stdcall SetMessageQueue(long cMessagesMax);
long __stdcall PeekMessage(long lpMsg,long hWnd,long wMsgFilterMin,long wMsgFilterMax,long wRemoveMsg);
long __stdcall GetMessagePos(long);
long __stdcall GetMessageTime(long);
long __stdcall GetMessageExtraInfo(long);
long __stdcall SetMessageExtraInfo(long lParam);
long __stdcall SendMessage(long hWnd,long Msg,long wParam,long lParam);
long __stdcall SendMessageTimeout(long hWnd,long Msg,long wParam,long lParam,long fuFlags,long uTimeout,long lpdwResult);
long __stdcall SendNotifyMessage(long hWnd,long Msg,long wParam,long lParam);
long __stdcall SendMessageCallback(long hWnd,long Msg,long wParam,long lParam,long lpResultCallBack,long dwData);
long __stdcall BroadcastSystemMessage(long,long,long,long,long);
long __stdcall PostMessage(long hWnd,long Msg,long wParam,long lParam);
long __stdcall PostThreadMessage(long idThread,long Msg,long wParam,long lParam);
long __stdcall ReplyMessage(long lResult);
long __stdcall WaitMessage(void);
VOID __stdcall PostQuitMessage(long nExitCode);
long __stdcall InSendMessage(long);
long __stdcall InSendMessageEx(long lpReserved);

APIA(GetMessage,user32)
APIA(RegisterWindowMessage,user32)
API(TranslateMessage,user32)
APIA(DispatchMessage,user32)
APIA(PeekMessage,user32)
API(GetMessagePos,user32)
API(GetMessageTime,user32)
API(GetMessageExtraInfo,user32)
APIA(SendMessage,user32)
APIA(SendMessageTimeout,user32)
APIA(SendNotifyMessage,user32)
APIA(SendMessageCallback,user32)
APIA(PostMessage,user32)
APIA(PostThreadMessage,user32)
API(ReplyMessage,user32)
API(WaitMessage,user32)
API(PostQuitMessage,user32)
API(InSendMessage,user32)
API(InSendMessageEx,user32)

long __stdcall RegisterHotKey(long hWnd,long id,long fsModifiers,long vk);
long __stdcall UnregisterHotKey(long hWnd,long id);

long __stdcall ExitWindowsEx(long uFlags,long dwReserved);
long __stdcall SwapMouseButton(long fSwap);


long __stdcall AttachThreadInput(long idAttach,long idAttachTo,long fAttach);
long __stdcall WaitForInputIdle(long hProcess,long dwMilliseconds);
long __stdcall DefWindowProc(long hWnd,long Msg,long wParam,long lParam);
long __stdcall CallWindowProc(long lpPrevWndFunc,long hWnd,long Msg,long wParam,long lParam);
long __stdcall CallWindowProc(long lpPrevWndFunc,long hWnd,long Msg,long wParam,long lParam);
long __stdcall GetDoubleClickTime(void);
long __stdcall SetDoubleClickTime(long);
long __stdcall RegisterClass(long lpWndClass);
long __stdcall UnregisterClass(long lpClassName,long hInstance);
long __stdcall GetClassInfo(long hInstance,long lpClassName,long lpWndClass);
long __stdcall RegisterClassEx(long);
long __stdcall GetClassInfoEx(long,long,long);
long __stdcall CreateWindowEx(long dwExStyle,long lpClassName,long lpWindowName,long dwStyle,long X,long Y,long nWidth,long nHeight,long hWndParent,long hMenu,long hInstance,long lpParam);
long __stdcall IsWindow(long hWnd);
long __stdcall IsMenu(long hMenu);
long __stdcall IsChild(long hWndParent,long hWnd);
long __stdcall DestroyWindow(long hWnd);
long __stdcall ShowWindow(long hWnd,long nCmdShow);
long __stdcall AnimateWindow(long hWnd,long dwTime,long dwFlags);
long __stdcall ShowWindowAsync(long hWnd,long nCmdShow);
long __stdcall FlashWindow(long hWnd,long bInvert);
long __stdcall ShowOwnedPopups(long hWnd,long fShow);
long __stdcall OpenIcon(long hWnd);
long __stdcall CloseWindow(long hWnd);
long __stdcall MoveWindow(long hWnd,long X,long Y,long nWidth,long nHeight,long bRepaint);
long __stdcall SetWindowPos(long hWnd,long hWndInsertAfter,long X,long Y,long cx,long cy,long uFlags);
long __stdcall GetWindowPlacement(long hWnd,long lpwndpl);
long __stdcall SetWindowPlacement(long hWnd,long lpwndpl);
long __stdcall BeginDeferWindowPos(long nNumWindows);
long __stdcall DeferWindowPos(long hWinPosInfo,long hWnd,long hWndInsertAfter,long x,long y,long cx,long cy,long uFlags);
long __stdcall EndDeferWindowPos(long hWinPosInfo);
long __stdcall IsWindowVisible(long hWnd);
long __stdcall IsIconic(long hWnd);
long __stdcall AnyPopup(long);
long __stdcall BringWindowToTop(long hWnd);
long __stdcall IsZoomed(long hWnd);
long __stdcall CreateDialogParam(long hInstance,long lpTemplateName,long hWndParent,long lpDialogFunc,long dwInitParam);
long __stdcall CreateDialogIndirectParam(long hInstance,long lpTemplate,long hWndParent,long lpDialogFunc,long dwInitParam);
long __stdcall DialogBoxParam(long hInstance,long lpTemplateName,long hWndParent,long lpDialogFunc,long dwInitParam);
long __stdcall DialogBoxIndirectParam(long hInstance,long hDialogTemplate,long hWndParent,long lpDialogFunc,long dwInitParam);
long __stdcall EndDialog(long hDlg,long nResult);
long __stdcall GetDlgItem(long hDlg,long nIDDlgItem);
long __stdcall SetDlgItemInt(long hDlg,long nIDDlgItem,long uValue,long bSigned);
long __stdcall GetDlgItemInt(long hDlg,long nIDDlgItem,long lpTranslated,long bSigned);
long __stdcall SetDlgItemText(long hDlg,long nIDDlgItem,long lpString);
long __stdcall GetDlgItemText(long hDlg,long nIDDlgItem,long lpString,long nMaxCount);
long __stdcall CheckDlgButton(long hDlg,long nIDButton,long uCheck);
long __stdcall CheckRadioButton(long hDlg,long nIDFirstButton,long nIDLastButton,long nIDCheckButton);
long __stdcall IsDlgButtonChecked(long hDlg,long nIDButton);
long __stdcall SendDlgItemMessage(long hDlg,long nIDDlgItem,long Msg,long wParam,long lParam);
long __stdcall GetNextDlgGroupItem(long hDlg,long hCtl,long bPrevious);
long __stdcall GetNextDlgTabItem(long hDlg,long hCtl,long bPrevious);
long __stdcall GetDlgCtrlID(long hWnd);
long __stdcall GetDialogBaseUnits(long);
long __stdcall DefDlgProc(long hDlg,long Msg,long wParam,long lParam);
long __stdcall CallMsgFilter(long lpMsg,long nCode);

API(AnimateWindow,user32)
API(CheckDlgButton,user32)
API(CheckRadioButton,user32)
APIA(DialogBoxParam,user32)
API(RegisterHotKey,user32)
API(UnregisterHotKey,user32)
API(ExitWindows,user32)
API(ExitWindowsEx,user32)
API(SwapMouseButton,user32)
API(AttachThreadInput,user32)
API(WaitForInputIdle,user32)
APIA(DefWindowProc,user32)
API(GetDoubleClickTime,user32)
API(SetDoubleClickTime,user32)
APIA(RegisterClass,user32)
APIA(UnregisterClass,user32)
APIA(GetClassInfo,user32)
APIA(GetClassInfoEx,user32)
APIA(CreateWindowEx,user32)
API(IsWindow,user32)
API(IsMenu,user32)
API(IsChild,user32)
API(DestroyWindow,user32)
API(ShowWindow,user32)
API(FlashWindow,user32)
API(ShowOwnedPopups,user32)
API(OpenIcon,user32)
API(CloseWindow,user32)
API(MoveWindow,user32)
API(SetWindowPos,user32)
API(GetWindowPlacement,user32)
API(SetWindowPlacement,user32)
API(BeginDeferWindowPos,user32)
API(DeferWindowPos,user32)
API(EndDeferWindowPos,user32)
API(IsWindowVisible,user32)
API(IsIconic,user32)
API(AnyPopup,user32)
API(BringWindowToTop,user32)
API(IsZoomed,user32)
API(EndDialog,user32)
API(GetDlgItem,user32)
API(SetDlgItemInt,user32)
API(GetDlgItemInt,user32)
APIA(SetDlgItemText,user32)
APIA(GetDlgItemText,user32)
API(IsDlgButtonChecked,user32)
APIA(SendDlgItemMessage,user32)
API(GetNextDlgGroupItem,user32)
API(GetNextDlgTabItem,user32)
API(GetDlgCtrlID,user32)
API(GetDialogBaseUnits,user32)
APIA(DefDlgProc,user32)
APIA(CallMsgFilter,user32)

long __stdcall OpenClipboard(long hWndNewOwner);
long __stdcall CloseClipboard();
long __stdcall GetClipboardSequenceNumber();
long __stdcall GetClipboardOwner();
long __stdcall SetClipboardViewer(long hWndNewViewer);
long __stdcall GetClipboardViewer();
long __stdcall ChangeClipboardChain(long hWndRemove,long hWndNewNext);
long __stdcall SetClipboardData(long uFormat,long hMem);
long __stdcall GetClipboardData(long uFormat);
long __stdcall RegisterClipboardFormat(long lpszFormat);
long __stdcall CountClipboardFormats();
long __stdcall EnumClipboardFormats(long format);
long __stdcall GetClipboardFormatName(long format,long lpszFormatName,long cchMaxCount);
long __stdcall EmptyClipboard();
long __stdcall IsClipboardFormatAvailable(long format);
long __stdcall GetPriorityClipboardFormat(long paFormatPriorityList,long cFormats);
long __stdcall GetOpenClipboardWindow();

API(OpenClipboard,user32)
API(CloseClipboard,user32)
API(GetClipboardOwner,user32)
API(SetClipboardViewer,user32)
API(GetClipboardViewer,user32)
API(ChangeClipboardChain,user32)
API(SetClipboardData,user32)
API(GetClipboardData,user32)
APIA(RegisterClipboardFormat,user32)
API(CountClipboardFormats,user32)
API(EnumClipboardFormats,user32)
APIA(GetClipboardFormatName,user32)
API(EmptyClipboard,user32)
API(IsClipboardFormatAvailable,user32)
API(GetPriorityClipboardFormat,user32)
API(GetOpenClipboardWindow,user32)
API(GetClipboardSequenceNumber,user32)

long __stdcall CharToOem(long lpszSrc,long lpszDst);
long __stdcall OemToChar(long lpszSrc,long lpszDst);
long __stdcall CharToOemBuff(long lpszSrc,long lpszDst,long cchDstLength);
long __stdcall OemToCharBuff(long lpszSrc,long lpszDst,long cchDstLength);
long __stdcall CharUpper(long lpsz);
long __stdcall CharUpperBuff(long lpsz,long cchLength);
long __stdcall CharLower(long lpsz);
long __stdcall CharLowerBuff(long lpsz,long cchLength);
long __stdcall CharNext(long lpsz);
long __stdcall CharPrev(long lpszStart,long lpszCurrent);


long __stdcall IsCharAlpha(long ch);
long __stdcall IsCharAlphaNumeric(long ch);
long __stdcall IsCharUpper(long ch);
long __stdcall IsCharLower(long ch);

APIA(CharToOem,user32)
APIA(OemToChar,user32)
APIA(CharToOemBuff,user32)
APIA(OemToCharBuff,user32)
APIA(CharUpper,user32)
APIA(CharUpperBuff,user32)
APIA(CharLower,user32)
APIA(CharLowerBuff,user32)
APIA(CharNext,user32)
APIA(CharPrev,user32)
APIA(IsCharAlpha,user32)
APIA(IsCharAlphaNumeric,user32)
APIA(IsCharUpper,user32)
APIA(IsCharLower,user32)

long __stdcall SetFocus(long hWnd);
long __stdcall GetActiveWindow(void);
long __stdcall GetFocus(void);

long __stdcall GetKBCodePage(long);
long __stdcall GetKeyState(long nVirtKey);
long __stdcall GetAsyncKeyState(long vKey);
long __stdcall GetKeyboardState(long lpKeyState);
long __stdcall SetKeyboardState(long lpKeyState);
long __stdcall GetKeyNameText(long lParam,long lpString,long nSize);
long __stdcall GetKeyboardType(long nTypeFlag);
long __stdcall ToAscii(long uVirtKey,long uScanCode,long lpKeyState,long lpChar,long uFlags);
long __stdcall ToAsciiEx(long uVirtKey,long uScanCode,long lpKeyState,long lpChar,long uFlags,long dwhkl);
long __stdcall ToUnicode(long wVirtKey,long wScanCode,long lpKeyState,long pwszBuff,long cchBuff,long wFlags);
long __stdcall OemKeyScan(long wOemChar);
long __stdcall VkKeyScan(long ch);
long __stdcall VkKeyScanEx(long ch,long dwhkl);
VOID __stdcall keybd_event(long bVk,long bScan,long dwFlags,long dwExtraInfo);
VOID __stdcall mouse_event(long dwFlags,long dx,long dy,long dwData,long dwExtraInfo);

long __stdcall GetLastInputInfo(long plii);
long __stdcall MapVirtualKey(long uCode,long uMapType);
long __stdcall MapVirtualKeyEx(long uCode,long uMapType,long dwhkl);
long __stdcall GetInputState(long);
long __stdcall GetQueueStatus(long flags);
long __stdcall GetCapture(long);
long __stdcall SetCapture(long hWnd);
long __stdcall ReleaseCapture(void);
long __stdcall MsgWaitForMultipleObjects(long nCount,long pHandles,long fWaitAll,long dwMilliseconds,long dwWakeMask);
long __stdcall MsgWaitForMultipleObjectsEx(long nCount,long pHandles,long dwMilliseconds,long dwWakeMask,long dwFlags);
long __stdcall SetTimer(long hWnd,long nIDEvent,long uElapse,long lpTimerFunc);
long __stdcall KillTimer(long hWnd,long uIDEvent);
long __stdcall IsWindowUnicode(long hWnd);
long __stdcall EnableWindow(long hWnd,long bEnable);
long __stdcall IsWindowEnabled(long hWnd);
long __stdcall LoadAccelerators(long hInstance,long lpTableName);
long __stdcall CreateAcceleratorTable(long,long);
long __stdcall DestroyAcceleratorTable(long hAccel);
long __stdcall CopyAcceleratorTable(long hAccelSrc,long lpAccelDst,long cAccelEntries);
long __stdcall TranslateAccelerator(long hWnd,long hAccTable,long lpMsg);
long __stdcall GetSystemMetrics(long nIndex);
long __stdcall LoadMenu(long hInstance,long lpMenuName);
long __stdcall LoadMenuIndirect(long lpMenuTemplate);
long __stdcall GetMenu(long hWnd);
long __stdcall SetMenu(long hWnd,long hMenu);
long __stdcall ChangeMenu(long hMenu,long cmd,long lpszNewItem,long cmdInsert,long flags);
long __stdcall HiliteMenuItem(long hWnd,long hMenu,long uIDHiliteItem,long uHilite);
long __stdcall GetMenuString(long hMenu,long uIDItem,long lpString,long nMaxCount,long uFlag);
long __stdcall GetMenuState(long hMenu,long uId,long uFlags);
long __stdcall DrawMenuBar(long hWnd);
long __stdcall GetSystemMenu(long hWnd,long bRevert);
long __stdcall CreateMenu(void);
long __stdcall CreatePopupMenu(void);
long __stdcall DestroyMenu(long hMenu);
long __stdcall CheckMenuItem(long hMenu,long uIDCheckItem,long uCheck);
long __stdcall EnableMenuItem(long hMenu,long uIDEnableItem,long uEnable);
long __stdcall GetSubMenu(long hMenu,long nPos);
long __stdcall GetMenuItemID(long hMenu,long nPos);
long __stdcall GetMenuItemCount(long hMenu);
long __stdcall InsertMenu(long hMenu,long uPosition,long uFlags,long uIDNewItem,long lpNewItem);
long __stdcall AppendMenu(long hMenu,long uFlags,long uIDNewItem,long lpNewItem);
long __stdcall ModifyMenu(long hMnu,long uPosition,long uFlags,long uIDNewItem,long lpNewItem);
long __stdcall RemoveMenu(long hMenu,long uPosition,long uFlags);
long __stdcall DeleteMenu(long hMenu,long uPosition,long uFlags);
long __stdcall SetMenuItemBitmaps(long hMenu,long uPosition,long uFlags,long hBitmapUnchecked,long hBitmapChecked);
long __stdcall GetMenuCheckMarkDimensions(long);
long __stdcall TrackPopupMenu(long hMenu,long uFlags,long x,long y,long nReserved,long hWnd,long prcRect);
long __stdcall TrackPopupMenuEx(long,long,long,long,long,long);
long __stdcall GetMenuInfo(long,long);
long __stdcall SetMenuInfo(long,long);
long __stdcall EndMenu(void);
long __stdcall InsertMenuItem(long,long,long,long);
long __stdcall GetMenuItemInfo(long,long,long,long);
long __stdcall SetMenuItemInfo(long,long,long,long);
long __stdcall GetMenuDefaultItem(long hMenu,long fByPos,long gmdiFlags);
long __stdcall SetMenuDefaultItem(long hMenu,long uItem,long fByPos);
long __stdcall GetMenuItemRect(long hWnd,long hMenu,long uItem,long lprcItem);
long __stdcall MenuItemFromPoint(long hWnd,long hMenu,long ptScreen);
long __stdcall DragObject(long,long,long,long,long);
long __stdcall DragDetect(long,long);
long __stdcall DrawIcon(long hDC,long X,long Y,long hIcon);
long __stdcall DrawText(long hDC,long lpString,long nCount,long lpRect,long uFormat);
long __stdcall DrawTextEx(long,long,long,long,long,long);
long __stdcall GrayString(long hDC,long hBrush,long lpOutputFunc,long lpData,long nCount,long X,long Y,long nWidth,long nHeight);
long __stdcall DrawState(long,long,long,long,long,long,long,long,long,long);
long __stdcall TabbedTextOut(long hDC,long X,long Y,long lpString,long nCount,long nTabPositions,long lpnTabStopPositions,long nTabOrigin);
long __stdcall GetTabbedTextExtent(long hDC,long lpString,long nCount,long nTabPositions,long lpnTabStopPositions);
long __stdcall UpdateWindow(long hWnd);
long __stdcall SetActiveWindow(long hWnd);
long __stdcall GetForegroundWindow(void);
long __stdcall PaintDesktop(long hdc);
long __stdcall SetForegroundWindow(long hWnd);
long __stdcall WindowFromDC(long hDC);
long __stdcall GetDC(long hWnd);
long __stdcall GetDCEx(long hWnd,long hrgnClip,long flags);

long __stdcall GetWindowDC(long hWnd);
long __stdcall ReleaseDC(long hWnd,long hDC);
long __stdcall BeginPaint(long hWnd,long lpPaint);
long __stdcall EndPaint(long hWnd,long lpPaint);
long __stdcall GetUpdateRect(long hWnd,long lpRect,long bErase);
long __stdcall GetUpdateRgn(long hWnd,long hRgn,long bErase);
long __stdcall SetWindowRgn(long hWnd,long hRgn,long bRedraw);
long __stdcall GetWindowRgn(long hWnd,long hRgn);
long __stdcall ExcludeUpdateRgn(long hDC,long hWnd);
long __stdcall InvalidateRect(long hWnd,long lpRect,long bErase);
long __stdcall ValidateRect(long hWnd,long lpRect);
long __stdcall InvalidateRgn(long hWnd,long hRgn,long bErase);
long __stdcall ValidateRgn(long hWnd,long hRgn);
long __stdcall RedrawWindow(long hWnd,long lprcUpdate,long hrgnUpdate,long flags);
long __stdcall LockWindowUpdate(long hWndLock);
long __stdcall ScrollWindow(long hWnd,long XAmount,long YAmount,long lpRect,long lpClipRect);
long __stdcall ScrollDC(long hDC,long dx,long dy,long lprcScroll,long lprcClip,long hrgnUpdate,long lprcUpdate);
long __stdcall ScrollWindowEx(long hWnd,long dx,long dy,long prcScroll,long prcClip,long hrgnUpdate,long prcUpdate,long flags);
long __stdcall SetScrollPos(long hWnd,long nBar,long nPos,long bRedraw);
long __stdcall GetScrollPos(long hWnd,long nBar);
long __stdcall SetScrollRange(long hWnd,long nBar,long nMinPos,long nMaxPos,long bRedraw);
long __stdcall GetScrollRange(long hWnd,long nBar,long lpMinPos,long lpMaxPos);
long __stdcall ShowScrollBar(long hWnd,long wBar,long bShow);
long __stdcall EnableScrollBar(long hWnd,long wSBflags,long wArrows);
long __stdcall SetProp(long hWnd,long lpString,long hData);
long __stdcall GetProp(long hWnd,long lpString);
long __stdcall RemoveProp(long hWnd,long lpString);
long __stdcall EnumPropsEx(long hWnd,long lpEnumFunc,long lParam);
long __stdcall EnumProps(long hWnd,long lpEnumFunc);
long __stdcall SetWindowText(long hWnd,long lpString);
long __stdcall GetWindowText(long hWnd,long lpString,long nMaxCount);
long __stdcall GetWindowTextLength(long hWnd);
long __stdcall GetClientRect(long hWnd,long lpRect);
long __stdcall GetWindowRect(long hWnd,long lpRect);
long __stdcall AdjustWindowRect(long lpRect,long dwStyle,long bMenu);
long __stdcall AdjustWindowRectEx(long lpRect,long dwStyle,long bMenu,long dwExStyle);
long __stdcall SetWindowContextHelpId(long,long);
long __stdcall GetWindowContextHelpId(long);
long __stdcall SetMenuContextHelpId(long,long);
long __stdcall GetMenuContextHelpId(long);
long __stdcall MessageBox(long hWnd,long lpText,long lpCaption,long uType);
long __stdcall MessageBoxEx(long hWnd,long lpText,long lpCaption,long uType,long wLanguageId);
long __stdcall MessageBoxIndirect(long);
long __stdcall MessageBeep(long uType);
long __stdcall ShowCursor(long bShow);
long __stdcall SetCursorPos(long X,long Y);
long __stdcall SetCursor(long hCursor);
long __stdcall GetCursorPos(long lpPoint);
long __stdcall ClipCursor(long lpRect);
long __stdcall GetClipCursor(long lpRect);
long __stdcall GetCursor(long);
long __stdcall CreateCaret(long hWnd,long hBitmap,long nWidth,long nHeight);
long __stdcall GetCaretBlinkTime(long);
long __stdcall SetCaretBlinkTime(long uMSeconds);
long __stdcall DestroyCaret(long);
long __stdcall HideCaret(long hWnd);
long __stdcall ShowCaret(long hWnd);
long __stdcall SetCaretPos(long X,long Y);
long __stdcall GetCaretPos(long lpPoint);
long __stdcall ClientToScreen(long hWnd,long lpPoint);
long __stdcall ScreenToClient(long hWnd,long lpPoint);
long __stdcall MapWindowPoints(long hWndFrom,long hWndTo,long lpPoints,long cPoints);
long __stdcall WindowFromPoint(long Point);
long __stdcall ChildWindowFromPoint(long hWndParent,long Point);
long __stdcall ChildWindowFromPointEx(long,long,long);
long __stdcall GetSysColor(long nIndex);
long __stdcall GetSysColorBrush(long nIndex);
long __stdcall SetSysColors(long cElements,long lpaElements,long lpaRgbValues);
long __stdcall DrawFocusRect(long hDC,long lprc);
long __stdcall FillRect(long hDC,long lprc,long hbr);
long __stdcall FrameRect(long hDC,long lprc,long hbr);
long __stdcall InvertRect(long hDC,long lprc);
long __stdcall SetRect(long lprc,long xLeft,long yTop,long xRight,long yBottom);
long __stdcall SetRectEmpty(long lprc);
long __stdcall CopyRect(long lprcDst,long lprcSrc);
long __stdcall InflateRect(long lprc,long dx,long dy);
long __stdcall IntersectRect(long lprcDst,long lprcSrc1,long lprcSrc2);
long __stdcall UnionRect(long lprcDst,long lprcSrc1,long lprcSrc2);
long __stdcall SubtractRect(long lprcDst,long lprcSrc1,long lprcSrc2);
long __stdcall OffsetRect(long lprc,long dx,long dy);
long __stdcall IsRectEmpty(long lprc);
long __stdcall EqualRect(long lprc1,long lprc2);
long __stdcall PtInRect(long lprc,long pt);
long __stdcall GetWindowWord(long hWnd,long nIndex);
long __stdcall SetWindowWord(long hWnd,long nIndex,long wNewWord);
long __stdcall GetWindowLong(long hWnd,long nIndex);
long __stdcall SetWindowLong(long hWnd,long nIndex,long dwNewLong);
long __stdcall GetClassWord(long hWnd,long nIndex);
long __stdcall SetClassWord(long hWnd,long nIndex,long wNewWord);
long __stdcall GetClassLong(long hWnd,long nIndex);
long __stdcall SetClassLong(long hWnd,long nIndex,long dwNewLong);
long __stdcall GetDesktopWindow();
long __stdcall GetParent(long hWnd);
long __stdcall SetParent(long hWndChild,long hWndNewParent);
long __stdcall EnumChildWindows(long hWndParent,long lpEnumFunc,long lParam);
long __stdcall FindWindow(long lpClassName,long lpWindowName);
long __stdcall FindWindowEx(long,long,long,long);
long __stdcall EnumWindows(long lpEnumFunc,long lParam);
long __stdcall EnumThreadWindows(long dwThreadId,long lpfn,long lParam);
long __stdcall GetClassName(long hWnd,long lpClassName,long nMaxCount);
long __stdcall GetTopWindow(long hWnd);
long __stdcall GetWindowThreadProcessId(long hWnd,long lpdwProcessId);
long __stdcall GetLastActivePopup(long hWnd);
long __stdcall GetWindow(long hWnd,long uCmd);
long __stdcall SetWindowsHook(long nFilterType,long pfnFilterProc);
long __stdcall SetWindowsHook(long nFilterType,long pfnFilterProc);
long __stdcall UnhookWindowsHook(long nCode,long pfnFilterProc);
long __stdcall SetWindowsHookEx(long idHook,long lpfn,long hmod,long dwThreadId);
long __stdcall UnhookWindowsHookEx(long hhk);
long __stdcall CallNextHookEx(long hhk,long nCode,long wParam,long lParam);
long __stdcall CheckMenuRadioItem(long,long,long,long,long);

API(EnumWindows,user32)
API(EndMenu,user32)
API(GetLastInputInfo,user32)
API(GetMenuInfo,user32)
API(SetMenuInfo,user32)

long __stdcall LoadBitmap(long hInstance,long lpBitmapName);
long __stdcall LoadCursor(long hInstance,long lpCursorName);
long __stdcall LoadCursorFromFile(long lpFileName);
long __stdcall CreateCursor(long hInst,long xHotSpot,long yHotSpot,long nWidth,long nHeight,long pvANDPlane,long pvXORPlane);
long __stdcall DestroyCursor(long hCursor);

long __stdcall SetSystemCursor(long hcur,long id);
long __stdcall LoadIcon(long hInstance,long lpIconName);
long __stdcall CreateIcon(long hInstance,long nWidth,long nHeight,long cPlanes,long cBitsPixel,long lpbANDbits,long lpbXORbits);
long __stdcall DestroyIcon(long hIcon);
long __stdcall LookupIconIdFromDirectory(long presbits,long fIcon);
long __stdcall LookupIconIdFromDirectoryEx(long presbits,long fIcon,long cxDesired,long cyDesired,long Flags);
long __stdcall CreateIconFromResource(long presbits,long dwResSize,long fIcon,long dwVer);
long __stdcall CreateIconFromResourceEx(long presbits,long dwResSize,long fIcon,long dwVer,long cxDesired,long cyDesired,long Flags);
long __stdcall LoadImage(long,long,long,long,long,long);
long __stdcall CopyImage(long,long,long,long,long);


API(DrawIconEx,user32)
APIA(DrawState,user32)
APIA(DrawTextEx,user32)
APIA(LoadBitmap,user32)
APIA(LoadCursor,user32)
API(CreateCursor,user32)
API(DestroyCursor,user32)
APIA(LoadIcon,user32)
API(CreateIcon,user32)
API(DestroyIcon,user32)
API(LookupIconIdFromDirectory,user32)
API(CreateIconIndirect,user32)
API(CopyIcon,user32)
API(GetIconInfo,user32)
API(CreateIconFromResourceEx,user32)

long __stdcall DrawIconEx(long hdc,long xLeft,long yTop,long hIcon,long cxWidth,long cyWidth,long istepIfAniCur,long hbrFlickerFreeDraw,long diFlags);
long __stdcall CreateIconIndirect(long piconinfo);
long __stdcall CopyIcon(long hIcon);
long __stdcall GetIconInfo(long hIcon,long piconinfo);

long __stdcall LoadString(long hInstance,long uID,long lpBuffer,long nBufferMax);
long __stdcall IsDialogMessage(long hDlg,long lpMsg);
long __stdcall MapDialogRect(long hDlg,long lpRect);
long __stdcall DlgDirList(long hDlg,long lpPathSpec,long nIDListBox,long nIDStaticPath,long uFileType);
long __stdcall DlgDirSelectEx(long hDlg,long lpString,long nCount,long nIDListBox);
long __stdcall DlgDirListComboBox(long hDlg,long lpPathSpec,long nIDComboBox,long nIDStaticPath,long uFiletype);
long __stdcall DlgDirSelectComboBoxEx(long hDlg,long lpString,long nCount,long nIDComboBox);
long __stdcall SetScrollInfo(long,long,long,long);
long __stdcall GetScrollInfo(long,long,long);
long __stdcall DefFrameProc(long hWnd,long hWndMDIClient,long uMsg,long wParam,long lParam);
long __stdcall DefMDIChildProc(long hWnd,long uMsg,long wParam,long lParam);
long __stdcall TranslateMDISysAccel(long hWndClient,long lpMsg);
long __stdcall ArrangeIconicWindows(long hWnd);
long __stdcall CreateMDIWindow(long lpClassName,long lpWindowName,long dwStyle,long X,long Y,long nWidth,long nHeight,long hWndParent,long hInstance,long lParam);
long __stdcall TileWindows(long hwndParent,long wHow,long lpRect,long cKids,long lpKids);
long __stdcall CascadeWindows(long hwndParent,long wHow,long lpRect,long cKids,long lpKids);
long __stdcall WinHelp(long hWndMain,long lpszHelp,long uCommand,long dwData);



long __stdcall EnumDisplaySettings(long lpszDeviceName,long iModeNum,long lpDevMode);
long __stdcall EnumDisplayDevices(long Unused,long iDevNum,long lpDisplayDevice,long dwFlags);
long __stdcall EnumDisplayMonitors(long hdc,long lprcClip,long lpfnEnum,long dwData);
APIA(EnumDisplaySettings,user32)
API(EnumDisplayMonitors,user32)
APIA(EnumDisplayDevices,user32)

long __stdcall SystemParametersInfo(long uiAction,long uiParam,long pvParam,long fWinIni);
VOID __stdcall SetDebugErrorLevel(long dwLevel);
VOID __stdcall SetLastErrorEx(long dwErrCode,long dwType);



long __stdcall GetMonitorInfo(long hMonitor,long lpmi);




long __stdcall GetWindowModuleFileName(long hwnd,long pszFileName,long cchFileNameMax);



APIA(GetMonitorInfo,user32)
APIA(GetWindowModuleFileName,user32)

long __stdcall AddFontResource(long);
long __stdcall AnimatePalette(long,long,long,long);
long __stdcall Arc(long,long,long,long,long,long,long,long,long);
long __stdcall BitBlt(long,long,long,long,long,long,long,long,long);
long __stdcall CancelDC(long);
long __stdcall Chord(long,long,long,long,long,long,long,long,long);
long __stdcall ChoosePixelFormat(long,long);
long __stdcall CloseMetaFile(long);
long __stdcall CombineRgn(long,long,long,long);
long __stdcall CopyMetaFile(long,long);
long __stdcall CreateBitmap(long,long,long,long,long);
long __stdcall CreateBitmapIndirect(long);
long __stdcall CreateBrushIndirect(long);
long __stdcall CreateCompatibleBitmap(long,long,long);
long __stdcall CreateDiscardableBitmap(long,long,long);
long __stdcall CreateCompatibleDC(long);
long __stdcall CreateDC(long,long,long,long);
long __stdcall CreateDIBitmap(long,long ,long,long ,long ,long);
long __stdcall CreateDIBPatternBrush(long,long);
long __stdcall CreateDIBPatternBrushPt(long ,long);
long __stdcall CreateEllipticRgn(long,long,long,long);
long __stdcall CreateEllipticRgnIndirect(long);
long __stdcall CreateFontIndirect(long);
long __stdcall CreateFont(long,long,long,long,long,long,long,long,long,long,long,long,long,long);
long __stdcall CreateHatchBrush(long,long);
long __stdcall CreateIC(long,long,long,long);
long __stdcall CreateMetaFile(long);
long __stdcall CreatePalette(long);
long __stdcall CreatePen(long,long,long);
long __stdcall CreatePenIndirect(long);
long __stdcall CreatePolyPolygonRgn(long ,long ,long,long);
long __stdcall CreatePatternBrush(long);
long __stdcall CreateRectRgn(long,long,long,long);
long __stdcall CreateRectRgnIndirect(long);
long __stdcall CreateRoundRectRgn(long,long,long,long,long,long);
long __stdcall CreateScalableFontResource(long,long,long,long);
long __stdcall CreateSolidBrush(long);
long __stdcall DeleteDC(long);
long __stdcall DeleteMetaFile(long);
long __stdcall DeleteObject(long);
long __stdcall DescribePixelFormat(long,long,long,long);
long __stdcall DrawEscape(long,long,long,long);
long __stdcall Ellipse(long,long,long,long,long);
long __stdcall EnumFontFamiliesEx(long,long,long,long,long);
long __stdcall EnumFontFamilies(long,long,long,long);
long __stdcall EnumFonts(long,long,long,long);
long __stdcall EnumObjects(long,long,long,long);
long __stdcall EnumObjects(long,long,long,long);
long __stdcall EqualRgn(long,long);
long __stdcall Escape(long,long,long,long,long);
long __stdcall ExtEscape(long,long,long,long,long,long);
long __stdcall ExcludeClipRect(long,long,long,long,long);
long __stdcall ExtCreateRegion(long ,long,long);
long __stdcall ExtFloodFill(long,long,long,long,long);
long __stdcall FillRgn(long,long,long);
long __stdcall FloodFill(long,long,long,long);
long __stdcall FrameRgn(long,long,long,long,long);
long __stdcall GetROP2(long);
long __stdcall GetAspectRatioFilterEx(long,long);
long __stdcall GetBkColor(long);


long __stdcall GetBkMode(long);
long __stdcall GetBitmapBits(long,long,long);
long __stdcall GetBitmapDimensionEx(long,long);
long __stdcall GetBoundsRect(long,long,long);
long __stdcall GetBrushOrgEx(long,long);
long __stdcall GetCharWidth(long,long,long,long);
long __stdcall GetCharWidth32(long,long,long,long);
long __stdcall GetCharWidthFloat(long,long,long,long);
long __stdcall GetCharABCWidths(long,long,long,long);
long __stdcall GetCharABCWidthsFloat(long,long,long,long);
long __stdcall GetClipBox(long,long);
long __stdcall GetClipRgn(long,long);
long __stdcall GetMetaRgn(long,long);
long __stdcall GetCurrentObject(long,long);
long __stdcall GetCurrentPositionEx(long,long);
long __stdcall GetDeviceCaps(long,long);
long __stdcall GetDIBits(long,long,long,long,long,long,long);

long __stdcall GetGlyphIndices(long,long,long,long,long);
long __stdcall GetGlyphOutline(long,long,long,long,long,long,long);
long __stdcall GetGraphicsMode(long);
long __stdcall GetMapMode(long);
long __stdcall GetMetaFileBitsEx(long,long,long);
long __stdcall GetMetaFile(long);
long __stdcall GetNearestColor(long,long);
long __stdcall GetNearestPaletteIndex(long,long);
long __stdcall GetObjectType(long h);
long __stdcall GetOutlineTextMetrics(long,long,long);
long __stdcall GetPaletteEntries(long,long,long,long);
long __stdcall GetPixel(long,long,long);
long __stdcall GetPixelFormat(long);
long __stdcall GetPolyFillMode(long);
long __stdcall GetRasterizerCaps(long,long);

long __stdcall GetRgnBox(long,long);
long __stdcall GetStockObject(long);
long __stdcall GetStretchBltMode(long);
long __stdcall GetSystemPaletteEntries(long,long,long,long);
long __stdcall GetSystemPaletteUse(long);
long __stdcall GetTextCharacterExtra(long);
long __stdcall GetTextAlign(long);
long __stdcall GetTextColor(long);
long __stdcall GetTextExtentPoint(long,long,long,long);
long __stdcall GetTextExtentPoint32(long,long,long,long);
long __stdcall GetTextExtentExPoint(long,long,long,long,long,long,long);
long __stdcall GetTextCharset(long hdc);
long __stdcall GetTextCharsetInfo(long hdc,long lpSig,long dwFlags);
long __stdcall TranslateCharsetInfo(long lpSrc,long lpCs,long dwFlags);
long __stdcall GetFontLanguageInfo(long);
long __stdcall GetCharacterPlacement(long,long,long,long,long,long);

long __stdcall GetTextExtentPointI(long,long,long,long);
long __stdcall GetTextExtentExPointI(long,long,long,long,long,long,long);
long __stdcall GetCharWidthI(long,long,long,long,long);
long __stdcall GetCharABCWidthsI(long,long,long,long,long);
long __stdcall AddFontResourceEx(long,long,long);

long __stdcall AddFontMemResourceEx(long,long,long ,long);
long __stdcall RemoveFontMemResourceEx(long);

BOOL __stdcall SwapBuffers(HDC hdc);

APIA(AddFontResource,gdi32)
APIA(AddFontResourceEx,gdi32)
API(AddFontMemResourceEx,gdi32)
API(RemoveFontMemResourceEx,gdi32)

APIA(GetGlyphIndices,gdi32)
API(GetTextCharacterExtra,gdi32)
API(GetTextAlign,gdi32)
API(GetTextColor,gdi32)
API(GetTextExtentPoint,gdi32)
API(GetTextExtentPoint32,gdi32)
API(GetTextExtentExPoint,gdi32)
API(GetTextCharset,gdi32)
API(GetTextCharsetInfo,gdi32)
API(GetTextExtentPointI,gdi32)
API(GetTextExtentExPointI,gdi32)




API(GradientFill,msimg32)
API(TransparentBlt,msimg32)


long __stdcall GetViewportExtEx(long,long);
long __stdcall GetViewportOrgEx(long,long);
long __stdcall GetWindowExtEx(long,long);
long __stdcall GetWindowOrgEx(long,long);
long __stdcall IntersectClipRect(long,long,long,long,long);
long __stdcall InvertRgn(long,long);

long __stdcall LineTo(long,long,long);
long __stdcall MaskBlt(long,long,long,long,long,long,long,long,long,long,long,long);
long __stdcall PlgBlt(long,long ,long,long,long,long,long,long,long,long);
long __stdcall OffsetClipRgn(long,long,long);
long __stdcall OffsetRgn(long,long,long);
long __stdcall PatBlt(long,long,long,long,long,long);
long __stdcall Pie(long,long,long,long,long,long,long,long,long);
long __stdcall PlayMetaFile(long,long);
long __stdcall PaintRgn(long,long);
long __stdcall PolyPolygon(long,long ,long ,long);
long __stdcall PtInRegion(long,long,long);
long __stdcall PtVisible(long,long,long);
long __stdcall RectInRegion(long,long);
long __stdcall RectVisible(long,long);
long __stdcall Rectangle(long,long,long,long,long);
long __stdcall RestoreDC(long,long);
long __stdcall ResetDC(long,long);
long __stdcall RealizePalette(long);
long __stdcall RemoveFontResource(long);
long __stdcall RoundRect(long,long,long,long,long,long,long);
long __stdcall ResizePalette(long,long);
long __stdcall SaveDC(long);
long __stdcall SelectClipRgn(long,long);
long __stdcall ExtSelectClipRgn(long,long,long);
long __stdcall SetMetaRgn(long);
long __stdcall SelectObject(long,long);
long __stdcall SelectPalette(long,long,long);
long __stdcall SetBkColor(long,long);
long __stdcall SetDCBrushColor(long,long);
long __stdcall SetDCPenColor(long,long);
long __stdcall SetBkMode(long,long);
long __stdcall SetBitmapBits(long,long,long);
long __stdcall SetBoundsRect(long,long ,long);
long __stdcall SetDIBits(long,long,long,long,long ,long ,long);
long __stdcall SetDIBitsToDevice(long,long,long,long,long,long,long,long,long,long ,long ,long);
long __stdcall SetMapperFlags(long,long);
long __stdcall SetGraphicsMode(long hdc,long iMode);
long __stdcall SetMapMode(long,long);
long __stdcall SetMetaFileBitsEx(long,long);
long __stdcall SetPaletteEntries(long,long,long,long);
long __stdcall SetPixel(long,long,long,long);
long __stdcall SetPixelV(long,long,long,long);
long __stdcall SetPixelFormat(long,long,long);
long __stdcall SetPolyFillMode(long,long);
long __stdcall StretchBlt(long,long,long,long,long,long,long,long,long,long,long);
long __stdcall SetRectRgn(long,long,long,long,long);
long __stdcall StretchDIBits(long,long,long,long,long,long,long,long,long,long ,long ,long,long);
long __stdcall SetROP2(long,long);
long __stdcall SetStretchBltMode(long,long);
long __stdcall SetSystemPaletteUse(long,long);
long __stdcall SetTextCharacterExtra(long,long);
long __stdcall SetTextColor(long,long);
long __stdcall SetTextAlign(long,long);
long __stdcall SetTextJustification(long,long,long);
long __stdcall UpdateColors(long);

long __stdcall AlphaBlend(long,long,long,long,long,long,long,long,long,long,long);

API(AlphaBlend,msimg32)

long __stdcall TransparentBlt(long,long,long,long,long,long,long,long,long,long,long);

long __stdcall GradientFill(long,long,long,long,long,long);
long __stdcall PlayMetaFileRecord(long,long,long,long);
long __stdcall EnumMetaFile(long,long,long,long);
long __stdcall CloseEnhMetaFile(long);
long __stdcall CopyEnhMetaFile(long,long);
long __stdcall CreateEnhMetaFile(long,long,long ,long);
long __stdcall DeleteEnhMetaFile(long);
long __stdcall EnumEnhMetaFile(long,long,long,long,long);
long __stdcall GetEnhMetaFile(long);
long __stdcall GetEnhMetaFileBits(long,long,long);
long __stdcall GetEnhMetaFileDescription(long,long,long);
long __stdcall GetEnhMetaFileHeader(long,long,long);
long __stdcall GetEnhMetaFilePaletteEntries(long,long,long);
long __stdcall GetEnhMetaFilePixelFormat(long,long,long);
long __stdcall GetWinMetaFileBits(long,long,long,long,long);
long __stdcall PlayEnhMetaFile(long,long,long);
long __stdcall PlayEnhMetaFileRecord(long,long,long ,long);
long __stdcall SetEnhMetaFileBits(long,long);
long __stdcall SetWinMetaFileBits(long,long ,long,long);
long __stdcall GdiComment(long,long,long);
long __stdcall GetTextMetrics(long,long);
long __stdcall AngleArc(long,long,long,long,long,long);
long __stdcall PolyPolyline(long,long ,long ,long);
long __stdcall GetWorldTransform(long,long);
long __stdcall SetWorldTransform(long,long);
long __stdcall ModifyWorldTransform(long,long ,long);
long __stdcall CombineTransform(long,long ,long);
long __stdcall CreateDIBSection(long,long ,long,long ,long,long);
long __stdcall GetDIBColorTable(long,long,long,long);
long __stdcall SetDIBColorTable(long,long,long,long);
long __stdcall SetColorAdjustment(long,long);
long __stdcall GetColorAdjustment(long,long);
long __stdcall CreateHalftonePalette(long);
long __stdcall StartDoc(long,long);
long __stdcall EndDoc(long);
long __stdcall StartPage(long);
long __stdcall EndPage(long);
long __stdcall AbortDoc(long);
long __stdcall SetAbortProc(long,long);
long __stdcall AbortPath(long);
long __stdcall ArcTo(long,long,long,long,long,long,long,long,long);
long __stdcall BeginPath(long);
long __stdcall CloseFigure(long);
long __stdcall EndPath(long);
long __stdcall FillPath(long);
long __stdcall FlattenPath(long);
long __stdcall GetPath(long,long,long,long);
long __stdcall PathToRegion(long);
long __stdcall PolyDraw(long,long ,long ,long);
long __stdcall SelectClipPath(long,long);
long __stdcall SetArcDirection(long,long);
long __stdcall SetMiterLimit(long,long,long);
long __stdcall StrokeAndFillPath(long);
long __stdcall StrokePath(long);
long __stdcall WidenPath(long);
long __stdcall ExtCreatePen(long,long,long ,long,long);
long __stdcall GetMiterLimit(long,long);
long __stdcall GetArcDirection(long);
long __stdcall GetObject(long,long,long);
long __stdcall MoveToEx(long,long,long,long);
long __stdcall TextOut(long,long,long,long,long);
long __stdcall ExtTextOut(long,long,long,long,long ,long,long,long);
long __stdcall PolyTextOut(long,long ,long);
long __stdcall CreatePolygonRgn(long ,long,long);
long __stdcall DPtoLP(long,long,long);
long __stdcall LPtoDP(long,long,long);
long __stdcall Polygon(long,long ,long);
long __stdcall Polyline(long,long ,long);
long __stdcall PolyBezier(long,long ,long);
long __stdcall PolyBezierTo(long,long ,long);
long __stdcall PolylineTo(long,long ,long);
long __stdcall SetViewportExtEx(long,long,long,long);
long __stdcall SetViewportOrgEx(long,long,long,long);
long __stdcall SetWindowExtEx(long,long,long,long);
long __stdcall SetWindowOrgEx(long,long,long,long);
long __stdcall OffsetViewportOrgEx(long,long,long,long);
long __stdcall OffsetWindowOrgEx(long,long,long,long);
long __stdcall ScaleViewportExtEx(long,long,long,long,long,long);
long __stdcall ScaleWindowExtEx(long,long,long,long,long,long);
long __stdcall SetBitmapDimensionEx(long,long,long,long);
long __stdcall SetBrushOrgEx(long,long,long,long);
long __stdcall GetTextFace(long,long,long);
long __stdcall GetKerningPairs(long,long,long);
long __stdcall GetDCOrgEx(long,long);
long __stdcall FixBrushOrgEx(long,long,long,long);
long __stdcall UnrealizeObject(long);
long __stdcall GdiFlush();
long __stdcall GdiSetBatchLimit(long);
long __stdcall GdiGetBatchLimit();
long __stdcall SetICMMode(long,long);
long __stdcall CheckColorsInGamut(long,long,long,long);
long __stdcall GetColorSpace(long);
long __stdcall GetLogColorSpace(long,long,long);
long __stdcall CreateColorSpace(long);
long __stdcall SetColorSpace(long,long);
long __stdcall DeleteColorSpace(long);
long __stdcall GetICMProfile(long,long,long);
long __stdcall SetICMProfile(long,long);
long __stdcall GetDeviceGammaRamp(long,long);
long __stdcall SetDeviceGammaRamp(long,long);
long __stdcall ColorMatchToTarget(long,long,long);
long __stdcall EnumICMProfiles(long,long,long);
long __stdcall UpdateICMRegKey(long,long,long,long);
long __stdcall ColorCorrectPalette(long,long,long,long);

API(AnimatePalette,gdi32)
API(ColorCorrectPalette,gdi32)
API(Arc,gdi32)
API(BitBlt,gdi32)
API(CancelDC,gdi32)
API(Chord,gdi32)
API(CloseMetaFile,gdi32)
API(CombineRgn,gdi32)
APIA(CopyMetaFile,gdi32)
API(CreateBitmap,gdi32)
API(CreateBitmapIndirect,gdi32)
API(CreateBrushIndirect,gdi32)
API(CreateCompatibleBitmap,gdi32)
API(CreateDiscardableBitmap,gdi32)
API(CreateCompatibleDC,gdi32)
APIA(CreateDC,gdi32)
API(CreateDIBitmap,gdi32)
API(CreateDIBPatternBrush,gdi32)
API(CreateDIBPatternBrushPt,gdi32)
API(CreateEllipticRgnIndirect,gdi32)
API(CreateEllipticRgn,gdi32)
APIA(CreateFontIndirect,gdi32)
APIA(CreateFont,gdi32)
API(CreateHatchBrush,gdi32)
APIA(CreateIC,gdi32)
APIA(CreateMetaFile,gdi32)
API(CreatePalette,gdi32)
API(CreatePen,gdi32)
API(CreatePenIndirect,gdi32)
API(CreateRectRgn,gdi32)
API(CreateRectRgnIndirect,gdi32)
API(CreatePolyPolygonRgn,gdi32)
API(CreatePatternBrush,gdi32)
API(CreateRoundRectRgn,gdi32)
APIA(CreateScalableFontResource,gdi32)
API(CreateSolidBrush,gdi32)
API(DeleteDC,gdi32)
API(DeleteObject,gdi32)
API(DeleteMetaFile,gdi32)
API(Ellipse,gdi32)
API(EqualRgn,gdi32)
API(Escape,gdi32)
API(ExtEscape,gdi32)
API(DrawEscape,gdi32)
API(ExcludeClipRect,gdi32)
API(ExtCreateRegion,gdi32)
API(ExtFloodFill,gdi32)
API(FillRgn,gdi32)
API(FrameRgn,gdi32)
API(FloodFill,gdi32)
API(GetROP2,gdi32)
API(GetAspectRatioFilterEx,gdi32)
API(GetBkColor,gdi32)
API(GetBkMode,gdi32)
API(GetBitmapBits,gdi32)
API(GetBitmapDimensionEx,gdi32)
API(GetBoundsRect,gdi32)
APIA(GetCharWidth,gdi32)
APIA(GetCharWidth32,gdi32)
APIA(GetCharWidthFloat,gdi32)
API(GetCharWidthI,gdi32)
APIA(GetCharABCWidths,gdi32)
APIA(GetCharABCWidthsFloat,gdi32)
API(GetCharABCWidthsI,gdi32)
API(GetClipBox,gdi32)
API(GetClipRgn,gdi32)
API(GetMetaRgn,gdi32)
API(GetCurrentObject,gdi32)
API(GetCurrentPositionEx,gdi32)
API(GetDeviceCaps,gdi32)
API(GetDIBits,gdi32)
APIA(GetFontData,gdi32)
APIA(GetGlyphOutline,gdi32)
API(GetGraphicsMode,gdi32)
API(GetMapMode,gdi32)
API(GetMetaFileBitsEx,gdi32)
APIA(GetMetaFile,gdi32)
API(GetNearestColor,gdi32)
API(GetNearestPaletteIndex,gdi32)
API(GetObjectType,gdi32)
APIA(GetOutlineTextMetrics,gdi32)
API(GetPaletteEntries,gdi32)
API(GetPixel,gdi32)
API(GetPolyFillMode,gdi32)
API(GetRasterizerCaps,gdi32)
APIA(GetRegionData,gdi32)
API(GetRgnBox,gdi32)
API(GetStockObject,gdi32)
API(GetStretchBltMode,gdi32)
API(GetSystemPaletteEntries,gdi32)
API(GetSystemPaletteUse,gdi32)
API(GetTextCharacterExtra,gdi32)
API(GetTextAlign,gdi32)
API(GetTextColor,gdi32)
APIA(GetTextExtentPoint,gdi32)
APIA(GetTextExtentPoint32,gdi32)
APIA(GetTextExtentExPoint,gdi32)
API(GetViewportExtEx,gdi32)
API(GetViewportOrgEx,gdi32)
API(GetWindowExtEx,gdi32)
API(GetWindowOrgEx,gdi32)
API(IntersectClipRect,gdi32)
API(InvertRgn,gdi32)
API(LineTo,gdi32)
API(MaskBlt,gdi32)
API(PlgBlt,gdi32)
API(OffsetClipRgn,gdi32)
API(OffsetRgn,gdi32)
API(PatBlt,gdi32)
API(Pie,gdi32)
API(PlayMetaFile,gdi32)
API(PaintRgn,gdi32)
API(PolyPolygon,gdi32)
API(PtInRegion,gdi32)
API(PtVisible,gdi32)
API(RectVisible,gdi32)
API(RectInRegion,gdi32)
API(Rectangle,gdi32)
API(RestoreDC,gdi32)
APIA(ResetDC,gdi32)
API(RealizePalette,gdi32)
APIA(RemoveFontResource,gdi32)
API(RoundRect,gdi32)
API(ResizePalette,gdi32)
API(SaveDC,gdi32)
API(SelectClipRgn,gdi32)
API(ExtSelectClipRgn,gdi32)
API(SetMetaRgn,gdi32)
API(SelectObject,gdi32)
API(SelectPalette,gdi32)
API(SetBkColor,gdi32)
API(SetBkMode,gdi32)
API(SetDCBrushColor,gdi32)
API(SetDCPenColor,gdi32)
API(SetBitmapBits,gdi32)
API(SetBoundsRect,gdi32)
API(SetDIBits,gdi32)
API(SetDIBitsToDevice,gdi32)
API(SetMapperFlags,gdi32)
API(SetGraphicsMode,gdi32)
API(SetMapMode,gdi32)
API(SetMetaFileBitsEx,gdi32)
API(SetPaletteEntries,gdi32)
API(SetPixel,gdi32)
API(SetPixelV,gdi32)
API(SetPolyFillMode,gdi32)
API(StretchBlt,gdi32)
API(SetRectRgn,gdi32)
API(StretchDIBits,gdi32)
API(SetROP2,gdi32)
API(SetStretchBltMode,gdi32)
API(SetSystemPaletteUse,gdi32)
API(SetTextCharacterExtra,gdi32)
API(SetTextColor,gdi32)
API(SetTextAlign,gdi32)
API(SetTextJustification,gdi32)
API(UpdateColors,gdi32)
API(GetProcAddress,kernel32)
API(PlayMetaFileRecord,gdi32)
API(CloseEnhMetaFile,gdi32)
APIA(CopyEnhMetaFile,gdi32)
APIA(CreateEnhMetaFile,gdi32)
API(DeleteEnhMetaFile,gdi32)
API(EnumEnhMetaFile,gdi32)
APIA(GetEnhMetaFile,gdi32)
API(GetEnhMetaFileBits,gdi32)
APIA(GetEnhMetaFileDescription,gdi32)
API(GetEnhMetaFileHeader,gdi32)
API(GetEnhMetaFilePaletteEntries,gdi32)
API(GetEnhMetaFilePixelFormat,gdi32)
API(GetWinMetaFileBits,gdi32)
API(PlayEnhMetaFile,gdi32)
API(PlayEnhMetaFileRecord,gdi32)
API(SetEnhMetaFileBits,gdi32)
API(SetWinMetaFileBits,gdi32)
API(GdiComment,gdi32)
APIA(GetTextMetrics,gdi32)
API(AngleArc,gdi32)
API(PolyPolyline,gdi32)
API(GetWorldTransform,gdi32)
API(SetWorldTransform,gdi32)
API(ModifyWorldTransform,gdi32)
API(CombineTransform,gdi32)
API(SetColorAdjustment,gdi32)
API(GetColorAdjustment,gdi32)
API(CreateHalftonePalette,gdi32)
APIA(StartDoc,gdi32)
API(StartPage,gdi32)
API(EndPage,gdi32)
API(EndDoc,gdi32)
API(AbortDoc,gdi32)
API(AbortPath,gdi32)
API(ArcTo,gdi32)
API(BeginPath,gdi32)
API(CloseFigure,gdi32)
API(EndPath,gdi32)
API(FillPath,gdi32)
API(FlattenPath,gdi32)
API(GetPath,gdi32)
API(PathToRegion,gdi32)
API(PolyDraw,gdi32)
API(SelectClipPath,gdi32)
API(SetArcDirection,gdi32)
API(SetMiterLimit,gdi32)
API(StrokeAndFillPath,gdi32)
API(StrokePath,gdi32)
API(WidenPath,gdi32)
API(ExtCreatePen,gdi32)
API(GetMiterLimit,gdi32)
API(GetArcDirection,gdi32)
APIA(GetObject,gdi32)
API(MoveToEx,gdi32)
APIA(TextOut,gdi32)
APIA(ExtTextOut,gdi32)
APIA(PolyTextOut,gdi32)
API(CreatePolygonRgn,gdi32)
API(DPtoLP,gdi32)
API(LPtoDP,gdi32)
API(Polyline,gdi32)
API(Polygon,gdi32)
API(PolyBezier,gdi32)
API(PolyBezierTo,gdi32)
API(PolylineTo,gdi32)
API(SetViewportExtEx,gdi32)
API(SetViewportOrgEx,gdi32)
API(SetWindowOrgEx,gdi32)
API(SetWindowExtEx,gdi32)
API(OffsetViewportOrgEx,gdi32)
API(OffsetWindowOrgEx,gdi32)
API(ScaleWindowExtEx,gdi32)
API(ScaleViewportExtEx,gdi32)
API(SetBitmapDimensionEx,gdi32)
API(SetBrushOrgEx,gdi32)
APIA(GetTextFace,gdi32)
APIA(GetKerningPairs,gdi32)
API(GetDCOrgEx,gdi32)
API(UnrealizeObject,gdi32)
API(GdiFlush,gdi32)
API(GdiSetBatchLimit,gdi32)
API(GdiGetBatchLimit,gdi32)
APIA(EnumFontFamilies,gdi32)
APIA(EnumFontFamiliesEx,gdi32)
API(GetTextCharset,gdi32)
API(GetTextCharsetInfo,gdi32)
API(TranslateCharsetInfo,gdi32)
API(GetFontLanguageInfo,gdi32)
APIA(GetCharacterPlacement,gdi32)
API(SetICMMode,gdi32)
API(CheckColorsInGamut,gdi32)
APIA(GetLogColorSpace,gdi32)
API(GetColorSpace,gdi32)
APIA(CreateColorSpace,gdi32)
API(SetColorSpace,gdi32)
API(DeleteColorSpace,gdi32)
APIA(GetICMProfile,gdi32)
APIA(SetICMProfile,gdi32)
API(GetDeviceGammaRamp,gdi32)
API(SetDeviceGammaRamp,gdi32)
API(ColorMatchToTarget,gdi32)
APIA(EnumICMProfiles,gdi32)
APIA(UpdateICMRegKey,gdi32)

long __stdcall EncryptFile(long lpFileName);
long __stdcall DecryptFile(long lpFileName,long dwReserved);
APIA(EncryptFile,advapi32)
APIA(DecryptFile,advapi32)






long __stdcall IsTextUnicode(long lpBuffer,long cb,long lpi);
long __stdcall ClearEventLog(long hEventLog,long lpBackupFileName);
long __stdcall BackupEventLog(long hEventLog,long lpBackupFileName);
long __stdcall CloseEventLog(long hEventLog);
long __stdcall DeregisterEventSource(long hEventLog);
long __stdcall NotifyChangeEventLog(long hEventLog,long hEvent);
long __stdcall GetNumberOfEventLogRecords(long hEventLog,long NumberOfRecords);
long __stdcall GetOldestEventLogRecord(long hEventLog,long OldestRecord);
long __stdcall OpenEventLog(long lpUNCServerName,long lpSourceName);
long __stdcall RegisterEventSource(long lpUNCServerName,long lpSourceName);
long __stdcall OpenBackupEventLog(long lpUNCServerName,long lpFileName);
long __stdcall ReadEventLog(long hEventLog,long dwReadFlags,long dwRecordOffset,long lpBuffer,long nNumberOfBytesToRead,long pnBytesRead,long pnMinNumberOfBytesNeeded);
long __stdcall ReportEvent(long hEventLog,long wType,long wCategory,long dwEventID,long lpUserSid,long wNumStrings,long dwDataSize,long lpStrings,long lpRawData);
long __stdcall DuplicateToken(long ExistingTokenHandle,long ImpersonationLevel,long DuplicateTokenHandle);
long __stdcall GetKernelObjectSecurity(long Handle,long RequestedInformation,long pSecurityDescriptor,long nLength,long lpnLengthNeeded);
long __stdcall ImpersonateNamedPipeClient(long hNamedPipe);
long __stdcall ImpersonateSelf(long ImpersonationLevel);
long __stdcall RevertToSelf(long);
long __stdcall SetThreadToken(long Thread,long Token);

API(DuplicateToken,advapi32)
API(DuplicateTokenEx,advapi32)

long __stdcall AccessCheck(long pSecurityDescriptor,long ClientToken,long DesiredAccess,long GenericMapping,long PrivilegeSet,long PrivilegeSetLength,long GrantedAccess,long AccessStatus);
long __stdcall AccessCheckByType(long pSecurityDescriptor,long PrincipalSelfSid,long ClientToken,long DesiredAccess,long ObjectTypeList,long ObjectTypeListLength,long GenericMapping,long PrivilegeSet,long PrivilegeSetLength,long GrantedAccess,long AccessStatus);
long __stdcall AccessCheckByTypeResultList(long pSecurityDescriptor,long PrincipalSelfSid,long ClientToken,long DesiredAccess,long ObjectTypeList,long ObjectTypeListLength,long GenericMapping,long PrivilegeSet,long PrivilegeSetLength,long GrantedAccessList,long AccessStatusList);
long __stdcall AccessCheckAndAuditAlarm(long SubsystemName,long HandleId,long ObjectTypeName,long ObjectName,long SecurityDescriptor,long DesiredAccess,long GenericMapping,long ObjectCreation,long GrantedAccess,long AccessStatus,long pfGenerateOnClose);
long __stdcall AccessCheckByTypeAndAuditAlarm(long SubsystemName,long HandleId,long ObjectTypeName,long ObjectName,long SecurityDescriptor,long PrincipalSelfSid,long DesiredAccess,long AuditType,long Flags,long ObjectTypeList,long ObjectTypeListLength,long GenericMapping,long ObjectCreation,long GrantedAccess,long AccessStatus,long pfGenerateOnClose);
long __stdcall AccessCheckByTypeResultListAndAuditAlarm(long SubsystemName,long HandleId,long ObjectTypeName,long ObjectName,long SecurityDescriptor,long PrincipalSelfSid,long DesiredAccess,long AuditType,long Flags,long ObjectTypeList,long ObjectTypeListLength,long GenericMapping,long ObjectCreation,long GrantedAccess,long AccessStatusList,long pfGenerateOnClose);

API(AccessCheck,advapi32)
API(AccessCheckByType,advapi32)
API(AccessCheckByTypeResultList,advapi32)




long __stdcall OpenProcessToken(long ProcessHandle,long DesiredAccess,long TokenHandle);
long __stdcall OpenThreadToken(long ThreadHandle,long DesiredAccess,long OpenAsSelf,long TokenHandle);
long __stdcall GetTokenInformation(long TokenHandle,long TokenInformationClass,long TokenInformation,long TokenInformationLength,long ReturnLength);
long __stdcall SetTokenInformation(long TokenHandle,long TokenInformationClass,long TokenInformation,long TokenInformationLength);
long __stdcall AdjustTokenPrivileges(long TokenHandle,long DisableAllPrivileges,long NewState,long BufferLength,long PreviousState,long ReturnLength);
long __stdcall AdjustTokenGroups(long TokenHandle,long ResetToDefault,long NewState,long BufferLength,long PreviousState,long ReturnLength);
long __stdcall PrivilegeCheck(long ClientToken,long RequiredPrivileges,long pfResult);
long __stdcall ObjectOpenAuditAlarm(long SubsystemName,long HandleId,long ObjectTypeName,long ObjectName,long pSecurityDescriptor,long ClientToken,long DesiredAccess,long GrantedAccess,long Privileges,long ObjectCreation,long AccessGranted,long GenerateOnClose);
long __stdcall ObjectPrivilegeAuditAlarm(long SubsystemName,long HandleId,long ClientToken,long DesiredAccess,long Privileges,long AccessGranted);
long __stdcall ObjectCloseAuditAlarm(long SubsystemName,long HandleId,long GenerateOnClose);
long __stdcall ObjectDeleteAuditAlarm(long SubsystemName,long HandleId,long GenerateOnClose);
long __stdcall PrivilegedServiceAuditAlarm(long SubsystemName,long ServiceName,long ClientToken,long Privileges,long AccessGranted);
long __stdcall IsValidSid(long pSid);
long __stdcall EqualSid(long pSid1,long pSid2);
long __stdcall EqualPrefixSid(long pSid1,long pSid2);
long __stdcall GetSidLengthRequired(long nSubAuthorityCount);
long __stdcall AllocateAndInitializeSid(long pIdentifierAuthority,long nSubAuthorityCount,long nSubAuthority0,long nSubAuthority1,long nSubAuthority2,long nSubAuthority3,long nSubAuthority4,long nSubAuthority5,long nSubAuthority6,long nSubAuthority7,long pSid);
long __stdcall FreeSid(long pSid);
long __stdcall InitializeSid(long Sid,long pIdentifierAuthority,long nSubAuthorityCount);
long __stdcall GetSidIdentifierAuthority(long pSid);
long __stdcall GetSidSubAuthority(long pSid,long nSubAuthority);
long __stdcall GetSidSubAuthorityCount(long pSid);
long __stdcall GetLengthSid(long pSid);
long __stdcall CopySid(long nDestinationSidLength,long pDestinationSid,long pSourceSid);
long __stdcall AreAllAccessesGranted(long GrantedAccess,long DesiredAccess);
VOID __stdcall MapGenericMask(long AccessMask,long GenericMapping);

API(OpenProcessToken,advapi32)
API(GetTokenInformation,advapi32)
APIA(LookupAccountSid,advapi32)
API(NetLocalGroupDelMembers,advapi32)
API(NetLocalGroupGetMembers,advapi32)

long __stdcall IsValidAcl(long pAcl);
long __stdcall InitializeAcl(long pAcl,long nAclLength,long dwAclRevision);
long __stdcall GetAclInformation(long pAcl,long pAclInformation,long nAclInformationLength,long dwAclInformationClass);
long __stdcall SetAclInformation(long pAcl,long pAclInformation,long nAclInformationLength,long dwAclInformationClass);
long __stdcall AddAce(long pAcl,long dwAceRevision,long dwStartingAceIndex,long pAceList,long nAceListLength);
long __stdcall DeleteAce(long pAcl,long dwAceIndex);
long __stdcall GetAce(long pAcl,long dwAceIndex,long pAce);
long __stdcall AddAccessAllowedAce(long pAcl,long dwAceRevision,long AccessMask,long pSid);
long __stdcall AddAccessAllowedAceEx(long pAcl,long dwAceRevision,long AceFlags,long AccessMask,long pSid);
long __stdcall AddAccessDeniedAce(long pAcl,long dwAceRevision,long AccessMask,long pSid);
long __stdcall AddAccessDeniedAceEx(long pAcl,long dwAceRevision,long AceFlags,long AccessMask,long pSid);
long __stdcall AddAuditAccessAce(long pAcl,long dwAceRevision,long dwAccessMask,long pSid,long bAuditSuccess,long bAuditFailure);
long __stdcall AddAuditAccessAceEx(long pAcl,long dwAceRevision,long AceFlags,long dwAccessMask,long pSid,long bAuditSuccess,long bAuditFailure);
long __stdcall AddAccessAllowedObjectAce(long pAcl,long dwAceRevision,long AceFlags,long AccessMask,long ObjectTypeGuid,long InheritedObjectTypeGuid,long pSid);
long __stdcall AddAccessDeniedObjectAce(long pAcl,long dwAceRevision,long AceFlags,long AccessMask,long ObjectTypeGuid,long InheritedObjectTypeGuid,long pSid);
long __stdcall AddAuditAccessObjectAce(long pAcl,long dwAceRevision,long AceFlags,long AccessMask,long ObjectTypeGuid,long InheritedObjectTypeGuid,long pSid,long bAuditSuccess,long bAuditFailure);
long __stdcall FindFirstFreeAce(long pAcl,long pAce);

API(AddAccessAllowedAceEx,advapi32)
API(AddAccessAllowedObjectAce,advapi32)
API(AddAccessDeniedAceEx,advapi32)
API(AddAccessDeniedObjectAce,advapi32)
API(AddAuditAccessAceEx,advapi32)
API(AddAuditAccessObjectAce,advapi32)

long __stdcall InitializeSecurityDescriptor(long pSecurityDescriptor,long dwRevision);
long __stdcall IsValidSecurityDescriptor(long pSecurityDescriptor);
long __stdcall GetSecurityDescriptorLength(long pSecurityDescriptor);
long __stdcall GetSecurityDescriptorControl(long pSecurityDescriptor,long pControl,long lpdwRevision);
long __stdcall SetSecurityDescriptorControl(long pSecurityDescriptor,long ControlBitsOfInterest,long ControlBitsToSet);
long __stdcall SetSecurityDescriptorDacl(long pSecurityDescriptor,long bDaclPresent,long pDacl,long bDaclDefaulted);
long __stdcall GetSecurityDescriptorDacl(long pSecurityDescriptor,long lpbDaclPresent,long pDacl,long lpbDaclDefaulted);
long __stdcall SetSecurityDescriptorSacl(long pSecurityDescriptor,long bSaclPresent,long pSacl,long bSaclDefaulted);
long __stdcall GetSecurityDescriptorSacl(long pSecurityDescriptor,long lpbSaclPresent,long pSacl,long lpbSaclDefaulted);
long __stdcall SetSecurityDescriptorOwner(long pSecurityDescriptor,long pOwner,long bOwnerDefaulted);
long __stdcall GetSecurityDescriptorOwner(long pSecurityDescriptor,long pOwner,long lpbOwnerDefaulted);
long __stdcall SetSecurityDescriptorGroup(long pSecurityDescriptor,long pGroup,long bGroupDefaulted);
long __stdcall GetSecurityDescriptorGroup(long pSecurityDescriptor,long pGroup,long lpbGroupDefaulted);
long __stdcall CreatePrivateObjectSecurity(long ParentDescriptor,long CreatorDescriptor,long NewDescriptor,long IsDirectoryObject,long Token,long GenericMapping);
long __stdcall ConvertToAutoInheritPrivateObjectSecurity(long ParentDescriptor,long CurrentSecurityDescriptor,long NewSecurityDescriptor,long ObjectType,long IsDirectoryObject,long GenericMapping);
long __stdcall CreatePrivateObjectSecurityEx(long ParentDescriptor,long CreatorDescriptor,long NewDescriptor,long ObjectType,long IsContainerObject,long AutoInheritFlags,long Token,long GenericMapping);
long __stdcall SetPrivateObjectSecurity(long SecurityInformation,long ModificationDescriptor,long ObjectsSecurityDescriptor,long GenericMapping,long Token);
long __stdcall SetPrivateObjectSecurityEx(long SecurityInformation,long ModificationDescriptor,long ObjectsSecurityDescriptor,long AutoInheritFlags,long GenericMapping,long Token);
long __stdcall GetPrivateObjectSecurity(long ObjectDescriptor,long SecurityInformation,long ResultantDescriptor,long DescriptorLength,long ReturnLength);
long __stdcall DestroyPrivateObjectSecurity(long ObjectDescriptor);
long __stdcall MakeSelfRelativeSD(long pAbsoluteSecurityDescriptor,long pSelfRelativeSecurityDescriptor,long lpdwBufferLength);
long __stdcall MakeAbsoluteSD(long pSelfRelativeSecurityDescriptor,long pAbsoluteSecurityDescriptor,long lpdwAbsoluteSecurityDescriptorSize,long pDacl,long lpdwDaclSize,long pSacl,long lpdwSaclSize,long pOwner,long lpdwOwnerSize,long pPrimaryGroup,long lpdwPrimaryGroupSize);
long __stdcall SetFileSecurity(long lpFileName,long SecurityInformation,long pSecurityDescriptor);
long __stdcall GetFileSecurity(long lpFileName,long RequestedInformation,long pSecurityDescriptor,long nLength,long lpnLengthNeeded);
long __stdcall SetKernelObjectSecurity(long Handle,long SecurityInformation,long SecurityDescriptor);
long __stdcall LookupAccountSid(long lpSystemName,long Sid,long Name,long cbName,long ReferencedDomainName,long cbReferencedDomainName,long peUse);
long __stdcall LookupAccountName(long lpSystemName,long lpAccountName,long Sid,long cbSid,long ReferencedDomainName,long cbReferencedDomainName,long peUse);
long __stdcall LookupPrivilegeValue(long lpSystemName,long lpName,long lpLuid);
long __stdcall LookupPrivilegeName(long lpSystemName,long lpLuid,long lpName,long cbName);
long __stdcall LookupPrivilegeDisplayName(long lpSystemName,long lpName,long lpDisplayName,long cbDisplayName,long lpLanguageId);
long __stdcall AllocateLocallyUniqueId(long Luid);
long __stdcall GetUserName(long lpBuffer,long nSize);


long __stdcall CreateProcessAsUser(long hToken,long lpApplicationName,long lpCommandLine,long lpProcessAttributes,long lpThreadAttributes,long bInheritHandles,long dwCreationFlags,long lpEnvironment,long lpCurrentDirectory,long lpStartupInfo,long lpProcessInformation);

long __stdcall GetCurrentHwProfile(long lpHwProfileInfo);

API(ConvertToAutoInheritPrivateObjectSecurity,advapi32)
API(CreatePrivateObjectSecurityEx,advapi32)
APIA(GetCurrentHwProfile,advapi32)



long __stdcall InterlockedIncrement(long lpAddend);
long __stdcall InterlockedDecrement(long lpAddend);
long __stdcall InterlockedExchange(long ,long );
long __stdcall InterlockedExchangeAdd(long Addend,long Value);
long __stdcall InterlockedCompareExchange(long Destination,long Exchange,long Comperand);
long __stdcall FreeResource(long hResData);
long __stdcall LockResource(long hResData);
long __stdcall FreeLibrary(long hLibModule);
VOID __stdcall FreeLibraryAndExitThread(long hLibModule,long dwExitCode);
long __stdcall DisableThreadLibraryCalls(long hLibModule);
long __stdcall GetProcAddress(long hModule,long lpProcName);
long __stdcall GetVersion(long);

long __stdcall GlobalAlloc(long uFlags,long dwBytes);
long __stdcall GlobalReAlloc(long hMem,long dwBytes,long uFlags);
long __stdcall GlobalSize(long hMem);
long __stdcall GlobalFlags(long hMem);
long __stdcall GlobalLock(long hMem);
long __stdcall GlobalHandle(long pMem);
long __stdcall GlobalUnlock(long hMem);
long __stdcall GlobalFree(long hMem);
long __stdcall GlobalCompact(long dwMinFree);
VOID __stdcall GlobalFix(long hMem);
VOID __stdcall GlobalUnfix(long hMem);
long __stdcall GlobalWire(long hMem);
long __stdcall GlobalUnWire(long hMem);
VOID __stdcall GlobalMemoryStatus(long lpBuffer);
long __stdcall LocalAlloc(long uFlags,long uBytes);
long __stdcall LocalReAlloc(long hMem,long uBytes,long uFlags);
long __stdcall LocalLock(long hMem);
long __stdcall LocalHandle(long pMem);
long __stdcall LocalUnlock(long hMem);
long __stdcall LocalSize(long hMem);
long __stdcall LocalFlags(long hMem);
long __stdcall LocalFree(long hMem);
long __stdcall LocalShrink(long hMem,long cbNewSize);
long __stdcall LocalCompact(long uMinFree);
long __stdcall FlushInstructionCache(long hProcess,long lpBaseAddress,long dwSize);
long __stdcall VirtualAlloc(long lpAddress,long dwSize,long flAllocationType,long flProtect);
long __stdcall VirtualFree(long lpAddress,long dwSize,long dwFreeType);
long __stdcall VirtualProtect(long lpAddress,long dwSize,long flNewProtect,long lpflOldProtect);
long __stdcall VirtualQuery(long lpAddress,long lpBuffer,long dwLength);
long __stdcall VirtualAllocEx(long hProcess,long lpAddress,long dwSize,long flAllocationType,long flProtect);
long __stdcall VirtualFreeEx(long hProcess,long lpAddress,long dwSize,long dwFreeType);
long __stdcall VirtualProtectEx(long hProcess,long lpAddress,long dwSize,long flNewProtect,long lpflOldProtect);
long __stdcall VirtualQueryEx(long hProcess,long lpAddress,long lpBuffer,long dwLength);

long __stdcall HeapCreate(long flOptions,long dwInitialSize,long dwMaximumSize);
long __stdcall HeapDestroy(long hHeap);
long __stdcall HeapAlloc(long hHeap,long dwFlags,long dwBytes);
long __stdcall HeapReAlloc(long hHeap,long dwFlags,long lpMem,long dwBytes);
long __stdcall HeapFree(long hHeap,long dwFlags,long lpMem);
long __stdcall HeapSize(long hHeap,long dwFlags,long lpMem);
long __stdcall HeapValidate(long hHeap,long dwFlags,long lpMem);
long __stdcall HeapCompact(long hHeap,long dwFlags);
long __stdcall GetProcessHeap(long);
long __stdcall GetProcessHeaps(long NumberOfHeaps,long ProcessHeaps);
long __stdcall HeapLock(long hHeap);
long __stdcall HeapUnlock(long hHeap);
long __stdcall HeapWalk(long hHeap,long lpEntry);

API(HeapCreate,kernel32)
API(HeapDestroy,kernel32)
API(HeapAlloc,kernel32)
API(HeapReAlloc,kernel32)
API(HeapFree,kernel32)
API(HeapSize,kernel32)
API(HeapUnlock,kernel32)
API(HeapLock,kernel32)
API(HeapCompact,kernel32)
API(HeapValidate,kernel32)
API(HeapWalk,kernel32)
API(GetProcessHeap,kernel32)
API(GetProcessHeaps,kernel32)

long __stdcall GetBinaryType(long lpApplicationName,long lpBinaryType);
long __stdcall GetShortPathName(long lpszLongPath,long lpszShortPath,long cchBuffer);
long __stdcall GetLongPathName(long lpszShortPath,long lpszLongPath,long cchBuffer);
long __stdcall GetProcessAffinityMask(long hProcess,long lpProcessAffinityMask,long lpSystemAffinityMask);
long __stdcall SetProcessAffinityMask(long hProcess,long dwProcessAffinityMask);
long __stdcall GetProcessTimes(long hProcess,long lpCreationTime,long lpExitTime,long lpKernelTime,long lpUserTime);
long __stdcall GetProcessWorkingSetSize(long hProcess,long lpMinimumWorkingSetSize,long lpMaximumWorkingSetSize);
long __stdcall SetProcessWorkingSetSize(long hProcess,long dwMinimumWorkingSetSize,long dwMaximumWorkingSetSize);
long __stdcall OpenProcess(long dwDesiredAccess,long bInheritHandle,long dwProcessId);
long __stdcall GetCurrentProcess(void);
long __stdcall GetCurrentProcessId(void);
VOID __stdcall ExitProcess(long uExitCode);
long __stdcall TerminateProcess(long hProcess,long uExitCode);
long __stdcall GetExitCodeProcess(long hProcess,long lpExitCode);
VOID __stdcall FatalExit(long ExitCode);
long __stdcall GetEnvironmentStrings(long);
long __stdcall FreeEnvironmentStrings(long);
VOID __stdcall RaiseException(long dwExceptionCode,long dwExceptionFlags,long nNumberOfArguments,long lpArguments);
long __stdcall UnhandledExceptionFilter(long ExceptionInfo);
long __stdcall SetUnhandledExceptionFilter(long lpTopLevelExceptionFilter);

APIA(GetLongPathName,kernel32)
API(GetProcessAffinityMask,kernel32)
API(SetProcessAffinityMask,kernel32)
API(GlobalAlloc,kernel32)
API(GlobalFree,kernel32)
API(GlobalHandle,kernel32)
API(GlobalLock,kernel32)
API(GlobalReAlloc,kernel32)
API(GlobalSize,kernel32)
API(GlobalUnlock,kernel32)
API(GlobalFlags,kernel32)
API(GlobalMemoryStatus,kernel32)
API(LocalAlloc,kernel32)
API(LocalFree,kernel32)
API(LocalHandle,kernel32)
API(LocalLock,kernel32)
API(LocalReAlloc,kernel32)
API(LocalSize,kernel32)
API(LocalUnlock,kernel32)
API(LocalFlags,kernel32)
API(FlushInstructionCache,kernel32)
API(VirtualAlloc,kernel32)
API(VirtualFree,kernel32)
API(VirtualAllocEx,kernel32)
API(VirtualFreeEx,kernel32)
API(VirtualProtect,kernel32)
API(VirtualQuery,kernel32)
API(VirtualProtectEx,kernel32)
API(VirtualQueryEx,kernel32)
API(HeapCreate,kernel32)
API(HeapDestroy,kernel32)
API(HeapAlloc,kernel32)
API(HeapReAlloc,kernel32)
API(HeapFree,kernel32)
API(HeapSize,kernel32)
API(GetProcessTimes,kernel32)
API(OpenProcess,kernel32)
API(GetCurrentProcess,kernel32)
API(GetCurrentProcessId,kernel32)
API(ExitProcess,kernel32)
API(TerminateProcess,kernel32)
API(GetExitCodeProcess,kernel32)


long __stdcall CreateFiber(long dwStackSize,long lpStartAddress,long lpParameter);
VOID __stdcall DeleteFiber(long lpFiber);
long __stdcall ConvertThreadToFiber(long lpParameter);
VOID __stdcall SwitchToFiber(long lpFiber);
long __stdcall SwitchToThread(long);
long __stdcall CreateThread(long lpThreadAttributes,long dwStackSize,long lpStartAddress,long lpParameter,long dwCreationFlags,long lpThreadId);
long __stdcall CreateRemoteThread(long hProcess,long lpThreadAttributes,long dwStackSize,long lpStartAddress,long lpParameter,long dwCreationFlags,long lpThreadId);
long __stdcall GetCurrentThread(void);
long __stdcall GetCurrentThreadId(void);
long __stdcall SetThreadAffinityMask(long hThread,long dwThreadAffinityMask);

long __stdcall SetProcessPriorityBoost(long hProcess,long bDisablePriorityBoost);
long __stdcall GetProcessPriorityBoost(long hProcess,long pDisablePriorityBoost);
long __stdcall RequestWakeupLatency(long latency);
long __stdcall SetThreadPriority(long hThread,long nPriority);
long __stdcall SetThreadPriorityBoost(long hThread,long bDisablePriorityBoost);
long __stdcall GetThreadPriorityBoost(long hThread,long pDisablePriorityBoost);
long __stdcall GetThreadPriority(long hThread);
long __stdcall GetThreadTimes(long hThread,long lpCreationTime,long lpExitTime,long lpKernelTime,long lpUserTime);
VOID __stdcall ExitThread(long dwExitCode);
long __stdcall TerminateThread(long hThread,long dwExitCode);
long __stdcall GetExitCodeThread(long hThread,long lpExitCode);
long __stdcall GetThreadSelectorEntry(long hThread,long dwSelector,long lpSelectorEntry);
long __stdcall SetThreadExecutionState(long esFlags);
long __stdcall SetProcessShutdownParameters(long dwLevel,long dwFlags);
long __stdcall GetProcessShutdownParameters(long lpdwLevel,long lpdwFlags);
long __stdcall GetProcessVersion(long ProcessId);

API(ConvertThreadToFiber,kernel32)
API(CreateFiber,kernel32)
API(DeleteFiber,kernel32)
API(SwitchToFiber,kernel32)
API(SwitchToThread,kernel32)
API(CreateThread,kernel32)
API(CreateRemoteThread,kernel32)
API(GetCurrentThread,kernel32)
API(GetCurrentThreadId,kernel32)
API(SetProcessPriorityBoost,kernel32)
API(GetProcessPriorityBoost,kernel32)
API(RequestWakeupLatency,kernel32)
API(GetThreadPriorityBoost,kernel32)
API(SetThreadPriorityBoost,kernel32)
API(SetThreadPriority,kernel32)
API(GetThreadPriority,kernel32)
API(GetThreadTimes,kernel32)
API(ExitThread,kernel32)
API(TerminateThread,kernel32)
API(GetExitCodeThread,kernel32)
API(GetThreadSelectorEntry,kernel32)
API(SetThreadExecutionState,kernel32)
API(SetProcessShutdownParameters,kernel32)
API(GetProcessShutdownParameters,kernel32)
API(GetProcessVersion,kernel32)

long __stdcall GetLastError();
VOID __stdcall SetLastError(long dwErrCode);
long __stdcall GetOverlappedResult(long hFile,long lpOverlapped,long lpNumberOfBytesTransferred,long bWait);
long __stdcall CreateIoCompletionPort(long FileHandle,long ExistingCompletionPort,long CompletionKey,long NumberOfConcurrentThreads);
long __stdcall GetQueuedCompletionStatus(long CompletionPort,long lpNumberOfBytesTransferred,long lpCompletionKey,long lpOverlapped,long dwMilliseconds);
long __stdcall PostQueuedCompletionStatus(long CompletionPort,long dwNumberOfBytesTransferred,long dwCompletionKey,long lpOverlapped);
long __stdcall SetErrorMode(long uMode);
long __stdcall ReadProcessMemory(long hProcess,long lpBaseAddress,long lpBuffer,long nSize,long lpNumberOfBytesRead);
long __stdcall WriteProcessMemory(long hProcess,long lpBaseAddress,long lpBuffer,long nSize,long lpNumberOfBytesWritten);
long __stdcall GetThreadContext(long hThread,long lpContext);
long __stdcall SetThreadContext(long hThread,long lpContext);
long __stdcall SuspendThread(long hThread);
long __stdcall ResumeThread(long hThread);


VOID __stdcall DebugBreak(long);
long __stdcall WaitForDebugEvent(long lpDebugEvent,long dwMilliseconds);
long __stdcall ContinueDebugEvent(long dwProcessId,long dwThreadId,long dwContinueStatus);
long __stdcall DebugActiveProcess(long dwProcessId);
VOID __stdcall InitializeCriticalSection(long lpCriticalSection);
VOID __stdcall EnterCriticalSection(long lpCriticalSection);
VOID __stdcall LeaveCriticalSection(long lpCriticalSection);
long __stdcall InitializeCriticalSectionAndSpinCount(long lpCriticalSection,long dwSpinCount);
long __stdcall SetCriticalSectionSpinCount(long lpCriticalSection,long dwSpinCount);
long __stdcall TryEnterCriticalSection(long lpCriticalSection);
VOID __stdcall DeleteCriticalSection(long lpCriticalSection);
long __stdcall SetEvent(long hEvent);
long __stdcall ResetEvent(long hEvent);
long __stdcall PulseEvent(long hEvent);
long __stdcall ReleaseSemaphore(long hSemaphore,long lReleaseCount,long lpPreviousCount);
long __stdcall ReleaseMutex(long hMutex);
long __stdcall WaitForSingleObject(long hHandle,long dwMilliseconds);
long __stdcall WaitForMultipleObjects(long nCount,long lpHandles,long bWaitAll,long dwMilliseconds);
VOID __stdcall Sleep(long dwMilliseconds);
long __stdcall LoadResource(long hModule,long hResInfo);
long __stdcall SizeofResource(long hModule,long hResInfo);

long __stdcall InitAtomTable(long nSize);
long __stdcall AddAtom(long lpString);
long __stdcall FindAtom(long lpString);
long __stdcall GetAtomName(long nAtom,long lpBuffer,long nSize);
long __stdcall DeleteAtom(long nAtom);
long __stdcall GlobalDeleteAtom(long nAtom);
long __stdcall GlobalAddAtom(long lpString);
long __stdcall GlobalFindAtom(long lpString);
long __stdcall GlobalGetAtomName(long nAtom,long lpBuffer,long nSize);

API(InitAtomTable,kernel32)
APIA(AddAtom,kernel32)
APIA(FindAtom,kernel32)
API(DeleteAtom,kernel32)
APIA(GetAtomName,kernel32)
APIA(GlobalAddAtom,kernel32)
API(GlobalDeleteAtom,kernel32)
APIA(GlobalFindAtom,kernel32)
APIA(GlobalGetAtomName,kernel32)

long __stdcall SetHandleCount(long uNumber);
long __stdcall GetLogicalDrives(long);
long __stdcall LockFile(long hFile,long dwFileOffsetLow,long dwFileOffsetHigh,long nNumberOfBytesToLockLow,long nNumberOfBytesToLockHigh);
long __stdcall UnlockFile(long hFile,long dwFileOffsetLow,long dwFileOffsetHigh,long nNumberOfBytesToUnlockLow,long nNumberOfBytesToUnlockHigh);
long __stdcall LockFileEx(long hFile,long dwFlags,long dwReserved,long nNumberOfBytesToLockLow,long nNumberOfBytesToLockHigh,long lpOverlapped);
long __stdcall UnlockFileEx(long hFile,long dwReserved,long nNumberOfBytesToUnlockLow,long nNumberOfBytesToUnlockHigh,long lpOverlapped);
long __stdcall GetFileInformationByHandle(long hFile,long lpFileInformation);
long __stdcall GetFileType(long hFile);
long __stdcall GetFileSize(long hFile,long lpFileSizeHigh);
long __stdcall GetStdHandle(long nStdHandle);
long __stdcall SetStdHandle(long nStdHandle,long hHandle);
long __stdcall WriteFile(long hFile,long lpBuffer,long nNumberOfBytesToWrite,long lpNumberOfBytesWritten,long lpOverlapped);
long __stdcall ReadFile(long hFile,long lpBuffer,long nNumberOfBytesToRead,long lpNumberOfBytesRead,long lpOverlapped);
long __stdcall FlushFileBuffers(long hFile);
long __stdcall DeviceIoControl(long hDevice,long dwIoControlCode,long lpInBuffer,long nInBufferSize,long lpOutBuffer,long nOutBufferSize,long lpBytesReturned,long lpOverlapped);
long __stdcall SetEndOfFile(long hFile);
long __stdcall SetFilePointer(long hFile,long lDistanceToMove,long lpDistanceToMoveHigh,long dwMoveMethod);
long __stdcall FindClose(long hFindFile);
long __stdcall GetFileTime(long hFile,long lpCreationTime,long lpLastAccessTime,long lpLastWriteTime);
long __stdcall SetFileTime(long hFile,long lpCreationTime,long lpLastAccessTime,long lpLastWriteTime);
long __stdcall CloseHandle(long hObject);
long __stdcall DuplicateHandle(long hSourceProcessHandle,long hSourceHandle,long hTargetProcessHandle,long lpTargetHandle,long dwDesiredAccess,long bInheritHandle,long dwOptions);
long __stdcall GetHandleInformation(long hObject,long lpdwFlags);
long __stdcall SetHandleInformation(long hObject,long dwMask,long dwFlags);
long __stdcall LoadModule(long lpModuleName,long lpParameterBlock);

long __stdcall GetDevicePowerState(long hFile);
long __stdcall WinExec(long lpCmdLine,long uCmdShow);
long __stdcall ClearCommBreak(long hFile);
long __stdcall ClearCommError(long hFile,long lpErrors,long lpStat);
long __stdcall SetupComm(long hFile,long dwInQueue,long dwOutQueue);
long __stdcall EscapeCommFunction(long hFile,long dwFunc);
long __stdcall GetCommConfig(long hCommDev,long lpCC,long lpdwSize);
long __stdcall GetCommMask(long hFile,long lpEvtMask);
long __stdcall GetCommProperties(long hFile,long lpCommProp);
long __stdcall GetCommModemStatus(long hFile,long lpModemStat);
long __stdcall GetCommState(long hFile,long lpDCB);
long __stdcall GetCommTimeouts(long hFile,long lpCommTimeouts);
long __stdcall PurgeComm(long hFile,long dwFlags);
long __stdcall SetCommBreak(long hFile);
long __stdcall SetCommConfig(long hCommDev,long lpCC,long dwSize);
long __stdcall SetCommMask(long hFile,long dwEvtMask);
long __stdcall SetCommState(long hFile,long lpDCB);
long __stdcall SetCommTimeouts(long hFile,long lpCommTimeouts);
long __stdcall TransmitCommChar(long hFile,long cChar);
long __stdcall WaitCommEvent(long hFile,long lpEvtMask,long lpOverlapped);
long __stdcall SetTapePosition(long hDevice,long dwPositionMethod,long dwPartition,long dwOffsetLow,long dwOffsetHigh,long bImmediate);
long __stdcall GetTapePosition(long hDevice,long dwPositionType,long lpdwPartition,long lpdwOffsetLow,long lpdwOffsetHigh);
long __stdcall PrepareTape(long hDevice,long dwOperation,long bImmediate);
long __stdcall EraseTape(long hDevice,long dwEraseType,long bImmediate);
long __stdcall CreateTapePartition(long hDevice,long dwPartitionMethod,long dwCount,long dwSize);
long __stdcall WriteTapemark(long hDevice,long dwTapemarkType,long dwTapemarkCount,long bImmediate);
long __stdcall GetTapeStatus(long hDevice);
long __stdcall GetTapeParameters(long hDevice,long dwOperation,long lpdwSize,long lpTapeInformation);
long __stdcall SetTapeParameters(long hDevice,long dwOperation,long lpTapeInformation);
long __stdcall Beep(long dwFreq,long dwDuration);
long __stdcall MulDiv(long nNumber,long nNumerator,long nDenominator);

API(GetDevicePowerState,kernel32)

VOID __stdcall GetSystemTime(long lpSystemTime);
VOID __stdcall GetSystemTimeAsFileTime(long lpSystemTimeAsFileTime);
long __stdcall SetSystemTime(long lpSystemTime);
VOID __stdcall GetLocalTime(long lpSystemTime);
long __stdcall SetLocalTime(long lpSystemTime);
VOID __stdcall GetSystemInfo(long lpSystemInfo);

long __stdcall SystemTimeToTzSpecificLocalTime(long lpTimeZoneInformation,long lpUniversalTime,long lpLocalTime);
long __stdcall GetTimeZoneInformation(long lpTimeZoneInformation);
long __stdcall SetTimeZoneInformation(long lpTimeZoneInformation);
long __stdcall SystemTimeToFileTime(long lpSystemTime,long lpFileTime);
long __stdcall FileTimeToLocalFileTime(long lpFileTime,long lpLocalFileTime);
long __stdcall LocalFileTimeToFileTime(long lpLocalFileTime,long lpFileTime);
long __stdcall FileTimeToSystemTime(long lpFileTime,long lpSystemTime);
long __stdcall CompareFileTime(long lpFileTime1,long lpFileTime2);
long __stdcall FileTimeToDosDateTime(long lpFileTime,long lpFatDate,long lpFatTime);
long __stdcall DosDateTimeToFileTime(long wFatDate,long wFatTime,long lpFileTime);
long __stdcall GetTickCount(void);
long __stdcall SetSystemTimeAdjustment(long dwTimeAdjustment,long bTimeAdjustmentDisabled);
long __stdcall GetSystemTimeAdjustment(long lpTimeAdjustment,long lpTimeIncrement,long lpTimeAdjustmentDisabled);

API(GetSystemTimeAsFileTime,kernel32)
API(GetSystemTime,kernel32)
API(SetSystemTime,kernel32)
API(GetLocalTime,kernel32)
API(SetLocalTime,kernel32)
API(GetSystemInfo,kernel32)
API(GetTimeZoneInformation,kernel32)
API(SetTimeZoneInformation,kernel32)
API(SystemTimeToFileTime,kernel32)
API(FileTimeToLocalFileTime,kernel32)
API(LocalFileTimeToFileTime,kernel32)
API(FileTimeToSystemTime,kernel32)
API(CompareFileTime,kernel32)
API(FileTimeToDosDateTime,kernel32)
API(DosDateTimeToFileTime,kernel32)
API(GetTickCount,kernel32)
API(SetSystemTimeAdjustment,kernel32)
API(GetSystemTimeAdjustment,kernel32)


long __stdcall FormatMessage(long dwFlags,long lpSource,long dwMessageId,long dwLanguageId,long lpBuffer,long nSize,long Arguments);
long __stdcall CreatePipe(long hReadPipe,long hWritePipe,long lpPipeAttributes,long nSize);
long __stdcall ConnectNamedPipe(long hNamedPipe,long lpOverlapped);
long __stdcall DisconnectNamedPipe(long hNamedPipe);
long __stdcall SetNamedPipeHandleState(long hNamedPipe,long lpMode,long lpMaxCollectionCount,long lpCollectDataTimeout);
long __stdcall GetNamedPipeInfo(long hNamedPipe,long lpFlags,long lpOutBufferSize,long lpInBufferSize,long lpMaxInstances);
long __stdcall PeekNamedPipe(long hNamedPipe,long lpBuffer,long nBufferSize,long lpBytesRead,long lpTotalBytesAvail,long lpBytesLeftThisMessage);
long __stdcall TransactNamedPipe(long hNamedPipe,long lpInBuffer,long nInBufferSize,long lpOutBuffer,long nOutBufferSize,long lpBytesRead,long lpOverlapped);
long __stdcall CreateMailslot(long lpName,long nMaxMessageSize,long lReadTimeout,long lpSecurityAttributes);
long __stdcall GetMailslotInfo(long hMailslot,long lpMaxMessageSize,long lpNextSize,long lpMessageCount,long lpReadTimeout);
long __stdcall SetMailslotInfo(long hMailslot,long lReadTimeout);
long __stdcall MapViewOfFile(long hFileMappingObject,long dwDesiredAccess,long dwFileOffsetHigh,long dwFileOffsetLow,long dwNumberOfBytesToMap);

long __stdcall FlushViewOfFile(long lpBaseAddress,long dwNumberOfBytesToFlush);
long __stdcall UnmapViewOfFile(long lpBaseAddress);


long __stdcall lstrcmp(long lpString1,long lpString2);
long __stdcall lstrcmpi(long lpString1,long lpString2);
long __stdcall lstrcpyn(long lpString1,long lpString2,long iMaxLength);
long __stdcall lstrcpy(long lpString1,long lpString2);
long __stdcall lstrcat(long lpString1,long lpString2);
long __stdcall lstrlen(long lpString);
long __stdcall OpenFile(long lpFileName,long lpReOpenBuff,long uStyle);
# 8341 "/home/felix/gstudio8/include/windows.h"
long __stdcall TlsAlloc(long);
long __stdcall TlsGetValue(long dwTlsIndex);
long __stdcall TlsSetValue(long dwTlsIndex,long lpTlsValue);
long __stdcall TlsFree(long dwTlsIndex);
long __stdcall SleepEx(long dwMilliseconds,long bAlertable);
long __stdcall WaitForSingleObjectEx(long hHandle,long dwMilliseconds,long bAlertable);
long __stdcall WaitForMultipleObjectsEx(long nCount,long lpHandles,long bWaitAll,long dwMilliseconds,long bAlertable);

long __stdcall ReadFileEx(long hFile,long lpBuffer,long nNumberOfBytesToRead,long lpOverlapped,long lpCompletionRoutine);
long __stdcall WriteFileEx(long hFile,long lpBuffer,long nNumberOfBytesToWrite,long lpOverlapped,long lpCompletionRoutine);
long __stdcall BackupRead(long hFile,long lpBuffer,long nNumberOfBytesToRead,long lpNumberOfBytesRead,long bAbort,long bProcessSecurity,long lpContext);
long __stdcall BackupSeek(long hFile,long dwLowBytesToSeek,long dwHighBytesToSeek,long lpdwLowByteSeeked,long lpdwHighByteSeeked,long lpContext);
long __stdcall BackupWrite(long hFile,long lpBuffer,long nNumberOfBytesToWrite,long lpNumberOfBytesWritten,long bAbort,long bProcessSecurity,long lpContext);


long __stdcall CreateMutex(long lpMutexAttributes,long bInitialOwner,long lpName);
long __stdcall OpenMutex(long dwDesiredAccess,long bInheritHandle,long lpName);
long __stdcall CreateEvent(long lpEventAttributes,long bManualReset,long bInitialState,long lpName);
long __stdcall OpenEvent(long dwDesiredAccess,long bInheritHandle,long lpName);
long __stdcall CreateSemaphore(long lpSemaphoreAttributes,long lInitialCount,long lMaximumCount,long lpName);
long __stdcall OpenSemaphore(long dwDesiredAccess,long bInheritHandle,long lpName);

long __stdcall CreateWaitableTimer(long lpTimerAttributes,long bManualReset,long lpTimerName);
long __stdcall OpenWaitableTimer(long dwDesiredAccess,long bInheritHandle,long lpTimerName);
long __stdcall SetWaitableTimer(long hTimer,long lpDueTime,long lPeriod,long pfnCompletionRoutine,long lpArgToCompletionRoutine,long fResume);
long __stdcall CancelWaitableTimer(long hTimer);

APIA(CreateWaitableTimer,kernel32)
APIA(OpenWaitableTimer,kernel32)
API(SetWaitableTimer,kernel32)
API(CancelWaitableTimer,kernel32)

long __stdcall CreateFileMapping(long hFile,long lpFileMappingAttributes,long flProtect,long dwMaximumSizeHigh,long dwMaximumSizeLow,long lpName);
long __stdcall OpenFileMapping(long dwDesiredAccess,long bInheritHandle,long lpName);
long __stdcall GetLogicalDriveStrings(long nBufferLength,long lpBuffer);
long __stdcall LoadLibrary(long lpLibFileName);
long __stdcall LoadLibraryEx(long lpLibFileName,long hFile,long dwFlags);
long __stdcall GetModuleFileName(long hModule,long lpFilename,long nSize);
long __stdcall GetModuleHandle(long lpModuleName);
long __stdcall CreateProcess(long lpApplicationName,long lpCommandLine,long lpProcessAttributes,long lpThreadAttributes,long bInheritHandles,long dwCreationFlags,long lpEnvironment,long lpCurrentDirectory,long lpStartupInfo,long lpProcessInformation);
VOID __stdcall FatalAppExit(long uAction,long lpMessageText);
VOID __stdcall GetStartupInfo(long lpStartupInfo);
long __stdcall GetCommandLine(long);
long __stdcall GetEnvironmentVariable(long lpName,long lpBuffer,long nSize);
long __stdcall SetEnvironmentVariable(long lpName,long lpValue);
long __stdcall ExpandEnvironmentStrings(long lpSrc,long lpDst,long nSize);
VOID __stdcall OutputDebugString(long lpOutputString);
long __stdcall FindResource(long hModule,long lpName,long lpType);
long __stdcall FindResourceEx(long hModule,long lpType,long lpName,long wLanguage);
long __stdcall EnumResourceTypes(long hModule,long lpEnumFunc,long lParam);
long __stdcall EnumResourceNames(long hModule,long lpType,long lpEnumFunc,long lParam);
long __stdcall EnumResourceLanguages(long hModule,long lpType,long lpName,long lpEnumFunc,long lParam);
long __stdcall BeginUpdateResource(long pFileName,long bDeleteExistingResources);
long __stdcall UpdateResource(long hUpdate,long lpType,long lpName,long wLanguage,long lpData,long cbData);
long __stdcall EndUpdateResource(long hUpdate,long fDiscard);

long __stdcall GetProfileInt(long lpAppName,long lpKeyName,long nDefault);
long __stdcall GetProfileString(long lpAppName,long lpKeyName,long lpDefault,long lpReturnedString,long nSize);
long __stdcall WriteProfileString(long lpAppName,long lpKeyName,long lpString);
long __stdcall GetProfileSection(long lpAppName,long lpReturnedString,long nSize);
long __stdcall WriteProfileSection(long lpAppName,long lpString);
long __stdcall GetPrivateProfileInt(long lpAppName,long lpKeyName,long nDefault,long lpFileName);
long __stdcall GetPrivateProfileString(long lpAppName,long lpKeyName,long lpDefault,long lpReturnedString,long nSize,long lpFileName);
long __stdcall WritePrivateProfileString(long lpAppName,long lpKeyName,long lpString,long lpFileName);
long __stdcall GetPrivateProfileSection(long lpAppName,long lpReturnedString,long nSize,long lpFileName);
long __stdcall WritePrivateProfileSection(long lpAppName,long lpString,long lpFileName);
long __stdcall GetPrivateProfileSectionNames(long lpszReturnBuffer,long nSize,long lpFileName);
long __stdcall GetPrivateProfileStruct(long lpszSection,long lpszKey,long lpStruct,long uSizeStruct,long szFile);
long __stdcall WritePrivateProfileStruct(long lpszSection,long lpszKey,long lpStruct,long uSizeStruct,long szFile);

APIA(GetProfileInt,kernel32)
APIA(GetProfileString,kernel32)
APIA(WriteProfileString,kernel32)
APIA(GetProfileSection,kernel32)
APIA(WriteProfileSection,kernel32)
APIA(GetPrivateProfileInt,kernel32)
APIA(GetPrivateProfileString,kernel32)
APIA(WritePrivateProfileString,kernel32)
APIA(GetPrivateProfileSection,kernel32)
APIA(WritePrivateProfileSection,kernel32)
APIA(GetPrivateProfileSectionNames,kernel32)
APIA(GetPrivateProfileStruct,kernel32)
APIA(WritePrivateProfileStruct,kernel32)

long __stdcall GetDriveType(char* lpRootPathName);
long __stdcall GetTempPath(long nBufferLength,long lpBuffer);
long __stdcall GetTempFileName(char* lpPathName,long lpPrefixString,long uUnique,long lpTempFileName);
long __stdcall GetSystemDirectory(long lpBuffer,long uSize);
long __stdcall GetWindowsDirectory(long lpBuffer,long uSize);
long __stdcall SetCurrentDirectory(char* lpPathName);
long __stdcall GetCurrentDirectory(long nBufferLength,long lpBuffer);
long __stdcall GetDiskFreeSpace(char* lpRootPathName,long lpSectorsPerCluster,long lpBytesPerSector,long lpNumberOfFreeClusters,long lpTotalNumberOfClusters);
long __stdcall GetDiskFreeSpaceEx(char* lpDirectoryName,long lpFreeBytesAvailableToCaller,long lpTotalNumberOfBytes,long lpTotalNumberOfFreeBytes);
long __stdcall CreateDirectory(char* lpPathName,long lpSecurityAttributes);
long __stdcall CreateDirectoryEx(long lpTemplateDirectory,long lpNewDirectory,long lpSecurityAttributes);
long __stdcall RemoveDirectory(char* lpPathName);
long __stdcall GetFullPathName(char* lpFileName,long nBufferLength,long lpBuffer,long lpFilePart);
long __stdcall DefineDosDevice(long dwFlags,char* lpDeviceName,char* lpTargetPath);
long __stdcall QueryDosDevice(char* lpDeviceName,char* lpTargetPath,long ucchMax);
long __stdcall CreateFile(char* lpFileName,long dwDesiredAccess,long dwShareMode,long lpSecurityAttributes,long dwCreationDisposition,long dwFlagsAndAttributes,long hTemplateFile);
long __stdcall SetFileAttributes(char* lpFileName,long dwFileAttributes);
long __stdcall GetFileAttributes(char* lpFileName);
long __stdcall GetFileAttributesEx(char* lpFileName,long fInfoLevelId,long lpFileInformation);
long __stdcall GetCompressedFileSize(char* lpFileName,long lpFileSizeHigh);
long __stdcall DeleteFile(char* lpFileName);
long __stdcall FindFirstFileEx(char* lpFileName,long fInfoLevelId,WIN32_FIND_DATA *lpFindFileData,long fSearchOp,long lpSearchFilter,long dwAdditionalFlags);
long __stdcall FindFirstFile(char* lpFileName,WIN32_FIND_DATA *lpFindFileData);
long __stdcall FindNextFile(long hFindFile,WIN32_FIND_DATA *lpFindFileData);
long __stdcall SearchPath(char* lpPath,char* lpFileName,char* lpExtension,long nBufferLength,long lpBuffer,long lpFilePart);
long __stdcall CopyFile(char* lpExistingFileName,char* lpNewFileName,long bFailIfExists);
long __stdcall CopyFileEx(char* lpExistingFileName,char* lpNewFileName,long lpProgressRoutine,long lpData,long pbCancel,long dwCopyFlags);
long __stdcall MoveFile(char* lpExistingFileName,char* lpNewFileName);
long __stdcall MoveFileEx(char* lpExistingFileName,char* lpNewFileName,long dwFlags);
long __stdcall MoveFileWithProgress(char* lpExistingFileName,char* lpNewFileName,long lpProgressRoutine,long lpData,long dwFlags);

BOOL __stdcall SHGetSpecialFolderPath(HWND hwndOwner,LPTSTR lpszPath,int nFolder,BOOL fCreate);

APIA(FindFirstFileEx,kernel32)
APIA(GetWindowsDirectory,kernel32)
APIA(GetSystemDirectory,kernel32)
APIA(GetTempPath,kernel32)
APIA(SetCurrentDirectory,kernel32)
APIA(GetCurrentDirectory,kernel32)
APIA(GetDiskFreeSpace,kernel32)
APIA(GetDiskFreeSpaceEx,kernel32)
APIA(CreateDirectory,kernel32)
APIA(CreateDirectoryEx,kernel32)
APIA(RemoveDirectory,kernel32)
APIA(GetFullPathName,kernel32)
APIA(DefineDosDevice,kernel32)
APIA(QueryDosDevice,kernel32)
APIA(CreateFile,kernel32)
APIA(SetFileAttributes,kernel32)
APIA(GetFileAttributes,kernel32)
APIA(GetFileAttributesEx,kernel32)
APIA(DeleteFile,kernel32)
APIA(FindFirstFile,kernel32)
APIA(FindNextFile,kernel32)
APIA(SearchPath,kernel32)
APIA(CopyFile,kernel32)
APIA(MoveFile,kernel32)
APIA(MoveFileEx,kernel32)
APIA(MoveFileWithProgress,kernel32)
APIA(CreateNamedPipe,kernel32)
APIA(GetNamedPipeHandleState,kernel32)
APIA(CallNamedPipe,kernel32)
APIA(WaitNamedPipe,kernel32)
APIA(SetVolumeLabel,kernel32)
API(SetFileApisToOEM,kernel32)
APIA(GetVolumeInformation,kernel32)

long __stdcall CreateHardLink(long lpFileName,long lpExistingFileName,long lpSecurityAttributes);
long __stdcall CreateNamedPipe(long lpName,long dwOpenMode,long dwPipeMode,long nMaxInstances,long nOutBufferSize,long nInBufferSize,long nDefaultTimeOut,long lpSecurityAttributes);
long __stdcall GetNamedPipeHandleState(long hNamedPipe,long lpState,long lpCurInstances,long lpMaxCollectionCount,long lpCollectDataTimeout,long lpUserName,long nMaxUserNameSize);
long __stdcall CallNamedPipe(long lpNamedPipeName,long lpInBuffer,long nInBufferSize,long lpOutBuffer,long nOutBufferSize,long lpBytesRead,long nTimeOut);
long __stdcall WaitNamedPipe(long lpNamedPipeName,long nTimeOut);
long __stdcall SetVolumeLabel(long lpRootPathName,long lpVolumeName);

APIA(CopyFileEx,kernel32)
APIA(CreateHardLink,kernel32)

VOID __stdcall SetFileApisToOEM(long);
VOID __stdcall SetFileApisToANSI(long);
long __stdcall AreFileApisANSI(long);
API(AreFileApisANSI,kernel32)

long __stdcall GetVolumeInformation(long lpRootPathName,long lpVolumeNameBuffer,long nVolumeNameSize,long lpVolumeSerialNumber,long lpMaximumComponentLength,long lpFileSystemFlags,long lpFileSystemNameBuffer,long nFileSystemNameSize);
long __stdcall CancelIo(long hFile);
API(CancelIo,kernel32)

long __stdcall FindFirstChangeNotification(long lpPathName,long bWatchSubtree,long dwNotifyFilter);
long __stdcall FindNextChangeNotification(long hChangeHandle);
long __stdcall FindCloseChangeNotification(long hChangeHandle);
long __stdcall VirtualLock(long lpAddress,long dwSize);
long __stdcall VirtualUnlock(long lpAddress,long dwSize);
long __stdcall MapViewOfFileEx(long hFileMappingObject,long dwDesiredAccess,long dwFileOffsetHigh,long dwFileOffsetLow,long dwNumberOfBytesToMap,long lpBaseAddress);
long __stdcall SetPriorityClass(long hProcess,long dwPriorityClass);
long __stdcall GetPriorityClass(long hProcess);
long __stdcall IsBadReadPtr(long lp,long ucb);
long __stdcall IsBadWritePtr(long lp,long ucb);
long __stdcall IsBadHugeReadPtr(long lp,long ucb);
long __stdcall IsBadHugeWritePtr(long lp,long ucb);
long __stdcall IsBadCodePtr(long lpfn);
long __stdcall IsBadStringPtr(long lpsz,long ucchMax);
long __stdcall BuildCommDCB(long lpDef,long lpDCB);
long __stdcall BuildCommDCBAndTimeouts(long lpDef,long lpDCB,long lpCommTimeouts);
long __stdcall CommConfigDialog(long lpszName,long hWnd,long lpCC);
long __stdcall GetDefaultCommConfig(long lpszName,long lpCC,long lpdwSize);
long __stdcall SetDefaultCommConfig(long lpszName,long lpCC,long dwSize);
long __stdcall GetComputerName(long lpBuffer,long nSize);
long __stdcall SetComputerName(long lpComputerName);
long __stdcall QueryPerformanceCounter(long lpPerformanceCount);
long __stdcall QueryPerformanceFrequency(long lpFrequency);
long __stdcall GetVersionEx(long lpVersionInformation);
# 8545 "/home/felix/gstudio8/include/windows.h"
long __stdcall CreateJobObject(long lpJobAttributes,long lpName);
long __stdcall OpenJobObject(long dwDesiredAccess,long bInheritHandle,long lpName);
long __stdcall AssignProcessToJobObject(long hJob,long hProcess);
long __stdcall TerminateJobObject(long hJob,long uExitCode);



API(AssignProcessToJobObject,kernel32)
APIA(CreateJobObject,kernel32)
APIA(OpenJobObject,kernel32)
API(TerminateJobObject,kernel32)

long __stdcall DuplicateTokenEx(long ,long ,long ,long ,long ,long );
long __stdcall CreateRestrictedToken(long ,long ,long ,long ,long ,long ,long ,long ,long );
API(CreateRestrictedToken,advapi32)

BOOL __stdcall AllocConsole();
BOOL __stdcall FreeConsole();
BOOL __stdcall SetConsoleTitle(char* lpConsoleTitle);

long __stdcall DeviceCapabilities(long,long,long,long,long);
APIA(DeviceCapabilities,winspool.drv)

API(InitCommonControls,comctl32)

API(InterlockedIncrement,kernel32)
API(InterlockedDecrement,kernel32)
API(InterlockedExchange,kernel32)
API(InterlockedExchangeAdd,kernel32)
API(InterlockedCompareExchange,kernel32)
APIA(GetModuleFileName,kernel32)
APIA(GetModuleHandle,kernel32)
APIA(CreateProcess,kernel32)
APIA(FatalAppExit,kernel32)
APIA(GetStartupInfo,kernel32)
APIA(GetCommandLine,kernel32)
APIA(GetEnvironmentVariable,kernel32)
APIA(SetEnvironmentVariable,kernel32)
APIA(ExpandEnvironmentStrings,kernel32)
APIA(LoadLibrary,kernel32)
APIA(LoadLibraryEx,kernel32)
API(LoadModule,kernel32)
API(FreeLibrary,kernel32)
API(WinExec,kernel32)
API(DebugBreak,kernel32)
API(ContinueDebugEvent,kernel32)
API(WaitForDebugEvent,kernel32)
API(DebugActiveProcess,kernel32)
API(InitializeCriticalSection,kernel32)
API(EnterCriticalSection,kernel32)
API(LeaveCriticalSection,kernel32)
API(DeleteCriticalSection,kernel32)
API(InitializeCriticalSectionAndSpinCount,kernel32)
API(SetCriticalSectionSpinCount,kernel32)
API(TryEnterCriticalSection,kernel32)
API(SetEvent,kernel32)
API(ResetEvent,kernel32)
API(PulseEvent,kernel32)
API(ReleaseSemaphore,kernel32)
API(ReleaseMutex,kernel32)
API(WaitForSingleObject,kernel32)
API(WaitForMultipleObjects,kernel32)
API(Sleep,kernel32)
APIA(OutputDebugString,kernel32)
API(GetVersion,kernel32)
API(OpenFile,kernel32)
APIA(GetTempFileName,kernel32)
API(SetHandleCount,kernel32)
API(GetLogicalDrives,kernel32)
API(LockFile,kernel32)
API(UnlockFile,kernel32)
API(LockFileEx,kernel32)
API(UnlockFileEx,kernel32)
API(GetFileInformationByHandle,kernel32)
API(GetFileType,kernel32)
API(GetFileSize,kernel32)
API(GetStdHandle,kernel32)
API(SetStdHandle,kernel32)
API(WriteFile,kernel32)
API(ReadFile,kernel32)
API(FlushFileBuffers,kernel32)
API(DeviceIoControl,kernel32)
API(SetEndOfFile,kernel32)
API(SetFilePointer,kernel32)
API(FindClose,kernel32)
API(GetFileTime,kernel32)
API(SetFileTime,kernel32)
API(CloseHandle,kernel32)
API(DuplicateHandle,kernel32)
APIA(GetDriveType,kernel32)

API(GetLastError,kernel32)
API(SetLastError,kernel32)
API(SetLastErrorEx,user32)
API(GetOverlappedResult,kernel32)
API(SetDebugErrorLevel,user32)
API(SetErrorMode,kernel32)
API(ReadProcessMemory,kernel32)
API(WriteProcessMemory,kernel32)
API(GetThreadContext,kernel32)
API(SetThreadContext,kernel32)
API(SuspendThread,kernel32)
API(ResumeThread,kernel32)
APIA(FindResource,kernel32)
APIA(FindResourceEx,kernel32)
APIA(BeginUpdateResource,kernel32)
APIA(UpdateResource,kernel32)
APIA(EndUpdateResource,kernel32)
API(LoadResource,kernel32)
API(LockResource,kernel32)
API(SizeofResource,kernel32)

APIA(ClearEventLog,advapi32)
APIA(BackupEventLog,advapi32)
API(CloseEventLog,advapi32)
API(DeregisterEventSource,advapi32)
API(GetNumberOfEventLogRecords,advapi32)
API(GetOldestEventLogRecord,advapi32)
APIA(OpenEventLog,advapi32)
APIA(RegisterEventSource,advapi32)
APIA(OpenBackupEventLog,advapi32)
APIA(ReadEventLog,advapi32)
APIA(ReportEvent,advapi32)
API(DuplicateToken,advapi32)
API(GetKernelObjectSecurity,advapi32)
API(ImpersonateNamedPipeClient,advapi32)
API(ImpersonateSelf,advapi32)
API(RevertToSelf,advapi32)
API(OpenProcessToken,advapi32)
API(OpenThreadToken,advapi32)
API(GetTokenInformation,advapi32)
API(SetTokenInformation,advapi32)
API(AdjustTokenPrivileges,advapi32)
API(AdjustTokenGroups,advapi32)
API(PrivilegeCheck,advapi32)
APIA(ObjectOpenAuditAlarm,kernel32)
APIA(ObjectPrivilegeAuditAlarm,advapi32)
APIA(ObjectOpenAuditAlarm,advapi32)
APIA(ObjectCloseAuditAlarm,advapi32)
APIA(ObjectDeleteAuditAlarm,advapi32)
APIA(PrivilegedServiceAuditAlarm,advapi32)
API(IsValidSid,advapi32)
API(EqualSid,advapi32)
API(EqualPrefixSid,advapi32)
API(GetSidLengthRequired,advapi32)
API(AllocateAndInitializeSid,advapi32)
API(FreeSid,advapi32)
API(InitializeSid,advapi32)
API(GetSidIdentifierAuthority,advapi32)
API(GetSidSubAuthority,advapi32)
API(GetSidSubAuthorityCount,advapi32)
API(GetLengthSid,advapi32)
API(CopySid,advapi32)
API(AreAllAccessesGranted,advapi32)
API(AreAnyAccessesGranted,advapi32)
API(MapGenericMask,advapi32)
API(IsValidAcl,advapi32)
API(InitializeAcl,advapi32)
API(GetAclInformation,advapi32)
API(SetAclInformation,advapi32)
API(AddAce,advapi32)
API(DeleteAce,advapi32)
API(GetAce,advapi32)
API(AddAccessAllowedAce,advapi32)
API(AddAccessDeniedAce,advapi32)
API(AddAuditAccessAce,advapi32)
API(FindFirstFreeAce,advapi32)
API(InitializeSecurityDescriptor,advapi32)
API(IsValidSecurityDescriptor,advapi32)
API(GetSecurityDescriptorLength,advapi32)
API(SetSecurityDescriptorControl,advapi32)
API(GetSecurityDescriptorControl,advapi32)
API(SetSecurityDescriptorDacl,advapi32)
API(GetSecurityDescriptorDacl,advapi32)
API(SetSecurityDescriptorSacl,advapi32)
API(GetSecurityDescriptorSacl,advapi32)
API(SetSecurityDescriptorOwner,advapi32)
API(GetSecurityDescriptorOwner,advapi32)
API(SetSecurityDescriptorGroup,advapi32)
API(GetSecurityDescriptorGroup,advapi32)
API(CreatePrivateObjectSecurity,advapi32)
API(SetPrivateObjectSecurity,advapi32)
API(SetPrivateObjectSecurityEx,advapi32)
API(GetPrivateObjectSecurity,advapi32)
API(DestroyPrivateObjectSecurity,advapi32)
API(MakeSelfRelativeSD,advapi32)
API(MakeAbsoluteSD,advapi32)
APIA(SetFileSecurity,advapi32)
APIA(GetFileSecurity,advapi32)
API(SetKernelObjectSecurity,advapi32)

APIA(FindFirstChangeNotification,kernel32)
API(FindNextChangeNotification,kernel32)
API(FindCloseChangeNotification,kernel32)
API(VirtualLock,kernel32)
API(VirtualUnlock,kernel32)
API(MapViewOfFileEx,kernel32)
API(SetPriorityClass,kernel32)
API(GetPriorityClass,kernel32)
API(FatalExit,kernel32)
APIA(GetEnvironmentStrings,kernel32)
API(RaiseException,kernel32)
API(UnhandledExceptionFilter,kernel32)

API(SetCommState,kernel32)
API(SetCommTimeouts,kernel32)
API(GetCommState,kernel32)
API(GetCommTimeouts,kernel32)
API(PurgeComm,kernel32)
APIA(BuildCommDCB,kernel32)
APIA(BuildCommDCBAndTimeouts,kernel32)
API(TransmitCommChar,kernel32)
API(SetCommBreak,kernel32)
API(SetCommMask,kernel32)
API(ClearCommBreak,kernel32)
API(ClearCommError,kernel32)
API(SetupComm,kernel32)
API(EscapeCommFunction,kernel32)
API(GetCommMask,kernel32)
API(GetCommProperties,kernel32)
API(GetCommModemStatus,kernel32)
API(WaitCommEvent,kernel32)
API(SetTapePosition,kernel32)
API(GetTapePosition,kernel32)
API(PrepareTape,kernel32)
API(EraseTape,kernel32)
API(CreateTapePartition,kernel32)
API(WriteTapemark,kernel32)
API(GetTapeStatus,kernel32)
API(GetTapeParameters,kernel32)
API(SetTapeParameters,kernel32)
API(Beep,kernel32)
API(MulDiv,kernel32)

APIA(FormatMessage,kernel32)
API(CreatePipe,kernel32)
API(ConnectNamedPipe,kernel32)
API(DisconnectNamedPipe,kernel32)
API(SetNamedPipeHandleState,kernel32)
API(GetNamedPipeInfo,kernel32)
API(PeekNamedPipe,kernel32)
API(TransactNamedPipe,kernel32)
APIA(CreateMailslot,kernel32)
API(GetMailslotInfo,kernel32)
API(SetMailslotInfo,kernel32)
API(MapViewOfFile,kernel32)
API(FlushViewOfFile,kernel32)
API(UnmapViewOfFile,kernel32)


APIA(lstrcmp,kernel32)
APIA(lstrcmpi,kernel32)
APIA(lstrlen,kernel32)
# 8807 "/home/felix/gstudio8/include/windows.h"
API(TlsAlloc,kernel32)
API(TlsGetValue,kernel32)
API(TlsSetValue,kernel32)
API(TlsFree,kernel32)
API(SleepEx,kernel32)
API(WaitForSingleObjectEx,kernel32)
API(WaitForMultipleObjectsEx,kernel32)
API(BackupRead,kernel32)
API(BackupSeek,kernel32)
API(BackupWrite,kernel32)
APIA(CreateMutex,kernel32)
APIA(OpenMutex,kernel32)
APIA(CreateEvent,kernel32)
APIA(OpenEvent,kernel32)
APIA(CreateSemaphore,kernel32)
APIA(OpenSemaphore,kernel32)
APIA(CreateFileMapping,kernel32)
APIA(OpenFileMapping,kernel32)
APIA(GetLogicalDriveStrings,kernel32)
API(IsBadReadPtr,kernel32)
API(IsBadWritePtr,kernel32)
APIA(IsBadStringPtr,kernel32)
API(IsBadHugeReadPtr,kernel32)
API(IsBadHugeWritePtr,kernel32)
APIA(LookupAccountSid,advapi32)
APIA(LookupAccountName,advapi32)
APIA(LookupPrivilegeValue,advapi32)
APIA(LookupPrivilegeName,advapi32)
APIA(LookupPrivilegeDisplayName,advapi32)
API(AllocateLocallyUniqueId,advapi32)
APIA(GetComputerName,kernel32)
APIA(SetComputerName,kernel32)
APIA(GetUserName,advapi32)
API(QueryPerformanceCounter,kernel32)
API(QueryPerformanceFrequency,kernel32)
API(IsValidCodePage,kernel32)
API(GetACP,kernel32)
API(GetOEMCP,kernel32)
API(GetCPInfo,kernel32)
API(IsDBCSLeadByte,kernel32)
API(MultiByteToWideChar,kernel32)
API(WideCharToMultiByte,kernel32)
APIA(CompareString,kernel32)
APIA(LCMapString,kernel32)
APIA(GetLocaleInfo,kernel32)
APIA(GetTimeFormat,kernel32)
APIA(GetDateFormat,kernel32)
API(SetThreadLocale,kernel32)
API(GetSystemDefaultLangID,kernel32)
API(GetUserDefaultLangID,kernel32)
API(GetSystemDefaultLCID,kernel32)
API(GetUserDefaultLCID,kernel32)
API(GetStringTypeA,kernel32)
APIA(FoldString,kernel32)
API(EnumTimeFormats,KERNEL32)
API(EnumDateFormats,KERNEL32)
API(IsValidLocale,KERNEL32)
API(ConvertDefaultLocale,KERNEL32)
API(GetThreadLocale,KERNEL32)
API(EnumSystemLocales,KERNEL32)
API(EnumSystemCodePages,KERNEL32)
APIA(ReadConsoleOutput,kernel32)
APIA(WriteConsoleOutput,kernel32)
APIA(ReadConsoleOutputCharacter,kernel32)
API(ReadConsoleOutputAttribute,kernel32)
APIA(WriteConsoleOutputCharacter,kernel32)
API(WriteConsoleOutputAttribute,kernel32)
APIA(FillConsoleOutputCharacter,kernel32)
API(FillConsoleOutputAttribute,kernel32)
API(GetConsoleMode,kernel32)
API(GetNumberOfConsoleInputEvents,kernel32)
API(GetConsoleScreenBufferInfo,kernel32)
API(GetLargestConsoleWindowSize,kernel32)
API(GetConsoleCursorInfo,kernel32)
API(GetNumberOfConsoleMouseButtons,kernel32)
API(SetConsoleMode,kernel32)
API(SetConsoleActiveScreenBuffer,kernel32)
API(FlushConsoleInputBuffer,kernel32)
API(SetConsoleScreenBufferSize,kernel32)
API(SetConsoleCursorPosition,kernel32)
API(SetConsoleCursorInfo,kernel32)
APIA(ScrollConsoleScreenBuffer,kernel32)
API(SetConsoleWindowInfo,kernel32)
API(SetConsoleTextAttribute,kernel32)
API(SetConsoleCtrlHandler,kernel32)
API(GenerateConsoleCtrlEvent,kernel32)
API(AllocConsole,kernel32)
API(FreeConsole,kernel32)
APIA(GetConsoleTitle,kernel32)
APIA(SetConsoleTitle,kernel32)
APIA(ReadConsole,kernel32)
APIA(WriteConsole,kernel32)
API(CreateConsoleScreenBuffer,kernel32)
API(GetConsoleCP,kernel32)
API(SetConsoleCP,kernel32)
API(GetConsoleOutputCP,kernel32)
API(SetConsoleOutputCP,kernel32)

API(SetFocus,user32)
API(GetFocus,user32)
API(GetActiveWindow,user32)
API(GetKBCodePage,user32)
API(GetKeyState,user32)
API(GetAsyncKeyState,user32)
API(GetKeyboardState,user32)
API(SetKeyboardState,user32)
API(GetKeyboardType,user32)
APIA(GetKeyNameText,user32)
API(ToAscii,user32)
API(ToUnicode,user32)
API(OemKeyScan,user32)
APIA(VkKeyScan,user32)
API(keybd_event,user32)
API(mouse_event,user32)
APIA(MapVirtualKey,user32)
API(GetInputState,user32)
API(GetQueueStatus,user32)
API(GetCapture,user32)
API(SetCapture,user32)
API(ReleaseCapture,user32)
API(MsgWaitForMultipleObjects,user32)
API(MsgWaitForMultipleObjectsEx,user32)
API(KillTimer,user32)
API(IsWindowUnicode,user32)
API(EnableWindow,user32)
API(IsWindowEnabled,user32)
APIA(LoadAccelerators,user32)
APIA(CreateAcceleratorTable,user32)
API(DestroyAcceleratorTable,user32)
APIA(CopyAcceleratorTable,user32)
APIA(TranslateAccelerator,user32)
API(GetSystemMetrics,user32)
APIA(LoadMenu,user32)
APIA(LoadMenuIndirect,user32)
API(GetMenu,user32)
API(SetMenu,user32)
API(HiliteMenuItem,user32)
APIA(GetMenuString,user32)
API(GetMenuState,user32)
API(DrawMenuBar,user32)
API(GetSystemMenu,user32)
API(CreateMenu,user32)
API(CreatePopupMenu,user32)
API(DestroyMenu,user32)
API(CheckMenuItem,user32)
API(EnableMenuItem,user32)
API(GetSubMenu,user32)
API(GetMenuItemID,user32)
API(GetMenuItemCount,user32)
APIA(InsertMenu,user32)
APIA(AppendMenu,user32)
APIA(ModifyMenu,user32)
API(RemoveMenu,user32)
API(DeleteMenu,user32)
API(SetMenuItemBitmaps,user32)
API(GetMenuCheckMarkDimensions,user32)
API(TrackPopupMenu,user32)
API(DrawIcon,user32)
APIA(DrawText,user32)
APIA(TabbedTextOut,user32)
APIA(GetTabbedTextExtent,user32)
API(UpdateWindow,user32)
API(SetActiveWindow,user32)
API(GetForegroundWindow,user32)
API(SetForegroundWindow,user32)
API(WindowFromDC,user32)
API(GetDC,user32)
API(GetDCEx,user32)
API(GetWindowDC,user32)
API(ReleaseDC,user32)
API(BeginPaint,user32)
API(EndPaint,user32)
API(GetUpdateRect,user32)
API(GetUpdateRgn,user32)
API(ExcludeUpdateRgn,user32)
API(InvalidateRect,user32)
API(ValidateRect,user32)
API(InvalidateRgn,user32)
API(ValidateRgn,user32)
API(RedrawWindow,user32)
API(LockWindowUpdate,user32)
API(ScrollWindow,user32)
API(ScrollDC,user32)
API(ScrollWindowEx,user32)
API(SetScrollPos,user32)
API(GetScrollPos,user32)
API(SetScrollRange,user32)
API(GetScrollRange,user32)
API(ShowScrollBar,user32)
API(EnableScrollBar,user32)
APIA(SetProp,user32)
APIA(GetProp,user32)
APIA(RemoveProp,user32)
APIA(SetWindowText,user32)
APIA(GetWindowText,user32)
APIA(GetWindowTextLength,user32)
API(GetClientRect,user32)
API(GetWindowRect,user32)
API(AdjustWindowRect,user32)
API(AdjustWindowRectEx,user32)
APIA(MessageBox,user32)
APIA(MessageBoxEx,user32)
API(MessageBeep,user32)
API(ShowCursor,user32)
API(SetCursorPos,user32)
API(SetCursor,user32)
API(GetCursorPos,user32)
API(ClipCursor,user32)
API(GetCursor,user32)
API(GetClipCursor,user32)
API(CreateCaret,user32)
API(GetCaretBlinkTime,user32)
API(SetCaretBlinkTime,user32)
API(DestroyCaret,user32)
API(HideCaret,user32)
API(ShowCaret,user32)
API(SetCaretPos,user32)
API(GetCaretPos,user32)
API(ClientToScreen,user32)
API(ScreenToClient,user32)
API(MapWindowPoints,user32)
API(WindowFromPoint,user32)
API(ChildWindowFromPoint,user32)
API(GetSysColor,user32)
API(SetSysColors,user32)
API(DrawFocusRect,user32)
API(FillRect,user32)
API(FrameRect,user32)
API(InvertRect,user32)
API(SetRect,user32)
API(SetRectEmpty,user32)
API(CopyRect,user32)
API(InflateRect,user32)
API(IntersectRect,user32)
API(UnionRect,user32)
API(SubtractRect,user32)
API(OffsetRect,user32)
API(IsRectEmpty,user32)
API(EqualRect,user32)
API(PtInRect,user32)
API(GetWindowWord,user32)
API(SetWindowWord,user32)
APIA(GetWindowLong,user32)
APIA(SetWindowLong,user32)
API(GetClassWord,user32)
API(SetClassWord,user32)
APIA(GetClassLong,user32)
APIA(SetClassLong,user32)
API(GetDesktopWindow,user32)
API(GetParent,user32)
API(SetParent,user32)
APIA(FindWindow,user32)
APIA(GetClassName,user32)
API(GetTopWindow,user32)
API(GetNextWindow,user32)
API(GetWindowThreadProcessId,user32)
API(GetLastActivePopup,user32)
API(GetWindow,user32)
API(UnhookWindowsHookEx,user32)
API(CallNextHookEx,user32)

APIA(LoadString,user32)
APIA(IsDialogMessage,user32)
API(MapDialogRect,user32)
APIA(DlgDirList,user32)
APIA(DlgDirSelectEx,user32)
APIA(DlgDirListComboBox,user32)
APIA(DlgDirSelectComboBoxEx,user32)
APIA(DefFrameProc,user32)
APIA(DefMDIChildProc,user32)
API(TranslateMDISysAccel,user32)
API(ArrangeIconicWindows,user32)
APIA(CreateMDIWindow,user32)
APIA(WinHelp,user32)
APIA(SystemParametersInfo,user32)
API(DdeSetQualityOfService,user32)
API(ImpersonateDdeClientWindow,user32)
API(PackDDElParam,user32)
API(UnpackDDElParam,user32)
API(FreeDDElParam,user32)
API(ReuseDDElParam,user32)
API(DdeUninitialize,user32)
API(DdeConnectList,user32)
API(DdeQueryNextServer,user32)
API(DdeDisconnectList,user32)
API(DdeConnect,user32)
API(DdeDisconnect,user32)
API(DdeReconnect,user32)
API(DdeQueryConvInfo,user32)
API(DdeSetUserHandle,user32)
API(DdeAbandonTransaction,user32)
API(DdePostAdvise,user32)
API(DdeEnableCallback,user32)
API(DdeImpersonateClient,user32)
API(DdeNameService,user32)
API(DdeClientTransaction,user32)
API(DdeCreateDataHandle,user32)
APIA(DdeAddData,user32)
APIA(DdeGetData,user32)
APIA(DdeAccessData,user32)
APIA(DdeUnaccessData,user32)
API(DdeFreeDataHandle,user32)
API(DdeGetLastError,user32)
APIA(DdeCreateStringHandle,user32)
APIA(DdeQueryString,user32)
API(DdeFreeStringHandle,user32)
API(DdeKeepStringHandle,user32)
API(DdeCmpStringHandles,user32)

API(mixerGetNumDevs,winmm)
APIA(mixerGetDevCaps,winmm)
API(mixerOpen,winmm)
API(mixerClose,winmm)
API(mixerMessage,winmm)
APIA(mixerGetLineInfo,winmm)
API(mixerGetID,winmm)
APIA(mixerGetLineControls,winmm)
APIA(mixerGetControlDetails,winmm)
API(mixerSetControlDetails,winmm)

API(joyGetPos,winmm)
API(joyGetPosEx,winmm)

API(midiStreamOpen,winmm)
API(midiStreamClose,winmm)
API(midiStreamProperty,winmm)
API(midiStreamPosition,winmm)
API(midiStreamOut,winmm)
API(midiStreamPause,winmm)
API(midiStreamRestart,winmm)
API(midiStreamStop,winmm)
API(midiConnect,winmm)
API(midiDisconnect,winmm)
API(CloseDriver,winmm)
API(OpenDriver,winmm)
API(SendDriverMessage,winmm)
API(DrvGetModuleHandle,winmm)
API(GetDriverModuleHandle,winmm)
API(DefDriverProc,winmm)
API(mmsystemGetVersion,winmm)
API(OutputDebugStr,winmm)
APIA(sndPlaySound,winmm)
APIA(PlaySound,winmm)
API(waveOutGetNumDevs,winmm)
APIA(waveOutGetDevCaps,winmm)
API(waveOutGetVolume,winmm)
API(waveOutSetVolume,winmm)
APIA(waveOutGetErrorText,winmm)
API(waveOutOpen,winmm)
API(waveOutClose,winmm)
API(waveOutPrepareHeader,winmm)
API(waveOutUnprepareHeader,winmm)
API(waveOutWrite,winmm)
API(waveOutPause,winmm)
API(waveOutRestart,winmm)
API(waveOutReset,winmm)
API(waveOutBreakLoop,winmm)
API(waveOutGetPosition,winmm)
API(waveOutGetPitch,winmm)
API(waveOutSetPitch,winmm)
API(waveOutGetPlaybackRate,winmm)
API(waveOutSetPlaybackRate,winmm)
API(waveOutGetID,winmm)
API(waveOutMessage,winmm)
API(waveInGetNumDevs,winmm)
APIA(waveInGetDevCaps,winmm)
APIA(waveInGetErrorText,winmm)
API(waveInOpen,winmm)
API(waveInClose,winmm)
API(waveInPrepareHeader,winmm)
API(waveInUnprepareHeader,winmm)
API(waveInAddBuffer,winmm)
API(waveInStart,winmm)
API(waveInStop,winmm)
API(waveInReset,winmm)
API(waveInGetPosition,winmm)
API(waveInGetID,winmm)
API(waveInMessage,winmm)

APIA(midiOutGetDevCaps,winmm)
API(midiOutGetVolume,winmm)
API(midiOutSetVolume,winmm)
APIA(midiOutGetErrorText,winmm)
API(midiOutOpen,winmm)
API(midiOutClose,winmm)
API(midiOutPrepareHeader,winmm)
API(midiOutUnprepareHeader,winmm)
API(midiOutShortMsg,winmm)
API(midiOutLongMsg,winmm)
API(midiOutReset,winmm)
API(midiOutCachePatches,winmm)
API(midiOutCacheDrumPatches,winmm)
API(midiOutGetID,winmm)
API(midiOutMessage,winmm)
API(midiInGetNumDevs,winmm)
APIA(midiInGetDevCaps,winmm)
APIA(midiInGetErrorText,winmm)
API(midiInOpen,winmm)
API(midiInClose,winmm)
API(midiInPrepareHeader,winmm)
API(midiInUnprepareHeader,winmm)
API(midiInAddBuffer,winmm)
API(midiInStart,winmm)
API(midiInStop,winmm)
API(midiInReset,winmm)
API(midiInGetID,winmm)
API(midiInMessage,winmm)

API(auxGetNumDevs,winmm)
APIA(auxGetDevCaps,winmm)
API(auxSetVolume,winmm)
API(auxGetVolume,winmm)
API(auxOutMessage,winmm)

API(timeGetSystemTime,winmm)
API(timeGetTime,winmm)
API(timeSetEvent,winmm)
API(timeKillEvent,winmm)
API(timeGetDevCaps,winmm)
API(timeBeginPeriod,winmm)
API(timeEndPeriod,winmm)

APIA(joyGetDevCaps,winmm)
API(joyGetNumDevs,winmm)
API(joyGetThreshold,winmm)
API(joyReleaseCapture,winmm)
API(joySetCapture,winmm)
API(joySetThreshold,winmm)

APIA(mmioStringToFOURCC,winmm)
APIA(mmioOpen,winmm)
APIA(mmioRename,winmm)
API(mmioClose,winmm)
API(mmioRead,winmm)
API(mmioWrite,winmm)
API(mmioSeek,winmm)
API(mmioGetInfo,winmm)
API(mmioSetInfo,winmm)
API(mmioSetBuffer,winmm)
API(mmioFlush,winmm)
API(mmioAdvance,winmm)
API(mmioSendMessage,winmm)
API(mmioDescend,winmm)
API(mmioAscend,winmm)
API(mmioCreateChunk,winmm)

APIA(mciSendCommand,winmm)
APIA(mciSendString,winmm)
API(mciGetCreatorTask,winmm)
APIA(mciGetDeviceID,winmm)
APIA(mciGetDeviceIDFromElementID,winmm)
APIA(mciGetErrorString,winmm)
API(mciExecute,winmm)

APIA(WNetAddConnection,mpr)
APIA(WNetAddConnection2,mpr)
APIA(WNetCancelConnection,mpr)
APIA(WNetCancelConnection2,mpr)
APIA(WNetGetConnection,mpr)
APIA(WNetOpenEnum,mpr)
APIA(WNetEnumResource,mpr)
API(WNetCloseEnum,mpr)
APIA(WNetGetUser,mpr)
API(WNetConnectionDialog,mpr)
API(WNetDisconnectDialog,mpr)
APIA(WNetGetLastError,mpr)
APIA(WNetAddConnection2,mpr)
APIA(WNetOpenEnum,mpr)
APIA(WNetEnumResource,mpr)
API(WNetCloseEnum,mpr)

API(Netbios,netapi32)
API(NetUserChangePassword,Netapi32.dll)
API(NetUserGetInfo,Netapi32.dll)
API(NetUserGetGroups,Netapi32.dll)
API(NetUserGetLocalGroups,Netapi32.dll)
API(NetUserAdd,netapi32)
API(NetWkstaGetInfo,Netapi32.dll)
API(NetWkstaUserGetInfo,Netapi32.dll)
API(NetApiBufferFree,Netapi32.dll)
API(NetRemoteTOD,Netapi32.dll)
APIA(GetUserName,advapi32)
API(GetUserNameW,advapi32.dll)

APIA(GetComputerName,kernel32)

API(RegCloseKey,advapi32)
APIA(RegConnectRegistry,advapi32)
APIA(RegCreateKey,advapi32)
APIA(RegCreateKeyEx,advapi32)
APIA(RegDeleteKey,advapi32)
APIA(RegDeleteValue,advapi32)
APIA(RegEnumKey,advapi32)
APIA(RegEnumKeyEx,advapi32)
APIA(RegEnumValue,advapi32)
API(RegFlushKey,advapi32)
API(RegGetKeySecurity,advapi32)
APIA(RegLoadKey,advapi32)
API(RegNotifyChangeKeyValue,advapi32)
APIA(RegOpenKey,advapi32)
APIA(RegOpenKeyEx,advapi32)
APIA(RegQueryInfoKey,advapi32)
APIA(RegQueryValue,advapi32)
APIA(RegQueryValueEx,advapi32)
APIA(RegReplaceKey,advapi32)
APIA(RegRestoreKey,advapi32)
APIA(RegSaveKey,advapi32)
API(RegSetKeySecurity,advapi32)
APIA(RegSetValue,advapi32)
APIA(RegSetValueEx,advapi32)
APIA(RegUnLoadKey,advapi32)
APIA(InitiateSystemShutdown,advapi32)
APIA(AbortSystemShutdown,advapi32)
APIA(ChangeServiceConfig,advapi32)
API(CloseServiceHandle,advapi32)
API(ControlService,advapi32)
APIA(CreateService,advapi32)
API(DeleteService,advapi32)
APIA(EnumDependentServices,advapi32)
APIA(EnumServicesStatus,advapi32)
APIA(GetServiceKeyName,advapi32)
APIA(GetServiceDisplayName,advapi32)
API(LockServiceDatabase,advapi32)
API(NotifyBootConfigStatus,advapi32)
APIA(OpenSCManager,advapi32)
APIA(OpenService,advapi32)
APIA(QueryServiceConfig,advapi32)
APIA(QueryServiceLockStatus,advapi32)
API(QueryServiceObjectSecurity,advapi32)
API(QueryServiceStatus,advapi32)
APIA(RegisterServiceCtrlHandler,advapi32)
API(SetServiceObjectSecurity,advapi32)
API(SetServiceStatus,advapi32)
APIA(StartServiceCtrlDispatcher,advapi32)
APIA(StartService,advapi32)
API(UnlockServiceDatabase,advapi32)

API(LZCopy,lz32)
API(LZInit,lz32)
APIA(GetExpandedName,lz32)
APIA(LZOpenFile,lz32)
API(LZSeek,lz32)
API(LZRead,lz32)
API(LZClose,lz32)

APIA(ImmInstallIME,imm32)
API(ImmGetDefaultIMEWnd,imm32)
APIA(ImmGetDescription,imm32)
APIA(ImmGetIMEFileName,imm32)
API(ImmGetProperty,imm32)
API(ImmIsIME,imm32)
API(ImmSimulateHotKey,imm32)
API(ImmCreateContext,imm32)
API(ImmDestroyContext,imm32)
API(ImmGetContext,imm32)
API(ImmReleaseContext,imm32)
API(ImmAssociateContext,imm32)
APIA(ImmGetCompositionString,imm32)
APIA(ImmSetCompositionString,imm32)
APIA(ImmGetCandidateListCount,imm32)
APIA(ImmGetCandidateList,imm32)
APIA(ImmGetGuideLine,imm32)
API(ImmGetConversionStatus,imm32)
API(ImmSetConversionStatus,imm32)
API(ImmGetOpenStatus,imm32)
API(ImmSetOpenStatus,imm32)
APIA(ImmGetCompositionFont,imm32)
APIA(ImmSetCompositionFont,imm32)
API(ImmConfigureIME,imm32)
APIA(ImmEscape,imm32)
APIA(ImmGetConversionList,imm32)
API(ImmNotifyIME,imm32)
API(ImmGetStatusWindowPos,imm32)
API(ImmSetStatusWindowPos,imm32)
API(ImmGetCompositionWindow,imm32)
API(ImmSetCompositionWindow,imm32)
API(ImmGetCandidateWindow,imm32)
API(ImmSetCandidateWindow,imm32)
APIA(ImmIsUIMessage,imm32)
API(ImmGetVirtualKey,imm32)
APIA(ImmRegisterWord,imm32)
APIA(ImmUnregisterWord,imm32)
APIA(ImmGetRegisterWordStyle,imm32)
APIA(ImmEnumRegisterWord,imm32)

APIA(DragQueryFile,shell32)
API(DragQueryPoint,shell32)
API(DragFinish,shell32)
API(DragAcceptFiles,shell32)
APIA(ShellExecute,shell32)
APIA(FindExecutable,shell32)
APIA(ShellAbout,shell32)
API(DuplicateIcon,shell32)
APIA(ExtractAssociatedIcon,shell32)
APIA(ExtractIcon,shell32)
API(SHAppBarMessage,shell32)
APIA(DoEnvironmentSubst,shell32)
APIA(FindEnvironmentString,shell32)
APIA(ExtractIconEx,shell32)
APIA(SHFileOperation,shell32)
API(SHFreeNameMappings,shell32)
APIA(WinExecError,shell32)
APIA(Shell_NotifyIcon,shell32)
APIA(SHGetSpecialFolderPath,shell32)
APIA(SHGetFileInfo,shell32)
APIA(SHGetNewLinkInfo,shell32)
APIA(VerFindFile,version)
APIA(VerInstallFile,version)
APIA(GetFileVersionInfoSize,version)
APIA(GetFileVersionInfo,version)
APIA(VerLanguageName,kernel32)
API(VerQueryValue,version)

APIA(GetBinaryType,kernel32)
APIA(GetShortPathName,kernel32)


APIA(CreateProcessAsUser,advapi32)
APIA(GetVersionEx,kernel32)
API(GetSystemPowerStatus,kernel32)
API(SetSystemPowerState,kernel32)
APIA(GetFileTitle,comdlg32)
APIA(FindText,comdlg32)
APIA(ReplaceText,comdlg32)
APIA(ChooseFont,comdlg32)
APIA(PrintDlg,comdlg32)
API(CommDlgExtendedError,comdlg32)
APIA(PageSetupDlg,comdlg32)

APIA(DdeInitialize,user32)

API(SetServiceBits,advapi32)

API(CopyLZFile,lz32)
API(LZStart,lz32)
API(LZDone,lz32)

API(mciGetYieldProc,winmm)
API(mciSetYieldProc,winmm)
API(midiOutGetNumDevs,winmm)
API(mmioInstallIOProcA,winmm)

API(IsTextUnicode,advapi32)
API(NotifyChangeEventLog,advapi32)
API(SetThreadToken,advapi32)

APIA(CommConfigDialog,kernel32)
API(CreateIoCompletionPort,kernel32)
API(DisableThreadLibraryCalls,kernel32)
APIA(EnumResourceLanguages,kernel32)
APIA(EnumResourceNames,kernel32)
APIA(EnumResourceTypes,kernel32)
APIA(FreeEnvironmentStrings,kernel32)
API(FreeLibraryAndExitThread,kernel32)
API(FreeResource,kernel32)
API(GetCommConfig,kernel32)
APIA(GetCompressedFileSize,kernel32)
APIA(GetDefaultCommConfig,kernel32)
API(GetHandleInformation,kernel32)
API(GetProcessWorkingSetSize,kernel32)
API(GetQueuedCompletionStatus,kernel32)
API(PostQueuedCompletionStatus,kernel32)
API(GetSystemTimeAdjustment,kernel32)
API(GlobalCompact,kernel32)
API(GlobalFix,kernel32)
API(GlobalUnfix,kernel32)
API(GlobalWire,kernel32)
API(GlobalUnWire,kernel32)
API(IsBadCodePtr,kernel32)
API(LocalCompact,kernel32)
API(LocalShrink,kernel32)
API(ReadFileEx,kernel32)
API(SetCommConfig,kernel32)
APIA(SetDefaultCommConfig,kernel32)
API(SetFileApisToANSI,kernel32)
API(SetHandleInformation,kernel32)
API(SetProcessWorkingSetSize,kernel32)
APIA(lstrcat,kernel32)
APIA(lstrcpyn,kernel32)
APIA(lstrcpy,kernel32)
API(SetSystemTimeAdjustment,kernel32)
API(SetThreadAffinityMask,kernel32)
API(SetUnhandledExceptionFilter,kernel32)
API(SystemTimeToTzSpecificLocalTime,kernel32)
API(WriteFileEx,kernel32)
API(ChoosePixelFormat,gdi32)
API(CreateDIBSection,gdi32)
API(DescribePixelFormat,gdi32)
API(EndDoc,gdi32)
APIA(EnumFonts,gdi32)
API(EnumMetaFile,gdi32)
API(EnumObjects,gdi32)
API(FixBrushOrgEx,gdi32)
API(GetBrushOrgEx,gdi32)
API(GetDIBColorTable,gdi32)
API(GetPixelFormat,gdi32)

API(SetAbortProc,gdi32)
API(SetDIBColorTable,gdi32)
API(SetPixelFormat,gdi32)
API(SwapBuffers,gdi32)
APIA(EnumCalendarInfo,kernel32)
APIA(GetCurrencyFormat,kernel32)
APIA(GetNumberFormat,kernel32)
APIA(GetStringTypeEx,kernel32)
API(GetStringTypeW,kernel32)
APIA(SetLocaleInfo,kernel32)

API(BroadcastSystemMessage,user32)
APIA(CallWindowProc,user32)
API(CascadeWindows,user32)
APIA(ChangeMenu,user32)
API(CheckMenuRadioItem,user32)
API(ChildWindowFromPoint,user32)
API(ChildWindowFromPointEx,user32)
API(CopyImage,user32)
APIA(CreateDialogIndirectParam,user32)
APIA(CreateDialogParam,user32)
API(CreateIconFromResource,user32)
APIA(DialogBoxIndirectParam,user32)
API(DragDetect,user32)
API(DragObject,user32)

API(EnumChildWindows,user32)
APIA(EnumPropsEx,user32)
APIA(EnumProps,user32)
API(EnumThreadWindows,user32)
APIA(EnumWindowStations,user32)
APIA(FindWindowEx,user32)
API(GetKeyboardLayoutList,user32)
API(GetKeyboardLayout,user32)
API(GetMenuContextHelpId,user32)
API(GetMenuDefaultItem,user32)
APIA(GetMenuItemInfo,user32)
API(GetMenuItemRect,user32)
API(GetScrollInfo,user32)
API(GetSysColorBrush,user32)
API(GetWindowContextHelpId,user32)
API(GetWindowRgn,user32)
APIA(GrayString,user32)
APIA(InsertMenuItem,user32)
APIA(LoadCursorFromFile,user32)
APIA(LoadImage,user32)
API(LookupIconIdFromDirectoryEx,user32)
APIA(MapVirtualKeyEx,user32)
API(MenuItemFromPoint,user32)
APIA(MessageBoxIndirect,user32)
API(PaintDesktop,user32)
APIA(RegisterClassEx,user32)
API(SetMenuContextHelpId,user32)
API(SetMenuDefaultItem,user32)
APIA(SetMenuItemInfo,user32)
API(SetMessageExtraInfo,user32)
API(SetMessageQueue,user32)
API(SetScrollInfo,user32)
API(SetSystemCursor,user32)
API(SetTimer,user32)
API(SetWindowContextHelpId,user32)
API(SetWindowRgn,user32)
APIA(SetWindowsHook,user32)
APIA(SetWindowsHookEx,user32)
API(ShowWindowAsync,user32)
API(TileWindows,user32)
API(ToAsciiEx,user32)
API(TrackPopupMenuEx,user32)
API(UnhookWindowsHook,user32)
APIA(VkKeyScanEx,user32)
APIA(WNetGetUniversalName,mpr)

API(BSTR_UserFree,oleaut32)
API(BSTR_UserMarshal,oleaut32)
API(BSTR_UserSize,oleaut32)
API(BSTR_UserUnmarshal,oleaut32)
API(BstrFromVector,oleaut32)
API(ClearCustData,oleaut32)
API(CreateDispTypeInfo,oleaut32)
API(CreateErrorInfo,oleaut32)
API(CreateStdDispatch,oleaut32)
API(CreateTypeLib,oleaut32)
API(CreateTypeLib2,oleaut32)
API(DispCallFunc,oleaut32)
API(DispGetIDsOfNames,oleaut32)
API(DispGetParam,oleaut32)
API(DispInvoke,oleaut32)
API(DllCanUnloadNow,oleaut32)
API(DllGetClassObject,oleaut32)
API(DllRegisterServer,oleaut32)
API(DllUnregisterServer,oleaut32)
API(DosDateTimeToVariantTime,oleaut32)
API(GetActiveObject,oleaut32)
API(GetAltMonthNames,oleaut32)
API(GetErrorInfo,oleaut32)
API(GetRecordInfoFromGuids,oleaut32)
API(GetRecordInfoFromTypeInfo,oleaut32)
API(GetVarConversionLocaleSetting,oleaut32)
API(LHashValOfNameSys,oleaut32)
API(LHashValOfNameSysA,oleaut32)
API(LoadRegTypeLib,oleaut32)
API(LoadTypeLib,oleaut32)
API(LoadTypeLibEx,oleaut32)
API(LPSAFEARRAY_Marshal,oleaut32)
API(LPSAFEARRAY_Size,oleaut32)
API(LPSAFEARRAY_Unmarshal,oleaut32)
API(LPSAFEARRAY_UserFree,oleaut32)
API(LPSAFEARRAY_UserMarshal,oleaut32)
API(LPSAFEARRAY_UserSize,oleaut32)
API(LPSAFEARRAY_UserUnmarshal,oleaut32)
API(OaBuildVersion,oleaut32)
API(OACreateTypeLib2,oleaut32)
API(OleCreateFontIndirect,oleaut32)
API(OleCreatePictureIndirect,oleaut32)
API(OleCreatePropertyFrame,oleaut32)
API(OleCreatePropertyFrameIndirect,oleaut32)
API(OleIconToCursor,oleaut32)
API(OleLoadPicture,oleaut32)
API(OleLoadPictureEx,oleaut32)
API(OleLoadPictureFile,oleaut32)
API(OleLoadPictureFileEx,oleaut32)
API(OleLoadPicturePath,oleaut32)
API(OleSavePictureFile,oleaut32)
API(OleTranslateColor,oleaut32)

API(QueryPathOfRegTypeLib,oleaut32)
API(RegisterActiveObject,oleaut32)
API(RegisterTypeLib,oleaut32)
API(RevokeActiveObject,oleaut32)
API(SafeArrayAccessData,oleaut32)
API(SafeArrayAllocData,oleaut32)
API(SafeArrayAllocDescriptor,oleaut32)
API(SafeArrayAllocDescriptorEx,oleaut32)
API(SafeArrayCopy,oleaut32)
API(SafeArrayCopyData,oleaut32)
API(SafeArrayCreate,oleaut32)
API(SafeArrayCreateEx,oleaut32)
API(SafeArrayCreateVector,oleaut32)
API(SafeArrayCreateVectorEx,oleaut32)
API(SafeArrayDestroy,oleaut32)
API(SafeArrayDestroyData,oleaut32)
API(SafeArrayDestroyDescriptor,oleaut32)
API(SafeArrayGetDim,oleaut32)
API(SafeArrayGetElement,oleaut32)
API(SafeArrayGetElemsize,oleaut32)
API(SafeArrayGetIID,oleaut32)
API(SafeArrayGetLBound,oleaut32)
API(SafeArrayGetRecordInfo,oleaut32)
API(SafeArrayGetUBound,oleaut32)
API(SafeArrayGetVartype,oleaut32)
API(SafeArrayLock,oleaut32)
API(SafeArrayPtrOfIndex,oleaut32)
API(SafeArrayPutElement,oleaut32)
API(SafeArrayRedim,oleaut32)
API(SafeArraySetIID,oleaut32)
API(SafeArraySetRecordInfo,oleaut32)
API(SafeArrayUnaccessData,oleaut32)
API(SafeArrayUnlock,oleaut32)
API(SetErrorInfo,oleaut32)
API(SetVarConversionLocaleSetting,oleaut32)
API(SysAllocString,oleaut32)
API(SysAllocStringByteLen,oleaut32)
API(SysAllocStringLen,oleaut32)
API(SysFreeString,oleaut32)
API(SysReAllocString,oleaut32)
API(SysReAllocStringLen,oleaut32)
API(SysStringByteLen,oleaut32)
API(SysStringLen,oleaut32)
API(SystemTimeToVariantTime,oleaut32)
API(UnRegisterTypeLib,oleaut32)
# 9696 "/home/felix/gstudio8/include/windows.h"
API(VarAbs,oleaut32)
API(VarAdd,oleaut32)
API(VarAnd,oleaut32)
API(VarBoolFromCy,oleaut32)
API(VarBoolFromDate,oleaut32)
API(VarBoolFromDec,oleaut32)
API(VarBoolFromDisp,oleaut32)
API(VarBoolFromI1,oleaut32)
API(VarBoolFromI2,oleaut32)
API(VarBoolFromI4,oleaut32)
API(VarBoolFromR4,oleaut32)
API(VarBoolFromR8,oleaut32)
API(VarBoolFromStr,oleaut32)
API(VarBoolFromUI1,oleaut32)
API(VarBoolFromUI2,oleaut32)
API(VarBoolFromUI4,oleaut32)
API(VarBstrCat,oleaut32)
API(VarBstrCmp,oleaut32)
API(VarBstrFromBool,oleaut32)
API(VarBstrFromCy,oleaut32)
API(VarBstrFromDate,oleaut32)
API(VarBstrFromDec,oleaut32)
API(VarBstrFromDisp,oleaut32)
API(VarBstrFromI1,oleaut32)
API(VarBstrFromI2,oleaut32)
API(VarBstrFromI4,oleaut32)
API(VarBstrFromR4,oleaut32)
API(VarBstrFromR8,oleaut32)
API(VarBstrFromUI1,oleaut32)
API(VarBstrFromUI2,oleaut32)
API(VarBstrFromUI4,oleaut32)
API(VarCat,oleaut32)
API(VarCmp,oleaut32)
API(VarCyAbs,oleaut32)
API(VarCyAdd,oleaut32)
API(VarCyCmp,oleaut32)
API(VarCyCmpR8,oleaut32)
API(VarCyFix,oleaut32)
API(VarCyFromBool,oleaut32)
API(VarCyFromDate,oleaut32)
API(VarCyFromDec,oleaut32)
API(VarCyFromDisp,oleaut32)
API(VarCyFromI1,oleaut32)
API(VarCyFromI2,oleaut32)
API(VarCyFromI4,oleaut32)
API(VarCyFromR4,oleaut32)
API(VarCyFromR8,oleaut32)
API(VarCyFromStr,oleaut32)
API(VarCyFromUI1,oleaut32)
API(VarCyFromUI2,oleaut32)
API(VarCyFromUI4,oleaut32)
API(VarCyInt,oleaut32)
API(VarCyMul,oleaut32)
API(VarCyMulI4,oleaut32)
API(VarCyNeg,oleaut32)
API(VarCyRound,oleaut32)
API(VarCySub,oleaut32)
API(VarDateFromBool,oleaut32)
API(VarDateFromCy,oleaut32)
API(VarDateFromDec,oleaut32)
API(VarDateFromDisp,oleaut32)
API(VarDateFromI1,oleaut32)
API(VarDateFromI2,oleaut32)
API(VarDateFromI4,oleaut32)
API(VarDateFromR4,oleaut32)
API(VarDateFromR8,oleaut32)
API(VarDateFromStr,oleaut32)
API(VarDateFromUdate,oleaut32)
API(VarDateFromUdateEx,oleaut32)
API(VarDateFromUI1,oleaut32)
API(VarDateFromUI2,oleaut32)
API(VarDateFromUI4,oleaut32)
API(VarDecAbs,oleaut32)
API(VarDecAdd,oleaut32)
API(VarDecCmp,oleaut32)
API(VarDecCmpR8,oleaut32)
API(VarDecDiv,oleaut32)
API(VarDecFix,oleaut32)
API(VarDecFromBool,oleaut32)
API(VarDecFromCy,oleaut32)
API(VarDecFromDate,oleaut32)
API(VarDecFromDisp,oleaut32)
API(VarDecFromI1,oleaut32)
API(VarDecFromI2,oleaut32)
API(VarDecFromI4,oleaut32)
API(VarDecFromR4,oleaut32)
API(VarDecFromR8,oleaut32)
API(VarDecFromStr,oleaut32)
API(VarDecFromUI1,oleaut32)
API(VarDecFromUI2,oleaut32)
API(VarDecFromUI4,oleaut32)
API(VarDecInt,oleaut32)
API(VarDecMul,oleaut32)
API(VarDecNeg,oleaut32)
API(VarDecRound,oleaut32)
API(VarDecSub,oleaut32)
API(VarDiv,oleaut32)
API(VarEqv,oleaut32)
API(VarFix,oleaut32)
API(VarFormat,oleaut32)
API(VarFormatCurrency,oleaut32)
API(VarFormatDateTime,oleaut32)
API(VarFormatFromTokens,oleaut32)
API(VarFormatNumber,oleaut32)
API(VarFormatPercent,oleaut32)
API(VarI1FromBool,oleaut32)
API(VarI1FromCy,oleaut32)
API(VarI1FromDate,oleaut32)
API(VarI1FromDec,oleaut32)
API(VarI1FromDisp,oleaut32)
API(VarI1FromI2,oleaut32)
API(VarI1FromI4,oleaut32)
API(VarI1FromR4,oleaut32)
API(VarI1FromR8,oleaut32)
API(VarI1FromStr,oleaut32)
API(VarI1FromUI1,oleaut32)
API(VarI1FromUI2,oleaut32)
API(VarI1FromUI4,oleaut32)
API(VarI2FromBool,oleaut32)
API(VarI2FromCy,oleaut32)
API(VarI2FromDate,oleaut32)
API(VarI2FromDec,oleaut32)
API(VarI2FromDisp,oleaut32)
API(VarI2FromI1,oleaut32)
API(VarI2FromI4,oleaut32)
API(VarI2FromR4,oleaut32)
API(VarI2FromR8,oleaut32)
API(VarI2FromStr,oleaut32)
API(VarI2FromUI1,oleaut32)
API(VarI2FromUI2,oleaut32)
API(VarI2FromUI4,oleaut32)
API(VarI4FromBool,oleaut32)
API(VarI4FromCy,oleaut32)
API(VarI4FromDate,oleaut32)
API(VarI4FromDec,oleaut32)
API(VarI4FromDisp,oleaut32)
API(VarI4FromI1,oleaut32)
API(VarI4FromI2,oleaut32)
API(VarI4FromR4,oleaut32)
API(VarI4FromR8,oleaut32)
API(VarI4FromStr,oleaut32)
API(VarI4FromUI1,oleaut32)
API(VarI4FromUI2,oleaut32)
API(VarI4FromUI4,oleaut32)
API(VARIANT_UserFree,oleaut32)
API(VARIANT_UserMarshal,oleaut32)
API(VARIANT_UserSize,oleaut32)
API(VARIANT_UserUnmarshal,oleaut32)
API(VariantChangeType,oleaut32)
API(VariantChangeTypeEx,oleaut32)
API(VariantClear,oleaut32)
API(VariantCopy,oleaut32)
API(VariantCopyInd,oleaut32)
API(VariantInit,oleaut32)
API(VariantTimeToDosDateTime,oleaut32)
API(VariantTimeToSystemTime,oleaut32)
API(VarIdiv,oleaut32)
API(VarImp,oleaut32)
API(VarInt,oleaut32)
API(VarMod,oleaut32)
API(VarMonthName,oleaut32)
API(VarMul,oleaut32)
API(VarNeg,oleaut32)
API(VarNot,oleaut32)
API(VarNumFromParseNum,oleaut32)
API(VarOr,oleaut32)
API(VarParseNumFromStr,oleaut32)
API(VarPow,oleaut32)
API(VarR4CmpR8,oleaut32)
API(VarR4FromBool,oleaut32)
API(VarR4FromCy,oleaut32)
API(VarR4FromDate,oleaut32)
API(VarR4FromDec,oleaut32)
API(VarR4FromDisp,oleaut32)
API(VarR4FromI1,oleaut32)
API(VarR4FromI2,oleaut32)
API(VarR4FromI4,oleaut32)
API(VarR4FromR8,oleaut32)
API(VarR4FromStr,oleaut32)
API(VarR4FromUI1,oleaut32)
API(VarR4FromUI2,oleaut32)
API(VarR4FromUI4,oleaut32)
API(VarR8FromBool,oleaut32)
API(VarR8FromCy,oleaut32)
API(VarR8FromDate,oleaut32)
API(VarR8FromDec,oleaut32)
API(VarR8FromDisp,oleaut32)
API(VarR8FromI1,oleaut32)
API(VarR8FromI2,oleaut32)
API(VarR8FromI4,oleaut32)
API(VarR8FromR4,oleaut32)
API(VarR8FromStr,oleaut32)
API(VarR8FromUI1,oleaut32)
API(VarR8FromUI2,oleaut32)
API(VarR8FromUI4,oleaut32)
API(VarR8Pow,oleaut32)
API(VarR8Round,oleaut32)
API(VarRound,oleaut32)
API(VarSub,oleaut32)
API(VarTokenizeFormatString,oleaut32)
API(VarUdateFromDate,oleaut32)
API(VarUI1FromBool,oleaut32)
API(VarUI1FromCy,oleaut32)
API(VarUI1FromDate,oleaut32)
API(VarUI1FromDec,oleaut32)
API(VarUI1FromDisp,oleaut32)
API(VarUI1FromI1,oleaut32)
API(VarUI1FromI2,oleaut32)
API(VarUI1FromI4,oleaut32)
API(VarUI1FromR4,oleaut32)
API(VarUI1FromR8,oleaut32)
API(VarUI1FromStr,oleaut32)
API(VarUI1FromUI2,oleaut32)
API(VarUI1FromUI4,oleaut32)
API(VarUI2FromBool,oleaut32)
API(VarUI2FromCy,oleaut32)
API(VarUI2FromDate,oleaut32)
API(VarUI2FromDec,oleaut32)
API(VarUI2FromDisp,oleaut32)
API(VarUI2FromI1,oleaut32)
API(VarUI2FromI2,oleaut32)
API(VarUI2FromI4,oleaut32)
API(VarUI2FromR4,oleaut32)
API(VarUI2FromR8,oleaut32)
API(VarUI2FromStr,oleaut32)
API(VarUI2FromUI1,oleaut32)
API(VarUI2FromUI4,oleaut32)
API(VarUI4FromBool,oleaut32)
API(VarUI4FromCy,oleaut32)
API(VarUI4FromDate,oleaut32)
API(VarUI4FromDec,oleaut32)
API(VarUI4FromDisp,oleaut32)
API(VarUI4FromI1,oleaut32)
API(VarUI4FromI2,oleaut32)
API(VarUI4FromI4,oleaut32)
API(VarUI4FromR4,oleaut32)
API(VarUI4FromR8,oleaut32)
API(VarUI4FromStr,oleaut32)
API(VarUI4FromUI1,oleaut32)
API(VarUI4FromUI2,oleaut32)
API(VarWeekdayName,oleaut32)
API(VarXor,oleaut32)
API(VectorFromBstr,oleaut32)

API(BindMoniker,ole32)




API(CLSIDFromProgID,ole32)
API(CLSIDFromString,ole32)
API(CoAddRefServerProcess,ole32)
API(CoBuildVersion,ole32)
API(CoCopyProxy,ole32)
API(CoCreateFreeThreadedMarshaler,ole32)
API(CoCreateGuid,ole32)
API(CoCreateInstance,ole32)
API(CoCreateInstanceEx,ole32)
API(CoDisconnectObject,ole32)
API(CoDosDateTimeToFileTime,ole32)
API(CoFileTimeNow,ole32)
API(CoFileTimeToDosDateTime,ole32)
API(CoFreeAllLibraries,ole32)
API(CoFreeLibrary,ole32)
API(CoFreeUnusedLibraries,ole32)
API(CoGetCallContext,ole32)
API(CoGetCallerTID,ole32)
API(CoGetClassObject,ole32)
API(CoGetCurrentLogicalThreadId,ole32)
API(CoGetCurrentProcess,ole32)
API(CoGetInstanceFromFile,ole32)
API(CoGetInstanceFromIStorage,ole32)
API(CoGetInterfaceAndReleaseStream,ole32)
API(CoGetMalloc,ole32)
API(CoGetMarshalSizeMax,ole32)
API(CoGetObject,ole32)
API(CoGetPSClsid,ole32)
API(CoGetStandardMarshal,ole32)


API(CoGetTreatAsClass,ole32)
API(CoImpersonateClient,ole32)
API(CoInitialize,ole32)
API(CoInitializeEx,ole32)
API(CoInitializeSecurity,ole32)

API(CoIsHandlerConnected,ole32)
API(CoIsOle1Class,ole32)
API(CoLoadLibrary,ole32)
API(CoLockObjectExternal,ole32)
API(CoMarshalHresult,ole32)
API(CoMarshalInterface,ole32)
API(CoMarshalInterThreadInterfaceInStream,ole32)
API(CoQueryAuthenticationServices,ole32)
API(CoQueryClientBlanket,ole32)
API(CoQueryProxyBlanket,ole32)
API(CoQueryReleaseObject,ole32)
API(CoRegisterChannelHook,ole32)
API(CoRegisterClassObject,ole32)
API(CoRegisterMallocSpy,ole32)
API(CoRegisterMessageFilter,ole32)
API(CoRegisterPSClsid,ole32)
API(CoRegisterSurrogate,ole32)
API(CoReleaseMarshalData,ole32)
API(CoReleaseServerProcess,ole32)
API(CoResumeClassObjects,ole32)
API(CoRevertToSelf,ole32)
API(CoRevokeClassObject,ole32)
API(CoRevokeMallocSpy,ole32)
API(CoSetProxyBlanket,ole32)
API(CoSetState,ole32)
API(CoSuspendClassObjects,ole32)
API(CoSwitchCallContext,ole32)
API(CoTaskMemAlloc,ole32)
API(CoTaskMemFree,ole32)
API(CoTaskMemRealloc,ole32)
API(CoTreatAsClass,ole32)
API(CoUninitialize,ole32)


API(CoUnmarshalHresult,ole32)
API(CoUnmarshalInterface,ole32)
API(CreateAntiMoniker,ole32)
API(CreateBindCtx,ole32)
API(CreateClassMoniker,ole32)
API(CreateDataAdviseHolder,ole32)
API(CreateDataCache,ole32)
API(CreateErrorInfo,ole32)
API(CreateFileMoniker,ole32)
API(CreateGenericComposite,ole32)
API(CreateILockBytesOnHGlobal,ole32)
API(CreateItemMoniker,ole32)
API(CreateObjrefMoniker,ole32)
API(CreateOleAdviseHolder,ole32)
API(CreatePointerMoniker,ole32)
API(CreateStreamOnHGlobal,ole32)






API(FreePropVariantArray,ole32)
API(GetClassFile,ole32)
API(GetConvertStg,ole32)

API(GetErrorInfo,ole32)
# 10088 "/home/felix/gstudio8/include/windows.h"
API(IIDFromString,ole32)
API(IsAccelerator,ole32)
API(IsEqualGUID,ole32)
API(IsValidIid,ole32)
API(IsValidInterface,ole32)
API(IsValidPtrIn,ole32)
API(IsValidPtrOut,ole32)
API(MkParseDisplayName,ole32)
API(MonikerCommonPrefixWith,ole32)
API(MonikerRelativePathTo,ole32)

API(OleBuildVersion,ole32)
API(OleConvertIStorageToOLESTREAM,ole32)
API(OleConvertIStorageToOLESTREAMEx,ole32)
API(OleConvertOLESTREAMToIStorage,ole32)
API(OleConvertOLESTREAMToIStorageEx,ole32)
API(OleCreate,ole32)
API(OleCreateDefaultHandler,ole32)
API(OleCreateEmbeddingHelper,ole32)
API(OleCreateEx,ole32)
API(OleCreateFromData,ole32)
API(OleCreateFromDataEx,ole32)
API(OleCreateFromFile,ole32)
API(OleCreateFromFileEx,ole32)
API(OleCreateLink,ole32)
API(OleCreateLinkEx,ole32)
API(OleCreateLinkFromData,ole32)
API(OleCreateLinkFromDataEx,ole32)
API(OleCreateLinkToFile,ole32)
API(OleCreateLinkToFileEx,ole32)
API(OleCreateMenuDescriptor,ole32)
API(OleCreateStaticFromData,ole32)
API(OleDestroyMenuDescriptor,ole32)
API(OleDoAutoConvert,ole32)
API(OleDraw,ole32)
API(OleDuplicateData,ole32)
API(OleFlushClipboard,ole32)
API(OleGetAutoConvert,ole32)
API(OleGetClipboard,ole32)
API(OleGetIconOfClass,ole32)
API(OleGetIconOfFile,ole32)
API(OleInitialize,ole32)
API(OleInitializeWOW,ole32)
API(OleIsCurrentClipboard,ole32)
API(OleIsRunning,ole32)
API(OleLoad,ole32)
API(OleLoadFromStream,ole32)
API(OleLockRunning,ole32)
API(OleMetafilePictFromIconAndLabel,ole32)
API(OleNoteObjectVisible,ole32)
API(OleQueryCreateFromData,ole32)
API(OleQueryLinkFromData,ole32)
API(OleRegEnumFormatEtc,ole32)
API(OleRegEnumVerbs,ole32)
API(OleRegGetMiscStatus,ole32)
API(OleRegGetUserType,ole32)
API(OleRun,ole32)
API(OleSave,ole32)
API(OleSaveToStream,ole32)
API(OleSetAutoConvert,ole32)
API(OleSetClipboard,ole32)
API(OleSetContainedObject,ole32)
API(OleSetMenuDescriptor,ole32)
API(OleTranslateAccelerator,ole32)
API(OleUninitialize,ole32)

API(OpenOrCreateStream,ole32)
API(ProgIDFromCLSID,ole32)
API(PropSysAllocString,ole32)
API(PropSysFreeString,ole32)
API(PropVariantClear,ole32)
API(PropVariantCopy,ole32)
API(ReadClassStg,ole32)
API(ReadClassStm,ole32)
API(ReadFmtUserTypeStg,ole32)
API(ReadOleStg,ole32)
API(ReadStringStream,ole32)
API(RegisterDragDrop,ole32)
API(ReleaseStgMedium,ole32)
API(RevokeDragDrop,ole32)
API(SetConvertStg,ole32)
API(SetDocumentBitStg,ole32)
API(SetErrorInfo,ole32)




API(StgCreateDocfile,ole32)
API(StgCreateDocfileOnILockBytes,ole32)
API(StgCreateStorageEx,ole32)
API(StgGetIFillLockBytesOnFile,ole32)
API(StgGetIFillLockBytesOnILockBytes,ole32)
API(StgIsStorageFile,ole32)
API(StgIsStorageILockBytes,ole32)




API(StgOpenAsyncDocfileOnIFillLockBytes,ole32)
API(StgOpenStorage,ole32)
API(StgOpenStorageEx,ole32)
API(StgOpenStorageOnILockBytes,ole32)
API(StgSetTimes,ole32)
API(StringFromCLSID,ole32)
API(StringFromGUID2,ole32)
API(StringFromIID,ole32)
API(UpdateDCOMSettings,ole32)
# 10203 "/home/felix/gstudio8/include/windows.h"
API(WriteClassStg,ole32)
API(WriteClassStm,ole32)
API(WriteFmtUserTypeStg,ole32)






typedef struct tagPIXELFORMATDESCRIPTOR {
    WORD nSize;
    WORD nVersion;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE cColorBits;
    BYTE cRedBits;
    BYTE cRedShift;
    BYTE cGreenBits;
    BYTE cGreenShift;
    BYTE cBlueBits;
    BYTE cBlueShift;
    BYTE cAlphaBits;
    BYTE cAlphaShift;
    BYTE cAccumBits;
    BYTE cAccumRedBits;
    BYTE cAccumGreenBits;
    BYTE cAccumBlueBits;
    BYTE cAccumAlphaBits;
    BYTE cDepthBits;
    BYTE cStencilBits;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR;
# 10272 "/home/felix/gstudio8/include/windows.h"
typedef DWORD COLORREF;
typedef struct CHOOSECOLOR {
    long lStructSize;
    long hwndOwner;
    long hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    long Flags;
    long lCustData;
    long lpfnHook;
    char* lpTemplateName;
} CHOOSECOLOR;






BOOL __stdcall ChooseColor(CHOOSECOLOR* lpcc);
# 10303 "/home/felix/gstudio8/include/windows.h"
float minf(float a,float b) { if (a < b) return a; else return b; }
float maxf(float a,float b) { if (a > b) return a; else return b; }
# 6 "src/console.h" 2

 long __stdcall WriteConsole(int Handle, char* Buffer, int CharsToWrite, int* CharsWritten, int reserved);
 long __stdcall CreateConsoleScreenBuffer(long dwDesiredAccess, long dwShareMode, long *lpSecurityAttributes, long dwFlags, long lpScreenBufferData);
 long __stdcall SetConsoleActiveScreenBuffer(long hConsoleOutput);
 long GConsoleBuffer;
 int consoleInitialized = 0;



  int consolePrintTrue = 0;

 int consolePrintTarget = 2;

 void consoleInit()
 {
  if(consoleInitialized) return;
  consoleInitialized = 1;
  AllocConsole();
  GConsoleBuffer = CreateConsoleScreenBuffer(0x40000000, 0x1, 0, 1, 0);
  SetConsoleActiveScreenBuffer(GConsoleBuffer);


 }

 void cdiag(char* AText)
 {
  if(!consolePrintTrue) return;
  if(consolePrintTarget) diag(AText);
  if(consolePrintTarget == 0 || consolePrintTarget == 2)
  {
   if(!consoleInitialized) consoleInit();
   WriteConsole(GConsoleBuffer, AText, str_len(AText), 0, 0);
  }
 }
# 138 "src/jps.h" 2




 double dJPSTime = 0;
 int offset2D[16] = { -1,0, 1,0, 0,-1, 0,1, -1,-1, -1,1, 1,1, 1,-1 };




 MAP* mapGetCurrent();



 MAP* jpsMapLoadFromFile(char* filename);

 TILE* mapTileGet(MAP* map, int x, int y);

 VECTOR* mapGetVectorFromTile(MAP* map, VECTOR* v, TILE* tile);

 VECTOR* mapGetVector2DFromVector3D(MAP* map, VECTOR* v2d, VECTOR* v3d);
 VECTOR* mapGetVector3DFromVector2D(MAP* map, VECTOR* v3d, VECTOR* v2d);

 void unitSetTargetFromVector2D(MAP* map, UNIT* unit, VECTOR *vTarget);

 TILE* mapGetTileFromVector(MAP* map, VECTOR* v);

 BMAP* mapGetBitmap(MAP* map);

 void jpsGameUpdate(MAP* map);

 UNIT* jpsAllowMovementForEntity(ENTITY* ptr, int allow);

 void mapSetTileValueAtPos3D(MAP* map, VECTOR* pos3d, int value);
 int mapGetTileValueAtPos3D(MAP* map, VECTOR* pos3d);

 TILE* mapGetEmptyTileForAI(MAP* map, int freeBorder);


 int mapGetNearbyUnitsOfTypeForPos(VECTOR *vpos, int typeID, int owner, var maxDistance, int maxNumEntities);




 JPSPATH *jpsPathCreate(int maxLength);


 void mapFillTest(MAP* map);

 int mapTraceDo(MAP* map, int *posFrom, int *posTo, int mode);


 void mapJPSUpdate(MAP* map);

 void mapUpdateBmap(MAP* map);


 int mapJPSPathGet(MAP* map, TILE* startTile, TILE *targetTile, JPSPATH *jpsPathOut);




 LIST* listAdd(LIST* current, void* data);

 LIST* listAddTileSorted(LIST* current, TILE* tile, int sortMethod);

 void listDestroy(LIST* list, int mode);

 void draw_line2(VECTOR* vFrom, VECTOR* vTo, COLOR* color, var alpha);

 void mapTileFreeNeighborData(MAP* map, TILE* sourceTile);

 var mapTileCostCalculate(MAP* map, TILE* tile1, TILE* tile2);

 void mapTileCalculateVisibilityForTile(MAP* map, TILE* sourceTile);

 void tileResetJPSData(TILE* tile);



 void presetsInit();

 void draw_line3D2(VECTOR* vFrom, VECTOR* vTo, COLOR* color, var alpha);

 void mapUpdateUnits(MAP* map);


 void* pointerArray[1024];
 int pointerArrayNum = 0;

 int mapGetNearbyUnits(MAP* map, TILE* sourceTile, int range);
 int mapIsAnyUnitNearby(MAP* map, TILE* sourceTile, int range);
 int mapIsAnyFriendlyUnitNearby(MAP* map, TILE* sourceTile, int range, int playerNumber);

 VECTOR* unitFlockingSpeedGet(MAP* map, UNIT* unit, VECTOR* v);

 int sphereBoxCollision(VECTOR* spherePos2D, VECTOR* vSpeed, float sphereRadius, float boxMinX, float boxMinY, float boxMaxX, float boxMaxY);

 int unitMoveWithCollision(MAP* map, UNIT* unit, VECTOR *vSpeed);

 void unitMove(MAP* map, UNIT* unit);

 void mapMoveUnits(MAP* map);


 void unitInitializeFromPreset(UNIT *unit, int presetID);

 UNIT* jpsUnitCreate(int playerID, int unitType, ENTITY* ent);

 void jpsUnitDestroy(UNIT* unit);

 void unitSetTargetFromTile(MAP* map, UNIT* unit, TILE* targetTile);

 void unitAllSetTargetFromTile(MAP* map, int playerID, TILE* targetTile);

 void mapSaveToFile(MAP* map, char* filename);
# 9 "src/framework.c" 2
# 1 "src/ui_game.h" 1
# 23 "src/ui_game.h"
PANEL *ui_main_resources;
PANEL *ui_unit_meta;
PANEL *ui_game_menu;
PANEL *ui_monitor;

PANEL *ui_radial_delete;
PANEL *ui_radial_counter;
PANEL *ui_radial_cbabe;
PANEL *ui_radial_skull;
PANEL *ui_radial_esel;
PANEL *ui_radial_sputnik;
PANEL *ui_radial_active;

PANEL *ui_life_indicator[2000];

PANEL *ui_portrait;
PANEL *ui_minimap;

BMAP *ui_radial_prototype1 = "ui_placeholder_unit.png";
BMAP *ui_radial_prototype2 = "ui_placeholder_counter.png";

BMAP *ui_bmap_resources = "H3.png";
BMAP *ui_bmap_units = "H2.png";
BMAP *ui_bmap_gamemenu = "H1.png";

BMAP *ui_bmap_dead_indicator;
BMAP *ui_bmap_life_indicator;
BMAP *ui_bmap_yellow = "#2x2x24";
BMAP *ui_bmap_magenta = "#2x2x24";
BMAP *ui_bmap_cyan = "#2x2x24";
BMAP *ui_bmap_red = "#2x2x24";
BMAP *ui_bmap_green = "#2x2x24";
BMAP *ui_bmap_blue = "#2x2x24";
BMAP *ui_bmap_camera = "minimap_cam_marker.png";

BMAP *ui_bmap_cbabe[3];
BMAP *ui_bmap_sputnik[3];
BMAP *ui_bmap_noise[3];
BMAP *ui_bmap_eye[3];
BMAP *ui_bmap_esel[3];

BMAP **ui_active_portrait;

BMAP *ui_hide_button_n = "hide_button_n.png";
BMAP *ui_hide_button_o = "hide_button_o.png";
BMAP *ui_hide_button_p = "hide_button_p.png";

BMAP *ui_radial_o = "ui_placeholder_counter.png";
BMAP *ui_radial_n = "ui_placeholder_unit.png";
BMAP *ui_radial_progress = "#128x128x8888";

BMAP *ui_icon_cbabe = "ui_H2.png";
BMAP *ui_icon_sputnik = "ui_H1.png";
BMAP *ui_icon_skull = "ui_H4.png";
BMAP *ui_icon_esel = "ui_H3.png";

BMAP *ui_icon_blank = "ico_s_2.png";
BMAP *ui_icon_blank_o = "ico_s_2_o.png";
BMAP *ui_icon_tower = "Ico_S_2Bui2.png";
BMAP *ui_icon_tower_o = "Ico_S_2Bui2_o.png";
BMAP *ui_icon_farm = "Ico_S_2Bui.png";
BMAP *ui_icon_farm_o = "Ico_S_2Bui_o.png";
BMAP *ui_icon_bank = "Ico_S_2Bui3.png";
BMAP *ui_icon_bank_o = "Ico_S_2Bui3_o.png";

BMAP *ui_face_cbabe1 = "CbFace1.png";
BMAP *ui_face_cbabe2 = "CbFace2.png";
BMAP *ui_face_cbabe3 = "CbFace3.png";

BMAP *ui_face_sputnik1 = "Sputnik1.png";
BMAP *ui_face_sputnik2 = "Sputnik2.png";
BMAP *ui_face_sputnik3 = "Sputnik3.png";

BMAP *ui_face_esel1 = "ESFace1.png";
BMAP *ui_face_esel2 = "ESFace2.png";
BMAP *ui_face_esel3 = "ESFace3.png";

BMAP *ui_face_eye1 = "ui_H4.png";
BMAP *ui_face_eye2 = "ui_H4.png";
BMAP *ui_face_eye3 = "ui_H4.png";

BMAP *ui_face_noise1 = "Rauschen1.png";
BMAP *ui_face_noise2 = "Rauschen2.png";
BMAP *ui_face_noise3 = "Rauschen3.png";

BMAP *ui_mm = "#288x324x24";
BMAP *ui_bmap_monitor = "monitor.png";

ENTITY* last_building;
ENTITY* main_unit;

ENTITY *ui_active;
ENTITY *ui_active_building;

FONT *ui_hud_font = "HUD_font.png";

var ui_anim_state = 0;
var ui_anim_unit_state = 0;
var ui_scale1 = 0.1;
var ui_scale2 = 0.1;
var ui_scale3 = 0.1;
var ui_switch_frame = 0;
var a_stupid_var = 1234;
var a_dummy_var = 0;

int ui_frame_order[19] = {0, 1, 0, 1, 2, 1, 0, 1, 1, 2, 0, 2, 0, 0, 1, 2, 0, 1, 2};
int ui_selected_max_type = 0;
int ui_command_group_status = 0;
int ui_lifebar_counter = 0;


var scale_factor_x = 1;
var scale_factor_y = 1;
var mini_map_extra_scale_x = 1;
var mini_map_extra_scale_y = 1;

var ui_map_shift_x = 410;
var ui_map_shift_y = 96;
var ui_map_offset_x = 0;
var ui_map_offset_y = 0;


void ui_game_init();
void ui_game_open();
void ui_game_close();
void ui_game_update();
var ui_game_isdone();
void ui_game_after_all();
# 10 "src/framework.c" 2
# 1 "src/materials.h" 1
# 1 "src/mainmenu.c" 1




void mainmenu_init(void)
{

 mainmenu_wndMenuBackground = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackground->_forced_background = mainmenu_background;
 mainmenu_wndMenuBackgroundBright = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackgroundBright->_forced_background = mainmenu_background_bright;

 mainmenu_wndMenuMain = uimenu_window_create_borderless(0, 0, 1920, 1080);

 int btnHeight = bmap_height(mainmenu_btn_new_game);
 mainmenu_btnNewGame = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_new_game) / 2), 300 + (btnHeight * 0), 128, 32, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_set_start);
 mainmenu_btnOptions = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_options) / 2), 300 + (btnHeight * 1), 128, 32, mainmenu_btn_options, mainmenu_btn_options, mainmenu_btn_options, mainmenu_show_options);
 mainmenu_btnCredits = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_credits) / 2), 300 + (btnHeight * 2), 128, 32, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_set_credits);
 mainmenu_btnExit = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_exit) / 2), 300 + (btnHeight * 4), 128, 32, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_set_exit);

 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnNewGame);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnOptions);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnCredits);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnExit);

 uimenu_window_initialize(mainmenu_wndMenuMain);
 uimenu_window_initialize(mainmenu_wndMenuBackground);
 uimenu_window_initialize(mainmenu_wndMenuBackgroundBright);

 mainmenu_resolution_update();


 mainmenu_wndMenuOptions = uimenu_window_create( (screen_size.x / 2) - (640 / 2), (screen_size.y / 2) - (480 / 2), 640, 480, "Options");
 uimenu_element_t * optionsExit = uimenu_make_simple_button(640 - 90, 480 - 23, 85, 23, "OK", uimenu_default_font, mainmenu_hide_options);

 uimenu_element_t * optionsTabGeneral = uimenu_make_simple_button(0, 0, 23, "General", uimenu_default_font, mainmenu_show_options_general);
 uimenu_element_t * optionsTabVideo = uimenu_make_simple_button(optionsTabGeneral->x + optionsTabGeneral->width + 2, 0, 23, "Video", uimenu_default_font, mainmenu_show_options_video);
 uimenu_element_t * optionsTabAudio = uimenu_make_simple_button(optionsTabVideo->x + optionsTabVideo->width + 2, 0, 23, "Audio", uimenu_default_font, mainmenu_show_options_audio);
 uimenu_element_t * optionsTabControls = uimenu_make_simple_button(optionsTabAudio->x + optionsTabAudio->width + 2, 0, 23, "Controls", uimenu_default_font, mainmenu_show_options_controls);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsExit);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabGeneral);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabVideo);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabAudio);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabControls);

 uimenu_window_initialize(mainmenu_wndMenuOptions);


 mainmenu_wndMenuOptionsGeneral = uimenu_window_create_borderless(0, 32, 640 - 8, 380);

 uimenu_element_t * generalInfo = uimenu_make_text(5, 5, 100, 32, "Nothing to see here", 0, 0);

 uimenu_add_element_to_window(mainmenu_wndMenuOptionsGeneral, generalInfo);

 uimenu_slave_window_to_window(mainmenu_wndMenuOptions, mainmenu_wndMenuOptionsGeneral);

 uimenu_window_initialize(mainmenu_wndMenuOptionsGeneral);


 mainmenu_wndMenuBackgroundBright->_panel->flags |= (1<<10);
 mainmenu_wndMenuMain->_panel->flags |= (1<<10);
}


void mainmenu_set_start(void)
{
 mainmenu_current_response = 1;
}

void mainmenu_show_options_general(void)
{
 uimenu_window_show(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_video(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_show(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_audio(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_show(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_controls(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_show(mainmenu_wndMenuOptionsControls);
}


void mainmenu_show_options(void)
{
 uimenu_window_show(mainmenu_wndMenuOptions);
 mainmenu_show_options_general();
}
void mainmenu_hide_options(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptions);
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_set_credits(void)
{
 mainmenu_current_response = 2;
}
void mainmenu_set_exit(void)
{
 mainmenu_current_response = 3;
}

void mainmenu_open(void)
{
    mainmenu_current_response = 0;
 music_speedup(100);
 music_start("media/mainmenu.mp3", 0.5, 0);
 uimenu_window_show(mainmenu_wndMenuMain);
 uimenu_window_show(mainmenu_wndMenuBackground);
 uimenu_window_show(mainmenu_wndMenuBackgroundBright);
}

void mainmenu_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  if(mainmenu_wndMenuMain->_is_visible)
  {
   if(total_secs == mainmenu_buzz_wait_time)
   {
    var alpha = 25 + random(75);
    mainmenu_wndMenuMain->_panel->alpha = alpha;
    mainmenu_wndMenuBackgroundBright->_panel->alpha = alpha;
    mainmenu_buzz_handle = snd_play(mainmenu_buzz, alpha, 0);
    snd_tune(mainmenu_buzz_handle, alpha, 100 - (alpha / 10), 0);
    mainmenu_wndMenuMain->_content_panel->scale_x = mainmenu_wndMenuBackground->_content_panel->scale_x * (1 + (random(1) / 100));
    mainmenu_wndMenuMain->_content_panel->scale_y = mainmenu_wndMenuBackground->_content_panel->scale_y * (1 + (random(1) / 100));
   }

   if(total_secs > mainmenu_buzz_wait_time)
   {
    mainmenu_buzz_wait_time = total_secs + integer(random(8));
    mainmenu_resolution_update();
   }
  }
 }
}

void mainmenu_resolution_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  mainmenu_wndMenuMain->_content_panel->scale_x =
  mainmenu_wndMenuBackground->_content_panel->scale_x =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_x =
  screen_size.x / 1920;

  mainmenu_wndMenuMain->_content_panel->scale_y =
  mainmenu_wndMenuBackground->_content_panel->scale_y =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_y =
  screen_size.y / 1080;
 }
}

void mainmenu_close(void)
{
 uimenu_window_destroy(mainmenu_wndMenuBackground);
 uimenu_window_destroy(mainmenu_wndMenuBackgroundBright);
 uimenu_window_destroy(mainmenu_wndMenuMain);
}

int mainmenu_get_response()
{
 return mainmenu_current_response;
}
# 2 "src/materials.h" 2
# 1 "src/settings.h" 1





struct settings_t
{
    bool enable_shadows;
    bool enable_bloom;
    int max_framerate;
    int res_x, res_y;
    int master_volume;
};

struct settings_t settings;

void settings_init(void);

void settings_load(void);

void settings_save(void);
# 3 "src/materials.h" 2






BMAP *bmapPPOriginal = 0;

MATERIAL *matTrees =
{
    effect = "trees.fx";
}

MATERIAL *matCrystals =
{
    effect = "crystals.fx";
}

MATERIAL *matPPFilter =
{
    effect = "pp_filter.fx";
}

MATERIAL *matPPBlurVertical =
{
 effect = "pp_blur.fx";
}

MATERIAL *matPPBlurHorizontal =
{
 effect = "pp_blur.fx";
}

MATERIAL *matPPCombine =
{
 effect = "pp_combine.fx";
}

VIEW* pp_laststage(VIEW* view)
{
    if(!view) view = camera;
    while(view->stage) view = view->stage;
    return view;
}

VIEW* pp_findstage(VIEW* view)
{
    VIEW *v;
    for(v = ptr_first(camera); v; v = v->link.next)
        if(view == v->stage) return v;
    return camera;
}

VIEW* pp_stage = 0;
VIEW* pp_view = 0;

function pp_event() { return; }

function pp_set(VIEW* view,MATERIAL* m)
{
    if(!pp_view) pp_view = camera;
    if(!view) view = camera;
    if(m) {

      pp_view = view;

        if(!pp_stage) pp_stage = view_create(-1);
        pp_stage->material = m;
        pp_stage->flags |= (1<<3);
        pp_stage->size_x = view->size_x;
        pp_stage->size_y = view->size_y;
        view->stage = pp_stage;

        if(m->skill[10]) m->skill[0] = floatv(m->skill[10]);
        if(m->skill[11]) m->skill[1] = floatv(m->skill[11]);
        if(m->skill[12]) m->skill[2] = floatv(m->skill[12]);
        if(m->skill[13]) m->skill[3] = floatv(m->skill[13]);

        if(m->event) { pp_event = m->event; pp_event(); }
    } else {
        view->stage = 0;
        if(pp_stage) pp_stage->material = 0;
    }
}

function pp_add(MATERIAL* m)
{
    if(!pp_view) pp_view = camera;
    if(!pp_stage) pp_stage = camera;
    if(m) {
        VIEW* view = pp_laststage(pp_stage);
        pp_stage = 0;
        pp_set(view,m);
    } else {
        ptr_remove(pp_stage);
        pp_stage = pp_view;
        pp_stage->stage = 0;
        pp_view = pp_findstage(pp_stage);
    }
}

void UpdateRenderTargets()
{
 if(bmapPPOriginal)
 {
  if(bmap_width(bmapPPOriginal) == screen_size.x && bmap_height(bmapPPOriginal) == screen_size.y)
  {
   return;
  }
 }

 if(bmapPPOriginal)
  bmap_remove(bmapPPOriginal);

 bmapPPOriginal = bmap_createblack(screen_size.x, screen_size.y, 8888);

    camera.bmap = bmapPPOriginal;
    matPPCombine.skin1 = bmapPPOriginal;

    VIEW * it = camera;
    while(it != 0)
    {
        it->size_x = screen_size.x;
        it->size_y = screen_size.y;
        it = it->stage;
    }
}

void materials_reinit()
{
    while(pp_view != 0 && pp_view != camera)
    {
        pp_add(0);
    }

    if(settings.enable_bloom)
    {
        UpdateRenderTargets();

        matPPFilter.skill[0] = floatv(0.7);

        matPPBlurHorizontal.skill[0] = floatv(2.0);
        matPPBlurHorizontal.skill[1] = floatv(0.0);

        matPPBlurVertical.skill[0] = floatv(0.0);
        matPPBlurVertical.skill[1] = floatv(2.0);

        matPPCombine.skill[0] = floatv(1.5);

        pp_add(matPPFilter);
        pp_add(matPPBlurVertical);
        pp_add(matPPBlurHorizontal);
        pp_add(matPPCombine);
    }
}

int AmazingRendertargetCounter = 0;
void rendertargetUpdateBlubb()
{
    AmazingRendertargetCounter = 1;
}

void updateRenderTargetsIfNeeded()
{
    if(AmazingRendertargetCounter == 1)
    {
        materials_reinit();
        mainmenu_resolution_update();
    }

    AmazingRendertargetCounter = 0;
}

void SetupPostprocessing()
{
    materials_reinit();

    on_d3d_reset = rendertargetUpdateBlubb;
}
# 11 "src/framework.c" 2
# 22 "src/framework.c"
typedef struct
{
    int state;
    int nextState;
    int frameCounter;
    int loaderState;
} framework_t;

framework_t framework;

BMAP * framework_mouse_cursor = "cursor.tga";
# 45 "src/framework.c"
void framework_update_settings()
{
# 61 "src/framework.c"
}


void framework_init()
{
    settings_init();
    settings_load();

    fps_min = 25;
    fps_max = settings.max_framerate;

    framework_update_settings();


    max_entities = 5000;
    max_particles = 500000;
    particle_mode = 8;
    collision_mode = 2;
    preload_mode = 3;

    if(settings.enable_shadows)
        shadow_stencil = 1;
    else
        shadow_stencil = -1;

    mouse_map = framework_mouse_cursor;






    video_set(settings.res_x, settings.res_y, 0, 2);

    mouse_mode = 4;

    on_frame = framework_update;
}

void framework_setup(ENTITY * ent, int subsystem)
{
    if(ent == 0) error("framework: framework_setup mit NULL aufgerufen!");
    ent->skill[98] = subsystem;
}

void framework_freeze(ENTITY * ent)
{
    if(ent == 0) error("framework: framework_freeze mit NULL aufgerufen!");
    ent->skill[98] = 0;
    ent->emask &= ~(1<<0);
}

void framework_remove(ENTITY * ent)
{
 if(ent == 0) error("framework: framework_freeze mit NULL aufgerufen!");
 ent->skill[97] = 1;
}

void framework_transfer(int state)
{
    framework.nextState = state;
}

void framework_cleanup()
{
    ENTITY * ent;
    ent = ent_next(0);
    while(ent)
    {
        you = ent;
        ent = ent_next(ent);
        if(you->skill[97])
        {
            UNIT *unit = ((UNIT*)you->skill[96]);
            if(unit) jpsUnitDestroy(unit);
            ptr_remove(you);
        }
    }
}

void framework_capture_mouse()
{
    RECT rect;
    GetWindowRect(hWnd, &rect);
    SetCursorPos((rect.left + rect.right) / 2, (rect.top + rect.bottom) / 2);
}

var progress = 0;


void framework_update()
{

    if(key_alt && key_f4)
        framework_transfer(-1);






    if(framework.state != 0)
    {
        uimenu_update();
        updateRenderTargetsIfNeeded();
    }

    switch(framework.state)
    {
    case 0:
        if(framework.frameCounter == 1)
        {

            SetupPostprocessing();
            music_init();
            mainmenu_init();
            game_init();
            credits_init();






            framework_transfer(1);

        }
        break;

    case 1:
    {
        mainmenu_update();
        int response = mainmenu_get_response();
        if(response != 0)
        {
            switch(response)
            {
            case 1:
                framework_transfer(2);
                break;
            case 2:
                framework_transfer(3);
                break;
            case 3:
                framework_transfer(-1);
                break;
            default:
                error("framework: unknown response from main menu.");
            }
        }
        break;
    }

    case 3:
        credits_update();
        if(credits_isdone())
            framework_transfer(1);
        break;

    case 2:
        game_update();
        if(game_is_done())
            framework_transfer(1);
        break;

    default:
        error(str_printf(0, "framework: unsupported state %d!", framework.state));

    }

    if(framework.state != framework.nextState)
    {
        diag(str_printf(0, "\nstate transition from %d to %d.", framework.state, framework.nextState));

        switch(framework.state)
        {
        case -1:
            error("framework: shutdown state should never be left again!");
            break;

        case 0:
            break;

        case 1:
            mainmenu_close();
            break;

        case 3:
            credits_close();
            break;

        case 2:
            game_close();
            break;

        default:
            error(str_printf(0, "framework: unsupported state %d!", framework.state));
        }

        framework.state = framework.nextState;

        switch(framework.state)
        {
        case -1:
            break;

        case 0:
            error("framework: startup state should never be entered again!");
            break;

        case 1:
            mainmenu_open();
            break;

        case 3:
            credits_open();
            break;

        case 2:


            game_open();
            break;

        default:
            error(str_printf(0, "framework: unsupported state %d!", framework.state));
        }
    }


    framework_cleanup();


    music_update();


    if(framework.state == 2)
        ui_game_after_all();

    if(framework.state == -1)
    {
        on_frame = 0;
        sys_exit(0);
    }

    framework.frameCounter += 1;
}


void framework_load_level(const char * msg)
{
 player = 0;
 level_load(0);
}
# 35 "main.c" 2
# 1 "src/game.c" 1

# 1 "src/map_loader.h" 1





int maploader_cellsize = 3;
var maploader_trisize = 28.75;
# 16 "src/map_loader.h"
void maploader_init(void);

bool maploader_has_map(void);

void maploader_load(char const * fileName);

int maploader_size_x(void);
int maploader_size_y(void);

int maploader_tile_type(int x, int y);
float maploader_tile_vegetation(int x, int y);
float maploader_tile_height(int x, int y);
float maploader_tile_zettiness(int x, int y);
float maploader_tile_streetyness(int x, int y);

int maploader_get_type(VECTOR * v);
float maploader_get_vegetation(VECTOR * v);
float maploader_get_height(VECTOR * v);

void maploader_pos_to_vec(VECTOR * v, int x, int y);
void maploader_pos_for_vec(VECTOR * v, int * x, int * y);


VECTOR * maploader_trace(VECTOR * start, VECTOR * end);
# 3 "src/game.c" 2


# 1 "src/grid.h" 1
# 10 "src/grid.h"
void grid_init();
void grid_open(int xSize, int ySize);
void grid_close();


int grid_CoordToID(int x, int y);

void grid_setState(int x, int y, int state);
void grid_resetState(int x, int y, int state);
int grid_getState(int x, int y);

void grid_setState_byID(int id, state);
void grid_resetState_byID(int id, state);
int grid_getState_byID(int id);


int grid_getCellID(VECTOR);
VECTOR *grid_getCellCenter(int x, int y);
VECTOR *grid_getCellCenter_byID(int);
# 6 "src/game.c" 2
# 1 "src/camera.h" 1
# 10 "src/camera.h"
void topdown_camera_open();
void topdown_camera_update();

void topdown_camera_set_pos(VECTOR*);

VECTOR *get_pos_under_cursor();
VECTOR *topdown_target();
# 7 "src/game.c" 2
# 1 "src/sputnik.h" 1



void Sputnik();
void SPUTNIK_Init();
void SPUTNIK_Update();


void SPUTNIK__wait_or_walk(ENTITY * ptr);
void SPUTNIK__attack(ENTITY* ptr);
void SPUTNIK__die(ENTITY* ptr);
void SPUTNIK__hit(ENTITY* ptr);
# 8 "src/game.c" 2
# 1 "src/spawner.h" 1






int spawner_unit_cost[5] = {10,20,50,35,0};


ENTITY* spawner_spawn(int unittype, VECTOR* pos, var angle, var owner);
var spawner_produce(ENTITY* ent);
var spawner_getQueue(ENTITY* ent);
var spawner_getProgress(ENTITY* ent);
var spawner_getHealth(ENTITY* ent);


void Spawner();
void SPAWNER_Init();
void SPAWNER_Update();


void SPAWNER__hit(ENTITY* ptr);
void SPAWNER__hitcheck(ENTITY* ptr);
void SPAWNER__construct(ENTITY* ptr);
void SPAWNER__active(ENTITY* ptr);
void SPAWNER__produce(ENTITY* ptr);
void SPAWNER__die(ENTITY* ptr);
# 9 "src/game.c" 2
# 1 "src/stub.h" 1



void stub_init();
void stub_update();
# 10 "src/game.c" 2

# 1 "src/UnitMangement.h" 1



void UnitMangement_init();
void UnitMangement_open();
void UnitMangement_update();
void UnitMangement_close();
void UnitMangement_unselect(ENTITY* ent);
# 12 "src/game.c" 2
# 1 "src/building.h" 1
# 12 "src/building.h"
char* buildingPlacement_assets[4];
char* buildingPlacement_constructionAssets[4];


void buildingPlacement_init();
void buildingPlacement_open();
void buildingPlacement_update();

void buildingPlacement_endConstruction();
void buildingPlacement_beginConstruction(int selection);
int buildingState();
# 13 "src/game.c" 2
# 1 "src/fow.h" 1
# 13 "src/fow.h"
void fow_open();
void fow_update();
void fov_uncover(VECTOR *pos, var range);
void fow_close(void);

void fow_uncoverTile(TILE *);
bool fow_isVisible(TILE *);
bool fow_isPosVisible(VECTOR *);
# 14 "src/game.c" 2
# 1 "src/z.h" 1



var z_get(var);
bool z_pay(var,var);
bool z_isSufficient(var,var);
ENTITY* z_findNear(VECTOR* pos, var maxdist);
ENTITY* z_spawn(VECTOR* pos);
void Z();
void Z_Init();
void Z_Update();
void Z__hit(ENTITY* ptr);
void Z__wait(ENTITY* ptr);
void Z__die(ENTITY* ptr);
# 15 "src/game.c" 2
# 1 "src/materials.h" 1
# 1 "src/mainmenu.c" 1




void mainmenu_init(void)
{

 mainmenu_wndMenuBackground = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackground->_forced_background = mainmenu_background;
 mainmenu_wndMenuBackgroundBright = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackgroundBright->_forced_background = mainmenu_background_bright;

 mainmenu_wndMenuMain = uimenu_window_create_borderless(0, 0, 1920, 1080);

 int btnHeight = bmap_height(mainmenu_btn_new_game);
 mainmenu_btnNewGame = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_new_game) / 2), 300 + (btnHeight * 0), 128, 32, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_set_start);
 mainmenu_btnOptions = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_options) / 2), 300 + (btnHeight * 1), 128, 32, mainmenu_btn_options, mainmenu_btn_options, mainmenu_btn_options, mainmenu_show_options);
 mainmenu_btnCredits = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_credits) / 2), 300 + (btnHeight * 2), 128, 32, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_set_credits);
 mainmenu_btnExit = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_exit) / 2), 300 + (btnHeight * 4), 128, 32, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_set_exit);

 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnNewGame);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnOptions);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnCredits);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnExit);

 uimenu_window_initialize(mainmenu_wndMenuMain);
 uimenu_window_initialize(mainmenu_wndMenuBackground);
 uimenu_window_initialize(mainmenu_wndMenuBackgroundBright);

 mainmenu_resolution_update();


 mainmenu_wndMenuOptions = uimenu_window_create( (screen_size.x / 2) - (640 / 2), (screen_size.y / 2) - (480 / 2), 640, 480, "Options");
 uimenu_element_t * optionsExit = uimenu_make_simple_button(640 - 90, 480 - 23, 85, 23, "OK", uimenu_default_font, mainmenu_hide_options);

 uimenu_element_t * optionsTabGeneral = uimenu_make_simple_button(0, 0, 23, "General", uimenu_default_font, mainmenu_show_options_general);
 uimenu_element_t * optionsTabVideo = uimenu_make_simple_button(optionsTabGeneral->x + optionsTabGeneral->width + 2, 0, 23, "Video", uimenu_default_font, mainmenu_show_options_video);
 uimenu_element_t * optionsTabAudio = uimenu_make_simple_button(optionsTabVideo->x + optionsTabVideo->width + 2, 0, 23, "Audio", uimenu_default_font, mainmenu_show_options_audio);
 uimenu_element_t * optionsTabControls = uimenu_make_simple_button(optionsTabAudio->x + optionsTabAudio->width + 2, 0, 23, "Controls", uimenu_default_font, mainmenu_show_options_controls);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsExit);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabGeneral);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabVideo);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabAudio);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabControls);

 uimenu_window_initialize(mainmenu_wndMenuOptions);


 mainmenu_wndMenuOptionsGeneral = uimenu_window_create_borderless(0, 32, 640 - 8, 380);

 uimenu_element_t * generalInfo = uimenu_make_text(5, 5, 100, 32, "Nothing to see here", 0, 0);

 uimenu_add_element_to_window(mainmenu_wndMenuOptionsGeneral, generalInfo);

 uimenu_slave_window_to_window(mainmenu_wndMenuOptions, mainmenu_wndMenuOptionsGeneral);

 uimenu_window_initialize(mainmenu_wndMenuOptionsGeneral);


 mainmenu_wndMenuBackgroundBright->_panel->flags |= (1<<10);
 mainmenu_wndMenuMain->_panel->flags |= (1<<10);
}


void mainmenu_set_start(void)
{
 mainmenu_current_response = 1;
}

void mainmenu_show_options_general(void)
{
 uimenu_window_show(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_video(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_show(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_audio(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_show(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_controls(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_show(mainmenu_wndMenuOptionsControls);
}


void mainmenu_show_options(void)
{
 uimenu_window_show(mainmenu_wndMenuOptions);
 mainmenu_show_options_general();
}
void mainmenu_hide_options(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptions);
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_set_credits(void)
{
 mainmenu_current_response = 2;
}
void mainmenu_set_exit(void)
{
 mainmenu_current_response = 3;
}

void mainmenu_open(void)
{
    mainmenu_current_response = 0;
 music_speedup(100);
 music_start("media/mainmenu.mp3", 0.5, 0);
 uimenu_window_show(mainmenu_wndMenuMain);
 uimenu_window_show(mainmenu_wndMenuBackground);
 uimenu_window_show(mainmenu_wndMenuBackgroundBright);
}

void mainmenu_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  if(mainmenu_wndMenuMain->_is_visible)
  {
   if(total_secs == mainmenu_buzz_wait_time)
   {
    var alpha = 25 + random(75);
    mainmenu_wndMenuMain->_panel->alpha = alpha;
    mainmenu_wndMenuBackgroundBright->_panel->alpha = alpha;
    mainmenu_buzz_handle = snd_play(mainmenu_buzz, alpha, 0);
    snd_tune(mainmenu_buzz_handle, alpha, 100 - (alpha / 10), 0);
    mainmenu_wndMenuMain->_content_panel->scale_x = mainmenu_wndMenuBackground->_content_panel->scale_x * (1 + (random(1) / 100));
    mainmenu_wndMenuMain->_content_panel->scale_y = mainmenu_wndMenuBackground->_content_panel->scale_y * (1 + (random(1) / 100));
   }

   if(total_secs > mainmenu_buzz_wait_time)
   {
    mainmenu_buzz_wait_time = total_secs + integer(random(8));
    mainmenu_resolution_update();
   }
  }
 }
}

void mainmenu_resolution_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  mainmenu_wndMenuMain->_content_panel->scale_x =
  mainmenu_wndMenuBackground->_content_panel->scale_x =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_x =
  screen_size.x / 1920;

  mainmenu_wndMenuMain->_content_panel->scale_y =
  mainmenu_wndMenuBackground->_content_panel->scale_y =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_y =
  screen_size.y / 1080;
 }
}

void mainmenu_close(void)
{
 uimenu_window_destroy(mainmenu_wndMenuBackground);
 uimenu_window_destroy(mainmenu_wndMenuBackgroundBright);
 uimenu_window_destroy(mainmenu_wndMenuMain);
}

int mainmenu_get_response()
{
 return mainmenu_current_response;
}
# 2 "src/materials.h" 2
# 16 "src/game.c" 2
# 1 "src/effects2d.h" 1







void effects2d_init(void);
void effects2d_open(void);
void effects2d_update(void);
void effects2d_close(void);

void effects2d_spawn(VECTOR * worldpos, int type);
# 17 "src/game.c" 2
# 1 "src/ai.h" 1
# 9 "src/ai.h"
 struct _AI_SYSTEM
 {
  int difficulty;
  int money;
  int escalationCounter;
  float elapsedTime, stepTime, unitBuildTimer;
  int buildingCount[4];
  ENTITY* entBuildings[4][8];
 };
 typedef struct _AI_SYSTEM AI_SYSTEM;
 AI_SYSTEM *aiSystemInstance = 0;


 void ai_reset(int difficulty);

 void ai_init(int difficulty);

 void ai_spawn_building(int buildingType);

 void ai_update();
# 18 "src/game.c" 2


void game_init(void)
{
 ui_game_init();
    UnitMangement_init();
    grid_init();
 buildingPlacement_init();
 presetsInit();
    effects2d_init();
 ai_init(1);

    effect_load(mtl_model, "units.fx");
}

void game_open(void)
{



 framework_load_level(0);

    sun_light = 100;




 int loadResult = (jpsMapLoadFromFile("map0.txt") != 0);




 maploader_load("the-core.png");




 ui_game_open();
 topdown_camera_open();

    UnitMangement_open();
    fow_open();



 SPUTNIK_Init();
 SPAWNER_Init();
 Z_Init();
 stub_init();

 grid_open(50,50);
 buildingPlacement_open();




    effects2d_open();

    music_start("media/ingame.mp3", 2.0, 1);
}

void game_update(void)
{

    topdown_camera_update();
    ui_game_update();
    ai_update();
 jpsGameUpdate(mapGetCurrent());
 SPUTNIK_Update();
 SPAWNER_Update();
 Z_Update();
 stub_update();
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
    framework_load_level(0);
}

bool game_is_done(void)
{
 return key_esc;
}
# 36 "main.c" 2
# 1 "src/ui_menu.c" 1




void uimenu_update()
{
    if(uimenu__first_window != 0)
        uimenu_update_chain(uimenu__first_window);
}

void uimenu_update_chain(uimenu_window_t * window)
{
    uimenu__window_update(window);
    if(window->_next != 0)
        uimenu_update_chain(window->_next);
}





uimenu_window_t * uimenu_window_create(var x, var y, var width, var height, char * title)
{
    uimenu_window_t * window = sys_malloc(((int)_sizeof(uimenu_window_t)));
    memset(window, 0, ((int)_sizeof(uimenu_window_t)));
    window->x = x;
    window->y = y;
    window->width = width + (4 * 2);
    window->height = height + (4 * 2) + 22 + 1;
    window->layer = uimenu_last_layer;
    window->title = title;

    window->_panel = 0;
    window->_parent = 0;
    window->_first = 0;
    window->_is_initialized = 0;
    window->_is_visible = 0;
    window->_is_dirty = 1;
    window->_is_borderless = 0;
    window->_is_moving = 0;
    window->_is_titlebar_active = 0;



    uimenu_last_layer += 100;


    window->id = uimenu_window_id++;
    window->_next = uimenu__first_window;
    uimenu__first_window = window;

    return window;
}

uimenu_window_t * uimenu_window_create_borderless(var x, var y, var width, var height)
{
    uimenu_window_t * window = uimenu_window_create(x, y, width, height, "");
    window->width = width;
    window->height = height;
    window->_is_borderless = 1;
    return window;
}

uimenu_element_t * uimenu_element_create(int type, var x, var y, var width, var height)
{
    uimenu_element_t * element = sys_malloc(((int)_sizeof(uimenu_element_t)));
    memset(element, 0, ((int)_sizeof(uimenu_element_t)));
    element->type = type;
    element->x = x;
    element->y = y;
    element->width = width;
    element->height = height;

    element->bmap = 0;
    element->bmap_active = 0;
    element->bmap_hover = 0;
    element->evt_on_click = 0;
    element->evt_on_cancel = 0;
    element->evt_on_enter = 0;
    element->evt_on_leave = 0;

    element->_next = 0;
    element->_related = 0;
    element->_parent = 0;
    element->_child = 0;

    element->_is_dirty = 1;
    element->_is_initialized = 0;

    return element;
}



void uimenu_add_element_to_window(uimenu_window_t * window, uimenu_element_t * element)
{
    if(window == 0) error("UIMENU: window must not be NULL");
    if(element == 0) error("UIMENU: element must not be NULL");

    element->_parent = window;
    if(element->_related != 0) element->_related->_parent = window;

    element->_next = window->_first;
    window->_first = element;
}

void uimenu_slave_window_to_window(uimenu_window_t * master, uimenu_window_t * slave)
{
    if(slave == 0) error("UIMENU: slave must not be NULL");

    slave->_parent = master;
    if(master != 0)
    {
        slave->_child = master->_child;
        master->_child = slave;
    }
}



uimenu_element_t * uimenu_make_text(var x, var y, var width, var height, char * text, COLOR * colorBGR, FONT * font)
{
    uimenu_element_t * element = uimenu_element_create(1, x, y, width, height);

    element->skill[0] = str_create(text);
    if(colorBGR == 0)
        element->skill[2] = vector(255, 255, 255);
    else
        element->skill[2] = colorBGR;

    if(font == 0)
        element->skill[1] = uimenu_default_font;
    else
        element->skill[1] = font;

    return element;
}

uimenu_element_t * uimenu_make_button(var x, var y, var width, var height, BMAP * bmap, BMAP * bmapHover, BMAP * bmapActive, void * evt_on_click)
{
    uimenu_element_t * element = uimenu_element_create(3, x, y, width, height);

    element->bmap = bmap;
    element->bmap_active = bmapActive;
    element->bmap_hover = bmapHover;
    element->evt_on_click = evt_on_click;

    return element;
}

uimenu_element_t * uimenu_make_button(var x, var y, BMAP * bmap, BMAP * bmapHover, BMAP * bmapActive, void * evt_on_click)
{
    return uimenu_make_button(x, y, bmap_width(bmap), bmap_height(bmap), bmap, bmapHover, bmapActive, evt_on_click);
}

uimenu_element_t * uimenu_make_simple_button(var x, var y, var width, var height, char * text, FONT * font, void * evt_on_click)
{
    FONT * finalFont = font;
    if(font == 0)
        finalFont = uimenu_default_font;

    uimenu_element_t * element = uimenu_element_create(8, x, y, width, height);
    var stringWidth = str_width(text, finalFont);

    element->_related = uimenu_make_text(x + (width / 2) - (stringWidth / 2) , y + 3, width, height, text, vector(0, 0, 0), finalFont);
    element->evt_on_click = evt_on_click;

    return element;
}

uimenu_element_t * uimenu_make_simple_button(var x, var y, var height, char * text, FONT * font, void * evt_on_click)
{
    FONT * finalFont = font;
    if(font == 0)
        finalFont = uimenu_default_font;

    var stringWidth = str_width(text, finalFont) + 20;

    uimenu_element_t * element = uimenu_element_create(8, x, y, stringWidth, height);

    element->_related = uimenu_make_text(x + 10, y + 3, stringWidth, height, text, vector(0, 0, 0), finalFont);
    element->evt_on_click = evt_on_click;

    return element;
}

uimenu_element_t * uimenu_make_image(var x, var y, var width, var height, BMAP * bmap)
{
    uimenu_element_t * element = uimenu_element_create(2, x, y, width, height);

    element->bmap = bmap;

    return element;
}

uimenu_element_t * uimenu_make_dropdown(var x, var y, var width, var height, char * nothingSelectedText, var currentValue, uimenu_listitem_t * items, int numItems, void * evt_on_select)
{
    uimenu_element_t * element = uimenu_element_create(4, x, y, width, height);

    element->skill[0] = str_create(nothingSelectedText);
    element->skill[5] = currentValue;
    element->skill[6] = items;
    element->skill[7] = numItems;

    element->evt_on_select = evt_on_select;

    element->_related = uimenu_make_text(
        x + 10,
        y + 5,
        width - 20,
        height,
        nothingSelectedText,
        vector(0, 0, 0),
        uimenu_default_font);

    return element;
}



void uimenu_window_initialize(uimenu_window_t * window)
{

    uimenu__window_initialize(window);
}

void uimenu_window_to_top(uimenu_window_t * window)
{
    if(!uimenu_is_top_window(window))
    {
        window->layer = uimenu_last_layer;
        uimenu__window_make_dirty(uimenu__top_window);
        uimenu__top_window = window;
        uimenu__window_make_dirty(window);

        uimenu_last_layer += 100;
    }
}

int uimenu_is_top_window(uimenu_window_t * window)
{
    if(uimenu__top_window != 0)
    {
        if(uimenu__top_window->id == window->id)
        {
            return 1;
        }
    }

    return 0;
}



void uimenu_window_show(uimenu_window_t * window)
{
    if(window == 0) return;

    if(window->_is_initialized)
    {
        window->_panel->flags |= (1<<14);
        if(window->_is_borderless == 0)
            window->_content_panel->flags |= (1<<14);

        window->_is_visible = 1;

        uimenu__window_make_dirty(window);
    }
}

void uimenu_window_hide(uimenu_window_t * window)
{
    if(window == 0) return;

    if(window->_is_initialized)
    {
        window->_panel->flags &= ~(1<<14);
        if(window->_is_borderless == 0)
            window->_content_panel->flags &= ~(1<<14);

        window->_is_visible = 0;
    }
}

void uimenu_window_destroy(uimenu_window_t * window)
{
    if(window == 0) return;



    uimenu_window_hide(window);
# 308 "src/ui_menu.c"
}





BMAP * uimenu__make_button_graphic(int width, int height, int pressed, int tab)
{
    BMAP * final = bmap_createblack(width, height, 565);
    BMAP * canvas = bmap_createblack(width, height, 565);

    bmap_fill(final, vector(201 * 0.75, 196 * 0.75, 193 * 0.75), 100);
    bmap_fill(canvas, vector(201 * 1.25, 196 * 1.25, 193 * 1.25), 100);

    bmap_blitpart(final, canvas, vector(pressed, pressed, 0), vector(width - 1, height - 1, 0), vector(0, 0, 0), vector(width - 1, height - 1, 0));

    bmap_fill(canvas, vector(201, 196, 193), 100);
    bmap_blitpart(final, canvas, vector(1, 1, 0), vector(width - 2, height - 2 - tab, 0), vector(0, 0, 0), vector(width - 2, height - 2 - tab, 0));

    bmap_purge(canvas);
    return final;
}

BMAP * uimenu__make_field_graphic(int width, int height)
{
    BMAP * final = bmap_createblack(width, height, 565);
    BMAP * canvas = bmap_createblack(width, height, 565);

    bmap_fill(final, vector(201 * 0.75, 196 * 0.75, 193 * 0.75), 100);
    bmap_fill(canvas, vector(201 * 1.25, 196 * 1.25, 193 * 1.25), 100);

    bmap_blitpart(final, canvas, vector(1, 1, 0), vector(width - 1, height - 1, 0), vector(0, 0, 0), vector(width - 1, height - 1, 0));

    bmap_fill(canvas, vector(255, 255, 255), 100);
    bmap_blitpart(final, canvas, vector(1, 1, 0), vector(width - 2, height - 2, 0), vector(0, 0, 0), vector(width - 2, height - 2, 0));

    bmap_purge(canvas);
    return final;
}



VECTOR * uimenu__get_element_screen_offset(uimenu_element_t * element)
{
    if(element == 0) error("UIMENU: element must not be NULL");

    return vector( ((uimenu_window_t*)element->_parent)->_content_panel->pos_x + element->x, ((uimenu_window_t*)element->_parent)->_content_panel->pos_y + element->y, 0);
}

VECTOR * uimenu__get_cursor_offset_to_window(uimenu_window_t * window)
{
    if(window == 0) error("UIMENU: window must not be NULL");

    return vector(mouse_pos.x - window->x, mouse_pos.y - window->y, 0);
}

int uimenu__is_cursor_in_window_titlebar(uimenu_window_t * window)
{
    if(window == 0) error("UIMENU: window must not be NULL");

    VECTOR * cursorOffsetToWindow = uimenu__get_cursor_offset_to_window(window);
    if(cursorOffsetToWindow->x > 4 && cursorOffsetToWindow->x < (window->width - 4))
    {
        if(cursorOffsetToWindow->y > 4 && cursorOffsetToWindow->y < (22 + 4))
        {
            return 1;
        }
    }

    return 0;
}

int uimenu__is_cursor_in_window(uimenu_window_t * window)
{
    if(window == 0) error("UIMENU: window must not be NULL");

    VECTOR * cursorOffsetToWindow = uimenu__get_cursor_offset_to_window(window);
    if(cursorOffsetToWindow->x > 0 && cursorOffsetToWindow->x < window->width)
    {
        if(cursorOffsetToWindow->y > 0 && cursorOffsetToWindow->y < window->height)
        {
            return 1;
        }
    }

    return 0;
}

int uimenu__is_cursor_in_element(uimenu_element_t * element)
{
    if(element == 0) error("UIMENU: element must not be NULL");

    VECTOR * elementScreenOffset = uimenu__get_element_screen_offset(element);
    if(mouse_pos.x >= elementScreenOffset->x && mouse_pos.x <= (elementScreenOffset->x + element->width))
    {
        if(mouse_pos.y >= elementScreenOffset->y && mouse_pos.y <= (elementScreenOffset->y + element->height))
        {
            return 1;
        }
    }

    return 0;
}



void uimenu__window_initialize(uimenu_window_t * window)
{
    if(window == 0) return;

    if(window->_is_initialized == 1) return;

    if(window->_is_borderless == 1)
    {
        window->_panel = pan_create(0, window->layer);
        window->_content_panel = window->_panel;
    }
    else
    {

        if(uimenu__top_window == 0)
            uimenu__top_window = window;

        window->_panel = pan_create(0, window->layer);
        window->_content_panel = pan_create(0, window->layer + 1);


        window->_panel->flags |= ((1<<19));
        vec_set(window->_panel->blue, vector(184, 179, 176));



        window->_title_element_bg_active_bmap = bmap_createblack(
            window->width - (4 * 2),
            22 - 4,
            565);
        bmap_fill(window->_title_element_bg_active_bmap,
            vector(129, 0, 0),
            100);


        window->_title_element_bg_inactive_bmap = bmap_createblack(
            window->width - (4 * 2),
            22 - 4,
            565);
        bmap_fill(window->_title_element_bg_inactive_bmap,
            vector(64, 64, 64),
            100);

        window->_is_titlebar_active = 0;
        window->_title_element_bg_current_bmap = window->_title_element_bg_inactive_bmap;

        window->_title_element_bg_index = pan_setwindow(window->_panel, 0,
            4,
            4,
            window->width - (4 * 2),
            22 - 4,
            window->_title_element_bg_current_bmap, 0, 0);


        window->_title_element_index = pan_setstring(window->_panel,
            0,
            4 * 2,
            4 + 1,
            uimenu_default_font_bold,
            str_create(window->title));
        pan_setcolor(window->_panel,
            1,
            window->_title_element_index,
            vector(255, 255, 255));

    }

    uimenu__sync_panel_with_window(window);


    if(window->_is_borderless == 0)
    {
        window->_content_panel_bg_bmap = bmap_createblack(
            window->_content_panel->size_x,
            window->_content_panel->size_y,
            565);
        bmap_fill(window->_content_panel_bg_bmap,
            vector(201, 196, 193),
            100);
        window->_content_panel->bmap = window->_content_panel_bg_bmap;
    }

    if(window->_forced_background != 0)
        window->_content_panel->bmap = window->_forced_background;

    if(window->_first != 0)
        uimenu__element_initialize(window, window->_first);

    window->_is_initialized = 1;
}

void uimenu__element_initialize(uimenu_window_t * window, uimenu_element_t * element)
{
    if(window == 0) return;
    if(element == 0) return;
    if(window->_content_panel == 0) return;

    if(element->_is_initialized == 0)
    {
        switch(element->type)
        {
            case 8:
                element->bmap = uimenu__make_button_graphic(element->width, element->height, 0, 0);
                element->bmap_hover = element->bmap;
                element->bmap_active = uimenu__make_button_graphic(element->width, element->height, 1, 0);

                element->element_index = pan_setbutton(window->_content_panel, 0, 0,
                element->x,
                element->y,
                element->bmap_active,
                element->bmap,
                element->bmap,
                element->bmap,
                0, 0, 0);
                break;

            case 3:
                element->element_index = pan_setbutton(window->_content_panel, 0, 0,
                element->x,
                element->y,
                element->bmap,
                element->bmap,
                element->bmap_hover,
                element->bmap,
                element->evt_on_click,
                element->evt_on_leave,
                element->evt_on_enter);
                break;

            case 1:
                element->element_index = pan_setstring(window->_content_panel, 0,
                    element->x,
                    element->y,
                    (FONT*)element->skill[1],
                    (STRING*)element->skill[0]);
                pan_setcolor(window->_content_panel, 1, element->element_index, element->skill[2]);
                break;

            case 7:
                element->bmap = bmap_createblack(element->width, element->height, 565);
                bmap_fill(element->bmap, element->skill[2], 100);

            case 2:
                element->element_index = pan_setwindow(window->_content_panel, 0,
                element->x,
                element->y,
                element->width,
                element->height,
                element->bmap, 0, 0);
                break;

            default:

                break;
        }

        if(element->_related != 0)
        {
            if(element->_related->_is_initialized == 0)
                uimenu__element_initialize(window, element->_related);
        }

        element->_is_initialized = 1;
    }

    if(element->_next != 0)
        uimenu__element_initialize(window, element->_next);
}

void uimenu__sync_panel_with_window(uimenu_window_t * window)
{
    if(window == 0) return;
    if(window->_panel == 0) return;

    int fixContent = 0;
    int fixTitlebar = 0;

    if(window->_is_dirty == 1)
    {
        if(window->_parent == 0)
        {
            window->_panel->pos_x = window->x;
            window->_panel->pos_y = window->y;
        }
        else
        {
            window->_panel->pos_x = window->_parent->_content_panel->pos_x + window->x;
            window->_panel->pos_y = window->_parent->_content_panel->pos_y + window->y;
        }

        if(window->width > 0)
            window->_panel->size_x = window->width;
        else
            window->_panel->size_x = screen_size.x * (-window->width / 100.0);

        if(window->height > 0)
            window->_panel->size_y = window->height;
        else
            window->_panel->size_y = screen_size.y * (-window->height / 100.0);

        layer_sort(window->_panel, window->layer);

        if(window->_is_borderless == 0)
        {
            layer_sort(window->_content_panel, window->layer + 1);
            fixContent = 1;

            if(uimenu_is_top_window(window) && window->_is_titlebar_active == 0)
            {
                window->_title_element_bg_current_bmap = window->_title_element_bg_active_bmap;
                fixTitlebar = 1;
            }
            else if(!uimenu_is_top_window(window) && window->_is_titlebar_active == 1)
            {
                window->_title_element_bg_current_bmap = window->_title_element_bg_inactive_bmap;
                fixTitlebar = 1;
            }

            if(fixTitlebar == 1)
            {
                pan_setwindow(window->_panel, window->_title_element_bg_index,
                    4,
                    4,
                    window->width - (4 * 2),
                    22 - 4,
                    window->_title_element_bg_current_bmap, 0, 0);
            }
        }

        window->_is_dirty = 0;
    }


    if(window->_parent == 0)
    {

        if((window->_panel->pos_x + window->_panel->size_x) > screen_size.x)
        {
            window->x = screen_size.x - window->_panel->size_x;

            uimenu__window_make_dirty(window);
        }
        if(window->_panel->pos_x < 0)
        {
            window->_panel->pos_x = 0;

            uimenu__window_make_dirty(window);
            if(window->_is_borderless == 0) fixContent = 1;
        }
        if((window->_panel->pos_y + window->_panel->size_y) > screen_size.y)
        {
            window->y = screen_size.y - window->_panel->size_y;

            uimenu__window_make_dirty(window);
        }
        if(window->_panel->pos_y < 0)
        {
            window->_panel->pos_y = 0;

            uimenu__window_make_dirty(window);
            if(window->_is_borderless == 0) fixContent = 1;
        }
    }

    if(fixContent == 1)
    {
        window->_content_panel->pos_x = window->_panel->pos_x + 4;
        window->_content_panel->pos_y = window->_panel->pos_y + 22 + 1;
        window->_content_panel->size_x = window->_panel->size_x - (4 * 2);
        window->_content_panel->size_y = window->_panel->size_y - (4 + 22);
    }
}

void uimenu__window_make_dirty(uimenu_window_t * window)
{
    if(window == 0) return;
    window->_is_dirty = 1;
    if(window->_child != 0)
        uimenu__window_make_dirty(window->_child);
}

void uimenu__window_update(uimenu_window_t * window)
{
    if(window == 0) return;


    if(window->_is_visible == 1)
    {
        if(window->_is_borderless == 0)
        {
            if(window->_is_moving == 0 && mouse_left && uimenu__is_cursor_in_window_titlebar(window))
            {
                window->_is_moving = 1;
                vec_set(window->_moving_start_offset, uimenu__get_cursor_offset_to_window(window));
            }
            else if(window->_is_moving && mouse_left)
            {
                window->x = mouse_pos.x - window->_moving_start_offset[0];
                window->y = mouse_pos.y - window->_moving_start_offset[1];

                uimenu__window_make_dirty(window);
            }
            else if(window->_is_moving && !mouse_left)
            {
                window->_is_moving = 0;

                uimenu__window_make_dirty(window);
            }
        }

        uimenu__element_update(window->_first);
    }

    uimenu__sync_panel_with_window(window);
}

void uimenu__element_update(uimenu_element_t * element)
{
    if(element == 0) return;

    if(element->type != 3)
    {
        if(uimenu__is_cursor_in_element(element))
        {
            if(element->evt_on_click != 0)
            {
                if(mouse_left)
                {
                    element->_is_pressed = 1;
                }
                else if(element->_is_pressed == 1 && !mouse_left)
                {
                    element->_is_pressed = 0;


                    function callback_evt_on_click();
                    callback_evt_on_click = element->evt_on_click;
                    if(callback_evt_on_click != 0)
                    {
                        callback_evt_on_click();
                    }
                }
            }

            if(element->evt_on_enter != 0 && element->_is_hover == 0)
            {
                element->_is_hover = 1;


                function callback_evt_on_enter();
                callback_evt_on_enter = element->evt_on_enter;
                if(callback_evt_on_enter != 0)
                {
                    callback_evt_on_enter();
                }
            }
        }
        else
        {
            if(element->_is_pressed == 1)
            {

                element->_is_pressed = 0;
                if(element->evt_on_cancel != 0)
                {

                    function callback_evt_on_cancel();
                    callback_evt_on_cancel = element->evt_on_cancel;
                    if(callback_evt_on_cancel != 0)
                    {
                        callback_evt_on_cancel();
                    }
                }
            }

            if(element->evt_on_leave != 0 && element->_is_hover == 1)
            {
                element->_is_hover = 0;


                function callback_evt_on_leave();
                callback_evt_on_leave = element->evt_on_leave;
                if(callback_evt_on_leave != 0)
                {
                    callback_evt_on_leave();
                }
            }
        }
    }

    if(element->_next)
        uimenu__element_update(element->_next);
}
# 37 "main.c" 2
# 1 "src/mainmenu.c" 1




void mainmenu_init(void)
{

 mainmenu_wndMenuBackground = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackground->_forced_background = mainmenu_background;
 mainmenu_wndMenuBackgroundBright = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackgroundBright->_forced_background = mainmenu_background_bright;

 mainmenu_wndMenuMain = uimenu_window_create_borderless(0, 0, 1920, 1080);

 int btnHeight = bmap_height(mainmenu_btn_new_game);
 mainmenu_btnNewGame = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_new_game) / 2), 300 + (btnHeight * 0), 128, 32, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_set_start);
 mainmenu_btnOptions = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_options) / 2), 300 + (btnHeight * 1), 128, 32, mainmenu_btn_options, mainmenu_btn_options, mainmenu_btn_options, mainmenu_show_options);
 mainmenu_btnCredits = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_credits) / 2), 300 + (btnHeight * 2), 128, 32, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_set_credits);
 mainmenu_btnExit = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_exit) / 2), 300 + (btnHeight * 4), 128, 32, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_set_exit);

 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnNewGame);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnOptions);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnCredits);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnExit);

 uimenu_window_initialize(mainmenu_wndMenuMain);
 uimenu_window_initialize(mainmenu_wndMenuBackground);
 uimenu_window_initialize(mainmenu_wndMenuBackgroundBright);

 mainmenu_resolution_update();


 mainmenu_wndMenuOptions = uimenu_window_create( (screen_size.x / 2) - (640 / 2), (screen_size.y / 2) - (480 / 2), 640, 480, "Options");
 uimenu_element_t * optionsExit = uimenu_make_simple_button(640 - 90, 480 - 23, 85, 23, "OK", uimenu_default_font, mainmenu_hide_options);

 uimenu_element_t * optionsTabGeneral = uimenu_make_simple_button(0, 0, 23, "General", uimenu_default_font, mainmenu_show_options_general);
 uimenu_element_t * optionsTabVideo = uimenu_make_simple_button(optionsTabGeneral->x + optionsTabGeneral->width + 2, 0, 23, "Video", uimenu_default_font, mainmenu_show_options_video);
 uimenu_element_t * optionsTabAudio = uimenu_make_simple_button(optionsTabVideo->x + optionsTabVideo->width + 2, 0, 23, "Audio", uimenu_default_font, mainmenu_show_options_audio);
 uimenu_element_t * optionsTabControls = uimenu_make_simple_button(optionsTabAudio->x + optionsTabAudio->width + 2, 0, 23, "Controls", uimenu_default_font, mainmenu_show_options_controls);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsExit);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabGeneral);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabVideo);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabAudio);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabControls);

 uimenu_window_initialize(mainmenu_wndMenuOptions);


 mainmenu_wndMenuOptionsGeneral = uimenu_window_create_borderless(0, 32, 640 - 8, 380);

 uimenu_element_t * generalInfo = uimenu_make_text(5, 5, 100, 32, "Nothing to see here", 0, 0);

 uimenu_add_element_to_window(mainmenu_wndMenuOptionsGeneral, generalInfo);

 uimenu_slave_window_to_window(mainmenu_wndMenuOptions, mainmenu_wndMenuOptionsGeneral);

 uimenu_window_initialize(mainmenu_wndMenuOptionsGeneral);


 mainmenu_wndMenuBackgroundBright->_panel->flags |= (1<<10);
 mainmenu_wndMenuMain->_panel->flags |= (1<<10);
}


void mainmenu_set_start(void)
{
 mainmenu_current_response = 1;
}

void mainmenu_show_options_general(void)
{
 uimenu_window_show(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_video(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_show(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_audio(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_show(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_controls(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_show(mainmenu_wndMenuOptionsControls);
}


void mainmenu_show_options(void)
{
 uimenu_window_show(mainmenu_wndMenuOptions);
 mainmenu_show_options_general();
}
void mainmenu_hide_options(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptions);
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_set_credits(void)
{
 mainmenu_current_response = 2;
}
void mainmenu_set_exit(void)
{
 mainmenu_current_response = 3;
}

void mainmenu_open(void)
{
    mainmenu_current_response = 0;
 music_speedup(100);
 music_start("media/mainmenu.mp3", 0.5, 0);
 uimenu_window_show(mainmenu_wndMenuMain);
 uimenu_window_show(mainmenu_wndMenuBackground);
 uimenu_window_show(mainmenu_wndMenuBackgroundBright);
}

void mainmenu_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  if(mainmenu_wndMenuMain->_is_visible)
  {
   if(total_secs == mainmenu_buzz_wait_time)
   {
    var alpha = 25 + random(75);
    mainmenu_wndMenuMain->_panel->alpha = alpha;
    mainmenu_wndMenuBackgroundBright->_panel->alpha = alpha;
    mainmenu_buzz_handle = snd_play(mainmenu_buzz, alpha, 0);
    snd_tune(mainmenu_buzz_handle, alpha, 100 - (alpha / 10), 0);
    mainmenu_wndMenuMain->_content_panel->scale_x = mainmenu_wndMenuBackground->_content_panel->scale_x * (1 + (random(1) / 100));
    mainmenu_wndMenuMain->_content_panel->scale_y = mainmenu_wndMenuBackground->_content_panel->scale_y * (1 + (random(1) / 100));
   }

   if(total_secs > mainmenu_buzz_wait_time)
   {
    mainmenu_buzz_wait_time = total_secs + integer(random(8));
    mainmenu_resolution_update();
   }
  }
 }
}

void mainmenu_resolution_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  mainmenu_wndMenuMain->_content_panel->scale_x =
  mainmenu_wndMenuBackground->_content_panel->scale_x =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_x =
  screen_size.x / 1920;

  mainmenu_wndMenuMain->_content_panel->scale_y =
  mainmenu_wndMenuBackground->_content_panel->scale_y =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_y =
  screen_size.y / 1080;
 }
}

void mainmenu_close(void)
{
 uimenu_window_destroy(mainmenu_wndMenuBackground);
 uimenu_window_destroy(mainmenu_wndMenuBackgroundBright);
 uimenu_window_destroy(mainmenu_wndMenuMain);
}

int mainmenu_get_response()
{
 return mainmenu_current_response;
}
# 38 "main.c" 2
# 1 "src/credits.c" 1
# 9 "src/credits.c"
STRING * credits_source = "credits.dat";
var credits_scrollSpeed = 2.8;
var credits_speedup = 1;
var credits_speedup_factor = 4;


STRING * credits_fontName = "Arial";
STRING * credits_fontFlags = "b";


var credits_hugeFontSize = 80;
var credits_largeFontSize = 60;
var credits_mediumFontSize = 40;
var credits_normalFontSize = 30;


var credits_imageMarginW = 80;


var credits_imageMarginH = 30;


var credits_textMarginW = 60;


var credits_filmicSepW = 16;


var credits_filmicTextDist = 32;

typedef struct CreditsNode
{
    var height;
    var alignment;
    int fuckYouType;
    STRING * text1;
    STRING * text2;
    BMAP * image;
    int font;
    struct CreditsNode * next;
} CreditsNode;

CreditsNode * credits_firstNode = 0;

FONT * credits_fontset[4];

TEXT * credits_text =
{
    strings = 1;
    string ( "This is stupid!");
    flags = (1<<15);
}

BMAP* credits_bmp_ff = "credits_ff.tga";

PANEL* credits_pnl_ff =
{
    pos_x = 0;
    pos_y = 0;
    size_x = 32;
    size_y = 16;
    bmap = credits_bmp_ff;
    flags = (1<<20);

}



BMAP * credits_backgrounds[100];
VECTOR credits_background_dirs[100];
int credits_background_count;

var credits_timer;
var credits_fadeout;
var credits_render;

var credits_done = 0;

void credits_init()
{
    credits_imageMarginW = screen_size.x * 0.2;
    credits_textMarginW = screen_size.x * 0.2;

    STRING * temp = "#100";
    credits_fontset[0] = font_create(str_printf(temp,
        "%s#%d%s",
        _chr(credits_fontName),
        (int)credits_normalFontSize,
        _chr(credits_fontFlags)));
    credits_fontset[1] = font_create(str_printf(temp,
        "%s#%d%s",
        _chr(credits_fontName),
        (int)credits_mediumFontSize,
        _chr(credits_fontFlags)));
    credits_fontset[2] = font_create(str_printf(temp,
        "%s#%d%s",
        _chr(credits_fontName),
        (int)credits_largeFontSize,
        _chr(credits_fontFlags)));
    credits_fontset[3] = font_create(str_printf(temp,
        "%s#%d%s",
        _chr(credits_fontName),
        (int)credits_hugeFontSize,
        _chr(credits_fontFlags)));

    if(credits_fontset[0] == 0) error("Failed to init font 0");
    if(credits_fontset[1] == 0) error("Failed to init font 1");
    if(credits_fontset[2] == 0) error("Failed to init font 2");
    if(credits_fontset[3] == 0) error("Failed to init font 3");

    var f = file_open_read(credits_source);

    STRING * tempString = "#512";
    STRING * fuckYouTypeString = "#512";
    STRING * inputString = "#512";

    str_cpy(delimit_str, ";\n");

    diag("\nLoading credits data...");

    CreditsNode * it = 0;
    while(1)
    {
        if(file_str_readto(f, fuckYouTypeString, 0, 512) < 0) {
            break;
        }
        CreditsNode * curr = malloc(((int)_sizeof(CreditsNode)));
        memset(curr, 0, ((int)_sizeof(CreditsNode)));

        if(str_cmp("h1", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.font = 3;
            curr.text1 = str_create(inputString);
            curr.alignment = 1;
        }
        else if(str_cmp("h2", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.font = 2;
            curr.text1 = str_create(inputString);
            curr.alignment = 1;
        }
        else if(str_cmp("h3", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.font = 1;
            curr.text1 = str_create(inputString);
            curr.alignment = 1;
        }
        else if(str_cmp("c", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.text1 = str_create(inputString);
            curr.alignment = 1;
        }
        else if(str_cmp("l", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.text1 = str_create(inputString);
            curr.alignment = 0;
        }
        else if(str_cmp("r", fuckYouTypeString)) {
            file_str_read(f, inputString);
            curr.fuckYouType = 0;
            curr.text1 = str_create(inputString);
            curr.alignment = 2;
        }
        else if(str_cmp("x", fuckYouTypeString)) {
            curr.fuckYouType = 0;

            file_str_read(f, inputString);
            curr.text1 = str_create(inputString);

            file_str_read(f, inputString);
            curr.text2 = str_create(inputString);

            curr.alignment = 0;
        }
        else if(str_cmp("f", fuckYouTypeString)) {
            curr.fuckYouType = 3;

            file_str_read(f, inputString);
            curr.text1 = str_create(inputString);

            file_str_read(f, inputString);
            curr.text2 = str_create(inputString);

            curr.alignment = 0;
        }
        else if(str_cmp("i", fuckYouTypeString)) {
            curr.fuckYouType = 1;

            file_str_read(f, inputString);
            curr.image = bmap_create(inputString);
            if(curr.image == 0) {
                str_printf(
                    tempString,
                    "Image %s not found!",
                    _chr(inputString));
                error(tempString);
            }

            curr.alignment = 1;
        }
        else if(str_cmp("s", fuckYouTypeString)) {
            curr.fuckYouType = 2;
            file_str_read(f, inputString);
            curr.height = credits_normalFontSize * str_to_num(inputString);
        }
        else {
            str_printf(
                tempString,
                "Unknown directive recognized: %s",
                _chr(fuckYouTypeString));
            error(tempString);
        }

        if(curr != 0) {
            diag_var("\nnode(%f)", (var)curr.fuckYouType);
            if(it != 0 ) {
                it->next = curr;
            } else {
                credits_firstNode = curr;
            }
            it = curr;
        }
    }

    file_close(f);


    for(credits_background_count = 0; credits_background_count < 100; credits_background_count ++)
    {
        STRING * fname = str_printf(0, "screen_%d.jpg", (credits_background_count + 1));

        credits_background_dirs[credits_background_count].x = random(2) - 1;
        credits_background_dirs[credits_background_count].y = random(2) - 1;
        credits_background_dirs[credits_background_count].z = random(2) - 1;

        if(credits_background_count > 0)
        {

            if(vec_dot(credits_background_dirs[credits_background_count], credits_background_dirs[credits_background_count- 1]) > 0)
                vec_scale(credits_background_dirs[credits_background_count], -1);
        }

        credits_backgrounds[credits_background_count] = bmap_create(fname);
        if(credits_backgrounds[credits_background_count] == 0)
            break;
        bmap_preload(credits_backgrounds[credits_background_count]);
    }
}

void credits_open()
{
    if(credits_firstNode == 0)
    {
        error("Error in credits: failed to initialize credits!");
        return;
    }

    credits_pnl_ff.scale_x = (screen_size.x/16)/32;
    credits_pnl_ff.scale_y = (screen_size.y/16)/16;







 fog_color = 2;
 camera.fog_end = 20000.0;
    level_load(0);

    music_start("media\\ribanna.mp3", 0.5, 0);

    credits_done = 0;
    credits_timer = 0;
    credits_fadeout = 0;
    credits_render = 1;
}

void credits_close()
{
  fog_color = 2;
  camera.fog_end = 20000.0;
    level_load(0);
    credits_pnl_ff.flags &= ~(1<<14);
}

void credits_draw_bg(int id, var fOffset, var alpha)
{
    BMAP * bmp = credits_backgrounds[id];

    var scrollLen = 0.15 * maxv(screen_size.x, screen_size.y);

    var scale_x = (screen_size.x + 2.0 * scrollLen) / bmap_width(bmp);
    var scale_y = (screen_size.y + 2.0 * scrollLen) / bmap_height(bmp);
    var scale = maxv(scale_x, scale_y);

    VECTOR offset;
    vec_set(offset, credits_background_dirs[id]);
    vec_normalize(offset, scrollLen);

    draw_quad(
        bmp,
        vector(
            fOffset * offset.x - scrollLen,
            fOffset * offset.y - scrollLen,
            0),
        0,
        vector(bmap_width(bmp), bmap_height(bmp), 0),
        vector(scale, scale, 0),
        0,
        alpha,
        0);

}

void credits_update()
{
    if(key_esc)
  {
        credits_done = 1;
        return;
    }

    if(credits_background_count > 0)
    {
        var bg_id = (total_ticks / 256);


        bg_id -= credits_background_count * integer(bg_id / credits_background_count);

        var fOffset = fraction(bg_id);

        credits_draw_bg(integer(bg_id), fOffset, 100);

        var altemp = 100.0 * (10.0 * (fraction(bg_id) - 0.9));
        var alnext = 100 - clamp(-altemp, 0, 100);
        if(alnext >= 0)
        {
            credits_draw_bg(integer(bg_id + 1) % credits_background_count, fOffset - 1.0, alnext);
        }
    }



    CreditsNode * it;
    var h = 0;
    var y = screen_size.y - credits_timer;

    if(credits_render)
    {
        for(it = credits_firstNode; it != 0; it = it->next, y += h)
        {
            if(y >= screen_size.y) {
                break;
            }
            h = it.height;
            COLOR * color = vector(0,0,255);
            switch(it->fuckYouType)
            {
                case 0:
                    credits_text.font = credits_fontset[it.font];
                    credits_text.pos_y = y;

                    credits_text.flags &= ~((1<<8) | (1<<7));
                    switch(it.alignment) {
                        case 0:
                            credits_text.pos_x = credits_textMarginW;
                        case 1:
                            credits_text.pos_x = 0.5 * screen_size.x;
                            credits_text.flags |= (1<<8);
                            break;
                        case 2:
                            credits_text.pos_x = screen_size.x - credits_textMarginW;
                            credits_text.flags |= (1<<7);
                            break;
                    }

                    if(it.text1) {
                        (credits_text.pstring)[0] = it.text1;
                        draw_obj(credits_text);
                    }

                    if(it.text2) {
                        credits_text.pos_x = screen_size.x - credits_textMarginW;
                        credits_text.flags |= (1<<7);
                        (credits_text.pstring)[0] = it.text2;
                        draw_obj(credits_text);
                    }

                    y += credits_text.font.dy;
                    break;
                case 1:
                    h = bmap_height(it.image);
                    var w = bmap_width(it.image);
                    var sc = (screen_size.x - 2*credits_imageMarginW) / w;
                    draw_quad(
                        it.image,
                        vector(
                            0.5 * (screen_size.x - sc * w),
                            y + credits_imageMarginH,
                            0),
                        0,
                        vector(w, h, 0), vector(sc, sc, 0),
                        0, 100, 0);
                    h *= sc;
                    h += 2 * credits_imageMarginH;
                    break;
                case 2:
                    break;

                case 3:
                    credits_text.font = credits_fontset[it.font];
                    credits_text.pos_y = y;

                    credits_text.flags &= ~((1<<8) | (1<<7));
                    credits_text.flags |= (1<<7);
                    credits_text.pos_x = 0.5 * screen_size.x - 0.5 * credits_filmicTextDist;
                    (credits_text.pstring)[0] = it.text1;
                    draw_obj(credits_text);

                    draw_quad(
                        0,
                        vector(
                            0.5 * screen_size.x - 0.5 * credits_filmicSepW,
                            y + 0.5 * credits_text.font.dy,
                            0),
                        0,
                        vector(credits_filmicSepW, 1, 0),
                        0,
                        vector(255,255,255),
                        100,
                        0);

                    credits_text.flags &= ~((1<<8) | (1<<7));
                    credits_text.pos_x = 0.5 * screen_size.x + 0.5 * credits_filmicTextDist;
                    (credits_text.pstring)[0] = it.text2;
                    draw_obj(credits_text);

                    y += credits_text.font.dy;
                    break;
                default:
                    error(str_printf(0, "invalid fuckYouType: %d", it.fuckYouType));
                    break;
            }
        }
    }
    credits_render &= (y >= 0);

    if(!credits_render && !music_is_playing())
    {

        draw_quad(
            0,
            vector(0,0,0),
            0,
            screen_size,
            0,
            vector(1,1,1),
            credits_fadeout,
            0);
        if(credits_fadeout >= 100)
            credits_done = 1;
        credits_fadeout += credits_speedup * credits_scrollSpeed * time_step;
    }

    if(key_space)
    {
        credits_speedup = credits_speedup_factor;
        if ((total_ticks % 16) > 8)
        {
            draw_obj(credits_pnl_ff);
        }
    }
    else
    {
        credits_speedup = 1;
    }
    credits_timer += credits_speedup * credits_scrollSpeed * time_step;

    music_speedup(100 * credits_speedup);
}

var credits_isdone()
{
    return credits_done;
}
# 39 "main.c" 2
# 1 "src/music_player.c" 1





typedef struct
{
    var handle_current;
    var handle_last;
    var volume_current;
    var volume_last;
    var crossTime;
    var maxVol;
    var musicCurrentPosition;
    STRING* currentMusic;

    long songStart;
} music_t;

music_t music;

void music_reload_settings()
{

}

void music_init()
{
    music.handle_current = 0;
    music.handle_last = 0;
    music.volume_current = 0;
    music.volume_last = 0;
    music.crossTime = 0;
    music.maxVol = settings.master_volume;
    music.musicCurrentPosition = 0;
    music.currentMusic = 0;


}

void music_start(STRING* file, var crossFadeTime, var loop)
{
    if(music.currentMusic != 0 && file != 0)
 {
        if(str_cmp(music.currentMusic, file) == 1)
   return;
    }
    music.currentMusic = 0;
    if(music.handle_current != 0)
 {
        if(music.handle_last != 0)
  {
            media_stop(music.handle_last);
  }

        music.handle_last = music.handle_current;
        music.volume_last = music.volume_current;
 }

 if(file != 0)
 {
        music.currentMusic = file;

        if(loop != 0)
  {
            music.handle_current = media_loop(file, 0, 0);
  }
  else
  {
            music.handle_current = media_play(file, 0, 0);
        }



        music.songStart = GetTickCount();
        music.musicCurrentPosition = 0;
 }
 else {
        music.handle_current = 0;
 }
    music.volume_current = 0;
    music.crossTime = crossFadeTime;
}

void music_stop()
{
    if(music.handle_current != 0)
 {
        media_stop(music.handle_current);
 }
    if(music.handle_last != 0)
 {
        media_stop(music.handle_last);
 }
}

void music_speedup(var speed)
{
    if (music_is_playing())
 {
        media_tune(music.handle_current, 0, speed, 0);
 }
}

var music_is_playing()
{
    if(music.handle_current != 0 && media_playing(music.handle_current) != 0)
        return 1;
    if(music.handle_last != 0 && media_playing(music.handle_last) != 0)
        return 1;
 return 0;
}

var music_get_time()
{
    if(music_is_playing())
        return GetTickCount() - music.songStart;
    else
        return -1;
}

void music_set_master_volume(var vol)
{
    music.maxVol = vol;
}

var music_get_position()
{
    return music.musicCurrentPosition;
}

void music_update()
{
    music.musicCurrentPosition += time_frame / 16;
    if(music.handle_current != 0 && media_playing(music.handle_current) == 0)
 {
        music_start(0, 0, 0);
 }

    if(music.crossTime == 0)
  return;



    var crossfactor = music.maxVol * (time_step / 16.0) / music.crossTime;





    if(music.handle_current != 0 && music.volume_current < music.maxVol)
 {
        music.volume_current = minv(music.volume_current + crossfactor,music. maxVol);
        media_tune(music.handle_current, music.volume_current, 0, 0);
 }

    if(music.handle_last != 0)
 {
        music.volume_last -= minv(music.volume_last, crossfactor);
        if(music.volume_last == 0)
  {
            media_stop(music.handle_last);
            music.handle_last = 0;
  }
        else
        {
            media_tune(music.handle_last, music.volume_last, 0, 0);
  }
 }
}
# 40 "main.c" 2
# 1 "src/ui_game.c" 1

# 1 "src/unit.h" 1
# 12 "src/unit.h"
var unit_setTarget(ENTITY* ent, VECTOR* pos);
var unit_setVictim(ENTITY* ent, ENTITY* victim);
ENTITY* unit_spawn(int unittype, VECTOR* pos, var owner);
ENTITY* unit_spawn(int unittype, VECTOR* pos, VECTOR* targetPos, var owner);
VECTOR* unit_getTarget(ENTITY* ent);
ENTITY* unit_getVictim(ENTITY* ent);
var unit_getHealth(ENTITY* ent);
var unit_setDamage(ENTITY* victim, ENTITY* attacker);
int unit_getType(ENTITY* ent);
ENTITY* unit_findNextVictim(ENTITY* ptr);
ENTITY* unit_findNextVictim(ENTITY* ptr, var unittype);
void unit_deactivate(ENTITY* ent);
# 3 "src/ui_game.c" 2

# 1 "src/progressbars.h" 1
# 10 "src/progressbars.h"
void progressbar_radial_render(BMAP * _target, var progress, var radius, COLOR * color, var alpha);
# 5 "src/ui_game.c" 2





void ui_spawn_event_sputnik(var num, PANEL *panel)
{
 ENTITY *ent = panel->skill_y;
 if (!ent) { return; }
 spawner_produce(ent);
 ent->skill[39] = 1;
}

void ui_destroy_event_sputnik(var num, PANEL *panel)
{
 ENTITY *ent= panel->skill_y;
 if (!ent) { return; }
 ent->skill[52] = 0;
 ent->skill[54] = 4;
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
 icon->flags |= (1<<14);
 rad->flags |= (1<<14);
}

void ui_hide_radial(PANEL *rad)
{
 if(!rad) { return; }
 PANEL *icon = ptr_for_handle(rad->skill_x);

 icon->flags &= ~(1<<14);
 rad->flags &= ~(1<<14);
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

 pan_setbutton(rad, 0, 0, 0, 0, ui_radial_o, ui_radial_n, ui_radial_o, ui_radial_n, ev, 0, 0);

 rad->scale_x = scale_factor_x;
 rad->scale_y = scale_factor_x;

 PANEL *icon = pan_create("", 3);
 icon->bmap = initial_icon;
 icon->scale_x = scale_factor_x;
 icon->scale_y = scale_factor_x;
 icon->flags |= (1<<0);


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
 ui_life_indicator[ui_lifebar_counter]->flags |= ((1<<14) | (1<<0) | (1<<10));

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

 ui_radial_delete = ui_create_radial_button(0, ui_destroy_event_sputnik);
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
 ui_radial_counter->flags = (1<<8) | (1<<9) | (1<<0);
 pan_setwindow(ui_radial_counter, 0, -5, -4, 128, 128, ui_radial_progress, 0, 0);
 pan_setdigits(ui_radial_counter, 0, bmap_width(ui_radial_n) / 2, bmap_height(ui_radial_n) / 2 , "%.0f", ui_hud_font, 1, &a_dummy_var);

 pan_setbutton(ui_game_menu, 0, 0, 1, 151, ui_hide_button_p, ui_hide_button_n, ui_hide_button_o, ui_hide_button_n, ui_show_commando_groups, 0, 0);

 pan_setbutton(ui_game_menu, 0, 4, 15, 134, ui_icon_tower_o, ui_icon_tower, ui_icon_tower_o, ui_icon_tower, ui_place_building, 0, 0);
 pan_setbutton(ui_game_menu, 0, 4, 15, 242, ui_icon_farm_o, ui_icon_farm, ui_icon_farm_o, ui_icon_farm, ui_place_building, 0, 0);
 pan_setbutton(ui_game_menu, 0, 4, 15, 350, ui_icon_blank_o, ui_icon_blank, ui_icon_blank_o, ui_icon_blank, ui_place_building, 0, 0);
 pan_setbutton(ui_game_menu, 0, 4, 15, 458, ui_icon_bank_o, ui_icon_bank, ui_icon_bank_o, ui_icon_bank, ui_place_building, 0, 0);

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
 ui_main_resources->flags |= (1<<7);
 pan_setdigits(ui_main_resources, 0, bmap_width(ui_bmap_resources) - 50, 13, "%.0f", ui_hud_font, 1, &a_stupid_var );

 ui_monitor->bmap = ui_bmap_monitor;
 ui_minimap->bmap = ui_mm;
 ui_minimap->event = ui_minimap_click;

}

void ui_game_open()
{
 ui_monitor->flags |= (1<<14);
 ui_minimap->flags |= (1<<14);
 ui_minimap->pos_x = 46;
 ui_minimap->pos_y = screen_size.y - (bmap_height(ui_bmap_monitor) + 14) * scale_factor_x;

 ui_game_menu->pos_x = screen_size.x - bmap_width(ui_bmap_gamemenu) + 100;
 ui_game_menu->pos_y = screen_size.y * 0.15;

 ui_unit_meta->pos_y = screen_size.y - bmap_height(ui_bmap_units);
 ui_main_resources->flags |= (1<<14);

 ui_game_menu->flags |= (1<<14);
}

void ui_game_close()
{
 ui_main_resources->flags &= ~(1<<14);
 ui_unit_meta->flags &= ~(1<<14);
 ui_hide_radial(ui_radial_sputnik);
 ui_hide_radial(ui_radial_cbabe);
 ui_hide_radial(ui_radial_skull);
 ui_hide_radial(ui_radial_esel);
 ui_game_menu->flags &= ~(1<<14);
 ui_radial_counter->flags &= ~(1<<14);
 ui_portrait->flags &= ~(1<<14);
 ui_minimap->flags &= ~(1<<14);
 ui_radial_delete->flags &= ~(1<<14);
 ui_monitor->flags &= ~(1<<14);

 int i; for(i = 0; i < 2000; i++)
 {
  if( ui_life_indicator[i] )
  {
   ui_life_indicator[i]->flags &= ~(1<<14);
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
   if( !ent->skill[39] )
   {
    ui_life_indicator[i]->flags &= ~(1<<14);
   }
  }
 }

 scale_factor_x = screen_size.x / 1920;
 scale_factor_y = screen_size.y / 1080;

 if(key_m)
 {
  BMAP* bmp = mapGetBitmap(0);
  if(bmp)
  {
   int size = 4;
   draw_quad(bmp,vector(000,0,0),0,0,vector(size,size,0),0,100,0);
   int unitDrawSize = 4;
   int currentPlayer;
   for(currentPlayer = 0; currentPlayer < 2; currentPlayer++)
   {
    UNIT *unit = mapCurrent.unitFirst[currentPlayer];
    while(unit)
    {
     if(unit->isActive)
     {
      draw_quad(0,vector(unit->pos2d.x*size-unitDrawSize/2,unit->pos2d.y*size-unitDrawSize/2,0),0,vector(4,4,0),0,vector(0,0,255),50,0);
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
 ui_minimap->pos_y = screen_size.y - bmap_height(ui_mm) * scale_factor_x - 12 * scale_factor_x;

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
 for(ent = ent_next(0); ent != 0; ent = ent_next(ent)) if(ent->skill[98] == (99))
 {
  if( ent->skill[39] && ent->skill[52] > 0 )
  {
   if( ent->group == 11 )
   {
    ui_has_building = 1;
    ui_active_building = ent;

    update_or_create_lifebar(ent);

    switch(ent->skill[59])
    {
     case 0:
     ui_radial_active = ui_radial_sputnik;
     ui_radial_sputnik->skill_y = 0;
     break;
     case 1:
     ui_radial_active = ui_radial_esel;
     ui_radial_esel->skill_y = 0;
     break;
     case 2:
     ui_radial_active = ui_radial_skull;
     ui_radial_skull->skill_y = 0;
     break;
     case 3:
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
                if( ent->group == 13 )
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
 for(ent = ent_next(0); ent != 0; ent = ent_next(ent))
 {
  if( ent->group == 10)
  {
   if( ent->skill[39] )
   {
    ui_has_ents = 1;

    switch(unit_getType(ent))
    {
     case 0:
     ui_count_sputniks++;
     break;
     case 1:
     ui_count_esel++;
     break;
     case 2:
     ui_count_skull++;
     break;
     case 3:
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
                if(ent->group == 10)
                {
                    ui_add_dot_to_minimap(ent, 1, ui_bmap_cyan, counter);
                    counter++;
                }
                else if( ent->group == 12 && ent->skill[59] != 4)
                {
                    ui_add_dot_to_minimap(ent, 1, ui_bmap_red, counter);
                    counter++;
                }
            }
        }
 }

 for(ent = ent_next(0); ent != 0; ent = ent_next(ent)) if(ent->skill[98] == (107))
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
  ui_unit_meta->flags |= (1<<14);
  ui_monitor->flags &= ~(1<<14);
  ui_minimap->flags &= ~(1<<14);

  if( ui_count_sputniks >= ui_count_esel && ui_count_sputniks >= ui_count_cbabes && ui_count_sputniks >= ui_count_skull )
  {
   ui_max_type = 1;
   ui_active_portrait = ui_bmap_sputnik;
  }
  else if( ui_count_cbabes >= ui_count_esel && ui_count_cbabes >= ui_count_sputniks && ui_count_sputniks >= ui_count_skull )
  {
   ui_max_type = 2;
   ui_active_portrait = ui_bmap_cbabe;
  }
  else if( ui_count_skull >= ui_count_esel && ui_count_skull >= ui_count_sputniks && ui_count_skull >= ui_count_cbabes )
  {
   ui_max_type = 3;
   ui_active_portrait = ui_bmap_eye;
  }
  else if( ui_count_esel >= ui_count_skull && ui_count_esel >= ui_count_sputniks && ui_count_esel >= ui_count_cbabes )
  {
   ui_max_type = 4;
   ui_active_portrait = ui_bmap_esel;
  }
 }
 else
 {
  ui_unit_meta->flags &= ~(1<<14);
  ui_monitor->flags |= (1<<14);
  ui_minimap->flags |= (1<<14);
 }



 VECTOR screen;

 a_stupid_var = z_get(0);

 if( last_building != ui_active_building)
 {
  ui_hide_radial(ui_radial_sputnik);
  ui_hide_radial(ui_radial_cbabe);
  ui_hide_radial(ui_radial_skull);
  ui_hide_radial(ui_radial_esel);
  ui_anim_state = 3;
  last_building = ui_active_building;
 }

 if( ui_max_type != ui_selected_max_type )
 {
  ui_anim_unit_state = 3;
  ui_anim_state = 0;
  ui_selected_max_type = ui_max_type;
 }

 if( !ui_selected_max_type)
 {
  ui_anim_unit_state = 0;
 }

 if( ui_anim_unit_state == 3 )
 {

  ui_switch_frame = 0;
  pan_setwindow(ui_unit_meta, 1, 408, 98, 196, 186, (ui_active_portrait)[0], 0, 0);
  ui_anim_unit_state = 1;
 }
 else if( ui_anim_unit_state == 1 )
 {
  ui_switch_frame += time_step * 0.4;
  ui_switch_frame %= 19;
  if ( ui_switch_frame >= 13 && ui_switch_frame < 18)
  {
   ui_active_portrait = ui_bmap_noise;
  }
  else if( ui_switch_frame >= 18 )
  {
   ui_anim_unit_state = 0;
  }

  pan_setwindow(ui_unit_meta, 1, 408, 98, 196, 186, (ui_active_portrait)[ui_frame_order[ui_switch_frame]], 0, 0);
 }
 else if( ui_anim_unit_state == 2 )
 {

 }
 else if ( ui_anim_unit_state == 0 )
 {
  pan_setwindow(ui_unit_meta, 1, 0, 0, 0, 0, (ui_bmap_cbabe)[0], 0, 0);
  if( ui_unit_meta->flags & (1<<14) )
  {
   ui_minimap->pos_x = 412 * scale_factor_x;
   ui_minimap->pos_y = screen_size.y - (202 * scale_factor_x);
   mini_map_extra_scale_x = 0.69;
   mini_map_extra_scale_y = 0.58;
   ui_minimap->scale_x = scale_factor_x * mini_map_extra_scale_x;
   ui_minimap->scale_y = scale_factor_x * mini_map_extra_scale_y;
   ui_minimap->flags |= (1<<14);
  }
  else
  {
   mini_map_extra_scale_x = 1;
   mini_map_extra_scale_y = 1;
  }
 }


 if(!last_building || !ui_has_building)
 {
  last_building = 0;
  ui_anim_state = 0;
 }
 else
 {
  vec_set(screen, last_building.x);
  vec_to_screen(screen, camera);
 }

 if( ui_radial_active )
 {

  if( ui_anim_state == 3 )
  {
   ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
   ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
   ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

   ui_anim_unit_state = 0;

   ui_show_radial(ui_radial_active);
   ui_scale_radial(ui_radial_active, 0.1);

   ui_show_radial(ui_radial_delete);
   ui_scale_radial(ui_radial_delete, 0.1);

   ui_radial_counter->flags |= (1<<14);
   ui_radial_counter->scale_x = 0.1;
   ui_radial_counter->scale_y = 0.1;

   ui_anim_state = 1;
  }
  else if( ui_anim_state == 1 )
  {
   ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
   ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
   ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

   if( ui_scale1 <= scale_factor_x )
   {
    ui_scale1 += time_step * 0.3;
   }
   if( ui_scale1 >= 0.5 * scale_factor_x )
   {
    ui_scale2 += time_step * 0.3;
   }
   if( ui_scale2 >= 0.5* scale_factor_x )
   {
    ui_scale3 += time_step * 0.3;
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
    ui_anim_state = 2;
   }
  }
  else if( ui_anim_state == 2 )
  {
   ui_orbit_radial(ui_radial_active,screen.x, screen.y, 270, 200);
   ui_orbit_radial(ui_radial_delete,screen.x, screen.y, 230, 200);
   ui_orbit_radial(ui_radial_counter,screen.x, screen.y, 190, 200);

   ui_scale_radial(ui_radial_active, scale_factor_x);
   ui_scale_radial(ui_radial_delete, scale_factor_x);

   ui_radial_counter->scale_x = scale_factor_x;
   ui_radial_counter->scale_y = scale_factor_x;


  }
  else if ( ui_anim_state == 0 )
  {
   ui_hide_radial(ui_radial_active);
   ui_hide_radial(ui_radial_delete);
   ui_radial_counter->flags &= ~(1<<14);

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
# 41 "main.c" 2
# 1 "src/map_loader.c" 1


# 1 "src/materials.h" 1
# 1 "src/mainmenu.c" 1




void mainmenu_init(void)
{

 mainmenu_wndMenuBackground = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackground->_forced_background = mainmenu_background;
 mainmenu_wndMenuBackgroundBright = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackgroundBright->_forced_background = mainmenu_background_bright;

 mainmenu_wndMenuMain = uimenu_window_create_borderless(0, 0, 1920, 1080);

 int btnHeight = bmap_height(mainmenu_btn_new_game);
 mainmenu_btnNewGame = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_new_game) / 2), 300 + (btnHeight * 0), 128, 32, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_set_start);
 mainmenu_btnOptions = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_options) / 2), 300 + (btnHeight * 1), 128, 32, mainmenu_btn_options, mainmenu_btn_options, mainmenu_btn_options, mainmenu_show_options);
 mainmenu_btnCredits = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_credits) / 2), 300 + (btnHeight * 2), 128, 32, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_set_credits);
 mainmenu_btnExit = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_exit) / 2), 300 + (btnHeight * 4), 128, 32, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_set_exit);

 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnNewGame);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnOptions);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnCredits);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnExit);

 uimenu_window_initialize(mainmenu_wndMenuMain);
 uimenu_window_initialize(mainmenu_wndMenuBackground);
 uimenu_window_initialize(mainmenu_wndMenuBackgroundBright);

 mainmenu_resolution_update();


 mainmenu_wndMenuOptions = uimenu_window_create( (screen_size.x / 2) - (640 / 2), (screen_size.y / 2) - (480 / 2), 640, 480, "Options");
 uimenu_element_t * optionsExit = uimenu_make_simple_button(640 - 90, 480 - 23, 85, 23, "OK", uimenu_default_font, mainmenu_hide_options);

 uimenu_element_t * optionsTabGeneral = uimenu_make_simple_button(0, 0, 23, "General", uimenu_default_font, mainmenu_show_options_general);
 uimenu_element_t * optionsTabVideo = uimenu_make_simple_button(optionsTabGeneral->x + optionsTabGeneral->width + 2, 0, 23, "Video", uimenu_default_font, mainmenu_show_options_video);
 uimenu_element_t * optionsTabAudio = uimenu_make_simple_button(optionsTabVideo->x + optionsTabVideo->width + 2, 0, 23, "Audio", uimenu_default_font, mainmenu_show_options_audio);
 uimenu_element_t * optionsTabControls = uimenu_make_simple_button(optionsTabAudio->x + optionsTabAudio->width + 2, 0, 23, "Controls", uimenu_default_font, mainmenu_show_options_controls);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsExit);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabGeneral);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabVideo);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabAudio);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabControls);

 uimenu_window_initialize(mainmenu_wndMenuOptions);


 mainmenu_wndMenuOptionsGeneral = uimenu_window_create_borderless(0, 32, 640 - 8, 380);

 uimenu_element_t * generalInfo = uimenu_make_text(5, 5, 100, 32, "Nothing to see here", 0, 0);

 uimenu_add_element_to_window(mainmenu_wndMenuOptionsGeneral, generalInfo);

 uimenu_slave_window_to_window(mainmenu_wndMenuOptions, mainmenu_wndMenuOptionsGeneral);

 uimenu_window_initialize(mainmenu_wndMenuOptionsGeneral);


 mainmenu_wndMenuBackgroundBright->_panel->flags |= (1<<10);
 mainmenu_wndMenuMain->_panel->flags |= (1<<10);
}


void mainmenu_set_start(void)
{
 mainmenu_current_response = 1;
}

void mainmenu_show_options_general(void)
{
 uimenu_window_show(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_video(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_show(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_audio(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_show(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_controls(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_show(mainmenu_wndMenuOptionsControls);
}


void mainmenu_show_options(void)
{
 uimenu_window_show(mainmenu_wndMenuOptions);
 mainmenu_show_options_general();
}
void mainmenu_hide_options(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptions);
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_set_credits(void)
{
 mainmenu_current_response = 2;
}
void mainmenu_set_exit(void)
{
 mainmenu_current_response = 3;
}

void mainmenu_open(void)
{
    mainmenu_current_response = 0;
 music_speedup(100);
 music_start("media/mainmenu.mp3", 0.5, 0);
 uimenu_window_show(mainmenu_wndMenuMain);
 uimenu_window_show(mainmenu_wndMenuBackground);
 uimenu_window_show(mainmenu_wndMenuBackgroundBright);
}

void mainmenu_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  if(mainmenu_wndMenuMain->_is_visible)
  {
   if(total_secs == mainmenu_buzz_wait_time)
   {
    var alpha = 25 + random(75);
    mainmenu_wndMenuMain->_panel->alpha = alpha;
    mainmenu_wndMenuBackgroundBright->_panel->alpha = alpha;
    mainmenu_buzz_handle = snd_play(mainmenu_buzz, alpha, 0);
    snd_tune(mainmenu_buzz_handle, alpha, 100 - (alpha / 10), 0);
    mainmenu_wndMenuMain->_content_panel->scale_x = mainmenu_wndMenuBackground->_content_panel->scale_x * (1 + (random(1) / 100));
    mainmenu_wndMenuMain->_content_panel->scale_y = mainmenu_wndMenuBackground->_content_panel->scale_y * (1 + (random(1) / 100));
   }

   if(total_secs > mainmenu_buzz_wait_time)
   {
    mainmenu_buzz_wait_time = total_secs + integer(random(8));
    mainmenu_resolution_update();
   }
  }
 }
}

void mainmenu_resolution_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  mainmenu_wndMenuMain->_content_panel->scale_x =
  mainmenu_wndMenuBackground->_content_panel->scale_x =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_x =
  screen_size.x / 1920;

  mainmenu_wndMenuMain->_content_panel->scale_y =
  mainmenu_wndMenuBackground->_content_panel->scale_y =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_y =
  screen_size.y / 1080;
 }
}

void mainmenu_close(void)
{
 uimenu_window_destroy(mainmenu_wndMenuBackground);
 uimenu_window_destroy(mainmenu_wndMenuBackgroundBright);
 uimenu_window_destroy(mainmenu_wndMenuMain);
}

int mainmenu_get_response()
{
 return mainmenu_current_response;
}
# 2 "src/materials.h" 2
# 4 "src/map_loader.c" 2

# 1 "/home/felix/gstudio8/include/d3d9.h" 1
# 90 "/home/felix/gstudio8/include/d3d9.h"
typedef struct WAVEFORMATEX {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
} WAVEFORMATEX;

typedef struct DSBUFFERDESC {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwBufferBytes;
    DWORD dwReserved;
    WAVEFORMATEX* lpwfxFormat;
    GUID guid3DAlgorithm;
} DSBUFFERDESC;




typedef struct _D3DVECTOR {
    float x;
    float y;
    float z;
} D3DVECTOR;




typedef struct _D3DCOLORVALUE {
    float r;
    float g;
    float b;
    float a;
} D3DCOLORVALUE;




typedef struct _D3DRECT {
    LONG x1;
    LONG y1;
    LONG x2;
    LONG y2;
} D3DRECT;




typedef struct _D3DMATRIX {
        float m[4][4];
} D3DMATRIX;
# 165 "/home/felix/gstudio8/include/d3d9.h"
typedef struct _D3DVIEWPORT9 {
    DWORD X;
    DWORD Y;
    DWORD Width;
    DWORD Height;
    float MinZ;
    float MaxZ;
} D3DVIEWPORT9;

typedef struct _D3DMATERIAL9 {
    D3DCOLORVALUE Diffuse;
    D3DCOLORVALUE Ambient;
    D3DCOLORVALUE Specular;
    D3DCOLORVALUE Emissive;
    float Power;
} D3DMATERIAL9;

typedef struct _D3DLIGHT9 {
    long Type;
    D3DCOLORVALUE Diffuse;
    D3DCOLORVALUE Specular;
    D3DCOLORVALUE Ambient;
    D3DVECTOR Position;
    D3DVECTOR Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
} D3DLIGHT9;

typedef long D3DXIMAGE_FILEFORMAT;

typedef struct _D3DXIMAGE_INFO
{
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    long Format;
    long ResourceType;
    D3DXIMAGE_FILEFORMAT ImageFileFormat;
} D3DXIMAGE_INFO;

typedef struct _D3DBOX
{
    UINT Left;
    UINT Top;
    UINT Right;
    UINT Bottom;
    UINT Front;
    UINT Back;
} D3DBOX;







typedef struct D3DXVECTOR2 {
    float x; float y;
} D3DXVECTOR2;

typedef struct D3DXVECTOR4 {
    float x; float y; float z; float w;
} D3DXVECTOR4;

typedef struct D3DXQUATERNION {
    float x; float y; float z; float w;
} D3DXQUATERNION;

typedef struct D3DXPLANE {
    float x; float y; float z; float w;
} D3DXPLANE;

typedef struct D3DXCOLOR {
    float r, g, b, a;
} D3DXCOLOR;
# 263 "/home/felix/gstudio8/include/d3d9.h"
typedef struct _D3DPRESENT_PARAMETERS_
{
    UINT BackBufferWidth;
    UINT BackBufferHeight;
    long BackBufferFormat;
    UINT BackBufferCount;

    long MultiSampleType;
    DWORD MultiSampleQuality;

    long SwapEffect;
    HWND hDeviceWindow;
    BOOL Windowed;
    BOOL EnableAutoDepthStencil;
    long AutoDepthStencilFormat;
    DWORD Flags;


    UINT FullScreen_RefreshRateInHz;
    UINT PresentationInterval;
} D3DPRESENT_PARAMETERS;




struct IDirect3D9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall RegisterSoftwareDevice(void * _This , void* pInitializeFunction) ;
    UINT __stdcall GetAdapterCount(void * _This) ;
    long __stdcall GetAdapterIdentifier(void * _This , UINT Adapter,DWORD Flags,void* pIdentifier) ;
    UINT __stdcall GetAdapterModeCount(void * _This , UINT Adapter,long Format) ;
    long __stdcall EnumAdapterModes(void * _This , UINT Adapter,long Format,UINT Mode,void* pMode) ;
    long __stdcall GetAdapterDisplayMode(void * _This , UINT Adapter,void* pMode) ;
    long __stdcall CheckDeviceType(void * _This , UINT iAdapter,long DevType,long DisplayFormat,long BackBufferFormat,BOOL bWindowed) ;
    long __stdcall CheckDeviceFormat(void * _This , UINT Adapter,long DeviceType,long AdapterFormat,DWORD Usage,long RType,long CheckFormat) ;
    long __stdcall CheckDeviceMultiSampleType(void * _This , UINT Adapter,long DeviceType,long SurfaceFormat,BOOL Windowed,long MultiSampleType,DWORD* pQualityLevels) ;
    long __stdcall CheckDepthStencilMatch(void * _This , UINT Adapter,long DeviceType,long AdapterFormat,long RenderTargetFormat,long DepthStencilFormat) ;
    long __stdcall CheckDeviceFormatConversion(void * _This , UINT Adapter,long DeviceType,long SourceFormat,long TargetFormat) ;
    long __stdcall GetDeviceCaps(void * _This , UINT Adapter,long DeviceType,void* pCaps) ;
    long __stdcall GetAdapterMonitor(void * _This , UINT Adapter) ;
    long __stdcall CreateDevice(void * _This , UINT Adapter,long DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,void** ppReturnedDeviceInterface) ;
};

typedef struct IDirect3D9Vtbl IDirect3D9Vtbl;typedef interface IDirect3D9 {IDirect3D9Vtbl * lpVtbl;} IDirect3D9;

typedef IDirect3D9 * LPDIRECT3D9;




struct IDirect3DDevice9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall TestCooperativeLevel(void * _This) ;
    UINT __stdcall GetAvailableTextureMem(void * _This) ;
    long __stdcall EvictManagedResources(void * _This) ;
    long __stdcall GetDirect3D(void * _This , IDirect3D9** ppD3D9) ;
    long __stdcall GetDeviceCaps(void * _This , void* pCaps) ;
    long __stdcall GetDisplayMode(void * _This , UINT iSwapChain,void* pMode) ;
    long __stdcall GetCreationParameters(void * _This , void *pParameters) ;
    long __stdcall SetCursorProperties(void * _This , UINT XHotSpot,UINT YHotSpot,void* pCursorBitmap) ;
    void __stdcall SetCursorPosition(void * _This , int X,int Y,DWORD Flags) ;
    BOOL __stdcall ShowCursor(void * _This , BOOL bShow) ;
    long __stdcall CreateAdditionalSwapChain(void * _This , D3DPRESENT_PARAMETERS* pPresentationParameters,void** pSwapChain) ;
    long __stdcall GetSwapChain(void * _This , UINT iSwapChain,void** pSwapChain) ;
    UINT __stdcall GetNumberOfSwapChains(void * _This) ;
    long __stdcall Reset(void * _This , D3DPRESENT_PARAMETERS* pPresentationParameters) ;
    long __stdcall Present(void * _This , RECT* pSourceRect, RECT* pDestRect,HWND hDestWindowOverride, void* pDirtyRegion) ;
    long __stdcall GetBackBuffer(void * _This , UINT iSwapChain,UINT iBackBuffer,long Type,void** ppBackBuffer) ;
    long __stdcall GetRasterStatus(void * _This , UINT iSwapChain,void* pRasterStatus) ;
    long __stdcall SetDialogBoxMode(void * _This , BOOL bEnableDialogs) ;
    void __stdcall SetGammaRamp(void * _This , UINT iSwapChain,DWORD Flags, void* pRamp) ;
    void __stdcall GetGammaRamp(void * _This , UINT iSwapChain,void* pRamp) ;
    long __stdcall CreateTexture(void * _This , UINT Width,UINT Height,UINT Levels,DWORD Usage,long Format,long Pool,void** ppTexture,HANDLE* pSharedHandle) ;
    long __stdcall CreateVolumeTexture(void * _This , UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,long Format,long Pool,void** ppVolumeTexture,HANDLE* pSharedHandle) ;
    long __stdcall CreateCubeTexture(void * _This , UINT EdgeLength,UINT Levels,DWORD Usage,long Format,long Pool,void** ppCubeTexture,HANDLE* pSharedHandle) ;
    long __stdcall CreateVertexBuffer(void * _This , UINT Length,DWORD Usage,DWORD FVF,long Pool,void** ppVertexBuffer,HANDLE* pSharedHandle) ;
    long __stdcall CreateIndexBuffer(void * _This , UINT Length,DWORD Usage,long Format,long Pool,void** ppIndexBuffer,HANDLE* pSharedHandle) ;
    long __stdcall CreateRenderTarget(void * _This , UINT Width,UINT Height,long Format,long MultiSample,DWORD MultisampleQuality,BOOL Lockable,void** ppSurface,HANDLE* pSharedHandle) ;
    long __stdcall CreateDepthStencilSurface(void * _This , UINT Width,UINT Height,long Format,long MultiSample,DWORD MultisampleQuality,BOOL Discard,void** ppSurface,HANDLE* pSharedHandle) ;
    long __stdcall UpdateSurface(void * _This , void* pSourceSurface, RECT* pSourceRect,void* pDestinationSurface, POINT* pDestPoint) ;
    long __stdcall UpdateTexture(void * _This , void* pSourceTexture,void* pDestinationTexture) ;
    long __stdcall GetRenderTargetData(void * _This , void* pRenderTarget,void* pDestSurface) ;
    long __stdcall GetFrontBufferData(void * _This , UINT iSwapChain,void* pDestSurface) ;
    long __stdcall StretchRect(void * _This , void* pSourceSurface, RECT* pSourceRect,void* pDestSurface, RECT* pDestRect,long Filter) ;
    long __stdcall ColorFill(void * _This , void* pSurface, RECT* pRect,long color) ;
    long __stdcall CreateOffscreenPlainSurface(void * _This , UINT Width,UINT Height,long Format,long Pool,void** ppSurface,HANDLE* pSharedHandle) ;
    long __stdcall SetRenderTarget(void * _This , DWORD RenderTargetIndex,void* pRenderTarget) ;
    long __stdcall GetRenderTarget(void * _This , DWORD RenderTargetIndex,void** ppRenderTarget) ;
    long __stdcall SetDepthStencilSurface(void * _This , void* pNewZStencil) ;
    long __stdcall GetDepthStencilSurface(void * _This , void** ppZStencilSurface) ;
    long __stdcall BeginScene(void * _This) ;
    long __stdcall EndScene(void * _This) ;
    long __stdcall Clear(void * _This , DWORD Count, D3DRECT* pRects,DWORD Flags,long Color,float Z,DWORD Stencil) ;
    long __stdcall SetTransform(void * _This , long State, D3DMATRIX* pMatrix) ;
    long __stdcall GetTransform(void * _This , long State,D3DMATRIX* pMatrix) ;
    long __stdcall MultiplyTransform(void * _This , long, D3DMATRIX*) ;
    long __stdcall SetViewport(void * _This , D3DVIEWPORT9* pViewport) ;
    long __stdcall GetViewport(void * _This , D3DVIEWPORT9* pViewport) ;
    long __stdcall SetMaterial(void * _This , D3DMATERIAL9* pMaterial) ;
    long __stdcall GetMaterial(void * _This , D3DMATERIAL9* pMaterial) ;
    long __stdcall SetLight(void * _This , DWORD Index, D3DLIGHT9*) ;
    long __stdcall GetLight(void * _This , DWORD Index,D3DLIGHT9*) ;
    long __stdcall LightEnable(void * _This , DWORD Index,BOOL Enable) ;
    long __stdcall GetLightEnable(void * _This , DWORD Index,BOOL* pEnable) ;
    long __stdcall SetClipPlane(void * _This , DWORD Index, float* pPlane) ;
    long __stdcall GetClipPlane(void * _This , DWORD Index,float* pPlane) ;
    long __stdcall SetRenderState(void * _This , long State,DWORD Value) ;
    long __stdcall GetRenderState(void * _This , long State,DWORD* pValue) ;
    long __stdcall CreateStateBlock(void * _This , long Type,void** ppSB) ;
    long __stdcall BeginStateBlock(void * _This) ;
    long __stdcall EndStateBlock(void * _This , void** ppSB) ;
    long __stdcall SetClipStatus(void * _This , void* pClipStatus) ;
    long __stdcall GetClipStatus(void * _This , void* pClipStatus) ;
    long __stdcall GetTexture(void * _This , DWORD Stage,void** ppTexture) ;
    long __stdcall SetTexture(void * _This , DWORD Stage,void* pTexture) ;
    long __stdcall GetTextureStageState(void * _This , DWORD Stage,long Type,DWORD* pValue) ;
    long __stdcall SetTextureStageState(void * _This , DWORD Stage,long Type,DWORD Value) ;
    long __stdcall GetSamplerState(void * _This , DWORD Sampler,long Type,DWORD* pValue) ;
    long __stdcall SetSamplerState(void * _This , DWORD Sampler,long Type,DWORD Value) ;
    long __stdcall ValidateDevice(void * _This , DWORD* pNumPasses) ;
    long __stdcall SetPaletteEntries(void * _This , UINT PaletteNumber, void* pEntries) ;
    long __stdcall GetPaletteEntries(void * _This , UINT PaletteNumber,void* pEntries) ;
    long __stdcall SetCurrentTexturePalette(void * _This , UINT PaletteNumber) ;
    long __stdcall GetCurrentTexturePalette(void * _This , UINT *PaletteNumber) ;
    long __stdcall SetScissorRect(void * _This , RECT* pRect) ;
    long __stdcall GetScissorRect(void * _This , RECT* pRect) ;
    long __stdcall SetSoftwareVertexProcessing(void * _This , BOOL bSoftware) ;
    BOOL __stdcall GetSoftwareVertexProcessing(void * _This) ;
    long __stdcall SetNPatchMode(void * _This , float nSegments) ;
    float __stdcall GetNPatchMode(void * _This) ;
    long __stdcall DrawPrimitive(void * _This , long PrimitiveType,UINT StartVertex,UINT PrimitiveCount) ;
    long __stdcall DrawIndexedPrimitive(void * _This , long,int BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) ;
    long __stdcall DrawPrimitiveUP(void * _This , long PrimitiveType,UINT PrimitiveCount, void* pVertexStreamZeroData,UINT VertexStreamZeroStride) ;
    long __stdcall DrawIndexedPrimitiveUP(void * _This , long PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount, void* pIndexData,long IndexDataFormat, void* pVertexStreamZeroData,UINT VertexStreamZeroStride) ;
    long __stdcall ProcessVertices(void * _This , UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,void* pDestBuffer,void* pVertexDecl,DWORD Flags) ;
    long __stdcall CreateVertexDeclaration(void * _This , void* pVertexElements,void** ppDecl) ;
    long __stdcall SetVertexDeclaration(void * _This , void* pDecl) ;
    long __stdcall GetVertexDeclaration(void * _This , void** ppDecl) ;
    long __stdcall SetFVF(void * _This , DWORD FVF) ;
    long __stdcall GetFVF(void * _This , DWORD* pFVF) ;
    long __stdcall CreateVertexShader(void * _This , DWORD* pFunction,void** ppShader) ;
    long __stdcall SetVertexShader(void * _This , void* pShader) ;
    long __stdcall GetVertexShader(void * _This , void** ppShader) ;
    long __stdcall SetVertexShaderConstantF(void * _This , UINT StartRegister, float* pConstantData,UINT Vector4fCount) ;
    long __stdcall GetVertexShaderConstantF(void * _This , UINT StartRegister,float* pConstantData,UINT Vector4fCount) ;
    long __stdcall SetVertexShaderConstantI(void * _This , UINT StartRegister, int* pConstantData,UINT Vector4iCount) ;
    long __stdcall GetVertexShaderConstantI(void * _This , UINT StartRegister,int* pConstantData,UINT Vector4iCount) ;
    long __stdcall SetVertexShaderConstantB(void * _This , UINT StartRegister, BOOL* pConstantData,UINT BoolCount) ;
    long __stdcall GetVertexShaderConstantB(void * _This , UINT StartRegister,BOOL* pConstantData,UINT BoolCount) ;
    long __stdcall SetStreamSource(void * _This , UINT StreamNumber,void* pStreamData,UINT OffsetInBytes,UINT Stride) ;
    long __stdcall GetStreamSource(void * _This , UINT StreamNumber,void** ppStreamData,UINT* OffsetInBytes,UINT* pStride) ;
    long __stdcall SetStreamSourceFreq(void * _This , UINT StreamNumber,UINT Divider) ;
    long __stdcall GetStreamSourceFreq(void * _This , UINT StreamNumber,UINT* Divider) ;
    long __stdcall SetIndices(void * _This , void* pIndexData) ;
    long __stdcall GetIndices(void * _This , void** ppIndexData) ;
    long __stdcall CreatePixelShader(void * _This , DWORD* pFunction,void** ppShader) ;
    long __stdcall SetPixelShader(void * _This , void* pShader) ;
    long __stdcall GetPixelShader(void * _This , void** ppShader) ;
    long __stdcall SetPixelShaderConstantF(void * _This , UINT StartRegister, float* pConstantData,UINT Vector4fCount) ;
    long __stdcall GetPixelShaderConstantF(void * _This , UINT StartRegister,float* pConstantData,UINT Vector4fCount) ;
    long __stdcall SetPixelShaderConstantI(void * _This , UINT StartRegister, int* pConstantData,UINT Vector4iCount) ;
    long __stdcall GetPixelShaderConstantI(void * _This , UINT StartRegister,int* pConstantData,UINT Vector4iCount) ;
    long __stdcall SetPixelShaderConstantB(void * _This , UINT StartRegister, BOOL* pConstantData,UINT BoolCount) ;
    long __stdcall GetPixelShaderConstantB(void * _This , UINT StartRegister,BOOL* pConstantData,UINT BoolCount) ;
    long __stdcall DrawRectPatch(void * _This , UINT Handle, float* pNumSegs, void* pRectPatchInfo) ;
    long __stdcall DrawTriPatch(void * _This , UINT Handle, float* pNumSegs, void* pTriPatchInfo) ;
    long __stdcall DeletePatch(void * _This , UINT Handle) ;
    long __stdcall CreateQuery(void * _This , long Type,void** ppQuery) ;
};

typedef struct IDirect3DDevice9Vtbl IDirect3DDevice9Vtbl;typedef interface IDirect3DDevice9 {IDirect3DDevice9Vtbl * lpVtbl;} IDirect3DDevice9;
typedef IDirect3DDevice9 *LPDIRECT3DDEVICE9;





struct IDirect3DVertexBuffer9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDevice(void * _This , IDirect3DDevice9** ppDevice) ;
    long __stdcall SetPrivateData(void * _This , long refguid, void* pData,DWORD SizeOfData,DWORD Flags) ;
    long __stdcall GetPrivateData(void * _This , long refguid,void* pData,DWORD* pSizeOfData) ;
    long __stdcall FreePrivateData(void * _This , long refguid) ;
    DWORD __stdcall SetPriority(void * _This , DWORD PriorityNew) ;
    DWORD __stdcall GetPriority(void * _This) ;
    void __stdcall PreLoad(void * _This) ;
    long __stdcall GetType(void * _This) ;
    long __stdcall Lock(void * _This , UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) ;
    long __stdcall Unlock(void * _This) ;
    long __stdcall GetDesc(void * _This , void *pDesc) ;
};

typedef struct IDirect3DVertexBuffer9Vtbl IDirect3DVertexBuffer9Vtbl;typedef interface IDirect3DVertexBuffer9 {IDirect3DVertexBuffer9Vtbl * lpVtbl;} IDirect3DVertexBuffer9;

typedef IDirect3DVertexBuffer9 *LPDIRECT3DVERTEXBUFFER9;





struct IDirect3DTexture9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDevice(void * _This , IDirect3DDevice9** ppDevice) ;
    long __stdcall SetPrivateData(void * _This , long refguid, void* pData,DWORD SizeOfData,DWORD Flags) ;
    long __stdcall GetPrivateData(void * _This , long refguid,void* pData,DWORD* pSizeOfData) ;
    long __stdcall FreePrivateData(void * _This , long refguid) ;
    DWORD __stdcall SetPriority(void * _This , DWORD PriorityNew) ;
    DWORD __stdcall GetPriority(void * _This) ;
    void __stdcall PreLoad(void * _This) ;
    long __stdcall GetType(void * _This) ;
    DWORD __stdcall SetLOD(void * _This , DWORD LODNew) ;
    DWORD __stdcall GetLOD(void * _This) ;
    DWORD __stdcall GetLevelCount(void * _This) ;
    long __stdcall SetAutoGenFilterType(void * _This , long FilterType) ;
    long __stdcall GetAutoGenFilterType(void * _This) ;
    void __stdcall GenerateMipSubLevels(void * _This) ;
    long __stdcall GetLevelDesc(void * _This , UINT Level,void *pDesc) ;
    long __stdcall GetSurfaceLevel(void * _This , UINT Level,void** ppSurfaceLevel) ;
    long __stdcall LockRect(void * _This , UINT Level,void* pLockedRect, RECT* pRect,DWORD Flags) ;
    long __stdcall UnlockRect(void * _This , UINT Level) ;
    long __stdcall AddDirtyRect(void * _This , RECT* pDirtyRect) ;
};
typedef struct IDirect3DTexture9Vtbl IDirect3DTexture9Vtbl;typedef interface IDirect3DTexture9 {IDirect3DTexture9Vtbl * lpVtbl;} IDirect3DTexture9;
typedef IDirect3DTexture9 *LPDIRECT3DTEXTURE9;




struct IDirect3DSurface9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDevice(void * _This , IDirect3DDevice9** ppDevice) ;
    long __stdcall SetPrivateData(void * _This , long refguid, void* pData,DWORD SizeOfData,DWORD Flags) ;
    long __stdcall GetPrivateData(void * _This , long refguid,void* pData,DWORD* pSizeOfData) ;
    long __stdcall FreePrivateData(void * _This , long refguid) ;
    DWORD __stdcall SetPriority(void * _This , DWORD PriorityNew) ;
    DWORD __stdcall GetPriority(void * _This) ;
    void __stdcall PreLoad(void * _This) ;
    long __stdcall GetType(void * _This) ;
    long __stdcall GetContainer(void * _This , long riid,void** ppContainer) ;
    long __stdcall GetDesc(void * _This , void *pDesc) ;
    long __stdcall LockRect(void * _This , void* pLockedRect, RECT* pRect,DWORD Flags) ;
    long __stdcall UnlockRect(void * _This) ;
    long __stdcall GetDC(void * _This , HDC *phdc) ;
    long __stdcall ReleaseDC(void * _This , HDC hdc) ;
};
typedef struct IDirect3DSurface9Vtbl IDirect3DSurface9Vtbl;typedef interface IDirect3DSurface9 {IDirect3DSurface9Vtbl * lpVtbl;} IDirect3DSurface9;
typedef IDirect3DSurface9 *LPDIRECT3DSURFACE9;




struct ID3DXBufferVtbl
{

    long __stdcall QueryInterface(void * _This , long iid, LPVOID *ppv) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    LPVOID __stdcall GetBufferPointer(void * _This) ;
    DWORD __stdcall GetBufferSize(void * _This) ;
};
typedef struct ID3DXBufferVtbl ID3DXBufferVtbl;typedef interface ID3DXBuffer {ID3DXBufferVtbl * lpVtbl;} ID3DXBuffer;
typedef ID3DXBuffer *LPD3DXBUFFER;




struct ID3DXBaseMeshVtbl
{

    long __stdcall QueryInterface(void * _This , long iid, LPVOID *ppv) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall DrawSubset(void * _This , DWORD AttribId) ;
    DWORD __stdcall GetNumFaces(void * _This) ;
    DWORD __stdcall GetNumVertices(void * _This) ;
    DWORD __stdcall GetFVF(void * _This) ;
    long __stdcall GetDeclaration(void * _This , void *) ;
    DWORD __stdcall GetNumBytesPerVertex(void * _This) ;
    DWORD __stdcall GetOptions(void * _This) ;
    long __stdcall GetDevice(void * _This , LPDIRECT3DDEVICE9* ppDevice) ;
    long __stdcall CloneMeshFVF(void * _This , DWORD Options,
                DWORD FVF, LPDIRECT3DDEVICE9 pD3DDevice, void* ppCloneMesh) ;
    long __stdcall CloneMesh(void * _This , DWORD Options,
                void *pDeclaration, LPDIRECT3DDEVICE9 pD3DDevice, void* ppCloneMesh) ;
    long __stdcall GetVertexBuffer(void * _This , LPDIRECT3DVERTEXBUFFER9* ppVB) ;
    long __stdcall GetIndexBuffer(void * _This , void* ppIB) ;
    long __stdcall LockVertexBuffer(void * _This , DWORD Flags, void** ppData) ;
    long __stdcall UnlockVertexBuffer(void * _This) ;
    long __stdcall LockIndexBuffer(void * _This , DWORD Flags, void** ppData) ;
    long __stdcall UnlockIndexBuffer(void * _This) ;
    long __stdcall GetAttributeTable(
                void * _This , void *pAttribTable, DWORD* pAttribTableSize) ;

    long __stdcall ConvertPointRepsToAdjacency(void * _This , DWORD* pPRep, DWORD* pAdjacency) ;
    long __stdcall ConvertAdjacencyToPointReps(void * _This , DWORD* pAdjacency, DWORD* pPRep) ;
    long __stdcall GenerateAdjacency(void * _This , float Epsilon, DWORD* pAdjacency) ;

    long __stdcall UpdateSemantics(void * _This , void *) ;
};
typedef struct ID3DXBaseMeshVtbl ID3DXBaseMeshVtbl;typedef interface ID3DXBaseMesh {ID3DXBaseMeshVtbl * lpVtbl;} ID3DXBaseMesh;
typedef ID3DXBaseMesh *LPD3DXBASEMESH;




struct ID3DXMeshVtbl
{

    long __stdcall QueryInterface(void * _This , long iid, LPVOID *ppv) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall DrawSubset(void * _This , DWORD AttribId) ;
    DWORD __stdcall GetNumFaces(void * _This) ;
    DWORD __stdcall GetNumVertices(void * _This) ;
    DWORD __stdcall GetFVF(void * _This) ;
    long __stdcall GetDeclaration(void * _This , void *) ;
    DWORD __stdcall GetNumBytesPerVertex(void * _This) ;
    DWORD __stdcall GetOptions(void * _This) ;
    long __stdcall GetDevice(void * _This , LPDIRECT3DDEVICE9* ppDevice) ;
    long __stdcall CloneMeshFVF(void * _This , DWORD Options,
                DWORD FVF, LPDIRECT3DDEVICE9 pD3DDevice, void* ppCloneMesh) ;
    long __stdcall CloneMesh(void * _This , DWORD Options,
                void *pDeclaration, LPDIRECT3DDEVICE9 pD3DDevice, void* ppCloneMesh) ;
    long __stdcall GetVertexBuffer(void * _This , LPDIRECT3DVERTEXBUFFER9* ppVB) ;
    long __stdcall GetIndexBuffer(void * _This , void* ppIB) ;
    long __stdcall LockVertexBuffer(void * _This , DWORD Flags, void** ppData) ;
    long __stdcall UnlockVertexBuffer(void * _This) ;
    long __stdcall LockIndexBuffer(void * _This , DWORD Flags, void** ppData) ;
    long __stdcall UnlockIndexBuffer(void * _This) ;
    long __stdcall GetAttributeTable(
                void * _This , void *pAttribTable, DWORD* pAttribTableSize) ;

    long __stdcall ConvertPointRepsToAdjacency(void * _This , DWORD* pPRep, DWORD* pAdjacency) ;
    long __stdcall ConvertAdjacencyToPointReps(void * _This , DWORD* pAdjacency, DWORD* pPRep) ;
    long __stdcall GenerateAdjacency(void * _This , float Epsilon, DWORD* pAdjacency) ;

    long __stdcall UpdateSemantics(void * _This , void *) ;


    long __stdcall LockAttributeBuffer(void * _This , DWORD Flags, DWORD** ppData) ;
    long __stdcall UnlockAttributeBuffer(void * _This) ;
    long __stdcall Optimize(void * _This , DWORD Flags, DWORD* pAdjacencyIn, DWORD* pAdjacencyOut,
                     DWORD* pFaceRemap, LPD3DXBUFFER *ppVertexRemap,
                     void* ppOptMesh) ;
    long __stdcall OptimizeInplace(void * _This , DWORD Flags, DWORD* pAdjacencyIn, DWORD* pAdjacencyOut,
                     DWORD* pFaceRemap, LPD3DXBUFFER *ppVertexRemap) ;
    long __stdcall SetAttributeTable(void * _This , void *pAttribTable, DWORD cAttribTableSize) ;
};
typedef struct ID3DXMeshVtbl ID3DXMeshVtbl;typedef interface ID3DXMesh {ID3DXMeshVtbl * lpVtbl;} ID3DXMesh;
typedef ID3DXMesh *LPD3DXMESH;


typedef struct _D3DXMATERIAL
{
    D3DMATERIAL9 MatD3D;
    LPSTR pTextureFilename;
} D3DXMATERIAL;
typedef D3DXMATERIAL *LPD3DXMATERIAL;

typedef LPCSTR D3DXHANDLE;
typedef D3DXHANDLE *LPD3DXHANDLE;

typedef struct _D3DXEFFECT_DESC
{
    LPCSTR Creator;
    UINT Parameters;
    UINT Techniques;
    UINT Functions;
} D3DXEFFECT_DESC;

typedef DWORD D3DXPARAMETER_CLASS;
typedef DWORD D3DXPARAMETER_TYPE;

typedef struct _D3DXPARAMETER_DESC
{
    LPCSTR Name;
    LPCSTR Semantic;
    D3DXPARAMETER_CLASS Class;
    D3DXPARAMETER_TYPE Type;
    UINT Rows;
    UINT Columns;
    UINT Elements;
    UINT Annotations;
    UINT StructMembers;
    DWORD Flags;
    UINT Bytes;
} D3DXPARAMETER_DESC;

typedef struct _D3DXTECHNIQUE_DESC
{
    LPCSTR Name;
    UINT Passes;
    UINT Annotations;
} D3DXTECHNIQUE_DESC;

typedef struct _D3DXPASS_DESC
{
    LPCSTR Name;
    UINT Annotations;
    DWORD *pVertexShaderFunction;
    DWORD *pPixelShaderFunction;
} D3DXPASS_DESC;

typedef struct _D3DXFUNCTION_DESC
{
    LPCSTR Name;
    UINT Annotations;
} D3DXFUNCTION_DESC;




struct IDirect3DVertexShader9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDevice(void * _This , IDirect3DDevice9** ppDevice) ;
    long __stdcall GetFunction(void * _This , void*,UINT* pSizeOfData) ;
};
typedef struct IDirect3DVertexShader9Vtbl IDirect3DVertexShader9Vtbl;typedef interface IDirect3DVertexShader9 {IDirect3DVertexShader9Vtbl * lpVtbl;} IDirect3DVertexShader9;
typedef IDirect3DVertexShader9 *LPDIRECT3DVERTEXSHADER9;




struct IDirect3DPixelShader9Vtbl
{

    long __stdcall QueryInterface(void * _This , long riid, void** ppvObj) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDevice(void * _This , IDirect3DDevice9** ppDevice) ;
    long __stdcall GetFunction(void * _This , void*,UINT* pSizeOfData) ;
};
typedef struct IDirect3DPixelShader9Vtbl IDirect3DPixelShader9Vtbl;typedef interface IDirect3DPixelShader9 {IDirect3DPixelShader9Vtbl * lpVtbl;} IDirect3DPixelShader9;
typedef IDirect3DPixelShader9 *LPDIRECT3DPIXELSHADER9;




struct ID3DXEffectVtbl
{

    long __stdcall QueryInterface(void * _This , long iid, LPVOID *ppv) ;
    long __stdcall AddRef(void * _This) ;
    long __stdcall Release(void * _This) ;


    long __stdcall GetDesc(void * _This , D3DXEFFECT_DESC* pDesc) ;
    long __stdcall GetParameterDesc(void * _This , D3DXHANDLE hParameter, D3DXPARAMETER_DESC* pDesc) ;
    long __stdcall GetTechniqueDesc(void * _This , D3DXHANDLE hTechnique, D3DXTECHNIQUE_DESC* pDesc) ;
    long __stdcall GetPassDesc(void * _This , D3DXHANDLE hPass, D3DXPASS_DESC* pDesc) ;
    long __stdcall GetFunctionDesc(void * _This , D3DXHANDLE hShader, D3DXFUNCTION_DESC* pDesc) ;


    D3DXHANDLE __stdcall GetParameter(void * _This , D3DXHANDLE hParameter, UINT Index) ;
    D3DXHANDLE __stdcall GetParameterByName(void * _This , D3DXHANDLE hParameter, LPCSTR pName) ;
    D3DXHANDLE __stdcall GetParameterBySemantic(void * _This , D3DXHANDLE hParameter, LPCSTR pSemantic) ;
    D3DXHANDLE __stdcall GetParameterElement(void * _This , D3DXHANDLE hParameter, UINT Index) ;
    D3DXHANDLE __stdcall GetTechnique(void * _This , UINT Index) ;
    D3DXHANDLE __stdcall GetTechniqueByName(void * _This , LPCSTR pName) ;
    D3DXHANDLE __stdcall GetPass(void * _This , D3DXHANDLE hTechnique, UINT Index) ;
    D3DXHANDLE __stdcall GetPassByName(void * _This , D3DXHANDLE hTechnique, LPCSTR pName) ;
    D3DXHANDLE __stdcall GetFunction(void * _This , UINT Index) ;
    D3DXHANDLE __stdcall GetFunctionByName(void * _This , LPCSTR pName) ;
    D3DXHANDLE __stdcall GetAnnotation(void * _This , D3DXHANDLE hObject, UINT Index) ;
    D3DXHANDLE __stdcall GetAnnotationByName(void * _This , D3DXHANDLE hObject, LPCSTR pName) ;


    long __stdcall SetValue(void * _This , D3DXHANDLE hParameter, void* pData, UINT Bytes) ;
    long __stdcall GetValue(void * _This , D3DXHANDLE hParameter, LPVOID pData, UINT Bytes) ;
    long __stdcall SetBool(void * _This , D3DXHANDLE hParameter, BOOL b) ;
    long __stdcall GetBool(void * _This , D3DXHANDLE hParameter, BOOL* pb) ;
    long __stdcall SetBoolArray(void * _This , D3DXHANDLE hParameter, BOOL* pb, UINT Count) ;
    long __stdcall GetBoolArray(void * _This , D3DXHANDLE hParameter, BOOL* pb, UINT Count) ;
    long __stdcall SetInt(void * _This , D3DXHANDLE hParameter, int n) ;
    long __stdcall GetInt(void * _This , D3DXHANDLE hParameter, int* pn) ;
    long __stdcall SetIntArray(void * _This , D3DXHANDLE hParameter, int* pn, UINT Count) ;
    long __stdcall GetIntArray(void * _This , D3DXHANDLE hParameter, int* pn, UINT Count) ;
    long __stdcall SetFloat(void * _This , D3DXHANDLE hParameter, float f) ;
    long __stdcall GetFloat(void * _This , D3DXHANDLE hParameter, float* pf) ;
    long __stdcall SetFloatArray(void * _This , D3DXHANDLE hParameter, float* pf, UINT Count) ;
    long __stdcall GetFloatArray(void * _This , D3DXHANDLE hParameter, float* pf, UINT Count) ;
    long __stdcall SetVector(void * _This , D3DXHANDLE hParameter, D3DXVECTOR4* pVector) ;
    long __stdcall GetVector(void * _This , D3DXHANDLE hParameter, D3DXVECTOR4* pVector) ;
    long __stdcall SetVectorArray(void * _This , D3DXHANDLE hParameter, D3DXVECTOR4* pVector, UINT Count) ;
    long __stdcall GetVectorArray(void * _This , D3DXHANDLE hParameter, D3DXVECTOR4* pVector, UINT Count) ;
    long __stdcall SetMatrix(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix) ;
    long __stdcall GetMatrix(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix) ;
    long __stdcall SetMatrixArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix, UINT Count) ;
    long __stdcall GetMatrixArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix, UINT Count) ;
    long __stdcall SetMatrixPointerArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX** ppMatrix, UINT Count) ;
    long __stdcall GetMatrixPointerArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX** ppMatrix, UINT Count) ;
    long __stdcall SetMatrixTranspose(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix) ;
    long __stdcall GetMatrixTranspose(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix) ;
    long __stdcall SetMatrixTransposeArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix, UINT Count) ;
    long __stdcall GetMatrixTransposeArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX* pMatrix, UINT Count) ;
    long __stdcall SetMatrixTransposePointerArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX** ppMatrix, UINT Count) ;
    long __stdcall GetMatrixTransposePointerArray(void * _This , D3DXHANDLE hParameter, D3DMATRIX** ppMatrix, UINT Count) ;
    long __stdcall SetString(void * _This , D3DXHANDLE hParameter, LPCSTR pString) ;
    long __stdcall GetString(void * _This , D3DXHANDLE hParameter, LPCSTR* ppString) ;
    long __stdcall SetTexture(void * _This , D3DXHANDLE hParameter, LPVOID pTexture) ;
    long __stdcall GetTexture(void * _This , D3DXHANDLE hParameter, LPVOID *ppTexture) ;
    long __stdcall GetPixelShader(void * _This , D3DXHANDLE hParameter, LPDIRECT3DPIXELSHADER9 *ppPShader) ;
    long __stdcall GetVertexShader(void * _This , D3DXHANDLE hParameter, LPDIRECT3DVERTEXSHADER9 *ppVShader) ;



 long __stdcall SetArrayRange(void * _This , D3DXHANDLE hParameter, UINT uStart, UINT uEnd) ;




    long __stdcall GetPool(void * _This , LPVOID *ppPool) ;


    long __stdcall SetTechnique(void * _This , D3DXHANDLE hTechnique) ;
    D3DXHANDLE __stdcall GetCurrentTechnique(void * _This) ;
    long __stdcall ValidateTechnique(void * _This , D3DXHANDLE hTechnique) ;
    long __stdcall FindNextValidTechnique(void * _This , D3DXHANDLE hTechnique, D3DXHANDLE *pTechnique) ;
    BOOL __stdcall IsParameterUsed(void * _This , D3DXHANDLE hParameter, D3DXHANDLE hTechnique) ;
# 834 "/home/felix/gstudio8/include/d3d9.h"
    long __stdcall Begin(void * _This , UINT *pPasses, DWORD Flags) ;
    long __stdcall BeginPass(void * _This , UINT Pass) ;
    long __stdcall CommitChanges(void * _This) ;
    long __stdcall EndPass(void * _This) ;
    long __stdcall End(void * _This) ;


    long __stdcall GetDevice(void * _This , LPDIRECT3DDEVICE9* ppDevice) ;
    long __stdcall OnLostDevice(void * _This) ;
    long __stdcall OnResetDevice(void * _This) ;


    long __stdcall SetStateManager(void * _This , LPVOID pManager) ;
    long __stdcall GetStateManager(void * _This , LPVOID *ppManager) ;


    long __stdcall BeginParameterBlock(void * _This) ;
    D3DXHANDLE __stdcall EndParameterBlock(void * _This) ;
    long __stdcall ApplyParameterBlock(void * _This , D3DXHANDLE hParameterBlock) ;
    long __stdcall DeleteParameterBlock(void * _This , D3DXHANDLE hParameterBlock) ;


    long __stdcall CloneEffect(void * _This , LPDIRECT3DDEVICE9 pDevice, LPVOID *ppEffect) ;


    long __stdcall SetRawValue(void * _This , D3DXHANDLE hParameter, void* pData, UINT ByteOffset, UINT Bytes) ;
};
typedef struct ID3DXEffectVtbl ID3DXEffectVtbl;typedef interface ID3DXEffect {ID3DXEffectVtbl * lpVtbl;} ID3DXEffect;
typedef ID3DXEffect *LPD3DXEFFECT;


typedef struct _D3DXATTRIBUTEWEIGHTS
{
    float Position;
    float Boundary;
    float Normal;
    float Diffuse;
    float Specular;
    float Texcoord[8];
    float Tangent;
    float Binormal;
} D3DXATTRIBUTEWEIGHTS;
typedef D3DXATTRIBUTEWEIGHTS *LPD3DXATTRIBUTEWEIGHTS;
# 1136 "/home/felix/gstudio8/include/d3d9.h"
IDirect3D9 * __stdcall Direct3DCreate9(UINT SDKVersion);



BOOL __stdcall D3DXCheckVersion(UINT D3DSdkVersion, UINT D3DXSdkVersion);

BOOL __stdcall D3DXDebugMute(BOOL Mute);

UINT __stdcall D3DXGetDriverLevel(LPDIRECT3DDEVICE9 pDevice);
# 1161 "/home/felix/gstudio8/include/d3d9.h"
D3DXCOLOR* __stdcall D3DXColorAdjustSaturation
    (D3DXCOLOR *pOut, D3DXCOLOR *pC, float s);


D3DXCOLOR* __stdcall D3DXColorAdjustContrast
    (D3DXCOLOR *pOut, D3DXCOLOR *pC, float c);
# 1210 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall D3DXCreateTextureFromFileA(
        LPDIRECT3DDEVICE9 pDevice,
        LPCSTR pSrcFile,
        LPDIRECT3DTEXTURE9* ppTexture);



HRESULT __stdcall
    D3DXGetImageInfoFromFileA(
        LPCSTR pSrcFile,
        D3DXIMAGE_INFO* pSrcInfo);



HRESULT __stdcall
    D3DXGetImageInfoFromResourceA(
        HMODULE hSrcModule,
        LPCSTR pSrcResource,
        D3DXIMAGE_INFO* pSrcInfo);



HRESULT __stdcall
    D3DXGetImageInfoFromFileInMemory(
        void* pSrcData,
        UINT SrcDataSize,
        D3DXIMAGE_INFO* pSrcInfo);

HRESULT __stdcall
    D3DXLoadSurfaceFromFileA(
        LPDIRECT3DSURFACE9 pDestSurface,
        void* pDestPalette,
        RECT* pDestRect,
        LPCSTR pSrcFile,
        RECT* pSrcRect,
        DWORD Filter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo);



HRESULT __stdcall
    D3DXLoadSurfaceFromResourceA(
        LPDIRECT3DSURFACE9 pDestSurface,
        void* pDestPalette,
        RECT* pDestRect,
        HMODULE hSrcModule,
        LPCSTR pSrcResource,
        RECT* pSrcRect,
        DWORD Filter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo);



HRESULT __stdcall
    D3DXLoadSurfaceFromFileInMemory(
        LPDIRECT3DSURFACE9 pDestSurface,
        void* pDestPalette,
        RECT* pDestRect,
        void* pSrcData,
        UINT SrcDataSize,
        RECT* pSrcRect,
        DWORD Filter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo);

HRESULT __stdcall
    D3DXLoadSurfaceFromSurface(
        LPDIRECT3DSURFACE9 pDestSurface,
        void* pDestPalette,
        RECT* pDestRect,
        LPDIRECT3DSURFACE9 pSrcSurface,
        void* pSrcPalette,
        RECT* pSrcRect,
        DWORD Filter,
        long ColorKey);

HRESULT __stdcall
    D3DXLoadSurfaceFromMemory(
        LPDIRECT3DSURFACE9 pDestSurface,
        void* pDestPalette,
        RECT* pDestRect,
        void* pSrcMemory,
        long SrcFormat,
        UINT SrcPitch,
        void* pSrcPalette,
        RECT* pSrcRect,
        DWORD Filter,
        long ColorKey);

HRESULT __stdcall
    D3DXSaveSurfaceToFileA(
        LPCSTR pDestFile,
        D3DXIMAGE_FILEFORMAT DestFormat,
        LPDIRECT3DSURFACE9 pSrcSurface,
        void* pSrcPalette,
        RECT* pSrcRect);



HRESULT __stdcall
    D3DXSaveSurfaceToFileInMemory(
        LPD3DXBUFFER* ppDestBuf,
        D3DXIMAGE_FILEFORMAT DestFormat,
        LPDIRECT3DSURFACE9 pSrcSurface,
        void* pSrcPalette,
        RECT* pSrcRect);
# 1403 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCheckTextureRequirements(
        LPDIRECT3DDEVICE9 pDevice,
        UINT* pWidth,
        UINT* pHeight,
        UINT* pNumMipLevels,
        DWORD Usage,
        long* pFormat,
        long Pool);

HRESULT __stdcall
    D3DXCheckCubeTextureRequirements(
        LPDIRECT3DDEVICE9 pDevice,
        UINT* pSize,
        UINT* pNumMipLevels,
        DWORD Usage,
        long* pFormat,
        long Pool);

HRESULT __stdcall
    D3DXCheckVolumeTextureRequirements(
        LPDIRECT3DDEVICE9 pDevice,
        UINT* pWidth,
        UINT* pHeight,
        UINT* pDepth,
        UINT* pNumMipLevels,
        DWORD Usage,
        long* pFormat,
        long Pool);

HRESULT __stdcall
    D3DXCreateTexture(
        LPDIRECT3DDEVICE9 pDevice,
        UINT Width,
        UINT Height,
        UINT MipLevels,
        DWORD Usage,
        long Format,
        long Pool,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1466 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromFileA(
        LPDIRECT3DDEVICE9 pDevice,
        LPCSTR pSrcFile,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1490 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromResourceA(
        LPDIRECT3DDEVICE9 pDevice,
        HMODULE hSrcModule,
        LPCSTR pSrcResource,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1517 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromFileExA(
        LPDIRECT3DDEVICE9 pDevice,
        LPCSTR pSrcFile,
        UINT Width,
        UINT Height,
        UINT MipLevels,
        DWORD Usage,
        long Format,
        long Pool,
        DWORD Filter,
        DWORD MipFilter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo,
        void* pPalette,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1574 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromResourceExA(
        LPDIRECT3DDEVICE9 pDevice,
        HMODULE hSrcModule,
        LPCSTR pSrcResource,
        UINT Width,
        UINT Height,
        UINT MipLevels,
        DWORD Usage,
        long Format,
        long Pool,
        DWORD Filter,
        DWORD MipFilter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo,
        void* pPalette,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1634 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromFileInMemory(
        LPDIRECT3DDEVICE9 pDevice,
        void* pSrcData,
        UINT SrcDataSize,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1655 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateTextureFromFileInMemoryEx(
        LPDIRECT3DDEVICE9 pDevice,
        void* pSrcData,
        UINT SrcDataSize,
        UINT Width,
        UINT Height,
        UINT MipLevels,
        DWORD Usage,
        long Format,
        long Pool,
        DWORD Filter,
        DWORD MipFilter,
        long ColorKey,
        D3DXIMAGE_INFO* pSrcInfo,
        void* pPalette,
        LPDIRECT3DTEXTURE9* ppTexture);
# 1768 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXComputeNormalMap(
        LPDIRECT3DTEXTURE9 pTexture,
        LPDIRECT3DTEXTURE9 pSrcTexture,
        void* pSrcPalette,
        DWORD Flags,
        DWORD Channel,
        float Amplitude);
# 1854 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXCreateMesh(
        DWORD NumFaces,
        DWORD NumVertices,
        DWORD Options,
        void *pDeclaration,
        LPDIRECT3DDEVICE9 pD3DDevice,
        LPD3DXMESH* ppMesh);

HRESULT __stdcall
    D3DXCreateMeshFVF(
        DWORD NumFaces,
        DWORD NumVertices,
        DWORD Options,
        DWORD FVF,
        LPDIRECT3DDEVICE9 pD3DDevice,
        LPD3DXMESH* ppMesh);
# 1890 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXValidMesh(
    LPD3DXMESH pMeshIn,
    DWORD* pAdjacency,
    LPD3DXBUFFER* ppErrorsAndWarnings);
# 1906 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXSimplifyMesh(
        LPD3DXMESH pMesh,
        DWORD* pAdjacency,
        D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights,
        float *pVertexWeights,
        DWORD MinValue,
        DWORD Options,
        LPD3DXMESH* ppMesh);

HRESULT __stdcall
    D3DXComputeBoundingSphere(
        D3DVECTOR *pFirstPosition,
        DWORD NumVertices,
        DWORD dwStride,
        D3DVECTOR *pCenter,
        float *pRadius);

HRESULT __stdcall
    D3DXComputeBoundingBox(
        D3DVECTOR *pFirstPosition,
        DWORD NumVertices,
        DWORD dwStride,
        D3DVECTOR *pMin,
        D3DVECTOR *pMax);

HRESULT __stdcall
    D3DXComputeNormals(
        LPD3DXBASEMESH pMesh,
        DWORD *pAdjacency);

HRESULT __stdcall
    D3DXCreateBuffer(
        DWORD NumBytes,
        LPD3DXBUFFER *ppBuffer);


HRESULT __stdcall
    D3DXLoadMeshFromXA(
        LPCSTR pFilename,
        DWORD Options,
        LPDIRECT3DDEVICE9 pD3DDevice,
        LPD3DXBUFFER *ppAdjacency,
        LPD3DXBUFFER *ppMaterials,
        LPD3DXBUFFER *ppEffectInstances,
        DWORD *pNumMaterials,
        LPD3DXMESH *ppMesh);



HRESULT __stdcall
    D3DXLoadMeshFromXInMemory(
        void* Memory,
        DWORD SizeOfMemory,
        DWORD Options,
        LPDIRECT3DDEVICE9 pD3DDevice,
        LPD3DXBUFFER *ppAdjacency,
        LPD3DXBUFFER *ppMaterials,
        LPD3DXBUFFER *ppEffectInstances,
        DWORD *pNumMaterials,
        LPD3DXMESH *ppMesh);

HRESULT __stdcall
    D3DXLoadMeshFromXResource(
        HMODULE Module,
        LPCSTR Name,
        LPCSTR Type,
        DWORD Options,
        LPDIRECT3DDEVICE9 pD3DDevice,
        LPD3DXBUFFER *ppAdjacency,
        LPD3DXBUFFER *ppMaterials,
        LPD3DXBUFFER *ppEffectInstances,
        DWORD *pNumMaterials,
        LPD3DXMESH *ppMesh);
# 2061 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXTessellateNPatches(
        LPD3DXMESH pMeshIn,
        DWORD* pAdjacencyIn,
        float NumSegs,
        BOOL QuadraticInterpNormals,
        LPD3DXMESH *ppMeshOut,
        LPD3DXBUFFER *ppAdjacencyOut);






HRESULT __stdcall
    D3DXGenerateOutputDecl(
        void *pOutput,
        void *pInput);
# 2095 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXRectPatchSize(
        float *pfNumSegs,
        DWORD *pdwTriangles,
        DWORD *pdwVertices);


HRESULT __stdcall
    D3DXTriPatchSize(
        float *pfNumSegs,
        DWORD *pdwTriangles,
        DWORD *pdwVertices);




HRESULT __stdcall
    D3DXTessellateRectPatch(
        LPDIRECT3DVERTEXBUFFER9 pVB,
        float *pNumSegs,
        void *pdwInDecl,
        void *pRectPatchInfo,
        LPD3DXMESH pMesh);


HRESULT __stdcall
    D3DXTessellateTriPatch(
      LPDIRECT3DVERTEXBUFFER9 pVB,
      float *pNumSegs,
      void *pInDecl,
      void *pTriPatchInfo,
      LPD3DXMESH pMesh);
# 2157 "/home/felix/gstudio8/include/d3d9.h"
UINT __stdcall
    D3DXGetFVFVertexSize(DWORD FVF);

UINT __stdcall
    D3DXGetDeclVertexSize( void *pDecl,DWORD Stream);

UINT __stdcall
    D3DXGetDeclLength( void *pDecl);

HRESULT __stdcall
    D3DXDeclaratorFromFVF(
        DWORD FVF,
        void *pDeclarator);

HRESULT __stdcall
    D3DXFVFFromDeclarator(
        void *pDeclarator,
        DWORD *pFVF);
# 2186 "/home/felix/gstudio8/include/d3d9.h"
HRESULT __stdcall
    D3DXIntersect(
        LPD3DXBASEMESH pMesh,
        D3DVECTOR *pRayPos,
        D3DVECTOR *pRayDir,
        BOOL *pHit,
        DWORD *pFaceIndex,
        float *pU,
        float *pV,
        float *pDist,
        LPD3DXBUFFER *ppAllHits,
        DWORD *pCountOfHits);

HRESULT __stdcall
    D3DXIntersectSubset(
        LPD3DXBASEMESH pMesh,
        DWORD AttribId,
        D3DVECTOR *pRayPos,
        D3DVECTOR *pRayDir,
        BOOL *pHit,
        DWORD *pFaceIndex,
        float *pU,
        float *pV,
        float *pDist,
        LPD3DXBUFFER *ppAllHits,
        DWORD *pCountOfHits);


HRESULT __stdcall D3DXSplitMesh
    (
    LPD3DXMESH pMeshIn,
    DWORD *pAdjacencyIn,
    DWORD MaxSize,
    DWORD Options,
    DWORD *pMeshesOut,
    LPD3DXBUFFER *ppMeshArrayOut,
    LPD3DXBUFFER *ppAdjacencyArrayOut,
    LPD3DXBUFFER *ppFaceRemapArrayOut,
    LPD3DXBUFFER *ppVertRemapArrayOut
    );

BOOL __stdcall D3DXIntersectTri
(
    D3DVECTOR *p0,
    D3DVECTOR *p1,
    D3DVECTOR *p2,
    D3DVECTOR *pRayPos,
    D3DVECTOR *pRayDir,
    float *pU,
    float *pV,
    float *pDist);

BOOL __stdcall
    D3DXSphereBoundProbe(
        D3DVECTOR *pCenter,
        float Radius,
        D3DVECTOR *pRayPosition,
        D3DVECTOR *pRayDirection);

BOOL __stdcall
    D3DXBoxBoundProbe(
        D3DVECTOR *pMin,
        D3DVECTOR *pMax,
        D3DVECTOR *pRayPosition,
        D3DVECTOR *pRayDirection);


HRESULT __stdcall D3DXComputeTangentFrame(ID3DXMesh *pMesh,
                                       DWORD dwOptions);

HRESULT __stdcall D3DXComputeTangentFrameEx(ID3DXMesh *pMesh,
                                         DWORD dwTextureInSemantic,
                                         DWORD dwTextureInIndex,
                                         DWORD dwUPartialOutSemantic,
                                         DWORD dwUPartialOutIndex,
                                         DWORD dwVPartialOutSemantic,
                                         DWORD dwVPartialOutIndex,
                                         DWORD dwNormalOutSemantic,
                                         DWORD dwNormalOutIndex,
                                         DWORD dwOptions,
                                         DWORD *pdwAdjacency,
                                         float fPartialEdgeThreshold,
                                         float fSingularPointThreshold,
                                         float fNormalEdgeThreshold,
                                         ID3DXMesh **ppMeshOut,
                                         ID3DXBuffer **ppVertexMapping);


HRESULT __stdcall D3DXComputeTangent(LPD3DXMESH Mesh,
                                 DWORD TexStage,
                                 DWORD TangentIndex,
                                 DWORD BinormIndex,
                                 DWORD Wrap,
                                 DWORD *pAdjacency);
# 2312 "/home/felix/gstudio8/include/d3d9.h"
D3DMATRIX* D3DXMatrixIdentity
    ( D3DMATRIX *pOut )
{
    float* m = (float*)pOut;
    m[0+0] = 1.0; m[0+1] = 0.0; m[0+2] = 0.0; m[0+3] = 0.0;
    m[4+0] = 0.0; m[4+1] = 1.0; m[4+2] = 0.0; m[4+3] = 0.0;
    m[8+0] = 0.0; m[8+1] = 0.0; m[8+2] = 1.0; m[8+3] = 0.0;
    m[12+0] = 0.0; m[12+1] = 0.0; m[12+2] = 0.0; m[12+3] = 1.0;
    return pOut;
}


BOOL D3DXMatrixIsIdentity
    ( D3DMATRIX *pM )
{
    float* m = (float*)pM;
    return
        m[0+0] == 1.0 && m[0+1] == 0.0 && m[0+2] == 0.0 && m[0+3] == 0.0 &&
        m[4+0] == 0.0 && m[4+1] == 1.0 && m[4+2] == 0.0 && m[4+3] == 0.0 &&
        m[8+0] == 0.0 && m[8+1] == 0.0 && m[8+2] == 1.0 && m[8+3] == 0.0 &&
        m[12+0] == 0.0 && m[12+1] == 0.0 && m[12+2] == 0.0 && m[12+3] == 1.0;
}


float __stdcall D3DXMatrixDeterminant
    ( D3DMATRIX *pM );

HRESULT __stdcall D3DXMatrixDecompose
    ( D3DVECTOR *pOutScale, D3DXQUATERNION *pOutRotation,
   D3DVECTOR *pOutTranslation, D3DMATRIX *pM );

D3DMATRIX* __stdcall D3DXMatrixTranspose
    ( D3DMATRIX *pOut, D3DMATRIX *pM );



D3DMATRIX* __stdcall D3DXMatrixMultiply
    ( D3DMATRIX *pOut, D3DMATRIX *pM1, D3DMATRIX *pM2 );


D3DMATRIX* __stdcall D3DXMatrixMultiplyTranspose
    ( D3DMATRIX *pOut, D3DMATRIX *pM1, D3DMATRIX *pM2 );




D3DMATRIX* __stdcall D3DXMatrixInverse
    ( D3DMATRIX *pOut, float *pDeterminant, D3DMATRIX *pM );


D3DMATRIX* __stdcall D3DXMatrixScaling
    ( D3DMATRIX *pOut, float sx, float sy, float sz );


D3DMATRIX* __stdcall D3DXMatrixTranslation
    ( D3DMATRIX *pOut, float x, float y, float z );


D3DMATRIX* __stdcall D3DXMatrixRotationX
    ( D3DMATRIX *pOut, float Angle );


D3DMATRIX* __stdcall D3DXMatrixRotationY
    ( D3DMATRIX *pOut, float Angle );


D3DMATRIX* __stdcall D3DXMatrixRotationZ
    ( D3DMATRIX *pOut, float Angle );


D3DMATRIX* __stdcall D3DXMatrixRotationAxis
    ( D3DMATRIX *pOut, D3DVECTOR *pV, float Angle );


D3DMATRIX* __stdcall D3DXMatrixRotationQuaternion
    ( D3DMATRIX *pOut, D3DXQUATERNION *pQ);



D3DMATRIX* __stdcall D3DXMatrixRotationYawPitchRoll
    ( D3DMATRIX *pOut, float Yaw, float Pitch, float Roll );



D3DMATRIX* __stdcall D3DXMatrixTransformation
    ( D3DMATRIX *pOut, D3DVECTOR *pScalingCenter,
      D3DXQUATERNION *pScalingRotation, D3DVECTOR *pScaling,
      D3DVECTOR *pRotationCenter, D3DXQUATERNION *pRotation,
      D3DVECTOR *pTranslation);



D3DMATRIX* __stdcall D3DXMatrixTransformation2D
    ( D3DMATRIX *pOut, D3DXVECTOR2* pScalingCenter,
      float ScalingRotation, D3DXVECTOR2* pScaling,
      D3DXVECTOR2* pRotationCenter, float Rotation,
      D3DXVECTOR2* pTranslation);



D3DMATRIX* __stdcall D3DXMatrixAffineTransformation
    ( D3DMATRIX *pOut, float Scaling, D3DVECTOR *pRotationCenter,
      D3DXQUATERNION *pRotation, D3DVECTOR *pTranslation);



D3DMATRIX* __stdcall D3DXMatrixAffineTransformation2D
    ( D3DMATRIX *pOut, float Scaling, D3DXVECTOR2* pRotationCenter,
      float Rotation, D3DXVECTOR2* pTranslation);


D3DMATRIX* __stdcall D3DXMatrixLookAtRH
    ( D3DMATRIX *pOut, D3DVECTOR *pEye, D3DVECTOR *pAt,
      D3DVECTOR *pUp );


D3DMATRIX* __stdcall D3DXMatrixLookAtLH
    ( D3DMATRIX *pOut, D3DVECTOR *pEye, D3DVECTOR *pAt,
      D3DVECTOR *pUp );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveRH
    ( D3DMATRIX *pOut, float w, float h, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveLH
    ( D3DMATRIX *pOut, float w, float h, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveFovRH
    ( D3DMATRIX *pOut, float fovy, float Aspect, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveFovLH
    ( D3DMATRIX *pOut, float fovy, float Aspect, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveOffCenterRH
    ( D3DMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );


D3DMATRIX* __stdcall D3DXMatrixPerspectiveOffCenterLH
    ( D3DMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );


D3DMATRIX* __stdcall D3DXMatrixOrthoRH
    ( D3DMATRIX *pOut, float w, float h, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixOrthoLH
    ( D3DMATRIX *pOut, float w, float h, float zn, float zf );


D3DMATRIX* __stdcall D3DXMatrixOrthoOffCenterRH
    ( D3DMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );


D3DMATRIX* __stdcall D3DXMatrixOrthoOffCenterLH
    ( D3DMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf );



D3DMATRIX* __stdcall D3DXMatrixShadow
    ( D3DMATRIX *pOut, D3DXVECTOR4 *pLight,
      D3DXPLANE *pPlane );


D3DMATRIX* __stdcall D3DXMatrixReflect
    ( D3DMATRIX *pOut, D3DXPLANE *pPlane );
# 2525 "/home/felix/gstudio8/include/d3d9.h"
D3DXPLANE* __stdcall D3DXPlaneNormalize
    ( D3DXPLANE *pOut, D3DXPLANE *pP);



D3DVECTOR* __stdcall D3DXPlaneIntersectLine
    ( D3DVECTOR *pOut, D3DXPLANE *pP, D3DVECTOR *pV1,
      D3DVECTOR *pV2);


D3DXPLANE* __stdcall D3DXPlaneFromPointNormal
    ( D3DXPLANE *pOut, D3DVECTOR *pPoint, D3DVECTOR *pNormal);


D3DXPLANE* __stdcall D3DXPlaneFromPoints
    ( D3DXPLANE *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2,
      D3DVECTOR *pV3);



D3DXPLANE* __stdcall D3DXPlaneTransform
    ( D3DXPLANE *pOut, D3DXPLANE *pP, D3DMATRIX *pM );



D3DXPLANE* __stdcall D3DXPlaneTransformArray
    ( D3DXPLANE *pOut, UINT OutStride, D3DXPLANE *pP, UINT PStride, D3DMATRIX *pM, UINT n );
# 2623 "/home/felix/gstudio8/include/d3d9.h"
void __stdcall D3DXQuaternionToAxisAngle
    ( D3DXQUATERNION *pQ, D3DVECTOR *pAxis, float *pAngle );


D3DXQUATERNION* __stdcall D3DXQuaternionRotationMatrix
    ( D3DXQUATERNION *pOut, D3DMATRIX *pM);


D3DXQUATERNION* __stdcall D3DXQuaternionRotationAxis
    ( D3DXQUATERNION *pOut, D3DVECTOR *pV, float Angle );



D3DXQUATERNION* __stdcall D3DXQuaternionRotationYawPitchRoll
    ( D3DXQUATERNION *pOut, float Yaw, float Pitch, float Roll );



D3DXQUATERNION* __stdcall D3DXQuaternionMultiply
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ1,
      D3DXQUATERNION *pQ2 );

D3DXQUATERNION* __stdcall D3DXQuaternionNormalize
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ );


D3DXQUATERNION* __stdcall D3DXQuaternionInverse
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ );



D3DXQUATERNION* __stdcall D3DXQuaternionLn
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ );



D3DXQUATERNION* __stdcall D3DXQuaternionExp
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ );



D3DXQUATERNION* __stdcall D3DXQuaternionSlerp
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ1,
      D3DXQUATERNION *pQ2, float t );



D3DXQUATERNION* __stdcall D3DXQuaternionSquad
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ1,
      D3DXQUATERNION *pA, D3DXQUATERNION *pB,
      D3DXQUATERNION *pC, float t );




void __stdcall D3DXQuaternionSquadSetup
    ( D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut,
      D3DXQUATERNION *pQ0, D3DXQUATERNION *pQ1,
      D3DXQUATERNION *pQ2, D3DXQUATERNION *pQ3 );



D3DXQUATERNION* __stdcall D3DXQuaternionBaryCentric
    ( D3DXQUATERNION *pOut, D3DXQUATERNION *pQ1,
      D3DXQUATERNION *pQ2, D3DXQUATERNION *pQ3,
      float f, float g );
# 2749 "/home/felix/gstudio8/include/d3d9.h"
D3DXVECTOR2* __stdcall D3DXVec2Normalize
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV );



D3DXVECTOR2* __stdcall D3DXVec2Hermite
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV1, D3DXVECTOR2 *pT1,
      D3DXVECTOR2 *pV2, D3DXVECTOR2 *pT2, float s );


D3DXVECTOR2* __stdcall D3DXVec2CatmullRom
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV0, D3DXVECTOR2 *pV1,
      D3DXVECTOR2 *pV2, D3DXVECTOR2 *pV3, float s );


D3DXVECTOR2* __stdcall D3DXVec2BaryCentric
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV1, D3DXVECTOR2 *pV2,
      D3DXVECTOR2 *pV3, float f, float g);


D3DXVECTOR4* __stdcall D3DXVec2Transform
    ( D3DXVECTOR4 *pOut, D3DXVECTOR2 *pV, D3DMATRIX *pM );


D3DXVECTOR2* __stdcall D3DXVec2TransformCoord
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV, D3DMATRIX *pM );


D3DXVECTOR2* __stdcall D3DXVec2TransformNormal
    ( D3DXVECTOR2 *pOut, D3DXVECTOR2 *pV, D3DMATRIX *pM );


D3DXVECTOR4* __stdcall D3DXVec2TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, D3DXVECTOR2 *pV, UINT VStride, D3DMATRIX *pM, UINT n);


D3DXVECTOR2* __stdcall D3DXVec2TransformCoordArray
    ( D3DXVECTOR2 *pOut, UINT OutStride, D3DXVECTOR2 *pV, UINT VStride, D3DMATRIX *pM, UINT n );


D3DXVECTOR2* __stdcall D3DXVec2TransformNormalArray
    ( D3DXVECTOR2 *pOut, UINT OutStride, D3DXVECTOR2 *pV, UINT VStride, D3DMATRIX *pM, UINT n );
# 2807 "/home/felix/gstudio8/include/d3d9.h"
float D3DXVec3Length
    ( D3DVECTOR *pV )
{
    return (float) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
}

float D3DXVec3LengthSq
    ( D3DVECTOR *pV )
{
    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
}

float D3DXVec3Dot
    ( D3DVECTOR *pV1, D3DVECTOR *pV2 )
{
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

D3DVECTOR* D3DXVec3Cross
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2 )
{
    D3DVECTOR v;
    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

    memcpy(pOut,&v,((int)_sizeof(D3DVECTOR)));
    return pOut;
}

D3DVECTOR* D3DXVec3Add
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2 )
{
    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    return pOut;
}

D3DVECTOR* D3DXVec3Subtract
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2 )
{
    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    return pOut;
}
# 2873 "/home/felix/gstudio8/include/d3d9.h"
D3DVECTOR* D3DXVec3Scale
    ( D3DVECTOR *pOut, D3DVECTOR *pV, float s)
{
    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    return pOut;
}

D3DVECTOR* D3DXVec3Lerp
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2,
      float s )
{
    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    return pOut;
}



D3DVECTOR* D3DXVec3Set(D3DVECTOR *pOut, D3DVECTOR *pIn)
{
    pOut->x = pIn->x;
    pOut->y = pIn->y;
    pOut->z = pIn->z;
    return pOut;
}

D3DVECTOR* D3DXVec3Set(D3DVECTOR *pOut, D3DXVECTOR4 *pIn)
{
    pOut->x = pIn->x;
    pOut->y = pIn->y;
    pOut->z = pIn->z;
    return pOut;
}

D3DVECTOR* D3DXVec3Set(D3DVECTOR *pOut,float x,float y,float z)
{
    pOut->x = x;
    pOut->y = y;
    pOut->z = z;
    return pOut;
}



D3DVECTOR* __stdcall D3DXVec3Normalize
    ( D3DVECTOR *pOut, D3DVECTOR *pV );



D3DVECTOR* __stdcall D3DXVec3Hermite
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pT1,
      D3DVECTOR *pV2, D3DVECTOR *pT2, float s );


D3DVECTOR* __stdcall D3DXVec3CatmullRom
    ( D3DVECTOR *pOut, D3DVECTOR *pV0, D3DVECTOR *pV1,
      D3DVECTOR *pV2, D3DVECTOR *pV3, float s );


D3DVECTOR* __stdcall D3DXVec3BaryCentric
    ( D3DVECTOR *pOut, D3DVECTOR *pV1, D3DVECTOR *pV2,
      D3DVECTOR *pV3, float f, float g);


D3DXVECTOR4* __stdcall D3DXVec3Transform
    ( D3DXVECTOR4 *pOut, D3DVECTOR *pV, D3DMATRIX *pM );


D3DVECTOR* __stdcall D3DXVec3TransformCoord
    ( D3DVECTOR *pOut, D3DVECTOR *pV, D3DMATRIX *pM );




D3DVECTOR* __stdcall D3DXVec3TransformNormal
    ( D3DVECTOR *pOut, D3DVECTOR *pV, D3DMATRIX *pM );


D3DXVECTOR4* __stdcall D3DXVec3TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, D3DVECTOR *pV, UINT VStride, D3DMATRIX *pM, UINT n );


D3DVECTOR* __stdcall D3DXVec3TransformCoordArray
    ( D3DVECTOR *pOut, UINT OutStride, D3DVECTOR *pV, UINT VStride, D3DMATRIX *pM, UINT n );




D3DVECTOR* __stdcall D3DXVec3TransformNormalArray
    ( D3DVECTOR *pOut, UINT OutStride, D3DVECTOR *pV, UINT VStride, D3DMATRIX *pM, UINT n );


D3DVECTOR* __stdcall D3DXVec3Project
    ( D3DVECTOR *pOut, D3DVECTOR *pV, D3DVIEWPORT9 *pViewport,
      D3DMATRIX *pProjection, D3DMATRIX *pView, D3DMATRIX *pWorld);


D3DVECTOR* __stdcall D3DXVec3Unproject
    ( D3DVECTOR *pOut, D3DVECTOR *pV, D3DVIEWPORT9 *pViewport,
      D3DMATRIX *pProjection, D3DMATRIX *pView, D3DMATRIX *pWorld);


D3DVECTOR* __stdcall D3DXVec3ProjectArray
    ( D3DVECTOR *pOut, UINT OutStride, D3DVECTOR *pV, UINT VStride, D3DVIEWPORT9 *pViewport,
      D3DMATRIX *pProjection, D3DMATRIX *pView, D3DMATRIX *pWorld, UINT n);


D3DVECTOR* __stdcall D3DXVec3UnprojectArray
    ( D3DVECTOR *pOut, UINT OutStride, D3DVECTOR *pV, UINT VStride, D3DVIEWPORT9 *pViewport,
      D3DMATRIX *pProjection, D3DMATRIX *pView, D3DMATRIX *pWorld, UINT n);
# 3004 "/home/felix/gstudio8/include/d3d9.h"
float D3DXVec4Length
    ( D3DXVECTOR4 *pV )
{
    return (float) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
}

float D3DXVec4LengthSq
    ( D3DXVECTOR4 *pV )
{
    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w;
}

float D3DXVec4Dot
    ( D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2 )
{
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
}

D3DXVECTOR4* D3DXVec4Add
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2)
{
    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    pOut->w = pV1->w + pV2->w;
    return pOut;
}

D3DXVECTOR4* D3DXVec4Subtract
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2)
{
    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    pOut->w = pV1->w - pV2->w;
    return pOut;
}
# 3062 "/home/felix/gstudio8/include/d3d9.h"
D3DXVECTOR4* D3DXVec4Scale
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV, float s)
{
    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    pOut->w = pV->w * s;
    return pOut;
}

D3DXVECTOR4* D3DXVec4Lerp
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2,
      float s )
{
    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    pOut->w = pV1->w + s * (pV2->w - pV1->w);
    return pOut;
}


D3DXVECTOR4* D3DXVec4Set(D3DXVECTOR4 *pOut, D3DVECTOR *pIn)
{
    pOut->x = pIn->x;
    pOut->y = pIn->y;
    pOut->z = pIn->z;
    pOut->w = 1.0;
    return pOut;
}

D3DXVECTOR4* D3DXVec4Set(D3DXVECTOR4 *pOut, D3DXVECTOR4 *pIn)
{
    pOut->x = pIn->x;
    pOut->y = pIn->y;
    pOut->z = pIn->z;
    pOut->w = pIn->w;
    return pOut;
}

D3DXVECTOR4* D3DXVec4Set(D3DXVECTOR4 *pOut,float x,float y,float z,float w)
{
    pOut->x = x;
    pOut->y = y;
    pOut->z = z;
    pOut->w = w;
    return pOut;
}


D3DXVECTOR4* __stdcall D3DXVec4Cross
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2,
      D3DXVECTOR4 *pV3);

D3DXVECTOR4* __stdcall D3DXVec4Normalize
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV );



D3DXVECTOR4* __stdcall D3DXVec4Hermite
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pT1,
      D3DXVECTOR4 *pV2, D3DXVECTOR4 *pT2, float s );


D3DXVECTOR4* __stdcall D3DXVec4CatmullRom
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV0, D3DXVECTOR4 *pV1,
      D3DXVECTOR4 *pV2, D3DXVECTOR4 *pV3, float s );


D3DXVECTOR4* __stdcall D3DXVec4BaryCentric
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV1, D3DXVECTOR4 *pV2,
      D3DXVECTOR4 *pV3, float f, float g);


D3DXVECTOR4* __stdcall D3DXVec4Transform
    ( D3DXVECTOR4 *pOut, D3DXVECTOR4 *pV, D3DMATRIX *pM );


D3DXVECTOR4* __stdcall D3DXVec4TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, D3DXVECTOR4 *pV, UINT VStride, D3DMATRIX *pM, UINT n );
# 6 "src/map_loader.c" 2
# 1 "/home/felix/gstudio8/include/stdio.h" 1
# 9 "/home/felix/gstudio8/include/stdio.h"
typedef char* va_list;
typedef long fpos_t;
typedef long size_t;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};
typedef struct _iobuf FILE;
# 32 "/home/felix/gstudio8/include/stdio.h"
FILE _iob[3];
# 55 "/home/felix/gstudio8/include/stdio.h"
FILE * __cdecl _fsopen(const char *, const char *, int);
void __cdecl clearerr(FILE *);

int __cdecl fclose(FILE *);
int __cdecl _fcloseall(void);

FILE * __cdecl _fdopen(int, const char *);

int __cdecl feof(FILE *);
int __cdecl ferror(FILE *);
int __cdecl fflush(FILE *);
int __cdecl fgetc(FILE *);
int __cdecl _fgetchar(void);
int __cdecl fgetpos(FILE *, fpos_t *);
char * __cdecl fgets(char *, int, FILE *);

int __cdecl _fileno(FILE *);
int __cdecl _flushall(void);

FILE * __cdecl fopen(const char *, const char *);
int __cdecl fprintf(FILE *, const char *, ...);
int __cdecl fputc(int, FILE *);
int __cdecl _fputchar(int);
int __cdecl fputs(const char *, FILE *);
size_t __cdecl fread(void *, size_t, size_t, FILE *);
FILE * __cdecl freopen(const char *, const char *, FILE *);
int __cdecl fscanf(FILE *, const char *, ...);
int __cdecl fsetpos(FILE *, const fpos_t *);
int __cdecl fseek(FILE *, long, int);
long __cdecl ftell(FILE *);
size_t __cdecl fwrite(const void *, size_t, size_t, FILE *);
int __cdecl getc(FILE *);
int __cdecl getchar(void);
int __cdecl _getmaxstdio(void);
char * __cdecl gets(char *);
int __cdecl _getw(FILE *);
void __cdecl perror(const char *);
int __cdecl _pclose(FILE *);
FILE * __cdecl _popen(const char *, const char *);
int __cdecl printf(const char *, ...);
int __cdecl putc(int, FILE *);
int __cdecl putchar(int);
int __cdecl puts(const char *);
int __cdecl _putw(int, FILE *);
int __cdecl remove(const char *);
int __cdecl rename(const char *, const char *);
void __cdecl rewind(FILE *);
int __cdecl _rmtmp(void);
int __cdecl scanf(const char *, ...);
void __cdecl setbuf(FILE *, char *);
int __cdecl _setmaxstdio(int);
int __cdecl setvbuf(FILE *, char *, int, size_t);
int __cdecl _snprintf(char *, size_t, const char *, ...);
int __cdecl sprintf(char *, const char *, ...);
int __cdecl _scprintf(const char *, ...);
int __cdecl sscanf(const char *, const char *, ...);
int __cdecl _snscanf(const char *, size_t, const char *, ...);
char * __cdecl _tempnam(const char *, const char *);
FILE * __cdecl tmpfile(void);
char * __cdecl tmpnam(char *);
int __cdecl ungetc(int, FILE *);
int __cdecl _unlink(const char *);
int __cdecl vfprintf(FILE *, const char *, va_list);
int __cdecl vprintf(const char *, va_list);
int __cdecl _vsnprintf(char *, size_t, const char *, va_list);
int __cdecl vsprintf(char *, const char *, va_list);
int __cdecl _vscprintf(const char *, va_list);
# 132 "/home/felix/gstudio8/include/stdio.h"
typedef long time_t;
typedef long intptr_t;
typedef long _fsize_t;

typedef struct _finddata_t {
     long attrib;
     time_t time_create;
     time_t time_access;
     time_t time_write;
     _fsize_t size;
     char name[260];
} _finddata_t;
# 156 "/home/felix/gstudio8/include/stdio.h"
int __cdecl _access(const char *, int);
int __cdecl _chmod(const char *, int);
int __cdecl _chsize(int, long);
int __cdecl _close(int);
int __cdecl _commit(int);
int __cdecl _creat(const char *, int);
int __cdecl _dup(int);
int __cdecl _dup2(int, int);
int __cdecl _eof(int);
long __cdecl _filelength(int);
intptr_t __cdecl _findfirst(const char *, _finddata_t *);
int __cdecl _findnext(intptr_t, _finddata_t *);
int __cdecl _findclose(intptr_t);
int __cdecl _isatty(int);
int __cdecl _locking(int, int, long);
long __cdecl _lseek(int, long, int);
char * __cdecl _mktemp(char *);
int __cdecl _open(const char *, int, ...);
int __cdecl _pipe(int *, unsigned int, int);
int __cdecl _read(int, void *, unsigned int);
int __cdecl remove(const char *);
int __cdecl rename(const char *, const char *);
int __cdecl _setmode(int, int);
int __cdecl _sopen(const char *, int, int, ...);
long __cdecl _tell(int);
int __cdecl _umask(int);
int __cdecl _unlink(const char *);
int __cdecl _write(int, const void *, unsigned int);



typedef struct _diskfree_t {
    long total_clusters;
    long avail_clusters;
    long sectors_per_cluster;
    long bytes_per_sector;
} _diskfree_t;



int __cdecl _chdir(const char *);
char * __cdecl _getcwd(char *, int);
int __cdecl _mkdir(const char *);
int __cdecl _rmdir(const char *);

int __cdecl _chdrive(int);
char * __cdecl _getdcwd(int, char *, int);
int __cdecl _getdrive(void);
long __cdecl _getdrives(void);
long __cdecl _getdiskfree(long, _diskfree_t *);



API(_fsopen,msvcrt)
API(clearerr,msvcrt)
API(fclose,msvcrt)
API(_fcloseall,msvcrt)
API(_fdopen,msvcrt)
API(feof,msvcrt)
API(ferror,msvcrt)
API(fflush,msvcrt)
API(fgetc,msvcrt)
API(_fgetchar,msvcrt)
API(fgetpos,msvcrt)
API(fgets,msvcrt)
API(_fileno,msvcrt)
API(_flushall,msvcrt)
API(fopen,msvcrt)
API(fprintf,msvcrt)
API(fputc,msvcrt)
API(_fputchar,msvcrt)
API(fputs,msvcrt)
API(fread,msvcrt)
API(freopen,msvcrt)
API(fscanf,msvcrt)
API(fsetpos,msvcrt)
API(fseek,msvcrt)
API(ftell,msvcrt)
API(fwrite,msvcrt)
API(getc,msvcrt)
API(getchar,msvcrt)
API(_getmaxstdio,msvcrt)
API(gets,msvcrt)
API(_getw,msvcrt)
API(perror,msvcrt)
API(_pclose,msvcrt)
API(_popen,msvcrt)
API(printf,msvcrt)
API(putc,msvcrt)
API(putchar,msvcrt)
API(puts,msvcrt)
API(_putw,msvcrt)
API(remove,msvcrt)
API(rename,msvcrt)
API(rewind,msvcrt)
API(_rmtmp,msvcrt)
API(scanf,msvcrt)
API(setbuf,msvcrt)
API(_setmaxstdio,msvcrt)
API(setvbuf,msvcrt)
API(_snprintf,msvcrt)
API(sprintf,msvcrt)
API(_scprintf,msvcrt)
API(sscanf,msvcrt)
API(_snscanf,msvcrt)
API(_tempnam,msvcrt)
API(tmpfile,msvcrt)
API(tmpnam,msvcrt)
API(ungetc,msvcrt)
API(_unlink,msvcrt)
API(vfprintf,msvcrt)
API(vprintf,msvcrt)
API(_vsnprintf,msvcrt)
API(vsprintf,msvcrt)
API(_vscprintf,msvcrt)

API(_access,msvcrt)
API(_chmod,msvcrt)
API(_chsize,msvcrt)
API(_close,msvcrt)
API(_commit,msvcrt)
API(_creat,msvcrt)
API(_dup,msvcrt)
API(_dup2,msvcrt)
API(_eof,msvcrt)
API(_filelength,msvcrt)
API(_findfirst,msvcrt)
API(_findnext,msvcrt)
API(_findclose,msvcrt)
API(_isatty,msvcrt)
API(_locking,msvcrt)
API(_lseek,msvcrt)
API(_mktemp,msvcrt)
API(_open,msvcrt)
API(_pipe,msvcrt)
API(_read,msvcrt)
API(remove,msvcrt)
API(rename,msvcrt)
API(_setmode,msvcrt)
API(_sopen,msvcrt)
API(_tell,msvcrt)
API(_umask,msvcrt)
API(_unlink,msvcrt)
API(_write,msvcrt)

API(_chdir,msvcrt)
API(_getcwd,msvcrt)
API(_mkdir,msvcrt)
API(_rmdir,msvcrt)
API(_chdrive,msvcrt)
API(_getdcwd,msvcrt)
API(_getdrive,msvcrt)
API(_getdrives,msvcrt)
API(_getdiskfree,msvcrt)
# 7 "src/map_loader.c" 2

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
    effect = "terrain.fx";
    flags = (1<<11) | (1<<24);
}

MATERIAL * maploader_water_material =
{
    effect = "water.fx";
    flags = (1<<11) | (1<<24);
}


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
    maploader.cells = 0;
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
  return 4;
 if(gray < 0x30)
  return 5;
 else if(gray <= 0x60)
  return 2;
 else if(gray <= 0xA0)
  return 3;
 else if(gray <= 0xE0)
  return 1;
 else
  return 0;
}

void maploader_load(char const * fileName)
{
 if(maploader.cells) {
  sys_free(maploader.cells);
 }
 BMAP * bmp = bmap_create(fileName);
 if(bmp == 0)
  error("failed to load level");
    bmap_to_mipmap(bmp);
 var format = bmap_lock(bmp, 0);

 maploader.w = bmap_width(bmp);
 maploader.h = bmap_height(bmp);
 maploader.cells = sys_malloc(((int)_sizeof(maploader_cell)) * maploader.w * maploader.h);

 int x, y;
 for(x = 0; x < maploader.w; x++)
 {
  for(y = 0; y < maploader.h; y++)
  {
   var pixel = pixel_for_bmap(bmp, x, y);

   COLOR col;
   var alpha;
   pixel_to_vec(&col, &alpha, format, pixel);
# 138 "src/map_loader.c"
            int type;
            if(col.blue >= 250)
                type = 4;
            else
                type = 0;

   ((maploader.cells)[maploader.w * y + x]).celltype = type;
   ((maploader.cells)[maploader.w * y + x]).vegetation = col.green / 255.0;
            ((maploader.cells)[maploader.w * y + x]).elevation = col.blue * 3;
            ((maploader.cells)[maploader.w * y + x]).zettiness = 1.0 - alpha / 100.0;
            ((maploader.cells)[maploader.w * y + x]).streetyness = col.red / 255.0;
  }
 }

 bmap_unlock(bmp);


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


        }
        mesh->UnlockVertexBuffer();
    }

    maploader.terrain->flags |= ((1<<9));

    maploader.terrain.material = maploader_terrain_material;

    random_seed(1337);
    for(x = 0; x < maploader.w; x++)
    {
        for(y = 0; y < maploader.h; y++)
        {
            int type = maploader_tile_type(x, y);
            float v = maploader_tile_vegetation(x, y);
            float s = maploader_tile_streetyness(x, y);
            if(type != 0)
                continue;
            VECTOR pos;
            maploader_pos_to_vec(pos, x, y);

            pos.x += (maploader_cellsize * maploader_trisize) * (random(1) - 0.5);
            pos.y += (maploader_cellsize * maploader_trisize) * (random(1) - 0.5);

            if(v < 0.1 && s < 0.2 && random(100) < 3)
            {
                you = ent_create("kabel4.mdl", pos, 0);
                you->pan = random(360);
            }
            else if(v < 0.1 && s < 0.1 && random(100) < 0.5)
            {
                you = ent_create("KisteA.mdl", pos, 0);
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

                        you = ent_create(boom, pos, 0);
                        you->flags &= ~((1<<18));
                        you->material = matTrees;
                        you->red = 100;
                        you->green = 100;
                        you->blue = 100;
                        you->pan = random(360);
                        you->tilt = random(30) - 15;

                    }
                }
            }
        }
    }
    maploader.terrain.clipfactor = 2;
# 296 "src/map_loader.c"
    collision_mode = 1;

    for(x = 0; x < maploader.w; x++)
    {
        for(y = 0; y < maploader.h; y++)
        {
            int type = maploader_tile_type(x, y);
            if(type != 0)
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
 return (maploader.cells != 0);
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

int maploader_get_type(VECTOR * v)
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

    return 0;
}
# 42 "main.c" 2
# 1 "src/sputnik.c" 1



# 1 "src/scan.h" 1



bool SCAN_invisibility = 0;

var SCAN_IsCameraNear(ENTITY* ent);
var SCAN_IsEntityNear(ENTITY* ent, ENTITY* targetEnt, var distance);
var SCAN_IsTargetNear(ENTITY* ent, VECTOR* pos, var distance);
# 5 "src/sputnik.c" 2
# 1 "src/ang.h" 1



var ANG_turnToPos(ENTITY* ptr, VECTOR* pos, var speed, var hysteresis);
var ANG_turnToAngle(ENTITY* ptr, var angle, var speed, var hysteresis);
# 6 "src/sputnik.c" 2
# 30 "src/sputnik.c"
SOUND* sputnik_snd_death = "sputnik_death.wav";
SOUND* sputnik_snd_attack1 = "sputnik_attack1.wav";
SOUND* sputnik_snd_attack2 = "sputnik_attack2.wav";
SOUND* sputnik_snd_attack3 = "sputnik_attack3.wav";


void Sputnik()
{
 framework_setup(my, 100);
 my->skill[0] = 30;
 my->skill[1] = 50;
 my->skill[2] = 5;
 my->skill[3] = 200;
 my->skill[21] = 0;
 my->skill[27] = 0;
 my->skill[52] = 23;
 my->skill[51] = my->skill[52];
    my->flags &= ~((1<<18));
 c_setminmax(me);
 my->min_z += 30;
 my->skill[54] = 1;
 my->skill[57] = 5;
}

void SPUTNIK_Init()
{
}


void SPUTNIK__wait_or_walk(ENTITY * ptr)
{
 UNIT* unit = jpsAllowMovementForEntity(ptr, 1);
 if(!unit) return;

 vec_set(ptr->x, unit->pos3d);
 VECTOR diff, temp;
 vec_diff(diff, unit->pos3d, unit->prevPos3d);

 var len = vec_to_angle(temp, diff)/time_step;

 if(len > 8) ptr->skill[26] = 4;


 if(ptr->skill[26] > 0)
 {
  ptr->skill[26] = maxv(ptr->skill[26]-time_step,0);
  if(len > 8) ptr->pan += ang(temp.x-ptr->pan)*0.5*time_step;

  ptr->skill[25] = 0;
  ptr->skill[21] = 0;
  ptr->skill[20] += len*0.425*time_step;
  ent_animate(ptr, "walk", ptr->skill[20], (1<<0));

  ptr->skill[27] = 0;
 }
 else
 {
  ptr->skill[27] += time_step;
  ptr->skill[20] += 7 * time_step;
  ent_animate(ptr, "stand", ptr->skill[20], (1<<0));
 }


 if (ptr->skill[50] > 0)
 {
  if (ptr->skill[54] != 6)
  {
   ptr->skill[52] = maxv(0, ptr->skill[52] - ptr->skill[50]);
   ptr->skill[54] = 6;
   ptr->skill[58] = 5;
  }
  ptr->skill[50] = 0;
 }
 else
 {

  if (SCAN_IsEntityNear(ptr, unit_getVictim(ptr), ptr->skill[3]))
  {
   ptr->skill[54] = 3;
  }

  if(ptr->skill[27] > 32 && !unit_getVictim(ptr))
  {
   unit_findNextVictim(ptr, 4);
  }


  if (unit_getVictim(ptr) == 0 && ptr->skill[60] != -1)
  {
   if (!unit_findNextVictim(ptr))
   {

    ptr->skill[60] = -1;
   }
  }

 }
}


void SPUTNIK_Update()
{
 ENTITY * ptr;
 for(ptr = ent_next(0); ptr != 0; ptr = ent_next(ptr)) if(ptr->skill[98] == (100))
 {
  if(ptr->skill[54] != 1)
   ptr->skill[27] = 0;

  jpsAllowMovementForEntity(ptr, 0);

  switch(ptr->skill[54])
  {
   case 1:
   {
    SPUTNIK__wait_or_walk(ptr);
    break;
   }

   case 3:
   {
    SPUTNIK__attack(ptr);
    break;
   }

   case 4:
   {
    SPUTNIK__die(ptr);
    break;
   }

   case 6:
   {
    SPUTNIK__hit(ptr);
    break;
   }

   default:
   {
    break;
   }
  }

  if (ptr->skill[54] != 4 && ptr->skill[54] != 5)
  {
   UNIT* unit = ((UNIT*)ptr->skill[96]);
   if(unit)
   {
    TILE* tile = unit->tile;
    if(tile)
    {
                    if(!tile->value) ptr->z = maploader_get_height(ptr->x) - ptr->min_z - 30;
    }
   }
  }
 }
}

void SPUTNIK__hit(ENTITY* ptr)
{
 ptr->skill[58] -= time_step;
 if (ptr->skill[52] <= 0)
 {
  ptr->skill[54] = 4;
  ptr->skill[20] = 0;
  snd_play(sputnik_snd_death, 100, 0);
  ptr->flags |= ((1<<9));
  unit_deactivate(ptr);
 }
 else if (ptr->skill[58] <= 0)
 {
  ptr->skill[54] = 1;
 }
 else
 {
  var percent = (1 - (ptr->skill[58]/5)) * 56;
  if (percent > 28)
  percent = 56-percent;
  ent_animate(ptr, "AttackA", percent, 0);
 }
}

void SPUTNIK__attack(ENTITY* ptr)
{
 ANG_turnToPos(ptr, unit_getTarget(ptr), ptr->skill[1], 5);
 if (ptr->skill[21] == 0)
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
 ptr->skill[21] += ptr->skill[2] * time_step;
 ptr->skill[21] = minv(ptr->skill[21], 100);
 ptr->skill[20] = 0;
 ent_animate(ptr, "AttackA", ptr->skill[21], 0);

 if (ptr->skill[21] > 50)
 {
  if (ptr->skill[25] == 0)
  {
   ENTITY* victim = unit_getVictim(ptr);
   if (SCAN_IsEntityNear(ptr, victim, ptr->skill[3]))
   {

    if (victim == ptr) error ("attacking myself :O");
    unit_setDamage(victim, ptr);
   }
  }
  ptr->skill[25] = 1;
 }
 else
 {
  ptr->skill[25] = 0;
 }

 if (ptr->skill[21] >= 100)
 {

  ptr->skill[21] = 0;
  ptr->skill[54] = 1;
 }

}

void SPUTNIK__die(ENTITY* ptr)
{
 ptr->skill[20] += 5 * time_step;
 ent_animate(ptr, "Die", ptr->skill[20], 0);

 if(ptr->skill[20] >= 90)
 {
  ptr->skill[54] = 5;
 }
}
# 43 "main.c" 2
# 1 "/home/felix/gstudio8/include/camera.c" 1
# 10 "/home/felix/gstudio8/include/camera.c"
# 1 "/home/felix/gstudio8/include/keys.c" 1
# 9 "/home/felix/gstudio8/include/keys.c"
function button_pressed(var buttons,var num)
{
 if (num <= 0 || num > 32)
  return 0;
 else if (num <= 10)
  return (buttons<<10) & (1 << num-1);
 else
  return buttons & (1 << num-11);
}




function joy_pressed(var num)
{
 return button_pressed(joy_buttons,num);
}


function joy2_pressed(var num)
{
 return button_pressed(joy2_buttons,num);
}


function joy_hit(var num)
{
 static var last_buttons = 0;
 var jhit = 0;
 if(!button_pressed(last_buttons,num)
  && button_pressed(joy_buttons,num))
  jhit = 1;
 last_buttons = joy_buttons;
 return jhit;
}

byte _keys_down[256];


function key_hit(var num)
{
 if (num <= 0 || num >= 256) return 0;
 if(!_keys_down[num] && key_pressed(num))
 {
  _keys_down[num] = 1;
  return 1;
 }
 _keys_down[num] = key_pressed(num);
 return 0;
}


function key_hit(STRING* keystr)
{
 return key_hit(key_for_str(keystr));
}





function mouse_drag()
{
   VECTOR click_pos,new_pos;
   vec_set(click_pos,mouse_cursor);

   while (mouse_left) {
      vec_diff(new_pos,mouse_cursor,click_pos);
      vec_add(new_pos,window_pos);
      video_window(new_pos,0,0,0);
      _ich_bin_verboten_(1);
   }
}
# 11 "/home/felix/gstudio8/include/camera.c" 2

var tcamera_mode = 1;
var tcamera_dist = 250;
var tcamera_height = 50;
var tcamera_minDist = 100;
var tcamera_maxDist = 2000;
var tcamera_zoomDist = 2;


var tcamera_pos_x = 0;
var tcamera_pos_y = 0;


var tcamera_offset_x = 0;
var tcamera_offset_y = 10;
var tcamera_offset_z = 20;



STRING* key_togglecamera = "c";
STRING* key_camera1 = "f1";
STRING* key_camera2 = "f2";
STRING* key_camera3 = "f3";
STRING* key_camera4 = "f4";
STRING* key_camera5 = "f5";
STRING* key_camera6 = "f6";

var joy_togglecamera = 4;




function camera_face(ENTITY* ent,var height)
{
 if (!ent) return;

 camera.z = ent.z + height;

 vec_to_angle(camera.pan,vec_diff(0,ent.x,camera.x));
}


function camera_offset(ENTITY* ent,VECTOR* offset)
{
 if (!ent) return;
 vec_set(camera.x,offset);
 vec_add(camera.x,ent.x);
 camera_face(ent,offset.z);
}


function camera_orbit(ENTITY* ent,var angle,var dist,var height)
{
 if (!ent) return;

 vec_set(camera.x,vector(dist,0,0));
 vec_rotate(camera.x,vector(ent.pan+180+angle,0,0));
 vec_add(camera.x,ent.x);
 camera_face(ent,height);
}


function camera_chase(ENTITY* ent,var dist,var height)
{
 if (!ent) return;

 VECTOR vLine;
 vec_diff(vLine,ent.x,camera.x);
 vec_normalize(vLine,dist);
 vec_set(camera.x,vec_diff(0,ent.x,vLine));
 camera_face(ent,height);
}


function camera_person(ENTITY* ent,VECTOR* offset,var factor)
{
 if (!ent) return;
 vec_set(camera.x,offset);
 vec_rotate(camera.x,ent.pan);
 vec_add(camera.x,ent.x);
 vec_set(camera.pan,vector(ent.pan,ent.tilt*factor,ent.roll*factor));
 if (camera.z < ent.z) {
  camera.tilt = 0;
  camera.z = ent.z;
 }
}

function camera_startup()
{
 while(!player) _ich_bin_verboten_(1);
 if (!tcamera_mode) return;

 while(tcamera_mode)
 {
  if(key_hit(key_togglecamera) || joy_hit(joy_togglecamera))
   tcamera_mode = (tcamera_mode % 6)+1;
  else if(key_hit(key_camera1))
   tcamera_mode = 1;
  else if(key_hit(key_camera2))
   tcamera_mode = 2;
  else if(key_hit(key_camera3))
   tcamera_mode = 3;
  else if(key_hit(key_camera4))
   tcamera_mode = 4;
  else if(key_hit(key_camera5))
   tcamera_mode = 5;
  else if(key_hit(key_camera6))
   tcamera_mode = 6;

  tcamera_dist -= tcamera_zoomDist * time_step * mickey.z;
  tcamera_dist = clamp(tcamera_dist,tcamera_minDist,tcamera_maxDist);
  camera.genius = 0;

  switch(tcamera_mode)
  {
   case 1:
    camera_chase(player,tcamera_dist,tcamera_height); break;
   case 2:
    camera_orbit(player,0,tcamera_dist,tcamera_height); break;
   case 3:
    vec_set(camera.x,vector(tcamera_pos_x,tcamera_pos_y,0));
    camera_face(player,tcamera_dist); break;
   case 4:
    camera_offset(player,vector(tcamera_dist,tcamera_dist,tcamera_height)); break;
   case 5:
    camera.genius = player;
    camera_person(player,
     vector(tcamera_offset_x,tcamera_offset_y,tcamera_offset_z),0.5);
    break;
   case 6:
    camera_person(player,
     vector(-tcamera_dist,tcamera_offset_y,tcamera_height),0.8);
    break;
  }
  _ich_bin_verboten_(1);
 }
}
# 44 "main.c" 2
# 1 "src/UnitMangement.c" 1



var CamFPS;
# 16 "src/UnitMangement.c"
SOUND * unit_management_taunt_generic01 = "taunt-galep-04.ogg";
SOUND * unit_management_taunt_generic02 = "taunt-galep-05.ogg";
SOUND * unit_management_taunt_generic03 = "taunt-jcl-04.ogg";
SOUND * unit_management_taunt_generic04 = "taunt-jcl-05.ogg";
SOUND * unit_management_taunt_generic05 = "taunt-jcl-06.ogg";

SOUND * unit_management_taunt_move01 = "taunt-fritz-01.ogg";
SOUND * unit_management_taunt_move02 = "taunt-fritz-04.ogg";
SOUND * unit_management_taunt_move03 = "taunt-galep-01.ogg";
SOUND * unit_management_taunt_move04 = "taunt-jcl-01.ogg";
SOUND * unit_management_taunt_move05 = "infinity.wav";

SOUND * unit_management_taunt_attack01 = "taunt-fritz-02.ogg";
SOUND * unit_management_taunt_attack02 = "taunt-jcl-02.ogg";
SOUND * unit_management_taunt_attack03 = "taunt-jcl-02.ogg";
SOUND * unit_management_taunt_attack04 = "taunt-jcl-03.ogg";

SOUND * unit_management_taunt_mine01 = "taunt-fritz-02.ogg";
SOUND * unit_management_taunt_mine02 = "taunt-fritz-03.ogg";
SOUND * unit_management_taunt_mine03 = "taunt-galep-03.ogg";
SOUND * unit_management_taunt_mine04 = "taunt-galep-06.ogg";

SOUND * unit_management_taunt_move[9];
SOUND * unit_management_taunt_attack[9];
SOUND * unit_management_taunt_mine[9];





var unit_management_current_taunt_sound;

void UnitMangement_init(){

    unit_management_taunt_move[0] = unit_management_taunt_generic01;
    unit_management_taunt_move[1] = unit_management_taunt_generic02;
    unit_management_taunt_move[2] = unit_management_taunt_generic03;
    unit_management_taunt_move[3] = unit_management_taunt_generic04;
    unit_management_taunt_move[4] = unit_management_taunt_generic05;
    unit_management_taunt_move[5] = unit_management_taunt_move01;
    unit_management_taunt_move[6] = unit_management_taunt_move02;
    unit_management_taunt_move[7] = unit_management_taunt_move03;
    unit_management_taunt_move[8] = unit_management_taunt_move04;
    unit_management_taunt_move[9] = unit_management_taunt_move05;

    unit_management_taunt_attack[0] = unit_management_taunt_generic01;
    unit_management_taunt_attack[1] = unit_management_taunt_generic02;
    unit_management_taunt_attack[2] = unit_management_taunt_generic03;
    unit_management_taunt_attack[3] = unit_management_taunt_generic04;
    unit_management_taunt_attack[4] = unit_management_taunt_generic05;
    unit_management_taunt_attack[5] = unit_management_taunt_attack01;
    unit_management_taunt_attack[6] = unit_management_taunt_attack02;
    unit_management_taunt_attack[7] = unit_management_taunt_attack03;
    unit_management_taunt_attack[8] = unit_management_taunt_attack04;

    unit_management_taunt_mine[0] = unit_management_taunt_generic01;
    unit_management_taunt_mine[1] = unit_management_taunt_generic02;
    unit_management_taunt_mine[2] = unit_management_taunt_generic03;
    unit_management_taunt_mine[3] = unit_management_taunt_generic04;
    unit_management_taunt_mine[4] = unit_management_taunt_generic05;
    unit_management_taunt_mine[5] = unit_management_taunt_mine01;
    unit_management_taunt_mine[6] = unit_management_taunt_mine02;
    unit_management_taunt_mine[7] = unit_management_taunt_mine03;
    unit_management_taunt_mine[8] = unit_management_taunt_mine04;
}





void UnitMangement_open(){
    unit_management_current_taunt_sound = 0;
}


var ClickPoint2D_A[2];
var ClickPoint2D_B[2];



function PosToMap(VECTOR * vec, var x, var y)
{
    VECTOR temp;
    vec_set(temp, vector(x,y, camera.clip_far));
    if(vec_for_screen(temp,camera) != 0)
    {
        VECTOR * p = maploader_trace(camera.x, temp.x);
        if(p){
            vec_set(vec,p);
            return 1;
        }
    }
    return 0;
}

function CheckIsLeftFrom(VECTOR* Base, VECTOR* V1, VECTOR * V2)
{
    VECTOR Line1;
    VECTOR Line2;
    VECTOR Cross;
    vec_diff(Line1,Base, V1);
    vec_diff(Line2,Base, V2);



    vec_normalize (Line1, 1);
    vec_normalize (Line2, 1);

    vec_cross(Cross, Line1, Line2);
    if(Cross.z < 0){
        return 1;
    }
}



function DeselectUnit(ENTITY * ent)
{
    ent.skill[39] = 0;
    ent.ambient = 0;
}

function SelectUnit(ENTITY * ent)
{
    ent.skill[39] = 1;
    ent.ambient = 40;
}

function SetUnitSelcted(ENTITY* ent, var isSelected)
{
    if(isSelected){
        SelectUnit(ent);
    }else{
        DeselectUnit(ent);
    }
}

function MarkUnits()
{
    VECTOR Posis[4];

    var success = 0;
    success += PosToMap(Posis[0], maxv(ClickPoint2D_A[0],ClickPoint2D_B[0]), minv(ClickPoint2D_A[1],ClickPoint2D_B[1]));
    success += PosToMap(Posis[1], maxv(ClickPoint2D_A[0],ClickPoint2D_B[0]), maxv(ClickPoint2D_A[1],ClickPoint2D_B[1]));
    success += PosToMap(Posis[2], minv(ClickPoint2D_A[0],ClickPoint2D_B[0]), maxv(ClickPoint2D_A[1],ClickPoint2D_B[1]));
    success += PosToMap(Posis[3], minv(ClickPoint2D_A[0],ClickPoint2D_B[0]), minv(ClickPoint2D_A[1],ClickPoint2D_B[1]));

    if(success != 4){return;}

    var i;

    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==10 && ent->skill[52] > 0){
            var isInside = 1;
            for(i = 0; i < 4 && isInside; i++){
                isInside = CheckIsLeftFrom(Posis[i],Posis[(i+1)%4],ent.x);
            }
            if(isInside || (key_shiftl && ent.skill[39])){
                ent.ambient = 40;
            }else{
               ent.ambient = 0;
            }
        }
    }
}


function SelectMarkedUnits()
{
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==10){
            SetUnitSelcted(ent, ent.ambient > 0);
        }
     }
}



function DrawQuadDemo(){
    draw_line(vector(maxv(ClickPoint2D_A[0],ClickPoint2D_B[0]),minv(ClickPoint2D_A[1],ClickPoint2D_B[1]),0),0,100);
    draw_line(vector(maxv(ClickPoint2D_A[0],ClickPoint2D_B[0]),maxv(ClickPoint2D_A[1],ClickPoint2D_B[1]),0),vector(255,255,255),80);
    draw_line(vector(minv(ClickPoint2D_A[0],ClickPoint2D_B[0]),maxv(ClickPoint2D_A[1],ClickPoint2D_B[1]),0),vector(255,255,255),80);
    draw_line(vector(minv(ClickPoint2D_A[0],ClickPoint2D_B[0]),minv(ClickPoint2D_A[1],ClickPoint2D_B[1]),0),vector(255,255,255),80);
    draw_line(vector(maxv(ClickPoint2D_A[0],ClickPoint2D_B[0]),minv(ClickPoint2D_A[1],ClickPoint2D_B[1]),0),vector(255,255,255),80);
}


var MouseLeftLast = 0;
var MouseRightLast = 0;

function SetDestForSelectd(VECTOR * Dest)
{
    int Count = 0;
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==10 && ent.skill[39]){
            unit_setTarget(ent, Dest);
            Count++;
        }
    }
    return Count;
}


function SetVictimForSelectd(ENTITY * Victim)
{
    int Count = 0;
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==10 && ent.skill[39]){
            unit_setVictim(ent, Victim);
            Count++;
        }
    }
    return Count;
}


function DebugDrawDests()
{
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)) if(ent->skill[98] == (106)){
        draw_line3d(ent.x, 0, 100);
        draw_line3d(ent.x, vector(0,255,0), 50);
        draw_line3d(ent.skill[40], vector(0,255,0), 50);
    }
}

function DeselectAllOfSubsystem(int Subsys)
{
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)) if(ent->skill[98] == (Subsys)){
        DeselectUnit(ent);
    }
}

function DeselectAllOfGroup(int Group)
{
    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==Group){
            DeselectUnit(ent);
        }
     }
}

function NumberKeyPressed(int nr)
{
    var x = 0;
    var y = 0;
    var count = 0;

    ENTITY * ent;
    for(ent = ent_next(0); ent != 0; ent = ent_next(ent)){
        if(ent->group==10){
            if(key_ctrl){
                if(ent.skill[39]){
                    ent.skill[38] = nr;
                }else{
                    if(ent.skill[38] == nr){
                        ent.skill[38] = 0;
                    }
                }
            }else{
                SetUnitSelcted(ent, ent.skill[38] == nr);
                if(ent.skill[38] == nr){
                    x+=ent.x;
                    y+=ent.y;
                    count++;
                }

            }
        }
    }
    if(!key_ctrl && key_alt && count){
        x /= count;
        y /= count;
        topdown_camera_set_pos(vector(x,y,0));
    }
}

var NuberKeyPressedLast = 0;

function UnitControl()
{
    VECTOR temp;
    mouse_mode = 4;
    if(mouse_left){
        if(MouseLeftLast == 0 ){

         if(mouse_panel == 0){
             if(!key_shiftl){
                 DeselectAllOfGroup(10);



             }
             DeselectAllOfGroup(12);
             DeselectAllOfSubsystem(99);

                vec_set(temp, vector(mouse_pos.x,mouse_pos.y, camera.clip_far));
                vec_for_screen(temp,camera);
                c_trace(camera.x, temp,(1<<19) | (1<<3) | (1<<5));
                if(you != 0){
                         if(you->group==10 || you->group==11 || you->group==12 || you->group==13){



                            if(you->skill[52] > 0)
                            {
                                if(fow_isPosVisible(target.x))
                                {
                                    SelectUnit(you);
                                }
                            }
                        }
                 }
            }

            ClickPoint2D_A[0]= ClickPoint2D_B[0] = mouse_pos.x;
            ClickPoint2D_A[1]= ClickPoint2D_B[1] = mouse_pos.y;

        }else{
            ClickPoint2D_B[0]=mouse_pos.x;
            ClickPoint2D_B[1]=mouse_pos.y;
        }
        if(abs(ClickPoint2D_A[0]-ClickPoint2D_B[0]) > 2 && abs(ClickPoint2D_A[1]-ClickPoint2D_B[1])> 2){
            DrawQuadDemo();
            MarkUnits();
        }
    }else{
       if(MouseLeftLast){
            SelectMarkedUnits();
       }
    }
    if(mouse_right && !MouseRightLast){
        var CmdType = 1;

        if(mouse_panel == 0){
            vec_set(temp, vector(mouse_pos.x,mouse_pos.y, camera.clip_far));
            vec_for_screen(temp,camera);
            c_trace(camera.x, temp,(1<<19) | (1<<3));
            if(you != 0){
                 if(you->group==12 || you->group==14 || you->group == 13){

                    CmdType = 2;
                    if(unit_getType(you) == 4){
                       CmdType = 3;
                    }


                }
            }
        }
        VECTOR Dest;
        PosToMap(Dest,mouse_pos.x,mouse_pos.y);
        if(SetDestForSelectd(Dest) > 0){

            SOUND ** group;
            int count;

            switch(CmdType)
            {
            case 1:
                group = unit_management_taunt_move;
                count = 10;
                break;
            case 2:
                group = unit_management_taunt_attack;
                count = 9;
                SetVictimForSelectd(you);
                break;
            case 3:
                group = unit_management_taunt_mine;
                count = 9;
                SetVictimForSelectd(you);
                break;
            }

            int sndid = (int)random(count);

            if(unit_management_current_taunt_sound == 0)
                unit_management_current_taunt_sound = snd_play(group[sndid], 100, 0);

            effects2d_spawn(Dest, CmdType);
        }
    }

    int i;
    var NuberPressed = 0;
    for(i = 2; i < 10; i++){
        if(key_pressed(i) && !NuberKeyPressedLast){
            NumberKeyPressed(i-1);
            NuberPressed = i-1;
        }
    }
    NuberKeyPressedLast = NuberPressed;
    MouseLeftLast = mouse_left;
    MouseRightLast = mouse_right;
}



void UnitMangement_update()
{
    UnitControl();


    if(unit_management_current_taunt_sound != 0)
    {
        if(!snd_playing(unit_management_current_taunt_sound))
            unit_management_current_taunt_sound = 0;
    }
}

void UnitMangement_close(){
    if(unit_management_current_taunt_sound != 0)
        snd_stop(unit_management_current_taunt_sound);
}

void UnitMangement_unselect(ENTITY* ent)
{
 if (ent) ent->skill[39] = 0;
}
# 45 "main.c" 2
# 1 "src/stub.c" 1




ENTITY* fancysputnik;
ENTITY* evilsputnik;
ENTITY* fancytower;
ENTITY* fancyz;

void producesputnik()
{
 spawner_produce(fancytower);
}

void getz()
{
 unit_setTarget(fancysputnik, fancyz->x);
 unit_setVictim(fancysputnik, fancyz);
}

void attack()
{
 unit_setTarget(fancysputnik, evilsputnik->x);
 unit_setVictim(fancysputnik, evilsputnik);
}

void stub_init()
{
 on_p = producesputnik;
 on_k = getz;
 on_f = attack;
 fancysputnik = unit_spawn(0, vector(0,0,500), 0);
 evilsputnik = unit_spawn(0, vector(-1500,0,500), 1);
 unit_spawn(0, vector(-1800,0,500), 1);
 unit_spawn(0, vector(-2100,0,500), 1);
 fancytower = spawner_spawn(0, vector(100,1000,500), 0, 0);
 fancyz = z_spawn(vector(3000, 0, 500));
}

void stub_update()
{
}
# 46 "main.c" 2
# 1 "src/unit.c" 1





var unit__dmgtable[25] = {

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



 if (ent != 0)
 {
  if (ent->group == 10 || ent->group == 12)
  {
   vec_set(ent->skill[29], pos);
   unitSetTargetFromVector2D(map, ((UNIT*)ent->skill[96]), target2D);
   unit_setVictim(ent, 0);
   return 1;
  }
 }
 return 0;

}

VECTOR* unit_getTarget(ENTITY* ent)
{
 return &ent->skill[29];
}

var unit_setVictim(ENTITY* ent, ENTITY* victim)
{
 if (ent != 0)
 {
  if (ent->group == 10 || ent->group == 12)
  {
   if (victim != 0)
   {

    {
     ent->skill[56] = handle(victim);
     ent->skill[60] = victim->skill[59];
     return 1;
    }
   }
   ent->skill[60] = -1;
   ent->skill[56] = 0;
  }
 }
 return 0;
}

ENTITY* unit_getVictim(ENTITY* ent)
{
 if (ent != 0)
 {
  ENTITY* victim = ptr_for_handle(ent->skill[56]);
  if (victim != 0)
  {
   if (victim->skill[54] == 4 || victim->skill[54] == 5)
    return 0;
  }
  return victim;
 }
 return 0;
}

ENTITY* unit_spawn(int unittype, VECTOR* pos, var owner)
{
 return unit_spawn(unittype, pos, pos, owner);
}

ENTITY* unit_spawn(int unittype, VECTOR* pos, VECTOR* targetPos, var owner)
{
 ENTITY* ent = 0;
 switch (unittype)
 {
  case 0:
   ent = ent_create("sputnik.mdl", pos, Sputnik);
   break;

  case 1:
   ent = ent_create("cEselslerche.mdl", pos, Sputnik);
   break;

  case 2:
   ent = ent_create("eye.mdl", pos, Sputnik);
   break;

  case 3:
   ent = ent_create("cbabe.mdl", pos, Sputnik);
   break;

  default:
   break;
 }

 if (ent != 0)
 {
  ent->skill[53] = owner;
  if (owner == 1)
  {
   ent->group = 12;
   ent->skill[96] = jpsUnitCreate(1, unittype, ent);
  }
  else
  {
   ent->group = 10;
   ent->skill[96] = jpsUnitCreate(0, unittype, ent);
  }

  ent->skill[59] = unittype;
  unit_setTarget(ent, targetPos);
  unit_setVictim(ent,0);
 }

 return ent;
}

var unit_getHealth(ENTITY* ent)
{
 return ent->skill[52] / ent->skill[51];
}

var unit_setDamage(ENTITY* victim, ENTITY* attacker)
{
 if (victim != 0 && attacker != 0)
 {
  var index = 5 * clamp(attacker->skill[59],0,5 -1) + clamp(victim->skill[59],0,5 -1);
  victim->skill[50] = unit__dmgtable[index];
  victim->skill[49] = handle(attacker);

  return unit__dmgtable[index];
 }
 return 0;
}

int unit_getType(ENTITY* ent)
{
 if (ent != 0)
 {
  return ent->skill[59];
 }
 return -1;
}

ENTITY* unit_findNextVictim(ENTITY* ptr, var unittype)
{
 ptr->skill[60] = unittype;
 return unit_findNextVictim(ptr);
}

ENTITY* unit_findNextVictim(ENTITY* ptr)
{







 if (unit_getVictim(ptr) == 0 && ptr->skill[60] != -1)
 {
  cdiag(_chr("\n unit__findNextVictim: TRYFIND..."));
  ENTITY* ent;
  if(ptr->skill[60] == 4)
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

   if (mapGetNearbyUnitsOfTypeForPos(ptr->x, ptr->skill[60], ptr->skill[53], 2000, 1) > 0)
   {
    ent = (((UNIT*)pointerArray[0])->ent);


    unit_setTarget(ptr, &ent->x);
    unit_setVictim(ptr, ent);
    return ent;
   }
  }
 }
 return 0;
}

void unit_deactivate(ENTITY* ptr)
{
 UnitMangement_unselect(ptr);
 jpsUnitDestroy(((UNIT*)ptr->skill[96]));
 ptr->group = 0;
}
# 47 "main.c" 2
# 1 "src/ang.c" 1


var ANG_turnToPos(ENTITY* ptr, VECTOR* pos, var speed, var hysteresis)
{
 ANGLE vecAngle;
 VECTOR vecTemp;
 vec_set(&vecTemp, &pos->x);
 vec_sub(&vecTemp, &ptr->x);
 vec_to_angle(&vecAngle, &vecTemp);
 var x = ANG_turnToAngle(ptr, vecAngle.pan, speed, hysteresis);
 return x;
}

var ANG_turnToAngle(ENTITY* ptr, var angle, var speed, var hysteresis)
{
 ANGLE* sourceAngle = vector(ang(ptr->pan),0,0);
 ANGLE* targetAngle = vector(ang(angle),0,0);
 ANGLE diffAngle;
 ang_diff(&diffAngle, targetAngle, sourceAngle);
 if (absv(diffAngle.pan) > hysteresis)
 {
  ANGLE* angle;
  if (diffAngle.pan > 0)
  {
   ptr->pan += minv(diffAngle.pan, speed * time_step);

  }
  else
  {
   ptr->pan += maxv(diffAngle.pan, -speed * time_step);
  }
  ptr->pan = ang(ptr->pan);
  return 0;
 }
 return 1;
}
# 48 "main.c" 2
# 1 "src/scan.c" 1




var SCAN_IsCameraNear(ENTITY* ent)
{
 if (ent == 0)
  return 0;

 if (vec_dist(&camera->x, ent->x) < 1000)
  return 1;
 else
  return 0;
}

var SCAN_IsEntityNear(ENTITY* ent, ENTITY* targetEnt, var distance)
{
 if (ent != 0 && targetEnt != 0)
 {
  return SCAN_IsTargetNear(ent, targetEnt->x, distance);
 }
 else
 {
  return 0;
 }
}

var SCAN_IsTargetNear(ENTITY* ent, VECTOR* pos, var distance)
{
 if (ent == 0)
  return 0;

 VECTOR* vec1 = vector(ent->x, ent->y, 0);
 VECTOR* vec2 = vector(pos->x, pos->y, 0);
 if (vec_dist(vec1, vec2) < distance)
  return 1;
 else
  return 0;
}
# 49 "main.c" 2
# 1 "src/grid.c" 1


int *grid_state;
int grid_xSize;
int grid_ySize;

void grid_init()
{
 grid_state = 0;
}

void grid_open(int xSize, int ySize)
{
 grid_state = sys_malloc(((int)_sizeof(int))*xSize*ySize);
 grid_xSize = xSize;
 grid_ySize = ySize;

 int i;
 int on = 0;
 for(i = 0; i<xSize*ySize; ++i)
 {
  on = 1-on;
  grid_state[i] = on;


 }

}

void grid_close()
{
 sys_free(grid_state);
 grid_state = 0;
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
 if(id < 0 || id > grid_xSize*grid_ySize)
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


void grid_setState_byID(int id, state)
{
 grid_errorcheck(id);
 grid_state[id] |= state;

}

void grid_resetState_byID(int id, state)
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
 int x = (pos.x + 200*grid_xSize/2) / 200;
 int y = (pos.y + 200*grid_ySize/2) / 200;

 return grid_CoordToID(x,y);
}

VECTOR *grid_getCellCenter(int x, int y)
{
 grid_errorcheck(grid_CoordToID(x,y));
 x -= grid_xSize/2;
 y -= grid_ySize/2;
 return vector((x+0.5)*200, (y+0.5)*200, 400);
}

VECTOR *grid_getCellCenter_byID(int ID)
{
 return grid_getCellCenter(grid_idx2X(ID), grid_idx2Y(ID));
}
# 50 "main.c" 2
# 1 "src/particle.c" 1
# 1 "src/particle.h" 1



void PARTICLE_explode(var count, VECTOR* pos);
void PARTICLE_laser(VECTOR* pos, VECTOR* vecDist);
void PARTICLE_smoke(PARTICLE* p);


void PARTICLE__explode_fade(PARTICLE* p);
void PARTICLE__explode_init(PARTICLE* p);
void PARTICLE__laser_init(PARTICLE* p);
void PARTICLE__laser_fade(PARTICLE* p);
# 2 "src/particle.c" 2






void PARTICLE_explode(var count, VECTOR* pos)
{
 effect(PARTICLE__explode_init, count, pos, nullvector);
}

void PARTICLE__explode_fade(PARTICLE* p)
{
 p->alpha = maxv(p->alpha - 10* time_step, 0);
}

void PARTICLE__explode_init(PARTICLE* p)
{


 vec_set(&p->blue,vector(5,174,86));
 p->flags |= ((1<<11) | (1<<21) | (1<<9));
 p->lifespan = 20+random(1);
 p->alpha = 90 + random(10);
 p->gravity = 1;
 p->size = 3;
 p->event = PARTICLE__explode_fade;
}

void PARTICLE_laser(VECTOR* pos, VECTOR* vecDist)
{


 effect(PARTICLE__laser_init, 1, pos, vecDist);
}

void PARTICLE__laser_init(PARTICLE* p)
{
 vec_set(&p->blue,vector(0,255,0));
 p->flags |= ((1<<9));
 p->lifespan = 0.1;
 p->alpha = 100;
 p->size = 10;
 p->event = 0;
}

void PARTICLE__laser_fade(PARTICLE* p)
{
 ENTITY* ent = ptr_for_handle(p->skill[0]);
 if (ent)
  vec_lerp(&p->vel_x,&p->vel_x,&ent->skill[23],0.5);
 p->alpha = maxv(p->alpha - 5* time_step, 0);
}

void smoke_fade_p(PARTICLE* p)
{
 p.alpha -= p.skill[0]*time_step;
 if (p.alpha <= 0) p.lifespan = 0;

 p.size = minv(p.skill[1], p.size+time_step*3);
}

BMAP* bmp_smoke = "rauch2.tga";

void PARTICLE_smoke(PARTICLE* p)
{
 p.skill[0] = 3;
 p.bmap = bmp_smoke;
 p.lifespan = 1200+random(600);
 p.skill[1] = 100 + random(50);
 p.size = 20;
 p.alpha = 80;
 vec_scale(p.vel_x, 0.4);
 p->flags |= ((1<<10) | (1<<11));
 p.event = smoke_fade_p;
}
# 51 "main.c" 2
# 1 "src/spawner.c" 1
# 49 "src/spawner.c"
SOUND* spawner_spawn_snd = "factory.wav";
SOUND* spawner_destroy_snd = "factory_destroyed.wav";

MATERIAL * building_wireframe_material =
{
  flags = (1<<24) | (1<<10);
  effect = "building_wireframe.fx";
}

MATERIAL * building_material =
{
  flags = (1<<24) | (1<<11);
  effect = "building.fx";
}

ENTITY* spawner_spawn(int unittype, VECTOR* pos, var angle, var owner)
{
 ENTITY* ent;
   ENTITY *wireframe;
 switch (unittype)
 {
        case 0:
            ent = ent_create("sputnik_trash_press.mdl", pos, Spawner);
            wireframe = ent_create("sputnik_trash_press_wf.mdl", pos, 0);
            break;
        case 1:
            ent = ent_create("lark_farm.mdl", pos, Spawner);
            wireframe = ent_create("lark_farm_wireframe.mdl", pos, 0);
            break;
        case 2:
            ent = ent_create("eye_tree_you.mdl", pos, Spawner);
            wireframe = ent_create("eye_tree_you_wireframe.mdl", pos, 0);
            break;
        case 3:


            ent = ent_create("the_tower.mdl", pos, Spawner);
            wireframe = ent_create("the_tower_wireframe.mdl", pos, 0);
            break;
 }

 if (ent != 0)
 {
  ent->pan = angle;
  wireframe->pan = angle;
  mapSetTileValueAtPos3D(mapGetCurrent(), pos, 1);
  mapJPSUpdate(mapGetCurrent());

  ent->skill[59] = unittype;
  ent->skill[53] = owner;
  if (owner == 1)
  {
   ent->group = 13;
  }
  else
  {
   ent->group = 11;
   snd_play(spawner_spawn_snd, 100, 0);
   fov_uncover(pos, 2000);
  }

  ent->material = building_material;

  if(wireframe != 0)
  {
   wireframe->material = building_wireframe_material;
   wireframe->flags &= ~((1<<18));
   ent->skill[30] = handle(wireframe);
  }
 }

 return ent;
}

var spawner_produce(ENTITY* ent)
{
 if (ent != 0)
 {
  if (ent->group == 13 || ent->group == 11)
  {
   if(z_isSufficient(spawner_unit_cost[ent->skill[59]], ent->skill[53]))
   {
    z_pay(spawner_unit_cost[ent->skill[59]], ent->skill[53]);
    ent->skill[20]++;
   }
   return ent->skill[20];
  }
 }
 return 0;
}

var spawner_getQueue(ENTITY* ent)
{
 if (ent != 0)
 {
  if (ent->group == 13 || ent->group == 11)
  {
   return ent->skill[20];
  }
 }
 return 0;
}

var spawner_getProgress(ENTITY* ent)
{
 if (ent != 0)
 {
  if (ent->group == 13 || ent->group == 11)
  {
   if (ent->skill[54] == 2)
    return 1 - (ent->skill[22] / 20);
  }
 }
 return 0;
}

var spawner_getHealth(ENTITY* ent)
{
 return ent->skill[52] / ent->skill[51];
}

void Spawner()
{
   framework_setup(my, 99);
 my->skill[52] = 50;
 my->skill[51] = my->skill[52];
 my->flags |= ((1<<18));
    my->flags &= ~((1<<10));
 c_setminmax(me);
 my->skill[54] = 0;

 my->skill[20] = 0;
 my->skill[22] = 20;
 my->skill[23] = 30;

 my->z = maploader_get_height(my->x) - my->min_z;
 my->skill[69] = my->x;
 my->skill[70] = my->y;
 my->skill[71] = my->z;
}

void SPAWNER_Init()
{
}

void SPAWNER_Update()
{
 ENTITY * ptr;
 for(ptr = ent_next(0); ptr != 0; ptr = ent_next(ptr)) if(ptr->skill[98] == (99))
 {

  if (ptr->skill[52] > 0)
  {
   SPAWNER__hitcheck(ptr);
  }

  if (ptr->skill[50] > 0)
  {
   SPAWNER__hit(ptr);
  }

  switch(ptr->skill[54])
  {

   case 0:
   {
    SPAWNER__construct(ptr);
    break;
   }

   case 1:
   {
    SPAWNER__active(ptr);
    break;
   }

   case 2:
   {
    SPAWNER__produce(ptr);
    break;
   }

   case 4:
   {
    SPAWNER__die(ptr);
    break;
   }

   default:
   {
    break;
   }
  }

 }
}

void SPAWNER__hit(ENTITY* ptr)
{
 ptr->skill[58] = 3;

 ptr->skill[52] = maxv(0, ptr->skill[52] - ptr->skill[50]);
 ptr->skill[50] = 0;

 if (ptr->skill[52] <= 0)
 {
  UnitMangement_unselect(ptr);
  ptr->group = 0;
  ptr->skill[54] = 4;
  ptr->skill[55] = 0;
  snd_play(spawner_destroy_snd, 100, 0);
 }
}

void SPAWNER__hitcheck(ENTITY* ptr)
{
 if (ptr->skill[58] > 0)
 {
  ptr->skill[58] -= time_step;

  if (ptr->skill[58] <= 0)
  {
   ptr->skill[58] = 0;
  }
 }
}


void SPAWNER__construct(ENTITY* ptr)
{
 ptr->skill[21] += 5 * time_step;

 var percentage = ptr->skill[21] * (ptr.max_z + 200) / 100;
 ptr->skill[40] = floatv(percentage);
 ptr->skill[41] = floatv(ptr->max_x * 0.5);
 ptr->skill[42] = floatv(clamp((80.0 - ptr->skill[21])/20.0, 0.0, 1.0));

 ptr->skill[44] = floatv(ptr->x);
 ptr->skill[45] = floatv(ptr->z);
 ptr->skill[46] = floatv(ptr->y);

 ENTITY *wireframe = ptr_for_handle(ptr->skill[30]);
 wireframe->z = ptr->z;
 if(wireframe != 0)
 {
  wireframe->skill[40] = floatv(percentage);

  wireframe->skill[44] = floatv(wireframe->x);
  wireframe->skill[45] = floatv(wireframe->z);
  wireframe->skill[46] = floatv(wireframe->y);
 }

 if (ptr->skill[21] >= 100)
 {
  ptr->skill[21] = 100;
  ptr->skill[54] = 1;
  ptr->skill[30] = 0;
  ptr_remove(wireframe);
 }
}

void SPAWNER__active(ENTITY* ptr)
{
 if (ptr->skill[20] > 0)
 {
  ptr->skill[54] = 2;
 }
 else
 {
  ent_animate(ptr, "Stand", ptr->skill[24], (1<<0));
  ptr->skill[24] = cycle(ptr->skill[24] + time_step, 0, 100);
 }
}

void SPAWNER__produce(ENTITY* ptr)
{
 ptr->skill[22] -= time_step;
 var progress = 100 * (1 - (ptr->skill[22] / 20));
 ent_animate(ptr, "produce", clamp(progress, 0, 100), 0);

 if (ptr->skill[22] <= 0)
 {
  ptr->skill[22] = 20;
  ptr->skill[20]--;
  ptr->skill[31] += 137.5;
  ptr->skill[31] %= 360;
  VECTOR* targetPos = vector(400,0,0);
  VECTOR* angle = vector(ang(ptr->skill[31]), 0, 0);
  vec_rotate(targetPos, angle);
  vec_add(targetPos, ptr->x);
  unit_spawn(ptr->skill[59], ptr->x, targetPos, ptr->skill[53]);
 }
 if (ptr->skill[20] == 0)
 {
  ptr->skill[22] = 20;
  ptr->skill[54] = 1;
  ptr->skill[24] = 0;
 }
}

void SPAWNER_smoke_fade_p(PARTICLE* p)
{
 p->skill[0]-=time_step;
 p->alpha = maxv(0, minv(100, p->skill[0]));
 if (p->alpha <= 0) p->lifespan = 0;

 p->size = minv(p->skill[1], p->size+time_step*3);
}

BMAP* bmp_smoke = "rauch2.tga";

void SPAWNER_smoke(PARTICLE* p)
{
 p->skill[0] = random(20) + 10;
 p->bmap = bmp_smoke;
 p->lifespan = 9000;
 p->skill[1] = 1000 + random(50);
 p->size = 200;
 p->alpha = 80;

 p->vel_x = 20-random(40);
 p->vel_y = 20-random(40);
 p->vel_z = 20 - random(30);
 p->flags |= ((1<<10) | (1<<11));
 p.event = SPAWNER_smoke_fade_p;
}

void SPAWNER_debris(PARTICLE* p)
{
 p->lifespan = 50;
 p->size = 100 + random(200);
 p->alpha = 80;
 p->gravity = 4;
 p->red = 0;
 p->green = 0;
 p->blue = 0;
 p->vel_x = 80-random(160);
 p->vel_y = 80-random(160);
 p->vel_z = 20 + random(30);
 p->flags |= ((1<<10) | (1<<11));
 p->event = 0;
}


void SPAWNER_fire_fade_p(PARTICLE* p)
{
 p->skill[0]-=time_step * 3;
 p->alpha = maxv(0, minv(100, p->skill[0]));
 p->size -= time_step * p->skill[1];
 p->green = minv(255, p->green + time_step * p->skill[1] * 2);
}

BMAP* bmp_fire = "rauch2.tga";

void SPAWNER_fire(PARTICLE* p)
{
 p->skill[0] = random(30) + 60;
 p->lifespan = 90;
 p->skill[1] = random(4) + 2;
 p->size = 200;
 p->alpha = 80;
 p->red = 255;
 p->green = 80;
 p->vel_x = 20-random(40);
 p->vel_y = 20-random(40);
 p->vel_z = 20 - random(30);
 p->flags |= ((1<<10) | (1<<11));
 p.event = SPAWNER_fire_fade_p;
}


void SPAWNER__die(ENTITY* ptr)
{
 ptr->skill[23] -= time_step;

 var deathfactor = 1.0 - (ptr->skill[23] / 30);

 ptr->z = ptr->skill[71] - deathfactor * 700.0;
 ptr->roll = deathfactor * 15.0;

 if (deathfactor < 0.1)
 {
  VECTOR* pos = vector(ptr->skill[69]+random(100)-50, ptr->skill[70]+random(100)-50, ptr->skill[71]+random(100)-50);
  effect(SPAWNER_debris, 12*time_step, pos, nullvector);
 }

 if (deathfactor < 0.3)
 {
  VECTOR* pos = vector(ptr->skill[69]+random(100)-50, ptr->skill[70]+random(100)-50, ptr->skill[71]+random(100)-50);
  effect(SPAWNER_fire, 30*time_step, pos, nullvector);
 }

 if (deathfactor < 0.7)
 {
  VECTOR* pos = vector(ptr->skill[69]+random(100)-50, ptr->skill[70]+random(100)-50, ptr->skill[71]+random(100)-50);
  effect(SPAWNER_smoke, 60*time_step, pos, nullvector);
 }







 if(ptr->skill[23] <= 0)
 {
  mapSetTileValueAtPos3D(mapGetCurrent(), ptr->x, 0);
  mapJPSUpdate(mapGetCurrent());
  ptr->flags &= ~((1<<18));
  ptr->skill[23] = 0;
  ptr->skill[54] = 5;
 }
}
# 52 "main.c" 2
# 1 "src/building.c" 1







ENTITY *buildingPlacement_previewModel;
int buildingPlacement_selection;

int buildingState()
{
 return buildingPlacement_selection;
}


void buildingPlacement_init()
{



 buildingPlacement_assets[0] = "sputnik_trash_press.mdl";
 buildingPlacement_constructionAssets[0] = "sputnik_trash_press_wf.mdl";

 buildingPlacement_assets[1] = "lark_farm.mdl";
 buildingPlacement_constructionAssets[1] = "lark_farm_wireframe.mdl";

 buildingPlacement_assets[2] = "eye_tree_you.mdl";
 buildingPlacement_constructionAssets[2] = "eye_tree_you_wireframe.mdl";



 buildingPlacement_assets[3] = "the_tower.mdl";
 buildingPlacement_constructionAssets[3] = "the_tower_wireframe.mdl";
}

void buildingPlacement_open()
{
 buildingPlacement_previewModel = 0;
 buildingPlacement_selection = -1;
}


void buildingPlacement_movePreview()
{
 VECTOR *_hit = get_pos_under_cursor();
 if(_hit != 0)
 {
  TILE* tile = mapGetTileFromVector(mapCurrent, _hit);
  if(tile != 0)
  {
   if(!tile->value)
   {
    VECTOR targetPos;
    mapGetVectorFromTile(mapCurrent, &targetPos, tile);
    targetPos.z = _hit.z;
    vec_set(&buildingPlacement_previewModel->x, targetPos);
   }
  }
 }
}



void buildingPlacement_beginConstruction(int selection)
{
 if( buildingPlacement_selection != -1 )
 {
  buildingPlacement_endConstruction();
 }

 buildingPlacement_selection = selection;
 buildingPlacement_previewModel = ent_create(buildingPlacement_constructionAssets[selection], nullvector, 0);
 buildingPlacement_previewModel->flags |= (1<<10);
 buildingPlacement_previewModel->alpha = 70;
 buildingPlacement_previewModel->pan = random(360);
}

void buildingPlacement_endConstruction()
{
 ptr_remove(buildingPlacement_previewModel);
 buildingPlacement_previewModel = 0;
 buildingPlacement_selection = -1;
}

void buildingPlacement_placeConstruction()
{
 switch(buildingPlacement_selection)
 {
  case 0:
  case 1:
  case 2:
  case 3:

  if(!buildingPlacement_previewModel) error("buildingPlacement_placeConstruction: !buildingPlacement_previewModel !!!");
  spawner_spawn(buildingPlacement_selection, &buildingPlacement_previewModel->x, buildingPlacement_previewModel->pan, 0);

  break;
  default:
  error("unbekannter Gebauedetyp");
 }

 buildingPlacement_endConstruction();
}

void buildingPlacement_update()
{
 if(buildingPlacement_selection == -1 && !mouse_left)
 {
  if(key_1)
  buildingPlacement_beginConstruction(0);
  if(key_2)
  buildingPlacement_beginConstruction(1);
  if(key_3)
  buildingPlacement_beginConstruction(2);
  if(key_4)
  buildingPlacement_beginConstruction(3);
 }

 if(buildingPlacement_selection != -1)
 {
  buildingPlacement_movePreview();
  if(mouse_left && !mouse_panel)
  buildingPlacement_placeConstruction();
  if(mouse_right)
  buildingPlacement_endConstruction();
 }
}
# 53 "main.c" 2
# 1 "src/jps.c" 1
# 9 "src/jps.c"
LIST* listAdd(LIST* current, void* data)
{
 LIST* new;

 new = (LIST*)sys_malloc(((int)_sizeof(LIST)));
 new->data = data;
 new->next = current;

 return new;
}

LIST* listAddTileSorted(LIST* current, TILE* tile, int sortMethod)
{
 LIST* new, *first = current, *prev = 0;

 new = (LIST*)sys_malloc(((int)_sizeof(LIST)));
 new->data = tile;
 new->next = 0;

 if(!first) return new;

 if(sortMethod)
 {
  if(((TILE*)first->data) == tile) return first;
  prev = first;
  LIST* current2 = first->next;
  while(current2)
  {
   TILE* tile2 = (TILE*)current2->data;

   if(tile2 == tile)
   {
    prev->next = current2->next;
    sys_free(current2);
    break;
   }
   prev = current2;
   current2 = current2->next;
  }
  prev = 0;
 }

 while(current)
 {
  TILE* tile2 = (TILE*)current->data;
  if(tile->totalCost < tile2->totalCost)
  {
   if(prev) prev->next = new;
   else first = new;
   new->next = current;
   return first;
  }
  prev = current;
  current = current->next;
 }
 prev->next = new;

 return first;
}

void listDestroy(LIST* list, int mode)
{
 LIST* prev;

 while(list)
 {
  if(mode & (1<<0))
  {
   TILE* tile = (TILE*)list->data;
   if(tile)
   {
    if(!(tile->flags & (1<<1))) tileResetJPSData(tile);
   }
  }
  prev = list;
  list = list->next;
  sys_free(prev);
 }
}

void draw_line2(VECTOR* vFrom, VECTOR* vTo, COLOR* color, var alpha)
{
 draw_line(vFrom,0,alpha);
 draw_line(vFrom,color,alpha);
 draw_line(vTo,color,alpha);
}

void draw_line3D2(VECTOR* vFrom, VECTOR* vTo, COLOR* color, var alpha)
{
 draw_line3d(vFrom,0,alpha);
 draw_line3d(vFrom,color,alpha);
 draw_line3d(vTo,color,alpha);
}




UNIT* jpsAllowMovementForEntity(ENTITY* ptr, int allow)
{
 UNIT* unit = ((UNIT*)ptr->skill[96]);
 unit->allowMovement = allow;
 return unit;
}

JPSPATH *jpsPathCreate(int maxLength)
{
 JPSPATH *jpsPath = (JPSPATH*)sys_malloc(((int)_sizeof(JPSPATH)));
 memset(jpsPath, 0, ((int)_sizeof(JPSPATH)));
 jpsPath->maxLength = maxLength;
 jpsPath->tiles = (TILE**)sys_malloc(((int)_sizeof(TILE*)) * maxLength);
 memset(jpsPath->tiles, 0, ((int)_sizeof(TILE*)) * maxLength);

 return jpsPath;
}

void jpsPathDestroy(JPSPATH *jpsPath)
{
 if(!jpsPath) return;
 if(jpsPath->tiles) sys_free(jpsPath->tiles);
 sys_free(jpsPath);
}

void mapTilesInitialize(MAP* map)
{
 int i,j,k,i2,j2;
 for(i = 0; i < map->size[0]; i++)
 {
  for(j = 0; j < map->size[1]; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   tile->pos[0] = i;
   tile->pos[1] = j;
   tile->flags = 0;
   tile->value = (!i || i == map->size[0]-1 || !j || j == map->size[1]-1);
   tile->numNeighbors = 0;
   tile->neighborList = 0;
   tile->prev = 0;
  }
 }
}

MAP* mapGetCurrent()
{
 if(!mapCurrent) error("mapGetCurrent: !mapCurrent");
 return mapCurrent;
}

MAP *mapCreate(int sizeX, int sizeY, VECTOR *vMin, VECTOR *vMax, var tileSize)
{
 MAP *map = (MAP*)sys_malloc(((int)_sizeof(MAP)));
 memset(map, 0, ((int)_sizeof(MAP)));
 map->size[0] = sizeX;
 map->size[1] = sizeY;
 map->tiles = (TILE*)sys_malloc(((int)_sizeof(TILE)) * map->size[0] * map->size[1]);
 mapTilesInitialize(map);
 map->bmp = bmap_createblack(map->size[0], map->size[1], 24);
 map->jpsPath = jpsPathCreate(4*sizeX);

 vec_set(map->vMin, vMin);
 vec_set(map->vMax, vMax);
 vec_diff(map->vSize, vMax, vMin);
 map->tileSize = tileSize;
 mapCurrent = map;

 return map;
}

void mapFillTest(MAP* map)
{
 int i,j,k,i2,j2;
 for(i = 0; i < map->size[0]; i++)
 {
  for(j = 0; j < map->size[1]; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   tile->pos[0] = i;
   tile->pos[1] = j;
   tile->flags = 0;

   tile->value = (!i || i == map->size[0]-1 || !j || j == map->size[1]-1);
   tile->numNeighbors = 0;
   tile->neighborList = 0;
   tile->prev = 0;
  }
 }


 int shiftX,shiftY,sizeX,sizeY;
 for(k = 0; k < 26; k++)
 {
  shiftX = random(map->size[0]);
  shiftY = random(map->size[1]);
  sizeX = 3+random(7);
  sizeY = 3+random(7);
  for(i = 0; i < sizeX; i++)
  {
   for(j = 0; j < sizeY; j++)
   {
    i2 = i+shiftX;
    j2 = j+shiftY;
    i2 %= map->size[0];
    j2 %= map->size[1];
    TILE* tile = mapTileGet(map,i2,j2);
    if(tile) tile->value = 1;
   }
  }
 }
}

void tileResetJPSData(TILE* tile)
{
 tile->currentCost = 9999;
 tile->targetCost = 9999;
 tile->totalCost = 9999*2;
 tile->targetReachable = 0;
 tile->flags &= ~(1<<1);
 tile->prev = 0;
}

TILE* mapTileGet(MAP* map, int x, int y)
{
 if(x < 0 || x >= map->size[0] || y < 0 || y >= map->size[1]) return 0;
 return &((map->tiles)[x*map->size[1] + y]);
}

void mapUpdateBmap(MAP* map)
{
 int i,j;
 BMAP* bmp = map->bmp;
 if(!bmp) return;
 var format = bmap_lock(bmp,0);
 var pixelJPS = pixel_for_vec(vector(255,0,255),100,format);
 var pixelOn = pixel_for_vec(vector(128,128,128),100,format);
 var pixelOff = pixel_for_vec(vector(0,0,0),100,format);

 for(i = 0; i < map->size[0]; i++)
 {
  for(j = 0; j < map->size[1]; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   if(tile->flags & (1<<0)) pixel_to_bmap(bmp,i,j,pixelJPS);
   else
   {
    if(tile->value) pixel_to_bmap(bmp,i,j,pixelOff);
    else pixel_to_bmap(bmp,i,j,pixelOn);
   }
  }
 }
 bmap_unlock(bmp);
}

void mapTileFreeNeighborData(MAP* map, TILE* sourceTile)
{
 sourceTile->numNeighbors = 0;
 if(sourceTile->neighborList)
 {
  listDestroy(sourceTile->neighborList,0);
  sourceTile->neighborList = 0;
 }
 if(sourceTile->neighborCost)
 {
  sys_free(sourceTile->neighborCost);
  sourceTile->neighborCost = 0;
 }
 sourceTile->targetCost = 9999;
 sourceTile->currentCost = 9999;
}

void mapJPSDo(MAP* map)
{
 int i,j,k,i2,j2;
 char nearbyGrid[8];

 listDestroy(map->JPSTileList,0);
 map->JPSTileList = 0;

 for(i = 1; i < map->size[0]-1; i++)
 {
  for(j = 1; j < map->size[1]-1; j++)
  {
   TILE* tile = mapTileGet(map,i,j);

   if(tile->jpsType) mapTileFreeNeighborData(map,tile);
   tile->flags &= ~(1<<0);
   tile->jpsType = 0;
  }
 }
 int extraSpace = jpsExtraWidth;
 int range = 1+extraSpace;
 for(i = range; i < map->size[0]-range; i++)
 {
  for(j = range; j < map->size[1]-range; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   if(!tile->value)
   {
    int tileOkay = 1;
    if(extraSpace)
    {
     for(k = 0; k < 8; k++)
     {
      i2 = i+offset2D[k*2+0];
      j2 = j+offset2D[k*2+1];
      TILE* tile2 = mapTileGet(map,i2,j2);
      if(tile2)
      {
       if(tile2->value)
       {
        tileOkay = 0;
        break;
       }
      }
     }
    }
    if(tileOkay)
    {
     for(k = 0; k < 8; k++)
     {
      i2 = i+offset2D[k*2+0]*range;
      j2 = j+offset2D[k*2+1]*range;
      TILE* tile2 = mapTileGet(map,i2,j2);
      if(tile2)
      {
       if(tile2->value) nearbyGrid[k] = 1;
       else nearbyGrid[k] = 0;
      }
      else error("B");
     }
     if(!nearbyGrid[0] && !nearbyGrid[2] && nearbyGrid[4]) tile->jpsType |= (1<<4);
     if(!nearbyGrid[0] && !nearbyGrid[3] && nearbyGrid[5]) tile->jpsType |= (1<<5);
     if(!nearbyGrid[1] && !nearbyGrid[2] && nearbyGrid[7]) tile->jpsType |= (1<<6);
     if(!nearbyGrid[1] && !nearbyGrid[3] && nearbyGrid[6]) tile->jpsType |= (1<<7);
     if(tile->jpsType)
     {
      tile->flags |= (1<<0);
      map->JPSTileList = listAdd(map->JPSTileList,tile);
     }
    }
   }
  }
 }
}


int mapTraceDo(MAP* map, int *posFrom, int *posTo, int mode)
{
 int dx = abs(posTo[0] - posFrom[0]);
 int dy = abs(posTo[1] - posFrom[1]);
 int x = posFrom[0];
 int y = posFrom[1];
 int n = 1 + dx + dy;
 int x_inc = (posTo[0] > posFrom[0])*2-1;
 int y_inc = (posTo[1] > posFrom[1])*2-1;
 int derror = dx - dy;
 dx *= 2;
 dy *= 2;
 for (; n > 0; --n)
 {
  TILE* tile = mapTileGet(map,x,y);
  if(!tile) printf("mapTraceDo: no tile at (%d,%d)!",x,y);
  if(tile->value) return 1;

  if (derror > 0)
  {
   x += x_inc;
   derror -= dy;
  }
  else
  {
   y += y_inc;
   derror += dx;
  }
 }
 return 0;
}

var mapTileCostCalculate(MAP* map, TILE* tile1, TILE* tile2)
{
 return vec_length(vector(abs(tile1->pos[0]-tile2->pos[0]),abs(tile1->pos[1]-tile2->pos[1]),0));
}

void mapTileCalculateVisibilityForTile(MAP* map, TILE* sourceTile)
{
 mapTileFreeNeighborData(map,sourceTile);

 LIST* listCurrent = map->JPSTileList;
 while(listCurrent)
 {
  TILE* tile = (TILE*)listCurrent->data;
  if(tile != sourceTile)
  {
   if(!mapTraceDo(map,sourceTile->pos,tile->pos,0))
   {
    sourceTile->neighborList = listAdd(sourceTile->neighborList,tile);
    sourceTile->numNeighbors++;
   }
  }
  listCurrent = listCurrent->next;
 }

 if(sourceTile->numNeighbors > 0)
 {
  sourceTile->neighborCost = (int*)sys_malloc(((int)_sizeof(int))*sourceTile->numNeighbors);
  int i = 0;
  listCurrent = sourceTile->neighborList;
  while(listCurrent)
  {
   TILE* tile = (TILE*)listCurrent->data;

   (sourceTile->neighborCost)[i] = mapTileCostCalculate(map,tile,sourceTile);

   i++;
   listCurrent = listCurrent->next;
  }
  if(i != sourceTile->numNeighbors) error("mapTileCalculateVisibilityForTile: mega error!");
 }
}


void mapTileCalculateVisibility(MAP* map)
{
 LIST* listCurrent;
 listCurrent = map->JPSTileList;
 while(listCurrent)
 {
  TILE* tile = (TILE*)listCurrent->data;
  mapTileCalculateVisibilityForTile(map, tile);
  listCurrent = listCurrent->next;
 }
}



int mapJPSPathGet(MAP* map, TILE* startTile, TILE *targetTile, JPSPATH *jpsPathOut)
{
 dtimer();




 if(jpsPathOut)
 {
  jpsPathOut->length = 0;
  jpsPathOut->currentNode = -1;
  jpsPathOut->startTile = startTile;
  jpsPathOut->targetTile = targetTile;
 }
 JPSPATH *jpsPath = map->jpsPath;
 int i;
 for(i = 0; i < jpsPath->length; i++)
 {
  TILE* tile = (jpsPath->tiles)[i];
  tileResetJPSData(tile);
 }
 jpsPath->length = 0;
 jpsPath->startTile = startTile;
 jpsPath->targetTile = targetTile;

 LIST* listCurrent = map->JPSTileList;
 while(listCurrent)
 {
  TILE* tile = (TILE*)listCurrent->data;
  tileResetJPSData(tile);
  listCurrent = listCurrent->next;
 }
 if(!startTile || !targetTile) return 0;




 if(!mapTraceDo(map,startTile->pos,targetTile->pos,0))
 {
  targetTile->currentCost = mapTileCostCalculate(map,startTile,targetTile);

  dJPSTime = dtimer();
  cdiag(_chr("->END(target visible from start)"));
  return 0;
 }




 startTile->currentCost = 0;
 startTile->totalCost = 0;
 targetTile->targetCost = 0;
 targetTile->targetReachable = 1;
 targetTile->currentCost = 9999;

 if(!targetTile->jpsType || 1)
 {
  LIST* listCurrent = map->JPSTileList;
  while(listCurrent)
  {
   TILE* tile = (TILE*)listCurrent->data;
   if(tile != targetTile)
   {

    tile->targetCost = mapTileCostCalculate(map,tile,targetTile);
    tile->totalCost = tile->currentCost+tile->targetCost;
    tile->targetReachable = !mapTraceDo(map,targetTile->pos,tile->pos,0);



   }
   listCurrent = listCurrent->next;
  }
 }




 LIST* listActive = 0;
 if(!startTile->jpsType)
 {
  LIST* listCurrent = map->JPSTileList;
  while(listCurrent)
  {
   TILE* tile = (TILE*)listCurrent->data;

   if(!mapTraceDo(map,startTile->pos,tile->pos,0))
   {
    tile->currentCost = mapTileCostCalculate(map,tile,startTile);
    tile->totalCost = tile->currentCost+tile->targetCost;
    tile->prev = startTile;
    listActive = listAddTileSorted(listActive,tile,0);



   }

   listCurrent = listCurrent->next;
  }
 }
 else listActive = listAdd(0,startTile);






 while(listActive)
 {
  TILE* tile = (TILE*)listActive->data;
  LIST *prev = listActive;
  listActive = listActive->next;
  sys_free(prev);

  if(tile == targetTile) break;
  if(tile->targetReachable && !key_f)
  {
   int newCost = tile->currentCost+tile->targetCost;
   if(newCost < targetTile->currentCost)
   {
    targetTile->prev = tile;
    targetTile->currentCost = newCost;
    targetTile->totalCost = targetTile->currentCost;
    listActive = listAddTileSorted(listActive,targetTile,1);
   }
  }
  int i = 0;
  LIST* neighborList = tile->neighborList;
  while(neighborList)
  {

   TILE* tile2 = (TILE*)neighborList->data;

   int newCost = tile->currentCost+(tile->neighborCost)[i];
   if(newCost < tile2->currentCost)
   {
    tile2->prev = tile;
    tile2->currentCost = newCost;
    tile2->totalCost = tile2->currentCost+tile2->targetCost;
    listActive = listAddTileSorted(listActive,tile2,1);
   }


   i++;
   neighborList = neighborList->next;
  }
 }




 TILE* current = targetTile;
 while(current && jpsPath->length < jpsPath->maxLength)
 {
  current->flags |= (1<<1);
  (jpsPath->tiles)[jpsPath->length++] = current;
  if(jpsPathOut)
  {
   if(jpsPathOut->length < jpsPathOut->maxLength) (jpsPathOut->tiles)[jpsPathOut->length++] = current;
  }
  if(current == startTile) break;
  current = current->prev;
 }
 if(jpsPathOut) jpsPathOut->currentNode = jpsPathOut->length - 1;

 listDestroy(listActive, (1<<0));
 dJPSTime = dtimer();




 return jpsPath->length;
}

void mapJPSUpdate(MAP* map)
{

 mapJPSDo(map);

 mapTileCalculateVisibility(map);
}

void presetsInit()
{

 UNIT_PRESET* unitPreset = &unitPresets[0];

 unitPreset->ID = 0;
 unitPreset->maxSpeed = 0.125;
 unitPreset->maxHP = 100;
 unitPreset->radius = 0.2;


 UNIT_PRESET* unitPreset = &unitPresets[1];
 unitPreset->ID = 0;
 unitPreset->maxSpeed = 0.1;
 unitPreset->maxHP = 100;
 unitPreset->radius = 0.15;

  UNIT_PRESET* unitPreset = &unitPresets[2];
 unitPreset->ID = 0;
 unitPreset->maxSpeed = 0.175;
 unitPreset->maxHP = 100;
 unitPreset->radius = 0.175;

  UNIT_PRESET* unitPreset = &unitPresets[3];
 unitPreset->ID = 0;
 unitPreset->maxSpeed = 0.135;
 unitPreset->maxHP = 100;
 unitPreset->radius = 0.175;

}

VECTOR* mapGetVectorFromTile(MAP* map, VECTOR* v, TILE* tile)
{
 if(!tile) error("you called mapGetVectorFromTile with a NULL tile, probably because of mapGetTile and bad indices!");
 static VECTOR _vstatic;
 if(!v) v = &_vstatic;
 v->x = (tile->pos[0]+0.5)*map->tileSize + map->vMin.x;
 v->y = (tile->pos[1]+0.5)*map->tileSize + map->vMin.y;
 v->z = 0.5*map->tileSize;
 return v;
}

VECTOR* mapGetVector2DFromVector3D(MAP* map, VECTOR* v2d, VECTOR* v3d)
{
 static VECTOR _vstatic;
 if(!v2d) v2d = &_vstatic;
 v2d->x = (v3d->x-map->vMin.x)/map->tileSize;
 v2d->y = (v3d->y-map->vMin.y)/map->tileSize;
 v2d->z = 0;
 return v2d;
}


VECTOR* mapGetVector3DFromVector2D(MAP* map, VECTOR* v3d, VECTOR* v2d)
{
 static VECTOR _vstatic;
 if(!v3d) v3d = &_vstatic;
 v3d->x = v2d->x*map->tileSize + map->vMin.x;
 v3d->y = v2d->y*map->tileSize + map->vMin.y;

 return v3d;
}

TILE* mapGetTileFromVector(MAP* map, VECTOR* v)
{
 int i = (v->x-map->vMin.x)/map->tileSize;
 int j = (v->y-map->vMin.y)/map->tileSize;
 return mapTileGet(map, i, j);
}


void mapUpdateUnits(MAP* map)
{
 int currentPlayer;
 int i,j;
 for(i = 1; i < map->size[0]-1; i++)
 {
  for(j = 1; j < map->size[1]-1; j++)
  {
   TILE* tile = mapTileGet(map,i,j);





   for(currentPlayer = 0; currentPlayer < 2; currentPlayer++)
   tile->numUnits[currentPlayer] = 0;
  }
 }

 for(currentPlayer = 0; currentPlayer < 2; currentPlayer++)
 {
  UNIT *unit = map->unitFirst[currentPlayer];
  while(unit)
  {
   TILE* tile = mapTileGet(map, unit->pos2d.x, unit->pos2d.y);
   if(tile)
   {
    if(tile->numUnits[currentPlayer] < 16)
    {
     tile->unitArray[tile->numUnits[currentPlayer]] = unit;
     tile->numUnits[currentPlayer]++;
    }
   }
   if(unit->tile) unit->prevTile = unit->tile;
   unit->tile = tile;
   unit = unit->next;
  }
 }
}

int mapGetNearbyUnits(MAP* map, TILE* sourceTile, int range)
{
 pointerArrayNum = 0;
 if(!sourceTile) return 0;
 int i,j;
 for(i = sourceTile->pos[0]-range; i <= sourceTile->pos[0]+range; i++)
 {
  for(j = sourceTile->pos[1]-range; j <= sourceTile->pos[1]+range; j++)
  {
   TILE* tile = mapTileGet(map, i, j);
   if(tile)
   {
    int k;
    int currentPlayer;
    for(currentPlayer = 0; currentPlayer<2; ++currentPlayer)
    {
     for(k = 0; k < tile->numUnits[currentPlayer]; k++)
     {
      pointerArray[pointerArrayNum++] = tile->unitArray[k];
      if(pointerArrayNum >= 1024) return pointerArrayNum;
     }
    }
   }
  }
 }
 return pointerArrayNum;
}

int unit_getType(ENTITY* ent);



int mapGetNearbyUnitsOfTypeForPos(VECTOR *vpos, int typeID, int owner, var maxDistance, int maxNumEntities)
{
 MAP* map = mapGetCurrent();
 TILE* sourceTile = mapGetTileFromVector(map, vpos);
 pointerArrayNum = 0;
 if(!sourceTile) return 0;
 int range = 1+maxDistance/map->tileSize;
 int ownerMin = 0;
 int ownerMax = 1;
 int currentPlayer;


 if(owner == 0) currentPlayer = 1;
 if(owner == 1) currentPlayer = 0;

 int i,j;
 for(i = sourceTile->pos[0]-range; i <= sourceTile->pos[0]+range; i++)
 {
  for(j = sourceTile->pos[1]-range; j <= sourceTile->pos[1]+range; j++)
  {
   TILE* tile = mapTileGet(map, i, j);
   if(tile)
   {
    if (fow_isVisible(tile))

    {
     int k;
     for(k = 0; k < tile->numUnits[currentPlayer]; k++)
     {
      UNIT* unit = tile->unitArray[k];
      ENTITY* ent = unit->ent;
      if(ent)
      {

       if(typeID < 0 || typeID == unit_getType(ent) && ent->skill[52] > 0 )
       {
        pointerArray[pointerArrayNum++] = tile->unitArray[k];
        if(pointerArrayNum >= 1024 || pointerArrayNum >= maxNumEntities) return pointerArrayNum;
       }
      }
     }
    }
   }
  }
 }
 return pointerArrayNum;
}


int mapIsAnyUnitNearby(MAP* map, TILE* sourceTile, int range)
{
 if(!sourceTile) return 0;
 int i,j;
 for(i = sourceTile->pos[0]-range; i <= sourceTile->pos[0]+range; i++)
 {
  for(j = sourceTile->pos[1]-range; j <= sourceTile->pos[1]+range; j++)
  {
   TILE* tile = mapTileGet(map, i, j);
   int currentPlayer;
   if(tile)
   for(currentPlayer = 0; currentPlayer<2; ++currentPlayer)
   if(tile->numUnits[currentPlayer]) return 1;
  }
 }
 return 0;
}


int mapIsAnyFriendlyUnitNearby(MAP* map, TILE* sourceTile, int range, int playerNumber)
{
 if(!sourceTile) return 0;
 VECTOR pos;
 mapGetVectorFromTile(map, &pos, sourceTile);
 int iRange = floor(range / map->tileSize + 0.5);
 int i,j;
 for(i = sourceTile->pos[0]-iRange; i <= sourceTile->pos[0]+iRange; i++)
 {
  for(j = sourceTile->pos[1]-iRange; j <= sourceTile->pos[1]+iRange; j++)
  {
   TILE* tile = mapTileGet(map, i, j);

   int currentPlayer;
   if(tile) {
    VECTOR otherPos;
    mapGetVectorFromTile(map, &otherPos, tile);

    if(vec_dist(pos, &otherPos) > range)
    continue;
    if(tile->numUnits[playerNumber]) return 1;
   }
  }
 }
 return 0;
}

VECTOR* unitFlockingSpeedGet(MAP* map, UNIT* unit, VECTOR* v)
{
 static VECTOR _vstatic;
 if(!v) v = &_vstatic;

 UNIT_PRESET* unitPreset = &unitPresets[unit->presetID];
 vec_set(v, nullvector);



 int numNeighbors = mapGetNearbyUnits(map, unit->tile, 1);
 int i;
 for(i = 0; i < numNeighbors; i++)
 {
  UNIT* neighbor = (UNIT*)pointerArray[i];
  int size = 12;
  int unitDrawSize = 2;


  UNIT_PRESET* neighborPreset = &unitPresets[neighbor->presetID];
  VECTOR vDir;
  vec_diff(vDir, unit->pos2d, neighbor->pos2d);
  var length = vec_length(vDir);
  var range = 2*(unitPreset->radius + neighborPreset->radius);

  if(length < range)
  {
   vec_normalize(vDir, (range-length)/range);
   vec_add(v, vDir);
  }

 }


 return v;
}

int sphereBoxCollision(VECTOR* spherePos2D, VECTOR* vSpeed, float sphereRadius, float boxMinX, float boxMinY, float boxMaxX, float boxMaxY)
{
 VECTOR pbox;



 float midX = (boxMinX+boxMaxX)*0.5;
 float midY = (boxMinY+boxMaxY)*0.5;
 VECTOR vMid;
 vMid.x = midX;
 vMid.y = midY;
 vMid.z = 0;







 float tolerance = 0;
 int caseA = 0;
 int caseB = 0;
 if(spherePos2D->x < boxMinX) pbox.x = boxMinX-tolerance;
 else
 {
  if(spherePos2D->x > boxMaxX) pbox.x = boxMaxX+tolerance;
  else
  {
   pbox.x = spherePos2D->x;
   caseA = 1;
  }
 }
 if(spherePos2D->y < boxMinY) pbox.y = boxMinY-tolerance;
 else
 {
  if(spherePos2D->y > boxMaxY) pbox.y = boxMaxY+tolerance;
  else
  {
   pbox.y = spherePos2D->y;
   caseB = 1;
  }
 }
 int sphereIsInBox = caseA*caseB;
 if(sphereIsInBox)
 {
  if(spherePos2D->x < midX) pbox.x = boxMinX;
  else pbox.x = boxMaxX;
  if(spherePos2D->y < midY) pbox.y = boxMinY;
  else pbox.y = boxMaxY;
 }
 int size = 12;
 int unitDrawSize = 2;
 if(sphereIsInBox)
 {
  unitDrawSize *= 2;

  vec_set(spherePos2D, pbox);
# 973 "src/jps.c"
 }

 {

  VECTOR delta;
  vec_diff(delta, spherePos2D, pbox);
  float len = vec_length(delta);
  if(len < 0.025) vec_sub(delta,vSpeed);
  if(len < sphereRadius)
  {






   VECTOR vCorrection;
   vec_set(vCorrection, delta);
   vec_normalize(vCorrection, sphereRadius-len);
   vec_add(spherePos2D, vCorrection);


   return 1;
  }
 }
 return 0;
}

int unitMoveWithCollision(MAP* map, UNIT* unit, VECTOR *vSpeed)
{
 if(!unit->tile)
 {
  vec_add(unit->pos2d, vSpeed);
  return -1;
 }
 VECTOR prevPos;
 vec_set(prevPos, unit->pos2d);
 vec_add(unit->pos2d, vSpeed);



 int hitTrue = 0;
 UNIT_PRESET* unitPreset = &unitPresets[unit->presetID];
 TILE* sourceTile = unit->tile;
 int i,j;
# 1029 "src/jps.c"
 for(i = sourceTile->pos[0]-1; i <= sourceTile->pos[0]+1; i++)
 {
  for(j = sourceTile->pos[1]-1; j <= sourceTile->pos[1]+1; j++)
  {
   if(1)
   {
    TILE* tile = mapTileGet(map, i, j);
    if(tile)
    {
     if(tile->value)
     {
      int size = 12;
      int unitDrawSize = 2;

      if(sphereBoxCollision(unit->pos2d, vSpeed, unitPreset->radius, i, j, (i+1), (j+1)))
      {




       hitTrue = 1;

      }

     }
    }
   }
  }
 }


 return hitTrue;
}

void unitMove(MAP* map, UNIT* unit)
{


 VECTOR vDir, currentTarget;
 vec_set(currentTarget, unit->target2d);
 JPSPATH *jpsPath = unit->jpsPath;
 if(jpsPath && unit->tile)
 {
  if(jpsPath->currentNode >= 0 && jpsPath->length > 0)
  {
   TILE* unitTile = unit->tile;
   TILE* nextTile = (jpsPath->tiles)[jpsPath->currentNode];
   if(!nextTile) error("ERROR");

   if(vec_length( vector(unitTile->pos[0]-nextTile->pos[0], unitTile->pos[1]-nextTile->pos[1], 0) ) < 0.25 )
   {
    jpsPath->currentNode--;
    if(jpsPath->currentNode >= 0) nextTile = (jpsPath->tiles)[jpsPath->currentNode];
    else nextTile = 0;
   }
   if(nextTile) vec_set(currentTarget, vector(nextTile->pos[0]+0.5, nextTile->pos[1]+0.5, 0));
  }
 }
 int size = 12;

   UNIT_PRESET* unitPreset = &unitPresets[unit->presetID];
 float maxSpeed = unitPreset->maxSpeed;
 vec_diff(vDir, currentTarget, unit->pos2d);
 vDir.z = 0;
 var length = vec_length(vDir);
 if(length > maxSpeed) vec_normalize(vDir, maxSpeed);
 VECTOR vFlock;
 unitFlockingSpeedGet(map, unit, &vFlock);
 vFlock.z = 0;

 var length = vec_length(vFlock);
 if(length > maxSpeed*4) vec_normalize(vFlock, maxSpeed*4);
 vec_add(vDir, vFlock);
 var length = vec_length(vDir);
 if(length > maxSpeed) vec_normalize(vDir, maxSpeed);
 vec_scale(vDir, time_step);
 if(vDir.z) error("unitMove: vDir.z");
# 1115 "src/jps.c"
 unitMoveWithCollision(map, unit, vDir);
}

void mapMoveUnits(MAP* map)
{
 int currentPlayer;
 for(currentPlayer = 0; currentPlayer < 2; currentPlayer++)
 {
  UNIT* prev = 0;
  UNIT *unit = map->unitFirst[currentPlayer];
  while(unit)
  {
   UNIT* next = unit->next;
   UNIT_PRESET* unitPreset = &unitPresets[unit->presetID];
   vec_set(unit->prevPos3d, unit->pos3d);
   if(unit->allowMovement)
   {
    unitMove(map, unit);
    mapGetVector3DFromVector2D(map, unit->pos3d, unit->pos2d);
    unit->isMoving = (abs(unit->pos3d.x-unit->prevPos3d.x) > 0.025 || abs(unit->pos3d.y-unit->prevPos3d.y) > 0.025);

    prev = unit;
   }
   else
   {
    unit->isMoving = 0;
   }






   unit = next;
  }
 }
}


void jpsGameUpdate(MAP* map)
{
 mapUpdateUnits(map);
 mapMoveUnits(map);
}

void unitInitializeFromPreset(UNIT *unit, int presetID)
{
 if(presetID < 0 || presetID >= 5) error("unitInitializeFromPreset: invalid presetID!");
 unit->presetID = presetID;
 UNIT_PRESET* unitPreset = &unitPresets[unit->presetID];
 unit->HP = unitPreset->maxHP;
}

UNIT* jpsUnitCreate(int playerID, int unitType, ENTITY* ent)
{
 MAP* map = mapGetCurrent();
 if(playerID < 0 || playerID >= 2) error("jpsUnitCreate: bad playerID!");
 UNIT *unit = (UNIT*)sys_malloc(((int)_sizeof(UNIT)));
 memset(unit, 0, ((int)_sizeof(UNIT)));
 unit->ent = ent;
 unit->isActive = 1;
 unit->playerID = playerID;
 mapGetVector2DFromVector3D(map, unit->pos2d, ent->x);
 vec_set(unit->target2d, unit->pos2d);
 vec_set(unit->prevTarget2d, unit->pos2d);
 unitInitializeFromPreset(unit, unitType);
 unit->next = mapCurrent->unitFirst[playerID];
 mapCurrent->unitFirst[playerID] = unit;
 return unit;
}

void jpsUnitDestroy(UNIT* unit)
{
 if(!unit) return;
 if(unit->jpsPath) jpsPathDestroy(unit->jpsPath);
 MAP* map = mapGetCurrent();

 int currentPlayer;
 for(currentPlayer = 0; currentPlayer < 2; currentPlayer++)
 {
  UNIT* prev = 0;
  UNIT *otherUnit = map->unitFirst[currentPlayer];
  while(otherUnit)
  {
   UNIT* next = otherUnit->next;
   if(unit == otherUnit)
   {
    if(prev) prev->next = next;
    else map->unitFirst[currentPlayer] = next;
    sys_free(unit);
    return;
   }
   otherUnit = next;
  }
 }
}

void unitSetTargetFromVector2D(MAP* map, UNIT* unit, VECTOR *vTarget)
{

 if(!unit) return;
 vec_set(unit->target2d, vTarget);
 if(vec_dist(unit->target2d, unit->prevTarget2d) > 0.2)
 {
  vec_set(unit->prevTarget2d, unit->target2d);
  unit->targetTile = mapTileGet(map, vTarget.x, vTarget.y);


  if(!unit->jpsPath) unit->jpsPath = jpsPathCreate(16);
  mapJPSPathGet(map, unit->tile, unit->targetTile, unit->jpsPath);
 }
}

void unitSetTargetFromTile(MAP* map, UNIT* unit, TILE* targetTile)
{
 error("unitSetTargetFromTile: bad function, delete this!");
 vec_set(unit->target2d, vector(targetTile->pos[0]+0.5, targetTile->pos[1]+0.5, 0));
 if(vec_dist(unit->target2d, unit->prevTarget2d) > 0.2)
 {
  vec_set(unit->prevTarget2d, unit->target2d);
  unit->targetTile = targetTile;

  if(!unit->jpsPath) unit->jpsPath = jpsPathCreate(16);
  mapJPSPathGet(map, unit->tile, targetTile, unit->jpsPath);
 }
}

void unitAllSetTargetFromTile(MAP* map, int playerID, TILE* targetTile)
{
 UNIT *unit = map->unitFirst[playerID];
 while(unit)
 {
  unitSetTargetFromTile(map, unit, targetTile);
  unit = unit->next;
 }
}

void mapSaveToFile(MAP* map, char* filename)
{
 var fhandle = file_open_write(filename);
 if(!fhandle) return;
 int mapVersion = 1;
 file_var_write(fhandle, mapVersion);
 file_var_write(fhandle, map->size[0]);
 file_var_write(fhandle, map->size[1]);
 int i,j;
 for(i = 0; i < map->size[0]; i++)
 {
  for(j = 0; j < map->size[1]; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   file_var_write(fhandle, tile->value);
  }
 }
 file_close(fhandle);
}

MATERIAL* jpsDummyNoFilter_mat =
{
 effect = "jpsDummyNoFilter.fx";
 flags = (1<<24);
}

MAP* jpsMapLoadFromFile(char* filename)
{
 var fhandle = file_open_read(filename);
 if(!fhandle) return 0;
 int mapVersion = file_var_read(fhandle);
 int sizeX = file_var_read(fhandle);
 int sizeY = file_var_read(fhandle);
 var tileSize = 64*4;
 MAP* map = mapCreate(sizeX, sizeY, vector(-sizeX/2*tileSize,-sizeY/2*tileSize,0), vector(sizeX/2*tileSize,sizeY/2*tileSize,0), tileSize);
 int i,j;
 for(i = 0; i < map->size[0]; i++)
 {
  for(j = 0; j < map->size[1]; j++)
  {
   TILE* tile = mapTileGet(map,i,j);
   tile->value = file_var_read(fhandle);
  }
 }
 file_close(fhandle);
 mapJPSUpdate(map);
 mapUpdateBmap(map);

 if(0)
 {
  entJPSDummyPlane = ent_create("jpsPlane.mdl", vector(0,0,800), 0);
  entJPSDummyPlane->flags |= ((1<<9) | (1<<10));
  entJPSDummyPlane.flags2 |= (1<<0);
  ent_setskin(entJPSDummyPlane, map->bmp, 1);
  vec_set(entJPSDummyPlane->scale_x, vector(sizeX/64.0*tileSize, sizeY/64.0*tileSize, 0));
  entJPSDummyPlane->material = jpsDummyNoFilter_mat;
 }

 return map;
}

BMAP* mapGetBitmap(MAP* map)
{
 if(!map) map = mapGetCurrent();
 if(!map) return 0;
 return map->bmp;
}

void mapSetTileValueAtPos3D(MAP* map, VECTOR* pos3d, int value)
{
 TILE* tile = mapGetTileFromVector(map, pos3d);
 if(tile) tile->value = value;
}

int mapGetTileValueAtPos3D(MAP* map, VECTOR* pos3d)
{
 TILE* tile = mapGetTileFromVector(map, pos3d);
 if(tile) return tile->value;
 return -1;
}

TILE* mapGetEmptyTileForAI(MAP* map, int freeBorder)
{
 int ishift = random(map->size[0]);

 int jstart = 2+random(4);
 int i,j;
 for(j = jstart; j < map->size[1]; j++)
 {
  for(i = 0; i < map->size[0]; i++)
  {
   int i2 = (i+ishift)%map->size[0];

   int j2 = j;
   if(i2 >= 3 && i2 < map->size[0]-3 && j2 >= 3 && j2 < map->size[1]-3)
   {
    TILE* tile = mapTileGet(map,i2,j2);
    if(!tile->value)
    {
     int tileOkay = 8;
     if(freeBorder)
     {
      tileOkay = 0;
      int i3,j3;
      for(i3 = -1; i3 <= 1; i3++)
      {
       for(j3 = -1; j3 <= 1; j3++)
       {
        if(i3 || j3)
        {
         int i4 = i3+i2;
         int j4 = j3+j2;
         TILE* tile2 = mapTileGet(map,i4,j4);
         if(tile2)
         {
          if(!tile2->value) tileOkay++;
         }
        }
       }
      }
     }
     if(tileOkay == 8) return tile;
    }
   }
  }
 }
 return 0;
}
# 54 "main.c" 2
# 1 "src/fow.c" 1




bool fow_killparticles = 0;





TILE **fow_borderCells;
int fow_borderCells_IDX;


BMAP* FogBmap = "fow_fog2.png";
int fow_lightningX[] = {-100,-100,-100};
int fow_lightningY[] = {-100,-100,-100};
int fow_numLigntnings = 0;
void FogEvent(PARTICLE *p)
{
    if(fow_killparticles) {
        p->lifespan = 0;
        return;
    }

    p.lifespan = 2;
    p.x = p.skill[0] + cosv(p->skill[2]*total_ticks)*100+(p.skill[0]%100);
    p.y = p.skill[1] + cosv(p->skill[3]*total_ticks)*100+(p.skill[1]%100);


 MAP *map = mapGetCurrent();
 TILE *tile = mapGetTileFromVector(map, vector(p->skill[0], p->skill[1], 0));

    if(fow_isVisible(tile))
 {
  p->alpha -= 10*time_step;
  if(p->alpha <= 0)
   p.lifespan = 0;
 }
 else
 {
  p.flags &= ~(1<<21);
  int i;
  for(i=0; i<fow_numLigntnings; ++i)
  {
   VECTOR dist;
   dist.x = tile->pos[0]-fow_lightningX[i];
   dist.y = tile->pos[1]-fow_lightningY[i];
   dist.z = 0;
   if(vec_length(&dist)<2.5)
    p.flags |= (1<<21);
  }

 }

}

void Fog(PARTICLE *p)
{
    p.bmap = FogBmap;
    p.alpha = 90;
    p.gravity = 0;
    p.size = 600;

    var cRand = random(0.3)+0.5;
    p.red = cRand * 255;
    p.green = cRand * 255;
    p.blue = cRand * 255;

    p.flags |= ((1<<11) | (1<<10));
    p.event = FogEvent;

    p.skill[0] = p.x;
    p.skill[1] = p.y;

    p->skill[2] = random(0.5)+0.5;
    p->skill[3] = random(0.5)+0.5;
}

bool fow_hasDirectLOS(MAP *map, VECTOR* t1, VECTOR *t2)
{
 VECTOR tp1, tp2;



 vec_set(&tp1, t1);
 vec_set(&tp2, t2);

 tp1.z += 300;
 tp2.z += 300;
 if(maploader_trace(&tp1, &tp2) == 0)
  return 1;
 return 0;
}

int fow_isTileInLOS(MAP* map, TILE* sourceTile, int range, int playerNumber)
{
 if(!sourceTile) return 0;
 VECTOR pos;
 mapGetVectorFromTile(map, &pos, sourceTile);
 int iRange = floor(range / map->tileSize + 0.5);
 int i,j;
 for(i = sourceTile->pos[0]-iRange; i <= sourceTile->pos[0]+iRange; i++)
 {
  for(j = sourceTile->pos[1]-iRange; j <= sourceTile->pos[1]+iRange; j++)
  {
   TILE* tile = mapTileGet(map, i, j);

   int currentPlayer;
   if(!tile)
    continue;

   VECTOR otherPos;
   mapGetVectorFromTile(map, &otherPos, tile);
   if(vec_dist(pos, &otherPos) > range)
    continue;

   if(!tile->numUnits[playerNumber])
    continue;
   if(fow_hasDirectLOS(map, &pos, &otherPos))
    return 1;
  }
 }
 return 0;
}


void fow_open()
{
    fow_killparticles = 0;

 MAP *map = mapGetCurrent();

 fow_borderCells = sys_malloc(((int)_sizeof(TILE*))*map->size[0]*map->size[1]);
 fow_borderCells_IDX = 0;

 int x, y;
 for(x = 0; x<map->size[0]; ++x)
  for(y = 0; y<map->size[1]; ++y)
  {
   TILE *tile = mapTileGet(map, x,y);
   VECTOR pos;
   mapGetVectorFromTile(map, &pos, tile);
   pos.z = 550;

   tile->visibility = 1;
   if(!tile->value)
             effect(Fog, 1, pos, nullvector);
  }

}


void fow_setBorder(TILE *tile)
{
 if(tile == 0)
  return;
 if(fow_isVisible(tile))
  return;
 if(tile->visibility & 2)
  return;

 tile->visibility |= 2;´
 fow_borderCells[fow_borderCells_IDX] = tile;
 fow_borderCells_IDX++;
}

void fov_uncoverTile(TILE *tile)
{
 if(tile->visibility & 2)
 {
  int i;
  for(i=0; i<fow_borderCells_IDX; ++i)
   if(fow_borderCells[i] == tile)
   {

    fow_borderCells[i] = fow_borderCells[fow_borderCells_IDX-1];

    fow_borderCells_IDX--;
    break;
   }
 }

 tile->visibility &= ~(1 | 2);

 MAP *map = mapGetCurrent();
 int x = tile->pos[0];
 int y = tile->pos[1];

 fow_setBorder(mapTileGet(map, x+1, y));
 fow_setBorder(mapTileGet(map, x-1, y));
 fow_setBorder(mapTileGet(map, x, y+1));
 fow_setBorder(mapTileGet(map, x, y-1));
}

bool fow_isVisible(TILE *tile)
{
 return !(tile->visibility & 1);
}

bool fow_isPosVisible(VECTOR *pos)
{
 MAP *map = mapGetCurrent();
 TILE *tile = mapGetTileFromVector(map, pos);
 if(!tile)
  return 0;
 return fow_isVisible(tile);
}


void fov_uncover(VECTOR *pos, var range)
{
 MAP *map = mapGetCurrent();
 TILE *tile = mapGetTileFromVector(map, pos);

 int iRange = floor(range / map->tileSize + 0.5);

 int i,j;
 for(i = tile->pos[0]-iRange; i <= tile->pos[0]+iRange; i++)
  for(j = tile->pos[1]-iRange; j <= tile->pos[1]+iRange; j++)
  {
   TILE *otherTile = mapTileGet(map, i, j);
   if(!otherTile)
    continue;

   VECTOR otherPos;
   mapGetVectorFromTile(map, &otherPos, otherTile);

   if(vec_dist(pos, &otherPos) > range)
    continue;

   if(fow_hasDirectLOS(map, pos, &otherPos))
    fov_uncoverTile(otherTile);
  }
}


int fow_loadbalancingIDX = 0;
int fow_loadbalancingFactor = 1;
var fow_lightningDuration = 2.0;
void fow_update()
{

 MAP *map = mapGetCurrent();

 int mapSize = map->size[0]*map->size[1];
 int i;

 if(key_f3)
 {
  for(i = 0; i< mapSize; ++i)
  {
   fov_uncoverTile(&((map->tiles)[i]));
  }
 }

 fow_lightningDuration -= time_step;
 if(fow_lightningDuration <= 0)
 {
        fow_lightningDuration = 2.0;
  fow_numLigntnings = random(3);
  for(i=0; i<fow_numLigntnings; ++i)
  {
   fow_lightningX[i] = (int)random(map->size[0]);
   fow_lightningY[i] = (int)random(map->size[1]);
  }
 }


 for(i = fow_loadbalancingIDX; i< fow_borderCells_IDX; i = i+fow_loadbalancingFactor)
 {
  TILE *tile = fow_borderCells[i];
  if(!fow_isVisible(tile))
   if(fow_isTileInLOS(map, tile, 1500, 0))
    fov_uncoverTile(tile);
 }
# 289 "src/fow.c"
 fow_loadbalancingIDX = (fow_loadbalancingIDX+1)%fow_loadbalancingFactor;

}

void fow_close()
{
 fow_killparticles = 1;
 if(fow_borderCells)
  sys_free(fow_borderCells);
}
# 55 "main.c" 2
# 1 "src/progressbars.c" 1


MATERIAL * progressbar_radial_mtl =
{
    effect = "progress-radial.fx";
    flags = (1<<24);
}

void progressbar_radial_render(BMAP *_target, var progress, var radius, COLOR *color, var alpha)
{
    progressbar_radial_mtl->skill[0] = floatv(color.red);
    progressbar_radial_mtl->skill[1] = floatv(color.green);
    progressbar_radial_mtl->skill[2] = floatv(color.blue);
    progressbar_radial_mtl->skill[3] = floatv(alpha / 100.0);
    progressbar_radial_mtl->skill[4] = floatv(progress / 100.0);
    progressbar_radial_mtl->skill[5] = floatv(radius / 100.0);
    bmap_process(_target, 0, progressbar_radial_mtl);
}
# 56 "main.c" 2
# 1 "src/z.c" 1




# 1 "src/materials.h" 1
# 1 "src/mainmenu.c" 1




void mainmenu_init(void)
{

 mainmenu_wndMenuBackground = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackground->_forced_background = mainmenu_background;
 mainmenu_wndMenuBackgroundBright = uimenu_window_create_borderless(0, 0, 1920, 1080);
 mainmenu_wndMenuBackgroundBright->_forced_background = mainmenu_background_bright;

 mainmenu_wndMenuMain = uimenu_window_create_borderless(0, 0, 1920, 1080);

 int btnHeight = bmap_height(mainmenu_btn_new_game);
 mainmenu_btnNewGame = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_new_game) / 2), 300 + (btnHeight * 0), 128, 32, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_btn_new_game, mainmenu_set_start);
 mainmenu_btnOptions = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_options) / 2), 300 + (btnHeight * 1), 128, 32, mainmenu_btn_options, mainmenu_btn_options, mainmenu_btn_options, mainmenu_show_options);
 mainmenu_btnCredits = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_credits) / 2), 300 + (btnHeight * 2), 128, 32, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_btn_credits, mainmenu_set_credits);
 mainmenu_btnExit = uimenu_make_button( (1920 / 2) - (bmap_width(mainmenu_btn_exit) / 2), 300 + (btnHeight * 4), 128, 32, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_btn_exit, mainmenu_set_exit);

 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnNewGame);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnOptions);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnCredits);
 uimenu_add_element_to_window(mainmenu_wndMenuMain, mainmenu_btnExit);

 uimenu_window_initialize(mainmenu_wndMenuMain);
 uimenu_window_initialize(mainmenu_wndMenuBackground);
 uimenu_window_initialize(mainmenu_wndMenuBackgroundBright);

 mainmenu_resolution_update();


 mainmenu_wndMenuOptions = uimenu_window_create( (screen_size.x / 2) - (640 / 2), (screen_size.y / 2) - (480 / 2), 640, 480, "Options");
 uimenu_element_t * optionsExit = uimenu_make_simple_button(640 - 90, 480 - 23, 85, 23, "OK", uimenu_default_font, mainmenu_hide_options);

 uimenu_element_t * optionsTabGeneral = uimenu_make_simple_button(0, 0, 23, "General", uimenu_default_font, mainmenu_show_options_general);
 uimenu_element_t * optionsTabVideo = uimenu_make_simple_button(optionsTabGeneral->x + optionsTabGeneral->width + 2, 0, 23, "Video", uimenu_default_font, mainmenu_show_options_video);
 uimenu_element_t * optionsTabAudio = uimenu_make_simple_button(optionsTabVideo->x + optionsTabVideo->width + 2, 0, 23, "Audio", uimenu_default_font, mainmenu_show_options_audio);
 uimenu_element_t * optionsTabControls = uimenu_make_simple_button(optionsTabAudio->x + optionsTabAudio->width + 2, 0, 23, "Controls", uimenu_default_font, mainmenu_show_options_controls);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsExit);

 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabGeneral);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabVideo);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabAudio);
 uimenu_add_element_to_window(mainmenu_wndMenuOptions, optionsTabControls);

 uimenu_window_initialize(mainmenu_wndMenuOptions);


 mainmenu_wndMenuOptionsGeneral = uimenu_window_create_borderless(0, 32, 640 - 8, 380);

 uimenu_element_t * generalInfo = uimenu_make_text(5, 5, 100, 32, "Nothing to see here", 0, 0);

 uimenu_add_element_to_window(mainmenu_wndMenuOptionsGeneral, generalInfo);

 uimenu_slave_window_to_window(mainmenu_wndMenuOptions, mainmenu_wndMenuOptionsGeneral);

 uimenu_window_initialize(mainmenu_wndMenuOptionsGeneral);


 mainmenu_wndMenuBackgroundBright->_panel->flags |= (1<<10);
 mainmenu_wndMenuMain->_panel->flags |= (1<<10);
}


void mainmenu_set_start(void)
{
 mainmenu_current_response = 1;
}

void mainmenu_show_options_general(void)
{
 uimenu_window_show(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_video(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_show(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_audio(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_show(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_show_options_controls(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_show(mainmenu_wndMenuOptionsControls);
}


void mainmenu_show_options(void)
{
 uimenu_window_show(mainmenu_wndMenuOptions);
 mainmenu_show_options_general();
}
void mainmenu_hide_options(void)
{
 uimenu_window_hide(mainmenu_wndMenuOptions);
 uimenu_window_hide(mainmenu_wndMenuOptionsGeneral);
 uimenu_window_hide(mainmenu_wndMenuOptionsVideo);
 uimenu_window_hide(mainmenu_wndMenuOptionsAudio);
 uimenu_window_hide(mainmenu_wndMenuOptionsControls);
}

void mainmenu_set_credits(void)
{
 mainmenu_current_response = 2;
}
void mainmenu_set_exit(void)
{
 mainmenu_current_response = 3;
}

void mainmenu_open(void)
{
    mainmenu_current_response = 0;
 music_speedup(100);
 music_start("media/mainmenu.mp3", 0.5, 0);
 uimenu_window_show(mainmenu_wndMenuMain);
 uimenu_window_show(mainmenu_wndMenuBackground);
 uimenu_window_show(mainmenu_wndMenuBackgroundBright);
}

void mainmenu_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  if(mainmenu_wndMenuMain->_is_visible)
  {
   if(total_secs == mainmenu_buzz_wait_time)
   {
    var alpha = 25 + random(75);
    mainmenu_wndMenuMain->_panel->alpha = alpha;
    mainmenu_wndMenuBackgroundBright->_panel->alpha = alpha;
    mainmenu_buzz_handle = snd_play(mainmenu_buzz, alpha, 0);
    snd_tune(mainmenu_buzz_handle, alpha, 100 - (alpha / 10), 0);
    mainmenu_wndMenuMain->_content_panel->scale_x = mainmenu_wndMenuBackground->_content_panel->scale_x * (1 + (random(1) / 100));
    mainmenu_wndMenuMain->_content_panel->scale_y = mainmenu_wndMenuBackground->_content_panel->scale_y * (1 + (random(1) / 100));
   }

   if(total_secs > mainmenu_buzz_wait_time)
   {
    mainmenu_buzz_wait_time = total_secs + integer(random(8));
    mainmenu_resolution_update();
   }
  }
 }
}

void mainmenu_resolution_update(void)
{
 if(mainmenu_wndMenuMain != 0)
 {
  mainmenu_wndMenuMain->_content_panel->scale_x =
  mainmenu_wndMenuBackground->_content_panel->scale_x =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_x =
  screen_size.x / 1920;

  mainmenu_wndMenuMain->_content_panel->scale_y =
  mainmenu_wndMenuBackground->_content_panel->scale_y =
  mainmenu_wndMenuBackgroundBright->_content_panel->scale_y =
  screen_size.y / 1080;
 }
}

void mainmenu_close(void)
{
 uimenu_window_destroy(mainmenu_wndMenuBackground);
 uimenu_window_destroy(mainmenu_wndMenuBackgroundBright);
 uimenu_window_destroy(mainmenu_wndMenuMain);
}

int mainmenu_get_response()
{
 return mainmenu_current_response;
}
# 2 "src/materials.h" 2
# 6 "src/z.c" 2







SOUND* z_collect_snd = "z_collect.wav";
var z_amount[2];

var z_get(var owner)
{
 return z_amount[clamp(owner,0,1)];
}


bool z_isSufficient(var amount, var owner)
{
 return (amount <= z_amount[clamp(owner,0,1)]);
}

bool z_pay(var amount, var owner)
{
 if(amount > z_amount[clamp(owner,0,1)])
  return 0;
 z_amount[clamp(owner,0,1)] -= amount;
 return 1;
}

ENTITY* z_findNear(VECTOR* pos, var maxdist)
{
 ENTITY *zUnit, *zUnitNear = 0;
 var minDist = maxdist;
 for(zUnit = ent_next(0); zUnit != 0; zUnit = ent_next(zUnit)) if(zUnit->skill[98] == (107))
 {
  MAP *map = mapGetCurrent();
  VECTOR zPos;
  vec_set(&zPos, &zUnit->x);
  vec_sub(&zPos, pos);
  if(vec_length(&zPos) < minDist)
  {
   TILE *tile = mapGetTileFromVector(map, &zUnit->x);

   if(fow_isVisible(tile))
   {
    zUnitNear = zUnit;
    minDist = vec_length(&zPos);
   }
  }
 }
 return zUnitNear;
}

ENTITY* z_spawn(VECTOR* pos)
{
 ENTITY* ent;
    ent = ent_create("Crystalmeth.mdl", pos, Z);
 ent->group = 14;
 return ent;
}

void Z()
{
 framework_setup(my, 107);
 my->flags |= ((1<<18));
 my->skill[10] = 2.0 + random(2);
 my->pan = random(360);
 vec_set(my->scale_x, vector(my->skill[10] , my->skill[10] , my->skill[10] ));
 c_setminmax(me);
 my->skill[54] = 1;
 my->skill[59] = 4;
 my->material = matCrystals;
 my->skill[20] = 10;
}

void Z_Init()
{
 z_amount[0] = 50;
 z_amount[1] = 50;
}

void Z_Update()
{
 ENTITY * ptr;
 for(ptr = ent_next(0); ptr != 0; ptr = ent_next(ptr)) if(ptr->skill[98] == (107))
 {

  if (ptr->skill[50] > 0 && ptr->skill[54] != 4 && ptr->skill[54] != 5)
      {
        Z__hit(ptr);
  }

  switch(ptr->skill[54])
  {

   case 1:
   {
    Z__wait(ptr);
    break;
   }

   case 4:
   {
    Z__die(ptr);
    break;
   }

   default:
   {
    break;
   }
  }

        ptr->z = maploader_get_height(ptr->x) - ptr->min_z;

 }
}

void Z__hit(ENTITY* ptr)
{
 ENTITY* attacker = ptr_for_handle(ptr->skill[49]);
 z_amount[attacker->skill[53]] += minv(10, ptr->skill[50]*0.2);

 ptr->skill[20] -= ptr->skill[50]*0.2;
 ptr->skill[50] = 0;

 if(ptr->skill[20] <= 0)
 {
  ptr->skill[54] = 4;
  ptr->skill[55] = 100;

  if (num_sounds < 6)
  {
     var hndl = snd_play(z_collect_snd, 50, 0);
     snd_tune(hndl,0,random(10)+95,0);
  }
 }
 else
 ptr->skill[54] = 1;
}

void Z__wait(ENTITY* ptr)
{
    ptr->red = ptr->green = ptr->blue = 100 + (sin(ptr->x + ptr->y + total_ticks * 0.1) * 0.5 + 0.5) * 100.0;
}


void Z__die(ENTITY* ptr)
{
 ptr->skill[55] -= 15 * time_step;
 ptr->scale_x = ptr->skill[10] * maxv(ptr->skill[55], 0) * 0.01;
 ptr->scale_y = ptr->scale_x;


 if(ptr->skill[55] <= 0)
 {
  ptr->skill[54] = 5;
  ptr->flags |= ((1<<9));
  framework_remove(ptr);
 }
}
# 57 "main.c" 2
# 1 "src/effects2d.c" 1





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

    effects2d.animations[0].frame_count = 5;
    effects2d.animations[0].speed = 1;
    effects2d.animations[0].size = 0.5;
    effects2d.animations[0].frames[0] = bmap_create("Cursor1.png");
    effects2d.animations[0].frames[1] = bmap_create("Cursor2.png");
    effects2d.animations[0].frames[2] = bmap_create("Cursor3.png");
    effects2d.animations[0].frames[3] = bmap_create("Cursor4.png");
    effects2d.animations[0].frames[4] = bmap_create("Cursor5.png");


    effects2d.animations[1].frame_count = 4;
    effects2d.animations[1].speed = 0.75;
    effects2d.animations[1].size = 0.5;
    effects2d.animations[1].frames[0] = bmap_create("Attack_C.png");
    effects2d.animations[1].frames[1] = bmap_create("Attack_C1.png");
    effects2d.animations[1].frames[2] = bmap_create("Attack_C2.png");
    effects2d.animations[1].frames[3] = bmap_create("Attack_C3.png");


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
    int i; for(i = 0; i < 50; i++)
        effects2d.particles[i].animation = 0;
}

void effects2d_update()
{
    int i; for(i = 0; i < 50; i++)
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
                0,
                vector(w, h, 0),
                vector(a->size, a->size, 0),
                0,
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
    int i; for(i = 0; i < 50; i++)
    {
        if(effects2d.particles[i].animation != 0)
            continue;

        effects2d.particles[i].animation = type;
        effects2d.particles[i].frame = 0;

        vec_set(&effects2d.particles[i].pos, worldpos);
        break;
    }
}
# 58 "main.c" 2
# 1 "src/ai.c" 1







void ai_reset(int difficulty)
{
 memset(aiSystemInstance, 0, ((int)_sizeof(AI_SYSTEM)));
 aiSystemInstance->difficulty = difficulty;
 aiSystemInstance->money = 10000;
 aiSystemInstance->escalationCounter = 0;
 aiSystemInstance->elapsedTime = 0;
 aiSystemInstance->stepTime = 0;
 aiSystemInstance->unitBuildTimer = -10;
 int i;
 for(i = 0; i < 4; i++) aiSystemInstance->buildingCount[i] = 0;
}

void ai_init(int difficulty)
{
 aiSystemInstance = (AI_SYSTEM*)sys_malloc(((int)_sizeof(AI_SYSTEM)));
 memset(aiSystemInstance, 0, ((int)_sizeof(AI_SYSTEM)));
 ai_reset(difficulty);
}

void ai_spawn_building(int buildingType)
{
 if(aiSystemInstance->buildingCount[buildingType] >= 8) return;
 MAP* map = mapGetCurrent();
 TILE* tile = mapGetEmptyTileForAI(map, 1);
 cdiag(_chr(str_printf(0,"\n ai_spawn_building(%d) at frame %d: tile(%p)",buildingType,(int)total_frames,tile)));
 if(tile)
 {
  aiSystemInstance->entBuildings[buildingType][aiSystemInstance->buildingCount[buildingType]++] = spawner_spawn(0, mapGetVectorFromTile(map, 0, tile), random(360), 1);
 }
}

void ai_spawn_unit(int unitType)
{
 int buildingType = 0;
 if(aiSystemInstance->buildingCount[buildingType] <= 0) return;
 ENTITY* ptr = aiSystemInstance->entBuildings[buildingType][(int)random(aiSystemInstance->buildingCount[buildingType])];


 spawner_produce(ptr);
}

void ai_update()
{
 static int dummyUnitCountForNow = 0;
 if(dummyUnitCountForNow >= 50) return;
 float timeAdd = (1.0+aiSystemInstance->difficulty*0.5)*(float)time_step/16.0;
 aiSystemInstance->elapsedTime += timeAdd;
 if(aiSystemInstance->elapsedTime > aiSystemInstance->stepTime)
 {
  aiSystemInstance->stepTime += 10;
  ai_spawn_building(0);
 }
 aiSystemInstance->unitBuildTimer += timeAdd;
 if(aiSystemInstance->unitBuildTimer > 6)
 {
  aiSystemInstance->unitBuildTimer -= 6;
  ai_spawn_unit(0);
  dummyUnitCountForNow++;
 }
}
# 59 "main.c" 2
# 1 "src/ini.c" 1


# 1 "src/ini.h" 1
# 18 "src/ini.h"
void ini_write(STRING *filename, STRING *section, STRING *entry, STRING *value);
# 27 "src/ini.h"
void ini_write_int(STRING *filename, STRING *section, STRING *entry, int value);
# 36 "src/ini.h"
void ini_write_var(STRING *filename, STRING *section, STRING *entry, var value);
# 45 "src/ini.h"
void ini_write_float(STRING *filename, STRING *section, STRING *entry, float value);







int ini_read_sections(TEXT *txt, STRING *filename);
# 64 "src/ini.h"
int ini_read(STRING *targetValue, STRING *filename, STRING *section, STRING *entry, STRING *defaultValue);
# 74 "src/ini.h"
int ini_read_int(STRING *filename, STRING *section, STRING *entry, int defaultValue);
# 84 "src/ini.h"
float ini_read_float(STRING *filename, STRING *section, STRING *entry, float defaultValue);
# 94 "src/ini.h"
var ini_read_var(STRING *filename, STRING *section, STRING *entry, var defaultValue);

# 1 "src/ini.c" 1


# 1 "src/ini.h" 1
# 4 "src/ini.c" 2

char iniBuffer[2048];

void ini_write(STRING *filename, STRING *section, STRING *entry, STRING *value)
{
 WritePrivateProfileString(_chr(section), _chr(entry), _chr(value), _chr(filename));
}

void ini_write_int(STRING *filename, STRING *section, STRING *entry, int value)
{
 ini_write(filename, section, entry, str_for_int(0, value));
}

void ini_write_var(STRING *filename, STRING *section, STRING *entry, var value)
{
 ini_write(filename, section, entry, str_for_num(0, value));
}

void ini_write_float(STRING *filename, STRING *section, STRING *entry, float value)
{
 ini_write(filename, section, entry, str_for_float(0, value));
}

int ini_read_sections(TEXT *txt, STRING *filename)
{
 int length = GetPrivateProfileString(0, 0, 0, iniBuffer, 2047, _chr(filename));
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
 if(targetValue != 0)
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
# 97 "src/ini.h" 2
# 4 "src/ini.c" 2

char iniBuffer[2048];

void ini_write(STRING *filename, STRING *section, STRING *entry, STRING *value)
{
 WritePrivateProfileString(_chr(section), _chr(entry), _chr(value), _chr(filename));
}

void ini_write_int(STRING *filename, STRING *section, STRING *entry, int value)
{
 ini_write(filename, section, entry, str_for_int(0, value));
}

void ini_write_var(STRING *filename, STRING *section, STRING *entry, var value)
{
 ini_write(filename, section, entry, str_for_num(0, value));
}

void ini_write_float(STRING *filename, STRING *section, STRING *entry, float value)
{
 ini_write(filename, section, entry, str_for_float(0, value));
}

int ini_read_sections(TEXT *txt, STRING *filename)
{
 int length = GetPrivateProfileString(0, 0, 0, iniBuffer, 2047, _chr(filename));
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
 if(targetValue != 0)
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
# 60 "main.c" 2
# 1 "src/settings.c" 1



STRING * settings_file = "settings.ini";




HRESULT SHGetFolderPath(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, LPSTR pszPath);


char settings_path[260];

void settings_init()
{

    if(ExpandEnvironmentStrings("%APPDATA%", settings_path, 260) == 0)
    {
        error("Failed to expand environment variable for settings.");
        return;
    }
    str_cpy(settings_file, settings_path);
    str_cat(settings_file, "\\AckCon");
    CreateDirectory(_chr(settings_file), 0);
    str_cat(settings_file, "\\2019");
    CreateDirectory(_chr(settings_file), 0);
    str_cat(settings_file, "\\settings.ini");

    diag("\nstore settings in ");
    diag(_chr(settings_file));

    settings.enable_shadows = 1;
    settings.enable_bloom = 1;
    settings.res_x = 1280;
    settings.res_y = 720;
    settings.max_framerate = 60;
    settings.master_volume = 100;


    if(!file_exists(settings_file)) {
        settings_save();
    }
}

void settings_load()
{
    if(!file_exists(settings_file)) {
        error("file not found!");
        return;
    }
    settings.enable_bloom = ini_read_int(settings_file, "generic", "bloom", 1);
    settings.enable_shadows = ini_read_int(settings_file, "generic", "shadows", 1);
    settings.max_framerate = ini_read_int(settings_file, "generic", "fps_limit", 60);
    settings.res_x = ini_read_int(settings_file, "resolution", "width", 1280);
    settings.res_y = ini_read_int(settings_file, "resolution", "height", 720);
    settings.master_volume = ini_read_int(settings_file, "volume", "master", 100);
}

void settings_save()
{
    ini_write_int(settings_file, "generic", "bloom", settings.enable_bloom);
    ini_write_int(settings_file, "generic", "shadows", settings.enable_shadows);
    ini_write_int(settings_file, "generic", "fps_limit", settings.max_framerate);
    ini_write_int(settings_file, "resolution", "width", settings.res_x);
    ini_write_int(settings_file, "resolution", "height", settings.res_y);
    ini_write_int(settings_file, "volume", "master", settings.master_volume);
}
# 60 "main.c" 2
