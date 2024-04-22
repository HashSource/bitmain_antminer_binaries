
undefined4
AddFormData(undefined4 *param_1,uint param_2,char *param_3,undefined4 param_4,size_t param_5,
           uint param_6,uint *param_7)

{
  code **ppcVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  code **__dest;
  undefined4 uVar6;
  undefined auStack_90 [52];
  int iStack_5c;
  
  __dest = DAT_0005a598;
  if (((int)param_6 < 0) || ((param_7 != (uint *)0x0 && ((int)param_7[1] < 0)))) {
LAB_0005a4e4:
    uVar6 = 0x2b;
  }
  else {
    puVar2 = (undefined4 *)(**DAT_0005a598)(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      return 0x1b;
    }
    *puVar2 = 0;
    if (1 < param_2) {
      __dest = (code **)0x0;
    }
    if (param_2 < 2) {
      if ((param_5 | param_6) == 0) {
        param_6 = 0;
        param_5 = strlen(param_3);
      }
      else if ((int)(param_6 - (param_5 != 0xffffffff)) < 0 ==
               (SBORROW4(param_6,(uint)(param_5 != 0xffffffff)) != false)) {
        uVar6 = 0x2b;
        goto LAB_0005a530;
      }
      __dest = (code **)(**__dest)(param_5 + 1);
      puVar2[2] = __dest;
      if (__dest == (code **)0x0) {
        uVar6 = 0x1b;
LAB_0005a530:
        (**DAT_0005a59c)(puVar2);
        return uVar6;
      }
      memcpy(__dest,param_3,param_5);
      puVar2[3] = param_5;
      *(undefined *)(puVar2[2] + param_5) = 0;
    }
    else {
      puVar2[2] = param_3;
    }
    puVar5 = (undefined4 *)*param_1;
    puVar2[1] = param_2;
    if (puVar5 == (undefined4 *)0x0) {
      *param_1 = puVar2;
    }
    else {
      *puVar5 = puVar2;
      *param_1 = puVar2;
    }
    if (param_7 != (uint *)0x0) {
      if (param_2 != 3) {
        uVar4 = *param_7;
        *param_7 = param_5 + uVar4;
        param_7[1] = param_6 + param_7[1] + (uint)CARRY4(param_5,uVar4);
        return 0;
      }
      iVar3 = curl_strequal(DAT_0005a5a0,puVar2[2]);
      if (iVar3 == 0) {
        iVar3 = __xstat64(3,(char *)puVar2[2],(stat64 *)auStack_90);
        ppcVar1 = DAT_0005a59c;
        if ((iVar3 == 0) && ((auStack_90._16_4_ & 0xf000) != 0x4000)) {
          uVar4 = *param_7;
          *param_7 = auStack_90._48_4_ + uVar4;
          param_7[1] = iStack_5c + param_7[1] + (uint)CARRY4(auStack_90._48_4_,uVar4);
          return 0;
        }
        (**DAT_0005a59c)(puVar2);
        if (__dest != (code **)0x0) {
          (**ppcVar1)(__dest);
          return 0x2b;
        }
        goto LAB_0005a4e4;
      }
    }
    uVar6 = 0;
  }
  return uVar6;
}

