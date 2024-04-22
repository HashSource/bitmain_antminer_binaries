
void register_tm_clones(void)

{
  if (((DAT_00008b28 - DAT_00008b24 >> 2) - (DAT_00008b28 - DAT_00008b24 >> 0x1f) >> 1 != 0) &&
     (DAT_00008b2c != (code *)0x0)) {
    (*DAT_00008b2c)();
  }
  return;
}

