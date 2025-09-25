
size_t EC_POINT_point2oct(EC_GROUP *group,EC_POINT *p,point_conversion_form_t form,uchar *buf,
                         size_t len,BN_CTX *ctx)

{
  size_t sVar1;
  int *piVar2;
  
  piVar2 = *(int **)group;
  if (((code *)piVar2[0x15] == (code *)0x0) && (-1 < *piVar2 << 0x1f)) {
    ERR_put_error(0x10,0x7b,0x42,"crypto/ec/ec_oct.c",0x4c);
  }
  else {
    if ((piVar2 == *(int **)p) &&
       ((*(int *)(group + 0x10) == 0 ||
        (*(int *)(group + 0x10) == *(int *)(p + 4) || *(int *)(p + 4) == 0)))) {
      if (-1 < *piVar2 << 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x0011c482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        sVar1 = (*(code *)piVar2[0x15])();
        return sVar1;
      }
      if (piVar2[1] != 0x196) {
        sVar1 = ec_GF2m_simple_point2oct();
        return sVar1;
      }
      sVar1 = ec_GFp_simple_point2oct();
      return sVar1;
    }
    ERR_put_error(0x10,0x7b,0x65,"crypto/ec/ec_oct.c",0x50);
  }
  return 0;
}

