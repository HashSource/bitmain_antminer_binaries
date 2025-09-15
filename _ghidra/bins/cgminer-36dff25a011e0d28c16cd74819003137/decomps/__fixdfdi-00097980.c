
int __fixdfdi(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (0.0 <= (double)CONCAT44(param_2,param_1)) {
    iVar1 = __fixunsdfdi();
    return iVar1;
  }
  iVar1 = __fixunsdfdi(param_1,param_2 ^ 0x80000000);
  return -iVar1;
}

