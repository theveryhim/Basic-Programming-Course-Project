#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void quit();
void offlist(int j,int k);
void startpic(int i,int j);
void homepage();
void homepic(int j);
void aboutpic(int j);
void abouttab();
void settingtab();
void settingpic();
void soundtrack(int i);
void playlist(int i);
void prematch();
void prematchpic();
void result(int r,int l);
void appearance(int appr,int appl);
void mode(int m);
void pause();
void background0(int y1);
void player_r0(double wh,double hh,double xh,double yh,bool hitr,int r,int g,int b);
void player_l0(double wH,double hH,double xH,double yH,bool hitl,int r,int g,int b);
void targets0();
void background1(int y1);
void targets1();
void targets_case(int i,int y1);
void background_case(int i,int y1);
void clock(int i,bool tim);
void match(int m,int appr,int appl);
void player_lcase(double wh,double hh,double xH,double yH,bool hitl,int appl,int m);
void player_rcase(double wh,double hh,double xh,double yh,bool hitr,int appr,int m);
void player_r1(double wh,double hh,double xh,double yh,bool hitr);
void player_l1(double wH,double hH,double xH,double yH,bool hitl);
void start(bool strt);
void result(int r,int l);
void goalr(int r,int l);
void goall(int l,int r);
    int  mus[12]={};
    int vm=20,vs=20;
    bool hitl=false,hitr=false;
    const char*text;
    int minute=0;
    bool tim=false;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Texture* m_img;
    SDL_Event*e;
    Mix_Music*m_mus;
    Mix_Chunk*ch0;
    Mix_Chunk*ch;
