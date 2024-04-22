
int RSA_size(RSA *rsa)

{
  int iVar1;
  int iVar2;
  
  iVar1 = BN_num_bits(rsa->n);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}

