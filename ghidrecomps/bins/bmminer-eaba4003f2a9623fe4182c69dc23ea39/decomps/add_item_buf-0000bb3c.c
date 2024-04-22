
void add_item_buf(K_ITEM *item,char *str)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  char *str_local;
  K_ITEM *item_local;
  size_t ext;
  size_t new_siz;
  size_t old_siz;
  size_t siz;
  char *buf;
  
                    /* WARNING: Load size is inaccurate */
  buf = *item->data;
  sVar1 = strlen(str);
  iVar2 = *(int *)((int)item->data + 4);
  if (*(uint *)((int)item->data + 8) < iVar2 + sVar1 + 1) {
    iVar3 = (sVar1 - (sVar1 + 1 & 0xfff)) + 0x1001;
    ppcVar4 = (char **)item->data;
                    /* WARNING: Load size is inaccurate */
    buf = (char *)_cgrealloc(*item->data,*(int *)((int)item->data + 8) + iVar3,"api-btm.c",
                             "add_item_buf",0x498);
    *ppcVar4 = buf;
    *(int *)((int)item->data + 8) = *(int *)((int)item->data + 8) + iVar3;
  }
  memcpy(buf + iVar2,str,sVar1 + 1);
  *(size_t *)((int)item->data + 4) = *(int *)((int)item->data + 4) + sVar1;
  return;
}