int main( int argc, char * argv[] )
{   SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init( SDL_flags);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,1,1024);
    SDL_CreateWindowAndRenderer(1280,800, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    boxRGBA(m_renderer,0,0,1280,800,10,10,250,255);
    SDL_RenderPresent( m_renderer );
    Mix_VolumeMusic(20);
     e=new SDL_Event();
        int i=0,j=800;
    m_mus=Mix_LoadMUS("ucl.mp3");
    Mix_PlayMusic(m_mus,-1);
    m_img = IMG_LoadTexture(m_renderer,"ucl.jpg");
    while (e->type!=SDL_KEYUP)
    {   SDL_PollEvent(e);
        if (j>0)j--;
        startpic(i,j);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(16);
    }
homepage();
    return 0;

}
void startpic(int i,int j)
{
    int img_w, img_h;
    SDL_Rect img_rect;
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.w =1280;
    img_rect.h =800;
    img_rect.x = i;
    img_rect.y = j;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
    textRGBA(m_renderer,0,100,"press ENTER to continue!!",2,20,j-50,j-50,j-50,255);
}
void homepic(int j)
{
        int img_w, img_h,x=0;
    SDL_Rect img_rect;
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.w =2000;
    img_rect.h =800;
    img_rect.x = j;
    img_rect.y = 0;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
}
void quit()
{
        SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
}
void homepage()
{int i,j;
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    Mix_FreeMusic(m_mus);
    m_img=IMG_LoadTexture(m_renderer,"3.jpg");
    m_mus=Mix_LoadMUS("footbalista.mp3");
    Mix_PlayMusic(m_mus,-1);
    ch=Mix_LoadWAV("click.mp3");
    i=1002;
    j=0;
    int v=-3;
    bool exit=false;
    while (!exit)
    {
    if (j>0)v=-v;
    if (j<=-720)v=-v;
    j+=v;
        homepic(j);
const Uint8 *state = SDL_GetKeyboardState(NULL);
if (state[SDL_SCANCODE_UP])
{
    i--;Mix_PlayChannel(-1,ch,0);
}
if (state[SDL_SCANCODE_DOWN])
{
    i++;Mix_PlayChannel(-1,ch,0);
}
if (state[SDL_SCANCODE_SPACE])
{
    exit=true;
}
if (state[SDL_SCANCODE_ESCAPE])
{
    exit=true;
}
SDL_PollEvent(e);
    switch(i%3)
    {
    case 0:
        roundedBoxRGBA(m_renderer,400,70,880,270,70,200,200,200,255);
        roundedBoxRGBA(m_renderer,400,300,880,500,70,180,20,200,255);
        roundedBoxRGBA(m_renderer,400,530,880,730,70,180,20,200,255);
        break;
    case 1:
        roundedBoxRGBA(m_renderer,400,70,880,270,70,180,20,200,255);
        roundedBoxRGBA(m_renderer,400,300,880,500,70,200,200,200,255);
        roundedBoxRGBA(m_renderer,400,530,880,730,70,180,20,200,255);
        break;
    case 2:
        roundedBoxRGBA(m_renderer,400,70,880,270,70,180,20,200,255);
        roundedBoxRGBA(m_renderer,400,300,880,500,70,180,20,200,255);
        roundedBoxRGBA(m_renderer,400,530,880,730,70,200,200,200,255);
        break;
    }
        textRGBA(m_renderer,485,120,"START",2,100,10,250,250,255);
        textRGBA(m_renderer,425,345,"SETTING",2,100,10,250,250,255);
        textRGBA(m_renderer,475,580,"ABOUT",2,100,10,250,250,255);
        textRGBA(m_renderer,25,25,"press key space to continue",1,25,200,200,200,255);
        textRGBA(m_renderer,25,55,"and ESC to exit!!",1,25,200,200,200,255);
SDL_RenderPresent(m_renderer);
SDL_Delay(80);
    }
    if (e->key.keysym.sym==SDLK_ESCAPE)
quit();
switch(i%3)
{
    case 0:prematch();break;
    case 1:settingtab();break;
    case 2:abouttab();break;
}
}
void abouttab()
{
 int j=800,x=10,vx;
Mix_FreeMusic(m_mus);
SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
SDL_RenderClear( m_renderer );
m_img=IMG_LoadTexture(m_renderer,"spongebob.jpg");
m_mus=Mix_LoadMUS("spongebob.mp3");
e->type=0;
Mix_PlayMusic(m_mus,-1);
while (e->key.keysym.sym!=SDLK_s)
{
    if (j>0)j--;
    aboutpic(j);
    textRGBA(m_renderer,x,j+290,"ARMAN YAZDANI",2,70,250,170,130,255);
textRGBA(m_renderer,500,j+40,"CREATED BY",2,70,100,150,250,255);
textRGBA(m_renderer,x,j+390,"&",2,55,250,170,130,255);
textRGBA(m_renderer,x,j+490,"MATIN MOHAMMAD GHASEMI",2,70,250,170,130,255);
textRGBA(m_renderer,1200,j,"S=BACK",2,10,20,20,30,255);
SDL_RenderPresent(m_renderer);
SDL_PollEvent(e);
  SDL_Delay(7);
}
homepage();
}
void aboutpic(int j)
{
        int img_w, img_h;
    SDL_Rect img_rect;
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.w =1280;
    img_rect.h =800;
    img_rect.x = 0;
    img_rect.y = j;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
}
void settingtab()
{int i=1120,j=0,k=0,m=0;
bool exit=false;
     SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    Mix_FreeMusic(m_mus);
    m_img = IMG_LoadTexture(m_renderer,"charliechaplin.jpg");
    m_mus=Mix_LoadMUS("angrybirds.mp3");
    Mix_PlayMusic(m_mus,-1);
    settingpic();
    e->type=0;
    boxRGBA(m_renderer,400,360,800,770,200,200,200,150);
    while (!exit)
    {
        SDL_PollEvent(e);
        offlist(j,k);
        textRGBA(m_renderer,710,100,"SOUND EFFECT",2,30,200,200,200,255);
        textRGBA(m_renderer,710,200,"MUSIC",2,30,200,200,200,255);
        textRGBA(m_renderer,450,280,"SOUND TRACKS",2,40,200,200,200,100);
        textRGBA(m_renderer,980,315,"RIGHT KEY = PLAY SONG",2,20,200,200,200,255);
        textRGBA(m_renderer,1020,280,"KEY S = ENTER",2,20,200,200,200,255);
        textRGBA(m_renderer,560,37,"EXIT",2,35,200,200,200,255);
        roundedRectangleRGBA(m_renderer,500,30,700,80,10,255,255,255,255);
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_UP])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==3)
    {
        if (j==1)
        {
            if (k>0)
            {
                        if (k==6)
        {
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    settingpic();
    boxRGBA(m_renderer,400,360,800,770,200,200,200,150);
        }
        k--;
            }
            else
            {
              j=0;
if (m==1)
{       Mix_FreeMusic(m_mus);
    m_mus=Mix_LoadMUS("angrybirds.mp3");
    Mix_PlayMusic(m_mus,-1);
}
            }
        }
        else i--;
    }
    else i--;
}
        if (state[SDL_SCANCODE_DOWN])
{Mix_PlayChannel(-1,ch,0);
if (j==1)
{
    if (k<11)
    {
        if (k==5)
        {
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    settingpic();
    boxRGBA(m_renderer,400,360,800,770,200,200,200,150);
        }
        k++;
    }
}
else i++;
}
        if (state[SDL_SCANCODE_LEFT])
{Mix_PlayChannel(-1,ch,0);
                switch(i%4)
        {
case 2:if (vm<=0)vm=0;else vm-=20;break;
case 1:if (vs<=0)vs=0;else vs-=20;break;
case 3:if (j==1)
{j=0;

if (m==1)
{    Mix_FreeMusic(m_mus);
    m_mus=Mix_LoadMUS("angrybirds.mp3");
    Mix_PlayMusic(m_mus,-1);
}
} break;
        }
}
        if (state[SDL_SCANCODE_RIGHT])
{Mix_PlayChannel(-1,ch,0);
                switch(i%4)
        {
        case 2:if (vm>=80)vm=100;else vm+=20;break;
        case 1:if (vs>=80)vs=100;else vs+=20;break;
        case 3: if (j==1){soundtrack(k);m=1;}
                 else j=1;break;
        }
}
        if (state[SDL_SCANCODE_S])
        {Mix_PlayChannel(-1,ch,0);
            switch(i%4)
            {
                case 0:exit=true;break;
                case 1:if (vs!=0)vs=0;
                else vs=40;break;
                case 2:if (vm!=0)vm=0;
                else vm=40;break;
                case 3:if (j==0)j=1;
                else
                {
                    if (mus[k]==0)mus[k]=1;
                    else if (mus[k]==1)mus[k]=0;
                }
            }
        }
        switch(vs)
        {
        case 0:
            boxRGBA(m_renderer,400,100,420,130,120,120,120,255);
            boxRGBA(m_renderer,430,100,445,130,120,120,120,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,120,120,120,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,120,120,120,255);
            boxRGBA(m_renderer,465,100,505,130,120,120,120,255);
            boxRGBA(m_renderer,510,100,550,130,120,120,120,255);
            boxRGBA(m_renderer,555,100,595,130,120,120,120,255);
            boxRGBA(m_renderer,600,100,640,130,120,120,120,255);
            boxRGBA(m_renderer,645,100,685,130,120,120,120,255);
            break;
        case 20:
            boxRGBA(m_renderer,400,100,420,130,220,220,220,255);
            boxRGBA(m_renderer,430,100,445,130,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,220,220,220,255);
            boxRGBA(m_renderer,465,100,505,130,220,220,220,255);
            boxRGBA(m_renderer,510,100,550,130,120,120,120,255);
            boxRGBA(m_renderer,555,100,595,130,120,120,120,255);
            boxRGBA(m_renderer,600,100,640,130,120,120,120,255);
            boxRGBA(m_renderer,645,100,685,130,120,120,120,255);
            break;
        case 40:
                        boxRGBA(m_renderer,400,100,420,130,220,220,220,255);
            boxRGBA(m_renderer,430,100,445,130,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,220,220,220,255);
            boxRGBA(m_renderer,465,100,505,130,220,220,220,255);
            boxRGBA(m_renderer,510,100,550,130,220,220,220,255);
            boxRGBA(m_renderer,555,100,595,130,120,120,120,255);
            boxRGBA(m_renderer,600,100,640,130,120,120,120,255);
            boxRGBA(m_renderer,645,100,685,130,120,120,120,255);
            break;
        case 60:
                        boxRGBA(m_renderer,400,100,420,130,220,220,220,255);
            boxRGBA(m_renderer,430,100,445,130,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,220,220,220,255);
            boxRGBA(m_renderer,465,100,505,130,220,220,220,255);
            boxRGBA(m_renderer,510,100,550,130,220,220,220,255);
            boxRGBA(m_renderer,555,100,595,130,220,220,220,255);
            boxRGBA(m_renderer,600,100,640,130,120,120,120,255);
            boxRGBA(m_renderer,645,100,685,130,120,120,120,255);
            break;
        case 80:
                                    boxRGBA(m_renderer,400,100,420,130,220,220,220,255);
            boxRGBA(m_renderer,430,100,445,130,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,220,220,220,255);
            boxRGBA(m_renderer,465,100,505,130,220,220,220,255);
            boxRGBA(m_renderer,510,100,550,130,220,220,220,255);
            boxRGBA(m_renderer,555,100,595,130,220,220,220,255);
            boxRGBA(m_renderer,600,100,640,130,220,220,220,255);
            boxRGBA(m_renderer,645,100,685,130,120,120,120,255);
            break;
        case 100:
                                                boxRGBA(m_renderer,400,100,420,130,220,220,220,255);
            boxRGBA(m_renderer,430,100,445,130,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,100,445,100,445,80,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,130,445,130,445,150,220,220,220,255);
            boxRGBA(m_renderer,465,100,505,130,220,220,220,255);
            boxRGBA(m_renderer,510,100,550,130,220,220,220,255);
            boxRGBA(m_renderer,555,100,595,130,220,220,220,255);
            boxRGBA(m_renderer,600,100,640,130,220,220,220,255);
            boxRGBA(m_renderer,645,100,685,130,220,220,220,255);
            break;
        }
        switch(vm)
        {
        case 0:
            boxRGBA(m_renderer,400,200,420,230,120,120,120,255);
            boxRGBA(m_renderer,430,200,445,230,120,120,120,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,120,120,120,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,120,120,120,255);
            boxRGBA(m_renderer,465,200,505,230,120,120,120,255);
            boxRGBA(m_renderer,510,200,550,230,120,120,120,255);
            boxRGBA(m_renderer,555,200,595,230,120,120,120,255);
            boxRGBA(m_renderer,600,200,640,230,120,120,120,255);
            boxRGBA(m_renderer,645,200,685,230,120,120,120,255);
            break;
        case 20:
            boxRGBA(m_renderer,400,200,420,230,220,220,220,255);
            boxRGBA(m_renderer,430,200,445,230,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,220,220,220,255);
            boxRGBA(m_renderer,465,200,505,230,220,220,220,255);
            boxRGBA(m_renderer,510,200,550,230,120,120,120,255);
            boxRGBA(m_renderer,555,200,595,230,120,120,120,255);
            boxRGBA(m_renderer,600,200,640,230,120,120,120,255);
            boxRGBA(m_renderer,645,200,685,230,120,120,120,255);
            break;
        case 40:
                        boxRGBA(m_renderer,400,200,420,230,220,220,220,255);
            boxRGBA(m_renderer,430,200,445,230,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,220,220,220,255);
            boxRGBA(m_renderer,465,200,505,230,220,220,220,255);
            boxRGBA(m_renderer,510,200,550,230,220,220,220,255);
            boxRGBA(m_renderer,555,200,595,230,120,120,120,255);
            boxRGBA(m_renderer,600,200,640,230,120,120,120,255);
            boxRGBA(m_renderer,645,200,685,230,120,120,120,255);
            break;
        case 60:
                        boxRGBA(m_renderer,400,200,420,230,220,220,220,255);
            boxRGBA(m_renderer,430,200,445,230,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,220,220,220,255);
            boxRGBA(m_renderer,465,200,505,230,220,220,220,255);
            boxRGBA(m_renderer,510,200,550,230,220,220,220,255);
            boxRGBA(m_renderer,555,200,595,230,220,220,220,255);
            boxRGBA(m_renderer,600,200,640,230,120,120,120,255);
            boxRGBA(m_renderer,645,200,685,230,120,120,120,255);
            break;
        case 80:
                    boxRGBA(m_renderer,400,200,420,230,220,220,220,255);
            boxRGBA(m_renderer,430,200,445,230,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,220,220,220,255);
            boxRGBA(m_renderer,465,200,505,230,220,220,220,255);
            boxRGBA(m_renderer,510,200,550,230,220,220,220,255);
            boxRGBA(m_renderer,555,200,595,230,220,220,220,255);
            boxRGBA(m_renderer,600,200,640,230,220,220,220,255);
            boxRGBA(m_renderer,645,200,685,230,120,120,120,255);
            break;
        case 100:
                    boxRGBA(m_renderer,400,200,420,230,220,220,220,255);
            boxRGBA(m_renderer,430,200,445,230,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,200,445,200,445,180,220,220,220,255);
            filledTrigonRGBA(m_renderer,430,230,445,230,445,250,220,220,220,255);
            boxRGBA(m_renderer,465,200,505,230,220,220,220,255);
            boxRGBA(m_renderer,510,200,550,230,220,220,220,255);
            boxRGBA(m_renderer,555,200,595,230,220,220,220,255);
            boxRGBA(m_renderer,600,200,640,230,220,220,220,255);
            boxRGBA(m_renderer,645,200,685,230,220,220,220,255);
            break;
        }
        Mix_VolumeMusic(vm);
        Mix_Volume(-1,vs);
    if (j==0)
    {
     if (k<6)
     {
    rectangleRGBA(m_renderer,420,368,780,428,200,200,200,220);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,434,780,494,200,200,200,220);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,500,780,560,200,200,200,220);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,566,780,626,200,200,200,220);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,632,780,692,200,200,200,220);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,698,780,758,200,200,200,220);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,764,780,770,200,200,200,220);
     }
     else
     {
    rectangleRGBA(m_renderer,420,360,780,366,200,200,200,220);
    rectangleRGBA(m_renderer,420,372,780,432,200,200,200,220);
    textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,438,780,498,200,200,200,220);
    textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,504,780,564,200,200,200,220);
    textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,570,780,630,200,200,200,220);
    textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,636,780,696,200,200,200,220);
    textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
    rectangleRGBA(m_renderer,420,702,780,762,200,200,200,220);
    textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
     }
    }
    if (j==1)
    {
        if (k<6)
        {
    rectangleRGBA(m_renderer,420,368,780,428,200,200,200,220);
    rectangleRGBA(m_renderer,420,434,780,494,200,200,200,220);
    rectangleRGBA(m_renderer,420,500,780,560,200,200,200,220);
    rectangleRGBA(m_renderer,420,566,780,626,200,200,200,220);
    rectangleRGBA(m_renderer,420,632,780,692,200,200,200,220);
    rectangleRGBA(m_renderer,420,698,780,758,200,200,200,220);
    rectangleRGBA(m_renderer,420,764,780,770,200,200,200,220);
        }
        else
        {
    rectangleRGBA(m_renderer,420,360,780,366,200,200,200,220);
    rectangleRGBA(m_renderer,420,372,780,432,200,200,200,220);
    rectangleRGBA(m_renderer,420,438,780,498,200,200,200,220);
    rectangleRGBA(m_renderer,420,504,780,564,200,200,200,220);
    rectangleRGBA(m_renderer,420,570,780,630,200,200,200,220);
    rectangleRGBA(m_renderer,420,636,780,696,200,200,200,220);
    rectangleRGBA(m_renderer,420,702,780,762,200,200,200,220);
        }
        switch(k)
        {
            case 0:textRGBA(m_renderer,520,378,"babyblue",2,40,100,200,200,155);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);
            break;
            case 1:
    textRGBA(m_renderer,525,444,"believer",2,40,100,200,200,155);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);break;
            case 2:textRGBA(m_renderer,505,510,"desperado",2,40,100,200,200,155);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);break;
            case 3:textRGBA(m_renderer,525,576,"bella ciao",2,40,100,200,200,155);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);break;
            case 4:textRGBA(m_renderer,525,642,"despacito",2,40,100,200,200,155);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);
    textRGBA(m_renderer,535,708,"Happy",2,40,20,20,20,155);
            break;
            case 5:textRGBA(m_renderer,535,708,"Happy",2,40,100,200,200,155);
    textRGBA(m_renderer,525,444,"believer",2,40,20,20,20,155);
    textRGBA(m_renderer,505,510,"desperado",2,40,20,20,20,155);
    textRGBA(m_renderer,520,378,"babyblue",2,40,20,20,20,155);
    textRGBA(m_renderer,525,642,"despacito",2,40,20,20,20,155);
    textRGBA(m_renderer,525,576,"bella ciao",2,40,20,20,20,155);break;
            case 6:textRGBA(m_renderer,525,382,"Je veux",2,40,100,200,200,155);
                textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
                textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
                textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
                textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
                textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
            break;
            case 7:textRGBA(m_renderer,525,448,"lalala",2,40,100,200,200,155);
                textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
                textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
                textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
                textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
                textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
            break;
            case 8:textRGBA(m_renderer,525,514,"L'Americano",2,40,100,200,200,155);
                textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
                textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
                textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
                textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
                textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
            break;
            case 9:textRGBA(m_renderer,525,580,"my type",2,40,100,200,200,155);
                textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
                textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
                textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
                textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
                textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
                break;
            case 10:textRGBA(m_renderer,525,646,"pulp fiction",2,40,100,200,200,155);
                textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
                textRGBA(m_renderer,525,712,"wake me up",2,40,20,20,20,155);
                textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
                textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
                textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
            break;
            case 11:textRGBA(m_renderer,525,712,"wake me up",2,40,100,200,200,155);
                textRGBA(m_renderer,525,580,"my type",2,40,20,20,20,155);
                textRGBA(m_renderer,525,646,"pulp fiction",2,40,20,20,20,155);
                textRGBA(m_renderer,525,448,"lalala",2,40,20,20,20,155);
                textRGBA(m_renderer,525,382,"Je veux",2,40,20,20,20,155);
                textRGBA(m_renderer,525,514,"L'Americano",2,40,20,20,20,155);
            break;
        }
    }
    switch(i%4)
    {
    case 0:textRGBA(m_renderer,560,37,"EXIT",2,35,200,200,100,255);break;
    case 1:textRGBA(m_renderer,710,100,"SOUND EFFECT",2,30,200,200,10,255);break;
    case 2:textRGBA(m_renderer,710,200,"MUSIC",2,30,200,200,10,255);break;
    case 3:textRGBA(m_renderer,450,280,"SOUND TRACKS",2,40,200,200,10,100);break;
    }
        SDL_RenderPresent(m_renderer);
        SDL_Delay(100);
    }
    homepage();
}
void settingpic()
{
        int img_w, img_h;
    SDL_Rect img_rect;
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.w =1280;
    img_rect.h =800;
    img_rect.x = 0;
    img_rect.y = 0;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
}
void offlist(int j,int k)
{int i;
if (k<6)
    {
   for (i=0;i<6;i++)
   {
       if (i==0)
           {
               if (mus[0]==1) filledCircleRGBA(m_renderer,360,398,10,200,20,20,50);
               else filledCircleRGBA(m_renderer,360,398,10,20,20,200,50);
           }
       if (i==1)
           {
                if(mus[1]==1)filledCircleRGBA(m_renderer,360,468,10,200,20,20,50);
                else filledCircleRGBA(m_renderer,360,468,10,20,20,200,50);
           }
       if (i==2)
           {
               if (mus[2]==1)filledCircleRGBA(m_renderer,360,528,10,200,20,20,50);
               else filledCircleRGBA(m_renderer,360,528,10,20,20,200,50);
           }
       if (i==3)
           {
              if (mus[3]==1)filledCircleRGBA(m_renderer,360,598,10,200,20,20,50);
              else filledCircleRGBA(m_renderer,360,598,10,20,20,200,50);
           }
       if (i==4)
           {
            if (mus[4]==1)filledCircleRGBA(m_renderer,360,658,10,200,20,20,50);
            else filledCircleRGBA(m_renderer,360,658,10,20,20,200,50);
           }
        if (i==5)
           {
            if (mus[5]==1)filledCircleRGBA(m_renderer,360,728,10,200,20,20,50);
            else filledCircleRGBA(m_renderer,360,728,10,20,20,200,50);
           }
   }
    }
   else
   {
           for (i=6;i<12;i++)
           {
                          if (i==6)
           {
               if (mus[6]==1) filledCircleRGBA(m_renderer,360,398,10,200,20,20,50);
               else filledCircleRGBA(m_renderer,360,398,10,20,20,200,50);
           }
       if (i==7)
           {
                if(mus[7]==1)filledCircleRGBA(m_renderer,360,468,10,200,20,20,50);
                else filledCircleRGBA(m_renderer,360,468,10,20,20,200,50);
           }
       if (i==8)
           {
               if (mus[8]==1)filledCircleRGBA(m_renderer,360,528,10,200,20,20,50);
               else filledCircleRGBA(m_renderer,360,528,10,20,20,200,50);
           }
       if (i==9)
           {
              if (mus[9]==1)filledCircleRGBA(m_renderer,360,598,10,200,20,20,50);
              else filledCircleRGBA(m_renderer,360,598,10,20,20,200,50);
           }
       if (i==10)
           {
            if (mus[10]==1)filledCircleRGBA(m_renderer,360,658,10,200,20,20,50);
            else filledCircleRGBA(m_renderer,360,658,10,20,20,200,50);
           }
        if (i==11)
           {
            if (mus[11]==1)filledCircleRGBA(m_renderer,360,728,10,200,20,20,50);
            else filledCircleRGBA(m_renderer,360,728,10,20,20,200,50);
           }
           }
    }
}
void prematch()
{bool exit=false,start=false;int i=1000,appr=1000,appl=1000,m=1000;
SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
SDL_RenderClear( m_renderer );
Mix_FreeMusic(m_mus);
m_img=IMG_LoadTexture(m_renderer,"footbalistha.jpg");
m_mus=Mix_LoadMUS("patomat.mp3");
prematchpic();
Mix_PlayMusic(m_mus,-1);
while (!exit&&!start)
{SDL_PollEvent(e);
const Uint8 *state = SDL_GetKeyboardState(NULL);
if (state[SDL_SCANCODE_S])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==0)start=true;
    if (i%4==3)
exit=true;
}
if (state[SDL_SCANCODE_UP])
{Mix_PlayChannel(-1,ch,0);
    i--;
        SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
SDL_RenderClear( m_renderer );
    prematchpic();
}
if (state[SDL_SCANCODE_DOWN])
{Mix_PlayChannel(-1,ch,0);
    i++;
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
SDL_RenderClear( m_renderer );
    prematchpic();
}
if (state[SDL_SCANCODE_RIGHT])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==1)
    {
              appr++;
    }
    if (i%4==2)
    {
        m++;
    }
}
if (state[SDL_SCANCODE_D])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==1)
    {
         appl++;
    }
    if (i%4==2)
    {
          m++;
    }
}
if (state[SDL_SCANCODE_LEFT])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==1)
    {
         appr--;
    }
    if (i%4==2)
    {
        m--;
    }
}
if (state[SDL_SCANCODE_A])
{Mix_PlayChannel(-1,ch,0);
    if (i%4==1)
    {
        if (appl>0)appl--;
    }
    if (i%4==2)
    {
        m--;
    }
}
switch(i%4)
{
case 0:roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
roundedBoxRGBA(m_renderer,500,50,780,140,10,50,200,100,255);
textRGBA(m_renderer,590,70,"EXIT",2,40,25,255,255,255);
textRGBA(m_renderer,560,250,"KICK-OFF",2,30,100,100,100,255);
textRGBA(m_renderer,540,340,"APPEARANCE",2,30,25,255,255,255);
textRGBA(m_renderer,590,450,"MODE",2,30,25,255,255,255);break;
case 1:appearance(appr,appl);break;
case 2:mode(m);break;
case 3:roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
roundedBoxRGBA(m_renderer,500,50,780,140,10,50,200,100,255);
textRGBA(m_renderer,590,70,"EXIT",2,40,100,100,100,255);
textRGBA(m_renderer,560,250,"KICK-OFF",2,30,25,255,255,255);
textRGBA(m_renderer,540,340,"APPEARANCE",2,30,25,255,255,255);
textRGBA(m_renderer,590,450,"MODE",2,30,25,255,255,255);
break;
}
textRGBA(m_renderer,1100,100,"S=ENTER",2,20,255,255,255,255);
SDL_RenderPresent(m_renderer);
SDL_Delay(100);
}
if (start)match(m,appr,appl);
if (exit)homepage();
}
void prematchpic()
{
        int img_w, img_h;
    SDL_Rect img_rect;
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.w =1280;
    img_rect.h =800;
    img_rect.x = 0;
    img_rect.y = 0;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
}
void appearance(int appr,int appl)
{int r,g,b;
 roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
 boxRGBA(m_renderer,180,280,470,750,70,70,70,255);
 boxRGBA(m_renderer,800,280,1090,750,70,70,70,255);
 roundedBoxRGBA(m_renderer,500,50,780,140,10,50,200,100,255);
textRGBA(m_renderer,590,70,"EXIT",2,40,25,255,255,255);
textRGBA(m_renderer,560,250,"KICK-OFF",2,30,25,255,255,255);
textRGBA(m_renderer,540,340,"APPEARANCE",2,30,100,100,100,255);
textRGBA(m_renderer,590,450,"MODE",2,30,25,255,255,255);
switch(appl%4)
{
case 0:r=255,g=255,b=255;text="STYLE 1/4";break;
case 1:r=0;g=0;b=0;text="STYLE 2/4";break;
case 2:r=0,g=0,b=255;text="STYLE 3/4";break;
case 3:r=255,g=0,b=0;text="STYLE 4/4";break;
}
boxRGBA(m_renderer,200,300,450,370,r,g,b,255);
boxRGBA(m_renderer,250,370,400,550,r,g,b,255);
boxRGBA(m_renderer,250,570,400,620,r,g,b,255);
boxRGBA(m_renderer,250,620,310,690,r,g,b,255);
boxRGBA(m_renderer,340,620,400,690,r,g,b,255);
textRGBA(m_renderer,250,700,text,2,30,20,50,255,255);
filledEllipseRGBA(m_renderer,325,300,30,20,70,70,70,255);
switch(appr%4)
{
case 0:r=255,g=255,b=255;text="STYLE 1/4";break;
case 1:r=0;g=0;b=0;text="STYLE 2/4";break;
case 2:r=0,g=0,b=255;text="STYLE 3/4";break;
case 3:r=255,g=0,b=0;text="STYLE 4/4";break;
}
boxRGBA(m_renderer,820,300,1070,370,r,g,b,255);
boxRGBA(m_renderer,870,370,1020,550,r,g,b,255);
boxRGBA(m_renderer,870,570,1020,620,r,g,b,255);
boxRGBA(m_renderer,870,620,930,690,r,g,b,255);
boxRGBA(m_renderer,960,620,1020,690,r,g,b,255);
textRGBA(m_renderer,870,700,text,2,30,20,50,255,255);
filledEllipseRGBA(m_renderer,945,300,30,20,70,70,70,255);
}
void mode(int m)
{prematchpic();
 roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
textRGBA(m_renderer,590,70,"EXIT",2,40,25,255,255,255);
textRGBA(m_renderer,560,250,"KICK-OFF",2,30,25,255,255,255);
textRGBA(m_renderer,540,340,"APPEARANCE",2,30,25,255,255,255);
textRGBA(m_renderer,590,450,"MODE",2,30,25,255,255,255);
double wh=40,hh=34,xh=1000,yh=480,xH=280,yH=480;
    switch(m%4)
    {
    case 0:
        background0(300);targets0();player_l0(wh,hh,xH,yH,hitl,200,20,20);player_r0(wh,hh,xh,yh,hitr,20,20,200);
        text="NORMAL MODE";
        textRGBA(m_renderer,550,400,text,2,30,255,255,0,255);
        break;
    case 1:
        background1(300);targets1();player_l1(wh,hh,xH,yH,hitl);player_r1(wh,hh,xh,yh,hitr);
        text="NIGHT MODE";
        textRGBA(m_renderer,550,400,text,2,30,255,255,0,255);
        break;
    case 2:
            background0(300);targets0();player_l1(wh,hh,xH,yH,hitl);player_r1(wh,hh,xh,yh,hitr);
        text="SKELETON MODE";
        textRGBA(m_renderer,550,400,text,2,30,255,255,0,255);
        break;
    case 3:
                background0(300);targets0();player_l0(wh,hh,xH,yH,hitl,200,20,20);player_r0(wh,hh,xh,yh,hitr,20,20,200);
        text="SPILL MODE";
        textRGBA(m_renderer,550,400,text,2,30,255,255,0,255);
        textRGBA(m_renderer,520,500,"EVERY NOW AND THEN A",2,20,255,25,255,255);
        textRGBA(m_renderer,520,520,"A POTION WITH SPECIAL",2,20,255,25,255,255);
        textRGBA(m_renderer,520,540,"EFFECT WILL BE SPILLED",2,20,255,25,255,255);
        textRGBA(m_renderer,520,560,"IN THE ARENA!!!",2,20,255,25,255,255);
        break;
    }
    textRGBA(m_renderer,600,350,"MODE",2,30,0,255,255,255);
    filledTrigonRGBA(m_renderer,590,350,590,380,570,365,255,25,25,255);
    filledTrigonRGBA(m_renderer,700,350,700,380,720,365,255,25,25,255);
}
void match(int m,int appr,int appl)
{int b,t,sp[10],s=0,r=0,l=0;bool strt=true,spill,exit=false,tim=false;
    switch(m%4)
{
    case 0:b=0;t=0;break;
    case 1:b=1;t=1;break;
    case 2:b=0;t=0;break;
    case 3:b=0;t=0;spill=true;break;
}
        double wh=40,hh=34,xh=1000,yh=480,xH=280,yH=480;
    double y0=480,vj=-37,a=2.5,vvr=vj,vvl=vj,tr,tl,vhr=10,vhl=10;
    double xb=640,yb=200,ay=1.2,vy=0,cy=1,yb0,vx=0,cx=0.988,tby=0,ry=20,rx=20,rb=20;
    bool jump_l=false,jump_r=false,hitr=false,hitl=false,r1=false,r2=false,l1=false,l2=false;
    int i=0;
    m_mus=Mix_LoadMUS("moviez.mp3");
    if (strt)
{
    start(strt);
}
playlist(s);
while (!exit)
{SDL_PollEvent(e);i++;
    SDL_RenderClear( m_renderer );
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
            vx*=cx;
        xb+=vx;
        yb+=(0.5*ay+vy);
        vy+=ay;
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_H])
        {
            playlist(s++);
        }
       if(state[SDL_SCANCODE_A])
       {vhl=-10;
                  if(xH-10>0&&xH-10!=xh+wh)
       {
           if (xH>70||yH>400)xH+=vhl;
       }
       else if (xH-10-xh-wh<10)
       {
           if (yH+210<yh&&xH-10>0)xH+=vhl;
       }
       }
       if(state[SDL_SCANCODE_D])
       {vhl=10;
                      if(xH+wh+10<1280&&xH+wh+10!=xh)
           {
               if (xH+wh<1210||yH>400)xH+=vhl;
           }
        else
       {
           if (yH+210<yh&&xH+10<1280)xH+=vhl;
       }
       }
       if(state[SDL_SCANCODE_KP_0])
       {
           hitr=true;tr=0;r1=true;
       }
              if(state[SDL_SCANCODE_KP_1])
       {
           hitr=true;tr=0;r2=true;
       }
              if(state[SDL_SCANCODE_1])
       {
           hitl=true;tl=0;l1=true;
       }
              if(state[SDL_SCANCODE_2])
       {
           hitl=true;tl=0;l2=true;
       }
       if(state[SDL_SCANCODE_LEFT])
       {vhr=-10;
       if(xh-10>0&&xh-10!=xH+wh)
       {
           if (xh>70||yh>400)xh+=vhr;
       }
       else if (xh-10-xH-wh<10)
       {
           if (yh+210<yH&&xh-10>0)xh+=vhr;
       }
       }
       if(state[SDL_SCANCODE_RIGHT])
       {vhr=10;
           if(xh+wh+10<1280&&xh+wh+10!=xH)
           {
               if (xh+wh<1210||yh>400)xh+=vhr;
           }
        else
       {
           if (yh+210<yH&&xh+10<1280)xh+=vhr;
       }
       }
       if(state[SDL_SCANCODE_W])jump_l=true;
       if(state[SDL_SCANCODE_UP])jump_r=true;

                            if(jump_l)
       {
               yH+=0.5*a+vvl;
               vvl+=a;
        if ((xH+wh>=1210||xH<=70)&&(yH<=420)&&vvl<0)
          {
              vvl=0;
          }
           if (yH>=y0)
           {
               jump_l=false;
               yH=y0;
               vvl=vj;
           }
       }
       if(jump_r)
       {
               yh+=0.5*a+vvr;
               vvr+=a;
          if ((xh+wh>=1210||xh<=70)&&(yh<=420)&&vvr<0)
          {
              vvr=0;
          }
           if (yh>=y0)
           {
               jump_r=false;
               yh=y0;
               vvr=vj;
           }
       }
       if (hitr)
       {tr++;
           if (tr>10)
           {
               r1=false,r2=false,hitr=false;
           }
       }
              if (hitl)
       {tl++;
           if (tl>10)hitl=false;l1=false,l2=false;
       }
       if (yb-ry<=0){vy=0;yb=40;}
        if (ry+yb>=700)
        {
            vy=-vy*cy;
            yb=680;
        }
        if (xb+rb>1210)
        {
           if (ry+yb>400&&yb-ry<400)
           {
               vy=-vy;
               if (xb+rx<1220)vx-=10;
           }
        }
                if (xb-rb<70)
        {
           if (ry+yb>400&&yb-ry<400)
           {
               vy=-vy;
               if (xb-rx>60)vx+=10;
           }
        }
        if ((xb-rx<0)||(rx+xb>1280))
        {
            vx=-vx;
        }
                if (xb+rx>xh&&xb-rx<xh+wh)
        {
            if (yb+ry>yh&&yb-ry<yh-10)
                {
                    vx=-vx+2*vhr;
                    if (vy>0)vy=-vy;
                }
        }
                if (xb+rx>xh-15&&xb-rx<xh+wh+15)
                {
                    if (yb+ry<yh+80&&yb-ry>yh+10)
                        {
                            vx=-vx+2*vhr;
                        }
                }
