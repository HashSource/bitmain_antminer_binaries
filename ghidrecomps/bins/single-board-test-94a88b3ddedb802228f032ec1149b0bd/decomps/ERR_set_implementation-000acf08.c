
int ERR_set_implementation(ERR_FNS *fns)

{
  bool bVar1;
  
  CRYPTO_lock(9,1,DAT_000acf40,0x139);
  bVar1 = *(int *)(DAT_000acf44 + 0x2f4) == 0;
  if (bVar1) {
    *(ERR_FNS **)(DAT_000acf44 + 0x2f4) = fns;
  }
  CRYPTO_lock(10,1,DAT_000acf40,0x142);
  return (uint)bVar1;
}

