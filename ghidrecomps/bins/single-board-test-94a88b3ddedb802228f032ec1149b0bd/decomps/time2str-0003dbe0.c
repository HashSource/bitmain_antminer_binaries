
void time2str(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  if ((int)(param_4 - (uint)(param_3 == 0)) < 0 == (SBORROW4(param_4,(uint)(param_3 == 0)) != false)
     ) {
    lVar7 = __aeabi_ldivmod(param_3,param_4,0xe10,0);
    iVar4 = (int)((ulonglong)lVar7 >> 0x20);
    bVar6 = (uint)lVar7 < 100;
    if ((int)(iVar4 - (uint)bVar6) < 0 == (SBORROW4(iVar4,(uint)bVar6) != false)) {
      lVar7 = __aeabi_ldivmod(param_3,param_4,0x15180,0);
      iVar4 = (int)((ulonglong)lVar7 >> 0x20);
      bVar6 = (uint)lVar7 < 1000;
      iVar3 = iVar4 - (uint)bVar6;
      if (iVar3 < 0 == (SBORROW4(iVar4,(uint)bVar6) != false)) {
        curl_msnprintf(param_1,9,DAT_0003dcec,iVar3,lVar7);
      }
      else {
        lVar2 = lVar7 * -0x15180 + CONCAT44(param_4,param_3);
        __aeabi_ldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0xe10,0,lVar7);
        curl_msnprintf(param_1,9,DAT_0003dcf0);
      }
    }
    else {
      lVar2 = lVar7 * -0xe10 + CONCAT44(param_4,param_3);
      uVar5 = (undefined4)lVar2;
      iVar3 = (int)((ulonglong)lVar2 >> 0x20);
      uVar8 = __aeabi_ldivmod(uVar5,iVar3,0x3c,0);
      iVar4 = (int)(uVar8 >> 0x20) * -0x3c - (int)uVar8;
      lVar2 = (uVar8 & 0xffffffff) * 0xffffffc4 + CONCAT44(iVar4,uVar5);
      curl_msnprintf(param_1,9,DAT_0003dcf4,iVar4,lVar7,uVar8,(int)lVar2,
                     iVar3 + (int)((ulonglong)lVar2 >> 0x20));
    }
  }
  else {
    uVar5 = DAT_0003dcf8[1];
    uVar1 = *(undefined *)(DAT_0003dcf8 + 2);
    *param_1 = *DAT_0003dcf8;
    param_1[1] = uVar5;
    *(undefined *)(param_1 + 2) = uVar1;
  }
  return;
}

