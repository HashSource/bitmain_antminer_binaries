
int BN_asc2bn(BIGNUM **a,char *str)

{
  char cVar1;
  int iVar2;
  char *str_00;
  
  cVar1 = *str;
  str_00 = str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    str_00 = str + 1;
  }
  if ((cVar1 == '0') && ((str_00[1] & 0xdfU) == 0x58)) {
    iVar2 = BN_hex2bn(a,str_00 + 2);
  }
  else {
    iVar2 = BN_dec2bn(a,str_00);
  }
  if (iVar2 == 0) {
    return 0;
  }
  if (*str == '-') {
    (*a)->neg = 1;
    return 1;
  }
  return 1;
}

