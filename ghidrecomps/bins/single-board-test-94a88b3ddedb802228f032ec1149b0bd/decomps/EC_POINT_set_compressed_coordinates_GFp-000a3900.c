
int EC_POINT_set_compressed_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,int y_bit,BN_CTX *ctx)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)group;
  if (((code *)puVar2[0x13] == (code *)0x0) && ((*puVar2 & 1) == 0)) {
    ERR_put_error(0x10,0x7d,0x42,DAT_000a3974,0x4e);
    iVar1 = 0;
  }
  else if (puVar2 == *(uint **)p) {
    if ((*puVar2 & 1) != 0) {
      if (puVar2[1] != 0x196) {
        iVar1 = ec_GF2m_simple_set_compressed_coordinates();
        return iVar1;
      }
      iVar1 = ec_GFp_simple_set_compressed_coordinates();
      return iVar1;
    }
    iVar1 = (*(code *)puVar2[0x13])();
  }
  else {
    ERR_put_error(0x10,0x7d,0x65,DAT_000a3974,0x53);
    iVar1 = 0;
  }
  return iVar1;
}

