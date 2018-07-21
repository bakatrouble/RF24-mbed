

#include "mbed.h"

#define MOSI_PIN PA_7
#define MISO_PIN PA_6
#define SCLK_PIN PA_5

class MbedSPI {
public:
    MbedSPI()
        : spi(MOSI_PIN, MISO_PIN, SCLK_PIN)
    {
    }

    void begin()
    {
        spi.frequency(1000000);
	spi.format(8, 0);
    }

    uint8_t transfer(uint8_t tx_)
    {
        return spi.write(tx_);
    }

    void transfernb(char* tbuf, char* rbuf, uint32_t len)
    {
        spi.write(tbuf, len, rbuf, len);
    }

    void transfern(char* buf, uint32_t len)
    {
        char rbuf[32+1] = {0};
        spi.write(buf, len, rbuf, len);
    }

    virtual ~MbedSPI() {}

private:
    mbed::SPI spi;
};
