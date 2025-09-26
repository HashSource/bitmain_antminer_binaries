
undefined4 conf_ssl_get(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = ssl_names + param_1 * 0xc;
  uVar1 = *(undefined4 *)(iVar2 + 8);
  *param_2 = *(undefined4 *)(ssl_names + param_1 * 0xc);
  *param_3 = uVar1;
  return *(undefined4 *)(iVar2 + 4);
}

