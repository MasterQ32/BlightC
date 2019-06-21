
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
