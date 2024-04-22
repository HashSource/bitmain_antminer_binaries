
void register_tm_clones(void)

{
  if (((DAT_0000a838 - DAT_0000a834 >> 2) - (DAT_0000a838 - DAT_0000a834 >> 0x1f) >> 1 != 0) &&
     (DAT_0000a83c != (code *)0x0)) {
    (*DAT_0000a83c)();
  }
  return;
}

