
// 14886
JPSPATH *jpsPathCreate(int maxLength)
{
    JPSPATH *jpsPath = (JPSPATH*)sys_malloc(((int)sizeof(JPSPATH)));
    memset(jpsPath, 0, ((int)sizeof(JPSPATH)));
    jpsPath->maxLength = maxLength;
    jpsPath->tiles = (TILE**)sys_malloc(((int)sizeof(TILE*)) * maxLength);
    //memset(jpsPath->tiles, 0, ((int)sizeof(TILE*)) * maxLength);

    return jpsPath;
}

// 16248
void fow_open()
{
    fow_killparticles = 0;

    MAP *map = mapGetCurrent();

    fow_borderCells = sys_malloc(((int)sizeof(TILE*))*map->size[0]*map->size[1]);
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
