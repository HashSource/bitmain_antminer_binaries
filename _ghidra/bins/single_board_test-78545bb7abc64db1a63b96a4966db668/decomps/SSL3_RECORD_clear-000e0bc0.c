
void SSL3_RECORD_clear(void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      uVar2 = *(undefined4 *)((int)param_1 + 0x1c);
      memset(param_1,0,0x30);
      *(undefined4 *)((int)param_1 + 0x1c) = uVar2;
      param_1 = (void *)((int)param_1 + 0x30);
    } while (param_2 != iVar1);
    return;
  }
  return;
}

