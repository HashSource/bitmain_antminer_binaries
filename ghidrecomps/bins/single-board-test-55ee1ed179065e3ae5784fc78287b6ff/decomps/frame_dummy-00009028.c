
void frame_dummy(void)

{
  if ((*DAT_00009040 != 0) && (DAT_00009044 != (code *)0x0)) {
    (*DAT_00009044)();
  }
  register_tm_clones();
  return;
}

