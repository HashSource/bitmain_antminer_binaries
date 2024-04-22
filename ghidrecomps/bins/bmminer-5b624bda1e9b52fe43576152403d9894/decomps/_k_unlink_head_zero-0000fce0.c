
/* WARNING: Unknown calling convention */

K_ITEM * _k_unlink_head_zero(K_LIST *list,char *file,char *func,int line)

{
  K_ITEM *pKVar1;
  K_ITEM *item;
  
  pKVar1 = _k_unlink_head(list,file,func,line);
  if (pKVar1 != (K_ITEM *)0x0) {
    memset(pKVar1->data,0,list->siz);
  }
  return pKVar1;
}

