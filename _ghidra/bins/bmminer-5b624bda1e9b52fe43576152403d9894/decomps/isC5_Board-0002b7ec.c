
/* WARNING: Unknown calling convention */

_Bool isC5_Board(void)

{
  FILE *__stream;
  char *pcVar1;
  char board_type [32];
  
  board_type[0] = '\0';
  board_type[1] = '\0';
  board_type[2] = '\0';
  board_type[3] = '\0';
  board_type[4] = '\0';
  board_type[5] = '\0';
  board_type[6] = '\0';
  board_type[7] = '\0';
  board_type[8] = '\0';
  board_type[9] = '\0';
  board_type[10] = '\0';
  board_type[0xb] = '\0';
  board_type[0xc] = '\0';
  board_type[0xd] = '\0';
  board_type[0xe] = '\0';
  board_type[0xf] = '\0';
  board_type[0x10] = '\0';
  board_type[0x11] = '\0';
  board_type[0x12] = '\0';
  board_type[0x13] = '\0';
  board_type[0x14] = '\0';
  board_type[0x15] = '\0';
  board_type[0x16] = '\0';
  board_type[0x17] = '\0';
  board_type[0x18] = '\0';
  board_type[0x19] = '\0';
  board_type[0x1a] = '\0';
  board_type[0x1b] = '\0';
  board_type[0x1c] = '\0';
  board_type[0x1d] = '\0';
  board_type[0x1e] = '\0';
  board_type[0x1f] = '\0';
  __stream = fopen("/usr/bin/ctrl_bd","rb");
  if (__stream != (FILE *)0x0) {
    fread(board_type,1,0x20,__stream);
    fclose(__stream);
    pcVar1 = strstr(board_type,"XILINX");
    if (pcVar1 != (char *)0x0) {
      return false;
    }
  }
  return true;
}

