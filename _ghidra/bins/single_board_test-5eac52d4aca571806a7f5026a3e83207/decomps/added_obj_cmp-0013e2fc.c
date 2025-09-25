
int added_obj_cmp(int *param_1,int *param_2)

{
  int *piVar1;
  char *__s1;
  int *piVar2;
  char *__s2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 - *param_2 != 0) {
    return iVar3 - *param_2;
  }
  piVar1 = (int *)param_1[1];
  piVar2 = (int *)param_2[1];
  switch(iVar3) {
  case 0:
    iVar3 = piVar1[3] - piVar2[3];
    if (iVar3 == 0) {
      iVar3 = memcmp((void *)piVar1[4],(void *)piVar2[4],piVar1[3]);
      return iVar3;
    }
    break;
  case 1:
    __s1 = (char *)*piVar1;
    if (__s1 != (char *)0x0) {
      __s2 = (char *)*piVar2;
      if (__s2 == (char *)0x0) {
        return iVar3;
      }
LAB_0013e344:
      iVar3 = strcmp(__s1,__s2);
      return iVar3;
    }
    goto LAB_0013e35a;
  case 2:
    __s1 = (char *)piVar1[1];
    if (__s1 != (char *)0x0) {
      __s2 = (char *)piVar2[1];
      if (__s2 == (char *)0x0) {
        return 1;
      }
      goto LAB_0013e344;
    }
LAB_0013e35a:
    iVar3 = -1;
    break;
  case 3:
    iVar3 = piVar1[2] - piVar2[2];
    break;
  default:
    iVar3 = 0;
  }
  return iVar3;
}

