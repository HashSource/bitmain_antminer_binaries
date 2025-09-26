
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  byte *pbVar1;
  uint uVar3;
  byte *pbVar2;
  
  if (len != 0) {
    uVar3 = 0;
    pbVar2 = (byte *)a;
    do {
      pbVar1 = pbVar2 + 1;
                    /* WARNING: Load size is inaccurate */
      uVar3 = uVar3 | *b ^ *pbVar2;
      pbVar2 = pbVar1;
      b = (byte *)((int)b + 1);
    } while (pbVar1 != (byte *)((int)a + len));
    return uVar3;
  }
  return 0;
}

