
undefined4
AddFormData(undefined4 *param_1,uint param_2,char *param_3,undefined4 param_4,size_t param_5,
           int param_6,uint *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *__dest;
  undefined4 uVar5;
  stat64 sStack_90;
  
  if ((param_6 < 0) || ((param_7 != (uint *)0x0 && ((int)param_7[1] < 0)))) {
LAB_0005a4e4:
    uVar5 = 0x2b;
  }
  else {
    __dest = &Curl_cmalloc;
    puVar1 = (undefined4 *)(*Curl_cmalloc)(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x1b;
    }
    *puVar1 = 0;
    if (1 < param_2) {
      __dest = (undefined4 *)0x0;
    }
    if (param_2 < 2) {
      if (param_5 == 0 && param_6 == 0) {
        param_6 = 0;
        param_5 = strlen(param_3);
      }
      else if ((int)(uint)(param_5 != 0xffffffff) <= param_6) {
        uVar5 = 0x2b;
        goto LAB_0005a530;
      }
      __dest = (undefined4 *)(*(code *)*__dest)(param_5 + 1);
      puVar1[2] = __dest;
      if (__dest == (undefined4 *)0x0) {
        uVar5 = 0x1b;
LAB_0005a530:
        (*Curl_cfree)(puVar1);
        return uVar5;
      }
      memcpy(__dest,param_3,param_5);
      puVar1[3] = param_5;
      *(undefined1 *)(puVar1[2] + param_5) = 0;
    }
    else {
      puVar1[2] = param_3;
    }
    puVar4 = (undefined4 *)*param_1;
    puVar1[1] = param_2;
    if (puVar4 == (undefined4 *)0x0) {
      *param_1 = puVar1;
    }
    else {
      *puVar4 = puVar1;
      *param_1 = puVar1;
    }
    if (param_7 != (uint *)0x0) {
      if (param_2 != 3) {
        uVar3 = *param_7;
        *param_7 = param_5 + uVar3;
        param_7[1] = param_6 + param_7[1] + (uint)CARRY4(param_5,uVar3);
        return 0;
      }
      iVar2 = curl_strequal("-",puVar1[2]);
      if (iVar2 == 0) {
        iVar2 = __xstat64(3,(char *)puVar1[2],&sStack_90);
        if ((iVar2 == 0) && ((sStack_90.st_mode & 0xf000) != 0x4000)) {
          uVar3 = *param_7;
          *param_7 = (uint)sStack_90.st_size + uVar3;
          param_7[1] = sStack_90.st_size._4_4_ +
                       param_7[1] + (uint)CARRY4((uint)sStack_90.st_size,uVar3);
          return 0;
        }
        (*Curl_cfree)(puVar1);
        if (__dest != (undefined4 *)0x0) {
          (*Curl_cfree)(__dest);
          return 0x2b;
        }
        goto LAB_0005a4e4;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

