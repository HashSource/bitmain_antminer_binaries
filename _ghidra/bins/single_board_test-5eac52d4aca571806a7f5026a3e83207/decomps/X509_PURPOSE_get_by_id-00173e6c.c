
int X509_PURPOSE_get_by_id(int id)

{
  int iVar1;
  int local_24 [8];
  
  if (id - 1U < 9) {
    return id - 1U;
  }
  if (xptable != 0) {
    local_24[0] = id;
    iVar1 = OPENSSL_sk_find(xptable,local_24);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = iVar1 + 9;
    }
    return iVar1;
  }
  return -1;
}

