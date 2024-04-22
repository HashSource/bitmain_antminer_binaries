
int conf_value_LHASH_COMP(char **param_1,char **param_2)

{
  int iVar1;
  
  if ((*param_1 == *param_2) || (iVar1 = strcmp(*param_1,*param_2), iVar1 == 0)) {
    if (param_1[1] == (char *)0x0) {
      if (param_2[1] == (char *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
    if (param_2[1] != (char *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_LAB_00194368)();
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

