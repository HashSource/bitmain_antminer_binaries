
void obj_name_LHASH_COMP(int *param_1,int *param_2)

{
  _STACK **pp_Var1;
  int iVar2;
  void *pvVar3;
  
  pp_Var1 = DAT_0008ba84;
  if (*param_1 != *param_2) {
    return;
  }
  if (*DAT_0008ba84 != (_STACK *)0x0) {
    iVar2 = sk_num(*DAT_0008ba84);
    if (*param_1 < iVar2) {
      pvVar3 = sk_value(*pp_Var1,*param_1);
      (**(code **)((int)pvVar3 + 4))(param_1[2],param_2[2]);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_00194368)(param_1[2],param_2[2]);
  return;
}

