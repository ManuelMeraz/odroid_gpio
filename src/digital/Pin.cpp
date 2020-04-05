
#include <detail/gpio.hpp>
#include <odroid/digital/Pin.hpp>
#include <wiringPi.h>

gpio::digital::Pin::Pin(uint8_t pin_number, Mode mode) : BasePin(pin_number), m_mode(mode)
{
   gpio::pin_mode(m_pin_number, static_cast<uint8_t>(m_mode));
}

gpio::digital::Pin::~Pin()
{
   gpio::pin_mode(m_pin_number, static_cast<uint8_t>(Mode::OFF));
}

auto gpio::digital::Pin::mode() const -> Mode
{
   return m_mode;
}

void gpio::digital::Pin::mode(Mode mode)
{
   m_mode = mode;
   gpio::pin_mode(m_pin_number, static_cast<uint8_t>(m_mode));
}

void gpio::digital::Pin::write(Write mode)
{
   digitalWrite(m_pin_number, static_cast<int>(mode));
}
