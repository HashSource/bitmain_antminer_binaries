
pitem * pqueue_insert(pqueue pq,pitem *item)

{
  _pitem *p_Var1;
  int iVar2;
  _pitem *__s1;
  _pitem *p_Var3;
  
  if (*(_pitem **)pq != (_pitem *)0x0) {
    p_Var1 = *(_pitem **)pq;
    p_Var3 = (_pitem *)0x0;
    while( true ) {
      __s1 = p_Var1;
      iVar2 = memcmp(__s1,item,8);
      if (0 < iVar2) break;
      if (iVar2 == 0) {
        return (pitem *)0x0;
      }
      p_Var1 = __s1->next;
      p_Var3 = __s1;
      if (__s1->next == (_pitem *)0x0) {
        item->next = (_pitem *)0x0;
        __s1->next = item;
        return item;
      }
    }
    item->next = __s1;
    if (p_Var3 != (_pitem *)0x0) {
      p_Var3->next = item;
      return item;
    }
  }
  *(pitem **)pq = item;
  return item;
}

