
/* WARNING: Unknown calling convention */

clib_bool empty_c_rb(clib_rb *pTree)

{
  int iVar1;
  
  iVar1 = (int)pTree->root - (int)&pTree->sentinel;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

