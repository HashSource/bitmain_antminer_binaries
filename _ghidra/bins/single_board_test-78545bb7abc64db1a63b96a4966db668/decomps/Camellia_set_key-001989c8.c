
int Camellia_set_key(uchar *userKey,int bits,CAMELLIA_KEY *key)

{
  int iVar1;
  int iVar2;
  
  if (key == (CAMELLIA_KEY *)0x0 || userKey == (uchar *)0x0) {
    return -1;
  }
  if ((bits & 0xffffffbfU) == 0x80 || bits == 0x100) {
    iVar2 = 0;
    iVar1 = Camellia_Ekeygen(bits,userKey);
    key->grand_rounds = iVar1;
  }
  else {
    iVar2 = -2;
  }
  return iVar2;
}

