
void obj_cmp_BSEARCH_CMP_FN(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0008c120 + *param_2 * 0x18;
  iVar1 = *(int *)(*param_1 + 0xc);
  if ((iVar1 == *(int *)(iVar2 + 0xc)) && (iVar1 != 0)) {
    (*(code *)PTR_memcmp_00194160)(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(iVar2 + 0x10));
    return;
  }
  return;
}

