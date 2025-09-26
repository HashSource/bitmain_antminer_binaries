
int paritition(char (*logs) [128],int left,int right)

{
  int iVar1;
  int right_local;
  int left_local;
  char (*logs_local) [128];
  char pivot [128];
  
  strncpy(pivot,logs[left],0x80);
  right_local = right;
  left_local = left;
  while (left_local < right_local) {
    while ((left_local < right_local && (iVar1 = strncmp(pivot,logs[right_local],0x80), -1 < iVar1))
          ) {
      right_local = right_local + -1;
    }
    if (left_local * 0x80 + right_local * -0x80 != 0) {
      strncpy(logs[left_local],logs[right_local],0x80);
    }
    while ((left_local < right_local && (iVar1 = strncmp(pivot,logs[left_local],0x80), iVar1 < 1)))
    {
      left_local = left_local + 1;
    }
    if (left_local * 0x80 + right_local * -0x80 != 0) {
      strncpy(logs[right_local],logs[left_local],0x80);
    }
  }
  strncpy(logs[left_local],pivot,0x80);
  return left_local;
}

