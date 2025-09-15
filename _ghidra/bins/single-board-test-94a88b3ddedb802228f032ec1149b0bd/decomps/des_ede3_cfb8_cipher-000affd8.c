
undefined4 des_ede3_cfb8_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  DES_key_schedule *pDVar2;
  uchar *out;
  uchar *in;
  uint uVar3;
  uchar *local_2c;
  
  local_2c = param_2;
  if (0x3fffffff < param_4) {
    out = param_2;
    in = param_3;
    uVar3 = param_4;
    do {
      pDVar2 = *(DES_key_schedule **)(param_1 + 0x60);
      uVar3 = uVar3 + 0xc0000000;
      DES_ede3_cfb_encrypt
                (in,out,8,0x40000000,pDVar2,pDVar2 + 1,pDVar2 + 2,(DES_cblock *)(param_1 + 0x20),
                 *(int *)(param_1 + 8));
      out = out + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = (uVar3 & 0xc0000000) + 0x40000000;
    param_3 = param_3 + iVar1;
    local_2c = param_2 + iVar1;
  }
  if (param_4 != 0) {
    pDVar2 = *(DES_key_schedule **)(param_1 + 0x60);
    DES_ede3_cfb_encrypt
              (param_3,local_2c,8,param_4,pDVar2,pDVar2 + 1,pDVar2 + 2,
               (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
  }
  return 1;
}

