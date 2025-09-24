
bool ssl_cipher_disabled(int param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x7c);
  if ((((*(uint *)(param_2 + 0x10) & *(uint *)(iVar2 + 0x2a0)) == 0) &&
      ((*(uint *)(param_2 + 0x14) & *(uint *)(iVar2 + 0x2a4)) == 0)) &&
     (iVar3 = *(int *)(iVar2 + 0x2ac), iVar3 != 0)) {
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      iVar4 = *(int *)(param_2 + 0x28);
      if (iVar4 == 0x100) {
        if (iVar3 != 0x100) {
          iVar4 = 0xff00;
          goto LAB_000fb294;
        }
      }
      else {
        if (iVar3 == 0x100) {
          iVar3 = 0xff00;
        }
LAB_000fb294:
        if (iVar4 < iVar3) goto LAB_000fb2b2;
      }
      iVar3 = *(int *)(param_2 + 0x2c);
      iVar2 = *(int *)(iVar2 + 0x2a8);
      if (iVar3 == 0x100) {
        if (iVar2 == 0x100) goto LAB_000fb26a;
        iVar3 = 0xff00;
      }
      else if (iVar2 == 0x100) {
        iVar2 = 0xff00;
      }
      if (iVar2 < iVar3) goto LAB_000fb2b2;
    }
    else {
      iVar4 = *(int *)(param_2 + 0x20);
      if (param_4 != 0 && iVar4 == 0x301) {
        if ((*(uint *)(param_2 + 0x10) & 0x84) == 0) {
          iVar4 = 0x301;
        }
        else {
          iVar4 = 0x300;
        }
      }
      if ((iVar3 < iVar4) || (*(int *)(param_2 + 0x24) < *(int *)(iVar2 + 0x2a8)))
      goto LAB_000fb2b2;
    }
LAB_000fb26a:
    iVar2 = ssl_security(param_1,param_3,*(undefined4 *)(param_2 + 0x38),0,param_2);
    bVar1 = iVar2 == 0;
  }
  else {
LAB_000fb2b2:
    bVar1 = true;
  }
  return bVar1;
}

