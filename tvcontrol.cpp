#include "tvcontrol.h"

tvControl::tvControl() : m_isWork(false), m_channel(1), m_sound(20)
{

}

//-----------------------------------------------------------------------

void tvControl::pushPower()
{
    m_isWork = !m_isWork;
}

//-----------------------------------------------------------------------

void tvControl::setChannel(int channel)
{
    if(m_isWork)
    {
        m_channel = channel;
    }
}

//-----------------------------------------------------------------------

void tvControl::pushSoundOff()
{
    if(m_isWork && m_sound)
    {
        m_sound = 0;
    }
}

//-----------------------------------------------------------------------

void tvControl::pushForward()
{
    if(m_isWork)
    {
        m_channel++;

        if(m_channel == 10)
        {
            m_channel = 0;
        }
    }
}

//-----------------------------------------------------------------------

void tvControl::pushBack()
{
    if(m_isWork)
    {
        m_channel--;

        if(m_channel == -1)
        {
            m_channel = 9;
        }
    }
}

//-----------------------------------------------------------------------

void tvControl::pushPlus()
{
    if(m_isWork && m_sound != 100)
    {
        m_sound += 10;

        if(m_sound > 100)
        {
            m_sound = 100;
        }
    }
}

//-----------------------------------------------------------------------

void tvControl::pushMinus()
{
    if(m_isWork && m_sound)
    {
        m_sound -= 10;

        if(m_sound < 0)
        {
            m_sound = 0;
        }
    }
}

//-----------------------------------------------------------------------

int tvControl::getChannel() const
{
    if(m_isWork)
    {
        return m_channel;
    }

    return -1;
}

//-----------------------------------------------------------------------

int tvControl::getSound() const
{
    if(m_isWork)
    {
        return m_sound;
    }

    return -1;
}

//-----------------------------------------------------------------------
