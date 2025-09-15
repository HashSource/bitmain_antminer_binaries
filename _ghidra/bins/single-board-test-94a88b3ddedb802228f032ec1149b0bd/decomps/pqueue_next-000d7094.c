
pitem * pqueue_next(piterator *iter)

{
  piterator p_Var1;
  
  p_Var1 = (piterator)iter;
  if ((iter != (piterator *)0x0) && (p_Var1 = *iter, p_Var1 != (piterator)0x0)) {
    *iter = p_Var1->next;
    return p_Var1;
  }
  return p_Var1;
}

