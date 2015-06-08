#include "game.h"

game::game()
        :
        PrevFrameInput(),
        ThisFrameInput(),
        Fighter(100, 500),
//        Buffer(Const::WindowWidth, Const::WindowHeight),
        Paused(false),
        AdvancingFrame(false)
{   
    //RECT rc;
    //GetClientRect(Global::Window, &rc);

    Fighter.Animation.LoadFrameDirectory(Global::ImagePath + "RedSquare/Neutral/");

    IsRunning = true;
}

void
game::Update()
{   
    Fighter.HandleInput(&ThisFrameInput);
    Fighter.Update();
}

void
game::Blit()
{
    //Buffer.Clear({255, 0, 0, 0});
    Global::Window.clear({30, 30, 30, 255});
    
    Fighter.Blit();

    Global::Window.display();
    
    //Blit::BlitBufferToWindow(&Buffer, Global::Window);

    if(AdvancingFrame)
    {
        AdvancingFrame = false;
        Paused = true;
    }
}

void
game::HandleInput()
{
    FetchAndParseInput(&ThisFrameInput, &PrevFrameInput);

    if(ThisFrameInput.HitboxToggle.WasPressed)
    {
        Global::DebugMode = !Global::DebugMode;
    }
    
    if(ThisFrameInput.FrameStop.WasPressed)
    {
        Paused = !Paused;
    }
    if(Paused)
    {
        if(ThisFrameInput.FrameAdvance.WasPressed)
        {
            HandleInput();
            Update();
        }
        Blit();
    }
    
//    Blit();
}

