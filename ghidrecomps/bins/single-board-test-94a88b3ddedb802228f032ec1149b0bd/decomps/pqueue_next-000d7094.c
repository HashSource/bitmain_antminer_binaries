
pitem * pqueue_next(piterator *iter)

{
  pitem *ppVar1;
  
  ppVar1 = (pitem *)iter;
  if ((iter != (piterator *)0x0) && (ppVar1 = *iter, ppVar1 != (pitem *)0x0)) {
    *iter = ppVar1->next;
    return ppVar1;
  }
  return ppVar1;
}

