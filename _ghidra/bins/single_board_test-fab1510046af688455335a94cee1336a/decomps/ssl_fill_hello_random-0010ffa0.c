
int ssl_fill_hello_random(int param_1,int param_2,uchar *param_3,int param_4)

{
  time_t tVar1;
  int iVar2;
  
  if (param_4 < 4) {
    return 0;
  }
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x104) << 0x1a;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x104) << 0x19;
  }
  if (-1 < iVar2) {
    iVar2 = RAND_pseudo_bytes(param_3,param_4);
    return iVar2;
  }
  tVar1 = time((time_t *)0x0);
  param_3[3] = (uchar)tVar1;
  *param_3 = (uchar)((uint)tVar1 >> 0x18);
  param_3[1] = (uchar)((uint)tVar1 >> 0x10);
  param_3[2] = (uchar)((uint)tVar1 >> 8);
  iVar2 = RAND_pseudo_bytes(param_3 + 4,param_4 + -4);
  return iVar2;
}

