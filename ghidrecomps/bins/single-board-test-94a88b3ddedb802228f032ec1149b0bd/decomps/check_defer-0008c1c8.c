
void check_defer(int nid)

{
  if ((*DAT_0008c1dc == 0) && (0x3bd < nid)) {
    *DAT_0008c1dc = 1;
  }
  return;
}

