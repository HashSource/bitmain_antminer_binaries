
void final(int param_1,uchar *param_2)

{
  RIPEMD160_Final(param_2,*(RIPEMD160_CTX **)(param_1 + 0xc));
  return;
}

