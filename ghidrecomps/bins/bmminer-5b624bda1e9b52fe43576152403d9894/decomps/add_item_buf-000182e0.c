
/* WARNING: Unknown calling convention */

void add_item_buf(K_ITEM *item,char *str)

{
  size_t sVar1;
  size_t siz;
  void **ppvVar2;
  void *__ptr;
  char *buf;
  size_t old_siz;
  void *pvVar3;
  size_t ext;
  int iVar4;
  char tmp42 [2048];
  
  ppvVar2 = (void **)item->data;
  sVar1 = strlen(str);
  pvVar3 = ppvVar2[1];
  __ptr = *ppvVar2;
  if (ppvVar2[2] < (void *)((int)pvVar3 + sVar1 + 1)) {
    iVar4 = (sVar1 + 0x1001) - (sVar1 + 1 & 0xfff);
    __ptr = realloc(__ptr,(int)ppvVar2[2] + iVar4);
    *ppvVar2 = __ptr;
    if (__ptr == (void *)0x0) {
      snprintf(tmp42,0x800,DAT_00018390,sVar1,*(undefined4 *)((int)item->data + 8),iVar4,
               DAT_0001838c,DAT_00018394,0x49b);
      _applog(3,tmp42,true);
      _quit(1);
    }
    *(int *)((int)item->data + 8) = *(int *)((int)item->data + 8) + iVar4;
  }
  memcpy((void *)((int)__ptr + (int)pvVar3),str,sVar1 + 1);
  *(size_t *)((int)item->data + 4) = *(int *)((int)item->data + 4) + sVar1;
  return;
}

