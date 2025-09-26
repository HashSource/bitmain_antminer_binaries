
bool ssl_cert_is_disabled(void)

{
  int iVar1;
  
  iVar1 = ssl_cert_lookup_by_idx();
  if (iVar1 == 0) {
    return true;
  }
  return (*(uint *)(iVar1 + 4) & disabled_auth_mask) != 0;
}

