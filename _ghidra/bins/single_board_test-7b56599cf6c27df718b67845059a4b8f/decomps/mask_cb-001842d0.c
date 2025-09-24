
undefined4 mask_cb(char *param_1,undefined *param_2,uint *param_3)

{
  undefined **ppuVar1;
  int iVar2;
  ulong uVar3;
  undefined *puVar4;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (param_2 == (undefined *)0x3) {
    iVar2 = strncmp(param_1,"DIR",3);
    if (iVar2 == 0) {
      *param_3 = *param_3 | 0x2906;
      return 1;
    }
  }
  else if (param_2 == (undefined *)0xffffffff) {
    param_2 = (undefined *)strlen(param_1);
  }
  puVar4 = (undefined *)0x4;
  tntmp_22592 = (undefined **)&tnst_22593;
  while ((ppuVar1 = tntmp_22592, param_2 != puVar4 ||
         (iVar2 = strncmp(*tntmp_22592,param_1,(size_t)param_2), iVar2 != 0))) {
    tntmp_22592 = ppuVar1 + 3;
    if (tntmp_22592 == &tag2str_10906) {
      return 0;
    }
    puVar4 = ppuVar1[4];
  }
  puVar4 = ppuVar1[2];
  if (((puVar4 != (undefined *)0x0) && (-1 < (int)puVar4 << 0xf)) &&
     (uVar3 = ASN1_tag2bit((int)puVar4), uVar3 != 0)) {
    *param_3 = uVar3 | *param_3;
    return 1;
  }
  return 0;
}

