
int X509_check_ca(X509 *x)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  x509v3_cache_extensions();
  uVar3 = x[1].references;
  if (((uVar3 & 2) == 0) || (uVar1 = (uint)x[1].name & 4, uVar1 != 0)) {
    if ((int)(uVar3 << 0x1f) < 0) {
      return (uVar3 << 0x1b) >> 0x1f;
    }
    if ((uVar3 & 0x2040) == 0x2040) {
      return 3;
    }
    if ((uVar3 & 2) != 0) {
      return 4;
    }
    if ((int)(uVar3 << 0x1c) < 0) {
      if ((x[1].ex_data.dummy & 7U) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 5;
      }
      return iVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}

