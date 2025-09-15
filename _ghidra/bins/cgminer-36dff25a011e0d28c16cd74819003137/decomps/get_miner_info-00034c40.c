
void get_miner_info(char *infoStr)

{
  int iVar1;
  int iVar2;
  double dVar3;
  char *infoStr_local;
  double voltage;
  int chain_num;
  int retlen;
  int i;
  
  retlen = 0;
  dVar3 = get_working_voltage();
  chain_num = 0;
  i = 0;
  while( true ) {
    if (0xf < i) break;
    if (dev->chain_exist[i] != 0) {
      iVar2 = sprintf(infoStr + retlen,"chain%d_voltage=%d;",i + 1,(int)(longlong)(dVar3 * 100.0));
      iVar1 = sprintf(infoStr + retlen + iVar2,"chain%d_voladded=%d;",i + 1,0);
      iVar1 = retlen + iVar2 + iVar1;
      iVar2 = sprintf(infoStr + iVar1,"chain%d_basefreq=%d;",i + 1,0x113);
      iVar1 = iVar1 + iVar2;
      iVar2 = sprintf(infoStr + iVar1,"chain%d_badcore=%d;",i + 1,0);
      retlen = iVar1 + iVar2;
      chain_num = chain_num + 1;
    }
    i = i + 1;
  }
  iVar2 = sprintf(infoStr + retlen,"chainnum=%d;",chain_num);
  sprintf(infoStr + retlen + iVar2,"version=%s;",g_miner_compiletime);
  return;
}

