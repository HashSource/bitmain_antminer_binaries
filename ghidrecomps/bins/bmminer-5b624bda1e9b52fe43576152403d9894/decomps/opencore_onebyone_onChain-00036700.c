
/* WARNING: Unknown calling convention */

void opencore_onebyone_onChain(int chainIndex)

{
  int opencore_num;
  
  opencore_num = 0;
  do {
    opencore_num = opencore_num + 1;
    open_core_onChain(chainIndex,0x72,opencore_num,true);
    usleep(100000);
  } while (opencore_num != 0x72);
  return;
}

