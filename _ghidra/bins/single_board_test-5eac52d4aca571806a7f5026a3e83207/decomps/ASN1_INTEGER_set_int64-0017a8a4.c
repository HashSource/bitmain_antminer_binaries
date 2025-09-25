
void ASN1_INTEGER_set_int64(ASN1_STRING *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_19 [5];
  
  param_1->type = 2;
  if ((int)param_4 < 0) {
    iVar5 = 8;
    puVar1 = local_19;
    uVar4 = -param_3;
    uVar6 = -param_4 - (uint)(param_3 != 0);
    do {
      puVar2 = puVar1;
      uVar7 = uVar6 >> 8;
      uVar3 = uVar4 >> 8 | uVar6 << 0x18;
      *puVar2 = (char)uVar4;
      iVar5 = iVar5 + -1;
      puVar1 = puVar2 + -1;
      uVar4 = uVar3;
      uVar6 = uVar7;
    } while (uVar3 != 0 || uVar7 != 0);
    param_1->type = 0x102;
    ASN1_STRING_set(param_1,puVar2,8 - iVar5);
    return;
  }
  iVar5 = 8;
  puVar1 = local_19;
  do {
    puVar2 = puVar1;
    uVar6 = param_4 >> 8;
    uVar4 = param_3 >> 8 | param_4 << 0x18;
    *puVar2 = (char)param_3;
    iVar5 = iVar5 + -1;
    param_3 = uVar4;
    param_4 = uVar6;
    puVar1 = puVar2 + -1;
  } while (uVar4 != 0 || uVar6 != 0);
  ASN1_STRING_set(param_1,puVar2,8 - iVar5);
  return;
}

