
int mime_hdr_cmp(int **param_1,int **param_2)

{
  int iVar1;
  
  iVar1 = **param_2;
  if ((**param_1 != 0) && (iVar1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_LAB_00194368)();
    return iVar1;
  }
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  if (**param_1 == 0) {
    iVar1 = -iVar1;
  }
  else {
    iVar1 = 1 - iVar1;
  }
  return iVar1;
}

