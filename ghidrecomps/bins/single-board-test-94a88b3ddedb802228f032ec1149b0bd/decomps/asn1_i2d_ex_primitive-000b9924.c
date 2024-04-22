
int asn1_i2d_ex_primitive
              (ASN1_VALUE **param_1,uchar **param_2,ASN1_ITEM *param_3,uint param_4,int param_5)

{
  bool bVar1;
  int length;
  int constructed;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  uint local_2c [2];
  
  local_2c[0] = param_3->utype;
  length = asn1_ex_i2c(param_1,(uchar *)0x0,(int *)local_2c,param_3);
  uVar2 = local_2c[0] - 0x10;
  bVar4 = 0xfffffffc < local_2c[0];
  bVar3 = local_2c[0] != 0xfffffffd;
  if (bVar3) {
    bVar4 = uVar2 != 0;
  }
  bVar1 = uVar2 != 1;
  if (bVar4 && (bVar3 && bVar1)) {
    uVar2 = 0;
  }
  if (!bVar4 || (!bVar3 || !bVar1)) {
    uVar2 = 1;
  }
  if (length == -1) {
    length = 0;
  }
  else {
    if (length == -2) {
      constructed = 2;
      length = 0;
    }
    else {
      constructed = 0;
    }
    if (param_4 == 0xffffffff) {
      param_4 = local_2c[0];
    }
    if (param_2 != (uchar **)0x0) {
      if ((uVar2 ^ 1) != 0) {
        ASN1_put_object(param_2,constructed,length,param_4,param_5);
      }
      asn1_ex_i2c(param_1,*param_2,(int *)local_2c,param_3);
      if (constructed == 0) {
        *param_2 = *param_2 + length;
      }
      else {
        ASN1_put_eoc(param_2);
      }
    }
    if ((uVar2 ^ 1) != 0) {
      length = ASN1_object_size(constructed,length,param_4);
    }
  }
  return length;
}

