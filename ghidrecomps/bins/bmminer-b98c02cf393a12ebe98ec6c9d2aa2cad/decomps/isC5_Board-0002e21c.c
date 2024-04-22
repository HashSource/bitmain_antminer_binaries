
undefined4 isC5_Board(void)

{
  FILE *__stream;
  char *pcVar1;
  undefined4 uVar2;
  char acStack_28 [32];
  
  memset(acStack_28,0,0x20);
  __stream = fopen("/usr/bin/ctrl_bd","rb");
  if (__stream == (FILE *)0x0) {
    is7007_ctrl_board = 0;
    return 1;
  }
  fread(acStack_28,1,0x20,__stream);
  fclose(__stream);
  pcVar1 = strstr(acStack_28,"XILINX");
  uVar2 = 0;
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strstr(acStack_28,"7007");
    uVar2 = 1;
    if (pcVar1 == (char *)0x0) {
      is7007_ctrl_board = 0;
      return 1;
    }
  }
  is7007_ctrl_board = uVar2;
  return 0;
}

