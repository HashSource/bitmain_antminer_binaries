
int DH_size(DH *dh)

{
  int iVar1;
  int iVar2;
  
  iVar1 = BN_num_bits(dh->p);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}

