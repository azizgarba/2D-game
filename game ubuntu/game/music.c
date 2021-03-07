Music InitMusic() {
//Init Audio for the Menu
    Music mu;
    int Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    //Loading variables to play as music and chunks

    mu->bg_music = Mix_LoadMUS("MM1.mp3");
    mu->select1 = Mix_LoadMUS("S1.mp3");
    mu->select2 = Mix_LoadMUS("S2.mp3");
    mu->select3 = Mix_LoadMUS("S3.mp3");
    mu->select4 = Mix_LoadMUS("S4.mp3");
    mu->enter = Mix_LoadMUS("E1.mp3");
    //Loading music variables is completed.
    //Init volume
};
