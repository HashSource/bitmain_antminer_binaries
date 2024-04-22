
void sk_sort(_STACK *st)

{
  if ((st != (_STACK *)0x0) && (st->sorted == 0)) {
    qsort(st->data,st->num,4,(__compar_fn_t)st->comp);
    st->sorted = 1;
  }
  return;
}

