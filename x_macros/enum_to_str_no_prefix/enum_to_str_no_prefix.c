#include <stdio.h>


#define SPI_ERR_LIST \
    X(OK) \
    X(BUSY) \
    X(TIMEOUT) \
    X(INVALID_ARG) \
    X(NOT_INITIALIZED)


typedef enum {
#define X(name) SPI_ERR_ ## name,
    SPI_ERR_LIST
#undef X
} SpiErr;


const char* spi_err_to_str(SpiErr err) {
    switch (err) {
#define X(name) case SPI_ERR_ ## name: return #name;
        SPI_ERR_LIST
#undef X
        default: return "UNKNOWN";
    }
}


int main() {
    SpiErr e = SPI_ERR_BUSY;
    printf("SPI Error: %s\n", spi_err_to_str(e));

    return 0;
}

