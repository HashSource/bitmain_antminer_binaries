
int der_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  size_t __n;
  size_t sVar2;
  size_t sVar3;
  
  sVar2 = param_2[1];
  sVar3 = param_1[1];
  __n = sVar3;
  if ((int)sVar2 <= (int)sVar3) {
    __n = sVar2;
  }
  iVar1 = memcmp((void *)*param_1,(void *)*param_2,__n);
  if (iVar1 == 0) {
    iVar1 = sVar3 - sVar2;
  }
  return iVar1;
}

