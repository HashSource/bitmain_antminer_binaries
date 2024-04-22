
void register_tm_clones(void)

{
  if (((DAT_00009168 - DAT_00009164 >> 2) - (DAT_00009168 - DAT_00009164 >> 0x1f) >> 1 != 0) &&
     (DAT_0000916c != (code *)0x0)) {
    (*DAT_0000916c)();
  }
  return;
}

