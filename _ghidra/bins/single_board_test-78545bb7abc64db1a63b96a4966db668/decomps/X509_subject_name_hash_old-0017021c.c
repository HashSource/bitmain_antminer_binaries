
ulong X509_subject_name_hash_old(X509 *x)

{
  ulong uVar1;
  
  uVar1 = X509_NAME_hash_old((X509_NAME *)x->ex_flags);
  return uVar1;
}

