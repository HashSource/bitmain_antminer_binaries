
void register_tm_clones(void)

{
  if (((DAT_0000862c - DAT_00008628 >> 2) - (DAT_0000862c - DAT_00008628 >> 0x1f) >> 1 != 0) &&
     (DAT_00008630 != (code *)0x0)) {
    (*DAT_00008630)();
  }
  return;
}

