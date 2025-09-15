
/* WARNING: Unknown calling convention */

void add_item_buf(K_ITEM *item,char *str)

{
  size_t sVar1;
  undefined4 *puVar2;
  void *__ptr;
  size_t old_siz;
  int iVar3;
  size_t ext;
  int iVar4;
  char tmp42 [2048];
  
  puVar2 = (undefined4 *)item->data;
  sVar1 = strlen(str);
  iVar3 = puVar2[1];
  __ptr = (void *)*puVar2;
  if ((uint)puVar2[2] < iVar3 + 1 + sVar1) {
    iVar4 = (sVar1 + 0x1001) - (sVar1 + 1 & 0xfff);
    __ptr = realloc(__ptr,puVar2[2] + iVar4);
    *puVar2 = __ptr;
    if (__ptr == (void *)0x0) {
      snprintf(tmp42,0x800,"OOM buf siz=%d tot=%d ext=%d in %s %s():%d",sVar1,
               *(undefined4 *)((int)item->data + 8),iVar4,"api.c","add_item_buf",0x49b);
      _applog(3,tmp42,true);
      _quit(1);
    }
    *(int *)((int)item->data + 8) = *(int *)((int)item->data + 8) + iVar4;
  }
  memcpy((void *)((int)__ptr + iVar3),str,sVar1 + 1);
  *(size_t *)((int)item->data + 4) = *(int *)((int)item->data + 4) + sVar1;
  return;
}

