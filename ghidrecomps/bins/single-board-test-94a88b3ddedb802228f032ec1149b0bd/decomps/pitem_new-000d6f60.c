
pitem * pitem_new(uchar *prio64be,void *data)

{
  pitem *ppVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  ppVar1 = (pitem *)CRYPTO_malloc(0x10,DAT_000d6f84,0x47);
  if (ppVar1 != (pitem *)0x0) {
    uVar2 = *(undefined4 *)prio64be;
    uVar3 = *(undefined4 *)(prio64be + 4);
    ppVar1->data = data;
    *(undefined4 *)ppVar1->priority = uVar2;
    *(undefined4 *)(ppVar1->priority + 4) = uVar3;
    ppVar1->next = (_pitem *)0x0;
  }
  return ppVar1;
}

