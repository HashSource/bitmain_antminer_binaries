
BIGNUM * hashsum2bn(int param_1)

{
  undefined *puVar1;
  BIGNUM *a;
  int len;
  uchar *s;
  undefined *puVar2;
  uchar local_28 [32];
  
  puVar2 = &stack0xfffffff8;
  s = local_28;
  puVar1 = (undefined *)(param_1 + -1);
  do {
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + -1;
    *puVar2 = *puVar1;
  } while (puVar2 != local_28);
  if (local_28[0] == '\0') {
    len = 0x20;
    s = local_28;
    do {
      s = s + 1;
      len = len + -1;
      if (*s != '\0') {
        if (len != 0) goto LAB_000e0678;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
  }
  else {
    len = 0x20;
LAB_000e0678:
    a = BN_bin2bn(s,len,(BIGNUM *)0x0);
  }
  return a;
}

