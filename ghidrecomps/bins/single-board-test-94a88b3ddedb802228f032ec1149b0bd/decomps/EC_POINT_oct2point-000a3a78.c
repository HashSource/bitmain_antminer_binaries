
int EC_POINT_oct2point(EC_GROUP *group,EC_POINT *p,uchar *buf,size_t len,BN_CTX *ctx)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)group;
  if (((code *)puVar2[0x15] == (code *)0x0) && ((*puVar2 & 1) == 0)) {
    ERR_put_error(0x10,0x7a,0x42,DAT_000a3aec,0xab);
    iVar1 = 0;
  }
  else if (puVar2 == *(uint **)p) {
    if ((*puVar2 & 1) != 0) {
      if (puVar2[1] != 0x196) {
        iVar1 = ec_GF2m_simple_oct2point();
        return iVar1;
      }
      iVar1 = ec_GFp_simple_oct2point();
      return iVar1;
    }
    iVar1 = (*(code *)puVar2[0x15])();
  }
  else {
    ERR_put_error(0x10,0x7a,0x65,DAT_000a3aec,0xaf);
    iVar1 = 0;
  }
  return iVar1;
}

