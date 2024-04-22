
void scan_freq_done_mark(void)

{
  int iVar1;
  
  iVar1 = is7007_Board();
  if (iVar1 != 0) {
    system("touch /config/scanfreqdone");
  }
  return;
}

