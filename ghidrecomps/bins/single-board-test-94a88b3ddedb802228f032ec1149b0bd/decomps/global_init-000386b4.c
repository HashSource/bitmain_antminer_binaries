
undefined4 global_init(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  piVar1 = DAT_00038704;
  iVar7 = *DAT_00038704;
  *DAT_00038704 = iVar7 + 1;
  uVar6 = DAT_0003871c;
  uVar5 = DAT_00038718;
  uVar4 = DAT_00038714;
  uVar3 = DAT_00038710;
  puVar2 = DAT_00038708;
  if (iVar7 != 0) {
    return 0;
  }
  if (param_2 != 0) {
    *DAT_00038708 = DAT_0003870c;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    puVar2[4] = uVar6;
  }
  if ((param_1 << 0x1f < 0) && (iVar7 = Curl_ssl_init(), iVar7 == 0)) {
    return 2;
  }
  if (param_1 << 0x1d < 0) {
    *DAT_00038720 = 1;
  }
  piVar1[1] = param_1;
  Curl_version_init();
  return 0;
}

