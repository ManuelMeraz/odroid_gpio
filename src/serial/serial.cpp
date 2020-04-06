#include "detail/serial/serial.hpp"

#include <sstream>
#include <wiringSerial.h>

int gpio::serial::open(const std::string& device, uint32_t baud_rate)
{

   const int file_descriptor = serialOpen(device.c_str(), static_cast<int>(baud_rate));
   if (file_descriptor == -1) {
      std::stringstream ss;
      ss << "Failed to open serial device. Device: " << device << " Baud Rate: " << baud_rate
         << std::endl;
      throw std::runtime_error(ss.str());
   }

   return file_descriptor;
}

void gpio::serial::close(const int file_descriptor)
{
   serialClose(file_descriptor);
}

void gpio::serial::clear(const int file_descriptor)
{
   serialFlush(file_descriptor);
}

void gpio::serial::write_byte(const int file_descriptor, const uint8_t byte)
{
   serialPutchar(file_descriptor, static_cast<unsigned char>(byte));
}

void gpio::serial::write(const int file_descriptor, const std::string& message)
{
   serialPuts(file_descriptor, message.c_str());
}

void gpio::serial::print(const int file_descriptor, const std::string& message)
{
   serialPrintf(file_descriptor, message.c_str());
}
