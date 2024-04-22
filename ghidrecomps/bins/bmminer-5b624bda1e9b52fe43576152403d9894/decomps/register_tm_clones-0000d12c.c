
void register_tm_clones(void)

{
  if (((DAT_0000d150 - DAT_0000d14c >> 2) - (DAT_0000d150 - DAT_0000d14c >> 0x1f) >> 1 != 0) &&
     (DAT_0000d154 != (code *)0x0)) {
    (*DAT_0000d154)();
  }
  return;
}

