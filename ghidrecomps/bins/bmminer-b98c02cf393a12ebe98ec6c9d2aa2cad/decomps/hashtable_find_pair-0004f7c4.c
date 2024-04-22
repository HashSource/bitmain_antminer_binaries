
int hashtable_find_pair(int param_1,int *param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if ((iVar2 != param_1 + 0xc) || (iVar2 != param_2[1])) {
    while( true ) {
      if ((*(int *)(iVar2 + 0x10) == param_4) &&
         (iVar1 = strcmp((char *)(iVar2 + 0x18),param_3), iVar1 == 0)) {
        return iVar2;
      }
      if (iVar2 == param_2[1]) break;
      iVar2 = *(int *)(iVar2 + 4);
    }
  }
  return 0;
}

