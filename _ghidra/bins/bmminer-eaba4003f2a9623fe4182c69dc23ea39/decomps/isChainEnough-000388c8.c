
/* WARNING: Unknown calling convention */

_Bool isChainEnough(void)

{
  int chainnum;
  int i;
  
  chainnum = 0;
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      chainnum = chainnum + 1;
    }
  }
  return 2 < chainnum;
}

