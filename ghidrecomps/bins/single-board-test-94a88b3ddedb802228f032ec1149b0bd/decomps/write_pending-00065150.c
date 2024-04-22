
void write_pending(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  BIO *b;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x54);
  if ((param_3 < *(int *)(iVar4 + 0x14)) ||
     ((*(int *)(iVar4 + 0x18) != param_2 && (-1 < *(int *)(param_1 + 0x104) << 0x1e)))) {
    ERR_put_error(0x14,0xd4,0x7f,DAT_000651fc,0x1c8);
  }
  else {
    piVar1 = __errno_location();
    while( true ) {
      b = *(BIO **)(param_1 + 0x10);
      *piVar1 = 0;
      if (b == (BIO *)0x0) break;
      iVar3 = *(int *)(iVar4 + 0x1c);
      iVar2 = *(int *)(iVar4 + 0x38);
      iVar4 = *(int *)(iVar4 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = 2;
      iVar2 = BIO_write(b,(void *)(iVar2 + iVar3),iVar4);
      iVar4 = *(int *)(param_1 + 0x54);
      if (iVar2 == *(int *)(iVar4 + 0x20)) goto LAB_000651d8;
      if (iVar2 < 1) {
        return;
      }
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) - iVar2;
      *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + iVar2;
    }
    ERR_put_error(0x14,0xd4,0x104,DAT_000651fc,0x1d4);
    iVar4 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar4 + 0x20) == -1) {
LAB_000651d8:
      *(undefined4 *)(iVar4 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
  }
  return;
}

