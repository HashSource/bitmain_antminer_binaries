
void cmac_signctx(int param_1,uchar *param_2,size_t *param_3)

{
  CMAC_Final(*(CMAC_CTX **)(param_1 + 0x14),param_2,param_3);
  return;
}

