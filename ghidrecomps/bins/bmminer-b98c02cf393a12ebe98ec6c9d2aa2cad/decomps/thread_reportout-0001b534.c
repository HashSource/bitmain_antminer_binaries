
void thread_reportout(int param_1)

{
  time_t tVar1;
  int iVar2;
  
  *(undefined *)(param_1 + 0x3d) = 1;
  cgtime(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x60) = 0;
  tVar1 = time((time_t *)0x0);
  *(time_t *)(iVar2 + 0xf0) = tVar1;
  return;
}

