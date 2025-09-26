
void split_x_y(char combined,char *x,char *y)

{
  byte bVar1;
  int iVar2;
  char *y_local;
  char *x_local;
  char combined_local;
  int y_val;
  int x_val;
  int combined_val;
  
  iVar2 = (byte)combined - 0x41;
  bVar1 = (byte)iVar2 & 1;
  if (iVar2 < 0) {
    bVar1 = -bVar1;
  }
  *x = (char)(iVar2 / 2) + '1';
  *y = bVar1 + 0x31;
  return;
}

