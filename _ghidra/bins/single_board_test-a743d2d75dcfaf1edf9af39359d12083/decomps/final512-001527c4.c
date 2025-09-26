
void final512(int param_1,uchar *param_2)

{
  SHA512_Final(param_2,*(SHA512_CTX **)(param_1 + 0xc));
  return;
}

