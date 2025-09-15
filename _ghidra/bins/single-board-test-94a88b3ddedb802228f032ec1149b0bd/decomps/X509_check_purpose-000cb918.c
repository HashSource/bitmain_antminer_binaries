
int X509_check_purpose(X509 *x,int id,int ca)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int local_2c [7];
  
  if (-1 < (int)(x->ex_flags << 0x17)) {
    CRYPTO_lock(9,3,"v3_purp.c",0x84);
    if (-1 < (int)(x->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_7(x);
    }
    CRYPTO_lock(10,3,"v3_purp.c",0x86);
  }
  if (id == -1) {
    return 1;
  }
  uVar1 = id - 1;
  if (8 < uVar1) {
    if ((xptable == (_STACK *)0x0) ||
       (local_2c[0] = id, iVar2 = sk_find(xptable,local_2c), iVar2 == -1)) {
      return -1;
    }
    uVar1 = iVar2 + 9;
    if (iVar2 == -10) {
      return uVar1;
    }
    if ((int)uVar1 < 0) {
      puVar3 = (undefined1 *)0x0;
      goto LAB_000cb968;
    }
  }
  if ((int)uVar1 < 9) {
    puVar3 = &xstandard + uVar1 * 0x1c;
  }
  else {
    puVar3 = (undefined1 *)sk_value(xptable,uVar1 - 9);
  }
LAB_000cb968:
  iVar2 = (**(code **)(puVar3 + 0xc))(puVar3,x,ca);
  return iVar2;
}

