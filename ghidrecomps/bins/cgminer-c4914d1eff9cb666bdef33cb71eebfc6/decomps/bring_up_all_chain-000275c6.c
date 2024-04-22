
/* WARNING: Unknown calling convention */

int bring_up_all_chain(void)

{
  uint uVar1;
  int ret;
  int chain;
  
  ret = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      uVar1 = bring_up_chain(chain,true);
      ret = ret | uVar1;
    }
  }
  return ret;
}