if (hitr)
                if (xb+rx>xh-30&&xb-rx<xh+wh-5)
                {
            if (yb+ry<=yh+220&&yb-ry>yh+100)
            {
            if (r1)
           {
            vx=-vx+2*vhr-20;xb-=20;vy=-vy-20;r2=false;
            }
        else if (r2)
            {
            vx=-vx+2*vhr-40;xb-=20;r1=false;vy=0;
            }
                 }
                }
else if (xb+rx>xh-100&&xb-rx<xh+wh+100)
{
                    if (yb+ry<yh+300&&yb+ry>yh)
                    {
                     vx=-vx+2*vhr;xb-20;
                    }
}
                if (xb+rx>xH&&xb-rx<xH+wh)
        {
            if (yb+ry>yH&&yb-ry<yH-10)
                {
                    vx=-vx+2*vhl;
                    if (vy>0)vy=-vy;
                }
        }
                if (xb+rx>xH-5&&xb-rx<xH+wh+5)
                {
                    if (yb+ry<yH+140&&yb-ry>yH+10)
                        {
                            vx=-vx+2*vhl;
                        }
                }
        if (hitl)   if (xb+rx>xH-10&&xb-rx<xH+wh+30)
{
                if (yb-ry<yH+210&&yb+ry>yH+140)
            {
            if (l1)
           {
            vx=-vx+2*vhl+20;xb+=20;vy=-vy-20;l1=false;
            }
        else if (l2)
            {
            vx=-vx+2*vhl+40;xb+=20;l2=false;vy=0;
            }
            }
}
    if (xb+rx<70)
    {
        if (yb-ry>410){r++;goalr(r,l);xH=280,yH=480;xh=1000,yh=480;xb=640,yb=200;
   ay=1.2,vy=0,vx=0;}
    }
        if (xb-rx>1210)
    {
        if (yb-ry>410){l++;goall(l,r);xH=280,yH=480;xh=1000,yh=480;xb=640,yb=200;
    ay=1.2,vy=0,vx=0;}
    }
    background_case(b,0);
    player_rcase(wh,hh,xh,yh,hitr,appr,m);
    player_lcase(wh,hh,xH,yH,hitl,appl,m);
    result(r,l);
                clock(i,tim);
    if (m%4!=2&&m%4!=1)
    {
    filledEllipseRGBA(m_renderer,xb,yb,rx,ry,255,0,0,255);
    }
    else
    {
    ellipseRGBA(m_renderer,xb,yb,rx,ry,255,255,255,255);
    }
    targets_case(t,400);
    SDL_RenderPresent( m_renderer );
    SDL_Delay(15);
    vhl=0;vhr=0;
    if (tim)
    {Uint32 timeout1 = SDL_GetTicks() + 2000;ch=Mix_LoadWAV("longwhistle.mp3");
    Mix_PlayChannel(-1,ch,0);
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1))
    {
        textRGBA(m_renderer,400,500,"FULL-TIME",2,300,200,200,200,100);
    }
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1+2000))
    {
        textRGBA(m_renderer,400,500,"FULL-TIME",2,300,200,200,200,100);
    }
    exit=true;
    }
                  if(state[SDL_SCANCODE_ESCAPE])
               {
                pause();
               }
}homepage();
}
void goalr(int r,int l)
{    ch=Mix_LoadWAV("shortwhistle.mp3");
    Mix_PlayChannel(-1,ch,0);
    Uint32 timeout1 = SDL_GetTicks() + 1000;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1))
{
         switch(r)
    {
    case 0:textRGBA(m_renderer,500,400,"0",2,200,200,100,200,100);break;
    case 1:textRGBA(m_renderer,500,400,"1",2,200,200,100,200,100);break;
    case 2:textRGBA(m_renderer,500,400,"2",2,200,200,100,200,100);break;
    case 3:textRGBA(m_renderer,500,400,"3",2,200,200,100,200,100);break;
    case 4:textRGBA(m_renderer,500,400,"4",2,200,200,100,200,100);break;
    }
                switch(l)
    {
    case 0:textRGBA(m_renderer,780,400,"0",2,200,200,100,200,100);break;
    case 1:textRGBA(m_renderer,780,400,"1",2,200,200,100,200,100);break;
    case 2:textRGBA(m_renderer,780,400,"2",2,200,200,100,200,100);break;
    case 3:textRGBA(m_renderer,780,400,"3",2,200,200,100,200,100);break;
    case 4:textRGBA(m_renderer,780,400,"4",2,200,200,100,200,100);break;
    }SDL_RenderPresent(m_renderer);
}
}
void goall(int l,int r) {
    ch=Mix_LoadWAV("shortwhistle.mp3");
    Mix_PlayChannel(-1,ch,0);
    Uint32 timeout1 = SDL_GetTicks() + 1000;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1))
    {
         switch(r)
    {
    case 0:textRGBA(m_renderer,400,400,"0",2,200,200,100,200,100);break;
    case 1:textRGBA(m_renderer,400,400,"1",2,200,200,100,200,100);break;
    case 2:textRGBA(m_renderer,400,400,"2",2,200,200,100,200,100);break;
    case 3:textRGBA(m_renderer,400,400,"3",2,200,200,100,200,100);break;
    case 4:textRGBA(m_renderer,400,400,"4",2,200,200,100,200,100);break;
    }
                switch(l)
    {
    case 0:textRGBA(m_renderer,780,400,"0",2,200,200,100,200,100);break;
    case 1:textRGBA(m_renderer,780,400,"1",2,200,200,100,200,100);break;
    case 2:textRGBA(m_renderer,780,400,"2",2,200,200,100,200,100);break;
    case 3:textRGBA(m_renderer,780,400,"3",2,200,200,100,200,100);break;
    case 4:textRGBA(m_renderer,780,400,"4",2,200,200,100,200,100);break;
    }SDL_RenderPresent(m_renderer);
    }
}
void result(int r,int l)
{
    switch(r)
    {
    case 0:textRGBA(m_renderer,500,100,"0",2,100,200,200,200,100);break;
    case 1:textRGBA(m_renderer,500,100,"1",2,100,200,200,200,100);break;
    case 2:textRGBA(m_renderer,500,100,"2",2,100,200,200,200,100);break;
    case 3:textRGBA(m_renderer,500,100,"3",2,100,200,200,200,100);break;
    case 4:textRGBA(m_renderer,500,100,"4",2,100,200,200,200,100);break;
    }
        switch(l)
    {
    case 0:textRGBA(m_renderer,780,100,"0",2,100,200,200,200,100);break;
    case 1:textRGBA(m_renderer,780,100,"1",2,100,200,200,200,100);break;
    case 2:textRGBA(m_renderer,780,100,"2",2,100,200,200,200,100);break;
    case 3:textRGBA(m_renderer,780,100,"3",2,100,200,200,200,100);break;
    case 4:textRGBA(m_renderer,780,100,"4",2,100,200,200,200,100);break;
    }
}
void start(bool strt)
{
        SDL_RenderClear( m_renderer );
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    Mix_PlayMusic(m_mus,-1);
    Uint32 timeout1 = SDL_GetTicks() + 1000;
    boxRGBA(m_renderer,0,0,1280,800,0,0,0,255);
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1))
    {
         filledCircleRGBA(m_renderer,640,400,350,200,200,200,255);
         textRGBA(m_renderer,540,200,"3",2,400,10,10,10,200);
         thickLineRGBA(m_renderer,290,400,990,400,20,100,100,100,100);
         thickLineRGBA(m_renderer,640,50,640,750,20,100,100,100,100);
         SDL_RenderPresent(m_renderer);
    }
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1+1000))
    {
         filledCircleRGBA(m_renderer,640,400,350,200,200,200,255);
         textRGBA(m_renderer,540,200,"2",2,400,10,10,10,255);
         thickLineRGBA(m_renderer,290,400,990,400,20,100,100,100,100);
         thickLineRGBA(m_renderer,640,50,640,750,20,100,100,100,100);
         SDL_RenderPresent(m_renderer);
    }
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1+2000))
    {
         filledCircleRGBA(m_renderer,640,400,350,200,200,200,255);
         textRGBA(m_renderer,520,200,"1",2,400,10,10,10,255);
         thickLineRGBA(m_renderer,290,400,990,400,20,100,100,100,100);
         thickLineRGBA(m_renderer,640,50,640,750,20,100,100,100,100);
         SDL_RenderPresent(m_renderer);
    }
    Mix_FreeMusic(m_mus);
    m_mus=Mix_LoadMUS("longwhistle.mp3");
    Mix_PlayMusic(m_mus,-1);
            while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout1+3000))
    {
         filledCircleRGBA(m_renderer,640,400,350,200,200,200,255);
         textRGBA(m_renderer,540,200,"0",2,400,10,10,10,255);
         thickLineRGBA(m_renderer,290,400,990,400,20,100,100,100,100);
         thickLineRGBA(m_renderer,640,50,640,750,20,100,100,100,100);
         SDL_RenderPresent(m_renderer);
    }
            strt=false;
}
void pause()
{bool order=false;int i=1011,r,g,b;
    while (!order)
    {SDL_PollEvent(e);
      const Uint8 *state = SDL_GetKeyboardState(NULL);
       if (state[SDL_SCANCODE_UP])
       {
           i--;
       }
              if (state[SDL_SCANCODE_DOWN])
       {
           i++;
       }
                    if (state[SDL_SCANCODE_S])
       {
           switch(i%3)
           {
               case 1:if (vm>0)vm=0;else vm=60;break;
               case 0:order=true;break;
               case 2:homepage();break;
           }
       }
       switch(i%3)
       {
           case 0:roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
textRGBA(m_renderer,560,250,"RESUME",2,30,100,100,100,255);r=25,g=225,b=225;
textRGBA(m_renderer,550,470,"MAIN MENU",2,30,25,255,255,255);break;
case 1:r=100,g=100,b=100;
roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
textRGBA(m_renderer,560,250,"RESUME",2,30,25,255,255,255);
textRGBA(m_renderer,550,470,"MAIN MENU",2,30,25,255,255,255);
break;
           case 2:roundedBoxRGBA(m_renderer,500,200,780,570,20,50,200,100,255);
textRGBA(m_renderer,560,250,"RESUME",2,30,25,255,255,255);r=25,g=225,b=225;
textRGBA(m_renderer,550,470,"MAIN MENU",2,30,100,100,100,255);break;
       }
       if (vm==0)
       {
           filledCircleRGBA(m_renderer,610,370,20,r,g,b,255);
           boxRGBA(m_renderer,640,345,660,395,r,g,b,255);
           filledTrigonRGBA(m_renderer,640,345,660,345,660,325,r,g,b,255);
           filledTrigonRGBA(m_renderer,640,395,660,395,660,415,r,g,b,255);
           thickLineRGBA(m_renderer,640,340,610,400,4,200,20,20,255);
       }
              else
       {
           filledCircleRGBA(m_renderer,590,370,20,r,g,b,255);
           boxRGBA(m_renderer,620,345,640,395,r,g,b,255);
           filledTrigonRGBA(m_renderer,620,345,640,345,640,325,r,g,b,255);
           filledTrigonRGBA(m_renderer,620,395,640,395,640,415,r,g,b,255);
           thickLineRGBA(m_renderer,660,360,660,380,6,r,g,b,255);
           thickLineRGBA(m_renderer,680,350,680,390,6,r,g,b,255);
           thickLineRGBA(m_renderer,700,340,700,400,6,r,g,b,255);
       }
       textRGBA(m_renderer,250,400,"KEY 1 = UPWARD SHOT",2,20,10,10,10,255);
       textRGBA(m_renderer,250,430,"KEY 2 = GROUND SHOT",2,20,10,10,10,255);
       textRGBA(m_renderer,800,400,"KEY 0 = UPWARD SHOT",2,20,10,10,10,255);
       textRGBA(m_renderer,800,430,"KEY 1 = UPWARD SHOT",2,20,10,10,10,255);
       textRGBA(m_renderer,250,370,"KEY H = NEXT SONG",2,20,10,10,10,255);
       Mix_VolumeMusic(vm);
       SDL_RenderPresent(m_renderer);
       SDL_Delay(100);
    }
}
void clock(int i,bool tim)
{
    if ((minute/500)%5!=4)
    {
             filledCircleRGBA(m_renderer,50,50,50,20,200,20,200);
     filledCircleRGBA(m_renderer,50,50,7,100,100,100,200);
    switch((i/50)%4)
    {
    case 0:boxRGBA(m_renderer,55,45,95,55,100,100,100,255);
    filledTrigonRGBA(m_renderer,95,45,95,55,100,50,100,100,100,255);
    break;
    case 1:boxRGBA(m_renderer,45,55,55,95,100,100,100,255);
    filledTrigonRGBA(m_renderer,45,95,55,95,50,100,100,100,100,255);break;
    case 2:boxRGBA(m_renderer,5,45,45,55,100,100,100,255);
    filledTrigonRGBA(m_renderer,5,45,5,55,0,50,100,100,100,255);break;
    case 3:boxRGBA(m_renderer,45,5,55,45,100,100,100,255);
    filledTrigonRGBA(m_renderer,45,5,55,5,50,0,100,100,100,255);
    minute++;break;
    }
    }
    else
    {
                    filledCircleRGBA(m_renderer,50,50,50,200,20,20,200);
     filledCircleRGBA(m_renderer,50,50,7,100,100,100,200);
    switch((i/50)%4)
    {
    case 0:boxRGBA(m_renderer,55,45,95,55,100,100,100,255);
    filledTrigonRGBA(m_renderer,95,45,95,55,100,50,100,100,100,255);
    break;
    case 1:boxRGBA(m_renderer,45,55,55,95,100,100,100,255);
    filledTrigonRGBA(m_renderer,45,95,55,95,50,100,100,100,100,255);break;
    case 2:boxRGBA(m_renderer,5,45,45,55,100,100,100,255);
    filledTrigonRGBA(m_renderer,5,45,5,55,0,50,100,100,100,255);break;
    case 3:boxRGBA(m_renderer,45,5,55,45,100,100,100,255);
    filledTrigonRGBA(m_renderer,45,5,55,5,50,0,100,100,100,255);
    minute++;break;
    }
    }
    switch((minute/500)%6)
    {
    case 0:textRGBA(m_renderer,40,30,"0",2,40,200,200,200,100);break;
    case 1:textRGBA(m_renderer,40,30,"1",2,40,200,200,200,100);break;
    case 2:textRGBA(m_renderer,40,30,"2",2,40,200,200,200,100);break;
    case 3:textRGBA(m_renderer,40,30,"3",2,40,200,200,200,100);break;
    case 4:textRGBA(m_renderer,40,30,"4",2,40,200,200,200,100);break;
    case 5:tim=true;break;
    }
}
void player_lcase(double wh,double hh,double xH,double yH,bool hitl,int appl,int m)
{int r,g,b;
switch(appl%4)
{
case 0:r=255,g=255,b=255;break;
case 1:r=0;g=0;b=0;break;
case 2:r=0,g=0,b=255;break;
case 3:r=255,g=0,b=0;break;
}
switch(m%4)
{
case 0:player_l0(wh,hh,xH,yH,hitl,r,g,b);break;
case 1:player_l1(wh,hh,xH,yH,hitl);break;
case 2:player_l1(wh,hh,xH,yH,hitl);break;
case 3:player_l0(wh,hh,xH,yH,hitl,r,g,b);break;
}
}
void player_rcase(double wh,double hh,double xh,double yh,bool hitr,int appr,int m)
{int r,g,b;
switch(appr%4)
{
case 0:r=255,g=255,b=255;break;
case 1:r=0;g=0;b=0;break;
case 2:r=0,g=0,b=255;break;
case 3:r=255,g=0,b=0;break;
}
switch(m%4)
{
case 0:player_r0(wh,hh,xh,yh,hitr,r,g,b);break;
case 1:player_r1(wh,hh,xh,yh,hitr);break;
case 2:player_r1(wh,hh,xh,yh,hitr);break;
case 3:player_r0(wh,hh,xh,yh,hitr,r,g,b);break;
}
}
void player_l0(double wh,double hh,double xH,double yH,bool hitl,int r,int g,int b)
{
double xn=xH+0.3*wh,yn=yH+hh,wn=0.4*wh,hn=11;
double xe=xH+37,ye=yH+0.3*hh;
double xl=xH+wh,yl=yH+0.8*hh;
double wb=3.5*wn,hb=97,xb=xn-1.25*wn,yb=yn+hn;
double wa=0.3*wb,ha=0.65*hb,xa=xb+0.35*wb,ya=yb+0.02*hb;
double hf=63,wf=0.4*wb,xf=xb+0.3*wb,yf=yb+hb;
double XW=xf+wf/2,YW=yf+hf,RW=wf/2;
// head&neck
roundedBoxRGBA(m_renderer,xH,yH,xH+wh,yH+hh,7,240,200,200,255);
boxRGBA(m_renderer,xn,yn,xn+wn,yn+hn,240,200,200,255);
filledEllipseRGBA(m_renderer,xH+wh/2,yH,wh/2-1,5,190,195,50,250);
//eye//lips
thickLineRGBA(m_renderer,xe,ye,xe-10,ye,2,0,0,0,255);
thickLineRGBA(m_renderer,xl,yl,xl-9,yl-3,2,0,0,0,255);
thickLineRGBA(m_renderer,xl,yl-3.5,xl-9,yl-6.5,2,0,0,0,255);
if (hitl)
{
    thickLineRGBA(m_renderer,xf+wf,yf,xf+wf+hf*0.8,yf+hf*0.6,wf,r,g,b,255);
    filledCircleRGBA(m_renderer,xf+wf+hf*0.8,yf+hf*0.6,wf/2,0,0,0,255);
    filledCircleRGBA(m_renderer,xf+wf+hf*0.8,yf+hf*0.6,wf/6,100,100,100,255);
}
// foot
roundedBoxRGBA(m_renderer,xf,yf-12,xf+wf,yf+hf,3,r,g,b,255);
 // body
roundedBoxRGBA(m_renderer,xb,yb,xb+wb,yb+hb,8,r,g,b,255);
//arm
roundedBoxRGBA(m_renderer,xa,ya,xa+wa,ya+ha,2,200,200,20,255);
//wheel
filledCircleRGBA(m_renderer,XW,YW,RW,0,0,0,255);
filledCircleRGBA(m_renderer,XW,YW,RW/3,100,100,100,255);
}
void player_l1(double wh,double hh,double xH,double yH,bool hitl)
{
double xn=xH+0.3*wh,yn=yH+hh,wn=0.4*wh,hn=11;
double xe=xH+37,ye=yH+0.3*hh;
double xl=xH+wh,yl=yH+0.8*hh;
double wb=3.5*wn,hb=97,xb=xn-1.25*wn,yb=yn+hn;
double wa=0.3*wb,ha=0.65*hb,xa=xb+0.35*wb,ya=yb+0.02*hb;
double hf=63,wf=0.4*wb,xf=xb+0.3*wb,yf=yb+hb;
double XW=xf+wf/2,YW=yf+hf,RW=wf/2;
// head&neck
roundedRectangleRGBA(m_renderer,xH,yH,xH+wh,yH+hh,7,200,200,200,255);
rectangleRGBA(m_renderer,xn,yn,xn+wn,yn+hn,200,200,200,255);
//eye//lips
thickLineRGBA(m_renderer,xe,ye,xe-10,ye,2,255,255,255,255);
thickLineRGBA(m_renderer,xl,yl,xl-9,yl-3,2,255,255,255,255);
thickLineRGBA(m_renderer,xl,yl-3.5,xl-9,yl-6.5,2,255,255,255,255);
if (hitl)
{short int x[4],y[4];
x[0]=xf+wf,x[1]=xf+wf+0.8*hf,x[2]=xf+wf+0.8*hf-0.6*wf,x[3]=xf+wf-0.6*wf;
y[0]=yf-12,y[1]=yf+0.6*hf-12,y[3]=yf+0.8*wf-12,y[2]=yf+0.6*hf+0.8*wf-12;
    polygonRGBA(m_renderer,x,y,4,255,255,255,250);
    circleRGBA(m_renderer,(x[2]+x[1])/2,(y[1]+y[2])/2,wf/2,255,255,255,255);
    circleRGBA(m_renderer,(x[2]+x[1])/2,(y[1]+y[2])/2,wf/6,255,255,255,255);
}
// foot
roundedRectangleRGBA(m_renderer,xf,yf-12,xf+wf,yf+hf,3,255,255,250,255);
 // body
roundedRectangleRGBA(m_renderer,xb,yb,xb+wb,yb+hb,8,255,255,255,255);
//arm
roundedRectangleRGBA(m_renderer,xa,ya,xa+wa,ya+ha,2,200,200,200,255);
//shoe
circleRGBA(m_renderer,XW,YW,RW,255,255,255,255);
circleRGBA(m_renderer,XW,YW,RW/3,255,255,255,255);
}
void player_r0(double wh,double hh,double xh,double yh,bool hitr,int r,int g,int b)
{double xn=xh+0.3*wh,yn=yh+hh,wn=0.4*wh,hn=11;
double xe=xh+3,ye=yh+0.3*hh;
double xl=xh,yl=yh+0.8*hh;
double wb=3.5*wn,hb=97,xb=xn-1.25*wn,yb=yn+hn;
double wa=0.3*wb,ha=0.65*hb,xa=xb+0.35*wb,ya=yb+0.02*hb;
double hf=63,wf=0.4*wb,xf=xb+0.3*wb,yf=yb+hb;
double xw=xf+wf/2,yw=yf+hf,rw=wf/2;
// head&neck
roundedBoxRGBA(m_renderer,xh,yh,xh+wh,yh+hh,7,140,100,100,255);
boxRGBA(m_renderer,xn,yn,xn+wn,yn+hn,140,100,100,255);
filledEllipseRGBA(m_renderer,xh+wh/2,yh,wh/2-1,5,55,55,50,250);
//eye//lips
thickLineRGBA(m_renderer,xe,ye,xe+10,ye,2,0,0,0,255);
thickLineRGBA(m_renderer,xl,yl,xl+9,yl-3,2,0,0,0,255);
thickLineRGBA(m_renderer,xl,yl-3.5,xl+9,yl-6.5,2,0,0,0,255);
// foot
if (hitr)
{
    thickLineRGBA(m_renderer,xf,yf,xf-hf*0.8,yf+hf*0.6,wf,r,g,b,255);
    filledCircleRGBA(m_renderer,xf-hf*0.8,yf+hf*0.6,wf/2,0,0,0,255);
    filledCircleRGBA(m_renderer,xf-hf*0.8,yf+hf*0.6,wf/6,100,100,100,255);
}
roundedBoxRGBA(m_renderer,xf,yf-12,xf+wf,yf+hf,3,r,g,b,255);
 // body
roundedBoxRGBA(m_renderer,xb,yb,xb+wb,yb+hb,8,r,g,b,255);
//arm
roundedBoxRGBA(m_renderer,xa,ya,xa+wa,ya+ha,2,200,20,20,255);
//wheel
filledCircleRGBA(m_renderer,xw,yw,rw,0,0,0,255);
filledCircleRGBA(m_renderer,xw,yw,rw/3,100,100,100,255);
}
void player_r1(double wh,double hh,double xh,double yh,bool hitr)
{double xn=xh+0.3*wh,yn=yh+hh,wn=0.4*wh,hn=11;
double xe=xh+3,ye=yh+0.3*hh;
double xl=xh,yl=yh+0.8*hh;
double wb=3.5*wn,hb=97,xb=xn-1.25*wn,yb=yn+hn;
double wa=0.3*wb,ha=0.65*hb,xa=xb+0.35*wb,ya=yb+0.02*hb;
double hf=63,wf=0.4*wb,xf=xb+0.3*wb,yf=yb+hb;
double xw=xf+wf/2,yw=yf+hf,rw=wf/2;
// head&neck
roundedRectangleRGBA(m_renderer,xh,yh,xh+wh,yh+hh,7,200,200,200,255);
rectangleRGBA(m_renderer,xn,yn,xn+wn,yn+hn,200,200,200,255);
//filledEllipseRGBA(m_renderer,xh+wh/2,yh,wh/2-1,5,55,55,50,250);
//eye//lips
thickLineRGBA(m_renderer,xe,ye,xe+10,ye,2,255,255,255,255);
thickLineRGBA(m_renderer,xl,yl,xl+9,yl-3,2,255,255,255,255);
thickLineRGBA(m_renderer,xl,yl-3.5,xl+9,yl-6.5,2,255,255,255,255);
// foot
if (hitr)
{short int x[4],y[4];
x[0]=xf,x[1]=xf-0.8*hf,x[2]=xf-0.8*hf+0.6*wf,x[3]=xf+0.6*wf;
y[0]=yf,y[1]=yf+0.6*hf,y[3]=yf+0.8*wf,y[2]=yf+0.6*hf+0.8*wf;
    polygonRGBA(m_renderer,x,y,4,255,255,255,250);
    circleRGBA(m_renderer,(x[2]+x[1])/2,(y[1]+y[2])/2,wf/2,255,255,255,255);
    circleRGBA(m_renderer,(x[2]+x[1])/2,(y[1]+y[2])/2,wf/6,255,255,255,255);
}
roundedRectangleRGBA(m_renderer,xf,yf,xf+wf,yf+hf,3,255,255,255,255);
 // body
roundedRectangleRGBA(m_renderer,xb,yb,xb+wb,yb+hb,8,255,255,255,255);
//arm
roundedRectangleRGBA(m_renderer,xa,ya,xa+wa,ya+ha,2,200,200,200,255);
//shoe
circleRGBA(m_renderer,xw,yw,rw,255,255,255,255);
circleRGBA(m_renderer,xw,yw,rw/3,255,255,255,255);
}
void background_case(int i,int y1)
        {
    switch(i)
    {
        case 0:background0(y1);break;
        case 1:background1(y1);break;
    }
}
void background0(int y1)
{int x1=0,x2=0,y2=700,y=420,x=0;
//f=field\b=background
    boxRGBA(m_renderer,x1,y1,x1+1280,y1+800,100,100,255,255);
    boxRGBA(m_renderer,x2,y2,x2+1280,y2+200,100,255,100,255);
}
void background1(int y1)
{int x1=0,x2=0,y2=700,y=420,x=0;
//f=field\b=background
    boxRGBA(m_renderer,x1,y1,x1+1280,y1+800,0,0,0,255);
    boxRGBA(m_renderer,x2,y2,x2+1280,y2+200,100,100,100,255);
}
void targets_case(int i,int y1)
{
    switch(i)
    {
        case 0:targets0();break;
        case 1:targets1();break;
    }
}
void targets0()
{int y=400,x=0;
        //left target
    //posts
    boxRGBA(m_renderer,60,400,70,700,200,200,200,255);
    boxRGBA(m_renderer,0,410,7,700,200,200,200,255);
    //bar
    boxRGBA(m_renderer,0,410,70,400,200,200,200,255);
    //net
for (int i=0;y+20*i<700;i++)
{
    aalineRGBA(m_renderer,0,y+i*20,70,y+i*20,200,200,200,255);
}
for (int i=0;x+10*i<70;i++)
{
    aalineRGBA(m_renderer,x+10*i,400,x+10*i,700,200,200,200,255);
}
    //right target
    //posts
    boxRGBA(m_renderer,1273,400,1280,700,200,200,200,255);
    boxRGBA(m_renderer,1210,410,1220,700,200,200,200,255);
    //bar
    boxRGBA(m_renderer,1210,410,1280,400,200,200,200,255);
    //net
for (int i=0;y+20*i<700;i++)
{
    aalineRGBA(m_renderer,1210,y+i*20,1280,y+i*20,200,200,200,255);
}
x=1210;
for (int i=0;x+10*i<1280;i++)
{
    aalineRGBA(m_renderer,x+10*i,400,x+10*i,700,200,200,200,255);
}
}
void targets1()
{int y=400,x=0;
        //left target
    //posts
    boxRGBA(m_renderer,60,400,70,700,255,255,255,255);
    boxRGBA(m_renderer,0,410,7,700,255,255,255,255);
    //bar
    boxRGBA(m_renderer,0,410,70,400,255,255,255,255);
    //net
for (int i=0;y+20*i<700;i++)
{
    aalineRGBA(m_renderer,0,y+i*20,70,y+i*20,255,255,255,255);
}
for (int i=0;x+10*i<70;i++)
{
    aalineRGBA(m_renderer,x+10*i,400,x+10*i,700,255,255,255,255);
}
    //right target
    //posts
    boxRGBA(m_renderer,1273,400,1280,700,255,255,255,255);
    boxRGBA(m_renderer,1210,410,1220,700,255,255,255,255);
    //bar
    boxRGBA(m_renderer,1210,410,1280,400,255,255,255,255);
    //net
for (int i=0;y+20*i<700;i++)
{
    aalineRGBA(m_renderer,1210,y+i*20,1280,y+i*20,255,255,255,255);
}
x=1210;
for (int i=0;x+10*i<1280;i++)
{
    aalineRGBA(m_renderer,x+10*i,400,x+10*i,700,255,255,255,255);
}
}
void playlist(int i)
{
    if (mus[i%12]==0)
        soundtrack(i);
    else playlist(i++);
}
void soundtrack(int i)
{
    switch (i%12)
    {
 case 0:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("babyblue.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 1:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Believer.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 2:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Desperado.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 3:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Bella Ciao.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 4:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Despacito.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 5:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("happy.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 6:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Je veux.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 7:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("lalala.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 8:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("L'Americano.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 9:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("my type.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 10:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("pulp fiction.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
 case 11:
        Mix_FreeMusic(m_mus);
    Mix_LoadMUS("Wake Me Up.mp3");
    Mix_PlayMusic(m_mus,-1);
break;
    }
}
