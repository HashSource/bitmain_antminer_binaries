
int X509_TRUST_get_by_id(int id)

{
  int iVar1;
  int local_20 [7];
  
  if (id - 1U < 8) {
    return id - 1U;
  }
  if (trtable != 0) {
    local_20[0] = id;
    iVar1 = OPENSSL_sk_find(trtable,local_20);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = iVar1 + 8;
    }
    return iVar1;
  }
  return -1;
}

