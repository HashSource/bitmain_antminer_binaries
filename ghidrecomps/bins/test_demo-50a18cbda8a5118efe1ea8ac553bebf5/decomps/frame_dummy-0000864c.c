
void frame_dummy(void)

{
  if ((*DAT_00008664 != 0) && (DAT_00008668 != (code *)0x0)) {
    (*DAT_00008668)();
  }
  register_tm_clones();
  return;
}

