
void add_item_buf_isra_2(int *param_1,char *param_2)

{
  size_t sVar1;
  void *__ptr;
  int iVar2;
  void **ppvVar3;
  void *pvVar4;
  char acStack_828 [2052];
  
  ppvVar3 = (void **)*param_1;
  sVar1 = strlen(param_2);
  pvVar4 = ppvVar3[1];
  __ptr = *ppvVar3;
  if (ppvVar3[2] < (void *)((int)pvVar4 + sVar1 + 1)) {
    iVar2 = (sVar1 + 0x1001) - (sVar1 + 1 & 0xfff);
    __ptr = realloc(__ptr,(int)ppvVar3[2] + iVar2);
    *ppvVar3 = __ptr;
    if (__ptr == (void *)0x0) {
      snprintf(acStack_828,0x800,"OOM buf siz=%d tot=%d ext=%d in %s %s():%d",sVar1,
               *(undefined4 *)(*param_1 + 8),iVar2,"api.c",DAT_00015b38,0x49e);
      _applog(3,acStack_828,1);
      _quit(1);
    }
    *(int *)(*param_1 + 8) = iVar2 + *(int *)(*param_1 + 8);
  }
  memcpy((void *)((int)__ptr + (int)pvVar4),param_2,sVar1 + 1);
  *(size_t *)(*param_1 + 4) = sVar1 + *(int *)(*param_1 + 4);
  return;
}

