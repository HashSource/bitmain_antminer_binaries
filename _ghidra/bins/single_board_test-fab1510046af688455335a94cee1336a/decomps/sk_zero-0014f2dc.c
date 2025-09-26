
void sk_zero(_STACK *st)

{
  if ((st != (_STACK *)0x0) && (0 < st->num)) {
    memset(st->data,0,st->num << 2);
    st->num = 0;
  }
  return;
}

