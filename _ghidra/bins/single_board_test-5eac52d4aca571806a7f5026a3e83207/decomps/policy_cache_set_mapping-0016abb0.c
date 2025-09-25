
undefined4 policy_cache_set_mapping(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_1 + 0x98);
  iVar1 = OPENSSL_sk_num(param_2);
  if (iVar1 == 0) {
LAB_0016ac6e:
    uVar6 = 0xffffffff;
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x800;
  }
  else {
    for (iVar1 = 0; iVar2 = OPENSSL_sk_num(param_2), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_2,iVar1);
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)puVar3[1]);
      if ((iVar2 == 0x2ea) || (iVar2 = OBJ_obj2nid((ASN1_OBJECT *)*puVar3), iVar2 == 0x2ea))
      goto LAB_0016ac6e;
      puVar4 = (uint *)policy_cache_find_data(piVar7,*puVar3);
      if (puVar4 == (uint *)0x0) {
        if ((uint *)*piVar7 != (uint *)0x0) {
          puVar4 = (uint *)policy_data_new(0,*puVar3,*(uint *)*piVar7 & 0x10);
          if (puVar4 == (uint *)0x0) goto LAB_0016ac96;
          uVar5 = *(uint *)(*piVar7 + 8);
          *puVar4 = *puVar4 | 6;
          puVar4[2] = uVar5;
          iVar2 = OPENSSL_sk_push(piVar7[1],puVar4);
          if (iVar2 != 0) goto LAB_0016abe0;
          policy_data_free(puVar4);
          uVar6 = 0;
          goto LAB_0016ac7e;
        }
      }
      else {
        *puVar4 = *puVar4 | 1;
LAB_0016abe0:
        iVar2 = OPENSSL_sk_push(puVar4[3],puVar3[1]);
        if (iVar2 == 0) {
LAB_0016ac96:
          uVar6 = 0;
          goto LAB_0016ac7e;
        }
        puVar3[1] = 0;
      }
    }
    uVar6 = 1;
  }
LAB_0016ac7e:
  OPENSSL_sk_pop_free(param_2,0x1733a9);
  return uVar6;
}

