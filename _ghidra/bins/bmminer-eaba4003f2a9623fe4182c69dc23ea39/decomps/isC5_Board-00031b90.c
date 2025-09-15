
/* WARNING: Unknown calling convention */

_Bool isC5_Board(void)

{
  _Bool _Var1;
  FILE *__stream;
  char *pcVar2;
  char board_type [32];
  FILE *fd;
  int isC5;
  
  memset(board_type,0,0x20);
  __stream = fopen("/usr/bin/ctrl_bd","rb");
  if (__stream == (FILE *)0x0) {
    _Var1 = true;
  }
  else {
    fread(board_type,1,0x20,__stream);
    fclose(__stream);
    pcVar2 = strstr(board_type,"XILINX");
    if (pcVar2 == (char *)0x0) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  return _Var1;
}

