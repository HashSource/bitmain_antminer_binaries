
undefined4 rc4_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  RC4(*(RC4_KEY **)(param_1 + 0x60),param_4,param_3,param_2);
  return 1;
}

