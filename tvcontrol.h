#ifndef TVCONTROL_H
#define TVCONTROL_H

#include <cstdint>

class tvControl
{
public:
    tvControl();

    void pushPower();
    void setChannel(int channel);
    void pushSoundOff();
    void pushForward();
    void pushBack();
    void pushPlus();
    void pushMinus();

    int getChannel() const;
    int getSound() const;

private:
    bool m_isWork;
    int64_t m_channel;
    int64_t m_sound;
};

#endif // TVCONTROL_H
