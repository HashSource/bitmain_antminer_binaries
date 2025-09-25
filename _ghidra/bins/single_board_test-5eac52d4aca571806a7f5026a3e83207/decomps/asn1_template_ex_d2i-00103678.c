
undefined4
asn1_template_ex_d2i
          (int param_1,undefined4 *param_2,int param_3,uint *param_4,char param_5,char *param_6,
          undefined4 param_7)

{
  uchar *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uchar *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uchar *local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uchar *local_2c [2];
  
  if (param_1 == 0) {
    return 0;
  }
  uVar7 = *param_4;
  puVar5 = (uchar *)*param_2;
  local_3c = puVar5;
  if ((uVar7 & 0x10) == 0) {
    uVar4 = asn1_template_noexp_d2i();
  }
  else {
    uVar8 = param_4[1];
    local_2c[0] = puVar5;
    if (param_6 == (char *)0x0) {
      uVar2 = ASN1_get_object(local_2c,&local_30,(int *)&local_38,(int *)&local_34,param_3);
      if ((int)(uVar2 << 0x18) < 0) {
        ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
        goto LAB_001036fa;
      }
    }
    else {
      if (*param_6 == '\0') {
        uVar2 = ASN1_get_object(local_2c,&local_30,(int *)&local_38,(int *)&local_34,param_3);
        *(uint *)(param_6 + 0x10) = local_34;
        *(uint *)(param_6 + 4) = uVar2;
        *(int *)(param_6 + 0x14) = (int)local_2c[0] - (int)puVar5;
        *(uint *)(param_6 + 0xc) = local_38;
        *(int *)(param_6 + 8) = local_30;
        *param_6 = '\x01';
        if (((uVar2 & 0x81) == 0) && (param_3 < ((int)local_2c[0] - (int)puVar5) + local_30)) {
          ERR_put_error(0xd,0x68,0x9b,"crypto/asn1/tasn_dec.c",0x469);
          *param_6 = '\0';
          goto LAB_001036fa;
        }
      }
      else {
        local_38 = *(uint *)(param_6 + 0xc);
        local_30 = *(int *)(param_6 + 8);
        uVar2 = *(uint *)(param_6 + 4);
        local_2c[0] = puVar5 + *(int *)(param_6 + 0x14);
        local_34 = *(uint *)(param_6 + 0x10);
      }
      if ((int)(uVar2 << 0x18) < 0) {
        ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
        *param_6 = '\0';
        goto LAB_001036fa;
      }
    }
    puVar1 = local_2c[0];
    if (-1 < (int)uVar8) {
      if ((uVar8 != local_38) || ((uVar7 & 0xc0) != local_34)) {
        if (param_5 != '\0') {
          return 0xffffffff;
        }
        if (param_6 != (char *)0x0) {
          *param_6 = '\0';
        }
        ERR_put_error(0xd,0x68,0xa8,"crypto/asn1/tasn_dec.c",0x47d);
LAB_001036fa:
        ERR_put_error(0xd,0x84,0x3a,"crypto/asn1/tasn_dec.c",0x1e4);
        return 0;
      }
      if (param_6 != (char *)0x0) {
        *param_6 = '\0';
      }
    }
    bVar9 = (int)(uVar2 << 0x1f) < 0;
    iVar6 = local_30;
    if (bVar9) {
      iVar6 = (int)local_2c[0] - (int)puVar5;
    }
    local_3c = local_2c[0];
    if (bVar9) {
      iVar6 = param_3 - iVar6;
    }
    if ((uVar2 & 0x20) == 0) {
      ERR_put_error(0xd,0x84,0x78,"crypto/asn1/tasn_dec.c",0x1ea);
      return 0;
    }
    iVar3 = asn1_template_noexp_d2i(param_1,&local_3c,iVar6,param_4,0,param_6,param_7);
    if (iVar3 == 0) {
      ERR_put_error(0xd,0x84,0x3a,"crypto/asn1/tasn_dec.c",0x1f0);
      uVar4 = 0;
    }
    else {
      if ((uVar2 & 1) == 0) {
        puVar5 = local_3c;
        if (iVar6 != (int)local_3c - (int)puVar1) {
          ERR_put_error(0xd,0x84,0x77,"crypto/asn1/tasn_dec.c",0x201);
          return 0;
        }
      }
      else if (((iVar6 - ((int)local_3c - (int)puVar1) < 2) || (*local_3c != '\0')) ||
              (puVar5 = local_3c + 2, local_3c[1] != '\0')) {
        ERR_put_error(0xd,0x84,0x89,"crypto/asn1/tasn_dec.c",0x1f8);
        return 0;
      }
      *param_2 = puVar5;
      uVar4 = 1;
    }
  }
  return uVar4;
}

