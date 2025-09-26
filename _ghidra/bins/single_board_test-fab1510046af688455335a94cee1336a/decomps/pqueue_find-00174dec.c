
pitem * pqueue_find(pqueue pq,uchar *prio64be)

{
  pitem *__s1;
  pitem *ppVar1;
  int iVar2;
  pitem *ppVar3;
  pitem *ppVar4;
  
  ppVar3 = *(pitem **)pq;
  ppVar4 = ppVar3;
  ppVar1 = ppVar3;
  while( true ) {
    __s1 = ppVar4;
    if (ppVar3 == (pitem *)0x0) {
      return ppVar1;
    }
    ppVar4 = __s1->next;
    if (ppVar4 == (_pitem *)0x0) break;
    ppVar3 = (pitem *)memcmp(__s1,prio64be,8);
    ppVar1 = __s1;
  }
  iVar2 = memcmp(__s1,prio64be,8);
  if (iVar2 == 0) {
    return __s1;
  }
  return (pitem *)0x0;
}

