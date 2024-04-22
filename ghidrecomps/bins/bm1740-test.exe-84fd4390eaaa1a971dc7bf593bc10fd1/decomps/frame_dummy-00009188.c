
void frame_dummy(void)

{
  if ((*DAT_000091a0 != 0) && (DAT_000091a4 != (code *)0x0)) {
    (*DAT_000091a4)();
  }
  register_tm_clones();
  return;
}

