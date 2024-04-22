
void sha256_final(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  if ((param_1[1] & 0x3fU) < 0x38) {
    iVar1 = 1;
  }
  else {
    iVar1 = 2;
  }
  iVar2 = (*param_1 + param_1[1]) * 8;
  iVar3 = iVar1 * 0x40;
  memset((void *)((int)param_1 + param_1[1] + 8),0,iVar3 - param_1[1]);
  *(undefined *)((int)param_1 + param_1[1] + 8) = 0x80;
  *(char *)((int)param_1 + iVar3 + 7) = (char)iVar2;
  *(char *)((int)param_1 + iVar3 + 6) = (char)((uint)iVar2 >> 8);
  *(char *)((int)param_1 + iVar3 + 5) = (char)((uint)iVar2 >> 0x10);
  *(char *)(param_1 + iVar1 * 0x10 + 1) = (char)((uint)iVar2 >> 0x18);
  sha256_transf(param_1,param_1 + 2,iVar1);
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(char *)(param_2 + local_c * 4 + 3) = (char)param_1[local_c + 0x22];
    *(char *)(param_2 + local_c * 4 + 2) = (char)((uint)param_1[local_c + 0x22] >> 8);
    *(char *)(param_2 + local_c * 4 + 1) = (char)((uint)param_1[local_c + 0x22] >> 0x10);
    *(char *)(param_2 + local_c * 4) = (char)((uint)param_1[local_c + 0x22] >> 0x18);
  }
  return;
}

