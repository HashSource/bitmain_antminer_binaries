
int X509_TRUST_get_by_id(int id)

{
  int iVar1;
  uint uVar2;
  int local_20 [8];
  
  uVar2 = id - 1;
  if (7 < uVar2) {
    if ((*DAT_000c511c == (_STACK *)0x0) ||
       (local_20[0] = id, iVar1 = sk_find(*DAT_000c511c,local_20), iVar1 == -1)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = iVar1 + 8;
    }
  }
  return uVar2;
}

