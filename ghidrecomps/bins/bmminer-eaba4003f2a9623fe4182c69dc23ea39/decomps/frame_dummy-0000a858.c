
void frame_dummy(void)

{
  if ((*DAT_0000a870 != 0) && (DAT_0000a874 != (code *)0x0)) {
    (*DAT_0000a874)();
  }
  register_tm_clones();
  return;
}

