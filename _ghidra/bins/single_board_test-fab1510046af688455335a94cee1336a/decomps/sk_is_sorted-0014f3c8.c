
int sk_is_sorted(_STACK *st)

{
  if (st != (_STACK *)0x0) {
    return st->sorted;
  }
  return 1;
}

