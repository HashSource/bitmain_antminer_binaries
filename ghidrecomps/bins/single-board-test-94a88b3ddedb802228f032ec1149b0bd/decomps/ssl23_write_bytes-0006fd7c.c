
int ssl23_write_bytes(int param_1)

{
  int iVar1;
  int len;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x48);
  len = *(int *)(param_1 + 0x44);
  iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  while( true ) {
    *(undefined4 *)(param_1 + 0x18) = 2;
    iVar1 = BIO_write(*(BIO **)(param_1 + 0x10),(void *)(iVar3 + iVar2),len);
    if (iVar1 < 1) {
      *(int *)(param_1 + 0x48) = iVar2;
      *(int *)(param_1 + 0x44) = len;
      return iVar1;
    }
    *(undefined4 *)(param_1 + 0x18) = 1;
    if (iVar1 == len) break;
    len = len - iVar1;
    iVar2 = iVar2 + iVar1;
  }
  return len + iVar2;
}

