
undefined4 cast5_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  uchar *in;
  uchar *out;
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*param_1 + 4);
  if (uVar2 <= param_4) {
    uVar1 = 0;
    do {
      in = (uchar *)(param_3 + uVar1);
      out = (uchar *)(param_2 + uVar1);
      uVar1 = uVar1 + uVar2;
      CAST_ecb_encrypt(in,out,(CAST_KEY *)param_1[0x18],param_1[2]);
    } while (uVar1 <= param_4 - uVar2);
  }
  return 1;
}

