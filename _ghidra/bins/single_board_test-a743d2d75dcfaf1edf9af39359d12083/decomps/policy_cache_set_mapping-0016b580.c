
undefined4 policy_cache_set_mapping(int param_1,_STACK *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *data;
  _STACK *st;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x40);
  iVar1 = sk_num(param_2);
  if (iVar1 == 0) {
LAB_0016b638:
    uVar5 = 0xffffffff;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x800;
  }
  else {
    for (iVar1 = 0; iVar2 = sk_num(param_2), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      puVar3 = (undefined4 *)sk_value(param_2,iVar1);
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)puVar3[1]);
      if ((iVar2 == 0x2ea) || (iVar2 = OBJ_obj2nid((ASN1_OBJECT *)*puVar3), iVar2 == 0x2ea))
      goto LAB_0016b638;
      data = (uint *)policy_cache_find_data(piVar6,*puVar3);
      if (data == (uint *)0x0) {
        if ((uint *)*piVar6 != (uint *)0x0) {
          data = (uint *)policy_data_new(0,*puVar3,*(uint *)*piVar6 & 0x10);
          if (data == (uint *)0x0) goto LAB_0016b65a;
          st = (_STACK *)piVar6[1];
          uVar4 = *(uint *)(*piVar6 + 8);
          *data = *data | 6;
          data[2] = uVar4;
          iVar2 = sk_push(st,data);
          if (iVar2 != 0) goto LAB_0016b5a8;
          policy_data_free(data);
          uVar5 = 0;
          goto LAB_0016b648;
        }
      }
      else {
        *data = *data | 1;
LAB_0016b5a8:
        iVar2 = sk_push((_STACK *)data[3],(void *)puVar3[1]);
        if (iVar2 == 0) {
LAB_0016b65a:
          uVar5 = 0;
          goto LAB_0016b648;
        }
        puVar3[1] = 0;
      }
    }
    uVar5 = 1;
  }
LAB_0016b648:
  sk_pop_free(param_2,(func *)0x16a2d1);
  return uVar5;
}

