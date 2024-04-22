
void Sha256_WriteByteBlock(CSha256 *p)

{
  CSha256 *p_local;
  uint32_t data32 [16];
  uint i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    data32[i] = (uint)p->buffer[i * 4 + 3] +
                (uint)p->buffer[i * 4 + 2] * 0x100 +
                (uint)p->buffer[i * 4] * 0x1000000 + (uint)p->buffer[i * 4 + 1] * 0x10000;
  }
  Sha256_Transform(p->state,data32);
  return;
}

