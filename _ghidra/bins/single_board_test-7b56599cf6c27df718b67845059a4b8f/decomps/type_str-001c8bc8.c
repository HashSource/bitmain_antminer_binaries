
undefined4 type_str(uint param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  uVar3 = param_1;
  if ((int)param_1 < 0) {
    uVar3 = 0x7fffffff;
  }
  if (((int)(uVar2 << 0x1f) < 0) &&
     (iVar1 = ossl_ctype_check(uVar3,4,param_3,param_4,param_4), uVar3 != 0x20 && iVar1 == 0)) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  if (((int)(uVar2 << 0x1e) < 0) && (iVar1 = ossl_ctype_check(uVar3,0x800), iVar1 == 0)) {
    uVar2 = uVar2 & 0xfffffffd;
  }
  if (((int)(uVar2 << 0x1b) < 0) && ((uVar3 & 0xffffff80) != 0)) {
    uVar2 = uVar2 & 0xffffffef;
  }
  if (((uint)(0xff < param_1) & uVar2 >> 2) != 0) {
    uVar2 = uVar2 & 0xfffffffb;
  }
  if ((int)(uVar2 << 0x14) < 0) {
    if (param_1 < 0x10000) goto LAB_001c8c10;
    uVar2 = uVar2 & 0xfffff7ff;
  }
  if (uVar2 == 0) {
    return 0xffffffff;
  }
LAB_001c8c10:
  *param_2 = uVar2;
  return 1;
}

