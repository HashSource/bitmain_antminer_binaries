
void frame_dummy(void)

{
  if ((*DAT_00008b60 != 0) && (DAT_00008b64 != (code *)0x0)) {
    (*DAT_00008b64)();
  }
  register_tm_clones();
  return;
}

