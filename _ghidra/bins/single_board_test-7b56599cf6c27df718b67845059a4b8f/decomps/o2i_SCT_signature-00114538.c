
int o2i_SCT_signature(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  if (*param_1 == 0) {
    if (param_3 < 5) {
      iVar1 = 0x2a;
    }
    else {
      puVar3 = (undefined1 *)*param_2;
      *(undefined1 *)(param_1 + 10) = *puVar3;
      *(undefined1 *)((int)param_1 + 0x29) = puVar3[1];
      iVar1 = SCT_get_signature_nid();
      if (iVar1 == 0) {
        iVar1 = 0x33;
      }
      else {
        puVar5 = puVar3 + 4;
        uVar4 = (uint)CONCAT11(puVar3[2],puVar3[3]);
        uVar2 = param_3 - ((int)puVar5 - *param_2);
        if (uVar4 <= uVar2) {
          iVar1 = SCT_set1_signature(param_1,puVar5,uVar4);
          if (iVar1 != 1) {
            return -1;
          }
          *param_2 = (int)(puVar5 + uVar4);
          return param_3 - (uVar2 - uVar4);
        }
        iVar1 = 0x3a;
      }
    }
    ERR_put_error(0x32,0x70,0x6b,"crypto/ct/ct_oct.c",iVar1);
  }
  else {
    ERR_put_error(0x32,0x70,0x67,"crypto/ct/ct_oct.c",0x1f);
  }
  return -1;
}

