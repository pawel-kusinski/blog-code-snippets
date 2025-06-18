#include <stdio.h>


#define SPI_ERR_LIST \
    X(SPI_ERR_OK) \
    X(SPI_ERR_BUSY) \
    X(SPI_ERR_TIMEOUT) \
    X(SPI_ERR_INVALID_ARG) \
    X(SPI_ERR_NOT_INITIALIZED)


typedef enum {
#define X(name) name,
    SPI_ERR_LIST
#undef X
} SpiErr;


const char* spi_err_to_str(SpiErr err) {
    switch (err) {
#define X(name) case name: return #name;
        SPI_ERR_LIST
#undef X
        default: return "UNKNOWN";
    }
}


int main() {
    SpiErr e = SPI_ERR_TIMEOUT;
    printf("SPI Error: %s\n", spi_err_to_str(e));

    return 0;
}

