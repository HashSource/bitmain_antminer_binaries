
ulong lh_num_items(_LHASH *lh)

{
  if (lh != (_LHASH *)0x0) {
    lh = (_LHASH *)lh->num_items;
  }
  return (ulong)lh;
}

