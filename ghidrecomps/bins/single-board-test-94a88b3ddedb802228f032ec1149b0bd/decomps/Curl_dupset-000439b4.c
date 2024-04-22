
int Curl_dupset(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  puVar4 = (undefined4 *)(param_2 + 0x33c);
  memcpy((void *)(param_1 + 0x150),(void *)(param_2 + 0x150),0x300);
  memset((void *)(param_1 + 0x340),0,0xb8);
  do {
    iVar1 = iVar3 + 0xd0;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
    iVar1 = setstropt(param_1 + iVar1 * 4,*puVar4);
    if (iVar1 != 0) {
      return iVar1;
    }
  } while (iVar3 != 0x2c);
  iVar3 = 0;
  if (((*(uint *)(param_2 + 0x198) | *(uint *)(param_2 + 0x19c)) != 0) &&
     (iVar1 = *(int *)(param_2 + 0x3f4), iVar1 != 0)) {
    uVar2 = curlx_sotouz();
    iVar3 = Curl_memdup(iVar1,uVar2);
    *(int *)(param_1 + 0x3f4) = iVar3;
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x18c) = iVar3;
      return 0;
    }
    iVar3 = 0x1b;
  }
  return iVar3;
}

