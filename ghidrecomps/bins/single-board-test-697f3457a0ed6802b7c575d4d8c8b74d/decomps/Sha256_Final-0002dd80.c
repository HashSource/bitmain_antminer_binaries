
void Sha256_Final(CSha256 *p,uint8_t *digest)

{
  uint8_t *puVar1;
  uint uVar2;
  uint8_t *digest_local;
  CSha256 *p_local;
  uint i;
  uint32_t curBufferPos;
  uint64_t lenInBits;
  
  lenInBits._4_4_ = *(int *)((int)&p->count + 4) << 3 | *(uint *)&p->count >> 0x1d;
  lenInBits._0_4_ = *(uint *)&p->count << 3;
  uVar2 = *(uint *)&p->count & 0x3f;
  p->buffer[uVar2] = 0x80;
  while (curBufferPos = uVar2 + 1, curBufferPos != 0x38) {
    uVar2 = curBufferPos & 0x3f;
    if (uVar2 == 0) {
      Sha256_WriteByteBlock(p);
    }
    p->buffer[uVar2] = '\0';
  }
  for (i = 0; i < 8; i = i + 1) {
    p->buffer[curBufferPos] = (uint8_t)(lenInBits._4_4_ >> 0x18);
    lenInBits._4_4_ = lenInBits._4_4_ << 8 | (uint)lenInBits >> 0x18;
    lenInBits._0_4_ = (uint)lenInBits << 8;
    curBufferPos = curBufferPos + 1;
  }
  Sha256_WriteByteBlock(p);
  digest_local = digest;
  for (i = 0; i < 8; i = i + 1) {
    *digest_local = (uint8_t)(p->state[i] >> 0x18);
    digest_local[1] = (uint8_t)(p->state[i] >> 0x10);
    puVar1 = digest_local + 3;
    digest_local[2] = (uint8_t)(p->state[i] >> 8);
    digest_local = digest_local + 4;
    *puVar1 = (uint8_t)p->state[i];
  }
  Sha256_Init(p);
  return;
}

