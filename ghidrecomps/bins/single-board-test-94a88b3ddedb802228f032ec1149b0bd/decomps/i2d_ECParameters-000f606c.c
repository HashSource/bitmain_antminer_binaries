
int i2d_ECParameters(EC_KEY *key,uchar **out)

{
  int iVar1;
  
  if (key != (EC_KEY *)0x0) {
    iVar1 = i2d_ECPKParameters(*(EC_GROUP **)(key + 4),out);
    return iVar1;
  }
  ERR_put_error(0x10,0xbe,0x43,DAT_000f6098,0x4c7);
  return 0;
}

