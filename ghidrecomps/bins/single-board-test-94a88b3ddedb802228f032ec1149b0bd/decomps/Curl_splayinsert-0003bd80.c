
undefined4 * Curl_splayinsert(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_4 == (undefined4 *)0x0) {
    return param_3;
  }
  if (param_3 == (undefined4 *)0x0) {
    param_4[1] = 0;
    *param_4 = 0;
    goto LAB_0003bdbc;
  }
  puVar2 = (undefined4 *)Curl_splay(param_1,param_2);
  puVar1 = DAT_0003be1c;
  iVar4 = puVar2[3];
  if (param_1 == iVar4) {
    iVar4 = puVar2[4];
    if (param_2 == iVar4) {
      uVar6 = *puVar2;
      param_4[3] = param_1;
      param_4[4] = param_2;
      uVar7 = puVar2[1];
      uVar5 = *puVar1;
      uVar3 = puVar1[1];
      *param_4 = uVar6;
      *puVar2 = param_4;
      param_4[2] = puVar2;
      param_4[1] = uVar7;
      puVar2[3] = uVar5;
      puVar2[4] = uVar3;
      return param_4;
    }
LAB_0003bdae:
    if (iVar4 <= param_2) {
LAB_0003bdde:
      uVar5 = puVar2[1];
      *param_4 = puVar2;
      param_4[1] = uVar5;
      puVar2[1] = 0;
      goto LAB_0003bdbc;
    }
  }
  else if (iVar4 <= param_1) {
    if (param_1 <= iVar4) {
      iVar4 = puVar2[4];
      goto LAB_0003bdae;
    }
    goto LAB_0003bdde;
  }
  uVar5 = *puVar2;
  param_4[1] = puVar2;
  *param_4 = uVar5;
  *puVar2 = 0;
LAB_0003bdbc:
  param_4[2] = 0;
  param_4[3] = param_1;
  param_4[4] = param_2;
  return param_4;
}

