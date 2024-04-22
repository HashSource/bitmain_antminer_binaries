
void Sha256_Update(CSha256 *p,uint8_t *data,size_t size)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  size_t size_local;
  uint8_t *data_local;
  CSha256 *p_local;
  uint32_t curBufferPos;
  
  size_local = size;
  data_local = data;
  curBufferPos = *(uint *)&p->count & 0x3f;
  while (size_local != 0) {
    uVar2 = curBufferPos + 1;
    puVar1 = data_local + 1;
    p->buffer[curBufferPos] = *data_local;
    uVar3 = *(uint *)&p->count;
    iVar4 = *(int *)((int)&p->count + 4);
    *(uint *)&p->count = uVar3 + 1;
    *(uint *)((int)&p->count + 4) = iVar4 + (uint)(0xfffffffe < uVar3);
    size_local = size_local - 1;
    data_local = puVar1;
    curBufferPos = uVar2;
    if (uVar2 == 0x40) {
      curBufferPos = 0;
      Sha256_WriteByteBlock(p);
    }
  }
  return;
}

