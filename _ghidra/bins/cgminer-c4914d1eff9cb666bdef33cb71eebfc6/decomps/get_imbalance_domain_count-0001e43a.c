
void get_imbalance_domain_count(char *infoStr)

{
  int iVar1;
  char *infoStr_local;
  int chain;
  int len;
  
  len = sprintf(infoStr,"%d ",imbalance_domain_count_total);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = sprintf(infoStr + len,"%d ",imbalance_domain_count_chain[chain]);
      len = len + iVar1;
    }
  }
  return;
}

