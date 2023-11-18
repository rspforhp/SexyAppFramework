#ifndef MD5_H
#define MD5_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    uint64_t size;        // Size of input in bytes
    uint32_t buffer[4];   // Current accumulation of hash
    uint8_t input[64];    // Input to be used in the next step
    uint8_t digest[16];   // Result of algorithm
}MD5Context;

void MD5Init(MD5Context *ctx);
void MD5Update(MD5Context *ctx, uint8_t *input, size_t input_len);
void MD5Final(MD5Context *ctx);
void MD5Step(uint32_t *buffer, uint32_t *input);

void MD5String(char *input, uint8_t *result);
void MD5File(FILE *file, uint8_t *result);

#endif
