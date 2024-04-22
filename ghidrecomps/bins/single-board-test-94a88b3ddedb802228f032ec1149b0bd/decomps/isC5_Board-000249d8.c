
undefined isC5_Board(void)

{
  undefined uVar1;
  char *pcVar2;
  char acStack_34 [32];
  FILE *local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0;
  memset(acStack_34,0,0x20);
  local_14 = fopen("/usr/bin/ctrl_bd","rb");
  if (local_14 == (FILE *)0x0) {
    uVar1 = 1;
    local_10 = 0;
  }
  else {
    fread(acStack_34,1,0x20,local_14);
    fclose(local_14);
    pcVar2 = strstr(acStack_34,"XILINX");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(acStack_34,"7007");
      if (pcVar2 == (char *)0x0) {
        uVar1 = 1;
        local_10 = 0;
      }
      else {
        uVar1 = 0;
        local_10 = 1;
      }
    }
    else {
      uVar1 = 0;
      local_10 = 0;
    }
  }
  is7007_ctrl_board = local_10;
  return uVar1;
}

