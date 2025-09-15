
void final(int param_1,uchar *param_2)

{
  SHA_Final(param_2,*(SHA_CTX **)(param_1 + 0xc));
  return;
}

