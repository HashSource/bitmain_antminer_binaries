
undefined4 file_gets(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  
  *param_2 = '\0';
  pcVar2 = fgets(param_2,param_3,*(FILE **)(param_1 + 0x20));
  if ((pcVar2 != (char *)0x0) && (*param_2 != '\0')) {
    uVar1 = (*(code *)PTR_strlen_00194240)(param_2);
    return uVar1;
  }
  return 0;
}

