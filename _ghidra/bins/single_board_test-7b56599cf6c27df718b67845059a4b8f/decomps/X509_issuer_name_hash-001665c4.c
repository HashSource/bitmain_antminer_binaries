
ulong X509_issuer_name_hash(X509 *a)

{
  ulong uVar1;
  
  uVar1 = X509_NAME_hash((X509_NAME *)(a->ex_data).dummy);
  return uVar1;
}

