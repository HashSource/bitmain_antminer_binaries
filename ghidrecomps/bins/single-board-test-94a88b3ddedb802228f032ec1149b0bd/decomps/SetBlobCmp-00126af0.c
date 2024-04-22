
int SetBlobCmp(void **param_1,void **param_2)

{
  int iVar1;
  void *__n;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = param_2[1];
  pvVar3 = param_1[1];
  __n = pvVar3;
  if ((int)pvVar2 <= (int)pvVar3) {
    __n = pvVar2;
  }
  iVar1 = memcmp(*param_1,*param_2,(size_t)__n);
  if (iVar1 == 0) {
    iVar1 = (int)pvVar3 - (int)pvVar2;
  }
  return iVar1;
}

