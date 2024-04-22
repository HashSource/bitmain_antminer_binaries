
undefined4 scan_freq_already_done(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  
  iVar1 = is7007_Board();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    __stream = fopen("/config/scanfreqdone","r");
    if (__stream == (FILE *)0x0) {
      uVar2 = 0;
    }
    else {
      fclose(__stream);
      uVar2 = 1;
    }
  }
  return uVar2;
}

