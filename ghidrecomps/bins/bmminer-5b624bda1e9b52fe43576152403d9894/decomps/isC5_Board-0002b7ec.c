
/* WARNING: Unknown calling convention */

_Bool isC5_Board(void)

{
  FILE *__stream;
  FILE *fd;
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
  board_type[11] = '\0';
  board_type[12] = '\0';
  board_type[13] = '\0';
  board_type[14] = '\0';
  board_type[15] = '\0';
  board_type[16] = '\0';
  board_type[17] = '\0';
  board_type[18] = '\0';
  board_type[19] = '\0';
  board_type[20] = '\0';
  board_type[21] = '\0';
  board_type[22] = '\0';
  board_type[23] = '\0';
  board_type[24] = '\0';
  board_type[25] = '\0';
  board_type[26] = '\0';
  board_type[27] = '\0';
  board_type[28] = '\0';
  board_type[29] = '\0';
  board_type[30] = '\0';
  board_type[31] = '\0';
  __stream = fopen(DAT_0002b834,DAT_0002b838);
  if (__stream != (FILE *)0x0) {
    fread(board_type,1,0x20,__stream);
    fclose(__stream);
    pcVar1 = strstr(board_type,DAT_0002b83c);
    if (pcVar1 != (char *)0x0) {
      return false;
    }
  }
  return true;
}

