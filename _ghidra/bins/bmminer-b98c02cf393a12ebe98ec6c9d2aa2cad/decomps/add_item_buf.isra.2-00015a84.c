
void add_item_buf_isra_2(int *param_1,char *param_2)

{
  size_t sVar1;
  void *__ptr;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char acStack_828 [2052];
  
  puVar3 = (undefined4 *)*param_1;
  sVar1 = strlen(param_2);
  iVar4 = puVar3[1];
  __ptr = (void *)*puVar3;
  if ((uint)puVar3[2] < iVar4 + 1 + sVar1) {
    iVar2 = (sVar1 + 0x1001) - (sVar1 + 1 & 0xfff);
    __ptr = realloc(__ptr,puVar3[2] + iVar2);
    *puVar3 = __ptr;
    if (__ptr == (void *)0x0) {
      snprintf(acStack_828,0x800,"OOM buf siz=%d tot=%d ext=%d in %s %s():%d",sVar1,
               *(undefined4 *)(*param_1 + 8),iVar2,"api.c","add_item_buf",0x49e);
      _applog(3,acStack_828,1);
      _quit(1);
    }
    *(int *)(*param_1 + 8) = iVar2 + *(int *)(*param_1 + 8);
  }
  memcpy((void *)((int)__ptr + iVar4),param_2,sVar1 + 1);
  *(size_t *)(*param_1 + 4) = sVar1 + *(int *)(*param_1 + 4);
  return;
}

