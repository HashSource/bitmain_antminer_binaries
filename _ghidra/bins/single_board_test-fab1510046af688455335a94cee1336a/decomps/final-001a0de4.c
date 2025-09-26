
void final(int param_1,uchar *param_2)

{
  MD4_Final(param_2,*(MD4_CTX **)(param_1 + 0xc));
  return;
}

