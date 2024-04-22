
int X509_PURPOSE_get_by_id(int id)

{
  int iVar1;
  uint uVar2;
  int local_24 [9];
  
  uVar2 = id - 1;
  if (8 < uVar2) {
    if ((*DAT_000cbad8 == (_STACK *)0x0) ||
       (local_24[0] = id, iVar1 = sk_find(*DAT_000cbad8,local_24), iVar1 == -1)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = iVar1 + 9;
    }
  }
  return uVar2;
}

