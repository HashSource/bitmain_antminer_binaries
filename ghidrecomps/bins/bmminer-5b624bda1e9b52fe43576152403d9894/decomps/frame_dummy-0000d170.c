
void frame_dummy(void)

{
  if ((*DAT_0000d188 != 0) && (DAT_0000d18c != (code *)0x0)) {
    (*DAT_0000d18c)();
  }
  register_tm_clones();
  return;
}

