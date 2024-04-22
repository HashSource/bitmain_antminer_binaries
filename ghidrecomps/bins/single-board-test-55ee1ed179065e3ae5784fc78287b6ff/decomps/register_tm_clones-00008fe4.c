
void register_tm_clones(void)

{
  if (((DAT_00009008 - DAT_00009004 >> 2) - (DAT_00009008 - DAT_00009004 >> 0x1f) >> 1 != 0) &&
     (DAT_0000900c != (code *)0x0)) {
    (*DAT_0000900c)();
  }
  return;
}

