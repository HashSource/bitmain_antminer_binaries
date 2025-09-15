
undefined4 * Curl_splayinsert(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_4 == (undefined4 *)0x0) {
    return param_3;
  }
  if (param_3 == (undefined4 *)0x0) {
    param_4[1] = 0;
    *param_4 = 0;
    goto LAB_0003bdbc;
  }
  puVar1 = (undefined4 *)Curl_splay(param_1,param_2);
  iVar2 = puVar1[3];
  if (param_1 == iVar2) {
    iVar2 = puVar1[4];
    if (param_2 == iVar2) {
      uVar3 = *puVar1;
      param_4[3] = param_1;
      param_4[4] = param_2;
      uVar4 = puVar1[1];
      *param_4 = uVar3;
      *puVar1 = param_4;
      param_4[2] = puVar1;
      param_4[1] = uVar4;
      puVar1[3] = 0xffffffff;
      puVar1[4] = 0xffffffff;
      return param_4;
    }
LAB_0003bdae:
    if (iVar2 <= param_2) {
LAB_0003bdde:
      uVar3 = puVar1[1];
      *param_4 = puVar1;
      param_4[1] = uVar3;
      puVar1[1] = 0;
      goto LAB_0003bdbc;
    }
  }
  else if (iVar2 <= param_1) {
    if (param_1 <= iVar2) {
      iVar2 = puVar1[4];
      goto LAB_0003bdae;
    }
    goto LAB_0003bdde;
  }
  uVar3 = *puVar1;
  param_4[1] = puVar1;
  *param_4 = uVar3;
  *puVar1 = 0;
LAB_0003bdbc:
  param_4[2] = 0;
  param_4[3] = param_1;
  param_4[4] = param_2;
  return param_4;
}

