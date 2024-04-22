
void RenameThread(undefined4 param_1)

{
  char acStack_18 [24];
  
  snprintf(acStack_18,0x10,"cg@%s",param_1);
  prctl(0xf,acStack_18,0,0,0);
  return;
}

