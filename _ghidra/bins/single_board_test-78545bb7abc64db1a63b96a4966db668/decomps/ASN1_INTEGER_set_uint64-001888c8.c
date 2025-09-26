
void ASN1_INTEGER_set_uint64(ASN1_STRING *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *data;
  int iVar3;
  uint uVar4;
  undefined1 local_19 [5];
  
  iVar3 = 8;
  param_1->type = 2;
  puVar1 = local_19;
  do {
    data = puVar1;
    uVar4 = param_4 >> 8;
    uVar2 = param_3 >> 8 | param_4 << 0x18;
    *data = (char)param_3;
    iVar3 = iVar3 + -1;
    param_3 = uVar2;
    param_4 = uVar4;
    puVar1 = data + -1;
  } while (uVar2 != 0 || uVar4 != 0);
  ASN1_STRING_set(param_1,data,8 - iVar3);
  return;
}

