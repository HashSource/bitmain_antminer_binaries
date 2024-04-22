
size_t EC_POINT_point2oct(EC_GROUP *group,EC_POINT *p,point_conversion_form_t form,uchar *buf,
                         size_t len,BN_CTX *ctx)

{
  size_t sVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)group;
  if (((code *)puVar2[0x14] == (code *)0x0) && ((*puVar2 & 1) == 0)) {
    ERR_put_error(0x10,0x7b,0x42,DAT_000a3a74,0x8d);
    sVar1 = 0;
  }
  else if (puVar2 == *(uint **)p) {
    if ((*puVar2 & 1) != 0) {
      if (puVar2[1] != 0x196) {
        sVar1 = ec_GF2m_simple_point2oct();
        return sVar1;
      }
      sVar1 = ec_GFp_simple_point2oct();
      return sVar1;
    }
    sVar1 = (*(code *)puVar2[0x14])();
  }
  else {
    ERR_put_error(0x10,0x7b,0x65,DAT_000a3a74,0x91);
    sVar1 = 0;
  }
  return sVar1;
}

