#ifndef ODROIDGPIO_BASEPIN_HPP
#define ODROIDGPIO_BASEPIN_HPP

#include <cstdint>

namespace gpio {
class BasePin
{
 public:
   BasePin() = delete;
   BasePin(const BasePin&) = delete;
   BasePin(BasePin&&) = delete;
   auto operator=(const BasePin&) -> BasePin& = delete;
   auto operator=(BasePin &&) -> BasePin& = delete;
   ~BasePin() = default;

 protected:
   explicit BasePin(uint8_t pin_number);

 private:
   friend class PinDatabase;
   uint8_t m_pin_number;
};
} // namespace gpio

#endif // ODROIDGPIO_BASEPIN_HPP
