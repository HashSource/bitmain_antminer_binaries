
undefined4 X509_check_ip_asc(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_48 [2];
  int local_40 [2];
  int local_38 [2];
  int local_30 [2];
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  
  if (param_2 == (char *)0x0) {
LAB_000c8422:
    uVar3 = 0xfffffffe;
  }
  else {
    pcVar1 = strchr(param_2,0x3a);
    if (pcVar1 == (char *)0x0) {
      iVar2 = __isoc99_sscanf(param_2,DAT_000c845c,local_48,local_40,local_38,local_30);
      if (((((iVar2 != 4) || (0xff < local_48[0])) || (local_40[0] < 0)) ||
          ((0xff < local_40[0] || (local_38[0] < 0)))) ||
         ((0xff < local_38[0] || ((local_30[0] < 0 || (0xff < local_30[0])))))) goto LAB_000c8422;
      uVar3 = 4;
      local_28 = (undefined)local_48[0];
      local_27 = (undefined)local_40[0];
      local_26 = (undefined)local_38[0];
      local_25 = (undefined)local_30[0];
    }
    else {
      iVar2 = ipv6_from_asc(&local_28,param_2);
      uVar3 = 0x10;
      if (iVar2 == 0) goto LAB_000c8422;
    }
    uVar3 = do_x509_check_constprop_4(param_1,&local_28,uVar3,param_3);
  }
  return uVar3;
}

