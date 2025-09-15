
void time2str(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  if (param_4 < (int)(uint)(param_3 == 0)) {
    *param_1 = 0x2d3a2d2d;
    param_1[1] = 0x2d2d3a2d;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  else {
    lVar6 = __aeabi_ldivmod(param_3,param_4,0xe10,0);
    if ((int)((ulonglong)lVar6 >> 0x20) < (int)(uint)((uint)lVar6 < 100)) {
      lVar2 = lVar6 * -0xe10 + CONCAT44(param_4,param_3);
      uVar4 = (undefined4)lVar2;
      iVar5 = (int)((ulonglong)lVar2 >> 0x20);
      uVar7 = __aeabi_ldivmod(uVar4,iVar5,0x3c,0);
      iVar3 = (int)(uVar7 >> 0x20) * -0x3c - (int)uVar7;
      lVar2 = (uVar7 & 0xffffffff) * 0xffffffc4 + CONCAT44(iVar3,uVar4);
      curl_msnprintf(param_1,9,"%2lld:%02lld:%02lld",iVar3,lVar6,uVar7,(int)lVar2,
                     iVar5 + (int)((ulonglong)lVar2 >> 0x20));
    }
    else {
      lVar6 = __aeabi_ldivmod(param_3,param_4,0x15180,0);
      iVar3 = (int)((ulonglong)lVar6 >> 0x20);
      uVar1 = (uint)((uint)lVar6 < 1000);
      if (iVar3 < (int)uVar1) {
        lVar2 = lVar6 * -0x15180 + CONCAT44(param_4,param_3);
        __aeabi_ldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0xe10,0,lVar6);
        curl_msnprintf(param_1,9,&DAT_001357c4);
      }
      else {
        curl_msnprintf(param_1,9,"%7lldd",iVar3 - uVar1,lVar6);
      }
    }
  }
  return;
}

