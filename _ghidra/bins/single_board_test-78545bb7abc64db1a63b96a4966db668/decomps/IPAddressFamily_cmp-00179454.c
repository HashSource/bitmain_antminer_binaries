
int IPAddressFamily_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  size_t __n;
  size_t sVar2;
  size_t sVar3;
  
  sVar3 = **(size_t **)*param_1;
  sVar2 = **(size_t **)*param_2;
  __n = sVar3;
  if ((int)sVar2 <= (int)sVar3) {
    __n = sVar2;
  }
  iVar1 = memcmp((void *)(*(size_t **)*param_1)[2],(void *)(*(size_t **)*param_2)[2],__n);
  if (iVar1 == 0) {
    iVar1 = sVar3 - sVar2;
  }
  return iVar1;
}

