
ulong X509_issuer_name_hash_old(X509 *a)

{
  ulong uVar1;
  
  uVar1 = X509_NAME_hash_old(a->cert_info->issuer);
  return uVar1;
}

