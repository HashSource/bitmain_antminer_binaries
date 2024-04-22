
void opencore_onebyone_onChain(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    open_core_onChain(param_1,0x72,iVar1,1);
    usleep(100000);
  } while (iVar1 != 0x72);
  return;
}

