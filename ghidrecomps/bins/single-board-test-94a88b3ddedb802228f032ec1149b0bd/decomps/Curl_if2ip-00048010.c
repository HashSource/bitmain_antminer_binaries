
int Curl_if2ip(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  void *__cp;
  int *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  char acStack_68 [68];
  
  iVar1 = getifaddrs(&local_78);
  if (iVar1 < 0) {
    return 0;
  }
  if (local_78 == (int *)0x0) {
    iVar1 = 0;
LAB_00048064:
    freeifaddrs(local_78);
    return iVar1;
  }
  iVar1 = 0;
  piVar4 = local_78;
LAB_0004803e:
  if ((ushort *)piVar4[3] != (ushort *)0x0) {
    if (*(ushort *)piVar4[3] != param_1) {
      if (iVar1 != 0) goto LAB_00048038;
      iVar1 = curl_strequal(piVar4[1],param_4);
      piVar4 = (int *)*piVar4;
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      goto joined_r0x00048060;
    }
    iVar2 = curl_strequal(piVar4[1],param_4);
    if (iVar2 == 0) goto LAB_0004803a;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    iVar1 = piVar4[3];
    if (param_1 != 10) {
      __cp = (void *)(iVar1 + 4);
LAB_000480ac:
      pcVar3 = inet_ntop(param_1,__cp,acStack_68,0x40);
      iVar1 = 2;
      curl_msnprintf(param_5,param_6,"%s%s",pcVar3,&local_74);
      goto LAB_00048064;
    }
    iVar2 = Curl_ipv6_scope(iVar1);
    if (iVar2 == param_2) {
      __cp = (void *)(iVar1 + 8);
      if (*(int *)(iVar1 + 0x18) == param_3 || param_3 == 0) {
        if (*(int *)(iVar1 + 0x18) != 0) {
          curl_msnprintf(&local_74,0xc,&DAT_00137088);
        }
        goto LAB_000480ac;
      }
    }
LAB_00048038:
    iVar1 = 1;
  }
LAB_0004803a:
  piVar4 = (int *)*piVar4;
joined_r0x00048060:
  if (piVar4 == (int *)0x0) goto LAB_00048064;
  goto LAB_0004803e;
}

