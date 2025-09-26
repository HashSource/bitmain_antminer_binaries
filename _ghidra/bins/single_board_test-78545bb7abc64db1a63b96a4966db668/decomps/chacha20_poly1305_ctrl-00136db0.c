
undefined4 chacha20_poly1305_ctrl(int param_1,undefined4 param_2,size_t param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x60);
  switch(param_2) {
  case 0:
    if (iVar5 == 0) {
      iVar5 = Poly1305_ctx_size();
      iVar5 = CRYPTO_zalloc(iVar5 + 0xd0,"crypto/evp/e_chacha20_poly1305.c",0x1fd);
      *(int *)(param_1 + 0x60) = iVar5;
      if (iVar5 == 0) {
        ERR_put_error(6,0xb6,0x86,"crypto/evp/e_chacha20_poly1305.c",0x1ff);
        return 0;
      }
    }
    *(undefined4 *)(iVar5 + 0xa8) = 0;
    *(undefined4 *)(iVar5 + 0xac) = 0;
    *(undefined4 *)(iVar5 + 0xb0) = 0;
    *(undefined4 *)(iVar5 + 0xb4) = 0;
    uVar1 = 1;
    *(undefined4 *)(iVar5 + 0xb8) = 0;
    *(undefined4 *)(iVar5 + 0xbc) = 0;
    *(undefined4 *)(iVar5 + 0xc0) = 0;
    *(undefined4 *)(iVar5 + 0x94) = 0;
    *(undefined4 *)(iVar5 + 0xc4) = 0xc;
    *(undefined4 *)(iVar5 + 200) = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x98) = 0;
    *(undefined4 *)(iVar5 + 0x9c) = 0;
    *(undefined4 *)(iVar5 + 0xa0) = 0;
    break;
  default:
    uVar1 = 0xffffffff;
    break;
  case 8:
    if (iVar5 != 0) {
      iVar2 = Poly1305_ctx_size();
      iVar5 = CRYPTO_memdup(iVar5,iVar2 + 0xd0,"crypto/evp/e_chacha20_poly1305.c",0x211);
      param_4[0x18] = iVar5;
      if (iVar5 == 0) {
        ERR_put_error(6,0xb6,0xad,"crypto/evp/e_chacha20_poly1305.c",0x213);
        return 0;
      }
    }
  case 0x17:
switchD_00136dc2_caseD_17:
    uVar1 = 1;
    break;
  case 9:
    if (0xb < param_3 - 1) {
      return 0;
    }
    *(size_t *)(iVar5 + 0xc4) = param_3;
    uVar1 = 1;
    break;
  case 0x10:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      return 0;
    }
    memcpy(param_4,(void *)(iVar5 + 0x84),param_3);
    goto switchD_00136dc2_caseD_17;
  case 0x11:
    if (0xf < param_3 - 1) {
      return 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      memcpy((void *)(iVar5 + 0x84),param_4,param_3);
      *(size_t *)(iVar5 + 0xc0) = param_3;
      return 1;
    }
    goto switchD_00136dc2_caseD_17;
  case 0x12:
    if (param_3 != 0xc) {
      return 0;
    }
    uVar3 = *param_4;
    uVar1 = 1;
    *(undefined4 *)(iVar5 + 0x24) = uVar3;
    *(undefined4 *)(iVar5 + 0x78) = uVar3;
    uVar3 = param_4[1];
    *(undefined4 *)(iVar5 + 0x28) = uVar3;
    *(undefined4 *)(iVar5 + 0x7c) = uVar3;
    uVar3 = param_4[2];
    *(undefined4 *)(iVar5 + 0x2c) = uVar3;
    *(undefined4 *)(iVar5 + 0x80) = uVar3;
    break;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    uVar3 = param_4[2];
    uVar1 = *param_4;
    *(undefined4 *)(iVar5 + 0x98) = param_4[1];
    *(undefined4 *)(iVar5 + 0x9c) = uVar3;
    *(undefined4 *)(iVar5 + 0x94) = uVar1;
    *(undefined1 *)(iVar5 + 0xa0) = *(undefined1 *)(param_4 + 3);
    uVar4 = (uint)CONCAT11(*(undefined1 *)((int)param_4 + 0xb),*(undefined1 *)(param_4 + 3));
    if (*(int *)(param_1 + 8) == 0) {
      if (uVar4 < 0x10) {
        return 0;
      }
      uVar4 = uVar4 - 0x10;
      *(char *)(iVar5 + 0xa0) = (char)uVar4;
      *(char *)(iVar5 + 0x9f) = (char)(uVar4 >> 8);
    }
    uVar1 = 0x10;
    *(uint *)(iVar5 + 200) = uVar4;
    *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x94) ^ *(uint *)(iVar5 + 0x7c);
    *(uint *)(iVar5 + 0x2c) = *(uint *)(iVar5 + 0x80) ^ *(uint *)(iVar5 + 0x98);
    *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(iVar5 + 0x78);
    *(undefined4 *)(iVar5 + 0xbc) = 0;
    break;
  case 0x25:
    *param_4 = *(undefined4 *)(iVar5 + 0xc4);
    return 1;
  }
  return uVar1;
}

